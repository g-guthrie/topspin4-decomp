/* Small world-subsystem helpers. */
typedef unsigned char u8;

/* ---- 0x888C72E8 */
typedef struct Q5SWord { void *v; } Q5SWord;
typedef struct Q5SLinkState {
    char pad0[0x18];
    Q5SWord cur;        /* +0x18 */
    void *pending;      /* +0x1c */
    void *aux;          /* +0x20 */
    Q5SWord target;     /* +0x24 */
} Q5SLinkState;

/* Copying the key into a one-word struct local fixes the cmplw operand order. */
static int link_at_target(Q5SLinkState *s)
{
    Q5SWord k;
    k = s->target;
    return s->cur.v == k.v;
}

/* Swing_DLL.xex 0x888C72E8 */
u8 ts4_link_is_busy_888C72E8(Q5SLinkState *s)
{
    return s->pending != 0 || link_at_target(s);
}

/* ---- 0x888C4EE0 */
typedef struct Q5SSlot { char pad0[0x18]; u8 on; char pad19[0x1c - 0x19]; } Q5SSlot;
typedef struct Q5SRel { int off; } Q5SRel;
typedef struct Q5SSlotBank { char pad0[0x738]; Q5SRel slots; } Q5SSlotBank;
typedef struct Q5SSlotOwner {
    char pad0[0x23c];
    u8 lock;            /* +0x23c */
    char pad23d[0x254 - 0x23d];
    Q5SSlotBank *bank;  /* +0x254 */
} Q5SSlotOwner;

/* Swing_DLL.xex 0x888C4EE0 */
void ts4_slot_set_on_888C4EE0(Q5SSlotOwner *t, int i, int j)
{
    u8 v = 1;
    Q5SRel *r;
    if (t->lock && j)
        v = 0;
    r = &t->bank->slots;
    ((Q5SSlot *)((char *)r + r->off))[i * 2 + j].on = v;
}
