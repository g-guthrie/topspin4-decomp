/* Swing_DLL.xex 0x88476CB0-0x88476CB0, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ts4RcCounted {
    virtual void *destroy(int flags);
    unsigned short live;
    short refs;
};
struct Ts4RcBlock { unsigned short tag; char pad2[0xe]; unsigned short size; char pad12[2]; Ts4RcBlock *next; };
struct Ts4RcLinkObj { void *vt; char pad4[8]; Ts4RcCounted *ref; Ts4RcBlock *blocks; void *a; void *b; };
extern "C" {
extern u32 lbl_88CACF08;
extern char lbl_8808384C[], lbl_8803A308[];
void *KeTlsGetValue(u32 index);
void fn_8841A590(void *allocator, void *p, u32 size, int kind);
void ts4_counted_ref_release_88475B08(void *p);
void ts4_destroy_link_obj_88476CB0(Ts4RcLinkObj *o)
{
    Ts4RcBlock *blk;
    Ts4RcBlock *cur;
    void *a;
    Ts4RcCounted *r;
    o->vt = lbl_8808384C;
    if (o->a != 0)
        ts4_counted_ref_release_88475B08(o->a);
    if (o->b != 0)
        ts4_counted_ref_release_88475B08(o->b);
    blk = o->blocks;
    if (blk != 0) {
        while (blk->tag >= 0x17) {
            cur = blk;
            blk = blk->next;
            a = KeTlsGetValue(lbl_88CACF08);
            fn_8841A590(a, cur, cur->size, 0x2c);
        }
    }
    r = o->ref;
    if (r != 0 && r->live != 0) {
        if (--r->refs == 0)
            r->destroy(1);
    }
    o->vt = lbl_8803A308;
}
}
