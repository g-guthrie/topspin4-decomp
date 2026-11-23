/* Swing_DLL.xex 0x8816C2F0: destructor body: release the handle at +0x8C, free three member vectors, destroy two text vectors (8815BB30 + free) and two buffer slots (registry release + free) in reverse, free four more vectors, then the base part (88158648).
 * /Oc. Registry release is an inline taking the registry as a parameter (gives the clrrwi copy); reverse array destroys use the (first, count) inline. */
typedef struct Ts4Registry { char p[0x24]; void *fallback; } Ts4Registry;
extern Ts4Registry *lbl_88D45B38;
typedef struct Vec { unsigned int *first; unsigned int *last; unsigned int *end; } Vec;
typedef struct Text { char *p; char *last; char *end; } Text;
typedef struct TextVec { Text *first; Text *last; Text *end; } TextVec;
typedef struct BufSlot { void *buf; Vec items; unsigned int a; unsigned int b; } BufSlot;
typedef struct Big {
    char p0[0x7c];
    Vec v7c; char p1[0x8c - 0x88];
    void *handle; char p1b[0x9c - 0x90];
    Vec v9c; char p2[0xb0 - 0xa8];
    Vec vb0; char p3[0xc4 - 0xbc];
    Vec vc4; char p4[0x2d4 - 0xd0];
    BufSlot bufs[2]; char p4b[0x308 - 0x304];
    TextVec names[2]; char p5a[0x328 - 0x320];
    Vec v328; char p5[0x33c - 0x334];
    Vec v33c; char p6[0x350 - 0x348];
    Vec v350;
} Big;
void ts4_destroy_owned_object(void *obj);
void ts4_registry_dispatch_888860A0(void *p);
void ts4_buf3_destroy_range_8815BB30(Text *first, Text *last);
void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
void ts4_node_visit_8860DBC8(void *entry, void *key);
void ts4_if_call_seq_u32_off0_88158648(void *p);

static __inline void vec_free(Vec *v)
{
    if (v->first) ts4_destroy_owned_object(v->first);
}

static __inline void release(Ts4Registry *registry, void *key)
{
    void *entry;
    if (key == 0)
        return;
    entry = ts4_find_range_owner_8860D360(registry, key);
    if (entry != 0)
        ts4_node_visit_8860DBC8(entry, key);
    else
        ts4_node_visit_8860DBC8(registry->fallback, key);
}

static __inline void text_vecs_destroy_n(TextVec *first, int count)
{
    TextVec *p = first + count;
    while (--count >= 0) {
        --p;
        ts4_buf3_destroy_range_8815BB30(p->first, p->last);
        if (p->first) ts4_destroy_owned_object(p->first);
    }
}

static __inline void buf_slots_destroy_n(BufSlot *first, int count)
{
    BufSlot *p = first + count;
    while (--count >= 0) {
        --p;
        release(lbl_88D45B38, p->buf);
        vec_free(&p->items);
    }
}

void fn_8816C2F0(Big *b)
{
    ts4_registry_dispatch_888860A0(b->handle);
    vec_free(&b->v350);
    vec_free(&b->v33c);
    vec_free(&b->v328);
    text_vecs_destroy_n(b->names, 2);
    buf_slots_destroy_n(b->bufs, 2);
    vec_free(&b->vc4);
    vec_free(&b->vb0);
    vec_free(&b->v9c);
    vec_free(&b->v7c);
    ts4_if_call_seq_u32_off0_88158648(b);
}
