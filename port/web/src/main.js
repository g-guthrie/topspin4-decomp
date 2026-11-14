// Top Spin 4 browser port: viewer (milestone 1).  Court scene, player skeleton with a clip browser, ball trajectory
// from ts4core (WASM) or the labelled JS fallback, keyboard/gamepad -> shot request stub.
import * as THREE from "three";
import { OrbitControls } from "three/addons/controls/OrbitControls.js";
import { buildCourt, COURT } from "./court.js";
import { PlayerRig } from "./player.js";
import { BallView } from "./ballview.js";
import { loadCore, MODE } from "./core.js";
import { InputMapper } from "./input.js";
import { cfg, fetchJson, fmt } from "./config.js";
import { PlayMode } from "./play.js";
import { TuningPanel } from "./tuning.js";

const $ = (id) => document.getElementById(id);
const state = { manifest: null, anim: null, shots: null, core: null, wasmNote: null, errors: [], selClip: null, selRecord: null, pairs: {} };

try { state.pairs = JSON.parse(localStorage.getItem("ts4port.clipmap") || "{}"); } catch { state.pairs = {}; }

function toast(msg, ms = 3500) {
  const t = $("toast");
  t.textContent = msg; t.style.display = "block";
  clearTimeout(toast.h); toast.h = setTimeout(() => (t.style.display = "none"), ms);
}

// ---------------------------------------------------------------------------------------------- scene
const canvas = $("view");
const renderer = new THREE.WebGLRenderer({ canvas, antialias: true });
renderer.setPixelRatio(Math.min(devicePixelRatio, 2));
renderer.shadowMap.enabled = true;
const scene = new THREE.Scene();
scene.background = new THREE.Color(0x0e1318);
const camera = new THREE.PerspectiveCamera(45, 1, 0.1, 400);
const controls = new OrbitControls(camera, canvas);
controls.enableDamping = true;
scene.add(new THREE.HemisphereLight(0xffffff, 0x334455, 0.9));
const sun = new THREE.DirectionalLight(0xffffff, 1.4);
sun.position.set(-12, 25, 10); sun.castShadow = true;
sun.shadow.mapSize.set(2048, 2048);
Object.assign(sun.shadow.camera, { left: -20, right: 20, top: 14, bottom: -14, near: 1, far: 70 });
scene.add(sun);
const courtGroup = buildCourt(cfg.surface);      // procedural fallback; hidden (net kept) once the exported venue loads
scene.add(courtGroup);
const grid = new THREE.AxesHelper(1); grid.position.set(-COURT.halfLength - 1, 0.01, -COURT.doublesHalfWidth - 1); scene.add(grid);

let play = null;                                  // PlayMode, created below
const CAMS = {
  broadcast: [[-24, 12, 0], [0, 0.5, 0]],
  behind: [[-19, 4.5, 0], [0, 1, 0]],
  side: [[0, 5, 20], [0, 1, 0]],
  top: [[0.01, 34, 0], [0, 0, 0]],
  player: [[-14, 2.2, 3.5], [-9, 1, 0]],
};
function setCam(name) {
  if (name === "follow") { play?.setFollow(true); $("mFollow").checked = true; return; }
  play?.setFollow(false); $("mFollow").checked = false;
  const [p, t] = CAMS[name];
  camera.position.set(...p); controls.target.set(...t); controls.update();
}
setCam("broadcast");
document.querySelectorAll("[data-cam]").forEach((b) => b.addEventListener("click", () => setCam(b.dataset.cam)));

function resize() {
  const s = $("stage");
  renderer.setSize(s.clientWidth, s.clientHeight, false);
  camera.aspect = s.clientWidth / s.clientHeight; camera.updateProjectionMatrix();
}
addEventListener("resize", resize); resize();

const rig = new PlayerRig();
scene.add(rig.root);
const ballView = new BallView(4);
scene.add(ballView.group);
const targetMark = new THREE.Mesh(new THREE.RingGeometry(0.15, 0.22, 24), new THREE.MeshBasicMaterial({ color: 0xff3366, side: THREE.DoubleSide }));
targetMark.rotation.x = -Math.PI / 2; targetMark.position.y = 0.012; scene.add(targetMark);
const fromMark = new THREE.Mesh(new THREE.RingGeometry(0.1, 0.16, 24), new THREE.MeshBasicMaterial({ color: 0x3dd6ff, side: THREE.DoubleSide }));
fromMark.rotation.x = -Math.PI / 2; fromMark.position.y = 0.012; scene.add(fromMark);

// ---------------------------------------------------------------------------------------------- tabs
function showTab(name) {
  document.querySelectorAll("#tabs button").forEach((x) => x.classList.toggle("active", x.dataset.tab === name));
  document.querySelectorAll(".tab").forEach((t) => t.classList.toggle("active", t.id === "tab-" + name));
  const playing = (name === "play" || name === "tune") && play.ready;
  play.setActive(playing);
  $("hud").classList.toggle("on", playing);
  rig.root.visible = !playing; ballView.group.visible = !playing; targetMark.visible = fromMark.visible = !playing;
}
document.querySelectorAll("#tabs button").forEach((b) => b.addEventListener("click", () => showTab(b.dataset.tab)));
play = new PlayMode({ scene, camera, controls, canvas, cfg, manifest: null, anim: null, toast, $ });

// ---------------------------------------------------------------------------------------------- loading
async function loadAll() {
  try { state.manifest = await fetchJson(cfg.assets + "manifest.json"); }
  catch (e) { state.errors.push("manifest.json: " + e.message); }
  try { state.anim = await fetchJson(cfg.assets + "animations.json"); }
  catch (e) { state.errors.push("animations.json: " + e.message); }
  try { state.shots = await fetchJson(cfg.assets + "gameplay/shots.json"); }
  catch (e) { state.errors.push("gameplay/shots.json: " + e.message); }

  const skel = state.manifest?.skeletons?.[0];
  if (skel) {
    try { await rig.loadSkeleton(cfg.assets + skel.file); }
    catch (e) { state.errors.push("skeleton: " + e.message); rig.showPlaceholder(); }
  } else { rig.showPlaceholder(); }
  placePlayer();

  if (state.shots) {
    const r = await loadCore({ wasmUrl: cfg.wasm, blobUrl: cfg.blob, shots: state.shots });
    state.core = r.core; state.wasmNote = r.wasmNote;
  }
  const badge = $("backend");
  if (state.core) {
    badge.textContent = state.core.label;
    badge.className = "badge " + state.core.kind;
  } else { badge.textContent = "no gameplay data: run the export"; badge.className = "badge"; }
  initClips(); initShot(); renderStatus();
  await initPlay();
}

// ---------------------------------------------------------------------------------------------- play and tune
async function initPlay() {
  play.env.manifest = state.manifest; play.env.anim = state.anim;
  const ok = await play.init();
  $("playStatus").textContent = "ts4core: " + play.status + (play.meshNote ? " | " + play.meshNote : "");
  if (!ok) {
    $("playUnavailable").hidden = $("tuneUnavailable").hidden = false;
    $("playUnavailable").textContent = $("tuneUnavailable").textContent = play.status;
    return;
  }
  const lib = play.lib;
  $("clipStatus").innerHTML = "Animation mapping: <b>" + (play.clipMapLoaded ? "clip_map.json present" : "PLACEHOLDER (clipmap.config.json)") + "</b>; " + lib.loaded.size + " clips loaded" +
    (lib.missing.size ? "; not exported: core:" + [...lib.missing].join(", core:") + " (export them with --core-clips)" : "") + (lib.failed.length ? "; failed: " + lib.failed.join("; ") : "");
  play.refreshTunables();
  $("matchForm").addEventListener("submit", (e) => { e.preventDefault(); startMatch(); });
  $("pauseBtn").addEventListener("click", () => { play.session.paused = !play.session.paused; $("pauseBtn").textContent = play.session.paused ? "Resume" : "Pause"; });
  $("stepBtn").addEventListener("click", () => { if (play.session.paused) play.session.tick(); });
  $("mScale").addEventListener("change", () => (play.session.timeScale = +$("mScale").value));
  $("mFollow").addEventListener("change", () => play.setFollow($("mFollow").checked));
  $("mDebug").addEventListener("change", () => { play.debug = $("mDebug").checked; $("hud").classList.toggle("dbg", play.debug); });
  $("mFollow").checked = play.follow;
  startMatch();
  showTab(document.querySelector("#tabs button.active").dataset.tab);
  const venue = await play.loadVenue(courtGroup);
  $("playStatus").textContent = "ts4core: " + play.status + (play.meshNote ? " | " + play.meshNote : "") + (venue ? " | venue: " + cfg.venue : "");
  if (!venue) $("playStatus").textContent += " | venue: procedural court" + (cfg.venue === "none" ? "" : " (exported venue not found at " + cfg.meshes + cfg.venue + ")");
  const text = async (u) => { try { const r = await fetch(u); return r.ok ? r.text() : ""; } catch { return ""; } };
  const [defsText, rolesText] = await Promise.all([text("../core/include/ts4_tunables.def"), text("../core/include/ts4_roles.def")]);
  let analyser = null; try { analyser = await fetchJson(cfg.assets + "gameplay/analyser.json"); } catch { analyser = null; }
  const panel = new TuningPanel({ root: $("tuneRoot"), core: play.session.core, play, defsText, rolesText, shots: state.shots, analyser, toast, restart: startMatch });
  if (Object.keys(panel.overrides()).length) { play.refreshTunables(); startMatch(); toast("restored saved tunable overrides"); }
  if (!defsText) $("tuneUnavailable").hidden = false, $("tuneUnavailable").textContent = "ts4_tunables.def not served: units and docs are missing";
}
function startMatch() {
  const rc = play.start({ format: $("mFormat").value, firstServer: +$("mServer").value, stats0: +$("mStats0").value, stats1: +$("mStats1").value,
                          seed: +$("mSeed").value, left0: $("mLeft").checked, surface: cfg.surface });
  if (rc !== 0) toast("ts4_match_start failed: " + rc + " (TS4_ERR_*)", 6000);
  play.session.paused = false; $("pauseBtn").textContent = "Pause";
}
addEventListener("keydown", (e) => {
  if (play.active && ["Space", "ArrowUp", "ArrowDown", "ArrowLeft", "ArrowRight"].includes(e.code) && !/^(INPUT|SELECT|TEXTAREA)$/.test(e.target.tagName)) e.preventDefault();
});

// ---------------------------------------------------------------------------------------------- clips
function contactSeconds(record, duration) {
  if (!record || record.contact == null) return null;
  return record.contact <= 1 ? record.contact * duration : record.contact / 60;
}
function clipListItems(mode, filter, exportedOnly) {
  const f = filter.trim().toLowerCase();
  if (mode === "core") {
    const clips = state.anim?.clips || [];
    return clips.filter((c) => (!exportedOnly || c.file) && (!f || (c.id + " " + c.codec + " " + c.tracks + "t").toLowerCase().includes(f)))
      .map((c) => ({ kind: "core", c, label: c.index + "  " + c.codec + "  " + fmt(c.duration) + "s  " + c.tracks + " tracks" + (c.additive ? " add" : ""), dim: !c.file }));
  }
  const recs = state.anim?.records || [];
  return recs.filter((r) => !f || (r.name || "").toLowerCase().includes(f) || String(r.index) === f)
    .map((r) => ({ kind: "record", r, label: r.name || r.id, dim: false }));
}
let clipMode = "core";
function renderClipList() {
  const box = $("cliplist");
  const items = clipListItems(clipMode, $("clipfilter").value, $("exportedOnly").checked);
  box.textContent = "";
  const frag = document.createDocumentFragment();
  items.slice(0, 600).forEach((it) => {
    const d = document.createElement("div");
    d.textContent = it.label; d.title = it.label;
    if (it.dim) d.classList.add("dim");
    d.addEventListener("click", () => { box.querySelectorAll(".sel").forEach((x) => x.classList.remove("sel")); d.classList.add("sel"); selectItem(it); });
    frag.appendChild(d);
  });
  if (items.length > 600) { const d = document.createElement("div"); d.className = "dim"; d.textContent = "... " + (items.length - 600) + " more, refine the filter"; frag.appendChild(d); }
  if (!items.length) { const d = document.createElement("div"); d.className = "dim"; d.textContent = state.anim ? "no match" : "animations.json not loaded"; frag.appendChild(d); }
  box.appendChild(frag);
}
async function selectItem(it) {
  if (it.kind === "core") { state.selClip = it.c; await playCoreClip(it.c); }
  else {
    state.selRecord = it.r;
    const linked = it.r.clip && state.anim.clips.find((c) => c.id === it.r.clip);
    const paired = state.pairs[it.r.name];
    const target = linked || (paired && state.anim.clips.find((c) => c.id === paired));
    if (target) { state.selClip = target; await playCoreClip(target); }
    else showRecordInfo();
  }
}
function showRecordInfo() {
  const r = state.selRecord;
  if (!r) return;
  const dur = rig.duration;
  const cs = dur ? contactSeconds(r, dur) : null;
  $("clipinfo").innerHTML = "<b>" + (r.name || r.id) + "</b><br>slot " + r.slot + ", id " + r.id +
    "<br>events: " + r.events.map((e) => e.name + "@" + fmt(e.time, 3)).join(", ") +
    "<br>contact (EventRacket) raw " + (r.contact == null ? "none" : fmt(r.contact, 3)) +
    (cs != null ? " = " + fmt(cs, 3) + " s of the playing clip (value &lt;= 1 read as a phase)" : "") +
    "<br>" + (r.clip ? "linked to " + r.clip : "no clip link (the record to clip mapping is not established; select a Core clip, then Pair)");
  updateContactMark();
}
async function playCoreClip(c) {
  if (!c.file) {
    $("clipinfo").innerHTML = "<b>core:" + c.index + "</b> was not exported. Run<br><code>python3 tools/port/export_assets.py --only havok animdb --core-clips " + c.index + "</code>";
    return;
  }
  if (!rig.mixer) { toast("no skeleton loaded: run the havok export part"); return; }
  try {
    await rig.loadClip(cfg.assets + c.file);
    rig.setPlaying(true); $("playBtn").textContent = "Pause";
    $("clipinfo").innerHTML = "<b>core:" + c.index + "</b> " + c.codec + ", " + fmt(c.duration, 3) + " s, " + c.frames + " frames, " + c.tracks + " tracks" +
      (c.additive ? ", additive" : "") + (state.selRecord ? "<br>record: " + (state.selRecord.name || "") : "");
    updateContactMark();
  } catch (e) { $("clipinfo").textContent = "failed to load clip: " + e.message; }
}
function updateContactMark() {
  const m = $("contactMark"), dur = rig.duration;
  const cs = state.selRecord && dur ? contactSeconds(state.selRecord, dur) : null;
  if (cs == null || cs > dur) { m.style.display = "none"; return; }
  const s = $("scrub");
  m.style.display = "block";
  m.style.left = s.offsetLeft + 8 + (s.clientWidth - 16) * (cs / dur) + "px";
}
function initClips() {
  document.querySelectorAll("input[name=clipmode]").forEach((r) => r.addEventListener("change", () => { clipMode = r.value; renderClipList(); }));
  $("clipfilter").addEventListener("input", renderClipList);
  $("exportedOnly").addEventListener("change", renderClipList);
  $("playBtn").addEventListener("click", () => { rig.setPlaying(!rig.playing); $("playBtn").textContent = rig.playing ? "Pause" : "Play"; });
  $("scrub").addEventListener("input", () => { rig.setPlaying(false); $("playBtn").textContent = "Play"; rig.seek(($("scrub").value / 1000) * rig.duration); });
  $("speed").addEventListener("input", () => (rig.speed = +$("speed").value));
  $("loop").addEventListener("change", () => rig.setLoop($("loop").checked));
  $("yaw").addEventListener("input", () => { if (rig.facing) rig.facing.rotation.y = -rig.forwardYaw + (+$("yaw").value * Math.PI) / 180; });
  $("pairBtn").addEventListener("click", () => {
    if (!state.selRecord || !state.selClip) { toast("select a swing record, then a Core clip"); return; }
    state.pairs[state.selRecord.name] = state.selClip.id;
    try { localStorage.setItem("ts4port.clipmap", JSON.stringify(state.pairs)); } catch { /* storage may be unavailable */ }
    renderPairs();
  });
  $("dlPairs").addEventListener("click", () => {
    const a = document.createElement("a");
    a.href = URL.createObjectURL(new Blob([JSON.stringify(state.pairs, null, 1)], { type: "application/json" }));
    a.download = "clip-map.json"; a.click();
  });
  renderClipList(); renderPairs();
}
function renderPairs() { $("pairInfo").textContent = Object.keys(state.pairs).length + " pairing(s) saved in this browser; feed clip-map.json to export_assets.py --clip-map"; }

// ---------------------------------------------------------------------------------------------- shot
const num = (id) => parseFloat($(id).value) || 0;
function shotInput() {
  return {
    row: +$("tplSel").value, from: [num("fx"), num("fy"), num("fz")], to: [num("tx"), 0, num("tz")],
    spin_blend: num("blend"), f4c: num("f4c"), left_handed: $("lefty").checked ? 1 : 0,
    mode: $("mode").value === "net" ? MODE.NET : MODE.IN, planned: 1, speed_kmh: 0, aim_height_m: 0,
  };
}
function syncMarks() {
  fromMark.position.x = num("fx") * 0.01; fromMark.position.z = num("fz") * 0.01;
  targetMark.position.x = num("tx") * 0.01; targetMark.position.z = num("tz") * 0.01;
  placePlayer();
}
function placePlayer() {
  rig.root.position.set(num("fx") * 0.01, 0, num("fz") * 0.01);
  rig.root.rotation.y = num("fx") < 0 ? 0 : Math.PI;
}
function launch(inp) {
  if (!state.core) return;
  try {
    const t = state.core.trace(inp, 480);
    ballView.rate = num("ballRate");
    ballView.setTrajectory(t.points, t.events);
    const i = t.info, pts = t.points, n = pts.length / 3;
    let apex = 0; for (let k = 0; k < n; k++) apex = Math.max(apex, pts[3 * k + 1]);
    const land = t.events.find((e) => e.type === "bounce");
    const arr = Math.hypot(...i.arrive_vel) * 3.6;
    let netY = null;                                                   // ball-centre height where the trace crosses x = 0 (cm)
    for (let k = 1; k < n && netY == null; k++) {
      const x0 = pts[3 * k - 3], x1 = pts[3 * k];
      if (x0 * x1 < 0) netY = pts[3 * k - 2] + (pts[3 * k + 1] - pts[3 * k - 2]) * (Math.abs(x0) / (Math.abs(x0) + Math.abs(x1)));
    }
    $("shotOut").textContent =
      "backend        " + state.core.label + "\n" +
      "template       #" + inp.row + " " + state.shots.rows.filter((r) => r.file === "Settings.bin")[inp.row].name + "\n" +
      "flight time    " + fmt(i.tau, 3) + " s (bounce tick " + i.bounce_tick + ")\n" +
      "launch speed   " + fmt(i.initial_kmh, 1) + " km/h, arrival " + fmt(arr, 1) + " km/h\n" +
      "net plane      ball centre " + (netY == null ? "does not cross" : fmt(netY / 100, 2) + " m") + " (net 0.914 m)" + (i.raised ? ", flight time raised to clear the net" : "") + (i.net_unreachable ? ", NET UNREACHABLE" : "") + "\n" +
      "apex           " + fmt(apex / 100, 2) + " m\n" +
      "first bounce   " + (land ? "x " + fmt(land.pos[0], 0) + " z " + fmt(land.pos[2], 0) + " cm (tick " + land.tick + ")" : "none") + "\n" +
      "events         " + t.events.map((e) => e.type + "@" + e.tick).join(", ");
  } catch (e) { $("shotOut").textContent = "launch failed: " + e.message; }
}
const PRESETS = {
  "fh-cross": { row: 6, from: [-1250, 100, 150], to: [1000, 0, -250] },
  serve: { row: 26, from: [-1200, 270, 100], to: [550, 0, -200] },
  volley: { row: 19, from: [-250, 100, 0], to: [1000, 0, -200] },
  lob: { row: 7, from: [-1250, 100, 100], to: [1100, 0, -100] },
};
function initShot() {
  if (!state.core) {
    $("shotUnavailable").hidden = false;
    $("shotUnavailable").textContent = "gameplay/shots.json is missing. Run: python3 tools/port/export_assets.py --only gameplay";
    return;
  }
  const sel = $("tplSel");
  state.shots.rows.filter((r) => r.file === "Settings.bin").forEach((r, i) => {
    const o = document.createElement("option");
    o.value = i; o.textContent = i + ": " + r.name + " (" + r.kind + "+" + r.secondary_kind + ")"; sel.appendChild(o);
  });
  sel.value = 6;
  $("blend").addEventListener("input", () => ($("blendOut").value = $("blend").value));
  $("f4c").addEventListener("input", () => ($("f4cOut").value = $("f4c").value));
  ["fx", "fy", "fz", "tx", "tz"].forEach((id) => $(id).addEventListener("input", syncMarks));
  $("shotForm").addEventListener("submit", (e) => { e.preventDefault(); launch(shotInput()); });
  document.querySelectorAll("[data-preset]").forEach((b) => b.addEventListener("click", () => {
    const p = PRESETS[b.dataset.preset];
    $("tplSel").value = p.row; $("fx").value = p.from[0]; $("fy").value = p.from[1]; $("fz").value = p.from[2];
    $("tx").value = p.to[0]; $("tz").value = p.to[2];
    syncMarks(); launch(shotInput());
  }));
  syncMarks();
}

// click the court: target, shift+click: contact point
const ray = new THREE.Raycaster(), ndc = new THREE.Vector2();
let down = null;
canvas.addEventListener("pointerdown", (e) => (down = [e.clientX, e.clientY]));
canvas.addEventListener("pointerup", (e) => {
  if (!down || Math.hypot(e.clientX - down[0], e.clientY - down[1]) > 4 || !state.core) return;
  const r = canvas.getBoundingClientRect();
  ndc.set(((e.clientX - r.left) / r.width) * 2 - 1, -((e.clientY - r.top) / r.height) * 2 + 1);
  ray.setFromCamera(ndc, camera);
  const p = new THREE.Vector3();
  if (!ray.ray.intersectPlane(new THREE.Plane(new THREE.Vector3(0, 1, 0), 0), p)) return;
  const [ix, iz] = e.shiftKey ? ["fx", "fz"] : ["tx", "tz"];
  $(ix).value = Math.round(p.x * 100); $(iz).value = Math.round(p.z * 100);
  syncMarks();
});

// ---------------------------------------------------------------------------------------------- input
const input = new InputMapper(window);
function initInput() {
  $("situation").addEventListener("change", () => (input.situation = $("situation").value));
}
function handleRequests() {
  for (const req of input.takeRequests()) {
    $("requestOut").textContent = JSON.stringify(req, null, 1);
    if (!state.core) continue;
    const n = state.shots.rows.filter((r) => r.file === "Settings.bin").length;
    if (req.row >= n) continue;
    $("tplSel").value = req.row;
    if (req.aim.depth > 0 || Math.abs(req.aim.stick.z) > 0) {          // stub: stick -> landing point (aim tables are not decoded)
      $("tx").value = Math.round(300 + req.aim.depth * 800);
      $("tz").value = Math.round(Math.max(-1, Math.min(1, req.aim.stick.z)) * 412);
    }
    syncMarks();
    if ($("autoLaunch").checked) launch(shotInput());
    toast("shot request: " + req.shot + (req.risk ? " + risk" : "") + ", " + req.tier + " -> row " + req.row);
  }
}

// ---------------------------------------------------------------------------------------------- status
function renderStatus() {
  const m = state.manifest, rows = [];
  const parts = m?.parts || {};
  for (const p of ["havok", "animdb", "gameplay", "meshes"]) {
    const s = parts[p];
    rows.push("<tr><td>" + p + "</td><td class='" + (s ? s.status : "skipped") + "'>" + (s ? s.status : "not run") + "</td><td>" + (s ? s.message : "") + "</td></tr>");
  }
  const g = m?.gameplay || {};
  const blob = g.blob ? g.blob.status + (g.blob.message ? ": " + g.blob.message : "") : "n/a";
  $("statusOut").innerHTML =
    "<p class='small'>assets <code>" + cfg.assets + "</code><br>wasm <code>" + cfg.wasm + "</code></p>" +
    "<table class='st'>" + rows.join("") + "</table>" +
    "<p class='small'><b>ts4core backend</b><br>" + (state.core ? state.core.label : "none") + (state.wasmNote ? "<br><span class='muted'>WASM not used: " + state.wasmNote + "</span>" : "") +
    "<br><b>data blob</b> " + blob + "</p>" +
    (state.errors.length ? "<p class='warn small'>" + state.errors.map((e) => "&bull; " + e).join("<br>") + "</p>" : "") +
    (m ? "" : "<p class='warn small'>No manifest.json: export first<br><code>python3 tools/port/export_assets.py --iso &lt;your disc image&gt;</code></p>") +
    "<p class='small muted'>Court dimensions are procedural (ITF). Player meshes and venue geometry are not loaded yet.</p>";
}

// ---------------------------------------------------------------------------------------------- loop
let last = performance.now();
function frame(now) {
  const dt = Math.min((now - last) / 1000, 0.1); last = now;
  input.update(dt);
  if (play.active) { input.takeRequests(); play.update(dt, input.toTs4Input()); } else handleRequests();
  if (rig.mixer && !play.active) {
    rig.update(dt);
    if (rig.clip) {
      const d = rig.duration || 1;
      $("scrub").value = Math.round((rig.time / d) * 1000);
      $("timeLabel").textContent = fmt(rig.time) + " / " + fmt(d) + " s";
    }
  }
  ballView.rate = num("ballRate") || 0.5;
  ballView.update(dt);
  if ($("tab-input").classList.contains("active")) {
    $("inputState").textContent = JSON.stringify({ ...input.state, ts4_input: input.toTs4Input(), latched: input.latched }, null, 1);
  }
  if (!(play.active && play.follow)) controls.update();
  renderer.render(scene, camera);
  requestAnimationFrame(frame);
}
window.__ts4 = { state, input, get play() { return play; } };      // console hook for debugging
initInput();
requestAnimationFrame(frame);                    // the loop runs while assets load (the venue is large)
loadAll().catch((e) => { console.error(e); toast("startup error: " + e.message, 8000); });
