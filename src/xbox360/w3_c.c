#include "w3_types.h"
struct W3Rec { int rel; int v4; };
struct W3VObj;
struct W3VT { char pad[0x2c]; void (*s2c)(struct W3VObj *); void (*s30)(struct W3VObj *); };
struct W3VObj { struct W3VT *vt; };
struct W3P6c { char pad[8]; struct W3VObj *o; };
struct W3P34 { char pad[0x6c]; struct W3P6c *p6c; };
struct W3Flags { char pad[0x54]; int v54; char pad2[0xc8 - 0x58]; w3_u8 f[3]; };
struct W3Blk { char pad[0x3c]; struct W3Rec hdr; };
struct W3Elem { int cnt; char pad[8]; w3_u8 b0c; w3_u8 b0d; char pad2[2]; unsigned v10; char pad3[8]; w3_u8 b1c; w3_u8 b1d; };
struct W3Self {
    char pad[0x20]; struct W3Flags *fl;
    char pad2[4]; struct W3Blk *blk;
    char pad3[8]; struct W3P34 *p34;
};

/* Seven dead referenced locals shift the symbol number of the header pointer in the
   next block (operand order of the indexed add, see docs/agents/near-misses/OP1.md). */
#define W3_PAD7 int w3_p0 = 0, w3_p1 = 0, w3_p2 = 0, w3_p3 = 0, w3_p4 = 0, w3_p5 = 0, w3_p6 = 0;
#define W3_PAD7_USE (void)w3_p0; (void)w3_p1; (void)w3_p2; (void)w3_p3; (void)w3_p4; (void)w3_p5; (void)w3_p6;
#define W3_ELEM() \
        struct W3Blk *b = self->blk; \
        struct W3Rec *h = &b->hdr; \
        struct W3Elem *e = (struct W3Elem *)((char *)h + h->rel);

/* Swing_DLL.xex 0x88667B28 */
void ts4_update_flags_88667B28(struct W3Self *self)
{
    struct W3VObj *o = self->p34->p6c->o;
    unsigned cnt;
    o->vt->s2c(o);
    o = self->p34->p6c->o;
    o->vt->s30(o);
    self->fl->f[0] = 0;
    self->fl->f[1] = 0;
    self->fl->f[2] = 0;
    { W3_ELEM() cnt = e->cnt; }
    if (cnt > 0) {
        if (self->fl->v54 != 0)
            self->fl->f[0] = 1;
        { W3_ELEM() if (e->b0c) self->fl->f[1] = 1; }
        { W3_ELEM() if (e->b0d) self->fl->f[2] = 1; }
    }
    { W3_ELEM() cnt = e->v10; }
    if (cnt > 0) {
        if (self->fl->v54 != 1)
            self->fl->f[0] = 1;
        {
            W3_PAD7
            W3_ELEM()
            W3_PAD7_USE
            if (e->b1c) self->fl->f[1] = 1;
        }
        { W3_ELEM() if (e->b1d) self->fl->f[2] = 1; }
    }
}
