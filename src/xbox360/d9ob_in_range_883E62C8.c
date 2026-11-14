/* Swing_DLL.xex 0x883E62C8-0x883E6308, executable version 0.0.0.3. */
typedef struct Ts4Ob2R { unsigned int n; unsigned int base; } Ts4Ob2R;

int ts4_in_range_883E62C8(Ts4Ob2R *o, unsigned int p)
{
    if (p != 0 && p >= o->base && p <= o->base + o->n * 8) {
        if ((p - o->base & 7) == 0)
            return 1;
    }
    return 0;
}
