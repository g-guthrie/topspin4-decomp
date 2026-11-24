/* CW23 part a: game flow database helpers. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

#ifdef _MSC_VER
#define CX23_INL static __forceinline
#else
#define CX23_INL static inline
#endif
typedef struct Cx23Tbl { int off; int count; } Cx23Tbl;
typedef struct Cx23Sub { u32 key; u8 pad[0xc4]; } Cx23Sub;
typedef struct Cx23Ent { int sub_off; int sub_count; u32 pad8; u32 id; u32 kind; } Cx23Ent;
typedef struct Cx23State { u8 pad0[0xbc]; Cx23Tbl tbl; } Cx23State;
typedef struct Cx23Game { u8 pad0[0x28]; Cx23State *state; u8 pad2c[4]; void *f30; } Cx23Game;
typedef struct Cx23Svc238Vt { void *s[10]; void (*slot10)(void *self, u32 key, void *out); } Cx23Svc238Vt;
typedef struct Cx23Svc238 { const Cx23Svc238Vt *vt; } Cx23Svc238;
typedef struct Cx23Ctx { u8 pad0[0x228]; u8 pool[0x10]; Cx23Svc238 *f238; } Cx23Ctx;
extern Cx23Game *lbl_88D459E8;
extern Cx23Ctx *lbl_88D45B1C;
extern int fn_8860BAB8(void *pool, int a, int b);

/* 0x88840D20 */
Cx23Sub *ts4_state_find_sub_88840D20(u32 id, u32 key)
{
    Cx23Tbl *t = &lbl_88D459E8->state->tbl;
    int i;
    for (i = 0; i < t->count; i++) {
        Cx23Ent *e = (Cx23Ent *)((char *)t + (i * 0x14 + t->off));
        if (e->id == id) {
            if (e->kind == 0x1197DFE3) {
                int idx = fn_8860BAB8(lbl_88D45B1C->pool, 0, e->sub_count - 1);
                Cx23Sub *r = 0;
                if (e->sub_off != -1) r = (Cx23Sub *)((char *)e + (idx * 0xc8 + e->sub_off));
                return r;
            }
            if (e->kind == 0x653B538D) {
                Cx23Sub *b, *en, *p;
                en = 0;
                if (e->sub_off != -1) en = (Cx23Sub *)((char *)e + (e->sub_count * 0xc8 + e->sub_off));
                b = 0;
                if (e->sub_off != -1) b = (Cx23Sub *)((char *)e + e->sub_off);
                for (p = b; p != en; p++)
                    if (p->key == key) return p;
            }
            return 0;
        }
    }
    return 0;
}

/* ---- event dispatch through the global lbl_88D45A08 ---- */
typedef struct Cx23Vt { void *s[11]; void (*slot11)(void *self, void *ev, u32 arg); } Cx23Vt;
typedef struct Cx23Obj { const Cx23Vt *vt; } Cx23Obj;
extern Cx23Obj *lbl_88D45A08;
typedef struct Cx23Param { u32 a; u8 flag; u8 pad[3]; u32 mode; } Cx23Param;
typedef struct Cx23Ev { u32 a; int kind; u8 flag; u32 val; } Cx23Ev;
typedef struct Cx23Params { u8 pad0[0x60]; Cx23Param p[1]; } Cx23Params;

/* 0x88865128 */
void ts4_param_dispatch_88865128(u32 *base, int idx, float f, u32 arg)
{
    Cx23Ev ev;
    Cx23Param *e = (Cx23Param *)(base + (idx + 8) * 3);
    ev.val = 0;
    ev.kind = 3;
    ev.flag = e->flag;
    ev.a = e->a;
    if (e->flag != 0) {
        if (e->mode >= 1) {
            if (e->mode != 1) return;
            ev.kind = 1;
            *(float *)&ev.val = f;
        } else {
            ev.val = (int)f;
            ev.kind = 0;
        }
    } else {
        switch (idx) {
        case 0:
            ev.val = base[(u32)f + 0x21];
            ev.kind = 2;
            break;
        case 2:
            ev.kind = 2;
            ev.val = base[(u32)f + 0x2d];
            break;
        }
    }
    lbl_88D45A08->vt->slot11(lbl_88D45A08, &ev, arg);
}

/* ---- ring read of 6-byte items out to a stream ---- */
typedef struct Cx23Item6 { u16 v[3]; } Cx23Item6;
typedef struct Cx23Ring { Cx23Item6 *begin; Cx23Item6 *end; u32 pad8; u32 stride; } Cx23Ring;
typedef struct Cx23SinkVt { void *s[4]; void (*write)(void *self, void *data, u32 bytes); } Cx23SinkVt;
typedef struct Cx23Sink { const Cx23SinkVt *vt; } Cx23Sink;

/* 0x88870328: write `*count` items starting at item `*pos / stride` of the ring, wrapping at the end */
int ts4_ring_write_out_88870328(Cx23Ring *r, Cx23Sink *out, u32 *pos, u32 *count)
{
    u32 start = *pos / r->stride;
    u32 total = (u32)(r->end - r->begin) / r->stride;
    u32 n = *count;
    if (n + start <= total) {
        out->vt->write(out, r->begin + r->stride * start, (u32)(r->stride * n * 6));
        return 1;
    }
    out->vt->write(out, r->begin + r->stride * start, (u32)(r->stride * (total - start) * 6));
    out->vt->write(out, r->begin, (u32)(r->stride * (*count - total + start) * 6));
    return 1;
}


/* ---- name builders: the string copy runs inline and its result is dropped ---- */
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
extern char lbl_880E1064[];
extern char lbl_880E1078[];
extern char lbl_880E1084[];
extern char *ts4_crt_strncat_88564EF0(char *front, const char *back, u32 count);
extern void *ts4_find_service(u32 hash);
extern void *fn_88611620(void *svc, int name);
typedef struct Cx23Name { int v; } Cx23Name;
extern Cx23Name *ts4_build_name_from_two_literals_8883AD10(Cx23Name *out, const char *suffix);
extern Cx23Name *ts4_build_name_from_two_literals_8883ADF8(Cx23Name *out, const char *suffix);

#define CX23_NAME_THEN_SEND(NAME, STR2, BUILD) \
void NAME(const char *suffix) \
{ \
    char buf[124]; \
    const char *s = lbl_880E1064; \
    char *d = buf; \
    Cx23Name tmp; \
    void *svc; \
    while (d != buf + 124) { \
        char c = *s; \
        if (!c) break; \
        *d = c; d++; s++; \
    } \
    *d = 0; \
    if (suffix) \
        ts4_crt_strncat_88564EF0(buf, suffix, 124 - strlen(buf)); \
    ts4_crt_strncat_88564EF0(buf, STR2, 124 - strlen(buf)); \
    svc = ts4_find_service(0xE2AE8939); \
    fn_88611620(svc, BUILD(&tmp, suffix)->v); \
}
/* 0x8883C318 */
CX23_NAME_THEN_SEND(ts4_send_name_8883C318, lbl_880E1084, ts4_build_name_from_two_literals_8883AD10)
/* 0x8883C428 */
CX23_NAME_THEN_SEND(ts4_send_name_8883C428, lbl_880E1078, ts4_build_name_from_two_literals_8883ADF8)



/* ---- registering a fixed list of hashes ---- */
extern void fn_8883B8B0(void *self, int a, u32 *hash, int flag);
#define CX23_REG(H) { u32 h = H; fn_8883B8B0(self, a, &h, 0); }

/* 0x8883E140: call fn_8883B8B0 once for each of eight fixed hashes */
void ts4_register_hashes_8883E140(void *self, int a)
{
    CX23_REG(0xA6A1B2AE)
    CX23_REG(0xB8820C15)
    CX23_REG(0xE630E16B)
    CX23_REG(0x45FFFB93)
    CX23_REG(0x71198650)
    CX23_REG(0x6A4B2EA4)
    CX23_REG(0xCEE7D1F2)
    CX23_REG(0xF431F5E8)
}


/* ---- slot table of 0x18-byte records: look up by id or take the first unused one ---- */
typedef struct Cx23Slot { u32 id; u32 stamp; int level; u32 extra; u32 handle; u8 flag; u8 used; u8 pad16[2]; } Cx23Slot;
typedef struct Cx23SlotHost { u8 pad0[0xa4]; Cx23Tbl slots; u8 pad_ac[0xd20 - 0xac]; u32 stamp; } Cx23SlotHost;
typedef struct Cx23SlotOwner { u8 pad0[0x24]; Cx23SlotHost *host; } Cx23SlotOwner;
typedef struct Cx23Stats { u8 pad0[0xec]; u32 handle; } Cx23Stats;
extern Cx23Stats *fn_8883CC80(Cx23SlotOwner *o, u32 arg);

CX23_INL Cx23Slot *find_slot(Cx23Tbl *t, u32 id)
{
    Cx23Slot *r = 0;
    int i;
    for (i = 0; i < t->count; i++) {
        Cx23Slot *s = (Cx23Slot *)((char *)t + (i * 0x18 + t->off));
        if (s->id == id) { r = s; break; }
    }
    return r;
}

/* 0x8883EC78 */
void ts4_slot_claim_8883EC78(Cx23SlotOwner *o, u32 id, u8 flag, int level, u32 extra, u32 arg)
{
    Cx23Tbl *t = &o->host->slots;
    Cx23Slot *found, *p, *end;
    u8 ok = 0;
    end = 0;
    if (t->off != -1) end = (Cx23Slot *)((char *)t + (t->count * 0x18 + t->off));
    p = 0;
    if (t->off != -1) p = (Cx23Slot *)((char *)t + t->off);
    found = find_slot(t, id);
    if (found == 0) {
        ok = 1;
        for (; p != end; p++) {
            if (p->used == 0) { found = p; p->used = 1; break; }
        }
    } else if (flag == 1 || !(level < found->level)) {
        ok = 1;
    }
    if (ok == 1) {
        Cx23Stats *r = fn_8883CC80(o, arg);
        found->id = id;
        found->stamp = o->host->stamp;
        found->flag = flag;
        found->level = level;
        found->extra = extra;
        found->handle = r->handle;
    }
}

/* ---- wide label built from two names ---- */
extern void fn_88608150(const char *src, unsigned short *dst, u32 n);
extern void fn_881AC518(void *self, unsigned short *begin, unsigned short *end);
typedef struct Cx23Label { u8 pad0[4]; char first[0x40]; char second[0x40]; } Cx23Label;

/* 0x888417F8: join rec->first, the optional suffix and rec->second into a 63-char name, widen it and hand the nonempty result on */
void ts4_label_forward_888417F8(void *self, Cx23Label *rec, const char *suffix)
{
    char buf[64];
    unsigned short wide[64];
    const char *s = rec->first;
    char *d = buf;
    u32 n;
    while (d != buf + 63) {
        char c = *s;
        if (!c) break;
        *d = c; d++; s++;
    }
    *d = 0;
    if (suffix)
        ts4_crt_strncat_88564EF0(buf, suffix, 63 - strlen(buf));
    ts4_crt_strncat_88564EF0(buf, rec->second, 63 - strlen(buf));
    fn_88608150(buf, wide, 0x40);
    n = 0;
    if (wide[0] != 0) {
        const unsigned short *q = wide;
        do { ++q; ++n; } while (*q != 0);
    }
    if (wide != wide + n) fn_881AC518(self, wide, wide + n);
}

/* ---- record description built from a key ---- */
extern Cx23Name *ts4_build_name_from_two_literals_8883AEE0(Cx23Name *out, const char *suffix);
extern Cx23Name *ts4_build_name_from_literal_8883AFC8(Cx23Name *out, const char *suffix);
extern int *fn_88848BB0(int key);
extern const char lbl_880C1320[];
extern void *ts4_find_record_by_key_881AD100(void *tbl, u32 *key);
extern u32 *ts4_find_record_by_key_88187800(void *tbl, u32 *key);
extern const char *fn_8883EA70(void *a, u32 b);
typedef struct Cx23ObjVt { void *s[19]; void *(*slot19)(void *self, int a); } Cx23ObjVt;
typedef struct Cx23VObj { const Cx23ObjVt *vt; } Cx23VObj;
typedef struct Cx23Info { u8 pad0[0xc]; u32 name_a; u32 name_b; u32 name_c; u32 pad1c; u32 pad20; } Cx23Info;
typedef struct Cx23InfoOut { u32 key; u32 pad4; u32 f8; u32 name_a; u32 name_b; u32 name_c; u32 pad18; u32 f1c; u32 f20; u8 pad24[0x128 - 0x24]; u8 set; } Cx23InfoOut;
typedef struct Cx23InfoRec { u8 pad0[0x4c]; u8 sub[0x10]; u32 f5c; u32 f60; } Cx23InfoRec;
typedef struct Cx23InfoOwn { u8 pad0[0x24]; struct { u8 pad0[0x40]; Cx23VObj *o; } *mid; } Cx23InfoOwn;

/* 0x8884A7B0: fill the description for a key unless it is the no-key hash */
void ts4_info_fill_8884A7B0(Cx23InfoOwn *o, Cx23InfoOut *out, u32 key)
{
    u32 noKey = 0xDFA2AFF1;
    Cx23Name tmp0, tmp1;
    if (key == noKey) return;
    out->key = key;
    out->set = 1;
    {
        int *own = fn_88848BB0(key) + 0xe8 / 4;
        const char *name = *own != -1 ? (char *)own + *own : lbl_880C1320;
        Cx23InfoRec *rec;
        out->name_a = ts4_build_name_from_two_literals_8883AEE0(&tmp0, name)->v;
        out->name_b = ts4_build_name_from_two_literals_8883ADF8(&tmp1, name)->v;
        out->name_c = ts4_build_name_from_two_literals_8883AD10(&tmp0, name)->v;
        rec = (Cx23InfoRec *)ts4_find_record_by_key_881AD100(o->mid->o->vt->slot19(o->mid->o, 0), &key);
        if (rec) {
            out->f8 = rec->f5c;
            out->f1c = ts4_build_name_from_literal_8883AFC8(&tmp1, fn_8883EA70(lbl_88D459E8->f30, rec->f60))->v;
            tmp0.v = 0x1208D727;
            out->f20 = ts4_find_record_by_key_88187800(rec->sub, (u32 *)&tmp0)[4];
        } else {
            out->f8 = noKey;
            out->f1c = noKey;
            out->f20 = 0;
        }
    }
}

