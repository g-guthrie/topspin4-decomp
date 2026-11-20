/* 0x887DA1E8: constructor that publishes the new object in a global (0x88D45A14). Installs the vtable (0x880E7060) and
 * clears four 16-byte records at +4 (body words first, then the head word), two short word runs, the byte at +0x68 and
 * an embedded object at +0x6C. That object clears five body words and two trailing words, then clears its eight body
 * words again (two Quad casts, which also keeps the second set of stores) and its head word. The heads at +0x44/+0x54
 * and the word at +0x98 are cleared last. Matches plain /Oc and LTCG. */
typedef struct Quad { int w[4]; } Quad;
static __inline void quad_init(Quad *q) { q->w[0] = 0; q->w[1] = 0; q->w[2] = 0; q->w[3] = 0; }
typedef struct Rec { int h; int v[3]; } Rec;
typedef struct Obj { int h; int w[8]; int x90, x94; } Obj;
typedef struct Self2 { void *vt; Rec r[4]; int c44; int d[3]; int c54; int e[4]; unsigned char b68; Obj o; int f98; } Self2;
extern char lbl_880E7060[];
extern Self2 *lbl_88D45A14;
static __inline void rec_init(Rec *r) { r->v[0] = 0; r->v[1] = 0; r->v[2] = 0; r->h = 0; }
static __inline void recs_init(Rec *r) { rec_init(&r[0]); rec_init(&r[1]); rec_init(&r[2]); rec_init(&r[3]); }
static __inline void obj_clear(Obj *o) { quad_init((Quad *)&o->w[0]); quad_init((Quad *)&o->w[4]); o->h = 0; }
static __inline void obj_init(Obj *o) { o->w[0] = 0; o->w[1] = 0; o->w[2] = 0; o->w[3] = 0; o->w[4] = 0; o->x90 = 0; o->x94 = 0; obj_clear(o); }
Self2 *ts4_ctor_publish_instance_887DA1E8(Self2 *s)
{
    s->vt = lbl_880E7060;
    recs_init(s->r);
    s->d[0] = 0; s->d[1] = 0; s->d[2] = 0;
    s->e[0] = 0; s->e[1] = 0; s->e[2] = 0; s->e[3] = 0;
    s->b68 = 0;
    obj_init(&s->o);
    s->c44 = 0; s->c54 = 0; s->f98 = 0;
    lbl_88D45A14 = s;
    return s;
}
