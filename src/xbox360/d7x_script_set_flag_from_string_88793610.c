/* Swing_DLL.xex 0x88793610-0x887936A8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
typedef unsigned __int64 u64;
#else
#define INL static inline
typedef unsigned long long u64;
#endif
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
extern Val *g_ts4_default_script_value;

INL Val *arg_at(Args *a, u32 i)
{
    if (a->count > i) {
        return &a->items[i];
    }
    return g_ts4_default_script_value;
}

extern char g_ts4_true_string[];
extern char lbl_880EAF00[];
extern int ts4_script_string_equals(const void *a, const void *b);
typedef struct Obj Obj;
typedef struct ObjVtbl { void *s[10]; u8 *(*get)(Obj *, void *out, u32 x, int flag); } ObjVtbl;
struct Obj { ObjVtbl *vt; };
typedef struct Pair { Obj *obj; u32 x; } Pair;
extern Pair *fn_8862BE08(Pair *out, const char *name);

u32 ts4_script_set_flag_from_string_88793610(Ctx *c)
{
    Pair tmp;
    Pair *p;
    u8 *dst;
    u8 eq = (u8)ts4_script_string_equals((char *)arg_at(c->args, 0) + 0x10, g_ts4_true_string);
    p = fn_8862BE08(&tmp, lbl_880EAF00);
    dst = p->obj->vt->get(p->obj, p, p->x, 1);
    *dst = eq;
    return 0;
}
