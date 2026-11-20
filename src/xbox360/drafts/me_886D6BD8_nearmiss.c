/* agentB 2026-11-18 pass 2: still 5 off (plain and LTCG). Volatile pose offset read flips the pose add order to match but swaps
 * r10/r11 across the function (15 off; 14 with non-volatile tail); pad counts 0-11, hdr/clip declaration orders, block pads 0-11 no help. */
/* 0x886D6BD8 near miss (5 off since sweep 2026-11-18: tail-call offset read as *(volatile int *)&hdr->self_off fixes the
 * tail add order; pose add order still (idx+base)+off vs (idx+off)+base after rel_at/idx-first/unsigned/volatile forms and
 * z-local placements. Was 6 off, LTCG + pp1_pool_primer). Two dead int pads fixed most r10/r11 swaps (14 -> 6);
 * residue: add operand order in the pose address and the tail-call self-relative pointer, and the r7/r9 pair for
 * the zero load. Pad counts 1,3-8 give 14; rewriting either add order changes nothing.
 * Samples a track: bone -1 -> 1.0; type 0xA0B2A282 copies pose [frame + bone] from the clip self-relative array and
 * returns 0; type 0x2DB2D90F tail-calls fn_886D5140(anim+0x460, self-relative track data, out). */

#include "vx1_vector.h"
extern const float g_ts4_event_value;
extern const float g_ts4_script_constants[];

typedef struct Ts4Anim { char p[0x18]; struct Ts4Clip *clip; char p2[0x28c - 0x1c]; int frame; char p3[0x460 - 0x290]; char sampler[1]; } Ts4Anim;
typedef struct Ts4TrackHdr { int self_off; unsigned type_hash; } Ts4TrackHdr;
typedef struct Ts4TrackDesc { char p[0xc]; short bone; } Ts4TrackDesc;
typedef struct Ts4Track { Ts4TrackHdr *hdr; Ts4TrackDesc *desc; } Ts4Track;
float fn_886D5140(void *sampler, void *track, __vector4 *out);
typedef struct Ts4RelArray { int self_off; } Ts4RelArray;
typedef struct Ts4ClipData { char p[0x90]; Ts4RelArray poses; } Ts4ClipData;
typedef struct Ts4Clip { char p[0xc]; Ts4ClipData *data; } Ts4Clip;
static __inline __vector4 *rel_vecs(Ts4RelArray *b) { return (__vector4 *)((char *)b + b->self_off); }

float ts4_track_sample(Ts4Track *t, Ts4Anim *a, __vector4 *out)
{
    int pad0 = 0;
    int pad1 = 0;
    int bone = t->desc->bone;
    float r = g_ts4_script_constants[0];
    if (bone != -1) {
        Ts4RelArray *base = &a->clip->data->poses;
        unsigned type = t->hdr->type_hash;
        if (type == 0xA0B2A282u) {
            *out = rel_vecs(base)[a->frame + bone];
            return g_ts4_event_value;
        }
        if (type == 0x2DB2D90Fu)
            return fn_886D5140(a->sampler, (char *)t->hdr + *(volatile int *)&t->hdr->self_off, out);
    }
    (void)pad0;
    (void)pad1;
    return r;
}
