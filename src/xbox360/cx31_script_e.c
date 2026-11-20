/* CW31 part e: script bindings in 0x88790000-0x887A0000. */
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

typedef struct Hdl12 { u32 a, b, c; } Hdl12;
typedef struct HEnt { u32 f0, f4, f8, fc; u8 pad[0xc]; u32 f1c; } HEnt;
extern void *lbl_88D458F0;
extern void *lbl_88D45954;
extern void *lbl_88D459E0;
extern HEnt *ts4_hash_find_881AB900(void *table, u32 hash, Hdl12 h);

/* 0x88792F38: set the word at +0x1c of the hash-table entry to argument 0 */
u32 ts4_script_set_hash_entry_word_88792F38(Ctx *c)
{
    Hdl12 h;
    double d = arg_number(arg_at(c->args, 0));
    h.a = 0;
    h.b = 0xFFFFF;
    h.c = 0;
    ts4_hash_find_881AB900(lbl_88D458F0, 0x7E35EE14u, h)->f1c = (u32)d;
    return 0;
}

typedef struct Rec24 { u8 pad[0x24]; u32 f24; u32 f28; } Rec24;
extern void *ts4_hash_find_null_888E1D40(void);
extern Rec24 *ts4_find_record_by_key_881877A8(void *tbl, u32 *key);
extern void ts4_clear_script_prop_B1CA7E98_888C8190(void *obj);

