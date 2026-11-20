/* NEAR MISS fn_8866E318 court bounds: 39 off (0xC0 vs 0xCC), LTCG + pp1_pool_primer.c, /Oc.
 * Remaining: float register numbering of x/zmin/zmax (target f0/f13/f12), the flow load is above the serve
 * test, and the target re-reads z_max/z_min right after storing them (loads of m->ball sit between). */
/* Swing_DLL.xex 0x8866E318: court target bounds {x_max, z_min, z_max} for the next shot, widened by the
   ball radius. Serve boxes depend on the serve side hash; rally bounds on the doubles flag. */
typedef unsigned int ts4_u32;
typedef unsigned char ts4_u8;
extern const float lbl_880C8F9C;   /* serve box z_max (other side) */
extern const float lbl_8814B45C;   /* radius scale */
struct Ts4BoxFlow { ts4_u8 pad_000[0xAC]; ts4_u32 serve_side; ts4_u8 pad_0b0[0x327 - 0xB0]; ts4_u8 doubles; };
struct Ts4BoxBall { ts4_u8 pad_000[0x4D0]; float radius; };
struct Ts4BoxBallLink { ts4_u8 pad_00[0x20]; struct Ts4BoxBall *ball; };
struct Ts4BoxMatch { ts4_u8 pad_00[0x30]; struct Ts4BoxFlow *flow; ts4_u8 pad_34[0x28]; struct Ts4BoxBallLink *ball; };
struct Ts4CourtBounds { float x_max; float z_min; float z_max; };

void ts4_court_bounds_8866E318(struct Ts4BoxMatch *m, ts4_u8 serve, struct Ts4CourtBounds *b)
{
    struct Ts4BoxFlow *flow = m->flow;
    float x, zmin, zmax, r;
    if (serve) {
        if (flow->serve_side == 0x23BAED9Eu) {
            x = 646.0f; zmin = -4.0f; zmax = 415.5f;
        } else {
            x = 646.0f; zmax = lbl_880C8F9C; zmin = -415.5f;
        }
    } else {
        x = 1194.5f;
        if (!flow->doubles) {
            zmin = -415.5f; zmax = 415.5f;
        } else {
            zmin = -552.5f; zmax = 552.5f;
        }
    }
    b->z_max = zmax;
    b->z_min = zmin;
    b->x_max = x;
    r = m->ball->ball->radius * lbl_8814B45C;
    b->x_max = x + r;
    b->z_min = b->z_min - r;
    b->z_max = r + b->z_max;
}
