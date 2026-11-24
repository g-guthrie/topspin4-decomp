/* 0x882908C0: unless the gate callback refuses, allocates a resource (0x28 header, plus 0x340 when blob flag 1 is set, plus the blob header), zeroes the header, copies the blob header after it, copies the blob payload into a second allocation and attaches it */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); the header size is read into a local before the inline header zeroing; returns the attach result, or 0 on failure. */
typedef int (*Gate)(void);
extern Gate lbl_88D452DC;
typedef struct Blob { unsigned int flags; unsigned int hdr; unsigned int size; } Blob;
typedef struct Res { union { __int64 q; struct { unsigned int flags; int p4; } w; } h; __int64 a, b, c, d; } Res;
void *fn_88888668(unsigned int size, unsigned int tag);
void ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(void *p, unsigned int tag);
void fn_8857ACB8(void *dst, const void *src, unsigned int n);
void *memcpy(void *d, const void *s, unsigned int n);
Res *ts4_set_u64_off0_88290888(Res *r, void *data);
static void *res_init(Res *r)
{
    r->h.q = 0; r->a = 0; r->b = 0; r->c = 0; r->d = 0;
    return r + 1;
}
Res * ts4_resource_from_blob_882908C0(Blob *b)
{
    Res *res;
    void *data;
    unsigned int n;
    char *src;
    if (lbl_88D452DC && !lbl_88D452DC()) return 0;
    n = b->size;
    src = (char *)b + b->hdr;
    res = (Res *)fn_88888668(((b->flags & 1) ? 0x368 : 0x28) + b->hdr, 0x24800000);
    if (!res) return 0;
    {
        unsigned int h = b->hdr;
        void *d = res_init(res);
        fn_8857ACB8(d, b, h);
    }
    data = fn_88888668(n, 0xb5800000);
    if (!data) {
        ts4_if_call_seq_u32_lbl_88D45B38_88884DE0(res, 0x24800000);
        return 0;
    }
    memcpy(data, src, n);
    {
        Res *r = ts4_set_u64_off0_88290888(res, data);
        res->h.w.flags |= 0x100000;
        return r;
    }
}
