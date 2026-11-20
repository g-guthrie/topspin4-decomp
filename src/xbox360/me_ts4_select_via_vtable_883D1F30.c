/* 0x883D1F30: calls vtable slot 0x34(a, 0), then slot 0x2C(a, b) when flag 0x20 at +0x80AC is set, and on success stores a at +0x3C */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct T T;
typedef struct TVt {
    char pad[0x2c];
    int (*f2c)(T *t, void *a, void *b);
    char pad2[4];
    int (*f34)(T *t, void *a, void *b);
} TVt;
struct T { TVt *vt; char pad[0x38]; void *cur; char pad2[0x80ac - 0x40]; unsigned int flags; };
int ts4_select_via_vtable_883D1F30(T *t, void *a, void *b)
{
    int r = t->vt->f34(t, a, 0);
    if (r)
        return r;
    if (t->flags & 0x20) {
        r = t->vt->f2c(t, a, b);
        if (r)
            return r;
    }
    t->cur = a;
    return 0;
}
