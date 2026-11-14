// Player skeleton + animation clip playback.  The exported glTF has bones only (no mesh yet), so the rig is drawn as
// bone lines and joint points; when the assets agent's player meshes are exported they are loaded on top (see the
// roadmap in docs/port/web.md).  Clips are separate glTF files whose node names equal the skeleton's bone names, so
// an AnimationClip from any clip file drives the skeleton from skeletons/player_<n>.gltf.
import * as THREE from "three";
import { GLTFLoader } from "three/addons/loaders/GLTFLoader.js";

export class PlayerRig {
  constructor(color = 0xffd34d) {
    this.root = new THREE.Group();              // place/rotate this in the court
    this.root.name = "player";
    this.loader = new GLTFLoader();
    this.color = color;
    this.mixer = null;
    this.action = null;
    this.clip = null;
    this.speed = 1;
    this.playing = true;
    this.loop = true;
    this.bones = [];                            // {obj, parent}
    this.handle = null;                         // B_Racket_Handle object
    this.cache = new Map();
    this.skeletonScene = null;
    this.placeholder = null;
  }

  // A static mannequin used until a skeleton asset has been exported; clearly not animated.
  showPlaceholder() {
    const g = new THREE.Group();
    const m = new THREE.MeshStandardMaterial({ color: this.color, roughness: 0.8 });
    const body = new THREE.Mesh(new THREE.CapsuleGeometry(0.17, 0.85, 4, 12), m); body.position.y = 1.15; g.add(body);
    const head = new THREE.Mesh(new THREE.SphereGeometry(0.11, 16, 12), m); head.position.y = 1.75; g.add(head);
    for (const s of [-1, 1]) {
      const leg = new THREE.Mesh(new THREE.CapsuleGeometry(0.07, 0.7, 4, 8), m); leg.position.set(0, 0.45, s * 0.12); g.add(leg);
    }
    const racket = new THREE.Mesh(new THREE.TorusGeometry(0.15, 0.015, 8, 24), new THREE.MeshStandardMaterial({ color: 0x222222 }));
    racket.position.set(0.55, 1.1, 0.35); racket.rotation.y = Math.PI / 2; g.add(racket);
    g.name = "placeholder";
    this.placeholder = g;
    this.root.add(g);
  }

  async loadSkeleton(url) {
    const gltf = await this.loader.loadAsync(url);
    if (this.skeletonScene) this.root.remove(this.skeletonScene);
    if (this.placeholder) { this.root.remove(this.placeholder); this.placeholder = null; }
    const scene = gltf.scene;
    this.skeletonScene = scene;
    this.facing = new THREE.Group();            // yaw alignment node: the rig's forward axis is detected, then pointed at +x
    this.facing.add(scene);
    this.root.add(this.facing);
    scene.updateMatrixWorld(true);
    this.bones = [];
    scene.traverse((o) => { if (o !== scene && o.name) this.bones.push({ obj: o, parent: o.parent && o.parent !== scene ? o.parent : null }); });
    this.handle = scene.getObjectByName("B_Racket_Handle") || null;
    // forward axis from foot -> toe in the reference pose
    const foot = scene.getObjectByName("B_LeftFoot"), toe = scene.getObjectByName("B_LeftToeBase");
    this.forwardYaw = 0;
    if (foot && toe) {
      const a = new THREE.Vector3(), b = new THREE.Vector3();
      foot.getWorldPosition(a); toe.getWorldPosition(b);
      this.forwardYaw = Math.atan2(-(b.z - a.z), b.x - a.x);
      this.facing.rotation.y = -this.forwardYaw;                      // rotate so that (toe - foot) points to +x
    }
    // drawing
    const lineGeo = new THREE.BufferGeometry();
    lineGeo.setAttribute("position", new THREE.BufferAttribute(new Float32Array(this.bones.length * 6), 3));
    this.lines = new THREE.LineSegments(lineGeo, new THREE.LineBasicMaterial({ color: this.color, depthTest: false }));
    this.lines.renderOrder = 2; this.lines.frustumCulled = false;
    const ptGeo = new THREE.BufferGeometry();
    ptGeo.setAttribute("position", new THREE.BufferAttribute(new Float32Array(this.bones.length * 3), 3));
    this.points = new THREE.Points(ptGeo, new THREE.PointsMaterial({ color: 0xffffff, size: 0.025, depthTest: false }));
    this.points.renderOrder = 3; this.points.frustumCulled = false;
    this.root.add(this.lines, this.points);
    if (!this.contactMarker) {
      this.contactMarker = new THREE.Mesh(new THREE.SphereGeometry(0.04, 12, 8), new THREE.MeshBasicMaterial({ color: 0xff3366, depthTest: false }));
      this.contactMarker.renderOrder = 4;
    }
    this.root.add(this.contactMarker);
    this.mixer = new THREE.AnimationMixer(scene);
    this.action = null;
    this.refreshBones();
    return { bones: this.bones.length };
  }

  refreshBones() {
    if (!this.lines) return;
    this.root.updateMatrixWorld(true);
    const lp = this.lines.geometry.attributes.position, pp = this.points.geometry.attributes.position;
    const v = new THREE.Vector3(), w = new THREE.Vector3();
    // vertices are in the rig's parent space (this.root): convert world positions into it
    const inv = new THREE.Matrix4().copy(this.root.matrixWorld).invert();
    this.bones.forEach((b, i) => {
      b.obj.getWorldPosition(v).applyMatrix4(inv);
      if (b.parent) b.parent.getWorldPosition(w).applyMatrix4(inv); else w.copy(v);
      lp.setXYZ(2 * i, v.x, v.y, v.z); lp.setXYZ(2 * i + 1, w.x, w.y, w.z);
      pp.setXYZ(i, v.x, v.y, v.z);
    });
    lp.needsUpdate = true; pp.needsUpdate = true;
    if (this.handle) { this.handle.getWorldPosition(v).applyMatrix4(inv); this.contactMarker.position.copy(v); }
  }

  async loadClip(url) {
    if (!this.mixer) throw new Error("no skeleton loaded");
    let clip = this.cache.get(url);
    if (!clip) {
      const gltf = await this.loader.loadAsync(url);
      clip = gltf.animations[0];
      if (!clip) throw new Error("clip file has no animation: " + url);
      this.cache.set(url, clip);
    }
    if (this.action) this.action.stop();
    this.clip = clip;
    this.action = this.mixer.clipAction(clip);
    this.action.setLoop(this.loop ? THREE.LoopRepeat : THREE.LoopOnce, Infinity);
    this.action.clampWhenFinished = true;
    this.action.play();
    this.action.paused = !this.playing;
    return clip;
  }

  setLoop(on) { this.loop = on; if (this.action) { this.action.setLoop(on ? THREE.LoopRepeat : THREE.LoopOnce, Infinity); } }
  setPlaying(on) { this.playing = on; if (this.action) this.action.paused = !on; }
  get duration() { return this.clip ? this.clip.duration : 0; }
  get time() { return this.action ? this.action.time : 0; }
  seek(t) {
    if (!this.action) return;
    this.action.time = Math.min(Math.max(t, 0), this.duration);
    this.mixer.update(0);
    this.refreshBones();
  }

  update(dt) {
    if (this.mixer && this.action) {
      if (this.playing) {
        this.action.paused = false;
        this.mixer.update(dt * this.speed);
        if (!this.loop && this.action.time >= this.duration) this.playing = false;
      }
    }
    this.refreshBones();
  }
}
