/* Loader_DLL.xex 0x832F7158-0x832F73E0, executable version 0.0.0.3. */
extern int lbl_8353AF44;

void ts4l_coef_adjust_832F7158(short *p, int mode, int q)
{
    int t;
    int sh;
    if (mode == 0) {
        t = (q * 0xee3 + 0x8000) >> 16;
        p[1] = (short)(p[1] - t);
        p[8] = (short)(p[8] - t);
        t = (q * 0x1e7 + 0x8000) >> 16;
        p[2] = (short)(p[2] - t);
        p[16] = (short)(p[16] - t);
        t = (q * 0x1fa + 0x8000) >> 16;
        p[3] = (short)(p[3] - t);
        p[24] = (short)(p[24] - t);
        t = (q * 0x87 + 0x8000) >> 16;
        p[4] = (short)(p[4] - t);
        p[32] = (short)(p[32] - t);
        p[10] = (short)(p[10] + t);
        p[11] = (short)(p[11] + t);
        p[17] = (short)(p[17] + t);
        p[25] = (short)(p[25] + t);
        t = (q * 0xad + 0x8000) >> 16;
        p[5] = (short)(p[5] - t);
        p[40] = (short)(p[40] - t);
        t = (q * 0x3d + 0x8000) >> 16;
        p[6] = (short)(p[6] - t);
        p[48] = (short)(p[48] - t);
        p[13] = (short)(p[13] + t);
        p[41] = (short)(p[41] + t);
        t = (q * 0x2a + 0x8000) >> 16;
        p[7] = (short)(p[7] - t);
        p[56] = (short)(p[56] - t);
        p[12] = (short)(p[12] + t);
        p[36] = (short)(p[36] + t);
        p[33] = (short)(p[33] + t);
        t = (q * 0x43c + 0x8000) >> 16;
        p[9] = (short)(p[9] + t);
        return;
    }
    sh = ((mode == 2) ^ lbl_8353AF44) ? 0 : 3;
    t = (q * 0x187d + 0x8000) >> 16;
    p[1 << sh] = (short)(p[1 << sh] - t);
    t = (q * 0x2c4 + 0x8000) >> 16;
    p[3 << sh] = (short)(p[3 << sh] - t);
    t = (q * 0xac + 0x8000) >> 16;
    p[5 << sh] = (short)(p[5 << sh] - t);
    t = (q * 0x49 + 0x8000) >> 16;
    p[7 << sh] = (short)(p[7 << sh] - t);
}
