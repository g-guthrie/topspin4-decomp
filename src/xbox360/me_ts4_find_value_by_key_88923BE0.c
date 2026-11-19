/* 0x88923BE0: returns vals->items[i] for the first 0x1C-byte entry of the self-relative table at tab(+8)+0x18 whose key (+0x14) equals key; 0 if none. */
/* Matched on /Oc (agAF). r = 0 result with a break gives the li r3,0 before the count test and the blelr exit. */
typedef struct Ent { char p[0x14]; unsigned int key; char p18[4]; } Ent;
typedef struct Rel { int off; int count; } Rel;
typedef struct Tab { char p[0x18]; Rel rel; } Tab;
typedef struct Vals { void **items; } Vals;
typedef struct T { char p[8]; Tab *tab; char pc[4]; Vals *vals; } T;
static __inline Ent *ent_at(Rel *r, int i) { return (Ent *)((char *)r + (i * sizeof(Ent) + r->off)); }
void *fn_88923BE0(T *t, unsigned int key)
{
    void *r = 0;
    int i;
    for (i = 0; i < t->tab->rel.count; i++)
        if (ent_at(&t->tab->rel, i)->key == key) {
            r = t->vals->items[i];
            break;
        }
    return r;
}
