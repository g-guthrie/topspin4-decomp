/* CW52 (plain): UI/script helpers in 0x887D0000-0x88800000. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Cx52G27c { char pad[0x27c]; u32 w27c; } Cx52G27c;
extern Cx52G27c *lbl_88D45B1C;
typedef struct Cx52Rf { char pad[0x110]; int count; u32 owner, pending; } Cx52Rf;
static __inline int cx52_dec(int *p) { *p = *p - 1; return *p; }
/* 0x887D4B98: drop one reference unless the current owner is the caller; when the count reaches 0 move owner to pending. */
u32 ts4_release_ref_887D4B98(Cx52Rf *self)
{
    u32 r = 0;
    if (lbl_88D45B1C->w27c != self->owner) {
        if (self->count > 0) cx52_dec(&self->count);
        if (self->count == 0) {
            *(volatile u32 *)&self->pending = self->owner;
            *(volatile u32 *)&self->owner = 0;
        }
    } else {
        if (self->pending != 0) r = 1;
    }
    return r;
}

typedef struct Cx52Vec { u32 b, e, c; } Cx52Vec;
typedef struct Cx52P2 { u32 a, b; } Cx52P2;
typedef struct Cx52M { Cx52Vec v0; Cx52P2 p; } Cx52M;
typedef struct Cx52O55E0 { u32 w0; Cx52M m; Cx52Vec v1; u8 f[5]; } Cx52O55E0;
static __inline void cx52_vec_init(Cx52Vec *v) { v->b = 0; v->e = 0; v->c = 0; }
static __inline void cx52_p2_init(Cx52P2 *v) { v->a = 0; v->b = 0; }
static __inline void cx52_m_init(Cx52M *m) { cx52_vec_init(&m->v0); cx52_p2_init(&m->p); }
/* 0x887D55E0: zero a record made of a word, a vector-plus-pair member, a vector and five flag bytes. */
void ts4_zero_record_887D55E0(Cx52O55E0 *o)
{
    cx52_vec_init(&o->v1);
    o->w0 = 0;
    cx52_m_init(&o->m);
    o->f[0] = 0; o->f[1] = 0; o->f[2] = 0; o->f[3] = 0; o->f[4] = 0;
}

typedef struct Cx52S3 { u32 a, b, c; } Cx52S3;
extern void fn_887D93F0(Cx52S3 *, u32, u32, u32);
extern u32 fn_881BBC78(void *, void *, u32, Cx52S3 *);
extern void fn_887DA2B8(Cx52S3 *);
/* 0x887DACE0: run the lookup with a zeroed scratch triple that is filled by fn_887D93F0 and released afterwards; returns whether it found something. */
u8 ts4_lookup_with_scratch_887DACE0(void *a, void *b, u32 c, u32 d, u32 e)
{
    Cx52S3 s;
    u8 r;
    s.a = 0; s.b = 0; s.c = 0;
    fn_887D93F0(&s, d, e, 0);
    r = 0 < fn_881BBC78(a, b, c, &s);
    fn_887DA2B8(&s);
    return r;
}

extern void fn_887E67F8(void *, void *, int);
typedef struct Cx52Nd69C8 { char pad[0x10]; u32 w10, w14; char pad2[6]; u8 b1e, b1f, b20, b21; } Cx52Nd69C8;
static __inline u8 cx52_nz69C8(Cx52Nd69C8 *p) { return 0 != p; }
/* 0x887E69C8: link node o into the owner (optionally as both head slots), reset its state bytes; returns whether o was non-null. */
u8 ts4_attach_node_887E69C8(char *self, Cx52Nd69C8 *o, u8 flag)
{
    if (flag != 0) {
        *(Cx52Nd69C8 **)(self + 0xa0) = o;
        *(Cx52Nd69C8 **)(self + 0xa4) = o;
    }
    if (o != 0) {
        o->w10 = 0;
        o->w14 = 0;
        fn_887E67F8(self, o, 0);
        o->b1f = 0;
        o->b1e = 1;
        o->b20 = 0;
        o->b21 = 0;
    }
    return cx52_nz69C8(o);
}

extern u32 fn_887EDF40(void *, u32, u32);
extern void *lbl_88D45A10;
/* 0x887EE5A0: true when the lookup on the global table for (a, field +0x10) returns 0. */
u8 ts4_lookup_is_zero_887EE5A0(char *self, u32 a)
{
    return 0 == fn_887EDF40(lbl_88D45A10, a, *(u32 *)(self + 0x10));
}

typedef struct Cx52Vt2c { void *s[11]; void (*s2c)(void *, void *); } Cx52Vt2c;
typedef struct Cx52Ch2c { Cx52Vt2c *vt; } Cx52Ch2c;
typedef struct Cx52Pv3 { char pad[0x30]; Cx52Ch2c **first, **last; } Cx52Pv3;
extern u32 fn_887F7248(void *);
extern void fn_882642E0(void *, u32);
/* 0x887F9DC0: push the computed value into the sub-object at +0x48, then hand that sub-object to every child of the vector at +0x30. */
void ts4_apply_children_887F9DC0(Cx52Pv3 *self)
{
    int n;
    u32 r = fn_887F7248(self);
    char *sub = (char *)self + 0x48;
    fn_882642E0(sub, r);
    n = self->last - self->first;
    if (n != 0) {
        u32 off = 0;
        int i = n;
        do {
            Cx52Ch2c *c = *(Cx52Ch2c **)((char *)self->first + off);
            if (c) c->vt->s2c(c, sub);
            off += 4;
        } while (--i != 0);
    }
}
