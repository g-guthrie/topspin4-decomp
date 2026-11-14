/* Loader_DLL.xex 0x8340B238-0x8340B328, executable version 0.0.0.3. */
typedef unsigned long u32;
extern int ts4l_import_XMsgStartIORequest_83516BB8(u32 id, u32 msg, u32 overlapped, void *buf, u32 size);
extern int fn_8340F0C0(void);
u32 ts4l_xmsg_io_8340B2B0(u32 a, u32 b, u32 overlapped)
{
    u32 buf[2];
    int r;
    buf[0] = a;
    buf[1] = b;
    r = ts4l_import_XMsgStartIORequest_83516BB8(251, 0xb0071, overlapped, buf, 8);
    if (r < 0) return 0x65b;
    if (overlapped == 0) {
        r = fn_8340F0C0();
        if (r < 0) return 0x65b;
        return 0;
    }
    return 0x3e5;
}

u32 ts4l_xmsg_io_8340B238(u32 a, u32 b, u32 overlapped)
{
    u32 buf[2];
    int r;
    buf[0] = a;
    buf[1] = b;
    r = ts4l_import_XMsgStartIORequest_83516BB8(251, 0xb0008, overlapped, buf, 8);
    if (r < 0) return 0x65b;
    if (overlapped == 0) {
        r = fn_8340F0C0();
        if (r < 0) return 0x65b;
        return 0;
    }
    return 0x3e5;
}
