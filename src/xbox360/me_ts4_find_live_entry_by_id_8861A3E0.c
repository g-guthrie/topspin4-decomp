/* 0x8861A3E0: Returns the first of 20 inline 0x210-byte entries that has an owner, is active and ready, and whose id equals id; returns 0 for id 0 or no hit. */
/* Matched on /Oc (agAH). Found/break form with end hoisted and constant-first compares. */
typedef struct Entry { void *owner; unsigned char active; char p5[0x204 - 5]; int ready; char p208[4]; unsigned int id; } Entry;
typedef struct Mgr { char p0[0x490]; Entry entries[20]; } Mgr;
static unsigned char entry_is_live(const Entry *e)
{
    return e->owner != 0 && e->active && e->ready != 0;
}
Entry *fn_8861A3E0(Mgr *m, unsigned int id)
{
    Entry *found = 0;
    if (id != 0) {
        Entry *end = m->entries + 20;
        Entry *e;
        for (e = m->entries; end != e; e++) {
            if (entry_is_live(e) && id == e->id) {
                found = e;
                break;
            }
        }
    }
    return found;
}
