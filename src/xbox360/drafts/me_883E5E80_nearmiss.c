#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
typedef struct T { char pad[0xc]; void *impl; char pad2[8]; u64 pos; u64 end; u64 f28; int mode; } T;
int fn_883E5AA0(void *impl, u64 at, u64 from, u64 to);
static void adj(u64 *v, u64 at, u64 d)
{
    *v = *v - at + d;
}
int fn_883E5E80(T *t, u64 at, u64 from, u64 to)
{
    int r;
    u64 d;
    if (from > to)
        return 0x21;
    if (t->mode == 2 || t->mode == 3) {
        r = fn_883E5AA0(t->impl, at, from, to);
        if (r)
            return r;
        d = to - from;
        adj(&t->pos, at, d);
        adj(&t->end, at, d);
    }
    return 0;
}
