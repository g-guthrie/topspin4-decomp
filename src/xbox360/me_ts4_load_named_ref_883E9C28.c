/* 0x883E9C28: loader for versions below 0x330000 (else 0x21): creates a 0x10-byte reference object, reads a length-prefixed name (at most 0x400) and an int from the stream (883194F0), resolves the name through lbl_88CAC988 slot 6 and stores both; the first two parameters are unused */
/* Matched on /O1 plain only (agV, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039A20[];
extern const char lbl_88039904[];
typedef struct Svc Svc;
typedef struct SvcVt { void *f[6]; int (*find)(Svc *s, const char *name, void **out); } SvcVt;
struct Svc { SvcVt *vt; };
extern Svc *lbl_88CAC988;
typedef struct Res { const void *vt; int a; void *h; int val; } Res;
void *fn_88315C60(void *heap, unsigned int size, const char *file, int line, int a, int b);
int fn_883194F0(void *stream, void *dst, unsigned int size, unsigned int count, int a);

int fn_883E9C28(void *self, void *ctx, void *stream, unsigned int version, int *flag, Res **out)
{
    unsigned int len;
    int val;
    void *h;
    char name[0x400];
    int r;
    Res *o;
    (void)self;
    (void)ctx;
    if (version >= 0x330000)
        return 0x21;
    *flag = 1;
    o = (Res *)fn_88315C60(lbl_88B3302C->heap, 0x10, lbl_88039A20, 0x7eb, 0, 0);
    *out = o;
    if (!o)
        return 0x2c;
    o->a = 0;
    o->vt = lbl_88039904;
    o->h = 0;
    o->val = 0;
    r = fn_883194F0(stream, &len, 4, 1, 0);
    if (r)
        return r;
    if (len > 0x400)
        return 0x2c;
    r = fn_883194F0(stream, name, 1, len, 0);
    if (r)
        return r;
    r = fn_883194F0(stream, &val, 4, 1, 0);
    if (r)
        return r;
    h = 0;
    if (len) {
        r = lbl_88CAC988->vt->find(lbl_88CAC988, name, &h);
        if (r)
            return r;
    }
    { Res *d = *out; void *hv = h; d->val = val; d->h = hv; }
    return 0;
}
