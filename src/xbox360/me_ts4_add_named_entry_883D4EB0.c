/* 0x883D4EB0: validates kind/handle/name (0x25), readiness at +0x809C (0x1F), the handle flag 0x80 when kind is set and type 8 (0x19); allocates a 0x11C-byte entry (inline ctor, vtable lbl_8803934C), copies the name to +0x11, tail-links it at +0x8090 and sets handle flag 0x100; 0x2C on allocation failure. The ctor's zero store goes through a pointer local */
/* Matched on /O1 plain and LTCG (agX, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_880391A8[];
extern const void *lbl_8803934C[];
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct H { char pad[0x40]; unsigned int flags; } H;
typedef struct Ent {
    const void **vt; Link link; int fc; char pad[0x11 - 0x10];
    char name[0x114 - 0x11];
    H *h; int kind;
} Ent;
typedef struct T { char pad[0x8090]; Link head; char pad2[0x809c - 0x8098]; void *ready; } T;
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
int ts4_if_get_fn_8832BFC0_88316E00(H *h, unsigned int *out);
int ts4_if_get_fn_8832BFC0_88316AB8(H *h, int *out, int a, int b, int c);
char *fn_88329680(char *dst, const char *src);
static void link_before(Link *n, Link *head)
{
    Link *p = head->prev;
    n->next = head;
    n->prev = p;
    head->prev = n;
    n->prev->next = n;
}
static Ent *ent_ctor(Ent *e)
{
    e->link.next = &e->link;
    e->link.prev = &e->link;
    { int *pf = &e->fc; *pf = 0; }
    e->vt = lbl_8803934C;
    return e;
}
int fn_883D4EB0(T *t, const char *name, int kind, H *h)
{
    unsigned int fl;
    int type;
    void *p;
    Ent *e;
    int r;
    if (kind < 0)
        return 0x25;
    if (!t->ready)
        return 0x1f;
    if (!h || !name)
        return 0x25;
    r = ts4_if_get_fn_8832BFC0_88316E00(h, &fl);
    if (r)
        return r;
    if (kind && !(fl & 0x80))
        return 0x25;
    r = ts4_if_get_fn_8832BFC0_88316AB8(h, &type, 0, 0, 0);
    if (r)
        return r;
    if (type != 8)
        return 0x19;
    p = fn_88315C60(lbl_88B3302C->heap, 0x11c, lbl_880391A8, 0xfd5, 0, 0);
    e = p ? ent_ctor((Ent *)p) : 0;
    if (!e)
        return 0x2c;
    e->h = h;
    e->kind = kind;
    fn_88329680(e->name, name);
    link_before(&e->link, &t->head);
    h->flags |= 0x100;
    return 0;
}
