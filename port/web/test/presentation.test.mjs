// node --test port/web/test/presentation.test.mjs   (run by tests/test_port_audio.py; pure logic only, no browser)
// TV camera (camera_tv.js) and sound-event classification / direction (audio.js).
import test from 'node:test';
import assert from 'node:assert/strict';
import {
  TV_FALLBACK, TvCamera, shotName, mirrorShot, nearFar, clampAt, shotFov, tvGoal, smooth,
} from '../src/camera_tv.js';
import {
  shotFamily, powerWord, shotEvent, bounceEvent, netEvent, applauseEvent, applauseLevel, umpireCall, AudioDirector,
  pickWave, layerGain, SPEED_UNIT,
} from '../src/audio.js';

const close = (a, b, eps = 1e-6) => assert.ok(Math.abs(a - b) < eps, a + ' != ' + b);

test('shot names follow fn_888F03B0', () => {
  assert.equal(shotName(), 'CameraInGameWidescreenLeftSinglesTV');
  assert.equal(shotName({ widescreen: false, side: 1, doubles: true, option: 'TVZoom' }), 'CameraInGameNormalRightDoublesTVZoom');
});

test('near/far: near is the player at the camera end; doubles average each end', () => {
  const { near, far } = nearFar([[1100, 0, 50], [-1150, 0, -30]], -1);
  assert.deepEqual(near, [-1150, 0, -30]);
  assert.deepEqual(far, [1100, 0, 50]);
  const d = nearFar([[-1000, 0, 100], [-800, 0, -100], [900, 0, 0], [1100, 0, 200]], -1);
  assert.deepEqual(d.near, [-900, 0, 0]);
  assert.deepEqual(d.far, [1000, 0, 100]);
});

test('AtLimit clamp is max then min (Min > Max pins to Max)', () => {
  assert.deepEqual(clampAt([-500, 0, 350], TV_FALLBACK.at_limit), [-300, 0, 200]);
  assert.deepEqual(clampAt([100, 0, -50], TV_FALLBACK.at_limit), [-300, 0, -50]);
  assert.deepEqual(clampAt([250, 5, 0], { use: 1, min: [200, 0, -200], max: [300, 0, 200] }), [250, 0, 0]);
  assert.deepEqual(clampAt([9, 9, 9], { use: 0, min: [0, 0, 0], max: [1, 1, 1] }), [9, 9, 9]);
});

test('fov widens past FarLimit, then SideLimit, without clamping', () => {
  const s = TV_FALLBACK;
  close(shotFov(s, [-1200, 0, 0]), s.fov[0]);
  close(shotFov(s, [-1600, 0, 0]), s.fov[0] + 0.5 * (s.fov_max[0] - s.fov[0]));
  close(shotFov(s, [-1900, 0, 0]), s.fov[0] + 2 * (s.fov_max[0] - s.fov[0]));
  close(shotFov(s, [-1000, 0, 1750]), s.fov[0] + 0.5 * (s.fov_max[0] - s.fov[0]));
  close(shotFov({ ...s, loop: 1 }, [-1000, 0, 0]), s.fov[1]);
});

test('tvGoal: at = near + (far - near) * PositionPercent, clamped', () => {
  const g = tvGoal(TV_FALLBACK, [[-1100, 0, 100], [1100, 0, -300]], -1);
  // x: -1100 + 2200*0.3 = -440 -> max(-440,-200) = -200 -> min(-200,-300) = -300 ; z: 100 - 400*0.3 = -20
  assert.deepEqual(g.at.map((v) => Math.round(v)), [-300, 0, -20]);
  assert.deepEqual(g.from, [-3300, 900, 0]);
  close(Math.tan(g.fovV / 2) / Math.tan(g.fov / 2), 0.75);
});

test('mirror and smoothing', () => {
  const m = mirrorShot(TV_FALLBACK);
  assert.deepEqual(m.from, [3300, 900, -0]);
  assert.deepEqual(m.at_limit.min.slice(0, 1), [300]);
  assert.deepEqual(m.at_limit.max.slice(0, 1), [200]);
  close(smooth(0, 1, 0.1, 0.1), 1 - Math.exp(-1));
  assert.equal(smooth(0, 1, 0, 0.1), 1);
  assert.deepEqual(smooth([0, 0], [2, 4], -1, 0.1), [2, 4]);
});

test('TvCamera uses exported records, falls back and mirrors', () => {
  const cam = new TvCamera();
  const a = cam.update(1 / 60, [[-1100, 0, 0], [1100, 0, 0]], -1);
  assert.equal(a.fallback, true);
  assert.deepEqual(a.pos, [-33, 9, 0]);
  const b = cam.update(1 / 60, [[-1100, 0, 0], [1100, 0, 0]], 1);
  assert.ok(b.pos[0] > 0 && b.name.includes('mirrored'));
  const rec = { ...TV_FALLBACK, fallback: false, type: 'CShotSourceInGame', name: 'CameraInGameWidescreenRightSinglesTV', from: [3300, 933, 0] };
  const c = new TvCamera([rec]).update(1 / 60, [[-1100, 0, 0], [1100, 0, 0]], 1);
  assert.equal(c.name, 'CameraInGameWidescreenRightSinglesTV');
  assert.deepEqual(c.pos, [33, 9.33, 0]);
  assert.ok(c.fovDeg > 15 && c.fovDeg < 25);
});

test('shot event classification (fn_8888D700)', () => {
  assert.equal(shotFamily(0), 'TopSpin');
  assert.equal(shotFamily(1), 'Slice');
  assert.equal(shotFamily(2), 'Flat');
  assert.equal(shotFamily(3), 'TopSpin');           // lob folds into TopSpin
  assert.equal(shotFamily(33), 'Flat');             // smash folds into Flat
  assert.equal(shotFamily(32), 'Drop');
  assert.deepEqual([0.1, 0.3, 0.5, 0.7, 0.9].map((p) => powerWord(p, false)), ['Powerless', 'Weak', '', 'Strong', 'Powerfull']);
  assert.deepEqual([0.3, 0.5, 0.8].map((p) => powerWord(p, true)), ['', 'Strong', 'Powerfull']);
  assert.equal(shotEvent(2, 0.9, false), '/Root/Ball/Shot/FlatPowerfull');
  assert.equal(shotEvent(32, 0.9, false), '/Root/Ball/Shot/Drop');
});

test('bounce / net classification (fn_8888CFD0, fn_8888EBE8)', () => {
  const kmh = (v) => v / SPEED_UNIT.perCmS;
  assert.equal(bounceEvent([kmh(30), -kmh(5), 0]), '/Root/Ball/Bounce/SmallAngleVerySlowSpeed');
  assert.equal(bounceEvent([kmh(50), -kmh(30), 0]), '/Root/Ball/Bounce/LargeAngleMediumSpeed');
  assert.equal(bounceEvent([kmh(100), -kmh(40), 0]), '/Root/Ball/Bounce/MediumAngleFastSpeed');
  assert.equal(netEvent([kmh(20), 0, 0]), '/Root/Ball/Collision/Net_Slow');
  assert.equal(netEvent([kmh(30), 0, 0]), '/Root/Ball/Collision/Net_Fast');
});

test('applause and umpire wording', () => {
  assert.deepEqual([-1, 0, 1, 2, 3, 7].map(applauseEvent).map((p) => p.split('/').pop()),
    ['ApplauseLow', 'ApplauseLow', 'ApplauseAverage', 'ApplauseStrong', 'ApplauseWild', 'ApplauseWild']);
  assert.equal(applauseLevel(12, 1), 3);
  assert.equal(applauseLevel(1, 5), 0);
  const sc = (d, server = 0, extra = {}) => ({ display: d, server, curSet: 0, games: [[0], [0]], setsWon: [0, 0], ...extra });
  assert.deepEqual(umpireCall(sc([15, 0])), ['/Root/Umpire/RallyNormal/15-0']);
  assert.deepEqual(umpireCall(sc([15, 30], 1)), ['/Root/Umpire/RallyNormal/30-15']);
  assert.deepEqual(umpireCall(sc([40, 40])), ['/Root/Umpire/RallyNormal/Deuce']);
  assert.deepEqual(umpireCall(sc([40, -1])), ['/Root/Umpire/RallyNormal/Advantage', '/Root/Umpire/PlayerName/PlayerTwo/EndWith']);
  assert.deepEqual(umpireCall(sc([3, 3], 0, { tiebreak: 1 })), ['/Root/Umpire/TieBreakNormal/3All']);
  assert.deepEqual(umpireCall(sc([0, 0], 0, { games: [[3], [1]] }), { gameWon: 0 }),
    ['/Root/Umpire/GameNormal/Game', '/Root/Umpire/PlayerName/PlayerOne/EndWith', '/Root/Umpire/PlayerName/PlayerOne/BeginWith',
     '/Root/Umpire/GameNormal/Leads3GameTo1']);
  assert.deepEqual(umpireCall(sc([0, 0], 0, { games: [[2], [2]] }), { gameWon: 1 }).slice(-1), ['/Root/Umpire/GameNormal/2GameAll']);
  assert.deepEqual(umpireCall(sc([0, 0]), { matchWon: 1 }), ['/Root/Umpire/SetNormal/GameSetAndMatch', '/Root/Umpire/PlayerName/PlayerTwo/EndWith']);
});

test('director: rally sounds, delayed umpire call, footsteps', () => {
  const d = new AudioDirector();
  d.start();
  assert.ok(d.take().some((c) => c.path === '/Root/Ambience/BackNoise' && c.op === 'loop'));
  const snap = (vel, display = [0, 0]) => ({ ball: { vel }, score: { display, server: 0, curSet: 0, games: [[0], [0]], setsWon: [0, 0] } });
  d.onTick(null, snap([0, 0, 0]), [{ type: 'serve', a: 0 }]);
  d.onTick(snap([0, 0, 0]), snap([4500, 0, 0]), [{ type: 'hit', a: 0, b: 2, pos: [0, 100, 0] }]);
  let cmds = d.take();
  assert.ok(cmds.some((c) => c.path === '/Root/Ball/Shot/FlatPowerfull'));
  assert.ok(cmds.some((c) => c.path === '/Root/Grunt/Man/00/Shot'));
  d.onTick(snap([2000, -800, 0]), snap([1500, 500, 0]), [{ type: 'bounce', a: 1, b: 0, pos: [900, 0, 0] }]);
  assert.ok(d.take()[0].path.startsWith('/Root/Ball/Bounce/'));
  d.onTick(snap([0, 0, 0]), snap([0, 0, 0], [15, 0]), [{ type: 'point_end', a: 0, b: 1 }]);
  assert.ok(d.take().some((c) => c.path === '/Root/LineJudge/Out'));
  let all = [];
  for (let i = 0; i < 300; i++) all = all.concat(d.frame(1 / 60));
  const paths = all.map((c) => c.path);
  assert.ok(paths.includes('/Root/Crowd/EndOfPoint/ApplauseLow'));
  assert.ok(paths.includes('/Root/Umpire/RallyNormal/15-0'));
  const steps = [];
  for (let i = 0; i < 120; i++) steps.push(...d.frame(1 / 60, [{ vel: [300, 0, 0] }, { vel: [0, 0, 0] }]));
  assert.ok(steps.filter((c) => c.path === '/Root/Foot/Step').length >= 4);
});

test('wave pick and layer gain', () => {
  const s = { playmode: 'random_no_repeat', waves: [{ file: 'a', weight: 100 }, { file: 'b', weight: 100 }] };
  for (let i = 0; i < 20; i++) assert.equal(pickWave(s, 0), 1);
  assert.equal(pickWave({ waves: [{ file: null }] }), -1);
  const layer = { param: 0, sounds: [{ start: 0, length: 1 }], envelopes: [{ dsp_type: 12, points: [[0, 0], [1, 1]] }] };
  close(layerGain(layer, 15, [0, 30]), 0.5);
  close(layerGain({ param: -1, sounds: [], envelopes: [] }, 3), 1);
  assert.equal(layerGain({ param: 0, sounds: [{ start: 0.5, length: 0.2 }], envelopes: [] }, 0.1), 0);
});
