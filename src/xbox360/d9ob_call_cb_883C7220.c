/* Swing_DLL.xex 0x883C7220-0x883C7274, executable version 0.0.0.3. */
typedef struct Ts4Ob2Cb { char pad0[0x18]; void *f18; char pad1c[0x44]; unsigned int f60; char pad64[0x10]; void (*f74)(void *, int, int, int, void *); void *f78; } Ts4Ob2Cb;

void ts4_call_cb_883C7220(Ts4Ob2Cb *o, int a, int b, int c)
{
    o->f60 |= 1;
    o->f74(o->f18, a, b, c, o->f78);
    o->f60 &= ~1u;
}
