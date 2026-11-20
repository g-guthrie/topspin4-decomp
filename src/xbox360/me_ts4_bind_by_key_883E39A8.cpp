/* 0x883E39A8: once: asks the owner's key object (+0x20, virtual slot 4) for its key, finds the matching node in the registry from ts4_get_u32_lbl_88CAC9A8_883E63A0, binds the owner to id +0xC and to the node's entry for that id, then sets the done byte at +5 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); C++ virtual calls (the target loads the method before the arguments); returns 0x5F without an owner, 0x21 when no node. */
struct K { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual int key(); };
struct F { virtual void v0(); virtual void v1(); virtual void v2(); virtual void *find(int key); };
struct Own { char pad[0x20]; K k; };
struct T { char p0[5]; unsigned char done; char p6[2]; Own *own; int id; int out; };
extern "C" F *ts4_get_u32_lbl_88CAC9A8_883E63A0(void);
extern "C" int ts4_tailcall_fn_883FBA90_883FBFA8(Own *o, int id);
extern "C" int ts4_tailcall_fn_883FC9E8_883FCD98(Own *o, void *x, int *out);
extern "C" int ts4_bind_by_key_883E39A8(T *t)
{
    int key, r;
    F *o;
    void *x;
    if (!t->done) {
        if (!t->own) return 0x5f;
        key = t->own->k.key();
        o = (F *)ts4_get_u32_lbl_88CAC9A8_883E63A0()->find(key);
        if (!o) return 0x21;
        r = ts4_tailcall_fn_883FBA90_883FBFA8(t->own, t->id);
        if (r) return r;
        x = o->find(t->id);
        if (x) {
            r = ts4_tailcall_fn_883FC9E8_883FCD98(t->own, x, &t->out);
            if (r) return r;
        }
        t->done = 1;
    }
    return 0;
}
