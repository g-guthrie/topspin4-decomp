/* Loader_DLL.xex 0x83167488-0x831A31F8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern float lbl_830009F8;
extern float lbl_83002200;
extern int lbl_83527E08;
extern int lbl_835312C0, lbl_835312BC;
extern void fn_83120540(void *);

void ts4l_put_be16_83167488(char *p, u32 v)
{
    (*(u8 **)(p + 8))[(*(int *)(p + 0x14))++] = (u8)(v >> 8);
    (*(u8 **)(p + 8))[(*(int *)(p + 0x14))++] = (u8)v;
}

int ts4l_popcount_u32_83184548(u32 x)
{
    int n = 0;
    while (x) {
        x &= x - 1;
        n++;
    }
    return n;
}

int ts4l_popcount_u32_831A31F8(u32 x)
{
    int n = 0;
    while (x) {
        x &= x - 1;
        n++;
    }
    return n;
}
