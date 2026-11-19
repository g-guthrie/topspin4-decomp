/* 0x88867A40: clears every 0x48-byte slot in the self-relative table at +0 (count +4): stamps the slot tag from
 * lbl_88D45B1C->0x27c and zeroes its 0x40 data bytes; clears +0x1c, then looks up o->key in the lbl_88D45B30 key/value
 * vector and passes the value (or 0) to fn_88887A00. */

typedef unsigned int u32;
typedef struct { u32 a; unsigned char d[0x40]; u32 tag; } Ent;
typedef struct { int rel; int n; char p8[4]; u32 key; char p10[0x1c-0x10]; u32 f1c; } O;
typedef struct { char p[0x27c]; u32 tag; } G1;
typedef struct { u32 key; void *val; } KV;
typedef struct { char p[0x1c]; KV *first, *last; } G2;
extern G1 *lbl_88D45B1C;
extern G2 *lbl_88D45B30;
extern void *ts4_memset(void *dst, int c, u32 n);
extern void fn_88887A00(void *v);
static Ent *ebegin(O *o) { Ent *e = 0; if (o->rel != -1) e = (Ent *)((char *)o + o->rel); return e; }
static Ent *eend(O *o) { Ent *e = 0; if (o->rel != -1) e = (Ent *)((char *)o + o->rel) + o->n; return e; }
void ts4_slot_table_reset_88867A40(O *o) {
    Ent *end = eend(o), *e;
    KV *last, *it;
    void *v;
    for (e = ebegin(o); end != e; e++) { e->tag = lbl_88D45B1C->tag; ts4_memset(e->d, 0, 0x40); }
    o->f1c = 0;
    v = 0;
    last = lbl_88D45B30->last;
    for (it = lbl_88D45B30->first; last != it; it++) if (o->key == it->key) { v = it->val; break; }
    fn_88887A00(v);
}
