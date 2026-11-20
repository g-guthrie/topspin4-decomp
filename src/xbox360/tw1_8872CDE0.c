/* Swing_DLL.xex 0x8872CDE0: constructor, avec at +0x80 (twin ts4_ctor_avec_88724548) */
typedef unsigned int u32;
typedef unsigned char u8;
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#ifdef _MSC_VER
#define CX46_INL static __forceinline
#else
#define CX46_INL static inline
#endif

extern void ts4_ctor_cleared_88723AD0(void *self);
extern char lbl_880F2968[];
extern void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(u32 *p);

typedef struct Cx46AVec { u32 begin, end, ctx, cap; } Cx46AVec;
CX46_INL void cx46_avec_init(Cx46AVec *v, u32 z)
{
    u32 tmp = z;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
    v->begin = z;
    v->end = z;
    v->ctx = z;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&v->ctx);
    v->cap = z;
}

char *ts4_ctor_avec_8872CDE0(char *self)
{
    ts4_ctor_cleared_88723AD0(self);
    *(char **)self = lbl_880F2968;
    cx46_avec_init((Cx46AVec *)(self + 0x80), 0);
    W(self, 8) = 0xd99d0011u;
    return self;
}
