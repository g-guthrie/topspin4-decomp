/* Swing_DLL.xex 0x88384A00: reports *idle = 1 when the owner record (+0x54) or any present linked record (+0x18c when +0x18 is
 * set, +0x300, +0x30C, +0x1C) has its loaded bit (+0x11C bit 1) clear; otherwise defers to ts4_if_get_u32_off24_883AC490. agAD: /O1. */
typedef struct Rec { char pad[0x11c]; unsigned int flags; } Rec;
typedef struct Obj {
    char pad0[0x18]; void *active; Rec *r1c; char pad20[0x54 - 0x20]; Rec *owner; char pad58[0x18c - 0x58]; Rec *r18c;
    char pad190[0x300 - 0x190]; Rec *r300; char pad304[8]; Rec *r30c;
} Obj;
int ts4_if_get_u32_off24_883AC490(Obj *o, unsigned char *idle);
static __inline unsigned char rec_loaded(const Rec *r) { return (unsigned char)((r->flags >> 1) & 1); }

int fn_88384A00(Obj *o, unsigned char *idle)
{
    if (!rec_loaded(o->owner)) { *idle = 1; return 0; }
    if (o->active && o->r18c && !rec_loaded(o->r18c)) { *idle = 1; return 0; }
    if (o->r300 && !rec_loaded(o->r300)) { *idle = 1; return 0; }
    if (o->r30c && !rec_loaded(o->r30c)) { *idle = 1; return 0; }
    if (o->r1c && !rec_loaded(o->r1c)) { *idle = 1; return 0; }
    return ts4_if_get_u32_off24_883AC490(o, idle);
}
