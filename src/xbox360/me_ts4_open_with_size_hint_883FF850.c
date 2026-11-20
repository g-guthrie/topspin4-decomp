/* 0x883FF850: 0x21 for a null sink; calls sink slot 0xC(a, t, *src or 0), then, when the info mask hits lbl_88039738 or lbl_8803973C, raises the target to info+8 (ts4_set_u64_at_least_min_883E5F90) and returns fn_883E6618(t->f0, info+8) */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
#ifdef _MSC_VER
typedef unsigned __int64 u64;
#else
typedef unsigned long long u64;
#endif
typedef struct Info { unsigned int mask; int f4; u64 size; } Info;
typedef struct Sink Sink;
typedef struct SinkVt { char pad[0xc]; int (*f0c)(Sink *s, void *a, void *t, void *x); } SinkVt;
struct Sink { SinkVt *vt; };
typedef struct T { void *f0; } T;
extern unsigned int lbl_88039738;
extern unsigned int lbl_8803973C;
int ts4_set_u64_at_least_min_883E5F90(void *x, u64 v);
int fn_883E6618(void *p, u64 v);
static unsigned char wants_size(const Info *i)
{
    return (i->mask & lbl_88039738) || (i->mask & lbl_8803973C);
}
int ts4_open_with_size_hint_883FF850(T *t, void *a, void **src, Info *info, Sink *s)
{
    void *x;
    int r;
    if (!s)
        return 0x21;
    x = src ? *src : 0;
    r = s->vt->f0c(s, a, t, x);
    if (r)
        return r;
    if (x && wants_size(info))
        ts4_set_u64_at_least_min_883E5F90(x, info->size);
    return fn_883E6618(t->f0, info->size);
}
