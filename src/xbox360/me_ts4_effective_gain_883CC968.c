/* 0x883CC968: reads the source level (vtable slot 0x44 of +0x138), scales it by fn_883C95B8 unless flag 8 is set, by the owner modifier gain, and by the two factors at +0x30/+0x34 */
/* Matched on /O1 plain only (work/army/ME/v.py chk); the owner at +0x70 is tested with cmpwi, so it is typed as an int handle and cast. */
typedef struct S S;
typedef struct SVt { void *f[17]; int (*get)(S *s, float *out); } SVt;
struct S { SVt *vt; };
typedef struct Mod { char pad[0x44]; float gain; } Mod;
typedef struct Own { char pad[0x44]; Mod *mod; } Own;
typedef struct T { char pad[0x30]; float a; float b; char p38[8]; unsigned int flags; char p44[0x70 - 0x44]; int owner; char p74[0x138 - 0x74]; S *src; } T;
int fn_883C95B8(T *t, float *out);
int ts4_effective_gain_883CC968(T *t, float *out)
{
    float v, m;
    int r;
    if (!out) return 0x25;
    v = 0.0f;
    r = t->src->vt->get(t->src, &v);
    if (r) return r;
    if (!(t->flags & 8)) {
        r = fn_883C95B8(t, &m);
        if (r) return r;
        v = m * v;
    }
    if (t->owner && ((Own *)t->owner)->mod)
        v = ((Own *)t->owner)->mod->gain * v;
    *out = t->b * t->a * v;
    return 0;
}
