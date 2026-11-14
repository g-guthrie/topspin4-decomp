// Ball trajectory view: draws a trace returned by core.trace() (cm, 3 per tick at 60 Hz) and plays the ball along it.
import * as THREE from "three";

export class BallView {
  constructor(radiusCm = 4) {
    this.group = new THREE.Group();
    this.group.name = "ballView";
    this.ball = new THREE.Mesh(new THREE.SphereGeometry(radiusCm * 0.01, 20, 14), new THREE.MeshStandardMaterial({ color: 0xd8f03c, roughness: 0.7 }));
    this.ball.castShadow = true;
    this.shadow = new THREE.Mesh(new THREE.CircleGeometry(radiusCm * 0.01, 16), new THREE.MeshBasicMaterial({ color: 0x000000, transparent: true, opacity: 0.35 }));
    this.shadow.rotation.x = -Math.PI / 2;
    this.shadow.position.y = 0.004;
    this.line = null;
    this.markers = new THREE.Group();
    this.group.add(this.ball, this.shadow, this.markers);
    this.points = null;
    this.tick = 0;
    this.accum = 0;
    this.playing = false;
    this.rate = 1;
    this.ball.visible = false; this.shadow.visible = false;
  }

  setTrajectory(points, events, color = 0xff8a3d) {
    if (this.line) { this.group.remove(this.line); this.line.geometry.dispose(); }
    this.points = points;
    const m = new Float32Array(points.length);
    for (let i = 0; i < points.length; i++) m[i] = points[i] * 0.01;     // cm -> m
    const g = new THREE.BufferGeometry();
    g.setAttribute("position", new THREE.BufferAttribute(m, 3));
    this.line = new THREE.Line(g, new THREE.LineBasicMaterial({ color }));
    this.group.add(this.line);
    this.markers.clear();
    for (const e of events || []) {
      const ring = new THREE.Mesh(new THREE.RingGeometry(0.08, 0.12, 24), new THREE.MeshBasicMaterial({ color: e.type === "net" ? 0xff3366 : 0xffffff, side: THREE.DoubleSide }));
      ring.rotation.x = -Math.PI / 2;
      ring.position.set(e.pos[0] * 0.01, 0.01, e.pos[2] * 0.01);
      if (e.type === "net") { ring.rotation.set(0, Math.PI / 2, 0); ring.position.y = e.pos[1] * 0.01; }
      this.markers.add(ring);
    }
    this.tick = 0; this.accum = 0; this.playing = true;
    this.ball.visible = this.shadow.visible = true;
    this._place(0);
  }

  _place(i) {
    if (!this.points) return;
    const n = this.points.length / 3;
    i = Math.min(Math.max(i, 0), n - 1);
    const x = this.points[3 * i] * 0.01, y = this.points[3 * i + 1] * 0.01, z = this.points[3 * i + 2] * 0.01;
    this.ball.position.set(x, y, z);
    this.shadow.position.set(x, 0.004, z);
  }

  get length() { return this.points ? this.points.length / 3 : 0; }

  update(dt) {
    if (!this.points || !this.playing) return;
    this.accum += dt * this.rate * 60;
    const n = this.length;
    this.tick = Math.min(this.tick + Math.floor(this.accum), n - 1);
    this.accum -= Math.floor(this.accum);
    this._place(this.tick);
    if (this.tick >= n - 1) this.playing = false;
  }
}
