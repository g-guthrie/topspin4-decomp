typedef struct Node { char pad[4]; int id; char p1[8]; unsigned char done; } Node;
typedef struct Vec { int *first; int *last; int *end; } Vec;
typedef struct Obj { char pad[0x4c]; Node **first; Node **last; } Obj;
void ts4_vector_realloc_insert_88263908(void *vec, void *where, void *item, int count, int flag);
static unsigned char contains(Vec *v, int id)
{
    unsigned char r = 0;
    int *p, *e = v->last;
    for (p = v->first; p != e; p++)
        if (*p == id) { r = 1; break; }
    return r;
}
static void push(Vec *v, int *val)
{
    int *p = v->last;
    if (p != v->end) {
        if (p) *p = *val;
        v->last++;
    } else
        ts4_vector_realloc_insert_88263908(v, p, val, 1, 1);
}
/* Appends the id of every unfinished node to v, skipping ids already present. */
void fn_887ED328(Obj *o, Vec *v)
{
    Node **it, **e;
    it = o->first; e = o->last;
    for (; it != e; it++) {
        Node *n = *it;
        if (!n->done) {
            int id = n->id;
            if (!contains(v, id)) push(v, &id);
        }
    }
}
