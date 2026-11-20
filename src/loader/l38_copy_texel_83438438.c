/* Loader_DLL.xex 0x83438438-0x83438498, executable version 0.0.0.3. */
typedef unsigned long u32;
extern void *fn_83430B48(void *o);
extern void fn_830E8670(void *dst, void *src, u32 n);
typedef struct { char p0[0x10]; int flag; char p1[0x20 - 0x14]; char *base; char p2[0x60 - 0x24]; u32 sx; u32 sy; u32 cnt; } Tex;
void ts4l_copy_texel_83438438(Tex *t, u32 x, u32 y, void *src)
{
    void *s = src;
    if (t->flag != 0) s = fn_83430B48(t);
    fn_830E8670(t->base + t->sx * x + t->sy * y, s, t->cnt * 4);
}
