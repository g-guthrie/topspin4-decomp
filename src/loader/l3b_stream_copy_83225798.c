/* Loader_DLL.xex 0x83225798-0x83225828, executable version 0.0.0.3.
 * Bounded copy in/out of a memory-backed stream (virtual end test). */

extern void *fn_833E3AD0(void *, const void *, unsigned);

typedef struct Ts4lStream Ts4lStream;
typedef struct {
    char pad[0x5c];
    int (*at_end)(Ts4lStream *);
} Ts4lStreamVt;
struct Ts4lStream {
    Ts4lStreamVt *vt;
    char pad[0x28];
    char *base;
    unsigned size;
    unsigned pos;
};

int ts4l_stream_read_83225798(Ts4lStream *s, void *dst, unsigned n, unsigned *out)
{
    if (s->vt->at_end(s) != 0) {
        *out = 0;
    } else {
        unsigned avail = s->size - s->pos;
        if (n > avail)
            *out = avail;
        else
            *out = n;
    }
    fn_833E3AD0(dst, s->base + s->pos, *out);
    s->pos += *out;
    return 0;
}

int ts4l_stream_write_83225828(Ts4lStream *s, const void *src, unsigned n, unsigned *out)
{
    if (s->vt->at_end(s) != 0) {
        *out = 0;
    } else {
        unsigned avail = s->size - s->pos;
        if (n > avail)
            *out = avail;
        else
            *out = n;
    }
    fn_833E3AD0(s->base + s->pos, src, *out);
    s->pos += *out;
    return 0;
}
