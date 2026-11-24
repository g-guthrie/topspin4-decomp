/* CX37: string-keyed finds in self-relative tables, Swing_DLL.xex 0x8894xxxx. */
#ifdef _MSC_VER
#define CX37_INL static __forceinline
#else
#define CX37_INL static inline
#endif
typedef unsigned char u8;
typedef unsigned int u32;
#ifdef _MSC_VER
extern int strcmp(const char *, const char *);
#pragma intrinsic(strcmp)
#else
#include <string.h>
#endif

typedef struct Cx37Hdr { int off; int cnt; } Cx37Hdr;
typedef struct Cx37Nm { u8 pad[0x10]; int noff; u8 pad2[0x24 - 0x14]; } Cx37Nm;
typedef struct Cx37NmOwn { u8 pad[0x7c]; Cx37Hdr *tab; } Cx37NmOwn;
extern u8 lbl_880C1320[];

CX37_INL Cx37Nm *nm_begin(Cx37Hdr *h)
{
    Cx37Nm *r = 0;
    if (h->off != -1)
        r = (Cx37Nm *)((char *)h + h->off);
    return r;
}
CX37_INL Cx37Nm *nm_end(Cx37Hdr *h)
{
    Cx37Nm *r = 0;
    if (h->off != -1)
        r = (Cx37Nm *)((char *)h + (h->cnt * 0x24 + h->off));
    return r;
}
/* 0x88942080: entry whose name equals *name */
Cx37Nm *ts4_find_by_name_88942080(Cx37NmOwn *o, const char **name)
{
    Cx37Nm *p = nm_begin(o->tab);
    for (; p != nm_end(o->tab); p++) {
        const char *s;
        if (p->noff != -1)
            s = (const char *)p + p->noff + 0x10;
        else
            s = (const char *)lbl_880C1320;
        if (strcmp(*name, s) == 0)
            return p;
    }
    return 0;
}

#if 0 /* near miss, not byte-identical */
typedef struct Cx37Nm1c { Cx37Hdr sub; u8 pad[4]; int noff; u8 pad2[0x1c - 0x10]; } Cx37Nm1c;
typedef struct Cx37Sub4c { u8 pad[0x48]; int k; } Cx37Sub4c;
typedef struct Cx37NmOwna4 { u8 pad[0xa4]; Cx37Hdr *tab; } Cx37NmOwna4;
extern void *ts4_offset_array_end76_88160BE0(void *h);
CX37_INL Cx37Nm1c *nm1c_begin(Cx37Hdr *h)
{
    Cx37Nm1c *r = 0;
    if (h->off != -1)
        r = (Cx37Nm1c *)((char *)h + h->off);
    return r;
}
CX37_INL Cx37Nm1c *nm1c_end(Cx37Hdr *h)
{
    Cx37Nm1c *r = 0;
    if (h->off != -1)
        r = (Cx37Nm1c *)((char *)h + (h->cnt * 0x1c + h->off));
    return r;
}
/* 0x889426C8: sub-entry with key inside the entry named `name` */
Cx37Sub4c *ts4_find_sub_by_name_889426C8(Cx37NmOwna4 *o, const char *name, int key)
{
    Cx37Sub4c *r = 0;
    Cx37Nm1c *p;
    if (o->tab != 0) {
        for (p = nm1c_begin(o->tab); p != nm1c_end(o->tab); p++) {
            const char *s;
            if (p->noff != -1)
                s = (const char *)&p->noff + p->noff + 0;
            else
                s = (const char *)lbl_880C1320;
            if (strcmp(name, s) == 0) {
                Cx37Sub4c *q = 0;
                Cx37Sub4c *qe;
                if (p->sub.off != -1)
                    q = (Cx37Sub4c *)((char *)p + p->sub.off);
                qe = (Cx37Sub4c *)ts4_offset_array_end76_88160BE0(p);
                for (; q != qe; q = (Cx37Sub4c *)((char *)q + 0x4c))
                    if (key == q->k)
                        return q;
                break;
            }
        }
    }
    return r;
}
#endif

extern void ts4_assign_formatted_text(void *dst, const char *text);
extern void ts4_destroy_owned_object(void *p);
typedef struct Cx37Str16 { char *p; u32 a, b, c; } Cx37Str16;
typedef struct Cx37TObj { void **vt; } Cx37TObj;
typedef char **(*Cx37TFn)(char **out, Cx37TObj *o);
#define CX37_TMPTXT(NAME, ADDR, OFF) \
    void *NAME##_##ADDR(void *dst, char *src) \
    { \
        Cx37Str16 tmpA; \
        char *tmpB; \
        char **h; \
        int fl; \
        Cx37TObj *o = *(Cx37TObj **)(src + (OFF)); \
        if (o) { \
            fl = 1; \
            h = ((Cx37TFn)o->vt[25])(&tmpA.p, o); \
        } else { \
            fl = 2; \
            ts4_assign_formatted_text(&tmpB, (const char *)lbl_880C1320); \
            h = &tmpB; \
        } \
        ts4_assign_formatted_text(dst, *h); \
        if (fl & 2) { \
            fl &= ~2; \
            ts4_destroy_owned_object(tmpB); \
        } \
        if (fl & 1) \
            ts4_destroy_owned_object(tmpA.p); \
        return dst; \
    }
CX37_TMPTXT(ts4_text_obj_4c, 88957DF0, 0x4c)
CX37_TMPTXT(ts4_text_obj_40a, 88957F88, 0x40)
CX37_TMPTXT(ts4_text_obj_40b, 889580A0, 0x40)

typedef struct Cx37Ent { u8 pad[4]; u32 w4; u8 pad2[0x38 - 8]; const char *n38; u8 pad3[0x44 - 0x3c]; const char *n44; u8 pad4[0x50 - 0x48]; u8 b50; } Cx37Ent;
typedef struct Cx37Act { u8 pad[0x20]; char *w20; u8 pad2[0x34 - 0x24]; u8 b34; u8 pad3[0x60 - 0x35]; Cx37Ent **first; Cx37Ent **last; } Cx37Act;
typedef struct Cx37Tgt { u8 pad[0x90]; u32 w90; } Cx37Tgt;
extern void fn_8898E9C0(Cx37Tgt *t, char *a);
extern void fn_8815B210(Cx37Tgt *t, char *a);
extern void fn_88953B40(Cx37Act *o, Cx37Ent *e);
#define CX37_ACT(o, e) \
    { \
        char *a = (o)->w20 + 0x10; \
        Cx37Tgt *t = (Cx37Tgt *)(unsigned long)(e)->w4; \
        if (t->w90 != 0x620) \
            fn_8898E9C0(t, a); \
        else \
            fn_8815B210(t, a); \
        fn_88953B40(o, *p); \
    }
/* 0x88953D40: act on the first entry named `name` */
void ts4_act_on_named_88953D40(Cx37Act *o, const char *name)
{
    Cx37Ent **p;
    Cx37Ent **end;
    if (o->b34 == 0)
        return;
    p = o->first;
    end = o->last;
    for (; p != end; p++) {
        Cx37Ent *e = *p;
        if (e && strcmp(name, e->n38) == 0) {
            CX37_ACT(o, e)
            return;
        }
    }
}
/* 0x88953C78: act on every enabled entry named `name` */
void ts4_act_on_named_all_88953C78(Cx37Act *o, const char *name)
{
    Cx37Ent **p;
    if (o->b34 == 0)
        return;
    for (p = o->first; p != o->last; p++) {
        Cx37Ent *e = *p;
        if (e && e->b50 == 1 && strcmp(name, e->n44) == 0)
            CX37_ACT(o, e)
    }
}

typedef struct Cx37Nm60 { u8 pad[0x4c]; int noff; u8 pad2[0x60 - 0x50]; } Cx37Nm60;
typedef struct Cx37Own1c { u8 pad[0x1c]; char *p1c; } Cx37Own1c;
extern void *ts4_offset_array_end96_88160B58(Cx37Hdr *h);
CX37_INL Cx37Nm60 *nm60_begin(Cx37Hdr *h)
{
    Cx37Nm60 *r = 0;
    if (h->off != -1)
        r = (Cx37Nm60 *)((char *)h + h->off);
    return r;
}
/* 0x88943978: entry of the table at +0x18 of the owned block whose name equals *name */
Cx37Nm60 *ts4_find_by_name_88943978(Cx37Own1c *o, const char **name)
{
    Cx37Nm60 *p;
    Cx37Nm60 *end;
    Cx37Hdr *h;
    if (o->p1c == 0)
        return 0;
    h = (Cx37Hdr *)(o->p1c + 0x18);
    p = nm60_begin(h);
    end = (Cx37Nm60 *)ts4_offset_array_end96_88160B58(h);
    for (; p != end; p++) {
        const char *s;
        if (p->noff != -1)
            s = (const char *)&p->noff + p->noff;
        else
            s = (const char *)lbl_880C1320;
        if (strcmp(*name, s) == 0)
            return p;
    }
    return 0;
}

typedef struct Cx37Rec { int off; u32 key; } Cx37Rec;
typedef struct Cx37Grp { int off; u32 n; u32 w8, wc; } Cx37Grp;
typedef struct Cx37Root { int off; u32 n; } Cx37Root;
typedef struct Cx37Arg6c { u8 pad[0x6c]; u32 w6c; } Cx37Arg6c;
extern void *ts4_rel_table_find16_88941C68(void *self, u32 key);
extern void fn_889440D0(void *self, u32 v);
/* 0x88946EA0: walk the two-level record table for the key pair and hand each match to fn_889440D0 */
void ts4_walk_records_88946EA0(void *self, Cx37Arg6c *a)
{
    Cx37Root *r = ts4_rel_table_find16_88941C68(self, a->w6c);
    u32 i;
    u32 j;
    int op1_pad0 = 0;
    (void)op1_pad0;
    if (r == 0)
        return;
    for (i = 0; i < r->n; i++) {
        Cx37Grp *g = (Cx37Grp *)((char *)r + r->off + i * 16);
        for (j = 0; j < g->n; j++) {
            Cx37Rec *it = (Cx37Rec *)((char *)g + g->off + j * 8);
            if (it->key == 0xAB25C3AD) {
                Cx37Rec *it2 = (Cx37Rec *)(it->off + (char *)it);
                if (it2->key == 0x0DB2434A)
                    fn_889440D0(self, *(u32 *)it2);
            }
        }
    }
}

#if 0 /* near miss, not byte-identical */
typedef struct Cx37PVec { u32 w0; u32 *last; u32 *cap; } Cx37PVec;
extern void ts4_vector_grow_append_scalar4_88174A38(Cx37PVec *vec, u32 *pos, u32 *val);
CX37_INL void cx37_push(Cx37PVec *v, u32 *val)
{
    if (v->last != v->cap) {
        if (v->last)
            *v->last = *val;
        v->last++;
    } else {
        ts4_vector_grow_append_scalar4_88174A38(v, v->last, val);
    }
}
CX37_INL void cx37_push2(Cx37PVec *v, Cx37Grp *g, u32 *pg)
{
    if (v->last != v->cap) {
        if (v->last)
            *v->last = (u32)(unsigned long)g;
        v->last++;
    } else {
        ts4_vector_grow_append_scalar4_88174A38(v, v->last, pg);
    }
}
typedef struct Cx37Hub { u8 pad[0x20]; void *w20; } Cx37Hub;
typedef struct Cx37Glob { u8 pad[0x27c]; u32 w27c; } Cx37Glob;
extern Cx37Glob *lbl_88D45B1C;
extern void *fn_887F8218(void *a, void *b, u32 *key);
/* 0x88943ED0: collect the groups whose record pair matches the key pair */
void ts4_collect_groups_88943ED0(Cx37Hub *o, Cx37Root *root, Cx37PVec *vec)
{
    struct { u32 key; Cx37Grp *val; } L;
    Cx37Grp *g;
    u32 i;
    if (root == 0)
        return;
    for (i = 0; i < root->n; i++) {
        g = (Cx37Grp *)((char *)root + root->off + i * 16);
        L.val = g;
        if (g->n > 0) {
            L.key = lbl_88D45B1C->w27c;
            if (fn_887F8218(o->w20, &g->wc, &L.key) != 0) {
                Cx37Rec *it = (Cx37Rec *)((char *)g + g->off);
                if (it->key == 0x63D9A4EA) {
                    if (*(u32 *)((char *)it + it->off) == 0xF40584B2)
                        cx37_push2(vec, g, (u32 *)&L.val);
                }
            }
        }
    }
}
/* 0x88943FD0: collect the groups whose record pair does not match the key pair */
void ts4_collect_groups_not_88943FD0(Cx37Hub *o, Cx37Root *root, Cx37PVec *vec)
{
    struct { Cx37Grp *val; u32 key; } L;
    Cx37Grp *g;
    u32 i;
    if (root == 0)
        return;
    for (i = 0; i < root->n; i++) {
        g = (Cx37Grp *)((char *)root + root->off + i * 16);
        L.val = g;
        if (g->n > 0) {
            L.key = lbl_88D45B1C->w27c;
            if (fn_887F8218(o->w20, &g->wc, &L.key) != 0) {
                Cx37Rec *it = (Cx37Rec *)((char *)g + g->off);
                if (it->key != 0x63D9A4EA || *(u32 *)((char *)it + it->off) != 0xF40584B2)
                    cx37_push2(vec, g, (u32 *)&L.val);
            }
        }
    }
}
#endif

typedef struct Cx37E8 { u32 a, b; } Cx37E8;
typedef struct Cx37Vec8 { Cx37E8 *first; Cx37E8 *last; } Cx37Vec8;
CX37_INL Cx37E8 *cx37_copy8(Cx37E8 *first, Cx37E8 *last, Cx37E8 *dst)
{
    int n = last - first;
    Cx37E8 *s = first;
    Cx37E8 *p = dst;
    while (n > 0) {
        *p = *s;
        n--;
        s++;
        p++;
    }
    return p;
}
typedef struct Cx37MItem { u8 pad[4]; struct Cx37MDst *w4; u8 pad2[0x54 - 8]; void *w54; } Cx37MItem;
struct Cx37MDst { u8 pad[4]; u32 n; u8 pad2[0x8c - 8]; void *w8c; };
typedef struct Cx37Snap {
    u8 pad[0x20];
    void *w20;
    u8 pad2[0x60 - 0x24];
    Cx37MItem **first;
    Cx37MItem **last;
    u8 pad3[0xa8 - 0x68];
    u8 ba8;
    u8 pad4[0xec - 0xa9];
    Cx37Vec8 v;
} Cx37Snap;
#ifdef _MSC_VER
#pragma function(memcpy)
extern void *memcpy(void *, const void *, unsigned int);
#endif
extern void fn_8898F5E0(void *w);
/* 0x88953FA0: clear the vector at +0xEC, then optionally copy each item's data block */
void ts4_snapshot_clear_88953FA0(Cx37Snap *o, u32 flag)
{
    Cx37MItem **p;
    Cx37Vec8 *v = &o->v;
    v->last = cx37_copy8(v->last, v->last, v->first);
    fn_8898F5E0(o->w20);
    if (o->ba8 != 0 && (u8)flag) {
        for (p = o->first; p != o->last; p++) {
            Cx37MItem *e = *p;
            if (e)
                memcpy(e->w4->w8c, e->w54, e->w4->n * 12);
        }
    }
}

typedef struct Cx37PV { void *first; void *last; } Cx37PV;
typedef struct Cx37Own3 { u8 pad[0xd0]; Cx37PV v; } Cx37Own3;
extern void fn_88161418(void *p);
extern void *ts4_copy_vec3_range_8816B0F8(void *first, void *last, void *dst);
/* 0x88948200: release the member at +0xC4, then clear the vector at +0xD0 */
void ts4_release_and_clear_88948200(Cx37Own3 *o)
{
    Cx37PV *v;
    fn_88161418((char *)o + 0xc4);
    v = &o->v;
    v->last = ts4_copy_vec3_range_8816B0F8(v->last, v->last, v->first);
}

typedef struct Cx37VObj { void **vt; } Cx37VObj;
typedef u32 (*Cx37VFn1)(Cx37VObj *o, u32 a);
extern Cx37VObj *ts4_glue_map_lookup_88941B30(void *self, u32 *key);
#if 0 /* near miss, needs the LTCG route (r5 survives the call) */
/* 0x88943CB8: call virtual slot 19 of the object found for the key */
u32 ts4_lookup_vcall_88943CB8(void *self, u32 *key, u32 arg)
{
    Cx37VObj *o = ts4_glue_map_lookup_88941B30(self, key);
    if (o)
        return ((Cx37VFn1)o->vt[19])(o, arg);
    return 0;
}

#endif
typedef struct Cx37Own24 { u8 pad[0x24]; char *w24; } Cx37Own24;
extern void fn_88953570(void *self, Cx37Arg6c *a, void *p);
/* 0x889537F0 */
void ts4_apply_two_889537F0(Cx37Own24 *o, Cx37Arg6c *a)
{
    if (a) {
        void *k = ts4_rel_table_find16_88941C68(o, a->w6c);
        char *q;
        char *p = o->w24;
        if (p)
            q = p + 0x10;
        else
            q = 0;
        fn_88953570(o, a, k);
        fn_88953570(o, a, q);
    }
}

typedef struct Cx37P3 { u32 a, b, c; } Cx37P3;
#if 0 /* near miss, not byte-identical */
typedef struct Cx37PtrVec { u32 **first; u32 **last; } Cx37PtrVec;
typedef struct Cx37Conv {
    void **vt;
    u8 pad[0x28];
    Cx37PtrVec v;
    Cx37P3 *out;
} Cx37Conv;
extern Cx37P3 fn_88923238(u32 *p, u32 a, u32 b);
extern u32 lbl_88D458B0;
extern u32 lbl_88D458AC;
/* 0x88942C80: convert every non-null source entry into the output table, then notify (vtable slot 14) */
void ts4_convert_all_88942C80(Cx37Conv *o)
{
    u32 i;
    Cx37PtrVec *v = &o->v;
    for (i = 0; i < (u32)(v->last - v->first); i++) {
        if (v->first[i] != 0) {
            Cx37P3 t = fn_88923238(v->first[i], lbl_88D458B0, lbl_88D458AC);
            o->out[i] = t;
        }
    }
    ((void (*)(Cx37Conv *))o->vt[14])(o);
}
#endif
