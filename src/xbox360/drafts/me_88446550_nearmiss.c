/* NEAR MISS (agO round 2, 2026-11-19): 1 off on plain and LTCG (/Oc): add r28,r30,r11 (offset first) vs add r28,r11,r30.
 * Int mode parameter removed the clrlwi; add order unchanged by index/pointer forms. */
/* Swing_DLL.xex 0x88446550: stores mode at +0x40, recomputes the 16-bit id at +0xc of every 16-byte entry (array +0x24, count +0x28)
 * as fn_88465FE0(index, arg, mode != 5), then sets the dirty flag at +0x14. */
typedef struct Entry { char pad[0xc]; unsigned short id; char pad2[2]; } Entry;
typedef struct Obj { char pad[0x14]; unsigned char dirty; char pad2[0xf]; Entry *entries; int count; char pad3[0x14]; unsigned char mode; } Obj;
unsigned short fn_88465FE0(int index, void *arg, int not5);

void fn_88446550(Obj *o, void *arg, int mode)
{
    int i;
    o->mode = (unsigned char)mode;
    for (i = 0; i < o->count; i++)
    {
        Entry *e = &o->entries[i];
        e->id = fn_88465FE0(i, arg, mode != 5);
    }
    o->dirty = 1;
}
