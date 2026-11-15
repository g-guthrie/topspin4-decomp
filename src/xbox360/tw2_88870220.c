/* Twin of 0x88870328 (ts4_ring_write_out_88870328 in src/xbox360/cx23_a.c). Sink write slot at +4. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct Cx23Item6 { u16 v[3]; } Cx23Item6;
typedef struct Cx23Ring { Cx23Item6 *begin; Cx23Item6 *end; u32 pad8; u32 stride; } Cx23Ring;
typedef struct Cx23SinkVt4 { void *s0; void (*write)(void *self, void *data, u32 bytes); } Cx23SinkVt4;
typedef struct Cx23Sink4 { const Cx23SinkVt4 *vt; } Cx23Sink4;

int ts4_ring_write_out_88870220(Cx23Ring *r, Cx23Sink4 *out, u32 *pos, u32 *count)
{
    u32 start = *pos / r->stride;
    u32 total = (u32)(r->end - r->begin) / r->stride;
    u32 n = *count;
    if (n + start <= total) {
        out->vt->write(out, r->begin + r->stride * start, (u32)(r->stride * n * 6));
        return 1;
    }
    out->vt->write(out, r->begin + r->stride * start, (u32)(r->stride * (total - start) * 6));
    out->vt->write(out, r->begin, (u32)(r->stride * (*count - total + start) * 6));
    return 1;
}
