/* 0x8847AF38: destructor that releases every counted ref of the array at +0x2c (count +0x30, re-read each pass), drops the shared object at +0x38, frees the buffer unless cap (+0x34) has the top bit set, then chains to ts4_destroy_link_obj_88476CB0. */
/* Near miss (agAB, /Oc): 1 off, lwzx r3,r11,r30 (base first) where the target has r30,r11. Without the vtable store
 * the loop-body local gives index-first; with it, the local, chain, element local, wrapper, embedded list struct,
 * hoisted count and /O1 /Os /O2 all stay base-first. */
extern char lbl_8808386C[];
extern unsigned int lbl_88CACF08;
void *KeTlsGetValue(unsigned int index);
void fn_8841A590(void *allocator, void *object, unsigned int size, int kind);
void ts4_counted_ref_release_88475B08(void *r);
void ts4_destroy_link_obj_88476CB0(void *self);
typedef struct Shared Shared;
typedef struct SharedVt { void (*destroy)(Shared *s, int flags); } SharedVt;
struct Shared { SharedVt *vt; unsigned short live; short refs; };
typedef struct Obj {
    void *vtbl;
    char pad[0x2c - 4];
    void **items;
    int count;
    int cap;
    Shared *shared;
} Obj;
void fn_8847AF38(Obj *self)
{
    int i;
    int cap;
    Shared *s;
    self->vtbl = lbl_8808386C;
    for (i = 0; i < self->count; i++) {
        void **it = self->items;
        ts4_counted_ref_release_88475B08(it[i]);
    }
    s = self->shared;
    if (s->live != 0) {
        if (--s->refs == 0)
            s->vt->destroy(s, 1);
    }
    cap = self->cap;
    if ((cap & (int)0x80000000) == 0) {
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(alloc, self->items, cap << 2, 0x17);
    }
    ts4_destroy_link_obj_88476CB0(self);
}
