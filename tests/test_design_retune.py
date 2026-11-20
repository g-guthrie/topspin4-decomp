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
    # grade_of(frames, v_req, run_cm, height, pace, depth_x, set_f, stretch, kick)
    def test_sitter_is_teeoff(self):
        g, sc, _ = M.grade_of(100, 0.8, 60, 110, 45, -250, 40, False, 0.1)
        self.assertEqual((g, sc), ("Tee-off", -1))

    def test_ordinary_ball_standing_still_is_verygood(self):
        g, sc, _ = M.grade_of(90, 0.0, 0, 110, 68, 80, 40, False, 0.1)
        self.assertEqual((g, sc), ("VeryGood", 0))

    def test_neutral_rally_ball_is_good(self):
        g, sc, _ = M.grade_of(78, 2.0, 150, 100, 68, 100, 20, False, 0.15)
        self.assertEqual((g, sc), ("Good", 1))

    def test_teeoff_needs_slow_ball_and_short_contact(self):
        self.assertNotEqual(M.grade_of(100, 0.8, 60, 110, 70, -250, 40, False, 0.1)[0], "Tee-off")
        g, sc, _ = M.grade_of(100, 0.8, 60, 120, 48, 200, 40, False, 0.1)     # slow but taken 2 m deep
        self.assertEqual((g, sc), ("VeryGood", -1))

    def test_stretched_run_is_bad(self):
        g, _, _ = M.grade_of(70, 5.8, 420, 85, 70, 150, 0, True, 0.15)
        self.assertIn(g, ("Bad", "VeryBad"))

    def test_score_rows(self):
        self.assertEqual([M.grade_of_score(x) for x in (-1, 0, 1, 2, 3, 4, 5, 6, 9)],
                         ["VeryGood", "VeryGood", "Good", "Good", "Normal", "Bad", "Bad", "VeryBad", "VeryBad"])

    def test_rushed_and_tired_add_points(self):
        base = M.grade_of(78, 2.0, 150, 100, 68, 100, 20, False)[1]
        self.assertEqual(M.grade_of(78, 2.0, 150, 100, 68, 100, 20, False, rushed=True)[1], base + 1)
        self.assertEqual(M.grade_of(78, 2.0, 150, 100, 68, 100, 20, False, vigor=0.2)[1], base + 1)

    def test_let_high_ball_drop(self):
        s = M.Situation()
        s.height, s.set_f, s.frames, s.depth_x, s.dist_net_cm = 190.0, 40, 90, 100.0, 1288.0
        self.assertTrue(M.choose_contact(random.Random(1), s))
        self.assertLessEqual(s.height, M.SHOULDER_CM)
        self.assertGreater(s.depth_x, 150.0)

    def test_effects_ordered(self):
        for k in ("pace_cap", "aim_cap", "w_grade"):
            v = [M.GRADE_FX[g][k] for g in M.GRADES]
            self.assertEqual(v, sorted(v, reverse=True))
        self.assertEqual(M.GRADE_FX["Good"]["pace_cap"], 1.0)
        self.assertEqual(M.GRADE_FX["Good"]["aim_cap"], 1.0)


class Window(unittest.TestCase):
    def test_retail_at_w1(self):
        hp, hg, w = M.window_halfwidths("Good", M.new_stat(70), 1000)
        self.assertAlmostEqual(w, 1.0, places=6)
        self.assertAlmostEqual(hp, 2.0)
        self.assertAlmostEqual(hg, 6.0)

    def test_design_note_cases(self):
        self.assertAlmostEqual(M.window_scale("Good", M.new_stat(70), 1300, "Good")[0], 0.93, places=6)
        self.assertAlmostEqual(M.window_scale("Normal", M.new_stat(70), 1100, "Perfect")[0], 0.8075, places=6)
        self.assertAlmostEqual(M.window_scale("Bad", M.new_stat(70), 300, "Perfect")[0], 0.60, places=6)
        self.assertAlmostEqual(M.window_scale("Tee-off", M.new_stat(70), 1600, "Mistimed")[0], 1.69, places=6)

    def test_reaction_threshold(self):
        self.assertLess(M.reaction_factor(300), M.reaction_factor(500))
        self.assertEqual(M.reaction_factor(600), M.reaction_factor(1500))
        self.assertAlmostEqual(M.reaction_factor(250), 0.70)

    def test_rating_widens(self):
        self.assertAlmostEqual(M.rating_factor(M.new_stat(40)), 0.90, places=6)
        self.assertAlmostEqual(M.rating_factor(1.0), 1.10, places=6)

    def test_clamp_and_overcharge(self):
        self.assertEqual(M.window_scale("Tee-off", 1.0, 2000, "Mistimed", opp_scale=10.0)[0], M.W_CLAMP[1])
        self.assertEqual(M.window_scale("VeryBad", 0.0, 100, "Perfect")[0], M.W_CLAMP[0])
        w = M.window_scale("Good", 0.6, 1000)[0]
        self.assertAlmostEqual(M.window_scale("Good", 0.6, 1000, overcharge=True)[0], w * M.OVERCHARGE_W)

    def test_zero_error_band(self):
        self.assertEqual(M.timing_error(0.40, "Full"), 0.0)        # retail band, 19 frames at W = 1
        self.assertEqual(M.timing_error(-0.55, "Full"), 0.0)
        self.assertGreater(M.timing_error(0.60, "Full"), M.timing_error(-0.75, "Full"))
        self.assertAlmostEqual(M.timing_error(0.5, "Overcharge"), 2 * M.timing_error(0.5, "Full"))

    def test_rushed_release_is_late(self):
        c, f, pos, t = M.release(random.Random(1), 2.0, 6.0, rushed=True)
        self.assertEqual(c, "Poor")
        self.assertAlmostEqual(t, 0.4)

    def test_p_window(self):
        self.assertLess(M.p_window(1.0), M.p_window(3.0))
        self.assertLess(M.p_window(1.0, sigma=4.0), M.p_window(1.0, sigma=2.0))


class Speed(unittest.TestCase):
    def test_good_row_is_retail(self):
        self.assertAlmostEqual(M.row_max_mph("Flat", "Good", "Full", 100), M.mph(145.2))
        self.assertAlmostEqual(M.row_max_mph("Flat", "Good", "Medium", 54), M.mph(125.0))

    def test_ceiling_arithmetic(self):
        self.assertAlmostEqual(M.row_max_mph("Flat", "Tee-off", "Full", 100), M.mph(145.2) * 1.18)
        self.assertGreater(M.row_max_mph("Flat", "Tee-off", "Overcharge", 100), 110.0)       # clipped by the ceiling
        self.assertTrue(95.0 <= M.row_max_mph("Flat", "Tee-off", "Overcharge", 54) <= 99.5)

    def test_tier_steps_grow_above_good(self):
        def step(g):
            return M.row_max_mph("Flat", g, "Full", 75) / M.row_max_mph("Flat", g, "Medium", 75)
        self.assertGreater(step("Tee-off"), step("Good"))
        self.assertLess(step("Bad"), step("Good"))

    def test_hold_reached(self):
        c, lead = M.CHARGE, M.RELEASE_LEAD
        self.assertEqual(M.hold_reached(lead + 2, 30), "Finesse")
        self.assertEqual(M.hold_reached(lead + c["powerful_from"] + 1, 30), "Powerful")
        self.assertEqual(M.hold_reached(lead + c["full_at"] + 1, 30), "Full")
        self.assertEqual(M.hold_reached(lead + c["full_at"] + c["overcharge_past_full"] + 2, 60), "Overcharge")
        self.assertEqual(M.hold_reached(lead + c["full_at"] + c["overcharge_past_full"] + 2, 10), "Full")

    def test_ceiling(self):
        v = M.stack_speed("Flat", "Tee-off", "Overcharge", 1.0, 1.0, 1.0, skill=True, noise=30.0)[0]
        self.assertEqual(v, 110.0)
        vb = M.stack_speed("Flat", "Tee-off", "Overcharge", 1.0, 1.0, 1.0, skill=True, noise=30.0, stroke="BH")[0]
        self.assertEqual(vb, 105.0)
        self.assertLess(M.stack_speed("Flat", "Good", "Medium", 0.5, 0.6, 0.6)[0], M.stack_speed("Flat", "Good", "Medium", 1.0, 0.6, 0.6)[0])


class Movement(unittest.TestCase):
    def test_run_curve(self):
        self.assertEqual(M.run_cm(0), 0.0)
        self.assertAlmostEqual(M.run_cm(18), 5.0)
        self.assertAlmostEqual(M.run_cm(43), 100.0)
        self.assertAlmostEqual(M.run_cm(53) - M.run_cm(43), 96.0)
        self.assertIs(M.RUSH_FIRST_STEP, M.RUSH_RETAIL)        # first step from rest kept as retail

    def test_retail_rush_waits_for_hit(self):
        d = M.net_timeline(36, 47, 34, -600, 76, buffered=False)
        self.assertEqual(d["start"], 47)
        d = M.net_timeline(36, 47, 34, -600, 76, buffered=True)
        self.assertEqual(d["start"], 36)

    def test_shorter_tail_gets_closer(self):
        a = M.net_timeline(38, 42, 29, -400, 83, M.RUSH_RETAIL, False, True)
        b = M.net_timeline(19, 42, 29, -400, 83 * 19 / 38, M.RUSH_RETAIL, False, True)
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
        self.assertLessEqual(M.depth_shortfall("Good", "Perfect")[0], 20)
        self.assertGreater(M.depth_shortfall("Good", "Poor")[0], 200)
        self.assertEqual(M.depth_shortfall("Bad", "Perfect"), M.depth_shortfall("Tee-off", "Perfect"))   # timing only


class Returns(unittest.TestCase):
    def _player(self, ret):
        r = dict(M.BUILDS["big server"][0])
        r["ret"] = ret
        return M.MatchPlayer("R", r)

    def test_family_grade(self):
        self.assertEqual(M.return_grade(120.0, 0.5), "Good")
        self.assertEqual(M.return_grade(85.0, 0.5), "VeryGood")
        self.assertEqual(M.return_grade(120.0, 0.9), "Bad")

    def test_bad_grade_never_attacking(self):
        rng = random.Random(3)
        p = self._player(95)
        qs = {M.return_quality(rng, p, 85.0, 0.9, second=True)[0] for _ in range(2000)}
        self.assertNotIn("good", qs)        # hold lever 1: a stretched return is lowered one step

    def test_low_return_rating_errs_more(self):
        def unret(ret):
            rng = random.Random(5)
            p = self._player(ret)
            return sum(M.return_quality(rng, p, 115.0, 0.5)[0] == "unreturned" for _ in range(4000))
        self.assertGreater(unret(60), unret(90))

    def test_volley_base_error(self):
        self.assertGreater(M.RALLY["volley_base_err"], 0.0)
        self.assertLess(M.RALLY["volley_base_err"], M.RALLY["base_err"])


class Sim(unittest.TestCase):
    def test_round_robin_deterministic(self):
        b = {k: M.BUILDS[k] for k in ("heavy topspin", "slicer")}
        r1 = M.round_robin(b, 2, 5)
        r2 = M.round_robin(b, 2, 5)
        self.assertEqual(r1, r2)

    def test_spec_tables_run(self):
        class A:
            quick = True
        for name in ("grade", "window", "power", "stats", "movement"):
            self.assertIn("|", S.SECTIONS[name](A()))


if __name__ == "__main__":
    unittest.main()
