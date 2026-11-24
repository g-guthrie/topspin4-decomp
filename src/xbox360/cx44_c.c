/* CX44 part c: renderer helpers over pointer vectors and relative tables, plain route. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
#ifdef _MSC_VER
#define CX44_INL static __forceinline
#else
#define CX44_INL static inline
#endif
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))
extern int fn_8856A3A0(const char *a, const char *b);
extern char *fn_886F5FB0(char *self);

CX44_INL u32 cx44_sr8(char *blk, u32 i)
{
    char *h = blk + 8;
    return *(u32 *)(h + i * 8 + *(int *)h + 4);
}

/* 0x886EBAB8: find the 16-byte entry whose name (+0xc) equals key; returns base + its offset (+4), or null */
char *ts4_find_named_886EBAB8(char *self, char *key)
{
    if (W(self, 0x10) != 0 && key != 0) {
        int i = 0;
        u32 off;
        if (W(self, 0x14) > 0) {
            off = 0;
            do {
                if (fn_8856A3A0(key, *(char **)(*(char **)(self + 0x10) + off + 0xc)) == 0)
                    return *(char **)(*(char **)(self + 0x10) + (i << 4) + 4) + W(self, 0);
                i++;
                off += 16;
            } while ((u32)i < W(self, 0x14));
        }
    }
    return 0;
}

/* 0x886FC1C0: after resolving, refresh field +8 of each 16-byte entry from the relative table */
char *ts4_refresh_entries_886FC1C0(char *self)
{
    char *r = fn_886F5FB0(self);
    if (r != 0) {
        char *end = *(char **)(self + 0x3c);
        char *p = *(char **)(self + 0x38);
        char *o = *(char **)(self + 0x34);
        if (p != end) {
            do {
                W(p, 8) = cx44_sr8(*(char **)(o + 0xc), W(p, 4));
                p += 16;
            } while (p != end);
        }
    }
    return r;
}

/* ---- pointer vector of objects: release, delete, clear ---- */
extern void *fn_88562DC0(void *dst, const void *src, u32 n);
extern void ts4_teardown_886F1900(char *self);
typedef struct Cx44Obj { void **vt; } Cx44Obj;
typedef struct Cx44PV { Cx44Obj **first; Cx44Obj **last; } Cx44PV;
typedef void (*Cx44VFn)(Cx44Obj *o);
typedef void (*Cx44DelFn)(Cx44Obj *o, int flags);
CX44_INL Cx44Obj **cx44_mv(Cx44Obj **first, Cx44Obj **last, Cx44Obj **dst)
{
    if (first == last) return dst;
    {
        u32 n = (u32)((char *)last - (char *)first);
        return (Cx44Obj **)((char *)fn_88562DC0(dst, first, n) + n);
    }
}

/* 0x886F32B8: release and delete every object of the vector at +0x44, clear it, then finish through 0x886F1900 */
void ts4_pv_destroy_all_886F32B8(char *self)
{
    Cx44Obj **end = *(Cx44Obj ***)(self + 0x48);
    Cx44PV *v = (Cx44PV *)(self + 0x44);
    Cx44Obj **p = v->first;
    for (; p != end; p++) {
        Cx44Obj *e = *p;
        ((Cx44VFn)e->vt[2])(e);
        ((Cx44DelFn)e->vt[0])(e, 1);
    }
    v->last = cx44_mv(v->last, v->last, v->first);
    ts4_teardown_886F1900(self);
}

/* 0x886ECED0: release and delete every object of the vector at +0x18, then clear it */
void ts4_pv_destroy_all_886ECED0(char *self)
{
    Cx44Obj **end = *(Cx44Obj ***)(self + 0x1c);
    Cx44PV *v = (Cx44PV *)(self + 0x18);
    Cx44Obj **p = v->first;
    for (; p != end; p++) {
        Cx44Obj *e = *p;
        ((Cx44VFn)e->vt[1])(e);
        ((Cx44DelFn)e->vt[0])(e, 1);
    }
    v->last = cx44_mv(v->last, v->last, v->first);
}






/* 0x886FC898: if the object at +0xc has a pending slot-b counter (+0x34), clear it and latch the table value */
u8 ts4_latch_slot_b_886FC898(char *self, char *owner)
{
    if (((u8 (*)(char *))(*(void ***)self)[6])(self) != 0) {
        char *c = *(char **)(self + 0xc);
        if (*(int *)(c + 0x34) != 0) {
            *(int *)(c + 0x34) = 0;
            W(self, 0x24) = cx44_sr8(*(char **)(owner + 0xc), W(*(char **)(self + 0xc), 0x30));
            return 1;
        }
    }
    return 0;
}

/* 0x886FC9F0: same with the counter at +0x30 */
u8 ts4_latch_slot_a_886FC9F0(char *self, char *owner)
{
    if (((u8 (*)(char *))(*(void ***)self)[6])(self) != 0) {
        char *c = *(char **)(self + 0xc);
        if (*(int *)(c + 0x30) != 0) {
            *(int *)(c + 0x30) = 0;
            W(self, 0x24) = cx44_sr8(*(char **)(owner + 0xc), W(*(char **)(self + 0xc), 0x30));
            return 1;
        }
    }
    return 0;
}

extern void fn_886F6128(char *self);
/* 0x886FB3C0: reset, then call slot 3 with 0 on each of the five objects at +0xe0..+0xf0 */
void ts4_reset_objs_886FB3C0(char *self)
{
    fn_886F6128(self);
    ((void (*)(Cx44Obj *, int))(*(Cx44Obj **)(self + 0xe0))->vt[3])(*(Cx44Obj **)(self + 0xe0), 0);
    ((void (*)(Cx44Obj *, int))(*(Cx44Obj **)(self + 0xe4))->vt[3])(*(Cx44Obj **)(self + 0xe4), 0);
    ((void (*)(Cx44Obj *, int))(*(Cx44Obj **)(self + 0xe8))->vt[3])(*(Cx44Obj **)(self + 0xe8), 0);
    ((void (*)(Cx44Obj *, int))(*(Cx44Obj **)(self + 0xec))->vt[3])(*(Cx44Obj **)(self + 0xec), 0);
    ((void (*)(Cx44Obj *, int))(*(Cx44Obj **)(self + 0xf0))->vt[3])(*(Cx44Obj **)(self + 0xf0), 0);
}

extern void ts4_tsu_cleanup_end(void *p);
/* 0x886FD198: release and delete every object of the vector at +0x38, clear it, clean up +0x54, finish through 0x886F1900 */
void ts4_pv_destroy_all_886FD198(char *self)
{
    Cx44Obj **end = *(Cx44Obj ***)(self + 0x3c);
    Cx44PV *v = (Cx44PV *)(self + 0x38);
    Cx44Obj **p = v->first;
    for (; p != end; p++) {
        Cx44Obj *e = *p;
        ((Cx44VFn)e->vt[2])(e);
        ((Cx44DelFn)e->vt[0])(e, 1);
    }
    v->last = cx44_mv(v->last, v->last, v->first);
    if (W(self, 0x54) != 0) ts4_tsu_cleanup_end(*(void **)(self + 0x54));
    ts4_teardown_886F1900(self);
}

typedef struct Cx44Hdr { int rel; int cnt; } Cx44Hdr;
CX44_INL char *cx44_hb(Cx44Hdr *h)
{
    char *p = 0;
    if (h->rel != -1) p = (char *)h + h->rel;
    return p;
}
CX44_INL char *cx44_he170(Cx44Hdr *h)
{
    char *p = 0;
    if (h->rel != -1) p = (char *)h + (h->cnt * 0x170 + h->rel);
    return p;
}
extern void fn_886EABC0(char *self, char *entry);
extern char *lbl_88D45B1C;

/* 0x886EB080: tick the 0x170-byte entries of the relative table at +0x1c */
void ts4_tick_entries_886EB080(char *self)
{
    char *p = cx44_hb(*(Cx44Hdr **)(self + 0x1c));
    char *end = cx44_he170(*(Cx44Hdr **)(self + 0x1c));
    for (; p != end; p += 0x170) {
        if (W(p, 0x44) != 0) {
            if (W(p, 0x48) == 0) {
                fn_886EABC0(self, p);
                W(p, 0x44) = W(lbl_88D45B1C, 0x27c);
            } else {
                W(p, 0x48) = W(p, 0x48) - 1;
            }
        }
    }
}

/* 0x886F1900: tear down: slot 14(1), slot 19, delete every object of the vector at +0x24, clear it, reset +0x34 */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_teardown_886F1900(char *self)
{
    Cx44Obj **end;
    Cx44PV *v;
    Cx44Obj **p;
    ((void (*)(char *, int))(*(void ***)self)[14])(self, 1);
    ((void (*)(char *))(*(void ***)self)[19])(self);
    v = (Cx44PV *)(self + 0x24);
    end = *(Cx44Obj ***)(self + 0x28);
    p = v->first;
    for (; p != end; p++) {
        Cx44Obj *e = *p;
        ((Cx44VFn)e->vt[2])(e);
        ((Cx44DelFn)e->vt[0])(e, 1);
    }
    v->last = cx44_mv(v->last, v->last, v->first);
    W(self, 0x34) = 0;
}



/* 0x886F6048: find the object (vector at +0x24) with +4 == *k1 and +8 == *k2 (or *k2 == 0); else create through slot 20 */
char *ts4_find_or_make_886F6048(char *s, u32 *k1, u32 *k2, u8 make)
{
    char **end = *(char ***)(s + 0x28);
    char **p = *(char ***)(s + 0x24);
    for (; p != end; p++) {
        char *o = *p;
        if (*k1 == W(o, 4)) {
            if (*k2 == 0) return o;
            if (*k2 == W(o, 8)) return o;
        }
    }
    if (make != 0 && *k2 != 0) {
        char *(*fnp)(char *, u32 *, u32 *, int) = (char *(*)(char *, u32 *, u32 *, int))(*(void ***)s)[20];
        u32 tmp = W(lbl_88D45B1C, 0x27c);
        return fnp(s, k1, &tmp, 1);
    }
    return 0;
}
