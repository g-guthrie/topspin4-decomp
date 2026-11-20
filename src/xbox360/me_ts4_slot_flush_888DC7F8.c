/* 0x888DC7F8: optionally set the slot value, then flush slot i (of 4, 0x3c bytes at +0x1c) when both of its vectors are non-empty and the slot check passes (agAY). Plain /Oc. */
typedef unsigned char u8;
typedef struct PVec { void *first; void *last; } PVec;
typedef struct Slot { u8 pad0[0xc]; PVec a; int pad14; PVec b; u8 pad20[0x14]; int x34; int pad38; } Slot;
typedef struct Mgr { u8 pad0[0x1c]; Slot slots[4]; u8 pad10c[0x50]; u8 enabled; } Mgr;
static u8 slot_pending(Slot *s) { return s->a.first != s->a.last && s->b.first != s->b.last; }
u8 fn_888D4EF8(Slot *s);
void fn_888DC5E8(Mgr *o, Slot *s, int a, int b);
void ts4_slot_flush_888DC7F8(Mgr *o, int i, int a, int b, int v)
{
    Slot *s;
    if (!o->enabled) return;
    s = &o->slots[i];
    if (v != -1) s->x34 = v;
    if (slot_pending(s) && fn_888D4EF8(s)) fn_888DC5E8(o, s, a, b);
}
