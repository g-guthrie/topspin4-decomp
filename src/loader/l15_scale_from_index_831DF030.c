/* Loader_DLL.xex 0x831DF030-0x8326C314, executable version 0.0.0.3. */
/* Index-to-linear scale: 2^(n/4)-style division/multiplication of a table entry,
 * clamped to the valid index range. */
extern float lbl_83014510[];
extern float lbl_83014630[];
extern float lbl_83032928[];
extern float lbl_83032A48[];

float ts4l_scale_from_index_831DF030(int n)
{
    if (n <= 0) {
        if (n < -0x48)
            n = -0x47;
        return lbl_83014510[-n] / (float)(1 << (-n >> 2));
    }
    if (n >= 0x3e)
        n = 0x3e;
    return (float)(1 << (n >> 2)) * lbl_83014630[n - 1];
}

float ts4l_scale_from_index_831FA358(int n)
{
    if (n <= 0) {
        if (n < -0x48)
            n = -0x47;
        return lbl_83014510[-n] / (float)(1 << (-n >> 2));
    }
    if (n >= 0x3e)
        n = 0x3e;
    return (float)(1 << (n >> 2)) * lbl_83014630[n - 1];
}

float ts4l_scale_from_index_8326C278(int n)
{
    if (n <= 0) {
        if (n < -0x48)
            n = -0x47;
        return lbl_83032928[-n] / (float)(1 << (-n >> 2));
    }
    if (n >= 0x3e)
        n = 0x3e;
    return (float)(1 << (n >> 2)) * lbl_83032A48[n - 1];
}
