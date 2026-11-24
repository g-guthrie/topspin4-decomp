/* nearmiss: 8 off (plain and LTCG); the target loads owner->q (+0x20) before dereferencing the selected table pointer and
 * loads the vector cap before end; we compute the u16 ref first. Statement orders (60 perms), push helpers, cap/end
 * compare forms and ref expressions do not move it (best 8). */
/* 0x888CC218: if enabled (+0x1c), push an 8-byte record {key, ref = table + idx, kind, 0} onto the vector at
 * owner->q(+0x20)+0x48; table is *(+0x4c) when use_main else *(+0x44). */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct Rec { u32 key; u16 ref; u8 kind; u8 done; } Rec;
typedef struct Vec { Rec *begin; Rec *end; Rec *cap; } Vec;
typedef struct Q { char p[0x48]; Vec recs; } Q;
typedef struct Own { char p[0x1c]; void *enabled; Q *q; char p24[0x20]; u16 **alt; char p48[4]; u16 **main; } Own;
void ts4_vector_grow_append_881784B0(Vec *v, Rec *where, const Rec *val);
void ts4_queue_push_record_888CC218(Own *o, u8 kind, const u32 *key, u16 idx, u8 use_main)
{
    Rec r;
    Vec *v;
    if (!o->enabled) return;
    r.key = *key;
    r.kind = kind;
    r.done = 0;
    r.ref = (u16)(unsigned long)((use_main ? *o->main : *o->alt) + idx);
    v = &o->q->recs;
    if (v->end != v->cap) {
        if (v->end != 0) *v->end = r;
        v->end++;
    } else {
        ts4_vector_grow_append_881784B0(v, v->end, &r);
    }
}
