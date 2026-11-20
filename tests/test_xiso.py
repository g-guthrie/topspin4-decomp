import struct
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def entry(left, right, sector, size, attributes, name):
    raw = struct.pack("<HHIIBB", left, right, sector, size, attributes, len(name)) + name
    return raw + b"\xff" * ((-len(raw)) % 4)


class XisoTests(unittest.TestCase):
    def test_lists_and_extracts_synthetic_image(self):
        image = bytearray(40 * 2048)
        struct.pack_into("<20sII", image, 32 * 2048, b"MICROSOFT*XBOX*MEDIA", 34, 2048)
        root = entry(0, 5, 36, 5, 0x20, b"a.txt") + entry(0, 0, 35, 2048, 0x10, b"Physics")
        image[34 * 2048 : 34 * 2048 + len(root)] = root
        sub = entry(0, 0, 37, 3, 0x20, b"P.bin")
        image[35 * 2048 : 35 * 2048 + len(sub)] = sub
        image[36 * 2048 : 36 * 2048 + 5] = b"hello"
        image[37 * 2048 : 37 * 2048 + 3] = b"abc"
        with tempfile.TemporaryDirectory() as temp:
            iso = Path(temp) / "synthetic.iso"
            iso.write_bytes(image)
            listing = subprocess.run(
                [sys.executable, str(ROOT / "tools" / "xiso.py"), "list", str(iso)],
                capture_output=True, text=True, check=True,
            ).stdout
            self.assertIn("Physics/P.bin", listing)
            self.assertIn("a.txt", listing)
            out = Path(temp) / "out"
            subprocess.run(
                [sys.executable, str(ROOT / "tools" / "xiso.py"), "extract", str(iso), str(out), "Physics/"],
                capture_output=True, text=True, check=True,
            )
            self.assertEqual((out / "Physics" / "P.bin").read_bytes(), b"abc")
            self.assertFalse((out / "a.txt").exists())


if __name__ == "__main__":
    unittest.main()
