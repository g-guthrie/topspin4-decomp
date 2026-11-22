import sys, os
sys.path.insert(0, os.path.join(os.getcwd(), "tools"))
import fn_equiv as F
orig = F.compare
done = [False]
N = int(os.environ.get("EQDBG_N", "30"))
def comp(world, A, B, rkind, nonvol=True):
    r = orig(world, A, B, rkind, nonvol)
    if r and not done[0] and r.startswith("call #"):
        done[0] = True
        i = int(r.split("#")[1].split(":")[0]) - 1
        ea, eb = A["events"], B["events"]
        for j in range(max(0, i - N), i + 2):
            def f(e):
                if j >= len(e): return "-"
                return "%s %s" % (world.label(e[j][0])[:28], " ".join("%08x" % (v & 0xffffffff) for v in e[j][1][:4]))
            print("%4d O %-70s | C %s" % (j + 1, f(ea), f(eb)))
    return r
F.compare = comp
_ss = F.Machine._save_slot
def ss(self, x):
    r = _ss(self, x)
    if r and (0x7f0ef800 <= x < 0x7f0efa40) and os.environ.get('EQDBG_SS'):
        d = x & ~7
        print('saveslot', hex(x), bytes(self.stack_buf[d-F.STACK_LO:d-F.STACK_LO+8]).hex(), len(self.events))
    return r
F.Machine._save_slot = ss
_ic = F.Machine._intercept
def ic(self, uc, a):
    k = len(self.events)
    r3 = uc.reg_read(F.P.UC_PPC_REG_3) & 0xffffffff
    _ic(self, uc, a)
    lo = int(os.environ.get('EQDBG_K', '-1'))
    if lo <= k < lo + 12 and F.STACK_LO <= r3 < F.STACK_HI:
        print('K', k, self.w.label(a)[:24], hex(r3), bytes(self.stack_buf[r3-F.STACK_LO:r3-F.STACK_LO+4]).hex(), 'r3ret', hex(uc.reg_read(F.P.UC_PPC_REG_3)&0xffffffff), 'seed', self.seed)
F.Machine._intercept = ic
sys.argv = ["fn_equiv.py"] + sys.argv[1:]
sys.exit(F.main())
