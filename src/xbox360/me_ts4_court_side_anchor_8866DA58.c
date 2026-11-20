/* 0x8866DA58: picks a court anchor vector from three flags: same (scoring cur == player index), ad (court hash 0xD826E563, the ad court) and match (the indexed 8-byte score entry id equals self->id). In free play it indexes the self table (+0x2C, +0x40 for court kind 0x1110721A, +0x20 when !same, +0x10 when !match) and mirrors z on the ad court; otherwise it returns one of eight court vectors at +0x920..+0x990. Plain /Oc. */
#include "vx1_vector.h"
typedef unsigned int u32; typedef unsigned char u8;
typedef struct Vec { __vector4 v; } Vec;
typedef struct Entry { u32 id; u32 f4; } Entry;
typedef struct Blk { int rel; int f4; int f8; int cur; u32 court; } Blk;
typedef struct B44 { char p[0x48]; Blk blk; } B44;
typedef struct P48 { char p[0x44]; B44 *b44; } P48;
typedef struct P4c { char p[0x28]; int idx; } P4c;
typedef struct Court { char p[0x5c0]; u32 kind; char q[0x920 - 0x5c4]; __vector4 v[8]; } Court;
typedef struct Self { char p[0x10]; u8 b10; char q[7]; u32 id; char r[0x2c - 0x1c]; char *vecs; char s[0x40 - 0x30]; u8 *p40; char t[4]; P48 *p48; P4c *p4c; char u[0x74 - 0x50]; Court *court; } Self;
Vec ts4_court_side_anchor_8866DA58(Self *s)
{
    Blk *b = &s->p48->b44->blk;
    int idx = s->p4c->idx;
    u8 same = (b->cur == idx);
    u8 ad = (0xD826E563u == b->court);
    u8 match = (s->id == ((Entry *)((char *)b + (idx * 8 + b->rel)))->id);
    Vec r; __vector4 v;
    if (!s->b10 && !*s->p40) {
        char *p;
        Vx1Vec o; float z;
        if (s->court->kind == 0x1110721Au) p = s->vecs + 0x40; else p = s->vecs;
        if (!same) p += 0x20;
        if (!match) p += 0x10;
        o.v = *(__vector4 *)p;
        { float t = o.v.v[2]; if (ad) t = -t; z = t; }
        v = __vrlimi(o.v, __lvlx(&z, 0), 2, 2);
    } else if (match) {
        if (same) { if (ad) v = s->court->v[1]; else v = s->court->v[0]; }
        else { if (ad) v = s->court->v[3]; else v = s->court->v[2]; }
    } else {
        if (same) { if (ad) v = s->court->v[5]; else v = s->court->v[4]; }
        else { if (ad) v = s->court->v[7]; else v = s->court->v[6]; }
    }
    r.v = v;
    return r;
}
