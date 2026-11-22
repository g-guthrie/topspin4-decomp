/* Q5 gameplay small functions closed by the equivalence route (fn_equiv).
 * See work/specs/Q5/eq_q5_gameplay_small_b.json and its .equiv.json evidence. */
typedef unsigned int u32;
typedef unsigned char u8;

/* ---- 0x888C1B58 / 0x888C1B88: phase counters of a timed state, advanced by the
 * owner's period table. Not byte-matched: the target schedules the loads of the
 * deadline and of self->periods after the counter stores (perm_auto best 7). */
typedef struct Q5Periods {
    char pad0[0x1c];
    u32 active_len;     /* +0x1c */
    u32 idle_len;       /* +0x20 */
} Q5Periods;
typedef struct Q5PhaseOwner { char pad0[0x28]; Q5Periods *periods; } Q5PhaseOwner;
typedef struct Q5Phase {
    char pad0[0x20];
    u32 active_runs;    /* +0x20 */
    u32 ticks;          /* +0x24 */
    u32 idle_runs;      /* +0x28 */
    u8 active;          /* +0x2c */
    char pad2d[0x13];
    u32 deadline;       /* +0x40 */
} Q5Phase;

/* Swing_DLL.xex 0x888C1B58 */
/* byte-gap: 7 off; target schedules the loads of the deadline and of self->periods after the counter stores (perm_auto best 7) */
void ts4_phase_enter_idle_888C1B58(Q5PhaseOwner *self, Q5Phase *ph)
{
    ph->active = 0;
    ph->ticks = 0;
    ph->idle_runs++;
    ph->deadline += self->periods->idle_len;
}

/* Swing_DLL.xex 0x888C1B88 */
/* byte-gap: 4 off; target schedules the loads of the deadline and of self->periods after the counter stores (perm_auto best 7) */
void ts4_phase_enter_active_888C1B88(Q5PhaseOwner *self, Q5Phase *ph)
{
    ph->active = 1;
    ph->active_runs++;
    ph->ticks++;
    ph->deadline += self->periods->active_len;
}

/* ---- 0x888C5EB8: show the four parts unless the object is hidden.
 * Not byte-matched: the first part pointer is loaded before the select in the target (6 off). */
typedef struct Q5Part { char pad0[8]; u8 visible; } Q5Part;
typedef struct Q5Parts {
    char pad0[0x42];
    u8 hidden;          /* +0x42 */
    char pad43[0x35];
    Q5Part *parts[4];   /* +0x78 */
} Q5Parts;

/* Swing_DLL.xex 0x888C5EB8 */
/* byte-gap: 6 off; the first part pointer is loaded before the select in the target */
void ts4_parts_sync_visible_888C5EB8(Q5Parts *self)
{
    int i;
    u8 v = 0;
    if (!self->hidden)
        v = 1;
    for (i = 0; i < 4; i++)
        self->parts[i]->visible = v;
}

/* ---- 0x8866EB80: reset five best-value records to INT_MAX.
 * Not byte-matched: the target materialises the constant into five registers (dead mr copies). */
typedef struct Q5Best { int value; int extra; } Q5Best;
typedef struct Q5BestTable {
    char pad0[0xb0];
    Q5Best a, b, c;     /* +0xb0, +0xb8, +0xc0 */
    char padc8[0x18];
    Q5Best d, e;        /* +0xe0, +0xe8 */
} Q5BestTable;
typedef struct Q5BestHolder { char pad0[0x20]; Q5BestTable *table; } Q5BestHolder;
typedef struct Q5BestOwner { char pad0[0x5c]; Q5BestHolder *holder; } Q5BestOwner;

/* Swing_DLL.xex 0x8866EB80 */
/* byte-gap: 15 off; target materialises the constant into five registers (dead mr copies) */
void ts4_best_reset_8866EB80(Q5BestOwner *self)
{
    Q5BestTable *t = self->holder->table;
    t->a.value = 0x7FFFFFFF;
    t->b.value = 0x7FFFFFFF;
    t->c.value = 0x7FFFFFFF;
    t->d.value = 0x7FFFFFFF;
    t->e.value = 0x7FFFFFFF;
}

/* ---- 0x888D9368: forward two 12-byte xdata handles with the hash 0x5392B268.
 * Not byte-matched: the hash is built in r11 and moved to r4 in the target. */
typedef struct Q5XNode Q5XNode;
typedef struct Q5XRef { Q5XNode *node; u32 offset; u32 extra; } Q5XRef;
extern void fn_888D0FE0(void *self, u32 hash, Q5XRef a, Q5XRef b);

/* Swing_DLL.xex 0x888D9368 */
/* byte-gap: 15 off; the hash is built in r11 and moved to r4 in the target */
void ts4_xdata_forward_5392B268_888D9368(void *self, Q5XRef a, Q5XRef b)
{
    fn_888D0FE0(self, 0x5392B268, a, b);
}
