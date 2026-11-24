/* Swing_DLL.xex 0x88378F68: calls prepare (vtable slot 8) on each of count (+0x7C) resources (+0x80) and marks each ready:
 * flags +0x24 clear 0x80 and 0x10, set 0x40. 0x24 if the first slot is empty. agAE: /Oc. */
typedef struct Res Res;
typedef struct ResVt { void *slots[8]; int (*prepare)(Res *r); } ResVt;
struct Res { ResVt *vt; char pad4[0x24 - 4]; unsigned int flags; };
typedef struct Set { char pad[0x7c]; int count; Res *items[1]; } Set;
int fn_88378F68(Set *s)
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
    return 0;
}
