/* 0x8843F788: Steps a float from lbl_88001A20 by lbl_880038E0 while it is below lbl_88081B20 and returns the first value whose integer part is non-zero; returns lbl_88001A68 if none is found. */
/* Near miss (agAH): 1 off: fadds operand order (target fadds f1,f1,f0; candidate f1,f0,f1). Tried x += c, x = x + c, x = c + x, a step local and /fp:precise. */
extern const float lbl_88001A20;
extern const float lbl_880038E0;
extern const float lbl_88081B20;
extern const float lbl_88001A68;
float fn_8843F788(void)
{
    float x = lbl_88001A20;
    do {
        if ((int)x != 0)
            return x;
        x += lbl_880038E0;
    } while (x < lbl_88081B20);
    return lbl_88001A68;
}
