/* 0x883EC148: reads a "lnkd" chunk: two words, a flag mask (masked by lbl_8803973C|38|40) when version >= 0x3B0000, then a "cond" chunk into a ref (vtable lbl_880398A0) through 883E78C0, builds the entry (883E7E08) and registers it in the bank at +0x18 (883E4EC8); releases the ref (slot 7). 0x21 on a wrong chunk id. */
/* Near miss (agAB, /O1): 4 off, the two ref init stores (p=0 at +0x70, vt at +0x68) are scheduled before the first
 * read call's li r7/li r5, the target puts each after one. Store order, a pointer local, an init helper, /Os, a C++ ctor
 * (with or without dtor) all tried; the C++ dtor form adds release calls on every path. */
typedef struct Hdr { unsigned int magic; unsigned int value; } Hdr;
typedef struct Obj Obj;
typedef struct ObjVt { void *f[7]; void (*release)(Obj *o); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct Ref { const void *vt; int pad; Obj *p; } Ref;
typedef struct T { char pad[0x18]; void *bank; } T;
extern char lbl_880398A0[];
extern unsigned int lbl_88039738, lbl_8803973C, lbl_88039740;
int fn_883E7828(Hdr *h, void *stream, unsigned int version);
int fn_883194F0(void *stream, void *dst, unsigned int size, unsigned int count, int a);
int fn_883E78C0(Ref *ref, Hdr *h, void *stream, unsigned int version);
void ts4_call_seq_u32_off4_883E7E08(void *out, unsigned int a, unsigned int b, Ref *ref, unsigned int *flags);
void fn_883E4EC8(void *bank, unsigned int *key, void *out);

int fn_883EC148(T *t, void *out, int unused, void *stream, unsigned int version)
{
    Hdr h;
    Ref ref;
    unsigned int a, b, flags;
    int r;
    r = fn_883E7828(&h, stream, version);
    if (r)
        return r;
    if (h.value != 0x646b6e6c)
        return 0x21;
    ref.p = 0;
    ref.vt = lbl_880398A0;
    flags = lbl_88039740;
    r = fn_883194F0(stream, &a, 4, 1, 0);
    if (r)
        return r;
    r = fn_883194F0(stream, &b, 4, 1, 0);
    if (r)
        return r;
    if (version >= 0x3b0000) {
        r = fn_883194F0(stream, &flags, 4, 1, 0);
        if (r)
            return r;
        flags &= lbl_8803973C | lbl_88039738 | lbl_88039740;
    }
    r = fn_883E7828(&h, stream, version);
    if (r)
        return r;
    if (h.value != 0x646e6f63)
        return 0x21;
    r = fn_883E78C0(&ref, &h, stream, version);
    if (r) {
        if (ref.p)
            ref.p->vt->release(ref.p);
        return r;
    }
    ts4_call_seq_u32_off4_883E7E08(out, a, b, &ref, &flags);
    fn_883E4EC8(t->bank, &a, out);
    if (ref.p)
        ref.p->vt->release(ref.p);
    return 0;
}
