/* Loader_DLL.xex 0x8336F3A0-0x8336F4AC, executable version 0.0.0.3. */
/* Pick one of four callbacks from two mode flags and pass it the matching field set. */
struct Ts4lSel;
typedef int (*Ts4lCb)();
typedef struct Ts4lSel {
    int pad0[3];
    int modeA;
    int modeB;
    int f14, f18, f1c, f20, f24, f28, f2c, f30;
    int pad34[8];
    int f54;
    char pad58[0x393c - 0x58];
    Ts4lCb cb393c;
    Ts4lCb cb3940;
    Ts4lCb cb3944;
    Ts4lCb cb3948;
} Ts4lSel;
int ts4l_select_cb_8336F3A0(Ts4lSel *p)
{
    if (p->modeA == 0) {
        if (p->modeB == 0)
            return p->cb393c(p->f14, p->f24, 0, p->f54, p);
        return p->cb3940(p->f14, p->f28, p->f2c, p->f30, 0, p->f54, p);
    }
    if (p->modeB == 0)
        return p->cb3948(p->f24, p->f18, p->f1c, p->f20, 0, p->f54, p);
    return p->cb3944(p->f18, p->f1c, p->f20, p->f28, p->f2c, p->f30, 0, p->f54, p);
}
