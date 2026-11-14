"""Synthetic tests for tools/design/baseline_lib.py (no game data needed)."""
import math
import os
import sys
import unittest

sys.path.insert(0, os.path.join(os.path.dirname(__file__), "..", "tools", "design"))
import baseline_lib as L  # noqa: E402


class TestUnits(unittest.TestCase):
    def test_conversions(self):
        self.assertAlmostEqual(L.kmh_to_mph(100.0), 62.137, places=2)
        self.assertAlmostEqual(L.frames_to_ms(6), 100.0)


class TestRamp(unittest.TestCase):
    KEYS = [(0.0, 0.5, 0.0, 1.0), (0.5, 1.0, 1.0, 1.0)]

    def test_ramp(self):
        self.assertAlmostEqual(L.ramp_eval(self.KEYS, 0.25), 0.5)
        self.assertAlmostEqual(L.ramp_eval(self.KEYS, 0.75), 1.0)
        self.assertAlmostEqual(L.ramp_eval(self.KEYS, -1.0), 0.0)   # clamped below
        self.assertAlmostEqual(L.ramp_eval(self.KEYS, 9.0), 1.0)    # clamped above

    def test_flat_spans_and_knees(self):
        f = lambda x: L.ramp_eval(self.KEYS, x)
        spans = L.flat_spans(f, 0.0, 1.0, n=100)
        self.assertTrue(any(a <= 0.52 and b >= 0.98 for a, b, _ in spans))
        ks = L.knees(f, 0.0, 1.0, n=100)
        self.assertTrue(any(abs(k - 0.5) < 0.03 for k in ks))

    def test_sweep(self):
        mn, mx, xmin, xmax = L.sweep(lambda x: (x - 0.3) ** 2, 0.0, 1.0, 100)
        self.assertAlmostEqual(mn, 0.0, places=6)
        self.assertAlmostEqual(xmin, 0.3, places=6)
        self.assertAlmostEqual(xmax, 1.0)


class TestArc2(unittest.TestCase):
    def integrate(self, p, v, k, weff, t, n=20000):
        dt = t / n
        p, v = list(p), list(v)
        for _ in range(n):
            a = [k * (weff[i] - v[i]) for i in range(3)]
            v = [v[i] + a[i] * dt for i in range(3)]
            p = [p[i] + v[i] * dt for i in range(3)]
        return p, v

    def test_closed_form_matches_integration(self):
        k = 0.5
        weff = L.arc2_weff(k, 0.03, [0.0, -0.003, 0.0])
        p0, v0 = [-11.88, 1.0, 0.0], [35.0, 4.0, 1.0]
        p, v = L.arc2_state(p0, v0, k, weff, 0.6)
        q, w = self.integrate(p0, v0, k, weff, 0.6)
        for i in range(3):
            self.assertAlmostEqual(p[i], q[i], places=2)
            self.assertAlmostEqual(v[i], w[i], places=2)

    def test_apex_and_time_to_x(self):
        k = 0.5
        weff = L.arc2_weff(k, 1.0, [0.0, 0.0, 0.0])
        p0, v0 = [0.0, 0.0, 0.0], [20.0, 5.0, 0.0]
        h, t = L.arc2_apex(p0, v0, k, weff)
        self.assertAlmostEqual(L.arc2_state(p0, v0, k, weff, t)[1][1], 0.0, places=6)
        self.assertGreater(h, 0.0)
        tx = L.arc2_time_to_x(p0, v0, k, weff, 5.0)
        self.assertAlmostEqual(L.arc2_state(p0, v0, k, weff, tx)[0][0], 5.0, places=4)
        self.assertIsNone(L.arc2_time_to_x(p0, v0, k, weff, 500.0))


class TestTable(unittest.TestCase):
    def test_md_table(self):
        t = L.md_table(["a", "b"], [(1, 2)])
        self.assertEqual(t.splitlines()[0], "| a | b |")
        self.assertEqual(len(t.splitlines()), 3)


if __name__ == "__main__":
    unittest.main()
