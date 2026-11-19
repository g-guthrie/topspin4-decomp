/* Swing_DLL.xex 0x8844EAD8: calls virtual slot 7 with arg on the non-null object of every 12-byte entry of the array at +0xc
 * (count +0x10), then virtual slot 0 of self with 1. agO: plain and LTCG (begin()/end() members). */
struct Item { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void apply(int arg); };
struct Entry { int a; int b; unsigned obj; };
struct EVec { Entry *data; int count; Entry *begin() { return data; } Entry *end() { return data + count; } };
struct Obj { virtual void finish(int flag); int f4; int f8; EVec entries; };
extern "C" void fn_8844EAD8(Obj *o, int arg)
{
    Entry *end = o->entries.end();
    for (Entry *e = o->entries.begin(); e != end; ++e) {
        if (e->obj)
            ((Item *)(unsigned long)e->obj)->apply(arg);
    }
    o->finish(1);
}
