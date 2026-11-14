// node --test port/web/test/helpers.test.mjs   (run by tests/test_port_web.py; pure helpers only, no browser)
import test from 'node:test';
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import {
  FixedStepper, lerpAngle, lerpOrSnap, damp, interpolateSnapshot, locomotionClass, locomotionRate, isForehand, swingClassForRow,
  swingFallbacks, clipIndexOf, contactSeconds, recordClip, pickSwingClip, swingClipTime, effectiveSwingScale, serveChargeTime,
  cameraGoal, scoreRows, pointText, describeEvent, phaseHint, parseTunablesDef, parseRolesDef, groupTunables, parseNumber,
  diffOverrides, firstBounce, netCrossing, summariseProbe, probeDelta, matchConfigFrom, guessSwingClass, mirrorTrackValues,
} from '../src/helpers.js';

const near = (a, b, e = 1e-6) => assert.ok(Math.abs(a - b) <= e, a + ' vs ' + b);

test('fixed stepper: whole ticks, alpha, backlog cap', () => {
  const s = new FixedStepper(60, 4);
  assert.equal(s.advance(1 / 60 + 1e-4), 1);
  near(s.alpha, 0.006, 0.01);
  assert.equal(s.advance(0.5 / 60), 0);
  near(s.alpha, 0.5 + 0.006, 0.02);
  let total = 0; for (let i = 0; i < 60; i++) total += s.advance(1 / 60);
  assert.ok(total >= 59 && total <= 61);
  assert.equal(s.advance(0.5), 4);           // 30 ticks asked, capped
  assert.equal(s.dropped, 26);
});

test('angles take the short way round', () => {
  near(lerpAngle(3.0, -3.0, 0.5), Math.PI, 0.2);
  near(lerpAngle(0, 1, 0.25), 0.25);
  near(lerpAngle(-3.1, 3.1, 0.5), -Math.PI, 0.05 + 0.0);
});

test('lerpOrSnap snaps teleports', () => {
  assert.deepEqual(lerpOrSnap([0, 0, 0], [10, 0, 0], 0.5, 150), [5, 0, 0]);
  assert.deepEqual(lerpOrSnap([0, 0, 0], [1000, 0, 0], 0.5, 150), [1000, 0, 0]);
  near(damp(0, 10, 3, 0), 0); near(damp(0, 10, 1000, 1), 10, 1e-3);
});

const snap = (tick, x, phase = 'rally', swing = 0, st = 0) => ({
  tick, phase, ball: { pos: [x, 0, 0], live: true },
  players: [{ pos: [x, 0, 0], heading: 0, swingState: st, swingT: swing }, { pos: [-x, 0, 0], heading: 3, swingState: 0, swingT: 0 }],
});
test('interpolateSnapshot blends, snaps on phase reset, keeps discrete fields', () => {
  const a = snap(1, 0), b = snap(2, 10);
  const m = interpolateSnapshot(a, b, 0.5);
  assert.equal(m.players[0].pos[0], 5); assert.equal(m.ball.pos[0], 5); assert.equal(m.tickF, 1.5);
  assert.equal(interpolateSnapshot(null, b, 0.5), b);
  const c = snap(3, 800, 'serve');
  assert.equal(interpolateSnapshot(b, c, 0.5).players[0].pos[0], 800);
  const sw = interpolateSnapshot(snap(1, 0, 'rally', 0.2, 1), snap(2, 0, 'rally', 0.4, 1), 0.5);
  near(sw.players[0].swingT, 0.3);
});

test('locomotion classes follow the speed tunables', () => {
  const tun = { walk: 220, jog: 480, rush: 700 };
  assert.equal(locomotionClass(0, tun), 'idle');
  assert.equal(locomotionClass(220, tun), 'jog');
  assert.equal(locomotionClass(480, tun), 'run');
  assert.equal(locomotionClass(700, tun), 'rush');
  assert.equal(locomotionClass(480, { walk: 220, jog: 900, rush: 1000 }), 'jog');
  assert.equal(locomotionRate(240, 480), 0.6);
  assert.equal(locomotionRate(480, 480), 1); assert.equal(locomotionRate(100, 0), 1);
});

test('forehand side and swing class of rows', () => {
  assert.ok(isForehand([-1200, 0, 0], [-1200, 100, 100]));        // x < 0 faces +x, right is +z
  assert.ok(!isForehand([-1200, 0, 0], [-1200, 100, -100]));
  assert.ok(isForehand([1200, 0, 0], [1200, 100, -100]));          // other end: right is -z
  assert.ok(!isForehand([-1200, 0, 0], [-1200, 100, 100], true));  // left-handed
  assert.equal(swingClassForRow(0, true), 'fh_topspin'); assert.equal(swingClassForRow(5, false), 'bh_slice');
  assert.equal(swingClassForRow(6, true), 'fh_flat'); assert.equal(swingClassForRow(7, true), 'lob');
  assert.equal(swingClassForRow(16, false), 'volley_bh'); assert.equal(swingClassForRow(18, true), 'drop');
  assert.equal(swingClassForRow(26, true), 'serve'); assert.equal(swingClassForRow(33, true), 'smash');
  assert.deepEqual(swingFallbacks('fh_flat'), ['fh_flat', 'fh', 'default']);
  assert.deepEqual(swingFallbacks('volley_bh'), ['volley_bh', 'bh', 'default']);
  assert.deepEqual(swingFallbacks('serve'), ['serve', 'default']);
});

test('swing class guess from buttons and ball zone', () => {
  const tun = { volleyXMax: 400, splitVolley: 180, splitOther: 180, smashLoV: 180, smashHiV: 400, smashLoO: 180, smashHiO: 400 };
  const base = { playerPos: [-1200, 0, 0], tun };
  assert.equal(guessSwingClass({ ...base, buttons: 2, ballPos: [-1000, 100, 50] }), 'fh_topspin');
  assert.equal(guessSwingClass({ ...base, buttons: 4 | 16, ballPos: [-1000, 100, -50] }), 'drop');
  assert.equal(guessSwingClass({ ...base, buttons: 8, ballPos: [-1000, 100, -50] }), 'lob');
  assert.equal(guessSwingClass({ ...base, buttons: 1, ballPos: [-200, 100, -50] }), 'volley_bh');
  assert.equal(guessSwingClass({ ...base, buttons: 1, ballPos: [-200, 250, 50] }), 'smash');
  assert.equal(guessSwingClass({ ...base, buttons: null, ballPos: [-1000, 100, 50] }), 'fh_topspin');
});

test('clip references, contact time and record lookup', () => {
  assert.equal(clipIndexOf('core:12'), 12); assert.equal(clipIndexOf(7), 7); assert.equal(clipIndexOf('x'), null); assert.equal(clipIndexOf(null), null);
  near(contactSeconds(0.4, 2), 0.8); near(contactSeconds(30, 2), 0.5); assert.equal(contactSeconds(null, 2), null);
  const r = { name: 'N', id: 'abcd0123', index: 5, clip: null };
  assert.equal(recordClip({ ...r, clip: 'core:3' }, null), 3);
  assert.equal(recordClip(r, { N: 'core:9' }), 9);
  assert.equal(recordClip(r, { abcd0123: { clip: 'core:8' } }), 8);
  assert.equal(recordClip(r, { '#5': 'core:7' }), 7);
  assert.equal(recordClip(r, {}), null);
  // tools/port/clip_map.py layout: nested map, blends through records[].primary, other kinds never
  const cm = { map: { '#5': 'core:11' }, records: [{ index: 6, poly: 'blend', primary: 'core:12' }, { index: 7, poly: 'single', primary: 'core:13' }] };
  assert.equal(recordClip({ index: 5, name: 'a' }, cm), 11); assert.equal(recordClip({ index: 6, name: 'b' }, cm), 12); assert.equal(recordClip({ index: 7, name: 'c' }, cm), null);
});

test('pickSwingClip: record mapping wins, config placeholder otherwise', () => {
  const clips = new Map([[1, { duration: 2, file: 'a' }], [2, { duration: 1, file: 'b' }], [3, { duration: 1, file: null }]]);
  const cfg = { placeholder: true, defaultContactPhase: 0.4, swing: { default: { clip: 'core:2' }, fh: { clip: 'core:1', contactSeconds: 0.7 } },
                recordTags: { fh_flat: { all: ['Swing', 'FH', 'Flat'], none: ['Return'] } } };
  let p = pickSwingClip('fh_flat', cfg, { clips });
  assert.deepEqual([p.clip, p.contact, p.placeholder, p.source], [1, 0.7, true, 'config:fh']);
  p = pickSwingClip('bh_flat', cfg, { clips });
  assert.deepEqual([p.clip, p.source], [2, 'config:default']); near(p.contact, 0.4);
  const records = [{ name: 'a', tags: ['Swing', 'FH', 'Flat', 'Return'], clip: 'core:2', contact: 0.5 },
                   { name: 'b', tags: ['Swing', 'FH', 'Flat'], clip: 'core:3', contact: 0.5 },     // clip not exported
                   { name: 'c', tags: ['Swing', 'FH', 'Flat'], clip: 'core:1', contact: 0.25 }];
  p = pickSwingClip('fh_flat', cfg, { clips, records });
  assert.deepEqual([p.clip, p.source, p.placeholder, p.label], [1, 'record', false, 'c']); near(p.contact, 0.5);
  assert.equal(pickSwingClip('x', { swing: {} }, { clips }), null);
});

test('swing clip time lands on contact at swing_t = 1', () => {
  const a = { contact: 0.6, duration: 1.5 };
  assert.equal(swingClipTime({ ...a, swingState: 0, swingT: 0 }), null);
  near(swingClipTime({ ...a, swingState: 1, swingT: 0 }), 0);
  near(swingClipTime({ ...a, swingState: 1, swingT: 1 }), 0.6);
  near(swingClipTime({ ...a, swingState: 1, swingT: 0.5 }), 0.3);
  near(swingClipTime({ ...a, swingState: 2, swingT: 0, recoveryFrac: 0 }), 0.6);
  near(swingClipTime({ ...a, swingState: 2, swingT: 0, recoveryFrac: 1 }), 1.5);
  near(swingClipTime({ ...a, swingState: 2, swingT: 0, recoveryFrac: 7 }), 1.5);
  near(effectiveSwingScale(0.6, 18), 2); near(serveChargeTime(1, 1), 0.85); near(serveChargeTime(1, 5), 0.85);
});

test('mirror of Havok tracks for the skinned export', () => {
  assert.deepEqual([...mirrorTrackValues('position', [1, 2, 3, 4, 5, 6])], [1, 2, -3, 4, 5, -6]);
  assert.deepEqual([...mirrorTrackValues('quaternion', [1, 2, 3, 4])], [-1, -2, 3, 4]);
  assert.deepEqual([...mirrorTrackValues('quaternion', [0.5, 0.25, 0.125, 1, 0, 0, 0, 1])], [-0.5, -0.25, 0.125, 1, -0, -0, 0, 1]);
});

test('broadcast camera sits behind the human baseline', () => {
  const g = cameraGoal({ side: -1, player: [-1250, 0, 100], ball: [0, 100, 0] });
  assert.ok(g.pos[0] < -11.885 && g.pos[1] > 2);
  const h = cameraGoal({ side: 1, player: [1250, 0, 0], ball: [0, 100, 0] });
  assert.ok(h.pos[0] > 11.885);
});

test('scoreboard rows and event text', () => {
  const sc = { curSet: 1, server: 1, games: [[6, 2, 0, 0, 0], [4, 3, 0, 0, 0]], setsWon: [1, 0], display: [40, -1], tiebreak: 0 };
  const rows = scoreRows(sc);
  assert.deepEqual(rows[0].games, [6, 2]); assert.equal(rows[1].serving, true); assert.equal(rows[1].game, 'Ad'); assert.equal(rows[0].game, '40');
  assert.equal(pointText(7, 1), '7');
  assert.equal(describeEvent({ type: 'point_end', a: 0, b: 1 }), 'Point You (out)');
  assert.equal(describeEvent({ type: 'point_end', a: -1, b: 6 }), 'No point (let)');
  assert.equal(describeEvent({ type: 'match', a: 1 }), 'Match: CPU');
  assert.equal(describeEvent({ type: 'bounce' }), null);
  assert.match(phaseHint({ phase: 'serve', score: { server: 0, secondServe: 1 } }), /second serve/);
  assert.match(phaseHint({ phase: 'match_over', score: { server: 0, winner: 1 } }), /lose/);
});

test('registry text parsing', () => {
  const defs = parseTunablesDef('/* c */\nTS4_TUN(BALL_G, "ball.g", "m/s^2", GAME, R, "gravity; \\"x\\"")\nTS4_TUN(MOVE_X,"move.x","cm",PORT,O,"d")\nnoise');
  assert.equal(defs.length, 2);
  assert.deepEqual([defs[0].id, defs[0].name, defs[0].unit, defs[0].origin, defs[0].required], ['BALL_G', 'ball.g', 'm/s^2', 'GAME', true]);
  assert.equal(defs[1].required, false);
  const r = parseRolesDef('TS4_VAR(ZERO, "zero", "c")\nTS4_ROLE(A, "a", "G (0x1)", "when")');
  assert.equal(r.roles[0].graph, 'G (0x1)'); assert.equal(r.vars[0].name, 'zero');
  const g = groupTunables(defs); assert.deepEqual([...g.keys()], ['ball', 'move']);
  assert.equal(parseNumber(' 1.5 '), 1.5); assert.equal(parseNumber(''), null); assert.equal(parseNumber('abc'), null); assert.equal(parseNumber(Infinity), null);
  assert.deepEqual(diffOverrides({ a: 1, b: 2, c: null }, { a: 1, b: 3, c: 0 }), { b: 2 });
});

test('the shipped .def files parse completely', () => {
  const root = new URL('../../core/include/', import.meta.url);
  const text = readFileSync(new URL('ts4_tunables.def', root), 'utf8');
  const n = (text.match(/^\s*TS4_TUN\(/gm) || []).length;
  assert.ok(n > 50); assert.equal(parseTunablesDef(text).length, n);
  const roles = readFileSync(new URL('ts4_roles.def', root), 'utf8');
  const p = parseRolesDef(roles);
  assert.equal(p.roles.length, (roles.match(/^\s*TS4_ROLE\(/gm) || []).length);
  assert.equal(p.vars.length, (roles.match(/^\s*TS4_VAR\(/gm) || []).length);
});

test('probe summaries', () => {
  const pts = [[-1000, 100, 0], [-500, 120, 0], [-1, 90, 0], [1, 88, 0], [600, 4, 10], [900, 60, 20], [1200, 90, 30]];
  near(netCrossing(pts), 89, 0.1);
  const b = firstBounce(pts, 4); assert.equal(b.tick, 4);
  const s = summariseProbe({ tau: 1, bounceTick: 60, initialKmh: 100, arriveVel: [10, 0, 0], raised: false, netUnreachable: false }, pts);
  near(s.arriveKmh, 36); near(s.landX, 600); near(s.apexCm, 120);
  assert.deepEqual(probeDelta({ tau: 1, x: 2 }, { tau: 1.5, x: 1, y: 3 }), { tau: 0.5, x: -1 });
  assert.equal(firstBounce([[0, 50, 0], [10, 60, 0]]), null);
});

test('match config from the form', () => {
  const c = matchConfigFrom({ format: 'best3', firstServer: 1, stats0: 150, stats1: 20, seed: 9, left0: true, surface: 'clay' });
  assert.equal(c.numSets, 3); assert.equal(c.shortFormat, false); assert.equal(c.firstServer, 1); assert.equal(c.surface, 1);
  assert.deepEqual([c.players[0].human, c.players[1].human, c.players[0].stats[0], c.players[1].stats[7], c.players[0].leftHanded], [true, false, 100, 20, true]);
  assert.equal(matchConfigFrom({ format: 'short' }).shortFormat, true);
});
