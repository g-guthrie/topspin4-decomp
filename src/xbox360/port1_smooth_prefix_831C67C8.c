/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l15_smooth_prefix_831C67C8.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
typedef struct { char pad0[0xae]; unsigned short s; char pad1[0x278 - 0xb0]; int mul; } Ts4lSmoothObj;

/* Running smoothing over a buffer: after the initial fill, each element accumulates
 * a rounded, scaled copy of its predecessor. */
extern int ts4_scale_int_array_885D9AA8(int *, int, unsigned);

/* Swing_DLL.xex 0x885C8448 */
int ts4_smooth_prefix_885C8448(Ts4lSmoothObj *o, int a1, int *buf, int a3, int n)
{
    short i;

    (void)a1;
    (void)a3;
    ts4_scale_int_array_885D9AA8(buf, n, o->s);
    if (n > 1) {
        for (i = 1; i < n; i++)
            buf[i] += (buf[i - 1] * o->mul + 0x20) >> 6;
    }
    return 1;
}

