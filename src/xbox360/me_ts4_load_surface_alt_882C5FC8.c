/* 0x882C5FC8: like 882C5EA8 with the 0x10-byte loader (88192770 ctor, 882D1858 dtor), 882D1860 and the 15-argument copier 882C4C48. */
/* Matched on /O1 plain (agAC); the descriptor is 0x48 bytes (0x40 puts it before Info in the frame). */
typedef struct Fmt { char pad[0x30]; unsigned flags; } Fmt;
typedef struct Surf { char pad[0x18]; Fmt *fmt; } Surf;
typedef struct Loader { unsigned w[4]; } Loader;
typedef struct Info { unsigned a, b, c, d; char pad[0x28 - 0x10]; char tail[0x38]; } Info;
typedef struct Desc { unsigned f0, f4, f8, fc; char pad[0x38]; } Desc;
void ts4_set_u32_off0_88192770(Loader *l);
void ts4_forward_882D1858(Loader *l);
int fn_882D1860(Loader *l, Info *info, Surf *dst, void *e, void *f, int g, unsigned flags);
void ts4_forward_882AA058(Fmt *fmt, int level, Desc *d);
int fn_882C4C48(void *a, void *b, void *c, unsigned i0, unsigned i1, unsigned i2, unsigned i3, void *e, void *tail,
                unsigned bit, unsigned d4, unsigned d8, unsigned dc, void *g, void *h);
int ts4_load_surface_alt_882C5FC8(Surf *src, void *b, void *c, Surf *dst, void *e, void *f, void *g, void *h)
{
    Loader l;
    Info info;
    Desc d;
    int r;
    unsigned fl;
    ts4_set_u32_off0_88192770(&l);
    if (!src) {
        ts4_forward_882D1858(&l);
        return (int)0x8876086C;
    }
    if (!dst) {
        ts4_forward_882D1858(&l);
        return (int)0x8876086C;
    }
    fl = 1;
    if (src == dst) fl = 0x10001;
    r = fn_882D1860(&l, &info, dst, e, f, 0, fl);
    if (r < 0) {
        ts4_forward_882D1858(&l);
        return r;
    }
    ts4_forward_882AA058(dst->fmt, 0, &d);
    r = fn_882C4C48(src, b, c, info.a, info.b, info.c, info.d, e, info.tail,
                    (dst->fmt->flags >> 11) & 1, d.f4, d.f8, d.fc, g, h);
    if (r < 0) {
        ts4_forward_882D1858(&l);
        return r;
    }
    ts4_forward_882D1858(&l);
    return 0;
}
