import json
import unittest
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]


class ProgressTests(unittest.TestCase):
    def test_progress_stages_are_explicit_and_monotonic(self):
        progress = json.loads((ROOT / "config" / "progress.json").read_text())

        self.assertLessEqual(
            progress["reconstructed_functions"], progress["semantic_drafts"]
        )
        self.assertLessEqual(
            progress["validated_functions"], progress["reconstructed_functions"]
        )
        self.assertLessEqual(
            progress["matching_functions"], progress["validated_functions"]
        )
        self.assertGreaterEqual(progress["matching_bytes"], 0)


if __name__ == "__main__":
    unittest.main()
