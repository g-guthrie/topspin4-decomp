/* Swing_DLL.xex 0x884A1EA0-0x884A1EA0, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ts4RcCounted {
    virtual void *destroy(int flags);
    unsigned short live;
    short refs;
};
struct Ts4RcVecC { void *vt; char pad4[4]; Ts4RcCounted **data; int count; int cap; };
extern "C" {
extern u32 lbl_88CACF08;
extern char lbl_88088180[], lbl_8803A308[];
void *KeTlsGetValue(u32 index);
void fn_8841A590(void *allocator, void *p, u32 size, int kind);
void ts4_destroy_ref_vector_884A1EA0(Ts4RcVecC *o)
{
    int i;
    int c;
    void *a;
    o->vt = lbl_88088180;
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
    o->vt = lbl_8803A308;
}
}
