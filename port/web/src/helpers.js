// Pure helpers of the playable viewer: no DOM, no three.js, no WebAssembly, so `node` can unit-test them
// (port/web/test/helpers.test.mjs, run by tests/test_port_web.py).
//
// World frame everywhere: centimetres at the ts4core boundary (x along the court, net at x = 0, y up, z across),
// the renderer multiplies by CM.  Everything here is a port-side policy, not game data; the clearly-labelled
// placeholders are the clip mapping (clipmap.config.json) and the camera framing.

export const CM = 0.01;

// ------------------------------------------------------------------------------------------------ small maths
export const clamp = (v, lo, hi) => (v < lo ? lo : v > hi ? hi : v);
export const lerp = (a, b, t) => a + (b - a) * t;

/** shortest-arc interpolation of an angle in radians */
export function lerpAngle(a, b, t) {
  let d = (b - a) % (2 * Math.PI);
  if (d > Math.PI) d -= 2 * Math.PI;
  else if (d < -Math.PI) d += 2 * Math.PI;
  return a + d * t;
}

export const lerpVec = (a, b, t) => a.map((v, i) => lerp(v, b[i], t));
export const dist2d = (a, b) => Math.hypot(a[0] - b[0], a[2] - b[2]);

/** interpolate two positions, but snap to the new one when it jumped more than maxJump cm (point setup, serve reset) */
export function lerpOrSnap(a, b, t, maxJump) {
  return dist2d(a, b) > maxJump || Math.abs(a[1] - b[1]) > maxJump ? b.slice() : lerpVec(a, b, t);
}

/** frame-rate independent exponential smoothing toward goal; lambda in 1/s (larger = snappier) */
export const damp = (cur, goal, lambda, dt) => goal + (cur - goal) * Math.exp(-lambda * dt);
export const dampVec = (cur, goal, lambda, dt) => cur.map((v, i) => damp(v, goal[i], lambda, dt));

// ------------------------------------------------------------------------------------------------ fixed step
/**
 * Fixed-timestep accumulator.  advance(dt) returns how many simulation ticks to run for a frame of dt seconds
 * and sets `alpha` (0..1) = how far the render time is between the last two ticks.  More than maxSteps per frame
 * (tab was hidden, debugger) drops the backlog instead of spiralling.
 */
export class FixedStepper {
  constructor(hz = 60, maxSteps = 6) { this.dt = 1 / hz; this.maxSteps = maxSteps; this.acc = 0; this.alpha = 0; this.dropped = 0; }
  advance(frameSeconds) {
    this.acc += clamp(frameSeconds, 0, 1);
    let n = Math.floor(this.acc / this.dt + 1e-9);
    this.acc -= n * this.dt;
    if (n > this.maxSteps) { this.dropped += n - this.maxSteps; n = this.maxSteps; }
    if (this.acc < 0) this.acc = 0;
    this.alpha = clamp(this.acc / this.dt, 0, 1);
    return n;
  }
  reset() { this.acc = 0; this.alpha = 0; }
}

// ------------------------------------------------------------------------------------------------ snapshot interpolation
/** a player or ball jump (cm per tick) above this is a teleport (new point setup), not movement */
export const SNAP_JUMP_CM = 150;

/**
 * Blend two decoded snapshots (Ts4Core.snapshot()).  `prev` may be null on the first tick.  Discrete fields
 * (phase, states) come from `cur`.
 */
export function interpolateSnapshot(prev, cur, alpha) {
  if (!prev || prev.tick === cur.tick) return cur;
  const t = clamp(alpha, 0, 1);
  // a new phase can reposition everything (serve setup): do not slide across the court
  const reset = prev.phase !== cur.phase && (cur.phase === 'serve' || cur.phase === 'idle');
  const players = cur.players.map((p, i) => {
    const q = prev.players[i];
    return { ...p,
      pos: reset ? p.pos : lerpOrSnap(q.pos, p.pos, t, SNAP_JUMP_CM),
      heading: reset ? p.heading : lerpAngle(q.heading, p.heading, t),
      swingT: p.swingState === q.swingState ? lerp(q.swingT, p.swingT, t) : p.swingT };
  });
  const ball = { ...cur.ball, pos: reset ? cur.ball.pos : lerpOrSnap(prev.ball.pos, cur.ball.pos, t, SNAP_JUMP_CM * 3) };
  return { ...cur, ball, players, tickF: prev.tick + t };
}

// ------------------------------------------------------------------------------------------------ locomotion
export const LOCO = ['idle', 'jog', 'run', 'rush'];

/**
 * Locomotion class from the planar speed (cm/s) and the speed tunables {walk, jog, rush} (cm/s): thresholds at
 * the midpoints between the three speed regimes of the core (walk / jog / rush), so retuning the speeds moves them.
 */
export function locomotionClass(speed, tun, idleMax = 30) {
  if (speed < idleMax) return 'idle';
  if (speed < (tun.walk + tun.jog) / 2) return 'jog';
  if (speed < (tun.jog + tun.rush) / 2) return 'run';
  return 'rush';
}

/** playback rate so the clip's nominal speed (cm/s of root motion, unknown: config placeholder) matches the sim speed */
export function locomotionRate(speed, nominal, lo = 0.6, hi = 1.6) {
  return nominal > 0 ? clamp(speed / nominal, lo, hi) : 1;
}

/** planar speed of a player view (cm/s) */
export const planarSpeed = (p) => Math.hypot(p.vel[0], p.vel[2]);

// ------------------------------------------------------------------------------------------------ swings
/** is the ball on the player's forehand side?  rightSign: +z when the player stands at x < 0 (facing +x) */
export function isForehand(playerPos, ballPos, leftHanded = false) {
  const rightSign = playerPos[0] < 0 ? 1 : -1;
  const side = (ballPos[2] - playerPos[2]) * rightSign;
  return leftHanded ? side <= 0 : side >= 0;
}

/**
 * Swing class of a template row (Settings.bin row order of docs/gameplay/shot-to-template.md):
 * 0..15 groundstrokes, column order TopSpin / Slice / Flat / Lob per tier; 16..19 volleys (Power, Slice, Drop, Flat);
 * 20..31 serves; 32 drop shot; 33 smash; 34 defensive; 35, 36 lobs.
 */
export function swingClassForRow(row, forehand) {
  const side = forehand ? 'fh' : 'bh';
  if (row >= 0 && row <= 15) return row % 4 === 3 ? 'lob' : side + '_' + ['topspin', 'slice', 'flat'][row % 4];
  if (row >= 16 && row <= 19) return row === 18 ? 'drop' : 'volley_' + side;
  if (row >= 20 && row <= 31) return 'serve';
  if (row === 32) return 'drop';
  if (row === 33) return 'smash';
  if (row === 34) return 'defensive';
  if (row === 35 || row === 36) return 'lob';
  return 'default';
}

/**
 * Which swing class the visual should use when a swing starts.  The core only reports the row of the shot AFTER the
 * hit (Ts4PlayerView.template_row), so at swing start the rig guesses from what is known: the shot buttons released
 * (null for the AI: groundstroke topspin, or flat in the volley zone), the ball position classified with the same
 * zone tunables as sim.c classify(), and the side the ball is on.  A wrong guess only picks a different clip; the
 * hit event later reports the true row (the debug readout shows both).
 * tun = { volleyXMax, splitVolley, splitOther, smashLoV, smashHiV, smashLoO, smashHiO }
 */
export function guessSwingClass({ buttons, playerPos, ballPos, bounceCount = 0, tun, leftHanded = false }) {
  const lateral = Math.abs(ballPos[0]), height = ballPos[1];
  const vz = bounceCount <= 2 && lateral < tun.volleyXMax;
  const split = vz ? tun.splitVolley : tun.splitOther;
  const lo = vz ? tun.smashLoV : tun.smashLoO, hi = vz ? tun.smashHiV : tun.smashHiO;
  const side = isForehand(playerPos, ballPos, leftHanded) ? 'fh' : 'bh';
  if (height >= split && height > lo && height < hi) return 'smash';
  if (height < split && vz) return 'volley_' + side;
  if (buttons == null) return side + '_topspin';
  if (buttons & 8) return 'lob';
  if (buttons & 4) return (buttons & 16) ? 'drop' : side + '_slice';
  if (buttons & 2) return side + '_topspin';
  return side + '_flat';
}

/** class -> ordered list of config keys to try: exact, side family, default */
export function swingFallbacks(cls) {
  const out = [cls];
  const m = /^(fh|bh)_|_(fh|bh)$/.exec(cls);
  if (m) out.push(m[1] || m[2]);
  out.push('default');
  return out;
}

/** "core:12" -> 12, 12 -> 12, anything else -> null */
export function clipIndexOf(ref) {
  if (typeof ref === 'number' && Number.isInteger(ref)) return ref;
  const m = /^core:(\d+)$/.exec(String(ref ?? ''));
  return m ? +m[1] : null;
}

/** EventRacket of a swing record in seconds of the clip: values <= 1 read as a phase (docs/port/web.md), larger as ticks */
export function contactSeconds(contact, duration) {
  if (contact == null) return null;
  return contact <= 1 ? contact * duration : contact / 60;
}

/** the clip a record is linked to: its own `clip` field (export --clip-map), else the clip map by name, id or "#index" */
const primaryCache = new WeakMap();
function primaryOf(clipMap, index) {
  if (!clipMap || !Array.isArray(clipMap.records)) return null;
  let idx = primaryCache.get(clipMap);
  if (!idx) {
    idx = new Map(clipMap.records.filter((r) => r.poly === 'blend').map((r) => [r.index, r.primary]));
    primaryCache.set(clipMap, idx);
  }   // blends only: for the other kinds the core lead-in alone would give a wrong contact fraction
  return idx.get(index) ?? null;
}

export function recordClip(record, clipMap) {
  const m = clipMap?.map && typeof clipMap.map === 'object' ? clipMap.map : clipMap;       // tools/port/clip_map.py nests it under "map"
  const ref = record.clip ?? m?.[record.name] ?? m?.[record.id] ?? m?.['#' + record.index] ?? primaryOf(clipMap, record.index);
  return clipIndexOf(ref?.clip ?? ref);
}

/**
 * Choose the clip and the racket-contact time for a swing class.
 *   cfg  = clipmap.config.json  { swing: { <class|fh|bh|default>: {clip, contactSeconds?, contactPhase?} }, recordTags: {<class>: {all, none}} }
 *   ctx  = { clips: Map(index -> {duration, file}), records?: [...], clipMap?: {...} }
 * Order: (1) a swing record whose tags match cfg.recordTags[class] AND that has an exported clip (the real mapping,
 * used only when it exists), (2) the placeholder entry of cfg.swing.  Returns null when nothing is usable.
 */
export function pickSwingClip(cls, cfg, ctx) {
  const usable = (idx) => { const c = ctx.clips.get(idx); return c && c.file ? c : null; };
  for (const key of swingFallbacks(cls)) {
    const rule = cfg.recordTags?.[key];
    if (rule && ctx.records) {
      const all = (rule.all || []).map((s) => s.toLowerCase()), none = (rule.none || []).map((s) => s.toLowerCase());
      const prefer = (rule.prefer || []).map((s) => s.toLowerCase());
      let best = null, bestScore = -1;
      for (const r of ctx.records) {
        const tags = (r.tags || []).map((s) => s.toLowerCase());
        if (!all.every((t) => tags.includes(t)) || none.some((t) => tags.includes(t))) continue;
        const idx = recordClip(r, ctx.clipMap);
        const clip = idx == null ? null : usable(idx);
        if (!clip) continue;
        const contact = contactSeconds(r.contact, clip.duration);
        if (contact == null || !(contact > 0 && contact < clip.duration)) continue;
        const score = prefer.reduce((n, t) => n + (tags.includes(t) ? 1 : 0), 0);
        if (score > bestScore) { best = { clip: idx, contact, source: 'record', placeholder: false, label: r.name }; bestScore = score; }
      }
      if (best) return best;
    }
  }
  for (const key of swingFallbacks(cls)) {
    const e = cfg.swing?.[key];
    if (!e) continue;
    const idx = clipIndexOf(e.clip);
    const clip = idx == null ? null : ctx.clips.get(idx);
    if (!clip) continue;
    const contact = e.contactSeconds ?? clip.duration * (e.contactPhase ?? cfg.defaultContactPhase ?? 0.4);
    return { clip: idx, contact: clamp(contact, 0.01, clip.duration), source: 'config:' + key, placeholder: cfg.placeholder !== false,
             label: 'core:' + idx, exported: !!clip.file };
  }
  return null;
}

/**
 * The Core clip index of a locomotion entry: { record: "<exact record name>" } resolved through the record -> clip
 * link, else { clip: "core:N" } (placeholder).  Returns { clip, source, label } or null.
 */
export function locomotionClipIndex(entry, ctx) {
  if (!entry) return null;
  if (entry.record && ctx.records) {
    const r = ctx.records.find((x) => x.name === entry.record);
    const idx = r ? recordClip(r, ctx.clipMap) : null;
    const clip = idx == null ? null : ctx.clips.get(idx);
    if (clip && clip.file) return { clip: idx, source: 'record', label: entry.record };
  }
  const idx = clipIndexOf(entry.clip);
  return idx == null ? null : { clip: idx, source: 'config', label: 'core:' + idx };
}

export const SWING_CLASSES = ['fh_topspin', 'fh_slice', 'fh_flat', 'bh_topspin', 'bh_slice', 'bh_flat', 'lob', 'volley_fh', 'volley_bh', 'drop', 'smash', 'defensive', 'serve'];

/**
 * Clip time while swinging.  swing_t (0..1) is the core's progress to the contact tick, so driving the clip's
 * time by it makes the racket-contact marker land exactly on the contact tick whatever the clip's own speed
 * (the effective time scale is contact / (contact_delay_ticks / 60)).  After contact the follow-through plays out
 * over the recovery window (recoveryFrac 0..1).  Returns null when not swinging.
 */
export function swingClipTime({ swingState, swingT, contact, duration, recoveryFrac = 0 }) {
  if (swingState === 1) return contact * clamp(swingT, 0, 1);
  if (swingState === 2) return contact + (duration - contact) * clamp(recoveryFrac, 0, 1);
  return null;
}

/**
 * Track values of a Havok clip glTF mirrored into the right-handed frame of the skinned player export
 * (docs/assets.md section 7: translation z negated, quaternion (x, y, z, w) -> (-x, -y, z, w)).  `kind` is the
 * property suffix of a three.js track name ("quaternion", "position", "scale").  Returns a new Float32Array.
 */
export function mirrorTrackValues(kind, values) {
  const out = Float32Array.from(values);
  if (kind === 'position') for (let i = 2; i < out.length; i += 3) out[i] = -out[i];
  else if (kind === 'quaternion') for (let i = 0; i + 3 < out.length; i += 4) { out[i] = -out[i]; out[i + 1] = -out[i + 1]; }
  return out;
}

/** the time scale a clip effectively runs at while approaching contact (for the debug readout) */
export const effectiveSwingScale = (contact, delayTicks) => (delayTicks > 0 ? contact / (delayTicks / 60) : 1);

/** serve wind-up pose while the button charges: a fraction of the way to the contact time */
export function serveChargeTime(contact, chargeFrac, maxFrac = 0.85) { return contact * maxFrac * clamp(chargeFrac, 0, 1); }

// ------------------------------------------------------------------------------------------------ camera
export const CAM = {
  behind: 8.5,          // m behind the human's baseline
  height: 5.2,          // m
  followZ: 0.30,        // fraction of the human's z the camera slides with
  lookBall: 0.30,       // how far the look-at point leans toward the ball
  lambdaPos: 2.2, lambdaLook: 3.5,
  fov: 42,
};

/**
 * Broadcast camera goal behind the human's baseline.  `side` = sign of the human's x (-1 at the start).  Positions in
 * metres.  Port-chosen framing, not decoded from the game.
 */
export function cameraGoal({ side, player, ball }, halfLength = 11.885, p = CAM) {
  const px = player[0] * CM, pz = player[2] * CM, bx = ball[0] * CM, bz = ball[2] * CM;
  const pos = [side * (halfLength + p.behind), p.height, pz * p.followZ + bz * 0.1];
  const look = [lerp(0, bx, p.lookBall) - side * 1.5, 0.9, lerp(pz * p.followZ, bz, 0.5)];
  void px;
  return { pos, look };
}

// ------------------------------------------------------------------------------------------------ scoreboard
export function pointText(display, tiebreak) {
  if (display === -1) return 'Ad';
  if (tiebreak) return String(display);
  return String(display);
}

/** rows for the HUD: [{name, games:[..], game, serving}] for the sets played so far (cur_set + 1 entries) */
export function scoreRows(score, names = ['You', 'CPU']) {
  const n = clamp(score.curSet + 1, 1, 5);
  return [0, 1].map((i) => ({
    name: names[i], serving: score.server === i,
    games: score.games[i].slice(0, n), setsWon: score.setsWon[i],
    game: pointText(score.display[i], !!score.tiebreak),
  }));
}

const REASONS = ['', 'out', 'net', 'double bounce', 'winner', 'fault', 'let', 'serve out of the box'];
export function describeEvent(ev, names = ['You', 'CPU']) {
  switch (ev.type) {
    case 'serve': return null;
    case 'whiff': return ev.a === 0 ? 'Missed the ball' : null;
    case 'fault': return 'Fault';
    case 'double_fault': return 'Double fault';
    case 'let': return 'Let';
    case 'point_end': return ev.a < 0 ? 'No point (' + (REASONS[ev.b] || 'replay') + ')' : 'Point ' + names[ev.a] + ' (' + (REASONS[ev.b] || 'end') + ')';
    case 'game': return 'Game';
    case 'set': return 'Set';
    case 'match': return 'Match: ' + names[ev.a];
    case 'change_ends': return 'Change ends';
    default: return null;
  }
}

/** one line telling the human what to do now */
export function phaseHint(snap, humanIndex = 0) {
  if (!snap) return '';
  const sc = snap.score;
  switch (snap.phase) {
    case 'serve': return sc.server === humanIndex
      ? 'Serve: hold A/J (flat) or B/K (topspin) to charge, release to serve; stick = aim' + (sc.secondServe ? '  [second serve]' : '')
      : 'Opponent serves: move to the ball, press a shot button to swing';
    case 'rally': return 'Rally: move with WASD, hold J/K/U/I and release to swing (Shift = sprint, L = risk)';
    case 'point_end': return 'Point over';
    case 'match_over': return 'Match over: ' + (sc.winner === humanIndex ? 'you win' : 'you lose') + '. Press Restart';
    default: return '';
  }
}

// ------------------------------------------------------------------------------------------------ registry text files
/**
 * Parse include/ts4_tunables.def: TS4_TUN(ID, "name", "unit", ORIGIN, REQ, "doc") one per line.  Units and origin
 * are not exposed by the C ABI, so the retuning panel reads them from the .def the repository ships next to the header.
 */
export function parseTunablesDef(text) {
  const out = [];
  const re = /^\s*TS4_TUN\(\s*([A-Z0-9_]+)\s*,\s*"([^"]+)"\s*,\s*"([^"]*)"\s*,\s*(GAME|PORT)\s*,\s*([RO])\s*,\s*"((?:[^"\\]|\\.)*)"\s*\)/;
  for (const line of text.split('\n')) {
    const m = re.exec(line);
    if (m) out.push({ id: m[1], name: m[2], unit: m[3], origin: m[4], required: m[5] === 'R', doc: m[6] });
  }
  return out;
}

/** Parse include/ts4_roles.def: the graph roles (what the sim runs when) and the variables they bind to */
export function parseRolesDef(text) {
  const roles = [], vars = [];
  const rv = /^\s*TS4_ROLE\(\s*([A-Z0-9_]+)\s*,\s*"([^"]+)"\s*,\s*"([^"]*)"\s*,\s*"((?:[^"\\]|\\.)*)"\s*\)/;
  const vv = /^\s*TS4_VAR\(\s*([A-Z0-9_]+)\s*,\s*"([^"]+)"\s*,\s*"((?:[^"\\]|\\.)*)"\s*\)/;
  for (const line of text.split('\n')) {
    let m = rv.exec(line);
    if (m) { roles.push({ id: m[1], name: m[2], graph: m[3], when: m[4] }); continue; }
    m = vv.exec(line);
    if (m) vars.push({ id: m[1], name: m[2], doc: m[3] });
  }
  return { roles, vars };
}

/** tunable groups by the first dotted component of the name, in first-seen order */
export function groupTunables(list) {
  const groups = new Map();
  for (const t of list) {
    const g = t.name.split('.')[0];
    if (!groups.has(g)) groups.set(g, []);
    groups.get(g).push(t);
  }
  return groups;
}

/**
 * Tunables the core copies at match start (setup_mvcfg in sim.c) rather than reading every tick: an edit takes
 * effect on the next match.  Everything else is read live (TUN(c, id)).
 */
export const APPLY_ON_RESTART = new Set(['move.reaction_frames', 'move.rush_guard', 'move.min_distance_rush', 'move.min_distance_jogjog',
  'move.min_distance_jog', 'move.validity_threshold', 'move.max_hops']);

/** parse a user-typed number; null when not a finite number */
export function parseNumber(s) {
  if (typeof s === 'number') return Number.isFinite(s) ? s : null;
  const t = String(s).trim();
  if (t === '') return null;
  const v = Number(t);
  return Number.isFinite(v) ? v : null;
}

/** overrides = {name: value} that differ from the defaults captured at load */
export function diffOverrides(current, defaults) {
  const out = {};
  for (const [k, v] of Object.entries(current)) if (v !== null && v !== undefined && !(Math.abs(v - defaults[k]) <= 1e-9 * Math.max(1, Math.abs(v)))) out[k] = v;
  return out;
}

// ------------------------------------------------------------------------------------------------ shot probes
/** first ground contact of a trace [[x,y,z],...] (ball-centre height <= radius + eps, local minimum), or null */
export function firstBounce(points, radiusCm = 4) {
  for (let i = 1; i < points.length; i++) {
    const y = points[i][1], next = i + 1 < points.length ? points[i + 1][1] : Infinity;
    if (y <= points[i - 1][1] && y <= next && y < radiusCm + 1) return { tick: i, pos: points[i] };
  }
  return null;
}

/** height (cm) of the trace where it crosses the net plane x = 0, or null */
export function netCrossing(points) {
  for (let i = 1; i < points.length; i++) {
    const x0 = points[i - 1][0], x1 = points[i][0];
    if (x0 * x1 < 0) { const t = Math.abs(x0) / (Math.abs(x0) + Math.abs(x1)); return lerp(points[i - 1][1], points[i][1], t); }
  }
  return null;
}

/** summary numbers of one probe+trace used by the panel and its baseline comparison */
export function summariseProbe(out, points, radiusCm = 4) {
  const b = firstBounce(points, radiusCm);
  const apex = points.reduce((m, p) => Math.max(m, p[1]), 0);
  return { tau: out.tau, bounceTick: out.bounceTick, launchKmh: out.initialKmh,
           arriveKmh: Math.hypot(...out.arriveVel) * 3.6, netCm: netCrossing(points), apexCm: apex,
           landX: b ? b.pos[0] : null, landZ: b ? b.pos[2] : null, raised: out.raised, netUnreachable: out.netUnreachable };
}

/** field-wise difference b - a over the numeric fields both have (null when either is missing) */
export function probeDelta(a, b) {
  const d = {};
  for (const k of Object.keys(b)) if (typeof b[k] === 'number' && typeof a?.[k] === 'number') d[k] = b[k] - a[k];
  return d;
}

/** human-readable match config -> ts4core startMatch() argument */
export function matchConfigFrom(form) {
  const fmt = form.format || 'short';
  return {
    seed: (form.seed >>> 0) || 1,
    gamesPerSet: 6,
    numSets: fmt === 'best3' ? 3 : 1,
    shortFormat: fmt === 'short',
    singleServe: false,
    firstServer: form.firstServer === 1 ? 1 : 0,
    surface: ['hard', 'clay', 'grass'].indexOf(form.surface) < 0 ? 0 : ['hard', 'clay', 'grass'].indexOf(form.surface),
    players: [
      { human: true, stats: Array(8).fill(clamp(form.stats0 ?? 70, 0, 100)), leftHanded: !!form.left0 },
      { human: !!form.human1, stats: Array(8).fill(clamp(form.stats1 ?? 60, 0, 100)), leftHanded: !!form.left1 },
    ],
  };
}
