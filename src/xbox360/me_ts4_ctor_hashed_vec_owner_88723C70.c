typedef unsigned int u32;
extern void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(u32 *p);
extern char lbl_880F2B00[];
typedef struct AVec { u32 begin, end, ctx, cap; } AVec;
typedef struct Self { void *vt; char p4[4]; u32 hash; char pc[0x74]; AVec items; } Self;
Self *ts4_ctor_cleared_88723AD0(Self *s);
static __inline void avec_init(AVec *v, u32 z) { u32 tmp = z; ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp); v->begin = z; v->end = z; v->ctx = z; ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&v->ctx); v->cap = z; }
Self *ts4_ctor_hashed_vec_owner_88723C70(Self *s){ ts4_ctor_cleared_88723AD0(s); s->vt = lbl_880F2B00; { u32 tmp = 0; ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp); } s->items.begin = 0; s->items.end = 0; { AVec *v = &s->items; v->ctx = 0; ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&v->ctx); } s->items.cap = 0; s->hash = 0x2A45F643; return s; }