/* Loader_DLL.xex 0x83109770-0x83162DF0, executable version 0.0.0.3. */
/* Destructor-style helpers around the heap free routine fn_83120540. */
typedef unsigned int u32;
extern void fn_83120540(void *p);

typedef struct Obj5 { void *a, *b, *c, *d, *e; } Obj5;
void ts4l_free_members_8311CCA8(Obj5 *o)
{
    if (o) {
        fn_83120540(o->a);
        fn_83120540(o->b);
        fn_83120540(o->c);
        fn_83120540(o->e);
        fn_83120540(o);
    }
}

typedef struct Tab100 { void *a[100]; int na; void *b[100]; int nb; } Tab100;
void ts4l_free_tables_83153048(Tab100 *t)
{
    Tab100 *o = t;
    void **pa = &t->a[0];
    int i;
    for (i = 0; i < 100; i++) {
        if (pa[0]) {
            fn_83120540(pa[0]);
            pa[0] = 0;
        }
        if (pa[101]) {
            fn_83120540(pa[101]);
            pa[101] = 0;
        }
        pa++;
    }
    o->na = 0;
    o->nb = 0;
}

typedef struct Ref { int pad; void *buf; int pad2[2]; int cnt; } Ref;
int ts4l_release_83162DF0(Ref *o)
{
    int r;
    if (o == 0) {
        r = (int)0x80000006u;
    } else {
        if (--o->cnt == 0) {
            if (o->buf)
                fn_83120540(o->buf);
            fn_83120540(o);
        }
        r = 0;
    }
    return r;
}

typedef struct Slots { void *slot[0x80]; char pad[0x20]; int cnt; } Slots;
int ts4l_clear_slots_831417C0(Slots *o)
{
    int i;
    o->cnt = 0;
    for (i = 0; i < 0x80; i++) {
        if (o->slot[i])
            fn_83120540(o->slot[i]);
        o->slot[i] = 0;
    }
    return 0;
}

typedef struct HNode { int a; void *key; int b; struct HNode *next; } HNode;
void ts4l_free_hash_83109770(HNode **t)
{
    int i;
    for (i = 0; i < 0x1b; i++) {
        HNode *n = t[i];
        HNode *nx;
        while (n) {
            nx = n->next;
            fn_83120540(n->key);
            fn_83120540(n);
            n = nx;
        }
        t[i] = 0;
    }
}

extern void fn_831460E0(void *p);
extern void ts4_tailcall_fn_83142118_83142508(void *p);
extern void fn_83142098(void *self, u32 i);

typedef struct HN { int a, b, c; struct HN *next; } HN;
void ts4l_free_hash_83146478(HN **t)
{
    int i;
    for (i = 0; i < 0x20; i++) {
        HN *n = t[i];
        HN *nx;
        while (n) {
            nx = n->next;
            fn_831460E0(n);
            fn_83120540(n);
            n = nx;
        }
        t[i] = 0;
    }
}

void ts4l_set_owned_83115658(char *s, void *v)
{
    void *o = *(void **)(s + 0xc);
    if (o != 0) {
        ts4_tailcall_fn_83142118_83142508(o);
        fn_83120540(o);
    }
    *(void **)(s + 0xc) = v;
}

typedef struct Ent { void *a; void *b; } Ent;
typedef struct Arr { int n; int pad; Ent **items; u32 flags; } Arr;

void ts4l_free_items_83142118(Arr *s)
{
    int i;
    if (s->items != 0) {
        for (i = 0; (u32)i < (u32)s->n; i++)
            fn_83142098(s, i);
        fn_83120540(s->items);
        s->items = 0;
    }
    s->pad = 0;
    s->n = 0;
}

typedef struct Ts4lLN { char pad[0x14]; struct Ts4lLN *next; } Ts4lLN;
extern Ts4lLN *lbl_83531078;
extern void fn_83120540(void *p);
void ts4l_free_list_8311D930(void)
{
    Ts4lLN *p = lbl_83531078;
    Ts4lLN *nx;
    if (p) {
        do {
            nx = p->next;
            fn_83120540(p);
            p = nx;
        } while (nx);
    }
    lbl_83531078 = 0;
}

