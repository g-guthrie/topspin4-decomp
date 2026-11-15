/* CW32 part b: IO result writers, vcall wrappers, float and loop helpers (Swing_DLL.xex 0x88878FA0-0x88891678). Default flags. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned long long u64;

extern float lbl_8814B440;
extern char g_ts4_script_constants[];
extern void *lbl_88D45B38;

/* ---- file-open style IO result writers (0x88886FC0, 0x88886BC0, 0x888871D0 family) ---- */
int fn_8857B848(int a, u32 b, int c, int d, int e, int f, int g);
int ts4_query_size_8857BF40(int h, int a);
void ts4_if_get_u32_lbl_88C32048_8857A1E0(int h);
void fn_8857BBB0(int h, int a, int b, int *out, int c);
int ts4_tailcall_fn_88582660_8857B840(void);
void ts4_tailcall_fn_885827E0_88563110(int a);
extern struct Cx32G { char pad[0x234]; void *tbl; } *lbl_88D45B1C;
void *fn_88614938(void *a, int b);
int ts4_call_seq_XNetLogonGetTitleID_884F1EE8(int a, void *b, int c, void *d, int e);

typedef struct Cx32Res { int w0; int w4; u8 b8; } Cx32Res;
typedef struct Cx32Ctx { char pad[0x250]; u32 *err; } Cx32Ctx;

int ts4_open_query_size_88886FC0(Cx32Ctx *c, Cx32Res *out, int a)
{
    int h = fn_8857B848(a, 0x80000000u, 1, 0, 3, 0, 0);
    int one = 1;
    int size = 0;
    if (h != -1) {
        size = ts4_query_size_8857BF40(h, 0);
        ts4_if_get_u32_lbl_88C32048_8857A1E0(h);
    } else {
        *c->err = 0x9C1C9375u;
        if (out) out->w0 = one;
    }
    out->w0 = ts4_tailcall_fn_88582660_8857B840();
    out->w4 = 0;
    out->b8 = one;
    return size;
}

typedef struct Cx32Hnd { char pad[0x10]; int id; } Cx32Hnd;
typedef struct Cx32CtxB { char pad[0x1c]; int f1c; int f20; } Cx32CtxB;
typedef struct Cx32Op3 { Cx32CtxB *c; Cx32Res *r; int *f8; int *fc; int f10; int f14; int f18; } Cx32Op3;

int ts4_titleid_result_88887610(Cx32Op3 *t)
{
    u32 rc;
    int id;
    Cx32Hnd *hd;
    int one;
    hd = (Cx32Hnd *)fn_88614938(lbl_88D45B1C->tbl, t->c->f1c);
    id = hd ? hd->id : -1;
    rc = ts4_call_seq_XNetLogonGetTitleID_884F1EE8(id, t->fc, 8, t->f8, 0);
    one = 1;
    if (rc != 0 && rc != 0x12) {
        Cx32Res *rr = t->r;
        *((Cx32Ctx *)t->c)->err = 0x9C1C9375u;
        if (rr) rr->w0 = one;
    }
    if (rc == 0x12) rc = 0;
    t->r->w0 = rc;
    t->r->w4 = *t->f8;
    t->r->b8 = one;
    ts4_tailcall_fn_885827E0_88563110(0);
    return 0;
}

typedef struct Cx32Op4 { Cx32Ctx *c; Cx32Res *r; u32 count; char names[0x1488]; } Cx32Op4;
int ts4_read_files_88886BC0(Cx32Op4 *t)
{
    int local50 = 0;
    int one = 1;
    int j = 0;
    int h;
    local50 = 0;
    if (t->count > 0) {
        int *pb = (int *)((char *)t + 0x14a8);
        char *name = (char *)t + 0xc;
        do {
            int a, b;
            h = fn_8857B848(*(int *)name, 0x80000000u, 1, 0, 3, 0, 0);
            local50 = 0;
            if (h == -1) {
                Cx32Res *rr = t->r;
                *t->c->err = 0x9C1C9375u;
                if (rr) rr->w0 = one;
                break;
            }
            a = pb[-9];
            b = *++pb;
            fn_8857BBB0(h, a, b, &local50, 0);
            ts4_if_get_u32_lbl_88C32048_8857A1E0(h);
            j++;
            name += 0x20c;
        } while ((u32)j < t->count);
    }
    {
        int r = ts4_tailcall_fn_88582660_8857B840();
        t->r->w0 = r;
        t->r->w4 = local50;
        t->r->b8 = one;
    }
    ts4_tailcall_fn_885827E0_88563110(0);
    return 0;
}

/* ---- vcall wrappers on a spilled by-address parameter (0x8888A5C8, 0x8888A658) and slot-7 test (0x88890320) ---- */
typedef struct Cx32VOp { void **vt; } Cx32VOp;
void ts4_vcall_13_10_11_8888A5C8(Cx32VOp *o, int a, int b)
{
    ((void (*)(Cx32VOp *, int *))o->vt[13])(o, &a);
    ((void (*)(Cx32VOp *, int *, int, int, int, int))o->vt[10])(o, &a, b, 0, 0, 0);
    ((void (*)(Cx32VOp *, int *))o->vt[11])(o, &a);
}
void ts4_vcall_13_10_11_15_8888A658(Cx32VOp *o, int a, int b, float f)
{
    ((void (*)(Cx32VOp *, int *))o->vt[13])(o, &a);
    ((void (*)(Cx32VOp *, int *, int, int, int, int))o->vt[10])(o, &a, b, 0, 0, 0);
    ((void (*)(Cx32VOp *, int *))o->vt[11])(o, &a);
    ((void (*)(Cx32VOp *, int *, float))o->vt[15])(o, &a, f);
}

typedef struct Cx32T8 { char pad[8]; Cx32VOp *o8; } Cx32T8;
int ts4_vcall_7_nonpositive_88890320(Cx32T8 *t, int a, int idx)
{
    int arr[3];
    arr[0] = 2; arr[1] = 0; arr[2] = 1;
    return ((int (*)(Cx32VOp *, int, int))t->o8->vt[7])(t->o8, a, arr[idx]) <= 0;
}

/* ---- allocate N nodes into an array (0x88890E98) ---- */
void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);
void ts4_alloc_nodes_88890E98(int unused, void **arr, int n, u32 sz)
{
    int i;
    (void)unused;
    for (i = 0; i < n; i++)
        arr[i] = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, sz, 0x10, 0, 2);
}

/* ---- float helpers (0x88879DA0, 0x88884C08) ---- */
void *ts4_if_get_u32_off8_8846B398(void *a, float f);
typedef struct Cx32TD { char pad[8]; int cnt; float f; void *obj; } Cx32TD;
void ts4_repeat_step_88879DA0(Cx32TD *t, u32 n)
{
    int i;
    u32 k;
    if (t->obj && t->f > lbl_8814B440 && n) {
        k = n;
        do {
            for (i = 0; i < t->cnt; i++)
                ts4_if_get_u32_off8_8846B398(t->obj, t->f / (float)t->cnt);
        } while (--k);
    }
}

void ts4_if_call_seq_u32_off0_8857B180(int a, void *b);
typedef struct Cx32T4C08 { char pad[0x14]; int f14; u16 s18; u16 s1a; } Cx32T4C08;
void ts4_set_scaled_u16_pair_88884C08(Cx32T4C08 *t, float a, float b)
{
    double K = *(double *)(g_ts4_script_constants + 0x2f8);
    u16 y = (u16)(K * b);
    u16 x = (u16)(K * a);
    if (t->s18 != x || t->s1a != y) {
        t->s1a = y;
        t->s18 = x;
        ts4_if_call_seq_u32_off0_8857B180(t->f14, &t->s18);
    }
}

/* ---- transform two vec3 by a matrix from a vcall (0x8887A488) ---- */
void ts4_transform_vec3_in_place_8864E9F8(void *a, void *b);
#ifdef _MSC_VER
#pragma function(memcpy)
void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
typedef struct Cx32V4 { float x, y, z, w; } Cx32V4;
typedef struct Cx32MObj { void (**vt)(struct Cx32MObj *, void *, void *); } Cx32MObj;
typedef struct Cx32TA { Cx32MObj vt; char pad[8]; void *c; } Cx32TA;
typedef struct Cx32SrcA { char pad[0x20]; char a[12]; char pad2[4]; char b[12]; } Cx32SrcA;
void ts4_transform_two_points_8887A488(Cx32TA *t, Cx32SrcA *s, void *d)
{
    Cx32V4 l50, l60;
    char m[0x40];
    if (t->c && s && d) {
        t->vt.vt[7](&t->vt, d, m);
        l50.x = lbl_8814B440;
        l50.y = lbl_8814B440;
        l50.z = lbl_8814B440;
        l60.x = lbl_8814B440;
        l60.y = lbl_8814B440;
        l60.z = lbl_8814B440;
        memcpy(&l50, s->a, 12);
        memcpy(&l60, s->b, 12);
        ts4_transform_vec3_in_place_8864E9F8(&l50, m);
        ts4_transform_vec3_in_place_8864E9F8(&l60, m);
    }
}

/* ---- content device free-space check (0x88885228) ---- */
u64 fn_8857B308(u32 a, u32 b);
u32 ts4_tailcall_XamContentGetDeviceData_8857B300(int a, void *b);
typedef struct Cx32Dev { char pad[0x10]; u64 freebytes; char rest[0x38]; } Cx32Dev;
typedef struct Cx32T5228 { char pad[0x20]; u32 h; } Cx32T5228;
u8 ts4_content_has_space_88885228(Cx32T5228 *t)
{
    Cx32Dev d;
    u8 r = 0;
    u64 need = fn_8857B308(0x2AB980, 0);
    if (t->h != 0 && ts4_tailcall_XamContentGetDeviceData_8857B300(t->h, &d) == 0)
        r = need <= d.freebytes;
    return r;
}
