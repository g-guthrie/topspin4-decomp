/* Q5 equivalent route: xdata child-node loader (Swing_DLL.xex 0x888BB670, 0x206c bytes).
 *
 * ts4_load_child_params_888BB670(owner) walks the children of the owner's xdata reference (+0x4..+0xf). For each
 * child it reads the child's type hash and, for the known types, resolves the child id (sub-view 0x2c77dc6a) and
 * reads float / bool / float3 sub-views into the matching parameter setter of the owner (cx34_a.c setters and the
 * slot thunks of d2f_thunks_a_888873E8.c). Every handled child is then handed to fn_88707908; an unknown type is
 * skipped. The hashes are crc32 names whose strings are unknown, so they keep their hex value.
 * Copy discipline follows the machine code: a child id is read through the forward call's out buffer, scalar views
 * through a copy of the reference it returns; the first sub-node of a group is built in place, later ones are copied
 * over it. Not byte-matched: see the byte-gap line. */
#include "vx1_vector.h"
__vector4 __vsldoi(__vector4 a, __vector4 b, int imm);
#ifdef _MSC_VER
#pragma intrinsic(__vsldoi)
#endif

typedef unsigned int q5b_u32;
typedef unsigned char q5b_u8;

#ifdef _MSC_VER
#define Q5B_INLINE static __forceinline
#else
#define Q5B_INLINE static inline
#endif

typedef struct Q5bRef { q5b_u32 node; q5b_u32 offset; q5b_u32 extra; } Q5bRef;
typedef struct Q5bF3 { float x, y, z; } Q5bF3;
typedef struct Q5bF3Pair { Q5bF3 a, b; } Q5bF3Pair;

typedef struct Q5bChildOwner {
    q5b_u32 w0;
    Q5bRef ref;          /* +0x04 xdata node of the parameter block */
    char *child;         /* +0x10 child object, flag byte at +0xa8 */
} Q5bChildOwner;

/* Limb configuration block for type 0xf6ca7e72 (0x70 bytes). */
typedef struct Q5bLimbCfg {
    q5b_u8 on0; float a0, b0;            /* +0x00 sub-node 0xffd00afa */
    q5b_u8 on1; float a1, b1;            /* +0x0c sub-node 0x88d73a6c */
    q5b_u8 on2; __vector4 p2, q2;        /* +0x18 sub-node 0x19280e4e */
    q5b_u8 on3; __vector4 p3, q3;        /* +0x40 sub-node 0xffd3d99e */
} Q5bLimbCfg;

extern int ts4_handle_fwd_slot1c_8860ABB0(Q5bRef *node);
extern Q5bRef *ts4_handle_forward0_88610AC8(Q5bRef *out, Q5bRef *node);
extern Q5bRef *ts4_handle_forward0_88610948(Q5bRef *out, Q5bRef *node);
extern q5b_u32 *ts4_handle_release_881506A0(q5b_u32 *out, Q5bRef *node);
extern Q5bRef *ts4_handle_forward_88150770(Q5bRef *out, Q5bRef *node, q5b_u32 *hash);
extern Q5bRef *ts4_handle_forward_88610A48(Q5bRef *out, Q5bRef *node, q5b_u32 *hash);
extern void fn_88169350(q5b_u32 *out, Q5bRef *view);
extern float ts4_if_get_u32_off0_8816CCE0(Q5bRef *view);
extern q5b_u8 ts4_gp0_xdata_get_bool_88163C60(Q5bRef *view);
extern void fn_88707908(Q5bRef child);

extern void fn_888B9460(Q5bChildOwner *self);
extern void ts4_bind_child_by_id_888BB5A8(Q5bChildOwner *self, q5b_u32 id, q5b_u32 key);
extern void ts4_emit_child_set_vvff_888AE880(Q5bChildOwner *self, q5b_u32 key, Q5bF3 *a, Q5bF3 *b, float *lo, float *hi);
extern void ts4_emit_child_set_vv_888AE7F8(Q5bChildOwner *self, q5b_u32 key, Q5bF3 *a, Q5bF3 *b);
extern void ts4_child_set_pair_58_888AE788(Q5bChildOwner *self, q5b_u32 key, float *a, float *b);
extern q5b_u32 ts4_if_get_u32_off10_888AE728(Q5bChildOwner *self, q5b_u32 key, float *v8);
extern void ts4_child_set_float_60_888AE6C8(Q5bChildOwner *self, q5b_u32 key, float v);
extern q5b_u32 ts4_if_get_u32_off10_888AE668(Q5bChildOwner *self, q5b_u32 key, Q5bLimbCfg *cfg);
extern void ts4_child_set_mode_xyz_888AE590(Q5bChildOwner *self, q5b_u32 key, q5b_u8 mode, float x, float y, float z);
extern void ts4_child_set_float_74_888AE530(Q5bChildOwner *self, q5b_u32 key, float v);
extern void ts4_child_set_float_78_888AE4D0(Q5bChildOwner *self, q5b_u32 key, float v);
extern void ts4_child_set_float_7c_888AE470(Q5bChildOwner *self, q5b_u32 key, float v);
extern q5b_u32 ts4_if_get_u32_off10_888AE410(Q5bChildOwner *self, q5b_u32 key, Q5bF3Pair *v);
extern q5b_u32 ts4_if_get_u32_off10_888AE3B0(Q5bChildOwner *self, q5b_u32 key, float *v6);
extern void ts4_emit_owner_set_f_888AF6E8(Q5bChildOwner *self, q5b_u32 key, float v);
extern void ts4_child_set_u8_888AE358(Q5bChildOwner *self, q5b_u32 key, q5b_u8 v);

#define Q5B_VIEW_ID 0x2c77dc6au

Q5B_INLINE q5b_u8 q5b_ref_invalid(Q5bRef *r)
{
    return r->node == 0 || r->offset == 0xfffff;
}

Q5B_INLINE q5b_u32 q5b_type_of(Q5bRef *node)
{
    q5b_u32 t;
    return *ts4_handle_release_881506A0(&t, node);
}

/* Child id: read through the forward call's out buffer. */
Q5B_INLINE q5b_u32 q5b_id_of(Q5bRef *node)
{
    q5b_u32 h = Q5B_VIEW_ID;
    q5b_u32 key;
    Q5bRef v;
    ts4_handle_forward_88150770(&v, node, &h);
    fn_88169350(&key, &v);
    return key;
}

/* Scalar views: read through a copy of the returned reference. */
Q5B_INLINE float q5b_float(Q5bRef *node, q5b_u32 hash)
{
    q5b_u32 h = hash;
    Q5bRef tmp;
    Q5bRef v = *ts4_handle_forward_88150770(&tmp, node, &h);
    return ts4_if_get_u32_off0_8816CCE0(&v);
}

Q5B_INLINE q5b_u8 q5b_bool(Q5bRef *node, q5b_u32 hash)
{
    q5b_u32 h = hash;
    Q5bRef tmp;
    Q5bRef v = *ts4_handle_forward_88150770(&tmp, node, &h);
    return ts4_gp0_xdata_get_bool_88163C60(&v);
}

Q5B_INLINE void q5b_sub_init(Q5bRef *out, Q5bRef *node, q5b_u32 hash)
{
    q5b_u32 h = hash;
    ts4_handle_forward_88610A48(out, node, &h);
}

Q5B_INLINE void q5b_sub_next(Q5bRef *out, Q5bRef *node, q5b_u32 hash)
{
    q5b_u32 h = hash;
    Q5bRef tmp;
    *out = *ts4_handle_forward_88610A48(&tmp, node, &h);
}

/* Position view: x/y/z float sub-views. */
Q5B_INLINE void q5b_float3(Q5bF3 *out, Q5bRef *node)
{
    out->x = q5b_float(node, 0xb7b2364bu);
    out->y = q5b_float(node, 0xc0b506ddu);
    out->z = q5b_float(node, 0x59bc5767u);
}

Q5B_INLINE __vector4 q5b_load3(const void *p)
{
    __vector4 lo = __lvlx(p, 0);
    __vector4 hi = __lvrx(p, 12);
    hi = __vsldoi(hi, hi, 4);
    return __vor(lo, hi);
}

Q5B_INLINE __vector4 q5b_vec3(Q5bRef *node)
{
    Q5bF3 f;
    q5b_float3(&f, node);
    return q5b_load3(&f);
}

/* byte-gap: not attempted (size); 8300-byte child-node loader, 216 calls passing copied 12-byte xdata references */
/* Swing_DLL.xex 0x888BB670 */
void ts4_load_child_params_888BB670(Q5bChildOwner *self)
{
    Q5bRef cur, tmp, a, b;
    int count;

    if (q5b_ref_invalid(&self->ref))
        return;
    a = self->ref;
    count = ts4_handle_fwd_slot1c_8860ABB0(&a);
    b = self->ref;
    ts4_handle_forward0_88610AC8(&cur, &b);
    if (count <= 0)
        return;
    do {
        q5b_u32 type = q5b_type_of(&cur);
        if (type == 0xbde89290u) {
            fn_888B9460(self);
        } else if (q5b_type_of(&cur) == 0x88bc7a91u) {
            q5b_u32 h = 0x72926b09u, id, key;
            Q5bRef v, t;
            ts4_handle_forward_88150770(&v, &cur, &h);
            fn_88169350(&id, &v);
            h = Q5B_VIEW_ID;
            v = *ts4_handle_forward_88150770(&t, &cur, &h);
            fn_88169350(&key, &v);
            ts4_bind_child_by_id_888BB5A8(self, id, key);
        } else if (q5b_type_of(&cur) == 0x7a2e57f2u) {
            q5b_u32 key = q5b_id_of(&cur);
            float lo = q5b_float(&cur, 0x9c643acfu);
            float hi = q5b_float(&cur, 0x3fd0f8a8u);
            Q5bF3 pa, pb;
            Q5bRef sub;
            q5b_sub_init(&sub, &cur, 0x19280e4eu);
            q5b_float3(&pa, &sub);
            q5b_sub_next(&sub, &cur, 0xffd3d99eu);
            q5b_float3(&pb, &sub);
            ts4_emit_child_set_vvff_888AE880(self, key, &pa, &pb, &lo, &hi);
        } else if (q5b_type_of(&cur) == 0x9d13f134u) {
            q5b_u32 key = q5b_id_of(&cur);
            Q5bF3 pa, pb;
            Q5bRef sub;
            q5b_sub_init(&sub, &cur, 0x19280e4eu);
            q5b_float3(&pa, &sub);
            q5b_sub_next(&sub, &cur, 0xffd3d99eu);
            q5b_float3(&pb, &sub);
            ts4_emit_child_set_vv_888AE7F8(self, key, &pa, &pb);
        } else if (q5b_type_of(&cur) == 0xf9a165c1u) {
            q5b_u32 key = q5b_id_of(&cur);
            float lo = q5b_float(&cur, 0x9c643acfu);
            float hi = q5b_float(&cur, 0x3fd0f8a8u);
            ts4_child_set_pair_58_888AE788(self, key, &lo, &hi);
        } else if (q5b_type_of(&cur) == 0xd0e3a48eu) {
            q5b_u32 key = q5b_id_of(&cur);
            float v[8];
            v[0] = q5b_float(&cur, 0x2fc76a96u);
            v[1] = q5b_float(&cur, 0xc2c1521eu);
            v[2] = q5b_float(&cur, 0x7d06f71fu);
            v[3] = q5b_float(&cur, 0x02642da2u);
            v[4] = q5b_float(&cur, 0x118f9763u);
            v[5] = q5b_float(&cur, 0xaf343fe3u);
            v[6] = q5b_float(&cur, 0xb8f028d0u);
            v[7] = q5b_float(&cur, 0xb0272e9cu);
            ts4_if_get_u32_off10_888AE728(self, key, v);
        } else if (q5b_type_of(&cur) == 0x5fd8fca6u) {
            q5b_u32 key = q5b_id_of(&cur);
            ts4_child_set_float_60_888AE6C8(self, key, q5b_float(&cur, 0x4dcab40cu));
        } else if (q5b_type_of(&cur) == 0xf6ca7e72u) {
            q5b_u32 key = q5b_id_of(&cur);
            Q5bLimbCfg cfg;
            Q5bRef s1, s2;
            q5b_sub_init(&s1, &cur, 0xffd00afau);
            cfg.on0 = q5b_bool(&s1, 0xacfc8aabu);
            cfg.a0 = q5b_float(&s1, 0x99365b30u);
            cfg.b0 = q5b_float(&s1, 0xa53b6469u);
            q5b_sub_next(&s1, &cur, 0x88d73a6cu);
            cfg.on1 = q5b_bool(&s1, 0xacfc8aabu);
            cfg.a1 = q5b_float(&s1, 0x99365b30u);
            cfg.b1 = q5b_float(&s1, 0xa53b6469u);
            q5b_sub_next(&s1, &cur, 0x19280e4eu);
            cfg.on2 = q5b_bool(&s1, 0xacfc8aabu);
            q5b_sub_init(&s2, &s1, 0x99365b30u);
            cfg.p2 = q5b_vec3(&s2);
            q5b_sub_next(&s2, &s1, 0xa53b6469u);
            cfg.q2 = q5b_vec3(&s2);
            q5b_sub_next(&s1, &cur, 0xffd3d99eu);
            cfg.on3 = q5b_bool(&s1, 0xacfc8aabu);
            q5b_sub_next(&s2, &s1, 0x99365b30u);
            cfg.p3 = q5b_vec3(&s2);
            q5b_sub_next(&s2, &s1, 0xa53b6469u);
            cfg.q3 = q5b_vec3(&s2);
            ts4_if_get_u32_off10_888AE668(self, key, &cfg);
        } else if (q5b_type_of(&cur) == 0xcddafe09u) {
            q5b_u32 key = q5b_id_of(&cur);
            q5b_u8 mode = q5b_bool(&cur, 0xacfc8aabu);
            float x = q5b_float(&cur, 0xd67eb32fu);
            float y = q5b_float(&cur, 0x49bb6296u);
            float z = q5b_float(&cur, 0x6b433a31u);
            ts4_child_set_mode_xyz_888AE590(self, key, mode, x, y, z);
        } else if (q5b_type_of(&cur) == 0x88f82837u) {
            q5b_u32 key = q5b_id_of(&cur);
            ts4_child_set_float_74_888AE530(self, key, q5b_float(&cur, 0xd67eb32fu));
        } else if (q5b_type_of(&cur) == 0x910461e5u) {
            q5b_u32 key = q5b_id_of(&cur);
            ts4_child_set_float_78_888AE4D0(self, key, q5b_float(&cur, 0x49bb6296u));
        } else if (q5b_type_of(&cur) == 0x761cc07eu) {
            q5b_u32 key = q5b_id_of(&cur);
            ts4_child_set_float_7c_888AE470(self, key, q5b_float(&cur, 0x6b433a31u));
        } else if (q5b_type_of(&cur) == 0x6669bfecu) {
            q5b_u32 key = q5b_id_of(&cur);
            Q5bF3Pair p;
            p.a.x = q5b_float(&cur, 0x8b416aa7u);
            p.b.x = q5b_float(&cur, 0xb74c55feu);
            p.a.y = q5b_float(&cur, 0x6cb3f1e9u);
            p.a.z = q5b_float(&cur, 0x14ebeeb6u);
            p.b.y = q5b_float(&cur, 0x50beceb0u);
            p.b.z = q5b_float(&cur, 0x28e6d1efu);
            ts4_if_get_u32_off10_888AE410(self, key, &p);
        } else if (q5b_type_of(&cur) == 0xc3eaa33bu) {
            q5b_u32 h = 0xacfc8aabu;
            Q5bRef v, c;
            q5b_u8 on;
            ts4_handle_forward_88150770(&v, &cur, &h);
            c = v;
            on = ts4_gp0_xdata_get_bool_88163C60(&c);
            if (self->child)
                *(q5b_u8 *)(self->child + 0xa8) = on;
        } else if (q5b_type_of(&cur) == 0x470fc1c4u) {
            q5b_u32 key = q5b_id_of(&cur);
            float v[6];
            v[0] = q5b_float(&cur, 0x998ecfe1u);
            v[1] = q5b_float(&cur, 0x4b79bbc1u);
            v[2] = q5b_float(&cur, 0x3dc714ebu);
            v[3] = q5b_float(&cur, 0x2b22db53u);
            v[4] = q5b_float(&cur, 0x6222a062u);
            v[5] = q5b_float(&cur, 0x97496167u);
            ts4_if_get_u32_off10_888AE3B0(self, key, v);
        } else if (q5b_type_of(&cur) == 0x24137f53u) {
            q5b_u32 key = q5b_id_of(&cur);
            ts4_emit_owner_set_f_888AF6E8(self, key, q5b_float(&cur, 0x55b78841u));
        } else if (q5b_type_of(&cur) == 0x3ee4175cu) {
            q5b_u32 key = q5b_id_of(&cur);
            ts4_child_set_u8_888AE358(self, key, q5b_bool(&cur, 0x413df12cu));
        } else {
            goto next;
        }
        fn_88707908(cur);
    next:
        cur = *ts4_handle_forward0_88610948(&tmp, &cur);
    } while (--count);
}
