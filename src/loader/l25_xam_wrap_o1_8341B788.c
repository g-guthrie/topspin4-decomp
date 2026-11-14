/* Loader_DLL.xex 0x8341B788-0x8341B8F8, 0x8341BFC8-0x8341C054, executable version 0.0.0.3. */
/* XAM-style thin wrappers: call the worker with a fixed operation code, store the returned handle through the out-pointer and return a failure HRESULT when it is null. */
typedef unsigned long ts4l_u32;

extern ts4l_u32 fn_830ADE48(ts4l_u32 a, ts4l_u32 b, ts4l_u32 c, ts4l_u32 d, ts4l_u32 e, ts4l_u32 f, ts4l_u32 g, ts4l_u32 op);
extern ts4l_u32 fn_830AE198(ts4l_u32 a);
extern ts4l_u32 fn_830AE250(ts4l_u32 a);

ts4l_u32 ts4l_xam_open_op17_8341B788(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 a2, ts4l_u32 a3, ts4l_u32 a4, ts4l_u32 a5, ts4l_u32 a6, ts4l_u32 a7, ts4l_u32 *out)
{
    ts4l_u32 r;
    (void)a0;
    r = fn_830ADE48(a1, a2, a3, a4, a5, a6, a7, 17);
    *out = r;
    return r == 0 ? 0x8007000E : 0;
}

ts4l_u32 ts4l_xam_open_op19_8341B850(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 a2, ts4l_u32 a3, ts4l_u32 a4, ts4l_u32 a5, ts4l_u32 a6, ts4l_u32 a7, ts4l_u32 *out)
{
    ts4l_u32 r;
    (void)a0;
    r = fn_830ADE48(a1, a2, a3, a4, a5, a6, a7, 19);
    *out = r;
    return r == 0 ? 0x8007000E : 0;
}

ts4l_u32 ts4l_xam_open_op18_8341B7E8(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 a2, ts4l_u32 a3, ts4l_u32 a4, ts4l_u32 a5, ts4l_u32 *out)
{
    ts4l_u32 r;
    (void)a0;
    r = fn_830ADE48(a1, a1, 6, a2, a3, a4, a5, 18);
    *out = r;
    return r == 0 ? 0x8007000E : 0;
}

ts4l_u32 ts4l_xam_open_op20_8341B8B0(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 a2, ts4l_u32 a3, ts4l_u32 a4, ts4l_u32 a5, ts4l_u32 *out)
{
    ts4l_u32 r;
    (void)a0;
    r = fn_830ADE48(a1, 1, 1, a2, a3, a4, a5, 20);
    *out = r;
    return r == 0 ? 0x8007000E : 0;
}

ts4l_u32 ts4l_xam_get_830AE198_8341BFC8(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 *out)
{
    ts4l_u32 r;
    (void)a1;
    r = fn_830AE198(a0);
    *out = r;
    return r == 0 ? 0x80004005 : 0;
}

ts4l_u32 ts4l_xam_get_830AE250_8341C010(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 *out)
{
    ts4l_u32 r;
    (void)a1;
    r = fn_830AE250(a0);
    *out = r;
    return r == 0 ? 0x80004005 : 0;
}
