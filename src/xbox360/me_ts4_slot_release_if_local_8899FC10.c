/* Swing_DLL.xex 0x8899FC10: release a held slot when the local player holds it, then post event 0xA0BDE62E on the state+0xa4 event slot
 * bounds-checked self-relative 0xd8-byte slot table; event post through an EventSlot pointer */
typedef struct EventSlot { unsigned char f0; unsigned char pending; unsigned char pad[2]; unsigned int hash; unsigned int value; } EventSlot;
typedef struct SessionState { char pad[0xa4]; EventSlot event; } SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
typedef struct SlotEntry { char pad[0xbc]; int holder; unsigned char held; char pad2[0xd8 - 0xc1]; } SlotEntry;
typedef struct SlotTable { int off; int count; } SlotTable;
typedef struct SlotOwner { char pad[0xac]; SlotTable *table; char pad2[0xd0 - 0xb0]; int localId; } SlotOwner;
extern SessionContext *g_ts4_session_context;

void ts4_lobby_remove_fake_player(SlotOwner *o, int index)
{
    SlotTable *t = o->table;
    SlotEntry *e;
    EventSlot *ev;
    if (index < 0 || index >= t->count)
        return;
    e = (SlotEntry *)((char *)t + t->off) + index;
    if (e->holder != o->localId)
        return;
    e->held = 0;
    ev = &g_ts4_session_context->state->event;
    ev->hash = 0xA0BDE62E;
    ev->value = 1;
    ev->pending = 1;
}
