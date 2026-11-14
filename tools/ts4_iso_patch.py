#!/usr/bin/env python3
"""Produce a patched, extracted game folder (or just the replaced .arc files) for Xenia.

The disc image is only ever READ.  Output goes to a new directory under work/ (anything
else is refused).  Two modes:

  --only-arcs   copy just the replacement archives into OUT/ (tiny; drop them over the
                matching files of an extracted game folder yourself)
  (default)     extract every file of the disc into OUT/ (about 5.7 GB for the retail
                disc; $SystemUpdate/ is skipped unless --with-system-update), using the
                replacement archive wherever one is given

  python3 tools/ts4_iso_patch.py ISO OUT --arc Core.arc=work/patched/Core.arc
  python3 tools/ts4_iso_patch.py ISO OUT --arc Core.arc=work/patched/Core.arc --only-arcs
  python3 tools/ts4_iso_patch.py ISO OUT --arc Core.arc=... --dry-run

Then point Xenia at OUT/default.xex (see docs/data-patching.md).  Standard library only.
"""
import argparse
import os
import shutil
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import xdvdfs  # noqa: E402

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
LIMIT = 10 * 1024 ** 3
CHUNK = 1 << 22


def check_out_dir(out):
    out = os.path.realpath(out)
    work = os.path.realpath(os.path.join(ROOT, "work"))
    if os.path.commonpath([out, work]) != work or out == work:
        raise SystemExit("refusing: output must be a new directory under %s" % work)
    if os.path.exists(out) and os.listdir(out):
        raise SystemExit("refusing: %s exists and is not empty" % out)
    return out


def copy_from_iso(x, entry, dst):
    remaining = entry["size"]
    x.f.seek(x.base + entry["sector"] * xdvdfs.SECTOR)
    os.makedirs(os.path.dirname(dst), exist_ok=True)
    with open(dst, "wb") as o:
        while remaining:
            chunk = x.f.read(min(remaining, CHUNK))
            if not chunk:
                raise IOError("short read from image")
            o.write(chunk)
            remaining -= len(chunk)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("iso")
    ap.add_argument("out", help="new directory under work/")
    ap.add_argument("--arc", action="append", default=[], metavar="NAME=FILE",
                    help="use FILE in place of the disc file NAME (path inside the image)")
    ap.add_argument("--only-arcs", action="store_true")
    ap.add_argument("--with-system-update", action="store_true")
    ap.add_argument("--dry-run", action="store_true")
    a = ap.parse_args()

    iso = os.path.realpath(a.iso)
    out = check_out_dir(a.out)
    if out == iso or out.startswith(iso + os.sep):
        raise SystemExit("refusing: output overlaps the disc image")
    x = xdvdfs.XDVDFS(iso)
    repl = {}
    for spec in a.arc:
        name, _, fn = spec.partition("=")
        if not fn or not os.path.isfile(fn):
            raise SystemExit("--arc needs NAME=FILE with an existing FILE: %r" % spec)
        e = x.find(name)                      # raises FileNotFoundError if absent
        repl[name.replace("\\", "/").strip("/").lower()] = (os.path.realpath(fn), e)
    files = [(p, e) for p, e in x.walk() if not e["attr"] & 0x10]
    if not a.with_system_update:
        files = [(p, e) for p, e in files if not p.startswith("$SystemUpdate/")]
    names = {p.lower() for p, _ in files}
    for k in repl:
        if k not in names:
            raise SystemExit("replacement target %r is not a file in the image" % k)

    if a.only_arcs:
        real = {p.lower(): p for p, _ in files}
        plan = [(real[k], os.path.getsize(v[0]), v[0]) for k, v in repl.items()]
    else:
        plan = []
        for p, e in files:
            r = repl.get(p.lower())
            plan.append((p, os.path.getsize(r[0]) if r else e["size"], r[0] if r else None))
    total = sum(s for _p, s, _f in plan)
    free = shutil.disk_usage(os.path.dirname(out) if os.path.isdir(os.path.dirname(out)) else ROOT).free
    print("%d files, %.2f GB to write, %.1f GB free" % (len(plan), total / 1e9, free / 1e9))
    if total > LIMIT:
        raise SystemExit("refusing: %.1f GB exceeds the 10 GB limit" % (total / 1e9))
    if total > free - (2 << 30):
        raise SystemExit("refusing: not enough free disk space")
    if a.dry_run:
        for p, s, f in plan:
            if f or a.only_arcs:
                print("  replace %s <- %s (%d bytes)" % (p, f, s))
        return 0
    os.makedirs(out, exist_ok=True)
    ents = {p: e for p, e in files}
    for p, s, f in plan:
        dst = os.path.join(out, *p.split("/"))
        if f:
            os.makedirs(os.path.dirname(dst), exist_ok=True)
            shutil.copyfile(f, dst)
        else:
            copy_from_iso(x, ents[p], dst)
    print("wrote %s" % out)
    return 0


if __name__ == "__main__":
    sys.exit(main())
