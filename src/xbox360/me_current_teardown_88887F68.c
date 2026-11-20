/* 0x88887F68: teardown: resets the vtable to lbl_880F7940, clears the link at +0x224, and if the global manager
 * (lbl_88D45B1C) has this object as its current entry (+0x224), restores the previous one (+0x220); then
 * tail-calls the base teardown. */
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
extern char lbl_880F7940[];
typedef struct Ts4Current { void *vt; char p[0x220]; struct Ts4Current *cur; } Ts4Current;
typedef struct Ts4CurrentMgr { char p[0x220]; Ts4Current *prev; Ts4Current *cur; } Ts4CurrentMgr;
extern Ts4CurrentMgr *lbl_88D45B1C;
void ts4_current_teardown_88887F68(Ts4Current *o)
{
    Ts4CurrentMgr *m;
    o->vt = lbl_880F7940;
    o->cur = 0;
    m = lbl_88D45B1C;
    if (o == m->cur)
        m->cur = m->prev;
    ts4_if_call_seq_lbl_880F7EE4_88617D28(o);
}
