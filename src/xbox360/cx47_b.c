/* CX47 part b: Pam Display renderer helpers with a divide (0x88740000-0x88760000), /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Cx47E { u8 p0[0xd]; u8 f; u8 p1[0x44 - 0xe]; } Cx47E;
typedef struct Cx47Vec { Cx47E *first; Cx47E *last; Cx47E *cap; } Cx47Vec;
typedef struct Cx47O { u8 p0[0x24]; Cx47Vec v; } Cx47O;
typedef struct Cx47G { u8 p0[0x14]; Cx47O *o; } Cx47G;
extern Cx47G *lbl_88D45AD4;
extern void fn_8825E4F0(void *);
#ifdef _MSC_VER
#define CX47_INL static __forceinline
#else
#define CX47_INL static inline
#endif
CX47_INL u32 cx47_vsize(Cx47Vec *v) { return v->last - v->first; }
CX47_INL Cx47E *cx47_vat(Cx47Vec *v, u32 i) { return &v->first[i]; }

/* 0x8875BFE0: clear the byte at +0xd of every 0x44-byte element of the display object's vector, then 0x8825E4F0 */
void ts4_clear_flags_8875BFE0(void)
{
    Cx47G *g = lbl_88D45AD4;
    u32 i;
    for (i = 0; i < cx47_vsize(&g->o->v); i++) cx47_vat(&g->o->v, i)->f = 0;
    fn_8825E4F0(g->o);
}

typedef struct Cx47A { u8 p[0xa0]; } Cx47A;
typedef struct Cx47Rec { Cx47A *first; Cx47A *last; u32 c, d; } Cx47Rec;
typedef struct Cx47RV { Cx47Rec *first; Cx47Rec *last; } Cx47RV;
typedef struct Cx47S { u8 p[0x20]; Cx47RV rv; } Cx47S;
extern void fn_8871F128(void *);
extern void ts4_dtor_88744B98(void *);
extern void fn_88222E40(void *);
CX47_INL u32 cx47_rsize(Cx47RV *v) { return v->last - v->first; }
CX47_INL u32 cx47_asize(Cx47Rec *v) { return v->last - v->first; }

/* 0x88747EB0: run 0x8871F128 on every 0xa0-byte element of every record of the vector at +0x20, then finish */
void ts4_run_all_88747EB0(Cx47S *self)
{
    int op1_pad0 = 0, op1_pad1 = 0, op1_pad2 = 0, op1_pad3 = 0, op1_pad4 = 0, op1_pad5 = 0;
    Cx47RV *v = &self->rv;
    u32 i, j;
    (void)op1_pad0; (void)op1_pad1; (void)op1_pad2; (void)op1_pad3; (void)op1_pad4; (void)op1_pad5;
    for (i = 0; i < cx47_rsize(&self->rv); i++) {
        Cx47Rec *r = &v->first[i];
        for (j = 0; j < cx47_asize(r); j++) fn_8871F128(&r->first[j]);
    }
    ts4_dtor_88744B98((char *)self + 0x120);
    fn_88222E40(self);
}
