/* HS2 hand-decompiled functions compiled with /O1 (Swing_DLL.xex 0x885xxxxx). */

typedef struct Hs2Poly {
    void **vtbl;
} Hs2Poly;

/* True when vtbl[0x54]() returns 0, 1 or 2 (the virtual is called again for each comparison). */
int ts4_state_is_0_1_or_2_885AA6E0(Hs2Poly *o)
{
    return ((int (*)(Hs2Poly *))o->vtbl[0x54 / 4])(o) == 0 ||
           ((int (*)(Hs2Poly *))o->vtbl[0x54 / 4])(o) == 1 ||
           ((int (*)(Hs2Poly *))o->vtbl[0x54 / 4])(o) == 2;
}
