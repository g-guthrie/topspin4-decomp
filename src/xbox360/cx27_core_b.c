/* CX27 part b: game core 0x8820F390-0x88220C18, plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX27_INL static __forceinline
#else
#define CX27_INL static inline
#endif

/* ---- object with one allocator-backed vector ---- */
extern void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(u32 *p);
typedef struct Cx27AVec { u32 begin, end, ctx, cap; } Cx27AVec;
typedef struct Cx27Pool { u32 f0, f4, f8; Cx27AVec v; } Cx27Pool;

CX27_INL void cx27_avec_init(Cx27AVec *v, u32 z)
{
    u32 tmp = z;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
    v->begin = z;
    v->end = z;
    v->ctx = z;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&v->ctx);
    v->cap = z;
}

/* 0x8821B500: reset to empty with a 0xFFFFF limit and an empty allocator-backed vector */
Cx27Pool *ts4_pool_init_8821B500(Cx27Pool *s)
{
    u32 z = 0;
    s->f0 = z;
    s->f8 = z;
    s->f4 = 0xFFFFFu;
    cx27_avec_init(&s->v, z);
    return s;
}
