/* Loader_DLL.xex 0x833E6648-0x833E671C, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _fpclass. */
extern int fn_833E8CD0(double x);
extern double lbl_8300C968;

int ts4l_crt_fpclass_833E6648(double x)
{
    unsigned short *s = (unsigned short *)&x;
    unsigned *u = (unsigned *)&x;
    unsigned ex, neg;
    int t, r;
    ex = s[0] & 0x7ff0;
    if (ex == 0x7ff0) {
        t = fn_833E8CD0(x);
        switch (t) {
        case 1: r = 0x200; break;
        case 2: r = 4; break;
        default: r = (t == 3) + 1; break;
        }
    } else {
        neg = s[0] & 0x8000;
        if (ex == 0 && ((u[0] & 0xfffff) != 0 || u[1] != 0)) {
            r = neg ? 0x10 : 0x80;
        } else if (x == lbl_8300C968) {
            r = neg ? 0x20 : 0x40;
        } else {
            r = neg ? 8 : 0x100;
        }
    }
    return r;
}
