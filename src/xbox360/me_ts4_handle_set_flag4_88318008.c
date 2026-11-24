/* 0x88318008: twin of 88317FA8 for bit 0x4 */
/* Matched on /Oc (agAH).  */
typedef struct Obj { char pad[0x11c]; unsigned int flags; } Obj;
extern int ts4_if_set_u32_off0_8832BFC0(void *h, Obj **out);
int fn_88318008(void *h, unsigned char on)
{
    Obj *o;
    int hr = ts4_if_set_u32_off0_8832BFC0(h, &o);
    if (hr != 0)
        return hr;
    if (on)
        o->flags |= 4;
    else
        o->flags &= ~4;
    return 0;
}
