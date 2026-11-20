/* Swing_DLL.xex 0x8899F520: lobby joined: store the session id (desc+0x42c), set joined, clear the name and the info ready byte, copy the id to the host member in mode 1, post event 0x7FAFB4B6 on the state+0x80 event slot.
 * /Oc. The host field is compared signed (cmpwi), so it is an int handle cast to Member*; the id store precedes the joined store in source. */
typedef struct EventSlot { unsigned char f0; unsigned char pending; unsigned char pad[2]; unsigned int hash; unsigned int value; } EventSlot;
typedef struct SessionState { char pad[0x80]; EventSlot event; } SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; } SessionContext;
typedef struct Member { char pad[0x18]; int id; } Member;
typedef struct LobbyInfo { char pad[0x448]; unsigned char ready; } LobbyInfo;
typedef struct SessionDesc { char pad[0x42c]; int id; } SessionDesc;
typedef struct Lobby {
    char pad[0xb8]; int sessionId; char pad1[0xc4 - 0xbc]; int host; char pad2[0xd8 - 0xc8];
    LobbyInfo *info; char pad3[0xe4 - 0xdc]; char *name; unsigned char joined; char pad4[0x110 - 0xe9]; int mode;
} Lobby;
extern SessionContext *g_ts4_session_context;

void fn_8899F520(Lobby *l, const SessionDesc *d)
{
    EventSlot *ev;
    l->sessionId = d->id;
    l->joined = 1;
    l->name[0] = 0;
    l->info->ready = 0;
    if (l->mode == 1 && l->host)
        ((Member *)l->host)->id = d->id;
    ev = &g_ts4_session_context->state->event;
    ev->hash = 0x7FAFB4B6;
    ev->value = 1;
    ev->pending = 1;
}
