/* Q5 batch K (Opus A): small gameplay helper byte-matched on b215 (TS4_MATCHING_DIR=work/matching-b215),
 * with and without /Oc. */
typedef unsigned int u32;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef struct Ts4HashTable { u32 pad[7]; void *buckets; } Ts4HashTable;
typedef struct Q5Ent3C { char pad[0x2c]; u32 id; u32 arg; char pad2[0x3c - 0x34]; } Q5Ent3C;
typedef struct Q5RelEnts { int off; u32 count; } Q5RelEnts;
typedef struct Q5EntOwner { char pad[0x1c]; u32 level; } Q5EntOwner;
extern Ts4HashTable *lbl_88D458F0;
extern void *ts4_hash_find_881AB900(Ts4HashTable *table, u32 hash, Ts4Handle12 h);
extern void fn_8886F9A0(Q5EntOwner *self, u32 level, u32 id, u32 arg);
static Q5Ent3C *q5_ents_begin(Q5RelEnts *a) { Q5Ent3C *r = 0; if (a->off != -1) r = (Q5Ent3C *)((char *)a + a->off); return r; }
static Q5Ent3C *q5_ents_end(Q5RelEnts *a) { Q5Ent3C *r = 0; if (a->off != -1) r = (Q5Ent3C *)((char *)a + a->count * 0x3c + a->off); return r; }
/* Swing_DLL.xex 0x8886FCC0: look up the 0xECE067E5 record list (881AB900, handle {0, 0xFFFFF, 0}) and apply every
 * 0x3c-byte entry's (id, arg) pair at level - 1 (8886F9A0) */
void ts4_apply_ece067e5_entries_8886FCC0(Q5EntOwner *self)
{
    Ts4Handle12 h;
    Q5RelEnts *a;
    Q5Ent3C *p, *e;
    h.a = 0;
    h.b = 0xFFFFF;
    h.c = 0;
    a = (Q5RelEnts *)ts4_hash_find_881AB900(lbl_88D458F0, 0xECE067E5, h);
    e = q5_ents_end(a);
    for (p = q5_ents_begin(a); p != e; p++)
        fn_8886F9A0(self, self->level - 1, p->id, p->arg);
}
