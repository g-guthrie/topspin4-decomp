/* Swing_DLL.xex 0x8899FF98: rebuild the list of teams on the local side and reset the slot status of their members
 * member loop as guarded do/while with the session context read once in the guard (target loads it after the empty test) */
typedef struct Member { char pad[0x80]; int slot; } Member;
typedef struct Team { int pad0; Member **first; Member **last; char pad0c[0x48 - 0xc]; int side; } Team;
typedef struct TeamList { Team **first; Team **last; void *alloc; Team **end; } TeamList;
typedef struct Roster {
    char pad[0x14];
    Team *local;     /* +0x14 */
    Team **first;    /* +0x18 */
    Team **last;     /* +0x1C */
    char pad20[0x8];
    TeamList sameSide; /* +0x28 */
} Roster;
typedef struct SlotStatus { char pad[0x18]; unsigned int state; int owner; } SlotStatus; /* 32 bytes */
typedef struct SlotStatusTable { int off; } SlotStatusTable; /* self-relative */
typedef struct LobbyData { char pad[0x214]; SlotStatusTable status; } LobbyData;
typedef struct SessionState { char pad[0x2d0]; unsigned int mode; } SessionState;
typedef struct SessionContext { char pad[0x3c]; SessionState *state; char pad40[0x68 - 0x40]; LobbyData *lobby; } SessionContext;
extern SessionContext *g_ts4_session_context;
void ts4_object_finalize(TeamList *l);
void ts4_vector_grow_append_scalar4_8816DD48(TeamList *v, Team **where, Team *const *val);

static __inline void push_back(TeamList *v, Team *t)
{
    if (v->last != v->end) {
        if (v->last)
            *v->last = t;
        v->last++;
    } else {
        ts4_vector_grow_append_scalar4_8816DD48(v, v->last, &t);
    }
}

void fn_8899FF98(Roster *r)
{
    SlotStatusTable *tbl = &g_ts4_session_context->lobby->status;
    int side;
    Team **ti;
    Team **tend;
    ts4_object_finalize(&r->sameSide);
    side = r->local->side;
    tend = r->last;
    for (ti = r->first; ti != tend; ti++) {
        Team *t = *ti;
        if (t->side == side) {
            Member **end = t->last;
            Member **it = t->first;
            if (it != end) {
                SessionContext *ctx = g_ts4_session_context;
                do {
                    Member *m = *it;
                    SlotStatus *s;
                    if (ctx->state->mode != 0xA9FDE255)
                        m->slot = 1;
                    s = (SlotStatus *)((char *)tbl + tbl->off) + m->slot;
                    s->state = 0x64A3FAF1;
                    s->owner = -1;
                } while (++it != end);
            }
            push_back(&r->sameSide, t);
        }
    }
}
