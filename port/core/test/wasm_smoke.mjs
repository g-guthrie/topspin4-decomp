// Node smoke test of the wasm build: node wasm_smoke.mjs ts4core.wasm blob.ts4d SEED TICKS [EXPECTED_HASH_HEX]
// Runs the same AI-vs-AI match as `test_core --match` and compares the state hash with the host build.
import { readFileSync } from 'node:fs';
import { Ts4Core, BTN } from '../js/ts4core.mjs';

const [wasmPath, blobPath, seed = '7', ticks = '6000', expect] = process.argv.slice(2);
const core = await Ts4Core.fromBytes(readFileSync(wasmPath), new Uint8Array(readFileSync(blobPath)));
const fail = (m) => { console.error('FAIL: ' + m); process.exit(1); };
if (core.loadResult !== 0) fail('ts4_data_load returned ' + core.loadResult);
if (core.missingTunables().length) fail('missing tunables ' + core.missingTunables());
if (WebAssembly.Module.imports(new WebAssembly.Module(readFileSync(wasmPath))).length) fail('module has imports');
console.log(core.buildInfo(), JSON.stringify(core.moduleStatus()));
// same stats as default_cfg() in test_core.c so the host and wasm hashes are comparable
const stats = (i) => Array.from({ length: 8 }, (_, k) => 60 + 5 * i + k);
if (core.startMatch({ seed: Number(seed), players: [{ stats: stats(0) }, { stats: stats(1) }] }) !== 0) fail('match start');
const counts = {};
for (let t = 0; t < Number(ticks); t++) {
  core.step();
  for (const e of core.pollEvents()) counts[e.type] = (counts[e.type] ?? 0) + 1;
}
const hash = core.stateHash().toString(16).padStart(8, '0');
console.log(`hash ${hash} serves ${counts.serve} hits ${counts.hit} bounces ${counts.bounce} points ${counts.point_end} games ${counts.game ?? 0}`);
if (expect && hash !== expect) fail(`hash ${hash} != host ${expect}`);
const snap = core.snapshot();
if (!(snap.tick === Number(ticks))) fail('snapshot tick');
// human-driven serve through the JS binding
core.startMatch({ seed: 5, players: [{ human: true }, {}] });
core.step(30);
core.setInput(0, { buttons: BTN.FLAT }); core.step(20);
core.setInput(0, { buttons: 0 }); core.step(1);
const ev = core.pollEvents();
if (!ev.some((e) => e.type === 'serve')) fail('human serve did not happen');
if (core.snapshot().phase !== 'rally') fail('not in rally after the serve');
// shot trace through the binding: first bounce at the planned point
const tr = core.shotTrace({ row: 0, from: [-1100, 110, 40], to: [900, 0, -150] });
if (!(tr.length > 60) || Math.abs(tr[tr.length - 1][0]) > 5000) fail('trace');
console.log('wasm smoke OK');
