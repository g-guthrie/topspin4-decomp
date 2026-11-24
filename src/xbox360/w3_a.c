#include "w3_types.h"
struct W3Rec { int rel; int v4; };
struct W3Sub { char pad[0x28]; int idx; };
struct W3Own { char pad[0x4c]; struct W3Sub *sub; };
struct W3Blk { char pad[0xb4]; struct W3Rec hdr; };
struct W3Ctx { char pad[0x14]; struct W3Blk *blk; char pad2[0x24 - 0x18]; struct W3Own *own; };

/* Swing_DLL.xex 0x88664FC8 */
int ts4_rec_field_zero_88664FC8(struct W3Ctx *self)
{
    struct W3Own *o = self->own;
    struct W3Blk *b = self->blk;
    struct W3Rec *h = &b->hdr;
    struct W3Sub *s = o->sub;
    int idx = s->idx;
    int rel = h->rel;
    char *e = (char *)h + (idx * 24 + rel);
    struct W3Rec *r = (struct W3Rec *)(e + *(int *)e);
    return r->v4 == 0;
}

struct W3Hash { char pad[0xc]; w3_u32 key; };
struct W3KA { char pad[0x28]; struct W3Hash *h; };
struct W3Flag { char pad[0xac]; w3_u32 id; char pad2[0x32a - 0xb0]; w3_u8 on; };
struct W3KB { char pad[0x30]; struct W3Flag *f; };
struct W3KC { char pad[0x20]; struct W3KB *b; };
struct W3KD { char pad[0x4c]; struct W3KC *c; };
struct W3Self8 { char pad[8]; struct W3Rec hdr; };
struct W3Ctx2 { char pad[4]; struct W3KA *a; struct W3Self8 *blk; };

struct W3Obj { char pad[0x18]; int r18; int r1c; };
/* Swing_DLL.xex 0x8866D070 */
void *ts4_select_sub_8866D070(struct W3Ctx2 *self)
{
    struct W3KA *a = self->a;
    struct W3Rec *h = &self->blk->hdr;
    int rel = h->rel;
    struct W3Obj *base = (struct W3Obj *)((char *)h - rel);
    struct W3Hash *kh = a->h;
    w3_u32 key = kh->key;
    unsigned char on;
    struct W3KD *kd;
    struct W3KC *c;
    struct W3KB *kb;
    struct W3Flag *f;
    if (key == 0xda554856u) {
        if (base->r1c != -1) {
            int *p = &base->r1c;
            base = (struct W3Obj *)((char *)p + *p);
        }
    }
    kd = (struct W3KD *)a;
    c = kd->c;
    kb = c->b;
    f = kb->f;
    on = 0;
    if (f->on) {
        w3_u32 id = f->id;
        if (id == 0xd826e563u)
            on = 1;
    }
    if (on) {
        int r18 = base->r18;
        if (r18 != -1) {
            int *q = &base->r18;
            base = (struct W3Obj *)((char *)q + *q);
        }
    }
    return base;
}
