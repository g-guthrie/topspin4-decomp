// node --test port/web/test/crowd_fsm.test.mjs : crowd state machine on a synthetic trackside graph (no game data)
import test from 'node:test';
import assert from 'node:assert/strict';
import { TrackSideGraph, SectionFSM, CrowdDirector, excitementUpdate, excitementGain, excitementCap, applauseLevel, pointEvents }
  from '../src/venue/crowd_fsm.js';

const B = (name, clip, start = [], stop = []) => ({ name, name_hash: name, clip, start, stop });
const TS = {
  setups: { TS_SE00: { index: 4 }, TS_LJ00: { index: 0 }, TS_NET00: { index: 2 }, TS_STANDARD01: { index: 24 } },
  clips: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10].map((c) => ({ clip: c, duration: 1.0 })),
  behaviour_lists: [
    { setup_index: 0, behaviours: [B('Idle', 1), B('FaultLeft', 2), B('FaultRight', 3), B('Watch1', 4), B('a0', 5), B('fc', 6),
                                   B('45020cf7', null, ['a0', 'Watch1'], ['fc', 'Idle'])] },
    { setup_index: 2, behaviours: [B('IdleNet', 7), B('Running', 8), B('Running2', 9), B('28bd8c9d', null, ['Running', 'Running2'], ['Running2', 'IdleNet'])] },
    { setup_index: 4, behaviours: [B('Idle', 1), B('ApplauseLowIn', 2), B('ApplauseLowLoop', 3), B('ApplauseLowOut', 4),
                                   B('ApplauseLow', null, ['ApplauseLowIn', 'ApplauseLowLoop'], ['ApplauseLowOut', 'Idle'])] },
    { setup_index: 24, behaviours: [B('Idle01', 5), B('Flourish_01_01', 6)] },
  ],
};

test('excitement tables follow the gp1 s6 rule', () => {
  assert.equal(excitementGain(0.3, 0.1), 0.04);
  assert.equal(excitementGain(0.9, 1.0), -0.04);
  assert.equal(excitementCap(1), 0.01);
  assert.equal(excitementCap(9), 0.03);
  // gain 0.04 capped to 0.01 at one shot, + WinAce 0.01
  assert.ok(Math.abs(excitementUpdate(0.3, { events: ['WinAce'], ratio: 0.1, shots: 1 }) - 0.32) < 1e-9);
  assert.equal(excitementUpdate(0.999, { events: ['WinPassingShot'], ratio: 0.1, shots: 3 }), 1);
  assert.equal(applauseLevel(0.1, []), 0);
  assert.equal(applauseLevel(0.8, ['WinAce']), 3);
  assert.deepEqual(pointEvents({ reason: 'NO_RETURN', shots: 1, serverWon: true, homeWon: true }), ['WinAce']);
  assert.deepEqual(pointEvents({ reason: 'OUT', shots: 5, lastSpeed: 100, homeWon: false }), ['LoseUnforcedError']);
});

test('composite start loops its tail, stop runs the stop sequence to idle', () => {
  const g = new TrackSideGraph(TS);
  const f = new SectionFSM(g, 4);
  assert.equal(f.name, 'Idle');
  f.play('ApplauseLow', { hold: 2 });
  assert.equal(f.name, 'ApplauseLowIn');
  for (let i = 0; i < 12; i++) f.update(0.1);
  assert.equal(f.name, 'ApplauseLowLoop');
  for (let i = 0; i < 25; i++) f.update(0.1);        // hold runs out -> ApplauseLowOut
  assert.equal(f.name, 'ApplauseLowOut');
  for (let i = 0; i < 12; i++) f.update(0.1);
  assert.equal(f.name, 'Idle');
  assert.equal(f.current, null);
});

test('director: serve -> judges watch, fault -> call, point -> applause', () => {
  const g = new TrackSideGraph(TS);
  const d = new CrowdDirector(g, { crowd: ['TS_SE00'], judges: ['TS_LJ00'], net: 'TS_NET00',
    officials: [{ setup: 'TS_STANDARD01', behaviours: ['Idle01', 'Flourish_01_01'] }] }, { rnd: () => 0, level: 0 });
  d.onEvent({ type: 'serve', a: 0 });
  assert.equal(d.judges[0].fsm.name, 'a0');
  d.onEvent({ type: 'fault', pos: [600, 0, 300] });
  assert.equal(d.judges[0].fsm.name, 'FaultLeft');
  d.onEvent({ type: 'net' });
  assert.equal(d.net.fsm.name, 'Running');
  d.onEvent({ type: 'hit', a: 0 });
  d.onEvent({ type: 'point_end', a: 0, b: 1 });   // opponent hit out: no gp1 row, level 0 -> ApplauseLow
  d.update(0.01);
  assert.equal(d.crowd[0].fsm.name, 'ApplauseLowIn');
  assert.equal(d.log.length, 1);
  for (let i = 0; i < 100; i++) d.update(0.1);
  assert.equal(d.officials[0].fsm.name, 'Idle01');      // flourish played and returned
});
