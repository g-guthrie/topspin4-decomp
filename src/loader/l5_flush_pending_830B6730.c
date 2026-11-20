/* Loader_DLL.xex 0x830B6730-0x830B7264 (two identical copies), executable version 0.0.0.3.
 * D3D device: flush the pending dirty-state masks (five 64-bit words)
 * into the command-buffer writers. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif

typedef struct {
    ts4_u64 w0;                 /* 0x00 */
    ts4_u64 w8;                 /* 0x08 */
    ts4_u64 w10;                /* 0x10 */
    ts4_u64 w18;                /* 0x18 */
    ts4_u64 w20;                /* 0x20 */
    ts4_u64 w28;                /* 0x28 */
    unsigned char pad0[0x2940 - 0x30];
    unsigned u2940;
    unsigned char pad1[0x2ac0 - 0x2944];
    unsigned char flags;        /* 0x2ac0 */
} Ts4lDev;

extern void fn_830D4108(Ts4lDev *d, ts4_u64 mask, int size, void *dst);
extern ts4_u64 fn_830D5268(Ts4lDev *d, ts4_u64 v);
extern ts4_u64 fn_830D39D8(Ts4lDev *d, ts4_u64 v, unsigned x);
extern void fn_830D3D70(Ts4lDev *d, ts4_u64 v, int size, void *dst);
extern void fn_830D3FB0(Ts4lDev *d, ts4_u64 v);
extern void fn_830D3E30(Ts4lDev *d, ts4_u64 v);
extern void fn_830AA940(Ts4lDev *d);

#define OFF(d, o) ((char *)(d) + (o))

void ts4l_flush_pending_830B6730(Ts4lDev *d)
{
    ts4_u64 a = d->w0;
    ts4_u64 g = d->w20;
    ts4_u64 e = d->w18;
    ts4_u64 c = d->w10;
    ts4_u64 b = d->w8;

    if (a) {
        fn_830D4108(d, a, 0x4000, OFF(d, 0x780));
        d->w0 = 0;
    }
    if (b) {
        fn_830D4108(d, b, 0x4400, OFF(d, 0x1780));
        d->w8 = 0;
    }
    if (c) {
        if (c & 0x1e0000)
            c = fn_830D5268(d, c);
        if (d->w28 & c)
            c = fn_830D39D8(d, c, d->u2940);
        if (c & 0xfffULL)
            fn_830D3D70(d, (c & 0xfffULL) << 52, 0x2200, OFF(d, 0x2934));
        if (c & 0x1f000ULL)
            fn_830D3D70(d, (c & 0x1f000ULL) << 47, 0x2180, OFF(d, 0x2920));
        if (c & (0xffffULL << 42))
            fn_830D3D70(d, (c & (0xffffULL << 42)) << 6, 0x2000, OFF(d, 0x2880));
        if (c & 0x3ffffe00000ULL)
            fn_830D3D70(d, (c & 0x3ffffe00000ULL) << 22, 0x2100, OFF(d, 0x28cc));
        d->w10 = 0;
    }
    if (e) {
        if (e & 0xffffffffULL)
            fn_830D3FB0(d, (e & 0xffffffffULL) << 32);
        if (e & (0x1fffffULL << 34))
            fn_830D3D70(d, (e & (0x1fffffULL << 34)) << 9, 0x2280, OFF(d, 0x2964));
        d->w18 = 0;
    }
    if (g) {
        if (g & (0xffULL << 38))
            fn_830D3D70(d, (g & (0xffULL << 38)) << 18, 0x2380, OFF(d, 0x2a50));
        if (g & (0x3fULL << 49))
            fn_830D3E30(d, (g & (0x3fULL << 49)) << 9);
        if (g & (1ULL << 56))
            fn_830D3D70(d, (ts4_s64)(int)0xff000000, 0x4900, OFF(d, 0x2780));
        if (g & 0x3fffffffffULL)
            fn_830D3D70(d, (g & 0x3fffffffffULL) << 26, 0x2300, OFF(d, 0x29b8));
        if (g & 0xc000000000000000ULL) {
            if ((d->flags & ~0x7f) || (d->flags & 0x40))
                fn_830AA940(d);
        }
        d->w20 = 0;
    }
}

void ts4l_flush_pending_830B7008(Ts4lDev *d)
{
    ts4_u64 a = d->w0;
    ts4_u64 g = d->w20;
    ts4_u64 e = d->w18;
    ts4_u64 c = d->w10;
    ts4_u64 b = d->w8;

    if (a) {
        fn_830D4108(d, a, 0x4000, OFF(d, 0x780));
        d->w0 = 0;
    }
    if (b) {
        fn_830D4108(d, b, 0x4400, OFF(d, 0x1780));
        d->w8 = 0;
    }
    if (c) {
        if (c & 0x1e0000)
            c = fn_830D5268(d, c);
        if (d->w28 & c)
            c = fn_830D39D8(d, c, d->u2940);
        if (c & 0xfffULL)
            fn_830D3D70(d, (c & 0xfffULL) << 52, 0x2200, OFF(d, 0x2934));
        if (c & 0x1f000ULL)
            fn_830D3D70(d, (c & 0x1f000ULL) << 47, 0x2180, OFF(d, 0x2920));
        if (c & (0xffffULL << 42))
            fn_830D3D70(d, (c & (0xffffULL << 42)) << 6, 0x2000, OFF(d, 0x2880));
        if (c & 0x3ffffe00000ULL)
            fn_830D3D70(d, (c & 0x3ffffe00000ULL) << 22, 0x2100, OFF(d, 0x28cc));
        d->w10 = 0;
    }
    if (e) {
        if (e & 0xffffffffULL)
            fn_830D3FB0(d, (e & 0xffffffffULL) << 32);
        if (e & (0x1fffffULL << 34))
            fn_830D3D70(d, (e & (0x1fffffULL << 34)) << 9, 0x2280, OFF(d, 0x2964));
        d->w18 = 0;
    }
    if (g) {
        if (g & (0xffULL << 38))
            fn_830D3D70(d, (g & (0xffULL << 38)) << 18, 0x2380, OFF(d, 0x2a50));
        if (g & (0x3fULL << 49))
            fn_830D3E30(d, (g & (0x3fULL << 49)) << 9);
        if (g & (1ULL << 56))
            fn_830D3D70(d, (ts4_s64)(int)0xff000000, 0x4900, OFF(d, 0x2780));
        if (g & 0x3fffffffffULL)
            fn_830D3D70(d, (g & 0x3fffffffffULL) << 26, 0x2300, OFF(d, 0x29b8));
        if (g & 0xc000000000000000ULL) {
            if ((d->flags & ~0x7f) || (d->flags & 0x40))
                fn_830AA940(d);
        }
        d->w20 = 0;
    }
}
