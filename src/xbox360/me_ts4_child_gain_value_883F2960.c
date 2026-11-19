/* 0x883F2960: looks up the 0x40 child of the list at a+0x18 and, unless its state is disabled, converts its level through fn_883FEB50 and fn_88565118 into an offset from the base value at cfg+0x94 */
/* Matched on /O1 plain only (work/army/ME/v.py chk); the 5.020597f literal (lbl_88039DD4) must be written as a literal: the extern swaps the fmuls operands. */
extern const float lbl_88001A68;
extern const float lbl_88039DD0;
typedef struct St { char pad[0x10]; unsigned int flags; } St;
typedef struct Pr { char pad[0x18]; float v; } Pr;
typedef struct C { char pad[0x14]; St *st; char p18[8]; Pr *pr; } C;
typedef struct A { char pad[0x18]; void *list; } A;
typedef struct Cfg { char pad[0x94]; float base; } Cfg;
typedef struct T { int p0; Cfg *cfg; } T;
C *fn_883FDC10(void *list, int kind);
int fn_883FEB50(St *st, float v, float *out);
double fn_88565118(double x);
int ts4_child_gain_value_883F2960(T *t, A *a, float *out)
{
    C *c;
    float tmp;
    int r;
    c = a->list ? fn_883FDC10(a->list, 0x40) : 0;
    if (c && !(c->st->flags & 1)) {
        r = fn_883FEB50(c->st, c->pr->v, &tmp);
        if (r) return r;
        *out = ((float)fn_88565118(tmp * 5.020597f) - lbl_88001A68) * lbl_88039DD0 + t->cfg->base;
    } else {
        *out = t->cfg->base;
    }
    return 0;
}
