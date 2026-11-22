/* Q5 batch I (Opus A): small gameplay helpers proven EQUIVALENT with tools/fn_equiv.py on b215
 * (TS4_MATCHING_DIR=work/matching-b215, /Oc). Each function carries its byte gap to the target. */
typedef unsigned int u32;
#ifdef _MSC_VER
extern float __fres(float);
#pragma intrinsic(__fres)
#else
static float __fres(float x) { return 1.0f / x; }
#endif

typedef struct Q5Slot8 { unsigned a, b; } Q5Slot8;
typedef struct Q5Row30 { char pad[0x30]; } Q5Row30;
typedef struct Q5Grid { char pad[0x5a0]; Q5Row30 *rows_begin; Q5Row30 *rows_end; } Q5Grid;
typedef struct Q5CursorIn { char pad[0x7c]; Q5Slot8 *begin; Q5Slot8 *end; Q5Grid *grid; int grid_id; } Q5CursorIn;
typedef struct Q5Cursor { int idx; Q5CursorIn *in; char pad8[4]; int grid_id; } Q5Cursor;
extern unsigned char ts4_cursor_out_of_range_886603C0(Q5Cursor *s);

/* Swing_DLL.xex 0x88660520: false when the cursor is out of range (886603C0), when its input has no grid or a different grid id;
 * otherwise whether the input holds one 8-byte slot per 0x30-byte grid row */
/* byte-gap: 37 off (perm not run); LTCG: the target keeps r5 live across the call to 886603C0 */
unsigned char ts4_cursor_grid_complete_88660520(Q5Cursor *self)
{
    Q5CursorIn *in;
    if (ts4_cursor_out_of_range_886603C0(self))
        return 0;
    in = self->in;
    if (in->grid == 0 || in->grid_id != self->grid_id)
        return 0;
    return (in->end - in->begin) == (self->in->grid->rows_end - self->in->grid->rows_begin);
}

typedef struct Q5Span { char pad[0x24]; float lo; float hi; } Q5Span;
typedef struct Q5SpanList { char pad[4]; Q5Span **begin; Q5Span **end; } Q5SpanList;
typedef struct Q5Range2 { float lo; float hi; } Q5Range2;

/* Swing_DLL.xex 0x886C4970: index of the first span whose [lo, hi] (+0x24, +0x28) contains t, else -1 */
/* byte-gap: 36 off (perm not run); LTCG register/fsel scheduling, the target selects with fsel */
int ts4_span_find_886C4970(Q5SpanList *self, float t)
{
    int n = self->end - self->begin;
    int i;
    for (i = 0; i < n; i++) {
        Q5Span *s = self->begin[i];
        float below = t - s->lo;
        float above = s->hi - t;
        float m = below >= 0.0f ? above : below;
        if (m >= 0.0f)
            return i;
    }
    return -1;
}

/* Swing_DLL.xex 0x886C5820: map point p into the unit range of r: (p - lo) / (hi - lo), with 1.0 when the range is empty;
 * NaN-faithful select written out explicitly */
/* byte-gap: 39 off (perm not run); the target selects the divisor with a +/-1 fsel table (LTCG) */
void ts4_range_normalize_886C5820(const Q5Range2 *r, const float *p, float *out)
{
    float lo = r->lo;
    float d = r->hi - lo;
    float ad = d >= 0.0f ? d : -d;
    float inv;
    if (-ad < 0.0f || -ad != -ad)
        inv = __fres(d);
    else {
        d = 1.0f;
        inv = __fres(d);
    }
    inv = (1.0f - inv * d + 1.0f) * inv;
    out[1] = (p[1] - lo) * inv;
    out[0] = (p[0] - lo) * inv;
}

typedef struct Ga6Pair2 Ga6Pair2; /* 0x28-byte pair record, see ga6_o.c */
typedef struct Q5PairArr { int off; unsigned count; } Q5PairArr;
typedef struct Q5PairOwner { char pad[0x70]; Q5PairArr pairs; } Q5PairOwner;
typedef struct Q5PairRec { char raw[0x28]; } Q5PairRec;
extern unsigned char ga6_pair_accepts_886D0CE0(Ga6Pair2 *a, float unused, Ga6Pair2 *b);

static __inline Q5PairRec *q5_pairs_end(Q5PairArr *a)
{
    Q5PairRec *e = 0;
    if (a->off != -1)
        e = (Q5PairRec *)((char *)a + a->off) + a->count;
    return e;
}
static __inline Q5PairRec *q5_pairs_begin(Q5PairArr *a)
{
    Q5PairRec *b = 0;
    if (a->off != -1)
        b = (Q5PairRec *)((char *)a + a->off);
    return b;
}

/* Swing_DLL.xex 0x886D5F78: walk the owner's self-relative 0x28-byte pair records (+0x70) and return the first that
 * ga6_pair_accepts_886D0CE0 accepts in *out */
/* byte-gap: 36 off (perm not run); LTCG: the target keeps f4 live across the calls */
unsigned char ts4_find_accepted_pair_886D5F78(Ga6Pair2 *self, Q5PairOwner *o, void *unused, Q5PairRec **out, float t)
{
    unsigned char r = 0;
    Q5PairRec *end = q5_pairs_end(&o->pairs);
    Q5PairRec *it;
    (void)unused;
    for (it = q5_pairs_begin(&o->pairs); it != end; it++) {
        r = ga6_pair_accepts_886D0CE0(self, t, (Ga6Pair2 *)it);
        if (r) {
            *out = it;
            break;
        }
    }
    return r;
}

typedef struct Q5Stat Q5Stat; /* state object, see ts4_set_state_4_8887C9A8 */
typedef struct Q5IdSlot { int id; } Q5IdSlot;
typedef struct Q5SlotTables { char pad[0xac]; Q5IdSlot **ids_begin; Q5IdSlot **ids_end; char padb4[4];
    Q5Stat **stats_begin; Q5Stat **stats_end; char padc0[0x1471]; unsigned char dirty; } Q5SlotTables;
extern void ts4_set_state_4_8887C9A8(Q5Stat *t);

/* Swing_DLL.xex 0x888C9940: release slot idx: clear its id record to -1, reset its stats object to state 4 (8887C9A8)
 * when present, then mark the tables dirty (+0x1531) */
/* byte-gap: 33 off (perm not run); LTCG clrrwi on the vector bounds */
void ts4_slot_release_888C9940(Q5SlotTables *self, u32 idx)
{
    if (idx < (u32)(self->ids_end - self->ids_begin))
        self->ids_begin[idx]->id = -1;
    if (idx < (u32)(self->stats_end - self->stats_begin))
        ts4_set_state_4_8887C9A8(self->stats_begin[idx]);
    self->dirty = 1;
}

typedef struct Q5SessCtx1C { char pad[0x1c]; void *events; } Q5SessCtx1C;
extern Q5SessCtx1C *g_ts4_session_context;
extern void *g_ts4_session_state;
extern void fn_8893E280(void *events, const u32 *key);
extern void *ts4_create_linked_object_881542F8(void *state, u32 hash);
extern void ts4_guarded_update_88151560(void *state, void *obj);

/* Swing_DLL.xex 0x888E5190: when the session context has an event target (+0x1c), post event 0x60905E80 to it (8893E280),
 * then create and submit linked objects 0xD98C63D3 and 0xC7B1B848 on the session state */
/* byte-gap: 34 off (perm not run); LTCG clrrwi on the event target pointer */
void ts4_session_post_pair_888E5190(void)
{
    Q5SessCtx1C *ctx = g_ts4_session_context;
    if (ctx && ctx->events) {
        void *ev = ctx->events;
        if (ev) {
            u32 key = 0x60905E80u;
            fn_8893E280(ev, &key);
        }
        ts4_guarded_update_88151560(g_ts4_session_state,
            ts4_create_linked_object_881542F8(g_ts4_session_state, 0xD98C63D3u));
        ts4_guarded_update_88151560(g_ts4_session_state,
            ts4_create_linked_object_881542F8(g_ts4_session_state, 0xC7B1B848u));
    }
}

extern char *strcpy(char *, const char *);
extern char *strcat(char *, const char *);
#ifdef _MSC_VER
#pragma intrinsic(strcpy, strcat)
#endif
extern char lbl_880D2EFC[]; /* "\\" */
extern void fn_88611F10(char *out);

/* Swing_DLL.xex 0x88885408: out = "Locale\\" + locale code (88611F10) + "\\" */
/* byte-gap: 2 off (perm not run); the split has no relocation on the target's literal load (lis/ld 0x880DF1F0), so the candidate's relocated literal cannot byte-compare */
void ts4_locale_dir_88885408(char *out)
{
    char code[16];
    fn_88611F10(code);
    strcpy(out, "Locale\\");
    strcat(out, code);
    strcat(out, lbl_880D2EFC);
}

typedef struct Q5Str { char *b; char *e; char *c; } Q5Str;
typedef struct Q5Str16 { char *b; char *e; char *c; void *alloc; } Q5Str16;
typedef struct Q5Sink Q5Sink;
typedef struct Q5SinkVt { void *slots[0x13]; int (*query)(Q5Sink *self, char *text); } Q5SinkVt;
struct Q5Sink { Q5SinkVt *vt; };
typedef struct Q5Engine2A4 { char pad[0x2a4]; Q5Sink *sink; } Q5Engine2A4;
typedef struct Q5Named { char pad[0x1c]; int active; char pad20[8]; Q5Str prefix; } Q5Named;
extern Q5Engine2A4 *lbl_88D45B1C;
extern Q5Str *fn_88163300(Q5Str *out, const Q5Str *a, const Q5Str *b);
extern void *ts4_if_call_seq_u32_off0_8816D140(Q5Str16 *self, Q5Str *s);
extern void ts4_destroy_owned_object(void *p);

/* Swing_DLL.xex 0x88888E40: when the engine has a text sink (+0x2a4) and this object is active (+0x1c), join the +0x28
 * prefix with text, convert it (8816D140), query the sink through slot +0x4c and return the answer */
/* byte-gap: 6 off (perm not run); the target tests both words with cmpwi and keeps the converted text in r30, the answer in r31 */
int ts4_query_prefixed_88888E40(Q5Named *self, const Q5Str *text)
{
    int r = 0;
    if (lbl_88D45B1C->sink && self->active) {
        Q5Str joined;
        Q5Str16 out;
        char *t;
        ts4_if_call_seq_u32_off0_8816D140(&out, fn_88163300(&joined, &self->prefix, text));
        ts4_destroy_owned_object(joined.b);
        t = out.b;
        r = lbl_88D45B1C->sink->vt->query(lbl_88D45B1C->sink, t);
        ts4_destroy_owned_object(t);
    }
    return r;
}

typedef struct Q5Handle { u32 h; } Q5Handle;
typedef struct Q5NamedId { char pad[0x1c]; u32 id; char pad20[8]; Q5Str prefix; } Q5NamedId;
extern Q5Handle *ts4_if_get_u32_off0_8861AB10(Q5Handle *out, Q5Sink *sink, u32 id, char *name, u32 a, u32 b);

/* Swing_DLL.xex 0x88888EE8: *ret = 0; when the engine has a text sink and this object has an id (+0x1c), join the prefix
 * with text, convert it and look the handle up through 8861AB10 (sink, id, text, a, b) */
/* byte-gap: 9 off (perm not run); register order of the saved arguments and the converted text */
Q5Handle *ts4_named_lookup_88888EE8(Q5Handle *ret, Q5NamedId *self, const Q5Str *text, u32 a, u32 unused, u32 b)
{
    (void)unused;
    ret->h = 0;
    if (lbl_88D45B1C->sink && self->id) {
        Q5Str joined;
        Q5Str16 out;
        Q5Handle tmp;
        char *t;
        ts4_if_call_seq_u32_off0_8816D140(&out, fn_88163300(&joined, &self->prefix, text));
        ts4_destroy_owned_object(joined.b);
        t = out.b;
        ret->h = ts4_if_get_u32_off0_8861AB10(&tmp, lbl_88D45B1C->sink, self->id, t, a, b)->h;
        ts4_destroy_owned_object(t);
    }
    return ret;
}

#include "ts4_vector.h"
typedef struct Q5RelVec4 { int off; int count; int cap; } Q5RelVec4;
typedef struct Q5Frame48 { int off; int count; char pad[0x28]; } Q5Frame48;
typedef struct Q5RelFrames { int off; int count; } Q5RelFrames;
typedef struct Q5AnimSrc { char pad[0x38c]; Q5RelFrames frames; } Q5AnimSrc;
typedef struct Q5PtrVec { int *begin; int *end; } Q5PtrVec;
typedef struct Q5Planner { char pad[0x14]; Q5AnimSrc *src; char pad18[0x74]; Q5PtrVec layers; } Q5Planner;

static __inline int q5_size(const Q5PtrVec *v) { return v->end - v->begin; }
static __inline Q5Frame48 *q5_frame(Q5RelFrames *fr, int i)
{
    return (Q5Frame48 *)((char *)fr + fr->off) + i;
}

/* Swing_DLL.xex 0x886C80C0: copy the frame record selected by min(layer count, frame count) - 1 into out: count clamped to
 * out->cap, then that many 16-byte vectors between the self-relative buffers */
/* byte-gap: 18 off (perm best 18); r10/r11 allocation and the begin/end load order */
void ts4_planner_copy_frame_886C80C0(Q5Planner *self, Q5RelVec4 *out)
{
    int n = q5_size(&self->layers);
    if (n > 0) {
        Q5AnimSrc *s = self->src;
        int idx = n - 1;
        Q5Frame48 *f;
        int cnt;
        int i;
        if (s->frames.count - 1 < idx)
            idx = s->frames.count - 1;
        f = q5_frame(&s->frames, idx);
        cnt = f->count;
        if (cnt >= out->cap)
            cnt = out->cap;
        out->count = cnt;
        for (i = 0; i < cnt; i++)
            ((__vector4 *)((char *)out + out->off))[i] = ((__vector4 *)((char *)f + f->off))[i];
    }
}

typedef struct Q5Rc { const void *vt; long rc; } Q5Rc;
typedef struct Q5TextKey { unsigned hash; } Q5TextKey;
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif
extern void *lbl_88D45290;
extern Q5TextKey *ts4_assign_text_from_c_string(Q5TextKey *out, const char *s);
extern unsigned char fn_88640510(void *mgr, Q5TextKey *name, Q5Rc **handle, int flags);
extern long ts4_if_atomic_interlocked_dec_881876D0(Q5Rc *p);

/* Swing_DLL.xex 0x886408C8: look the named scene object up (88640510); on success return it in *out with a new reference,
 * else 0; *out2 = 0; drop the lookup's reference */
/* byte-gap: 8 off (perm best 8); prologue scheduling only */
void ts4_scene_find_886408C8(const char *name, Q5Rc **out, Q5Rc **out2, int flags)
{
    void *mgr = lbl_88D45290;
    Q5Rc *h = 0;
    Q5TextKey key;
    unsigned char ok = fn_88640510(mgr, ts4_assign_text_from_c_string(&key, name), &h, flags);
    Q5Rc *p = h;
    if (ok) {
        _InterlockedIncrement(&p->rc);
        *out = p;
    } else {
        *out = 0;
    }
    *out2 = 0;
    if (p)
        ts4_if_atomic_interlocked_dec_881876D0(p);
}

typedef struct Q5Role20 { char pad[0x1c]; int slot; } Q5Role20;
typedef struct Q5RelRoles { int off; } Q5RelRoles;
typedef struct Q5SlotCfg {
    char pad[0x44];
    Q5RelRoles roles;   /* 0x44 */
    char pad48[0x14];
    u32 mode;           /* 0x5c */
    char pad60[8];
    u32 variant;        /* 0x68 */
} Q5SlotCfg;
typedef struct Q5Slot3C { char pad[0x38]; unsigned char active; char pad39[3]; } Q5Slot3C;
typedef struct Q5SlotHost {
    char pad[0x1c];
    Q5Slot3C slots[8];  /* 0x1c */
    char pad1fc[0x204 - 0x1c - 8 * 0x3c];
    Q5SlotCfg *cfg;     /* 0x204 */
} Q5SlotHost;

static Q5Role20 *q5_role_at(Q5RelRoles *r, u32 i)
{
    int o = r->off;
    return (Q5Role20 *)((char *)r + (i * 0x20 + o));
}

static int q5_roles_have(Q5RelRoles *r, u32 n, int idx)
{
    u32 i;
    for (i = 0; i < n; i++) {
        if (q5_role_at(r, i)->slot == idx)
            return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x888C5E10: recompute slot idx's active flag: it is set when one of the first n roles of the config (+0x204,
 * self-relative 0x20-byte records at +0x44) names idx; n is 1, 4 or 2/4 by config mode and variant */
/* byte-gap: 22 off (perm not run); loop induction register and zero sharing */
void ts4_slot_refresh_active_888C5E10(Q5SlotHost *self, int idx)
{
    Q5Slot3C *s = &self->slots[idx];
    Q5SlotCfg *cfg;
    u32 n;
    s->active = 0;
    cfg = self->cfg;
    if (cfg->mode == 0xFE32DF8Du)
        n = 1;
    else if (cfg->mode == 0xDD4BF7D9u)
        n = 4;
    else {
        n = 2;
        if (cfg->variant == 0xFB595DB2u)
            n = 4;
    }
    if (q5_roles_have(&cfg->roles, n, idx))
        s->active = 1;
}

typedef unsigned long long u64;
typedef struct Q5Node60Tail {
    u32 e14, e18, e1c;
    unsigned char f20, f21, f22;
} Q5Node60Tail;
typedef struct Q5Node60Stamp {
    u64 g28;
    u32 h30;
    unsigned char i34;
} Q5Node60Stamp;
typedef struct Q5Node60 {
    u32 key;            /* 0x00 */
    void *a;            /* 0x04 */
    void *b;            /* 0x08 */
    u32 c;              /* 0x0c */
    unsigned char d;    /* 0x10 */
    Q5Node60Tail t;     /* 0x14 */
    Q5Node60Stamp s;    /* 0x28 */
} Q5Node60;
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);

static void q5_node60_tail_init(Q5Node60Tail *t)
{
    t->e14 = 0;
    t->e18 = 0;
    t->e1c = 0;
    t->f20 = 0;
    t->f21 = 0;
    t->f22 = 0;
}

static void q5_node60_stamp_init(Q5Node60Stamp *s)
{
    s->g28 = 0;
    s->h30 = 0;
    s->i34 = 0;
}

static void q5_node60_init(Q5Node60 *n)
{
    q5_node60_tail_init(&n->t);
    q5_node60_stamp_init(&n->s);
    n->key = 0x629B9E5Bu;
    n->a = 0;
    n->b = 0;
    n->c = 0;
    n->d = 0;
}

/* Swing_DLL.xex 0x887EC8C0: allocate a 0x60-byte node (88613268, align 8, pool 2), default-construct it (key 0x629B9E5B,
 * all other fields zero), then set key = *key, a and b */
/* byte-gap: 7 off (perm best 7); li/lis scheduling of the two constants and the key register */
Q5Node60 *ts4_node60_create_887EC8C0(void *b, void *a, const u32 *key)
{
    u32 k;
    Q5Node60 *n = (Q5Node60 *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x60, 8, 0, 2);
    if (n) {
        q5_node60_init(n);
        k = *key;
        n->b = b;
        n->a = a;
        n->key = k;
        return n;
    }
    return 0;
}
