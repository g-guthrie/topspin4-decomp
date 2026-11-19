/* 0x883EB180: lazily creates the 0x1c-byte two-base object in lbl_88CAC9AC (heap of lbl_88B3302C, file lbl_88039A20, line 0x426) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); inlined ctors: base vtable lbl_8803978C at +8 then lbl_88039A84/lbl_88039A78, zeroed tail; model 0x883E8F58. */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039A20[];
extern void *lbl_8803978C[];
extern void *lbl_88039A84[];
extern void *lbl_88039A78[];
extern void *lbl_88CAC9AC;
void *fn_88315C60(void *heap, unsigned size, const char *file, int line, int a, int b);
typedef struct D { void **vt0; int f4; void **vt8; int fc; int f10; int f14; int f18; } D;
void *ts4_get_singleton_883EB180(void)
{
    if (!lbl_88CAC9AC) {
        D *d = fn_88315C60(lbl_88B3302C->heap, 0x1c, lbl_88039A20, 0x426, 0, 0);
        if (d) {
            { void ***pv = &d->vt8; *pv = lbl_8803978C; }
            d->f10 = 0;
            d->vt0 = lbl_88039A84;
            d->vt8 = lbl_88039A78;
            d->f14 = 0;
            d->f18 = 0;
        } else {
            d = 0;
        }
        lbl_88CAC9AC = d;
    }
    return lbl_88CAC9AC;
}
