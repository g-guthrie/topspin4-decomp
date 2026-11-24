/* Loader_DLL.xex 0x834014D8-0x83401534, executable version 0.0.0.3. */
typedef unsigned long u32;
extern const unsigned char lbl_83071C98[];
typedef struct { char p0[4]; int mode; } Cfg;
unsigned char *ts4l_copy_magic_834014D8(Cfg *c, unsigned char *dst, unsigned char *end)
{
    int d;
    u32 n;
    u32 i;
    if (c->mode == 1) {
        d = (int)(end - dst);
        n = 4;
        if (d < 4) n = d;
        for (i = 0; i < n; i++) dst[i] = lbl_83071C98[i];
        return dst + n;
    }
    return dst;
}
