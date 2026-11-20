typedef unsigned int u32;
extern void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(u32 *p);
extern char lbl_880F28C0[];
typedef struct AVec { u32 begin, end, ctx, cap; } AVec;
typedef struct Self { void *vt; char p4[0x18]; AVec items; char state[1]; } Self;
void fn_88617D88(Self *s);
void *ts4_call_seq_u32_off0_8821C010(void *p);
static __inline void avec_init(AVec *v, u32 z) { u32 tmp = z; ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp); v->begin = z; v->end = z; v->ctx = z; ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&v->ctx); v->cap = z; }
Self *ts4_ctor_vec_state_owner_887261D0(Self *s){ fn_88617D88(s); s->vt = lbl_880F28C0; avec_init(&s->items, 0); ts4_call_seq_u32_off0_8821C010(s->state); return s; }