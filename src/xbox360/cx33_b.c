/* CX33: small net/lobby/scheduler helpers, Swing_DLL.xex 0x889xxxxx. */
typedef unsigned char u8;
typedef unsigned int u32;

/* ---- net slot owner (layout shared with r6_net_slots.c) ---- */
typedef struct Cx33Slot {
    u8 active;          /* 0x00 */
    u8 pad[0x7f];
} Cx33Slot;
typedef struct Cx33SlotOwner {
    u8 pad0[0x24];
    Cx33Slot slots[4];  /* 0x24 */
    u8 pad_after[0x2d8 - 0x24 - 4 * 0x80];
    u8 b2d8;
} Cx33SlotOwner;
extern void ts4_net_update_slots_88908B80(Cx33SlotOwner *o, u8 a, u8 b);
extern void ts4_if_call_seq_u32_off18_88908710(Cx33SlotOwner *o, Cx33Slot *s);
extern void ts4_if_get_u8_off1f_889087F0(Cx33SlotOwner *o, Cx33Slot *s, int which);

/* 0x88908B38: for each active slot, run the which=0 getter */
void ts4_slots_each_get_88908B38(Cx33SlotOwner *o)
{
    Cx33Slot *s = o->slots;
    u32 n;
    for (n = 4; n != 0; n--, s++) {
        if (s->active)
            ts4_if_get_u8_off1f_889087F0(o, s, 0);
    }
}

/* 0x88908D98: update all slots, run the call-seq on each active one, clear the flag at +0x2d8 */
void ts4_slots_update_and_visit_88908D98(Cx33SlotOwner *o)
{
    Cx33Slot *s;
    u32 n;
    ts4_net_update_slots_88908B80(o, 0, 1);
    s = o->slots;
    for (n = 4; n != 0; n--, s++) {
        if (s->active)
            ts4_if_call_seq_u32_off18_88908710(o, s);
    }
    o->b2d8 = 0;
}

/* 0x88915DC8: raise a high-water mark (signed) from a value in a4 */
typedef struct Cx33Wm4 { u8 pad[0x2d4]; int w2d4; } Cx33Wm4;
typedef struct Cx33Wm { u8 pad0[4]; Cx33Wm4 *p4; u8 pad8[0x10]; int w18; u8 b1c; } Cx33Wm;
typedef struct Cx33Src { u8 pad[0x42c]; int w42c; } Cx33Src;
typedef struct Cx33Flag { u8 pad[0x38]; u8 b38; } Cx33Flag;
void ts4_raise_high_water_88915DC8(Cx33Wm *w, Cx33Src *src, Cx33Flag *f)
{
    if (f->b38 != 1)
        return;
    if (w->b1c == 0) {
        if (src->w42c > w->p4->w2d4)
            w->p4->w2d4 = src->w42c;
    } else {
        if (src->w42c > w->w18)
            w->w18 = src->w42c;
    }
}
