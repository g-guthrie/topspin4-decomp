# retune-v0 group: volleys

**What the player should feel:** A hard volley is a weak ball, not an error: low contact (below net height) and little time cost pace and placement and the ball floats short; standard volleys now have a depth pull (spec 8).

Files:

- `expressions.json`

| change | where | retail | retune-v0 | source |
|---|---|---|---|---|
| VolleyStandard power: time to contact ramp | Expressions graph 264 node 16 | [30.0, 60.0, 0.0, 1.0] | [25.0, 50.0, 0.0, 1.0] | spec 4g volley arrival edges |
| VolleyStandard power: little-time penalty | Expressions graph 264 node 3 | [100.0, 300.0, -0.1, -0.3] | [100.0, 300.0, -0.25, -0.45000002] | judgement (-0.15) |
| VolleyStandard power: low-contact penalty | Expressions graph 264 node 5 | [0.0, 50.0, -0.1, -0.1] [50.0, 100.0, -0.1, -0.05] [100.0, 110.0, -0.05, 0.0] | [0.0, 50.0, -0.16, -0.16] [50.0, 100.0, -0.16, -0.08] [100.0, 110.0, -0.08, 0.0] | judgement (x1.6) |
| VolleyStandard power: low-contact penalty | Expressions graph 264 node 7 | [0.0, 50.0, -0.3, -0.3] [50.0, 100.0, -0.3, -0.1] [100.0, 110.0, -0.1, 0.0] | [0.0, 50.0, -0.48000002, -0.48000002] [50.0, 100.0, -0.48000002, -0.16] [100.0, 110.0, -0.16, 0.0] | judgement (x1.6) |
| VolleyStandard power: low-contact penalty | Expressions graph 264 node 11 | [0.0, 50.0, -0.4, -0.3] [50.0, 80.0, -0.3, 0.0] [80.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.1] | [0.0, 50.0, -0.64, -0.48000002] [50.0, 80.0, -0.48000002, 0.0] [80.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.1] | judgement (x1.6) |
| VolleyPower power: time to contact ramp | Expressions graph 265 node 16 | [30.0, 60.0, 0.0, 1.0] | [25.0, 50.0, 0.0, 1.0] | spec 4g volley arrival edges |
| VolleyPower power: little-time penalty | Expressions graph 265 node 3 | [100.0, 300.0, -0.2, -0.4] | [100.0, 300.0, -0.35, -0.55] | judgement (-0.15) |
| VolleyPower power: low-contact penalty | Expressions graph 265 node 5 | [0.0, 50.0, -0.4, -0.4] [50.0, 100.0, -0.4, -0.15] [100.0, 110.0, -0.15, 0.0] | [0.0, 50.0, -0.64, -0.64] [50.0, 100.0, -0.64, -0.24000001] [100.0, 110.0, -0.24000001, 0.0] | judgement (x1.6) |
| VolleyPower power: low-contact penalty | Expressions graph 265 node 10 | [0.0, 50.0, -0.2, -0.2] [50.0, 100.0, -0.2, -0.1] [100.0, 110.0, -0.1, 0.0] | [0.0, 50.0, -0.32, -0.32] [50.0, 100.0, -0.32, -0.16] [100.0, 110.0, -0.16, 0.0] | judgement (x1.6) |
| VolleyPower power: low-contact penalty | Expressions graph 265 node 12 | [0.0, 50.0, -0.5, -0.3] [50.0, 100.0, -0.3, 0.0] [100.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.1] | [0.0, 50.0, -0.8, -0.48000002] [50.0, 100.0, -0.48000002, 0.0] [100.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.1] | judgement (x1.6) |
| VolleyStandard aim: time to contact ramp | Expressions graph 230 node 15 | [20.0, 60.0, 0.0, 1.0] | [25.0, 50.0, 0.0, 1.0] | spec 4g volley arrival edges |
| VolleyStandard aim: little-time penalty | Expressions graph 230 node 7 | [100.0, 300.0, -0.2, -0.4] | [100.0, 300.0, -0.35, -0.55] | judgement (-0.15) |
| VolleyStandard aim: low-contact penalty | Expressions graph 230 node 8 | [0.0, 50.0, -0.3, -0.2] [50.0, 100.0, -0.2, 0.0] [100.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.2] | [0.0, 50.0, -0.48000002, -0.32] [50.0, 100.0, -0.32, 0.0] [100.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.2] | judgement (x1.6) |
| VolleyStandard aim: low-contact penalty | Expressions graph 230 node 11 | [0.0, 50.0, -0.6, -0.4] [50.0, 100.0, -0.4, 0.0] [100.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.2] | [0.0, 50.0, -0.96000004, -0.64] [50.0, 100.0, -0.64, 0.0] [100.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.2] | judgement (x1.6) |
| VolleyStandard aim quality from a bad situation (vs timing) | Expressions graph 230 node 14 | [-1.0, -0.2, 0.2, 0.5] [-0.2, -0.05, 0.5, 0.7] [-0.05, 0.0, 0.7, 0.8] [0.0, 0.05, 0.8, 0.7] [0.05, 0.2, 0.7, 0.3] [0.2, 1.0, 0.3, 0.0] | [-1.0, -0.2, 0.1, 0.25] [-0.2, -0.05, 0.25, 0.35] [-0.05, 0.0, 0.35, 0.4] [0.0, 0.05, 0.4, 0.35] [0.05, 0.2, 0.35, 0.15] [0.2, 1.0, 0.15, 0.0] | judgement (x0.5; spec 8b bands 3-4) |
| VolleyStandard aim quality from a bad situation (vs timing) | Expressions graph 230 node 16 | [-1.0, -0.2, 0.1, 0.3] [-0.2, -0.05, 0.3, 0.6] [-0.05, 0.0, 0.6, 0.6] [0.0, 0.05, 0.6, 0.6] [0.05, 0.2, 0.6, 0.2] [0.2, 1.0, 0.2, 0.0] | [-1.0, -0.2, 0.05, 0.15] [-0.2, -0.05, 0.15, 0.3] [-0.05, 0.0, 0.3, 0.3] [0.0, 0.05, 0.3, 0.3] [0.05, 0.2, 0.3, 0.1] [0.2, 1.0, 0.1, 0.0] | judgement (x0.5; spec 8b bands 3-4) |
| VolleyStandard depth pull switched on | Expressions graph 230 node 3 | 0 | 1 | spec 8b (DeepDeviation per band; retail multiplies it by 0) |
| VolleyStandard depth pull | Expressions graph 230 node 4 | [0.0, 0.5, 400.0, 200.0] [0.5, 1.0, 200.0, 0.0] | [0.0, 0.5, 500.0, 400.0] [0.5, 1.0, 400.0, 300.0] | spec 8b bands 3-4 |
| VolleyStandard depth pull | Expressions graph 230 node 12 | [0.0, 1.0, 100.0, 0.0] | [0.0, 1.0, 80.0, 0.0] | spec 8b band 1 |
| VolleyStandard depth pull | Expressions graph 230 node 33 | [0.0, 0.5, 0.0, 0.2] [0.5, 1.0, 0.2, 1.0] | [0.0, 0.45, 0.0, 0.0] [0.45, 0.85, 0.0, 1.0] | judgement (band 2 about 1.2 m) |
| VolleyPower aim: time to contact ramp | Expressions graph 231 node 17 | [20.0, 60.0, 0.0, 1.0] | [25.0, 50.0, 0.0, 1.0] | spec 4g volley arrival edges |
| VolleyPower aim: little-time penalty | Expressions graph 231 node 6 | [100.0, 300.0, -0.2, -0.4] | [100.0, 300.0, -0.35, -0.55] | judgement (-0.15) |
| VolleyPower aim: low-contact penalty | Expressions graph 231 node 5 | [50.0, 80.0, -0.6, -0.4] [80.0, 100.0, -0.4, -0.2] [100.0, 110.0, -0.2, 0.0] [110.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.2] | [50.0, 80.0, -0.96000004, -0.64] [80.0, 100.0, -0.64, -0.32] [100.0, 110.0, -0.32, 0.0] [110.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.2] | judgement (x1.6) |
| VolleyPower aim: low-contact penalty | Expressions graph 231 node 18 | [50.0, 80.0, -0.4, -0.2] [80.0, 100.0, -0.2, -0.1] [100.0, 110.0, -0.1, 0.0] [110.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.2] | [50.0, 80.0, -0.64, -0.32] [80.0, 100.0, -0.32, -0.16] [100.0, 110.0, -0.16, 0.0] [110.0, 180.0, 0.0, 0.0] [180.0, 250.0, 0.0, 0.2] | judgement (x1.6) |
| VolleyPower aim quality from a bad situation (vs timing) | Expressions graph 231 node 7 | [-1.0, -0.2, 0.2, 0.5] [-0.2, -0.05, 0.5, 0.7] [-0.05, 0.0, 0.7, 0.8] [0.0, 0.05, 0.8, 0.7] [0.05, 0.2, 0.7, 0.3] [0.2, 1.0, 0.3, 0.0] | [-1.0, -0.2, 0.1, 0.25] [-0.2, -0.05, 0.25, 0.35] [-0.05, 0.0, 0.35, 0.4] [0.0, 0.05, 0.4, 0.35] [0.05, 0.2, 0.35, 0.15] [0.2, 1.0, 0.15, 0.0] | judgement (x0.5; spec 8b bands 3-4) |
| VolleyPower aim quality from a bad situation (vs timing) | Expressions graph 231 node 16 | [-1.0, -0.2, 0.1, 0.3] [-0.2, -0.05, 0.3, 0.6] [-0.05, 0.0, 0.6, 0.6] [0.0, 0.05, 0.6, 0.6] [0.05, 0.2, 0.6, 0.2] [0.2, 1.0, 0.2, 0.0] | [-1.0, -0.2, 0.05, 0.15] [-0.2, -0.05, 0.15, 0.3] [-0.05, 0.0, 0.3, 0.3] [0.0, 0.05, 0.3, 0.3] [0.05, 0.2, 0.3, 0.1] [0.2, 1.0, 0.1, 0.0] | judgement (x0.5; spec 8b bands 3-4) |
| VolleyPower depth pull switched on | Expressions graph 231 node 2 | 0 | 1 | spec 8b (DeepDeviation per band; retail multiplies it by 0) |
| VolleyPower depth pull | Expressions graph 231 node 13 | [0.0, 0.5, 400.0, 200.0] [0.5, 1.0, 200.0, 0.0] | [0.0, 0.5, 500.0, 400.0] [0.5, 1.0, 400.0, 300.0] | spec 8b bands 3-4 |
| VolleyPower depth pull | Expressions graph 231 node 11 | [0.0, 1.0, 100.0, 0.0] | [0.0, 1.0, 80.0, 0.0] | spec 8b band 1 |
| VolleyPower depth pull | Expressions graph 231 node 33 | [0.0, 0.5, 0.0, 0.2] [0.5, 1.0, 0.2, 1.0] | [0.0, 0.45, 0.0, 0.0] [0.45, 0.85, 0.0, 1.0] | judgement (band 2 about 1.2 m) |

Notes:

- Approximation: the spec's four bands are chosen by the volley grade (code). Here the existing situation inputs of the volley graphs stand in for it, so only the weak end is reshaped: the comfortable, high volley keeps its retail pace (bands 1-2 faster than retail need the grade rows).
- No volley error is added (retail has none, and the spec's overreach error needs the incoming pace, S+0x770, which is never written).
- Slice and drop volleys (graphs 232/233, 266/267) are unchanged in v0.
- The Volley rating already lerps between the weak and strong curves of these graphs; with the ratings group the Volley stat spreads more, so the rating matters more without a separate edit.

Generated by `python3 tuning/retune-v0/make_patches.py` from the values in `docs/design/retune-spec.md` at commit 93e3761.
