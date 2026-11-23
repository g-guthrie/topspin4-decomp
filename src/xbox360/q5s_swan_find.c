/*
 * Q5S swan: swing animation engine, clip lookups by record key (LTCG route, /Oc).
 * Check: python3 tools/fn_check_ltcg.py src/xbox360/q5s_swan_find.c <name>=<addr> --flags /Oc
 *        --context "flags(/Ob1):src/xbox360/w7a_a.c" --context src/xbox360/pp1_pool_primer.c
 * The callee must be in the link (not inlined) for its register survival (r5-r7 kept across the call).
 */

/* 16-byte keyed record (w7a_a.c W7aRec7150). */
typedef struct Q5sKeyRec {
    unsigned key;               /* +0x00 V 886C7150 */
    int w1, w2, w3;
} Q5sKeyRec;

/* 0x886C7150 (matched in w7a_a.c): first record of the object's relative array whose key equals *key. */
extern Q5sKeyRec *ts4_find_record_by_key_886C7150(void *o, const unsigned *key);

typedef struct Q5sClipItem {
    unsigned char pad_00[0x4];
    unsigned char *sub;         /* +0x04 V 886CB8D0 (record owner at sub + 4) */
} Q5sClipItem;

typedef struct Q5sClipItemVec {
    Q5sClipItem **begin;        /* +0x00 */
    Q5sClipItem **end;          /* +0x04 */
} Q5sClipItemVec;

typedef struct Q5sClipSet {
    unsigned char pad_00[0x5c];
    Q5sClipItemVec items;       /* +0x5c V 886CB8D0 */
} Q5sClipSet;

static __inline int q5s_clip_count(Q5sClipItemVec *v) { return (int)(v->end - v->begin); }
static __inline Q5sClipItem *q5s_clip_at(Q5sClipItemVec *v, int i) { return v->begin[i]; }

/* 0x886CB8D0: last item whose sub-record set holds a record keyed 0x7F6C2523; 0 if none.
 * The result local kept across the call gives `li r31,0; ...; mr r3,r31`; indexing through
 * q5s_clip_at(&s->items, i) gives the end-first loads and the `clrrwi` copy of begin. */
Q5sClipItem *ts4_find_last_clip_with_key_886CB8D0(Q5sClipSet *s)
{
    Q5sClipItem *r = 0;
    int i;
    for (i = q5s_clip_count(&s->items) - 1; i >= 0; i--) {
        unsigned key = 0x7F6C2523u;
        if (ts4_find_record_by_key_886C7150(q5s_clip_at(&s->items, i)->sub + 4, &key) != 0) {
            r = q5s_clip_at(&s->items, i);
            break;
        }
    }
    return r;
}
