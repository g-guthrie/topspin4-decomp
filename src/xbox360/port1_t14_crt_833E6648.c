/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l29_t14_crt_833E6648.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Statically linked MSVC CRT: _fpclass. */

extern int fn_8856E7F8(double x);
extern double lbl_880038D8;

/* Swing_DLL.xex 0x885636E8 */
int ts4_crt_fpclass_885636E8(double x)
{
    unsigned short *s = (unsigned short *)&x;
    unsigned *u = (unsigned *)&x;
    unsigned ex, neg;
    int t, r;
    ex = s[0] & 0x7ff0;
    if (ex == 0x7ff0) {
        t = fn_8856E7F8(x);
        switch (t) {
        case 1: r = 0x200; break;
        case 2: r = 4; break;
        default: r = (t == 3) + 1; break;
        }
    } else {
        neg = s[0] & 0x8000;
        if (ex == 0 && ((u[0] & 0xfffff) != 0 || u[1] != 0)) {
            r = neg ? 0x10 : 0x80;
        } else if (x == lbl_880038D8) {
            r = neg ? 0x20 : 0x40;
        } else {
            r = neg ? 8 : 0x100;
        }
    }
    return r;
}

