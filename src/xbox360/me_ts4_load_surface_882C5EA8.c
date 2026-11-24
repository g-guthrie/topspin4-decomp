/* 0x882C5EA8: loads src into dst through a 0x14-byte loader (885D94F8 ctor, 882D1330 dtor): 882D1338 describes dst, then 882C4350 copies. */
/* Matched on /O1 plain (agAC): C++-style dtor before every return; the 0x2AA058 descriptor must be 0x48 bytes for the frame layout. */
typedef struct Fmt { char pad[0x30]; unsigned flags; } Fmt;
typedef struct Surf { char pad[0x18]; Fmt *fmt; } Surf;
typedef struct Loader { unsigned w[8]; } Loader;
typedef struct Info { unsigned a, b, c; char pad[0x28 - 0xC]; char tail[0x38]; } Info;
typedef struct Desc { unsigned f0, f4, f8, fc; char pad[0x38]; } Desc;
void ts4_zero_five_words_885D94F8(Loader *l);
void ts4_forward_882D1330(Loader *l);
int fn_882D1338(Loader *l, Info *info, Surf *dst, void *e, void *f, int g, unsigned flags);
void ts4_forward_882AA058(Fmt *fmt, int level, Desc *d);
int fn_882C4350(void *a, void *b, void *c, unsigned i0, unsigned i1, unsigned i2, void *e, void *tail,
                unsigned bit, unsigned d4, unsigned d8, void *g, void *h);
int ts4_load_surface_882C5EA8(Surf *src, void *b, void *c, Surf *dst, void *e, void *f, void *g, void *h)
{
    Loader l;
    Info info;
    Desc d;
    int r;
    unsigned fl;
    ts4_zero_five_words_885D94F8(&l);
    if (!src) {
        ts4_forward_882D1330(&l);
        return (int)0x8876086C;
    }
    if (!dst) {
        ts4_forward_882D1330(&l);
        return (int)0x8876086C;
    }
    fl = 1;
    if (src == dst) fl = 0x10001;
    r = fn_882D1338(&l, &info, dst, e, f, 0, fl);
    if (r < 0) {
        ts4_forward_882D1330(&l);
        return r;
    }
    ts4_forward_882AA058(dst->fmt, 0, &d);
    r = fn_882C4350(src, b, c, info.a, info.b, info.c, e, info.tail,
                    (dst->fmt->flags >> 11) & 1, d.f4, d.f8, g, h);
    if (r < 0) {
        ts4_forward_882D1330(&l);
        return r;
    }
    ts4_forward_882D1330(&l);
    return 0;
}
