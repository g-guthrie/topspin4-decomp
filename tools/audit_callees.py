#!/usr/bin/env python3
"""Audit branch/call targets in matched Swing units against the original binary.

objdiff (and tools/fn_check.py) mask relocated fields and treat a relocation
whose symbol name differs from the target's as a rename, so a source that
calls the wrong fn_XXXXXXXX still reports MATCH. This script closes the gap.

For every function in tools/matching.py MATCHING_UNITS (LTCG units are
skipped: tools/ltcg_route.py rebuilds them from the split target object, so
their relocations carry the original names, and it fails on renames) it reads the rebuilt object from the
matching build (work/matching-bNNN/rebuilt/<object>), and for each REL24 or
REL14 relocation in the function compares:
  * the relocation symbol, resolved to an address by its 8-hex suffix
    (fn_XXXXXXXX, foo_XXXXXXXX) or else by its name in symbols.txt, with
  * the original branch target at the same instruction offset, from a pickled
    per-address disassembly (default work/army/VX1/textdis.pkl, entries like
    'bl 0x268558 -> 0x007bb340', targets relative to the instruction).
Symbols that resolve to no address (runtime helpers, unnamed locals) are
counted as unresolved and skipped. Standard library only.

usage: python3 tools/audit_callees.py --build work/matching-b163 [--dis PKL] [--json OUT]
"""
import argparse, importlib.util, json, pickle, re, sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))
from xcoff import demangle_base, read_coff  # noqa: E402

BRANCH = re.compile(r"(b|bl|bc\w*|b[a-z]+)\s+(?:cr\d,\s*)?(-?0x[0-9a-f]+) ->")


def load_units():
    spec = importlib.util.spec_from_file_location("matching", ROOT / "tools/matching.py")
    m = importlib.util.module_from_spec(spec); spec.loader.exec_module(m)
    # LTCG units are skipped: tools/ltcg_route.py writes their rebuilt object as the
    # split target object (original relocation names), and the route fails on renames.
    return list(m.MATCHING_UNITS)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--build", default=str(ROOT / "work/matching-b163"))
    ap.add_argument("--dis", default=str(ROOT / "work/army/VX1/textdis.pkl"))
    ap.add_argument("--verbose", action="store_true", help="list unresolved relocations")
    ap.add_argument("--json", help="write mismatches as JSON")
    a = ap.parse_args()
    dis = pickle.load(open(a.dis, "rb"))
    sym = {}
    for line in open(ROOT / "config/54540859/symbols.txt"):
        mo = re.match(r"(\S+)\s*=\s*\.text:0x([0-9A-Fa-f]{8});.*?size:0x([0-9A-Fa-f]+)", line)
        if mo:
            sym[mo.group(1)] = (int(mo.group(2), 16), int(mo.group(3), 16))
    name_of = {}
    for k, v in sym.items():
        name_of.setdefault(v[0], k)

    def resolve(name):
        if name in sym:
            return sym[name][0]
        base = demangle_base(name)
        hx = re.search(r"([0-9A-Fa-f]{8})$", base)
        if hx and int(hx.group(1), 16) >= 0x82000000:
            return int(hx.group(1), 16)
        return sym[base][0] if base in sym else None

    stats = dict(sources=0, functions=0, relocs=0, unresolved=0, missing_obj=0)
    bad = []
    for u in load_units():
        obj = Path(a.build) / "rebuilt" / u["object"]
        if not obj.exists():
            stats["missing_obj"] += 1
            continue
        coff = read_coff(obj); stats["sources"] += 1
        for fname in u.get("symbols", {}):
            if fname not in sym or sym[fname][0] not in dis:
                continue
            A, size = sym[fname]
            try:
                _, relocs = coff.function(fname, size)
            except KeyError:
                continue
            ins = dis[A]; stats["functions"] += 1
            for r in relocs:
                if r.kind not in (0x6, 0x7):
                    continue
                k = r.offset // 4
                mo = BRANCH.match(ins[k]) if k < len(ins) else None
                if not mo:
                    continue
                stats["relocs"] += 1
                orig = A + 4 * k + int(mo.group(2), 16)
                got = resolve(r.symbol)
                if got is None:
                    stats["unresolved"] += 1
                    if a.verbose:
                        print("unresolved", fname, r.symbol, "0x%08X" % orig, file=sys.stderr)
                    continue
                if got != orig:
                    bad.append(dict(source=u["source"], function=fname, offset=r.offset,
                                    source_callee=demangle_base(r.symbol),
                                    original=name_of.get(orig, "fn_%08X" % orig),
                                    original_addr="0x%08X" % orig))
    for b in bad:
        print(f"{b['source']}: {b['function']}+0x{b['offset']:X} calls {b['source_callee']}, "
              f"original {b['original']} ({b['original_addr']})")
    print(f"{stats} mismatches={len(bad)}", file=sys.stderr)
    if a.json:
        Path(a.json).write_text(json.dumps(bad, indent=1))
    return 1 if bad else 0


if __name__ == "__main__":
    sys.exit(main())
