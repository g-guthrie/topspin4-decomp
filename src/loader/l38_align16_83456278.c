/* Loader_DLL.xex 0x83456200-0x83456258, 0x83456278-0x834562D0, executable version 0.0.0.3. */
typedef unsigned long u32;
extern void *fn_8340D710(void *p, u32 tag);
void *ts4l_align16_83456278(void *u, void *p)
{
    char *r = (char *)fn_8340D710((char *)p + 16, 0x24810000);
    char *a;
    (void)u;
    if (r == 0) return 0;
    a = (char *)(((u32)r + 16) & ~15u);
    a[-1] = (char)(a - r);
    return a;
}
void *ts4l_align16_83456200(void *u, void *p)
{
    char *r = (char *)fn_8340D710((char *)p + 16, 0x24810000);
    char *a;
    (void)u;
    if (r == 0) return 0;
    a = (char *)(((u32)r + 16) & ~15u);
    a[-1] = (char)(a - r);
    return a;
}
