/* agentA2 (2026-11-18 tips pass): volatile read of half_width or of the zero, block-local restrict store of *dx, z read into a local, decl reorders: best stays 7 off (plain and LTCG). Residue: f12/f13 for zero vs width and the lfs z placed before the *dx store. */
/* NEAR MISS (7 instructions): f12/f13 swapped between the half-width and the zero constant. */
/* 0x8865AC90: measures how far a point lies outside a court box: the lateral excess of |x| over the
 * half-width, and the depth excess past the far line (positive z) or the near line (negative z). */
typedef struct Pt { float x, y, z; } Pt;
typedef struct Box { float half_width; float near_line; float far_line; } Box;
extern float lbl_8814B440;
void ts4_box_overrun_8865AC90(Pt *p, Box *b, float *dx, float *dz)
{
    float x = p->x;
    float w = b->half_width;
    float zero = lbl_8814B440;
    if (x < zero) x = -x;
    *dx = x - w;
    if (p->z >= zero) *dz = p->z - b->far_line;
    else *dz = b->near_line - p->z;
}
