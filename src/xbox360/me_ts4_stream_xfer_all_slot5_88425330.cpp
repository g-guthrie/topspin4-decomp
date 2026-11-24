/* Swing_DLL.xex 0x88425330: transfers n bytes of buf through virtual slot 5 of the stream at +8, repeating on partial
 * transfers; returns n, or the count done so far when a call transfers nothing. agO: lookalike of 884EB4B0, plain and LTCG. */
struct Stream { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual int xfer(char *buf, int n);
    virtual int f6(char *buf, int n); };
struct Obj { void *vtbl; int f4; Stream *stream; };
extern "C" int fn_88425330(Obj *o, char *buf, int n)
{
    int done = 0;
    while (done < n) {
        int r = o->stream->xfer(buf + done, n - done);
        done += r;
        if (r == 0)
            return done;
    }
    return n;
}
