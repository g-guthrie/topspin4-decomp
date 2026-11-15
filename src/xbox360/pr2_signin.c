/*
 * Sign-in and profile waits on the front-end path (frontend-map section 1.3).
 *
 * The pad records live in a self-relative array (stride 0xB0) hanging off the
 * module list at engine+0x234 -> +0x38.  Record +0xC is the controller index
 * (0..3, 4 or more means no controller), +0x1A says the profile is signed in.
 */
typedef unsigned int u32;
typedef unsigned char u8;

#ifdef _MSC_VER
#define INL static __forceinline
#define NOINLINE __declspec(noinline)
#else
#define INL static inline __attribute__((unused))
#define NOINLINE
#define __emit(x) ((void)(x))
#endif

typedef struct PadObj { u8 pad[0xc]; int pad_index; u8 pad10[0xa]; u8 b1a; u8 b1b; u8 pad1c[0x94]; } PadObj;
typedef struct PadArr { int rel; u32 count; } PadArr;
typedef struct ModList { u8 pad[0x38]; PadArr *pads; } ModList;
typedef struct Engine { u8 pad[0x234]; ModList *modules; } Engine;

typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;

typedef struct SigninWatch SigninWatch;
typedef struct SigninWatchVt { u8 pad[0x80]; void (*refresh)(SigninWatch *w, int i); } SigninWatchVt;
struct SigninWatch { SigninWatchVt *vt; u8 pad4[0x18]; PadArr *pads; u8 pad20[0x1c]; int count; u8 pad40[8]; u32 enabled; u8 pad4c[0x38]; void *listener; };

typedef struct LaunchModes { u8 pad[0xc]; u8 normal; u8 m_d; u8 m_e; u8 m_f; u8 m_10; } LaunchModes;
typedef struct GameSvc GameSvc;
typedef struct GameSvcVt { u8 pad[0x4c]; LaunchModes *(*get_modes)(GameSvc *s, u32 a); } GameSvcVt;
struct GameSvc { GameSvcVt *vt; };
typedef struct SaveFs SaveFs;
typedef struct SaveFsVt { u8 pad[0x44]; u8 (*exists)(SaveFs *f, char *name); } SaveFsVt;
struct SaveFs { SaveFsVt *vt; };
typedef struct ProfSvc ProfSvc;
typedef struct ProfSvcVt { u8 pad[0x28]; void (*load)(ProfSvc *s, int pad, int a); } ProfSvcVt;
struct ProfSvc { ProfSvcVt *vt; };

extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern Engine *lbl_88D45B1C;
extern const char lbl_880D1CE0[]; /* "Global.bin" */
extern void *ts4_find_service(u32 id);
extern void *ts4_tailcall_XamNotifyCreateListener_8857A988(u32 areas);
extern u32 ts4_tailcall_XamShowSigninUI_8857A688(u32 user, u32 panes);
extern int XNotifyGetNext(void *listener, u32 id, u32 *out_id, int *out_param);
extern u32 ts4_if_get_u32_lbl_88C32048_8857A1E0(void *h);
extern SaveFs *ts4_if_call_seq_u32_lbl_88D459E4_8883F238(void);
extern void ts4_format_save_entry_8886B1B0(int pad, char *buf, u32 size, const char *name, u32 a);

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

/* 0x888C0260 (0xC8): block until the system UI has opened and closed again.
 * Listens for XN_SYS_UI (id 9): first waits for param != 0 (UI shown), then for
 * param != 1 (UI gone), spinning with the yield hint while no notification is
 * queued, then closes the listener.  Called after XamShowSigninUI. */
void ts4_wait_system_ui_closed_888C0260(void)
{
    void *l = ts4_tailcall_XamNotifyCreateListener_8857A988(1);
    u32 id;
    int param;
    do {
        while (!XNotifyGetNext(l, 9, &id, &param))
            __emit(0x7ffffb78);
    } while (param == 0);
    do {
        while (!XNotifyGetNext(l, 9, &id, &param))
            __emit(0x7ffffb78);
    } while (param == 1);
    ts4_if_get_u32_lbl_88C32048_8857A1E0(l);
}

/* 0x88614938 (0x58): find the pad record whose controller index (+0xC) is pad, or 0 */
NOINLINE PadObj *ts4_pad_record_find_88614938(ModList *m, int pad)
{
    PadObj *r = 0;
    PadArr *a = m->pads;
    u32 i;
    for (i = 0; i < a->count; i++) {
        if (((PadObj *)((char *)a + (i * 0xb0 + a->rel)))->pad_index == pad) {
            r = (PadObj *)((char *)a + (i * 0xb0 + a->rel));
            break;
        }
    }
    return r;
}

/* 0x888C5338 (0x9C): when enabled (+0x48), poll the listener (+0x84) for
 * XN_SYS_SIGNINCHANGED (id 0xE); on a change call vtable slot 0x80 for every
 * pad record (array at +0x1C, count at +0x3C) that has a controller (index < 4).
 * The dead locals reproduce the original register numbering. */
void ts4_signin_watch_poll_888C5338(SigninWatch *w)
{
    int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0;
    (void)op1_pad0; (void)op1_pad1; (void)op1_pad2;
    if (w->enabled != 0) {
        u32 id;
        int param;
        if (XNotifyGetNext(w->listener, 0xe, &id, &param)) {
            int i;
            for (i = 0; i < w->count; i++) {
                PadArr *a = w->pads;
                PadObj *e = (PadObj *)((char *)a + i * 0xb0 + *(int *)a);
                if (e->pad_index < 4)
                    w->vt->refresh(w, i);
            }
        }
    }
}

/* 0x8879A918 (0x128): Lua TCR_LoadProfileSettingsIfNotLoaded(pad).
 * If the pad's profile is signed in (+0x1A) and the save "Global.bin" for that
 * pad does not exist on the save device (save object vtable 0x44), ask the
 * profile service 0x10ADFA5A (vtable 0x28) to load the settings: load(pad, 1). */
u32 ts4_script_tcr_load_profile_settings_8879A918(Ctx *c)
{
    int pad = (int)arg_number(arg_at(c->args, 0));
    if (ts4_pad_record_find_88614938(lbl_88D45B1C->modules, pad)->b1a) {
        SaveFs *fs = ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
        char name[0x200];
        ts4_format_save_entry_8886B1B0(pad, name, 0x200, lbl_880D1CE0, 1);
        if (!fs->vt->exists(fs, name)) {
            ProfSvc *s = ts4_find_service(0x10ADFA5A);
            s->vt->load(s, pad, 1);
        }
    }
    return 0;
}

/* 0x8877AF50 (0x1C4): Lua OnLaunchSignInGameMode(mode).
 * Opens the sign-in UI for user 1 (retrying XamShowSigninUI until it returns 0), waits for the
 * XN_SYS_UI notification that says the UI is showing (it does NOT wait for it to close), closes the
 * listener, then gets the launch-mode flags from service 0x891542DA (vtable 0x4C, argument 0), clears
 * the five flag bytes at +0xC..+0x10 and sets the one picked by the mode hash:
 * 0xB5F769B2 -> +0xD, 0x08B1C95F -> +0x10, 0xA6F6E957 -> +0xE, 0xF202BB09 -> +0xF, anything else -> +0xC. */
u32 ts4_script_on_launch_sign_in_game_mode_8877AF50(Ctx *c)
{
    u32 mode = (u32)arg_number(arg_at(c->args, 0));
    void *l = ts4_tailcall_XamNotifyCreateListener_8857A988(1);
    u32 id;
    int param;
    GameSvc *s;
    LaunchModes *m;
    while (ts4_tailcall_XamShowSigninUI_8857A688(1, 0) != 0)
        ;
    do {
        while (!XNotifyGetNext(l, 9, &id, &param))
            __emit(0x7ffffb78);
    } while (param == 0);
    ts4_if_get_u32_lbl_88C32048_8857A1E0(l);
    s = ts4_find_service(0x891542DA);
    m = s->vt->get_modes(s, 0);
    m->normal = 0;
    m->m_d = 0;
    m->m_e = 0;
    m->m_f = 0;
    m->m_10 = 0;
    switch (mode) {
    case 0xB5F769B2: m->m_d = 1; break;
    case 0x08B1C95F: m->m_10 = 1; break;
    case 0xA6F6E957: m->m_e = 1; break;
    case 0xF202BB09: m->m_f = 1; break;
    default: m->normal = 1; break;
    }
    return 0;
}
