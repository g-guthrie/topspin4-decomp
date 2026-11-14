// Crowd and trackside state machine: readable reference for how the crowd reacts to a rally.
// Pure JavaScript, no DOM, no three.js (node can run it; tests/test_venue.py runs a smoke test through node).
//
// What comes from the game (docs/port/venues-and-crowd.md has addresses and confidence):
//   * The behaviour graph: <venue>.arc TrackSideBehaviorList.bin, exported to venues/_trackside/trackside.json by
//     tools/ts4_venue.py.  One list per setup (TrackSideSetupList index 0..24).  A plain behaviour plays one clip; a
//     composite has a start sequence and a stop sequence of plain behaviours.  The last entry of a start sequence
//     loops until the composite is stopped; the stop sequence ends in Idle (which loops).
//   * One animated skeleton per setup: every spectator that references TS_SE07 shares the TS_SE07 pose.  This file
//     therefore runs one SectionFSM per setup, not per spectator.
//   * The excitement gauge (gp1 section 6, fn_8868E370 / fn_8868EA30 / fn_8868E950) and its tables from
//     Core.arc Settings.bin (cfg+0x824, +0x830, +0x83C; values copied into data/gameplay/crowd.yaml).
//   * The end-of-point applause level 0..3 -> ApplauseLow/Average/Strong/Wild naming (fn_8888D930, sound side).
// What is a port choice (marked PORT below): how the 0..1 gauge becomes the 0..3 applause level, the rally quality
// "ratio" input, the applause hold time, the per-section start jitter, which events trigger Deception, line-judge
// calls and the net shake, and how often officials play a flourish.  The code that triggers trackside behaviours in
// the game has not been found (behaviour name hashes are not code constants), see the doc's gaps section.

// ---- excitement gauge (game tables) ---------------------------------------------------------------------------
export const EXCITEMENT = {
  // cfg+0x824: rows keyed by level limit (first row with level <= limit), columns (ratio key, gain): first key >= ratio
  gainTable: [
    { limit: 0.40, cols: [[0.2, 0.04], [0.4, 0.03], [0.6, 0.02], [0.8, 0.0], [0.99, -0.01], [1.0, -0.02]] },
    { limit: 0.75, cols: [[0.2, 0.04], [0.4, 0.02], [0.6, 0.0], [0.8, -0.01], [0.99, -0.02], [1.0, -0.03]] },
    { limit: 1.00, cols: [[0.2, 0.02], [0.4, 0.01], [0.6, 0.0], [0.8, -0.02], [0.99, -0.03], [1.0, -0.04]] },
  ],
  // cfg+0x830: |gain| cap by shot count (first row with shots <= key; the last row beyond it)
  capTable: [[1, 0.01], [2, 0.02], [3, 0.03]],
  // cfg+0x83C: event rows summed when their condition holds (conditions from fn_8868E370)
  events: {
    LoseUnforcedError: -0.01, LoseUnforcedErrorEasyBall: -0.01, LoseWinner: -0.01, WinWinner: 0.01,
    WinWinnerPowerfulShot: 0.01, WinPassingShot: 0.02, WinSmash: 0.01, WinTwentyShots: 0.01,
    WinServeAndVolley: 0.01, WinAce: 0.01,
  },
  displayScale: 100.0,
};

export function excitementGain(level, ratio, t = EXCITEMENT) {
  const row = t.gainTable.find((r) => level <= r.limit) || t.gainTable[t.gainTable.length - 1];
  const col = row.cols.find((c) => ratio <= c[0]) || row.cols[row.cols.length - 1];
  return col[1];
}

export function excitementCap(shots, t = EXCITEMENT) {
  const row = t.capTable.find((r) => shots <= r[0]) || t.capTable[t.capTable.length - 1];
  return row[1];
}

const clamp = (v, lo, hi) => (v < lo ? lo : v > hi ? hi : v);

/** gp1 s6: level = clamp(level + sum(events) + clamp(gain(level, ratio), -cap, cap), 0, 1) */
export function excitementUpdate(level, { events = [], ratio = 0.5, shots = 1 } = {}, t = EXCITEMENT) {
  let ev = 0;
  for (const e of events) ev += t.events[e] ?? 0;
  const cap = excitementCap(shots, t);
  return clamp(level + ev + clamp(excitementGain(level, ratio, t), -cap, cap), 0, 1);
}

/** PORT: map gauge + point events to the 0..3 applause level fn_8888D930 reads (event+0x38 -> +0x130) */
export function applauseLevel(level, events = []) {
  let a = Math.floor(level * 4);
  if (events.includes("WinAce") || events.includes("WinPassingShot") || events.includes("WinTwentyShots")) a++;
  return clamp(a, 0, 3);
}
export const APPLAUSE = ["ApplauseLow", "ApplauseAverage", "ApplauseStrong", "ApplauseWild"];

/**
 * PORT: classify a core point_end (+ rally facts) into the gp1 event rows, from the point of view of the crowd's
 * favourite (`homeWon`: the favourite won the point; the game's Win and Lose rows suggest a per-player view, the
 * favourite rule itself is unverified).  reason codes: TS4_REASON of ts4core.h.
 */
export const REASON = ["NONE", "OUT", "NET", "DOUBLE_BOUNCE", "NO_RETURN", "FAULT", "LET", "SERVE_OUT_OF_BOX"];
export function pointEvents({ reason, shots = 0, lastSpeed = 0, homeWon = true, serverWon = false, netApproach = false, smash = false }) {
  const r = typeof reason === "number" ? REASON[reason] : reason;
  const ev = [];
  const winner = r === "DOUBLE_BOUNCE" || r === "NO_RETURN";   // a clean winner by the last hitter
  const error = r === "OUT" || r === "NET";                   // the last hitter missed
  if (winner && homeWon) {
    if (shots <= 1 && serverWon) ev.push("WinAce");
    else ev.push("WinWinner");
    if (lastSpeed > 140) ev.push("WinWinnerPowerfulShot");   // fn_8868E370: ball speed > 140.0
    if (smash) ev.push("WinSmash");
    if (netApproach && serverWon && shots <= 3) ev.push("WinServeAndVolley");
  } else if (winner) ev.push("LoseWinner");
  else if (error && !homeWon) {
    ev.push("LoseUnforcedError");
    if (lastSpeed < 60) ev.push("LoseUnforcedErrorEasyBall");
  }
  if (shots >= 20 && homeWon) ev.push("WinTwentyShots");    // fn_8868E370: >= 20 shots
  return ev;
}

// ---- behaviour graph ------------------------------------------------------------------------------------------
/** wraps trackside.json: behaviour lookup per setup and clip durations */
export class TrackSideGraph {
  constructor(ts) {
    this.ts = ts;
    this.duration = new Map(ts.clips.map((c) => [c.clip, c.duration]));
    this.lists = ts.behaviour_lists.map((l) => {
      const byName = new Map();
      for (const b of l.behaviours) {
        if (!byName.has(b.name)) byName.set(b.name, []);
        byName.get(b.name).push(b);
      }
      return { ...l, byName };
    });
    this.setups = ts.setups;
  }

  setupIndex(setupName) { return this.setups[setupName]?.index ?? -1; }
  list(setupIndex) { return this.lists.find((l) => l.setup_index === setupIndex) || null; }

  /** a plain behaviour's clip (a random variant when the name has several) */
  clipOf(setupIndex, name, rnd = Math.random) {
    const l = this.list(setupIndex);
    const v = l?.byName.get(name)?.filter((b) => b.clip !== null);
    if (!v || !v.length) return null;
    return v[Math.floor(rnd() * v.length) % v.length].clip;
  }

  /** {start:[names], stop:[names]} for a composite, or {start:[name], stop:[]} for a plain behaviour */
  sequence(setupIndex, name) {
    const l = this.list(setupIndex);
    const b = l?.byName.get(name)?.[0];
    if (!b) return null;
    if (b.clip !== null) return { start: [name], stop: [] };
    return { start: b.start, stop: b.stop };
  }

  has(setupIndex, name) { return !!this.list(setupIndex)?.byName.get(name); }
}

/**
 * One animated setup (a crowd section, a line judge, the net, an official).
 * State: a queue of plain behaviour names; the head plays; the last entry loops ("hold") until play()/stop().
 * update(dt) returns { clip, time, changed } for the renderer (which cross-fades when `changed`).
 */
export class SectionFSM {
  constructor(graph, setupIndex, { idle = "Idle", rnd = Math.random } = {}) {
    this.g = graph; this.setup = setupIndex; this.idle = idle; this.rnd = rnd;
    this.queue = [idle];
    this.current = null;          // composite or plain name the section was asked to play
    this.stopSeq = [];
    this.delay = 0;               // PORT: seconds before a queued request starts (section jitter)
    this.pending = null;
    this.holdLeft = Infinity;     // seconds left on the looping tail before an automatic stop()
    this._enter(idle);
  }

  _enter(name) {
    this.name = name;
    this.clip = this.g.clipOf(this.setup, name, this.rnd);
    this.time = 0;
    this.len = this.g.duration.get(this.clip) ?? 1;
    this.changed = true;
  }

  get state() { return this.current || this.name; }

  /** start a composite or plain behaviour; `hold` = seconds its looping tail plays before the stop sequence */
  play(name, { hold = Infinity, delay = 0 } = {}) {
    const s = this.g.sequence(this.setup, name);
    if (!s || !s.start.length) return false;
    this.pending = { name, s, hold };
    this.delay = delay;
    if (delay <= 0) this._start();
    return true;
  }

  _start() {
    const { name, s, hold } = this.pending; this.pending = null;
    const oneShot = s.start.length === 1 && !s.stop.length && hold === Infinity;   // plain behaviour: play once
    this.current = oneShot ? null : name; this.queue = [...s.start]; this.stopSeq = [...s.stop]; this.holdLeft = hold;
    this._enter(this.queue[0]);
  }

  /** run the stop sequence of the current composite (or go back to idle) */
  stop() {
    const seq = this.stopSeq.length ? this.stopSeq : [this.idle];
    this.current = null; this.stopSeq = []; this.holdLeft = Infinity; this.pending = null;
    this.queue = [...seq];
    this._enter(this.queue[0]);
  }

  update(dt) {
    this.changed = false;
    if (this.pending) { this.delay -= dt; if (this.delay <= 0) this._start(); }
    this.time += dt;
    const tail = this.queue.length === 1;
    if (tail) {
      if (this.current !== null) { this.holdLeft -= dt; if (this.holdLeft <= 0) this.stop(); }
      else if (this.name !== this.idle && this.time >= this.len) {          // a one-shot plain behaviour ended
        this.queue = [this.idle]; this._enter(this.idle);
      }
      if (this.time >= this.len && this.queue.length === 1) this.time %= this.len;
    } else if (this.time >= this.len) {
      this.queue.shift();
      this._enter(this.queue[0]);
    }
    return { clip: this.clip, time: this.time, name: this.name, changed: this.changed };
  }
}

// ---- director: core events -> section requests ---------------------------------------------------------------
const SIDE = (z) => (z >= 0 ? "Left" : "Right");     // PORT: game +z -> the judge's left (unverified)

export class CrowdDirector {
  /**
   * @param graph   TrackSideGraph
   * @param setups  { crowd: [setup names], judges: [setup names], net: setup name|null, officials: [{setup, behaviours}] }
   */
  constructor(graph, setups, { rnd = Math.random, level = 0.3 } = {}) {
    this.g = graph; this.rnd = rnd; this.level = level;
    const mk = (name, idle) => new SectionFSM(graph, graph.setupIndex(name), { idle, rnd });
    this.crowd = (setups.crowd || []).map((n) => ({ name: n, fsm: mk(n, "Idle") }));
    this.judges = (setups.judges || []).map((n) => ({ name: n, fsm: mk(n, "Idle") }));
    this.net = setups.net ? { name: setups.net, fsm: mk(setups.net, "IdleNet") } : null;
    this.officials = (setups.officials || []).map((o) => {
      const idle = o.behaviours.find((b) => /^Idle/.test(b)) || "Idle";
      const f = new SectionFSM(graph, graph.setupIndex(o.setup), { idle, rnd });
      return { ...o, fsm: f, idle, flourishes: o.behaviours.filter((b) => /^Flourish/.test(b)), next: 4 + rnd() * 10 };
    });
    this.rally = { shots: 0, lastSpeed: 0, server: 0, lastHitter: -1 };
    this.home = 0;                // PORT: the crowd's favourite (player 0 = the human side)
    this.log = [];
  }

  all() {
    return [...this.crowd, ...this.judges, ...(this.net ? [this.net] : []), ...this.officials];
  }

  _crowd(name, hold) {
    for (const s of this.crowd) s.fsm.play(name, { hold, delay: this.rnd() * 0.35 });     // PORT jitter
  }

  /** feed one decoded core event ({type, tick, a, b, c, pos}, pos in cm) */
  onEvent(e, snap = null) {
    switch (e.type) {
      case "serve":
        this.rally = { shots: 0, lastSpeed: 0, server: e.a ?? 0, lastHitter: e.a ?? 0 };
        for (const s of this.crowd) if (s.fsm.current) s.fsm.stop();
        for (const j of this.judges) if (this.g.has(j.fsm.setup, "45020cf7")) j.fsm.play("45020cf7", { hold: 30 });
        break;
      case "hit": {
        this.rally.shots++; this.rally.lastHitter = e.a ?? this.rally.lastHitter;
        const v = snap?.ball?.vel; if (v) this.rally.lastSpeed = Math.hypot(v[0], v[1], v[2]) * 0.036;   // cm/s -> km/h
        break;
      }
      case "net":
        if (this.net) this.net.fsm.play("28bd8c9d", { hold: 1.2 });     // PORT: net shakes on contact
        break;
      case "fault":
      case "double_fault": {
        const side = SIDE(e.pos ? e.pos[2] : 0);
        for (const j of this.judges) {
          const n = "Fault" + side + (this.rnd() < 0.5 ? "" : "2");
          if (this.g.has(j.fsm.setup, n)) j.fsm.play(n);
        }
        if (e.type === "double_fault") this._crowd("DeceptionLow", 1.5);
        break;
      }
      case "point_end": {
        const winner = e.a ?? 0;
        const reasonName = REASON[e.b] ?? e.b;
        const facts = { reason: e.b, shots: this.rally.shots, lastSpeed: this.rally.lastSpeed,
                        serverWon: winner === this.rally.server, homeWon: winner === this.home };
        const ev = pointEvents(facts);
        const ratio = clamp(this.rally.shots / 12, 0, 1);       // PORT: rally length stands in for +0x344/+0x1048
        const before = this.level;
        this.level = excitementUpdate(this.level, { events: ev, ratio, shots: this.rally.shots });
        const tier = applauseLevel(this.level, ev);
        let req;
        if ((ev.includes("LoseUnforcedError") || ev.includes("LoseWinner")) && this.rally.shots >= 4) req = tier >= 2 ? "DeceptionAverage" : "DeceptionLow";
        else req = APPLAUSE[tier];
        this._crowd(req, 1.5 + tier * 1.2);                    // PORT hold times
        for (const j of this.judges) if (j.fsm.current) j.fsm.stop();
        this.log.push({ tick: e.tick, winner, reason: reasonName, events: ev, before, level: this.level, tier, req });
        break;
      }
      case "game": case "set": case "match":
        this._crowd(APPLAUSE[e.type === "game" ? 1 : 3], e.type === "game" ? 3 : 6);
        break;
      default: break;
    }
  }

  update(dt) {
    for (const o of this.officials) {
      if (o.flourishes.length && !o.fsm.current && o.fsm.name === o.idle) {
        o.next -= dt;
        if (o.next <= 0) {                                    // PORT: flourish every 6..16 s
          o.fsm.play(o.flourishes[Math.floor(this.rnd() * o.flourishes.length)]);
          o.next = 6 + this.rnd() * 10;
        }
      }
    }
    const out = [];
    for (const s of this.all()) out.push(s.fsm.update(dt));
    return out;
  }
}
