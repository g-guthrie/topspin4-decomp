/* 0x88592878: Record i (0x60 stride at +8): when bit 0x20000 of the set mode (+4) is set reads the record flags directly, else through its shared pointer (+0x40); returns whether the 2-bit field at bits 20-21 is not 3. */
/* Matched on /Oc (agAH). Written as (w & 0x300000) - 0x300000 != 0 to get subis/subic/subfe; != 0x300000 compiles to a reversed subtract. */
typedef struct Rec { unsigned int flags; char pad4[0x3c]; unsigned int *shared; char pad44[0x60 - 0x44]; } Rec;
typedef struct RecSet { int unk0; unsigned int mode; Rec *recs; } RecSet;
int fn_88592878(RecSet *s, int i)
{
    if (s->mode & 0x20000)
        return (s->recs[i].flags & 0x300000) - 0x300000 != 0;
    return (*s->recs[i].shared & 0x300000) - 0x300000 != 0;
}
