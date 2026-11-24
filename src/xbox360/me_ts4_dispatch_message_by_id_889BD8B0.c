/* 0x889BD8B0: dispatch a message through the 84-entry handler table lbl_880C6C00. The id is the big-endian u16 at msg+0xa; an entry matches when its id equals it and its direction field equals bit 0 of msg+0x8. The handler is tail-called with the message; no match returns.
 * Matched on plain /Oc and LTCG routes (work/army/ME/v.py chk, matching-b129). */
typedef struct Msg { unsigned short flags; char pad[6]; unsigned short w8; unsigned char hi, lo; } Msg;
typedef void (*Handler)(Msg *);
typedef struct Entry { unsigned short id; unsigned short dir; int unused4; Handler fn; } Entry;
extern const Entry lbl_880C6C00[0x54];
void fn_889BD8B0(Msg *m)
{
    unsigned i;
    const Entry *e = lbl_880C6C00;
    unsigned short w = m->w8;
    unsigned short id = (unsigned short)((m->hi << 8) | m->lo);
    for (i = 0; i < 0x54; i++, e++) {
        if (id == e->id && e->dir == (w & 1)) {
            e->fn(m);
            return;
        }
    }
}
