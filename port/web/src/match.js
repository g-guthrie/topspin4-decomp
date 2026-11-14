// Match session: drives ts4core (the reference binding port/core/js/ts4core.mjs) at a fixed 60 Hz from the frame
// clock and keeps the last two snapshots for render interpolation.  No DOM, no three.js (node can run it).
import { Ts4Core } from '../../core/js/ts4core.mjs';
import { FixedStepper, interpolateSnapshot } from './helpers.js';

export class MatchSession {
  constructor(core) {
    this.core = core;
    this.stepper = new FixedStepper(60, 6);
    this.prev = null;
    this.cur = null;
    this.events = [];           // decoded events since the last takeEvents()
    this.paused = false;
    this.timeScale = 1;         // 1 = real time
    this.humanIndex = 0;
    this.input = [{ x: 0, z: 0, buttons: 0 }, { x: 0, z: 0, buttons: 0 }];
    this.started = false;
    this.ticksRun = 0;
    this.onTick = null;         // optional (prev, cur, newEvents) callback after every tick (animation triggers)
  }

  static async load({ wasmUrl, blobUrl }) {
    const core = await Ts4Core.fromUrl(wasmUrl, blobUrl);
    if (core.loadResult !== 0) throw new Error('ts4_data_load failed: ' + core.loadResult + ' (TS4_ERR_*)');
    return new MatchSession(core);
  }

  /** returns the ts4_match_start result code (0 = ok); negative codes are TS4_ERR_* of ts4core.h */
  start(cfg) {
    const rc = this.core.startMatch(cfg);
    this.started = rc === 0;
    this.stepper.reset();
    this.prev = null;
    this.cur = this.started ? this.core.snapshot() : null;
    this.events = this.started ? this.core.pollEvents() : [];
    this.ticksRun = 0;
    return rc;
  }

  /** latch the input of a player for the following ticks (a held state, like a controller) */
  setInput(player, { x = 0, z = 0, buttons = 0 }) { this.input[player] = { x, z, buttons }; }

  /** one simulation tick (also used by tests and the single-step button) */
  tick() {
    const c = this.core;
    c.setInput(0, this.input[0]);
    c.setInput(1, this.input[1]);        // ignored by the core unless player 1 is human
    c.step();
    this.prev = this.cur;
    this.cur = c.snapshot();
    this.ticksRun++;
    const fresh = c.pollEvents();
    for (const e of fresh) this.events.push(e);
    if (this.onTick) this.onTick(this.prev, this.cur, fresh);
  }

  /** advance by a frame of `dt` real seconds; returns the number of ticks run */
  frame(dt) {
    if (!this.started || this.paused) return 0;
    const n = this.stepper.advance(dt * this.timeScale);
    for (let i = 0; i < n; i++) this.tick();
    return n;
  }

  /** the snapshot to render this frame: interpolated between the last two ticks */
  view() { return this.cur ? interpolateSnapshot(this.prev, this.cur, this.stepper.alpha) : null; }

  takeEvents() { const e = this.events; this.events = []; return e; }
}
