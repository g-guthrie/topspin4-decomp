/*
 * Lua-to-C++ entry points on the front-end path (frontend-map section 2.1).
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 payload[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern long _InterlockedDecrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement)
#endif
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
typedef struct StrAlloc StrAlloc;
typedef struct StrAllocVt { void *f0; void *f4; void (*free)(StrAlloc *a, void *hdr); } StrAllocVt;
struct StrAlloc { StrAllocVt *vt; };
typedef struct StrHdr { StrAlloc *alloc; u32 f4; u32 f8; long refs; } StrHdr;
typedef struct Str { char *p; u8 rest[8]; } Str;
typedef struct RuiMgr { u8 pad[0x314]; int master_pad; } RuiMgr;
typedef struct Out { u32 w; } Out;
typedef struct Engine { u8 pad[0x27c]; u32 f27c; } Engine;
typedef struct Pkg { u8 pad[0x38]; u32 state; } Pkg;
extern RuiMgr *lbl_88D45A60;
extern void fn_8818EB10(char **out, void *src);
extern void ts4_assign_formatted_text(Str *dst, const char *text);
extern void fn_887BFDA8(RuiMgr *m, Str *name, u32 a, u32 b, u32 c);
extern void *ts4_find_service(u32 id);
typedef struct PlayerSel PlayerSel;
extern PlayerSel *lbl_88D459E0;
extern void fn_88855420(PlayerSel *s, int pad, u32 *key, u32 a, u32 b, u32 c, u32 d, u32 e, int slot);
extern const char lbl_880D82C4[]; /* "S4Loading" */
extern const float lbl_8814B440;  /* 0.0f */
extern u32 fn_88608590(u32 seed, void *text);
extern void fn_887BE998(void *pkgmgr, void *name, u32 *hash, u32 a, u32 b, u32 c, u32 d, float t);
extern Engine *lbl_88D45B1C;
extern void ts4_call_seq_u32_off0_881B1A98(Out *out, void *self, int v);
extern void fn_88907128(void *tcr, int pad, u32 a, u32 b);

INL void str_release(char *p)
{
    StrHdr *h = (StrHdr *)(p - 0x10);
    if (_InterlockedDecrement(&h->refs) == 0)
        h->alloc->vt->free(h->alloc, h);
}

typedef struct Scene { u8 pad[0x118]; u8 deactivating; } Scene;
extern void *lbl_88D41FC4;
extern Scene **ts4_if_get_u32_off4_881E9010(Scene **out, void *engine, char **name);
extern void ts4_if_atomic_interlocked_dec_881876D0(void *p);
extern u8 ts4_script_string_equals(void *value, const char *text);
extern void fn_887ADEB8(Ctx *c, int pad, u8 flag);
extern const char g_ts4_true_string[];

/* 0x8879FE68 (0xC8): Lua WaitForSceneDeactivation(name): looks the RUI scene up by name in the script
 * engine [0x88D41FC4] and returns its +0x118 byte (still deactivating), 0 when there is no such scene. */
u32 ts4_script_wait_for_scene_deactivation_8879FE68(Ctx *c)
{
    char *name;
    Scene *sc;
    u32 r;
    fn_8818EB10(&name, arg_at(c->args, 0)->payload);
    r = 0;
    ts4_if_get_u32_off4_881E9010(&sc, lbl_88D41FC4, &name);
    if (sc) {
        r = sc->deactivating;
        ts4_if_atomic_interlocked_dec_881876D0(sc);
    }
    str_release(name);
    return r;
}

/* 0x887AE240 (0xD8): Lua TCR_SetActivePad(pad, active): fn_887ADEB8(ctx, pad, active == "true"). */
u32 ts4_script_tcr_set_active_pad_887AE240(Ctx *c)
{
    int pad = (int)arg_number(arg_at(c->args, 0));
    fn_887ADEB8(c, pad, ts4_script_string_equals(arg_at(c->args, 1)->payload, g_ts4_true_string));
    return 0;
}

/* 0x8877C740 (0xC8): Lua IsPackageNotReadyToUse(hash): 1 while the package service named by the hash
 * exists and its state (+0x38) is not 7 (ready); 0 when there is no such service. */
u32 ts4_script_is_package_not_ready_8877C740(Ctx *c)
{
    u32 key = (u32)arg_number(arg_at(c->args, 0));
    u32 r = 0;
    Pkg *p = ts4_find_service(key);
    if (p)
        r = p->state != 7;
    return r;
}

/* 0x887A76A0 (0x50): Lua GetMasterPad(): pushes the master pad index ([0x88D45A60]+0x314), or 0 when
 * it is negative; returns 1 result. */
int ts4_script_get_master_pad_887A76A0(void *self)
{
    int pad = lbl_88D45A60->master_pad;
    Out o;
    ts4_call_seq_u32_off0_881B1A98(&o, self, 0 <= pad ? pad : 0);
    return 1;
}

/* 0x887B6C00 (0xB4): Lua TCR_GoToStartScreen(pad): fn_88907128(TCR service 0xF4F09230, pad,
 * engine+0x27C, 0) sends the game back to Press Start (sign-out and similar); returns 1. */
u32 ts4_script_tcr_go_to_start_screen_887B6C00(Ctx *c)
{
    double pad = arg_number(arg_at(c->args, 0));
    void *t = ts4_find_service(0xF4F09230);
    fn_88907128(t, (int)pad, lbl_88D45B1C->f27c, 0);
    return 1;
}

/* 0x887C09D8 (0x118): Lua ChangePackage(manager, package, scene, flag).  First switches the RUI to the
 * "S4Loading" scene (fn_887BFDA8, like ChangeScene), then asks the package manager service named by
 * hash(manager) to load `package` with scene hash(scene) (fn_887BE998, time 0.0).  The flag string is
 * compared with "true" but the result is not used.  Returns 0. */
u32 ts4_script_change_package_887C09D8(Ctx *c)
{
    Val *mgr = arg_at(c->args, 0);
    Val *pkg = arg_at(c->args, 1);
    Val *scene = arg_at(c->args, 2);
    Str s;
    void *svc;
    u32 h;
    ts4_script_string_equals(arg_at(c->args, 3)->payload, g_ts4_true_string);
    ts4_assign_formatted_text(&s, lbl_880D82C4);
    fn_887BFDA8(lbl_88D45A60, &s, 0, 0, 0);
    svc = ts4_find_service(fn_88608590(0, *(void **)mgr->payload));
    h = fn_88608590(0, *(void **)scene->payload);
    fn_887BE998(svc, *(void **)pkg->payload, &h, 0, 0, 0, 0, lbl_8814B440);
    return 0;
}

/* 0x8879BE08 (0x114): Lua PlayerSelectLoadSavedPlayerInfo(pad, key): asks the player-select object
 * [0x88D459E0] to load the saved player `key` for `pad` (fn_88855420(sel, pad, &key, 1, 0, 1, 0, 0, -1);
 * the ninth argument goes on the stack).  The block-scoped copy of key gives the original's
 * scheduling of the float conversions.  Returns 0. */
u32 ts4_script_player_select_load_saved_player_info_8879BE08(Ctx *c)
{
    int pad = (int)arg_number(arg_at(c->args, 0));
    u32 k = (u32)arg_number(arg_at(c->args, 1));
    {
        u32 key = k;
        fn_88855420(lbl_88D459E0, pad, &key, 1, 0, 1, 0, 0, -1);
    }
    return 0;
}
