/* CW14 part c: game flow database helpers (0x8883C000-0x88850000). Built with /Oc. */
typedef unsigned int u32;

typedef struct Cx14Db { char pad[8]; void *tbl; } Cx14Db;
typedef struct Cx14Hdr { int off; int count; } Cx14Hdr;

extern void *ts4_find_record_by_key_881AD100(void *tbl, void *key);
extern void *ts4_find_record_by_key_88187800(void *tbl, void *key);

/* ---- hash lookups with the null handle ---- */
typedef struct Cx14Handle12 { u32 a, b, c; } Cx14Handle12;
typedef struct Cx14HEnt { u32 f0, f4, f8; void **fc; } Cx14HEnt;
extern void *lbl_88D458F0;
extern Cx14HEnt *ts4_hash_find_881AB900(void *table, u32 hash, Cx14Handle12 h);
typedef struct Cx14Pair2 { void *a; void *b; } Cx14Pair2;
typedef struct Cx14VT { void **vt; } Cx14VT;
typedef struct Cx14VO { void **vt; char pad[0x3c]; Cx14VT *f40; } Cx14VO;

/* 0x8884E2A0: look up a record by hash and fetch two objects through slot 0x4c of its member and of the member's +0x40 */
void ts4_hash_fetch_pair_8884E2A0(Cx14Pair2 *out)
{
    Cx14Handle12 h;
    Cx14VO *o;
    h.a = 0;
    h.b = 0xFFFFF;
    h.c = 0;
    {
        Cx14VT *m = (Cx14VT *)ts4_hash_find_881AB900(lbl_88D458F0, 0x0651EA29, h)->fc;
        o = (Cx14VO *)((void *(*)(void *, int))m->vt[0x4c / 4])(m, 0);
    }
    out->a = o;
    out->b = ((void *(*)(void *, int))o->f40->vt[0x4c / 4])(o->f40, 0);
}

/* 0x8883DDA0: true for four selector hashes unless the member value is one of two excluded hashes */
extern u32 *ts4_member_field_addr_8883B578(void *self, int a);
u32 ts4_member_is_listed_8883DDA0(void *self, int a, u32 k)
{
    u32 v = *ts4_member_field_addr_8883B578(self, a);
    if (k == 0xC7EFB4C9 || k == 0xB67D10C7 || k == 0x3DE089AA || k == 0x4C722DA4) {
        if (v != 0x10A847FE && v != 0x55B44557) return 1;
    }
    return 0;
}

/* 0x88840708: add delta to the entry idx (12-byte stride, +0xc self-relative) of a record, return the property value plus delta */
int ts4_db_adjust_entry_88840708(Cx14Db *self, u32 key, int idx, int delta)
{
    int res = 0;
    char *r = (char *)ts4_find_record_by_key_881AD100(self->tbl, &key);
    u32 k2;
    if (r != 0) {
        char *hdr = r + 0xc;
        char *e = hdr + (idx * 12 + *(int *)hdr);
        if (delta > 0) *(int *)(e - 8) += delta;
        k2 = 0x13335288;
        res = *(int *)((char *)ts4_find_record_by_key_88187800(r + 0x4c, &k2) + 4) + delta;
    }
    return res;
}

extern Cx14Hdr *ts4_hash_find_null_88848D60(u32 key);

/* 0x8884C318: look up key in the 8-byte-stride table from 88848D60 and return its value */
u32 ts4_hash_find_value_8884C318(int key)
{
    u32 res = 0;
    Cx14Hdr *t = ts4_hash_find_null_88848D60((u32)key);
    if (t != 0) {
        int i;
        for (i = 0; i < t->count; i++) {
            char *e = (char *)t + (i * 8 + t->off);
            if (*(int *)e == key) { res = *(u32 *)(e + 4); break; }
        }
    }
    return res;
}
