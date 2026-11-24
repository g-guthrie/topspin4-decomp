/* 0x88917340: if the owner has a pending flag at +0xD5, posts event hash 0xEA954889 into the session request's
 * event slot (hash, count 1, armed) and clears the pending flag. Matched via the sub-struct-address rule. */
typedef unsigned char u8;
typedef struct Ts4EventSlot { u8 a; u8 armed; char q[2]; unsigned int hash; int count; } Ts4EventSlot;
typedef struct Ts4SessionRequest { char p[0x138]; Ts4EventSlot ev; } Ts4SessionRequest;
typedef struct Ts4SessionContext { char p[0x3c]; Ts4SessionRequest *req; } Ts4SessionContext;
extern Ts4SessionContext *g_ts4_session_context;
typedef struct Ts4PendingOwner { char p[0xd5]; u8 pending; } Ts4PendingOwner;
static void post_event(Ts4EventSlot *e, unsigned int hash) { e->hash = hash; e->count = 1; e->armed = 1; }
void ts4_flush_pending_event_88917340(Ts4PendingOwner *o)
{
    if (!o->pending) return;
    post_event(&g_ts4_session_context->req->ev, 0xEA954889u);
    o->pending = 0;
}
