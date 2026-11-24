/* Swing_DLL.xex 0x8899F5C8: if a leave action (lbl_88C6C940) is queued for the lobby's pad in the action queue (lbl_88D45A0C), remove it, clear hosting and post event 0xA0BDE62E: on state+0x20c in mode 1, on the remote slot (+0xd8) in mode 2, otherwise on state+0x1a4.
 * /Oc. Event posts go through EventSlot pointers; the remote field is compared signed (cmpwi), so it is an int handle cast at the store, like 8899F520. */
typedef struct EventSlot { unsigned char f0; unsigned char pending; unsigned char pad[2]; unsigned int hash; unsigned int value; } EventSlot;
typedef struct SessionState { char pad[0x1a4]; EventSlot leaveEvent; char pad2[0x20c - 0x1b0]; EventSlot hostLeaveEvent; } SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
typedef struct ActQueue ActQueue;
typedef struct RemoteSlot { char pad[0x8]; unsigned int eventHash; } RemoteSlot;
typedef struct Lobby {
    char pad[0xa0]; int mode; char pad1[0xbc - 0xa4]; int padIndex; char pad2[0xd8 - 0xc0]; int remote;
    char pad3[0x154 - 0xdc]; unsigned char hosting;
} Lobby;
extern SessionContext *g_ts4_session_context;
extern ActQueue *lbl_88D45A0C;
extern unsigned int lbl_88C6C940;
unsigned char ts4_range_has_887E97E8(ActQueue *q, void *kind, int pad, unsigned int key);
unsigned int ts4_range_remove_887E98F0(ActQueue *q, void *kind, int pad, unsigned int key);

void fn_8899F5C8(Lobby *l)
{
    ActQueue *q = lbl_88D45A0C;
    EventSlot *ev;
    if (!ts4_range_has_887E97E8(q, &lbl_88C6C940, l->padIndex, 0))
        return;
    ts4_range_remove_887E98F0(q, &lbl_88C6C940, l->padIndex, 0);
    l->hosting = 0;
    if (l->mode == 1) {
        ev = &g_ts4_session_context->state->hostLeaveEvent;
        ev->hash = 0xA0BDE62E;
        ev->value = 1;
        ev->pending = 1;
    } else if (l->mode == 2) {
        if (l->remote)
            ((RemoteSlot *)l->remote)->eventHash = 0xA0BDE62E;
    } else {
        ev = &g_ts4_session_context->state->leaveEvent;
        ev->hash = 0xA0BDE62E;
        ev->value = 1;
        ev->pending = 1;
    }
}
