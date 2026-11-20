/* HKA batch: matrix helpers, family of W5C ts4_matrix_rotate_x_8864EE78 (rotates the m[0..7] columns). */
typedef union HkaMat4 { float m[16]; unsigned long long q[8]; } HkaMat4;

void fn_88187FA8(float *s, float *c, float angle);

/* Swing_DLL.xex 0x8864ECA8 */
void ts4_matrix_rotate_z_8864ECA8(HkaMat4 *self, float angle)
{
    HkaMat4 t = *self;
    float s, c;
    fn_88187FA8(&s, &c, angle);
    self->m[0] = t.m[0] * c - t.m[4] * s;
    self->m[4] = t.m[0] * s + t.m[4] * c;
    self->m[1] = t.m[1] * c - t.m[5] * s;
    self->m[5] = t.m[1] * s + t.m[5] * c;
    self->m[2] = t.m[2] * c - t.m[6] * s;
    self->m[6] = t.m[2] * s + t.m[6] * c;
    self->m[3] = t.m[3] * c - t.m[7] * s;
    self->m[7] = t.m[3] * s + t.m[7] * c;
}
