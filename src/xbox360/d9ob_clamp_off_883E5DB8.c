/* Swing_DLL.xex 0x883E5DB8-0x883E5DFC, executable version 0.0.0.3. */
typedef struct Ts4Ob2S2 { char pad0[0x18]; unsigned long long lo; unsigned long long hi; char pad28[8]; int mode; } Ts4Ob2S3;

int ts4_clamp_off_883E5DB8(Ts4Ob2S3 *o, unsigned long long x, unsigned long long *out)
{
    unsigned long long v = 0;
    *out = 0;
    if (o->mode == 3) {
        if (x >= o->lo) {
            if (x < o->hi)
                v = x - o->lo;
            else
                v = o->hi - o->lo;
        }
        *out = v;
    }
    return 0;
}
