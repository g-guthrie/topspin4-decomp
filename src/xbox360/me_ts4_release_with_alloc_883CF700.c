/* 0x883CF700: drops a reference on +0x14 (releasing it through 883CF548 at zero), frees +0x34, then frees itself through the allocator or the global heap unless owned by a live source. 883CF548 is declared (Ref *, Alloc *) here; its asm2c body elsewhere declares 8 untyped words */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_880390E4[];
typedef struct Alloc Alloc;
typedef struct AllocVt { void *f0, *f1; void (*free)(Alloc *a, void *p, const char *file, int line); } AllocVt;
struct Alloc { AllocVt *vt; };
typedef struct Ref { char pad[8]; int refs; } Ref;
typedef struct Sys { char pad[0x20]; void *src; } Sys;
typedef struct Own { char pad[0xac]; Sys *sys; } Own;
typedef struct T { char pad0[0x14]; Ref *ref; char pad1[0x34 - 0x18]; void *buf; Own *own; } T;

void fn_88315F10(void *heap, void *buf, const char *file, int line);
int ts4_if_get_u32_off20_883CF548(Ref *r, Alloc *a);

int fn_883CF700(T *t, Alloc *a)
{
    if (t->ref) {
        t->ref->refs--;
        if (t->ref->refs == 0) {
            int r = ts4_if_get_u32_off20_883CF548(t->ref, a);
            if (r)
                return r;
        }
    }
    if (t->buf)
        fn_88315F10(lbl_88B3302C->heap, t->buf, lbl_880390E4, 0x5c);
    if (!t->own || !(t->own->sys ? t->own->sys->src : 0)) {
        if (a)
            a->vt->free(a, t, lbl_880390E4, 0x63);
        else
            fn_88315F10(lbl_88B3302C->heap, t, lbl_880390E4, 0x63);
    }
    return 0;
}
