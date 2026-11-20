/* Swing_DLL.xex 0x88323BA0: same as 88378F68 for a set with count +0x48 and slots +0x4C; afterwards clears bit 0x400
 * of the set state (+0x54). agAE: /Oc. */
typedef struct Res Res;
typedef struct ResVt { void *slots[8]; int (*prepare)(Res *r); } ResVt;
struct Res { ResVt *vt; char pad4[0x24 - 4]; unsigned int flags; };
typedef struct Set { char pad[0x48]; int count; Res *items[2]; unsigned int state; } Set;
int fn_88323BA0(Set *s)
{
    int i, hr;
    if (!s->items[0]) return 0x24;
    for (i = 0; i < s->count; i++) {
        hr = s->items[i]->vt->prepare(s->items[i]);
        if (hr) return hr;
        s->items[i]->flags &= ~0x80;
        s->items[i]->flags &= ~0x10;
        s->items[i]->flags |= 0x40;
    }
    s->state &= ~0x400;
    return 0;
}
