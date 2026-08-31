import tempfile
import unittest
from pathlib import Path

from tools.select_candidates import load_candidates


class CandidateSelectionTests(unittest.TestCase):
    def test_filters_and_ranks_deterministically(self):
        contents = """entry,name,namespace,source_type,is_thunk,is_external,body_bytes
82000030,FUN_82000030,Global,DEFAULT,false,false,48
82000010,FUN_82000010,Global,DEFAULT,false,false,16
82000020,named,Global,USER_DEFINED,false,false,8
82000040,FUN_82000040,Global,DEFAULT,true,false,4
82000050,FUN_82000050,Global,DEFAULT,false,true,32
"""
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "functions.csv"
            path.write_text(contents, encoding="utf-8")
            candidates = load_candidates(path, minimum_bytes=8, maximum_bytes=64)

        self.assertEqual(
            [candidate.entry for candidate in candidates],
            ["82000010", "82000030", "82000020"],
        )

    def test_applies_size_bounds(self):
        contents = """entry,name,namespace,source_type,is_thunk,is_external,body_bytes
1,FUN_1,Global,DEFAULT,false,false,7
2,FUN_2,Global,DEFAULT,false,false,8
3,FUN_3,Global,DEFAULT,false,false,128
4,FUN_4,Global,DEFAULT,false,false,129
"""
        with tempfile.TemporaryDirectory() as directory:
            path = Path(directory) / "functions.csv"
            path.write_text(contents, encoding="utf-8")
            candidates = load_candidates(path, minimum_bytes=8, maximum_bytes=128)

        self.assertEqual([candidate.entry for candidate in candidates], ["2", "3"])


if __name__ == "__main__":
    unittest.main()
