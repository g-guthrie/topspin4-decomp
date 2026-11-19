/* Swing_DLL.xex 0x88456D18: passes every 16-bit id of the array at +0xc (count at +0x10) other than 0xFFFF, with arg, to
 * virtual slot 5 of the sink at +8, then calls virtual slot 0 of self with 1. agO: lookalike of 88461310, plain and LTCG. */
struct Sink { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void add(unsigned short id, int arg); };
struct Obj { virtual void finish(int flag); int f4; Sink *sink; unsigned short *ids; int count; };
extern "C" void fn_88456D18(Obj *o, int arg)
{
    int i;
    int n = o->count;
    for (i = 0; i < n; i++) {
        if (o->ids[i] != 0xffff)
            o->sink->add(o->ids[i], arg);
    }
    o->finish(1);
}
