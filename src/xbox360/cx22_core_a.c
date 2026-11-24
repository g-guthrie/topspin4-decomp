/* CX22 part a: game core loaders/resources (0x8822C1C8-0x88240000), plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX22_INL static __forceinline
#else
#define CX22_INL static inline
#endif

/* ---- vector equality ---- */
typedef struct Cx22IntVec { int *first; int *last; } Cx22IntVec;
CX22_INL u8 cx22_range_eq(int *a, int *last, int *b)
{
    for (; a != last; a++, b++)
        if (*a != *b) return 0;
    return 1;
}
CX22_INL u8 cx22_intvec_eq(Cx22IntVec *a, Cx22IntVec *b)
{
    return a->last - a->first == b->last - b->first && cx22_range_eq(a->first, a->last, b->first);
}

/* 0x8822DF38: two int vectors are equal (same length and same elements) */
u8 ts4_intvec_equal_8822DF38(Cx22IntVec *a, Cx22IntVec *b)
{
    return cx22_intvec_eq(a, b);
}

/* ---- the global block holder ---- */
typedef struct Cx22Deq {
    char *f0, *f4, *f8;
    char **fc;
    char *f10, *f14, *f18;
    char **f1c;
    char **map;
    u32 mapsize;
} Cx22Deq;
typedef struct Cx22Own { u8 p[0x24]; void *dflt; } Cx22Own;
extern Cx22Deq lbl_88D492D0;
extern Cx22Own *lbl_88D45B38;
extern void ts4_destroy_owned_object(void *p);
extern void *ts4_find_range_owner_8860D360(Cx22Own *g, void *blk);
extern void ts4_node_visit_8860DBC8(void *owner, void *blk);
extern void fn_885651F8(void *p);

/* 0x8822D330: release the global block: destroy the live objects, then hand the block back to its owner (or free it) */
void ts4_release_global_block_8822D330(void)
{
    Cx22Deq *g = &lbl_88D492D0;
    void *blk;
    if (g->map) {
        char **it = g->fc;
        char **end = g->f1c + 1;
        for (; it < end; it++)
            ts4_destroy_owned_object(*it);
        blk = g->map;
        if (blk) {
            Cx22Own *o = lbl_88D45B38;
            if (o) {
                void *own = ts4_find_range_owner_8860D360(o, blk);
                if (own) ts4_node_visit_8860DBC8(own, blk);
                else ts4_node_visit_8860DBC8(o->dflt, blk);
            } else {
                fn_885651F8(blk);
            }
        }
    }
}

/* ---- allocated objects ---- */
#ifdef _MSC_VER
typedef unsigned int Cx22Up;
#else
typedef unsigned long Cx22Up;
#endif
extern void *lbl_88D45AD4;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);
extern void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(u32 *p);
extern void ts4_call_seq_fn_88255AA0_8825C7E8(void *p);
extern void fn_8825E7B0(void *p, u32 n);
extern void fn_8822C1C8(void *p, u32 n);
extern void fn_8825CB20(void *p, u32 n);
typedef struct Cx22AVec { u32 begin, end, ctx, cap; } Cx22AVec;
typedef struct Cx22TwoVec { u8 base[0x10]; Cx22AVec a; Cx22AVec b; u32 f30; } Cx22TwoVec;

CX22_INL void cx22_avec_init(Cx22AVec *v, u32 z)
{
    u32 tmp = z;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
    v->begin = z;
    v->end = z;
    v->ctx = z;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&v->ctx);
    v->cap = z;
}

/* 0x88238948: allocate a 0x34-byte object with two allocator-backed vectors, reserve 0x40 entries in each */
Cx22TwoVec *ts4_create_two_vec_object_88238948(void)
{
    Cx22TwoVec *result = 0;
    u32 z = (u32)(Cx22Up)result;
    u32 ctx = z;
    Cx22TwoVec *obj;
    if (lbl_88D45AD4) ctx = *(u32 *)((char *)lbl_88D45AD4 + 0x15680);
    obj = (Cx22TwoVec *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x34, 4, ctx, 2);
    if (obj) {
        ts4_call_seq_fn_88255AA0_8825C7E8(obj);
        cx22_avec_init(&obj->a, z);
        cx22_avec_init(&obj->b, z);
        obj->f30 = z;
        fn_8825E7B0(&obj->b, 0x40);
        fn_8822C1C8(&obj->a, 0x40);
        fn_8825CB20(obj, 0x40);
    }
    return obj ? obj : result;
}

typedef struct Cx22TwoVec3c { u8 base[0x10]; Cx22AVec a; Cx22AVec b; u32 f30; } Cx22TwoVec3c;
extern void fn_8825B648(void *p);
extern void fn_8825B730(void *p);

/* 0x88238F60: allocate a 0x3c-byte object with two allocator-backed vectors, reserve 0x24 entries */
Cx22TwoVec3c *ts4_create_two_vec_object_88238F60(void)
{
    Cx22TwoVec3c *result = 0;
    u32 z = (u32)(Cx22Up)result;
    u32 ctx = z;
    Cx22TwoVec3c *obj;
    if (lbl_88D45AD4) ctx = *(u32 *)((char *)lbl_88D45AD4 + 0x15680);
    obj = (Cx22TwoVec3c *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x3c, 4, ctx, 2);
    if (obj) {
        ts4_call_seq_fn_88255AA0_8825C7E8(obj);
        cx22_avec_init(&obj->a, z);
        cx22_avec_init(&obj->b, z);
        obj->f30 = z;
        fn_8825B648(&obj->b);
        fn_8822C1C8(&obj->a, 0x24);
        fn_8825CB20(obj, 0x24);
    }
    return obj ? obj : result;
}

/* ---- red-black tree insert next to a hint node ---- */
typedef struct Cx22TNode { u32 f0; struct Cx22TNode *parent; struct Cx22TNode *left; struct Cx22TNode *right; int key; } Cx22TNode;
typedef struct Cx22THead { u32 f0; Cx22TNode *head; u32 size; } Cx22THead;
extern Cx22TNode *fn_882401D0(Cx22THead *t, const int *v);
extern void fn_8815D7D0(Cx22TNode *node, Cx22TNode **root);

/* 0x8823D8F8: insert a value next to a hint node (to the left when forced, at the head, or when smaller), link it, rebalance and bump the count */
Cx22TNode **ts4_tree_insert_8823D8F8(Cx22TNode **out, Cx22THead *t, u32 addleft, Cx22TNode *where, const int *val, u32 addright)
{
    Cx22TNode *head = t->head;
    Cx22TNode *node;
    if (where == head || (addright == 0 && (addleft != 0 || *val < where->key))) {
        node = fn_882401D0(t, val);
        where->left = node;
        if (where == t->head) {
            t->head->parent = node;
            t->head->right = node;
        } else if (where == t->head->left) {
            t->head->left = node;
        }
    } else {
        node = fn_882401D0(t, val);
        where->right = node;
        if (where == t->head->right)
            t->head->right = node;
    }
    node->parent = where;
    node->right = 0;
    node->left = 0;
    {
        u32 n;
        fn_8815D7D0(node, &t->head->parent);
        n = t->size;
        *out = node;
        t->size = n + 1;
    }
    return out;
}

/* ---- global block map ---- */
extern void *ts4_if_call_seq_fn_88883CD0_8860D250(void *g);
extern void *fn_88613570(void *alloc, u32 size, u32 align, void *owner);

/* 0x8822D3D0: set up the global block map with eight slots and one 0x78-byte block in the middle slot */
void ts4_init_global_deque_8822D3D0(void)
{
    Cx22Deq *d = &lbl_88D492D0;
    char **mid;
    char **end;
    char **p;
    char *first;
    char *last;
    d->mapsize = 8;
    d->map = (char **)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, 0x20, 4, &d->map);
    mid = d->map + ((d->mapsize - 1) >> 1);
    end = mid + 1;
    for (p = mid; p < end; p++)
        *p = (char *)fn_88613570(lbl_88D45B38 ? ts4_if_call_seq_fn_88883CD0_8860D250(lbl_88D45B38) : 0, 0x78, 4, &d->mapsize);
    d->fc = mid;
    first = *mid;
    d->f1c = end - 1;
    d->f8 = first + 0x78;
    d->f4 = first;
    last = end[-1];
    d->f0 = first;
    d->f18 = last + 0x78;
    d->f14 = last;
    d->f10 = last;
}

/* ---- 0xfc-byte object with three allocator-backed vectors ---- */
typedef struct Cx22ThreeVec { Cx22AVec a; Cx22AVec b; Cx22AVec c; u8 pad30[0xb4 - 0x30]; u32 fb4, fb8, fbc, fc0; u8 padc4[0xf8 - 0xc4]; u32 ff8; } Cx22ThreeVec;

/* 0x88239138: allocate a 0xfc-byte object with three empty allocator-backed vectors and default scalar fields */
Cx22ThreeVec *ts4_create_three_vec_object_88239138(void)
{
    Cx22ThreeVec *result = 0;
    u32 z = (u32)(Cx22Up)result;
    u32 ctx = z;
    Cx22ThreeVec *obj;
    if (lbl_88D45AD4) ctx = *(u32 *)((char *)lbl_88D45AD4 + 0x15680);
    obj = (Cx22ThreeVec *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0xfc, 4, ctx, 2);
    if (obj) {
        cx22_avec_init(&obj->a, z);
        cx22_avec_init(&obj->b, z);
        cx22_avec_init(&obj->c, z);
        obj->fc0 = 1;
        obj->fb4 = z;
        obj->fb8 = z;
        obj->fbc = (u32)-1;
        obj->ff8 = z;
    }
    return obj ? obj : result;
}

/* ---- record copy constructor with two embedded sub-objects ---- */
extern char lbl_880F3428[];
extern char lbl_880F342C[];
extern void fn_882400F8(void *dst, void *src);
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct PartA { const void *vt; u32 pad; u32 w; u8 sub[0x40 - 0xc]; } PartA;
typedef struct PartB { const void *vt; u32 w; u8 sub[0x3c - 8]; } PartB;
typedef struct CRec {
    u32 w0;
    u32 pad4;
    PartA a;
    unsigned long long q48;
    PartB b;
    u32 w8c, w90, w94;
    u8 b98;
} CRec;

INL void copy_a(PartA *d, PartA *s)
{
    d->vt = lbl_880F3428;
    d->w = s->w;
    fn_882400F8(d->sub, s->sub);
}
INL void copy_b(PartB *d, PartB *s)
{
    d->vt = lbl_880F342C;
    d->w = s->w;
    fn_882400F8(d->sub, s->sub);
}
/* 0x8823F698: copy-construct a record with two embedded sub-objects */
void ts4_rec_copy_ctor_8823F698(CRec *dst, CRec *src)
{
    if (dst) {
        dst->w0 = src->w0;
        copy_a(&dst->a, &src->a);
        dst->q48 = src->q48;
        copy_b(&dst->b, &src->b);
        dst->w8c = src->w8c;
        dst->w90 = src->w90;
        dst->w94 = src->w94;
        dst->b98 = src->b98;
    }
}

/* ---- 0x134-byte record uninitialised copy ---- */
extern void fn_8822A4A0(void *dst, void *src);
typedef struct R134 { u8 head[0x10c]; u32 w10c, w110, w114; u8 b118; u32 w11c, w120, w124, w128, w12c, w130; } R134;

/* 0x88233A88: uninitialised copy of 0x134-byte records [first,last) to dest */
R134 *ts4_uninit_copy_rec134_88233A88(R134 *first, R134 *last, R134 *dest)
{
    if (first != last) {
        do {
            if (dest) {
                fn_8822A4A0(dest, first);
                dest->w10c = first->w10c;
                dest->w110 = first->w110;
                dest->w114 = first->w114;
                dest->b118 = first->b118;
                dest->w11c = first->w11c;
                dest->w120 = first->w120;
                dest->w124 = first->w124;
                dest->w128 = first->w128;
                dest->w12c = first->w12c;
                dest->w130 = first->w130;
            }
            first++;
            dest++;
        } while (first != last);
    }
    return dest;
}

/* ---- keyed entry vector ---- */
extern u32 ts4_crc32_cstr_seed_88608590(u32 a, u32 b);
extern void fn_8825C638(void *v, u32 key, u32 val);
typedef struct Ent { u32 key, val; } Ent;
typedef struct EVec { Ent *first; Ent *last; } EVec;

/* 0x882333C0: remove the entry for one key (swap with the last entry) and re-add its value under another key */
void ts4_vec_rekey_entry_882333C0(EVec *v, u32 *oldkey, u32 *newkey)
{
    u32 h = ts4_crc32_cstr_seed_88608590(0, *oldkey);
    Ent *p = v->first;
    Ent *end = v->last;
    if (p != end) {
        Ent *e;
        u32 val;
        do {
            if (p->key == h) break;
            p++;
        } while (p != end);
        if (p != v->last) {
            e = end - 1;
            val = p->val;
            if (p != e) *p = *e;
            v->last = v->last - 1;
            {
                u32 k2 = ts4_crc32_cstr_seed_88608590(0, *newkey);
                fn_8825C638(v, k2, val);
            }
        }
    }
}

/* ---- small allocated object ---- */
extern void *ts4_call_seq_u32_off0_8821FC18(void *p);

/* 0x882338B0: allocate a 0x10-byte object, register a zeroed allocator slot and finish construction */
void *ts4_create_obj10_882338B0(void)
{
    void *result = 0;
    u32 z = (u32)(Cx22Up)result;
    u32 ctx = z;
    void *obj;
    if (lbl_88D45AD4) ctx = *(u32 *)((char *)lbl_88D45AD4 + 0x15680);
    obj = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x10, 4, ctx, 2);
    if (obj) {
        u32 tmp = z;
        ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
        result = ts4_call_seq_u32_off0_8821FC18(obj);
    }
    return result;
}
