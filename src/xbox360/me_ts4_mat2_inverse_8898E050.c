/* 0x8898E050: writes the inverse of the 2x2 matrix m (row-major a,b,c,d) to o: (d,-b,-c,a) / (ad - bc). */
/* Matched on /Oc (agAB). __restrict on both pointers keeps single loads; o[3] stored before o[1], o[2]. */
void fn_8898E050(float *__restrict o, const float *__restrict m)
{
    float inv = 1.0f / (m[0] * m[3] - m[1] * m[2]);
    o[0] = m[3] * inv;
    o[3] = m[0] * inv;
    o[1] = -(m[1] * inv);
    o[2] = -(m[2] * inv);
}
