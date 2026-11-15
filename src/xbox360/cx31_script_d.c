/* CW31 part d: assorted callbacks and helpers (0x88780000-0x88790000). */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
typedef unsigned __int64 u64;
#else
#define INL static inline __attribute__((unused))
typedef unsigned long long u64;
#endif
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

extern void *ts4_find_service(u32 id);
typedef struct VO2 { void **vt; u8 pad[0x20]; int f24; u8 f28[8]; } VO2;
typedef struct Acc { u8 pad[0x10]; void *src; u8 pad14[0xb8]; u32 fcc, fd0, fd4; int fd8; u8 fdc; } Acc;
extern VO2 *ts4_if_call_seq_u32_lbl_88D45B38_88215110(void *p);
extern void fn_881AAE70(void *dst, void *src);
extern void fn_88778BE8(void *self, int code);
extern void ts4_tailcall_fn_88584548_8857AFE8(int a);
typedef struct Hold94 { u8 pad[0x94]; u8 f94[4]; } Hold94;
extern Hold94 *lbl_88D45A60;

/* 0x88784BF8 */
void ts4_cx31_check_state_88784BF8(Acc *self)
{
    VO2 *o = ts4_if_call_seq_u32_lbl_88D45B38_88215110(self->src);
    ((void (*)(VO2 *))o->vt[3])(o);
    if (o->f24 == 3) {
        fn_881AAE70(lbl_88D45A60->f94, o->f28);
        self->fcc = 0x4DBF870Fu;
        self->fd0 = 0xF13EBA2Cu;
        self->fd4 = 0xC4B86D10u;
        self->fd8 = -1;
        self->fdc = 0;
        fn_88778BE8(self, 0xe);
        ts4_tailcall_fn_88584548_8857AFE8(0xa0);
    }
    ((void (*)(VO2 *, int))o->vt[0])(o, 1);
}


typedef struct Hdl12 { u32 a, b, c; } Hdl12;
typedef struct Obj33 { u8 pad[0x334]; void *f334, *f338, *f33c, *f340; u32 f344; } Obj33;
extern void *ts4_find_typed_entry_88781930(u32 *key);
extern Hdl12 *ts4_if_set_u32_off0_8862C0E8(Hdl12 *out, void *src);
extern u32 fn_88923530(u32 pool, Hdl12 h, u32 hash);
extern char lbl_880D85CC[];

/* 0x8878EB58 */
void ts4_cx31_init_entries_8878EB58(Obj33 *o)
{
    u32 k;
    Hdl12 h;
    k = 0xEB189E45u;
    o->f338 = ts4_find_typed_entry_88781930(&k);
    k = 0xA4FD6147u;
    o->f33c = ts4_find_typed_entry_88781930(&k);
    k = 0x65A66941u;
    o->f340 = ts4_find_typed_entry_88781930(&k);
    ts4_if_set_u32_off0_8862C0E8(&h, lbl_880D85CC);
    o->f344 = fn_88923530(h.c, h, 0xF895ECB1u) + 0x785;
    k = 0xE6BEB2A1u;
    o->f334 = ts4_find_typed_entry_88781930(&k);
}

extern int fn_88780288(int value);
extern void *g_ts4_session_context;
typedef struct SessCtx { u8 pad[0x3c]; u8 *a; u8 pad40[0x2c]; u8 *b; } SessCtx;

/* 0x88783BD8 */
u32 ts4_cx31_script_match_value_88783BD8(Ctx *c)
{
    double d = arg_number(arg_at(c->args, 0));
    SessCtx *s = g_ts4_session_context;
    u8 *a = s->a;
    u8 *b = s->b;
    if (a[0x8ca] != 0 && b[0xd7] != 0) {
        int x = fn_88780288((int)d);
        if (*(int *)(b + 0xd8) == x) return 1;
    }
    return 0;
}

#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
typedef struct VN { void **vt; u8 pad4[0x1c]; u32 f20; u32 f24; u32 f28; } VN;
typedef struct HdlN { u8 pad[0x19]; u8 f19; } HdlN;
typedef struct Own2c { u8 pad[0x2c]; u8 *f2c; u8 pad30[0x2e4]; char text[1]; } Own2c;
typedef struct H234 { u8 pad[0x234]; void *f234; } H234;
extern H234 *lbl_88D45B1C;
extern void *lbl_88D45B38;
extern HdlN *fn_88614938(void *a, u32 b);
extern u32 ts4_parse_type_flags_88778558(const char *s);
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 tag, u32 pool);
extern VN *ts4_object_ctor_88782260(void *mem, u32 b);

/* 0x88784CC8 */
void ts4_cx31_spawn_node_88784CC8(Own2c *self, u32 a, u32 b)
{
    HdlN *h = fn_88614938(lbl_88D45B1C->f234, b);
    if (h && h->f19) {
        u32 flags;
        VN *n;
        void *mem;
        const char *t = self->text;
        if (t && strlen(t)) flags = ts4_parse_type_flags_88778558(t);
        else flags = 0;
        mem = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x654, 4, 0, 2);
        if (mem) n = ts4_object_ctor_88782260(mem, b);
        else n = 0;
        n->f20 = a;
        n->f24 = *(u32 *)(self->f2c + 0xc);
        {
            void **vt = ((volatile VN *)n)->vt;
            ((volatile VN *)n)->f28 = flags;
            ((void (*)(VN *))vt[3])(n);
        }
        ((void (*)(VN *, int))n->vt[0])(n, 1);
    }
}
