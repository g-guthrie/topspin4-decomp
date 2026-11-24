/* W2A batch E */
struct W2aEl { char pad0[0xc]; unsigned v0c; unsigned v10; unsigned v14; char pad1[0xc]; unsigned v24; char pad2[4]; unsigned v2c; };
struct W2aHdr { int rel; char pad[0xe]; unsigned char b12; unsigned char b13; };
struct W2aOwn2 { char pad[8]; struct { char pad[0x24]; struct W2aHdr hdr; } *base; };

/* Swing_DLL.xex 0x8865C2D8 */
void ts4_clear_flags_copy_8865C2D8(struct W2aOwn2 *s)
{
    struct W2aHdr *h = &s->base->hdr;
    struct W2aEl *e = (struct W2aEl *)((char *)h + s->base->hdr.rel);
    h->b12 = 0;
    h->b13 = 0;
    e->v14 = e->v0c;
    e->v2c = e->v24;
}

struct W2aDirty { char pad[0x5a0]; };
extern void fn_889C2818(void *self, unsigned item);
struct W2aItems { char pad[0x28]; unsigned *begin; unsigned *end; };
/* Swing_DLL.xex 0x889C28B0 */
void ts4_each_item_889C28B0(struct W2aItems *s)
{
    unsigned *end = s->end;
    unsigned *p;
    for (p = s->begin; p != end; p++)
        fn_889C2818(s, *p);
}

struct W2aVec6 { char pad[0x30]; char *p30; char pad2[0x1c]; unsigned *begin; unsigned *end; };
/* Swing_DLL.xex 0x886C5160 */
void ts4_set_owner_ptrs_886C5160(struct W2aVec6 *s)
{
    unsigned n = ((char *)s->end - (char *)s->begin) >> 2;
    char *dst = *(char **)((char *)s + 0x34) + 0x110;
    unsigned i;
    for (i = 0; i < n; i++) {
        char *item = *(char **)((char *)s->begin + i * 4);
        *(char **)(item + 0xc4) = dst;
    }
}

struct W2aSub { char pad[0x24]; unsigned v24; unsigned v28; };
struct W2a5C28 { char pad[4]; void *p4; void *p8; char pad2[0x14]; unsigned v20; char pad3[0xc]; struct W2aSub *p30; struct W2aSub *p34; };
extern void ts4_clear_three_vectors_886C3658(void *a);
extern void ts4_reset_pairs_886C4278(void *a);
/* Swing_DLL.xex 0x886C5C28 */
void ts4_reset_counters_886C5C28(struct W2a5C28 *s)
{
    s->p30->v24 = 0;
    s->p30->v28 = 0;
    s->p34->v24 = 0;
    s->p34->v28 = 0;
    s->v20 = 0;
    ts4_clear_three_vectors_886C3658(s->p8);
    ts4_reset_pairs_886C4278(s->p4);
}

struct W2a7578 { char pad[0x20]; void *p20; char pad2[0xAC]; unsigned d0, d4, d8, dc; };
struct W2aRel { int off; unsigned cnt; };
#ifdef _MSC_VER
#define W2A_INT(p) ((int)(p))
#define W2A_UINT(p) ((unsigned)(p))
#else
#define W2A_INT(p) ((int)(long)(p))
#define W2A_UINT(p) ((unsigned)(unsigned long)(p))
#endif
struct W2a7578Src { char pad[0x30]; struct W2aRel a; char pad2[4]; struct W2aRel b; };
/* Swing_DLL.xex 0x886E7578 */
void ts4_bind_source_886E7578(struct W2a7578 *s, struct W2a7578Src *src)
{
    s->p20 = src;
    if (W2A_INT(src) != 0) {
        struct W2aRel *b = &src->b;
        struct W2aRel *a = &src->a;
        s->d0 = b->off + W2A_UINT(b);
        s->d4 = b->cnt;
        s->d8 = a->off + W2A_UINT(a);
        s->dc = a->cnt;
    } else {
        s->d0 = 0; s->d4 = 0; s->d8 = 0; s->dc = 0;
    }
}
