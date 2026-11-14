// Pure animation logic for the player characters: no three.js, unit-tested under node (test/players.test.mjs).
// It ports the engine rules documented in docs/gameplay/movement-and-animation.md (agent G6), and follows the
// readable C in ref/gameplay/locomotion.c and anim_select.c function by function (names in the comments).
// Confidence tags (V read from code or data, I inferred) are those of the G6 note; port choices are marked PORT.
//
// The tables come from work/port/assets/players/anim_rules.json (tools/ts4_players.py animrules): clips[i] is
// AnimationsDB record i {name, frames, group, sub, setup, speed_coef, ignore_speed_coef, no_mirror, ev, tr, roty, q},
// groups [{setup, index, id, first, count, allow_speed_coef, subgroups[{id, first, count, abs}]}], movesets
// [{id, kind, sectors[{group, sub}]}].

export const FPS = 60;                         // engine tick and Havok clip rate (frames are 60 Hz, V)

// ------------------------------------------------------------------------------------------------ sectors
export const SECTOR = { FRONT: 0, FRONT_LEFT: 1, LEFT: 2, BACK_LEFT: 3, BACK: 4, BACK_RIGHT: 5, RIGHT: 6, FRONT_RIGHT: 7, STAND: 8, BACK_ALT: 9 };
export const SECTOR_NAMES = ["Front", "FrontLeft", "Left", "BackLeft", "Back", "BackRight", "Right", "FrontRight", "Stand", "BackAlt"];
// TransitionEvent Direction values for each sector (lo_sector_direction, V)
const SECTOR_DIR = [1, 8, 7, 6, 5, 4, 3, 2, 0, 5];

/** relative angle of travel to facing in [0, 2pi), counter-clockwise (left) positive; yaw 0 faces +z (locomotion.c) */
export function relAngle(facingYaw, dx, dz) {
  let a = Math.atan2(dx, dz) - facingYaw;
  const tp = 2 * Math.PI;
  a %= tp; if (a < 0) a += tp;
  return a;
}

/** lo_sector8: eight sectors counter-clockwise from Front, STAND inside the dead zone, BACK_ALT for Back + look left */
export function sector8(facingYaw, dx, dz, deadZoneSq = 1e-6, lookLeft = false) {
  if (dx * dx + dz * dz <= deadZoneSq) return SECTOR.STAND;
  const s = Math.floor(relAngle(facingYaw, dx, dz) / (Math.PI / 4) + 0.5) & 7;
  return s === SECTOR.BACK && lookLeft ? SECTOR.BACK_ALT : s;
}
export const sectorDirection = (s) => SECTOR_DIR[s] ?? 0;

/** lo_moveset_pick: falls back to Back for a missing BackAlt and to entry 0 out of range */
export function movesetPick(ms, s) {
  if (!ms || !ms.sectors || !ms.sectors.length) return null;
  let i = s;
  if (i === SECTOR.BACK_ALT && ms.sectors.length <= SECTOR.BACK_ALT) i = SECTOR.BACK;
  if (i < 0 || i >= ms.sectors.length) i = 0;
  return ms.sectors[i];
}

/** the port's frame (x toward the far court, z across) -> the locomotion yaw convention (yaw 0 = +z, left positive) */
/** port frame (x toward the opponent, z = right when facing +x) -> locomotion frame (lo_x = -z, lo_z = x): yaw = -heading */
export function viewHeadingToYaw(heading) { return -heading; }
export const viewDirToLo = (vx, vz) => [-vz, vx];

// ------------------------------------------------------------------------------------------------ clip clock
/** lo_play_rate (product is I, each input V) */
export function playRate(clip, { globalCoef = 1, groupAllowsCoef = false, gameplayCoef = 1, transitionSpeed = 1 } = {}) {
  let r = globalCoef * transitionSpeed;
  if (!clip.ignore_speed_coef) r *= clip.speed_coef ?? 1;
  if (groupAllowsCoef) r *= gameplayCoef;
  return r;
}
/** lo_cycle_phase: wrap a looping locomotion phase between the Cycle_In / Cycle_Out AnimEvents (I) */
export function cyclePhase(phase, cin, cout) {
  const len = cout - cin;
  if (!(len > 0)) return phase;
  while (phase > cout) phase -= len;
  return phase;
}
/** lo_blend_weight: linear cross-fade over the rule's BlendIn frames (I: 15 frames, 10 for Allow rule 9) */
export const blendWeight = (frames, blendFrames) => (blendFrames <= 0 ? 1 : Math.min(1, Math.max(0, frames / blendFrames)));
/** lo_phase_to_frame (fn_886D1408, V) */
export const phaseToFrame = (phase, t0, frameCount, base, end) => Math.min(end, Math.max(base, (phase - t0) * (frameCount - 1) + base));
/** lo_roty_offset: code-driven yaw of RotY_JogType / RotY_BasicTransition clips (data V, linear curve I) */
export function rotyOffset(frame, start, end, inAngle, outAngle) {
  if (frame <= start) return inAngle;
  if (frame >= end || end <= start) return outAngle;
  return inAngle + (outAngle - inAngle) * (frame - start) / (end - start);
}
/** pl_rate_to_target (fn_886C72E0, V): clip frames per tick so that the event frame lands on the target tick */
export function rateToTarget(eventFrame, clipFrame, targetTick, nowTick, prevRate, decay = 1) {
  if (nowTick <= targetTick) return (eventFrame - clipFrame) / (targetTick - nowTick + 1);
  return prevRate * decay;
}
/** clip events by name (AnimEventList rows [id, pos, duration, orientation]; positions are phases 0..1, V) */
export function eventPhase(clip, id) { const e = (clip.ev || []).find((r) => r[0] === id); return e ? e[1] : null; }
export function cycleWindow(clip) {
  const a = eventPhase(clip, "Cycle_In"), b = eventPhase(clip, "Cycle_Out");
  return a != null && b != null && b > a ? [a, b] : null;
}
/** TransitionEvents [dirMask, paceMask, pos, dur, reactivity, startBlend, in, out]: is an Out window open (lo_can_leave, I) */
export function canLeave(clip, phase, direction = 0) {
  for (const t of clip.tr || []) {
    if (!t[7]) continue;
    if (phase < t[2] || phase > t[2] + t[3]) continue;
    if (direction && t[0] && !((t[0] >>> direction) & 1)) continue;
    return true;
  }
  return !(clip.tr && clip.tr.length);
}

// ------------------------------------------------------------------------------------------------ tables
export class AnimTables {
  constructor(rules) {
    this.r = rules;
    this.clips = rules.clips;
    this.groupsBySetup = {};
    for (const g of rules.groups) (this.groupsBySetup[g.setup] ||= []).push(g);
    this.movesets = new Map(rules.movesets.map((m) => [m.id, m]));
    this.byName = new Map();
    for (const c of rules.clips) { const k = c.setup + ":" + c.name; if (!this.byName.has(k)) this.byName.set(k, c.i); }
  }
  group(setup, id) { return (this.groupsBySetup[setup] || []).find((g) => g.id === id) || null; }
  /** clip records of a sector {group, sub} for a setup ("Men" / "Women") */
  sectorClips(setup, entry) {
    const g = entry && this.group(setup, entry.group);
    const s = g && g.subgroups.find((x) => x.id === entry.sub);
    if (!s) return [];
    const out = [];
    for (let i = s.first; i < s.first + s.count; i++) if (this.clips[i]) out.push(this.clips[i]);
    return out;
  }
  groupOf(clip) { return (this.groupsBySetup[clip.setup] || []).find((g) => g.index === clip.group) || null; }
  find(setup, name) { const i = this.byName.get(setup + ":" + name); return i == null ? null : this.clips[i]; }
}

/**
 * Choose the clip inside a sub-group (G6 s2.1 step 5; the qualifier filters are mostly unknown for locomotion, so PORT:
 * prefer a clip whose name carries every wanted token, then the first one that the caller can play).
 */
export function chooseInSector(clips, { prefer = [], avoid = ["Bad", "Wrong"], playable = () => true } = {}) {
  const ok = clips.filter((c) => playable(c));
  if (!ok.length) return null;
  const score = (c) => prefer.reduce((s, t) => s + (c.name.includes(t) ? 2 : 0), 0) - avoid.reduce((s, t) => s + (c.name.includes(t) ? 1 : 0), 0);
  return ok.slice().sort((a, b) => score(b) - score(a) || a.i - b.i)[0];
}

// ------------------------------------------------------------------------------------------------ swing timing
/**
 * Time warp to contact (gp7 s4/s5, player-and-movement s4.4; V formulas): the swing clip runs from the swing start at the
 * rate that puts its EventRacket frame on the contact tick, then at the clip's normal rate.  Returns the clip time in
 * seconds for the core's swing progress `swingT` (0..1 up to contact, Ts4PlayerView.swing_t) or the recovery fraction.
 */
export function swingClipTime({ clip, swingState, swingT, recoveryFrac, startPhase = 0 }) {
  const frames = clip.frames || 1, dur = (frames - 1) / FPS;
  const contact = eventPhase(clip, "EventRacket");
  if (contact == null) return null;
  if (swingState === 1) return (startPhase + (contact - startPhase) * Math.min(1, Math.max(0, swingT))) * dur;
  if (swingState === 2) return (contact + (1 - contact) * Math.min(1, Math.max(0, recoveryFrac))) * dur;
  return null;
}

/** mirroring (as_mirror_mode, V/I): left-handed players play right-handed clips mirrored unless the clip is NoMirror */
export const mirrorFor = (clip, leftHanded) => !!leftHanded && !clip.no_mirror;

/** PlayerHeight band -> step factor f769c520 (height_steps, V data; use as root-motion / visual scale is I) */
export function heightScale(heightSteps, setupIndex, heightCm) {
  const bands = {};
  for (const [s, b, k, v] of heightSteps || []) if (s === setupIndex) (bands[b] ||= {})[k] = v;
  for (const b of Object.values(bands)) if (heightCm >= b.MinHeight && heightCm < b.MaxHeight) return b.f769c520 ?? 1;
  return 1;
}

// ------------------------------------------------------------------------------------------------ swing record choice
/** SwingType / SwingEffect / PositionOnCourt keys of a port swing class (classes of helpers.js) */
export const SWING_KEYS = {
  fh_topspin: { SwingType: "FH", SwingEffect: "TopSpin", PositionOnCourt: "Baseline" },
  bh_topspin: { SwingType: "BH", SwingEffect: "TopSpin", PositionOnCourt: "Baseline" },
  fh_flat: { SwingType: "FH", SwingEffect: "Flat", PositionOnCourt: "Baseline" },
  bh_flat: { SwingType: "BH", SwingEffect: "Flat", PositionOnCourt: "Baseline" },
  fh_slice: { SwingType: "FH", SwingEffect: "Slice", PositionOnCourt: "Baseline" },
  bh_slice: { SwingType: "BH", SwingEffect: "Slice", PositionOnCourt: "Baseline" },
  fh_volley: { SwingType: "FH", PositionOnCourt: "Volley" },
  bh_volley: { SwingType: "BH", PositionOnCourt: "Volley" },
  smash: { SwingCategory: "Smash" },
  serve: { name: "Swing_Serve" },
};
/** as_swing_matches subset: Category Swing plus the known keys; zero-mask (absent) qualifiers do not constrain (I) */
export function swingMatches(clip, keys) {
  if (keys.name) return clip.name.startsWith(keys.name);
  const q = clip.q || {};
  if (!(q.Category || []).includes("Swing")) return false;
  for (const [k, v] of Object.entries(keys)) { const have = q[k]; if (have && have.length && !have.includes(v)) return false; if (!have && k === "SwingType") return false; }
  return eventPhase(clip, "EventRacket") != null;
}

/** yaw (rad, about +y) of a quaternion [x, y, z, w] */
export function quatYaw([x, y, z, w]) { return Math.atan2(2 * (w * y + x * z), 1 - 2 * (x * x + y * y)); }

/**
 * Facing correction between the bind pose and the game's clips (M: every exported Core clip carries B_Hips at yaw
 * about -90 deg in Havok space, the bind pose at +90 deg, so an animated player faces 180 deg from the bind-pose forward
 * PlayerRig aligns to +x).  Returns 0 or PI: the hips yaw difference rounded to a half turn (stance twist, e.g. the
 * idle's -104 deg, is ignored).
 */
export function facingOffset(restHipsQ, clipHipsQ) {
  let d = quatYaw(clipHipsQ) - quatYaw(restHipsQ);
  d = Math.atan2(Math.sin(d), Math.cos(d));
  return Math.abs(d) > Math.PI / 2 ? Math.PI : 0;
}
