/*
 * DRAFT (not part of the matching build). PR2.
 * Swing_DLL.xex fn_8890BCA0 (0x8890BCA0, size 0x764): CLoadingManager (vtable 0x880DB408) slot 12, called
 * by the module manager (fn_886345E0) when the new Part has finished starting (state 4 -> 5):
 * (self, req = ModuleManager record, desc = new module record).
 *
 * Byte match: no. fn_check: about 450 of 473 instructions differ (candidate 0x76C bytes; about 110 differ
 * after normalising stack offsets and registers: saved-register assignment, a hoisted 0xFFFFF constant).
 * fn_equiv: UNCHECKED, the original faults on 59 of 60 seeded inputs (too few valid trials)
 * (work/equiv/pr2_8890BCA0.json).
 *
 * What it does, in order: [0x88D45B06] = 0 (Lua IsInLoadingUI false); lock engine+0x250; remember the
 * current id for the TCR actions; mark every RUI row (+0xa4, stride 0x98) dirty; network property from
 * "PlayerCreator key present in engine+0x2c0"; stop music channel 0x713E7404 and pick the part's music
 * (PressStart for PracticeGround, Season, PlayerCreator, RandomMusic; none for Minigame and InGame);
 * per-part extras; then the in-place parts (InGame, PracticeGround, LockerRoom, PlayerCreator, Minigame,
 * 0x04F0A963, 0x3D616581, 0xF6875E97, 0x41A6A445) get fn_8890AA50(0, ..), engine+0x278 = 4 and
 * ChangeScene("") (when key 0xDD3795AD is absent from engine+0x2c0 or desc has plugin 0x4DBA60F6); other
 * parts get fn_8890AA50(1, ..) and ChangeScene("") only with that plugin. Then: self's flag list set, service
 * 0x5BCBE4C1 +0x20 = 1, fn_888E8A80, script engine +0x70 resumed (fn_88210B18), self+0x7c = 0,
 * fn_888CDC48(desc), queued message box; for InGame: services FF3C5689, D2652B1A, A8D40302 +0x20 = 1,
 * fn_8883D8D0 and (MatchType != 0xFB595DB2) fn_8884E478 on [0x88D459E0], fn_888693C8; unlock.
 * So for InGame the engine state is 4 after the switch, as for the practice ground (docs/frontend-map.md
 * says InGame gets S4Loading from slots 13/14: that happens earlier, at the start of the switch).
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
typedef struct Tri { u32 a, b, c; } Tri;
typedef struct Str { char *p; u32 a, b; } Str;
typedef struct Ts4HashTable Ts4HashTable;
typedef union Scratch { u32 w; Str s; } Scratch;   /* sp+0x50 in the original, reused */

/* part hashes (crc32 of the Part name) */
#define PART_PRACTICE_GROUND 0xCFC05A31u
#define PART_INGAME          0x1DCA7285u
#define PART_ONLINE          0x999EBBDCu
#define PART_PLAYER_CREATOR  0xA6F6E957u
#define PART_LOCKER_ROOM     0x1BC17295u
#define PART_MINIGAME        0x6D2794E5u

typedef struct Lock Lock;
typedef struct LockVt { void *s0; void (*lock)(Lock *); void (*unlock)(Lock *); } LockVt;
struct Lock { LockVt *vt; };
typedef struct Flag8 { u8 pad[8]; u8 b8; } Flag8;
typedef struct Flag8Vec { Flag8 **begin; Flag8 **end; } Flag8Vec;
typedef struct Item4 { u8 pad[4]; u32 key; u8 b8; } Item4;
typedef struct ItemVec { Item4 **begin; Item4 **end; } ItemVec;
typedef struct CbTable { u8 pad[0xc]; void (*fc)(int); } CbTable;
typedef struct GameObj { u8 pad[9]; u8 b9; u8 pad0a[0x2ae6]; CbTable cbs; } GameObj;
typedef struct Engine {
    u8 pad[0x250];
    Lock lock;               /* +0x250 */
    u8 pad254[0x24];
    u32 state;               /* +0x278 engine state (2 running, 4 in-place part, 6/7 switching) */
    u32 f27c;                /* +0x27c current id */
    u8 pad280[0x40];
    u32 *keys_begin;         /* +0x2c0 */
    u32 *keys_end;           /* +0x2c4 */
    u8 pad2c8[4];
    GameObj *game;           /* +0x2cc */
} Engine;
typedef struct TcrActions { u8 pad[0x5c]; u8 b5c; u8 b5d; } TcrActions;
typedef struct Row98 { u8 pad[0x8a]; u8 dirty; u8 pad2[0x98 - 0x8b]; } Row98;
typedef struct RuiMgr { u8 pad[0xa4]; Row98 *rows; u8 pad2[0x1c4 - 0xa8]; u32 count; } RuiMgr;
typedef struct NetState { u8 pad[0x94]; u8 b94; u8 b95; } NetState;
typedef struct LoadState { u8 pad[0x4c]; ItemVec *items; } LoadState;
typedef struct Music Music;
typedef struct MusicVt { u8 pad[0x34]; void (*stop)(Music *m, u32 *key); } MusicVt;
struct Music { MusicVt *vt; };
typedef struct Svc20 { u8 pad[0x20]; u8 b20; } Svc20;
typedef struct Sub70 { u8 pad[0x30]; u8 b30; } Sub70;
typedef struct ScriptEngine { u8 pad[0x70]; Sub70 *f70; } ScriptEngine;
typedef struct OnlineCtx { u8 pad[0x18c]; void *f18c; } OnlineCtx;
typedef struct Obj7c { u8 pad[0x7c]; u8 b7c; } Obj7c;
typedef struct Rules { u8 pad[0x68]; u32 match_type; } Rules;
typedef struct LoadReq { u8 pad[0x18]; u32 part; u32 prev; u8 pad20[4]; u32 f24; } LoadReq;
typedef struct LoadingMgr { u8 pad[0x1c]; Tri t1c; u8 pad28[0x44]; Flag8Vec v6c; u8 pad74[8]; u8 b7c; } LoadingMgr;

extern Engine *lbl_88D45B1C;
extern TcrActions *lbl_88D4593C;
extern u32 lbl_88D46350;
extern RuiMgr *lbl_88D45A60;
extern u8 lbl_88D45B06;
extern u8 lbl_88D4591A;
extern NetState *lbl_88D458E0;
extern u8 *lbl_88D45AD4;
extern Music *lbl_88D45A64;
extern OnlineCtx *g_ts4_online_context;
extern void *lbl_88D45954;
extern CbTable lbl_88C6BE68;
extern void *lbl_88D45960;
extern ScriptEngine *lbl_88D41FC4;
extern Obj7c *lbl_88D459C4;
extern void *lbl_88D459DC;
extern u32 lbl_88C6B82C[3];
extern void *lbl_88D459E0;
extern void *lbl_88D459D0;
extern Ts4HashTable *lbl_88D458F0;
extern const char lbl_880C1320[];
extern const char lbl_880D8610[];
extern const char lbl_880D8628[];
extern const char lbl_880D863C[];
extern const char lbl_880D8658[];
extern const char lbl_880D8670[];

extern u32 *fn_88165170(u32 *begin, u32 *end, u32 *key);
extern void ts4_net_set_prop_byte_8890A948(Tri t, u32 a, u32 b);
extern void ts4_assign_text_from_c_string(Str *dst, const char *s);
extern void ts4_obj_vcall_28_then_2c_88778E88(Music *m, u32 *key, Str *name, u32 a);
extern void ts4_call_seq_u32_off0_8819AD80(Str *s);
extern void fn_889B68A8(void *p);
extern void fn_888E1DD0(void);
extern void ts4_if_set_u32_off0_8862BE08(void *out, const void *path);
extern void ts4_get_u32_off0_8822AFE8(void *a, void *b);
extern void fn_8890AA50(u32 a, Tri t);
extern u8 fn_888CDBC8(void *p, u32 key);
extern void ts4_assign_formatted_text(Str *dst, const char *text);
extern void fn_887BFDA8(RuiMgr *m, Str *name, u32 a, u32 b, u32 c);
extern Svc20 *ts4_find_service(u32 id);
extern void fn_888E8A80(void *p, u32 *part);
extern void fn_88210B18(Sub70 *p);
extern void fn_888CDC48(void *p);
extern void fn_8878C020(RuiMgr *m, u32 *v, u32 a, u32 b);
extern void ts4_loop_call_seq_u32_off5c_8886B788(void *p);
extern void fn_888FE0C8(void);
extern void fn_8883D8D0(void *p);
extern void *ts4_hash_find_881AB900(Ts4HashTable *table, u32 hash, Tri h);
extern void fn_8884E478(void *p);
extern void fn_888693C8(void);

INL u8 tcr_busy(TcrActions *t)
{
    if (t->b5c || t->b5d)
        return 1;
    return 0;
}

INL u8 handle_is_null(Tri *h, u32 nul)
{
    if (h->a == 0 || h->b == nul)
        return 1;
    return 0;
}

INL u8 game_flag9(GameObj *g)
{
    if ((long)g != 0 && g->b9 != 0)
        return 1;
    return 0;
}

INL CbTable *game_cbs(GameObj *g)
{
    if ((long)g != 0)
        return &g->cbs;
    return &lbl_88C6BE68;
}

INL void change_scene_empty(void)
{
    Str t;
    ts4_assign_formatted_text(&t, lbl_880C1320);
    fn_887BFDA8(lbl_88D45A60, &t, 0, 0, 0);
}

INL void play_music(Scratch *t, const char *name, u32 *k)
{
    ts4_assign_text_from_c_string(&t->s, name);
    *k = 0x713E7404;
    ts4_obj_vcall_28_then_2c_88778E88(lbl_88D45A64, k, &t->s, 1);
    ts4_call_seq_u32_off0_8819AD80(&t->s);
}

INL void mark_item(ItemVec *v, u32 key)
{
    Item4 **it;
    for (it = v->begin; it < v->end; it++) {
        if ((*it)->key == key) {
            (*it)->b8 = 1;
            break;
        }
    }
}

/* 0x8890BCA0: CLoadingManager vtable slot 12 (start the requested Part) */
void ts4_loading_mgr_start_part_8890BCA0(LoadingMgr *self, LoadReq *req, void *ctx)
{
    Lock *lk;
    Scratch s50;
    u32 k1, k2, k3, k4;
    u32 *pending;
    u32 part;
    u32 prev;
    u32 *partp;
    lbl_88D45B06 = 0;
    lk = &lbl_88D45B1C->lock;
    lk->vt->lock(lk);
    {
        TcrActions *t = lbl_88D4593C;
        Engine *e = lbl_88D45B1C;
        pending = &lbl_88D46350;
        if (tcr_busy(t) || t->b5c)
            *pending = e->f27c;
    }
    lbl_88D4591A = 0;
    {
        RuiMgr *m = lbl_88D45A60;
        if (m != 0) {
            u32 i;
            for (i = 0; i < m->count; i++)
                m->rows[i].dirty = 1;
        }
    }
    {
        Engine *e = lbl_88D45B1C;
        u32 *it;
        s50.w = PART_PLAYER_CREATOR;
        it = fn_88165170(e->keys_begin, e->keys_end, &s50.w);
        ts4_net_set_prop_byte_8890A948(self->t1c, 1, it == e->keys_end);
    }
    {
        NetState *n = lbl_88D458E0;
        if (n != 0) {
            u8 *ls = lbl_88D45AD4;
            n->b95 = 1;
            n->b94 = 1;
            if (ls != 0)
                ls[0x15820] = 1;
        }
    }
    part = req->part;
    prev = req->prev;
    partp = &req->part;
    {
        u32 k = 0x713E7404;
        lbl_88D45A64->vt->stop(lbl_88D45A64, &k);
    }
    if (part == PART_PRACTICE_GROUND) {
        if (game_flag9(lbl_88D45B1C->game) && prev == lbl_88D45B1C->f27c)
            goto callbacks;
        play_music(&s50, lbl_880D8610, &k1);
        goto callbacks;
    }
    if (part == 0xF7485E9F || part == 0x876232A0)
        play_music(&s50, lbl_880D8628, &k4);
    else if (part == PART_PLAYER_CREATOR || part == PART_LOCKER_ROOM)
        play_music(&s50, lbl_880D863C, &k3);
    else if (part != PART_MINIGAME && part != PART_INGAME)
        play_music(&s50, lbl_880D8658, &k2);
    if (part == 0xA91B3508) {
        OnlineCtx *oc = g_ts4_online_context;
        if (oc != 0)
            fn_889B68A8(oc->f18c);
        goto callbacks;
    }
    if (part == PART_PLAYER_CREATOR) {
        if (req->prev == PART_ONLINE && lbl_88D45954 != 0)
            fn_888E1DD0();
    } else if (part != PART_LOCKER_ROOM) {
        goto check;
    }
    {
        Tri h;
        ts4_if_set_u32_off0_8862BE08(&h, lbl_880D8670);
        if (!handle_is_null(&h, 0xFFFFF)) {
            s50.w = 0;
            ts4_get_u32_off0_8822AFE8(&h, &s50.w);
        }
    }
check:
    if (part == PART_INGAME)
        goto in_place;
    if (part == PART_MINIGAME)
        goto classify;
callbacks:
    if (game_cbs(lbl_88D45B1C->game)->fc != 0)
        game_cbs(lbl_88D45B1C->game)->fc(0);
classify:
    if (part == PART_INGAME || part == 0x04F0A963 || part == 0x3D616581 || part == PART_PRACTICE_GROUND ||
        part == 0xF6875E97 || part == PART_MINIGAME || part == 0x41A6A445 || part == PART_PLAYER_CREATOR ||
        part == PART_LOCKER_ROOM)
        goto in_place;
    fn_8890AA50(1, self->t1c);
    if (fn_888CDBC8(ctx, 0x4DBA60F6))
        change_scene_empty();
    goto tail;
in_place:
    fn_8890AA50(0, self->t1c);
    {
        Engine *e = lbl_88D45B1C;
        s50.w = 0xDD3795AD;
        e->state = 4;
        if (e->keys_end == fn_88165170(e->keys_begin, e->keys_end, &s50.w) || fn_888CDBC8(ctx, 0x4DBA60F6)) {
            change_scene_empty();
            if (part == 0x04F0A963) {
                LoadState *ls = (LoadState *)lbl_88D45AD4;
                mark_item(ls->items, 0x447B3DB6);
                mark_item(ls->items, 0x35657E15);
            }
        }
    }
tail:
    {
        Flag8 **end = self->v6c.end;
        Flag8 **it = self->v6c.begin;
        for (; end != it; it++)
            (*it)->b8 = 1;
    }
    {
        Svc20 *s = ts4_find_service(0x5BCBE4C1);
        if (s != 0)
            s->b20 = 1;
    }
    if (lbl_88D45960 != 0)
        fn_888E8A80(lbl_88D45960, partp);
    if (lbl_88D45A60 != 0) {
        ScriptEngine *se = lbl_88D41FC4;
        se->f70->b30 = 1;
        fn_88210B18(se->f70);
    }
    self->b7c = 0;
    fn_888CDC48(ctx);
    lbl_88D459C4->b7c = 0;
    if (*pending != 0) {
        fn_8878C020(lbl_88D45A60, pending, 5, 0);
        *pending = 0;
    }
    if (part == PART_PRACTICE_GROUND && prev != 0)
        ts4_loop_call_seq_u32_off5c_8886B788(lbl_88D459DC);
    fn_888FE0C8();
    if (part == PART_INGAME) {
        u32 *k = lbl_88C6B82C;
        int i;
        for (i = 3; i != 0; i--) {
            Svc20 *s = ts4_find_service(*k);
            if (s != 0)
                s->b20 = 1;
            k++;
        }
        if (lbl_88D459E0 != 0) {
            Tri h;
            fn_8883D8D0(lbl_88D459E0);
            h.a = 0;
            h.b = 0xFFFFF;
            h.c = 0;
            if (((Rules *)ts4_hash_find_881AB900(lbl_88D458F0, 0x7E35EE14, h))->match_type != 0xFB595DB2)
                fn_8884E478(lbl_88D459E0);
        }
        if (lbl_88D459D0 != 0)
            fn_888693C8();
    }
    lk->vt->unlock(lk);
}
