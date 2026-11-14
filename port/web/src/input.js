// Input mapping STUB: keyboard and gamepad -> the "shot request" structure of docs/gameplay/input-to-shot.md.
// What is faithful (H in that document): A/B/X/Y = Flat/TopSpin/Slice/Lob, LT and RT are both the Risk modifier
// (a held flag), RB = Rush/sprint, a shot is raised on RELEASE of the first held shot button (latch priority
// Flat > TopSpin > Slice > Lob), drop shot = Slice + Risk, smash is automatic, the left stick gives aim and movement.
// What is a port-side stub: the Medium/Powerful tiers.  In the game they come from analyser graphs (not decoded);
// here they come from how long the shot button was held (HOLD_MEDIUM / HOLD_POWERFUL seconds, invented).
// The request->template-row mapping is the decision tree of docs/gameplay/shot-to-template.md section 3; the real
// ts4core owns that tree (blob section TREE) and will replace rowForRequest().

export const SHOTS = ["Flat", "TopSpin", "Slice", "Lob"];          // latch priority order
export const HOLD_MEDIUM = 0.20;                                    // seconds, port stub
export const HOLD_POWERFUL = 0.45;                                  // seconds, port stub

// ts4core.h TS4_BTN_*
export const BTN = { FLAT: 1, TOPSPIN: 2, SLICE: 4, LOB: 8, RISK: 16, SPRINT: 32 };
const BTN_OF = { Flat: BTN.FLAT, TopSpin: BTN.TOPSPIN, Slice: BTN.SLICE, Lob: BTN.LOB };

export const KEYMAP = {
  Flat: ["KeyJ", "Space"], TopSpin: ["KeyK"], Slice: ["KeyU"], Lob: ["KeyI"],
  Risk: ["KeyL", "ControlLeft"], Sprint: ["ShiftLeft", "ShiftRight"],
  Up: ["KeyW", "ArrowUp"], Down: ["KeyS", "ArrowDown"], Left: ["KeyA", "ArrowLeft"], Right: ["KeyD", "ArrowRight"],
};

// Rows of Settings.bin (shot-to-template.md section 3).  `situation`: "baseline" | "volley" | "smash" | "serve".
export function rowForRequest(r) {
  if (r.situation === "smash" || r.flags.IsSmash) return 33;
  if (r.situation === "serve") {
    const kind = r.shot === "TopSpin" ? 0 : r.shot === "Slice" ? 1 : 2;
    if (r.advancedServe) return 29 + kind;
    const base = 20 + 3 * kind;                                    // Medium, Powerful, else
    return r.tier === "Medium" ? base : r.tier === "Powerful" ? base + 1 : base + 2;
  }
  if (r.situation === "volley") {
    if (r.shot === "TopSpin") return 16;
    if (r.shot === "Slice") return r.risk ? 18 : 17;
    return 19;                                                     // Flat, and Lob in volley mode
  }
  const tier = r.tier === "Powerful" ? 2 : r.tier === "Medium" ? 1 : 0;
  if (r.shot === "Slice" && r.risk) return 32;                     // drop shot = Slice + Risk
  const col = { TopSpin: 0, Slice: 1, Flat: 2, Lob: 3 }[r.shot];
  return 4 * tier + col;
}

export class InputMapper {
  constructor(target = window) {
    this.keys = new Set();
    this.held = { Flat: 0, TopSpin: 0, Slice: 0, Lob: 0 };         // seconds each shot button has been held
    this.latched = null;
    this.state = this._blank();
    this.situation = "baseline";
    this.pending = [];
    target.addEventListener("keydown", (e) => { if (!e.repeat) this.keys.add(e.code); });
    target.addEventListener("keyup", (e) => this.keys.delete(e.code));
    target.addEventListener("blur", () => this.keys.clear());
    this.lastPadId = null;
  }

  _blank() {
    return { buttons: { Flat: false, TopSpin: false, Slice: false, Lob: false, Risk: false, Sprint: false, SpeedSwing: false },
             move: { x: 0, z: 0 }, source: "none" };
  }

  _any(codes) { return codes.some((c) => this.keys.has(c)); }

  _poll() {
    const s = this._blank();
    const k = KEYMAP;
    for (const n of SHOTS) s.buttons[n] = this._any(k[n]);
    s.buttons.Risk = this._any(k.Risk);
    s.buttons.Sprint = this._any(k.Sprint);
    // stick: x = toward the opponent baseline (up / W), z = player's right (D)
    s.move.x = (this._any(k.Up) ? 1 : 0) - (this._any(k.Down) ? 1 : 0);
    s.move.z = (this._any(k.Right) ? 1 : 0) - (this._any(k.Left) ? 1 : 0);
    if (s.move.x || s.move.z || SHOTS.some((n) => s.buttons[n])) s.source = "keyboard";
    const pads = navigator.getGamepads ? navigator.getGamepads() : [];
    for (const p of pads) {
      if (!p || !p.connected) continue;
      const b = (i) => !!p.buttons[i]?.pressed;
      const dead = (v) => (Math.abs(v) < 0.4 ? 0 : v);                 // dead zone 0.4 on every channel (input-to-shot.md 2.4)
      const pad = {
        Flat: b(0), TopSpin: b(1), Slice: b(2), Lob: b(3),
        SpeedSwing: b(4), Sprint: b(5),
        Risk: (p.buttons[6]?.value ?? 0) > 128 / 255 || (p.buttons[7]?.value ?? 0) > 128 / 255,   // LT and RT > 128 of 255
      };
      const x = -dead(p.axes[1] ?? 0), z = dead(p.axes[0] ?? 0);
      if (Object.values(pad).some(Boolean) || x || z) {
        for (const n of Object.keys(pad)) s.buttons[n] = s.buttons[n] || pad[n];
        s.move.x = s.move.x || x; s.move.z = s.move.z || z;
        s.source = "gamepad:" + (p.id || "pad").slice(0, 24);
      }
    }
    return s;
  }

  // Call once per frame.  Returns the polled state; completed shot requests are queued for takeRequests().
  update(dt) {
    const s = this._poll();
    for (const n of SHOTS) this.held[n] = s.buttons[n] ? this.held[n] + dt : 0;
    if (!this.latched) {
      this.latched = SHOTS.find((n) => s.buttons[n]) || null;          // first held button wins: Flat > TopSpin > Slice > Lob
      this.latchRisk = false;
    }
    if (this.latched) {
      this.latchRisk = this.latchRisk || s.buttons.Risk;
      const stillDown = s.buttons[this.latched];
      this.latchHold = Math.max(this.latchHold || 0, this.held[this.latched]);
      if (!stillDown) {                                                // release edge = "Raise"
        this.pending.push(this._request(this.latched, this.latchHold || 0, s));
        this.latched = null; this.latchHold = 0;
      }
    }
    this.state = s;
    return s;
  }

  takeRequests() { const r = this.pending; this.pending = []; return r; }

  _request(shot, hold, s) {
    const tier = hold >= HOLD_POWERFUL ? "Powerful" : hold >= HOLD_MEDIUM ? "Medium" : "Finesse";
    const forward = Math.max(0, s.move.x);
    const req = {
      shot,                                     // "Flat" | "TopSpin" | "Slice" | "Lob"
      risk: this.latchRisk,                     // IsRisk: LT or RT held while the button was down
      rush: s.buttons.Sprint,                   // RB
      speedSwing: s.buttons.SpeedSwing,         // LB
      tier,                                     // STUB: from hold time (analyser graphs are not decoded)
      hold_s: +hold.toFixed(3),
      situation: this.situation,
      advancedServe: false,
      flags: {                                  // ShotSelection/Request/@Is* (input-to-shot.md section 4)
        IsFlat: shot === "Flat", IsTopSpin: shot === "TopSpin", IsSlice: shot === "Slice", IsLob: shot === "Lob",
        IsRisk: this.latchRisk, IsMedium: tier === "Medium", IsPowerful: tier === "Powerful",
        IsSmash: this.situation === "smash", ModeBaseLine: this.situation === "baseline",
        IsClassicServe: this.situation === "serve", IsAdvancedServe: false,
      },
      aim: {                                    // fn_8869C010: (lateral angle, forward depth 0..1) from the left stick
        lateral: Math.atan2(s.move.z, Math.max(forward, 1e-6)), depth: Math.min(1, forward), stick: { ...s.move },
      },
      source: s.source,
    };
    req.row = rowForRequest(req);
    return req;
  }

  // ts4core.h Ts4Input for ts4_set_input()
  toTs4Input() {
    const b = this.state.buttons;
    let mask = 0;
    for (const n of SHOTS) if (b[n]) mask |= BTN_OF[n];
    if (b.Risk) mask |= BTN.RISK;
    if (b.Sprint) mask |= BTN.SPRINT;
    return { stick_x: this.state.move.x, stick_z: this.state.move.z, buttons: mask };
  }
}
