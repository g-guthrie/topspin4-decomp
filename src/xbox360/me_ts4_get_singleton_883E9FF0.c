/* 0x883E9FF0: lazily creates the 0x28-byte two-base object in lbl_88CAC9C0 (heap of lbl_88B3302C, file lbl_88039A20, line 0x91b) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); inlined ctors: base vtable lbl_8803978C at +8 then lbl_880399E8/lbl_880399DC, zeroed tail; model 0x883E8F58. */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039A20[];
extern void *lbl_8803978C[];
extern void *lbl_880399E8[];
extern void *lbl_880399DC[];
extern void *lbl_88CAC9C0;
void *fn_88315C60(void *heap, unsigned size, const char *file, int line, int a, int b);
typedef struct D { void **vt0; int f4; void **vt8; int fc; int f10; int f14; int f18; int x0; int x1; int x2; } D;
void *ts4_get_singleton_883E9FF0(void)
{
    if (!lbl_88CAC9C0) {
        D *d = fn_88315C60(lbl_88B3302C->heap, 0x28, lbl_88039A20, 0x91b, 0, 0);
        if (d) {
            { void ***pv = &d->vt8; *pv = lbl_8803978C; }
            d->f10 = 0;
            d->vt0 = lbl_880399E8;
            d->vt8 = lbl_880399DC;
            d->f14 = 0;
            d->f18 = 0;
            d->x0 = 0;
            d->x1 = 0;
            d->x2 = 0;
        } else {
            d = 0;
        }
        lbl_88CAC9C0 = d;
    }
    return lbl_88CAC9C0;
}
