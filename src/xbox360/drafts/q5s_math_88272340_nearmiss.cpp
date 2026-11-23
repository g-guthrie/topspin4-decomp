/* nearmiss: 23 off; blocker: target loads lbl_880FC650 once and makes 4 vor128 copies, ours reloads lvx per field - missing the original vector class (ctor/operator= shape) for the 0xB0 track type; tried C helper, volatile, locals, restrict, copy ctor, by-value op=. */
#include "include/ts4/ts4.h"
struct Q5sV { __vector4 v; Q5sV() {} Q5sV(const __vector4 &a) : v(a) {}
 Q5sV &operator=(const Q5sV &o) { v = o.v; return *this; } };
extern "C" const __vector4 lbl_880FC650;
extern "C" const float g_ts4_event_value;
typedef struct Q5sTrk {
    Q5sV v00, v10, v20;
    float f30, f34, f38, f3c, f40;
    int i44, i48;
    float f4c, f50, f54;
    unsigned char b58; char p59[7];
    Q5sV v60, v70;
    int i80, i84, i88, i8c;
    float f90, f94;
    unsigned char b98, b99, b9a, b9b; char p9c[4];
    int ia0;
    unsigned char ba4; char pa5[0xb];
} Q5sTrk;
extern "C" void fn_88272340(Q5sTrk *t)
{
    t->v00 = Q5sV(lbl_880FC650);
    t->v10 = Q5sV(lbl_880FC650);
    t->v20 = Q5sV(lbl_880FC650);
    t->f30 = g_ts4_event_value;
    t->f34 = g_ts4_event_value;
    t->f38 = g_ts4_event_value;
    t->f3c = g_ts4_event_value;
    t->f40 = g_ts4_event_value;
    t->i44 = 0;
    t->i48 = 0;
    t->f4c = g_ts4_event_value;
    t->f50 = g_ts4_event_value;
    t->f54 = g_ts4_event_value;
    t->b58 = 0;
    t->v60 = Q5sV(lbl_880FC650);
    t->v70 = Q5sV(lbl_880FC650);
    t->i80 = 0;
    t->i84 = 0;
    t->i88 = 0;
    t->i8c = 0;
    t->f90 = g_ts4_event_value;
    t->f94 = g_ts4_event_value;
    t->b98 = 0;
    t->b99 = 0;
    t->b9a = 0;
    t->b9b = 0;
    t->ia0 = 0;
    t->ba4 = 0;
}
