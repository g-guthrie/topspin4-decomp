/* Swing_DLL.xex 0x882E21B8: loads a resource from a raw 0x102A11xx block (size word + data at src[4]) or from chunk 'BATC'
 * (fn_882DD1B8), builds it with fn_882E1CC8, then sizes the device buffer from the largest kind-2 entry. agAD: /O1, shared bad label. */
typedef struct Ent { int f0; unsigned short kind; unsigned short a; unsigned short b; char pad[0x14 - 0xA]; } Ent;
typedef struct Hdr { char pad[0x10]; char *base; } Hdr;
typedef struct Res { int f0; int f4; unsigned off; unsigned size; Hdr *hdr; int f14; unsigned count; } Res;
int fn_882DD1B8(const unsigned *src, unsigned fourcc, char **data, unsigned *size);
int fn_882E1CC8(Res *r, char *data, unsigned size, int raw);
int ts4_forward_882DD6C0(unsigned size, void *dev);
int ts4_resource_load_batc_882E21B8(Res *res, const unsigned *src, void *dev)
{
    char *data;
    int raw;
    int r;
    unsigned off, i, max;
    Ent *e;
    if (!src) return (int)0x8876086C;
    data = 0;
    raw = 0;
    if ((src[0] & 0xFFFFFF00) == 0x102A1100) {
        off = src[4];
        if (!off) goto bad;
        { const unsigned *p = (const unsigned *)((const char *)src + off);
        data = (char *)(p + 1);
        raw = 1;
        res->size = *p; }
    } else {
        r = fn_882DD1B8(src, 0x42415443, &data, &res->size);
        if (r < 0) return r;
        if (r == 1) goto bad;
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
bad:
    return (int)0x88760B59;
}
