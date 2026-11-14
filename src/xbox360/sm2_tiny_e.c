/* SM2: float-array helpers, small searches, refcounted-object constructors. */
#ifdef _MSC_VER
extern double fabs(double x);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

extern char lbl_8803DE28[];
extern char lbl_8803EADC[];
extern char lbl_880C079C[];

static void ts4_swap_floats(float *a, float *b)
{
    float t = *a;
    *a = *b;
    *b = t;
}
/* swap float pairs (1,4) (2,8) (6,9) */
void ts4_swap_float_pairs_88425638(float *p)
{
    ts4_swap_floats(p + 4, p + 1);
    ts4_swap_floats(p + 8, p + 2);
    ts4_swap_floats(p + 9, p + 6);
}
/* scale the four floats at +0x20 */
void ts4_scale_vec4_20_8864E208(float *p, float s)
{
    p[8] = s * p[8];
    p[9] = s * p[9];
    p[10] = s * p[10];
    p[11] = s * p[11];
}
float ts4_dot4_88517340(const float *a, const float *b)
{
    return a[0] * b[0] + (a[1] * b[1] + (a[3] * b[3] + a[2] * b[2]));
}
void ts4_clear_fields_886C93C8(int *p)
{
    p[9] = 0; p[10] = 0; p[11] = 0; p[0] = 0; p[3] = 0; p[8] = 0; p[1] = 0; p[2] = 0; p[14] = 0; p[15] = -1;
}
/* known type ids */
unsigned char ts4_is_known_type_id_8865E788(const unsigned *p)
{
    unsigned id = *p;
    return id == 0x317c51b7u || id == 0xa2eda1e7u;
}
