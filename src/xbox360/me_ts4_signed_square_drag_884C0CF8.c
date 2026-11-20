/* 0x884C0CF8: |x| * x * d * c * b * lbl_88004444 (signed square drag term); grouping in parentheses is needed */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
double fabs(double);
#pragma intrinsic(fabs)
extern const float lbl_88004444;
typedef struct { int x0; float a, b, c, d; } O;
float ts4_signed_square_drag_884C0CF8(O *o, float x)
{
    float a = (float)fabs(x);
    float r = (a * o->d * o->c * o->b * x) * lbl_88004444;
    return r;
}
