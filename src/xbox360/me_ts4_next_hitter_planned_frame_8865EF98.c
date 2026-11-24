typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
/* Next hitter planned-hit lookup (ME). */
/* Planned-hit lookup: the next hitter's shot list (match flow). */
struct Ts4PlanShot {                      /* element of the per-player shot list */
    ts4_u8 pad_00[0x14];
    int record;                           /* +0x14 index into the plan records */
};
struct Ts4PlanRecord {                    /* 0xE0 bytes */
    ts4_u8 pad_00[0x10];
    int frame;                            /* +0x10 planned hit frame */
    ts4_u8 planned;                       /* +0x14 */
    ts4_u8 pad_15[0xE0 - 0x15];
};
struct Ts4PlanPlayer {
    ts4_u8 pad_00[0x10];
    struct Ts4PlanShot **begin;           /* +0x10 */
    struct Ts4PlanShot **end;             /* +0x14 */
};
struct Ts4PlanFlow {
    ts4_u8 pad_00[0x70];
    int records_rel;                      /* +0x70 self-relative Ts4PlanRecord array */
    ts4_u8 pad_74[8];
    int next_hitter;                      /* +0x7C */
};
struct Ts4PlanMatch {
    ts4_u8 pad_00[0x10];
    struct Ts4PlanPlayer **players;       /* +0x10 */
    ts4_u8 pad_14[0x1C];
    struct Ts4PlanFlow *flow;             /* +0x30 */
};
static struct Ts4PlanRecord *ts4_plan_record(int *rel, int i)
{
    return (struct Ts4PlanRecord *)((char *)rel + *rel) + i;
}
static int ts4_plan_count(struct Ts4PlanPlayer *p) { return (int)(p->end - p->begin); }
static struct Ts4PlanShot *ts4_plan_shot(struct Ts4PlanPlayer *p, int i) { return p->begin[i]; }

static struct Ts4PlanShot *ts4_plan_shot2(struct Ts4PlanShot ***b, int i) { return (*b)[i]; }
static struct Ts4PlanShot **ts4_plan_shot3(struct Ts4PlanPlayer *p) { return p->begin; }
static void ts4_set_none(int *p) { *p = -1; }
/* Swing_DLL.xex 0x8865EF98: frame of the next hitter's first planned shot. */
ts4_u8 ts4_next_hitter_planned_frame_8865EF98(struct Ts4PlanMatch *match, int *frame_out)
{
    struct Ts4PlanFlow *flow = match->flow;
    int *rel = &flow->records_rel;
    struct Ts4PlanPlayer **pl = match->players;
    ts4_u8 found = 0;
    int n, i;
    { int *__restrict fp = frame_out; *fp = -1; }
    
    n = ts4_plan_count(pl[flow->next_hitter]);
    for (i = 0; i < n; i++) {
        struct Ts4PlanRecord *r = ts4_plan_record(rel, ts4_plan_shot(pl[flow->next_hitter], i)->record);
        if (r->planned == 1) {
            *frame_out = r->frame;
            found = 1;
            break;
        }
    }
    return found;
}
