// Player appearance in the browser: loads a player export of tools/ts4_players.py (work/port/assets/players/
// <Baked_X>/player.gltf), switches the game's LODs by camera distance (Hierarchy Distance1 / Distance2, 1000 / 1500 cm
// on every shipped part, V data) and swaps the sweat / clay / grass texture variants (texture packs *_SWE, *_DST,
// *_GRA and the skin _<n>_0 packs, V names; which game state selects them is I, see docs/port/players.md s5).
import * as THREE from "three";
import { loadGltfRobust } from "../gltfload.js";

import { lodLevel, variantKey, pickVariant, useLevel } from "./appearance_pure.js";
export { lodLevel, variantKey, pickVariant, useLevel };

export class PlayerModel {
  constructor() { this.scene = null; this.lodNodes = []; this.materials = []; this.base = ""; this.texCache = new Map(); this.level = -1; this.info = null; }

  async load(url) {
    const gltf = await loadGltfRobust(url);
    this.attach(gltf.scene, url, gltf.parser?.json?.extras || null);
    return gltf;
  }

  /** wrap an already loaded player scene (e.g. PlayerRig.skeletonScene); url is the glTF's URL (texture base) */
  attach(scene, url, info = null) {
    this.base = url.slice(0, url.lastIndexOf("/") + 1);
    this.scene = scene; this.info = info; this.lodNodes = []; this.materials = [];
    const mats = new Set();
    scene.traverse((o) => {
      const ex = o.userData || {};
      if (o.isMesh || o.isSkinnedMesh) { o.castShadow = true; o.frustumCulled = false; mats.add(o.material); }
      if (ex.lod != null) this.lodNodes.push({ obj: o, lod: ex.lod, dists: ex.lod_distance_cm, part: ex.part });
    });
    for (const m of mats) { m.userData.baseMap = m.map; this.materials.push(m); }
    this.setLodDistance(0);
    return this;
  }

  /** show only the LOD of each part that the game would draw at this camera distance (cm) */
  setLodDistance(distCm) {
    for (const n of this.lodNodes) {
      const want = lodLevel(distCm, n.dists);
      const use = useLevel(want, this.lodNodes.filter((x) => x.part === n.part).map((x) => x.lod));
      n.obj.visible = n.lod === use;
    }
  }

  /** match condition -> texture variants (sweat 0..3, surface hard / clay / grass) */
  setCondition({ sweat = 0, surface = "hard" } = {}) {
    for (const m of this.materials) {
      const v = m.userData?.variants?.diffuse;
      const uri = sweat > 0 || surface === "clay" || surface === "grass" ? pickVariant(v, sweat, surface) : null;
      if (!uri) { if (m.map !== m.userData.baseMap) { m.map = m.userData.baseMap; m.needsUpdate = true; } continue; }
      let t = this.texCache.get(uri);
      if (!t) {
        t = new THREE.TextureLoader().load(this.base + uri);
        t.flipY = false; t.colorSpace = THREE.SRGBColorSpace;
        if (m.userData.baseMap) { t.wrapS = m.userData.baseMap.wrapS; t.wrapT = m.userData.baseMap.wrapT; }
        this.texCache.set(uri, t);
      }
      if (m.map !== t) { m.map = t; m.needsUpdate = true; }
    }
  }
}

/** players/index.json -> entries {arc, player, outfit, file, plays, height_cm, gender} */
export async function loadRoster(base) {
  const r = await fetch(base + "index.json");
  if (!r.ok) throw new Error("HTTP " + r.status + " for players/index.json");
  return (await r.json()).players || [];
}
