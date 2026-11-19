/* CX46 part a: Pam Display renderer small helpers (0x88720000-0x88740000), plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long long u64;
#ifdef _MSC_VER
#define CX46_INL static __forceinline
#else
#define CX46_INL static inline
#endif
#define W(p, o) (*(u32 *)((char *)(p) + (o)))
#define B(p, o) (*(u8 *)((char *)(p) + (o)))
#define VW(p, o) (*(volatile u32 *)((char *)(p) + (o)))

extern char *lbl_88D45AD4;

/* 0x88738B58: renderer state word at dev+0x2948, byte field bits 3..10, mark dirty bit 0x40 */
void ts4_gfx_set_state_2948_shift3_88738B58(u32 v)
{
    char *d = *(char **)(lbl_88D45AD4 + 0x15720);
    VW(d, 0x2948) = (W(d, 0x2948) & 0xfffff807u) | ((v << 3) & 0x7f8u);
    *(volatile u64 *)(d + 0x10) |= 0x40ULL;
}

CX46_INL void setlow_2948(u32 v)
{
    char *d = *(char **)(lbl_88D45AD4 + 0x15720);
    VW(d, 0x2948) = (W(d, 0x2948) & 0xfffffff8u) | (v & 0x7u);
    *(volatile u64 *)(d + 0x10) |= 0x40ULL;
}

/* 0x88738B88: low three bits of the state word, cleared when the flag byte is set */
void ts4_gfx_set_state_2948_low_88738B88(char *self, u32 v)
{
    if (B(self, 9) != 0)
        setlow_2948(0);
    else
        setlow_2948(v);
}

typedef struct Cx46XRef { int node; u32 offset; } Cx46XRef;
CX46_INL u8 cx46_xref_invalid(Cx46XRef *r) { return r->node == 0 || r->offset == 0xfffff; }
extern void fn_88721F10(void *self);
extern void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(u32 *p);
extern void ts4_if_call_seq_u32_off0_882240E8(void *p);
extern void *ts4_if_call_seq_lbl_880F7EE4_88617D28(void *p);
extern char lbl_880F2918[], lbl_880F22E8[], lbl_880F26E0[];
extern u32 lbl_88D45AD8;
extern u32 lbl_88D45AC8;
extern void fn_887208D0(void *self);
extern u32 ts4_if_get_u32_off34_88717650(void *p);
extern u32 ts4_if_get_u32_off0_8871E468(void *p);
extern u32 fn_8872F390(void *p);

CX46_INL int cx46_dec(int *p)
{
    *p = *p - 1;
    return *p;
}

/* 0x88720B08: base update, then count down a refcount at +0x3c and release at zero */
void ts4_refcount_release_88720B08(char *self)
{
    fn_887208D0(self);
    if (W(self, 0x34) != 0 && *(int *)(self + 0x38) != 0) {
        if (*(int *)(self + 0x3c) > 0) {
            if (cx46_dec((int *)(self + 0x3c)) == 0)
                ts4_if_get_u32_off34_88717650(self);
        }
    }
}

typedef struct Cx46AVec { u32 begin, end, ctx, cap; } Cx46AVec;
CX46_INL void cx46_avec_init(Cx46AVec *v, u32 z)
{
    u32 tmp = z;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
    v->begin = z;
    v->end = z;
    v->ctx = z;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&v->ctx);
    v->cap = z;
}

/* 0x88724548: constructor with an allocator-backed vector at +0x44 */
char *ts4_ctor_avec_88724548(char *self)
{
    fn_88721F10(self);
    *(char **)self = lbl_880F22E8;
    cx46_avec_init((Cx46AVec *)(self + 0x44), 0);
    W(self, 8) = 0xfd66898fu;
    return self;
}

extern char lbl_880F2348[], lbl_880F23B8[], lbl_880F21E8[];
extern u32 lbl_88D45AB8;
extern void fn_8816D1A8(void *p);
extern void ts4_call_seq_fn_88255AA0_8825C7E8(void *p);
extern void fn_88226AC0(void *p);

/* 0x88731390: constructor with two allocator-backed vectors at +0x10 and +0x20 */
char *ts4_ctor_two_avec_88731390(char *self)
{
    ts4_call_seq_fn_88255AA0_8825C7E8(self);
    cx46_avec_init((Cx46AVec *)(self + 0x10), 0);
    cx46_avec_init((Cx46AVec *)(self + 0x20), 0);
    fn_88226AC0(self);
    return self;
}

CX46_INL void cx46_pair_init(char *s)
{
    W(s, 0) = 0;
    W(s, 4) = 0x8000000u;
}

/* 0x88723AD0: constructor with a sub-object at +0x38 and a block of cleared fields */
char *ts4_ctor_cleared_88723AD0(char *self)
{
    fn_88721F10(self);
    *(char **)self = lbl_880F21E8;
    fn_8816D1A8(self + 0x38);
    W(self, 0x54) = 0;
    W(self, 0x5c) = 0;
    W(self, 0x60) = 0;
    W(self, 0x64) = 0;
    W(self, 0x68) = 0;
    B(self, 0x6c) = 0;
    W(self, 0x70) = 0;
    W(self, 0x74) = 0;
    cx46_pair_init(self + 0x78);
    W(self, 0x48) = 0xffffffffu;
    W(self, 0x44) = 0xffffffffu;
    W(self, 0x4c) = 0xffffffffu;
    return self;
}

extern char lbl_880F25A8[];
extern u32 lbl_88D45AAC;
extern u32 lbl_88D49384;
extern void fn_8872C7F0(void *self, int a);
extern void fn_88581AF0(void *p);
extern void fn_886ED298(void *p);
extern void ts4_rec134_all_idle_88736B28(void *p);
extern void ts4_vec134_clear_8821FF40(void *v);

/* 0x8873B758: tear down the frame state, then check the sub-object at +0x54 */
void ts4_frame_end_8873B758(char *self)
{
    char *p;
    u32 tmp[8];
    u32 key = *(u32 *)(self + 0x1562c);
    *(u32 *)(self + 0x15658) = 0;
    if (key == 0x83199eb2u)
        fn_8872C7F0(self, -1);
    p = *(char **)(self + 0x34);
    if (B(p, 0xc) == 1) {
        fn_88581AF0(tmp);
        fn_886ED298(p);
    }
    ts4_rec134_all_idle_88736B28(*(char **)(self + 0x54));
}

typedef struct Cx46Vec { char *first; char *last; } Cx46Vec;

CX46_INL u8 cx46_all_idle(Cx46Vec *v)
{
    char *p;
    for (p = v->first; p < v->last; p += 0x134) {
        int s = *(int *)(p + 0x11c);
        if (s != 3 && s != 0)
            return 0;
    }
    return 1;
}

/* 0x88736B28: when every 0x134-byte record is idle or done, count the frame and clear after ten */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_rec134_all_idle_88736B28(Cx46Vec *v)
{
    if (cx46_all_idle(v) == 1) {
        lbl_88D49384 = lbl_88D49384 + 1;
        if (lbl_88D49384 >= 10) {
            ts4_vec134_clear_8821FF40(v);
            lbl_88D49384 = 0;
        }
    }
}

extern char lbl_880F2120[], lbl_880F2124[];
extern void fn_88227FC8(void *p);
extern void fn_88227ED8(void *p, u32 a);
extern void fn_8822C1C8(void *p, u32 a);
/* 0x88737BD0: constructor, base block at +4 with two allocator-backed vectors, then a third at +0x3c */
char *ts4_ctor_two_avec_base_88737BD0(char *self)
{
    char *b = self + 4;
    ts4_call_seq_fn_88255AA0_8825C7E8(b);
    cx46_avec_init((Cx46AVec *)(b + 0x10), 0);
    cx46_avec_init((Cx46AVec *)(b + 0x20), 0);
    fn_88227FC8(b);
    *(char **)self = lbl_880F2120;
    W(self, 0x38) = 0xffffffffu;
    cx46_avec_init((Cx46AVec *)(self + 0x3c), 0);
    return self;
}
/* 0x88736C28: same with a size set on the base and a fourth vector at +0x38 */
char *ts4_ctor_two_avec_base_88736C28(char *self)
{
    char *b = self + 4;
    ts4_call_seq_fn_88255AA0_8825C7E8(b);
    cx46_avec_init((Cx46AVec *)(b + 0x10), 0);
    cx46_avec_init((Cx46AVec *)(b + 0x20), 0);
    W(self, 0x34) = 0;
    fn_88227ED8(b, 0x24);
    *(char **)self = lbl_880F2124;
    cx46_avec_init((Cx46AVec *)(self + 0x38), 0);
    fn_8822C1C8(self + 0x38, 4);
    return self;
}

extern void *fn_88562DC0(void *dst, const void *src, u32 n);
extern void *lbl_88D45B38;
extern void ts4_if_call_seq_fn_881F04B8_886131F0(void *g, void *node, u32 a);
extern void fn_885651F8(void *node);
typedef struct Cx46Obj { void **vt; } Cx46Obj;
typedef struct Cx46PV { Cx46Obj **first; Cx46Obj **last; u32 alloc; } Cx46PV;
typedef void (*Cx46VFn)(Cx46Obj *o);
typedef void (*Cx46DelFn)(Cx46Obj *o, int flags);
CX46_INL Cx46Obj **cx46_mv(Cx46Obj **first, Cx46Obj **last, Cx46Obj **dst)
{
    if (first == last) return dst;
    {
        u32 n = (u32)((char *)last - (char *)first);
        return (Cx46Obj **)((char *)fn_88562DC0(dst, first, n) + n);
    }
}
/* 0x88721898: release and delete every object of a pointer vector, clear it and free its storage */
void ts4_pv_destroy_free_88721898(Cx46PV *v)
{
    Cx46Obj **end = v->last;
    Cx46Obj **p = v->first;
    for (; p < end; p++) {
        Cx46Obj *e = *p;
        ((Cx46VFn)e->vt[5])(e);
        e = *p;
        if (e != 0)
            ((Cx46DelFn)e->vt[0])(e, 1);
    }
    v->last = cx46_mv(v->last, v->last, v->first);
    if (v->first != 0) {
        if (lbl_88D45B38 != 0)
            ts4_if_call_seq_fn_881F04B8_886131F0(lbl_88D45B38, v->first, v->alloc);
        else
            fn_885651F8(v->first);
    }
}

typedef struct Cx46S12 { u32 a, b, c; } Cx46S12;
typedef struct Cx46PtrVec { char **first; char **last; } Cx46PtrVec;
extern char lbl_880C1320[];
extern u8 fn_8822BF98(void *, void *);
extern u32 ts4_find_service(u32 id);
extern void fn_88722CA8(Cx46S12 *out, u32 a);
extern void ts4_if_set_u32_off0_8862BE08(void *out, u32 k);

/* 0x88724300: for each entry of the pointer vector at +0x84 find its service and resolve its text ref */
void ts4_resolve_entries_88724300(char *self)
{
    char **last = ((Cx46PtrVec *)(self + 0x84))->last;
    char **p = ((Cx46PtrVec *)(self + 0x84))->first;
    if (p != last) {
        do {
            char *e = *p;
            if (W(e, 0) == 0)
                W(e, 0) = ts4_find_service(W(e, 4));
            if (cx46_xref_invalid((Cx46XRef *)(e + 0x14)) != 0) {
                if (fn_8822BF98(lbl_880C1320, e + 8) == 0) {
                    Cx46S12 t;
                    fn_88722CA8(&t, W(e, 8));
                    *(Cx46S12 *)(e + 0x14) = t;
                }
            }
            p++;
        } while (p != last);
    }
}

/* 0x8872AF50: optionally reset the ref at +0x14, resolve it from the text at +8, return whether it is valid */
u8 ts4_resolve_ref_8872AF50(char *self, u8 reset)
{
    if (reset != 0) {
        *(volatile u32 *)(self + 0x14) = 0;
        *(volatile u32 *)(self + 0x1c) = 0;
        W(self, 0x18) = 0xfffff;
    }
    if (cx46_xref_invalid((Cx46XRef *)(self + 0x14)) != 0) {
        if (fn_8822BF98(lbl_880C1320, self + 8) == 0) {
            Cx46S12 t;
            ts4_if_set_u32_off0_8862BE08(&t, W(self, 8));
            *(Cx46S12 *)(self + 0x14) = t;
        }
    }
    return 0 == cx46_xref_invalid((Cx46XRef *)(self + 0x14));
}

extern void ts4_if_set_u32_off0_8862C0E8(void *out, u32 k);

/* 0x8872B030: optionally reset the ref at +0x14, resolve it from the text at +8, return whether it is valid */
u8 ts4_resolve_ref_8872B030(char *self, u8 reset)
{
    if (reset != 0) {
        *(volatile u32 *)(self + 0x14) = 0;
        *(volatile u32 *)(self + 0x1c) = 0;
        W(self, 0x18) = 0xfffff;
    }
    if (cx46_xref_invalid((Cx46XRef *)(self + 0x14)) != 0) {
        if (fn_8822BF98(lbl_880C1320, self + 8) == 0) {
            Cx46S12 t;
            ts4_if_set_u32_off0_8862C0E8(&t, W(self, 8));
            *(Cx46S12 *)(self + 0x14) = t;
        }
    }
    return 0 == cx46_xref_invalid((Cx46XRef *)(self + 0x14));
}

extern void fn_886F5390(void *p);
extern void fn_8871C658(void *p, u32 a);
extern void fn_886F51C0(void *p, void *self, u32 b, u32 c);
extern void ts4_release_buffer_array_88711998(void *p);
extern char *lbl_88D45B1C;
/* 0x887212A8: run a job through a 0x330-byte stack object, defaulting the owner from the global */
void ts4_run_job_887212A8(char *self, u32 a, u32 b, u32 c)
{
    char obj[0x330];
    if (b == 0)
        b = *(u32 *)(lbl_88D45B1C + 0x224);
    fn_886F5390(obj);
    fn_8871C658(obj, a);
    fn_886F51C0(obj, self, b, c);
    ts4_release_buffer_array_88711998(obj);
}
