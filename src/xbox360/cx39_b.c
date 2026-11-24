/* CX39 (LTCG): callers of the index-to-hash lookup, Swing_DLL.xex 0x8896xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX39_INL static __forceinline
#else
#define CX39_INL static inline
#endif
#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif

/* ---- work/cx39/keep_pick.c ---- */
extern u32 *ts4_index_to_name_hash_887F7BC8(u32 *out, u8 index);
extern void fn_889657D0(void *self);
typedef struct Cx39PEnt { u8 b0; u8 b1; u16 h2; } Cx39PEnt;
typedef struct Cx39PTab { int off; int cnt; } Cx39PTab;
typedef struct Cx39PRel { int off; } Cx39PRel;
typedef struct Cx39PL2 { u8 pad[0x20]; char *w20; } Cx39PL2;
typedef struct Cx39PL1 { u8 pad[0x1c]; Cx39PL2 *w1c; } Cx39PL1;
typedef struct Cx39PSel { u8 pad[0x20]; Cx39PL1 *w20; u8 p2[0x28 - 0x24]; Cx39PTab *w28; u8 p3[0x54 - 0x2c]; void *w54; } Cx39PSel;
void ts4_pick_by_hash_88965930(Cx39PSel *self)
{
    Cx39PTab *t;
    int n;
    int i;
    fn_889657D0(self);
    t = self->w28;
    n = t->cnt;
    if (n > 0) {
        int k = 0;
        for (i = n; i != 0; i--) {
            u32 h;
            Cx39PEnt *e = (Cx39PEnt *)((char *)t + (t->off + k));
            { u32 *hp = ts4_index_to_name_hash_887F7BC8(&h, e->b0);
            if (*hp == 0x6D44B7DB) {
                Cx39PRel *r = (Cx39PRel *)(self->w20->w1c->w20 + 0xc);
                self->w54 = (char *)r + (e->h2 * 4 + r->off);
            } }
            k += 4;
        }
    }
}
