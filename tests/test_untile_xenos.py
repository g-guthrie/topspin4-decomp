"""Tests for tools/recomp/untile_xenos.py (synthetic data only)."""
import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / 'tools' / 'recomp'))
import untile_xenos as ux  # noqa: E402


class TiledOffsetTest(unittest.TestCase):
    def test_bijection_on_aligned_surface(self):
        # A 64x64 32bpp surface is two 32x32 macro tiles wide: every texel index appears once.
        w = h = 64
        seen = {ux.tiled_offset_2d(x, y, w) for y in range(h) for x in range(w)}
        self.assertEqual(seen, set(range(w * h)))

    def test_known_values(self):
        self.assertEqual(ux.tiled_offset_2d(0, 0, 1280), 0)
        self.assertEqual(ux.tiled_offset_2d(1, 0, 1280), 1)
        # The first macro tile (32x32 texels) occupies the first 1024 texels.
        self.assertTrue(all(ux.tiled_offset_2d(x, y, 1280) < 1024
                            for y in range(32) for x in range(32)))

    def test_untile_round_trip(self):
        w, h = 64, 32
        data = bytearray(w * h * 4)
        for y in range(h):
            for x in range(w):
                t = ux.tiled_offset_2d(x, y, w)
                data[4 * t:4 * t + 4] = bytes((0xFF, x, y, (x + y) & 0xFF))  # A R G B
        rgb = ux.untile(bytes(data), w, h, "argb")
        for y in range(h):
            for x in range(w):
                o = 3 * (y * w + x)
                self.assertEqual(tuple(rgb[o:o + 3]), (x, y, (x + y) & 0xFF))


if __name__ == '__main__':
    unittest.main()
