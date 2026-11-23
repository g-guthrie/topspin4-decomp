/* Timed phase counters (world subsystem): enter the idle / active phase and
 * push the deadline out by the owner's period length. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Q5SPeriods {
    char pad0[0x1c];
    u32 active_len;     /* +0x1c */
    u32 idle_len;       /* +0x20 */
} Q5SPeriods;

typedef struct Q5SPhaseOwner {
    char pad0[0x28];
    Q5SPeriods *periods; /* +0x28 */
} Q5SPhaseOwner;

typedef struct Q5SPhase {
    char pad0[0x20];
    u32 active_runs;    /* +0x20 */
    u32 ticks;          /* +0x24 */
    u32 idle_runs;      /* +0x28 */
    u8 active;          /* +0x2c */
    char pad2d[0x13];
    u32 deadline;       /* +0x40 */
} Q5SPhase;

/* Going through the field address schedules the deadline load after the counter stores. */
static void phase_add(u32 *dst, u32 v)
{
    *dst += v;
}

/* Swing_DLL.xex 0x888C1B58 */
void ts4_phase_enter_idle_888C1B58(Q5SPhaseOwner *self, Q5SPhase *ph)
{
    ph->active = 0;
    ph->ticks = 0;
    ph->idle_runs++;
    phase_add(&ph->deadline, self->periods->idle_len);
}

/* Swing_DLL.xex 0x888C1B88 */
void ts4_phase_enter_active_888C1B88(Q5SPhaseOwner *self, Q5SPhase *ph)
{
    ph->active = 1;
    ph->active_runs++;
    ph->ticks++;
    phase_add(&ph->deadline, self->periods->active_len);
}
