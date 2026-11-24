/* HS2 hand-decompiled functions, group E (Swing_DLL.xex 0x884Axxxx-0x886xxxxx). */

typedef struct Hs2Sub {
    void **vtbl;
} Hs2Sub;

typedef struct Hs2Src {
    char pad[0x6c];
    int *items;
    int count;
} Hs2Src;

typedef struct Hs2Holder {
    char pad[0x18];
    Hs2Sub sub;
    Hs2Src *src;
} Hs2Holder;

#define HS2_NOTIFY_EACH_ITEM(h) \
    do { \
        Hs2Src *s = (h)->src; \
        if (s) { \
            int i = 0; \
            if (s->count > 0) { \
                do { \
                    ((void (*)(Hs2Sub *, int))(h)->sub.vtbl[1])(&(h)->sub, s->items[i]); \
                    s = (h)->src; \
                    i++; \
                } while (i < s->count); \
            } \
        } \
    } while (0)

/* Calls sub.vtbl[1](item) for every entry of the source's item list (re-reading the source after each call). */
void ts4_notify_each_item_884A9418(Hs2Holder *h)
{
    HS2_NOTIFY_EACH_ITEM(h);
}

/* Same body as ts4_notify_each_item_884A9418. */
void ts4_notify_each_item_884A99B0(Hs2Holder *h)
{
    HS2_NOTIFY_EACH_ITEM(h);
}

/* Same body as ts4_notify_each_item_884A9418. */
void ts4_notify_each_item_884A9CE8(Hs2Holder *h)
{
    HS2_NOTIFY_EACH_ITEM(h);
}

/* ---- reference list append ---- */

typedef struct Hs2PtrVec {
    void **data;
    int size;
    int cap; /* low 30 bits = capacity */
} Hs2PtrVec;

void fn_8841C678(Hs2PtrVec *vec, int grow_by);
int ts4_if_get_u16_off4_88475AE8(void *obj);

#define HS2_LIST_ADD_REF(vecfield, p) \
    do { \
        if (p) { \
            Hs2PtrVec *v; \
            ts4_if_get_u16_off4_88475AE8(p); \
            v = &(vecfield); \
            if (v->size == (v->cap & 0x3fffffff)) \
                fn_8841C678(v, 4); \
            v->data[v->size] = (p); \
            v->size++; \
        } \
    } while (0)

typedef struct Hs2RefListA {
    char pad[8];
    Hs2PtrVec vec;
} Hs2RefListA;

/* Takes a reference on p (when non-null) and appends it to the list's pointer vector. */
void ts4_list_add_ref_8847ED38(Hs2RefListA *l, void *p)
{
    HS2_LIST_ADD_REF(l->vec, p);
}

typedef struct Hs2RefListB {
    char pad[0x2c];
    Hs2PtrVec vec;
} Hs2RefListB;

/* Same as ts4_list_add_ref_8847ED38 for a list whose vector sits at +0x2c. */
void ts4_list_add_ref_8847EDC0(Hs2RefListB *l, void *p)
{
    HS2_LIST_ADD_REF(l->vec, p);
}

typedef struct Hs2PtrVecHolder {
    char pad[0x1c];
    Hs2PtrVec vec;
} Hs2PtrVecHolder;

typedef struct Hs2PtrVecOwner {
    char pad[8];
    Hs2PtrVecHolder *holder;
} Hs2PtrVecOwner;

/* Appends p to the pointer vector of the owner's holder object. */
void ts4_owner_push_ptr_884CC400(Hs2PtrVecOwner *o, void *p)
{
    Hs2PtrVec *v = &o->holder->vec;
    if (v->size == (v->cap & 0x3fffffff))
        fn_8841C678(v, 4);
    v->data[v->size] = p;
    v->size++;
}
