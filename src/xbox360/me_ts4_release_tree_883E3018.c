/* 0x883E3018: stops the node (883E2C90), drops its def reference when deep (883E2B30 at zero, declared (Ref *, Alloc *) here; its asm2c body elsewhere takes 8 words), releases every child recursively, frees +0x44 and frees itself through the allocator or the global heap unless owned by a live source */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_880395AC[];
typedef struct Alloc Alloc;
typedef struct AllocVt { void *f0, *f1; void (*free)(Alloc *a, void *p, const char *file, int line); } AllocVt;
struct Alloc { AllocVt *vt; };
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Ref { char pad[8]; int refs; } Ref;
typedef struct Sys { char pad[0x20]; void *src; } Sys;
typedef struct Own { char pad[0xac]; Sys *sys; } Own;
typedef struct T {
    int vt;
    Link link;
    char pad0[0x14 - 0xc];
    Ref *ref;
    char pad1[0x20 - 0x18];
    Own *own;
    char pad2[0x44 - 0x24];
    void *buf;
    char pad3[0x78 - 0x48];
    Link kids;
} T;

void fn_88315F10(void *heap, void *buf, const char *file, int line);
int ts4_stop_current_883E2C90(T *t);
int ts4_if_get_u32_off10_883E2B30(Ref *r, Alloc *a);

int fn_883E3018(T *t, Alloc *a, unsigned char deep)
{
    Link *n, *next;
    int r;
    r = ts4_stop_current_883E2C90(t);
    if (r)
        return r;
    if (t->ref && deep) {
        t->ref->refs--;
        if (t->ref->refs == 0) {
            r = ts4_if_get_u32_off10_883E2B30(t->ref, a);
            if (r)
                return r;
        }
    }
    for (n = t->kids.next; n != &t->kids; n = next) {
        next = n->next;
        r = fn_883E3018((T *)((char *)n - 4), a, deep);
        if (r)
            return r;
    }
    if (t->buf)
        fn_88315F10(lbl_88B3302C->heap, t->buf, lbl_880395AC, 0x68);
    if (!(t->own->sys ? t->own->sys->src : 0)) {
        if (a)
            a->vt->free(a, t, lbl_880395AC, 0x6f);
        else
            fn_88315F10(lbl_88B3302C->heap, t, lbl_880395AC, 0x6f);
    }
    return 0;
}
