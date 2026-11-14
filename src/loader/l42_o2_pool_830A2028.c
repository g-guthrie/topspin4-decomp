/* Loader_DLL.xex 0x830A2028-0x830A4E38, executable version 0.0.0.3. */
/* Small-block pool allocator (free-list per 8-byte size class, spin lock) and its vector users. */
typedef unsigned int u32;
#ifndef _MSC_VER
#define __forceinline inline
#endif
extern void ts4_tailcall_fn_833E74C0_833E1758(void *p);
extern void fn_830A50C0(void);
extern void *lbl_83544F68[];
extern volatile int lbl_83544FA8;

static __forceinline void pool_free(void *p, u32 n)
{
    void **fl;
    if (n > 0x80) {
        ts4_tailcall_fn_833E74C0_833E1758(p);
    } else {
        fl = lbl_83544F68 + ((n - 1) >> 3);
        fn_830A50C0();
        *(void **)p = *fl;
        *fl = p;
        lbl_83544FA8 = 0;
    }
}

void ts4l_pool_free_830A30C0(void *p, u32 n)
{
    pool_free(p, n);
}

void ts4l_pool_free_830A31B0(void *p, u32 n)
{
    pool_free(p, n);
}

void ts4l_pool_free_x16_830A2D08(void *p, u32 n)
{
    pool_free(p, n * 16);
}

void ts4l_pool_free_x4_830A2E98(void *p, u32 n)
{
    pool_free(p, n * 4);
}

void ts4l_pool_free_x12_830A3030(void *p, u32 n)
{
    pool_free(p, n * 12);
}

void ts4l_pool_free_x20_830A2A80(void *p, u32 n)
{
    pool_free(p, n * 20);
}

extern void *fn_833E0AB0(u32 n);
extern void *fn_830A43E0(u32 n);

static __forceinline void *pool_alloc(u32 n)
{
    void **fl;
    void *r;
    if (n > 0x80)
        return fn_833E0AB0(n);
    fl = lbl_83544F68 + ((n - 1) >> 3);
    fn_830A50C0();
    r = *fl;
    if (r)
        *fl = *(void **)r;
    else
        r = fn_830A43E0(n);
    lbl_83544FA8 = 0;
    return r;
}

void *ts4l_pool_alloc_x16_830A2C88(u32 n)
{
    return pool_alloc(n * 16);
}

void *ts4l_pool_alloc_x4_830A2E18(u32 n)
{
    return pool_alloc(n * 4);
}

void *ts4l_pool_alloc_830A3130(u32 n)
{
    return pool_alloc(n);
}

typedef struct E16 { int a[4]; } E16;
typedef struct E12 { int a[3]; } E12;
typedef struct E20 { int a[5]; } E20;
typedef struct Vec16 { E16 *first; E16 *last; E16 *end; } Vec16;
typedef struct Vec12 { E12 *first; E12 *last; E12 *end; } Vec12;
typedef struct Vec20 { E20 *first; E20 *last; E20 *end; } Vec20;

void ts4l_vec16_free_830A26C8(Vec16 *v)
{
    E16 *p = v->first;
    if (p)
        pool_free(p, (u32)((v->end - p) * 16));
}

void ts4l_vec12_free_830A29D0(Vec12 *v)
{
    E12 *p = v->first;
    if (p)
        pool_free(p, (u32)((v->end - p) * 12));
}

void ts4l_vec20_free_830A23D8(Vec20 *v)
{
    E20 *p = v->first;
    if (p)
        pool_free(p, (u32)((v->end - p) * 20));
}

typedef struct VecB { char *first; char *last; char *end; } VecB;
VecB *ts4l_vecb_free_ret_830A3C58(VecB *v)
{
    char *p = v->first;
    u32 n = (u32)(v->end - p);
    if (p)
        pool_free(p, n);
    return v;
}

void *ts4l_pool_alloc_small_830A3BA8(u32 n)
{
    void **fl = lbl_83544F68 + ((n - 1) >> 3);
    void *r;
    fn_830A50C0();
    r = *fl;
    if (r)
        *fl = *(void **)r;
    else
        r = fn_830A43E0(n);
    lbl_83544FA8 = 0;
    return r;
}

void ts4l_pool_free_small_830A3C10(void *p, u32 n)
{
    void **fl = lbl_83544F68 + ((n - 1) >> 3);
    fn_830A50C0();
    *(void **)p = *fl;
    *fl = p;
    lbl_83544FA8 = 0;
}

typedef struct Ent16 { char *first; char *last; char *end; int pad; } Ent16;
typedef struct VV { char *first; Ent16 *last; } VV;
void ts4l_vecvec_pop_830A2028(VV *v)
{
    Ent16 *e = v->last - 1;
    char *p;
    u32 n;
    v->last = e;
    n = (u32)(e->end - e->first);
    p = e->first;
    if (p)
        pool_free(p, n);
}

void ts4l_vec20_free_830A3E80(Vec20 *v)
{
    E20 *p = v->first;
    if (p)
        pool_free(p, (u32)((v->end - p) * 20));
}

void *ts4l_pool_alloc_830A3FC8(u32 n)
{
    return pool_alloc(n);
}

VecB *ts4l_vecb_free_ret_830A4E38(VecB *v)
{
    char *p = v->first;
    u32 n = (u32)(v->end - p);
    if (p)
        pool_free(p, n);
    return v;
}
