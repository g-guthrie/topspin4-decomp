// ts4core adapter.  Presents one interface to the viewer whether the simulation runs in the real WebAssembly
// build (work/port/ts4core.wasm + gameplay/ts4core.dat, API of port/core/include/ts4core.h) or in the labelled JS
// fallback (core_js.js).  Interface:
//   core.kind          "wasm" | "js"
//   core.label         human readable, shown in the UI (the fallback says so explicitly)
//   core.templateCount()
//   core.probe(inp)    -> Ts4ShotOut-like object
//   core.trace(inp, maxTicks) -> {points: Float32Array (cm, 3 per tick), events, info}
// inp is a Ts4ShotIn-like object {row, from:[x,y,z], to:[x,y,z], spin_blend, f4c, left_handed, mode, planned,
// speed_kmh, aim_height_m}; positions in cm (world: x along the court, net at x = 0, y up, z across).

import { JsBallModel, MODE } from "./core_js.js";

export { MODE };

const SHOT_IN_WORDS = 15;     // Ts4ShotIn: 15 four-byte fields = 60 bytes
const SHOT_OUT_WORDS = 13;    // Ts4ShotOut: 13 four-byte fields = 52 bytes

class WasmCore {
  constructor(ex, mem, label) {
    this.kind = "wasm";
    this.ex = ex;
    this.mem = mem;
    this.label = label;
    this.core = 0;
    this.heap = 0;
  }

  fn(name) { return this.ex[name] || this.ex["_" + name]; }

  _alloc(bytes, align = 16) {
    const wa = this.ex.ts4_wasm_alloc || this.ex._ts4_wasm_alloc;      // the core's own bump allocator (wasm_rt.c), preferred
    if (wa) {
      const q = wa(bytes);
      if (!q) throw new Error("ts4_wasm_alloc failed for " + bytes + " bytes");
      return q;
    }
    let p = (this.heap + align - 1) & ~(align - 1);
    const end = p + bytes;
    if (end > this.mem.buffer.byteLength) {
      const pages = Math.ceil((end - this.mem.buffer.byteLength) / 65536);
      this.mem.grow(pages);
    }
    this.heap = end;
    return p;
  }

  async init(blobBytes, ballFallback) {
    const heapBase = this.ex.__heap_base;
    this.heap = heapBase ? (heapBase.value ?? heapBase) : this.mem.buffer.byteLength;
    const size = this.fn("ts4_core_size")();
    const region = this._alloc(size);
    this.core = this.fn("ts4_core_init")(region, size);
    if (!this.core) throw new Error("ts4_core_init returned NULL");
    const blob = this._alloc(blobBytes.length, 16);
    new Uint8Array(this.mem.buffer, blob, blobBytes.length).set(blobBytes);
    const rc = this.fn("ts4_data_load")(this.core, blob, blobBytes.length);
    if (rc !== 0) throw new Error("ts4_data_load failed: " + rc + " (see TS4_ERR_* in ts4core.h)");
    this.inPtr = this._alloc(SHOT_IN_WORDS * 4);
    this.outPtr = this._alloc(SHOT_OUT_WORDS * 4);
    this.traceCap = 1024;                                          // ticks the trace buffer holds (reused by every call)
    this.tracePtr = this._alloc(this.traceCap * 12);
    this.ballRadiusCm = ballFallback?.radius_cm ?? 4;
    const version = this.fn("ts4_api_version")();
    const info = this.fn("ts4_build_info");
    this.label = "ts4core WASM (api " + version + (info ? ", " + readCString(this.mem, info()) : "") + ")";
  }

  templateCount() { return this.fn("ts4_template_count")(this.core); }

  _writeIn(inp) {
    const dv = new DataView(this.mem.buffer, this.inPtr, SHOT_IN_WORDS * 4);
    let o = 0;
    const u32 = (v) => { dv.setUint32(o, v >>> 0, true); o += 4; };
    const f32 = (v) => { dv.setFloat32(o, v, true); o += 4; };
    u32(SHOT_IN_WORDS * 4);
    u32(inp.row);
    inp.from.forEach(f32);
    inp.to.forEach(f32);
    f32(inp.spin_blend ?? 0.5);
    f32(inp.f4c ?? 0);
    u32(inp.left_handed ? 1 : 0);
    u32(inp.mode ?? MODE.IN);
    u32(inp.planned === 0 ? 0 : 1);
    f32(inp.speed_kmh ?? 0);
    f32(inp.aim_height_m ?? 0);
  }

  probe(inp) {
    this._writeIn(inp);
    new DataView(this.mem.buffer, this.outPtr, 4).setUint32(0, SHOT_OUT_WORDS * 4, true);
    const rc = this.fn("ts4_shot_probe")(this.core, this.inPtr, this.outPtr);
    if (rc !== 0) throw new Error("ts4_shot_probe failed: " + rc);
    const dv = new DataView(this.mem.buffer, this.outPtr, SHOT_OUT_WORDS * 4);
    const f = (i) => dv.getFloat32(4 * i, true), u = (i) => dv.getUint32(4 * i, true);
    return {
      tau: f(1), bounce_tick: u(2), initial_kmh: f(3), net_height_m: f(4), raised: u(5), net_unreachable: u(6),
      launch_vel: [f(7), f(8), f(9)], arrive_vel: [f(10), f(11), f(12)],
    };
  }

  trace(inp, maxTicks = 420) {
    this._writeIn(inp);
    const out = this.tracePtr;
    const n = this.fn("ts4_shot_trace")(this.core, this.inPtr, out, Math.min(maxTicks, this.traceCap));
    if (n < 0) throw new Error("ts4_shot_trace failed: " + n);
    const points = new Float32Array(this.mem.buffer.slice(out, out + n * 12));
    const info = this.probe(inp);
    return { points, events: detectBounces(points, this.ballRadiusCm), info };
  }
}

function readCString(mem, ptr) {
  const b = new Uint8Array(mem.buffer, ptr, 128);
  let s = "";
  for (let i = 0; i < b.length && b[i]; i++) s += String.fromCharCode(b[i]);
  return s;
}

// The WASM trace returns positions only; mark ground contacts as local minima near the ball-centre ground height.
export function detectBounces(points, radiusCm) {
  const ev = [];
  const n = points.length / 3;
  for (let i = 1; i < n; i++) {
    const y = points[3 * i + 1];
    const next = i + 1 < n ? points[3 * i + 4] : Infinity;            // the last point counts when the ball is still descending
    if (y <= points[3 * i - 2] && y <= next && y < radiusCm + 1.0) {
      ev.push({ type: "bounce", tick: i, pos: [points[3 * i], y, points[3 * i + 2]], count: ev.length + 1 });
    }
  }
  return ev;
}

async function tryWasm(wasmUrl, blobUrl, shots, log) {
  let wasmBuf;
  try {
    const r = await fetch(wasmUrl);
    if (!r.ok) return { reason: "ts4core.wasm not found at " + wasmUrl + " (HTTP " + r.status + ")" };
    wasmBuf = await r.arrayBuffer();
  } catch (e) {
    return { reason: "ts4core.wasm not reachable: " + e.message };
  }
  let blob;
  try {
    const r = await fetch(blobUrl);
    if (!r.ok) return { reason: "ts4core.wasm present but the data blob is missing (" + blobUrl + ", HTTP " + r.status +
                                "); export it with tools/port/export_assets.py once docs/port/data-format.md is implemented" };
    blob = new Uint8Array(await r.arrayBuffer());
  } catch (e) {
    return { reason: "data blob not reachable: " + e.message };
  }
  try {
    const mod = await WebAssembly.compile(wasmBuf);
    const imports = {};
    let memory = null;
    for (const imp of WebAssembly.Module.imports(mod)) {
      imports[imp.module] ??= {};
      if (imp.kind === "memory") {
        memory = new WebAssembly.Memory({ initial: 1024 });       // 64 MiB; grows on demand
        imports[imp.module][imp.name] = memory;
      } else if (imp.kind === "function") {
        imports[imp.module][imp.name] = () => 0;                   // freestanding build: host services are not expected
      } else {
        return { reason: "ts4core.wasm imports a " + imp.kind + " (" + imp.module + "." + imp.name + "), which this loader does not provide" };
      }
    }
    const inst = await WebAssembly.instantiate(mod, imports);
    const ex = inst.exports;
    const mem = ex.memory || memory;
    if (!mem) return { reason: "ts4core.wasm exposes no memory" };
    const core = new WasmCore(ex, mem, "ts4core WASM");
    await core.init(blob, shots.ball);
    return { core };
  } catch (e) {
    return { reason: "ts4core.wasm failed to start: " + e.message };
  }
}

// shots: parsed gameplay/shots.json.  Returns the best available backend plus the reason the WASM one was not used.
export async function loadCore({ wasmUrl, blobUrl, shots }) {
  const w = await tryWasm(wasmUrl, blobUrl, shots);
  if (w.core) return { core: w.core, wasmNote: null };
  const js = new JsBallModel(shots.rows, shots.ball);
  js.kind = "js";
  js.label = "JS fallback: documented formulas, NOT ts4core";
  return { core: js, wasmNote: w.reason };
}
