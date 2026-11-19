/* 0x889166D8: copies the mode byte, sets the dirty byte and fills a per-entry flag array with (handle == -1) over a self-relative entry table */
/* Matched on /Oc (agAH). Both self-relative arrays addressed through Arr pointer locals; flags local taken before the dirty store. */
typedef struct Arr { int first; unsigned int count; } Arr;
typedef struct Ent { char p[0x1c]; int handle; } Ent;
typedef struct C { char p[0x44]; Arr ents; } C;
typedef struct A { char p[0x39c]; unsigned char mode; } A;
typedef struct F { char p[0x10]; Arr flags; char p2[4]; unsigned char dirty; } F;
typedef struct T { char p[0x38]; A *a; F *f; char p2[4]; C *c; char p3[0xce - 0x48]; unsigned char mode; } T;
void fn_889166D8(T *t)
{
    Arr *ents, *flags;
    unsigned int i;
    t->a->mode = t->mode;
    flags = &t->f->flags;
    t->f->dirty = 1;
    ents = &t->c->ents;
    for (i = 0; i < ents->count; i++)
        ((unsigned char *)flags + flags->first)[i] = ((Ent *)((char *)ents + ents->first))[i].handle == -1;
}
