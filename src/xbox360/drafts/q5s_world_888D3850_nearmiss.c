/* nearmiss: 32 off plain, 26 off LTCG (register numbering only: the target keeps the header in r8, begin in r10, end in r9;
 * we get r9/r11/r8). Loop forms, find helper, begin/end helpers, vector build forms all give the same allocation; perm_auto
 * (LTCG) found nothing below baseline. On LTCG the {x,y,z,1} stack build matches. */
/* 0x888D3850: take the first unused 0x30-byte entry of the self-relative list at owner->pool(+0x28)+0x20, copy key,
 * position (x, y, z, 1.0f) and the +0x20 word from src, mark it used and set the list dirty byte. */
#include "include/ts4/ts4.h"
extern const float lbl_8814B440;
typedef struct Src { unsigned int key; char p4[0xc]; float x, y, z; char p1c[4]; unsigned int extra; } Src;
typedef struct Ent { unsigned int key; char p4[0xc]; Ts4Vec4 pos; unsigned int extra; unsigned char used; char p25[0xb]; } Ent;
typedef struct Hdr { int off; unsigned int count; char p8[4]; unsigned char dirty; } Hdr;
typedef struct Pool { char p0[0x20]; Hdr list; } Pool;
typedef struct Owner { char p0[0x28]; Pool *pool; } Owner;
void ts4_pool_add_entry_888D3850(Owner *o, const Src *s)
{
    Hdr *h = &o->pool->list;
    Ent *b, *e, *it;
    b = 0;
    if (h->off != -1) b = (Ent *)((char *)h + h->off);
    e = 0;
    if (h->off != -1) e = (Ent *)((char *)h + (h->count * 0x30 + h->off));
    for (it = b; it != e; it++) {
        if (!it->used) {
            Ts4Vec4 t;
            it->key = s->key;
            t.f[0] = s->x; t.f[1] = s->y; t.f[2] = s->z; t.f[3] = lbl_8814B440;
            it->pos.v = t.v;
            it->extra = s->extra;
            it->used = 1;
            h->dirty = 1;
            return;
        }
    }
}
