/* Loader_DLL.xex 0x8331BFD8-0x8331C258, executable version 0.0.0.3. */
struct Dec;
typedef void (*MbFn)(struct Dec *, int, int, int, int, int, int, int);
typedef void (*MbEdgeFn)(struct Dec *, int, int, int, int, int, int, int, int);
typedef void (*MbSimpleFn)(int, int, int, int, int);

typedef struct Dec {
    char pad0[0x60];
    int pitch_a;
    int step_x;
    char pad01[4];
    int step_y;
    int pitch_b;
    char pad1[0x80 - 0x74];
    unsigned rows;
    unsigned cols;
    char pad2[0x9c - 0x88];
    int edge_a;
    unsigned edge_b;
    char pad3[0xb4 - 0xa4];
    int edge_c;
    char pad4[4];
    int edge_d;
    char pad5[0xdc - 0xc0];
    int origin_a;
    int origin_b;
    char pad6[0xebc - 0xe4];
    int *planes;
    char pad7[0x3c0c - 0xec0];
    int alt_a;
    unsigned alt_b;
    int alt_c;
    int alt_d;
    char pad8[0x3d44 - 0x3c1c];
    int dst_step_a;
    char pad9[0x3d4c - 0x3d48];
    int dst_base;
    int dst_step_b;
    char pad10[0x3d5c - 0x3d54];
    int dst_step_c;
    char pad11[0x3e40 - 0x3d60];
    MbFn mb_inner;
    MbEdgeFn mb_edge;
    char pad12[0x3e54 - 0x3e48];
    MbSimpleFn mb_simple;
} Dec;

extern int fn_832758F0(Dec *);

int ts4l_decode_blocks_8331BFD8(Dec *d, int x)
{
    int dst;
    int py;
    int pu;
    int pv;
    unsigned i;
    unsigned j;
    unsigned lim;
    unsigned h;
    unsigned w;
    int a;
    int b;
    int e;
    int f;

    h = d->rows;
    w = d->cols;
    if (d->planes == 0)
        return -9;
    py = d->origin_a + d->planes[0];
    dst = d->dst_base + x;
    pu = d->planes[1] + d->origin_b;
    pv = d->planes[2] + d->origin_b;
    if (d->mb_simple != 0) {
        e = d->edge_a;
        lim = d->edge_b;
        if (fn_832758F0(d) != 0) {
            e = d->alt_a;
            lim = d->alt_b;
        }
        for (i = 0; i < lim; i++) {
            d->mb_simple(dst, py, pu, pv, e);
            py += d->pitch_a;
            dst += d->dst_step_a;
            pu += (i & 1) * d->step_y;
            pv += (i & 1) * d->step_y;
        }
        return 0;
    }
    for (j = 0; j < w; j++) {
        int cy = py;
        int cu = pu;
        int cd = dst;
        for (i = 0; i < h; i++) {
            if (i != h - 1 && j != w - 1) {
                d->mb_inner(d, cd, cy, cu, cu + (pv - pu), d->pitch_a, d->step_y, d->dst_step_a);
            } else {
                if (fn_832758F0(d) != 0) {
                    a = (i != h - 1) ? 16 : 16 + (d->alt_a - d->alt_c);
                    if (j != w - 1) {
                        b = 16;
                    } else {
                        e = d->alt_d;
                        f = d->alt_b;
                        b = 16 - (e < 0 ? -e : e) + (f < 0 ? -f : f);
                    }
                } else {
                    a = (i != h - 1) ? 16 : 16 + (d->edge_a - d->edge_c);
                    if (j != w - 1) {
                        b = 16;
                    } else {
                        e = d->edge_d;
                        f = d->edge_b;
                        b = 16 - (e < 0 ? -e : e) + (f < 0 ? -f : f);
                    }
                }
                d->mb_edge(d, cd, cy, cu, cu + (pv - pu), d->pitch_a, d->step_y, a, b);
            }
            cy += 16;
            cu += 8;
            cd += d->dst_step_b;
        }
        pu += d->pitch_b;
        py += d->step_x;
        pv += d->pitch_b;
        dst += d->dst_step_c;
    }
    return 0;
}
