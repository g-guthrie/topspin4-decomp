/* Loader_DLL.xex 0x830C1AF8-0x830DA620, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef long long s64;
extern void fn_833E3A30(void *dst, int c, u32 n);
extern void fn_8340C4F8(void *dst, void *src, u32 n);
extern void fn_8340BCE8(s64 *out);

typedef struct Sub { int a; u32 n; } Sub;
typedef struct DstA { char pad[0x368]; char sub[8]; } DstA;
typedef struct DstB { char pad[0x28]; char sub[8]; } DstB;

void ts4l_snapshot_830C1AF8(char *o, DstA *dst)
{
    Sub *s = (Sub *)(o + 0x368);
    u32 n = s->n;
    fn_833E3A30(dst, 0, 0x368);
    fn_8340C4F8(dst->sub, s, n);
}

void ts4l_snapshot_830C1F60(char *o, DstB *dst)
{
    Sub *s = (Sub *)(o + 0x28);
    u32 n = s->n;
    fn_833E3A30(dst, 0, 0x28);
    fn_8340C4F8(dst->sub, s, n);
}

u32 ts4l_elapsed_830DA620(char *o)
{
    s64 t;
    fn_8340BCE8(&t);
    return (u32)(t >> 10) - *(u32 *)(o + 0x5584);
}

extern char __imp_VdGlobalDevice[];

int ts4l_get_device_830D9DE8(void **out)
{
    char *dev = **(char ***)__imp_VdGlobalDevice;
    int r;
    *out = dev;
    if (dev == 0)
        return (int)0x80004005u;
    r = (*(u32 *)(dev + 0x5e88) & 0x100u) ? (int)0x80004005u : 0;
    return r;
}

typedef struct Ts4lKV { u32 key; u32 val; } Ts4lKV;
extern Ts4lKV lbl_8352DD50[];
extern u32 lbl_8352E934;
extern void fn_8340D830(void *p, u32 tag);

u32 ts4l_lookup_830DE620(u32 k)
{
    Ts4lKV *p = lbl_8352DD50;
    u32 i;
    for (i = 0; i < 9; i++, p++) {
        if (p->key == k)
            return lbl_8352DD50[i].val;
    }
    return 0;
}

u32 ts4l_rand_830DE6A0(void)
{
    u32 a;
    lbl_8352E934 = lbl_8352E934 * 0x41c64e6du + 0x3039;
    a = *(unsigned short *)&lbl_8352E934 & 0x7fff;
    lbl_8352E934 = lbl_8352E934 * 0x41c64e6du + 0x3039;
    return (lbl_8352E934 & 0x7fff0000u) + a;
}

typedef struct Ts4lSlot12 { void *p; int a, b; } Ts4lSlot12;
void ts4l_free_slots_830DFD68(Ts4lSlot12 *t)
{
    Ts4lSlot12 *p = t + 64;
    int i;
    for (i = 63; i >= 0; i--) {
        --p;
        if (p->p)
            fn_8340D830(p->p, 0x24800000u);
    }
}

extern void *fn_8340D710(u32 size, u32 tag);
void *ts4l_alloc_aligned_830AA158(void)
{
    char *p = (char *)fn_8340D710(0x5f80, 0x24800000u);
    char *r;
    if (p != 0) {
        r = (char *)(((unsigned long)p + 0x83) & ~0x7ful);
        *(char **)(r - 4) = p;
        p = r;
    }
    return p;
}

void ts4l_free_aligned_830AA200(void *p)
{
    if (p != 0)
        fn_8340D830(*(void **)((char *)p - 4), 0x24800000u);
}

