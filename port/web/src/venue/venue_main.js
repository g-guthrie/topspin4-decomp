// Standalone venue + crowd viewer (port/web/venue.html).  Serve the repository root and open /port/web/venue.html.
//   ?assets=URL  folder written by tools/port/export_assets.py (default ../../work/port/assets/)
//   ?venue=NAME  venue folder under <assets>/venues/ (default Amsterdam)
//   ?tier=0|1|2  crowd quality (LOW/MEDIUM/HIGH groups of the crowd file)
// The "watch CPU match" button runs ts4core (two CPU players) through MatchSession and feeds its events to the
// crowd director; the ball and the players are drawn as markers placed with coreToVenue().
import * as THREE from "three";
import { OrbitControls } from "three/addons/controls/OrbitControls.js";
import { cfg } from "../config.js";
import { VenueScene, coreToVenue, fetchJson } from "./venue_scene.js";

const $ = (id) => document.getElementById(id);
const q = new URLSearchParams(location.search);

const canvas = $("vcanvas");
const renderer = new THREE.WebGLRenderer({ canvas, antialias: true });
renderer.setPixelRatio(Math.min(devicePixelRatio, 2));
renderer.shadowMap.enabled = true;
renderer.shadowMap.type = THREE.PCFSoftShadowMap;
const scene = new THREE.Scene();
const camera = new THREE.PerspectiveCamera(45, 1, 0.1, 2000);
camera.position.set(-26, 11, 0);
const controls = new OrbitControls(camera, canvas);
controls.target.set(0, 0.5, 0);
controls.update();

function resize() {
  const w = innerWidth, h = innerHeight;
  renderer.setSize(w, h, false); camera.aspect = w / h; camera.updateProjectionMatrix();
}
addEventListener("resize", resize); resize();

// markers for the core-driven ball and players (A4's skinned players can replace these; same coreToVenue frame)
const markers = new THREE.Group();
const ball = new THREE.Mesh(new THREE.SphereGeometry(0.033, 16, 12), new THREE.MeshStandardMaterial({ color: 0xd8f03c }));
const pl = [0x2d6cdf, 0xdf4a2d].map((c) => {
  const m = new THREE.Mesh(new THREE.CapsuleGeometry(0.25, 1.3, 4, 10), new THREE.MeshStandardMaterial({ color: c }));
  m.castShadow = true; return m;
});
markers.add(ball, ...pl); markers.visible = false; scene.add(markers);

let venue = null, session = null;
const status = (s) => { $("vStatus").textContent = s; };
const log = (s) => { const el = $("vlog"); el.textContent = (s + "\n" + el.textContent).slice(0, 4000); };

async function loadVenue(name) {
  if (venue) { scene.remove(venue.group); venue = null; }
  status("loading " + name);
  try {
    const v = new VenueScene(cfg.assets, name);
    scene.add(v.group);                    // parts appear as they load
    await v.load({ status, tier: +$("vTier").value });
    venue = v;
    scene.background = v.lights.sky;
    scene.fog = new THREE.Fog(v.lights.sky, 150, 900);
    if (v.crowd) { v.crowd.setTint($("vTint").checked); $("vCount").textContent = v.crowd.visibleCount + " shown"; }
    const d = v.vj.desc || {};
    log(name + ": " + [d.TypeKey, d.SurfaceKey, d.e4e9cc69, d.WeatherKey, d.CapacityKey].join(" / ") +
        " | crowd " + (v.vj.crowd?.count ?? 0) + " | lines " + JSON.stringify(Object.fromEntries(
          Object.entries(v.vj.court_lines?.check || {}).map(([k, c]) => [k, c.centre_minus_itf_cm]))));
  } catch (e) { status("failed: " + e.message); console.error(e); }
  document.title = "TS4 venue and crowd" + (venue ? " (ready)" : "");
}

async function init() {
  let names = [];
  try {
    const idx = await fetchJson(cfg.assets + "venues/index.json");
    names = idx.venues.map((v) => v.venue).filter((n) => n !== "PlayerBackGround");
  } catch { names = ["Amsterdam"]; }
  const sel = $("vVenue");
  for (const n of names) sel.add(new Option(n, n));
  sel.value = q.get("venue") || "Amsterdam";
  if (q.get("tier")) $("vTier").value = q.get("tier");
  await loadVenue(sel.value);
}

$("vLoad").onclick = () => loadVenue($("vVenue").value);
$("vTier").onchange = () => { if (venue?.crowd) { venue.crowd.setTier(+$("vTier").value); $("vCount").textContent = venue.crowd.visibleCount + " shown"; } };
$("vTint").onchange = () => venue?.crowd?.setTint($("vTint").checked);

// synthetic events (same shape as ts4core pollEvents) for trying reactions without the core
let shots = 0;
const fake = {
  serve: () => { shots = 0; return [{ type: "serve", a: 0 }]; },
  hit: () => [{ type: "hit", a: shots++ % 2 }],
  net: () => [{ type: "net", pos: [0, 90, 100] }],
  fault: () => [{ type: "fault", a: 0, pos: [600, 0, Math.random() < 0.5 ? 300 : -300] }],
  ace: () => [{ type: "serve", a: 0 }, { type: "hit", a: 0 }, { type: "point_end", a: 0, b: 4 }],
  winner: () => [{ type: "serve", a: 0 }, ...Array.from({ length: 9 }, (_, i) => ({ type: "hit", a: i % 2 })), { type: "point_end", a: 0, b: 3 }],
  error: () => [{ type: "serve", a: 1 }, ...Array.from({ length: 12 }, (_, i) => ({ type: "hit", a: (i + 1) % 2 })), { type: "point_end", a: 1, b: 1 }],
  game: () => [{ type: "game", a: 0 }],
};
for (const b of document.querySelectorAll("[data-ev]")) {
  b.onclick = () => { for (const e of fake[b.dataset.ev]()) feed(e, null); };
}

function feed(e, snap) {
  if (!venue) return;
  venue.onEvent(e, snap);
  if (e.type === "point_end" || e.type === "fault" || e.type === "net" || e.type === "game") {
    const r = venue.director.log.at(-1);
    log(e.type + (e.type === "point_end" && r ? " -> " + r.req + " lvl " + r.level.toFixed(2) + " [" + r.events.join(",") + "]" : ""));
  }
}

$("vMatch").onclick = async () => {
  if (session) { session.paused = !session.paused; return; }
  status("loading core");
  try {
    const { MatchSession } = await import("../match.js");
    session = await MatchSession.load({ wasmUrl: cfg.wasm, blobUrl: cfg.blob });
    const rc = session.start({ seed: 7, players: [{}, {}] });
    if (rc !== 0) throw new Error("match start " + rc);
    session.onTick = (prev, cur, fresh) => { for (const e of fresh) feed(e, cur); };
    markers.visible = true;
    status("");
  } catch (e) { session = null; status("core unavailable: " + e.message); }
};

const clock = new THREE.Clock();
function frame() {
  requestAnimationFrame(frame);
  const dt = Math.min(clock.getDelta(), 0.1);
  if (session) {
    session.timeScale = +$("vSpeed").value;
    session.frame(dt);
    const v = session.view();
    if (v) {
      ball.position.set(...coreToVenue(v.ball.pos));
      v.players.forEach((p, i) => { const w = coreToVenue(p.pos); pl[i].position.set(w[0], 0.9, w[2]); });
    }
  }
  if (venue) {
    venue.update(dt);
    const lvl = venue.director.level;
    $("vLevel").textContent = lvl.toFixed(2);
    $("vGaugeBar").style.width = (lvl * 100).toFixed(0) + "%";
  }
  controls.update();
  renderer.render(scene, camera);
}
init();
frame();
