// Reader for agent P1's per-tick animation state (port/core/include/ts4core.h: Ts4AnimView, ts4_anim_view()).
// Pure apart from the wasm memory access; the record is identified by clip_hash = crc32(clip name), so the browser's
// tables (anim_rules.json, AnimationsDB record order) and the core's ANIM clip table need not share an order.
export const ANIM_VIEW_SIZE = 64;
export const LAYERS = ["idle", "move", "swing", "serve"];

let CRC_TABLE = null;
export function crc32(str) {
  if (!CRC_TABLE) {
    CRC_TABLE = new Uint32Array(256);
    for (let n = 0; n < 256; n++) { let c = n; for (let k = 0; k < 8; k++) c = c & 1 ? 0xedb88320 ^ (c >>> 1) : c >>> 1; CRC_TABLE[n] = c >>> 0; }
  }
  let c = 0xffffffff;
  for (let i = 0; i < str.length; i++) c = CRC_TABLE[(c ^ str.charCodeAt(i)) & 0xff] ^ (c >>> 8);
  return (c ^ 0xffffffff) >>> 0;
}

/** decode the 64-byte Ts4AnimView (little endian, 4-byte fields) from a DataView at byte offset o */
export function decodeAnimView(dv, o = 0) {
  const u = (k) => dv.getUint32(o + k, true), i = (k) => dv.getInt32(o + k, true), f = (k) => dv.getFloat32(o + k, true);
  return { layer: u(4), clip: i(8), clipHash: u(12), frame: f(16), rate: f(20), prevClip: i(24), prevHash: u(28),
           prevFrame: f(32), blend: f(36), group: i(40), subgroup: i(44), mirrored: u(48), contactFrame: f(52) };
}

/** read player p's view from a Ts4Core (port/core/js/ts4core.mjs) instance; null when the core has no ANIM data */
export function readAnimView(core, p) {
  const x = core?.x;
  if (!x || typeof x.ts4_anim_view !== "function") return null;
  if (x.ts4_anim_view_size && x.ts4_anim_view_size() !== ANIM_VIEW_SIZE) return null;   // header changed: refuse
  const ptr = core.scratch + 2048;
  const dv = new DataView(core.mem.buffer);
  dv.setUint32(ptr, ANIM_VIEW_SIZE, true);
  if (x.ts4_anim_view(core.corePtr, p, ptr) !== 0) return null;
  return decodeAnimView(new DataView(core.mem.buffer), ptr);
}

/** hash -> record index map for the browser tables (name per setup; the first record of a name wins) */
export function hashIndex(tables, setup) {
  const m = new Map();
  for (const c of tables.clips) { if (setup && c.setup !== setup) continue; const h = crc32(c.name); if (!m.has(h)) m.set(h, c.i); }
  return m;
}

/** view -> {record, time, prevRecord, prevTime, blend, mirrored} in seconds for GameAnimator.applyCoreState */
export function viewToState(v, byHash, fps = 60) {
  if (!v || v.clip < 0) return null;
  const rec = byHash.get(v.clipHash);
  if (rec == null) return null;
  const prev = v.prevClip >= 0 ? byHash.get(v.prevHash) : null;
  return { record: rec, time: v.frame / fps, prevRecord: prev ?? null, prevTime: v.prevFrame / fps,
           blend: v.prevClip >= 0 ? v.blend : 1, mirrored: !!v.mirrored, layer: LAYERS[v.layer] || "idle" };
}
