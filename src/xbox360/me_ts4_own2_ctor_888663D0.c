/* 0x888663D0: Own2 controller constructor. Runs the base constructor, sets the vtable, clears the
   six-word block at +0x20, resets the record vector, finalizes the +0x20 block and registers
   the object as the global instance lbl_88D459D4. */
typedef unsigned int u32;
typedef struct Own2Ctl { const void *vt; u32 pad[7]; u32 f20[6]; } Own2Ctl;
extern void *fn_88617D88(void *self);
extern void ts4_own2_reset_88865708(void *o);
extern void ts4_object_finalize(void *p);
extern const char lbl_880E0638[];
extern Own2Ctl *lbl_88D459D4;
Own2Ctl *ts4_own2_ctor_888663D0(Own2Ctl *o)
{
    fn_88617D88(o);
    o->vt = lbl_880E0638;
    { u32 *p = o->f20; p[0] = 0; p[1] = 0; p[2] = 0; p[3] = 0; p[4] = 0; p[5] = 0; }
    ts4_own2_reset_88865708(o);
    ts4_object_finalize(o->f20);
    lbl_88D459D4 = o;
    return o;
}
