/* W5A: signed distance of a point inside a box: min of the three margins; if outside, the least-negative margin. */
#include "w5a_types.h"

static const float w5a_zero = 0.0f;
#ifdef _MSC_VER
extern double fabs(double);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

static __inline float w5a_min(float a, float b) { return (a - b >= w5a_zero) ? b : a; }

float ts4_box_margin_8866E058(const float *a, const float *b)
{
    float m_lo = b[2] - a[2];
    float m_hi = a[2] - b[1];
    float ax = a[0];
    float m_x = b[0] - (float)fabs(ax);
    float r = w5a_min(m_x, w5a_min(m_lo, m_hi));
    if (r >= w5a_zero)
        return r;
    r = -3.4028234663852886e+38f;
    if (m_x < w5a_zero)
        r = m_x;
    if (m_lo < w5a_zero && m_lo > r)
        r = m_lo;
    if (m_hi < w5a_zero && m_hi > r)
        r = m_hi;
    return r;
}
