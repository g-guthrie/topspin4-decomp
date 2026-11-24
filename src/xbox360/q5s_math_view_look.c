/*
 * 0x8863AA58: builds the owner's view matrix (+0x80) with ts4_mat_look_to_8825CF28(eye, eye - from,
 * up) from three float3 points (w = 0.0f, g_ts4_event_value) and sets the valid flag at +0x23C.
 * Caller: 0x8863B098 (passes the object at +0x4 of its argument).
 *
 * Codegen (LTCG, primer-only context): each float3 goes through one shared 16-byte stack union
 * (x, y, z, then w = zero) and is reloaded with lvx. The matrix is stored through a local
 * `Af1Mat *v = &s->view` taken before the call: that keeps this+0x80 in r31 across the call and
 * orders the flag store after the four stvx. `s->view = m` or `s->view.r[i] = m.r[i]` gives one saved
 * GPR, a smaller frame and the stb mixed into the vector stores. Do not give the callee body as
 * context: with ts4_mat_look_to in the same LTCG unit the compiler keeps `s` in a volatile register
 * across the call (interprocedural register knowledge), which the target does not do.
 */
#include "af1_vector.h"

extern const float g_ts4_event_value; /* 0.0f */
Af1Mat ts4_mat_look_to_8825CF28(__vector4 eye, __vector4 dir, __vector4 up);

typedef struct Q5sViewF3 {
    float x, y, z;
} Q5sViewF3;

typedef struct Q5sViewOwner {
    char pad00[0x80];
    Af1Mat view;                /* +0x80 */
    char padc0[0x23c - 0xc0];
    unsigned char valid;        /* +0x23C */
} Q5sViewOwner;

typedef union Q5sViewV4 {
    __vector4 v;
    float f[4];
} Q5sViewV4;

AF1_FORCEINLINE __vector4 q5s_view_load3(const Q5sViewF3 *p)
{
    Q5sViewV4 u;
    u.f[0] = p->x;
    u.f[1] = p->y;
    u.f[2] = p->z;
    u.f[3] = g_ts4_event_value;
    return u.v;
}

void ts4_view_look_at_8863AA58(Q5sViewOwner *s, const Q5sViewF3 *eye, const Q5sViewF3 *from,
                               const Q5sViewF3 *up)
{
    __vector4 f = q5s_view_load3(from);
    __vector4 u = q5s_view_load3(up);
    __vector4 e = q5s_view_load3(eye);
    Af1Mat m;
    Af1Mat *v = &s->view;
    m = ts4_mat_look_to_8825CF28(e, __vsubfp(e, f), u);
    v->r[0] = m.r[0];
    v->r[1] = m.r[1];
    v->r[2] = m.r[2];
    v->r[3] = m.r[3];
    s->valid = 1;
}
