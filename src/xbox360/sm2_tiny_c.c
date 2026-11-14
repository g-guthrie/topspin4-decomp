/* SM2: small field/array helpers, float helpers, packers. */
#include "ts4_vector.h"

#ifdef _MSC_VER
extern double sqrt(double x);
#pragma intrinsic(sqrt)
#else
#include <math.h>
#define sqrt sqrt
#endif

extern float g_ts4_script_constants[];
extern float lbl_88001B04;
extern float lbl_880023D4;
extern float lbl_8814B440;

/* store flag at +0x98; when set, tail-call virtual slot 9 */
void ts4_set_flag_98_call_vslot9_886EF308(char *p, unsigned char v)
{
    p[0x98] = (char)v;
    if (v) ((void (*)(void *))(*(void ***)p)[9])(p);
}
/* copy vectors at +0x10 and +0x20 to +0xe0 and +0xf0 */
void ts4_copy_vec_pair_886ED6B0(char *p)
{
    __vector4 a = *(__vector4 *)(p + 0x10);
    __vector4 b = *(__vector4 *)(p + 0x20);
    *(__vector4 *)(p + 0xe0) = a;
    *(__vector4 *)(p + 0xf0) = b;
}
/* return script constant unless the object has an override at +0x48 */
float ts4_get_float_override_886C6010(const char *p)
{
    float r = g_ts4_script_constants[0x424 / 4];
    if (*(const unsigned char *)(p + 0x61)) r = (*(const float *const *)(p + 0x48))[0x28 / 4];
    return r;
}
/* negate x when the nested id matches */
float ts4_negate_if_id_8865EBD0(const char *p, float x)
{
    if (*(int *)(*(char **)(*(char **)(p + 0x4c) + 0x24) + 0xb0) == (int)0xa2eda1e7) return -x;
    return x;
}
/* pack four bytes into a word: d in the top byte, then a, b, c */
unsigned ts4_pack_bytes_dabc_884E1EE8(unsigned char a, unsigned char b, unsigned char c, unsigned char d)
{
    return ((((((unsigned)d << 8) + a) << 8) + b) << 8) + c;
}
/* normalized position of x between lo and hi scaled to a byte */
unsigned char ts4_norm_to_u8_8840F1B0(float lo, float hi, float x)
{
    return (unsigned char)((x - lo) / (hi - lo) * lbl_88001B04);
}
unsigned short ts4_norm_to_u16_8840F1D8(float lo, float hi, float x)
{
    return (unsigned short)((x - lo) / (hi - lo) * lbl_880023D4);
}
float ts4_length4_88518DA0(const float *v)
{
    return (float)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2] + v[3] * v[3]);
}
