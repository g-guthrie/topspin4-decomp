/* 0x883DE028: destroys a stream object: detaches it (883DD108 on a pointer to self), frees name, closes the stream unless flag 0x400, frees the data through the allocator or heap, the two buffers and +0x54, then 883DDEB0(t, -1, 1) and optionally frees itself */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_88039468[];
typedef struct Alloc Alloc;
typedef struct AllocVt { void *f0, *f1; void (*free)(Alloc *a, void *p, const char *file, int line); } AllocVt;
struct Alloc { AllocVt *vt; };
typedef struct T {
    char pad0[0x18];
    unsigned int flags;
    void *data;
    void *bufs[2];
    void *stream;
    char pad1[0x4c - 0x2c];
    void *name;
    char pad2[0x54 - 0x50];
    void *extra;
} T;
void fn_88315F10(void *heap, void *buf, const char *file, int line);
void fn_883DD108(T **t, int a);
int ts4_if_get_fn_8832BFC0_88317EC0(void *res);
int fn_883DDEB0(T *t, int a, int b);

int fn_883DE028(T *t, Alloc *a, unsigned char free_self)
{
    T *self = t;
    int i, r;
    fn_883DD108(&self, 1);
    if (t->name)
        fn_88315F10(lbl_88B3302C->heap, t->name, lbl_88039468, 0x14d);
    if (t->stream) {
        if (!(t->flags & 0x400))
            ts4_if_get_fn_8832BFC0_88317EC0(t->stream);
        t->stream = 0;
    }
    if (t->data) {
        if (a)
            a->vt->free(a, t->data, lbl_88039468, 0x15b);
        else
            fn_88315F10(lbl_88B3302C->heap, t->data, lbl_88039468, 0x15b);
    }
    for (i = 0; i < 2; i++)
        if (t->bufs[i])
            fn_88315F10(lbl_88B3302C->heap, t->bufs[i], lbl_88039468, 0x162);
    if (t->extra)
        fn_88315F10(lbl_88B3302C->heap, t->extra, lbl_88039468, 0x168);
    r = fn_883DDEB0(t, -1, 1);
    if (r)
        return r;
    if (free_self)
        fn_88315F10(lbl_88B3302C->heap, t, lbl_88039468, 0x173);
    return 0;
}
