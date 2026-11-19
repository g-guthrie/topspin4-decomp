/* 0x887F8E00: sets the u16-indexed float in the rel array at o->x20->x1c->x20+0x3c to 1.0 when the flag block's 'active' word is set (and clears b2c); recomputes b2c from on/off; when 'live' and b2c, adds the base script constant and fires vslot 13 of o->tgt with (x8, x30). Returns 1. */

typedef unsigned int u32; typedef unsigned char u8; typedef unsigned short u16;
typedef struct { int rel; } Rel;
typedef struct { char p[2]; u16 idx; } Blk;
typedef struct { char p[0xc]; Rel r; } Hdr;
typedef struct { char p[0x3c]; Rel r; } FHdr;
typedef struct { char p[0x20]; FHdr *f; } X1c;
typedef struct { char p[0x1c]; X1c *x; } X20;
typedef struct { int on, off, active, live; } Flags;
typedef struct Tgt Tgt;
typedef struct { char p[0x34]; void (*fire)(Tgt *t, u32 a, u32 b); } TgtVt;
struct Tgt { TgtVt *vt; };
typedef struct { char p[8]; u32 x8; char pc[8]; Flags *fl; char p18[8]; X20 *x20; Tgt *tgt; Hdr *hdr; u8 b2c; char p2d[3]; u32 x30; } O;
extern float lbl_8814B440;
extern float g_ts4_script_constants[];
int ts4_trigger_flag_update_887F8E00(O *o) {
    Rel *hr = &o->hdr->r;
    Blk *b = (Blk *)((char *)hr + hr->rel);
    Rel *fr = &o->x20->x->f->r;
    float *v = (float *)((char *)fr + fr->rel) + b->idx;
    Flags *f;
    if (o->fl->active) { *v = lbl_8814B440; o->b2c = 0; }
    f = o->fl;
    if (f->on) o->b2c = 1;
    if (f->off) o->b2c = 0;
    if (f->live && o->b2c) {
        *v += g_ts4_script_constants[0];
        o->tgt->vt->fire(o->tgt, o->x8, o->x30);
    }
    return 1;
}
