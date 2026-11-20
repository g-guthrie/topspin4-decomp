/* CW18 part f: flow-database table helpers (0x88850000-0x88871F08). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Cx18Tbl { int off; int count; } Cx18Tbl;
extern Cx18Tbl *ts4_hash_find_null_88868BB8(void);

/* 0x888697B0: set the flag byte (+0xc) of the 0x10-byte entry whose key (+0) matches */
void ts4_tbl_set_flag_888697B0(u32 key, u8 flag)
{
    Cx18Tbl *t = ts4_hash_find_null_88868BB8();
    int i;
    for (i = 0; i < t->count; i++) {
        char *e = (char *)t + (i * 0x10 + t->off);
        if (*(u32 *)e == key) {
            e[0xc] = flag;
            break;
        }
    }
}

typedef struct Cx18Host { u8 pad[0x214]; int hdr; } Cx18Host;
typedef struct Cx18Self1d { u8 pad0[0x1d]; u8 f1d; u8 pad1e[2]; int f20; Cx18Host *f24; u32 f28; } Cx18Self1d;
typedef struct Cx18Ent100 { u8 pad[0x100]; u32 f100; } Cx18Ent100;
extern Cx18Ent100 *ts4_find_entry_by_alt_id_88866C30(u32 a, u32 b);

/* 0x88866D00: commit the pending value into the slot (0x20-byte entries behind the relative base), clear the pending state and reset the found entry */
u8 ts4_commit_pending_88866D00(Cx18Self1d *o, u32 idx)
{
    if (o->f1d == 0) return 0;
    {
        u8 zero = 0;
        int *base = &o->f24->hdr;
        int pending = o->f20;
        char *rec;
        Cx18Ent100 *e;
        o->f1d = zero;
        rec = (char *)base + (idx * 0x20 + *base);
        if (pending != -1) *(int *)(rec + 0x10) = pending;
        o->f20 = -1;
        e = ts4_find_entry_by_alt_id_88866C30(*(u32 *)(rec + 0x10), o->f28);
        if (e != 0) e->f100 = zero;
        return 1;
    }
}

/* ---- flag setters on tables found by hash with the null handle {0, 0xFFFFF, 0} ---- */
typedef struct Cx18Handle12 { u32 a, b, c; } Cx18Handle12;
typedef struct Cx18HTbl { int off; int count; } Cx18HTbl;
extern void *lbl_88D458F0;
extern Cx18HTbl *ts4_hash_find_881AB900(void *table, u32 hash, Cx18Handle12 h);

#define CX18_HTBL_SET_FLAG(NAME, HASH, STRIDE, FOFF) \
void NAME(u32 key, u8 flag) \
{ \
    Cx18Handle12 h; \
    Cx18HTbl *t; \
    int i; \
    h.a = 0; \
    h.b = 0xFFFFF; \
    h.c = 0; \
    t = ts4_hash_find_881AB900(lbl_88D458F0, HASH, h); \
    for (i = 0; i < t->count; i++) { \
        char *e = (char *)t + (i * STRIDE + t->off); \
        if (*(u32 *)e == key) { \
            e[FOFF] = flag; \
            break; \
        } \
    } \
}
/* 0x88869690, 0x88869830: set the flag byte of the entry with this key in the table of a fixed hash */
CX18_HTBL_SET_FLAG(ts4_htbl_set_flag_88869690, 0x251E3B37, 0x10, 0xc)
CX18_HTBL_SET_FLAG(ts4_htbl_set_flag_88869830, 0x8928F4FD, 0xc, 8)

/* ---- serialisation of a byte vector through a stream's virtual write slot (+0x10) ---- */
typedef struct Cx18StreamVt { void *s[4]; void (*write)(void *self, const void *buf, u32 n); } Cx18StreamVt;
typedef struct Cx18Stream { const Cx18StreamVt *vt; } Cx18Stream;
typedef struct Cx18ByteVec { u8 *begin; u8 *end; u8 pad8[0x44]; u32 f4c; } Cx18ByteVec;

/* 0x88870020: write the word at +0x4c, the byte length and the bytes themselves */
u32 ts4_stream_write_bytes_88870020(Cx18ByteVec *v, Cx18Stream *s)
{
    u32 w = v->f4c;
    u32 n;
    s->vt->write(s, &w, 4);
    n = v->end - v->begin;
    s->vt->write(s, &n, 4);
    s->vt->write(s, v->begin, n);
    return 1;
}
