/* 0x8843F788: steps a float from 0 by 0.01 while it is below 1.1 and returns the first value whose integer part is
 * non-zero; 1.0 if none is found.
 * Matched (/Oc plain) with the constants written as float literals: the externs lbl_88001A20 (0), lbl_880038E0 (0.01),
 * lbl_88081B20 (1.1) and lbl_88001A68 (1.0) give `fadds f1,f0,f1`; the literal step gives the target's
 * `fadds f1,f1,f0`. */
float ts4_first_integral_step_8843F788(void)
{
    float x = 0.0f;
    do {
        if ((int)x != 0)
            return x;
        x += 0.01f;
    } while (x < 1.1f);
    return 1.0f;
}
