/* near-miss: 57 off, size 0xec vs 0xf4 (fp_contract off; target product order uses 3 saved FPRs, mine 4) */
/* ME: rotate a 3x4 basis about its Y axis (pick.py throughput). Swing_DLL.xex 0x8864ED80 */
struct Ts4Basis { float x[4]; float y[4]; float z[4]; };

void fn_88187FA8(float *s, float *c, float angle);

#pragma fp_contract(off)
void ts4_basis_rotate_y_8864ED80(struct Ts4Basis *m, float angle)
{
    float s, c;
    float x0, x1, x2, x3, z0, z1, z2, z3;
    fn_88187FA8(&s, &c, angle);
    x0 = m->x[0]; z0 = m->z[0]; x1 = m->x[1]; x2 = m->x[2]; x3 = m->x[3];
    z1 = m->z[1]; z2 = m->z[2]; z3 = m->z[3];
    m->x[0] = z0 * s + x0 * c;
    m->z[0] = z0 * c - x0 * s;
    m->x[1] = z1 * s + x1 * c;
    m->x[2] = z2 * s + x2 * c;
    m->z[1] = z1 * c - x1 * s;
    m->x[3] = z3 * s + x3 * c;
    m->z[2] = z2 * c - x2 * s;
    m->z[3] = z3 * c - x3 * s;
}
