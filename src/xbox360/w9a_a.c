/* W9A: constructors written with inline sub-object helpers (see da1_a.c). Plain route, /Oc. */
extern char lbl_880D7600[];
extern char lbl_880F4BCC[];
extern void ts4_destroy_owned_object(void *p);
typedef unsigned int W9U32;

extern char lbl_880D7600[];
extern char lbl_880F37A0[];
extern char lbl_880F4428[];
extern char lbl_880F444C[];
extern char lbl_880F4E2C[];
extern char lbl_880F58D8[];
extern void *lbl_88D45AF0;
extern void ts4_destroy_owned_object(void *p);
extern void ts4_object_finalize(void *p);
extern void fn_88262730(void *p);
extern void ts4_vec12_move_tail_88161620(void *p);
extern unsigned *fn_88268500(unsigned *a, unsigned *b, unsigned *c);
extern void ts4_loop_get_u32_off0_882666E0(unsigned *p, unsigned *e);
extern void *fn_88617D88(void *self);

/* ---- shared: three-word vector and the lbl_880D7600 object (0x44 bytes) ---- */
typedef struct W9Vec { W9U32 *b, *e, *c; } W9Vec;
typedef struct W9Vec3 { W9Vec v0, v1, v2; } W9Vec3;
typedef struct W9Obj44 {
    void *vt;
    W9U32 w04, w08, w0c, w10;
    W9Vec3 m;   /* +0x14 */
    W9Vec x;    /* +0x38 */
} W9Obj44;

static __inline void w9_vec_init(W9Vec *v) { v->b = 0; v->e = 0; v->c = 0; }
static __inline void w9_vec3_init(W9Vec3 *m) { w9_vec_init(&m->v0); w9_vec_init(&m->v1); w9_vec_init(&m->v2); }
static __inline void w9_obj44_init(W9Obj44 *s)
{
    s->vt = lbl_880D7600;
    w9_vec3_init(&s->m);
    w9_vec_init(&s->x);
    s->w04 = 0; s->w08 = 0; s->w0c = 0; s->w10 = 0;
}
static __inline void w9_vec_free(W9Vec *v) { if (v->b) ts4_destroy_owned_object(v->b); }
static __inline void w9_vec3_free(W9Vec3 *m) { w9_vec_free(&m->v2); w9_vec_free(&m->v1); w9_vec_free(&m->v0); }


typedef struct W9Obj8869AF98 { void *vt; W9U32 w04, w08; W9Obj44 a, b, c; W9U32 wd8; } W9Obj8869AF98;
void ts4_obj44_triple_ctor_8869AF98(W9Obj8869AF98 *o)
{
    o->vt = lbl_880F4BCC;
    w9_obj44_init(&o->a);
    w9_obj44_init(&o->b);
    w9_obj44_init(&o->c);
    o->wd8 = 0;
    o->w08 = 0;
    o->w04 = 0;
}
