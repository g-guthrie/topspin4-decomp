/* 0x883D2700: 0x25 for a null out; looks up t->f14 (883093F0, used for its return code), allocates and constructs a 0xA4-byte entry (883EE8E8, taken to return this), stores the handle at +0x9C and links it at the tail of the list at +0x806C; 0x2C on allocation failure */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_880391A8[];
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Obj { int f0; Link link; } Obj;
typedef struct T { char pad[0x14]; void *key; char pad2[0x8054]; Link head; } T;
int ts4_lookup_then_forward_883093F0(void *key, void **out);
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
Obj *ts4_addr_lbl_88039BEC_883EE8E8(void *p);
void ts4_set_u32_off9c_883EE518(Obj *o, void *v);
static void link_before(Link *n, Link *head)
{
    n->prev = head->prev;
    n->next = head;
    head->prev = n;
    n->prev->next = n;
}
int ts4_create_and_link_entry_883D2700(T *t, Obj **out)
{
    void *h;
    void *p;
    Obj *o;
    int r;
    if (!out)
        return 0x25;
    r = ts4_lookup_then_forward_883093F0(t->key, &h);
    if (r)
        return r;
    p = fn_88315C60(lbl_88B3302C->heap, 0xa4, lbl_880391A8, 0xdc2, 0, 0);
    o = p ? ts4_addr_lbl_88039BEC_883EE8E8(p) : 0;
    if (!o)
        return 0x2c;
    ts4_set_u32_off9c_883EE518(o, h);
    link_before(&o->link, &t->head);
    *out = o;
    return 0;
}
