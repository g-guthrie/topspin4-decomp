/* 0x883E0640: converts a rate to two integer periods: for hz > 0, (int)(1/hz * 500) into +8 and (int)(1/hz * 1500)
 * into +0xC, else zeros.
 * Matched (/Oc /Os plain) with float literals for lbl_88001A20 (0), lbl_88001A68 (1), lbl_880291B8 (500) and
 * lbl_880395A0 (1500): the extern multipliers give `fmuls f0,f0,f12`, the literals the target's `fmuls f0,f12,f0`. */
typedef struct Ts4RatePeriods { int pad_00; int pad_04; int a; int b; } Ts4RatePeriods;

void ts4_rate_to_periods_883E0640(Ts4RatePeriods *r, float hz)
{
    if (hz > 0.0f) {
        float t = 1.0f / hz;
        r->a = (int)(t * 500.0f);
        r->b = (int)(t * 1500.0f);
    } else {
        r->a = 0;
        r->b = 0;
    }
}
