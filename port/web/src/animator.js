// RigAnimator: drives one PlayerRig's AnimationMixer from simulation state.
//   * locomotion: looping clips (idle / jog / run / rush) cross-faded by weight, playback rate from the sim speed
//   * swing: one clip whose TIME is set from the core's swing_t (progress to the contact tick), so the racket-contact
//     marker lands exactly on the contact tick; after contact the follow-through plays out over the recovery window.
// Which clip plays for what comes from clipmap.config.json (PLACEHOLDERS until the record -> clip mapping is known)
// via the pure functions of helpers.js.
import * as THREE from "three";
import { mirrorTrackValues, clamp, locomotionClass, locomotionClipIndex, locomotionRate, pickSwingClip, swingClipTime, LOCO, SWING_CLASSES } from "./helpers.js";

/**
 * Remove root motion: the horizontal (x, z) translation of the hips is pinned to its first key, because the simulation
 * owns the player's position (the game drives it from the animation's root motion, which the port does not use yet).
 */
export function inPlaceClip(clip) {
  for (const t of clip.tracks) {
    if (t.name !== "B_Hips.position") continue;
    const v = t.values;
    for (let i = 3; i + 2 < v.length; i += 3) { v[i] = v[0]; v[i + 2] = v[2]; }
  }
  return clip;
}

/** a copy of the clip with every position / quaternion track mirrored (see mirrorTrackValues) */
export function mirrorClip(clip) {
  const tracks = clip.tracks.map((t) => {
    const kind = t.name.slice(t.name.lastIndexOf(".") + 1);
    const vals = kind === "position" || kind === "quaternion" ? mirrorTrackValues(kind, t.values) : t.values;
    return new t.constructor(t.name, t.times, vals);
  });
  return new THREE.AnimationClip(clip.name + "_mirrored", clip.duration, tracks);
}

export class ClipLibrary {
  /** assetsBase: URL of work/port/assets/ ; anim: animations.json ; cfg: clipmap.config.json ; clipMap: optional record->clip */
  constructor(loader, assetsBase, anim, cfg, clipMap) {
    this.loader = loader; this.base = assetsBase; this.anim = anim; this.cfg = cfg; this.clipMap = clipMap || null;
    this.clips = new Map((anim?.clips || []).map((c) => [c.index, c]));
    this.loaded = new Map();           // index -> THREE.AnimationClip (as exported: the bone-line skeleton's frame)
    this.loadedMirrored = new Map();   // index -> the same clip z-mirrored for the skinned player export (docs/assets.md s7)
    this.missing = new Set();          // wanted but not exported
    this.failed = [];
  }

  /** every clip index the presentation can ask for: the locomotion set and the pick of every swing class */
  wanted() {
    const set = new Set();
    for (const k of LOCO) { const e = this.locoPick(k); if (e) set.add(e.clip); }
    for (const cls of SWING_CLASSES) { const p = this.pick(cls); if (p) set.add(p.clip); }
    return [...set];
  }

  locoPick(name) { return locomotionClipIndex(this.cfg.locomotion?.[name], { clips: this.clips, records: this.anim?.records, clipMap: this.clipMap }); }

  async get(index) {
    if (this.loaded.has(index)) return this.loaded.get(index);
    const meta = this.clips.get(index);
    if (!meta || !meta.file) { this.missing.add(index); return null; }
    let lastErr = null;
    for (let attempt = 0; attempt < 4; attempt++) {                // a busy local dev server may reset connections: retry
      try {
        const gltf = await this.loader.loadAsync(this.base + meta.file);
        const clip = gltf.animations[0] || null;
        if (clip) this.loaded.set(index, inPlaceClip(clip));
        return clip;
      } catch (e) { lastErr = e; await new Promise((r) => setTimeout(r, 150 * (attempt + 1))); }
    }
    this.failed.push("core:" + index + ": " + lastErr.message);
    return null;
  }

  async preload() {
    const queue = this.wanted();
    const worker = async () => { for (let i = queue.shift(); i !== undefined; i = queue.shift()) await this.get(i); };
    await Promise.all([worker(), worker(), worker()]);     // 3 at a time
    for (const [i, c] of this.loaded) if (!this.loadedMirrored.has(i)) this.loadedMirrored.set(i, mirrorClip(c));
  }
  /** the clip for a rig: mirrored when the rig is the skinned export */
  forRig(index, rig) { return (rig.skinned ? this.loadedMirrored : this.loaded).get(index) || null; }

  pick(cls) { return pickSwingClip(cls, this.cfg, { clips: this.clips, records: this.anim?.records, clipMap: this.clipMap }); }
}

const FADE = 0.12;                    // seconds to cross-fade between poses

export class RigAnimator {
  constructor(rig, lib) {
    this.rig = rig; this.lib = lib;
    this.loco = {};                   // class -> {action, w}
    this.locoInfo = {};
    this.swing = null;                // {action, w, contact, duration, info}
    this.current = 'idle';
    this.swingActive = false;
    this.lastInfo = null;
  }

  _locoAction(cls) {
    if (this.loco[cls]) return this.loco[cls];
    const pick = this.lib.locoPick(cls);
    const clip = pick ? this.lib.forRig(pick.clip, this.rig) : null;
    this.locoInfo[cls] = pick;
    if (!clip || !this.rig.mixer) return (this.loco[cls] = { action: null, w: 0 });
    const action = this.rig.mixer.clipAction(clip);
    action.setLoop(THREE.LoopRepeat, Infinity);
    action.play(); action.weight = 0;
    return (this.loco[cls] = { action, w: 0 });
  }

  /** start a swing of class `cls`; returns the picked clip info ({clip, contact, source, placeholder}) or null */
  beginSwing(cls) {
    const info = this.lib.pick(cls);
    this.lastInfo = info;
    const clip = info ? this.lib.forRig(info.clip, this.rig) : null;
    if (!info || !clip || !this.rig.mixer) { this.swing = null; this.swingActive = false; return info; }
    if (this.swing?.action) { this.swing.action.stop(); }
    const action = this.rig.mixer.clipAction(clip);
    action.setLoop(THREE.LoopOnce, 1);
    action.clampWhenFinished = true;
    action.play(); action.paused = true; action.time = 0; action.weight = 0;
    this.swing = { action, w: 0, contact: info.contact, duration: clip.duration, info };
    this.swingActive = true;
    return info;
  }

  endSwing() { this.swingActive = false; }

  /**
   * drive: { speed (cm/s), tun {walk,jog,rush}, swingState, swingT, recoveryFrac, windUp (clip seconds or null) }
   * Called once per rendered frame (dt real seconds).
   */
  update(dt, drive) {
    const rig = this.rig;
    if (!rig.mixer) return;
    const cfgLoco = this.lib.cfg.locomotion || {};
    const cls = locomotionClass(drive.speed, drive.tun, cfgLoco.idleMaxCms ?? 30);
    this.current = cls;
    // swing time / weight
    let swingTarget = 0;
    if (this.swing && this.swingActive && drive.windUp != null && drive.swingState === 0) {
      this.swing.action.time = clamp(drive.windUp, 0, this.swing.duration); swingTarget = 1;      // serve charge pose
    } else if (this.swing && this.swingActive && drive.swingState > 0) {
      const t = swingClipTime({ swingState: drive.swingState, swingT: drive.swingT, contact: this.swing.contact,
                                duration: this.swing.duration, recoveryFrac: drive.recoveryFrac });
      if (t != null) { this.swing.action.time = t; swingTarget = 1; }
    } else if (this.swingActive && drive.swingState === 0) { this.swingActive = false; }
    const step = dt / FADE;
    for (const name of LOCO) {
      const l = this._locoAction(name);
      if (!l.action) continue;
      const want = name === cls ? 1 : 0;
      l.w = clamp(l.w + clamp(want - l.w, -step, step), 0, 1);
      l.action.weight = l.w * (1 - (this.swing ? this.swing.w : 0));
      l.action.enabled = l.action.weight > 0.001 || name === cls;
      if (name === cls) l.action.timeScale = locomotionRate(drive.speed, cfgLoco[name]?.nominalSpeedCms ?? 0);
    }
    if (this.swing) {
      this.swing.w = clamp(this.swing.w + clamp(swingTarget - this.swing.w, -step, step), 0, 1);
      this.swing.action.weight = this.swing.w;
      this.swing.action.enabled = this.swing.w > 0.001 || swingTarget > 0;
    }
    rig.mixer.update(dt);                 // the swing action is paused: it only evaluates at its set time
    rig.refreshBones();
  }
}
