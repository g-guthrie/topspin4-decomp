/* 0x883E8598: returns 0x25 for null args, writes 0 when +0x44 is clear, 0x38 when the impl at +0x48 is missing or not ready
   (state 0, or 6 with +0x38 clear), else forwards through the arg's vtable slot 0x5C. Matched plain /O1 (agT). */
typedef unsigned long ts4_word;
ts4_word ts4_if_get_fn_8832BFC0_88316BB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3);
typedef struct Obj Obj;
typedef struct ObjVt { char pad[0x5c]; int (*f5c)(Obj *self, void *impl, int *out); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct T { char pad[0x38]; void *f38; char pad2[8]; unsigned f44; void *impl; } T;
int ts4_forward_if_impl_ready_883E8598(T *t, Obj *a, int *out)
{
    int v;
    int r;
    unsigned char ok;
    if (!a || !out)
        return 0x25;
    if (!t->f44) {
        *out = 0;
        return 0;
    }
    if (!t->impl)
        return 0x38;
    r = (int)ts4_if_get_fn_8832BFC0_88316BB0((ts4_word)t->impl, (ts4_word)&v, 0, 0);
    if (r)
        return r;
    ok = (v == 0 || (!t->f38 && v == 6));
    if (!ok)
        return 0x38;
    return a->vt->f5c(a, t->impl, out);
}
