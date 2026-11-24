/* rough draft 0x886D8730 (ME agent B): 113 off (/Oc). Walk/run clip velocity refresh from the top layer; the target
 * addresses the record offset as (desc+0x58)+4 (a sub-struct at 0x58), and its frame is 0x90 vs our 0xa0. */
#include "ts4_vector.h"
typedef struct Vec { __vector4 v; } Vec;
typedef struct Rec { char p[0xc]; short walk_idx; char pe[0x18 - 0xe]; short run_idx; } Rec;
typedef struct ClipDesc { char p[0x14]; float time_ratio; char p18[0x5c - 0x18]; int rec_rel; unsigned int kind; } ClipDesc;
typedef struct LayerInner { char p[8]; ClipDesc *desc; } LayerInner;
typedef struct Layer { char p[4]; LayerInner *inner; } Layer;
typedef struct Flags { char p[0x60]; int rel; } Flags;
typedef struct Tbl { char p[8]; Flags *flags; } Tbl;
typedef struct Mover { char p[0x1c]; float scale; float speed; char p24[0x50 - 0x24]; __vector4 vel; float base; } Mover;
typedef struct Ctx { char p[0x1c]; Tbl *tbl; Mover *mover; } Ctx;
typedef struct Stack { char p[0x18]; float now; char p1c[0x20 - 0x1c]; Ctx *ctx; char p24[0x5c - 0x24]; Layer **begin; Layer **end; } Stack;
extern float g_ts4_script_constants[];
extern float g_ts4_event_value;
Vec ts4_lookup_scaled_vec_88649828(Mover *a, int idx, float x, float y);
Vec ts4_lookup_xz_886455A0(Mover *a, int idx, float x, float y);
static __inline Rec *rec_of(ClipDesc *d) { int *r = &d->rec_rel; return (Rec *)((char *)r + *r); }
static __inline unsigned short flag_at(Tbl *t, int i) { int *r = &t->flags->rel; return *(unsigned short *)((char *)r + *r + i * 0x1c); }
void fn_886D8730(Stack *self)
{
    ClipDesc *d;
    if (self->begin == self->end)
        return;
    d = self->begin[0]->inner->desc;
    if (d->kind == 0xA0B2A282) {
        float t = g_ts4_script_constants[0] / (d->time_ratio - g_ts4_script_constants[0]) * self->now;
        int idx = rec_of(d)->walk_idx;
        Ctx *c = self->ctx;
        float ev = g_ts4_event_value;
        Vec r;
        Mover *m;
        float z;
        if (flag_at(c->tbl, idx))
            r = ts4_lookup_scaled_vec_88649828(c->mover, idx, ev, t);
        else
            r = ts4_lookup_xz_886455A0(c->mover, idx, ev, t);
        m = self->ctx->mover;
        z = m->scale * r.v.v[2];
        m->base = ev;
        m->vel = __vrlimi(r.v, __lvlx(&z, 0), 2, 2);
    } else if (d->kind == 0x2DB2D90F) {
        float t = g_ts4_script_constants[0] / (d->time_ratio - g_ts4_script_constants[0]) * self->now;
        int idx = rec_of(d)->run_idx;
        Ctx *c = self->ctx;
        float ev = g_ts4_event_value;
        Vec r;
        Mover *m;
        float z;
        __vector4 v;
        if (flag_at(c->tbl, idx))
            r = ts4_lookup_scaled_vec_88649828(c->mover, idx, ev, t);
        else
            r = ts4_lookup_xz_886455A0(c->mover, idx, ev, t);
        m = self->ctx->mover;
        v = __vmulfp(r.v, __vspltw(__lvlx(&m->speed, 0), 0));
        z = m->scale * r.v.v[2];
        m->base = ev;
        m->vel = __vrlimi(v, __lvlx(&z, 0), 2, 2);
    }
}
