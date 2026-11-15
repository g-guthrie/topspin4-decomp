/* W11B batch D: plain route. */
extern void *ts4_memset(void *p, int v, unsigned n);

typedef struct W11bRgb { unsigned char r, g, b; } W11bRgb;
typedef struct W11bRgba { W11bRgb rgb; unsigned char a; } W11bRgba;
typedef struct W11bColorBlk { W11bRgba col; unsigned w; } W11bColorBlk;
typedef struct W11bBlkOwner { unsigned char pad[0x3a8]; W11bColorBlk blk; unsigned char pad2[0x610 - 0x3b0]; unsigned w610; } W11bBlkOwner;
typedef struct W11bBlkMid { unsigned char pad[0x74]; W11bBlkOwner *d; } W11bBlkMid;
typedef struct W11bBlkHold { unsigned char pad[8]; W11bBlkMid *m; } W11bBlkHold;
typedef struct W11bBlkSelf { unsigned char pad[0x1c]; W11bBlkHold *h; } W11bBlkSelf;

/* Swing_DLL.xex 0x88681AE0: reset the colour block (alpha byte left as the stack holds it), then copy the +0x610 word. */
void ts4_reset_color_block_88681AE0(W11bBlkSelf *s)
{
    W11bRgba c;
    W11bColorBlk *b;
    c.rgb.r = 0;
    c.rgb.g = 0;
    c.rgb.b = 0;
    b = &s->h->m->d->blk;
    b->col.rgb = c.rgb;
    b->col.a = c.a;
    { unsigned *pw = &b->w; *pw = 0; }
    ts4_memset(b, 0, 8);
    b->w = s->h->m->d->w610;
}
