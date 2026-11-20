/* 0x8846C0F8: Scans the track list at +0x28 (count at +0x2c) from the last entry back and returns the largest end address base + 4 * (slot * 32 + offset + 0x2a), or 0 for an empty list. */
/* Matched on /Oc (agAH). Keep-the-max written as if (best <= v) best = v (cmpw best, v; bgt). */
typedef struct Track { char pad[0xc]; int *base; char pad10[4]; int offset; char pad18[0x4c - 0x18]; int slot; } Track;
typedef struct TrackList { char pad[0x28]; Track **items; int count; } TrackList;
int fn_8846C0F8(TrackList *l)
{
    int best = 0;
    int i;
    for (i = l->count - 1; i >= 0; i--) {
        Track *t = l->items[i];
        int v = (int)(t->base + (t->slot * 32 + t->offset + 0x2a));
        if (best <= v)
            best = v;
    }
    return best;
}
