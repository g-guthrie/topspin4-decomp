/* Loader_DLL.xex 0x830A6150-0x83145320, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char __imp_VdGlobalDevice[];
extern char __imp_VdGlobalXamDevice[];
extern char lbl_83000F5C[];
extern char lbl_83000F78[];
extern char lbl_83000F94[];
extern char lbl_8300220C[];
extern char lbl_83002248[];
extern char lbl_83002264[];
extern char lbl_83002270[];
extern char lbl_83002354[];
extern char lbl_8300267C[];
extern char lbl_83002860[];
extern char lbl_830028A4[];
extern char lbl_83086A40[];
extern char lbl_83087158[];
extern char lbl_830871C0[];
extern char lbl_83088E00[];
extern char lbl_83089050[];
extern char lbl_83527DA0[];
extern char lbl_8352E934[];
extern char lbl_8352F7A0[];
extern char lbl_8352F7B0[];
extern char lbl_8352F7B4[];
extern char lbl_8352F7C4[];
extern char lbl_8352F7C8[];
extern char lbl_8352F7D8[];
extern char lbl_8352F7F4[];
extern char lbl_8352F804[];
extern char lbl_8352F818[];
extern char lbl_83531108[];
extern char lbl_83531134[];
extern char lbl_83531160[];
ts4_word KeGetCurrentProcessType();
ts4_word KeSetEvent();
ts4_word KeTlsGetValue();
ts4_word fn_830B9B50();
ts4_word fn_830DD9E0();
ts4_word fn_830DFD68();
ts4_word fn_830FEF70();
ts4_word fn_830FF250();
ts4_word fn_830FFAB0();
ts4_word fn_830FFBE8();
ts4_word fn_831005B8();
ts4_word fn_8310D380();
ts4_word fn_83111448();
ts4_word fn_83111970();
ts4_word fn_83115F78();
ts4_word fn_83120540();
ts4_word fn_83121438();
ts4_word fn_83121950();
ts4_word fn_831275C8();
ts4_word fn_8312C130();
ts4_word fn_8312C248();
ts4_word fn_8313FEA0();
ts4_word fn_83140210();
ts4_word fn_83141C60();
ts4_word fn_83141D10();
ts4_word fn_83141DE8();
ts4_word fn_83143438();
ts4_word fn_833E3088();
ts4_word fn_833E4AF8();
ts4_word fn_8340D710();
ts4_word fn_8340D830();
ts4_word fn_8340D860();

/* Loader_DLL.xex 0x830A6150: addr lbl_83086A40 */
ts4_word ts4_addr_lbl_83086A40_830A6150(ts4_word a0)
{
    return (((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (ts4_word)lbl_83086A40)) >> 12) & 0x1);
}

/* Loader_DLL.xex 0x830A61E8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_830A61E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((((((a2 << 4) | a1) << 24) | (((a2 << 4) | a1) >> 8)) & 0x7f000000) | ((2155872256) & 0x80ffffff)));
}

/* Loader_DLL.xex 0x830A6220: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_830A6220(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((((((a2 << 4) | a1) << 24) | (((a2 << 4) | a1) >> 8)) & 0x7f000000) | ((2155872256) & 0x80ffffff)));
}

/* Loader_DLL.xex 0x830A62C0: get u32@0x2a9c */
ts4_word ts4_get_u32_off2a9c_830A62C0(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10908)) - a1) == 0);
}

/* Loader_DLL.xex 0x830A6F40: get u32@0x35bc, u32@0x0, u32@0x35c0, u32@0x4, u32@0x550c, u32@0x8 */
void ts4_get_u32_off35bc_830A6F40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 13756));
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 13760));
    *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 21772));
    *(ts4_word *)((char *)(ts4_word)(a2) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 13764));
    return;
}

/* Loader_DLL.xex 0x830A80A0: get u32@0x2aa4, u32@0x0 */
void ts4_get_u32_off2aa4_830A80A0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 10916)) >> 12) & 0x3);
    return;
}

/* Loader_DLL.xex 0x830AA228: call_seq fn_8340D860, u32@0x2a88 */
ts4_word ts4_call_seq_fn_8340D860_830AA228(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8340D860();
    return ((t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 10888))) == 0);
}

/* Loader_DLL.xex 0x830AA2F8: call_seq KeGetCurrentProcessType */
ts4_word ts4_call_seq_KeGetCurrentProcessType_830AA2F8(void)
{
    ts4_word t1;

    t1 = KeGetCurrentProcessType();
    return ((t1 + -2) == 0);
}

/* Loader_DLL.xex 0x830AA328: if_call_seq KeGetCurrentProcessType, u32@__imp_VdGlobalDevice, u32@__imp_VdGlobalXamDevice, u32@0x0 */
ts4_word ts4_if_call_seq_KeGetCurrentProcessType_830AA328(void)
{
    ts4_word p4;
    int t1;

    t1 = KeGetCurrentProcessType();
    if ((int)t1 == 2) {
        p4 = (ts4_word)(*(ts4_word *)__imp_VdGlobalXamDevice);
    } else {
        p4 = (ts4_word)(*(ts4_word *)__imp_VdGlobalDevice);
    }
    return (*(ts4_word *)((char *)(ts4_word)(p4) + 0));
}

/* Loader_DLL.xex 0x830AB430: fn  */
ts4_word ts4_fn_830AB430(ts4_word a0, ts4_word a1)
{
    return (((a0 + a1) + -1) & ~(a1 + -1));
}

/* Loader_DLL.xex 0x830AB700: addr lbl_83086A40 */
ts4_word ts4_addr_lbl_83086A40_830AB700(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((a0 << 1)) + ((ts4_word)lbl_83086A40 + 1)));
}

/* Loader_DLL.xex 0x830AB7D0: addr lbl_83086A40 */
ts4_word ts4_addr_lbl_83086A40_830AB7D0(ts4_word a0)
{
    return (((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (ts4_word)lbl_83086A40)) >> 8) & 0xf);
}

/* Loader_DLL.xex 0x830AB7E8: get u32@0x0, u32@0xc, u8@0x7 */
ts4_word ts4_get_u32_off0_830AB7E8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return (((((((((t2 << 10) | (t2 >> 22)) & 0x7ffc00) | (t1 & 0xff8003ff)) << 7) | (((((t2 << 10) | (t2 >> 22)) & 0x7ffc00) | (t1 & 0xff8003ff)) >> 25)) & 0x3ffffe00) | (((t1 << 9) | (t1 >> 23)) & 0x100)) | (*(unsigned char *)((char *)(ts4_word)(a0) + 7)));
}

/* Loader_DLL.xex 0x830AB810: get u32@0x1c, u32@0x28, u8@0x23 */
ts4_word ts4_get_u32_off1c_830AB810(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    return (((((((((t2 << 10) | (t2 >> 22)) & 0x7ffc00) | (t1 & 0xff8003ff)) << 7) | (((((t2 << 10) | (t2 >> 22)) & 0x7ffc00) | (t1 & 0xff8003ff)) >> 25)) & 0x3ffffe00) | (((t1 << 9) | (t1 >> 23)) & 0x100)) | (*(unsigned char *)((char *)(ts4_word)(a0) + 35)));
}

/* Loader_DLL.xex 0x830ABF08: get u32@0x1c, u32@0x0, u32@0x18, u32@0x0, u32@0x4, u32@0x14 */
void ts4_get_u32_off1c_830ABF08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((((17409u << 20) | (17409u >> 12)) & 0xffdfffff) | (t2 & 0x200000));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(4294901760);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)((((a2 << 22) | (a2 >> 10)) & 0xfc00000) | (((t1 & 0x3fffff) | (a3 << 28)) & 0xf03fffff));
    return;
}

/* Loader_DLL.xex 0x830ABF48: get u32@0x0, u32@0x1c, u32@0x18, u32@0x4, u32@0x0, u32@0x14 */
void ts4_get_u32_off0_830ABF48(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((((17409u << 20) | (17409u >> 12)) & 0xffdfffff) | (t1 & 0x200000));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(4294901760);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)((((a2 << 28) | (a2 >> 4)) & 0xf0000000) | (t2 & 0xfffffff));
    return;
}

/* Loader_DLL.xex 0x830AE460: fn  */
ts4_word ts4_fn_830AE460(ts4_word a0, ts4_word a1)
{
    return (((a0 + a1) + -1) & ~(a1 + -1));
}

/* Loader_DLL.xex 0x830AE478: fn  */
ts4_word ts4_fn_830AE478(ts4_word a0, ts4_word a1)
{
    return (((a0 + a1) + -1) & ~(a1 + -1));
}

/* Loader_DLL.xex 0x830AE4A8: fn  */
ts4_word ts4_fn_830AE4A8(ts4_word a0, ts4_word a1)
{
    return (((a0 + a1) + -1) & ~(a1 + -1));
}

/* Loader_DLL.xex 0x830AE5D0: if_call_seq KeGetCurrentProcessType, u32@__imp_VdGlobalDevice, u32@__imp_VdGlobalXamDevice, u32@0x0 */
ts4_word ts4_if_call_seq_KeGetCurrentProcessType_830AE5D0(void)
{
    ts4_word p4;
    int t1;

    t1 = KeGetCurrentProcessType();
    if ((int)t1 == 2) {
        p4 = (ts4_word)(*(ts4_word *)__imp_VdGlobalXamDevice);
    } else {
        p4 = (ts4_word)(*(ts4_word *)__imp_VdGlobalDevice);
    }
    return (*(ts4_word *)((char *)(ts4_word)(p4) + 0));
}

/* Loader_DLL.xex 0x830AE758: if_get u32@0x0, u32@0x18, u32@0x18 */
ts4_word ts4_if_get_u32_off0_830AE758(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)(t1 & 0xf) != 4) {
        return a0;
    }
    if ((int)(t1 & 0x40000000) == 0) {
        return a0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t3 == 0) {
        return a0;
    }
    return t3;
}

/* Loader_DLL.xex 0x830AEAA8: if_get u32@0x0 */
ts4_word ts4_if_get_u32_off0_830AEAA8(ts4_word a0, ts4_word a1)
{
    if ((int)(a1 & 0xf00) != 0) {
        return (a1 + 256);
    }
    return (((a1 & 0xffffff0f) | (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) | 256);
}

/* Loader_DLL.xex 0x830AF608: set u32@0x8, u32@0x0, u32@0x4, u32@0xc, u32@0x1c, u32@0x10 */
void ts4_set_u32_off8_830AF608(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)8;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28)) & 0x3fffffc);
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830AF788: get u32@0x0, u32@0x8, u32@0x4, u32@0x0, u32@0xc, u32@0x1c */
void ts4_get_u32_off0_830AF788(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)((t1) >> 29);
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
    return;
}

/* Loader_DLL.xex 0x830B05E8: if_fn  */
ts4_word ts4_if_fn_830B05E8(ts4_word a0)
{
    if ((int)((a0 >> 16) & 0x3) == 0) {
        return 0;
    }
    if ((ts4_word)((a0 >> 16) & 0x3) == 1) {
        return ((0) | 32769);
    }
    return ((0) | 49155);
}

/* Loader_DLL.xex 0x830B06B8: addr lbl_83087158 */
ts4_word ts4_addr_lbl_83087158_830B06B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_83087158));
}

/* Loader_DLL.xex 0x830B15D8: if_get u32@0x5e88, u32@0x5e88 */
void ts4_if_get_u32_off5e88_830B15D8(ts4_word a0, ts4_word a1)
{
    ts4_word p2;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24200);
    if ((ts4_word)a1 != 0) {
        p2 = (ts4_word)(t1 | 1);
    } else {
        p2 = (ts4_word)(t1 & 0xfffffffe);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 24200) = (ts4_word)p2;
    return;
}

/* Loader_DLL.xex 0x830B1E18: get u32@0x292c */
ts4_word ts4_get_u32_off292c_830B1E18(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10540)) >> a1) & 0xf);
}

/* Loader_DLL.xex 0x830B1E58: get u32@0x2930 */
ts4_word ts4_get_u32_off2930_830B1E58(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10544)) >> a1) & 0xf);
}

/* Loader_DLL.xex 0x830B2228: fn  */
ts4_word ts4_fn_830B2228(ts4_word a0, ts4_word a1)
{
    return ((((a0 + 3) << 1) & ~(a1 + -1)) | ((((a0) >> 1) + -3) & (a1 + -1)));
}

/* Loader_DLL.xex 0x830B2320: get  */
ts4_word ts4_get_830B2320(ts4_word a0, ts4_word a1)
{
    return (*(ts4_word *)((char *)(ts4_word)(((a1 + 3051) << 2)) + a0));
}

/* Loader_DLL.xex 0x830B2AE8: get u8@0x2f92 */
ts4_word ts4_get_u8_off2f92_830B2AE8(ts4_word a0, ts4_word a1)
{
    return (((*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12178)) >> 1) & 0x1);
}

/* Loader_DLL.xex 0x830B2C88: get u8@0x2f92 */
ts4_word ts4_get_u8_off2f92_830B2C88(ts4_word a0, ts4_word a1)
{
    return ((*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12178)) & 0x1);
}

/* Loader_DLL.xex 0x830B2CD8: get u32@0x48c */
ts4_word ts4_get_u32_off48c_830B2CD8(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1164)) >> 23) & 0x3);
}

/* Loader_DLL.xex 0x830B2D88: get u8@0x2f92 */
ts4_word ts4_get_u8_off2f92_830B2D88(ts4_word a0, ts4_word a1)
{
    return (((*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12178)) >> 2) & 0x1);
}

/* Loader_DLL.xex 0x830B3108: get  */
ts4_word ts4_get_830B3108(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)(((int)(a1 + 48) * 24)) + a0)) >> 10) & 0x7);
}

/* Loader_DLL.xex 0x830B3158: get  */
ts4_word ts4_get_830B3158(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)(((int)(a1 + 48) * 24)) + a0)) >> 13) & 0x7);
}

/* Loader_DLL.xex 0x830B31A8: get  */
ts4_word ts4_get_830B31A8(ts4_word a0, ts4_word a1)
{
    return ((*(unsigned short *)((char *)(ts4_word)(((int)(a1 + 48) * 24)) + a0)) & 0x7);
}

/* Loader_DLL.xex 0x830B3200: get u32@0x494 */
ts4_word ts4_get_u32_off494_830B3200(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1172)) >> 3) & 0x3);
}

/* Loader_DLL.xex 0x830B3258: get u32@0x490 */
ts4_word ts4_get_u32_off490_830B3258(ts4_word a0, ts4_word a1)
{
    return ((int)((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1168)) << 5) >> 27);
}

/* Loader_DLL.xex 0x830B32B0: get u32@0x490 */
ts4_word ts4_get_u32_off490_830B32B0(ts4_word a0, ts4_word a1)
{
    return ((int)(*(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1168)) >> 27);
}

/* Loader_DLL.xex 0x830B3308: get u32@0x494 */
ts4_word ts4_get_u32_off494_830B3308(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1172)) >> 2) & 0x1);
}

/* Loader_DLL.xex 0x830B3368: get u32@0x484 */
ts4_word ts4_get_u32_off484_830B3368(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)((((int)a1 * 24) + a0)) + 1156);
    return (((~(t1 | t1)) >> 11) & 0x1);
}

/* Loader_DLL.xex 0x830B6340: addr lbl_83086A40 */
ts4_word ts4_addr_lbl_83086A40_830B6340(ts4_word a0)
{
    return (((*(unsigned short *)((char *)(ts4_word)((a0 << 1)) + (ts4_word)lbl_83086A40)) >> 13) & 0x1);
}

/* Loader_DLL.xex 0x830B6358: addr lbl_830871C0 */
ts4_word ts4_addr_lbl_830871C0_830B6358(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_830871C0) + a0));
}

/* Loader_DLL.xex 0x830B8370: fn  */
ts4_word ts4_fn_830B8370(ts4_word a0, ts4_word a1)
{
    return (((a0 + a1) + -1) & ~(a1 + -1));
}

/* Loader_DLL.xex 0x830B9468: set u32@0x0, u32@0x4188, u32@0x4, u32@0x4190, u32@0x4188, u32@0x8 */
void ts4_set_u32_off0_830B9468(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16776));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16784);
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16776)) - t2);
    return;
}

/* Loader_DLL.xex 0x830B99C8: get u32@0x98 */
ts4_word ts4_get_u32_off98_830B99C8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 152)) == 0);
}

/* Loader_DLL.xex 0x830B9AA8: if_call_seq KeGetCurrentProcessType, u32@__imp_VdGlobalDevice, u32@__imp_VdGlobalXamDevice, u32@0x0 */
ts4_word ts4_if_call_seq_KeGetCurrentProcessType_830B9AA8(void)
{
    ts4_word p4;
    int t1;

    t1 = KeGetCurrentProcessType();
    if ((int)t1 == 2) {
        p4 = (ts4_word)(*(ts4_word *)__imp_VdGlobalXamDevice);
    } else {
        p4 = (ts4_word)(*(ts4_word *)__imp_VdGlobalDevice);
    }
    return (*(ts4_word *)((char *)(ts4_word)(p4) + 0));
}

/* Loader_DLL.xex 0x830BA730: get u32@0x3b04, u32@0x0, u32@0x2acc, u32@0x0, u32@0x3b08, u32@0x0 */
void ts4_get_u32_off3b04_830BA730(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 15108));
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 10956));
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 15112));
    return;
}

/* Loader_DLL.xex 0x830BC308: fn  */
ts4_word ts4_fn_830BC308(ts4_word a0)
{
    return (((a0 + -1) & a0) == 0);
}

/* Loader_DLL.xex 0x830BC4D8: get u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x8, u32@0xc */
void ts4_get_u32_off0_830BC4D8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    return;
}

/* Loader_DLL.xex 0x830BC5F0: get u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x8, u32@0xc */
void ts4_get_u32_off0_830BC5F0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    return;
}

/* Loader_DLL.xex 0x830BDEA8: get u32@0x54, u32@0x54, u32@0x54, KeSetEvent */
ts4_word ts4_get_u32_off54_830BDEA8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(((((*(ts4_word *)((char *)(ts4_word)(a0) + 84)) & 0x3) + 23) << 2)) + a0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 84)) + 1);
    return KeSetEvent((ts4_word)(a0 + 60), (ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x830BDEE0: get u32@0x54, u32@0x54, u32@0x54, KeSetEvent */
ts4_word ts4_get_u32_off54_830BDEE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(((((*(ts4_word *)((char *)(ts4_word)(a1) + 84)) & 0x3) + 23) << 2)) + a1) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 84) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 84)) + 1);
    return KeSetEvent((ts4_word)(a1 + 60), (ts4_word)1, (ts4_word)0);
}

/* Loader_DLL.xex 0x830BEDE8: get u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x8, u32@0xc */
void ts4_get_u32_off0_830BEDE8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    return;
}

/* Loader_DLL.xex 0x830C0738: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C0738(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(((a0 + 535953408) << 2)) + 0));
}

/* Loader_DLL.xex 0x830C08E0: get u32@0x0, u32@0x0, u16@0x6, u32@0x0, u32@0x4, u16@0x0 */
void ts4_get_u32_off0_830C08E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned short t2;
    unsigned short t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    t2 = *(unsigned short *)((char *)(ts4_word)(a1) + 6);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(t2 | ((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) << 16));
    t4 = *(unsigned short *)((char *)(ts4_word)(a2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a2) + 4)) << 16) | t4);
    return;
}

/* Loader_DLL.xex 0x830C0A78: get  */
ts4_word ts4_get_830C0A78(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)(((a1 + 112) << 3)) + a0)) + a0) + 872);
}

/* Loader_DLL.xex 0x830C0A90: get u32@0x20, u32@0x368 */
ts4_word ts4_get_u32_off20_830C0A90(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    return ((*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(((a1 + 112) << 3)) + a0)) + a0)) + 872)) + t1);
}

/* Loader_DLL.xex 0x830C28E8: get u32@0x2aa8, u32@0x0, u32@0x2aa8, u32@0x0, u32@0x2aa8, u32@0x0 */
void ts4_get_u32_off2aa8_830C28E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 10920)) & 0x7f000) == 0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 10920)) >> 12) & 0x7f);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 10920)) >> 4) & 0x7f);
    return;
}

/* Loader_DLL.xex 0x830C2958: get u32@0x0, u32@0x0, u32@0x0 */
void ts4_get_u32_off0_830C2958(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    *(ts4_word *)((char *)(ts4_word)((((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 1) << 2)) + a0) = (ts4_word)(((((((((((((((a1 << 4) | (a1 >> 28)) & 0xfffffff0) | (a2 & 0xf)) << 8) | (a3 & 0xf)) << 1) | (((((((a1 << 4) | (a1 >> 28)) & 0xfffffff0) | (a2 & 0xf)) << 8) | (a3 & 0xf)) >> 31)) & 0xfffffffe) | (a4 & 0x1)) << 1) | (((((((((((a1 << 4) | (a1 >> 28)) & 0xfffffff0) | (a2 & 0xf)) << 8) | (a3 & 0xf)) << 1) | (((((((a1 << 4) | (a1 >> 28)) & 0xfffffff0) | (a2 & 0xf)) << 8) | (a3 & 0xf)) >> 31)) & 0xfffffffe) | (a4 & 0x1)) >> 31)) & 0xfffffffe) | (a5 & 0x1)) << 10);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 1);
    return;
}

/* Loader_DLL.xex 0x830C2A98: fn  */
ts4_word ts4_fn_830C2A98(ts4_word a0)
{
    return (((1 << a0) & 24702) != 0);
}

/* Loader_DLL.xex 0x830C2C08: get u32@0x4, u32@0x4 */
ts4_word ts4_get_u32_off4_830C2C08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((t1 + 31) & 0xffffffe0);
    return ((t1 + 31) & 0xffffffe0);
}

/* Loader_DLL.xex 0x830C2DF0: if_get u32@0x10, u32@0x24 */
ts4_word ts4_if_get_u32_off10_830C2DF0(ts4_word a0)
{
    ts4_word p3;
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p3 = (ts4_word)t1;
    if ((int)t1 >= 0) {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    }
    return p3;
}

/* Loader_DLL.xex 0x830C3348: get u32@0x2564, u32@0x4db4 */
ts4_word ts4_get_u32_off2564_830C3348(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 9572))) + 19892)) >> 2) & 0x1);
}

/* Loader_DLL.xex 0x830C3760: get u32@0x70 */
ts4_word ts4_get_u32_off70_830C3760(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 112)) == 0);
}

/* Loader_DLL.xex 0x830C3770: get u32@0x0, u32@0x4db4 */
ts4_word ts4_get_u32_off0_830C3770(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 19892)) >> 2) & 0x1);
}

/* Loader_DLL.xex 0x830C3780: get u32@0x0, u32@0x4db4 */
ts4_word ts4_get_u32_off0_830C3780(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 19892)) >> 3) & 0x1);
}

/* Loader_DLL.xex 0x830C3790: get u32@0x0, u32@0x4db4 */
ts4_word ts4_get_u32_off0_830C3790(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 19892);
    return (((~(t2 | t2)) >> 4) & 0x1);
}

/* Loader_DLL.xex 0x830C37A8: get u32@0x0, u32@0x4db4 */
ts4_word ts4_get_u32_off0_830C37A8(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 19892);
    return (((~(t2 | t2)) >> 5) & 0x1);
}

/* Loader_DLL.xex 0x830C37C0: get u32@0x0, u32@0x4db4 */
ts4_word ts4_get_u32_off0_830C37C0(ts4_word a0)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 19892);
    return (((~(t2 | t2)) >> 7) & 0x1);
}

/* Loader_DLL.xex 0x830C4960: fn  */
ts4_word ts4_fn_830C4960(ts4_word a0)
{
    return (((1 << a0) & 28664) != 0);
}

/* Loader_DLL.xex 0x830C4978: get u32@0x0, u32@0x154, u32@0x4, u32@0x158, u32@0x8, u32@0x15c */
void ts4_get_u32_off0_830C4978(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 340) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 344) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 348) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x830C6F70: get u32@0x0, u32@0x74 */
ts4_word ts4_get_u32_off0_830C6F70(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0)) + 116));
}

/* Loader_DLL.xex 0x830C6FC8: get u32@0x0, u32@0x80 */
ts4_word ts4_get_u32_off0_830C6FC8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0)) + 128)) + -1);
}

/* Loader_DLL.xex 0x830C7220: get u32@0x4de0, u32@0x4de4 */
void ts4_get_u32_off4de0_830C7220(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 19936);
    *(ts4_word *)((char *)(ts4_word)(((a1 - t1) << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 19940))) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x830C7238: get u32@0x4de0, u32@0x4de4 */
ts4_word ts4_get_u32_off4de0_830C7238(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 19936);
    return (*(ts4_word *)((char *)(ts4_word)(((a1 - t1) << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 19940))));
}

/* Loader_DLL.xex 0x830C7280: get u32@0x4db4 */
ts4_word ts4_get_u32_off4db4_830C7280(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 19892);
    return (((~(t1 | t1)) >> 4) & 0x1);
}

/* Loader_DLL.xex 0x830C7290: get u32@0x4db4 */
ts4_word ts4_get_u32_off4db4_830C7290(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 19892);
    return (((~(t1 | t1)) >> 5) & 0x1);
}

/* Loader_DLL.xex 0x830C72B0: get u32@0x4db4 */
ts4_word ts4_get_u32_off4db4_830C72B0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 19892);
    return (((~(t1 | t1)) >> 7) & 0x1);
}

/* Loader_DLL.xex 0x830C7400: get u32@0x0, u32@0x0, u32@0x164, u32@0x4, u32@0x168, u32@0x8 */
void ts4_get_u32_off0_830C7400(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 356) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 360) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 364) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x830C7618: get u32@0x0, u32@0x74 */
ts4_word ts4_get_u32_off0_830C7618(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0)) + 116));
}

/* Loader_DLL.xex 0x830C7670: get u32@0x0, u32@0x80 */
ts4_word ts4_get_u32_off0_830C7670(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0)) + 128)) + -1);
}

/* Loader_DLL.xex 0x830C79D8: get u32@0x0, u32@0x0, u32@0x164, u32@0x4, u32@0x168, u32@0x8 */
void ts4_get_u32_off0_830C79D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 356) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 360) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 364) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x830C7F40: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C7F40(ts4_word a0)
{
    return ((*(volatile ts4_word *)((char *)(ts4_word)((a0 << 2)) + 0)) & 0xff);
}

/* Loader_DLL.xex 0x830C88E8: get u32@0x14 */
ts4_word ts4_get_u32_off14_830C88E8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    return (((~(t1 | t1)) >> 6) & 0x1);
}

/* Loader_DLL.xex 0x830C8D10: if_get u32@0xc, u32@0x18, u32@0x1c, u32@0xc, u32@0xc, u32@0xc */
void ts4_if_get_u32_offc_830C8D10(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 == 0) {
        return;
    }
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 12);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(t3) + 12);
    *(volatile ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t5;
    *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12))) + 8) = (ts4_word)t6;
    return;
}

/* Loader_DLL.xex 0x830C9260: if_get u32@0x0, u32@0x4, fn_8340D830 */
ts4_word ts4_if_get_u32_off0_830C9260(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 == (ts4_word)t1) {
        return t1;
    }
    return fn_8340D830((ts4_word)t1, (ts4_word)(612368384));
}

/* Loader_DLL.xex 0x830C9280: if_get u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off0_830C9280(ts4_word a0)
{
    ts4_word p3;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    }
    return p3;
}

/* Loader_DLL.xex 0x830C9510: get  */
void ts4_get_830C9510(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((((a1 << 29) | (a1 >> 3)) & 0x1ffffffc)) + a0) = (ts4_word)((1 << (a1 & 0x1f)) | (*(ts4_word *)((char *)(ts4_word)((((a1 << 29) | (a1 >> 3)) & 0x1ffffffc)) + a0)));
    return;
}

/* Loader_DLL.xex 0x830C9568: get  */
void ts4_get_830C9568(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((((a1 << 29) | (a1 >> 3)) & 0x1ffffffc)) + a0) = (ts4_word)((1 << (a1 & 0x1f)) | (*(ts4_word *)((char *)(ts4_word)((((a1 << 29) | (a1 >> 3)) & 0x1ffffffc)) + a0)));
    return;
}

/* Loader_DLL.xex 0x830C9600: get  */
void ts4_get_830C9600(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((((a1 << 29) | (a1 >> 3)) & 0x1ffffffc)) + a0) = (ts4_word)((1 << (a1 & 0x1f)) | (*(ts4_word *)((char *)(ts4_word)((((a1 << 29) | (a1 >> 3)) & 0x1ffffffc)) + a0)));
    return;
}

/* Loader_DLL.xex 0x830C9620: loop_get u32@0x0, u32@0x0 */
void ts4_loop_get_u32_off0_830C9620(ts4_word a0, ts4_word a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p5;
    ts4_word t3;

    c1 = (ts4_word)8;
    lv2 = (ts4_word)a0;
    do {
        t3 = *(ts4_word *)((char *)(ts4_word)((a1 - a0)) + lv2);
        *(ts4_word *)((char *)(ts4_word)(lv2) + 0) = (ts4_word)(t3 | (*(ts4_word *)((char *)(ts4_word)(lv2) + 0)));
        p5 = (ts4_word)(lv2 + 4);
        lv2 = p5;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x830C9650: loop_get u32@0x0, u32@0x0 */
void ts4_loop_get_u32_off0_830C9650(ts4_word a0, ts4_word a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p5;
    ts4_word t3;

    c1 = (ts4_word)8;
    lv2 = (ts4_word)a0;
    do {
        t3 = *(ts4_word *)((char *)(ts4_word)((a1 - a0)) + lv2);
        *(ts4_word *)((char *)(ts4_word)(lv2) + 0) = (ts4_word)(t3 & (*(ts4_word *)((char *)(ts4_word)(lv2) + 0)));
        p5 = (ts4_word)(lv2 + 4);
        lv2 = p5;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x830C9778: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C9778(ts4_word a0)
{
    return ((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)) * 12);
}

/* Loader_DLL.xex 0x830C9CE8: get  */
void ts4_get_830C9CE8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((((a1 << 29) | (a1 >> 3)) & 0x1ffffffc)) + a0) = (ts4_word)((1 << (a1 & 0x1f)) | (*(ts4_word *)((char *)(ts4_word)((((a1 << 29) | (a1 >> 3)) & 0x1ffffffc)) + a0)));
    return;
}

/* Loader_DLL.xex 0x830CA580: get u32@0x40 */
ts4_word ts4_get_u32_off40_830CA580(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a1)) + 64))))((ts4_word)a0, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830CA598: get u32@0x1d4 */
ts4_word ts4_get_u32_off1d4_830CA598(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a2)) + 468))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830CB410: get u32@0x0 */
ts4_word ts4_get_u32_off0_830CB410(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(((a0 + 535953408) << 2)) + 0));
}

/* Loader_DLL.xex 0x830CBD10: get u8@0x2abd, u32@0x2a9c, u32@0x2a90, u8@0x2abd, u32@0x0, u32@0x2b04 */
ts4_word ts4_get_u8_off2abd_830CBD10(ts4_word a0)
{
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 10941);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 10908);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 10896);
    *(unsigned char *)((char *)(ts4_word)(a0) + 10941) = (unsigned char)(t1 | 3);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(t2 + -2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 11012) = (ts4_word)0;
    return fn_830DD9E0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830CC060: get u32@0x8, u32@0x4, u32@0x0, u32@0x0 */
void ts4_get_u32_off8_830CC060(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((int)(t2 - t1) >> 2);
    return;
}

/* Loader_DLL.xex 0x830D3480: get u32@0x36c */
ts4_word ts4_get_u32_off36c_830D3480(ts4_word a0, ts4_word a1)
{
    return (*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(((a1 + 112) << 3)) + a0)) + a0)) + 876));
}

/* Loader_DLL.xex 0x830D4270: addr lbl_83088E00 */
ts4_word ts4_addr_lbl_83088E00_830D4270(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_83088E00) + a0));
}

/* Loader_DLL.xex 0x830D7F10: call_seq fn_833E3088 */
ts4_word ts4_call_seq_fn_833E3088_830D7F10(void)
{
    ts4_word t1;

    t1 = fn_833E3088();
    return ((((65536) | 1) - t1) == 0);
}

/* Loader_DLL.xex 0x830DA2B0: fn  */
ts4_word ts4_fn_830DA2B0(ts4_word a0)
{
    return ((((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1ffff000)) | (a0 & 0xfff));
}

/* Loader_DLL.xex 0x830DC2C0: get u8@0x2abf, u8@0x2abf */
void ts4_get_u8_off2abf_830DC2C0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 10943) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a0) + 10943)) | 4);
    return;
}

/* Loader_DLL.xex 0x830DD900: if_call_seq fn_830B9B50, u32@0x30 */
ts4_word ts4_if_call_seq_fn_830B9B50_830DD900(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_830B9B50((ts4_word)a0, (ts4_word)70);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)t1;
    }
    return t1;
}

/* Loader_DLL.xex 0x830DE678: get u32@lbl_8352E934, u32@lbl_8352E934, u16@lbl_8352E934 */
ts4_word ts4_get_u32_lbl_8352E934_830DE678(void)
{
    *(ts4_word *)lbl_8352E934 = (ts4_word)(((int)(*(ts4_word *)lbl_8352E934) * (int)((1103495168) | 20077)) + 12345);
    return ((*(unsigned short *)lbl_8352E934) & 0x7fff);
}

/* Loader_DLL.xex 0x830DFCF0: addr lbl_83089050, u32@0x0, fn_830DFD68 */
ts4_word ts4_addr_lbl_83089050_830DFCF0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83089050;
    return fn_830DFD68((ts4_word)(a0 + 16));
}

/* Loader_DLL.xex 0x830DFFC8: loop_set u32@0x0 */
void ts4_loop_set_u32_off0_830DFFC8(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    c1 = (ts4_word)64;
    lv2 = (ts4_word)(a0 + -8);
    do {
        *(ts4_word *)((char *)(ts4_word)((lv2 + 12)) + 0) = (ts4_word)0;
        p3 = (ts4_word)(lv2 + 12);
        lv2 = p3;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x830F6AF0: get  */
void ts4_get_830F6AF0(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x830F6B48: get  */
void ts4_get_830F6B48(ts4_word a0, ts4_word a1)
{
    float t1;
    float t2;
    float t3;
    float t4;
    float t5;

    t1 = *(float *)((char *)(ts4_word)(a1) + 0);
    t2 = *(float *)((char *)(ts4_word)(a0) + 0);
    t3 = *(float *)((char *)(ts4_word)(a0) + 4);
    *(float *)((char *)(ts4_word)(a0) + 0) = (t2 - t1);
    t4 = *(float *)((char *)(ts4_word)(a1) + 4);
    t5 = *(float *)((char *)(ts4_word)(a0) + 8);
    *(float *)((char *)(ts4_word)(a0) + 4) = (t3 - t4);
    *(float *)((char *)(ts4_word)(a0) + 8) = (t5 - (*(float *)((char *)(ts4_word)(a1) + 8)));
    return;
}

/* Loader_DLL.xex 0x830F6B80: get  */
void ts4_get_830F6B80(ts4_word a0, float f1)
{
    float t1;
    float t2;
    float t3;

    t1 = *(float *)((char *)(ts4_word)(a0) + 0);
    t2 = *(float *)((char *)(ts4_word)(a0) + 4);
    t3 = *(float *)((char *)(ts4_word)(a0) + 8);
    *(float *)((char *)(ts4_word)(a0) + 0) = (t1 * f1);
    *(float *)((char *)(ts4_word)(a0) + 4) = (t2 * f1);
    *(float *)((char *)(ts4_word)(a0) + 8) = (t3 * f1);
    return;
}

/* Loader_DLL.xex 0x830F7E78: fn  */
ts4_word ts4_fn_830F7E78(ts4_word a0)
{
    return (((int)a0 * 24) + 12);
}

/* Loader_DLL.xex 0x830FA758: if_get u16@0x18, u32@0x40, u32@0x0 */
ts4_word ts4_if_get_u16_off18_830FA758(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)(a1 & 0xffff) > (ts4_word)t1) {
        return ((2147483648) | 16389);
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(((a1 & 0xffff) << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 64))));
    return 0;
}

/* Loader_DLL.xex 0x830FA790: if_get u16@0x20, u32@0x44, u32@0x48, u32@0x0 */
ts4_word ts4_if_get_u16_off20_830FA790(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned short t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)(a1 & 0xffff) > (ts4_word)t1) {
        return ((2147483648) | 16389);
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((*(unsigned short *)((char *)(ts4_word)(((a1 & 0xffff) << 1)) + t2)) + t3);
    return 0;
}

/* Loader_DLL.xex 0x830FBB60: fn  */
ts4_word ts4_fn_830FBB60(ts4_word a0, ts4_word a1)
{
    return (((int)((a1 & 0xffff) + 315) * (int)a0) << 3);
}

/* Loader_DLL.xex 0x830FCA98: if_get u32@0x8, u32@0xc, u32@0xc */
ts4_word ts4_if_get_u32_off8_830FCA98(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)(t1 - t2) < (ts4_word)a1) {
        return ((2147942400) | 122);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t2 + a1);
    return 0;
}

/* Loader_DLL.xex 0x830FD8C8: if_get u32@0x4, u32@0x10, u32@0x8, u32@0x0 */
ts4_word ts4_if_get_u32_off4_830FD8C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t1 == 11) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)0;
    }
    return 0;
}

/* Loader_DLL.xex 0x830FDBD0: get u32@0xc, u32@0xc */
void ts4_get_u32_offc_830FDBD0(ts4_word a0, float f1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(float *)((char *)(ts4_word)(a0) + 4) = f1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t1 | 1);
    return;
}

/* Loader_DLL.xex 0x830FDBE8: get u32@0xc, u32@0x8, u32@0xc */
void ts4_get_u32_offc_830FDBE8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t1 | 1);
    return;
}

/* Loader_DLL.xex 0x830FDC00: if_get u32@0x0, u32@0xc, u32@0xc */
ts4_word ts4_if_get_u32_off0_830FDC00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    (void)a0;
    if ((ts4_word)a1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)) == 4) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
        *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a2) + 4));
        *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(t2 | 1);
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x830FDC40: if_get u32@0x0, u32@0x4, u32@0xc, u32@0x8, u32@0xc */
ts4_word ts4_if_get_u32_off0_830FDC40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    if ((ts4_word)a1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)) == 6) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(t3 | 1);
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x830FDCB0: get u32@0x84, u32@0xc, u32@0x84 */
ts4_word ts4_get_u32_off84_830FDCB0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)(t1 | 1);
    return 0;
}

/* Loader_DLL.xex 0x830FDCD0: if_get u32@0x0, u32@0x4, u32@0x84, u32@0x84, u32@0xc */
ts4_word ts4_if_get_u32_off0_830FDCD0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    (void)a0;
    if ((ts4_word)a1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)) == 6) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
        *(ts4_word *)((char *)(ts4_word)(a1) + 132) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 132)) | 1);
        *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)t2;
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x830FDD10: get u32@0x84, u32@0x84 */
void ts4_get_u32_off84_830FDD10(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132)) | 1);
    return;
}

/* Loader_DLL.xex 0x830FDD20: get u32@0x84, u32@0x84 */
void ts4_get_u32_off84_830FDD20(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132)) | 2);
    return;
}

/* Loader_DLL.xex 0x830FDD30: if_get u32@0x0, u32@0x84, u32@0x84 */
ts4_word ts4_if_get_u32_off0_830FDD30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    (void)a0;
    if ((ts4_word)a1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)) == 4) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 132);
        *(float *)((char *)(ts4_word)(a1) + 64) = (*(float *)((char *)(ts4_word)(a2) + 4));
        *(ts4_word *)((char *)(ts4_word)(a1) + 132) = (ts4_word)(t2 | 2);
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x830FDE90: if_get u32@0x10, u32@0x84, u32@0x84 */
void ts4_if_get_u32_off10_830FDE90(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 132) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 132)) | 1);
    return;
}

/* Loader_DLL.xex 0x830FF3A0: call_seq fn_830FEF70 */
ts4_word ts4_call_seq_fn_830FEF70_830FF3A0(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    t1 = fn_830FEF70((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc50[0];
    return ((((t1) >> 31) + -1) & t2);
}

/* Loader_DLL.xex 0x83100058: if_get u32@0x4, u32@0x10, u32@0x8, u32@0x0 */
ts4_word ts4_if_get_u32_off4_83100058(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t1 == 11) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)0;
    }
    return 0;
}

/* Loader_DLL.xex 0x831008C0: if_call_seq fn_83120540 */
ts4_word ts4_if_call_seq_fn_83120540_831008C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83100948: if_call_seq fn_83120540 */
ts4_word ts4_if_call_seq_fn_83120540_83100948(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83100980: if_call_seq fn_83120540 */
ts4_word ts4_if_call_seq_fn_83120540_83100980(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831009B8: if_call_seq fn_83120540 */
ts4_word ts4_if_call_seq_fn_83120540_831009B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x831009F0: if_call_seq fn_83120540 */
ts4_word ts4_if_call_seq_fn_83120540_831009F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83100A28: if_call_seq fn_83120540 */
ts4_word ts4_if_call_seq_fn_83120540_83100A28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83100BA0: if_call_seq fn_83120540 */
ts4_word ts4_if_call_seq_fn_83120540_83100BA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((int)(a1 & 0x1) != 0) {
        fn_83120540((ts4_word)a0);
    }
    return a0;
}

/* Loader_DLL.xex 0x83100F50: get  */
void ts4_get_83100F50(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    return;
}

/* Loader_DLL.xex 0x83100F68: get  */
void ts4_get_83100F68(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x83101100: get  */
void ts4_get_83101100(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    return;
}

/* Loader_DLL.xex 0x831015A0: addr lbl_83000F5C, u32@0x0 */
void ts4_addr_lbl_83000F5C_831015A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83000F5C;
    return;
}

/* Loader_DLL.xex 0x831019B0: addr lbl_83000F78, u32@0x0 */
void ts4_addr_lbl_83000F78_831019B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83000F78;
    return;
}

/* Loader_DLL.xex 0x831019C0: addr lbl_83000F94, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_83000F94_831019C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83000F94;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83101A28: if_get u32@0xc, u32@0xc, u32@0x10, u32@0x84, u32@0x84 */
void ts4_if_get_u32_offc_83101A28(ts4_word a0, int a1)
{
    ts4_word p2;
    ts4_word t1;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)a1 != 0) {
        p2 = (ts4_word)(t1 | 1);
    } else {
        p2 = (ts4_word)(t1 & 0xfffffffe);
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)p2;
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t3 == 0) {
        return;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(t3) + 132) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t3) + 132)) | 1);
    return;
}

/* Loader_DLL.xex 0x83101D80: get u32@0x84, u32@0x84, fn_830FFBE8 */
ts4_word ts4_get_u32_off84_83101D80(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132)) | 1);
    return fn_830FFBE8((ts4_word)(a0 + 16));
}

/* Loader_DLL.xex 0x83101D98: if_get u32@0x0, u32@0x84, u32@0x4, u32@0x84, fn_830FFBE8 */
ts4_word ts4_if_get_u32_off0_83101D98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    if ((ts4_word)a1 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a2) + 0)) == 5) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 132);
        t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
        *(ts4_word *)((char *)(ts4_word)(a1) + 132) = (ts4_word)(t2 | 1);
        return fn_830FFBE8((ts4_word)(a1 + 16), (ts4_word)t3);
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x83103560: get u32@0x4, u32@0x4, fn_830FFBE8 */
ts4_word ts4_get_u32_off4_83103560(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) | 1);
    return fn_830FFBE8((ts4_word)(a0 + 8));
}

/* Loader_DLL.xex 0x83105778: if_call_seq fn_831005B8, u32@0x8 */
ts4_word ts4_if_call_seq_fn_831005B8_83105778(void)
{
    ts4_word p3;
    ts4_word t1;

    t1 = fn_831005B8();
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 8));
    }
    return p3;
}

/* Loader_DLL.xex 0x83111378: get u32@0x20, u32@0x0, u32@0x24, u32@0x0 */
void ts4_get_u32_off20_83111378(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    return;
}

/* Loader_DLL.xex 0x831113B8: get u32@0x4 */
ts4_word ts4_get_u32_off4_831113B8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return (((~(t1 | t1)) >> 2) & 0x1);
}

/* Loader_DLL.xex 0x831113F0: if_get u32@0x4, u32@0x4 */
void ts4_if_get_u32_off4_831113F0(ts4_word a0, int a1)
{
    ts4_word p2;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)a1 != 0) {
        p2 = (ts4_word)(t1 & 0xfffffffb);
    } else {
        p2 = (ts4_word)(t1 | 4);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p2;
    return;
}

/* Loader_DLL.xex 0x83111B48: if_call_seq u32@lbl_8352F7B4, fn_83111448, fn_831275C8 */
ts4_word ts4_if_call_seq_u32_lbl_8352F7B4_83111B48(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7B4));
    if ((ts4_word)t2 == 0) {
        p4 = (ts4_word)((2150629376) | 22);
    } else {
        t3 = fn_831275C8((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83111C98: if_call_seq u32@lbl_8352F7B4, fn_83111448, u32@0xc */
ts4_word ts4_if_call_seq_u32_lbl_8352F7B4_83111C98(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7B4));
    if ((ts4_word)t2 == 0) {
        p4 = (ts4_word)-1;
    } else {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 12));
    }
    return p4;
}

/* Loader_DLL.xex 0x83111D28: if_call_seq u32@lbl_8352F7B4, fn_83111448, u32@0x10 */
ts4_word ts4_if_call_seq_u32_lbl_8352F7B4_83111D28(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7B4));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(t2) + 16)) >> 1) & 0x1);
    }
    return p4;
}

/* Loader_DLL.xex 0x83111E20: if_call_seq u32@lbl_8352F7D8, fn_83111448, u32@0x18 */
ts4_word ts4_if_call_seq_u32_lbl_8352F7D8_83111E20(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7D8));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 24));
    }
    return p4;
}

/* Loader_DLL.xex 0x83111E58: if_call_seq u32@lbl_8352F7D8, fn_83111448, u32@0x1c */
ts4_word ts4_if_call_seq_u32_lbl_8352F7D8_83111E58(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7D8));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 28));
    }
    return p4;
}

/* Loader_DLL.xex 0x83112028: if_call_seq u32@lbl_8352F7F4, fn_83111448, u32@0x30 */
ts4_word ts4_if_call_seq_u32_lbl_8352F7F4_83112028(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7F4));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 48));
    }
    return p4;
}

/* Loader_DLL.xex 0x83112060: call_seq u32@lbl_8352F7C4, fn_830FFAB0 */
ts4_word ts4_call_seq_u32_lbl_8352F7C4_83112060(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_830FFAB0((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7C4));
    return (t2 != 0);
}

/* Loader_DLL.xex 0x83112090: call_seq u32@lbl_8352F7C8, fn_830FFAB0 */
ts4_word ts4_call_seq_u32_lbl_8352F7C8_83112090(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_830FFAB0((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7C8));
    return (t2 != 0);
}

/* Loader_DLL.xex 0x831120C0: if_call_seq u32@lbl_8352F7C4, fn_83111448, u32@0x4 */
ts4_word ts4_if_call_seq_u32_lbl_8352F7C4_831120C0(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7C4));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 4));
    }
    return p4;
}

/* Loader_DLL.xex 0x831120F8: if_call_seq u32@lbl_8352F7C4, fn_83111448, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_8352F7C4_831120F8(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7C4));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 8)) & 0x1);
    }
    return p4;
}

/* Loader_DLL.xex 0x83112358: call_seq u32@lbl_83527DA0, KeTlsGetValue */
ts4_word ts4_call_seq_u32_lbl_83527DA0_83112358(void)
{
    ts4_word t2;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_83527DA0));
    return (t2 != 0);
}

/* Loader_DLL.xex 0x83113428: if_call_seq u32@lbl_8352F7B0, fn_83111448, fn_83121438 */
ts4_word ts4_if_call_seq_u32_lbl_8352F7B0_83113428(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7B0));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t3 = fn_83121438((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83113768: if_call_seq u32@lbl_8352F7A0, fn_83111448, fn_83121950 */
ts4_word ts4_if_call_seq_u32_lbl_8352F7A0_83113768(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F7A0));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t3 = fn_83121950((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83113F48: if_call_seq fn_83141DE8, fn_83141D10 */
ts4_word ts4_if_call_seq_fn_83141DE8_83113F48(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = fn_83141DE8();
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_83141D10((ts4_word)t1, (ts4_word)a1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x83113F88: if_call_seq fn_83141DE8, fn_83141C60 */
ts4_word ts4_if_call_seq_fn_83141DE8_83113F88(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;

    (void)a0;
    t1 = fn_83141DE8();
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_83141C60((ts4_word)t1, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x83114148: if_call_seq u32@lbl_8352F818, fn_83111448, fn_8312C130 */
ts4_word ts4_if_call_seq_u32_lbl_8352F818_83114148(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F818));
    if ((ts4_word)t2 == 0) {
        p4 = (ts4_word)((2150629376) | 22);
    } else {
        t3 = fn_8312C130((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83114188: if_call_seq u32@lbl_8352F818, fn_83111448, fn_8312C248 */
ts4_word ts4_if_call_seq_u32_lbl_8352F818_83114188(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F818));
    if ((ts4_word)t2 == 0) {
        p4 = (ts4_word)((2150629376) | 22);
    } else {
        t3 = fn_8312C248((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Loader_DLL.xex 0x83114228: if_call_seq u32@lbl_8352F818, fn_83111448, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_8352F818_83114228(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F818));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 8));
    }
    return p4;
}

/* Loader_DLL.xex 0x83114320: get u32@0x0 */
ts4_word ts4_get_u32_off0_83114320(ts4_word a0, ts4_word a1)
{
    return (((int)a1 * 12) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x83114350: get u32@0x0 */
ts4_word ts4_get_u32_off0_83114350(ts4_word a0, ts4_word a1)
{
    return (((int)a1 * 12) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x83114390: get u32@0x0 */
ts4_word ts4_get_u32_off0_83114390(ts4_word a0, ts4_word a1)
{
    return (((int)a1 * 12) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x831143C0: get u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
void ts4_get_u32_off0_831143C0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    return;
}

/* Loader_DLL.xex 0x83115350: get u32@0x8 */
ts4_word ts4_get_u32_off8_83115350(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) == 0);
}

/* Loader_DLL.xex 0x83116538: if_call_seq fn_83115F78, fn_83111970 */
ts4_word ts4_if_call_seq_fn_83115F78_83116538(void)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_83115F78();
    p4 = (ts4_word)255;
    if ((ts4_word)t1 != 0) {
        t2 = fn_83111970();
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Loader_DLL.xex 0x83116FC0: set u32@0x4, lbl_8300220C, u32@0x0 */
void ts4_set_u32_off4_83116FC0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300220C;
    return;
}

/* Loader_DLL.xex 0x83118650: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_83118650(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x83119A30: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_83119A30(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x83119A50: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_83119A50(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x83119A70: if_get u32@0x0, u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8 */
void ts4_if_get_u32_off0_83119A70(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)(((int)a1 * 12) + t1) == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)((((int)a1 * 12) + t1)) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    *(ts4_word *)((char *)(ts4_word)((((int)a1 * 12) + t1)) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 4));
    *(ts4_word *)((char *)(ts4_word)((((int)a1 * 12) + t1)) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 8));
    return;
}

/* Loader_DLL.xex 0x8311AD70: if_set u32@0x4, u32@0x8, u32@0x0, u32@0x10, u32@0x14, u32@0x28 */
void ts4_if_set_u32_off4_8311AD70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, int a5)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)2;
    if ((int)a5 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a3;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(a2 - a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(t1 | 1);
    return;
}

/* Loader_DLL.xex 0x8311D480: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_8311D480(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x8311DDC8: addr lbl_83002248, u32@0xc, u32@0x4, u32@0x0, u32@0x8, u32@0x1c */
void ts4_addr_lbl_83002248_8311DDC8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002248;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x8311E138: if_set u32@0x0, u32@0x0, u32@0x28 */
ts4_word ts4_if_set_u32_off0_8311E138(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return ((2147942400) | 87);
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8311E170: if_get u32@0x0, u32@0x20 */
ts4_word ts4_if_get_u32_off0_8311E170(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0);
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x8311E1A0: if_get u32@0x0, u32@0x24 */
ts4_word ts4_if_get_u32_off0_8311E1A0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8311E240: if_get u32@0x0, u32@0x10 */
ts4_word ts4_if_get_u32_off0_8311E240(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8311E260: if_get u32@0x0, u32@0x1c */
ts4_word ts4_if_get_u32_off0_8311E260(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return ((2147942400) | 87);
    }
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8311E3B8: if_call_seq lbl_83002264, fn_833E4AF8 */
ts4_word ts4_if_call_seq_lbl_83002264_8311E3B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p2 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        t1 = fn_833E4AF8((ts4_word)a0, (ts4_word)(ts4_word)lbl_83002264);
        p2 = (ts4_word)(t1 != 0);
    }
    return p2;
}

/* Loader_DLL.xex 0x8311E7A8: addr lbl_83002270, u32@0x4, u32@0x0 */
void ts4_addr_lbl_83002270_8311E7A8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002270;
    return;
}

/* Loader_DLL.xex 0x8311EE58: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_8311EE58(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x83120028: get u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_83120028(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120038: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_83120038(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120048: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_83120048(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120058: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_83120058(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120068: get u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off0_83120068(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120078: get u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off0_83120078(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120088: get u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off0_83120088(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120098: get u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off0_83120098(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831200A8: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_831200A8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831200B8: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_831200B8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831200C8: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_831200C8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831200D8: get u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off0_831200D8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831200E8: get u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off0_831200E8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831200F8: get u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off0_831200F8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120108: get u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_83120108(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120118: get u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off0_83120118(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120128: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_83120128(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120138: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_83120138(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120148: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_83120148(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120158: get u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off0_83120158(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120168: get u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off0_83120168(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120178: get u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off0_83120178(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120188: get u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_83120188(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120198: get u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off0_83120198(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831201A8: get u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off0_831201A8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831201B8: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_831201B8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831201C8: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_831201C8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831201D8: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_831201D8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831201E8: get u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off0_831201E8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831201F8: get u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off0_831201F8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120208: get u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off0_83120208(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120218: get u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_83120218(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120228: get u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off0_83120228(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120238: get u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off0_83120238(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120248: get u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off0_83120248(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120258: get u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_off0_83120258(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120268: get u32@0x0, u32@0x2c */
ts4_word ts4_get_u32_off0_83120268(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120278: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_83120278(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120288: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_83120288(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120298: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_83120298(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831202A8: get u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off0_831202A8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831202B8: get u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off0_831202B8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831202C8: get u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off0_831202C8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831202D8: get u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_831202D8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831202E8: get u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off0_831202E8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831202F8: get u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off0_831202F8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120308: get u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_off0_83120308(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120318: get u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_off0_83120318(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120328: get u32@0x0, u32@0x2c */
ts4_word ts4_get_u32_off0_83120328(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831203D0: get u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off0_831203D0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831203E0: get u32@0x0, u32@0x3c */
ts4_word ts4_get_u32_off0_831203E0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x831203F0: get u32@0x0, u32@0x40 */
ts4_word ts4_get_u32_off0_831203F0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120400: get u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_83120400(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 68))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120410: get u32@0x0, u32@0x48 */
ts4_word ts4_get_u32_off0_83120410(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120420: get u32@0x0, u32@0x4c */
ts4_word ts4_get_u32_off0_83120420(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 76))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120430: get u32@0x0, u32@0x50 */
ts4_word ts4_get_u32_off0_83120430(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 80))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120440: get u32@0x0, u32@0x54 */
ts4_word ts4_get_u32_off0_83120440(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 84))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120450: get u32@0x0, u32@0x58 */
ts4_word ts4_get_u32_off0_83120450(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 88))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83120630: get u32@0x0 */
ts4_word ts4_get_u32_off0_83120630(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) == 0);
}

/* Loader_DLL.xex 0x831207B0: addr lbl_83002354, u32@0x0 */
void ts4_addr_lbl_83002354_831207B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83002354;
    return;
}

/* Loader_DLL.xex 0x831208B8: get u32@0xc8, u32@0xc8 */
void ts4_get_u32_offc8_831208B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 200)) | 1);
    return;
}

/* Loader_DLL.xex 0x83120A28: get u32@0x4 */
ts4_word ts4_get_u32_off4_83120A28(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return (((~(t1 | t1)) >> 5) & 0x1);
}

/* Loader_DLL.xex 0x83120A38: get u32@0x4 */
ts4_word ts4_get_u32_off4_83120A38(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return (((~(t1 | t1)) >> 4) & 0x1);
}

/* Loader_DLL.xex 0x83120A48: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_83120A48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) | 8);
    return;
}

/* Loader_DLL.xex 0x83120A58: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_83120A58(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) & 0xfffffff7);
    return;
}

/* Loader_DLL.xex 0x83120CB0: get u32@0x10, u32@0x8 */
ts4_word ts4_get_u32_off10_83120CB0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    *(float *)((char *)(ts4_word)(t1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 12));
    *(float *)((char *)(ts4_word)(t1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 16));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)1;
    return 0;
}

/* Loader_DLL.xex 0x83120EC8: call_seq fn_830FF250 */
ts4_word ts4_call_seq_fn_830FF250_83120EC8(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    t1 = fn_830FF250((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc50[0];
    return ((((t1) >> 31) + -1) & t2);
}

/* Loader_DLL.xex 0x83121418: if_get u32@0xc8, u32@0xc8 */
void ts4_if_get_u32_offc8_83121418(ts4_word a0, int a1)
{
    ts4_word p2;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 200);
    if ((int)a1 != 0) {
        p2 = (ts4_word)(t1 | 2);
    } else {
        p2 = (ts4_word)(t1 & 0xfffffffd);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 200) = (ts4_word)p2;
    return;
}

/* Loader_DLL.xex 0x83121D58: get u32@0x8, u32@0x0, u32@0xc, u32@0x0 */
void ts4_get_u32_off8_83121D58(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    return;
}

/* Loader_DLL.xex 0x83121E10: get u32@0x10, u32@0x0, u32@0x14, u32@0x0 */
void ts4_get_u32_off10_83121E10(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    return;
}

/* Loader_DLL.xex 0x831223D0: if_call_seq u32@lbl_8352F804, fn_83111448, u32@0x94 */
ts4_word ts4_if_call_seq_u32_lbl_8352F804_831223D0(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F804));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 148)) & 0x1);
    }
    return p4;
}

/* Loader_DLL.xex 0x83122408: if_call_seq u32@lbl_8352F804, fn_83111448, u32@0x90 */
ts4_word ts4_if_call_seq_u32_lbl_8352F804_83122408(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_83111448((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352F804));
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 144));
    }
    return p4;
}

/* Loader_DLL.xex 0x83122C70: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_83122C70(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return (((*(ts4_word *)((char *)(ts4_word)(a1) + 0)) - t1) == 0);
}

/* Loader_DLL.xex 0x83122CF0: get u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
void ts4_get_u32_off0_83122CF0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    return;
}

/* Loader_DLL.xex 0x83122E80: get  */
void ts4_get_83122E80(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    return;
}

/* Loader_DLL.xex 0x83122F30: get  */
void ts4_get_83122F30(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    return;
}

/* Loader_DLL.xex 0x83122F90: get  */
void ts4_get_83122F90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    float t1;
    float t3;

    t1 = *(float *)((char *)(ts4_word)(a2) + 0);
    *(float *)((char *)(ts4_word)(a0) + 0) = ((*(float *)((char *)(ts4_word)(a1) + 0)) - t1);
    t3 = *(float *)((char *)(ts4_word)(a1) + 4);
    *(float *)((char *)(ts4_word)(a0) + 4) = (t3 - (*(float *)((char *)(ts4_word)(a2) + 4)));
    return;
}

/* Loader_DLL.xex 0x83122FB8: get  */
void ts4_get_83122FB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    float t1;
    float t3;
    float t5;

    t1 = *(float *)((char *)(ts4_word)(a2) + 0);
    *(float *)((char *)(ts4_word)(a0) + 0) = ((*(float *)((char *)(ts4_word)(a1) + 0)) + t1);
    t3 = *(float *)((char *)(ts4_word)(a2) + 4);
    *(float *)((char *)(ts4_word)(a0) + 4) = ((*(float *)((char *)(ts4_word)(a1) + 4)) + t3);
    t5 = *(float *)((char *)(ts4_word)(a1) + 8);
    *(float *)((char *)(ts4_word)(a0) + 8) = (t5 + (*(float *)((char *)(ts4_word)(a2) + 8)));
    return;
}

/* Loader_DLL.xex 0x83125C88: get  */
ts4_word ts4_get_83125C88(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 48));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 52));
    *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(a0) + 56));
    return 0;
}

/* Loader_DLL.xex 0x83125CB0: get  */
ts4_word ts4_get_83125CB0(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 60));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 64));
    *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(a0) + 68));
    return 0;
}

/* Loader_DLL.xex 0x83125CD8: get  */
ts4_word ts4_get_83125CD8(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 72));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 76));
    *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(a0) + 80));
    *(float *)((char *)(ts4_word)(a1) + 12) = (*(float *)((char *)(ts4_word)(a0) + 84));
    return 0;
}

/* Loader_DLL.xex 0x83125D08: get u32@0xf0, u32@0xf0 */
ts4_word ts4_get_u32_offf0_83125D08(ts4_word a0, ts4_word a1)
{
    *(volatile float *)((char *)(ts4_word)(a0) + 72) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(volatile float *)((char *)(ts4_word)(a0) + 76) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(volatile float *)((char *)(ts4_word)(a0) + 80) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(volatile float *)((char *)(ts4_word)(a0) + 84) = (*(float *)((char *)(ts4_word)(a1) + 12));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 240)) | 2);
    return 0;
}

/* Loader_DLL.xex 0x83125D40: get  */
ts4_word ts4_get_83125D40(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 88));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 92));
    *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(a0) + 96));
    return 0;
}

/* Loader_DLL.xex 0x83125D68: get u32@0xf0, u32@0xf0 */
ts4_word ts4_get_u32_offf0_83125D68(ts4_word a0, ts4_word a1)
{
    *(volatile float *)((char *)(ts4_word)(a0) + 88) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(volatile float *)((char *)(ts4_word)(a0) + 92) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(volatile float *)((char *)(ts4_word)(a0) + 96) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 240)) | 2);
    return 0;
}

/* Loader_DLL.xex 0x83126820: get u32@0x18, u32@0x18 */
void ts4_get_u32_off18_83126820(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)(a1) + 16));
    *(float *)((char *)(ts4_word)(a0) + 20) = (*(float *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    return;
}

/* Loader_DLL.xex 0x83126860: get  */
ts4_word ts4_get_83126860(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 204));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 208));
    return 0;
}

/* Loader_DLL.xex 0x8312A958: get u32@0x0, u32@0x0, u32@0xc, u32@0xc, u32@0x10, u32@0x10 */
void ts4_get_u32_off0_8312A958(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    return;
}

/* Loader_DLL.xex 0x8312C790: get  */
void ts4_get_8312C790(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    return;
}

/* Loader_DLL.xex 0x8312D640: if_get u32@0x0, u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
void ts4_if_get_u32_off0_8312D640(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)((a1 << 3) + t1) == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(((a1 << 3) + t1)) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    *(ts4_word *)((char *)(ts4_word)(((a1 << 3) + t1)) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 4));
    return;
}

/* Loader_DLL.xex 0x8312E0F0: addr lbl_8300267C, u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_addr_lbl_8300267C_8312E0F0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8300267C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8312E5E0: get u32@0x18, u32@0x18 */
void ts4_get_u32_off18_8312E5E0(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)(a1) + 16));
    *(float *)((char *)(ts4_word)(a0) + 20) = (*(float *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    return;
}

/* Loader_DLL.xex 0x8313D1D8: get u8@0x0 */
ts4_word ts4_get_u8_off0_8313D1D8(ts4_word a0)
{
    return (((*(unsigned char *)((char *)(ts4_word)(a0) + 0)) & 0x7) == 0);
}

/* Loader_DLL.xex 0x8313D240: if_get u8@0x0 */
ts4_word ts4_if_get_u8_off0_8313D240(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    if ((int)(t1 & 0xffffff80) != 0) {
        return ((t1 & 0xffffff7f) + 1);
    }
    return 1;
}

/* Loader_DLL.xex 0x8313D8A8: get u8@0x4, u8@0x4 */
void ts4_get_u8_off4_8313D8A8(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)(((*(unsigned char *)((char *)(ts4_word)(a0) + 4)) & 249) | (a1 << 1));
    return;
}

/* Loader_DLL.xex 0x8313F300: get u32@0x0 */
ts4_word ts4_get_u32_off0_8313F300(ts4_word a0, ts4_word a1)
{
    return (((int)a1 * 12) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x8313FE80: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_8313FE80(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x83140388: call_seq lbl_83531134, fn_83140210, lbl_83531160, fn_83140210, lbl_83531108, fn_83140210 */
ts4_word ts4_call_seq_lbl_83531134_83140388(void)
{
    ts4_word t3;

    fn_83140210((ts4_word)(ts4_word)lbl_83531134);
    fn_83140210((ts4_word)(ts4_word)lbl_83531160);
    t3 = fn_83140210((ts4_word)(ts4_word)lbl_83531108);
    return t3;
}

/* Loader_DLL.xex 0x83140408: set u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_set_u32_off0_83140408(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Loader_DLL.xex 0x83140480: if_get u32@0x0, u32@0x4, u32@0x0 */
void ts4_if_get_u32_off0_83140480(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 == 5) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83140C60: set u32@0x0 */
void ts4_set_u32_off0_83140C60(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)8;
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)(a1) + 12));
    return;
}

/* Loader_DLL.xex 0x831416A0: if_get u32@0x0, u32@0x8, fn_83120540 */
ts4_word ts4_if_get_u32_off0_831416A0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)(t1 & 0x1) != 0) {
        return a0;
    }
    return fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
}

/* Loader_DLL.xex 0x831433E0: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_831433E0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return (((*(ts4_word *)((char *)(ts4_word)(a1) + 0)) - t1) == 0);
}

/* Loader_DLL.xex 0x831436D8: call_seq lbl_83002860, fn_8310D380, fn_83143438, lbl_83531108, fn_8313FEA0 */
ts4_word ts4_call_seq_lbl_83002860_831436D8(void)
{
    ts4_word t1;

    t1 = fn_8310D380((ts4_word)(ts4_word)lbl_83002860);
    fn_83143438((ts4_word)t1);
    fn_8313FEA0((ts4_word)(ts4_word)lbl_83531108);
    return 0;
}

/* Loader_DLL.xex 0x83143778: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_83143778(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return (((*(ts4_word *)((char *)(ts4_word)(a1) + 0)) - t1) == 0);
}

/* Loader_DLL.xex 0x83144A50: addr lbl_830028A4, u32@0x4, u32@0x0, u32@0xc, u32@0x10, u32@0x14 */
void ts4_addr_lbl_830028A4_83144A50(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830028A4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83144A88: addr lbl_830028A4, u32@0x0 */
void ts4_addr_lbl_830028A4_83144A88(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_830028A4;
    return;
}

/* Loader_DLL.xex 0x831452E0: get u32@0x0 */
ts4_word ts4_get_u32_off0_831452E0(ts4_word a0, ts4_word a1)
{
    return (((int)a1 * 12) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}
