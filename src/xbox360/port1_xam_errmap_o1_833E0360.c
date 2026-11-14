/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l25_xam_errmap_o1_833E0360.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* XAM wrappers that turn an HRESULT into a Win32 error code: success is 0, a Win32-facility HRESULT yields its low 16 bits, anything else is 1627. */
typedef unsigned long ts4_u32;

#ifndef _MSC_VER
#define __forceinline
#endif

/* The request payload is the first argument slot itself (its address is passed). */

extern int XMsgInProcessCall(ts4_u32 id, ts4_u32 msg, void *buf, ts4_u32 flags);
extern int XamUserGetXUID(ts4_u32 user, ts4_u32 type, ts4_u32 out);
extern int XamUserGetSigninInfo(void);
static __forceinline ts4_u32 ts4_hr_to_win32(int hr)
{
    if (hr >= 0) return 0;
    if ((hr & 0x1fff0000) == 0x70000) return hr & 0xffff;
    return 1627;
}

/* Swing_DLL.xex 0x882A92D8 */
ts4_u32 ts4_xam_in_process_call_882A92D8(ts4_u32 a0, ts4_u32 a1, ts4_u32 a2)
{
    ts4_u32 buf[3];
    buf[0] = a0;
    buf[1] = a1;
    buf[2] = a2;
    return ts4_hr_to_win32(XMsgInProcessCall(250, 0x7001B, buf, 0));
}

/* Swing_DLL.xex 0x8857A638 */
ts4_u32 ts4_xam_get_xuid_8857A638(ts4_u32 user, ts4_u32 out)
{
    return ts4_hr_to_win32(XamUserGetXUID(user, 7, out));
}

/* Swing_DLL.xex 0x8857A990 */
ts4_u32 ts4_xam_signin_info_8857A990(void)
{
    return ts4_hr_to_win32(XamUserGetSigninInfo());
}

