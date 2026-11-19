/* 0x8841ACB0: skips up to n bytes of stream s by reading into a 0x200-byte stack buffer through vtable slot 4 until a read returns 0; returns the number skipped. */
/* Matched on /Oc (agAF). while (left) loop with the clamp written in the call argument. */
typedef struct Stream Stream;
typedef struct StreamVt { void *f[4]; int (*read)(Stream *s, void *buf, int n); } StreamVt;
struct Stream { StreamVt *vt; };
int fn_8841ACB0(Stream *s, int n)
{
    char buf[0x200];
    int left = n;
    while (left) {
        int r = s->vt->read(s, buf, left > 0x200 ? 0x200 : left);
        if (!r)
            break;
        left -= r;
    }
    return n - left;
}
