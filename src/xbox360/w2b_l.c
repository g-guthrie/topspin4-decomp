#include "w2b_types.h"

/* ---- 0x886D7578 ---- */
struct W2bEntry { char pad[0x20]; w2b_u32 f20, f24, f28; };
struct W2bEntryBase { int dummy; };
struct W2bEntryOwner { char pad[0x28]; char *tab; };

extern void ts4_layout_refresh_886D3A00(void *base, struct W2bEntry *e, int one);

/* Swing_DLL.xex 0x886D7578 */
void ts4_set_entry_886D7578(struct W2bEntryOwner *self, int idx, w2b_u32 val)
{
    struct W2bEntryBase *base = (struct W2bEntryBase *)(self->tab + 0x3f0);
    w2b_u32 flag = 0;
    struct W2bEntry *e;
    if (idx == 1)
        flag = 1;
    e = ((struct W2bEntry **)base)[idx + 12];
    e->f28 = val;
    e->f20 = flag;
    e->f24 = 1;
    ts4_layout_refresh_886D3A00(base, e, 1);
}
