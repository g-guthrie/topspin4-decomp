// Procedural tennis court.  Real-world dimensions (ITF), in metres, in the game's world frame:
// x along the court (the net plane is x = 0), y up, z across.  Until venue meshes are exported this is the scene.
// The game's own court constants (docs/gameplay/gp1.md section 5: doubles half width 549 cm, singles 412 cm)
// agree with these to the centimetre.
import * as THREE from "three";

export const COURT = {
  halfLength: 11.885,        // baseline at x = +-11.885 (23.77 m long)
  doublesHalfWidth: 5.485,   // 10.97 m
  singlesHalfWidth: 4.115,   // 8.23 m
  serviceLine: 6.40,         // from the net
  netHeightCentre: 0.914,
  netHeightPosts: 1.07,
  postOffset: 0.914,         // posts stand this far outside the doubles sideline
  runoffBack: 6.4,
  runoffSide: 3.66,
  lineWidth: 0.05,
};

export function buildCourt(surface = "hard") {
  const g = new THREE.Group();
  g.name = "court";
  const C = COURT;
  const colours = {
    hard: { inside: 0x2e6aa6, outside: 0x3b7a52 },
    clay: { inside: 0xb5532b, outside: 0xa24a26 },
    grass: { inside: 0x4f8a3a, outside: 0x467b33 },
  }[surface] || { inside: 0x2e6aa6, outside: 0x3b7a52 };
  const mat = (c, rough = 0.9) => new THREE.MeshStandardMaterial({ color: c, roughness: rough });

  const outW = (C.doublesHalfWidth + C.runoffSide) * 2, outL = (C.halfLength + C.runoffBack) * 2;
  const out = new THREE.Mesh(new THREE.PlaneGeometry(outL, outW), mat(colours.outside));
  out.rotation.x = -Math.PI / 2; out.position.y = -0.002; out.receiveShadow = true; g.add(out);
  const inn = new THREE.Mesh(new THREE.PlaneGeometry(C.halfLength * 2, C.doublesHalfWidth * 2), mat(colours.inside));
  inn.rotation.x = -Math.PI / 2; inn.position.y = -0.001; inn.receiveShadow = true; inn.name = "courtSurface"; g.add(inn);

  const white = new THREE.MeshBasicMaterial({ color: 0xffffff });
  const strip = (x0, z0, x1, z1) => {          // a line of width lineWidth between two ground points
    const dx = x1 - x0, dz = z1 - z0, len = Math.hypot(dx, dz);
    const m = new THREE.Mesh(new THREE.PlaneGeometry(len, C.lineWidth), white);
    m.rotation.x = -Math.PI / 2;
    m.rotation.z = -Math.atan2(dz, dx);      // Euler XYZ: Rz acts in the plane before the tilt, which maps local y to -z
    m.position.set((x0 + x1) / 2, 0.003, (z0 + z1) / 2);
    g.add(m);
  };
  const L = C.halfLength, D = C.doublesHalfWidth, S = C.singlesHalfWidth, SV = C.serviceLine;
  strip(-L, -D, -L, D); strip(L, -D, L, D);                     // baselines
  strip(-L, -D, L, -D); strip(-L, D, L, D);                     // doubles sidelines
  strip(-L, -S, L, -S); strip(-L, S, L, S);                     // singles sidelines
  strip(-SV, -S, -SV, S); strip(SV, -S, SV, S);                 // service lines
  strip(-SV, 0, SV, 0);                                         // centre service line
  strip(-L, 0, -L + 0.1, 0); strip(L - 0.1, 0, L, 0);           // centre marks

  // net: posts, mesh (plane with transparency), top tape sagging to the centre strap height
  const netGroup = new THREE.Group(); netGroup.name = "net";
  const postMat = mat(0x222222, 0.6);
  for (const sgn of [-1, 1]) {
    const post = new THREE.Mesh(new THREE.CylinderGeometry(0.05, 0.05, C.netHeightPosts, 12), postMat);
    post.position.set(0, C.netHeightPosts / 2, sgn * (D + C.postOffset)); post.castShadow = true; netGroup.add(post);
  }
  const span = (D + C.postOffset) * 2, seg = 24, pts = [];
  for (let i = 0; i <= seg; i++) {
    const u = i / seg, z = -span / 2 + u * span;
    const h = C.netHeightCentre + (C.netHeightPosts - C.netHeightCentre) * Math.pow(Math.abs(z) / (span / 2), 2);
    pts.push([z, h]);
  }
  const verts = [], idx = [];
  pts.forEach(([z, h], i) => { verts.push(0, 0, z, 0, h, z); if (i) { const a = 2 * (i - 1); idx.push(a, a + 2, a + 1, a + 1, a + 2, a + 3); } });
  const netGeo = new THREE.BufferGeometry();
  netGeo.setAttribute("position", new THREE.Float32BufferAttribute(verts, 3));
  netGeo.setIndex(idx);
  const net = new THREE.Mesh(netGeo, new THREE.MeshBasicMaterial({ color: 0x111111, transparent: true, opacity: 0.35, side: THREE.DoubleSide, wireframe: false }));
  netGroup.add(net);
  const tape = new THREE.Line(new THREE.BufferGeometry().setFromPoints(pts.map(([z, h]) => new THREE.Vector3(0, h, z))),
    new THREE.LineBasicMaterial({ color: 0xffffff }));
  netGroup.add(tape);
  g.add(netGroup);
  return g;
}
