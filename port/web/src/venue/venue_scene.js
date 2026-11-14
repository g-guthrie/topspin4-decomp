// Venue scene: static stadium glTF + lights + sky + trackside + crowd, from the exports of tools/ts4_venue.py
// (tools/port/export_assets.py --only venues).  Frame: glTF, right handed, Y up, metres; the court centre is the
// origin, the net plane is x = 0 and game z is mirrored (z_gl = -z_game).  Use coreToVenue() for core positions.
import * as THREE from "three";
import { loadGltfRobust } from "../gltfload.js";
import { CrowdView, TracksideView, loadTrackside } from "./crowd.js";
import { TrackSideGraph, CrowdDirector } from "./crowd_fsm.js";

/** core / game world position (cm, left handed) -> venue glTF position (m) */
export const coreToVenue = (p) => [p[0] * 0.01, p[1] * 0.01, -p[2] * 0.01];

// PORT: sky colours per Desc WeatherKey (the game draws a sky dome mesh, "Sky02" in the hierarchy, kept in venue.gltf)
const SKY = { Sunny: 0x8fc3ec, Clear: 0x9cc8ef, Cloudy: 0xaab4be, Indoor: 0x1d2126 };

export async function fetchJson(url) {
  const r = await fetch(url);
  if (!r.ok) throw new Error("HTTP " + r.status + " for " + url);
  return r.json();
}

/** directional lights from venue.json lights (PackedLights.bin defs + hierarchy node directions) */
export function buildLights(vj) {
  const g = new THREE.Group(); g.name = "venueLights";
  const L = vj.lights || { defs: [], nodes: [] };
  const defs = new Map(L.defs.map((d) => [d.name, d]));
  const indoor = vj.desc?.e4e9cc69 === "Indoor";
  const weather = indoor ? "Indoor" : vj.desc?.WeatherKey;
  let main = null;
  for (const n of L.nodes) {
    const d = defs.get(n.name);
    if (!d || !d.multiplier || Math.hypot(...n.dir) < 0.5) continue;
    const col = new THREE.Color(...d.color);
    const light = new THREE.DirectionalLight(col, d.multiplier * (n.name === "PlayerLight" ? 1.0 : 2.2));
    light.name = n.name;
    light.position.set(-n.dir[0] * 60, -n.dir[1] * 60, -n.dir[2] * 60);
    light.target.position.set(0, 0, 0);
    g.add(light, light.target);
    if (!main && n.name !== "PlayerLight") main = light;
    if (n.name === "PlayerLight") light.intensity *= 0.35;     // PORT: the game applies it to players only
  }
  if (!main) {
    main = new THREE.DirectionalLight(0xffffff, 2.2); main.position.set(-20, 60, 30); g.add(main, main.target);
  }
  main.castShadow = true;
  main.shadow.mapSize.set(2048, 2048);
  const sc = main.shadow.camera; sc.left = -30; sc.right = 30; sc.top = 30; sc.bottom = -30; sc.near = 1; sc.far = 200;
  main.shadow.bias = -0.0005;
  const amb = defs.get("LightEnv")?.ambient_to_shadow ?? 0.8;
  const hemi = new THREE.HemisphereLight(SKY[weather] ?? SKY.Sunny, 0x404038, indoor ? 0.6 : 1.3 * amb);
  g.add(hemi);
  return { group: g, main, sky: new THREE.Color(SKY[weather] ?? SKY.Sunny), weather };
}

export class VenueScene {
  /** @param assets URL of work/port/assets/ ; name venue folder under venues/ */
  constructor(assets, name) {
    this.assets = assets; this.name = name;
    this.base = assets + "venues/" + name + "/";
    this.group = new THREE.Group(); this.group.name = "venue:" + name;
    this.netAnim = false; this.vj = null; this.crowd = null; this.trackside = null; this.director = null;
  }

  async load({ status = () => {}, crowd = true, trackside = true, tier = 2, staticScene = true, lights = true } = {}) {
    this.vj = await fetchJson(this.base + "venue.json");
    if (staticScene) {
      status("venue meshes");
      const g = await loadGltfRobust(this.base + this.vj.gltf, { onProgress: (n, m) => status("venue textures " + n + "/" + m) });
      g.scene.traverse((o) => { if (o.isMesh) { o.receiveShadow = true; } });
      this.static = g.scene; this.group.add(g.scene);
    }
    this.lights = buildLights(this.vj);
    if (lights) this.group.add(this.lights.group);
    if (!crowd && !trackside) return this;
    status("trackside skeletons");
    this.ts = await loadTrackside(this.assets + "venues/_trackside/");
    this.tsJson = await fetchJson(this.assets + "venues/_trackside/trackside.json");
    this.graph = new TrackSideGraph(this.tsJson);
    if (trackside) {
      status("officials");
      this.trackside = await new TracksideView(this.vj, this.ts, this.base).load();
      this.group.add(this.trackside.group);
    }
    if (crowd && this.vj.crowd?.file) {
      status("crowd");
      const cj = await fetchJson(this.base + this.vj.crowd.file);
      this.crowd = new CrowdView(cj, this.ts, this.base);
      this.crowd.tier = tier;
      await this.crowd.load((n, m) => status("crowd models " + n + "/" + m));
      this.group.add(this.crowd.group);
    }
    this._buildDirector();
    status("");
    return this;
  }

  _buildDirector() {
    const pl = this.trackside ? this.trackside.drivers.map((d) => d.placement) : [];
    const judges = [...new Set(pl.filter((p) => /^TS_LJ/.test(p.setup)).map((p) => p.setup))];
    const offIdx = [];
    const officials = [];
    pl.forEach((p, i) => { if (!/^TS_LJ/.test(p.setup)) { offIdx.push(i); officials.push({ setup: p.setup, behaviours: p.behaviours }); } });
    this.director = new CrowdDirector(this.graph, {
      crowd: this.crowd ? [...this.crowd.sections.keys()] : [],
      judges, net: this.trackside?.net ? "TS_NET00" : null, officials,
    });
    // which FSM drives which rig
    this.bindings = [];
    if (this.crowd) for (const s of this.director.crowd) this.bindings.push([s.fsm, this.crowd.sections.get(s.name)]);
    if (this.trackside) {
      pl.forEach((p, i) => {
        if (/^TS_LJ/.test(p.setup)) this.bindings.push([this.director.judges.find((j) => j.name === p.setup).fsm, this.trackside.drivers[i].driver]);
      });
      offIdx.forEach((i, k) => this.bindings.push([this.director.officials[k].fsm, this.trackside.drivers[i].driver]));
      // OPEN: the net clips (trackside_net.gltf) are keyed for a chained Filet_D01..09 / G01..09 hierarchy while the
      // exported net skeleton is flat under B_Hips, so playing them tears the net; it stays in its (correct) bind pose.
      // The net FSM still runs (director.net) so a fixed export only needs this binding back.
      if (this.trackside.net && this.director.net && this.netAnim) this.bindings.push([this.director.net.fsm, this.trackside.net]);
    }
    // PORT: the 16 crowd sections reuse 8 clip sets (SE08..15 = SE00..07); start them out of phase
    this.director.update(0);
    for (const [fsm, drv] of this.bindings) { drv.apply(fsm); if (drv.action) drv.action.time = Math.random() * drv.action.getClip().duration; }
  }

  onEvent(e, snap) { if (this.director) this.director.onEvent(e, snap); }

  update(dt) {
    if (!this.director) return;
    this.director.update(dt);
    for (const [fsm, drv] of this.bindings) drv.apply(fsm);
    if (this.crowd) this.crowd.update(dt);
    if (this.trackside) this.trackside.update(dt);
  }
}
