/* Swing_DLL.xex 0x889A00A8 (/Oc): set a member slot's team byte (+0xD2) from the request (+0x430).
 * A negative member index posts 0xE954AAAB on state+0x1BC. In modes 0xA9FDE255/0x72FD37F0 the slot
 * is indexed through the member list; otherwise the slot table is searched by member id, then
 * 0xE954AAAB is posted on state+0x1C8.
 * Matching note: the mode is bound to a const reference local, which keeps the ctx->state chain
 * in r10 (a by-value local loads state into r7, 2 off). The table is re-read through o->table
 * (no local) for the add order. */
typedef struct EventSlot { unsigned char f0; unsigned char pending; unsigned char pad[2]; unsigned int hash; unsigned int value; } EventSlot;
typedef struct SessionState {
    char pad[0x1bc]; EventSlot slotEvent; EventSlot memberEvent; char pad2[0x2d0 - 0x1d4]; unsigned int modeHash;
} SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
typedef struct SlotEntry { char pad[0xbc]; unsigned int memberId; char pad2[0xd2 - 0xc0]; unsigned char team; char pad3[0xd8 - 0xd3]; } SlotEntry;
typedef struct SlotTable { int off; unsigned int count; } SlotTable;
typedef struct SlotOwner { char pad[0xac]; SlotTable *table; } SlotOwner;
typedef struct Member { char pad[0x80]; int slot; } Member;
typedef struct MemberList { int pad; Member **members; char pad2[0x14 - 0x8]; unsigned int id; } MemberList;
typedef struct TeamRequest { char pad[0x42c]; int memberIndex; unsigned char team; } TeamRequest;
extern "C" SessionContext *g_ts4_session_context;

extern "C" void ts4_slot_set_team_889A00A8(SlotOwner *o, const TeamRequest *req, const MemberList *list)
{
    SessionContext *ctx;
    SlotTable *t;
    unsigned int i;
    EventSlot *ev;
    if (req->memberIndex < 0) {
        ev = &g_ts4_session_context->state->slotEvent;
        ev->hash = 0xE954AAAB;
        ev->value = 1;
        ev->pending = 1;
        return;
    }
    ctx = g_ts4_session_context;
    const unsigned int &mode = ctx->state->modeHash;
    if (mode == 0xA9FDE255 || mode == 0x72FD37F0) {
        ((SlotEntry *)((char *)o->table + o->table->off))[list->members[req->memberIndex]->slot].team = req->team;
        return;
    }
    t = o->table;
    for (i = 0; i < t->count; i++) {
        SlotEntry *e = &((SlotEntry *)((char *)t + t->off))[i];
        if (list->id == e->memberId) {
            e->team = req->team;
            break;
        }
    }
    ev = &ctx->state->memberEvent;
    ev->hash = 0xE954AAAB;
    ev->value = 1;
    ev->pending = 1;
}
