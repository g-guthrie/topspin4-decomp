/* 0x886F1D90: Maps kind to a bucket index through the global kind table (-1 if absent), then returns the first 0xA0-byte record in that bucket whose u64 id matches, or 0. */
/* Matched on /Oc (agAH). Cache the bucket end in a local assigned before the loop. */
typedef struct KeyIndex { unsigned int key; int index; } KeyIndex;
typedef struct KeyVec { KeyIndex *begin; KeyIndex *end; } KeyVec;
typedef struct Tables { char p0[0x28]; KeyVec *kinds; } Tables;
typedef struct Rec { char p0[0x48]; unsigned __int64 id; char p50[0x50]; } Rec;
typedef struct Bucket { Rec *begin; Rec *end; int p8; int pc; } Bucket;
typedef struct Store { char p0[0x20]; Bucket *buckets; } Store;
extern Tables *lbl_88D45AD4;
Rec *fn_886F1D90(Store *s, unsigned int kind, unsigned __int64 id)
{
    KeyVec *v = lbl_88D45AD4->kinds;
    KeyIndex *p;
    int index;
    Bucket *b;
    Rec *r;
    Rec *end;
    for (p = v->begin; p != v->end; p++) {
        if (p->key == kind)
            break;
    }
    index = p != v->end ? p->index : -1;
    b = &s->buckets[index];
    end = b->end;
    for (r = b->begin; r < end; r++) {
        if (r->id == id)
            return r;
    }
    return 0;
}
