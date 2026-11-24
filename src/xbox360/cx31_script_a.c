/* CW31 part a: script bindings in 0x88780000-0x88790000 (number-argument callbacks). */
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

extern u8 fn_88865388(void *, int, int, u8 *);
extern u32 ts4_if_get_u32_lbl_88D45B1C_887EA558(void *, u32, u32 *);
extern void *lbl_88D459DC;
extern void *lbl_88D45A04;

typedef struct Ent12 { u32 key; u32 f4; u32 f8; } Ent12;
typedef struct Hold84 { u8 pad[0x84]; Ent12 *begin; Ent12 *end; } Hold84;

typedef struct Row98 { u8 pad[0x8a]; u8 flag; u8 pad2[0x98 - 0x8b]; } Row98;
typedef struct Rows { u8 pad[0xa4]; Row98 *rows; u8 pad2[0x1c4 - 0xa8]; u32 count; } Rows;
typedef struct Sess68 { u8 pad[0x68]; u8 *a; u8 *b; } Sess68;
typedef struct HoldB1C { u8 pad[0x27c]; u32 f27c; } HoldB1C;
typedef struct Item4 { u8 pad[4]; int id; } Item4;
typedef struct List4 { u8 pad[4]; Item4 **begin; Item4 **end; } List4;
typedef struct OnlineSt { u8 pad[0x1c]; List4 *list; } OnlineSt;
typedef struct Tri { u32 a, b, c; } Tri;
typedef struct Obj10 { u8 pad0[4]; u8 name[0xc]; int f10; u32 f14; u32 f18; } Obj10;
typedef struct VObjS { void **vt; } VObjS;
typedef struct Pair8 { u32 key; u32 val; } Pair8;
typedef struct Tbl1c { u8 pad[0x1c]; Pair8 *begin; Pair8 *end; } Tbl1c;
typedef struct SvcV { u8 pad[0x4c]; u8 *(*get)(void *, int); } SvcV;
typedef struct SvcO { SvcV *vt; } SvcO;
extern void fn_888D0838(void *, u32);
extern void fn_888D0F00(void *, u32, u32);
extern void ts4_if_call_seq_fn_888C39A0_888D8078(u32, u32, u32, u32);
extern void fn_889ACF20(void *);
extern void *lbl_88D45B1C;
extern void ts4_push_rec2_88865D18(void *o, u32 a, u32 b);
extern u8 lbl_880C1320[];
extern u8 fn_8822BF98(void *, void *);
extern Tri *ts4_if_call_seq_u32_off0_8878F8F0(Tri *out, void *name);
extern void ts4_assign_formatted_text(void *dst, const char *text);
extern u32 ts4_crc32_cstr_seed_88608590(u32 a, void *name);
extern void *fn_88618998(void *g, u32 h);
extern void ts4_loop_get_u32_off120_88608698(void *g, void *x);
extern void ts4_destroy_owned_object(void *p);
extern void *lbl_88D45B38;
extern const char g_ts4_true_string[];
extern u32 ts4_script_string_equals(void *value, const char *text);
extern u32 ts4_profile_internal_is_available(void *online_state, int profile_index, u32 flags);
extern void *g_ts4_online_state;
extern void *lbl_88D45960;
extern void *lbl_88D45954;
extern void *lbl_88D45A60;
extern void *lbl_88D45B30;
extern void fn_888C7C28(void *, u32 *);
extern void fn_88887A00(u32);
extern void *ts4_find_service(u32 id);
extern void fn_888CB3F0(void *svc, int a, u32 b);
extern void ts4_rec_copy_88187900(void *dst, void *src);
extern void fn_888C8EB8(void *, int);
extern void fn_888C9040(void *);
extern void ts4_hash_service_str2_888C8970(void *, int, u32);
extern u32 *ts4_member_field_addr_8883B578(void *, int);
extern void *lbl_88D459E0;
extern void *g_ts4_session_context;

/* 0x88780758: argument 0 is an id, argument 1 a 64-bit-converted value; forward through the getter */
u32 ts4_script_two_arg_get_88780758(Ctx *c)
{
    int id = (int)arg_number(arg_at(c->args, 0));
    u32 v = (u32)arg_number(arg_at(c->args, 1));
    ts4_if_get_u32_lbl_88D45B1C_887EA558(lbl_88D45A04, id, &v);
    return 0;
}

/* 0x88782930: argument 0 is a profile index, argument 1 a "true" string; forward to the availability check */
u32 ts4_script_profile_available_88782930(Ctx *c)
{
    int idx = (int)arg_number(arg_at(c->args, 0));
    u32 flag = ts4_script_string_equals(arg_at(c->args, 1)->pad, g_ts4_true_string);
    return ts4_profile_internal_is_available(g_ts4_online_state, idx, flag);
}

/* 0x88782AA8: argument 0 selects one of four slots (or -1 for all); look each up and forward */
u32 ts4_script_each_slot_88782AA8(Ctx *c)
{
    int sel = (int)arg_number(arg_at(c->args, 0));
    Tbl1c *t = lbl_88D45B30;
    int i;
    for (i = 0; i < 4; i++) {
        if (sel == -1 || sel == i) {
            u32 r = 0;
            Pair8 *e = t->end;
            Pair8 *p = t->begin;
            for (; e != p; p++) {
                if ((u32)i == p->key) {
                    r = p->val;
                    break;
                }
            }
            fn_88887A00(r);
        }
    }
    return 0;
}

/* 0x88782CB0: copy two records out of the service object's self-relative table when it has more than six entries */
u32 ts4_script_copy_records_88782CB0(Ctx *c)
{
    SvcO *s = ts4_find_service(0x8C5A4922u);
    u8 *o = s->vt->get(s, 0);
    (void)c;
    if (*(u32 *)(o + 0x1a8) > 6) {
        u8 *base = o + 0x1a4;
        u8 *b = base + *(u32 *)base;
        ts4_rec_copy_88187900(b + 0x258, b + 0x190);
    }
    return 0;
}

/* 0x88783128: argument 0 id, argument 1 a hash; forward unless the hash is the no-op constant */
u32 ts4_script_hash_service_88783128(Ctx *c)
{
    int id = (int)arg_number(arg_at(c->args, 0));
    u32 h = (u32)arg_number(arg_at(c->args, 1));
    if (h != 0x4905ED7Bu) ts4_hash_service_str2_888C8970(lbl_88D45954, id, h);
    return 0;
}

/* 0x88783350: argument 0 picks a member field of the global, argument 1 is stored into its second word */
u32 ts4_script_set_member_word_88783350(Ctx *c)
{
    int id = (int)arg_number(arg_at(c->args, 0));
    u32 v = (u32)arg_number(arg_at(c->args, 1));
    u32 *pv = &v;
    u32 *p = ts4_member_field_addr_8883B578(lbl_88D459E0, id);
    p[1] = *pv;
    return 0;
}

/* 0x88783568: true when a self-relative pointer slot's non-null state equals a flag in the other object */
u32 ts4_script_slot_matches_88783568(Ctx *c)
{
    int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0, op1_pad3 = 0, op1_pad4 = 0;
    Sess68 *s = g_ts4_session_context;
    u8 *a = s->a + 0x220;
    u8 *b = s->b;
    u8 *base = a + *(u32 *)a;
    u32 v = *(u32 *)(base + *(u32 *)base);
    (void)op1_pad0; (void)op1_pad1; (void)op1_pad2; (void)op1_pad3; (void)op1_pad4;
    (void)c;
    return *(u32 *)(b + 0xd8) == (v != 0);
}

/* 0x88783960: argument 0 stored into a self-relative table of the service object */
u32 ts4_script_store_service_word_88783960(Ctx *c)
{
    u32 v = (u32)arg_number(arg_at(c->args, 0));
    u8 *svc = ts4_find_service(0x347BF406u);
    if (svc) {
        u8 *base = *(u8 **)(svc + 0x24) + 0x214;
        *(u32 *)(base + *(u32 *)base + 0x24) = v;
    }
    return 0;
}

/* 0x88782E50: forward, then set the flag in every row */
u32 ts4_script_set_row_flags_88782E50(Ctx *c)
{
    Rows *r;
    u32 i;
    (void)c;
    fn_888C9040(lbl_88D45954);
    r = lbl_88D45A60;
    for (i = 0; i < r->count; i++) *((u8 *)r->rows + i * 0x98 + 0x8a) = 1;
    return 0;
}

/* 0x88786330: argument 0 a "true" string flag, argument 1 a word; forward both to the global when it exists */
u32 ts4_script_forward_flag_u32_88786330(Ctx *c)
{
    u32 flag = ts4_script_string_equals(arg_at(c->args, 0)->pad, g_ts4_true_string);
    u32 v = (u32)arg_number(arg_at(c->args, 1));
    void *g = lbl_88D45954;
    if (g) fn_888D0F00(g, flag, v);
    return 0;
}

/* 0x8878A9C8: two words from the arguments plus a field of the global forwarded to the call-sequence helper */
u32 ts4_script_forward_two_8878A9C8(Ctx *c)
{
    u32 a = (u32)arg_number(arg_at(c->args, 0));
    u32 b = (u32)arg_number(arg_at(c->args, 1));
    HoldB1C *g = lbl_88D45B1C;
    ts4_if_call_seq_fn_888C39A0_888D8078(a, b, 0, g->f27c);
    return 0;
}

/* 0x8878AB50: argument 1 is an id; find the matching entry in the online list and forward it */
u32 ts4_script_find_entry_8878AB50(Ctx *c)
{
    int id = (int)arg_number(arg_at(c->args, 1));
    if (ts4_find_service(0x061B4A78u)) {
        OnlineSt *st = g_ts4_online_state;
        Item4 **e = st->list->end;
        Item4 **p = st->list->begin;
        for (; p != e; p++) {
            Item4 *o = *p;
            if (id == o->id) {
                fn_889ACF20(o);
                break;
            }
        }
    }
    return 0;
}

/* 0x88783E98: argument 0 and argument 1 pushed as a record onto the vector in the global */
u32 ts4_script_push_rec2_88783E98(Ctx *c)
{
    int a = (int)arg_number(arg_at(c->args, 0));
    u32 b = (u32)arg_number(arg_at(c->args, 1));
    ts4_push_rec2_88865D18(lbl_88D459DC, a, b);
    return 0;
}

/* 0x8878F9A0: refresh the cached triple when it is unset or holds the 0xFFFFF sentinel and the name is not empty */
void ts4_refresh_triple_8878F9A0(Obj10 *self)
{
    Tri tmp;
    u8 need;
    if (self->f10 == 0 || self->f14 == 0xFFFFFu) need = 1;
    else need = 0;
    if (need) {
        if (!fn_8822BF98(lbl_880C1320, self->name)) {
            Tri *t = ts4_if_call_seq_u32_off0_8878F8F0(&tmp, self->name);
            self->f10 = t->a;
            self->f14 = t->b;
            self->f18 = t->c;
        }
    }
}
