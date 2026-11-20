/* Swing_DLL.xex 0x886558B0: buffered write through a sink (flush when full, direct write when larger than
 * the buffer), then total += n.  nm1: the final add's (n, total) order needs a computed-address local
 * `t = &s->total` numbered 7 (see docs/agents/near-misses/NM1.md). */
typedef unsigned char u8;
typedef unsigned int u32;
struct L1;
struct L1Sink;
struct L1SinkVt { char p[0x10]; void (*write)(struct L1Sink *s, const void *p, u32 n); };
struct L1Sink { struct L1SinkVt *vt; };
struct L1Vt { char p[0xc]; u8 (*prep)(struct L1 *s, u32 n); };
typedef struct L1 { struct L1Vt *vt; char p[0x14-4]; u32 total; char p1[4]; struct L1Sink *sink; char p2[0x24-0x20]; char *buf; u32 cap; u32 fill; } L1;
#ifdef _MSC_VER
extern void *memcpy(void *d, const void *s, unsigned n);
#else
#include <string.h>
#endif
int ts4_buffered_write_886558B0(L1 *s, const void *p, u32 n)
{
    if ((long)s->sink == 0) return 0;
    if (!s->vt->prep(s, n)) return 0;
    if ((long)s->buf != 0) {
        if (s->fill + n > s->cap) {
            s->sink->vt->write(s->sink, s->buf, s->fill);
            s->fill = 0;
            if (n > s->cap) {
                s->sink->vt->write(s->sink, p, n);
            } else {
                memcpy(s->buf, p, n);
                s->fill = s->fill + n;
            }
        } else {
            memcpy(s->buf + s->fill, p, n);
            s->fill = s->fill + n;
        }
    } else {
        s->sink->vt->write(s->sink, p, n);
    }
    {
        /* four dead locals make `t` function-local symbol 7 (OP1 rule): add (n, total) */
        int nm1_pad0 = 0; int nm1_pad1 = 0; int nm1_pad2 = 0; int nm1_pad3 = 0;
        u32 *t = &s->total;
        *t = *t + n;
        (void)nm1_pad0; (void)nm1_pad1; (void)nm1_pad2; (void)nm1_pad3;
    }
    return 1;
}
