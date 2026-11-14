/* Swing_DLL.xex 0x883CEA80-0x883CEACC, executable version 0.0.0.3. */
extern float lbl_88001A68;

unsigned char ts4_in_range_883CEA80(float x, float lo, float len)
{
    float end = lo + len;
    if (x == lbl_88001A68)
        return x >= lo && x <= end;
    return x >= lo && x < end;
}
