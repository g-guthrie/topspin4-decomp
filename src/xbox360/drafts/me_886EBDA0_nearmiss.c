/* 0x886EBDA0 (renderer): linear ramp, returns b once t >= len, else a + (b - a) * t / len.
 * Near miss (agAL, LTCG /Oc, 3 off): the target schedules fdivs t/len before fsubs b-a and feeds fmadds (q, d, a);
 * ours computes b-a first. Locals for the quotient do not change it. */
float ts4_ramp_886EBDA0(float t, float a, float b, float len)
{
    if (t >= len)
        return b;
    return t / len * (b - a) + a;
}
