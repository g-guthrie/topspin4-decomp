"""Tests for the C++ rename rule in tools/fn_check.py (pure string logic, no game data)."""

import sys
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "tools"))

from fn_check import renameable_cxx  # noqa: E402


class RenameableCxx(unittest.TestCase):
    def test_vtable_for_label(self):
        self.assertTrue(renameable_cxx("??_7TS4Owner880F4424@@6B@", "lbl_880F4424"))
        self.assertTrue(renameable_cxx("??_7D@@6BBase@@@", "lbl_880F4428"))  # secondary vtable

    def test_vtable_not_for_function(self):
        self.assertFalse(renameable_cxx("??_7TS4Owner880F4424@@6B@", "fn_886B14E0"))

    def test_member_functions_for_fn(self):
        self.assertTrue(renameable_cxx("??1TS4Owner880F4424@@UAA@XZ", "fn_886B14E0"))  # dtor
        self.assertTrue(renameable_cxx("??0TS4SwObj888DDF98@@QAA@XZ", "fn_888DDF98"))  # ctor
        self.assertTrue(renameable_cxx("?get@Foo@@QAAHXZ", "fn_88100000"))

    def test_rejected(self):
        self.assertFalse(renameable_cxx("?count@Foo@@2HA", "lbl_88D00000"))  # static data
        self.assertFalse(renameable_cxx("??_GD@@UAAPAXI@Z", "fn_88100000"))  # special ??_ function
        self.assertFalse(renameable_cxx("??_C@_03ABC@foo?$AA@", "lbl_88000000"))  # string literal
        self.assertFalse(renameable_cxx("?get@Foo@@QAAHXZ", "ts4_named_88100000"))  # target already named
        self.assertFalse(renameable_cxx("plain_c", "fn_88100000"))


if __name__ == "__main__":
    unittest.main()
