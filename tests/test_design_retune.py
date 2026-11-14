"""Tests for tools/design/retune_model.py, retune_flight.py and retune_spec.py (synthetic, standard library)."""

import os
import random
import sys
import unittest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "tools", "design"))

import retune_flight as F  # noqa: E402
import retune_model as M  # noqa: E402
import retune_spec as S  # noqa: E402


class Helpers(unittest.TestCase):
    def test_pwl(self):
        pts = [(0, 0.0), (10, 1.0), (20, 3.0)]
        self.assertEqual(M.pwl(pts, -5), 0.0)
        self.assertAlmostEqual(M.pwl(pts, 5), 0.5)
        self.assertAlmostEqual(M.pwl(pts, 15), 2.0)
        self.assertEqual(M.pwl(pts, 99), 3.0)

    def test_units(self):
        self.assertAlmostEqual(M.mph(M.kmh(113.0)), 113.0)


class Ratings(unittest.TestCase):
    def test_no_dead_zone(self):
        self.assertEqual(M.retail_stat("forehand", 25), 0.0)      # retail: everything <= 30 is 0
        vals = [M.new_stat(r) for r in range(0, 101, 5)]
        self.assertTrue(all(b > a for a, b in zip(vals, vals[1:])))
        self.assertGreater(M.new_stat(20), 0.05)
        self.assertAlmostEqual(M.new_stat(100), 1.0)

    def test_floor_penalty(self):
        self.assertEqual(M.floor_penalty(60), 0.0)
        self.assertEqual(M.floor_penalty(90), 0.0)
        self.assertGreater(M.floor_penalty(25), M.floor_penalty(45) * 2)


class Grade(unittest.TestCase):
    def test_sitter_is_teeoff(self):
        g, q, _ = M.grade_of(100, 0.8, 60, 110, 45, -250, 40, False, 0.1)
        self.assertEqual(g, "Tee-off")

    def test_ordinary_ball_standing_still_is_not_teeoff(self):
        g, _, _ = M.grade_of(90, 0.0, 0, 110, 68, 80, 40, False, 0.1)
        self.assertEqual(g, "VeryGood")

    def test_teeoff_needs_slow_ball(self):
        g, _, _ = M.grade_of(100, 0.8, 60, 110, 70, -250, 40, False, 0.1)
        self.assertNotEqual(g, "Tee-off")

    def test_stretched_run_is_bad(self):
        g, _, _ = M.grade_of(70, 5.8, 420, 85, 70, 150, 0, True, 0.15)
        self.assertIn(g, ("Bad", "VeryBad"))

    def test_grade_order_monotone_in_time(self):
        qs = [M.grade_of(f, 2.0, 150, 100, 68, 100, 15, False, 0.15)[1] for f in (40, 55, 70, 90)]
        self.assertTrue(all(b <= a for a, b in zip(qs, qs[1:])))

    def test_effects_ordered(self):
        paces = [M.GRADE_FX[g]["pace"] for g in M.GRADES]
        self.assertEqual(paces, sorted(paces, reverse=True))
        self.assertIsNone(M.GRADE_FX["Tee-off"]["cap"])
        self.assertTrue(all(M.GRADE_FX[g]["cap"] is not None for g in M.GRADES[1:]))


class Window(unittest.TestCase):
    base = dict(pace_kmh=68, react_ms=1300, height=100, kick=0.15, v_req=2.0, set_f=15, stretch=False,
                dist_net_cm=1290, floating=False, stat=0.6)

    def w(self, **kw):
        a = dict(self.base)
        a.update(kw)
        return M.window_halfwidths(**a)

    def test_easier_ball_wider(self):
        self.assertGreater(self.w(pace_kmh=45)[1], self.w()[1])
        self.assertLess(self.w(pace_kmh=110)[1], self.w()[1])

    def test_reaction_threshold(self):
        self.assertLess(self.w(react_ms=300)[0], self.w(react_ms=600)[0])
        self.assertAlmostEqual(self.w(react_ms=1000)[0], self.w(react_ms=1500)[0])

    def test_rating_widens(self):
        self.assertGreater(self.w(stat=1.0)[1], self.w(stat=0.2)[1])

    def test_clamps(self):
        hp, hg, _ = self.w(pace_kmh=20, react_ms=3000, stat=1.0, floating=True, set_f=60)
        self.assertLessEqual(hp, 4.5)
        self.assertLessEqual(hg, 12.0)
        hp, hg, _ = self.w(pace_kmh=200, react_ms=150, stat=0.0, stretch=True, v_req=7.5, height=15)
        self.assertGreaterEqual(hp, 0.5)
        self.assertGreaterEqual(hg, 2.0)

    def test_opponent_term_and_cap(self):
        self.assertLess(self.w(opp_timing="Good")[1], self.w(opp_timing="Average")[1])
        g = self.w(opp_timing="Average")[1]
        self.assertLess(self.w(opp_timing="Perfect")[1], g)
        self.assertGreater(self.w(opp_timing="Mistimed")[1], self.w(opp_timing="Poor")[1])
        big = self.w(opp_timing="Mistimed", opp_scale=10.0)[1]
        self.assertLessEqual(big / g, M.OPP_FX_CAP[1] + 1e-9)
        # total floor: ball ease x opponent term never below TOTAL_FLOOR of the normal window
        hp, hg, e = self.w(pace_kmh=160, react_ms=300, opp_timing="Perfect", stat=0.5)
        self.assertGreaterEqual(e, M.TOTAL_FLOOR * M.rating_factor(0.5) - 1e-9)

    def test_p_window(self):
        self.assertLess(M.p_window(1.0), M.p_window(3.0))
        self.assertLess(M.p_window(1.0, sigma=4.0), M.p_window(1.0, sigma=2.0))


class Speed(unittest.TestCase):
    def test_stack_order(self):
        a = M.stack_speed("Flat", "Good", "Medium", "Good", 0.5, 0.5)[0]
        b = M.stack_speed("Flat", "Tee-off", "Overcharge", "Perfect", 1.0, 1.0)[0]
        self.assertGreater(b, a + 20)
        self.assertGreater(M.stack_speed("Flat", "Good", "Medium", "Good", 0.5, 0.5)[0],
                           M.stack_speed("TopSpin", "Good", "Medium", "Good", 0.5, 0.5)[0])

    def test_grade_cap_soft(self):
        v = M.stack_speed("Flat", "Good", "Overcharge", "Perfect", 1.0, 1.0)[0]
        cap = M.GRADE_FX["Good"]["cap"]
        self.assertLess(v, cap + 10)
        self.assertGreater(M.stack_speed("Flat", "Tee-off", "Overcharge", "Perfect", 1.0, 1.0)[0], v)

    def test_hold_reached(self):
        c = M.CHARGE
        lead = M.RELEASE_LEAD
        self.assertEqual(M.hold_reached(lead + 2, 30), "Finesse")
        self.assertEqual(M.hold_reached(lead + c["powerful_from"] + 1, 30), "Powerful")
        self.assertEqual(M.hold_reached(lead + c["full_at"] + c["overcharge_wait"] + 2, 40), "Overcharge")
        self.assertEqual(M.hold_reached(lead + c["full_at"] + c["overcharge_wait"] + 2, 10), "Powerful")

    def test_forehand_ceiling(self):
        v = M.stack_speed("Flat", "Tee-off", "Overcharge", "Perfect", 1.0, 1.0, skill=True, noise=30.0)[0]
        self.assertEqual(v, 110.0)
        vb = M.stack_speed("Flat", "Tee-off", "Overcharge", "Perfect", 1.0, 1.0, skill=True, noise=30.0, stroke="BH")[0]
        self.assertEqual(vb, 105.0)
        self.assertAlmostEqual(M.stack_speed("Flat", "Good", "Medium", "Good", 0.5, 0.5)[0], 74.0)


class Movement(unittest.TestCase):
    def test_run_curve(self):
        self.assertEqual(M.run_cm(0), 0.0)
        self.assertAlmostEqual(M.run_cm(8, M.RUSH_FIRST_STEP), 5.0)
        self.assertLess(M.run_cm(8), 5.0)                       # retail first step is slower
        # unchanged after the first metre: same speed beyond it
        self.assertAlmostEqual(M.run_cm(80) - M.run_cm(70), M.run_cm(80, M.RUSH_FIRST_STEP) - M.run_cm(70, M.RUSH_FIRST_STEP))

    def test_retail_rush_waits_for_hit(self):
        d = M.net_timeline(36, 47, 34, -600, 76, buffered=False)
        self.assertEqual(d["start"], 47)
        d = M.net_timeline(36, 47, 34, -600, 76, buffered=True)
        self.assertEqual(d["start"], 36)

    def test_shorter_tail_gets_closer(self):
        a = M.net_timeline(38, 42, 29, -400, 83, M.RUSH_FIRST_STEP, False, True)
        b = M.net_timeline(26, 42, 29, -400, 83 * 26 / 38, M.RUSH_FIRST_STEP, False, True)
        self.assertGreater(b["x_at_ball"], a["x_at_ball"])
        self.assertGreater(b["free"], a["free"])


class Flight(unittest.TestCase):
    def test_yaml_subset(self):
        d = F.parse_yaml_subset("a: 1\nb:\n  - x: 2\n    y: [1, 2]\n")
        self.assertEqual(d["a"], 1)
        self.assertEqual(d["b"][0]["y"], [1, 2])

    def test_load_rows_and_edit(self):
        rows = F.load_rows()
        self.assertAlmostEqual(rows[10]["T"], 0.05)
        r = F.edit_row(rows[10], primary_kmh=(150.0, 160.0))
        self.assertIsNot(r, rows[10])

    def test_game_fly_reproduces_baseline(self):
        rows = F.load_rows()
        d = F.game_fly(rows[10], (-1188, 100, 150), (1000, 0, -300), pf=1.0, blend=0.5)
        self.assertAlmostEqual(d["launch_kmh"], 147.0, delta=1.5)

    def test_real_model(self):
        r = F.real_aim(F.mph_to_kmh(72), 2700, 10.0, surface="hard")
        self.assertTrue(0.6 < r["net_clear_m"] < 1.3)
        self.assertTrue(0.70 < r["out_over_in"] < 0.90)
        h = {s: F.real_aim(F.mph_to_kmh(72), 2700, 10.0, surface=s)["bounce_apex_m"] for s in F.SURFACES}
        self.assertGreater(h["clay"], h["hard"])
        self.assertGreater(h["hard"], h["grass"])
        self.assertAlmostEqual(F.cpr(0.62, 0.81), 38.0)


class Aim(unittest.TestCase):
    def test_quads_match_aiming_doc(self):
        import retune_aim as A
        c = A.load_configs()["FlatNormal"]
        for m, up, upright in ((0.0, (737, -12), (739, 31)), (0.8, (1074, -3), (1074, 339)), (1.0, (1188, 0), (1188, 411))):
            q = A.quad_at(c, m)
            self.assertEqual(tuple(round(v) for v in A.stick_target(q, 0, 1)), up)
            self.assertEqual(tuple(round(v) for v in A.stick_target(q, 1, 1)), upright)

    def test_efficiency_feed(self):
        e = [M.aim_efficiency("FlatMedium", g, "Perfect", 0.8) for g in M.GRADES]
        self.assertEqual(e, sorted(e, reverse=True))
        self.assertLessEqual(max(e), M.EFF_MAX)
        # the hand stat now matters: 0.3 against 0.9 costs more than retail's 0.03-0.05
        self.assertGreater(M.aim_efficiency("FlatMedium", "Good", "Perfect", 0.9) - M.aim_efficiency("FlatMedium", "Good", "Perfect", 0.3), 0.1)
        self.assertGreater(M.aim_efficiency("TopSpinMedium", "Good", "Perfect", 0.8), M.aim_efficiency("FlatPower", "Good", "Perfect", 0.8))

    def test_final_efficiency_table(self):
        self.assertAlmostEqual(M.final_efficiency(0.5, 0.5), 0.63)
        self.assertAlmostEqual(M.final_efficiency(1.0, 1.0), 1.0)

    def test_deep_deviation(self):
        self.assertLess(M.depth_shortfall("Good", "Perfect")[0], 60)
        self.assertGreater(M.depth_shortfall("Good", "Mistimed")[0], 200)


class Sim(unittest.TestCase):
    def test_round_robin_deterministic(self):
        b = {k: M.BUILDS[k] for k in ("heavy topspin", "slicer")}
        r1 = M.round_robin(b, 2, 5)
        r2 = M.round_robin(b, 2, 5)
        self.assertEqual(r1, r2)

    def test_spec_tables_run(self):
        class A:
            quick = True
        for name in ("grade", "window", "power", "placement", "stats", "movement"):
            self.assertIn("|", S.SECTIONS[name](A()))


if __name__ == "__main__":
    unittest.main()
