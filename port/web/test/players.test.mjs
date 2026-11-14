// node port/web/test/players.test.mjs  -- pure player animation logic (synthetic data only)
import assert from "node:assert/strict";
import * as L from "../src/players/anim_logic.js";
import { makeMirror, worldOf, counterpart } from "../src/players/pose_mirror.js";
import { lodLevel, variantKey, pickVariant } from "../src/players/appearance_pure.js";

let n = 0;
const test = (name, f) => { f(); n++; };
const close = (a, b, e = 1e-5) => assert.ok(Math.abs(a - b) < e, a + " != " + b);

test("sector8", () => {
  assert.equal(L.sector8(0, 0, 1), L.SECTOR.FRONT);
  assert.equal(L.sector8(0, 1, 0), L.SECTOR.LEFT);                 // +x is left in the locomotion frame
  assert.equal(L.sector8(0, 0, -1), L.SECTOR.BACK);
  assert.equal(L.sector8(0, 0, -1, 1e-6, true), L.SECTOR.BACK_ALT);
  assert.equal(L.sector8(0, -1, 0), L.SECTOR.RIGHT);
  assert.equal(L.sector8(0, 0.01, 0.01, 1), L.SECTOR.STAND);
});
test("port frame -> locomotion frame", () => {
  // facing +x (heading 0), moving toward +z (the player's right) -> Right sector
  const yaw = L.viewHeadingToYaw(0); const [lx, lz] = L.viewDirToLo(0, 300);
  assert.equal(L.sector8(yaw, lx, lz), L.SECTOR.RIGHT);
  const [fx, fz] = L.viewDirToLo(300, 0);
  assert.equal(L.sector8(yaw, fx, fz), L.SECTOR.FRONT);
});
test("moveset pick fallbacks", () => {
  const ms = { sectors: Array.from({ length: 9 }, (_, i) => ({ group: "G", sub: "S" + i })) };
  assert.equal(L.movesetPick(ms, L.SECTOR.BACK_ALT).sub, "S4");
  assert.equal(L.movesetPick(ms, 42).sub, "S0");
});
test("clock", () => {
  close(L.playRate({ speed_coef: 0.9 }, { groupAllowsCoef: true, gameplayCoef: 1.15 }), 0.9 * 1.15);
  close(L.playRate({ speed_coef: 0.9, ignore_speed_coef: true }), 1);
  close(L.cyclePhase(1.05, 0.3, 1.0), 0.35);
  close(L.blendWeight(7.5, 15), 0.5);
  close(L.rotyOffset(5, 0, 10, 0, Math.PI / 4), Math.PI / 8);
  close(L.rateToTarget(40, 10, 20, 10, 0), 30 / 11);
});
test("swing time warp lands EventRacket on contact", () => {
  const clip = { frames: 121, ev: [["EventRacket", 0.4, 0, 0]] };
  close(L.swingClipTime({ clip, swingState: 1, swingT: 1 }), 0.4 * 2);
  close(L.swingClipTime({ clip, swingState: 1, swingT: 0.5 }), 0.2 * 2);
  close(L.swingClipTime({ clip, swingState: 2, recoveryFrac: 1 }), 2);
  assert.equal(L.swingClipTime({ clip: { frames: 10 }, swingState: 1, swingT: 1 }), null);
});
test("tables and swing matching", () => {
  const rules = {
    clips: [
      { i: 0, name: "Jog_Front", setup: "Men", group: 1, sub: 0, ev: [["Cycle_In", 0.3, 0, 0], ["Cycle_Out", 0.9, 0, 0]] },
      { i: 1, name: "Swing_FH_TopSpin_GoodControl", setup: "Men", group: 2, sub: 0, ev: [["EventRacket", 0.4, 0, 0]],
        q: { Category: ["Swing"], SwingType: ["FH"], SwingEffect: ["TopSpin"] } },
      { i: 2, name: "Swing_BH_Slice", setup: "Men", group: 2, sub: 0, ev: [["EventRacket", 0.4, 0, 0]], q: { Category: ["Swing"], SwingType: ["BH"] } },
    ],
    groups: [{ setup: "Men", index: 1, id: "Jog", subgroups: [{ id: "Front", first: 0, count: 1, abs: 0 }] }],
    movesets: [{ id: "Jog", sectors: [{ group: "Jog", sub: "Front" }] }],
  };
  const t = new L.AnimTables(rules);
  assert.deepEqual(t.sectorClips("Men", { group: "Jog", sub: "Front" }).map((c) => c.i), [0]);
  assert.deepEqual(L.cycleWindow(rules.clips[0]), [0.3, 0.9]);
  assert.ok(L.swingMatches(rules.clips[1], L.SWING_KEYS.fh_topspin));
  assert.ok(!L.swingMatches(rules.clips[2], L.SWING_KEYS.fh_topspin));
  assert.equal(L.chooseInSector(rules.clips, { prefer: ["GoodControl"] }).i, 1);
  assert.ok(L.mirrorFor({}, true) && !L.mirrorFor({ no_mirror: true }, true) && !L.mirrorFor({}, false));
  close(L.heightScale([[0, 2, "MinHeight", 178], [0, 2, "MaxHeight", 187], [0, 2, "f769c520", 1.0], [0, 3, "MinHeight", 187], [0, 3, "MaxHeight", 193], [0, 3, "f769c520", 1.04]], 0, 190), 1.04);
});
test("pose mirror", () => {
  // centre root, left / right arm along +-z; the plane normal is measured from the up-legs
  const names = ["B_Hips", "B_LeftUpLeg", "B_RightUpLeg", "B_LeftArm", "B_RightArm"];
  const parents = [-1, 0, 0, 0, 0];
  const I = [0, 0, 0, 1], one = [1, 1, 1];
  const rest = [{ t: [0, 1, 0], q: I, s: one }, { t: [0, 0, 0.1], q: I, s: one }, { t: [0, 0, -0.1], q: I, s: one },
                { t: [0, 0.5, 0.2], q: I, s: one }, { t: [0, 0.5, -0.2], q: I, s: one }];
  const m = makeMirror(names, parents, rest);
  assert.deepEqual(m.normal.map((v) => Math.round(v)), [0, 0, 1]);
  assert.equal(counterpart("B_LeftHand"), "B_RightHand");
  // rest pose mirrors onto itself
  const r = m.pose(rest);
  r.forEach((p, i) => { p.t.forEach((v, k) => close(v, rest[i].t[k])); close(Math.abs(p.q[3]), 1); });
  // raise the right arm (local translation up) -> mirrored pose raises the left arm
  const pose = rest.map((p) => ({ ...p }));
  pose[4] = { t: [0, 0.8, -0.2], q: I, s: one };
  const mp = m.pose(pose);
  close(mp[3].t[1], 0.8); close(mp[3].t[2], 0.2); close(mp[4].t[1], 0.5);
  // a yaw of the root turns the other way
  const s = Math.sin(0.25), c = Math.cos(0.25);
  pose[0] = { t: [0.3, 1, 0.2], q: [0, s, 0, c], s: one };
  const w = worldOf(m.pose(pose), parents);
  close(w[0][12], 0.3); close(w[0][14], -0.2);
  close(m.pose(pose)[0].q[1], -s);
});
test("appearance helpers", () => {
  assert.equal(lodLevel(500, [1000, 1500]), 0);
  assert.equal(lodLevel(1200, [1000, 1500]), 1);
  assert.equal(lodLevel(2000, [0, 0]), 2);
  assert.equal(variantKey(2, "clay"), "sweat2_clay");
  assert.equal(pickVariant({ sweat1: "a", sweat2_clay: "b" }, 3, "clay"), "b");
  assert.equal(pickVariant({ sweat1: "a" }, 2, "grass"), "a");
  assert.equal(pickVariant(null, 1, "hard"), null);
});
console.log("players.test.mjs: " + n + " tests passed");
import { crc32, decodeAnimView, viewToState } from "../src/players/core_anim.js";
{
  assert.equal(crc32("RightHanded").toString(16), "c4a7567b");
  const dv = new DataView(new ArrayBuffer(64));
  dv.setUint32(0, 64, true); dv.setUint32(4, 2, true); dv.setInt32(8, 7, true); dv.setUint32(12, crc32("Swing_X"), true);
  dv.setFloat32(16, 30, true); dv.setInt32(24, -1, true); dv.setFloat32(36, 1, true); dv.setUint32(48, 1, true);
  const v = decodeAnimView(dv);
  const st = viewToState(v, new Map([[crc32("Swing_X"), 99]]));
  assert.deepEqual([st.record, st.time, st.mirrored, st.layer, st.prevRecord], [99, 0.5, true, "swing", null]);
  console.log("players.test.mjs: core_anim ok");
}
