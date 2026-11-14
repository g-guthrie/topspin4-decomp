// Retuning panel: the tunable registry of ts4core (edit live through ts4_set_tunable), the graph roles, an analyser
// graph evaluator and shot probes (ts4_shot_probe / ts4_shot_trace) with a pinned baseline for before/after
// comparison.  Units, origin (GAME = decoded from the game, PORT = invented by the port) and docs come from
// include/ts4_tunables.def, which the C ABI does not expose.
import {
  parseTunablesDef, parseRolesDef, groupTunables, parseNumber, diffOverrides, APPLY_ON_RESTART, summariseProbe, probeDelta,
} from "./helpers.js";
import { MODE } from "../../core/js/ts4core.mjs";
import { fmt } from "./config.js";

const STORE = "ts4port.tuning";
const el = (tag, attrs = {}, ...kids) => {
  const e = document.createElement(tag);
  for (const [k, v] of Object.entries(attrs)) {
    if (k === "class") e.className = v;
    else if (k === "text") e.textContent = v;
    else if (k.startsWith("on")) e.addEventListener(k.slice(2), v);
    else e.setAttribute(k, v);
  }
  kids.forEach((c) => e.append(c));
  return e;
};

export class TuningPanel {
  /** env: { root, core (Ts4Core), play (PlayMode), defsText, rolesText, shots, analyser, toast, restart() } */
  constructor(env) {
    this.env = env;
    this.core = env.core;
    this.defs = parseTunablesDef(env.defsText || "");
    this.roles = parseRolesDef(env.rolesText || "");
    this.byName = new Map(this.defs.map((d) => [d.name, d]));
    this.rows = new Map();                    // tunable name -> {input, def, tr}
    this.defaults = {};
    this.baseline = null;
    this.last = null;
    this.autoProbe = true;
    this.restartOnEdit = false;
    this.build();
  }

  // ---------------------------------------------------------------------------------------------- build
  build() {
    const { root } = this.env, core = this.core;
    root.textContent = "";
    const list = core.tunables();
    const known = new Set(list.map((t) => t.name));
    for (const t of list) this.defaults[t.name] = t.value;
    // stored overrides are re-applied before anything is drawn
    let stored = {};
    try { stored = JSON.parse(localStorage.getItem(STORE) || "{}"); } catch { stored = {}; }
    for (const [k, v] of Object.entries(stored)) if (known.has(k) && Number.isFinite(v)) core.setTunable(k, v);

    this.filter = el("input", { type: "search", placeholder: "filter tunables (name, unit, doc)", oninput: () => this.applyFilter() });
    this.modOnly = el("input", { type: "checkbox", onchange: () => this.applyFilter() });
    this.restartBox = el("input", { type: "checkbox", onchange: () => (this.restartOnEdit = this.restartBox.checked) });
    const file = el("input", { type: "file", accept: "application/json", style: "display:none", onchange: (e) => this.importFile(e.target.files[0]) });
    root.append(
      el("div", { class: "row" }, this.filter),
      el("div", { class: "row small" },
        el("label", {}, this.modOnly, " modified only"), el("label", {}, this.restartBox, " restart match on edit")),
      el("div", { class: "row" },
        el("button", { text: "Reset all", onclick: () => this.resetAll() }),
        el("button", { text: "Export overrides", onclick: () => this.exportJson() }),
        el("button", { text: "Import", onclick: () => file.click() }), file),
      el("div", { class: "small muted", text: "Edits apply immediately (ts4_set_tunable); rows marked R are read at match start, so restart the match. Enter or leaving a field commits. Overrides persist in this browser's localStorage; Export writes them as JSON. G = decoded from the game, P = invented by the port." }));

    const wrap = el("div", { id: "tunList" });
    const full = list.map((t) => ({ ...t, ...(this.byName.get(t.name) || { unit: "", origin: "?", required: false, doc: "(not in ts4_tunables.def)" }) }));
    for (const [g, items] of groupTunables(full)) {
      const det = el("details", { open: "" }, el("summary", { text: g + " (" + items.length + ")" }));
      const table = el("table", { class: "st tun" });
      for (const t of items) table.append(this.row(t));
      det.append(table);
      wrap.append(det);
    }
    root.append(wrap);
    // rows modified by restored overrides
    for (const [name, row] of this.rows) {
      const now = core.getTunable(name);
      row.input.value = this.fmtVal(now);
      row.tr.classList.toggle("modified", Math.abs(now - this.defaults[name]) > 1e-9 * Math.max(1, Math.abs(now)));
    }
    this.probeUi(root);
    this.rolesUi(root);
    this.applyFilter();
    this.runProbe();
  }

  row(t) {
    const input = el("input", { type: "text", value: this.fmtVal(t.value), size: "9", onchange: () => this.commit(t.name, input), onkeydown: (e) => { if (e.key === "Enter") input.blur(); } });
    const reset = el("button", { class: "mini", text: "x", title: "reset to the loaded value", onclick: () => { input.value = this.fmtVal(this.defaults[t.name]); this.commit(t.name, input); } });
    const origin = el("span", { class: "origin " + t.origin, text: t.origin === "GAME" ? "G" : t.origin === "PORT" ? "P" : "?", title: t.origin === "GAME" ? "decoded from the game (or its data)" : "invented by the port" });
    const nameCell = el("td", { class: "tn" }, origin, " " + t.name + " ");
    if (APPLY_ON_RESTART.has(t.name)) nameCell.append(el("span", { class: "muted", text: "R", title: "read at match start" }));
    const tr = el("tr", { title: t.doc }, nameCell, el("td", {}, input), el("td", { class: "muted", text: t.unit }), el("td", {}, reset));
    this.rows.set(t.name, { input, def: t, tr });
    return tr;
  }

  fmtVal(v) { return v == null ? "" : String(Number(v.toPrecision(7))); }

  commit(name, input) {
    const v = parseNumber(input.value);
    const row = this.rows.get(name);
    if (v === null) { input.value = this.fmtVal(this.core.getTunable(name)); this.env.toast("not a number"); return; }
    const rc = this.core.setTunable(name, v);
    if (rc !== 0) { this.env.toast("ts4_set_tunable(" + name + ") failed: " + rc); return; }
    const now = this.core.getTunable(name);
    input.value = this.fmtVal(now);
    row.tr.classList.toggle("modified", Math.abs(now - this.defaults[name]) > 1e-9 * Math.max(1, Math.abs(now)));
    this.persist();
    this.env.play?.refreshTunables();
    if (this.restartOnEdit) this.env.restart?.();
    if (this.autoProbe) this.runProbe();
    this.applyFilter();
  }

  overrides() {
    const cur = {};
    for (const name of this.rows.keys()) cur[name] = this.core.getTunable(name);
    return diffOverrides(cur, this.defaults);
  }

  persist() { try { localStorage.setItem(STORE, JSON.stringify(this.overrides())); } catch { /* storage may be unavailable */ } }

  resetAll() {
    for (const [name, row] of this.rows) { this.core.setTunable(name, this.defaults[name]); row.input.value = this.fmtVal(this.defaults[name]); row.tr.classList.remove("modified"); }
    this.persist(); this.env.play?.refreshTunables(); this.applyFilter(); if (this.autoProbe) this.runProbe();
    this.env.toast("all tunables reset to the loaded values");
  }

  exportJson() {
    const blob = new Blob([JSON.stringify({ _comment: "ts4core tunable overrides (port/web retuning panel)", tunables: this.overrides() }, null, 1)], { type: "application/json" });
    el("a", { href: URL.createObjectURL(blob), download: "ts4-tunable-overrides.json" }).click();
  }

  async importFile(f) {
    if (!f) return;
    try {
      const j = JSON.parse(await f.text()), t = j.tunables || j;
      let n = 0;
      for (const [k, v] of Object.entries(t)) { const row = this.rows.get(k); if (row && Number.isFinite(v)) { row.input.value = this.fmtVal(v); this.commit(k, row.input); n++; } }
      this.env.toast("imported " + n + " override(s)");
    } catch (e) { this.env.toast("import failed: " + e.message); }
  }

  applyFilter() {
    const q = this.filter.value.trim().toLowerCase(), mod = this.modOnly.checked;
    for (const [name, row] of this.rows) {
      const d = row.def, hay = (name + " " + d.unit + " " + d.doc).toLowerCase();
      row.tr.style.display = (!q || hay.includes(q)) && (!mod || row.tr.classList.contains("modified")) ? "" : "none";
    }
    document.querySelectorAll("#tunList details").forEach((det) => { det.style.display = [...det.querySelectorAll("tr")].some((r) => r.style.display !== "none") ? "" : "none"; });
  }

  // ---------------------------------------------------------------------------------------------- shot probes
  probeUi(root) {
    const tpl = this.env.shots?.rows?.filter((r) => r.file === "Settings.bin") || [];
    const n = this.core.templateCount();
    this.tpl = el("select", { onchange: () => this.runProbe() });
    for (let i = 0; i < n; i++) this.tpl.append(el("option", { value: i, text: i + ": " + (tpl[i] ? tpl[i].name + " (" + tpl[i].kind + "+" + tpl[i].secondary_kind + ")" : "template") }));
    this.tpl.value = Math.min(6, n - 1);
    const num = (v) => el("input", { type: "number", value: v, style: "width:64px", onchange: () => this.runProbe() });
    this.f = { fx: num(-1250), fy: num(100), fz: num(150), tx: num(1000), tz: num(-250) };
    this.blend = el("input", { type: "range", min: 0, max: 1, step: 0.05, value: 0.5, oninput: () => this.runProbe() });
    this.f4c = el("input", { type: "range", min: 0, max: 1, step: 0.05, value: 0, oninput: () => this.runProbe() });
    this.lefty = el("input", { type: "checkbox", onchange: () => this.runProbe() });
    this.mode = el("select", { onchange: () => this.runProbe() }, ...Object.keys(MODE).map((k) => el("option", { value: k, text: k })));
    this.auto = el("input", { type: "checkbox", checked: "", onchange: () => (this.autoProbe = this.auto.checked) });
    this.show3d = el("input", { type: "checkbox", checked: "", onchange: () => this.runProbe() });
    this.out = el("pre", { class: "out", text: "(pick a template)" });
    this.sideCv = el("canvas", { width: 330, height: 130, class: "cv" });
    this.topCv = el("canvas", { width: 330, height: 130, class: "cv" });
    root.append(el("h3", { text: "Shot probe" }),
      el("div", { class: "small muted", text: "ts4_shot_probe / ts4_shot_trace without a match. Pin a baseline, change a tunable, compare (orange = now, grey = baseline; side view and top view)." }),
      el("label", { class: "small" }, "template ", this.tpl),
      el("div", { class: "row small" }, "from x", this.f.fx, "y", this.f.fy, "z", this.f.fz),
      el("div", { class: "row small" }, "to x", this.f.tx, "z", this.f.tz),
      el("div", { class: "row small" }, el("label", {}, "spin blend ", this.blend), el("label", {}, "f4C ", this.f4c)),
      el("div", { class: "row small" }, el("label", {}, this.lefty, " left-handed"), el("label", {}, "mode ", this.mode)),
      el("div", { class: "row small" }, el("button", { text: "Probe", onclick: () => this.runProbe() }), el("button", { text: "Pin baseline", onclick: () => this.pin() }),
        el("button", { text: "Clear baseline", onclick: () => { this.baseline = null; this.runProbe(); } }),
        el("label", {}, this.auto, " re-probe on edit"), el("label", {}, this.show3d, " draw in 3D")),
      this.out, this.sideCv, this.topCv);
  }

  probeInput() {
    const v = (e) => parseFloat(e.value) || 0;
    return { row: +this.tpl.value, from: [v(this.f.fx), v(this.f.fy), v(this.f.fz)], to: [v(this.f.tx), 0, v(this.f.tz)], spinBlend: +this.blend.value,
             f4c: +this.f4c.value, leftHanded: this.lefty.checked, mode: MODE[this.mode.value], maxTicks: 480 };
  }

  runProbe() {
    if (!this.tpl) return;
    const inp = this.probeInput();
    const out = this.core.shotProbe(inp);
    if (typeof out === "number") { this.out.textContent = "ts4_shot_probe failed: " + out + " (TS4_ERR_*; -6 = unsolvable)"; this.last = null; this.draw(); return; }
    const pts = this.core.shotTrace(inp);
    if (typeof pts === "number") { this.out.textContent = "ts4_shot_trace failed: " + pts; return; }
    const radius = this.core.getTunable("ball.radius_cm") ?? 4;
    this.last = { inp, pts, sum: summariseProbe(out, pts, radius) };
    this.show();
    this.draw();
    this.env.play?.showTrace(this.show3d.checked ? pts : null);
  }

  pin() { if (!this.last) this.runProbe(); this.baseline = this.last; this.show(); this.draw(); this.env.toast("baseline pinned"); }

  show() {
    const s = this.last.sum, b = this.baseline?.sum, d = b ? probeDelta(b, s) : null;
    const line = (label, key, digits, unit = "") => {
      const v = s[key];
      const dv = d && d[key] != null && Math.abs(d[key]) > 1e-6 ? "   (" + (d[key] > 0 ? "+" : "") + fmt(d[key], digits) + ")" : "";
      return label.padEnd(14) + (v == null ? "n/a" : fmt(v, digits) + unit) + dv;
    };
    this.out.textContent = [
      line("flight time", "tau", 3, " s"), line("bounce tick", "bounceTick", 0), line("launch speed", "launchKmh", 1, " km/h"), line("arrival speed", "arriveKmh", 1, " km/h"),
      line("net height", "netCm", 1, " cm"), line("apex", "apexCm", 1, " cm"), line("lands x", "landX", 0, " cm"), line("lands z", "landZ", 0, " cm"),
      "raised for net " + s.raised + (s.netUnreachable ? "   NET UNREACHABLE" : ""),
      b ? "deltas are against the pinned baseline" : "no baseline pinned",
    ].join("\n");
  }

  draw() {
    const plot = (cv, proj, grid) => {
      const g = cv.getContext("2d"), W = cv.width, H = cv.height;
      g.clearRect(0, 0, W, H); g.fillStyle = "#10151a"; g.fillRect(0, 0, W, H);
      g.strokeStyle = "#2c3540"; g.lineWidth = 1; grid(g, W, H);
      const line = (pts, col) => {
        if (!pts) return;
        g.strokeStyle = col; g.beginPath();
        pts.forEach((p, i) => { const [x, y] = proj(p, W, H); if (i) g.lineTo(x, y); else g.moveTo(x, y); });
        g.stroke();
      };
      line(this.baseline?.pts, "#7a8794"); line(this.last?.pts, "#ff8a3d");
    };
    const X = (x, W) => ((x + 1400) / 2800) * W;
    plot(this.sideCv, (p, W, H) => [X(p[0], W), H - 8 - (p[1] / 500) * (H - 16)], (g, W, H) => {
      g.beginPath(); g.moveTo(0, H - 8); g.lineTo(W, H - 8); g.moveTo(X(0, W), H - 8); g.lineTo(X(0, W), H - 8 - (91.4 / 500) * (H - 16)); g.stroke();
    });
    plot(this.topCv, (p, W, H) => [X(p[0], W), H / 2 + (p[2] / 600) * (H / 2 - 6)], (g, W, H) => {
      const z = (v) => H / 2 + (v / 600) * (H / 2 - 6);
      g.strokeRect(X(-1188, W), z(-411.5), X(1188, W) - X(-1188, W), z(411.5) - z(-411.5));
      g.beginPath(); g.moveTo(X(0, W), z(-550)); g.lineTo(X(0, W), z(550)); g.moveTo(X(-640, W), z(-411.5)); g.lineTo(X(-640, W), z(411.5));
      g.moveTo(X(640, W), z(-411.5)); g.lineTo(X(640, W), z(411.5)); g.stroke();
    });
  }

  // ---------------------------------------------------------------------------------------------- roles and graphs
  rolesUi(root) {
    const st = this.core.moduleStatus();
    const det = el("details", {}, el("summary", { text: "Graph roles and modules" }));
    det.append(el("div", { class: "small", text: "modules: " + Object.entries(st).map(([k, v]) => k + " " + v).join(", ") }),
      el("div", { class: "small muted", text: "A role runs an analyser graph at a fixed point of the simulation; the blob's ROLE section binds its ports to core variables. A role with no record is not run (module degraded; the fallback is the variable's initial tunable). Use the evaluator below to see what a graph computes." }));
    const table = el("table", { class: "st" });
    for (const r of this.roles.roles) table.append(el("tr", { title: r.when }, el("td", { text: r.name }), el("td", { class: "muted", text: r.graph }), el("td", { class: "small", text: r.when })));
    det.append(table);
    root.append(det);
    const gc = this.core.graphCount();
    const meta = new Map((this.env.analyser?.graphs || []).map((g) => [g.name_hash, g]));
    const sel = el("select", {}), inputs = el("div", { class: "row small" }), outPre = el("pre", { class: "out" });
    const hex = (h) => h.toString(16).padStart(8, "0");
    for (let i = 0; i < gc; i++) {
      const gi = this.core.graphInfo(i), m = meta.get(hex(gi.hash));
      sel.append(el("option", { value: i, text: i + "  " + hex(gi.hash) + (m?.name ? " " + m.name : "") + "  (" + gi.inputs + " in, " + gi.outputs + " out)" }));
    }
    let fields = [];
    const evaluate = () => {
      const r = this.core.graphEval(+sel.value, fields.map((f) => parseFloat(f.value) || 0));
      outPre.textContent = typeof r === "number" ? "ts4_graph_eval failed: " + r : "outputs: " + r.map((v) => fmt(v, 5)).join(", ");
    };
    const rebuild = () => {
      inputs.textContent = ""; fields = [];
      const gi = this.core.graphInfo(+sel.value), m = meta.get(hex(gi.hash));
      for (let k = 0; k < gi.inputs; k++) {
        const f = el("input", { type: "number", value: 0, step: "any", style: "width:70px", onchange: evaluate });
        fields.push(f);
        inputs.append(el("label", {}, (m?.inputs?.[k]?.path_names?.[0] || "in" + k) + " ", f));
      }
      evaluate();
    };
    sel.addEventListener("change", rebuild);
    root.append(el("details", {}, el("summary", { text: "Analyser graph evaluator (" + gc + " graphs)" }), sel, inputs, outPre));
    if (gc) rebuild();
  }
}
