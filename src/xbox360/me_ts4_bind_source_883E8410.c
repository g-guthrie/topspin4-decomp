/* 0x883E8410: validates via fn(t, a, s) (returning its error), then copies the source fields into t, including the record handle and its value at +0x24 (or clears the handle when there is none). */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare. */
typedef struct Rec { char pad[0x24]; int v; } Rec;
typedef struct Src { int a; int b; int rec; int d; } Src;
typedef struct T { char pad[0x3c]; int b; int recv; int rec; int pad2; int d; int z; char pad3[4]; unsigned char f; } T;
int ts4_set_u32_offc_883E54A8(T *t, void *a, Src *s);
int ts4_bind_source_883E8410(T *t, void *a, Src *s)
{
    int r = ts4_set_u32_offc_883E54A8(t, a, s);
    if (r)
        return r;
    if (s && s->rec) {
        t->d = s->d;
        t->rec = s->rec;
        t->b = s->b;
        t->recv = ((Rec *)t->rec)->v;
        t->z = 0;
        t->f = 0;
    } else {
        t->rec = 0;
    }
    return 0;
}
