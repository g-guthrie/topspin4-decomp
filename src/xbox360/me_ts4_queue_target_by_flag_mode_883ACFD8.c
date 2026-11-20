/* 0x883ACFD8: Picks mode 1, 2, 3 or 0 from target flag bits 0x20/0x40/0x80 and forwards the target to the engine queue with the session handle. Returns 0x25 with no target, 0 with no session. */
/* Matched on /Oc (agAH). Else-if chain; the last level is a ternary. */
typedef struct Target { char p0[0x44]; unsigned int flags; } Target;
typedef struct Session { char p0[0x38]; void *handle; } Session;
typedef struct Engine { char p0[0x57b4]; char queue[4]; } Engine;
typedef struct Ctx { int p0; Engine *engine; char p8[8]; Session *session; } Ctx;
extern int ts4_if_call_seq_u32_off0_8832C090(void *queue, int mode, void *handle, Target *t, int extra);
int fn_883ACFD8(Ctx *c, Target *t)
{
    int mode;
    if (t == 0)
        return 0x25;
    if (c->session == 0)
        return 0;
    if (t->flags & 0x20)
        mode = 1;
    else if (t->flags & 0x40)
        mode = 2;
    else
        mode = (t->flags & 0x80) ? 3 : 0;
    return ts4_if_call_seq_u32_off0_8832C090(c->engine->queue, mode, c->session->handle, t, 0);
}
