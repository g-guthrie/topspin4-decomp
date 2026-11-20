/* SM2: global-pointer accessors, bit-array ops, small float predicates. */
#ifdef _MSC_VER
extern double fabs(double x);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

extern char lbl_8803A844[];
extern char lbl_8803AE14[];
extern char lbl_8803B244[];
extern void fn_8840BAD8(void *p);
extern void fn_88410590(void *p);
extern void fn_88413970(void *p);
extern char *lbl_88D45B1C;
extern char **lbl_88D45B00;
extern void *lbl_88D45B38;
extern void *fn_88618998(void *a, void *b);
extern const float lbl_88001A20;
extern char *lbl_88D45AD4;

/* null-guarded: mark refcount 1, install vtable, forward to the next init stage */
#define INIT_AND_FWD(NAME, VT, CALLEE) \
    void NAME(char *p) { if (p == 0) return; *(unsigned short *)(p + 6) = 1; *(char **)p = (VT); CALLEE(p); }
INIT_AND_FWD(ts4_init_and_forward_88403918, lbl_8803A844, fn_8840BAD8)
INIT_AND_FWD(ts4_init_and_forward_88403CF0, lbl_8803AE14, fn_88410590)
INIT_AND_FWD(ts4_init_and_forward_88403DC0, lbl_8803B244, fn_88413970)

void ts4_vcall_global_slot2_886598F8(void)
{
    void **q = (void **)lbl_88D45B00;
    if (q) ((void (*)(void *))(*(void ***)q)[2])(q);
}
void *ts4_call_with_global_88618BB8(void *a)
{
    void *r = 0;
    if (lbl_88D45B38) r = fn_88618998(lbl_88D45B38, a);
    return r;
}
/* bit array test / clear / toggle */
unsigned ts4_bit_test_88544E48(const unsigned *bits, int i) { return bits[i >> 5] & (1u << (i & 31)); }
void ts4_bit_clear_88544E20(unsigned *bits, int i) { bits[i >> 5] &= ~(1u << (i & 31)); }
void ts4_bit_toggle_88544DF8(unsigned *bits, int i) { bits[i >> 5] ^= (1u << (i & 31)); }
/* true when the two floats differ by less than eps */
int ts4_float_near_8854F780(const float *a, const float *b, float eps) { return fabs(*a - *b) < eps; }
void ts4_set_positive_88486498(unsigned char *out, const char *p) { *out = *(const float *)(p + 0x44) > lbl_88001A20; }
unsigned ts4_get_global_field_886EEB98(void)
{
    char *g = lbl_88D45AD4;
    unsigned r = 0;
    if (g != 0) r = *(unsigned *)(g + 0x15680);
    return r;
}
