/* Swing_DLL.xex 0x88683BF0 (ts4_rally_tracker_reset_88683BF0), size 0x184: resets a rally tracker. Clears the header, sets last to -1,
 * finalizes and rebuilds the hit (8) and bounce (3) lists, and when the court surface hash is 0x1F85CDB1 marks
 * the tracker active, looks up both players (flag 0 near, flag 1 far) and zeroes all accumulated rally statistics.
 * Matching note (agP 2026-11-19, was a 19-off draft): the n4c store goes through a block-local pointer so the
 * float zero is loaded after the 0x40-0x4C stores. LTCG route only (pp1_pool_primer context); plain /Oc stays
 * 23 off (one-route match). */
#include "ts4_vector.h"
typedef unsigned int u32;
typedef struct RtHdr { int count; unsigned char a, b, c; char p; int x8, xc; } RtHdr;
typedef struct RtCourt { char p[0x238]; u32 surface; } RtCourt;
typedef struct RtVec { char p[0xc]; } RtVec;
typedef struct Rally {
    RtHdr *hdr; unsigned char active; char p0[3]; int last; char p1[0x18 - 0xc]; RtCourt *court; char p2[0x20 - 0x1c];
    void *far_p; void *near_p; RtVec hits; RtVec bounces;
    int n40, n44, n48, n4c, n50, n54, n58, n5c, n60, n64, n68, n6c, n70; float f74, f78; int n7c;
    char p3[0x84 - 0x80]; int n84, n88, n8c, n90, n94, n98, n9c, na0, na4, na8, nac, nb0; char p4[4]; int nb8, nbc;
    float fc0, fc4; char p5[0xd0 - 0xc8]; __vector4 vd0, ve0; int nf0, nf4, nf8, nfc, n100, n104, n108, n10c, n110, n114;
} Rally;
extern float g_ts4_event_value;
void ts4_object_finalize(void *p);
void fn_881705B0(void *vec, int n);
void *ts4_ga2_find_by_flag_88664F60(Rally *s, int flag);
void ts4_rally_tracker_reset_88683BF0(Rally *s)
{
    RtHdr *h = s->hdr;
    h->count = 0; h->a = 0; h->b = 0; h->c = 0; h->x8 = 0; h->xc = 0;
    s->last = -1;
    ts4_object_finalize(&s->hits);
    ts4_object_finalize(&s->bounces);
    fn_881705B0(&s->hits, 8);
    fn_881705B0(&s->bounces, 3);
    s->active = (0x1F85CDB1u - s->court->surface) == 0;
    if (s->active) {
        float z;
        __vector4 vz;
        s->far_p = 0;
        s->near_p = 0;
        s->near_p = ts4_ga2_find_by_flag_88664F60(s, 0);
        s->far_p = ts4_ga2_find_by_flag_88664F60(s, 1);
        z = g_ts4_event_value;
        vz = __vspltisw(0);
        s->n40 = 0; s->n44 = 0; s->n48 = 0; { int *p4 = &s->n4c; *p4 = 0; }
        s->n5c = 0; s->f74 = z; s->n58 = 0; s->f78 = z; s->n54 = 0; s->fc0 = z; s->n50 = 0; s->fc4 = z;
        s->n64 = 0; s->n60 = 0; s->vd0 = vz; s->n6c = 0; s->ve0 = vz; s->n68 = 0; s->n70 = 0;
        s->n84 = 0; s->n88 = 0; s->n8c = 0; s->n94 = 0; s->n90 = 0; s->n98 = 0; s->n9c = 0; s->n7c = 0;
        s->na4 = 0; s->na0 = 0; s->nac = 0; s->na8 = 0; s->nb0 = 0; s->nb8 = 0; s->nbc = 0;
        s->nf4 = 0; s->n10c = 0; s->nf8 = 0; s->nfc = 0; s->n100 = 0; s->n104 = 0; s->n108 = 0; s->n110 = 0; s->n114 = 0; s->nf0 = 0;
    }
}
