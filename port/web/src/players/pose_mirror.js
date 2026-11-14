// Left-handed playback: mirror a right-handed pose onto the same skeleton (the game plays its right-handed clips
// mirrored for left-handers; docs/gameplay/movement-and-animation.md s4.4, V for "mirrored", I for the method).
// Pure math, no three.js; unit-tested in test/players.test.mjs.
//
// Method: reflect each bone's world transform across the body's sagittal plane, take it from the opposite-side
// bone (Left <-> Right by name), and re-attach it to this bone's rest frame:
//     W'_b = R * W_c * R * C_b,   C_b = (R * Rest_c * R)^-1 * Rest_b,   R = I - 2 n n^T
// where c is b's counterpart (b itself for centre bones) and n the plane normal measured from the rest pose (left
// minus right upper leg).  R W R is a proper rotation, so the result is a valid pose and the mesh is NOT mirrored:
// shirt logos and hair partings stay where they are; the racket bone follows the mirrored hand (see mirrorRacket).

export const counterpart = (name) =>
  name.includes("Left") ? name.replace("Left", "Right") : name.includes("Right") ? name.replace("Right", "Left") : name;

// ---- 4x4 column-major matrices (three.js layout)
export function compose(t, q, s = [1, 1, 1]) {
  const [x, y, z, w] = q, x2 = x + x, y2 = y + y, z2 = z + z;
  const xx = x * x2, xy = x * y2, xz = x * z2, yy = y * y2, yz = y * z2, zz = z * z2, wx = w * x2, wy = w * y2, wz = w * z2;
  return [(1 - (yy + zz)) * s[0], (xy + wz) * s[0], (xz - wy) * s[0], 0,
          (xy - wz) * s[1], (1 - (xx + zz)) * s[1], (yz + wx) * s[1], 0,
          (xz + wy) * s[2], (yz - wx) * s[2], (1 - (xx + yy)) * s[2], 0,
          t[0], t[1], t[2], 1];
}
export function mul(a, b) {
  const o = new Array(16);
  for (let c = 0; c < 4; c++) for (let r = 0; r < 4; r++) {
    let v = 0;
    for (let k = 0; k < 4; k++) v += a[k * 4 + r] * b[c * 4 + k];
    o[c * 4 + r] = v;
  }
  return o;
}
export function invAffine(m) {
  const a = m[0], b = m[1], c = m[2], d = m[4], e = m[5], f = m[6], g = m[8], h = m[9], i = m[10];
  const det = a * (e * i - f * h) - d * (b * i - c * h) + g * (b * f - c * e);
  const id = 1 / det;
  const r = [(e * i - f * h) * id, (c * h - b * i) * id, (b * f - c * e) * id, 0,
             (f * g - d * i) * id, (a * i - c * g) * id, (c * d - a * f) * id, 0,
             (d * h - e * g) * id, (b * g - a * h) * id, (a * e - b * d) * id, 0, 0, 0, 0, 1];
  const t = [m[12], m[13], m[14]];
  r[12] = -(r[0] * t[0] + r[4] * t[1] + r[8] * t[2]);
  r[13] = -(r[1] * t[0] + r[5] * t[1] + r[9] * t[2]);
  r[14] = -(r[2] * t[0] + r[6] * t[1] + r[10] * t[2]);
  return r;
}
export function decompose(m) {
  const sx = Math.hypot(m[0], m[1], m[2]), sy = Math.hypot(m[4], m[5], m[6]), sz = Math.hypot(m[8], m[9], m[10]);
  const r00 = m[0] / sx, r10 = m[1] / sx, r20 = m[2] / sx, r01 = m[4] / sy, r11 = m[5] / sy, r21 = m[6] / sy, r02 = m[8] / sz, r12 = m[9] / sz, r22 = m[10] / sz;
  const tr = r00 + r11 + r22;
  let q;
  if (tr > 0) { const s = 0.5 / Math.sqrt(tr + 1); q = [(r21 - r12) * s, (r02 - r20) * s, (r10 - r01) * s, 0.25 / s]; }
  else if (r00 > r11 && r00 > r22) { const s = 2 * Math.sqrt(1 + r00 - r11 - r22); q = [0.25 * s, (r01 + r10) / s, (r02 + r20) / s, (r21 - r12) / s]; }
  else if (r11 > r22) { const s = 2 * Math.sqrt(1 + r11 - r00 - r22); q = [(r01 + r10) / s, 0.25 * s, (r12 + r21) / s, (r02 - r20) / s]; }
  else { const s = 2 * Math.sqrt(1 + r22 - r00 - r11); q = [(r02 + r20) / s, (r12 + r21) / s, 0.25 * s, (r10 - r01) / s]; }
  const n = Math.hypot(...q);
  return { t: [m[12], m[13], m[14]], q: q.map((v) => v / n), s: [sx, sy, sz] };
}
export function reflection(n) {
  const [x, y, z] = n;
  return [1 - 2 * x * x, -2 * x * y, -2 * x * z, 0, -2 * x * y, 1 - 2 * y * y, -2 * y * z, 0, -2 * x * z, -2 * y * z, 1 - 2 * z * z, 0, 0, 0, 0, 1];
}

/** world matrices from local {t, q, s} per bone (parents[i] < i or -1) */
export function worldOf(locals, parents) {
  const w = new Array(locals.length);
  for (let i = 0; i < locals.length; i++) {
    const l = compose(locals[i].t, locals[i].q, locals[i].s);
    w[i] = parents[i] < 0 ? l : mul(w[parents[i]], l);
  }
  return w;
}

/**
 * Build a mirror for one skeleton.  names / parents / rest (local {t,q,s}) describe the bind skeleton; parents must
 * precede children.  `normal` (optional) overrides the plane normal.
 */
export function makeMirror(names, parents, rest, normal = null) {
  const idx = new Map(names.map((n, i) => [n, i]));
  const restW = worldOf(rest, parents);
  let n = normal;
  if (!n) {
    const L = idx.get("B_LeftUpLeg"), Rr = idx.get("B_RightUpLeg");
    const a = restW[L], b = restW[Rr];
    n = [a[12] - b[12], a[13] - b[13], a[14] - b[14]];
    n[1] = 0;                                              // keep the plane vertical (PORT)
    const l = Math.hypot(...n) || 1; n = n.map((v) => v / l);
  }
  const R = reflection(n);
  const cp = names.map((nm) => idx.get(counterpart(nm)) ?? idx.get(nm));
  const corr = names.map((_, b) => mul(invAffine(mul(mul(R, restW[cp[b]]), R)), restW[b]));
  /** mirror one pose: locals[i] = {t, q, s}; returns new locals */
  function pose(locals) {
    const w = worldOf(locals, parents);
    const w2 = names.map((_, b) => mul(mul(mul(R, w[cp[b]]), R), corr[b]));
    return names.map((_, b) => decompose(parents[b] < 0 ? w2[b] : mul(invAffine(w2[parents[b]]), w2[b])));
  }
  return { normal: n, counterparts: cp, pose };
}
