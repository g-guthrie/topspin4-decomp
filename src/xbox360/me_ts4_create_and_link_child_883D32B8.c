/* 0x883D32B8: 0x1F when not ready (+0x809C), 0x25 for a null out; allocates and constructs a 0x3C-byte object (883EDE18, taken to return this), initialises it (883E63B8, freed on error) and links it at the tail of the list at +0x8078; 0x2C on allocation failure */
/* Matched on /O1 plain only (agV, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_880391A8[];
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Obj { int f0; Link link; } Obj;
typedef struct T { char pad[0x8078]; Link head; char pad2[0x809c - 0x8080]; void *ready; } T;
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
void fn_88315F10(void *heap, void *buf, const char *file, int line);
Obj *fn_883EDE18(void *p);
int ts4_fn_883E63B8(Obj *o);
static void link_before(Link *n, Link *head)
{
    Link *p = head->prev;
    n->next = head;
    n->prev = p;
    head->prev = n;
    n->prev->next = n;
}
int fn_883D32B8(T *t, Obj **out)
{
    void *p;
    Obj *o;
    int r;
    if (!t->ready)
        return 0x1f;
    if (!out)
        return 0x25;
    *out = 0;
    p = fn_88315C60(lbl_88B3302C->heap, 0x3c, lbl_880391A8, 0x10e7, 0, 0);
    o = p ? fn_883EDE18(p) : 0;
    if (!o)
        return 0x2c;
    r = ts4_fn_883E63B8(o);
    if (r) {
        fn_88315F10(lbl_88B3302C->heap, o, lbl_880391A8, 0x10f0);
        return r;
    }
    link_before(&o->link, &t->head);
    *out = o;
    return 0;
}
