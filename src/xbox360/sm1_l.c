/* SM1 batch l (default /O2). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

/* Store a scalar into the value cell of a property record: the cell is either inline (+0xc) or external (+0xc pointer),
 * unless the record carries a custom writer (flag 0x10), which is called instead. The record is marked dirty (bit 0 of +8). */
typedef struct Ts4PropRecord { char pad[8]; u8 flags; char pad2[3]; char *external; void (*writer)(void *, int, void *); } Ts4PropRecord;
typedef struct Ts4PropOwner { Ts4PropRecord *rec; } Ts4PropOwner;
#define WRITE_PROP(NAME, TY) \
    void NAME(Ts4PropOwner *t, void *v, int c) { \
        Ts4PropRecord *q = t->rec; \
        u32 fl = q->flags; \
        char *dst; \
        if (fl & 0x10) { q->writer(t, c, v); return; } \
        if (fl & 0x20) dst = q->external; else dst = (char *)q + 0xc; \
        *(TY *)dst = *(TY *)v; \
        *(u32 *)((char *)t->rec + 8) |= 1; \
    }
/* Swing_DLL.xex 0x881C7E70 */
WRITE_PROP(ts4_write_prop_u8_881C7E70, u8)
/* 0x881C8010 */
WRITE_PROP(ts4_write_prop_u16_881C8010, u16)
/* 0x881C8108 */
WRITE_PROP(ts4_write_prop_u32_881C8108, u32)

/* 0x88318068: fetch an object through the lookup helper and call its vtable slot 10 with an int and a float */
typedef struct Ts4VObj8 { int (**vt)(); } Ts4VObj8;
extern int ts4_if_set_u32_off0_8832BFC0(void *, Ts4VObj8 **);
int ts4_lookup_and_call_slot10_88318068(void *t, int a, float f) { Ts4VObj8 *o; int r = ts4_if_set_u32_off0_8832BFC0(t, &o); if (r == 0) r = ((int (*)(Ts4VObj8 *, int, float))o->vt[10])(o, a, f); return r; }
