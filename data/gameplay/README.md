# Gameplay values

Readable dumps of the values that govern Top Spin 4 gameplay: stats, analyser curves, thresholds, shot
templates, decision trees, movement and animation tunables. They are generated from the retail disc by the
tools in `tools/ts4data/` and `tools/ts4_analyser.py`; each file records the command that produced it and the
sha256 of its source file. Raw game files are never committed (see `AGENTS.md`).

G8 additions (docs/gameplay/controls-and-shot-selection.md s18):

* `special_swings.yaml`: clips per SwingCategory and Properties value (counts, frames, contact, entry and exit
  windows, root travel) and the trigger of each special swing.
  `python3 tools/ts4data/special_swings.py --settings work/disc/core/334e7e0d.bin --core work/disc/core_all --out data/gameplay/special_swings.yaml`
* `charge_table.yaml`: hold frames -> power -> tier -> PowerfulFactor -> launch speed for a flat forehand at
  min / median / max ratings, the category link effects, SwingSpeedCoef and the powerful-shot stamina cost.
  `python3 tools/ts4data/charge_table.py --out data/gameplay/charge_table.yaml`
* `shot_tree.yaml` `swing_category_rules` now also records the mode and class selection and the list offsets.
