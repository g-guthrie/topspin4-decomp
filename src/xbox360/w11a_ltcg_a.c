/* W11A: small gameplay functions that need the LTCG route. */
#include "w6a_types.h"

/* 0x8865FA18: reset a block of float parameters: zero (g_ts4_event_value) and the pool constant 1.0f. */
struct W11aParams {
    char pad0[0xf20];
    float f20, f24, f28, f2c;
    char pad1[0xf44 - 0xf30];
    float f44, f48, f4c;
    char pad2[0xf54 - 0xf50];
    float f54, f58;
    char pad3[0xf64 - 0xf5c];
    float f64;
};
struct W11aParamOwner { char pad[0x74]; struct W11aParams *p74; };
struct W11aParamRoot { struct W11aParamOwner *owner; char pad[0x158 - 4]; float *f158; float *f15c; };
extern const float g_ts4_event_value;

void ts4_reset_float_params_8865FA18(struct W11aParamRoot *o)
{
    struct W11aParams *p = o->owner->p74;
    float zero = g_ts4_event_value;
    float *a = o->f158;
    float *b = o->f15c;
    p->f20 = zero; p->f24 = zero; p->f2c = zero; p->f44 = zero; p->f48 = zero; p->f4c = zero;
    p->f54 = 1.0f; p->f58 = 1.0f; p->f64 = 1.0f;
    *a = 1.0f; *b = 1.0f;
    p->f28 = zero;
}

/* 0x886C71C8: on the clip message (id 0x2db2d90f) bind the self-relative clip entry; then count unless locked. */
struct W11aMsg { int rel; unsigned id; };
struct W11aCounter { char pad[0x88]; int count; };
struct W11aClipHandler { struct W11aMsg *msg; struct W11aCounter *cnt; };
struct W11aClipHost { char pad[0x460]; int binder; char pad2[0x555 - 0x464]; unsigned char locked; };
extern void ts4_bind_clip_entry_886C6048(void *binder, void *clip);

void ts4_on_clip_message_886C71C8(struct W11aClipHandler *self, struct W11aClipHost *host)
{
    struct W11aMsg *m = self->msg;
    if (m->id == 0x2db2d90f)
        ts4_bind_clip_entry_886C6048(&host->binder, (char *)m + m->rel);
    if (host->locked == 0)
        self->cnt->count = self->cnt->count + 1;
}

/* 0x886455A0: look up the 0x1c-byte entry `idx` of a self-relative table, ask fn_88644CE8 for two floats and
 * return them as the vector {a, 0, b, 0}. */
struct W11aTblHdr { int rel; };
struct W11aTbl { char pad[0x60]; struct W11aTblHdr hdr; };
struct W11aTblMid { char pad[8]; struct W11aTbl *p8; };
struct W11aTblSelf { char pad[0xa8]; struct W11aTblMid *pa8; };
void fn_88644CE8(void *self, void *elem, int idx, int unk, float *a, float *b);

__vector4 *ts4_lookup_xz_886455A0(__vector4 *out, struct W11aTblSelf *self, int idx, int unk)
{
    float a, b;
    __vector4 r;
    struct W11aTblHdr *h = &self->pa8->p8->hdr;
    fn_88644CE8(self, (char *)h + (idx * 0x1c + h->rel), idx, unk, &a, &b);
    r.v[0] = a;
    r.v[1] = g_ts4_event_value;
    r.v[2] = b;
    r.v[3] = g_ts4_event_value;
    *out = r;
    return out;
}

/* 0x886C3EB8: clip a segment against a span: when (v2 - v1) is at least the threshold constant, t = (*b - *a) / (v2 - v1)
 * (one Newton step reciprocal) and move *a and *b to *a + t * (v3 - v1) and *a + t * (v4 - v1). */
extern const float g_ts4_script_constants[];

void ts4_clip_segment_886C3EB8(__vector4 *a, __vector4 *b, __vector4 v1, __vector4 v2, __vector4 v3, __vector4 v4)
{
    __vector4 d = __vsubfp(v2, v1);
    __vector4 k = __vspltw(__lvlx(&g_ts4_script_constants[0x2ac / 4], 0), 0);
    unsigned int cr;
    unsigned int ok;
    __vector4 r0, one, s, t, a0, ab, e1, e2;
    __vcmpgefpR(d, k, &cr);
    ok = (cr >> 7) & 1;
    if ((unsigned char)ok == 0) return;
    r0 = __vrefp(d);
    one = __vupkd3d(__vspltisw(0), 0);
    a0 = *a;
    e1 = __vsubfp(v3, v1);
    ab = __vsubfp(*b, a0);
    e2 = __vsubfp(v4, v1);
    s = __vnmsubfp(d, r0, one);
    t = __vmaddfp(r0, s, r0);
    t = __vmulfp(t, ab);
    *a = __vmaddfp(t, e1, a0);
    *b = __vmaddfp(t, e2, a0);
}
