// Standalone player viewer (players.html): two exported players (tools/ts4_players.py export) driven by the game
// animation driver with a SCRIPTED state (no ts4core needed): baseline side-to-side movement and a swing every few
// seconds, exactly the inputs PlayMode feeds from Ts4PlayerView.  URL: ?assets= (default ../../work/port/assets/),
// ?p0= / ?p1= (player folders under assets/players/, default from players/index.json), ?t= (fixed start time, s).
import * as THREE from "three";
import { OrbitControls } from "three/addons/controls/OrbitControls.js";
import { PlayerRig } from "../player.js";
import { fetchJson } from "../config.js";
import { AnimTables } from "./anim_logic.js";
import { GameAnimator, ClipStore, recordToCore } from "./game_animator.js";
import { PlayerModel, loadRoster } from "./appearance.js";

const q = new URLSearchParams(location.search);
const assets = (q.get("assets") || "../../work/port/assets/").replace(/\/?$/, "/");
const hud = document.getElementById("hud");
const renderer = new THREE.WebGLRenderer({ antialias: true, preserveDrawingBuffer: true });
renderer.setSize(innerWidth, innerHeight); renderer.setPixelRatio(devicePixelRatio);
renderer.outputColorSpace = THREE.SRGBColorSpace; renderer.shadowMap.enabled = true;
document.body.prepend(renderer.domElement);
const scene = new THREE.Scene(); scene.background = new THREE.Color(0x2a3440);
const camera = new THREE.PerspectiveCamera(40, innerWidth / innerHeight, 0.05, 200);
camera.position.set(0, 1.6, 6.5);
const controls = new OrbitControls(camera, renderer.domElement); controls.target.set(0, 1.0, 0); controls.update();
scene.add(new THREE.HemisphereLight(0xffffff, 0x445566, 1.6));
const sun = new THREE.DirectionalLight(0xffffff, 2.2); sun.position.set(4, 8, 5); sun.castShadow = true; scene.add(sun);
const ground = new THREE.Mesh(new THREE.PlaneGeometry(30, 30), new THREE.MeshStandardMaterial({ color: 0x3b6e4f, roughness: 1 }));
ground.rotation.x = -Math.PI / 2; ground.receiveShadow = true; scene.add(ground);
addEventListener("resize", () => { renderer.setSize(innerWidth, innerHeight); camera.aspect = innerWidth / innerHeight; camera.updateProjectionMatrix(); });

const players = [];
async function main() {
  const [rules, clipMap, animDb] = await Promise.all([fetchJson(assets + "players/anim_rules.json"), fetchJson(assets + "clip_map.json"), fetchJson(assets + "animations.json")]);
  const roster = await loadRoster(assets + "players/");
  const tables = new AnimTables(rules);
  const pick = [q.get("p0"), q.get("p1")].map((p, i) => roster.find((e) => e.arc.replace(".arc", "") === p) || roster[i] || roster[0]);
  let chains = null;
  try { chains = await fetchJson(assets + "players/clip_chains.json"); } catch { chains = null; }
  let store = null;
  for (let i = 0; i < 2; i++) {
    const e = pick[i], rig = new PlayerRig();
    const url = assets + "players/" + e.file;
    await rig.loadSkeleton(url, { skinned: true });
    store ||= new ClipStore(rig.loader, assets, animDb, recordToCore(clipMap), chains);
    const an = new GameAnimator(rig, tables, store, { setup: e.gender === "Female" ? "Women" : "Men", leftHanded: e.plays === "LeftHanded" });
    await store.preload(an.wanted());
    const model = new PlayerModel().attach(rig.skeletonScene, url);
    scene.add(rig.root);
    players.push({ e, rig, an, model, x0: i ? 1.3 : -1.3 });
  }
  hud.textContent = "loaded " + store.raw.size + " clips";
  for (const id of ["sweat", "surface"]) document.getElementById(id).oninput = () => players.forEach((p) => p.model.setCondition({ sweat: +sweat.value, surface: surface.value }));
  requestAnimationFrame(loop);
}

// scripted state: run across (z) while facing the camera side (+x heading toward the viewer), swing every 4 s
const CLASSES = ["fh_topspin", "bh_topspin", "fh_slice", "bh_slice", "fh_flat", "bh_flat"];
let simT = +(q.get("t") || 0), last = performance.now();
function stateAt(t, p, k) {
  const cyc = t % 4;
  const phase = Math.floor(t / 4);
  const moving = cyc < 2.2;
  const dir = phase % 2 ? 1 : -1;
  const speed = moving ? (k ? 520 : 330) * Math.sin(Math.PI * cyc / 2.2) : 0;           // cm/s
  const swingState = cyc >= 2.4 && cyc < 2.9 ? 1 : cyc >= 2.9 && cyc < 3.6 ? 2 : 0;
  return { pos: [0, 0, 0], vel: [dir * speed, 0, 0], heading: Math.PI / 2,           // facing +z (the camera), moving sideways
           swingState, swingT: swingState === 1 ? (cyc - 2.4) / 0.5 : 1, recoveryFrac: swingState === 2 ? (cyc - 2.9) / 0.7 : 0,
           swingClass: CLASSES[(phase + k) % CLASSES.length] };
}
function loop(now) {
  const dt = Math.min(0.05, (now - last) / 1000); last = now;
  if (!document.getElementById("pause").checked) simT += dt;
  const lines = [];
  players.forEach((p, k) => {
    const st = stateAt(simT, p, k);
    p.rig.root.position.set(p.x0 + (st.vel[0] ? 0 : 0), 0, 0);
    p.rig.root.rotation.y = -st.heading;
    if (st.swingState === 0 && p.an.swing && !p.an.swing.ending) p.an.swing.ending = true;
    p.an.update(dt, st, { walk: 220, jog: 480, rush: 700, idleMax: 30 });
    p.model.setLodDistance(camera.position.distanceTo(p.rig.root.position) * 100);
    lines.push(p.e.player + " (" + p.e.plays + ")  loco " + (p.an.info.loco || "-") + "  sector " + p.an.info.sector + "  rate " + (p.an.info.rate || 0).toFixed(2) +
               (p.an.swing ? "\n    swing " + p.an.info.swing : ""));
  });
  hud.textContent = "t " + simT.toFixed(2) + "\n" + lines.join("\n");
  controls.update();
  renderer.render(scene, camera);
  requestAnimationFrame(loop);
}
main().catch((e) => { hud.textContent = "error: " + e.message; console.error(e); });
