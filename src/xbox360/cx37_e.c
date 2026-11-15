/* CX37: nested offset-array finds and string-keyed finds, Swing_DLL.xex 0x8894xxxx-0x8895xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif

typedef struct Cx37Hdr { int off; int cnt; } Cx37Hdr;
typedef struct Cx37Leaf { u8 pad[0x18]; int k; u32 w1c; } Cx37Leaf;
typedef struct Cx37Node { Cx37Hdr sub; u32 w8; int k; u32 w10; } Cx37Node;
extern void *ts4_offset_array_end20_8815E520(void *h);
extern void *ts4_offset_array_end32_8815E4F8(void *h);

#if 0 /* near miss, not byte-identical */
/* 0x88941A18: leaf (key b) inside the node (key a) of a two-level offset table */
void *ts4_find_leaf_88941A18(int a, int b, Cx37Hdr *h)
{
    Cx37Leaf *r = 0;
    Cx37Node *p = 0;
    Cx37Node *end;
    if (h->off != -1)
        p = (Cx37Node *)((char *)h + h->off);
    end = (Cx37Node *)ts4_offset_array_end20_8815E520(h);
    for (; p != end; p++) {
        if (a == p->k) {
            Cx37Leaf *q = 0;
            Cx37Leaf *qe;
            if (p->sub.off != -1)
                q = (Cx37Leaf *)((char *)p + p->sub.off);
            qe = (Cx37Leaf *)ts4_offset_array_end32_8815E4F8(p);
            for (; q != qe; q++) {
                if (b == q->k) {
                    r = q;
                    break;
                }
            }
            if (r != 0)
                break;
        }
    }
    return r;
}
#endif
#if 0 /* near miss, not byte-identical */
/* 0x88942130 */
void *ts4_find_leaf_88942130(int a, int b, Cx37Hdr *h)
{
    Cx37Leaf *r = 0;
    Cx37Node *p = 0;
    Cx37Node *end;
    if (h->off != -1)
        p = (Cx37Node *)((char *)h + h->off);
    end = (Cx37Node *)ts4_offset_array_end20_8815E520(h);
    for (; p != end; p++) {
        if (a == p->k) {
            Cx37Leaf *q = 0;
            Cx37Leaf *qe;
            if (p->sub.off != -1)
                q = (Cx37Leaf *)((char *)p + p->sub.off);
            qe = (Cx37Leaf *)ts4_offset_array_end32_8815E4F8(p);
            for (; q != qe; q++) {
                if (b == q->k) {
                    r = q;
                    break;
                }
            }
            if (r != 0)
                break;
        }
    }
    return r;
}
#endif
#if 0 /* near miss, not byte-identical */
/* 0x889421E0: address of the word at +0xC of the leaf */
u32 *ts4_find_leaf_word_889421E0(int a, int b, Cx37Hdr *h)
{
    u32 *r = 0;
    Cx37Node *p = 0;
    Cx37Node *end;
    if (h->off != -1)
        p = (Cx37Node *)((char *)h + h->off);
    end = (Cx37Node *)ts4_offset_array_end20_8815E520(h);
    for (; p != end; p++) {
        if (a == p->k) {
            Cx37Leaf *q = 0;
            Cx37Leaf *qe;
            if (p->sub.off != -1)
                q = (Cx37Leaf *)((char *)p + p->sub.off);
            qe = (Cx37Leaf *)ts4_offset_array_end32_8815E4F8(p);
            for (; q != qe; q++) {
                if (b == q->k) {
                    r = (u32 *)((char *)q + 0xc);
                    break;
                }
            }
            if (r != 0)
                break;
        }
    }
    return r;
}
#endif

/* 0x88941038: first object whose names at +0x38 and +0x44 equal the two strings */
typedef struct Cx37Named { u8 pad[0x38]; const char *n38; u8 pad2[8]; const char *n44; } Cx37Named;
typedef struct Cx37NamedList { u8 pad[0x60]; Cx37Named **first; Cx37Named **last; } Cx37NamedList;
Cx37Named *ts4_find_named_88941038(Cx37NamedList *o, const char *a, const char *b)
{
    Cx37Named **p;
    Cx37Named **end;
    for (p = o->first, end = o->last; p != end; p++) {
        Cx37Named *e = *p;
        if (e && strcmp(a, e->n38) == 0 && strcmp(b, e->n44) == 0)
            return e;
    }
    return 0;
}
