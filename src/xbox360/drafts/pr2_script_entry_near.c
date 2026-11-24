/*
 * DRAFTS (not byte-matched): Lua entry points from frontend-map section 2.1.
 *
 * 0x887AED08 (0x128) Lua TCR_RequireSignIn(pad, user, flag): fn_88905AA8(TCR service 0xF4F09230, pad,
 *   user, flag == "true"); returns 0.  3 instructions off: the original builds the 0xF4F09230 constant
 *   in r11 before moving the flag result to r29 (lis r11 / mr r29 / ori r3,r11); this compiler builds it
 *   directly in r3 after the move.  Same pattern as 0x8878A5D8 and 0x8879F810.
 * 0x8878DC68 (0x130) Lua UnloadArchive(id, kind): builds an archive request object on the stack
 *   (base constructor fn_88617D88, vtable lbl_880F8188), calls
 *   ts4_if_get_ts4_find_service_8862B028(&req, "NONE", kind, id), then destroys it (vtable store +
 *   ts4_if_call_seq_lbl_880F7EE4_88617D28).  The script default number is loaded once and shared by
 *   both numeric arguments (f31).  2 instructions off: the vtable store is scheduled one instruction
 *   later in the original (also with a C++ constructor/destructor version).
 * 0x887C26D0 (0xC4) Lua ChangeScene(name): copies the name into a ref-counted string (fn_8818EB10),
 *   builds a text object from it and calls fn_887BFDA8([0x88D45A60], &text, 0, 0, 0) to switch the RUI
 *   scene, then releases the string (atomic decrement of header+0xC at name-0x10; at zero the
 *   allocator's vtable slot 2 frees it).  The text object is not freed here.  Returns 0.
 *   3 instructions off: the original loads the string pointer straight into r31 and copies it to r4;
 *   this compiler loads r4 and copies to r31.  Tried: a separate pointer local in several places, an
 *   inline release helper, a C++ string class, 0..5 dead locals.
 * fn_equiv (work/equiv/pr2_script_entry_near.json): all three EQUIVALENT with 100% coverage
 *   (224, 228 and 168 valid trials in the order above).
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
extern const char g_ts4_true_string[];
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
INL double arg_number_d(Val *v, double d)
{
    if (v->type == 4) {
        return v->value.number;
    } else if (v->type == 1) {
        return v->value.integer;
    }
    return d;
}
extern long _InterlockedDecrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement)
#endif
typedef struct StrAlloc StrAlloc;
typedef struct StrAllocVt { void *f0; void *f4; void (*free)(StrAlloc *a, void *hdr); } StrAllocVt;
struct StrAlloc { StrAllocVt *vt; };
typedef struct StrHdr { StrAlloc *alloc; u32 f4; u32 f8; long refs; } StrHdr;
typedef struct Str { char *p; u8 rest[8]; } Str;
typedef struct RuiMgr RuiMgr;
extern RuiMgr *lbl_88D45A60;
extern void fn_8818EB10(char **out, void *src);
extern void ts4_assign_formatted_text(Str *dst, const char *text);
extern void fn_887BFDA8(RuiMgr *m, Str *name, u32 a, u32 b, u32 c);
typedef struct ArcReq { const void *vt; u8 pad[0x1c]; } ArcReq;
extern const u8 lbl_880F8188[];
extern const char lbl_880D35A0[];
extern void *ts4_find_service(u32 id);
extern u8 ts4_script_string_equals(void *value, const char *text);
extern void fn_88905AA8(void *tcr, int pad, int user, u8 flag);
extern void fn_88617D88(ArcReq *r);
extern void ts4_if_get_ts4_find_service_8862B028(ArcReq *r, const char *kind, u32 a, u32 b);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(ArcReq *r);

/* 0x887AED08: Lua TCR_RequireSignIn(pad, user, flag) */
u32 ts4_script_tcr_require_sign_in_887AED08(Ctx *c)
{
    int pad = (int)arg_number(arg_at(c->args, 0));
    int user = (int)arg_number(arg_at(c->args, 1));
    u8 flag = ts4_script_string_equals(arg_at(c->args, 2)->payload, g_ts4_true_string);
    void *t = ts4_find_service(0xF4F09230);
    fn_88905AA8(t, pad, user, flag);
    return 0;
}

/* 0x8878DC68: Lua UnloadArchive(id, kind) */
u32 ts4_script_unload_archive_8878DC68(Ctx *c)
{
    Val *v0 = arg_at(c->args, 0);
    double def = g_ts4_script_constants[11];
    u32 id = (u32)arg_number_d(v0, def);
    double kind = arg_number_d(arg_at(c->args, 1), def);
    ArcReq r;
    fn_88617D88(&r);
    r.vt = lbl_880F8188;
    ts4_if_get_ts4_find_service_8862B028(&r, lbl_880D35A0, (u32)kind, id);
    r.vt = lbl_880F8188;
    ts4_if_call_seq_lbl_880F7EE4_88617D28(&r);
    return 0;
}

u32 ts4_script_change_scene_887C26D0(Ctx *c)
{
    char *name;
    char *p;
    Str s;
    StrHdr *h;
    fn_8818EB10(&name, arg_at(c->args, 0)->payload);
    p = name;
    ts4_assign_formatted_text(&s, p);
    fn_887BFDA8(lbl_88D45A60, &s, 0, 0, 0);
    h = (StrHdr *)(p - 0x10);
    if (_InterlockedDecrement(&h->refs) == 0)
        h->alloc->vt->free(h->alloc, h);
    return 0;
}

