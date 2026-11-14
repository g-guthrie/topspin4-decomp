// Crowd and trackside rendering (three.js).  Reads the exports of tools/ts4_venue.py:
//   venues/_trackside/trackside_human.gltf, trackside_net.gltf  shared TrackSide.hkx skeletons + clips ("clipNNN" =
//                                                               binding index, the AnimID space of the behaviour lists)
//   venues/<V>/crowd.json      one row per spectator (glTF metres, yaw, scale, atlas offset, two tints, setup, tier)
//   venues/<V>/trackside/*.gltf crowd models and officials, skinned to the 19-bone TrackSide skeleton
// The game shares one animated skeleton per setup (TS_SE00..15 for the crowd), so here every crowd section is one
// rig + AnimationMixer and every (model, section) pair is ONE instanced skinned draw call bound to that rig.
// three r160 has no instanced SkinnedMesh; the vertex shader chunks support both at once (skinning runs before
// the instance matrix), so a SkinnedMesh flagged isInstancedMesh with an instanceMatrix draws instanced.
import * as THREE from "three";
import * as SkeletonUtils from "three/addons/utils/SkeletonUtils.js";
import { loadGltfRobust } from "../gltfload.js";

const clipIndex = (name) => { const m = /^clip(\d+)$/.exec(name || ""); return m ? +m[1] : -1; };

/** the shared skeleton glTFs: { human: {scene, clips: Map<int, AnimationClip>}, net: {...} } */
export async function loadTrackside(base) {
  const out = {};
  for (const [k, f] of [["human", "trackside_human.gltf"], ["net", "trackside_net.gltf"]]) {
    const g = await loadGltfRobust(base + f);
    out[k] = { scene: g.scene, clips: new Map(g.animations.map((a) => [clipIndex(a.name), a])) };
  }
  return out;
}

/** a bone hierarchy + mixer that plays FSM frames ({clip, changed}) with a short cross-fade */
export class RigDriver {
  constructor(root, clips, { fade = 0.25, timeScale = 1 } = {}) {
    this.root = root; this.clips = clips; this.fade = fade;
    this.mixer = new THREE.AnimationMixer(root);
    this.mixer.timeScale = timeScale;
    this.action = null; this.clip = null;
  }
  apply(frame) {
    if (!frame || frame.clip === null || frame.clip === undefined) return;
    if (!frame.changed && frame.clip === this.clip) return;
    if (frame.clip === this.clip && this.action) { this.action.reset().play(); return; }
    const c = this.clips.get(frame.clip);
    if (!c) return;
    const a = this.mixer.clipAction(c);
    a.reset(); a.setLoop(THREE.LoopRepeat, Infinity); a.enabled = true; a.setEffectiveWeight(1);
    a.time = Math.min(frame.time || 0, c.duration);
    if (this.action && this.action !== a) a.crossFadeFrom(this.action, this.fade, false);
    a.play();
    this.action = a; this.clip = frame.clip;
  }
  update(dt) { this.mixer.update(dt); }
}

function bonesByName(root) {
  const m = new Map();
  root.traverse((o) => { if (o.name && !m.has(o.name)) m.set(o.name, o); });
  return m;
}

function firstSkinned(scene) {
  let s = null;
  scene.traverse((o) => { if (!s && o.isSkinnedMesh) s = o; });
  return s;
}

/** material copy that adds the per-instance 2x2 atlas offset (crowd.json du, dv) to the base colour UV */
function atlasMaterial(src, tint) {
  const m = src.clone();
  m.onBeforeCompile = (sh) => {
    sh.vertexShader = sh.vertexShader
      .replace("#include <common>", "#include <common>\nattribute vec2 instUV;")
      .replace("#include <uv_vertex>", "#include <uv_vertex>\n#ifdef USE_MAP\n\tvMapUv += instUV;\n#endif");
  };
  m.customProgramCacheKey = () => "ts4crowd" + (tint ? "t" : "");
  return m;
}

export class CrowdView {
  /**
   * @param crowd   crowd.json
   * @param ts      loadTrackside() result
   * @param modelBase URL of venues/<V>/ (model_files are relative to it)
   */
  constructor(crowd, ts, modelBase) {
    this.crowd = crowd; this.ts = ts; this.base = modelBase;
    this.group = new THREE.Group(); this.group.name = "crowd";
    this.sections = new Map();      // setup name -> RigDriver
    this.meshes = [];
    this.tier = 2; this.tint = true;
  }

  async load(onProgress) {
    const c = this.crowd, col = Object.fromEntries(c.columns.map((n, i) => [n, i]));
    // one rig per setup used by this venue's crowd
    for (const s of c.setups) {
      const rig = SkeletonUtils.clone(this.ts.human.scene);
      rig.name = "rig_" + s;
      this.group.add(rig);
      this.sections.set(s, new RigDriver(rig, this.ts.human.clips));
    }
    // bucket rows by (model, setup), sorted by tier so a tier is a prefix
    const buckets = new Map();
    for (const r of c.rows) {
      const k = r[col.model] + ":" + r[col.setup];
      if (!buckets.has(k)) buckets.set(k, []);
      buckets.get(k).push(r);
    }
    let done = 0;
    for (let mi = 0; mi < c.models.length; mi++) {
      const name = c.models[mi];
      const file = c.model_files?.[name];
      if (!file) continue;
      let src;
      try { src = firstSkinned((await loadGltfRobust(this.base + file)).scene); } catch (e) { console.warn("crowd model", name, e); }
      if (onProgress) onProgress(++done, c.models.length);
      if (!src) continue;
      const jointNames = src.skeleton.bones.map((b) => b.name);
      for (let si = 0; si < c.setups.length; si++) {
        const rows = buckets.get(mi + ":" + si);
        if (!rows) continue;
        rows.sort((a, b) => a[col.tier] - b[col.tier]);
        const n = rows.length;
        const geo = src.geometry.clone();
        const uv = new Float32Array(n * 2), colors = new Float32Array(n * 3), mats = new Float32Array(n * 16);
        const m4 = new THREE.Matrix4(), q = new THREE.Quaternion(), p = new THREE.Vector3(), sc = new THREE.Vector3();
        const yAxis = new THREE.Vector3(0, 1, 0);
        const nt = Math.max(1, (c.groups || []).length);   // 1..4 groups per venue on disc
        const tierCount = new Array(nt).fill(0);
        rows.forEach((r, i) => {
          p.set(r[col.x], r[col.y], r[col.z]);
          q.setFromAxisAngle(yAxis, r[col.yaw]);
          sc.set(r[col.sx], r[col.sy], r[col.sz]);
          m4.compose(p, q, sc).toArray(mats, i * 16);
          uv[i * 2] = r[col.du]; uv[i * 2 + 1] = r[col.dv];
          colors.set([r[col.rA], r[col.gA], r[col.bA]], i * 3);
          for (let t = r[col.tier]; t < nt; t++) tierCount[t]++;
        });
        geo.setAttribute("instUV", new THREE.InstancedBufferAttribute(uv, 2));
        const mesh = new THREE.SkinnedMesh(geo, atlasMaterial(src.material, true));
        const rig = bonesByName(this.sections.get(c.setups[si]).root);
        const bones = jointNames.map((j) => rig.get(j));
        mesh.bind(new THREE.Skeleton(bones, src.skeleton.boneInverses.map((b) => b.clone())), new THREE.Matrix4());
        // instancing on a skinned mesh (see header)
        mesh.isInstancedMesh = true;
        mesh.instanceMatrix = new THREE.InstancedBufferAttribute(mats, 16);
        mesh.instanceColor = new THREE.InstancedBufferAttribute(colors, 3);
        mesh._tint = colors.slice();
        mesh.count = n;
        mesh.tierCount = tierCount;
        mesh.frustumCulled = false;
        mesh.name = name + "@" + c.setups[si];
        this.group.add(mesh);
        this.meshes.push(mesh);
      }
    }
    this.setTier(this.tier);
    return this;
  }

  /**
   * crowd quality: 0 = LOW (group 0 only), 1 = MEDIUM (groups 0..1), 2 = HIGH (every group).  The crowd files hold
   * 1..4 consecutive groups (Amsterdam 3, ArthurAshe 4, Athens 2); reading them as the CrowdLODList quality steps
   * is an inference (docs/port/venues-and-crowd.md).
   */
  setTier(t) {
    this.tier = t;
    for (const m of this.meshes) {
      const tc = m.tierCount;
      m.count = t >= 2 ? tc[tc.length - 1] : tc[Math.min(t, tc.length - 1)];
    }
  }

  setTint(on) {
    this.tint = on;
    for (const m of this.meshes) {
      const a = m.instanceColor.array;
      if (on) a.set(m._tint); else a.fill(1);
      m.instanceColor.needsUpdate = true;
    }
  }

  get visibleCount() { return this.meshes.reduce((s, m) => s + m.count, 0); }

  update(dt) { for (const d of this.sections.values()) d.update(dt); }
}

/**
 * Officials, ball kids, line judges, umpire and the net: ordinary skinned meshes, one rig each, placed by the
 * hierarchy matrices exported in venue.json trackside.placements (glTF frame, column major).
 */
export class TracksideView {
  constructor(venueJson, ts, modelBase) {
    this.v = venueJson; this.ts = ts; this.base = modelBase;
    this.group = new THREE.Group(); this.group.name = "trackside";
    this.drivers = [];        // { placement, driver }
    this.net = null;
  }

  async load() {
    const t = this.v.trackside || {};
    const models = t.models || {};
    const cache = new Map();
    const get = async (file) => {
      if (!cache.has(file)) cache.set(file, loadGltfRobust(this.base + file).catch((e) => { console.warn(file, e); return null; }));
      return cache.get(file);
    };
    for (const p of t.placements || []) {
      const key = models[p.mesh] ? p.mesh : (p.material || "").replace(/_\d+$/, "");
      const file = models[key];
      if (!file) continue;
      const g = await get(file);
      if (!g) continue;
      const inst = SkeletonUtils.clone(g.scene);
      inst.matrixAutoUpdate = false;
      inst.matrix.fromArray(p.matrix);
      inst.name = p.name + "@" + p.setup;
      inst.traverse((o) => { if (o.isMesh) { o.castShadow = true; o.frustumCulled = false; } });
      this.group.add(inst);
      this.drivers.push({ placement: p, driver: new RigDriver(inst, this.ts.human.clips) });
    }
    if (t.net) {
      const g = await get(t.net);
      if (g) {
        const inst = SkeletonUtils.clone(g.scene);
        // The net mesh is modelled along x (bounds x +-5.97 m, z +-0.025 m) while the court's net runs along z; the
        // placement that turns it is not in the exported hierarchy (OPEN), so the port applies the 90 degree yaw.
        inst.rotation.y = Math.PI / 2;
        inst.traverse((o) => { if (o.isMesh) o.frustumCulled = false; });
        this.group.add(inst);
        this.net = new RigDriver(inst, this.ts.net.clips);
      }
    }
    return this;
  }

  update(dt) {
    for (const d of this.drivers) d.driver.update(dt);
    if (this.net) this.net.update(dt);
  }
}
