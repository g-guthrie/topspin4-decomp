/*
 * DRAFT (not part of the matching build). PR2.
 * Swing_DLL.xex fn_8890B068 (0x8890B068, size 0xA90): CLoadingManager (vtable 0x880DB408) slot 17, the
 * load-phase notification the module manager (fn_886345E0) sends with mode 0..4:
 * (self, req = ModuleManager record, desc = new module record, mode, x).
 *
 * Byte match: no. fn_check: about 650 of 676 instructions differ (candidate 0xA98 bytes; about 370 differ
 * after normalising stack offsets and registers). Control flow and calls follow the original.
 * fn_equiv: UNCHECKED, coverage 45% (56/124 blocks): all 2922 valid trials of 3443 agree, but the harness
 * never seeds mode 0 (work/equiv/pr2_8890B068.json).
 *
 * What it does:
 *   mode 4 first: clear +0xE4 of object 0x3BAB2B6F in [0x88D45B38]. Always: self+0x7c = 1.
 *   mode 0 (load begins): game callback (+0x2af0 table, slot +0xc) with 1, [0x88D459C4]+0x7c = 1, leave the
 *     minigame pad state, mark every module flag object, ChangeGameStage value 0x98BF80FC when the part
 *     changes, stop music channel 0x713E7404 and play Root/Music/Loading, GameDB root +0x1b4 = 0xDFA2AFF1,
 *     +0x1bc = 0, fn_8890AA50(1, cameras), clear self's flag list, fn_88902008(self, req), fn_88902238(self,1),
 *     publish the cameras at +0x34 to the RUI manager (+0x2b8..) and [0x88D45AD4] (+0xbc..);
 *     for a first load (req->prev == 0) start service 0xABECF1ED/0xB01F4F95.
 *   mode 1: refresh handle +0x34 when there is a previous part; mode 3: nothing; then fn_88902238(self, 0)
 *     and publish the +0x34 cameras.
 *   mode 2 (data loaded): fn_88902238(self, 1); set CurrentVenue/@Licensed when the venue key is in self's
 *     list of 7 (+0x80); choose the sub-module (SubModuleManager/@DefaultModule, Module[@Name="InGame"]);
 *     reset PlayerList for Online; RulesInfo +0x30 = 0; publish the cameras at +0x4c; PlayerInfoList flags for
 *     PlayerCreator/LockerRoom/0x41A6A445; per part: InGame -> fn_888E6FF8 (MatchType: hash table entry
 *     0xC750E1AC +0x10 = +0x14), PlayerCreator -> fn_888E6E88, PracticeGround/0xF6875E97 -> fn_888DDB28,
 *     Minigame -> fn_888CD6D0; then fn_888E71A8, fn_888E70F0, fn_886EAB58.
 *   mode 4 (in-place part): PlayerCreator presets and camera sequence 0x5392B268, LockerRoom camera.
 *   End of modes 0 and 2: [0x88D459C4]+0x3c = 1 for InGame/PracticeGround/0xF6875E97/Minigame, else 0.
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

#define PART_PRACTICE_GROUND 0xCFC05A31u
#define PART_INGAME          0x1DCA7285u
#define PART_ONLINE          0x999EBBDCu
#define PART_PLAYER_CREATOR  0xA6F6E957u
#define PART_LOCKER_ROOM     0x1BC17295u
#define PART_MINIGAME        0x6D2794E5u

typedef struct Flag8 { u8 pad[8]; u8 b8; } Flag8;
typedef struct Flag8Vec { Flag8 **begin; Flag8 **end; } Flag8Vec;
typedef struct CbTable { u8 pad[0xc]; void (*fc)(int); } CbTable;
typedef struct GameObj { u8 pad[0x2af0]; CbTable cbs; } GameObj;
typedef struct ModList { u8 pad[0x24]; Flag8Vec flags; } ModList;
typedef struct Engine { u8 pad[0x234]; ModList *modules; u8 pad238[0x94]; GameObj *game; } Engine;
typedef struct RuiMgr { u8 pad[0x1e4]; void *f1e4; u8 pad1e8[0xd0]; Tri cam_b; Tri cam_a; u8 pad2d0[0x44]; u32 master_pad; } RuiMgr;
typedef struct LoadState { u8 pad[0xbc]; Tri cam_a; Tri cam_b; } LoadState;
typedef struct Music Music;
typedef struct MusicVt { u8 pad[0x34]; void (*stop)(Music *m, u32 *key); } MusicVt;
struct Music { MusicVt *vt; };
typedef struct Svc { u8 pad[8]; u8 b8; u8 pad9[0x17]; u8 b20; } Svc;
typedef struct Obj7c { u8 pad[0x3c]; u32 in_match_part; u8 pad40[0x3c]; u8 b7c; } Obj7c;
typedef struct TcrActions { u8 pad[0x60]; u32 *stage; } TcrActions;
typedef struct NetState { u8 pad[0x95]; u8 b95; } NetState;
typedef struct GameDbRoot { u8 pad[0x1b4]; u32 f1b4; u8 pad1b8[4]; u32 f1bc; } GameDbRoot;
typedef struct PadObj { u8 pad[0x1a]; u8 b1a; } PadObj;
typedef struct ObjE4 { u8 pad[0xe4]; u8 be4; } ObjE4;
typedef struct Vt14 Vt14;
typedef struct Vt14Vt { u8 pad[0x14]; void (*f14)(Vt14 *); } Vt14Vt;
struct Vt14 { Vt14Vt *vt; };
typedef struct G5CC0 { u8 pad[0x68c]; Vt14 *f68c; } G5CC0;
typedef struct PcSettings { u8 pad[0x40]; u32 f40; u8 pad44[0x11]; u8 b55; u8 b56; u8 b57; u8 b58; u8 b59; u8 b5a; u8 pad5b[0xa1]; u8 bfc; u8 padfd[4]; u8 b101; u8 b102; } PcSettings;
typedef struct PlayerCreator { u8 pad[0x80]; PcSettings *settings; u8 pad84[0x38]; u8 bbc; u8 bbd; } PlayerCreator;
typedef struct NodeGet NodeGet;
typedef struct NodeGetVt { u8 pad[0x4c]; u8 *(*get)(NodeGet *n, int i); } NodeGetVt;
struct NodeGet { NodeGetVt *vt; };
typedef struct Player { u8 pad[0x8c]; NodeGet *node; u8 pad90[0xf0]; int pad_index; } Player;
typedef struct PlayerList { u8 pad[0x20]; Player **begin; Player **end; } PlayerList;
typedef struct XNode XNode;
typedef struct XHandle XHandle;
typedef struct XNodeVt { u8 pad[0x28]; u8 *(*attr)(XNode *n, XHandle *h, u32 b, int c); } XNodeVt;
struct XNode { XNodeVt *vt; };
struct XHandle { XNode *node; u32 b, c; };   /* 12-byte XData attribute handle */
typedef struct LoadReq { u8 pad[0x18]; u32 part; u32 prev; u8 pad20[4]; u32 f24; u8 pad28[0xc]; u8 b34; } LoadReq;
typedef struct LoadingMgr {
    u8 pad[0x34];
    Tri cam1_a;              /* +0x34 */
    Tri cam1_b;              /* +0x40 */
    Tri cam_a;               /* +0x4c */
    Tri cam_b;               /* +0x58 */
    u8 pad64[8];
    Flag8Vec v6c;            /* +0x6c */
    u8 pad74[8];
    u8 b7c;                  /* +0x7c */
    u8 pad7d[3];
    u32 licensed_venues[7];  /* +0x80 */
} LoadingMgr;

extern void *lbl_88D45B38;
extern Engine *lbl_88D45B1C;
extern RuiMgr *lbl_88D45A60;
extern LoadState *lbl_88D45AD4;
extern Obj7c *lbl_88D459C4;
extern void *lbl_88D45910;
extern G5CC0 lbl_88D45CC0;
extern CbTable lbl_88C6BE68;
extern void *lbl_88D45B34;
extern u8 lbl_88D4591A;
extern NetState *lbl_88D458E0;
extern TcrActions *lbl_88D4593C;
extern Music *lbl_88D45A64;
extern u8 lbl_88D45918;
extern PlayerCreator *lbl_88D45954;
extern PlayerList *lbl_88D459E0;
extern const char lbl_880CBA07[];
extern const char lbl_880D82D0[];
extern const char lbl_880D85CC[];
extern const char lbl_880D86C8[];
extern const char lbl_880D86E0[];
extern const char lbl_880D875C[];
extern const char lbl_880D878C[];
extern const char lbl_880D87C0[];
extern const char lbl_880D8808[];
extern const char lbl_880D885C[];
extern const char lbl_880D8888[];
extern const char lbl_880D88D0[];

extern ObjE4 *fn_88618998(void *g, u32 h);
extern void fn_888F70A0(void);
extern Svc *ts4_find_service(u32 id);
extern PadObj *fn_88614938(ModList *m, u32 pad);
extern void fn_888F67B8(u32 pad, void *p);
extern void ts4_loop_call_seq_u8_off4c_887A3848(void *p, u32 prev, u32 pad);
extern void ts4_assign_text_from_c_string(Str *dst, const char *s);
extern void ts4_obj_vcall_28_then_2c_88778E88(Music *m, u32 *key, Str *name, u32 a);
extern void ts4_call_seq_u32_off0_8819AD80(Str *s);
extern void ts4_if_set_u32_off0_8862C0E8(Tri *out, const char *path);
extern Tri *ts4_if_set_u32_off0_8862BE08(void *out, const void *path);
extern void ts4_get_u32_off0_8822AFE8(void *a, void *b);
extern void *fn_88923530(u32 pool, Tri h, u32 hash);
extern void fn_8890AA50(u32 a, Tri t);
extern void ts4_net_set_prop_byte_8890A948(Tri t, u32 a, u32 b);
extern void fn_88902008(LoadingMgr *self, LoadReq *req);
extern void fn_88902238(LoadingMgr *self, u32 begin);
extern u32 fn_8857C8C8(void);
extern void ts4_handle_forward_88610778(void *out, void *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(void *out, void *in, u32 *key, u32 z);
extern void ts4_clone_byte_with_object_context(void *p, const char *s);
extern void ts4_get_ts4_handle_forward_88610778_888CDB38(Tri t);
extern u8 ts4_gp0_xdata_get_bool_88163C60(Tri *h);
extern void fn_888E1258(PlayerCreator *p);
extern void fn_888DC320(PlayerCreator *p, float f);
extern void fn_88169350(u32 *out, Tri *in);
extern void fn_888E73B0(void *p);
extern void ts4_loop_call_seq_lbl_880D8300_888E7308(void);
extern void fn_888D7CF8(void *p);
extern u8 fn_888CDBC8(void *p, u32 key);
extern void fn_88641718(void);
extern void fn_888E6FF8(void);
extern void fn_888E6E88(LoadingMgr *self);
extern void ts4_hash_service_set_888CD6D0(LoadingMgr *self);
extern void ts4_get_ts4_find_service_888DDB28(void);
extern void fn_888E71A8(LoadReq *req);
extern void fn_888E70F0(LoadReq *req);
extern void fn_886EAB58(void);

INL u8 handle_is_null(Tri *h)
{
    if (h->a == 0 || h->b == 0xFFFFF)
        return 1;
    return 0;
}
INL CbTable *game_cbs(GameObj *g)
{
    if ((long)g != 0)
        return &g->cbs;
    return &lbl_88C6BE68;
}
INL void publish_cameras(Tri *a, Tri *b)
{
    Tri ca = *a, cb = *b;
    RuiMgr *m;
    fn_8857C8C8();
    m = lbl_88D45A60;
    if (m != 0) {
        m->cam_a = ca;
        m->cam_b = cb;
    }
    lbl_88D45AD4->cam_a = ca;
    lbl_88D45AD4->cam_b = cb;
}
INL void set_camera_sequence(u32 seq)
{
    Tri h;
    u32 v = seq;
    ts4_if_set_u32_off0_8862BE08(&h, lbl_880D875C);
    ts4_get_u32_off0_8822AFE8(&h, &v);
}
INL u8 *rel_base(u8 *n)
{
    return n + *(int *)n;
}

/* 0x8890B068: CLoadingManager vtable slot 17 (load phase notification). mode 0 = load begins,
 * 1 = intermediate, 2 = load finished (fills match data for the new part), 4 = in-place part switched. */
void ts4_loading_mgr_phase_8890B068(LoadingMgr *self, LoadReq *req, void *ctx, int mode)
{
    u32 part;
    Tri s50;    /* one scratch slot (sp+0x50) shared by several out-parameters, as in the original */
    if (mode == 4) {
        ObjE4 *o = fn_88618998(lbl_88D45B38, 0x3BAB2B6F);
        if (o != 0)
            o->be4 = 0;
    }
    self->b7c = 1;
    if (mode == 0) {
        RuiMgr *rui;
        if (game_cbs(lbl_88D45B1C->game)->fc != 0)
            game_cbs(lbl_88D45B1C->game)->fc(1);
        lbl_88D459C4->b7c = 1;
        if (lbl_88D45910 != 0) {
            Vt14 *o;
            fn_888F70A0();
            o = lbl_88D45CC0.f68c;
            o->vt->f14(o);
        }
        if (req->prev == PART_MINIGAME) {
            Svc *s = ts4_find_service(0xE3767AD6);
            PadObj *p;
            rui = lbl_88D45A60;
            p = fn_88614938(lbl_88D45B1C->modules, rui->master_pad);
            if (p != 0 && s != 0 && s->b20 == 1 && p->b1a)
                fn_888F67B8(rui->master_pad, lbl_88D45B34);
        }
        rui = lbl_88D45A60;
        {
            Flag8Vec *v = &lbl_88D45B1C->modules->flags;
            int n = v->end - v->begin;
            int i;
            for (i = 0; i < n; i++)
                v->begin[i]->b8 = 1;
        }
        if (lbl_88D4591A && rui != 0 && rui->f1e4 != 0)
            ts4_loop_call_seq_u8_off4c_887A3848(rui->f1e4, req->prev, rui->master_pad);
        if (lbl_88D458E0 != 0)
            lbl_88D458E0->b95 = 0;
        if (req->part != req->f24)
            *lbl_88D4593C->stage = 0x98BF80FC;
        if (lbl_88D45A64 != 0) {
            u32 k = 0x713E7404;
            u32 k2;
            Str t;
            lbl_88D45A64->vt->stop(lbl_88D45A64, &k);
            ts4_assign_text_from_c_string(&t, lbl_880D86C8);
            k2 = 0x713E7404;
            ts4_obj_vcall_28_then_2c_88778E88(lbl_88D45A64, &k2, &t, 1);
            ts4_call_seq_u32_off0_8819AD80(&t);
        }
        {
            Tri h;
            GameDbRoot *db;
            ts4_if_set_u32_off0_8862C0E8(&h, lbl_880D85CC);
            db = fn_88923530(h.c, h, 0xF895ECB1);
            db->f1b4 = 0xDFA2AFF1;
            db->f1bc = 0;
            lbl_88D45918 = 0;
        }
        fn_8890AA50(1, lbl_88D45AD4->cam_a);
        if (req->prev == 0) {
            Svc *s;
            ts4_net_set_prop_byte_8890A948(lbl_88D45AD4->cam_a, 1, 0);
            s = ts4_find_service(0xFD5F7168);
            if (s != 0)
                s->b8 = 0;
        }
        {
            Flag8 **end = self->v6c.end;
            Flag8 **it = self->v6c.begin;
            for (; end != it; it++)
                (*it)->b8 = 0;
        }
        fn_88902008(self, req);
    } else if (mode == 1) {
        if (req->prev != 0) {
            fn_8857C8C8();
            fn_8857C8C8();
            ts4_get_ts4_handle_forward_88610778_888CDB38(self->cam1_a);
        }
        goto close;
    } else if (mode == 4) {
        if (req->part == PART_PLAYER_CREATOR) {
            Tri h;
            u8 presets = 0;
            PlayerCreator *pc;
            ts4_if_set_u32_off0_8862BE08(&h, lbl_880D86E0);
            if (!handle_is_null(&h))
                presets = ts4_gp0_xdata_get_bool_88163C60(&h);
            if (!presets)
                set_camera_sequence(0x5392B268);
            fn_888E1258(lbl_88D45954);
            pc = lbl_88D45954;
            pc->settings->b59 = 0;
            pc->settings->b5a = 0;
            pc->settings->b55 = 1;
            pc->settings->b57 = 1;
            pc->settings->bfc = 1;
            pc->settings->b102 = 1;
            pc->settings->b101 = 1;
            pc->settings->f40 = 0x60A2C435;
            pc->bbc = 1;
            pc->bbd = 1;
        } else if (req->part == PART_LOCKER_ROOM) {
            Player **it;
            PlayerList *pl;
            int pad;
            set_camera_sequence(0x5392B268);
            pad = (int)lbl_88D45A60->master_pad;
            pl = lbl_88D459E0;
            for (it = pl->begin; it != pl->end; it++) {
                if ((*it)->pad_index == pad) {
                    Player *p = *it;
                    if (p != 0 && p->node != 0) {
                        u8 *sub = p->node->vt->get(p->node, 0);
                        fn_888DC320(lbl_88D45954, (float)*(int *)(sub + 0x1c));
                    }
                    break;
                }
            }
        }
        goto close;
    } else if (mode != 2) {
        goto close;
    }
    fn_88902238(self, 1);
    if (mode == 0) {
        Svc *s = ts4_find_service(0x5BCBE4C1);
        if (s != 0)
            s->b20 = 0;
        publish_cameras(&self->cam1_a, &self->cam1_b);
        if (req->prev != 0) {
            if (req->prev == 0xBC6C8EFB && !req->b34)
                req->f24 = PART_PRACTICE_GROUND;
        } else {
            u8 tmp90[0x10];
            u8 tmp50[0x10];
            u32 key = 0xABECF1ED;
            u32 key2;
            ts4_handle_forward_88610778(tmp90, &self->cam_a, &key);
            key2 = 0xB01F4F95;
            ts4_clone_byte_with_object_context(ts4_init_range_and_run_service_opt_88164450(tmp50, tmp90, &key2, 0), lbl_880CBA07);
        }
        goto stage;
    }
    /* mode 2: the new part's data is loaded */
    {
        Tri h;
        int i;
        ts4_if_set_u32_off0_8862BE08(&h, lbl_880D82D0);
        fn_88169350(&s50.a, &h);
        for (i = 0; i < 7; i++) {
            if (s50.a == self->licensed_venues[i]) {
                XHandle l;
                ts4_if_set_u32_off0_8862BE08(&l, lbl_880D878C);
                *l.node->vt->attr(l.node, &l, l.b, 1) = 1;
                break;
            }
        }
    }
    part = req->part;
    {
        void *mod = 0;
        u8 same = (req->prev != 0) ? 1 : (part == req->f24);
        if (same && req->prev != 0xBC6C8EFB) {
            fn_888E73B0(ctx);
            fn_888D7CF8(ctx);
        } else {
            Tri h;
            ts4_net_set_prop_byte_8890A948(lbl_88D45AD4->cam_a, 1, 0);
            fn_88169350(&s50.a, ts4_if_set_u32_off0_8862BE08(&h, lbl_880D87C0));
            if (s50.a == PART_INGAME) {
                ts4_if_set_u32_off0_8862C0E8(&s50, lbl_880D8808);
                mod = fn_88923530(s50.c, s50, 0x9A4E609F);
                fn_888E73B0(mod);
            } else {
                fn_888E73B0(ctx);
            }
            ts4_loop_call_seq_lbl_880D8300_888E7308();
            fn_888D7CF8(mod != 0 ? mod : ctx);
        }
    }
    if (part == PART_ONLINE) {
        u8 *n;
        ts4_if_set_u32_off0_8862C0E8(&s50, lbl_880D885C);
        n = fn_88923530(s50.c, s50, 0x46467307);
        *(u32 *)(rel_base(n) + 0x1c) = 0;
    }
    if (fn_888CDBC8(ctx, 0x32F72925))
        fn_88641718();
    ts4_if_set_u32_off0_8862C0E8(&s50, lbl_880D8888);
    if (!handle_is_null(&s50))
        *(u32 *)((u8 *)fn_88923530(s50.c, s50, 0x8C6385AD) + 0x30) = 0;
    publish_cameras(&self->cam_a, &self->cam_b);
    if (part == PART_PLAYER_CREATOR || part == PART_LOCKER_ROOM || part == 0x41A6A445) {
        u8 *n;
        ts4_if_set_u32_off0_8862C0E8(&s50, lbl_880D88D0);
        n = fn_88923530(s50.c, s50, 0x1E51C496);
        rel_base(n)[0x120] = 1;
        rel_base(n)[0x260] = 0;
        rel_base(n)[0x3a0] = 0;
        rel_base(n)[0x4e0] = 0;
    }
    if (part == PART_INGAME)
        fn_888E6FF8();
    else if (part == PART_PLAYER_CREATOR)
        fn_888E6E88(self);
    else if (part == 0xF6875E97 || part == PART_PRACTICE_GROUND)
        ts4_get_ts4_find_service_888DDB28();
    else if (part == PART_MINIGAME)
        ts4_hash_service_set_888CD6D0(self);
    fn_888E71A8(req);
    fn_888E70F0(req);
    fn_886EAB58();
stage:
    {
        Obj7c *o = lbl_88D459C4;
        if (o != 0) {
            u32 p = req->part;
            if (p == PART_INGAME || p == PART_PRACTICE_GROUND || p == 0xF6875E97 || p == PART_MINIGAME)
                o->in_match_part = 1;
            else
                o->in_match_part = 0;
        }
    }
    return;
close:
    fn_88902238(self, 0);
    publish_cameras(&self->cam1_a, &self->cam1_b);
    fn_8857C8C8();
}
