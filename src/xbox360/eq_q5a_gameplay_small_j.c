/* Q5 batch J (Opus A): small gameplay helpers proven EQUIVALENT with tools/fn_equiv.py on b215
 * (TS4_MATCHING_DIR=work/matching-b215, /Oc). Each function carries its byte gap to the target. */
typedef unsigned int u32;
typedef struct Q5MvPlanner Q5MvPlanner; /* see q5_gameplay_move_leave.c */
typedef struct Q5RstAnim {
    char pad[0x3a0];
    u32 anim_a;             /* 0x3a0 */
    u32 anim_b;             /* 0x3a4 */
    char pad3a8[0x5dd - 0x3a8];
    unsigned char f5dd;     /* 0x5dd */
    unsigned char f5de;     /* 0x5de */
    unsigned char f5df;     /* 0x5df */
    char pad5e0[0xbc8 - 0x5e0];
    int target_a;           /* 0xbc8 */
    int target_b;           /* 0xbcc */
} Q5RstAnim;
typedef struct Q5RstPlayer { char pad[0x74]; Q5RstAnim *anim; } Q5RstPlayer;
typedef struct Q5RstOwner {
    char pad[0x14];
    u32 *state;             /* 0x14 */
    Q5MvPlanner *planner;   /* 0x18 */
    char pad1c[0x154 - 0x1c];
    Q5RstPlayer *player;    /* 0x154 */
} Q5RstOwner;
extern void ts4_move_state_leave_8865DAC0(Q5MvPlanner *self, u32 state);

/* Swing_DLL.xex 0x8866C248: reset the player's move animation: clear the 0x5dd-0x5df flags, set both animation ids to
 * 0xCCB6E1AC, leave the active move state (8865DAC0) when there is one, and clear both targets to -1 */
/* byte-gap: 39 off (perm not run); LTCG: the target keeps r7/r8 live across the call to 8865DAC0 */
void ts4_move_reset_8866C248(Q5RstOwner *self)
{
    self->player->anim->f5dd = 0;
    self->player->anim->f5df = 0;
    self->player->anim->f5de = 0;
    self->player->anim->anim_a = 0xCCB6E1ACu;
    self->player->anim->anim_b = 0xCCB6E1ACu;
    if (*self->state) {
        ts4_move_state_leave_8865DAC0(self->planner, *self->state);
        *self->state = 0;
    }
    self->player->anim->target_a = -1;
    self->player->anim->target_b = -1;
}

typedef struct Q5Rel { int off; } Q5Rel;
typedef struct Q5Range30 { char pad[0x24]; int lo; int hi; char pad2c[4]; } Q5Range30;
typedef struct Q5RangeSet {
    char pad[0x18];
    Q5Rel ranges;           /* 0x18: self-relative Q5Range30[] */
    int count;              /* 0x1c */
    char pad20[0x10];
    unsigned char enabled;  /* 0x30 */
} Q5RangeSet;
typedef struct Q5HashTable { char pad[0x24]; Q5Rel hashes; } Q5HashTable;

static int q5_find_hash(Q5HashTable *t, int lo, int hi, u32 hash)
{
    int i;
    for (i = lo; i <= hi; i++) {
        if (((u32 *)((char *)&t->hashes + t->hashes.off))[i] == hash)
            return i;
    }
    return -1;
}

/* Swing_DLL.xex 0x8865D7D8: when the range set is enabled, return the first index in any [lo, hi] range of the self-relative
 * hash array that holds 0x0F6FB110, else -1 */
/* byte-gap: 40 off (perm not run); the target saves three registers (__savegprlr_29) and keeps the array base live; the candidate keeps two */
int ts4_range_find_hash_8865D7D8(Q5HashTable *self, Q5RangeSet *set)
{
    int r = -1;
    if (set->enabled) {
        int n = set->count;
        int j;
        for (j = 0; j < n; j++) {
            Q5Range30 *g = (Q5Range30 *)((char *)&set->ranges + set->ranges.off) + j;
            r = q5_find_hash(self, g->lo, g->hi, 0x0F6FB110u);
            if (r != -1)
                return r;
        }
    }
    return r;
}

typedef struct Q5Pend10 { char raw[0x10]; } Q5Pend10;
typedef struct Q5PendSets {
    Q5Pend10 *first;        /* 0x00 */
    Q5Pend10 *last;         /* 0x04 */
    char pad08[4];
    void **a_first;         /* 0x0c */
    void **a_last;          /* 0x10 */
    char pad14[4];
    void **b_first;         /* 0x18 */
    void **b_last;          /* 0x1c */
} Q5PendSets;
extern unsigned char ts4_slotset_has_pending_888CA680(Q5Pend10 *o);

/* Swing_DLL.xex 0x888D4EF8: when both side lists (+0xc, +0x18) are non-empty, return 1 if any 16-byte slot set has pending
 * work (888CA680), else 0 */
/* byte-gap: 40 off (perm not run); LTCG: the target keeps r4/r5 live across the call to 888CA680 */
unsigned char ts4_pendsets_any_pending_888D4EF8(Q5PendSets *self)
{
    unsigned char ready = self->a_first != self->a_last && self->b_first != self->b_last;
    if (ready) {
        Q5Pend10 *it;
        for (it = self->first; it != self->last; it++) {
            if (ts4_slotset_has_pending_888CA680(it))
                return 1;
        }
    }
    return 0;
}

typedef struct Q5Job Q5Job;
struct Q5Job { char pad[0xc]; void *pending; unsigned char queued; };
typedef struct Q5JobVec { Q5Job **first; Q5Job **last; Q5Job **end; } Q5JobVec;
typedef struct Q5JobQueue { char pad[0x58]; Q5JobVec queue; } Q5JobQueue;
extern void fn_887EC7A0(Q5JobQueue *self, Q5Job *job);
extern void ts4_vector_grow_append_scalar4_88174A38(Q5JobVec *v, Q5Job **where, Q5Job **val);

static void q5_job_push(Q5JobVec *v, Q5Job **val)
{
    if (v->last != v->end) {
        if (v->last)
            *v->last = *val;
        v->last++;
    } else {
        ts4_vector_grow_append_scalar4_88174A38(v, v->last, val);
    }
}

/* Swing_DLL.xex 0x887ED280: submit a job: run it now (887EC7A0) when nothing is pending and it is not queued; otherwise queue
 * it once on the +0x58 vector (grow through 88174A38 when full) */
/* byte-gap: 17 off (perm best 16); the target spills the job argument to its home slot (0x7c) for the grow call */
void ts4_job_submit_887ED280(Q5JobQueue *self, Q5Job *job)
{
    if (job->pending == 0 && !job->queued) {
        fn_887EC7A0(self, job);
        return;
    }
    if (!job->queued) {
        job->queued = 1;
        q5_job_push(&self->queue, &job);
    }
}

typedef struct Q5ShotStat { char pad[0x7c]; u32 count_b; u32 count_a; char pad2[0x134 - 0x84]; } Q5ShotStat;
typedef struct Q5ShotInfo { char pad[0x5c]; u32 kind; char pad2[4]; u32 result; char pad3[0x110 - 0x68]; u32 stat_index; } Q5ShotInfo;
typedef struct Q5ShotState { char pad[0x54]; unsigned char active; char pad2[0x80 - 0x55]; Q5ShotInfo info; } Q5ShotState;
typedef struct Q5ShotHost { char pad[0x90]; Q5ShotState state; } Q5ShotHost;
typedef struct Q5StatBank { char pad[0x5c]; Q5Rel stats; } Q5StatBank;
typedef struct Q5ShotTracker { char pad[0x20]; Q5ShotHost *host; char pad2[4]; Q5StatBank *bank; } Q5ShotTracker;
static Q5ShotStat *q5_stat_at(Q5Rel *r, u32 i) { return (Q5ShotStat *)((char *)r + r->off) + i; }
/* Swing_DLL.xex 0x88667C98: when the shot state is active and its result is not 0x7EB30F90, count the shot in its stat
 * record: kind 0xE630E16B bumps +0x80, kind 0x45FFFB93 bumps +0x7c */
/* byte-gap: 41 off (perm best 41); the target keeps the shot info and the stat array head as separate pointers instead of folding the offsets */
void ts4_shot_stat_count_88667C98(Q5ShotTracker *self)
{
    Q5ShotState *st = &self->host->state;
    Q5ShotInfo *info = &st->info;
    u32 idx;
    if (!st->active)
        return;
    if (info->result == 0x7EB30F90)
        return;
    idx = info->stat_index;
    if (info->kind == 0xE630E16B)
        q5_stat_at(&self->bank->stats, idx)->count_a++;
    else if (info->kind == 0x45FFFB93)
        q5_stat_at(&self->bank->stats, idx)->count_b++;
}

typedef struct Q5Session {
    const void *vt;
    char pad[0x18];
    void *res_1c; char pad20[8];
    void *res_28; char pad2c[8];
    void *res_34; char pad38[8];
    void *res_40; char pad44[0x10];
    void *res_54; char pad58[8];
    const void *sub_vt; char pad64[0xbc - 0x64];
    void *res_bc;
} Q5Session;
extern const char lbl_880DC64C[];
extern const char ts4_vtbl_Ts4TrackerShell880D6B70[];
extern u32 lbl_88D45964;
extern void ts4_destroy_owned_object(void *p);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
/* Swing_DLL.xex 0x888B8D98: session destructor: reset the vtable, clear the global session pointer, free the owned buffers
 * (+0xbc, +0x54 after resetting the +0x60 vtable, +0x40, +0x34, +0x28, +0x1c), then run the base destructor */
/* byte-gap: 8 off (perm best 8); store/load scheduling of the vtable and global stores */
void ts4_session_dtor_888B8D98(Q5Session *self)
{
    self->vt = lbl_880DC64C;
    lbl_88D45964 = 0;
    if (self->res_bc)
        ts4_destroy_owned_object(self->res_bc);
    self->sub_vt = ts4_vtbl_Ts4TrackerShell880D6B70;
    ts4_destroy_owned_object(self->res_54);
    if (self->res_40)
        ts4_destroy_owned_object(self->res_40);
    if (self->res_34)
        ts4_destroy_owned_object(self->res_34);
    if (self->res_28)
        ts4_destroy_owned_object(self->res_28);
    if (self->res_1c)
        ts4_destroy_owned_object(self->res_1c);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(self);
}

extern void *lbl_88D45B38;
extern void *ts4_if_call_seq_u32_lbl_88D459E4_8883F238(void);
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);
extern unsigned char fn_888CFE38(u32 id, u32 *packet);
extern void ts4_format_save_dir_88866980(u32 id, char *out, u32 size);
extern void fn_8862A1F0(void *mgr, const u32 *data, u32 size, const char *dir);
extern void ts4_registry_dispatch_888860A0(void *p);
static u32 q5_read_u32(u32 **cur) { u32 v = **cur; (*cur)++; return v; }
/* Swing_DLL.xex 0x888DDD70: load the saved packet for id (888CFE38) into a 3000-byte buffer; when its kind matches, format the
 * save directory (88866980) and apply the payload (8862A1F0); free the buffer and return whether it was applied */
/* byte-gap: 15 off (perm best 15); the target reuses the buffer pointer as the read cursor and rebuilds it (subi 8) before the free */
unsigned char ts4_save_apply_packet_888DDD70(u32 id, int kind)
{
    char dir[0x200];
    unsigned char ok = 0;
    void *mgr = ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
    u32 *p = (u32 *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 3000, 1, 0, 0);
    if (fn_888CFE38(id, p)) {
        u32 *cur = p;
        u32 k = q5_read_u32(&cur);
        u32 size = q5_read_u32(&cur);
        if (kind == (int)k) {
            ts4_format_save_dir_88866980(id, dir, 0x200);
            fn_8862A1F0(mgr, cur, size, dir);
            ok = 1;
        }
    }
    ts4_registry_dispatch_888860A0(p);
    return ok;
}

typedef struct Q5Handle { u32 tree; u32 node_id; u32 pool; } Q5Handle;
typedef struct Q5Str { char *first; char *last; char *cap; } Q5Str;
typedef struct Q5NameRef { u32 a, b, c; } Q5NameRef;
typedef struct Q5RelStr { int off; } Q5RelStr;
typedef struct Q5NameRec { char pad[0x1c]; Q5RelStr name; } Q5NameRec;
typedef struct Q5NamedNode { char pad[0x24]; Q5NameRef ref; } Q5NamedNode;
extern const char lbl_880C1320[];
extern void *fn_88627EC0(void *object, Q5Handle h);
extern void fn_8816D1A8(Q5Str *s);
extern void *fn_88923530(u32 pool, Q5Handle h, u32 type_hash); /* pool: 32-bit target address */
extern void ts4_assign_formatted_text(Q5Str *dst, const char *text);
extern void ts4_if_set_u32_off0_8862C0E8(Q5NameRef *out, const char *name);
static const char *q5_rel_str(Q5RelStr *r) { return r->off != -1 ? (const char *)r + r->off : lbl_880C1320; }
/* Swing_DLL.xex 0x888E4CA0: base-construct from the handle, resolve its 0xEFCA9B4A record, and cache the name reference of
 * the record's self-relative name (or "") at +0x24 */
/* byte-gap: 3 off (perm best 3); register order of the name text load */
void ts4_named_node_ctor_888E4CA0(Q5NamedNode *self, Q5Handle h)
{
    Q5Str unused;
    Q5Str name;
    Q5NameRef ref;
    Q5NameRec *rec;
    char *text;
    fn_88627EC0(self, h);
    fn_8816D1A8(&unused);
    rec = (Q5NameRec *)fn_88923530(h.pool, h, 0xEFCA9B4A);
    ts4_assign_formatted_text(&name, q5_rel_str(&rec->name));
    text = name.first;
    ts4_if_set_u32_off0_8862C0E8(&ref, text);
    self->ref = ref;
    ts4_destroy_owned_object(text);
    ts4_destroy_owned_object(unused.first);
}

typedef struct Q5RallyA { char pad[0xf0]; unsigned char active; } Q5RallyA;
typedef struct Q5RallyB { char pad[0x19]; unsigned char active; } Q5RallyB;
typedef struct Q5RallyFlags { char pad[0xe]; unsigned char dirty; } Q5RallyFlags;
typedef struct Q5RallyC { char pad[0x40]; Q5RallyFlags *flags; } Q5RallyC;
typedef struct Q5RallyShots { char pad[0x28]; u32 count; char pad2[2]; unsigned char reset; } Q5RallyShots;
typedef struct Q5RallyAnim { char pad[0x74]; char *anim; } Q5RallyAnim;
typedef struct Q5Rally {
    char pad[0x1c]; Q5RallyC *c; Q5RallyAnim *player;
    char pad24[4]; Q5RallyShots *shots;
    char pad2c[8]; Q5RallyB *b; Q5RallyA *a;
    unsigned char started; char pad3d[7];
    u32 elapsed; u32 interval; u32 limit;
    char pad50[0x28]; u32 phase; char pad7c[4]; unsigned char pending;
} Q5Rally;
extern void ts4_if_call_seq_u32_off34_88696340(Q5Rally *self);
extern void fn_886643F8(Q5Rally *self);
extern void ts4_clear_entries_8865AF70(Q5Rally *self);
extern void fn_88271ED8(void *anim_state);
/* Swing_DLL.xex 0x886A1628: restart the rally state: reset the sub-objects, the 0x78 interval, the 0x7fffffff limit and phase
 * 0x968230B3, clear the shot entries (8865AF70) and the player animation (88271ED8), then flag the shots for reset */
/* byte-gap: 42 off (not attempted; LTCG); the target keeps r6 = 0 live across the call to 886643F8 */
void ts4_rally_restart_886A1628(Q5Rally *self)
{
    ts4_if_call_seq_u32_off34_88696340(self);
    self->a->active = 0;
    self->b->active = 0;
    self->c->flags->dirty = 1;
    self->started = 1;
    fn_886643F8(self);
    self->elapsed = 0;
    self->interval = 0x78;
    self->limit = 0x7fffffff;
    self->shots->count = 0;
    self->pending = 1;
    self->phase = 0x968230B3;
    ts4_clear_entries_8865AF70(self);
    fn_88271ED8(self->player->anim + 0x66c);
    self->shots->reset = 1;
}
