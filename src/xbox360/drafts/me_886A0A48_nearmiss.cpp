/* NEAR MISS draft (not built, not counted). See docs/agents/matching-tips.md, "Near misses parked". */
#include "vx1_vector.h"
typedef struct Src { __vector4 a, b; float f20, f24; } Src;
extern "C" float lbl_8814B440;
struct E { __vector4 a, b; float f; E(){ a = __vspltisw(0); f = lbl_8814B440; b = __vspltisw(0); } };
extern "C" { void fn_88670B10(Src *s, E *arr, __vector4 a, __vector4 b, float f);
void fn_886939E0(E *e, void *x, __vector4 a, __vector4 b);
void f(Src *s, void *x, __vector4 a, __vector4 b){ E arr[4]; int i;
 fn_88670B10(s, arr, s->a, s->b, s->f24);
 for (i = 0; i < 4; i++) fn_886939E0(&arr[i], x, a, b); } }