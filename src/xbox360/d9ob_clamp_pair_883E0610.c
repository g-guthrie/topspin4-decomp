/* Swing_DLL.xex 0x883E0610-0x883E063C, executable version 0.0.0.3. */
typedef struct Ts4Ob2Y { char pad0[8]; int a; int b; } Ts4Ob2Y;

void ts4_clamp_883E0610(Ts4Ob2Y *o)
{
    int v = o->b;
    if (v < 0)
        v = 0;
    o->b = v;
    o->a = o->a > v ? v : o->a;
}
