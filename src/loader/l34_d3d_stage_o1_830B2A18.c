/* Loader_DLL.xex 0x830B2A18-0x830CA518, executable version 0.0.0.3. */
/* D3D device per-stage state accessors (32 stages of 0x18 bytes at +0x480, dirty mask at +0x18). */
typedef unsigned int u32;
typedef unsigned long long u64;
extern float lbl_83084840[];

typedef union { float f; int i; } l34_fi_t;
typedef struct { u32 a:7; u32 f:2; u32 lo:23; } l34_w0c_t;
typedef struct { u32 a:5; u32 f:5; u32 lo:22; } l34_w10a_t;
typedef struct { u32 f:5; u32 lo:27; } l34_w10b_t;
typedef struct { u32 a:29; u32 f:1; u32 lo:2; } l34_w14a_t;
typedef struct { u32 a:30; u32 f:2; } l34_w14b_t;
typedef struct { u32 a:20; u32 f:1; u32 lo:11; } l34_w04_t;
typedef struct { u32 a:27; u32 f:2; u32 lo:3; } l34_w14c_t;
typedef struct { u32 a:20; u32 b:1; u32 lo:11; } l34_w10d_t;
typedef struct { u32 a:21; u32 b:1; u32 lo:10; } l34_w10e_t;
typedef struct { int a:23; int f:4; int lo:5; } l34_s14_t;
typedef struct { int a:10; int f:10; int lo:12; } l34_s10_t;

typedef struct { char pad[4]; l34_w04_t w04; u32 p8; l34_w0c_t w0c; l34_w10a_t w10; l34_w14a_t w14; } l34_slot_a_t;
typedef struct { char pad[4]; l34_w04_t w04; u32 p8; l34_w0c_t w0c; l34_w10b_t w10; l34_w14a_t w14; } l34_slot_b_t;
typedef struct { char pad[0x14]; l34_w14b_t w14; } l34_slot_c_t;
typedef struct { char pad[0x14]; l34_w14c_t w14; } l34_slot_d_t;
typedef struct { char pad[0xc]; u32 w0c; l34_w10d_t w10; u32 p14; } l34_slot_e_t;
typedef struct { char pad[0xc]; u32 w0c; l34_w10e_t w10; u32 p14; } l34_slot_f_t;
typedef struct { char pad[0x10]; l34_s10_t w10; l34_s14_t w14; } l34_slot_g_t;
typedef struct { char pad[4]; l34_w04_t w04; char pad2[0x10]; } l34_slot_h_t;
typedef struct { char pad[0x14]; l34_w14b_t w14; } l34_slot_i_t;
typedef struct { char pad[0x18]; u64 dirty; char pad2[0x460]; l34_slot_h_t h[32]; } l34_dev_h_t;
typedef struct { char pad[0x18]; u64 dirty; char pad2[0x460]; l34_slot_i_t i[32]; } l34_dev_i_t;
typedef struct { char pad[0x480]; l34_slot_c_t st[32]; } l34_dev_c_t;
typedef struct { char pad[0x480]; l34_slot_e_t st[32]; } l34_dev_e_t;
typedef struct { char pad[0x480]; l34_slot_f_t st[32]; } l34_dev_f_t;
typedef struct { char pad[0x480]; l34_slot_g_t st[32]; } l34_dev_g_t;

void ts4l_set_stage_w0c_830B2C98(char *p, int i, int v)
{
    u64 *f;
    l34_slot_a_t *s = (l34_slot_a_t *)p + (i + 0x30);
    s->w0c.f = v;
    f = (u64 *)(p + 0x18);
    *f |= 0x8000000000000000ULL >> (u32)(i + 0x20);
}

void ts4l_set_stage_w10a_830B3218(char *p, int i, int v)
{
    u64 *f;
    l34_slot_a_t *s = (l34_slot_a_t *)p + (i + 0x30);
    s->w10.f = v;
    f = (u64 *)(p + 0x18);
    *f |= 0x8000000000000000ULL >> (u32)(i + 0x20);
}

void ts4l_set_stage_w10b_830B3270(char *p, int i, int v)
{
    u64 *f;
    l34_slot_b_t *s = (l34_slot_b_t *)p + (i + 0x30);
    s->w10.f = v;
    f = (u64 *)(p + 0x18);
    *f |= 0x8000000000000000ULL >> (u32)(i + 0x20);
}

void ts4l_set_stage_w14a_830B32C8(char *p, int i, int v)
{
    u64 *f;
    l34_slot_a_t *s = (l34_slot_a_t *)p + (i + 0x30);
    s->w14.f = v;
    f = (u64 *)(p + 0x18);
    *f |= 0x8000000000000000ULL >> (u32)(i + 0x20);
}

void ts4l_set_stage_w14c_830B31C0(char *p, int i, int v)
{
    u64 *f;
    l34_slot_d_t *s = (l34_slot_d_t *)p + (i + 0x30);
    s->w14.f = v;
    f = (u64 *)(p + 0x18);
    *f |= 0x8000000000000000ULL >> (u32)(i + 0x20);
}

void ts4l_set_stage_w04_830B3320(char *p, int i, int v)
{
    u64 *f;
    l34_slot_a_t *s = (l34_slot_a_t *)p + (i + 0x30);
    s->w04.f = (v == 0);
    f = (u64 *)(p + 0x18);
    *f |= 0x8000000000000000ULL >> (u32)(i + 0x20);
}

void ts4l_set_stage_nz_830B3060(char *p, int i, int v)
{
    u64 *f;
    l34_slot_c_t *s = (l34_slot_c_t *)p + (i + 0x30);
    s->w14.f = (v != 0);
    f = (u64 *)(p + 0x18);
    *f |= 0x8000000000000000ULL >> (u32)(i + 0x20);
}

void ts4l_set_stage_nz_830CA3D0(l34_dev_i_t *d, int i, int v)
{
    u64 *f;
    l34_w14b_t *b = &d->i[i].w14;
    b->f = (v != 0);
    f = &d->dirty;
    *f |= 0x8000000000000000ULL >> (u32)(i + 0x20);
}

void ts4l_set_stage_zero_830CA518(l34_dev_h_t *d, int i, int v)
{
    u64 *f;
    l34_w04_t *b = &d->h[i].w04;
    b->f = (v == 0);
    f = &d->dirty;
    *f |= 0x8000000000000000ULL >> (u32)(i + 0x20);
}

u32 ts4l_get_stage_mask_830B30A8(l34_dev_c_t *d, int i)
{
    return d->st[i].w14.f ? 0xffffffffu : 0;
}

int ts4l_get_stage_scale_830B2E70(l34_dev_g_t *d, int i)
{
    l34_fi_t r;
    r.f = -((float)d->st[i].w14.f * lbl_83084840[0x168 / 4]);
    return r.i;
}

int ts4l_get_stage_scale_830B2F18(l34_dev_g_t *d, int i)
{
    l34_fi_t r;
    r.f = (float)d->st[i].w10.f * lbl_83084840[0x164 / 4];
    return r.i;
}

u32 ts4l_get_stage_mode_830B2A18(l34_dev_e_t *d, int i)
{
    l34_slot_e_t *s = &d->st[i];
    u32 m = s->w10.b - 1;
    return ((s->w0c >> 21) & m & 3) | (~m & 4);
}

u32 ts4l_get_stage_mode_830B2BC0(l34_dev_f_t *d, int i)
{
    l34_slot_f_t *s = &d->st[i];
    u32 m = s->w10.b - 1;
    return ((s->w0c >> 19) & m & 3) | (~m & 4);
}
