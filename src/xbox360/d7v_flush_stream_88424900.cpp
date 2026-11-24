/* Swing_DLL.xex 0x88424900, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ts4W6Sink {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual int write(const char *buf, int len);
};
struct Ts4W6Stream {
    char pad[8];
    Ts4W6Sink *sink;
    const char *buf;
    int pending;
};
extern "C" {
int ts4_flush_stream_88424900(Ts4W6Stream *s)
{
    int total;
    int n;
    int w;
    if (s->sink != 0) {
        n = s->pending;
        total = 0;
        if (n > 0) {
            do {
                w = s->sink->write(s->buf + total, n - total);
                total += w;
                if (w == 0)
                    return total;
            } while (total < n);
        }
        s->pending = 0;
        return total;
    }
    return 0;
}
}
