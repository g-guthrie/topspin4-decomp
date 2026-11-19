/* 0x886EFEF0: returns |b - a| <= eps as a byte */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
double fabs(double);
#pragma intrinsic(fabs)
unsigned char ts4_float_near_886EFEF0(float a, float b, float eps) { return (float)fabs(b - a) <= eps; }
