/* W7D: per-player counters in self-relative record arrays (LTCG route, /Oc).
 * Idiom: the record address comes from an inline helper taking the relative
 * header and the index, and the counter is bumped with `helper(...)->field++`.
 * That produces the target's dead `addi` of the field address. */
struct W7dRel { int rel; };
struct W7dRec64 { char pad[0x38]; int c38; };
struct W7dRec134 { char pad[0x68]; int c68; };
struct W7dRec64b { char pad[0x1c]; int c1c; };
struct W7dRec134b { char pad[0x28]; int c28; };
static __inline struct W7dRec64 *w7d_r64(struct W7dRel *h, int i) { return (struct W7dRec64 *)((char *)h + (i * 64 + h->rel)); }
static __inline struct W7dRec134 *w7d_r134(struct W7dRel *h, int i) { return (struct W7dRec134 *)((char *)h + (i * 0x134 + h->rel)); }
static __inline struct W7dRec64b *w7d_r64b(struct W7dRel *h, int i) { return (struct W7dRec64b *)((char *)h + (i * 64 + h->rel)); }
static __inline struct W7dRec134b *w7d_r134b(struct W7dRel *h, int i) { return (struct W7dRec134b *)((char *)h + (i * 0x134 + h->rel)); }

struct W7dSt { char pad[0x98]; unsigned char b98; };
struct W7dOwn1 { char pad[0x29]; unsigned char b29; char pad2[0x4c - 0x2a]; struct W7dRel h4c; char pad3[0x5c - 0x50]; struct W7dRel h5c; };
struct W7dS1 { char pad[0x20]; struct W7dSt *st; char pad2[0x28 - 0x24]; struct W7dOwn1 *own; };
/* Swing_DLL.xex 0x886685E0 */
void ts4_count_886685E0(struct W7dS1 *s, int idx)
{
    if (!s->st->b98) return;
    w7d_r64b(&s->own->h4c, idx)->c1c++;
    w7d_r134b(&s->own->h5c, idx)->c28++;
    s->own->b29 = 1;
}

struct W7dA { char pad[0xd4]; unsigned char bd4; char pad1[2]; unsigned char bd7; int fd8; };
struct W7dB { char pad[0xa8]; int fa8; char pad1[0xe4 - 0xac]; unsigned char be4; };
struct W7dB34 { char pad[0x30]; struct W7dB *b; };
struct W7dOwn2 { char pad[0x32]; unsigned char b32; char pad2[0x4c - 0x33]; struct W7dRel h4c; char pad3[0x5c - 0x50]; struct W7dRel h5c; };
struct W7dS2 { char pad[0x20]; struct W7dA *a; char pad1[0x28 - 0x24]; struct W7dOwn2 *own; char pad2[0x34 - 0x2c]; struct W7dB34 *c; };
/* Swing_DLL.xex 0x88668078 */
void ts4_count_88668078(struct W7dS2 *s)
{
    int idx;
    if (!s->a->bd4) return;
    if (s->a->bd7) return;
    if (s->c->b->be4) return;
    idx = s->a->fd8;
    if (idx == s->c->b->fa8) return;
    w7d_r64(&s->own->h4c, idx)->c38++;
    w7d_r134(&s->own->h5c, idx)->c68++;
    s->own->b32 = 1;
}
