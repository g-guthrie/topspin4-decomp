/* q5s eng: std::vector push_back of a default-constructed element (LTCG).
 * The element is constructed in place when the end pointer is non-null; end is re-read after the
 * stores (they may alias the vector), which gives the target's reload before the increment. */
typedef unsigned int u32;

extern float g_ts4_event_value; /* 0.0f */

/* 0x18-byte element: four float fields at +4..+0x10 set to zero, words 0 and 5 left untouched. */
typedef struct EngItem24 { float w[6]; } EngItem24;
typedef struct EngVecItem24 { EngItem24 *begin; EngItem24 *end; EngItem24 *cap; } EngVecItem24;
void ts4_vector_grow_append_88263B60(EngVecItem24 *v, EngItem24 *where);

EngItem24 *ts4_vec_push_default_88263290(EngVecItem24 *v)
{
    EngItem24 *e;
    if (v->end == v->cap)
        ts4_vector_grow_append_88263B60(v, v->end);
    e = v->end;
    if (e) {
        float z = g_ts4_event_value;
        e->w[1] = z;
        e->w[2] = z;
        e->w[3] = z;
        e->w[4] = z;
    }
    v->end = v->end + 1;
    return v->end - 1;
}

/* 0x14-byte all-zero element. */
typedef struct EngItem20 { u32 w[5]; } EngItem20;
typedef struct EngVecItem20 { EngItem20 *begin; EngItem20 *end; EngItem20 *cap; } EngVecItem20;
void ts4_vector_grow_append_88278990(EngVecItem20 *v, EngItem20 *where);

EngItem20 *ts4_vec20_push_zero_88278850(EngVecItem20 *v)
{
    EngItem20 *e;
    if (v->end == v->cap)
        ts4_vector_grow_append_88278990(v, v->end);
    e = v->end;
    if (e) {
        e->w[0] = 0;
        e->w[1] = 0;
        e->w[2] = 0;
        e->w[3] = 0;
        e->w[4] = 0;
    }
    v->end = v->end + 1;
    return v->end - 1;
}
