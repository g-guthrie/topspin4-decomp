/* 0x884F8A90: looks the interface up with fn_884F7E18(a, b) and forwards (c, d, e) to its virtual slot 7; E_INVALIDARG (0x80070057) when not found. */
/* Matched on /O1 (agAB). r preset to the error code and assigned from the call; cr0 test of the lookup result marks /O1. */
typedef struct O O;
typedef struct OVt { void *f[7]; int (*f7)(O *o, int a, int b, int c); } OVt;
struct O { OVt *vt; };
O *fn_884F7E18(void *a, void *b);
int fn_884F8A90(void *a, void *b, int c, int d, int e)
{
    int r = 0x80070057;
    O *o = fn_884F7E18(a, b);
    if (o)
        r = o->vt->f7(o, c, d, e);
    return r;
}
