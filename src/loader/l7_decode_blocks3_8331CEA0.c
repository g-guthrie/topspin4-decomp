/* Loader_DLL.xex 0x8331CEA0-0x8331D100, executable version 0.0.0.3. */
struct Dec;
typedef void (*MbFn)(struct Dec *, int, int, int, int, int, int, int, int, int, int);
typedef void (*MbEdgeFn)(struct Dec *, int, int, int, int, int, int, int, int, int, int, int, int);

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
    char pad8[0x3d18 - 0x3c1c];
    int plane_b;
    int plane_c;
    char pad8b[0x3d44 - 0x3d20];
    int dst_step_a;
    int dst_step_d;
    int dst_base;
    char pad10[0x3d5c - 0x3d50];
    int dst_step_c;
    char pad10b[0x3d64 - 0x3d60];
    int dst_step_e;
    char pad11[0x3e4c - 0x3d68];
    MbFn mb_inner;
    MbEdgeFn mb_edge;
} Dec;

extern int fn_832758F0(Dec *);

int ts4l_decode_blocks3_8331CEA0(Dec *d, int x)
{
    int da0;
    int db0;
    int dc0;
    int py;
    int pu;
    int pv;
    unsigned i;
    unsigned j;
    unsigned h;
    unsigned w;
    int da;
    int db;
    int dc;
    int cy;
    int cu;
    int cv;
    int a;
    int b;
    int e;
    int f;

    da0 = d->dst_base + x;
    h = d->rows;
    w = d->cols;
    py = d->origin_a + d->planes[0];
    pu = d->planes[1] + d->origin_b;
    db0 = d->plane_b + da0;
    pv = d->planes[2] + d->origin_b;
    dc0 = d->plane_c + da0;
    fn_832758F0(d);
    for (j = 0; j < w; j++) {
        cy = py;
        cu = pu;
        cv = pv;
        da = da0;
        db = db0;
        dc = dc0;
        for (i = 0; i < h; i++) {
            if (i != h - 1 && j != w - 1) {
                d->mb_inner(d, da, db, dc, cy, cu, cv, d->pitch_a, d->step_y, d->dst_step_a, d->dst_step_d);
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
                d->mb_edge(d, da, db, dc, cy, cu, cv, d->pitch_a, d->step_y, d->dst_step_a, d->dst_step_d, a, b);
            }
            da += 16;
            cy += 16;
            db += 8;
            cu += 8;
            dc += 8;
            cv += 8;
        }
        py += d->step_x;
        pu += d->pitch_b;
        pv += d->pitch_b;
        da0 += d->dst_step_c;
        db0 += d->dst_step_e;
        dc0 += d->dst_step_e;
    }
    return 0;
}
