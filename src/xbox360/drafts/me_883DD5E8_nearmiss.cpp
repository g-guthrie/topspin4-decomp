/* 0x883DD5E8: unless flag 0x400 or no stream: detaches (883DD108), then for each listed id whose used slot is 0 finds the item through the stream's source, clears its owner, removes and releases it; when no slot is used anymore, closes the stream and frees the used table. 0x21 when ids is given without a table. */
/* Near miss (agAB, /O1 C++): 1 off. The first `if (r) return r;` (after ts4_if_set_u32_off0_8832BFC0) branches to the
 * epilogue where the target branches to the `b` after `li r3,0x21`. goto/fail label, nested else, split 0x21 test, /Os, /Oy- tried.
 * The virtual-member form is needed for the vtable-before-*ids load order of the remove call. */
typedef struct Mgr { int p0; void *heap; } Mgr;
extern Mgr *lbl_88B3302C;
extern char lbl_88039468[];
struct Item { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual int release(int a); char pad[0x44 - 4]; int owner; };
struct Src { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9();
 virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18();
 virtual int remove(int id, int a); virtual int find(int id, Item **out); };
typedef struct T {
    char pad0[0x18];
    unsigned int flags;
    char pad1[0x28 - 0x1c];
    void *stream;
    char pad2[0x4c - 0x2c];
    int *used;
} T;
extern "C" void fn_88315F10(void *heap, void *buf, const char *file, int line);
extern "C" void fn_883DD108(T **t, int a);
extern "C" int ts4_if_set_u32_off0_8832BFC0(void *stream, Src **out);
extern "C" int ts4_if_get_fn_8832BFC0_88316B30(void *stream, int *out);
extern "C" int ts4_if_get_fn_8832BFC0_88317EC0(void *stream);

extern "C" int fn_883DD5E8(T *t, int *ids, int n)
{
    int i, r, cnt;
    Src *src;
    if (t->flags & 0x400)
        return 0;
    if (!t->stream)
        return 0;
    {
        T *self = t;
        fn_883DD108(&self, 1);
    }
    if (ids) {
        if (!t->used)
            return 0x21;
        for (i = 0; i < n; i++, ids++) {
            if (t->used[*ids] == 0) {
                Item *it;
                r = ts4_if_set_u32_off0_8832BFC0(t->stream, &src);
                if (r)
                    return r;
                r = src->find(*ids, &it);
                if (r)
                    return r;
                if (it) {
                    it->owner = 0;
                    r = src->remove(*ids, 0);
                    if (r)
                        return r;
                    r = it->release(1);
                    if (r)
                        return r;
                }
            }
        }
    }
    r = ts4_if_get_fn_8832BFC0_88316B30(t->stream, &cnt);
    if (r)
        return r;
    i = 0;
    if (cnt > 0) {
        int *p = t->used;
        for (; i < cnt; i++, p++)
            if (*p)
                break;
    }
    if (i == cnt) {
        void *s = t->stream;
        t->stream = 0;
        r = ts4_if_get_fn_8832BFC0_88317EC0(s);
        if (r)
            return r;
        if (t->used)
            fn_88315F10(lbl_88B3302C->heap, t->used, lbl_88039468, 0x47b);
        t->used = 0;
    }
    return 0;
}
