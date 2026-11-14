/* Swing_DLL.xex 0x8841F6D0-0x88557410, executable version 0.0.0.3. */
/* Linear-congruential float generators and a float-pair comparison. */
extern const float lbl_8802E854;
extern unsigned lbl_88B3C420;

float ts4_lcg_next_float_8841F6D0(void) {
    unsigned v = (0x3039 - lbl_88B3C420 * 0x3e39b193) & 0x7fffffff;
    lbl_88B3C420 = v;
    return (float)(long long)v * lbl_8802E854;
}

typedef struct ts4_fa_88518B80 { float *p; } ts4_fa_88518B80;
void ts4_differs_88518B80(unsigned char *out, int i, ts4_fa_88518B80 *a, int j) { *out = (i == j) || (a->p[i] != a->p[i + 1]); }

