typedef unsigned int u32;
extern void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(u32 *p);
extern char lbl_880F2B80[];
typedef struct AVec { u32 begin, end, ctx, cap; } AVec;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef struct Self { void *vt; char p4[4]; u32 hash; char pc[0x74]; AVec items; char p90[0xc]; Ts4Handle12 h; } Self;
Self *ts4_ctor_cleared_88723AD0(Self *s);
Self *fn_88723BE0(Self *s){ ts4_ctor_cleared_88723AD0(s); s->vt = lbl_880F2B80; { u32 tmp = 0; ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp); } s->items.begin = 0; s->items.end = 0; { AVec *v = &s->items; v->ctx = 0; ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&v->ctx); } s->items.cap = 0; s->h.a = 0; s->h.c = 0; s->h.b = 0xFFFFF; s->hash = 0x3835300E; return s; }
