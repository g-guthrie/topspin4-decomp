/* Loader_DLL.xex 0x83148218-0x83148310, executable version 0.0.0.3. */


typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern int fn_83148048(void *, void *, int);
extern void *fn_833E3A30(void *, int, int);
void ts4l_push_u8_83148218(void *p, char v)
{
    fn_83148048(p, &v, 1);
}

void ts4l_push_u16_83148278(void *p, short v)
{
    fn_83148048(p, &v, 2);
}

void ts4l_push_f2_83148310(void *p, float v)
{
    int t = *(int *)&v;
    fn_83148048(p, &t, 4);
}
