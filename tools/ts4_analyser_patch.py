#!/usr/bin/env python3
"""Patch curve keys and CONST values of analyser graphs in an Expressions.bin buffer.

Rewrites floats in place (the file size and every offset stay the same), then validates by
re-parsing the result with tools/ts4_analyser.py, checking that only the intended 4-byte
words changed, and re-evaluating each patched graph before and after.

Patch file (JSON).  Graph keys are a graph name ("ShotDifficulty"), an 8-digit hex hash,
or "#N" for the N-th graph in file order.  Node keys are node indexes within the graph.

  {
    "ShotDifficulty": {
      "3": {"value": 0.25},                          // CONST node: new value
      "5": {"keys": {"0": {"y0": 0.1, "slope": 0.5}, // CURVE node: per-key fields
                     "2": {"x0": 1.0, "x1": 2.0, "y0": 0.0, "slope": 1.0}}}
    },
    "1c2d3e4f": {"7": {"keys": [{"y0": 1.0}, {}, {"slope": 2.0}]}}   // list form: index = position
  }

CURVE key fields: x0, x1 (segment start and end), y0 (value at x0), slope (word +0xC), y1
(word +0x10, value at x1).  Only CONST and CURVE nodes are patchable.

Curve semantics (docs/gameplay/graphs-decoded.md): at load the game overwrites every key's slope
word with (y1-y0)/(x1-x0) (fn_88179740), so on the real game a curve is a ramp y0 -> y1 and a
patched `slope` has no effect: patch `y1` instead.  By default the re-evaluation uses that runtime
reading; `--disc-slopes` (fixup=False) evaluates with the slope words as stored on disc.

  python3 tools/ts4_analyser_patch.py Expressions.bin patch.json OUT.bin [--probe 0.5]
"""
import argparse
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import ts4_analyser as A  # noqa: E402

KEY_FIELDS = {"x0": 0, "x1": 4, "y0": 8, "slope": 12, "y1": 16}


def resolve_graph(graphs, spec):
    if spec.startswith("#"):
        i = int(spec[1:])
        if not 0 <= i < len(graphs):
            raise KeyError("graph index %d out of range" % i)
        return i
    if len(spec) == 8 and all(c in "0123456789abcdefABCDEF" for c in spec):
        h = int(spec, 16)
        hits = [i for i, g in enumerate(graphs) if g.name == h]
        if not hits and spec.isalpha():
            h = A.crc(spec)
            hits = [i for i, g in enumerate(graphs) if g.name == h]
    else:
        h = A.crc(spec)
        hits = [i for i, g in enumerate(graphs) if g.name == h]
    if not hits:
        raise KeyError("no graph %r" % spec)
    if len(hits) > 1:
        raise KeyError("graph %r matches %d graphs (%s); use #N" % (spec, len(hits), hits))
    return hits[0]


def _key_items(spec):
    if isinstance(spec, dict):
        return [(int(i), v) for i, v in spec.items()]
    return [(i, v) for i, v in enumerate(spec)]


def plan(buf, patch, fixup=True):
    """Return (graphs, edits) where edits is [(file_offset, new_float, description)]."""
    graphs = A.parse_expressions(buf, fixup=fixup)
    edits = []
    for gspec, nodes in patch.items():
        gi = resolve_graph(graphs, gspec)
        g = graphs[gi]
        for nspec, change in nodes.items():
            ni = int(nspec)
            if not 0 <= ni < len(g.nodes):
                raise KeyError("graph %s has no node %d" % (gspec, ni))
            n = g.nodes[ni]
            tag = "%s[%d]" % (gspec, ni)
            if n.kind == "CONST":
                if set(change) - {"value"}:
                    raise ValueError("%s: a CONST node only has 'value'" % tag)
                if "value" in change:
                    edits.append((n.offset + 4, float(change["value"]), tag + ".value"))
            elif n.kind == "CURVE":
                if set(change) - {"keys"}:
                    raise ValueError("%s: a CURVE node only has 'keys'" % tag)
                arr, cnt = A.read_array(buf, n.offset, A.CURVE_KEY_STRIDE)
                for ki, fields in _key_items(change.get("keys", {})):
                    if not 0 <= ki < cnt:
                        raise KeyError("%s: curve has %d keys, no key %d" % (tag, cnt, ki))
                    for fname, val in fields.items():
                        if fname not in KEY_FIELDS:
                            raise ValueError("%s key %d: unknown field %r" % (tag, ki, fname))
                        edits.append((arr + A.CURVE_KEY_STRIDE * ki + KEY_FIELDS[fname], float(val),
                                      "%s.keys[%d].%s" % (tag, ki, fname)))
            else:
                raise ValueError("%s: node kind %s is not patchable" % (tag, n.kind))
    seen = {}
    for off, val, d in edits:
        if off in seen and seen[off] != val:
            raise ValueError("conflicting edits for %s" % d)
        seen[off] = val
    return graphs, edits


def _probe_eval(g, v):
    try:
        return A.evaluate(g, [v] * len(g.inputs))
    except (ValueError, ZeroDivisionError, IndexError):
        return None


def patch_expressions(buf, patch, probe=(0.0, 0.5, 1.0), fixup=True):
    """Apply `patch` to a copy of `buf`.  Returns (new_bytes, report dict).

    Raises ValueError/AssertionError if the patched image fails validation."""
    graphs, edits = plan(buf, patch, fixup)
    out = bytearray(buf)
    for off, val, _d in edits:
        struct.pack_into(">f", out, off, val)
    out = bytes(out)
    assert len(out) == len(buf)
    # 1. only the intended words changed
    allowed = {off for off, _v, _d in edits}
    changed = [i for i in range(len(buf)) if buf[i] != out[i]]
    stray = [i for i in changed if (i & ~3) not in allowed]
    if stray:
        raise AssertionError("unexpected bytes changed at %s" % [hex(i) for i in stray[:8]])
    # 2. re-parse: same structure, patched values read back
    new_graphs = A.parse_expressions(out, fixup=fixup)
    assert len(new_graphs) == len(graphs)
    for g0, g1 in zip(new_graphs, graphs):
        assert g0.name == g1.name and g0.nregs == g1.nregs and len(g0.nodes) == len(g1.nodes)
        assert [n.kind for n in g0.nodes] == [n.kind for n in g1.nodes]
        assert not A.validate_graph(g0) or A.validate_graph(g0) == A.validate_graph(g1)
    for off, val, d in edits:
        got = struct.unpack_from(">f", out, off)[0]
        assert got == A.f32(val), "%s reads back %r" % (d, got)
    # 3. re-evaluate patched graphs before and after
    touched = sorted({resolve_graph(graphs, g) for g in patch})
    evals = []
    for gi in touched:
        for v in probe:
            evals.append(dict(graph="%08x" % graphs[gi].name, input=v,
                              before=_probe_eval(graphs[gi], v), after=_probe_eval(new_graphs[gi], v)))
    return out, dict(edits=[(hex(o), v, d) for o, v, d in edits], words_changed=len(allowed),
                     evaluations=evals)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("expressions")
    ap.add_argument("patch")
    ap.add_argument("out", help="output file (write under work/)")
    ap.add_argument("--probe", type=float, action="append",
                    help="input value used for every input port in the before/after evaluation (repeatable)")
    ap.add_argument("--disc-slopes", action="store_true",
                    help="evaluate with the on-disc slope words (the runtime recomputes them from y1)")
    a = ap.parse_args()
    if os.path.abspath(a.out) == os.path.abspath(a.expressions):
        ap.error("refusing to overwrite the input")
    buf = open(a.expressions, "rb").read()
    patch = json.load(open(a.patch))
    out, rep = patch_expressions(buf, patch, tuple(a.probe) if a.probe else (0.0, 0.5, 1.0),
                                 fixup=not a.disc_slopes)
    os.makedirs(os.path.dirname(os.path.abspath(a.out)), exist_ok=True)
    open(a.out, "wb").write(out)
    for off, val, d in rep["edits"]:
        print("  %s  %s = %r" % (off, d, val))
    for e in rep["evaluations"]:
        print("  eval %s in=%s before=%s after=%s" % (e["graph"], e["input"], e["before"], e["after"]))
    print("wrote %s (%d bytes, %d words changed)" % (a.out, len(out), rep["words_changed"]))


if __name__ == "__main__":
    main()
