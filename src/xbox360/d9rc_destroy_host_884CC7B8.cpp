/* Swing_DLL.xex 0x884CC7B8-0x884CC7B8, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ts4RcCounted {
    virtual void *destroy(int flags);
    unsigned short live;
    short refs;
};
struct Ts4RcArr8 { void *data; int count; int cap; };
struct Ts4RcHost { void *vt; char pad4[4]; Ts4RcCounted *ref; Ts4RcArr8 arr; char sub18[0x10]; char sub28[4]; };
extern "C" {
extern u32 lbl_88CACF08;
extern char lbl_8808C24C[], lbl_8803A308[];
void *KeTlsGetValue(u32 index);
void fn_8841A590(void *allocator, void *p, u32 size, int kind);
void fn_88423D60(void *p);
void ts4_destroy_host_884CC7B8(Ts4RcHost *o)
{
    Ts4RcCounted *r = o->ref;
    Ts4RcArr8 *arr;
    int c;
    void *a;
    o->vt = lbl_8808C24C;
    if (r->live != 0) {
        if (--r->refs == 0)
            r->destroy(1);
    }
    fn_88423D60(o->sub28);
    arr = &o->arr;
    fn_88423D60((char *)arr + 0xc);
    c = arr->cap;
    if ((c & (1 << 31)) == 0) {
        a = KeTlsGetValue(lbl_88CACF08);
        fn_8841A590(a, arr->data, c * 8, 0x17);
    }
    o->vt = lbl_8803A308;
}
}
