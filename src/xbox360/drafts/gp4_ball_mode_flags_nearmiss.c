/* NEAR MISS (size 0x10c vs 0x120): original uses shared tail blocks; kept as a reference for the structure of fn_889C0C70. */
/* GP4: ball stepper helper (Swing_DLL.xex 0x889C0C70).
 * Maps the ball mode hash to the three net-interaction flags of the ball state:
 *   +0x31 check the net-plane crossing, +0x32 net is solid, +0x33 net-cord (let) deflection.
 * While bounce_count (+0x14) != 0 the flags are always {1,1,0}. */

extern float lbl_8814B440; /* 0.0f */

void ts4_ball_mode_to_net_flags_889C0C70(unsigned char *ball, unsigned int mode)
{
    if (*(unsigned int *)(ball + 0x14) != 0)
        goto solid;
    if (mode > 0x9CAFB633u)
        goto high;
    if (mode == 0x9CAFB633u)
        goto solid;
    if (mode > 0x81A72B79u)
        goto mid;
    if (mode == 0x81A72B79u)
        goto out_mode;
    if (mode == 0x02315629u)
        goto let;
    if (mode != 0x5D25ED1Du)
        return;
live:
    ball[0x31] = 0;
    ball[0x32] = 0;
    ball[0x33] = 0;
    return;
mid:
    if (mode != 0x8F903DFBu)
        return;
let:
    ball[0x33] = 1;
    ball[0x32] = 0;
    ball[0x31] = 1;
    return;
high:
    if (mode == 0x9EA301C2u)
        goto live;
    if (mode == 0xCA68AAECu)
        goto out_mode;
    if (mode != 0xCAA7531Fu)
        return;
solid:
    ball[0x33] = 0;
    ball[0x32] = 1;
    ball[0x31] = 1;
    return;
out_mode:
    ball[0x33] = 0;
    if ((*(float *)(ball + 0x110) * *(float *)(ball + 0x100)) > lbl_8814B440)
        goto solid;
    ball[0x31] = 0;
    ball[0x32] = 0;
}
