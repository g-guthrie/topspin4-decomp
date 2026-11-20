/* 0x884FD970: zeroes n/8 blocks of eight floats */
/* Matched on /Os plain only (work/army/ME/v.py chk). */
void ts4_zero_float_blocks8_884FD970(float *p, unsigned n) { int k; for (k = n >> 3; k > 0; k--) { p[0] = 0.0f; p[1] = 0.0f; p[2] = 0.0f; p[3] = 0.0f; p[4] = 0.0f; p[5] = 0.0f; p[6] = 0.0f; p[7] = 0.0f; p += 8; } }
