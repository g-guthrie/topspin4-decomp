/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_88001A20[];
extern char lbl_88028DFC[];
extern char lbl_8802BC90[];
extern char lbl_8802C0C8[];
extern char lbl_8802E890[];
extern char lbl_8802EE60[];
extern char lbl_8802F8CC[];
extern char lbl_8802F8D0[];
extern char lbl_88037A38[];
extern char lbl_8803964C[];
extern char lbl_88039714[];
extern char lbl_88039750[];
extern char lbl_88039A20[];
extern char lbl_88039C34[];
extern char lbl_88B3302C[];
extern char lbl_88B3AF44[];
extern char lbl_88CAC9A8[];
ts4_word ts4_if_call_seq_fn_88309DB8_883094D8();
ts4_word fn_88315F10();
ts4_word ts4_get_u32_lbl_88B3302C_883163E0();
ts4_word fn_8831AFB8();
ts4_word fn_8831C9A8();
ts4_word ts4_if_get_u32_off14_8831DB88();
ts4_word fn_88329658();
ts4_word fn_8832EDB0();
ts4_word fn_8836CD70();
ts4_word ts4_call_seq_fn_88336050_88374E88();
ts4_word fn_88375208();
ts4_word fn_88388048();
ts4_word fn_88396180();
ts4_word fn_883961D8();
ts4_word fn_88396230();
ts4_word fn_883962A8();
ts4_word fn_88399560();
ts4_word fn_8839A678();
ts4_word fn_883A3218();
ts4_word fn_883A3950();
ts4_word fn_883AA340();
ts4_word fn_883AA9E0();
ts4_word fn_883AAC28();
ts4_word fn_883AD0D0();
ts4_word fn_883BBE98();
ts4_word ts4_if_call_seq_fn_883BBE98_883BBF50();
ts4_word fn_883BC3B8();
ts4_word fn_883BFF30();
ts4_word fn_883C03D8();
ts4_word fn_883C1EB8();
ts4_word fn_883C1FD0();
ts4_word fn_883C72E0();
ts4_word fn_883C8F98();
ts4_word fn_883CA4F0();
ts4_word fn_883CE7E0();
ts4_word fn_883D1D68();
ts4_word fn_883D9D88();
ts4_word fn_883DD558();
ts4_word fn_883E2390();
ts4_word fn_883E4E70();
ts4_word fn_883E5890();
ts4_word fn_883E74F0();
ts4_word fn_883E8CD0();
ts4_word fn_883E8F58();
ts4_word fn_883E9210();
ts4_word fn_883E97D8();
ts4_word fn_883E9FF0();
ts4_word fn_883EA3C0();
ts4_word fn_883EA9F8();
ts4_word fn_883EAA48();
ts4_word fn_883EAA98();
ts4_word fn_883EAAE8();
ts4_word fn_883EB180();
ts4_word fn_883EEC60();
ts4_word fn_883FB620();
ts4_word ts4_set_u32_off98_883FB6A0();
ts4_word fn_883FCCC0();
ts4_word ts4_tailcall_NetDll_closesocket_884F0258();
ts4_word fn_885651F8();
ts4_word fn_8856C298();
ts4_word fn_8857ACB8();
ts4_word ts4_lookup_then_forward_88309520();
ts4_word ts4_lookup_then_forward_88309568();
ts4_word ts4_lookup_then_forward_883095B0();
ts4_word ts4_memset();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x883833E8: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_883833E8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)((0) | 32768), (ts4_word)19256);
    return 0;
}

/* Swing_DLL.xex 0x88383ED0: if_set u8@0x0 */
ts4_word ts4_if_set_u8_off0_88383ED0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)1;
    return 0;
}

/* Swing_DLL.xex 0x88383EF0: if_get u32@0x184, u32@0x0 */
ts4_word ts4_if_get_u32_off184_88383EF0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 388));
    return 0;
}

/* Swing_DLL.xex 0x88383F68: if_call_seq lbl_8802BC90, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8802BC90_88383F68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8802BC90;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88385D80: if_call_seq fn_883AD0D0, u32@0x30c, u32@0x190, u32@0x20, u32@0x18 */
ts4_word ts4_if_call_seq_fn_883AD0D0_88385D80(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_883AD0D0((ts4_word)a0, (ts4_word)a1);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 780);
        if ((ts4_word)t2 != 0) {
            t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 400);
            *(ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
        }
        p6 = (ts4_word)0;
    }
    return p6;
}

/* Swing_DLL.xex 0x88386230: get u32@0x54, u32@0x0 */
ts4_word ts4_get_u32_off54_88386230(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84));
    return 0;
}

/* Swing_DLL.xex 0x88387AF8: call_seq ts4_call_seq_fn_88336050_88374E88, lbl_8802C0C8, u32@0x124, u32@0x0, u32@0x128, u32@0x138 */
ts4_word ts4_call_seq_fn_88374E88_88387AF8(ts4_word a0)
{
    ts4_call_seq_fn_88336050_88374E88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8802C0C8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 296) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 312) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88387CE0: set u32@0x124 */
ts4_word ts4_set_u32_off124_88387CE0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x88388928: if_call_seq fn_88375208, fn_88388048 */
ts4_word ts4_if_call_seq_fn_88375208_88388928(ts4_word a0)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88375208();
    p3 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = fn_88388048((ts4_word)a0);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x88388CE0: tailcall fn_88388048 */
ts4_word ts4_tailcall_fn_88388048_88388CE0(ts4_word a0)
{
    return fn_88388048((ts4_word)a0);
}

/* Swing_DLL.xex 0x88389200: if_call_seq ts4_if_get_u32_off14_8831DB88, u32@0x16c, u32@0x17c, u64@0x138, u64@0x150 */
ts4_word ts4_if_call_seq_fn_8831DB88_88389200(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = ts4_if_get_u32_off14_8831DB88((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    if ((int)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 364) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)2;
        *(ts4_u64 *)((char *)(ts4_word)(a0) + 312) = (ts4_u64)0;
        *(ts4_u64 *)((char *)(ts4_word)(a0) + 336) = (ts4_u64)0;
    }
    return t1;
}

/* Swing_DLL.xex 0x88389D80: if_call_seq fn_8831AFB8, fn_8831C9A8 */
ts4_word ts4_if_call_seq_fn_8831AFB8_88389D80(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t1;

    t1 = fn_8831AFB8((ts4_word)a0, (ts4_word)a1);
    p3 = (ts4_word)t1;
    if ((int)t1 == 0) {
        fn_8831C9A8((ts4_word)a0, (ts4_word)0);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x8838DCA0: if_call_seq ts4_tailcall_NetDll_closesocket_884F0258 */
ts4_word ts4_if_call_seq_fn_884F0258_8838DCA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)a0 != -1) {
        ts4_tailcall_NetDll_closesocket_884F0258((ts4_word)a0);
    }
    return 0;
}

/* Swing_DLL.xex 0x883974C8: if_call_seq u32@0x0, lbl_8802E890, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off0_883974C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8802E890, (ts4_word)117);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    }
    fn_88396180((ts4_word)a0);
    fn_883962A8((ts4_word)a0);
    fn_883961D8((ts4_word)a0);
    t9 = fn_88396230((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x88399720: set fn_88399560 */
ts4_word ts4_set_fn_88399560_88399720(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 36) = f1;
    return fn_88399560((ts4_word)a0);
}

/* Swing_DLL.xex 0x88399728: get  */
float ts4_get_88399728(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 36));
}

/* Swing_DLL.xex 0x88399730: set fn_88399560 */
ts4_word ts4_set_fn_88399560_88399730(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 40) = f1;
    return fn_88399560((ts4_word)a0);
}

/* Swing_DLL.xex 0x8839B898: if_call_seq fn_8839A678, u32@0xc, u32@0x4, u32@0x8, u32@0xc, u32@0x8 */
ts4_word ts4_if_call_seq_fn_8839A678_8839B898(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_8839A678((ts4_word)a1);
    if ((int)t1 == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    }
    return t1;
}

/* Swing_DLL.xex 0x883A3688: get u32@0x50, fn_883A3218 */
ts4_word ts4_get_u32_off50_883A3688(ts4_word a0)
{
    return fn_883A3218((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)));
}

/* Swing_DLL.xex 0x883A3B60: get u32@0x50, fn_883A3950 */
ts4_word ts4_get_u32_off50_883A3B60(ts4_word a0)
{
    return fn_883A3950((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80)), (ts4_word)0);
}

/* Swing_DLL.xex 0x883A8FF0: call_seq fn_883BC3B8, ts4_if_call_seq_fn_883BBE98_883BBF50, u32@0x58 */
ts4_word ts4_call_seq_fn_883BC3B8_883A8FF0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_883BC3B8((ts4_word)a0, (ts4_word)(a1 + 472));
    t2 = ts4_if_call_seq_fn_883BBE98_883BBF50((ts4_word)a0, (ts4_word)(a1 + 576));
    *(ts4_word *)((char *)(ts4_word)(a1) + 88) = (ts4_word)2;
    return t2;
}

/* Swing_DLL.xex 0x883A9590: get u32@0x34 */
ts4_word ts4_get_u32_off34_883A9590(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
}

/* Swing_DLL.xex 0x883AA840: call_seq fn_883AA340 */
ts4_word ts4_call_seq_fn_883AA340_883AA840(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    t1 = fn_883AA340((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)a7, (ts4_word)0, (ts4_word)0);
    return t1;
}

/* Swing_DLL.xex 0x883AACB8: if_call_seq fn_883AA9E0, fn_883AAC28 */
ts4_word ts4_if_call_seq_fn_883AA9E0_883AACB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    t1 = fn_883AA9E0();
    p3 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = fn_883AAC28((ts4_word)a0, (ts4_word)a2);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x883AAD08: tailcall ts4_memset */
ts4_word ts4_tailcall_ts4_memset_883AAD08(ts4_word a0)
{
    return ts4_memset((ts4_word)a0, (ts4_word)0, (ts4_word)16);
}

/* Swing_DLL.xex 0x883AADD0: if_get u32@0x1c */
ts4_word ts4_if_get_u32_off1c_883AADD0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + t1));
    }
    return -1;
}

/* Swing_DLL.xex 0x883ABAF8: addr lbl_88B3AF44 */
ts4_word ts4_addr_lbl_88B3AF44_883ABAF8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_88B3AF44));
}

/* Swing_DLL.xex 0x883AC348: addr lbl_8802BC90, u32@0x18, u32@0x0, u32@0x4, u32@0x14, u32@0xc */
void ts4_addr_lbl_8802BC90_883AC348(ts4_word a0)
{
    float t1;
    float t2;

    t1 = *(float *)lbl_88028DFC;
    t2 = *(float *)lbl_8802F8CC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 72) = t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8802BC90;
    *(float *)((char *)(ts4_word)(a0) + 68) = t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x883AC390: set u32@0x14, u32@0x4, u32@0x18, u32@0x24, u32@0x20, u32@0x2c */
ts4_word ts4_set_u32_off14_883AC390(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883AC3D8: if_get u32@0xc, u32@0x2c, u32@0x8, u32@0x8 */
ts4_word ts4_if_get_u32_offc_883AC3D8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    if ((ts4_word)t1 == 0) {
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 8)) + 1);
    return 0;
}

/* Swing_DLL.xex 0x883AC400: if_get u32@0xc, u32@0x8, u32@0x8, u32@0x2c */
ts4_word ts4_if_get_u32_offc_883AC400(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 8)) + 1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x883ACE40: set u32@0x34 */
ts4_word ts4_set_u32_off34_883ACE40(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883ACE50: if_get u32@0x34, u32@0x0 */
ts4_word ts4_if_get_u32_off34_883ACE50(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52));
    return 0;
}

/* Swing_DLL.xex 0x883AD098: if_set u8@0x0 */
ts4_word ts4_if_set_u8_off0_883AD098(ts4_word a0, ts4_word a1)
{
    (void)a0;
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)0;
    return 0;
}

/* Swing_DLL.xex 0x883AD0B8: fn  */
ts4_word ts4_fn_883AD0B8(void)
{
    return 51;
}

/* Swing_DLL.xex 0x883AD0C0: set u32@0x0 */
ts4_word ts4_set_u32_off0_883AD0C0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    return 51;
}

/* Swing_DLL.xex 0x883B1D00: set u32@0x18 */
void ts4_set_u32_off18_883B1D00(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)lbl_88001A20);
    return;
}

/* Swing_DLL.xex 0x883B1D18: set u32@0x10, u32@0x14 */
void ts4_set_u32_off10_883B1D18(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x883B1D80: set  */
void ts4_set_883B1D80(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Swing_DLL.xex 0x883B1D88: set u32@0xc */
void ts4_set_u32_offc_883B1D88(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883B1EC8: addr lbl_8802EE60, ts4_get_u32_lbl_88B3302C_883163E0 */
ts4_word ts4_addr_lbl_8802EE60_883B1EC8(ts4_word a0)
{
    return ts4_get_u32_lbl_88B3302C_883163E0((ts4_word)a0, (ts4_word)(ts4_word)lbl_8802EE60, (ts4_word)134);
}

/* Swing_DLL.xex 0x883B2308: tailcall fn_883C03D8 */
ts4_word ts4_tailcall_fn_883C03D8_883B2308(ts4_word a0)
{
    return fn_883C03D8((ts4_word)a0, (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x883B2400: call_seq lbl_8802EE60, u32@0x4, ts4_get_u32_lbl_88B3302C_883163E0, u32@0x8, ts4_get_u32_lbl_88B3302C_883163E0 */
ts4_word ts4_call_seq_lbl_8802EE60_883B2400(ts4_word a0)
{
    ts4_word t4;

    ts4_get_u32_lbl_88B3302C_883163E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)lbl_8802EE60, (ts4_word)134);
    t4 = ts4_get_u32_lbl_88B3302C_883163E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)(ts4_word)lbl_8802EE60, (ts4_word)134);
    return t4;
}

/* Swing_DLL.xex 0x883B3368: get u32@0x0, lbl_8802EE60, ts4_get_u32_lbl_88B3302C_883163E0 */
ts4_word ts4_get_u32_off0_883B3368(ts4_word a0)
{
    return ts4_get_u32_lbl_88B3302C_883163E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)(ts4_word)lbl_8802EE60, (ts4_word)134);
}

/* Swing_DLL.xex 0x883B39B0: set u32@0x4, u32@0x0, u32@0x8 */
void ts4_set_u32_off4_883B39B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x883B39C0: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_883B39C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1);
    return;
}

/* Swing_DLL.xex 0x883B39D0: if_get u32@0x0, u32@0x4, u32@0x8, u8@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off0_883B39D0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    unsigned char t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)(t2 - t1) >= (int)t3) {
        return -1;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(t2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t2 + 1);
    return t4;
}

/* Swing_DLL.xex 0x883B6BD8: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_883B6BD8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883B6BF0: if_call_seq u32@0x0, fn_885651F8, u32@0x4, fn_885651F8, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off0_883B6BF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        fn_885651F8((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = fn_885651F8((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return p6;
}

/* Swing_DLL.xex 0x883B6EB0: tailcall fn_8856C298 */
ts4_word ts4_tailcall_fn_8856C298_883B6EB0(void)
{
    return fn_8856C298((ts4_word)1, (ts4_word)96);
}

/* Swing_DLL.xex 0x883B6F68: if_call_seq u32@0x0, fn_885651F8, u32@0x0, u32@0x4, u32@0xc, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off0_883B6F68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_885651F8((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x883B6FC8: set u32@0xc, u32@0x8, u32@0x14, u32@0x10 */
ts4_word ts4_set_u32_offc_883B6FC8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return 1;
}

/* Swing_DLL.xex 0x883B6FE8: get u32@0x14, u32@0x18, u32@0x1c */
void ts4_get_u32_off14_883B6FE8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(a1 & 0xffff);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x883B7088: get u32@0x14 */
ts4_word ts4_get_u32_off14_883B7088(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) & 0x7) == 0);
}

/* Swing_DLL.xex 0x883B70B0: get u32@0x8, u32@0x10, u32@0xc, u32@0x14 */
ts4_word ts4_get_u32_off8_883B70B0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return (((((t1 - t2) << 2) + t3) << 3) - (*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Swing_DLL.xex 0x883B8088: if_call_seq u32@0x0, fn_885651F8, u32@0x0, u32@0x4, u32@0xc, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off0_883B8088(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        fn_885651F8((ts4_word)t1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    t4 = fn_885651F8((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x883B8B68: set u32@0x40, u32@0x50, u32@0x44, u32@0x48, u32@0x4c, u32@0x54 */
void ts4_set_u32_off40_883B8B68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)((1732575232) | 8961);
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)((4023189504) | 43913);
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)((2562326528) | 56574);
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)((271712256) | 21622);
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883BA9D0: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_883BA9D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883BAB88: get u32@0x0, u8@0x5 */
ts4_word ts4_get_u32_off0_883BAB88(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 5)) & 0x1);
}

/* Swing_DLL.xex 0x883BAC48: if_call_seq u32@0x0, fn_8836CD70, u32@0x10, fn_8836CD70, u32@0x14, fn_8836CD70 */
ts4_word ts4_if_call_seq_u32_off0_883BAC48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        if ((ts4_word)t1 != 0) {
            fn_8836CD70((ts4_word)a0, (ts4_word)t1);
        }
        t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
        if ((ts4_word)t4 != 0) {
            fn_8836CD70((ts4_word)a0, (ts4_word)t4);
        }
        t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
        if ((ts4_word)t7 != 0) {
            fn_8836CD70((ts4_word)a0, (ts4_word)t7);
        }
        ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)360);
    }
    return 0;
}

/* Swing_DLL.xex 0x883BADB0: if_call_seq u32@0x4, ts4_memset */
ts4_word ts4_if_call_seq_u32_off4_883BADB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)-1;
        ts4_memset((ts4_word)a0, (ts4_word)0, (ts4_word)28);
    }
    return 0;
}

/* Swing_DLL.xex 0x883BADF0: if_call_seq u32@0x0, fn_8836CD70, ts4_memset */
ts4_word ts4_if_call_seq_u32_off0_883BADF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        if ((ts4_word)t1 != 0) {
            fn_8836CD70((ts4_word)a0, (ts4_word)t1);
        }
        ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)28);
    }
    return 0;
}

/* Swing_DLL.xex 0x883BB5E8: if_get u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14, u32@0x18 */
ts4_word ts4_if_get_u32_off4_883BB5E8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t1 < 0) {
        return -1;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x883BBD80: call_seq ts4_memset, u32@0x40, u32@0x4c, u32@0x44 */
ts4_word ts4_call_seq_ts4_memset_883BBD80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    ts4_memset((ts4_word)a2, (ts4_word)0, (ts4_word)104);
    *(ts4_word *)((char *)(ts4_word)(a2) + 64) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 68) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x883BD130: call_seq ts4_memset, u32@0xc, u32@0x8, u32@0x10 */
ts4_word ts4_call_seq_ts4_memset_883BD130(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = ts4_memset((ts4_word)a0, (ts4_word)0, (ts4_word)20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
    return t1;
}

/* Swing_DLL.xex 0x883BDAA0: if_call_seq u32@0x10, fn_8836CD70, u32@0x14, fn_8836CD70, u32@0x18, fn_8836CD70 */
ts4_word ts4_if_call_seq_u32_off10_883BDAA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    if ((ts4_word)t1 != 0) {
        fn_8836CD70((ts4_word)a0, (ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 20);
    if ((ts4_word)t4 != 0) {
        fn_8836CD70((ts4_word)a0, (ts4_word)t4);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    if ((ts4_word)t7 != 0) {
        fn_8836CD70((ts4_word)a0, (ts4_word)t7);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 28);
    if ((ts4_word)t10 != 0) {
        fn_8836CD70((ts4_word)a0, (ts4_word)t10);
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    if ((ts4_word)t13 != 0) {
        fn_8836CD70((ts4_word)a0, (ts4_word)t13);
    }
    t16 = ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)44);
    return t16;
}

/* Swing_DLL.xex 0x883C02C8: tailcall fn_883BFF30 */
ts4_word ts4_tailcall_fn_883BFF30_883C02C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_883BFF30((ts4_word)a2, (ts4_word)a1, (ts4_word)1, (ts4_word)1, (ts4_word)(a0 + 8), (ts4_word)a0);
}

/* Swing_DLL.xex 0x883C02E0: addr lbl_88037A38 */
ts4_word ts4_addr_lbl_88037A38_883C02E0(void)
{
    return (ts4_word)lbl_88037A38;
}

/* Swing_DLL.xex 0x883C1FC8: tailcall fn_883C1EB8 */
ts4_word ts4_tailcall_fn_883C1EB8_883C1FC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_883C1EB8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Swing_DLL.xex 0x883C2098: tailcall fn_883C1FD0 */
ts4_word ts4_tailcall_fn_883C1FD0_883C2098(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_883C1FD0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)1);
}

/* Swing_DLL.xex 0x883C57A8: get u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_883C57A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    return (t3 - (*(ts4_word *)((char *)(ts4_word)(t2) + 0)));
}

/* Swing_DLL.xex 0x883C66E0: tailcall fn_883CE7E0 */
ts4_word ts4_tailcall_fn_883CE7E0_883C66E0(ts4_word a0)
{
    return fn_883CE7E0((ts4_word)a0);
}

/* Swing_DLL.xex 0x883CA4D0: if_get  */
ts4_word ts4_if_get_883CA4D0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 52));
    return 0;
}

/* Swing_DLL.xex 0x883CA7B0: set  */
ts4_word ts4_set_883CA7B0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 128) = f1;
    return 0;
}

/* Swing_DLL.xex 0x883CA7C0: if_get  */
ts4_word ts4_if_get_883CA7C0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 128));
    return 0;
}

/* Swing_DLL.xex 0x883CA7E0: set  */
ts4_word ts4_set_883CA7E0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 132) = f1;
    return 0;
}

/* Swing_DLL.xex 0x883CA7F0: if_get  */
ts4_word ts4_if_get_883CA7F0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 132));
    return 0;
}

/* Swing_DLL.xex 0x883CAAD0: if_call_seq fn_8857ACB8, fn_8857ACB8, fn_8857ACB8 */
ts4_word ts4_if_call_seq_fn_8857ACB8_883CAAD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        fn_8857ACB8((ts4_word)a1, (ts4_word)(a0 + 220), (ts4_word)12);
    }
    if ((ts4_word)a2 != 0) {
        fn_8857ACB8((ts4_word)a2, (ts4_word)(a0 + 188), (ts4_word)12);
    }
    if ((ts4_word)a3 != 0) {
        fn_8857ACB8((ts4_word)a3, (ts4_word)(a0 + 200), (ts4_word)12);
    }
    return 0;
}

/* Swing_DLL.xex 0x883CAB40: tailcall fn_883C8F98 */
ts4_word ts4_tailcall_fn_883C8F98_883CAB40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_883C8F98((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x883CB100: set u32@0x7c */
ts4_word ts4_set_u32_off7c_883CB100(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883CB110: if_get u32@0x7c, u32@0x0 */
ts4_word ts4_if_get_u32_off7c_883CB110(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 124));
    return 0;
}

/* Swing_DLL.xex 0x883CC1E8: tailcall fn_883C72E0 */
ts4_word ts4_tailcall_fn_883C72E0_883CC1E8(ts4_word a0, ts4_word a1)
{
    return fn_883C72E0((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x883CD2D0: tailcall fn_883CA4F0 */
ts4_word ts4_tailcall_fn_883CA4F0_883CD2D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_883CA4F0((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x883CEFF0: if_get u32@0x14 */
ts4_word ts4_if_get_u32_off14_883CEFF0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 16));
    return 0;
}

/* Swing_DLL.xex 0x883CF070: if_get u32@0x14 */
ts4_word ts4_if_get_u32_off14_883CF070(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 28));
    return 0;
}

/* Swing_DLL.xex 0x883CF098: set u32@0x3c */
ts4_word ts4_set_u32_off3c_883CF098(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883CF0A8: if_get u32@0x3c, u32@0x0 */
ts4_word ts4_if_get_u32_off3c_883CF0A8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
    return 0;
}

/* Swing_DLL.xex 0x883CF110: if_get  */
ts4_word ts4_if_get_883CF110(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 != 0) {
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 44));
    }
    if ((ts4_word)a2 != 0) {
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 48));
    }
    return 0;
}

/* Swing_DLL.xex 0x883CF610: if_call_seq fn_8832EDB0, u32@0xc, fn_88329658, fn_8832EDB0, u32@0x20, u32@0x24 */
ts4_word ts4_if_call_seq_fn_8832EDB0_883CF610(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)(4194304), (ts4_word)48);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88329658((ts4_word)t2);
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)2, (ts4_word)(t3 + 1));
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t6 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)(4194304), (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 36)) << 2));
    }
    return 0;
}

/* Swing_DLL.xex 0x883D1DB8: tailcall fn_883D1D68 */
ts4_word ts4_tailcall_fn_883D1D68_883D1DB8(ts4_word a0)
{
    return fn_883D1D68((ts4_word)a0, (ts4_word)16);
}

/* Swing_DLL.xex 0x883D27C8: get u32@0x14, ts4_lookup_then_forward_88309568 */
ts4_word ts4_get_u32_off14_883D27C8(ts4_word a0)
{
    return ts4_lookup_then_forward_88309568((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Swing_DLL.xex 0x883D27D0: get u32@0x14, ts4_lookup_then_forward_883095B0 */
ts4_word ts4_get_u32_off14_883D27D0(ts4_word a0)
{
    return ts4_lookup_then_forward_883095B0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Swing_DLL.xex 0x883D27D8: get u32@0x14, ts4_if_call_seq_fn_88309DB8_883094D8 */
ts4_word ts4_get_u32_off14_883D27D8(ts4_word a0)
{
    return ts4_if_call_seq_fn_88309DB8_883094D8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Swing_DLL.xex 0x883D27E0: get u32@0x14, ts4_lookup_then_forward_88309520 */
ts4_word ts4_get_u32_off14_883D27E0(ts4_word a0)
{
    return ts4_lookup_then_forward_88309520((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Swing_DLL.xex 0x883D47E0: tailcall fn_883EB180 */
ts4_word ts4_tailcall_fn_883EB180_883D47E0(ts4_word a0)
{
    return fn_883EB180((ts4_word)a0);
}

/* Swing_DLL.xex 0x883D47E8: tailcall fn_883E8CD0 */
ts4_word ts4_tailcall_fn_883E8CD0_883D47E8(ts4_word a0)
{
    return fn_883E8CD0((ts4_word)a0);
}

/* Swing_DLL.xex 0x883D47F0: tailcall fn_883E8F58 */
ts4_word ts4_tailcall_fn_883E8F58_883D47F0(ts4_word a0)
{
    return fn_883E8F58((ts4_word)a0);
}

/* Swing_DLL.xex 0x883D47F8: tailcall fn_883E9210 */
ts4_word ts4_tailcall_fn_883E9210_883D47F8(ts4_word a0)
{
    return fn_883E9210((ts4_word)a0);
}

/* Swing_DLL.xex 0x883D4800: tailcall fn_883E97D8 */
ts4_word ts4_tailcall_fn_883E97D8_883D4800(ts4_word a0)
{
    return fn_883E97D8((ts4_word)a0);
}

/* Swing_DLL.xex 0x883D4808: tailcall fn_883E9FF0 */
ts4_word ts4_tailcall_fn_883E9FF0_883D4808(ts4_word a0)
{
    return fn_883E9FF0((ts4_word)a0);
}

/* Swing_DLL.xex 0x883D4810: tailcall fn_883EA3C0 */
ts4_word ts4_tailcall_fn_883EA3C0_883D4810(ts4_word a0)
{
    return fn_883EA3C0((ts4_word)a0);
}

/* Swing_DLL.xex 0x883D7ED0: set u32@0x14, u32@0x18, u32@0x1c, u16@0x20, u16@0x22, u32@0x24 */
ts4_word ts4_set_u32_off14_883D7ED0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 32) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 34) = (unsigned short)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x883D8880: if_get u32@0x14, u32@0x0, u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_off14_883D8880(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    }
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    }
    return 0;
}

/* Swing_DLL.xex 0x883D88A8: if_get u32@0x2c, u32@0x0 */
ts4_word ts4_if_get_u32_off2c_883D88A8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44));
    return 0;
}

/* Swing_DLL.xex 0x883D88C8: if_get u32@0x30, u32@0x0 */
ts4_word ts4_if_get_u32_off30_883D88C8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 48));
    return 0;
}

/* Swing_DLL.xex 0x883D8FC0: set u32@0x54 */
ts4_word ts4_set_u32_off54_883D8FC0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883D8FD0: if_get u32@0x54, u32@0x0 */
ts4_word ts4_if_get_u32_off54_883D8FD0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84));
    return 0;
}

/* Swing_DLL.xex 0x883DB620: tailcall fn_883D9D88 */
ts4_word ts4_tailcall_fn_883D9D88_883DB620(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_883D9D88((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0);
}

/* Swing_DLL.xex 0x883DBC60: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_883DBC60(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)((0) | 32768), (ts4_word)24);
    return 0;
}

/* Swing_DLL.xex 0x883DE178: tailcall fn_883DD558 */
ts4_word ts4_tailcall_fn_883DD558_883DE178(ts4_word a0, ts4_word a1)
{
    return fn_883DD558((ts4_word)a0, (ts4_word)a1, (ts4_word)-1);
}

/* Swing_DLL.xex 0x883DF348: if_get u32@0x18, u32@0x0, u32@0x14, u32@0x0 */
ts4_word ts4_if_get_u32_off18_883DF348(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    }
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    }
    return 0;
}

/* Swing_DLL.xex 0x883DF588: if_get u32@0x4c, u32@0x0 */
ts4_word ts4_if_get_u32_off4c_883DF588(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76));
    return 0;
}

/* Swing_DLL.xex 0x883DF868: if_get  */
ts4_word ts4_if_get_883DF868(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 32));
    return 0;
}

/* Swing_DLL.xex 0x883DF9F0: if_get u8@0x1c, u8@0x0 */
ts4_word ts4_if_get_u8_off1c_883DF9F0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 28));
    return 0;
}

/* Swing_DLL.xex 0x883DFA60: if_get u8@0x1d, u8@0x0 */
ts4_word ts4_if_get_u8_off1d_883DFA60(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 29));
    return 0;
}

/* Swing_DLL.xex 0x883DFA80: if_get u32@0x44, u32@0x0 */
ts4_word ts4_if_get_u32_off44_883DFA80(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68));
    return 0;
}

/* Swing_DLL.xex 0x883E0590: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_883E0590(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)100;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883E05B8: set u32@0x4, u32@0x0, u32@0x8 */
void ts4_set_u32_off4_883E05B8(ts4_word a0)
{
    float t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)100;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    t1 = *(float *)lbl_88001A20;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(float *)((char *)(ts4_word)(a0) + 12) = t1;
    return;
}

/* Swing_DLL.xex 0x883E05E0: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_883E05E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)100;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)2;
    return;
}

/* Swing_DLL.xex 0x883E05F8: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_883E05F8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)100;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)3;
    return;
}

/* Swing_DLL.xex 0x883E0788: get u32@0x0 */
ts4_word ts4_get_u32_off0_883E0788(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) & 0x3);
}

/* Swing_DLL.xex 0x883E0FD8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_883E0FD8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883E18D0: if_get u32@0x18, u32@0x30 */
ts4_word ts4_if_get_u32_off18_883E18D0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 48) = (ts4_word)a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x883E2BB8: if_call_seq fn_8832EDB0, u32@0x10, fn_88329658, fn_8832EDB0 */
ts4_word ts4_if_call_seq_fn_8832EDB0_883E2BB8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)(524288), (ts4_word)60);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88329658((ts4_word)t2);
        fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)(524288), (ts4_word)(t3 + 1));
    }
    return 0;
}

/* Swing_DLL.xex 0x883E3858: if_get u8@0x5, u8@0x0 */
ts4_word ts4_if_get_u8_off5_883E3858(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 5));
    return 0;
}

/* Swing_DLL.xex 0x883E3930: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_883E3930(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)12);
    return 0;
}

/* Swing_DLL.xex 0x883E3968: call_seq lbl_8803964C, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_call_seq_lbl_8803964C_883E3968(ts4_word a0)
{
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803964C, (ts4_word)35);
    return 0;
}

/* Swing_DLL.xex 0x883E3FF0: get  */
ts4_word ts4_get_883E3FF0(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 4));
    return 0;
}

/* Swing_DLL.xex 0x883E40A0: get  */
ts4_word ts4_get_883E40A0(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 8));
    return 0;
}

/* Swing_DLL.xex 0x883E40B0: set u32@0xc */
ts4_word ts4_set_u32_offc_883E40B0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883E4408: if_get u32@0x8, fn_883FB620 */
ts4_word ts4_if_get_u32_off8_883E4408(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    return fn_883FB620((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x883E4420: if_get u32@0x8, fn_883FCCC0 */
ts4_word ts4_if_get_u32_off8_883E4420(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        return 95;
    }
    return fn_883FCCC0((ts4_word)t1);
}

/* Swing_DLL.xex 0x883E4768: if_get u32@0x8, ts4_set_u32_off98_883FB6A0 */
ts4_word ts4_if_get_u32_off8_883E4768(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        return 95;
    }
    return ts4_set_u32_off98_883FB6A0((ts4_word)t1);
}

/* Swing_DLL.xex 0x883E5008: get u32@0x0 */
ts4_word ts4_get_u32_off0_883E5008(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x883E5010: call_seq u32@0xc, fn_8832EDB0 */
ts4_word ts4_call_seq_u32_offc_883E5010(ts4_word a0, ts4_word a1)
{
    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)4, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) << 2));
    return 0;
}

/* Swing_DLL.xex 0x883E5060: call_seq fn_883E4E70, lbl_88039714, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_call_seq_fn_883E4E70_883E5060(ts4_word a0)
{
    fn_883E4E70((ts4_word)a0);
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039714, (ts4_word)41);
    return 0;
}

/* Swing_DLL.xex 0x883E5158: if_call_seq u32@0x8, lbl_88039750, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@lbl_88B3302C */
ts4_word ts4_if_call_seq_u32_off8_883E5158(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_88039750, (ts4_word)152);
    }
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039750, (ts4_word)155);
    return 0;
}

/* Swing_DLL.xex 0x883E51B8: if_get u32@0x4, u32@0x8 */
ts4_word ts4_if_get_u32_off4_883E51B8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t1 < 0) {
        return t1;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t2 == 0) {
        return t1;
    }
    return (*(ts4_word *)((char *)(ts4_word)((t1 << 2)) + t2));
}

/* Swing_DLL.xex 0x883E54A8: set u32@0xc, u32@0x30, u8@0x34 */
ts4_word ts4_set_u32_offc_883E54A8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)0;
    return 0;
}

/* Swing_DLL.xex 0x883E5CD0: set u32@0x4 */
ts4_word ts4_set_u32_off4_883E5CD0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883E5E78: get u32@0xc, fn_883E5890 */
ts4_word ts4_get_u32_offc_883E5E78(ts4_word a0)
{
    return fn_883E5890((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
}

/* Swing_DLL.xex 0x883E63B8: fn  */
ts4_word ts4_fn_883E63B8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x883E6418: set u32@lbl_88CAC9A8 */
void ts4_set_u32_lbl_88CAC9A8_883E6418(ts4_word a0)
{
    *(ts4_word *)lbl_88CAC9A8 = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x883E6428: get u32@lbl_88CAC9A8 */
ts4_word ts4_get_u32_lbl_88CAC9A8_883E6428(void)
{
    return (*(ts4_word *)lbl_88CAC9A8);
}

/* Swing_DLL.xex 0x883E7278: get u32@0x4 */
ts4_word ts4_get_u32_off4_883E7278(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Swing_DLL.xex 0x883E7358: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_883E7358(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883E7568: fn  */
ts4_word ts4_fn_883E7568(ts4_word a0)
{
    return (a0 + 12);
}

/* Swing_DLL.xex 0x883E7570: get u32@0x18, u32@0x0 */
void ts4_get_u32_off18_883E7570(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    return;
}

/* Swing_DLL.xex 0x883E75E0: set  */
void ts4_set_883E75E0(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Swing_DLL.xex 0x883E75F0: get u32@0x14 */
ts4_word ts4_get_u32_off14_883E75F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x883E75F8: get u32@0x18 */
ts4_word ts4_get_u32_off18_883E75F8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x883E7600: get u32@0x1c */
ts4_word ts4_get_u32_off1c_883E7600(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x883E7650: set u32@0x54 */
void ts4_set_u32_off54_883E7650(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x883E7740: fn  */
ts4_word ts4_fn_883E7740(void)
{
    return ((1936523264) | 29296);
}

/* Swing_DLL.xex 0x883E77D8: fn  */
ts4_word ts4_fn_883E77D8(void)
{
    return ((1936588800) | 25459);
}

/* Swing_DLL.xex 0x883E77E8: fn  */
ts4_word ts4_fn_883E77E8(void)
{
    return ((1936523264) | 26740);
}

/* Swing_DLL.xex 0x883E77F8: fn  */
ts4_word ts4_fn_883E77F8(void)
{
    return ((1936588800) | 27764);
}

/* Swing_DLL.xex 0x883E7808: fn  */
ts4_word ts4_fn_883E7808(void)
{
    return ((1936523264) | 26483);
}

/* Swing_DLL.xex 0x883E7818: fn  */
ts4_word ts4_fn_883E7818(void)
{
    return ((1936392192) | 28268);
}

/* Swing_DLL.xex 0x883E7E08: call_seq u32@0x4, u32@0x8, fn_883E74F0, u32@0x0, u32@0x18 */
ts4_word ts4_call_seq_u32_off4_883E7E08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    fn_883E74F0((ts4_word)(a0 + 12), (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a4) + 0));
    return 0;
}

/* Swing_DLL.xex 0x883E7E60: if_call_seq u32@0x10, lbl_88039A20, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_if_call_seq_u32_off10_883E7E60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_88039A20, (ts4_word)207);
    }
    return 0;
}

/* Swing_DLL.xex 0x883E7EF8: if_call_seq u32@0x10, u32@0x14, fn_8832EDB0 */
ts4_word ts4_if_call_seq_u32_off10_883E7EF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) << 3));
    }
    return 0;
}

/* Swing_DLL.xex 0x883E8018: if_call_seq u32@0x0, u32@0x2c, u32@0x24, fn_8857ACB8, u32@0x2c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_883E8018(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t1 < (ts4_word)t2) {
        p7 = (ts4_word)33;
    } else {
        fn_8857ACB8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)), (ts4_word)(t2 << 2));
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44));
        p7 = (ts4_word)0;
    }
    return p7;
}

/* Swing_DLL.xex 0x883E8310: get  */
float ts4_get_883E8310(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x883E8320: get u32@0x20 */
ts4_word ts4_get_u32_off20_883E8320(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Swing_DLL.xex 0x883E8328: get u32@0xc */
ts4_word ts4_get_u32_offc_883E8328(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x883E8330: get u32@0x10 */
ts4_word ts4_get_u32_off10_883E8330(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x883E8338: get u32@0x24 */
ts4_word ts4_get_u32_off24_883E8338(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Swing_DLL.xex 0x883E8808: if_call_seq u32@0xc, lbl_88039A20, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@lbl_88B3302C */
ts4_word ts4_if_call_seq_u32_offc_883E8808(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_88039A20, (ts4_word)843);
    }
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039A20, (ts4_word)848);
    return 0;
}

/* Swing_DLL.xex 0x883E8A98: if_call_seq u32@0xc, u32@0x10, fn_8832EDB0 */
ts4_word ts4_if_call_seq_u32_offc_883E8A98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) << 4));
    }
    return 0;
}

/* Swing_DLL.xex 0x883E98F0: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_883E98F0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)28);
    return 0;
}

/* Swing_DLL.xex 0x883E9AD8: if_call_seq u32@0xc, u32@0x10, fn_8832EDB0 */
ts4_word ts4_if_call_seq_u32_offc_883E9AD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)2, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) << 2));
    }
    return 0;
}

/* Swing_DLL.xex 0x883EA8D0: tailcall fn_883EAAE8 */
ts4_word ts4_tailcall_fn_883EAAE8_883EA8D0(ts4_word a0)
{
    return fn_883EAAE8((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x883EA8D8: tailcall fn_883EAA48 */
ts4_word ts4_tailcall_fn_883EAA48_883EA8D8(ts4_word a0)
{
    return fn_883EAA48((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x883EA8E0: tailcall fn_883EAA98 */
ts4_word ts4_tailcall_fn_883EAA98_883EA8E0(ts4_word a0)
{
    return fn_883EAA98((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x883EA9E0: fn  */
ts4_word ts4_fn_883EA9E0(void)
{
    return ((1935998976) | 30051);
}

/* Swing_DLL.xex 0x883EA9F0: tailcall fn_883EA9F8 */
ts4_word ts4_tailcall_fn_883EA9F8_883EA9F0(ts4_word a0)
{
    return fn_883EA9F8((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x883ED420: if_set u32@0x18 */
ts4_word ts4_if_set_u32_off18_883ED420(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883ED4B0: if_get u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_off18_883ED4B0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24));
    return 0;
}

/* Swing_DLL.xex 0x883ED4D0: if_get u32@0x1c, u32@0x0 */
ts4_word ts4_if_get_u32_off1c_883ED4D0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    return 0;
}

/* Swing_DLL.xex 0x883ED500: if_get u8@0x21, u8@0x0 */
ts4_word ts4_if_get_u8_off21_883ED500(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 33));
    return 0;
}

/* Swing_DLL.xex 0x883ED520: set u32@0x24 */
ts4_word ts4_set_u32_off24_883ED520(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883ED530: if_get u32@0x24, u32@0x0 */
ts4_word ts4_if_get_u32_off24_883ED530(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    return 0;
}

/* Swing_DLL.xex 0x883ED5A0: if_set u32@0x0 */
ts4_word ts4_if_set_u32_off0_883ED5A0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x883ED5C0: set u32@0x14 */
ts4_word ts4_set_u32_off14_883ED5C0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883EDD40: set u32@0x24, u32@0x28 */
ts4_word ts4_set_u32_off24_883EDD40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a2;
    return 0;
}

/* Swing_DLL.xex 0x883EE4A8: if_call_seq fn_8832EDB0, u32@0x14, fn_88329658, fn_8832EDB0 */
ts4_word ts4_if_call_seq_fn_8832EDB0_883EE4A8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    fn_8832EDB0((ts4_word)a1, (ts4_word)1, (ts4_word)4096, (ts4_word)152);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88329658((ts4_word)t2);
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)2, (ts4_word)(t3 + 1));
    }
    return 0;
}

/* Swing_DLL.xex 0x883EE518: set u32@0x9c */
ts4_word ts4_set_u32_off9c_883EE518(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883EE640: set u32@0xa0 */
ts4_word ts4_set_u32_offa0_883EE640(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x883EE650: if_get u32@0xa0, u32@0x0 */
ts4_word ts4_if_get_u32_offa0_883EE650(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 160));
    return 0;
}

/* Swing_DLL.xex 0x883EEB98: call_seq fn_883EEC60, lbl_88039C34, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_call_seq_fn_883EEC60_883EEB98(ts4_word a0)
{
    ts4_word t4;

    fn_883EEC60((ts4_word)a0);
    t4 = fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039C34, (ts4_word)148);
    return t4;
}

/* Swing_DLL.xex 0x883EEF48: call_seq fn_883EEC60, fn_883EEC60, lbl_88039C34, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_call_seq_fn_883EEC60_883EEF48(ts4_word a0)
{
    ts4_word t5;

    fn_883EEC60((ts4_word)(a0 + 4));
    fn_883EEC60((ts4_word)(a0 + 20));
    t5 = fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88039C34, (ts4_word)290);
    return t5;
}

/* Swing_DLL.xex 0x883F27C4: fn  */
ts4_word ts4_fn_883F27C4(void)
{
    return 1;
}

/* Swing_DLL.xex 0x883F7278: fn  */
ts4_word ts4_fn_883F7278(void)
{
    return 91;
}

/* Swing_DLL.xex 0x883F7280: fn  */
ts4_word ts4_fn_883F7280(void)
{
    return 33;
}

/* Swing_DLL.xex 0x883F7288: get u32@0x4, u32@0x10, u32@0x40, fn_883E2390 */
ts4_word ts4_get_u32_off4_883F7288(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return fn_883E2390((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 64)));
}

/* Swing_DLL.xex 0x883F72F8: fn  */
ts4_word ts4_fn_883F72F8(void)
{
    return 37;
}
