/* nearmiss: 2 off (LTCG /Oc, --include fn_88636DC8 --context flags(/Ob1):src/xbox360/me_ts4_ctor_register_current_88636DC8.c + pool primer); vt store and ori r8,r10,0xffff swapped. Blocker: base ctor fn_88636DC8 has no shared type for the class yet; the base layout (vector at +0x2c/+0x30 per dtor 0x88911FC0) may change inlining/scheduling. */
typedef unsigned int u32;
typedef struct IdSlot { int a; int id; int b; } IdSlot;
typedef struct Tri { u32 a, b, c; } Tri;
typedef struct Pair { u32 a, b; } Pair;
typedef struct RModD {
    const void **vt;
    char pad04[0x28];
    Tri t;
    IdSlot s0;
    char pad44[0xc];
    Pair p;
} RModD;
extern const void *lbl_880D75C4[];
void *fn_88636DC8(void *self);
static __inline void id_init(IdSlot *s) { s->a = 0; s->b = 0; s->id = 0xFFFFF; }
static __inline void tri_init(Tri *s) { s->a = 0; s->b = 0; s->c = 0; }
static __inline void pair_init(Pair *s) { s->a = 0; s->b = 0; }
RModD *ts4_input_rmod_ctor_88912018(RModD *m)
{
    fn_88636DC8(m); m->vt = lbl_880D75C4; tri_init(&m->t); id_init(&m->s0); pair_init(&m->p); return m;
}
