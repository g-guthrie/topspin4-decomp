/* W5C batch f: matrix helpers. */
typedef union W5fMat4 { float m[16]; unsigned long long q[8]; } W5fMat4;

void fn_88187FA8(float *s, float *c, float angle);

/* Swing_DLL.xex 0x8864EE78 */
void ts4_matrix_rotate_x_8864EE78(W5fMat4 *self, float angle)
{
    W5fMat4 t = *self;
    float s, c;
    fn_88187FA8(&s, &c, angle);
    self->m[4] = t.m[4] * c - t.m[8] * s;
    self->m[8] = t.m[4] * s + t.m[8] * c;
    self->m[5] = t.m[5] * c - t.m[9] * s;
    self->m[9] = t.m[5] * s + t.m[9] * c;
    self->m[6] = t.m[6] * c - t.m[10] * s;
    self->m[10] = t.m[6] * s + t.m[10] * c;
    self->m[7] = t.m[7] * c - t.m[11] * s;
    self->m[11] = t.m[7] * s + t.m[11] * c;
}
