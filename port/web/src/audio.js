// Match audio for the browser port: plays the game's own FMOD events (exported from the user's disc by
// tools/port/audio_export.py into <assets>/audio/) in response to ts4core events, the way the game's sound-event
// controller does (Swing_DLL.dll 0x8888A000-0x88890000, docs/port/presentation-and-audio.md section 3,
// data/gameplay/audio/events.yaml).
//
// Two parts:
//   * AudioDirector: pure logic (node-testable).  onTick(prev, cur, events) and frame(dt, view) turn core events into
//     commands {op: 'play'|'loop'|'stop'|'param', path, volume, param, pan}.  Classification thresholds are the game's
//     (fn_8888D700 shots, fn_8888CFD0 bounces, fn_8888EBE8 net, fn_8888D930 applause, umpire builders 0x8888C7E8..);
//     inputs the core does not provide (stroke power, crowd excitement) are PORT ASSUMPTIONS and say so.
//   * MatchAudio: WebAudio player of events.json (simple events, weighted random waves, max playbacks, loops, a
//     parameter -> volume envelope for complex events).  Missing files degrade to silence.

import { swingClassForRow } from './helpers.js';

// ------------------------------------------------------------------------------------------------ classifiers

/** fn_8888D700: stroke family -> event family. Lob folds into TopSpin, Smash into Flat (gp5 section 3). */
export function shotFamily(row) {
  const c = swingClassForRow(row, true);
  if (c === 'drop') return 'Drop';
  if (/flat|smash|serve/.test(c)) return 'Flat';                // serve rows: family not known per row (PORT)
  if (/topspin|lob/.test(c)) return 'TopSpin';
  return 'Slice';                                               // slice, volleys, defensive, default
}

/** power word of fn_8888D700: serve flag (R+0x95) uses 3 buckets 0.4/0.7, rally shots 5 buckets 0.2/0.4/0.6/0.8. */
export function powerWord(power, serve) {
  if (serve) return power < 0.4 ? '' : power < 0.7 ? 'Strong' : 'Powerfull';
  return power < 0.2 ? 'Powerless' : power < 0.4 ? 'Weak' : power < 0.6 ? '' : power < 0.8 ? 'Strong' : 'Powerfull';
}

export function shotEvent(row, power, serve) {
  const fam = shotFamily(row);
  if (fam === 'Drop') return '/Root/Ball/Shot/Drop';
  return '/Root/Ball/Shot/' + fam + powerWord(power, serve);
}

/** PORT ASSUMPTION: the core has no stroke power (R+0x178); map the launch speed 40..160 km/h onto 0..1. */
export function powerFromSpeed(cmPerS) {
  const kmh = cmPerS * 0.036;
  return Math.min(1, Math.max(0, (kmh - 40) / 120));
}

/** units of the physics speed fn_8888CFD0 / fn_8888EBE8 compare against (40/55/75 and 25).  Not confirmed:
 *  gp5 suggests m/s, but then nearly every bounce would be "VerySlow"; km/h gives the full range (PORT ASSUMPTION). */
export const SPEED_UNIT = { name: 'km/h', perCmS: 0.036 };

/** fn_8888CFD0: Root/Ball/Bounce/%sAngle%sSpeed from the incoming velocity (cm/s, y up). */
export function bounceEvent(vel, unit = SPEED_UNIT) {
  const sp = Math.hypot(vel[0], vel[1], vel[2]);
  const ratio = sp > 0 ? -vel[1] / sp : 0;
  const a = ratio < 0.30 ? 'Small' : ratio < 0.45 ? 'Medium' : 'Large';
  const s = sp * unit.perCmS;
  const w = s < 40 ? 'VerySlow' : s < 55 ? 'Slow' : s < 75 ? 'Medium' : 'Fast';
  return '/Root/Ball/Bounce/' + a + 'Angle' + w + 'Speed';
}

/** fn_8888EBE8: Root/Ball/Collision/Net_%s, Slow below 25 (same unit question as bounces). */
export function netEvent(vel, unit = SPEED_UNIT) {
  return '/Root/Ball/Collision/Net_' + (Math.hypot(vel[0], vel[1], vel[2]) * unit.perCmS < 25 ? 'Slow' : 'Fast');
}

/** fn_8888D930: Root/Crowd/EndOfPoint/<level>, level = int at (arg+0x38)->+0x130 (<=0, 1, 2, >=3). */
export function applauseEvent(level) {
  return '/Root/Crowd/EndOfPoint/' + (level <= 0 ? 'ApplauseLow' : level === 1 ? 'ApplauseAverage' : level === 2 ? 'ApplauseStrong' : 'ApplauseWild');
}

/** PORT ASSUMPTION for the applause level (the game's source of +0x130 was not traced): rally length + winner kind. */
export function applauseLevel(rallyHits, reason) {
  let l = rallyHits < 3 ? 0 : rallyHits < 6 ? 1 : rallyHits < 10 ? 2 : 3;
  if (reason === 4 && rallyHits >= 2) l = Math.max(l, 1);           // TS4_REASON_NO_RETURN: clean winner
  if (reason === 5) l = 0;                                          // double fault
  return l;
}

export const PLAYER_NAMES = ['PlayerOne', 'PlayerTwo', 'PlayerThree', 'PlayerFour'];
const pts = (v) => (v === -1 ? 'Ad' : String(v));

/** Umpire wording (fn_8888CCE8 / fn_8888C7E8 / fn_8888CB48; names via ts4_umpire_player_name_cue_8888C620):
 *  returns the FMOD event paths to play in order for the score as it stands after a point.
 *  ctx: { gameWon: winner index or null, setWon, matchWon, names } */
export function umpireCall(score, ctx = {}) {
  const names = ctx.names || PLAYER_NAMES;
  const nm = (i, end) => '/Root/Umpire/PlayerName/' + names[i] + (end ? '/EndWith' : '/BeginWith');
  const U = '/Root/Umpire/';
  if (ctx.matchWon != null) return [U + 'SetNormal/GameSetAndMatch', nm(ctx.matchWon, true)];
  if (ctx.gameWon != null) {
    const w = ctx.gameWon, set = score.curSet ?? 0;
    if (ctx.setWon != null) {
      const done = Math.max(0, (score.setsWon?.[0] ?? 0) + (score.setsWon?.[1] ?? 0));
      return [U + 'SetNormal/GameAnd' + Math.max(1, done) + 'Set', nm(w, true)];
    }
    const out = [U + 'GameNormal/Game', nm(w, true)];
    const g0 = score.games?.[0]?.[set] ?? 0, g1 = score.games?.[1]?.[set] ?? 0;
    if (g0 === g1) out.push(g0 === 6 ? U + 'GameNormal/TieBreak' : U + 'GameNormal/' + g0 + 'GameAll');
    else {
      const lead = g0 > g1 ? 0 : 1;
      out.push(nm(lead, false), U + 'GameNormal/Leads' + Math.max(g0, g1) + 'GameTo' + Math.min(g0, g1));
    }
    return out;
  }
  const sv = score.server ?? 0, a = score.display[sv], b = score.display[1 - sv];
  if (score.tiebreak) {
    if (a === b) return [U + 'TieBreakNormal/' + a + 'All'];
    return [U + 'TieBreakNormal/BeginWith/' + Math.max(a, b), U + 'TieBreakNormal/EndWith/' + Math.min(a, b),
            nm(score.display[0] > score.display[1] ? 0 : 1, true)];
  }
  if (a === -1 || b === -1) return [U + 'RallyNormal/Advantage', nm(a === -1 ? sv : 1 - sv, true)];
  if (a === 40 && b === 40) return [U + 'RallyNormal/Deuce'];
  if (a === 0 && b === 0) return [];
  return [U + 'RallyNormal/' + pts(a) + '-' + pts(b)];
}

// ------------------------------------------------------------------------------------------------ director

/** Turns ts4core events into sound commands.  Delays mirror the game's command queue (+0x10 countdown). */
export class AudioDirector {
  constructor(opts = {}) {
    this.voice = opts.voice || ['Man/00', 'Man/01'];              // Grunt/<sex>/<NN> per player (PORT choice)
    this.gruntPower = opts.gruntPower ?? 0.6;                       // "PowerfulShot" grunt rule threshold (PORT)
    this.names = opts.names || PLAYER_NAMES;
    this.pending = [];                                             // {t, fn}
    this.time = 0;
    this.rallyHits = 0;
    this.excitement = 0;
    this.inRally = false;
    this.ctx = {};
    this.stepPhase = [0, 0];
    this.out = [];
  }

  emit(cmd) { this.out.push(cmd); }
  later(delay, fn) { this.pending.push({ t: this.time + delay, fn }); }
  take() { const o = this.out; this.out = []; return o; }

  /** start of a match: ambience and crowd bed */
  start() {
    this.emit({ op: 'loop', path: '/Root/Ambience/BackNoise', param: 0 });
    this.emit({ op: 'loop', path: '/Root/Crowd/Interpoint/Hubbub', volume: 0.6 });
  }

  onTick(prev, cur, evs) {
    for (const e of evs) {
      const pan = Math.max(-1, Math.min(1, (e.pos?.[2] ?? 0) / 600));
      switch (e.type) {
        case 'serve':
          this.rallyHits = 0; this.inRally = true; this.excitement = 0; this.ctx = {};
          this.emit({ op: 'stop', path: '/Root/Crowd/Interpoint/Hubbub' });
          this.emit({ op: 'stop', path: '/Root/Crowd/Interpoint/Music' });
          break;
        case 'hit': {
          const serve = this.rallyHits === 0;
          this.rallyHits++;
          const vel = cur?.ball?.vel || [0, 0, 0];
          const power = powerFromSpeed(Math.hypot(vel[0], vel[1], vel[2]));
          this.emit({ op: 'play', path: shotEvent(e.b, power, serve), pan });
          if (power >= this.gruntPower) this.emit({ op: 'play', path: '/Root/Grunt/' + this.voice[e.a & 1] + '/Shot', pan });
          this.excitement = Math.min(1, this.rallyHits / 12);
          if (this.rallyHits === 4) this.emit({ op: 'loop', path: '/Root/Crowd/Rally/Loops/Excitement', param: this.excitement });
          else if (this.rallyHits > 4) this.emit({ op: 'param', path: '/Root/Crowd/Rally/Loops/Excitement', param: this.excitement });
          break;
        }
        case 'whiff': this.emit({ op: 'play', path: '/Root/Grunt/' + this.voice[e.a & 1] + '/Effort', pan }); break;
        case 'bounce':
          if (e.b === 0) this.emit({ op: 'play', path: bounceEvent(prev?.ball?.vel || [0, -1000, 0]), pan });
          break;
        case 'net':
          this.emit({ op: 'play', path: netEvent(prev?.ball?.vel || [0, 0, 0]), pan });
          if (e.a === 2) this.emit({ op: 'play', path: '/Root/Sensor/Beep' });
          break;
        case 'fault':
          this.emit({ op: 'play', path: '/Root/LineJudge/Fault' });
          this.inRally = false;
          break;
        case 'let':
          this.later(0.6, () => this.emit({ op: 'play', path: '/Root/Umpire/RallyNormal/' + (cur?.score?.secondServe ? 'LetSecondServe' : 'LetFirstServe') }));
          break;
        case 'point_end': {
          this.inRally = false;
          if (e.a >= 0) this.lastWinner = e.a;
          if (e.b === 1) this.emit({ op: 'play', path: '/Root/LineJudge/Out' });
          this.emit({ op: 'stop', path: '/Root/Crowd/Rally/Loops/Excitement' });
          const lvl = applauseLevel(this.rallyHits, e.b);
          this.later(0.25, () => this.emit({ op: 'play', path: applauseEvent(lvl) }));
          if (lvl >= 3) this.later(0.4, () => this.emit({ op: 'play', path: '/Root/Crowd/Rally/Kicks/Cheering0' + (1 + (this.rallyHits % 5)) }));
          if (e.a >= 0 && lvl >= 2) this.later(0.5, () => this.emit({ op: 'play', path: '/Root/PlayerSounds/' + this.voice[e.a & 1] + '/GruntVictory0' + (1 + (this.rallyHits % 3)) }));
          this.later(1.6, () => {
            const sc = this.latestScore || cur?.score;
            if (sc) for (const [i, p] of umpireCall(sc, { ...this.ctx, names: this.names }).entries()) this.later(i * 0.9, () => this.emit({ op: 'play', path: p }));
            this.ctx = {};
          });
          this.later(2.4, () => this.emit({ op: 'loop', path: '/Root/Crowd/Interpoint/Hubbub', volume: 0.6 }));
          break;
        }
        // TS4_EV_GAME / TS4_EV_SET carry no winner (sim.c passes 0): the last point's winner won it
        case 'game': this.ctx.gameWon = this.lastWinner ?? 0; break;
        case 'set': this.ctx.setWon = this.lastWinner ?? 0; break;
        case 'match':
          this.ctx.matchWon = e.a;
          this.later(3.5, () => this.emit({ op: 'play', path: '/Root/Crowd/Cutscenes/EndOfMatch/EndOfMatchPart1' }));
          break;
        case 'change_ends':
          this.later(3.0, () => this.emit({ op: 'play', path: '/Root/Umpire/CourtChange/Time' }));
          this.later(4.0, () => this.emit({ op: 'loop', path: '/Root/Crowd/Interpoint/Music', volume: 0.7 }));
          break;
        default: break;
      }
    }
    if (cur?.score) this.latestScore = cur.score;
  }

  /** per frame: delayed commands and footsteps (PORT: the game drives Root/Foot/* from animation events, command
   *  6023f2af; here a cadence from the planar speed stands in). players: [{vel:[x,y,z] cm/s}] */
  frame(dt, players = []) {
    this.time += dt;
    const due = this.pending.filter((p) => p.t <= this.time);
    this.pending = this.pending.filter((p) => p.t > this.time);
    due.sort((a, b) => a.t - b.t).forEach((p) => p.fn());
    players.forEach((p, i) => {
      const v = p?.vel ? Math.hypot(p.vel[0], p.vel[2]) : 0;
      if (v < 150) { this.stepPhase[i] = 0; return; }
      const rate = v > 450 ? 3.6 : 2.4;                                // steps per second
      this.stepPhase[i] += dt * rate;
      if (this.stepPhase[i] >= 1) {
        this.stepPhase[i] -= 1;
        this.emit({ op: 'play', path: v > 550 ? '/Root/Foot/Squeak' : '/Root/Foot/Step', volume: 0.5, player: i });
      }
    });
    return this.take();
  }
}

// ------------------------------------------------------------------------------------------------ playback

const LOOPING = /Loops\/|BackNoise|Hubbub|Interpoint\/Music|StadiumMusic|AmbientMusic|EndOfMatchPart2Loop|Corridor\//;

/** weighted pick over waves, avoiding the previous index for "no repeat" playmodes */
export function pickWave(sound, last = -1, rnd = Math.random) {
  const ws = sound.waves.filter((w) => w.file);
  if (!ws.length) return -1;
  const noRepeat = /no_repeat/.test(sound.playmode || '') && ws.length > 1;
  let total = 0;
  ws.forEach((w, i) => { if (!(noRepeat && i === last)) total += w.weight || 1; });
  let r = rnd() * total;
  for (let i = 0; i < ws.length; i++) {
    if (noRepeat && i === last) continue;
    r -= ws[i].weight || 1;
    if (r <= 0) return i;
  }
  return ws.length - 1;
}

/** gain of a complex event's layer at parameter value p: volume envelopes (dsp_type 12, x normalised 0..1 over the
 *  parameter range: an inference) multiply; layers whose sounds do not cover p are silent. */
export function layerGain(layer, p, range = [0, 1]) {
  if (layer.param < 0) return 1;
  const u = (p - range[0]) / ((range[1] - range[0]) || 1);
  let g = 1;
  if (layer.sounds.length && !layer.sounds.some((s) => u >= s.start - 1e-6 && u <= s.start + s.length + 1e-6)) return 0;
  for (const env of layer.envelopes || []) {
    const pts = env.points;
    if (!pts?.length) continue;
    let y = pts[pts.length - 1][1];
    if (u <= pts[0][0]) y = pts[0][1];
    else for (let i = 1; i < pts.length; i++) if (u <= pts[i][0]) { const [x0, y0] = pts[i - 1], [x1, y1] = pts[i]; y = y0 + (y1 - y0) * ((u - x0) / ((x1 - x0) || 1)); break; }
    g *= y;
  }
  return g;
}

export class MatchAudio {
  constructor({ base = 'assets/audio/', venue = 'Amsterdam', context = null } = {}) {
    this.base = base; this.venue = venue;
    this.ctx = context; this.events = null; this.buffers = new Map(); this.loops = new Map(); this.voices = new Map();
    this.last = new Map(); this.master = null; this.status = 'not loaded'; this.missing = new Set();
  }

  async load(fetchJson) {
    try {
      const j = await fetchJson(this.base + this.venue + '/events.json');
      this.events = j.events;
      try { const core = await fetchJson(this.base + 'Core/events.json'); Object.assign(this.events, core.events); } catch { /* optional */ }
      this.status = 'ok: ' + Object.keys(this.events).length + ' events (' + this.venue + ')';
    } catch (e) {
      this.events = null;
      this.status = 'audio not exported (python3 tools/port/audio_export.py): ' + e.message;
    }
    return !!this.events;
  }

  ensureContext() {
    if (!this.ctx && typeof AudioContext !== 'undefined') this.ctx = new AudioContext();
    if (this.ctx && !this.master) { this.master = this.ctx.createGain(); this.master.gain.value = 0.8; this.master.connect(this.ctx.destination); }
    if (this.ctx?.state === 'suspended') this.ctx.resume();
    return this.ctx;
  }

  async buffer(file) {
    if (this.buffers.has(file)) return this.buffers.get(file);
    const p = fetch(this.base + file).then((r) => { if (!r.ok) throw new Error(r.status); return r.arrayBuffer(); })
      .then((b) => this.ctx.decodeAudioData(b)).catch(() => { this.missing.add(file); return null; });
    this.buffers.set(file, p);
    return p;
  }

  async start(path, { volume = 1, param = 0, pan = 0, loop = null } = {}) {
    const ev = this.events?.[path];
    if (!ev || !this.ensureContext()) return null;
    const ctx = this.ctx;
    const isLoop = loop ?? LOOPING.test(path);
    const active = this.voices.get(path) || [];
    while (active.length >= Math.max(1, ev.max_playbacks || 4)) { try { active.shift().stop(); } catch { /* ended */ } }
    const range = ev.params?.[0] ? [ev.params[0].min, ev.params[0].max] : [0, 1];
    const out = ctx.createGain();
    const vr = ev.volume_randomization ? 1 - Math.random() * ev.volume_randomization : 1;
    out.gain.value = volume * (ev.volume ?? 1) * vr;
    let node = out;
    if (pan && ctx.createStereoPanner) { const p = ctx.createStereoPanner(); p.pan.value = pan; out.connect(p); node = p; }
    node.connect(this.master);
    const srcs = [];
    for (const [li, layer] of ev.layers.entries()) {
      const g = layerGain(layer, param, range);
      if (g <= 0) continue;
      for (const [si, s] of layer.sounds.entries()) {
        const key = path + '#' + li + '.' + si;
        const wi = pickWave(s, this.last.get(key));
        if (wi < 0) continue;
        this.last.set(key, wi);
        const w = s.waves.filter((x) => x.file)[wi];
        const buf = await this.buffer(w.file);
        if (!buf) continue;
        const src = ctx.createBufferSource();
        src.buffer = buf; src.loop = isLoop;
        const lg = ctx.createGain(); lg.gain.value = g * (s.volume ?? 1);
        src.connect(lg); lg.connect(out); src.start();
        srcs.push({ src, lg, layer });
      }
    }
    const handle = { path, out, srcs, range, stop: () => { for (const x of srcs) { try { x.src.stop(); } catch { /* */ } } } };
    active.push(handle); this.voices.set(path, active);
    if (isLoop) this.loops.set(path, handle);
    return handle;
  }

  setParam(path, value) {
    const h = this.loops.get(path);
    if (!h) return;
    for (const x of h.srcs) x.lg.gain.value = layerGain(x.layer, value, h.range);
  }

  stop(path) { const h = this.loops.get(path); if (h) { h.stop(); this.loops.delete(path); } }

  stopAll() { for (const p of [...this.loops.keys()]) this.stop(p); }

  /** execute AudioDirector commands */
  run(cmds) {
    if (!this.events) return;
    for (const c of cmds) {
      if (c.op === 'play') this.start(c.path, { volume: c.volume ?? 1, pan: c.pan || 0, param: c.param ?? 0, loop: false });
      else if (c.op === 'loop') { if (!this.loops.has(c.path)) this.start(c.path, { volume: c.volume ?? 1, param: c.param ?? 0, loop: true }); else this.setParam(c.path, c.param ?? 0); }
      else if (c.op === 'param') this.setParam(c.path, c.param ?? 0);
      else if (c.op === 'stop') this.stop(c.path);
    }
  }
}
