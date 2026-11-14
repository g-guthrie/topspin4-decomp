// node port/web/test/session_smoke.mjs ts4core.wasm blob.dat
// Headless check of the play path: MatchSession at a fixed 60 Hz (frame clock -> ticks), human serve, interpolation,
// tunable round trip, shot probe/trace through the reference binding, struct layout against the module.
import { readFileSync } from 'node:fs';
import { Ts4Core, SIZES, MODE, BTN } from '../../core/js/ts4core.mjs';
import { MatchSession } from '../src/match.js';
import { matchConfigFrom } from '../src/helpers.js';

const [wasmPath, blobPath] = process.argv.slice(2);
const fail = (m) => { console.error('FAIL: ' + m); process.exit(1); };
const core = await Ts4Core.fromBytes(readFileSync(wasmPath), new Uint8Array(readFileSync(blobPath)));
if (core.loadResult !== 0) fail('data load ' + core.loadResult);
if (core.missingTunables().length) fail('missing tunables');
const ses = new MatchSession(core);
if (ses.start(matchConfigFrom({ format: 'short', seed: 3 })) !== 0) fail('match start');
if (ses.cur.phase !== 'serve') fail('phase ' + ses.cur.phase);

// the frame clock turns into whole ticks: 1.0 s of 16.7 ms frames = 60 ticks (+-1)
let n = 0;
for (let i = 0; i < 60; i++) n += ses.frame(1 / 60 + 1e-6);
if (Math.abs(n - 60) > 1) fail('ticks per second ' + n);
// 144 Hz display still gives 60 ticks per second
const before = ses.core.snapshot().tick;
for (let i = 0; i < 144; i++) ses.frame(1 / 144);
const d = ses.core.snapshot().tick - before;
if (Math.abs(d - 60) > 1) fail('ticks at 144 Hz ' + d);

// human serve: hold the flat button, release
const ticksBefore = ses.cur.tick;
ses.setInput(0, { buttons: BTN.FLAT });
for (let i = 0; i < 25; i++) ses.frame(1 / 60 + 1e-6);
ses.setInput(0, { buttons: 0 });
for (let i = 0; i < 5; i++) ses.frame(1 / 60 + 1e-6);
const ev = ses.takeEvents();
if (!ev.some((e) => e.type === 'serve' && e.a === 0)) fail('no serve event: ' + JSON.stringify(ev.map((e) => e.type)));
if (!ev.some((e) => e.type === 'hit' && e.b >= 20 && e.b <= 31)) fail('serve did not use a serve template row');
if (ses.cur.phase !== 'rally') fail('not in rally');

// interpolation: render snapshot lies between the last two ticks
ses.frame(0.5 / 60);
const v = ses.view(), a = ses.prev.ball.pos[0], b = ses.cur.ball.pos[0];
if (ses.prev.tick !== ses.cur.tick && !(Math.min(a, b) - 1e-3 <= v.ball.pos[0] && v.ball.pos[0] <= Math.max(a, b) + 1e-3)) fail('ball interpolation');

// tunable round trip and its effect on a probe
const T = core.tunables();
if (T.length < 50 || T.some((t) => t.value === null && false)) fail('tunable list');
const probe = { row: 6, from: [-1250, 100, 150], to: [1000, 0, -250] };
const p0 = core.shotProbe(probe);
if (typeof p0 === 'number') fail('probe ' + p0);
const old = core.getTunable('ball.a4');
if (core.setTunable('ball.a4', old * 1.5) !== 0) fail('set tunable');
if (Math.abs(core.getTunable('ball.a4') - old * 1.5) > 1e-4) fail('get tunable');
const p1 = core.shotProbe(probe);
if (!(Math.abs(p1.initialKmh - p0.initialKmh) > 0.01 || Math.abs(p1.tau - p0.tau) > 1e-4)) fail('ball.a4 had no effect on the probe');
core.setTunable('ball.a4', old);
const p2 = core.shotProbe(probe);
if (Math.abs(p2.tau - p0.tau) > 1e-6) fail('restore');
if (core.setTunable('no.such.tunable', 1) !== -1) fail('unknown name');
const tr = core.shotTrace({ ...probe, maxTicks: 300 });
if (!(tr.length > 60)) fail('trace');
const tr2 = core.shotTrace({ ...probe, maxTicks: 100 });
if (tr2.length > 100) fail('trace cap');
if (core.shotProbe({ ...probe, mode: MODE.NET }).tau <= 0) fail('net-mode probe');
const g = core.graphCount();
if (g < 1 || typeof core.graphEval(0, Array(core.graphInfo(0).inputs).fill(1)) === 'number') fail('graph eval');
if (SIZES.shotIn !== 60) fail('shotIn size');
console.log('session smoke OK: ' + core.buildInfo() + ', ' + T.length + ' tunables, ' + g + ' graphs, probe tau ' + p0.tau.toFixed(3));
