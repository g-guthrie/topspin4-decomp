// Piecewise-linear curve and table evaluators used by the shot templates.
// Ports of fn_8817A688 (curve20), fn_881899D8 (curve16), fn_8826D278 (table2d); see docs/gameplay/gp4b.md section 1
// and tools/ts4data/templates.py (eval_*), which these mirror. Values come from the user's own export (shots.json).

export function evalCurve20(keys, x) {
  if (!keys || !keys.length) return 0;
  let sel = keys[0];
  for (const k of keys) { if (k[0] > x) break; sel = k; }
  const t = Math.max(Math.min(x - sel[0], sel[1] - sel[0]), 0);
  return sel[2] + t * sel[3];
}

export function evalCurve16(keys, x) {
  if (!keys || !keys.length) return 0;
  let sel = keys[0];
  for (const k of keys) { if (k[0] > x) break; sel = k; }
  const span = sel[1] - sel[0];
  const t = Math.min(Math.max(x - sel[0], 0), span);
  return sel[2] + (span ? t / span : 0) * (sel[3] - sel[2]);
}

export function evalTable2d(rows, a, b) {
  if (!rows || !rows.length) return 0;
  let lo = 0;
  for (let i = 0; i < rows.length; i++) { if (a - rows[i].a < 0) break; lo = i; }
  if (lo === rows.length - 1) return evalCurve16(rows[lo].keys, b);
  const r0 = rows[lo], r1 = rows[lo + 1];
  const v0 = evalCurve16(r0.keys, b), v1 = evalCurve16(r1.keys, b);
  const d = a - r0.a, span = r1.a - r0.a;
  if (d > 0) return d >= span ? v1 : v0 + (d / span) * (v1 - v0);
  return v0;
}

// val: {type: "const"|"curve20"|"table2d", ...}; x = horizontal distance cm, y = hit height cm (tables only)
export function evalValue(val, x, y = 0) {
  if (!val) return 0;
  switch (val.type) {
    case "const": return val.value;
    case "curve20": return evalCurve20(val.keys, x);
    case "table2d": return evalTable2d(val.rows, x, y);
    default: return 0;
  }
}
