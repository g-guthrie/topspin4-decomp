/* Swing_DLL.xex 0x883EECB8-0x883EECF8, executable version 0.0.0.3. */
typedef struct Ts4Ob2X { char pad0[4]; unsigned int len; unsigned int start; } Ts4Ob2X;
extern struct { char pad[4]; void *p; } *lbl_88B3302C;
void *fn_88315F10(void *p);

static unsigned char ts4_inr(Ts4Ob2X *o, unsigned int p)
{
    return p >= o->start && p < o->len + o->start;
}

void *ts4_chk_range_883EECB8(Ts4Ob2X *o, unsigned int p)
{
    if (ts4_inr(o, p))
        return o;
    return fn_88315F10(lbl_88B3302C->p);
}
