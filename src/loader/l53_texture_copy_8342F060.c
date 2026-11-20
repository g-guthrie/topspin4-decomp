/* Loader_DLL.xex 0x8342F060-0x8342F154, executable version 0.0.0.3. */
/* Copy a locked source surface into a locked destination surface row by row (block-compressed formats count 4-row groups). */
typedef struct Ts4lSurf {
    int pitch;
    char *bits;
} Ts4lSurf;
typedef struct Ts4lDesc {
    int fmt;
    int pad[6];
    unsigned rows;
} Ts4lDesc;
extern void ts4l_if_call_seq_u32_off0_830AE0A0(void *tex, Ts4lDesc *desc);
extern void ts4_get_u32_off1c_830AE138(void *tex, Ts4lSurf *s, int a, int b);
extern void ts4_get_u32_off18_830AE180(void *tex);
extern void fn_833E3AD0(void *dst, const void *src, unsigned n);
int ts4l_texture_copy_8342F060(void *src, void *dst)
{
    Ts4lDesc desc;
    Ts4lSurf sf[2];
    unsigned i;
    int n;
    int fmt;
    char *dp, *sp;
    ts4l_if_call_seq_u32_off0_830AE0A0(src, &desc);
    ts4_get_u32_off1c_830AE138(src, &sf[0], 0, 0);
    ts4_get_u32_off1c_830AE138(dst, &sf[1], 0, 0);
    fmt = desc.fmt & ~0x1C0;
    if (fmt >= 0x1A200012 && fmt <= 0x1A200014)
        desc.rows = (desc.rows + 3) >> 2;
    n = sf[1].pitch < sf[0].pitch ? sf[1].pitch : sf[0].pitch;
    sp = sf[0].bits;
    dp = sf[1].bits;
    for (i = 0; i < desc.rows; i++) {
        fn_833E3AD0(dp, sp, n);
        sp += sf[0].pitch;
        dp += sf[1].pitch;
    }
    ts4_get_u32_off18_830AE180(dst);
    ts4_get_u32_off18_830AE180(src);
    return 0;
}
