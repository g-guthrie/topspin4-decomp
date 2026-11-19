/* 0x88317FA8: resolves a handle through ts4_if_set_u32_off0_8832BFC0 and sets or clears bit 0x2 of the object flags at +0x11C; returns the lookup failure code or 0 */
/* Matched on /Oc (agAH). The early return of the lookup result keeps the bne straight to the epilogue. */
typedef struct Obj { char pad[0x11c]; unsigned int flags; } Obj;
extern int ts4_if_set_u32_off0_8832BFC0(void *h, Obj **out);
int fn_88317FA8(void *h, unsigned char on)
{
    Obj *o;
    int hr = ts4_if_set_u32_off0_8832BFC0(h, &o);
    if (hr != 0)
        return hr;
    if (on)
        o->flags |= 2;
    else
        o->flags &= ~2;
    return 0;
}
