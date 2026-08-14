import tempfile
import unittest
from pathlib import Path

from tools.inventory import classify, sha256_file


class InventoryTests(unittest.TestCase):
    def test_platform_markers(self):
        self.assertEqual(classify(["PS3_GAME/USRDIR/EBOOT.BIN"])["platform_hint"], "ps3")
        self.assertEqual(
            classify(["$SystemUpdate/file", "VIDEO_TS/VIDEO_TS.IFO"])["platform_hint"],
            "xbox360-optical",
        )

    def test_hash(self):
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "sample"
            path.write_bytes(b"topspin4")
            self.assertEqual(
                sha256_file(path),
                "5e943b3895f49e54b9ff4167f1639206a3502c2ad7774fa47dd2c2fe191761d1",
            )


if __name__ == "__main__":
    unittest.main()
