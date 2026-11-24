/* PR2: front-end path from ExhibitionConfig's confirm into the InGame part (docs/frontend-map.md section 3).
 * CLoadingManager (vtable 0x880DB408) loading-screen slots, InGame module Inits, and the Lua bindings
 * ChangeSubPart / InitMatchRules. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif

/* ---- script arguments (Lua call context) ---- */
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];

INL Val *arg_at(Args *a, u32 i)
{
    if (a->count > i) {
        return &a->items[i];
    }
    return g_ts4_default_script_value;
}

INL double arg_number(Val *v)
{
    if (v->type == 4) {
        return v->value.number;
    } else if (v->type == 1) {
        return v->value.integer;
    }
    return g_ts4_script_constants[11];
}

/* ---- shared types ---- */
typedef struct Tri { u32 a, b, c; } Tri;              /* 12-byte XData handle / hashed handle */
typedef struct Str { char *p; u32 a, b; } Str;        /* engine string */
typedef struct Ts4HashTable Ts4HashTable;
typedef struct Owner Owner;
typedef struct Res { u8 pad[4]; Owner *owner; } Res;
typedef struct Handle { Res *p; } Handle;             /* resource handle returned by a loader */
typedef struct OwnerVt { u8 pad[0x58]; void (*release)(Owner *o, Handle *h); } OwnerVt;
struct Owner { OwnerVt *vt; };
typedef struct Loader Loader;
typedef struct LoaderVt { u8 pad[0x28]; void (*open)(Handle *out, Loader *l, const char *name, int a, int b); } LoaderVt;
struct Loader { LoaderVt *vt; };
/* engine object [0x88D45B1C] */
typedef struct Engine {
    u8 pad[0x224];
    Loader *loader;          /* +0x224 file system / resource loader */
    u8 pad228[0x4c];
    u8 part_switch;          /* +0x274 set to 1 to make the module manager pick up @NextModule */
    u8 pad275[0x47];
    u32 f2bc;                /* +0x2bc */
} Engine;
typedef struct ScriptEngine70 { u8 pad[0x70]; void *busy; } ScriptEngine70;
typedef struct RuiMgr { u8 pad[0x2b8]; Tri cam_b; Tri cam_a; } RuiMgr;   /* [0x88D45A60] */
typedef struct LoadState { u8 pad[0xbc]; Tri cam_a; Tri cam_b; } LoadState; /* [0x88D45AD4] */
typedef struct SaveQueue { u8 pad[0x69]; u8 b69; } SaveQueue;           /* [0x88D45A0C] */

extern Engine *lbl_88D45B1C;
extern ScriptEngine70 *lbl_88D41FC4;
extern Ts4HashTable *lbl_88D458F0;
extern RuiMgr *lbl_88D45A60;
extern LoadState *lbl_88D45AD4;
extern SaveQueue *lbl_88D45A0C;
extern u8 lbl_88D45B06;
extern u8 lbl_88D4591A;
extern const char lbl_880C1320[];
extern const char lbl_880D82C4[];
extern const char lbl_880D8CE8[];
extern const char lbl_880D8D64[];
extern const char lbl_880D8DE4[];
extern const char lbl_880D8E08[];
extern const char g_ts4_true_string[];

extern void *ts4_hash_find_881AB900(Ts4HashTable *table, u32 hash, Tri h);
extern void fn_88627EC0(void *self, Tri value);
extern void ts4_if_set_u32_off0_8862BE08(void *out, const void *path);
extern void ts4_if_set_u32_off0_8862C0E8(Tri *out, const char *path);
extern void ts4_get_u32_off0_8822AFE8(void *a, void *b);
extern u8 ts4_loop_get_u32_off10_882109B8(void *);
extern u8 ts4_script_string_equals(void *value, const char *text);
extern u32 fn_8857C8C8(void);
extern void ts4_if_set_u32_off314_887993C8(RuiMgr *m, u32 v);
extern void fn_888E7278(u32 v);
extern void fn_8890AA50(u32 a, Tri t);
extern void ts4_assign_formatted_text(Str *dst, const char *text);
extern void fn_887BFDA8(RuiMgr *m, Str *name, u32 a, u32 b, u32 c);
extern void fn_887EB080(SaveQueue *q);

/* 0x888E0148: CPlayerLoadingManager Init. Base Init, then cache the match rules object
 * (hash 0x7E35EE14 in [0x88D458F0]) and the XData handle of
 * SystemData:/SystemData/LoadingList/Loading[@Name="InGameVenueLogo"]/@IsFinished. */
typedef struct PlayerLoadingMgr { u8 pad[0x24]; void *rules; Tri venue_logo_done; } PlayerLoadingMgr;
void ts4_player_loading_mgr_init_888E0148(PlayerLoadingMgr *self, Tri value)
{
    fn_88627EC0(self, value);
    {
        Tri h;
        h.a = 0;
        h.b = 0xFFFFF;
        h.c = 0;
        self->rules = ts4_hash_find_881AB900(lbl_88D458F0, 0x7E35EE14, h);
    }
    {
        Tri x;
        ts4_if_set_u32_off0_8862BE08(&x, lbl_880D8CE8);
        self->venue_logo_done = x;
    }
}

/* 0x88790FF0: Lua ChangeSubPart(hash). Returns 1 (retry) while the script engine is busy, otherwise writes
 * SystemData:/SystemData/Scheduler/SubModuleManager/@NextModule = hash and sets engine+0x274 = 1. */
u32 ts4_script_change_sub_part_88790FF0(Ctx *c)
{
    double d = arg_number(arg_at(c->args, 0));
    volatile u8 o50;
    u32 t60[3];
    u32 part;
    if (ts4_loop_get_u32_off10_882109B8(lbl_88D41FC4->busy)) {
        return 1;
    }
    ts4_if_set_u32_off0_8862BE08(t60, lbl_880D8D64);
    part = (u32)d;
    ts4_get_u32_off0_8822AFE8(t60, &part);
    o50 = 1;
    lbl_88D45B1C->part_switch = o50;
    return 0;
}

/* 0x8890BAF8: CLoadingManager vtable slot 14 (begin a load). mode 2: copy the two camera triples at +0x4c/+0x58
 * to the RUI manager and the loading state and return. Otherwise, with a RUI manager: mark "in loading UI"
 * ([0x88D45B06] = 1, read by Lua IsInLoadingUI), tell the RUI manager or the venue code about the part change,
 * and ChangeScene("S4Loading"). mode 0 also flushes the save queue. */
typedef struct LoadReq { u8 pad[0x18]; u32 f18; u32 f1c; u8 pad20[4]; u32 f24; u8 pad28[0xc]; u8 b34; } LoadReq;
typedef struct LoadingMgr { u8 pad[0x4c]; Tri cam_a; Tri cam_b; u8 pad64[0x18]; u8 b7c; } LoadingMgr;
void ts4_loading_mgr_begin_8890BAF8(LoadingMgr *self, LoadReq *req, u32 unused, int mode)
{
    (void)unused;
    self->b7c = 1;
    if (mode == 2) {
        Tri a, b;
        RuiMgr *m;
        fn_8857C8C8();
        a = self->cam_a;
        b = self->cam_b;
        m = lbl_88D45A60;
        if (m != 0) {
            m->cam_a = self->cam_a;
            m->cam_b = b;
        }
        {
            LoadState *ls = lbl_88D45AD4;
            ls->cam_a = a;
            ls->cam_b = b;
        }
        return;
    }
    if (lbl_88D45A60 != 0) {
        u32 cur = req->f18;
        u32 next = req->f24;
        lbl_88D45B06 = 1;
        if (cur != next) {
            if (req->f1c == 0)
                ts4_if_set_u32_off314_887993C8(lbl_88D45A60, 0);
        } else if (!lbl_88D4591A && req->f1c != 0 && req->f1c != 0xBC6C8EFB && !req->b34) {
            fn_888E7278(req->f24);
        }
        if (req->f1c == 0) {
            Str t;
            fn_8890AA50(1, lbl_88D45AD4->cam_a);
            ts4_assign_formatted_text(&t, lbl_880D82C4);
            fn_887BFDA8(lbl_88D45A60, &t, 0, 0, 0);
        } else {
            Str t;
            ts4_assign_formatted_text(&t, lbl_880D82C4);
            fn_887BFDA8(lbl_88D45A60, &t, 0, 0, 0);
        }
    }
    if (mode == 0) {
        fn_887EB080(lbl_88D45A0C);
        lbl_88D45A0C->b69 = 1;
    }
}

/* 0x88792D48: Lua InitMatchRules(games, sets, tiebreak, supertiebreak, b4, b5). Writes the rules object
 * ts4_hash_find([0x88D458F0], 0x7E35EE14): +4 games per set, +8 sets, +0xC/+0xD/+0xF/+0xE flags ("true" strings). */
typedef struct MatchRules { u32 f0; int games_per_set; int sets; u8 set_is_tiebreak; u8 super_tiebreak; u8 flag_e; u8 flag_f; } MatchRules;
u32 ts4_script_init_match_rules_88792D48(Ctx *c)
{
    int games = (int)arg_number(arg_at(c->args, 0));
    int sets = (int)arg_number(arg_at(c->args, 1));
    u8 b2 = ts4_script_string_equals(arg_at(c->args, 2)->pad, g_ts4_true_string);
    u8 b3 = ts4_script_string_equals(arg_at(c->args, 3)->pad, g_ts4_true_string);
    u8 b4 = ts4_script_string_equals(arg_at(c->args, 4)->pad, g_ts4_true_string);
    u8 b5 = ts4_script_string_equals(arg_at(c->args, 5)->pad, g_ts4_true_string);
    MatchRules *r;
    Tri h;
    h.a = 0;
    h.b = 0xFFFFF;
    h.c = 0;
    r = (MatchRules *)ts4_hash_find_881AB900(lbl_88D458F0, 0x7E35EE14, h);
    r->games_per_set = games;
    r->sets = sets;
    r->set_is_tiebreak = b2;
    r->super_tiebreak = b3;
    r->flag_f = b4;
    r->flag_e = b5;
    return 0;
}

/* 0x888E67A8: CPluginDataVenue: claim a venue pack slot. Walks GameDB:/GameDB/VenuePackSlotList (stride 0x40
 * self-relative array) for a slot whose node has a free entry; if none, loads
 * Media\\BinData\\GameDB\\EmptyVenuePackSlot.bin into the first slot without a node. Then loads the venue
 * data file named by the plugin definition (+0x34, self-relative string) into the chosen entry. Result in +0x68. */
typedef struct RelArr { int rel; u32 count; } RelArr;
typedef struct Node Node;
typedef struct NodeVt { u8 pad[0x4c]; RelArr *(*get)(Node *n, int i); } NodeVt;
struct Node { NodeVt *vt; };
typedef struct Slot { u8 pad[0xc]; Node *node; u8 pad10[0x30]; } Slot;
typedef struct Owner5c { u8 pad[0x5c]; Loader *loader; } Owner5c;
typedef struct VenuePlugin { u8 pad[8]; u8 *def; Owner5c *f0c; u8 pad10[0x58]; Slot *slot; } VenuePlugin;
extern RelArr *fn_88923530(u32 pool, Tri h, u32 hash);
extern void ts4_if_get_u32_offc_889271D8(Slot *slot, u32 a, Res *r);

INL Slot *rel_end(RelArr *a)
{
    Slot *r = 0;
    if (a->rel != -1)
        r = (Slot *)((char *)a + (a->count * 0x40 + a->rel));
    return r;
}
INL Slot *rel_begin(RelArr *a)
{
    Slot *r = 0;
    if (a->rel != -1)
        r = (Slot *)((char *)a + a->rel);
    return r;
}
INL const char *rel_str(int *p)
{
    if (*p != -1)
        return (const char *)p + *p;
    return lbl_880C1320;
}

void ts4_venue_plugin_claim_slot_888E67A8(VenuePlugin *self)
{
    Tri h;
    RelArr *list;
    Slot *found;
    Slot *spare;
    Slot *end;
    Slot *p;
    ts4_if_set_u32_off0_8862C0E8(&h, lbl_880D8DE4);
    list = fn_88923530(h.c, h, 0x03DF9421);
    found = 0;
    spare = 0;
    end = rel_end(list);
    p = rel_begin(list);
    while (found == 0) {
        Node *n;
        if (end == p)
            break;
        n = p->node;
        if (n != 0) {
            RelArr *sub = n->vt->get(n, 0);
            Slot *se = rel_end(sub);
            Slot *q;
            for (q = rel_begin(sub); se != q; q++) {
                if (q->node == 0) {
                    found = q;
                    break;
                }
            }
        } else if (spare == 0) {
            spare = p;
        }
        p++;
    }
    if (found == 0 && spare != 0) {
        Handle r;
        RelArr *sub;
        lbl_88D45B1C->loader->vt->open(&r, lbl_88D45B1C->loader, lbl_880D8E08, 1, 0);
        ts4_if_get_u32_offc_889271D8(spare, lbl_88D45B1C->f2bc, r.p);
        sub = spare->node->vt->get(spare->node, 0);
        found = (Slot *)((char *)sub + sub->rel);
        r.p->owner->vt->release(r.p->owner, &r);
    }
    if (found != 0) {
        Handle r;
        Loader *l = self->f0c->loader;
        l->vt->open(&r, l, rel_str((int *)(self->def + 0x34)), 1, 0);
        ts4_if_get_u32_offc_889271D8(found, lbl_88D45B1C->f2bc, r.p);
        r.p->owner->vt->release(r.p->owner, &r);
    }
    self->slot = found;
}
