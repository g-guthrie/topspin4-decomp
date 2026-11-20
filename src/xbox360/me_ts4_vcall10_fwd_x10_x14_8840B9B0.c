/* 0x8840B9B0: forwards (x, a, b, c) to vtable slot 0x10 with the object fields +0x10 and +0x14 interleaved */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct O O;
typedef struct { void *s[4]; void (*f10)(O *, float, int, int, int, int, int); } OVt;
struct O { OVt *vt; int pad[3]; int x10; int x14; };
void ts4_vcall10_fwd_x10_x14_8840B9B0(O *o, float x, int a, int b, int c)
{
    o->vt->f10(o, x, o->x10, a, o->x14, b, c);
}
