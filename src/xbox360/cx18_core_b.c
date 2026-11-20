/* CW18 part b: game flow database helpers (0x88850000-0x88871F08). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;
#ifdef _MSC_VER
#define CX18_INL static __forceinline
#else
#define CX18_INL static inline
#endif

/* ---- 8-byte vector clear (copy of an empty range, then end = result) ---- */
typedef struct Cx18Vec8 { u64 *begin; u64 *end; } Cx18Vec8;
CX18_INL u64 *copy8(u64 *first, u64 *last, u64 *dest)
{
    int n = last - first;
    for (; n > 0; --n) { *dest = *first; ++dest; ++first; }
    return dest;
}

/* 0x8886FE18 */
void ts4_vec8_clear_8886FE18(Cx18Vec8 *v)
{
    v->end = copy8(v->end, v->end, v->begin);
}

/* ---- virtual dispatch through the global lbl_88D45A08 ---- */
typedef struct Cx18Vt { void *s[12]; void (*slot12)(void *self, u32 arg); } Cx18Vt;
typedef struct Cx18Obj { const Cx18Vt *vt; } Cx18Obj;
extern Cx18Obj *lbl_88D45A08;

/* 0x88864CF0: forward the word at self[idx+7] to the global object's virtual slot 12 */
void ts4_forward_slot12_88864CF0(u32 *self, int idx)
{
    lbl_88D45A08->vt->slot12(lbl_88D45A08, self[idx + 7]);
}

/* ---- vector of 8-byte records {word, word}: clear with the dead sub-object address ---- */
typedef struct Cx18Rec2 { u32 a, b; } Cx18Rec2;
typedef struct Cx18Vec2 { Cx18Rec2 *begin; Cx18Rec2 *end; } Cx18Vec2;
typedef struct Cx18Own2 { u8 pad0[0x1c]; u32 f1c; u8 pad20[0xc]; Cx18Vec2 v; } Cx18Own2;
CX18_INL Cx18Rec2 *copy2(Cx18Rec2 *first, Cx18Rec2 *last, Cx18Rec2 *dest)
{
    int n = last - first;
    for (; n > 0; --n) { dest->a = first->a; dest->b = first->b; ++dest; ++first; }
    return dest;
}
CX18_INL void vec2_clear(Cx18Vec2 *v)
{
    v->end = copy2(v->end, v->end, v->begin);
}

/* 0x88865708: zero the field at +0x1c and empty the record vector at +0x2c */
void ts4_own2_reset_88865708(Cx18Own2 *o)
{
    o->f1c = 0;
    vec2_clear(&o->v);
}

/* ---- vector of 8-byte records {u32, u16, u8, u8} ---- */
typedef struct Cx18Rec3 { u32 a; u16 b; u8 c; u8 d; } Cx18Rec3;
typedef struct Cx18Vec3 { Cx18Rec3 *begin; Cx18Rec3 *end; } Cx18Vec3;
CX18_INL Cx18Rec3 *copy3(Cx18Rec3 *first, Cx18Rec3 *last, Cx18Rec3 *dest)
{
    int n = last - first;
    for (; n > 0; --n) { dest->a = first->a; dest->b = first->b; dest->c = first->c; dest->d = first->d; ++dest; ++first; }
    return dest;
}

/* 0x88870B98 */
void ts4_vec3_clear_88870B98(Cx18Vec3 *v)
{
    v->end = copy3(v->end, v->end, v->begin);
}

/* ---- object with a sub-array of 0x84-byte elements at +0x84/+0x88; flag byte at +0x54 ---- */
typedef struct Cx18Sub { u8 pad0[0x54]; u8 flag; u8 pad55[0x84 - 0x55]; } Cx18Sub;
typedef struct Cx18SubOwner { u8 pad0[0x54]; u8 flag; u8 pad55[0x84 - 0x55]; Cx18Sub *begin; Cx18Sub *end; } Cx18SubOwner;

/* 0x8886FF98: flag of the owner (index 0) or of element idx-1; false when out of range */
u8 ts4_sub_get_flag_8886FF98(Cx18SubOwner *o, u32 idx)
{
    if (idx == 0) return o->flag;
    {
        Cx18Sub *begin = o->begin;
        u32 i = idx - 1;
        if (i < (u32)(o->end - begin)) return begin[i].flag;
    }
    return 0;
}

/* ---- global service (lbl_88D45B1C) -> +0x234 -> +0x38: self-relative table {off,count} of 0xb0-byte entries ---- */
typedef struct Cx18Tbl { int off; u32 count; } Cx18Tbl;
typedef struct Cx18Mid { u8 pad[0x38]; Cx18Tbl *tbl; } Cx18Mid;
typedef struct Cx18Svc { u8 pad[0x234]; Cx18Mid *mid; } Cx18Svc;
extern Cx18Svc *lbl_88D45B1C;
extern void ts4_slot_table_reset_88867A40(void *ent);

/* 0x888657C8: how many entries have the flag byte at +0x19 equal to 1 */
int ts4_tbl_count_flag1_888657C8(void)
{
    int n = 0;
    Cx18Tbl *t = lbl_88D45B1C->mid->tbl;
    u32 i;
    for (i = 0; i < t->count; i++) {
        char *e = (char *)t + (i * 0xb0 + t->off);
        if (e[0x19] == 1) n++;
    }
    return n;
}

/* 0x88867F10: find the entry whose id at +0xc equals the argument and hand it on */
void ts4_tbl_find_forward_88867F10(int id)
{
    Cx18Tbl *t = lbl_88D45B1C->mid->tbl;
    u32 i;
    for (i = 0; i < t->count; i++) {
        char *e = (char *)t + (i * 0xb0 + t->off);
        if (id == *(int *)(e + 0xc)) {
            ts4_slot_table_reset_88867A40(e);
            return;
        }
    }
}

/* ---- cursor object: +0x24 -> settings {+0xd00 modulus, +0xd14, +0xd1c current, +0xd20 mode}; +0x38/+0x3c sinks ---- */
typedef struct Cx18Cfg { u8 pad0[0xd00]; int modulus; u8 padd04[0xd14 - 0xd04]; u32 f14; u8 padd18[4]; int cur; int mode; } Cx18Cfg;
typedef struct Cx18Cursor { u8 pad0[0x24]; Cx18Cfg *cfg; u8 pad28[0x10]; void *sink38; void *sink3c; } Cx18Cursor;
extern void fn_88862338(void *sink, u32 a, int mode, int target, int step, u32 d14);

/* 0x88862948: advance the cursor by step (wrapping at the modulus; 0 = stay) and forward it */
void ts4_cursor_forward_88862948(Cx18Cursor *c, u32 a, int step)
{
    int mod = c->cfg->modulus;
    int target;
    if (step == 0) target = c->cfg->cur;
    else target = (c->cfg->cur + mod + step - 1) % mod + 1;
    fn_88862338(c->sink38, a, c->cfg->mode, target, step, c->cfg->f14);
}

/* ---- vector of 0x50-byte records (string + word at +0x4c): clear ---- */
typedef struct Cx18Rec50 { u8 str[0x4c]; u32 w; } Cx18Rec50;
typedef struct Cx18Vec50 { Cx18Rec50 *begin; Cx18Rec50 *end; } Cx18Vec50;
extern void ts4_byte_string_assign_8815F510(void *dst, const void *src);
CX18_INL Cx18Rec50 *copy50(Cx18Rec50 *first, Cx18Rec50 *last, Cx18Rec50 *dest)
{
    int n = last - first;
    for (; n > 0; --n) {
        ts4_byte_string_assign_8815F510(dest, first);
        dest->w = first->w;
        ++dest; ++first;
    }
    return dest;
}

/* 0x88871310 */
void ts4_vec50_clear_88871310(Cx18Vec50 *v)
{
    v->end = copy50(v->end, v->end, v->begin);
}

/* ---- owner with a vector of 0x5c-byte entries at +0x5c/+0x60 (entry id at +0, value at +0xc).
   The loops re-read the vector end (o->end) in the condition and after the loop; that is what keeps the exit test. ---- */
typedef struct Cx18Ent { u32 id; u32 pad4; u32 pad8; u32 val; u8 pad10[0x4c]; } Cx18Ent;
typedef struct Cx18EntOwner { u8 pad0[0x5c]; Cx18Ent *begin; Cx18Ent *end; } Cx18EntOwner;
typedef struct Cx18IdArg { u32 id; u8 pad[0xc]; int count; } Cx18IdArg;
extern void *fn_88869C20(void *ent, u32 hash);

/* 0x88865C48: look up the entry with this id; return whether found and store its value */
u8 ts4_ent_get_val_88865C48(Cx18EntOwner *o, u32 id, u32 *out)
{
    Cx18Ent *p;
    for (p = o->begin; p != o->end; p++)
        if (p->id == id) break;
    if (p != o->end) {
        *out = p->val;
        return 1;
    }
    return 0;
}

/* 0x8886AAC0: find the entry with this id and hand it on with the fixed hash 0xCF0C5EA8; null when absent */
void *ts4_ent_find_forward_8886AAC0(Cx18EntOwner *o, u32 id)
{
    Cx18Ent *p;
    for (p = o->begin; p != o->end; p++)
        if (p->id == id) break;
    if (p != o->end) return fn_88869C20(p, 0xCF0C5EA8);
    return 0;
}

/* 0x8886ABA8: when the argument's count is positive, find its id's entry and hand it on with the fixed hash */
void ts4_ent_find_forward_arg_8886ABA8(Cx18EntOwner *o, Cx18IdArg *a)
{
    if (a->count > 0) {
        u32 id = a->id;
        Cx18Ent *p;
        for (p = o->begin; p != o->end; p++)
            if (p->id == id) break;
        if (p != o->end) fn_88869C20(p, 0xCF0C5EA8);
    }
}

/* ---- vector clear through the block-move helper (the copy of an empty range) ---- */
extern void *fn_88562DC0(void *dst, const void *src, u32 n);
typedef struct Cx18MVec { char *begin; char *end; } Cx18MVec;
CX18_INL char *mcopy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}

/* 0x8886FDB8 */
void ts4_mvec_clear_8886FDB8(Cx18MVec *v)
{
    v->end = mcopy(v->end, v->end, v->begin);
}
