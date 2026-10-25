"""Small, isolated tests for matching.py's provenance receipt writer.

These tests create tiny stand-in files. They never invoke Jeff, a compiler, or
objdiff, and they do not treat the receipt as proof of code equality.
"""

import json
import tempfile
import unittest
from pathlib import Path
from unittest.mock import patch

from tools import matching


class ReproductionReceiptTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name) / "repo"
        self.work = Path(self.temp.name) / "work"
        self.work.mkdir()
        self.source_name = "src/xbox360/matched/tiny.c"
        self.source = self.root / self.source_name
        self.header = self.root / "src/xbox360/tiny.h"
        self.source.parent.mkdir(parents=True)
        self.header.write_bytes(b"/* header */\n")
        self.source.write_bytes(b'#include "../tiny.h"\nint fn_88000000(void){return 0;}\n')
        self.units = ({"source": self.source_name, "object": "tiny.obj",
                       "symbols": {"fn_88000000": 8}, "extra_flags": ["/O1"]},)
        self.tools = Path(self.temp.name) / "tools"
        self.tools.mkdir()
        self.paths = {name: self.tools / name for name in
                      ("retail.xex", "jeff.exe", "cl.exe", "objdiff.exe", "wrapper.exe")}
        for name, path in self.paths.items():
            path.write_bytes(name.encode())
        self.companion = self.tools / "compiler.dll"
        self.companion.write_bytes(b"compiler companion")
        self.object = self.work / "rebuilt/tiny.obj"
        self.object.parent.mkdir()
        self.object.write_bytes(b"COFF fixture bytes")
        self.project = self.work / "objdiff-project/objdiff.json"
        self.report = self.project.parent / "report.json"
        self.project.parent.mkdir()
        self.project.write_bytes(b'{"project":true}\n')
        self.report.write_bytes(b'{"report":true}\n')
        self.root_patch = patch.object(matching, "ROOT", self.root)
        self.units_patch = patch.object(matching, "MATCHING_UNITS", self.units)
        self.root_patch.start()
        self.units_patch.start()
        self.addCleanup(self.units_patch.stop)
        self.addCleanup(self.root_patch.stop)
        self.inputs = matching.reproduction_inputs(
            self.paths["retail.xex"], self.paths["jeff.exe"], self.paths["cl.exe"],
            self.paths["objdiff.exe"], self.paths["wrapper.exe"])

    def write(self):
        matching.write_reproduction_receipt(
            self.work, self.inputs, {self.source_name: self.object})

    def test_complete_bindings(self):
        self.write()
        inputs = json.loads((self.work / "INPUTS.json").read_text())
        receipt = json.loads((self.work / "REPRODUCTION-RECEIPT.json").read_text())
        self.assertEqual(inputs, self.inputs)
        self.assertEqual(inputs["repo_files_sha256"][self.source_name], matching.sha256(self.source))
        self.assertEqual(inputs["repo_files_sha256"]["src/xbox360/tiny.h"], matching.sha256(self.header))
        self.assertEqual(inputs["pins"]["compiler"]["sha256"], matching.sha256(self.paths["cl.exe"]))
        self.assertEqual(inputs["compiler_companions_sha256"]["compiler.dll"], matching.sha256(self.companion))
        self.assertEqual(receipt["source_object_bindings"], [{
            "source": self.source_name, "source_sha256": matching.sha256(self.source),
            "extra_flags": ["/O1"], "object": "rebuilt/tiny.obj", "object_sha256": matching.sha256(self.object)}])
        self.assertEqual(receipt["objdiff_project_sha256"], matching.sha256(self.project))
        self.assertEqual(receipt["objdiff_report_sha256"], matching.sha256(self.report))

    def test_changed_source_rejected(self):
        self.source.write_bytes(b"changed")
        with self.assertRaisesRegex(SystemExit, "source/header changed"):
            self.write()

    def test_changed_header_rejected(self):
        self.header.write_bytes(b"changed")
        with self.assertRaisesRegex(SystemExit, "source/header changed"):
            self.write()

    def test_changed_tool_rejected(self):
        self.paths["cl.exe"].write_bytes(b"changed")
        with self.assertRaisesRegex(SystemExit, "private tool/input changed"):
            self.write()

    def test_changed_companion_rejected(self):
        self.companion.write_bytes(b"changed")
        with self.assertRaisesRegex(SystemExit, "compiler companion changed"):
            self.write()

    def test_duplicate_receipt_refused(self):
        self.write()
        before = (self.work / "REPRODUCTION-RECEIPT.json").read_bytes()
        with self.assertRaises(FileExistsError):
            self.write()
        self.assertEqual((self.work / "REPRODUCTION-RECEIPT.json").read_bytes(), before)

    def test_added_companion_rejected(self):
        """A new DLL after the snapshot is currently absent from the receipt."""
        (self.tools / "new_backend.dll").write_bytes(b"new companion")
        with self.assertRaises(SystemExit):
            self.write()


if __name__ == "__main__":
    unittest.main()
