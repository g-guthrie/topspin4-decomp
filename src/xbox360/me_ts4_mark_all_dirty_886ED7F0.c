/* 0x886ED7F0: sets the byte at +0x98 of every 0xA0-byte item in every group of the vector at +0x20 */
/* Matched on /Oc (agAH). Inline gsize(&t->groups) in the loop test, group pointer local, end hoisted before begin. */
typedef struct Item { char p[0x98]; unsigned char dirty; char p2[7]; } Item;
typedef struct Group { Item *begin; Item *end; int pad[2]; } Group;
typedef struct GVec { Group *begin; Group *end; } GVec;
typedef struct T { char p[0x20]; GVec groups; } T;
static __inline unsigned int gsize(GVec *v) { return v->end - v->begin; }
void fn_886ED7F0(T *t)
{
    unsigned int i;
    for (i = 0; i < gsize(&t->groups); i++) {
        Group *gr = &t->groups.begin[i];
        Item *end = gr->end;
        Item *it;
        for (it = gr->begin; it != end; it++)
            it->dirty = 1;
    }
}
