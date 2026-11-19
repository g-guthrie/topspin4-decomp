/* 0x882E21B8 near miss (agAC): body is right, block layout is not; the target puts the fn_882DD1B8 (else) path and the 0x88760B59 return after the epilogue. 66 off on /O1, /Os, /Oc, plain and LTCG. */
typedef struct Ent { int f0; unsigned short kind; unsigned short a; unsigned short b; char pad[0x14 - 0xA]; } Ent;
typedef struct Hdr { char pad[0x10]; char *base; } Hdr;
typedef struct Res { int f0; int f4; unsigned off; unsigned size; Hdr *hdr; int f14; unsigned count; } Res;
int fn_882DD1B8(const unsigned *src, unsigned fourcc, char **data, unsigned *size);
int fn_882E1CC8(Res *r, char *data, unsigned size, int raw);
int ts4_forward_882DD6C0(unsigned size, void *dev);
int fn_882E21B8(Res *res, const unsigned *src, void *dev)
{
    char *data;
    int raw;
    int r;
    unsigned off, i, max;
    Ent *e;
    if (!src) return (int)0x8876086C;
    data = 0;
    raw = 0;
    if ((src[0] & 0xFFFFFF00) != 0x102A1100) {
        r = fn_882DD1B8(src, 0x42415443, &data, &res->size);
        if (r < 0) return r;
        if (r == 1) return (int)0x88760B59;
    } else {
        off = src[4];
        if (!off) return (int)0x88760B59;
        data = (char *)src + off + 4;
        raw = 1;
        res->size = *(const unsigned *)((const char *)src + off);
    }
    r = fn_882E1CC8(res, data, res->size, raw);
    if (r < 0) return r;
    if (dev) {
        max = 0;
        e = (Ent *)(res->hdr->base + res->off);
        for (i = 0; i < res->count; i++, e++) {
            if (e->kind == 2) {
                unsigned v = e->b + e->a;
                if (max < v) max = v;
            }
        }
        r = ts4_forward_882DD6C0(max << 4, dev);
        if (r < 0) return r;
    }
    return 0;
}
