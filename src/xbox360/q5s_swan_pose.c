/*
 * Q5S swan: pose slot refresh from bound source poses (LTCG route, /Oc).
 * Check: python3 tools/fn_check_ltcg.py src/xbox360/q5s_swan_pose.c <name>=<addr> --flags /Oc
 *        --context src/xbox360/pp1_pool_primer.c
 *
 * Codegen notes (0x886C6590):
 * - The two 20-byte blocks (+0x44, +0x58) are struct assignments: MSVC copies them with a 5-count
 *   lwzu/stwu ctr loop. An int[5] element loop is fully unrolled instead.
 * - The target walks the slots with two induction pointers, the slot and slot+0x10, and addresses the copy
 *   with negative offsets from the second. That pointer is &d->t08 + 8: an inline helper taking the +0x08
 *   sub-record (whose first word is not copied) makes MSVC strength-reduce that address into the loop.
 *   With no sub-record helper there is one pointer; a helper on a sub-record at X gives base X+8.
 * - `end` is read into a local before `begin` (the target loads +0x14 first and keeps it in r5).
 * - The float argument is part of the caller's call (w4b_g.c passes self->rate->value) and is unused here.
 */

typedef struct Q5sPoseV3 { float x, y, z; } Q5sPoseV3;
typedef struct Q5sPoseI3 { int a, b, c; } Q5sPoseI3;
typedef struct Q5sPoseW5 { int w[5]; } Q5sPoseW5;
typedef struct Q5sPoseXf {
    int id;               /* +0x00 (pose +0x08): not copied */
    float x0c;            /* +0x04 */
    Q5sPoseV3 v10;        /* +0x08 */
} Q5sPoseXf;
typedef struct Q5sPose {
    int w00;
    int w04;
    Q5sPoseXf t08;        /* +0x08 */
    int w1c, w20;
    Q5sPoseV3 v24;        /* +0x24 */
    int w30, w34;
    Q5sPoseI3 i38;        /* +0x38 */
    Q5sPoseW5 a44;        /* +0x44 */
    Q5sPoseW5 a58;        /* +0x58 */
    int w6c;
} Q5sPose;                /* 0x70 */
typedef struct Q5sPoseSlot {
    Q5sPose pose;
    unsigned char pad70[0x84 - 0x70];
    Q5sPose *src;         /* +0x84: bound source pose, may be null */
    unsigned char pad88[0x98 - 0x88];
} Q5sPoseSlot;            /* 0x98 */
typedef struct Q5sPoseSet {
    unsigned char pad00[0xc];
    Q5sPoseSlot *begin;   /* +0x0c */
    Q5sPoseSlot *cap;     /* +0x10 */
    Q5sPoseSlot *end;     /* +0x14 */
} Q5sPoseSet;

static __inline void q5s_pose_xf_copy(Q5sPoseXf *d, const Q5sPoseXf *s)
{
    d->x0c = s->x0c;
    d->v10.x = s->v10.x; d->v10.y = s->v10.y; d->v10.z = s->v10.z;
}

static __inline void q5s_pose_copy(Q5sPose *d, const Q5sPose *s)
{
    d->w04 = s->w04;
    q5s_pose_xf_copy(&d->t08, &s->t08);
    d->v24.x = s->v24.x; d->v24.y = s->v24.y; d->v24.z = s->v24.z;
    d->i38 = s->i38;
    d->a44 = s->a44;
    d->a58 = s->a58;
    d->w6c = s->w6c;
}

/* Swing_DLL.xex 0x886C6590: copy each bound source pose into its slot */
void ts4_pose_slots_sync_886C6590(Q5sPoseSet *self, float dt)
{
    Q5sPoseSlot *end = self->end;
    Q5sPoseSlot *p = self->begin;
    (void)dt;
    for (; p != end; p++) {
        if (p->src) q5s_pose_copy(&p->pose, p->src);
    }
}
