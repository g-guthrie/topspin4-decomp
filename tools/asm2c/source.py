"""Access to original functions: candidate selection and disassembly lines.

Uses tools/xcoff.py (symbols.txt) and tools/fn_asm.py (split objects +
disassembler); nothing here needs the compiler.
"""
import pickle, re, sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parent.parent
ROOT = TOOLS.parent
sys.path.insert(0, str(TOOLS))
from xcoff import load_symbols  # noqa: E402


def parse_exclude(path=ROOT / "work" / "gen_exclude.txt"):
    """Return (set of excluded addresses, list of (lo, hi) excluded ranges).
    Single addresses are lines of hex; ranges are 0xLO-0xHI pairs found in the
    '#' header comment."""
    addrs, ranges = set(), []
    p = Path(path)
    if not p.is_file():
        return addrs, ranges
    for line in p.read_text().splitlines():
        line = line.strip()
        if line.startswith("#"):
            for lo, hi in re.findall(r"0x([0-9A-Fa-f]+)-0x([0-9A-Fa-f]+)", line):
                ranges.append((int(lo, 16), int(hi, 16)))
        elif re.fullmatch(r"(0x)?[0-9A-Fa-f]+", line):
            addrs.add(int(line, 16))
    return addrs, ranges


def candidates(max_size=0x100, prefix="fn_", exclude=None):
    """Unnamed .text functions (name starts with `prefix`) of size <= max_size,
    minus excluded addresses/ranges. Returns sorted [(name, address, size)]."""
    addrs, ranges = exclude if exclude is not None else parse_exclude()
    out = []
    for name, sec, addr, size in load_symbols():
        if sec != ".text" or not name.startswith(prefix) or not size or size > max_size:
            continue
        if addr in addrs or any(lo <= addr < hi for lo, hi in ranges):
            continue
        out.append((name, addr, size))
    return sorted(out, key=lambda x: x[1])


class Disasm:
    """Name -> disassembly lines (fn_asm format), memoised, optional pickle cache.
    Lookup failures return None (the split may predate some renames)."""

    def __init__(self, cache_path=None):
        self.cache_path = cache_path
        self.cache = {}
        if cache_path and Path(cache_path).is_file():
            self.cache = pickle.load(open(cache_path, "rb"))

    def lines(self, name):
        if name in self.cache:
            return self.cache[name]
        import functools, fn_asm
        if not getattr(fn_asm.load_symbols, 'cache_info', None):
            # fn_asm.find_function re-parses symbols.txt on every call; memoise it
            fn_asm.load_symbols = functools.lru_cache(maxsize=None)(fn_asm.load_symbols)
        try:
            _, address, data, relocs = fn_asm.find_function(name)
            res = fn_asm.disassemble(data, address, relocs)
        except (SystemExit, Exception):
            res = None
        self.cache[name] = res
        return res

    def save(self):
        if self.cache_path:
            pickle.dump(self.cache, open(self.cache_path, "wb"))


def symbol_at():
    """address -> .text symbol name, for resolving relocation-free `bl` targets."""
    return {a: n for n, sec, a, _ in load_symbols() if sec == ".text"}
