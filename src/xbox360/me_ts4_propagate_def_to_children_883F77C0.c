/* 0x883F77C0: copies the source def into the owner's child node and every item on its intrusive list, caches the def's
   short id at +0x40 when ts4_get_bits_0_1c_7_883E0778 is 0, then stores owner/+0x18/+0x24. Matched plain /O1 only (agT); LTCG keeps values in volatiles. */
unsigned int ts4_get_bits_0_1c_7_883E0778(const char *object);
typedef struct Link { struct Link *next; } Link;
typedef struct Item { int f0; Link link; int f8, fc, f10; void *f14; } Item;
typedef struct Info { char pad[0xc]; char *fc; char pad2[0xc]; int f1c; } Info;
typedef struct Def { char pad[0xc]; Info *fc; } Def;
typedef struct Src { char pad[0x14]; Def *def; char pad2[0xc]; int f24; } Src;
typedef struct Dst {
    char pad[0x14]; Def *def; int f18; char pad1[4]; void *owner; int f24;
    char pad2[0x18]; short f40; char pad3[0x36]; Link head;
} Dst;
typedef struct Mid { char pad[0xc]; int fc; Dst *dst; } Mid;
typedef struct Owner { char pad[0x138]; Mid *mid; } Owner;
typedef struct A { char pad[0xc]; int fc; Src *src; } A;
int ts4_propagate_def_to_children_883F77C0(A *a, Owner *o)
{
    Mid *m = o->mid;
    Src *s = a->src;
    Dst *d = m->dst;
    Link *n;
    m->fc = a->fc;
    d->def = s->def;
    for (n = d->head.next; n != &d->head; n = n->next) {
        Item *it = n ? (Item *)((char *)n - 4) : 0;
        it->f14 = s->def;
    }
    if ((int)ts4_get_bits_0_1c_7_883E0778(s->def->fc->fc) == 0)
        d->f40 = (short)s->def->fc->f1c;
    d->f24 = s->f24;
    d->f18 = 0;
    d->owner = o;
    return 0;
}
