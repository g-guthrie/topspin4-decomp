/* CW16 part a: game core loaders/resources (0x88229BD8-0x88258E50). */
typedef unsigned int u32;
typedef unsigned char u8;

extern void *fn_88562DC0(void *dst, const void *src, u32 n);
extern u8 fn_8821A9F8(u32 a, u32 b);
extern void fn_8825A068(u32 *p, u32 v);
extern void fn_88236358(u32 *first, u32 *last, u32 zero, u32 depth, u32 cmp);

/* 0x8822BF18: vector with four inline slots; when the heap block holds fewer than four elements move the contents back to the inline storage */
typedef struct Cw16InlineVec { u32 *begin; u32 *end; u32 inl[4]; u32 *cap; } Cw16InlineVec;
void ts4_inline_vec_shrink_8822BF18(Cw16InlineVec *self)
{
    u32 *begin = self->begin;
    if ((u32)(self->cap - begin) < 4) {
        u32 *end = self->end;
        int n = end - begin;
        u32 *dst;
        if (begin) {
            u32 *d = self->inl;
            if (end != begin) fn_88562DC0(d, begin, (u32)((char *)self->end - (char *)begin));
            dst = d;
        } else {
            dst = self->inl;
        }
        self->begin = dst;
        self->cap = dst + 4;
        self->end = dst + n;
    }
}

/* 0x882563A8: insertion (third argument is an unused comparer):  sort of a pointer array */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_insertion_sort_882563A8(u32 *first, u32 *last, u32 cmp)
{
    u32 *p;
    (void)cmp;
    if (first == last) return;
    p = first + 1;
    if (p == last) return;
    do {
        u32 v = *p;
        if (fn_8821A9F8(v, *first)) {
            int d = (char *)p - (char *)first;
            if (d > 0) fn_88562DC0((u32 *)((char *)p - d + 4), first, (u32)d);
            *first = v;
        } else {
            fn_8825A068(p, v);
        }
        ++p;
    } while (p != last);
}

/* 0x8822A1E8: introsort driver with 16-element insertion-sort threshold */
void ts4_sort_ptrs_8822A1E8(u32 *first, u32 *last, u32 cmp)
{
    int n, k, m;
    u32 *p;
    if (first == last) return;
    n = (int)(last - first);
    k = 0;
    for (m = n; m != 1; m >>= 1) k++;
    fn_88236358(first, last, 0, (u32)(k << 1), cmp);
    if (n > 16) {
        p = first + 16;
        ts4_insertion_sort_882563A8(first, p, cmp);
        if (p == last) return;
        do {
            fn_8825A068(p, *p);
            p++;
        } while (p != last);
    } else {
        ts4_insertion_sort_882563A8(first, last, cmp);
    }
}

/* ---- 0x2c-byte records with two vtable stores ---- */
extern char lbl_880F2480[];
extern char lbl_880F2508[];
typedef struct Cw16Rec2c { const void *vt; u32 f4, f8, fc; u8 b10; u32 f14, f18, f1c, f20, f24; u8 b28, b29; } Cw16Rec2c;

/* 0x88236578: uninitialised copy of 0x2c-byte records [first,last) to dest; returns the end of dest */
Cw16Rec2c *ts4_uninit_copy_rec2c_88236578(Cw16Rec2c *first, Cw16Rec2c *last, Cw16Rec2c *dest)
{
    const void *v2 = lbl_880F2508;
    const void *v1 = lbl_880F2480;
    if (first == last) return dest;
    do {
        if (dest) {
            dest->vt = v1;
            dest->f4 = first->f4;
            dest->f8 = first->f8;
            dest->fc = first->fc;
            dest->b10 = first->b10;
            dest->f14 = first->f14;
            dest->vt = v2;
            dest->f18 = first->f18;
            dest->f1c = first->f1c;
            dest->f20 = first->f20;
            dest->f24 = first->f24;
            dest->b28 = first->b28;
            dest->b29 = first->b29;
        }
        first++;
        dest++;
    } while (first != last);
    return dest;
}

