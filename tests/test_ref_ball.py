"""Build and run the ball reference model (ref/gameplay/ball.c) self-test, alone and cross-checked
against the bit-exact draft src/xbox360/drafts/gp4b_ball_model.c. Synthetic templates only."""

import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FLAGS = ["-std=c11", "-Wall", "-Wextra", "-Werror"]


class BallReferenceTests(unittest.TestCase):
    def _run(self, extra, sources):
        cc = shutil.which("cc")
        if cc is None:
            self.skipTest("no C compiler available")
        with tempfile.TemporaryDirectory() as d:
            exe = Path(d) / "test_ball"
            subprocess.run([cc, *FLAGS, *extra, *[str(ROOT / s) for s in sources], "-lm", "-o", str(exe)], check=True)
            out = subprocess.run([str(exe)], check=True, capture_output=True, text=True).stdout
        self.assertIn("all tests passed", out)
        return out

    def test_self_test(self):
        self._run([], ["ref/gameplay/ball.c", "ref/gameplay/test_ball.c"])

    def test_matches_bit_exact_draft(self):
        out = self._run(["-DBALL_CROSSCHECK_DRAFT", "-I" + str(ROOT / "src/xbox360")],
                        ["ref/gameplay/ball.c", "ref/gameplay/test_ball.c", "src/xbox360/drafts/gp4b_ball_model.c"])
        self.assertIn("cross-check against the bit-exact draft done", out)
        self.assertNotIn("tick differs", out)


if __name__ == "__main__":
    unittest.main()
