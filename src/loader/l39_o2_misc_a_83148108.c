/* Loader_DLL.xex 0x83148108-0x8318D918, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern float lbl_830009F8;
extern float lbl_83002200;
extern int lbl_83527E08;
extern int lbl_835312C0, lbl_835312BC;
extern void fn_83120540(void *);

u32 ts4l_min_take_83148108(char *p, u32 n)
{
    u32 c = *(u32 *)(p + 4);
    if (n > c)
        n = c;
    *(u32 *)(p + 4) = c - n;
    return n;
}

int ts4l_next_id_83149418(void)
{
    int r = lbl_83527E08;
    lbl_83527E08 = r + 1;
    if (lbl_83527E08 == 0)
        lbl_83527E08 = 1;
    return r;
}

int ts4l_gcd_8318D918(int a, int b)
{
    if (a <= 0)
        return b;
    while (a > 0) {
        if (a < b) {
            int t = a;
            a = b;
            b = t;
        }
        a -= b;
    }
    return b;
}
