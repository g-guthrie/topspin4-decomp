"""Build and run the portable reference models in ref/gameplay with the host compiler."""

import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
REF = ROOT / "ref" / "gameplay"
MODELS = {
    "rules": ["rules.c", "test_rules.c"],
    "movement": ["movement.c", "ai_driver.c", "test_movement.c"],
    "swing": ["stats.c", "swing_window.c", "clip_fit.c", "test_swing.c"],
}


class GameplayReferenceTests(unittest.TestCase):
    def test_reference_models_build_and_pass_their_self_tests(self):
        compiler = shutil.which("cc")
        if compiler is None:
            self.skipTest("no C compiler available")
        with tempfile.TemporaryDirectory() as directory:
            for name, sources in MODELS.items():
                with self.subTest(model=name):
                    binary = Path(directory) / name
                    subprocess.run(
                        [compiler, "-std=c11", "-Wall", "-Wextra", "-Werror",
                         *[str(REF / source) for source in sources], "-lm", "-o", str(binary)],
                        check=True,
                    )
                    subprocess.run([str(binary)], check=True, capture_output=True)


if __name__ == "__main__":
    unittest.main()
