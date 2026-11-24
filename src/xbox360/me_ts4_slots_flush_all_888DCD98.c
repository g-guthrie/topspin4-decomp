/* 0x888DCD98: flush all four slots of the owner manager (re-reading the manager each slot), passing mode 1 (agAY). Plain /Oc; per-slot inline flush(o, i) gives the byte-offset loop. */
typedef unsigned char u8;
typedef struct PVec { void *first; void *last; } PVec;
typedef struct Slot { u8 pad0[0xc]; PVec a; int pad14; PVec b; u8 pad20[0x14]; int x34; int pad38; } Slot;
typedef struct Mgr { u8 pad0[0x1c]; Slot slots[4]; u8 pad10c[0x50]; u8 enabled; } Mgr;
static u8 slot_pending(Slot *s) { return s->a.first != s->a.last && s->b.first != s->b.last; }
u8 fn_888D4EF8(Slot *s);
void fn_888DC5E8(Mgr *o, Slot *s, int a, int b);
typedef struct Own { u8 pad[0x70]; Mgr *mgr; } Own;
static void flush(Mgr *o, int i, int a, int b)
{
    Slot *s;
    if (!o->enabled) return;
    s = &o->slots[i];
    if (slot_pending(s) && fn_888D4EF8(s)) fn_888DC5E8(o, s, a, b);
}
void ts4_slots_flush_all_888DCD98(Own *w, int b)
{
    int i;
    for (i = 0; i < 4; i++) flush(w->mgr, i, 1, b);
}
