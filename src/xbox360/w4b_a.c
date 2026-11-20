#include "w4b_types.h"

struct W4bRec { W4B_PAD(0x24); int key; W4B_PAD(0x30 - 0x28); };
struct W4bVec { struct W4bRec *begin; struct W4bRec *end; };
struct W4bOwnerA { W4B_PAD(0x5A0); struct W4bVec recs; };

W4B_INLINE int w4b_vec_empty(const struct W4bVec *v) { return v->begin == v->end; }
W4B_INLINE struct W4bRec *w4b_vec_begin(const struct W4bVec *v) { return v->begin; }
W4B_INLINE int w4b_vec_size(const struct W4bVec *v) { return (int)(v->end - v->begin); }

/* Swing_DLL.xex 0x8866FC18 */
struct W4bRec *ts4_record_by_key_8866FC18(struct W4bOwnerA *o, int key)
{
    if (!w4b_vec_empty(&o->recs)) {
        int i = key - w4b_vec_begin(&o->recs)->key;
        if (i >= 0 && i < w4b_vec_size(&o->recs))
            return &w4b_vec_begin(&o->recs)[i];
    }
    return 0;
}
