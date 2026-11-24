/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8847AF38: destructor that releases every counted ref of the array at +0x2c (count +0x30, re-read each pass), drops
 * the shared object at +0x38, frees the buffer unless cap (+0x34) has the top bit set, then chains to
 * ts4_destroy_link_obj_88476CB0.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_8847AF38_nearmiss.c (Q5S sweep, 2026-11-24): the alias local(s) of the parameter change which symbol the indexed access goes through (regalloc.md C1/R2).
 * See work/specs/Q5S/sweep_8847AF38.json for route and flags. */
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
void ts4_ref_array_dtor_8847AF38(Obj *self)
{ Obj* obj = self; 
    int i;
    int cap;
    Shared *s;
    obj->vtbl = lbl_8808386C;
    for (i = 0; i < obj->count; i++) {
        void **it = obj->items;
        ts4_counted_ref_release_88475B08(it[i]);
    }
    s = obj->shared;
    if (s->live != 0) {
        if (--s->refs == 0)
            s->vt->destroy(s, 1);
    }
    cap = obj->cap;
    if ((cap & (int)0x80000000) == 0) {
        void *alloc = KeTlsGetValue(lbl_88CACF08);
        { void ** buf = obj->items; fn_8841A590(alloc, buf, cap << 2, 0x17); }
    }
    ts4_destroy_link_obj_88476CB0(obj);
}
