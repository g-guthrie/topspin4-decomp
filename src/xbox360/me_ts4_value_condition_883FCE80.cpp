/* 0x883FCE80: evaluates a condition on the registry value with id +0x1C: op +0x20 is ==, >, >=, <, <=, inside (a, b) or inside-or-near (a, b) against a/b at +0x14/+0x18 (near = within 1e-5), optionally negated by +0x24 */
/* Matched on /O1 plain only (work/army/ME/v.py chk); the second parameter (r4/f1 slot) is unused, typed float dt as a guess; ops >= 7 leave *out untouched; C++ virtual calls. */
struct Val { virtual void v0(); virtual void v1(); virtual float value(); };
struct Reg { virtual void v0(); virtual void v1(); virtual void v2(); virtual Val *find(int id); };
struct T { char pad[0x14]; float a, b; int id; unsigned int op; unsigned char negate; };
extern "C" Reg *ts4_get_u32_lbl_88CAC9A8_883E6388(void);
extern "C" double fabs(double);
#pragma intrinsic(fabs)
#define NEAR(x, y) (fabs((x) - (y)) < 1e-05)
extern "C" int ts4_value_condition_883FCE80(T *t, float dt, unsigned char *out)
{
    Val *v = ts4_get_u32_lbl_88CAC9A8_883E6388()->find(t->id);
    float x;
    if (!v) return 0x21;
    x = v->value();
    switch (t->op) {
    case 0: *out = NEAR(x, t->a) ? 1 : 0; break;
    case 1: *out = x > t->a ? 1 : 0; break;
    case 2: *out = (x > t->a || NEAR(x, t->a)) ? 1 : 0; break;
    case 3: *out = x < t->a ? 1 : 0; break;
    case 4: *out = (x < t->a || NEAR(x, t->a)) ? 1 : 0; break;
    case 5: *out = (x > t->a && x < t->b) ? 1 : 0; break;
    case 6: *out = ((x > t->a && x < t->b) || NEAR(x, t->a) || NEAR(x, t->b)) ? 1 : 0; break;
    }
    if (t->negate) *out = !*out;
    return 0;
}
