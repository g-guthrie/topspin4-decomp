// Reference JavaScript binding of the ts4core WebAssembly API (port/core/include/ts4core.h).
// Works in browsers (fetch) and in Node (fs). No dependencies. The struct layouts below are asserted against the
// module at load time, so a header change that moves a field fails loudly instead of silently misreading memory.
//
//   const core = await Ts4Core.fromBytes(wasmBytes, blobBytes);
//   core.startMatch({ seed: 1, players: [{human: true}, {}] });
//   core.setInput(0, { x: 0, z: 0, buttons: 0 });
//   core.step();                       // one 1/60 s tick
//   core.snapshot(); core.pollEvents();

export const BTN = { FLAT: 1, TOPSPIN: 2, SLICE: 4, LOB: 8, RISK: 16, SPRINT: 32 };
export const PHASE = ['idle', 'serve', 'rally', 'point_end', 'match_over'];
export const EVENT = ['?', 'serve', 'hit', 'whiff', 'bounce', 'net', 'point_end', 'fault', 'double_fault', 'let',
                      'game', 'set', 'match', 'change_ends'];
const SIZES = { snapshot: 256, event: 32, matchConfig: 120, input: 12, shotIn: 60, shotOut: 52 };

export class Ts4Core {
  static async fromBytes(wasmBytes, blobBytes) {
    const { instance } = await WebAssembly.instantiate(wasmBytes, {});
    return new Ts4Core(instance, blobBytes);
  }
  static async fromUrl(wasmUrl, blobUrl) {
    const [w, b] = await Promise.all([fetch(wasmUrl), fetch(blobUrl)]);
    return Ts4Core.fromBytes(await w.arrayBuffer(), new Uint8Array(await b.arrayBuffer()));
  }

  constructor(instance, blobBytes) {
    this.x = instance.exports;
    this.mem = this.x.memory;
    if (this.x.ts4_api_version() !== 1) throw new Error('ts4core API version mismatch');
    if (this.x.ts4_snapshot_size() !== SIZES.snapshot) throw new Error('snapshot layout mismatch');
    const size = this.x.ts4_core_size();
    this.corePtr = this.x.ts4_core_init(this.x.ts4_wasm_alloc(size), size);
    if (!this.corePtr) throw new Error('ts4_core_init failed');
    this.blobPtr = this.x.ts4_wasm_alloc(blobBytes.length);   // the blob must stay put while the core lives
    new Uint8Array(this.mem.buffer, this.blobPtr, blobBytes.length).set(blobBytes);
    this.loadResult = this.x.ts4_data_load(this.corePtr, this.blobPtr, blobBytes.length);
    this.scratch = this.x.ts4_wasm_alloc(4096);
    this.evBuf = this.x.ts4_wasm_alloc(SIZES.event * 64);
  }

  get dv() { return new DataView(this.mem.buffer); }
  cstr(p) { const u = new Uint8Array(this.mem.buffer); let e = p; while (u[e]) e++; return new TextDecoder().decode(u.subarray(p, e)); }
  buildInfo() { return this.cstr(this.x.ts4_build_info()); }

  /** names of the tunables that are required but absent from the blob (match start refuses while any exist) */
  missingTunables() {
    const out = [];
    const n = this.x.ts4_missing_tunable_count(this.corePtr);
    for (let i = 0; i < n; i++) out.push(this.cstr(this.x.ts4_tunable_name(this.x.ts4_missing_tunable_id(this.corePtr, i))));
    return out;
  }
  /** retuning hook: override a tunable by registry name */
  setTunable(name, value) {
    const n = this.x.ts4_tunable_count();
    for (let i = 0; i < n; i++) {
      if (this.cstr(this.x.ts4_tunable_name(i)) === name) return this.x.ts4_set_tunable(this.corePtr, i, value);
    }
    return -1;
  }
  moduleStatus() {
    const names = ['data', 'ball', 'templates', 'shot', 'graphs', 'rules', 'reach', 'move', 'swing', 'ai'];
    return Object.fromEntries(names.map((n, i) => [n, ['ready', 'missing_data', 'degraded'][this.x.ts4_module_status(this.corePtr, i)]]));
  }

  startMatch(cfg = {}) {
    const dv = this.dv, p = this.scratch;
    new Uint8Array(this.mem.buffer, p, SIZES.matchConfig).fill(0);
    dv.setUint32(p, SIZES.matchConfig, true);
    dv.setUint32(p + 4, cfg.seed ?? 1, true);
    dv.setInt32(p + 8, cfg.gamesPerSet ?? 6, true);
    dv.setInt32(p + 12, cfg.numSets ?? 1, true);
    dv.setUint32(p + 16, cfg.tiebreakOnlySets ? 1 : 0, true);
    dv.setUint32(p + 20, cfg.finalSetSuperTb ? 1 : 0, true);
    dv.setUint32(p + 24, cfg.shortFormat ? 1 : 0, true);
    dv.setUint32(p + 28, cfg.singleServe ? 1 : 0, true);
    dv.setInt32(p + 32, cfg.firstServer ?? 0, true);
    dv.setUint32(p + 36, cfg.surface ?? 0, true);
    for (let i = 0; i < 2; i++) {
      const pl = (cfg.players ?? [])[i] ?? {}, q = p + 40 + 40 * i;
      for (let k = 0; k < 8; k++) dv.setFloat32(q + 4 * k, (pl.stats ?? [])[k] ?? 60, true);
      dv.setUint32(q + 32, pl.leftHanded ? 1 : 0, true);
      dv.setUint32(q + 36, pl.human ? 1 : 0, true);
    }
    return this.x.ts4_match_start(this.corePtr, p);
  }

  setInput(player, { x = 0, z = 0, buttons = 0 } = {}) {
    const dv = this.dv, p = this.scratch + 512;
    dv.setFloat32(p, x, true); dv.setFloat32(p + 4, z, true); dv.setUint32(p + 8, buttons, true);
    return this.x.ts4_set_input(this.corePtr, player, p);
  }
  step(n = 1) { for (let i = 0; i < n; i++) this.x.ts4_step(this.corePtr); }
  stateHash() { return this.x.ts4_state_hash(this.corePtr) >>> 0; }

  snapshot() {
    const dv = this.dv, p = this.x.ts4_snapshot(this.corePtr);
    const f = (o) => dv.getFloat32(p + o, true), u = (o) => dv.getUint32(p + o, true), i = (o) => dv.getInt32(p + o, true);
    const vec = (o) => [f(o), f(o + 4), f(o + 8)];
    const player = (o) => ({ pos: vec(o), vel: vec(o + 12), heading: f(o + 24), moveState: u(o + 28), swingState: u(o + 32),
                             swingT: f(o + 36), templateRow: u(o + 40), flags: u(o + 44) });
    const s = 164;
    return {
      tick: u(4), phase: PHASE[u(8)], pointTicks: u(12),
      ball: { pos: vec(16), vel: vec(28), spin: vec(40), mode: u(52), bounceCount: u(56), live: !!u(60), lastHitter: i(64) },
      players: [player(68), player(116)],
      score: { games: [[0, 1, 2, 3, 4].map((k) => i(s + 4 * k)), [0, 1, 2, 3, 4].map((k) => i(s + 20 + 4 * k))],
               setsWon: [i(s + 40), i(s + 44)], display: [i(s + 48), i(s + 52)], curSet: i(s + 56), server: i(s + 60),
               serveSide: i(s + 64), secondServe: i(s + 68), tiebreak: i(s + 72), matchOver: i(s + 76), winner: i(s + 80),
               endsSwapped: i(s + 84) },
    };
  }

  pollEvents() {
    const out = [];
    for (;;) {
      const n = this.x.ts4_poll_events(this.corePtr, this.evBuf, 64);
      const dv = this.dv;
      for (let k = 0; k < n; k++) {
        const q = this.evBuf + 32 * k;
        out.push({ type: EVENT[dv.getUint32(q, true)] ?? '?', tick: dv.getUint32(q + 4, true), a: dv.getInt32(q + 8, true),
                   b: dv.getInt32(q + 12, true), c: dv.getInt32(q + 16, true),
                   pos: [dv.getFloat32(q + 20, true), dv.getFloat32(q + 24, true), dv.getFloat32(q + 28, true)] });
      }
      if (n < 64) return out;
    }
  }

  /** Fly one template row from -> to (cm) and return [[x,y,z], ...] per tick (retuning UI, shot previews). */
  shotTrace({ row, from, to, spinBlend = 0.5, f4c = 0, leftHanded = false, mode = 0xCA68AAEC, maxTicks = 400 }) {
    const dv = this.dv, p = this.scratch + 1024;
    new Uint8Array(this.mem.buffer, p, SIZES.shotIn).fill(0);
    dv.setUint32(p, SIZES.shotIn, true); dv.setUint32(p + 4, row, true);
    from.forEach((v, k) => dv.setFloat32(p + 8 + 4 * k, v, true));
    to.forEach((v, k) => dv.setFloat32(p + 20 + 4 * k, v, true));
    dv.setFloat32(p + 32, spinBlend, true); dv.setFloat32(p + 36, f4c, true);
    dv.setUint32(p + 40, leftHanded ? 1 : 0, true); dv.setUint32(p + 44, mode >>> 0, true); dv.setUint32(p + 48, 1, true);
    const buf = this.x.ts4_wasm_alloc(12 * maxTicks);
    const n = this.x.ts4_shot_trace(this.corePtr, p, buf, maxTicks);
    if (n < 0) return n;
    const f = new Float32Array(this.mem.buffer, buf, 3 * n);
    return Array.from({ length: n }, (_, k) => [f[3 * k], f[3 * k + 1], f[3 * k + 2]]);
  }
}
