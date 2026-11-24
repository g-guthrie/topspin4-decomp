/* Loader_DLL.xex 0x83166248-0x831AF8D0, executable version 0.0.0.3. */


typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern float lbl_830009F8;
extern float lbl_830009E0;
u32 ts4l_a_831AF8D0(u32 a, u32 b)
{
    u32 x = a & 0xffff;
    if (x != 0) {
        if ((b & 0xffff) == 1)
            return ((a >> 1) & 0x7fff) + 6;
        return (x + 12) & 0xffff;
    }
    return 0;
}

void ts4l_d_83166248(float * __restrict p)
{
    *(int *)(p + 6) = 0;
    p[0] = lbl_830009E0;
    p[1] = lbl_830009F8;
    p[2] = lbl_830009F8;
    p[3] = lbl_830009E0;
    p[4] = lbl_830009F8;
    p[5] = lbl_830009F8;
}
