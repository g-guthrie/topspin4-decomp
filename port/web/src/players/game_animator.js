// Drives a skinned player (PlayerRig from ../player.js loaded with a tools/ts4_players.py export) with the game's own
// clips, following the engine rules of docs/gameplay/movement-and-animation.md (pure parts in anim_logic.js):
//   * locomotion: move set (Jog / Rush / Sidesteps family) -> sector of the travel direction relative to facing -> clip
//     of that sub-group; loops between Cycle_In / Cycle_Out; cross-fade of the rule's 15 frames on a change; play rate =
//     SpeedCoef product (lo_play_rate) times the speed match to the sim (PORT: the sim owns position, the game moves the
//     player by the clip's root motion, so the rate is scaled by sim speed / clip root speed to keep the feet planted).
//   * swing: one record per swing, time-warped so EventRacket lands on the contact tick (swing_t from the core).
//   * left-handers: the clip is pose-mirrored (pose_mirror.js); the mesh is not mirrored.
// When the core publishes a per-tick animation state (agent P1: record index, phase, rate, mirror), pass it as
// state.anim and it is played verbatim instead of the derivation here (see applyCoreState).
import * as THREE from "three";
import { mirrorTrackValues } from "../helpers.js";
import { makeMirror } from "./pose_mirror.js";
import {
  FPS, SECTOR, sector8, movesetPick, playRate, cyclePhase, cycleWindow, chooseInSector, swingClipTime,
  swingMatches, SWING_KEYS, mirrorFor, eventPhase, viewHeadingToYaw, viewDirToLo,
} from "./anim_logic.js";

const BLEND_FRAMES = 15;                      // TransitionRule BlendIn/OutFrameCount (15/15, V data)

// ------------------------------------------------------------------------------------------------ clip store
/** clip_map.json -> record index -> Core clip index (only single-clip records: "core:<n>") */
export function recordToCore(clipMap) {
  const out = new Map();
  const put = (i, v) => {
    if (v && typeof v === "object" && v.poly && !/^(single|blend|set)/.test(v.poly)) return;   // AOD-appended records: skip
    const s = typeof v === "string" ? v : v?.primary ?? v?.clip ?? null;
    const m = typeof s === "string" ? s.match(/^core:(\d+)$/) : null;
    if (m && Number.isFinite(i)) out.set(i, +m[1]);
  };
  if (Array.isArray(clipMap?.map)) clipMap.map.forEach((v, k) => put(v?.index ?? k, v));
  else for (const [k, v] of Object.entries(clipMap?.map ?? clipMap?.records ?? clipMap ?? {})) put(k.startsWith("#") ? +k.slice(1) : +k, v);
  return out;
}

export class ClipStore {
  /** loader: GLTFLoader; base: assets URL; animDb: animations.json ({clips: [{index, file}]}); rec2core: Map;
   *  chains: players/clip_chains.json (tools/ts4_players.py aodclips): AOD-only and Core lead-in + AOD records */
  constructor(loader, base, animDb, rec2core, chains = null) {
    this.loader = loader; this.base = base; this.rec2core = rec2core;
    this.chains = chains?.chains || {}; this.aodFiles = chains?.aod_files || {};
    this.files = new Map((animDb?.clips || []).map((c) => [c.index, c.file]));
    this.raw = new Map(); this.byKey = new Map(); this.rootSpeed = new Map(); this.missing = new Set(); this.mirrors = new WeakMap();
  }
  playable(record) {
    const ch = this.chains[record];
    if (ch && ch.aod) return !!this.aodFiles[ch.aod] && (ch.core == null || !!this.files.get(ch.core));
    const c = this.rec2core.get(record); return c != null && !!this.files.get(c);
  }
  async preload(records) {
    const q = [...new Set(records)].filter((r) => this.playable(r));
    const worker = async () => { for (let r = q.shift(); r !== undefined; r = q.shift()) await this.loadRecord(r); };
    await Promise.all([worker(), worker(), worker()]);
  }
  async _gltfClip(file) {
    for (let k = 0; k < 4; k++) {
      try { return (await this.loader.loadAsync(this.base + file)).animations[0] || null; }
      catch (e) { if (k === 3) throw e; await new Promise((r) => setTimeout(r, 150 * (k + 1))); }
    }
    return null;
  }
  async loadRecord(record) {
    const ch = this.chains[record];
    const ci = ch && ch.aod ? "r" + record : this.rec2core.get(record);
    if (ci == null || this.raw.has(ci)) return;
    if (ch && ch.aod) this.rec2core.set(record, ci);
    const file = ch && ch.aod ? null : this.files.get(ci);
    if (!file && !(ch && ch.aod)) { this.missing.add(record); return; }
    try {
      let clip;
      if (ch && ch.aod) {
        const aod = await this._gltfClip(this.aodFiles[ch.aod]);
        const lead = ch.core != null ? await this._gltfClip(this.files.get(ch.core)) : null;
        clip = lead && aod ? concatClips(lead, aod) : aod;
      } else clip = await this._gltfClip(file);
      if (!clip) return;
      // the skinned export is z-mirrored into a right-handed frame (docs/assets.md s7): mirror the Havok tracks the same way
      for (const t of clip.tracks) {
        const kind = t.name.slice(t.name.lastIndexOf(".") + 1);
        if (kind === "position" || kind === "quaternion") t.values = mirrorTrackValues(kind, t.values);
      }
      // root speed (cm/s in the horizontal plane) before the root is pinned: the sim owns the position (PORT)
      const hip = clip.tracks.find((t) => t.name === "B_Hips.position");
      let speed = 0;
      if (hip && hip.times.length > 1) {
        const v = hip.values, n = hip.times.length - 1;
        speed = Math.hypot(v[3 * n] - v[0], v[3 * n + 2] - v[2]) * 100 / Math.max(1e-3, hip.times[n] - hip.times[0]);
        for (let i = 1; i <= n; i++) { v[3 * i] = v[0]; v[3 * i + 2] = v[2]; }
      }
      this.rootSpeed.set(record, speed);
      this.raw.set(ci, clip);
    } catch (e) { this.missing.add(record); }
  }
  /** THREE.AnimationClip for a record, pose-mirrored for left-handers (needs the rig to build the mirror once) */
  get(record, mirrored, rig) {
    const ci = this.rec2core.get(record);
    const clip = ci == null ? null : this.raw.get(ci);
    if (!clip) return null;
    if (!mirrored) return clip;
    const key = ci + ":m";
    if (!this.byKey.has(key)) this.byKey.set(key, mirrorAnimationClip(clip, rigMirror(rig, this.mirrors)));
    return this.byKey.get(key);
  }
}

/** Core lead-in then AOD clip (record frames = Core frames + AOD frames, clip-map.md): one clip, the second part
 *  offset by the first's duration plus one 60 Hz frame; a track missing on one side holds the other's end value */
export function concatClips(a, b) {
  const off = a.duration + 1 / 60;
  const names = new Set([...a.tracks, ...b.tracks].map((t) => t.name));
  const tracks = [];
  for (const n of names) {
    const ta = a.tracks.find((t) => t.name === n), tb = b.tracks.find((t) => t.name === n);
    const src = ta || tb, size = src.getValueSize();
    const ia = ta ? ta : null, ib = tb ? tb : null;
    const timesA = ia ? Array.from(ia.times) : [0, a.duration];
    const valsA = ia ? Array.from(ia.values) : [...Array.from(ib.values.slice(0, size)), ...Array.from(ib.values.slice(0, size))];
    const timesB = ib ? Array.from(ib.times, (t) => t + off) : [off, off + b.duration];
    const last = valsA.slice(valsA.length - size);
    const valsB = ib ? Array.from(ib.values) : [...last, ...last];
    tracks.push(new src.constructor(n, [...timesA, ...timesB], [...valsA, ...valsB]));
  }
  return new THREE.AnimationClip(a.name + "+" + b.name, off + b.duration, tracks);
}

/** rest locals / parents of a rig's skeleton (bone order = scene traversal of B_* nodes) -> pose mirror */
export function rigMirror(rig, cache) {
  if (cache && cache.has(rig)) return cache.get(rig);
  const bones = [];
  rig.skeletonScene.traverse((o) => { if (/^B_/.test(o.name) && !o.isMesh && !o.isSkinnedMesh) bones.push(o); });
  const index = new Map(bones.map((b, i) => [b, i]));
  const names = bones.map((b) => b.name);
  const parents = bones.map((b) => (index.has(b.parent) ? index.get(b.parent) : -1));
  const rest = bones.map((b) => ({ t: b.position.toArray(), q: b.quaternion.toArray(), s: b.scale.toArray() }));
  const m = { names, parents, rest, mirror: makeMirror(names, parents, rest) };
  if (cache) cache.set(rig, m);
  return m;
}

/** bake a pose-mirrored copy of a clip (all tracks resampled at the clip's own key times) */
export function mirrorAnimationClip(clip, rm) {
  const { names, rest, mirror } = rm;
  const byName = new Map(clip.tracks.map((t) => [t.name, t]));
  const ref = clip.tracks.find((t) => t.name.endsWith(".quaternion")) || clip.tracks[0];
  const times = ref.times;
  const interp = new Map();
  for (const t of clip.tracks) interp.set(t.name, t.createInterpolant());
  const outT = names.map(() => []), outQ = names.map(() => []), outS = names.map(() => []);
  for (const time of times) {
    const locals = names.map((n, i) => {
      const r = rest[i];
      const get = (k, def) => { const ip = interp.get(n + "." + k); return ip ? Array.from(ip.evaluate(time)) : def; };
      return { t: get("position", r.t), q: get("quaternion", r.q), s: get("scale", r.s) };
    });
    const m = mirror.pose(locals);
    m.forEach((p, i) => { outT[i].push(...p.t); outQ[i].push(...p.q); outS[i].push(...p.s); });
  }
  const tracks = [];
  names.forEach((n, i) => {
    if (!byName.has(n + ".quaternion") && !byName.has(n + ".position") && !mirror.counterparts.some((c, j) => c === i && j !== i && byName.has(names[j] + ".quaternion"))) return;
    tracks.push(new THREE.VectorKeyframeTrack(n + ".position", times, outT[i]));
    tracks.push(new THREE.QuaternionKeyframeTrack(n + ".quaternion", times, outQ[i]));
  });
  return new THREE.AnimationClip(clip.name + "_lh", clip.duration, tracks);
}

// ------------------------------------------------------------------------------------------------ animator
export class GameAnimator {
  /** rig: PlayerRig (skinned); tables: AnimTables; store: ClipStore; opts {setup: "Men"|"Women", leftHanded} */
  constructor(rig, tables, store, opts = {}) {
    this.rig = rig; this.tables = tables; this.store = store;
    this.setup = opts.setup || "Men"; this.leftHanded = !!opts.leftHanded;
    this.loco = null;          // {record, clip, action, phase, w}
    this.fading = [];          // actions fading out
    this.swing = null;         // {record, clip, action, w}
    this.info = {};
  }

  playable = (c) => this.store.playable(c.i);

  /** locomotion move set for a planar speed (cm/s) and the sim thresholds (PORT: regime from speed; the planner's
   *  regime (Rush 20 / JogJogPrepared 21 / JogPrepared 22) is not in Ts4PlayerView yet) */
  movesetFor(speed, tun) {
    if (speed < (tun.idleMax ?? 30)) return { ms: this.tables.movesets.get("Jog"), stand: true };
    if (speed > ((tun.jog ?? 480) + (tun.rush ?? 700)) / 2) return { ms: this.tables.movesets.get("Rush") };
    if (speed < ((tun.walk ?? 220) + (tun.jog ?? 480)) / 2) return { ms: this.tables.movesets.get("20485ec3") || this.tables.movesets.get("Jog") };  // sidesteps family
    return { ms: this.tables.movesets.get("Jog") };
  }

  locoClip(st, tun) {
    const speed = Math.hypot(st.vel[0], st.vel[2]);
    const { ms, stand } = this.movesetFor(speed, tun);
    const yaw = viewHeadingToYaw(st.heading);
    const [lx, lz] = viewDirToLo(st.vel[0], st.vel[2]);
    const s = stand ? SECTOR.STAND : sector8(yaw, lx, lz, 1, false);
    const entry = movesetPick(ms, s);
    let clips = this.tables.sectorClips(this.setup, entry);
    let c = chooseInSector(clips, { prefer: ["Normal", "Medium", "Good", "Loop"], playable: this.playable });
    if (!c) {   // fall back to the Front clip of the move set, then the idle
      clips = this.tables.sectorClips(this.setup, movesetPick(ms, stand ? SECTOR.STAND : SECTOR.FRONT));
      c = chooseInSector(clips, { playable: this.playable });
    }
    return { clip: c, sector: s, speed, moveset: ms?.id };
  }

  _action(record) {
    const clip = this.store.get(record, mirrorFor(this.tables.clips[record], this.leftHanded), this.rig);
    if (!clip) return null;
    const a = this.rig.mixer.clipAction(clip);
    a.setLoop(THREE.LoopRepeat, Infinity); a.play(); a.paused = true; a.weight = 0;
    return a;
  }

  /**
   * P1's core animation state played verbatim (core_anim.js viewToState): {record, time (s), prevRecord, prevTime,
   * blend, mirrored}.  The core owns selection, rate, time warp and blend; the renderer only samples.
   */
  applyCoreState(anim) {
    if (anim.mirrored != null) this.leftHanded = anim.mirrored;
    if (!this.loco || this.loco.record !== anim.record) {
      const prev = this.loco;
      this._switchLoco(anim.record);
      if (prev && prev.record === anim.prevRecord) this.fading = this.fading.filter((f) => f !== prev).concat([prev]);
    }
    if (this.loco?.action) {
      const dur = this.loco.action.getClip().duration;
      this.loco.action.time = Math.min(dur, anim.time != null ? anim.time : (anim.phase || 0) * dur);
      this.loco.w = anim.blend ?? 1;
    }
    for (const f of this.fading) {
      if (f.record === anim.prevRecord && anim.prevTime != null) { f.action.time = Math.min(f.action.getClip().duration, anim.prevTime); f.w = 1 - (anim.blend ?? 1); }
    }
    this.coreDriven = true;
  }

  _switchLoco(record) {
    const a = this._action(record);
    if (this.loco?.action) this.fading.push(this.loco);
    this.loco = a ? { record, clip: this.tables.clips[record], action: a, phase: 0, w: this.loco ? 0 : 1 } : null;
  }

  /**
   * state: {pos, vel (cm/s), heading, swingState, swingT, recoveryFrac, swingClass?, swingRecord?, anim?}
   * tun: {walk, jog, rush, idleMax, gameplayCoef}
   */
  update(dt, st, tun = {}) {
    const rig = this.rig;
    if (!rig.mixer) return;
    const fade = dt * FPS / BLEND_FRAMES;
    if (st.anim && st.anim.record != null) this.applyCoreState(st.anim);
    else {
      const pick = this.locoClip(st, tun);
      this.info.loco = pick.clip ? pick.clip.name : "none";
      this.info.sector = pick.sector; this.info.moveset = pick.moveset;
      if (pick.clip && (!this.loco || this.loco.record !== pick.clip.i)) this._switchLoco(pick.clip.i);
      if (this.loco?.action) {
        const c = this.loco.clip, dur = Math.max(1e-3, this.loco.action.getClip().duration);
        const g = this.tables.groupOf(c);
        let rate = playRate(c, { groupAllowsCoef: !!g?.allow_speed_coef, gameplayCoef: tun.gameplayCoef ?? 1 });
        const rs = this.store.rootSpeed.get(c.i) || 0;
        if (rs > 1 && pick.speed > 1) rate *= Math.min(2, Math.max(0.5, pick.speed / rs));     // PORT: foot planting
        let ph = this.loco.phase + rate * dt / dur;
        const cw = cycleWindow(c);
        ph = cw ? cyclePhase(ph, cw[0], cw[1]) : ph % 1;
        this.loco.phase = ph;
        this.loco.action.time = ph * dur;
        this.info.rate = rate;
      }
    }
    const core = !!(st.anim && st.anim.record != null);
    if (core) {                       // the core's view carries the swing too (layer swing / serve): sample only
      if (this.loco?.action) this.loco.action.weight = this.loco.w;
      for (const f of this.fading) f.action.weight = Math.max(0, f.w);
      this.fading = this.fading.filter((f) => { if (f.record !== st.anim.prevRecord) { f.action.stop(); return false; } return true; });
      rig.mixer.update(0);
      if (rig.refreshBones) rig.refreshBones();
      return;
    }
    // swing
    if (st.swingState === 1 && !this.swing) this.beginSwing(st);
    let swingTarget = 0;
    if (this.swing?.action) {
      const t = swingClipTime({ clip: this.swing.clip, swingState: st.swingState, swingT: st.swingT, recoveryFrac: st.recoveryFrac });
      if (t != null) { this.swing.action.time = Math.min(t, this.swing.action.getClip().duration); swingTarget = 1; }
      if (st.swingState === 0) this.swing.ending = true;
    }
    if (this.swing) {
      this.swing.w = Math.min(1, Math.max(0, this.swing.w + Math.sign((this.swing.ending ? 0 : swingTarget) - this.swing.w) * fade));
      if (this.swing.action) this.swing.action.weight = this.swing.w;
      if (this.swing.ending && this.swing.w <= 0) { this.swing.action?.stop(); this.swing = null; }
    }
    const sw = this.swing ? this.swing.w : 0;
    if (this.loco?.action) { this.loco.w = Math.min(1, this.loco.w + fade); this.loco.action.weight = this.loco.w * (1 - sw); }
    for (let i = this.fading.length - 1; i >= 0; i--) {
      const f = this.fading[i];
      f.w -= fade;
      if (f.w <= 0) { f.action.stop(); this.fading.splice(i, 1); } else f.action.weight = f.w * (1 - sw);
    }
    rig.mixer.update(0);
    if (rig.refreshBones) rig.refreshBones();
  }

  /** choose the swing record: the core's (P1) when given, else the class keys (as_swing_matches subset) */
  beginSwing(st) {
    let rec = st.swingRecord ?? null;
    if (rec == null) {
      const keys = SWING_KEYS[st.swingClass] || SWING_KEYS.fh_topspin;
      const cands = this.tables.clips.filter((c) => c.setup === this.setup && swingMatches(c, keys) && this.playable(c));
      const c = chooseInSector(cands, { prefer: ["GoodControl", "Normal", "Waist", "Stand"], playable: () => true });
      rec = c ? c.i : null;
    }
    const clip = rec != null ? this.tables.clips[rec] : null;
    const action = clip ? this._action(rec) : null;
    if (action) action.setLoop(THREE.LoopOnce, 1);
    this.swing = { record: rec, clip, action, w: 0, ending: false };
    this.info.swing = clip ? clip.name + " contact " + (eventPhase(clip, "EventRacket") ?? "?") : "none";
  }

  /** every record this animator may ask for (to preload) */
  wanted(tun = {}) {
    const set = new Set();
    for (const id of ["Jog", "Rush", "20485ec3"]) {
      const ms = this.tables.movesets.get(id);
      if (!ms) continue;
      for (const e of ms.sectors) for (const c of this.tables.sectorClips(this.setup, e)) set.add(c.i);
    }
    for (const keys of Object.values(SWING_KEYS)) {
      const c = this.tables.clips.filter((x) => x.setup === this.setup && swingMatches(x, keys));
      c.slice(0, 40).forEach((x) => set.add(x.i));
    }
    return [...set];
  }
}
