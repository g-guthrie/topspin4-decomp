/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88446550: stores mode at +0x40, recomputes the 16-bit id at +0xc of every 16-byte entry (array +0x24, count +0x28)
 * as fn_88465FE0(index, arg, mode != 5), then sets the dirty flag at +0x14.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_88446550_nearmiss.c (Q5S sweep, 2026-11-24): the mode byte goes through a block-local temporary.
 * See work/specs/Q5S/sweep_88446550.json for route and flags. */
typedef struct Entry { char pad[0xc]; unsigned short id; char pad2[2]; } Entry;
typedef struct Obj { char pad[0x14]; unsigned char dirty; char pad2[0xf]; Entry *entries; int count; char pad3[0x14]; unsigned char mode; } Obj;
unsigned short fn_88465FE0(int index, void *arg, int not5);

void ts4_entries_set_mode_88446550(Obj *o, void *arg, int mode)
{
    int i;
    { unsigned char m = (unsigned char)mode; o->mode = m; }
    for (i = 0; i < o->count; i++)
    {
        Entry *e = &o->entries[i];
        e->id = fn_88465FE0(i, arg, mode != 5);
    }
    o->dirty = 1;
}
