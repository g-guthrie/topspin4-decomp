/* CX39: net/lobby, scheduler, front end helpers, Swing_DLL.xex 0x8896xxxx-0x8897xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX39_INL static __forceinline
#else
#define CX39_INL static inline
#endif
#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif

/* ---- work/cx39/keep_remove.c ---- */
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
typedef struct Cx39AE { u8 pad[0x38]; char *n38; char *n3c; } Cx39AE;
typedef struct Cx39AV { Cx39AE **first; Cx39AE **last; } Cx39AV;
typedef struct Cx39AO { u8 pad[0x60]; Cx39AV v; } Cx39AO;
extern void ts4_if_call_seq_u32_off8_8895B160(Cx39AE *e);
extern Cx39AE **ts4_vec_erase_one_881AAE10(Cx39AV *v, Cx39AE **it);
void ts4_remove_named_88960E48(Cx39AO *o, const char *name)
{
    Cx39AE **p;
    Cx39AE **end = o->v.last;
    Cx39AV *v = &o->v;
    for (p = v->first; p != end; p++) {
        Cx39AE *e = *p;
        if (e && strcmp(name, e->n38) == 0) {
            ts4_if_call_seq_u32_off8_8895B160(e);
            ts4_vec_erase_one_881AAE10(v, p);
            return;
        }
    }
}

extern char *fn_88168F08(char *first, char *last, const char *s, const char *send);
void ts4_remove_containing_88960EE8(Cx39AO *o, const char *name)
{
    Cx39AV *v;
    Cx39AE **p;
    if (name[0] == 0)
        return;
    v = &o->v;
    p = v->first;
    for (; p != o->v.last;) {
        Cx39AE *e = *p;
        if (e != 0) {
            int len = (int)strlen(name);
            char *b = e->n3c;
            char *a = e->n38;
            if ((u32)len <= (u32)(b - a)) {
                char *r = fn_88168F08(a, b, name, name + len);
                if (r != b && r - a != -1) {
                    ts4_if_call_seq_u32_off8_8895B160(e);
                    p = ts4_vec_erase_one_881AAE10(v, p);
                    continue;
                }
            }
            p++;
        }
    }
}

/* ---- work/cx39/keep_apply.c ---- */
extern void *ts4_rel_table_find16_88941C68(void *self, u32 key);
extern void fn_88946348(void *self, void *o, u32 z, u32 v);
extern u8 fn_88978060(void *self, u32 a);
typedef struct Cx39BG { u8 pad[0x27c]; u32 w27c; } Cx39BG;
extern Cx39BG *lbl_88D45B1C;
u8 ts4_apply_named_8897D490(void *self, u32 key, u32 a, u8 flag)
{
    void *o = ts4_rel_table_find16_88941C68(self, key);
    if (o != 0) {
        fn_88946348(self, o, 0, lbl_88D45B1C->w27c);
        {
            int r;
            if (flag == 0 || fn_88978060(self, a) != 0)
                r = 1;
            else
                r = 0;
            return (u8)r;
        }
    }
    return 0;
}
typedef struct Cx39BP { u8 pad[0x24]; u8 *w24; } Cx39BP;
/* 0x8897D518: apply the sub-object at +0x10 of the owned block, and optionally re-run the check */
u8 ts4_apply_off10_8897D518(Cx39BP *self, u32 key, u8 flag)
{
    u8 *o = self->w24;
    u8 *p = o ? o + 0x10 : 0;
    if (p != 0) {
        int r;
        fn_88946348(self, p, 0, lbl_88D45B1C->w27c);
        if (flag == 0 || fn_88978060(self, key) != 0)
            r = 1;
        else
            r = 0;
        return (u8)r;
    }
    return 0;
}
/* 0x8897D5A0: same for the sub-object at +0x1c */
u8 ts4_apply_off1c_8897D5A0(Cx39BP *self, u32 key, u8 flag)
{
    u8 *o = self->w24;
    u8 *p = o ? o + 0x1c : 0;
    if (p != 0) {
        int r;
        fn_88946348(self, p, 0, lbl_88D45B1C->w27c);
        if (flag == 0 || fn_88978060(self, key) != 0)
            r = 1;
        else
            r = 0;
        return (u8)r;
    }
    return 0;
}

/* ---- work/cx39/keep_drop.c ---- */
typedef struct Cx39CNm { char *name; u32 a, b; } Cx39CNm;
typedef struct Cx39CNV { Cx39CNm *first; Cx39CNm *last; } Cx39CNV;
typedef struct Cx39CPk { u8 pad[0x64]; Cx39CNV v; } Cx39CPk;
extern void *ts4_find_service(u32 id);
extern void *ts4_memset(void *dst, int c, u32 n);
extern void ts4_normalize_dir_path_88606978(char *out, const char *in);
extern u32 fn_88608590(u32 seed, const char *s);
extern u32 fn_8861A370(void *svc, u32 h);
extern void fn_8861A278(void *svc, const char *s);
extern void ts4_vec_erase_0c_88160DB0(Cx39CNV *v, Cx39CNm *it);
u32 ts4_drop_known_paths_88965C80(Cx39CPk *o)
{
    void *svc = ts4_find_service(0x403EAA1C);
    Cx39CNV *v = &o->v;
    Cx39CNm *p;
    for (p = o->v.first; p != o->v.last; ) {
        char buf[0x200];
        char *s = p->name;
        ts4_memset(buf, 0, 0x200);
        ts4_normalize_dir_path_88606978(buf, s);
        if (fn_8861A370(svc, fn_88608590(0, buf)) != 0) {
            fn_8861A278(svc, p->name);
            ts4_vec_erase_0c_88160DB0(v, p);
        } else {
            p++;
        }
    }
    return 1;
}

/* ---- work/cx39/keep_clear.c ---- */
typedef struct Cx39DD20 { u8 s0[0xc]; u8 s1[0xc]; u32 w18, w1c; } Cx39DD20;
typedef struct Cx39DV { u32 *begin; u32 *end; } Cx39DV;
typedef struct Cx39DDV { Cx39DD20 *begin; Cx39DD20 *end; } Cx39DDV;
typedef struct Cx39DOwn {
    u8 pad[0x74]; u8 s74[0xc]; u8 s80[0xc]; u8 s8c[0xc]; u8 s98[0xc]; u8 sa4[0xc]; u8 sb0[0xc];
    Cx39DV vbc; u32 pad2; Cx39DV vc8; u32 pad3; Cx39DDV dv; u8 pad4[0xe0 - 0xdc]; u8 se0[0x1c];
} Cx39DOwn;
extern void ts4_call_seq_u32_off4_88160CE0(void *p);
extern Cx39DD20 *ts4_dc20_copy_881660A0(Cx39DD20 *first, Cx39DD20 *last, Cx39DD20 *dst);
extern void ts4_loop_call_seq_u32_offc_88166048(Cx39DD20 *a, Cx39DD20 *b);
extern void ts4_vector_erase_range_88150310(void *vec, void *first, void *last);
extern void ts4_cw2_vec28_clear_88160E20(void *v);
extern Cx39DD20 *ts4_dc20_copy_881660A0(Cx39DD20 *first, Cx39DD20 *last, Cx39DD20 *dst);
extern void ts4_loop_call_seq_u32_offc_88166048(Cx39DD20 *a, Cx39DD20 *b);
CX39_INL void dv_clear_D(Cx39DDV *v)
{
    Cx39DD20 *p = ts4_dc20_copy_881660A0(v->end, v->end, v->begin);
    ts4_loop_call_seq_u32_offc_88166048(p, v->end);
    v->end = p;
}
void ts4_clear_owner_889750F0(Cx39DOwn *o)
{
    if (o != 0) {
        ts4_call_seq_u32_off4_88160CE0(o->s74);
        ts4_call_seq_u32_off4_88160CE0(o->s80);
        ts4_call_seq_u32_off4_88160CE0(o->s8c);
        ts4_call_seq_u32_off4_88160CE0(o->s98);
        ts4_call_seq_u32_off4_88160CE0(o->sa4);
        dv_clear_D(&o->dv);
        ts4_call_seq_u32_off4_88160CE0(o->sb0);
        ts4_vector_erase_range_88150310(&o->vbc, o->vbc.begin, o->vbc.end);
        ts4_vector_erase_range_88150310(&o->vc8, o->vc8.begin, o->vc8.end);
        ts4_cw2_vec28_clear_88160E20(o->se0);
    }
}

/* ---- work/cx39/keep_vcall.c ---- */
typedef struct Cx39EObj Cx39EObj;
typedef struct Cx39EVt {
    void *s[12];
    u8 (*f30)(Cx39EObj *self);
    void (*f34)(Cx39EObj *self, u32 a);
    void *s2[9];
    void (*f5c)(u32 *out, Cx39EObj *self);
} Cx39EVt;
typedef struct Cx39ESub { u8 pad[0x5c]; int w5c; } Cx39ESub;
struct Cx39EObj { Cx39EVt *vt; u8 pad[0x3c - 4]; Cx39ESub *w3c; };
typedef struct Cx39EGl { u8 pad[0x24]; u8 b24; } Cx39EGl;
extern Cx39EGl *lbl_88D4589C;
extern void fn_8896A9D8(Cx39EObj *self, u32 a, u32 b);
extern void fn_8896A178(Cx39EObj *self, u32 a);
extern void ts4_destroy_owned_object(void *p);
u32 ts4_vcall_dispatch_88977FA0(Cx39EObj *self, u32 a, u32 b)
{
    u32 tmp[4];
    if (self->vt->f30(self) != 0) {
        self->vt->f34(self, a);
        return 1;
    }
    self->vt->f5c(tmp, self);
    if (lbl_88D4589C->b24 != 0 || self->w3c->w5c == 0) {
        fn_8896A9D8(self, a, b);
        fn_8896A178(self, a);
    }
    ts4_destroy_owned_object((void *)(unsigned long)tmp[0]);
    return 1;
}

/* ---- work/cx39/keep_reset.c ---- */
extern void ts4_assign_formatted_text(void *dst, const char *text);
extern void ts4_destroy_owned_object(void *p);
extern u8 lbl_880C1320[];
typedef struct Cx39FD30 { u8 s[0x30]; } Cx39FD30;
typedef struct Cx39FDV { Cx39FD30 *begin; Cx39FD30 *end; u32 cap; } Cx39FDV;
typedef struct Cx39FV { u32 *begin; u32 *end; u32 cap; } Cx39FV;
typedef struct Cx39FOwn {
    u32 w0; u8 p0[0x6c - 4]; int w6c; Cx39FDV d70; u8 s7c[0xc]; Cx39FDV d88; Cx39FV v94; u8 va0[0xc]; u8 vac[0xc]; u32 wb8; u8 sbc[0x30]; u32 wec; u8 bf0; u8 pf1[7]; u8 bf8;
} Cx39FOwn;
extern Cx39FD30 *ts4_dc30_copy_88165FC8(Cx39FD30 *first, Cx39FD30 *last, Cx39FD30 *dst);
extern void ts4_loop_call_seq_u32_off18_88165F68(Cx39FD30 *begin, Cx39FD30 *end);
extern void ts4_cw2_vec30_clear_88160F30(void *v);
extern void ts4_cx28_vec60_erase_88161C20(void *v, u32 *dst, u32 *first);
extern void ts4_cx28_vec54_clear_88161128(void *v);
extern void fn_88150600(void *dst, void *src);
CX39_INL void dv_clear_F(Cx39FDV *v)
{
    Cx39FD30 *p = ts4_dc30_copy_88165FC8(v->end, v->end, v->begin);
    ts4_loop_call_seq_u32_off18_88165F68(p, v->end);
    v->end = p;
}
void ts4_reset_owner_8897CCB8(Cx39FOwn *o)
{
    u32 z = 0;
    o->w0 = z;
    o->wec = z;
    dv_clear_F(&o->d70);
    ts4_cw2_vec30_clear_88160F30(o->s7c);
    dv_clear_F(&o->d88);
    ts4_cx28_vec60_erase_88161C20(&o->v94, o->v94.begin, o->v94.end);
    ts4_cx28_vec54_clear_88161128(o->vac);
    ts4_cx28_vec54_clear_88161128(o->va0);
    {
        u32 t[4];
        ts4_assign_formatted_text(t, (const char *)lbl_880C1320);
        fn_88150600(o->sbc, t);
        ts4_destroy_owned_object((void *)(unsigned long)t[0]);
    }
    o->bf8 = z;
    o->bf0 = 1;
    o->w6c = -1;
    o->wb8 = z;
}

/* ---- work/cx39/keep_pickname.c ---- */
extern void ts4_assign_formatted_text(void *dst, const char *text);
extern void ts4_destroy_owned_object(void *p);
typedef struct Cx39GS3 { u32 a, b, c; } Cx39GS3;
typedef struct Cx39GVec { Cx39GS3 *begin; u32 end; u32 cap; } Cx39GVec;
typedef struct Cx39GStr { char *p; u32 a, b, c; } Cx39GStr;
typedef struct Cx39GS12 { char *p; u32 a, b; } Cx39GS12;
extern u8 lbl_880D3598[], lbl_880D359C[];
extern void fn_8892E0B8(void *o, Cx39GVec *out);
extern void fn_88169350(u32 *out, Cx39GS3 *in);
extern void fn_88150600(void *dst, void *src);
typedef struct Cx39GOwn { u8 pad[0x1c]; Cx39GS12 s1c; u8 pad2[0x2c - 0x28]; int w2c; } Cx39GOwn;
void ts4_pick_name_88967840(Cx39GOwn *self)
{
    int o = self->w2c;
    if (o != 0) {
        Cx39GVec v;
        u32 h;
        Cx39GS3 c;
        const char *s;
        v.begin = 0;
        v.end = 0;
        v.cap = 0;
        fn_8892E0B8((void *)(long)(o + 0x18), &v);
        c = *v.begin;
        fn_88169350(&h, &c);
        if (h == 0xBC1789F5)
            s = (const char *)lbl_880D3598;
        else if (h == 0x69CCB0F7)
            s = (const char *)lbl_880D359C;
        else
            goto done;
        {
            Cx39GS12 t;
            ts4_assign_formatted_text(&t, s);
            fn_88150600(&self->s1c, &t);
            ts4_destroy_owned_object(t.p);
        }
done:
        if (v.begin != 0)
            ts4_destroy_owned_object(v.begin);
    }
}

/* ---- work/cx39/keep_register.c ---- */
typedef struct Cx39HNm { u8 pad[0x10]; int w10; } Cx39HNm;
typedef struct Cx39HOb Cx39HOb;
typedef struct Cx39HVt { void *s[8]; void (*f20)(Cx39HOb *self, void *arg); } Cx39HVt;
struct Cx39HOb { Cx39HVt *vt; };
typedef struct Cx39HNm2 { u8 pad[0x50]; int w50; } Cx39HNm2;
typedef struct Cx39HOwn { u8 pad; } Cx39HOwn;
extern u8 lbl_880C1320[];
extern u32 fn_88608590(u32 seed, const char *s);
extern Cx39HOb *fn_88941B30(Cx39HOwn *g, u32 *h);
extern void *ts4_find_by_name_88943978(Cx39HOwn *self, char **a);
extern void fn_8897CE90(char **b, void *arg);
Cx39HOb *ts4_register_named_8897CF90(Cx39HOwn *self, char **a, char **b)
{
    u32 h0;
    u32 h1;
    Cx39HOb *r;
    Cx39HNm2 *p;
    char *n;
    u32 seed;
    seed = fn_88608590(0, *a);
    n = *b;
    h0 = fn_88608590(seed, n);
    r = fn_88941B30(self, &h0);
    if (r == 0) {
        p = ts4_find_by_name_88943978(self, a);
        if (p != 0) {
            int *bp = &p->w50;
            Cx39HNm *q = (Cx39HNm *)((char *)bp - *bp);
            if (q != 0) {
                const char *s;
                Cx39HOb *f;
                int *np = &q->w10;
                if (*np != -1)
                    s = (const char *)np + *np;
                else
                    s = (const char *)lbl_880C1320;
                seed = fn_88608590(0, s);
                h1 = fn_88608590(seed, n);
                f = fn_88941B30(self, &h1);
                if (f == 0)
                    fn_8897CE90(b, q);
                else
                    f->vt->f20(f, p);
                return fn_88941B30(self, &h0);
            }
        }
    }
    return r;
}

/* ---- work/cx39/keep_texts.c ---- */
typedef struct Cx39ITri { u32 a, b, c; } Cx39ITri;

typedef struct Cx39IStr { char *p; u32 a, b; } Cx39IStr;
typedef struct Cx39IG2 { u8 pad[0x34]; u32 w34; } Cx39IG2;
typedef struct Cx39IG1 { u8 pad[0x24]; Cx39IG2 *w24; } Cx39IG1;
typedef struct Cx39IObj { u8 pad[0x1c]; u8 s1c[0xc]; u8 s28[0xc]; u8 s34[0xc]; u8 s40[0xc]; } Cx39IObj;
extern Cx39IG1 *lbl_88D45898;
extern u8 lbl_880C1320[];
extern void fn_88627EC0(void *self, Cx39ITri value);
extern void fn_88942520(void *self, u32 k);
extern const char *ts4_if_get_fn_88150770_886F7C08(Cx39ITri value, u32 key, const char *dflt);
extern void ts4_assign_formatted_text(void *dst, const char *text);
extern void ts4_destroy_owned_object(void *p);
extern void fn_88150600(void *dst, void *src);
void ts4_init_texts_88972BF0(Cx39IObj *self, Cx39ITri value)
{
    Cx39IStr t;
    u32 k;
    fn_88627EC0(self, value);
    k = 0xF5BF4F97;
    if (lbl_88D45898 != 0) {
        Cx39IG2 *g = lbl_88D45898->w24;
        if (g != 0)
            k = g->w34;
    }
    fn_88942520(self, k);
    ts4_assign_formatted_text(&t, ts4_if_get_fn_88150770_886F7C08(value, 0x30E3F0F8, (const char *)lbl_880C1320));
    fn_88150600(self->s1c, &t);
    ts4_destroy_owned_object(t.p);
    ts4_assign_formatted_text(&t, ts4_if_get_fn_88150770_886F7C08(value, 0x227340FB, (const char *)lbl_880C1320));
    fn_88150600(self->s28, &t);
    ts4_destroy_owned_object(t.p);
    ts4_assign_formatted_text(&t, ts4_if_get_fn_88150770_886F7C08(value, 0x4FED7CB6, (const char *)lbl_880C1320));
    fn_88150600(self->s34, &t);
    ts4_destroy_owned_object(t.p);
    ts4_assign_formatted_text(&t, ts4_if_get_fn_88150770_886F7C08(value, 0xA07CD45D, (const char *)lbl_880C1320));
    fn_88150600(self->s40, &t);
    ts4_destroy_owned_object(t.p);
}

/* ---- work/cx39/keep_namechain.c ---- */
extern void ts4_assign_formatted_text(void *dst, const char *text);
extern void fn_8816CAA0(void *self, const char *s);
extern u8 lbl_880C1320[];
typedef struct Cx39KA { u8 pad[0x14]; int w14; } Cx39KA;
typedef struct Cx39KB { u8 pad[0x50]; int w50; } Cx39KB;
typedef struct Cx39KC { u8 pad[0x14]; int w14; } Cx39KC;
void *ts4_set_name_chain_88964458(void *self, Cx39KA *a)
{
    int *bp;
    Cx39KB *b;
    ts4_assign_formatted_text(self, (const char *)lbl_880C1320);
    bp = &a->w14;
    b = (Cx39KB *)((char *)bp - *bp);
    if (b != 0) {
        int *cp = &b->w50;
        Cx39KC *c = (Cx39KC *)((char *)cp - *cp);
        if (c != 0) {
            int *np = &c->w14;
            const char *s;
            if (*np != -1)
                s = (const char *)np + *np;
            else
                s = (const char *)lbl_880C1320;
            fn_8816CAA0(self, s);
        }
    }
    return self;
}

/* ---- work/cx39/keep_release.c ---- */
typedef struct Cx39MV12 { void *b; void *e; u32 c; } Cx39MV12;
typedef struct Cx39MQ { Cx39MV12 a[4]; u8 tail[0xc]; } Cx39MQ;
typedef struct Cx39MSb { u8 pad[8]; u8 s8[0xc]; } Cx39MSb;
typedef struct Cx39MOwn { u8 pad[8]; u8 b8; u8 pad1[7]; u8 s10[0xc]; Cx39MQ *w1c; Cx39MSb *w20; } Cx39MOwn;
extern void ts4_vec204_move_tail_881B9148(void *p);
extern void fn_8895B200(void *self);
extern void fn_8816C648(void *p);
extern void ts4_tsu_cleanup_end(void *p);
extern void fn_8816C258(void *p);
extern void fn_8815DEA0(void *b, void *e);
extern void ts4_destroy_owned_object(void *p);
void ts4_release_owner_88960FB8(Cx39MOwn *self)
{
    Cx39MSb *o;
    Cx39MQ *q;
    self->b8 = 0;
    ts4_vec204_move_tail_881B9148(self->s10);
    fn_8895B200(self);
    o = self->w20;
    if (o != 0) {
        fn_8816C648(o->s8);
        ts4_tsu_cleanup_end(o);
    }
    q = self->w1c;
    if (q != 0) {
        Cx39MV12 *p = (Cx39MV12 *)q->tail;
        int i;
        fn_8816C258(p);
        for (i = 3; i >= 0; i--) {
            p--;
            fn_8815DEA0(p->b, p->e);
            if (p->b != 0)
                ts4_destroy_owned_object(p->b);
        }
        ts4_tsu_cleanup_end(q);
    }
}

/* ---- work/cx39/keep_count.c ---- */
typedef struct Cx39NE28 { u8 pad[0xc]; u32 w0c; u8 pad2[0x28 - 0x10]; } Cx39NE28;
typedef struct Cx39NV28 { Cx39NE28 *begin; Cx39NE28 *end; } Cx39NV28;
typedef struct Cx39NT { u8 pad[0x6c]; int key; u8 pad2[0xe0 - 0x70]; Cx39NV28 v; u8 tail[0x100 - 0xe8]; } Cx39NT;
extern void *ts4_rel_table_find16_88941C68(void *self, u32 key);
extern void ts4_call_seq_fn_8816D1A8_88160340(Cx39NT *t);
extern void ts4_apply_two_889537F0(void *self, Cx39NT *t);
extern void ts4_cw2_vec28_clear_88160E20(void *v);
extern void ts4_if_call_seq_u32_offe4_88160438(Cx39NT *t);
u8 ts4_count_active_88965BE0(void *self, int key)
{
    int n = 0;
    if (key != -1 && ts4_rel_table_find16_88941C68(self, key) != 0) {
        Cx39NT t;
        Cx39NE28 *p;
        ts4_call_seq_fn_8816D1A8_88160340(&t);
        t.key = key;
        ts4_apply_two_889537F0(self, &t);
        for (p = t.v.begin; p != t.v.end; p++) {
            if (p->w0c != 0)
                n++;
        }
        ts4_cw2_vec28_clear_88160E20(&t.v);
        ts4_if_call_seq_u32_offe4_88160438(&t);
    }
    return n > 0;
}
