/* 0x883F14E8: sums per-group levels: the first case whose condition holds (883CEAD0 on the def x/y, or always without an evaluator) gives the base value, then every flagged modifier (flag 8) multiplies it by 883FEB50's factor; writes the total */
/* Matched on /O1 plain only (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Def { char pad[0x10]; unsigned int flags; float x, y, value; } Def;
typedef struct Par { char pad[0x18]; float v; } Par;
typedef struct Item { int vt; Link link; char pad[0x14 - 0xc]; Def *def; char pad2[0x20 - 0x18]; Par *par; } Item;
typedef struct Group { int vt; Link link; char pad[0x24 - 0xc]; void *eval; char pad2[0x34 - 0x28]; Link cases; char pad3[0x40 - 0x3c]; Link mods; } Group;
typedef struct T { char pad[0xc]; Link groups; } T;
int fn_883CEAD0(void *eval, float x, float y, unsigned char *hit);
int fn_883FEB50(Def *d, float v, float *out);

#define ITEM(l, ty) ((l) ? (ty *)((char *)(l) - 4) : 0)

int fn_883F14E8(T *t, float *out)
{
    float total = 0.0f;
    Link *g, *n;
    int r;
    for (g = t->groups.next; g && g != &t->groups; g = g->next) {
        Group *gp = ITEM(g, Group);
        float v = 0.0f;
        for (n = gp->cases.next; n && n != &gp->cases; n = n->next) {
            Item *it = ITEM(n, Item);
            unsigned char hit;
            if (gp->eval) {
                r = fn_883CEAD0(gp->eval, it->def->x, it->def->y, &hit);
                if (r)
                    return r;
            } else {
                hit = 1;
            }
            if (hit) {
                v = it->def->value;
                break;
            }
        }
        for (n = gp->mods.next; n && n != &gp->mods; n = n->next) {
            Item *it = ITEM(n, Item);
            if (it->def->flags & 8) {
                float k;
                r = fn_883FEB50(it->def, it->par->v, &k);
                if (r)
                    return r;
                v = k * v;
            }
        }
        total = v + total;
    }
    *out = total;
    return 0;
}
