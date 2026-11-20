/* Loader_DLL.xex 0x833E0360-0x833E03C8, 0x8340ADE8-0x8340AE4C, 0x8340BAF0-0x8340BB40, 0x8340CEA8-0x8340CEF0, executable version 0.0.0.3. */
/* XAM wrappers that turn an HRESULT into a Win32 error code: success is 0, a Win32-facility HRESULT yields its low 16 bits, anything else is 1627. */
typedef unsigned long ts4l_u32;

#ifndef _MSC_VER
#define __forceinline
#endif

extern int ts4l_import_XamUserGetSigninInfo_83517348(void);
extern int ts4l_import_XamUserGetXUID_83516BD8(ts4l_u32 user, ts4l_u32 type, ts4l_u32 out);
extern int ts4l_import_XMsgStartIORequest_83516BB8(ts4l_u32 id, ts4l_u32 msg, ts4l_u32 overlapped, void *buf, ts4l_u32 size);
extern int ts4l_import_XMsgInProcessCall_83516B88(ts4l_u32 id, ts4l_u32 msg, void *buf, ts4l_u32 flags);

static __forceinline ts4l_u32 ts4l_hr_to_win32(int hr)
{
    if (hr >= 0) return 0;
    if ((hr & 0x1fff0000) == 0x70000) return hr & 0xffff;
    return 1627;
}

ts4l_u32 ts4l_xam_signin_info_8340CEA8(void)
{
    return ts4l_hr_to_win32(ts4l_import_XamUserGetSigninInfo_83517348());
}

ts4l_u32 ts4l_xam_get_xuid_8340BAF0(ts4l_u32 user, ts4l_u32 out)
{
    return ts4l_hr_to_win32(ts4l_import_XamUserGetXUID_83516BD8(user, 7, out));
}

/* The request payload is the first argument slot itself (its address is passed). */
ts4l_u32 ts4l_xam_io_request_8340ADE8(ts4l_u32 a0, ts4l_u32 overlapped)
{
    return ts4l_hr_to_win32(ts4l_import_XMsgStartIORequest_83516BB8(254, 0x2000B, overlapped, &a0, 4));
}

ts4l_u32 ts4l_xam_in_process_call_833E0360(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 a2)
{
    ts4l_u32 buf[3];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    return ts4l_hr_to_win32(ts4l_import_XMsgInProcessCall_83516B88(250, 0x7001B, buf, 0));
}
