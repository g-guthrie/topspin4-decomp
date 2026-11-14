/* Swing_DLL.xex 0x88189D98-0x88444778, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ts4RcCounted {
    virtual void *destroy(int flags);
    unsigned short live;
    short refs;
};
struct Ts4RcAlloc {
    virtual void *alloc(int size, void *p, int tag);
    virtual void release(void *p);
};
struct Ts4RcHolderU { void *vt; char pad4[2]; short refs; Ts4RcCounted *ref; u32 block; };
struct Ts4RcPtrVec { void *vt; char pad4[2]; short refs; int f8; int fc; Ts4RcCounted **data; int count; };
struct Ts4RcVecA { void *vt; char pad4[0x10]; void *vt14; char pad18[0x2c]; Ts4RcCounted **data; int count; int cap; };
struct Ts4RcElem16 { Ts4RcCounted *ref; int a, b, c; };
struct Ts4RcVecB { void *vt; char pad4[0xc]; void *vt10; char pad14[4]; Ts4RcElem16 *data; int count; int cap; };
struct Ts4RcPair { void *vt; char pad4[0xc]; void *vt10; char pad14[4]; Ts4RcCounted *ref18; Ts4RcCounted *ref1c; };
struct Ts4RcSub { void *vt; };
struct Ts4RcListenerVec { void *vt; char pad4[4]; Ts4RcSub sub; char padc[4]; Ts4RcCounted **data; int count; int cap; };
extern "C" {
extern u32 lbl_88CACF08;
extern Ts4RcCounted *lbl_88CAD33C;
extern char lbl_8803DA00[], lbl_8803A308[], lbl_8808019C[], lbl_88080174[], lbl_8807FF50[], lbl_88081CB4[], lbl_88081C90[];
extern char lbl_8808029C[], lbl_88080278[], lbl_8803BC7C[], lbl_8803BC70[], lbl_8803BC48[];
void fn_88408B18(Ts4RcCounted *r, Ts4RcSub *s);
void *KeTlsGetValue(u32 index);
void fn_8841A590(void *allocator, void *p, u32 size, int kind);

void ts4_set_global_counted_88189D98(Ts4RcCounted *n)
{
    Ts4RcCounted *o = lbl_88CAD33C;
    if (o != 0 && o->live != 0) {
        if (--o->refs == 0)
            o->destroy(1);
    }
    lbl_88CAD33C = n;
}

void ts4_destroy_counted_holder_8841B360(Ts4RcHolderU *o)
{
    Ts4RcCounted *r = o->ref;
    u32 c;
    o->vt = lbl_8803DA00;
    if (r->live != 0) {
        if (--r->refs == 0)
            r->destroy(1);
    }
    c = o->block;
    ((Ts4RcAlloc *)KeTlsGetValue(lbl_88CACF08))->release((void *)c);
    o->vt = lbl_8803A308;
}

void ts4_release_all_884418D0(Ts4RcPtrVec *o)
{
    int i;
    int n = o->count;
    Ts4RcCounted **d;
    void *al;
    for (i = 0; i < n; i++) {
        Ts4RcCounted *r = o->data[i];
        if (r->live != 0) {
            if (--r->refs == 0)
                r->destroy(1);
        }
        n = o->count;
    }
    d = o->data;
    al = KeTlsGetValue(lbl_88CACF08);
    fn_8841A590(al, d, n * 4, 0x27);
}

void ts4_destroy_ref_vector_8843C100(Ts4RcVecA *o)
{
    int i;
    int c;
    void *a;
    o->vt = lbl_8808019C;
    o->vt14 = lbl_88080174;
    for (i = 0; i < o->count; i++) {
        Ts4RcCounted *r = o->data[i];
        if (r->live != 0) {
            if (--r->refs == 0)
                r->destroy(1);
        }
    }
    c = o->cap;
    if ((c & (1 << 31)) == 0) {
        a = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(a, o->data, c * 4, 0x17);
    }
    o->vt14 = lbl_8807FF50;
    o->vt = lbl_8803A308;
}

void ts4_destroy_ref_vector16_88444778(Ts4RcVecB *o)
{
    int i;
    int c;
    void *a;
    o->vt = lbl_88081CB4;
    o->vt10 = lbl_88081C90;
    for (i = 0; i < o->count; i++) {
        Ts4RcCounted *r = o->data[i].ref;
        if (r->live != 0) {
            if (--r->refs == 0)
                r->destroy(1);
        }
    }
    c = o->cap;
    if ((c & (1 << 31)) == 0) {
        a = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(a, o->data, c * 16, 0x17);
    }
    o->vt10 = lbl_8807FF50;
    o->vt = lbl_8803A308;
}

void ts4_destroy_listener_vec_88406148(Ts4RcListenerVec *o)
{
    int i;
    int c;
    void *a;
    o->vt = lbl_8803BC7C;
    o->sub.vt = lbl_8803BC70;
    for (i = 0; i < o->count; i++) {
        Ts4RcCounted *r;
        fn_88408B18(o->data[i], &o->sub);
        r = o->data[i];
        if (r->live != 0) {
            if (--r->refs == 0)
                r->destroy(1);
        }
    }
    c = o->cap;
    if ((c & (1 << 31)) == 0) {
        a = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(a, o->data, c * 4, 0x17);
    }
    o->sub.vt = lbl_8803BC48;
    o->vt = lbl_8803A308;
}
}
