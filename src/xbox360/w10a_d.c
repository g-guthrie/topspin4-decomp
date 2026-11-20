/* W10A: zlib compress-style wrapper: deflateInit2, deflate(Z_FINISH), deflateEnd (Swing_DLL.xex 0x889C0AE0). Plain route, /Oc. */
extern char lbl_880DFA20[];
typedef struct A4O { unsigned char pad[0x14]; unsigned w14; unsigned pad18, pad1c; unsigned w20, w24, w28; } A4O;
extern int ex3_deflateInit2__88877400(A4O *o, int a, int b, int c, int d, int e, void *f, int g);
extern int fn_88876730(A4O *o, int a);
extern int ex3_deflateEnd_88876438(A4O *o);
int ts4_deflate_finish_889C0AE0(unsigned *out, A4O *o)
{
    int err;
    o->w20 = 0;
    o->w24 = 0;
    o->w28 = 0;
    err = ex3_deflateInit2__88877400(o, -1, 8, 15, 8, 0, lbl_880DFA20, 0x38);
    if (err != 0) return err;
    err = fn_88876730(o, 4);
    if (err != 1) {
        ex3_deflateEnd_88876438(o);
        return err == 0 ? -5 : err;
    }
    *out = o->w14;
    return ex3_deflateEnd_88876438(o);
}
