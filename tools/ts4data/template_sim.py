#!/usr/bin/env python3
"""Simulate a representative shot for every shot template with the host build of the ball model.

Compiles tools/ts4data/template_sim.c together with src/xbox360/drafts/gp4b_ball_model.c, runs it once
per (template, scenario, solver blend) and writes a CSV (default work/disc/template_trajectories.csv).

  python3 tools/ts4data/template_sim.py --settings Settings.bin --state State.bin [--out CSV]

Columns: see COLUMNS.  Distances in m, speeds in km/h, heights are ball-centre heights above the ground.
Ball constants (a4, g, radius) are the defaults stored in State.bin (see docs/gameplay/shot-templates.md);
the net height (91.4 cm) is an assumption.  f4c = 1 runs only the primary solver of the template, f4c = 0
adds the full secondary stage (Apogee / DropTime offset).
"""
from __future__ import annotations

import argparse
import csv
import math
import os
import subprocess
import sys
import tempfile

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
import templates  # noqa: E402

# world cm: x along the court (net at 0, hitter at x < 0), y up, z across.  (from, to)
SCENARIOS = {
    "ground":    ((-1250, 100, 150), (1100, 0, -250)),   # baseline to baseline, cross-court, lands 0.9 m inside
    "serve":     ((-1200, 270, 100), (550, 0, -200)),    # contact 2.7 m, lands 0.9 m inside the service line
    "volley":    ((-250, 100, 0), (1000, 0, -200)),
    "smash":     ((-300, 250, 0), (800, 0, -150)),
    "lob":       ((-1250, 100, 100), (1100, 0, -100)),
    "drop":      ((-800, 80, 0), (300, 0, -50)),
    "defensive": ((-1400, 50, 200), (1100, 0, -100)),
}


def scenarios_for(name):
    name = name or ""
    out = ["ground"]
    if name.startswith("Serve"):
        out = ["serve"]
    elif name.endswith("Volley"):
        out = ["volley"]
    elif name.startswith("Smash"):
        out = ["smash"]
    elif name.startswith("Lob"):
        out = ["ground", "lob"]
    elif name.startswith("DropShot"):
        out = ["ground", "drop"]
    elif name.startswith("Defensive"):
        out = ["ground", "defensive"]
    return out


COLUMNS = ["file", "index", "row_offset", "name", "kind", "secondary", "T", "scenario", "f4c", "target_kmh",
           "tau", "bounce_tick", "dist", "init_kmh", "arrive_kmh", "apex_m", "apex_t", "net_centre_m",
           "net_bottom_m", "raised", "unreach", "has_min", "speed_limited", "land_err", "in_deg", "sf", "out_kmh",
           "out_deg", "e_vert", "h_ret", "spin_a", "spin_b", "spin_c", "k", "drift_g", "lat_acc", "lat_dev_m",
           "launch_deg"]


def build(out_bin):
    cmd = ["cc", "-std=c11", "-O1", "-I", os.path.join(ROOT, "src/xbox360"), "-o", out_bin,
           os.path.join(HERE, "template_sim.c"), os.path.join(ROOT, "src/xbox360/drafts/gp4b_ball_model.c"), "-lm"]
    subprocess.run(cmd, check=True)


def run_one(binary, path, row, frm, to, blend, f4c, sign=0):
    args = [binary, path, str(row)] + [str(v) for v in frm + to] + [str(blend), str(f4c), str(sign)]
    line = subprocess.run(args, check=True, capture_output=True, text=True).stdout.strip()
    return dict(kv.split("=") for kv in line.split())


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--settings", required=True)
    ap.add_argument("--state")
    ap.add_argument("--out", default=os.path.join(ROOT, "work/disc/template_trajectories.csv"))
    ap.add_argument("--blend", type=float, default=0.5, help="spin blend 0..1 (command f50)")
    a = ap.parse_args(argv)
    paths = {"Settings.bin": a.settings, "State.bin": a.state}
    dec = templates.decode_all(open(a.settings, "rb").read(), open(a.state, "rb").read() if a.state else None)
    with tempfile.TemporaryDirectory() as td:
        binary = os.path.join(td, "template_sim")
        build(binary)
        rows_out = []
        for f in dec["files"]:
            for r in f["rows"]:
                for sc in scenarios_for(r.get("name")):
                    frm, to = SCENARIOS[sc]
                    dist_cm = math.hypot(to[0] - frm[0], to[2] - frm[2])
                    for f4c in (1, 0):
                        m = run_one(binary, paths[f["file"]], r["row_offset"], frm, to, a.blend, f4c)
                        tgt = ""
                        limited = ""
                        if r["kind"] == "InitialSpeed":
                            tgt = templates.eval_value(r["primary"], dist_cm, frm[1])
                            if f4c == 1:
                                limited = int(abs(float(m["init_kmh"]) - tgt) > 5.0)
                        rec = {"file": f["file"], "index": r["index"], "row_offset": "0x%X" % r["row_offset"],
                               "name": r.get("name") or "", "kind": r["kind"], "secondary": r["secondary_kind"],
                               "T": r["T"], "scenario": sc, "f4c": f4c,
                               "target_kmh": "%.1f" % tgt if tgt != "" else "", "speed_limited": limited}
                        rec.update(m)
                        rows_out.append(rec)
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    with open(a.out, "w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=COLUMNS, extrasaction="ignore")
        w.writeheader()
        w.writerows(rows_out)
    print("wrote %s (%d rows)" % (a.out, len(rows_out)))
    return 0


if __name__ == "__main__":
    sys.exit(main())
