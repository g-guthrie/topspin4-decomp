/* SM2: more field predicates, fixed-point converters, small float helpers. */
#ifdef _MSC_VER
extern double fabs(double x);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

extern const float lbl_8802C1D4;
extern const float lbl_88091E18;
extern const float lbl_8814B440;
extern const float lbl_88001A20;
extern const float lbl_88004444;
extern const float g_ts4_script_constants[];

int ts4_slot_ptr_or_zero_8860EE70(char *p)
{
    int r = 0;
    int i = *(int *)(p + 0x14);
    if (i >= 0 && i < *(int *)(p + 0x18)) r = *(int *)(p + 0x1c) + i;
    return r;
}
void ts4_set_chain_less_88487BF0(unsigned char *out, const char *a, const char *b)
{
    unsigned x = *(unsigned *)(**(char ***)(a + 0x48) + 0xc0);
    unsigned y = *(unsigned *)(**(char ***)(b + 0x48) + 0xc0);
    *out = x < y;
}
float ts4_fixed8_to_float_885BC6A0(const int *p) { return (float)(*p >> 8) * lbl_8802C1D4; }
float ts4_fixed12_to_float_885A47A0(const int *p) { return (float)(*p >> 12) * lbl_88091E18; }
unsigned char ts4_exceeds_88_886C4C30(const char *a, const char *b)
{
    return (*(const float *)(b + 0x24) - *(const float *)(*(const char *const *)(a + 0x20) + 0x18)) > *(const float *)(a + 0x10);
}
float ts4_blend_886CBD38(const char *p, float x)
{
    return (x - *(const float *)(p + 0x14)) * (*(const float *)(*(const char *const *)(*(const char *const *)(p + 4) + 8) + 0x14) - g_ts4_script_constants[0]) + *(const float *)(p + 0x24);
}
void ts4_notify_unless_flag_8865C230(char *p)
{
    if (*(unsigned char *)(*(char **)(*(char **)(p + 4) + 0x30) + 0x328) != 0) return;
    {
        void **q = *(void ***)(p + 8);
        ((void (*)(void *))(*(void ***)q)[5])(q);
    }
}
void ts4_vcall_if_flagged_886E63F0(char *p)
{
    void **q = *(void ***)(p + 0x24);
    if (q == 0) return;
    if (*((unsigned char *)q + 8) == 0) return;
    ((void (*)(void *))(*(void ***)q)[2])(q);
}
void ts4_set_is_space_884DCE58(unsigned char *out, int v) { *out = (v == 0x20 || v == 9 || v == 0xa || v == 0xd); }
void ts4_set_both_positive_88482358(unsigned char *out, const char *p)
{
    *out = *(const float *)(p + 0x70) > lbl_88001A20 && *(const float *)(p + 0x74) > lbl_88001A20;
}
unsigned char ts4_is_unset_and_default_886C45B8(const char *p)
{
    return *(const unsigned *)(p + 0x84) == 0 && *(const float *)(p + 0x88) == lbl_8814B440;
}
char *ts4_elem_ptr_stride48_886602B8(const char *p)
{
    char *r = 0;
    char *a = *(char **)(p + 0x5a0);
    if (a != *(char **)(p + 0x5a4)) r = a + *(int *)(p + 0x5bc) * 0x30;
    return r;
}
int ts4_track_max_885ED880(char *p, int unused, int n)
{
    int v = *(int *)(p + 8) + n;
    int m = *(int *)(p + 0xc);
    (void)unused;
    *(int *)(p + 8) = v;
    *(int *)(p + 0xc) = v > m ? v : m;
    return n;
}
