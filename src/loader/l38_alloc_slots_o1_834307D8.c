/* Loader_DLL.xex 0x834307D8-0x8343084C, executable version 0.0.0.3. */
typedef unsigned long u32;
extern void *fn_8340D710(u32 n, u32 tag);
extern void *fn_833E0AB0(u32 n);
typedef struct { char p0[8]; u32 mode; char p1[0x54 - 0xc]; u32 need; void *buf; char p2[0x68 - 0x5c]; u32 count; } Ts4lA;
int ts4l_alloc_slots_834307D8(Ts4lA *a)
{
    if (a->mode != 4) a->need = 4;
    if (a->need != 0) {
        a->buf = fn_8340D710(a->count << 4, 0x24810000);
        if (a->buf == 0) return 0x8007000e;
    }
    return 0;
}
