/* CX17 part a: game core 0x88258E50-0x88287D28 (containers, uninitialized copy/fill loops, dtors). Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;

/* ---- 0x88270720: construct a range of 0x14-byte records (vtable lbl_880D6B70 + 4 words) from [first,last) into dst ---- */
extern char lbl_880D6B70[];
typedef struct Cx17E14 { const void *vt; u32 a, b, c, d; } Cx17E14;
Cx17E14 *ts4_uninit_copy_e14_88270720(Cx17E14 *first, Cx17E14 *last, Cx17E14 *dst)
{
    for (; first != last; first++, dst++) {
        if (dst != 0) {
            dst->vt = lbl_880D6B70;
            dst->a = first->a;
            dst->b = first->b;
            dst->c = first->c;
            dst->d = first->d;
        }
    }
    return dst;
}

/* ---- 0x88267688: assign one 0x20-byte record (7 words + 2 bytes) to every element of [first,last) ---- */
typedef struct Cx17E20 { u32 w[7]; u8 b0, b1; u8 pad[2]; } Cx17E20;
void ts4_fill_e20_88267688(Cx17E20 *first, Cx17E20 *last, const Cx17E20 *src)
{
    for (; first != last; first++) {
        first->w[0] = src->w[0];
        first->w[1] = src->w[1];
        first->w[2] = src->w[2];
        first->w[3] = src->w[3];
        first->w[4] = src->w[4];
        first->w[5] = src->w[5];
        first->w[6] = src->w[6];
        first->b0 = src->b0;
        first->b1 = src->b1;
    }
}

/* ---- slot pools: push the slot index on the free list (grow when full), tear the slot down, then compact ---- */
typedef struct Cx17PtrV { u32 p0; u32 *end; u32 p8; u32 *cap; } Cx17PtrV;
typedef struct Cx17H { u8 pad[0x10]; Cx17PtrV v; u8 *arr; } Cx17H;
extern void fn_8825E9D0(void *, void *, void *, u32, u32);
extern void ts4_remove_swap_8825E8B0(void *, u32);
extern void ts4_destroy_owned_object(void *);

/* 0x88258F90: slots are 12 bytes, the first word owns an object */
void ts4_ptrvec_add_destroy12_88258F90(Cx17H *h, u32 idx)
{
    Cx17PtrV *v = &h->v;
    u32 tmp = idx;
    u32 *end = v->end;
    if (end != v->cap) {
        if (end != 0) *end = tmp;
        v->end++;
    } else {
        fn_8825E9D0(v, end, &tmp, 1, 1);
    }
    ts4_destroy_owned_object(*(void **)(h->arr + idx * 12));
    ts4_remove_swap_8825E8B0(h, idx);
}

/* 0x8825E900: slots are 0x44 bytes with a vtable; slot 1 of the vtable is called with 0 */
typedef struct Cx17VObj { const struct Cx17Vt *vt; } Cx17VObj;
typedef struct Cx17Vt { void *s0; void (*slot1)(Cx17VObj *, u32); } Cx17Vt;
void ts4_ptrvec_add_vcall44_8825E900(Cx17H *h, u32 idx)
{
    Cx17PtrV *v = &h->v;
    u32 tmp = idx;
    u32 *end = v->end;
    if (end != v->cap) {
        if (end != 0) *end = tmp;
        v->end++;
    } else {
        fn_8825E9D0(v, end, &tmp, 1, 1);
    }
    {
        Cx17VObj *o = (Cx17VObj *)(h->arr + idx * 0x44);
        o->vt->slot1(o, 0);
    }
    ts4_remove_swap_8825E8B0(h, idx);
}
