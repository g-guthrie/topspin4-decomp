import struct
import tempfile
import unittest
from pathlib import Path

from tools.xex_info import format_version, parse_xex


class XexInfoTests(unittest.TestCase):
    def test_format_version(self):
        self.assertEqual(format_version(0x12034506), "1.2.837.6")

    def test_parse_identity(self):
        data = bytearray(0x400)
        struct.pack_into(">6I", data, 0, 0x58455832, 1, 0x200, 0, 0x200, 1)
        struct.pack_into(">2I", data, 0x18, 0x00040006, 0x100)
        struct.pack_into(">4I", data, 0x100, 0x60819732, 3, 3, 0x54540859)
        struct.pack_into(">4B", data, 0x110, 0, 0, 1, 1)
        struct.pack_into(">I", data, 0x114, 0x54540859)
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "default.xex"
            path.write_bytes(data)
            result = parse_xex(path)
        self.assertEqual(result["title_id"], "54540859")
        self.assertEqual(result["media_id"], "60819732")
        self.assertEqual(result["version"], "0.0.0.3")
        self.assertEqual(result["disc_number"], 1)


if __name__ == "__main__":
    unittest.main()
