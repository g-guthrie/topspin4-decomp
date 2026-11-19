/* agentA2 2026-11-18: still 3: volatile last/first read in vclear blows up to 68. */
/* me_8866FDD0 near-miss: 3 off (plain /Oc and C++). 16 variants total (Lists start/extent, item-only split, vclear temp order, Lists local). Reset the four 0x44-byte slots that are not busy: zero three counters
   and clear their four vectors (two memmove-erased pointer vectors, two 8-byte-element copy-erased), then zero the
   count. The Lists sub-struct (+0x14) is what gives the target's `subi r30,r31,0x28` base. Residue: in the
   Lists.items clear the target loads `last` before `first` (we load first first). 8 variants. */
typedef unsigned int u32;
typedef unsigned __int64 u64;
extern void *fn_88562DC0(void *dst, void *src, u32 n);
typedef struct Vec { char *first; char *last; } Vec;
typedef struct Vec8 { u64 *first; u64 *last; } Vec8;
static __inline char *vcopy(char *first, char *last, char *dest)
{ if (first == last) { return dest; } else { u32 n = (u32)(last - first); dest = (char *)fn_88562DC0(dest, first, n); return dest + n; } }
static __inline void vclear(Vec *v) { v->last = vcopy(v->last, v->last, v->first); }
static __inline u64 *vcopy8(u64 *first, u64 *last, u64 *dest)
{ int n; for (n = last - first; n > 0; n--) *dest++ = *first++; return dest; }
static __inline void vclear8(Vec8 *v) { v->last = vcopy8(v->last, v->last, v->first); }
typedef struct Lists { Vec items; char p08[4]; Vec8 spans; char p14[4]; Vec8 marks; char p20[4]; } Lists;
static __inline void lists_clear(Lists *l) { vclear(&l->items); vclear8(&l->spans); vclear8(&l->marks); }
typedef struct Slot {
    char p0[4]; unsigned char *busy; int a; int b; int c; Lists lists; Vec v38; char p40[4];
} Slot;
typedef struct Slots { char p0[4]; int count; Slot slot[4]; } Slots;

void fn_8866FDD0(Slots *s)
{
    int i;
    for (i = 0; i < 4; i++) {
        Slot *sl = &s->slot[i];
        if (sl->busy && *sl->busy) continue;
        sl->a = 0;
        sl->b = 0;
        sl->c = 0;
        vclear(&sl->v38);
        lists_clear(&sl->lists);
    }
    s->count = 0;
}
