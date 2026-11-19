/* Swing_DLL.xex 0x88384918: sets or clears the loaded bit (+0x11C bit 1) on the owner record and each present linked record
 * (+0x18C when +0x18 is set, +0x300, +0x304, +0x30C, +0x1C), then tail-calls ts4_set_flag_bit5_off24_883AC468. agAE: /Oc. */
typedef struct Rec { char pad[0x11c]; unsigned int flags; } Rec;
typedef struct Obj {
    char pad0[0x18]; void *active; Rec *r1c; char pad20[0x54 - 0x20]; Rec *owner; char pad58[0x18c - 0x58]; Rec *r18c;
    char pad190[0x300 - 0x190]; Rec *r300; Rec *r304; char pad308[4]; Rec *r30c;
} Obj;
void ts4_set_flag_bit5_off24_883AC468(Obj *o, unsigned char unload);
static __inline void rec_set_loaded(Rec *r, unsigned char unload) { if (!unload) r->flags |= 2; else r->flags &= ~2u; }
void fn_88384918(Obj *o, unsigned char unload)
{
    rec_set_loaded(o->owner, unload);
    if (o->active && o->r18c) rec_set_loaded(o->r18c, unload);
    if (o->r300) rec_set_loaded(o->r300, unload);
    if (o->r304) rec_set_loaded(o->r304, unload);
    if (o->r30c) rec_set_loaded(o->r30c, unload);
    if (o->r1c) rec_set_loaded(o->r1c, unload);
    ts4_set_flag_bit5_off24_883AC468(o, unload);
}
