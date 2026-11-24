/* CW16 part b: game core loaders/resources (0x88229BD8-0x88258E50), range helpers. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CW16_INL static __forceinline
typedef unsigned int Cw16Up;
#else
#define CW16_INL static inline
typedef unsigned long Cw16Up;
#endif

extern void *fn_88562DC0(void *dst, const void *src, u32 n);
extern void fn_88162768(void *dst, const void *src);
extern void fn_88235D80(void *dst, const void *src);

typedef struct Cw16Rec14 { u32 w0, w4, w8, wc, w10; } Cw16Rec14;

/* 0x88233C68: uninitialised copy of 0x14-byte records [first,last) to dest (first four words by a copy helper, then the last word); returns the end of dest */
Cw16Rec14 *ts4_uninit_copy_rec14_88233C68(Cw16Rec14 *first, Cw16Rec14 *last, Cw16Rec14 *dest)
{
    if (first != last) {
        do {
            if (dest) {
                fn_88162768(dest, first);
                dest->w10 = first->w10;
            }
            first++;
            dest++;
        } while (first != last);
    }
    return dest;
}

/* 0x88233E30: same copy with a different element helper */
Cw16Rec14 *ts4_uninit_copy_rec14_88233E30(Cw16Rec14 *first, Cw16Rec14 *last, Cw16Rec14 *dest)
{
    if (first != last) {
        do {
            if (dest) {
                fn_88235D80(dest, first);
                dest->w10 = first->w10;
            }
            first++;
            dest++;
        } while (first != last);
    }
    return dest;
}

typedef struct Cw16Rec3c { u8 pad[0x1c]; char *vbegin; char *vend; u8 pad2[0x3c - 0x20 - 4]; } Cw16Rec3c;
CW16_INL char *cw16_copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        u32 n = (u32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}

/* 0x88233FE0: empty the vector held in each 0x3c-byte record of [first,last) */
void ts4_clear_rec3c_vectors_88233FE0(Cw16Rec3c *first, Cw16Rec3c *last)
{
    if (first != last) {
        do {
            first->vend = cw16_copy(first->vend, first->vend, first->vbegin);
            first++;
        } while (first != last);
    }
}

/* ---- 0x10-byte records with a vtable ---- */
extern char lbl_880F228C[];
typedef struct Cw16Rec10 { const void *vt; u32 f4, f8; u8 bc, bd; } Cw16Rec10;

/* 0x88234290: uninitialised copy of 0x10-byte records [first,last) to dest; returns the end of dest */
Cw16Rec10 *ts4_uninit_copy_rec10_88234290(Cw16Rec10 *first, Cw16Rec10 *last, Cw16Rec10 *dest)
{
    if (first == last) return dest;
    do {
        if (dest) {
            dest->vt = lbl_880F228C;
            dest->f4 = first->f4;
            dest->f8 = first->f8;
            dest->bc = first->bc;
            dest->bd = first->bd;
        }
        first++;
        dest++;
    } while (first != last);
    return dest;
}

/* ---- 0x2c-byte records with two vtable stores ---- */
extern char lbl_880F2480[];
extern char lbl_880F2508[];
typedef struct Cw16Rec2c { const void *vt; u32 f4, f8, fc; u8 b10; u32 f14, f18, f1c, f20, f24; u8 b28, b29; } Cw16Rec2c;

/* 0x88236618: assign the prototype's fields to every record of [first,last) (the vtable pointer is left alone) */
void ts4_fill_rec2c_88236618(Cw16Rec2c *first, Cw16Rec2c *last, const Cw16Rec2c *src)
{
    if (first == last) return;
    do {
        first->f4 = src->f4;
        first->f8 = src->f8;
        first->fc = src->fc;
        first->b10 = src->b10;
        first->f14 = src->f14;
        first->f18 = src->f18;
        first->f1c = src->f1c;
        first->f20 = src->f20;
        first->f24 = src->f24;
        first->b28 = src->b28;
        first->b29 = src->b29;
        first++;
    } while (first != last);
}

/* 0x88236690: small-string with 0x80 inline bytes: when the heap block is 1..128 bytes move the text back inline and terminate it */
typedef struct Cw16InlStr { char *begin; char *end; char inl[0x80]; char *cap; } Cw16InlStr;
void ts4_inline_str_shrink_88236690(Cw16InlStr *self)
{
    char *begin = self->begin;
    if ((u32)(self->cap - begin - 1) <= 0x7f) {
        char *d;
        char *end = self->end;
        char *inl = self->inl;
        if (end == begin) {
            d = inl;
        } else {
            u32 n = (u32)(end - begin);
            d = (char *)fn_88562DC0(inl, begin, n) + n;
        }
        *d = 0;
        self->begin = inl;
        self->end = d;
        self->cap = inl + 0x80;
    }
}

extern void *ts4_assign_formatted_text(void *dst, void *src);
/* 0x88233D20: uninitialised copy of 0x20-byte records [first,last) to dest; one embedded text field is assigned */
typedef struct Cw16Rec20 { u32 w0, w4; u32 t8; u32 pad[2]; u32 w14, w18, w1c; } Cw16Rec20;
Cw16Rec20 *ts4_uninit_copy_rec20_88233D20(Cw16Rec20 *first, Cw16Rec20 *last, Cw16Rec20 *dest)
{
    if (first != last) {
        do {
            if (dest) {
                dest->w0 = first->w0;
                dest->w4 = first->w4;
                ts4_assign_formatted_text(&dest->t8, (void *)(Cw16Up)first->t8);
                dest->w14 = first->w14;
                dest->w18 = first->w18;
                dest->w1c = first->w1c;
            }
            first++;
            dest++;
        } while (first != last);
    }
    return dest;
}


/* 0x8823F928: copy-construct a record (vtable pointer stored twice), then copy its 0x60-byte tail block */
extern char lbl_880F213C[];
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
typedef struct Cw16Rec80 { const void *vt; u32 f4, f8, fc, f10; u8 b14, b15; u8 pad16[10]; u8 blk[0x60]; } Cw16Rec80;




/* ---- allocated object with two allocator-backed vectors ---- */
extern void *lbl_88D45B38;
extern void *lbl_88D45AD4;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);
extern void ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(u32 *p);
extern void ts4_call_seq_fn_88255AA0_8825C7E8(void *p);
extern void fn_88255B20(void *p);
typedef struct Cw16AVec { u32 begin, end, ctx, cap; } Cw16AVec;
typedef struct Cw16TwoVec { u8 base[0x10]; Cw16AVec a; Cw16AVec b; u8 pad[0x38 - 0x30]; } Cw16TwoVec;

CW16_INL void cw16_avec_init(Cw16AVec *v, u32 z)
{
    u32 tmp = z;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&tmp);
    v->begin = z;
    v->end = z;
    v->ctx = z;
    ts4_if_call_seq_u32_lbl_88D45B38_88255AA0(&v->ctx);
    v->cap = z;
}

/* 0x88238E98: allocate a 0x38-byte object, run its base constructor, set up two empty allocator-backed vectors and finish it */
Cw16TwoVec *ts4_create_two_vec_object_88238E98(void)
{
    Cw16TwoVec *result = 0;
    u32 z = (u32)(Cw16Up)result;
    u32 ctx = z;
    Cw16TwoVec *obj;
    if (lbl_88D45AD4) ctx = *(u32 *)((char *)lbl_88D45AD4 + 0x15680);
    obj = (Cw16TwoVec *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x38, 4, ctx, 2);
    if (obj) {
        ts4_call_seq_fn_88255AA0_8825C7E8(obj);
        cw16_avec_init(&obj->a, z);
        cw16_avec_init(&obj->b, z);
        fn_88255B20(obj);
    }
    return obj ? obj : result;
}
