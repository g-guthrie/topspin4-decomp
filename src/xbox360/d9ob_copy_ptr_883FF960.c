/* Swing_DLL.xex 0x883FF960-0x883FF9AC, executable version 0.0.0.3. */
typedef struct Ts4Ob2Q { void *p; unsigned long long ll; } Ts4Ob2Q;
void fn_883E6C00(Ts4Ob2Q *o, void *p);

Ts4Ob2Q *ts4_copy_883FF960(Ts4Ob2Q *o, Ts4Ob2Q *src)
{
    void *p = src->p;
    if (p != 0) {
        fn_883E6C00(o, p);
        return o;
    }
    o->p = 0;
    o->ll = 0;
    return o;
}
