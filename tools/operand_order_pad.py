#!/usr/bin/env python3
"""operand_order_pad.py SRC FUNC MAPPING NMAX [--flags ...] [--marker TEXT]
Insert `int op1_padK = 0` declarations (K < N) after MARKER (default: first '{' after FUNC's definition)
for N = 0..NMAX and run fn_check; print the diff count for each N."""
import re, subprocess, sys
from pathlib import Path
ROOT = Path(__file__).resolve().parents[1]
src, func, mapping, nmax = sys.argv[1], sys.argv[2], sys.argv[3], int(sys.argv[4])
rest = sys.argv[5:]
marker = None
if "--marker" in rest:
    i = rest.index("--marker"); marker = rest[i+1]; rest = rest[:i] + rest[i+2:]
text = Path(src).read_text()
if marker:
    pos = text.index(marker) + len(marker)
else:
    m = re.search(re.escape(func) + r"\s*\([^;{]*\)\s*\{", text)
    pos = m.end()
out = Path(src).with_name("op1pad_" + Path(src).name)
for n in range(nmax + 1):
    pad = (" int " + ", ".join(f"op1_pad{k} = 0" for k in range(n)) + ";") if n else ""
    out.write_text(text[:pos] + pad + text[pos:])
    r = subprocess.run([sys.executable, str(ROOT/"tools/fn_check.py"), str(out), mapping, *rest], capture_output=True, text=True)
    first = (r.stdout.strip().splitlines() or ["?"])
    status = next((l for l in first if l.startswith(("MATCH", "FAIL", "OK"))), first[-1])
    print(n, r.returncode, status[:150], flush=True)
