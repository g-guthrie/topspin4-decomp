// Gameplay "TV" broadcast camera: a readable reimplementation of the game's in-game camera shot
// (Pam::CameraEngine::CShotSourceInGame, compute = fn_888B4900 in Swing_DLL.dll) driven by the shot records of a venue's
// Shots.bin.  Pure functions + one small stateful class; no DOM, no three.js (node tests run it).
//
// Data: tools/port/camera_export.py writes <assets>/cameras/shots.json (all 96 shots of the venue); the readable copy of
// the in-game shots is data/camera/tv_cameras.yaml.  Units: centimetres (core frame: x along the court, net at x = 0,
// y up, z lateral), fov in radians as full angles.  The game frames a 4:3 picture: fov[0] is the angle across the 4:3
// width, fov[1] the vertical angle (tan(fov[0]/2) : tan(fov[1]/2) = 4 : 3 on every record).
//
// What the game does per frame (fn_888B4900, 0x684 bytes; see docs/port/presentation-and-audio.md section 2):
//   1. near = the player closest to the camera's end (min x for a camera at -x), far = the one closest to the other end;
//      with more than two players each end's pair is averaged (0.5 at 0x8814B910).
//   2. at = near + (far - near) * PositionPercent; if AtLimit.Use: at = min(max(at, AtLimit.Min), AtLimit.Max) per axis
//      (fn_888AE0F8: max first, then min, so a record with Min > Max pins the axis to Max).
//   3. fov = fov_default; d = |near.x| - FarLimit; if d >= 0: fov += d / (FarLimitMax - FarLimit) * (fov_max - fov)
//      else if (s = |near.z| - SideLimit) > 0: fov += s / (SideLimitMax - SideLimit) * (fov_max - fov).  No clamp.
//      The Loop byte (+0x7C) selects the [1] pair instead of [0]; 0 on every in-game record.
//   4. From and Up are the record's constants (From smooth time 0); At and Fov are smoothed with the record's
//      SmoothTime (s).  The engine-side smoother was not decoded: an exponential lag with that time constant is used
//      here (PORT ASSUMPTION).  SmoothMax = -1 (no rate limit) on every in-game record.
// Shot selection (fn_888F03B0): "CameraInGame" + (Widescreen | Normal) + "Left" + (Singles | Doubles) + option suffix
// (TV, TVFar, TVClose, TVZoom, TVZoomFar, TVZoomClose, TV3D).  The game always builds "Left"; which end the camera
// films from at run time (the Right records exist and mirror x) was not traced.  The port uses the human's end.

export const TV_OPTIONS = ['TV', 'TVFar', 'TVClose', 'TVZoom', 'TVZoomFar', 'TVZoomClose', 'TV3D'];

/** Fallback when shots.json is not exported: CameraInGameWidescreenLeftSinglesTV as decoded from Amsterdam Shots.bin
 *  (data/camera/tv_cameras.yaml).  Used only when no export is present; labelled so the HUD can say so. */
export const TV_FALLBACK = {
  name: 'CameraInGameWidescreenLeftSinglesTV', fallback: true,
  from: [-3300, 900, 0], up: [0, 100, 0], fov: [0.430438, 0.325015], fov_max: [0.464416, 0.351061],
  smooth_time: { from: 0, at: 0.1, up: 0, fov: 0.15 }, loop: 0,
  at_limit: { min: [-200, 0, -200], max: [-300, 0, 200], use: 1 },
  position_percent: 0.3, far_limit: 1500, far_limit_max: 1700, side_limit: 1500, side_limit_max: 2000,
};

export function shotName({ widescreen = true, side = -1, doubles = false, option = 'TV' } = {}) {
  return 'CameraInGame' + (widescreen ? 'Widescreen' : 'Normal') + (side < 0 ? 'Left' : 'Right') +
         (doubles ? 'Doubles' : 'Singles') + option;
}

/** Mirror a Left record to the other end (x negated; the x limits swap).  Used only when the Right record is missing. */
export function mirrorShot(s) {
  const nx = (v) => [-v[0], v[1], -v[2]];
  const lim = s.at_limit;
  return { ...s, name: s.name + ' (mirrored)', from: nx(s.from),
           at_limit: { use: lim.use, min: [-lim.max[0], lim.min[1], lim.min[2]], max: [-lim.min[0], lim.max[1], lim.max[2]] } };
}

/** near / far points of fn_888B4900 for a camera at the `side` end (-1: camera at -x). players: [[x,y,z], ...] (cm). */
export function nearFar(players, side) {
  if (players.length > 2) {
    const ends = [[], []];
    for (const p of players) ends[p[0] * side > 0 ? 0 : 1].push(p);
    const avg = (a) => (a.length ? [0, 1, 2].map((k) => a.reduce((n, p) => n + p[k], 0) / a.length) : [0, 0, 0]);
    return { near: avg(ends[0]), far: avg(ends[1]) };
  }
  let near = players[0], far = players[0];
  for (const p of players) {
    if (p[0] * side > near[0] * side) near = p;
    if (p[0] * side < far[0] * side) far = p;
  }
  return { near, far };
}

/** Clamp of fn_888AE0F8: max(v, min) first, then min(v, max), per axis. */
export function clampAt(at, lim) {
  if (!lim || !lim.use) return at.slice();
  return at.map((v, k) => Math.min(Math.max(v, lim.min[k]), lim.max[k]));
}

/** fov widening of fn_888B4900 (returns the full angle of the selected pair index `k`). */
export function shotFov(s, near, k = s.loop ? 1 : 0) {
  const def = s.fov[k], max = s.fov_max[k];
  const d = Math.abs(near[0]) - s.far_limit;
  if (d >= 0) return def + (d / (s.far_limit_max - s.far_limit || 1)) * (max - def);
  const e = Math.abs(near[2]) - s.side_limit;
  if (e > 0) return def + (e / (s.side_limit_max - s.side_limit || 1)) * (max - def);
  return def;
}

/** Target of one frame: {from, at, up, fov (4:3 width angle), fovV (vertical angle)} in cm / radians. */
export function tvGoal(s, players, side) {
  const { near, far } = nearFar(players, side);
  const pp = s.position_percent;
  const at = clampAt([0, 1, 2].map((k) => near[k] + (far[k] - near[k]) * pp), s.at_limit);
  const fov = shotFov(s, near);
  return { from: s.from.slice(), at, up: s.up || [0, 100, 0], fov, fovV: 2 * Math.atan(Math.tan(fov / 2) * 0.75), near, far };
}

/** exponential lag with time constant T (s); T <= 0 snaps (PORT ASSUMPTION for the engine's SmoothTime). */
export function smooth(cur, goal, T, dt) {
  if (!(T > 0) || dt <= 0) return goal;
  const k = 1 - Math.exp(-dt / T);
  return Array.isArray(goal) ? goal.map((g, i) => cur[i] + (g - cur[i]) * k) : cur + (goal - cur) * k;
}

/** Picks a shot record by name from shots.json (or the fallback) and smooths it frame to frame. */
export class TvCamera {
  constructor(shots = null) {
    this.byName = new Map();
    for (const s of shots || []) if (s.type === 'CShotSourceInGame' || s.from) this.byName.set(s.name, s);
    this.option = 'TV'; this.widescreen = true; this.doubles = false;
    this.state = null; this.shot = null;
  }

  get loaded() { return this.byName.size > 0; }

  pick(side) {
    const name = shotName({ widescreen: this.widescreen, side, doubles: this.doubles, option: this.option });
    let s = this.byName.get(name);
    if (!s) {
      const left = this.byName.get(shotName({ widescreen: this.widescreen, side: -1, doubles: this.doubles, option: this.option }));
      const base = left || TV_FALLBACK;
      s = side < 0 ? base : mirrorShot(base);
    }
    if (this.shot !== s) { this.shot = s; this.state = null; }
    return s;
  }

  setOption(opt) { if (TV_OPTIONS.includes(opt)) { this.option = opt; this.state = null; } }

  /** players: [[x,y,z] cm...], side: the end the camera films from (-1 = -x).  Returns metres + vertical fov in degrees. */
  update(dt, players, side) {
    const s = this.pick(side);
    const g = tvGoal(s, players, side);
    const st = s.smooth_time || {};
    if (!this.state) this.state = { at: g.at, fov: g.fov };
    else this.state = { at: smooth(this.state.at, g.at, st.at, dt), fov: smooth(this.state.fov, g.fov, st.fov, dt) };
    const fovV = 2 * Math.atan(Math.tan(this.state.fov / 2) * 0.75);
    return { name: s.name, fallback: !!s.fallback, pos: g.from.map((v) => v / 100), look: this.state.at.map((v) => v / 100),
             up: g.up, fovDeg: (fovV * 180) / Math.PI };
  }
}
