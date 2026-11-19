typedef unsigned int u32;
extern void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(u32 *p);
extern char lbl_880F2C00[];
typedef struct AVec { u32 begin, end, ctx, cap; } AVec;
typedef struct Self { void *vt; char p4[4]; u32 hash; char pc[0x74]; AVec a; u32 p90; AVec b; } Self;
Self *ts4_ctor_cleared_88723AD0(Self *s);
static __inline void avec_init(AVec *v, u32 z) { u32 tmp = z; ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp); v->begin = z; v->end = z; v->ctx = z; ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&v->ctx); v->cap = z; }
Self *fn_8872CD50(Self *s){ ts4_ctor_cleared_88723AD0(s); s->vt = lbl_880F2C00; avec_init(&s->a, 0); avec_init(&s->b, 0); s->hash = 0x6F80A671; return s; }
