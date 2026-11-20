/* 0x885223F0: Releases each of the three u16 ids at the start of s that is not 0xFFFF through the releaser vtable slot 5 (id, arg) and marks it 0xFFFF; returns the address s + 0x20. The first argument is unused. */
/* Matched on /Oc (agAH). Count-down loop over a pointer to the ids (bne on subic.). */
typedef struct Releaser Releaser;
typedef struct ReleaserVtbl { void *slot0[5]; void (*release)(Releaser *r, unsigned short id, void *arg); } ReleaserVtbl;
struct Releaser { ReleaserVtbl *vtable; };
typedef struct IdSet { unsigned short ids[3]; char pad6[0x1a]; char next[1]; } IdSet;
char *fn_885223F0(void *self, IdSet *s, Releaser *r, void *arg)
{
    int i;
    unsigned short *id = s->ids;
    for (i = 3; i != 0; i--) {
        if (*id != 0xFFFF) {
            r->vtable->release(r, *id, arg);
            *id = 0xFFFF;
        }
        id++;
    }
    return s->next;
}
