/* Loader_DLL.xex 0x830AE548-0x830C7540, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_83544950[];
ts4_word KeUnlockL2();
ts4_word fn_830ACE48();
ts4_word fn_830AEE68();
ts4_word fn_830AF8A8();
ts4_word fn_830AFA08();
ts4_word fn_830B3380();
ts4_word fn_830B37D0();
ts4_word fn_830B86E0();
ts4_word fn_830B88A8();
ts4_word fn_830B9C30();
ts4_word fn_830BA770();
ts4_word fn_830BB150();
ts4_word fn_830BBC00();
ts4_word fn_830C0788();
ts4_word fn_830C1080();
ts4_word fn_830C2B00();
ts4_word fn_830C2B68();
ts4_word fn_830C3358();
ts4_word fn_830C3438();
ts4_word fn_830C3528();
ts4_word fn_830C37E8();
ts4_word fn_830C4600();
ts4_word fn_830C46E8();
ts4_word fn_830C4748();
ts4_word fn_830C47B0();
ts4_word fn_830C48B0();
ts4_word fn_830C4998();
ts4_word fn_830C4B18();
ts4_word fn_830C4C08();
ts4_word fn_830C4CA8();
ts4_word fn_830C4D80();
ts4_word fn_830C4E40();
ts4_word fn_830C60B8();
ts4_word fn_830C6CC8();
ts4_word fn_830C6DF0();
ts4_word fn_830C72C8();
ts4_word fn_830C7830();
ts4_word fn_830C7958();
ts4_word fn_830C7A00();
ts4_word fn_830D2EC0();
ts4_word fn_830D2FA8();
ts4_word fn_833E3A30();
ts4_word fn_833E3AD0();
ts4_word fn_8340C4F8();
ts4_word fn_8340D830();

/* Loader_DLL.xex 0x830AE548: fn  */
ts4_word ts4_fn_830AE548(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830AE580: tailcall fn_830C0788 */
ts4_word ts4_tailcall_fn_830C0788_830AE580(ts4_word a0, ts4_word a1)
{
    return fn_830C0788((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830AE588: get u32@0x18 */
ts4_word ts4_get_u32_off18_830AE588(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Loader_DLL.xex 0x830AE590: get u32@0x20 */
ts4_word ts4_get_u32_off20_830AE590(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x830AE598: fn  */
ts4_word ts4_fn_830AE598(ts4_word a0, ts4_word a1)
{
    return ((a0 << 16) | a1);
}

/* Loader_DLL.xex 0x830AE5A8: set u32@0x0, u32@0x0 */
void ts4_set_u32_off0_830AE5A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)((a0) >> 16);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(a0 & 0xffff);
    return;
}

/* Loader_DLL.xex 0x830AE5C0: fn  */
void ts4_fn_830AE5C0(void)
{
    return;
}

/* Loader_DLL.xex 0x830AE5C8: fn  */
void ts4_fn_830AE5C8(void)
{
    return;
}

/* Loader_DLL.xex 0x830AE858: get u32@lbl_83544950 */
ts4_word ts4_get_u32_lbl_83544950_830AE858(void)
{
    return ((*(ts4_word *)lbl_83544950) != 0);
}

/* Loader_DLL.xex 0x830AEAA0: set u32@0x0 */
void ts4_set_u32_off0_830AEAA0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830AF558: get u32@0x18, fn_830AEE68 */
ts4_word ts4_get_u32_off18_830AF558(ts4_word a0)
{
    return fn_830AEE68((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24)) & 0xfffffffc), (ts4_word)0);
}

/* Loader_DLL.xex 0x830AF5F8: get u32@0x18, fn_830AEE68 */
ts4_word ts4_get_u32_off18_830AF5F8(ts4_word a0)
{
    return fn_830AEE68((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)0);
}

/* Loader_DLL.xex 0x830AF778: get u32@0x18, fn_830AEE68 */
ts4_word ts4_get_u32_off18_830AF778(ts4_word a0)
{
    return fn_830AEE68((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)0);
}

/* Loader_DLL.xex 0x830AFA00: tailcall fn_830AF8A8 */
ts4_word ts4_tailcall_fn_830AF8A8_830AFA00(ts4_word a0)
{
    return fn_830AF8A8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830AFD90: tailcall fn_830AFA08 */
ts4_word ts4_tailcall_fn_830AFA08_830AFD90(ts4_word a0)
{
    return fn_830AFA08((ts4_word)a0);
}

/* Loader_DLL.xex 0x830B0380: fn  */
void ts4_fn_830B0380(void)
{
    return;
}

/* Loader_DLL.xex 0x830B0400: fn  */
ts4_word ts4_fn_830B0400(ts4_word a0, ts4_word a1)
{
    return (a0 & ~(a1 + -1));
}

/* Loader_DLL.xex 0x830B0410: fn  */
ts4_word ts4_fn_830B0410(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830B04A0: fn  */
ts4_word ts4_fn_830B04A0(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830B04B8: fn  */
void ts4_fn_830B04B8(void)
{
    return;
}

/* Loader_DLL.xex 0x830B04C0: fn  */
ts4_word ts4_fn_830B04C0(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830B0560: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_830B0560(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830B0568: set u64@0x0, u64@0x8, u64@0x10, u64@0x18, u64@0x20 */
void ts4_set_u64_off0_830B0568(ts4_word a0)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 0) = (ts4_u64)-1;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 8) = (ts4_u64)-1;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 16) = (ts4_u64)-1;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 24) = (ts4_u64)-1;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 32) = (ts4_u64)-1;
    return;
}

/* Loader_DLL.xex 0x830B0E48: fn  */
void ts4_fn_830B0E48(void)
{
    return;
}

/* Loader_DLL.xex 0x830B0E50: fn  */
ts4_word ts4_fn_830B0E50(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830B0E78: get u32@0x2948 */
ts4_word ts4_get_u32_off2948_830B0E78(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10568)) & 0x7);
}

/* Loader_DLL.xex 0x830B0EA8: get u32@0x2948 */
ts4_word ts4_get_u32_off2948_830B0EA8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10568)) >> 3) & 0xff);
}

/* Loader_DLL.xex 0x830B0EE0: get u32@0x293c */
ts4_word ts4_get_u32_off293c_830B0EE0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10556)) >> 3) & 0x1);
}

/* Loader_DLL.xex 0x830B0FE8: get u32@0x2efc */
ts4_word ts4_get_u32_off2efc_830B0FE8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 12028))) >> 31);
}

/* Loader_DLL.xex 0x830B1078: get u32@0x2ef8 */
ts4_word ts4_get_u32_off2ef8_830B1078(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 12024)) >> 5) & 0x7);
}

/* Loader_DLL.xex 0x830B1108: get u32@0x2ef8 */
ts4_word ts4_get_u32_off2ef8_830B1108(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 12024)) & 0x1f);
}

/* Loader_DLL.xex 0x830B1198: get u32@0x2ef8 */
ts4_word ts4_get_u32_off2ef8_830B1198(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 12024)) >> 8) & 0x1f);
}

/* Loader_DLL.xex 0x830B1208: get u32@0x2ef8 */
ts4_word ts4_get_u32_off2ef8_830B1208(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 12024)) >> 21) & 0x7);
}

/* Loader_DLL.xex 0x830B1278: get u16@0x2ef8 */
ts4_word ts4_get_u16_off2ef8_830B1278(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)(a0) + 12024)) & 0x1f);
}

/* Loader_DLL.xex 0x830B12E8: get u8@0x2ef8 */
ts4_word ts4_get_u8_off2ef8_830B12E8(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)(a0) + 12024)) & 0x1f);
}

/* Loader_DLL.xex 0x830B1380: get u32@0x2efc */
ts4_word ts4_get_u32_off2efc_830B1380(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 12028)) >> 30) & 0x1);
}

/* Loader_DLL.xex 0x830B1410: get u32@0x293c */
ts4_word ts4_get_u32_off293c_830B1410(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10556)) & 0x7);
}

/* Loader_DLL.xex 0x830B1550: get u32@0x29b8 */
ts4_word ts4_get_u32_off29b8_830B1550(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10680)) >> 10) & 0x1);
}

/* Loader_DLL.xex 0x830B15F8: get u32@0x5e88 */
ts4_word ts4_get_u32_off5e88_830B15F8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 24200)) & 0x1);
}

/* Loader_DLL.xex 0x830B1640: get u32@0x2f14 */
ts4_word ts4_get_u32_off2f14_830B1640(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12052));
}

/* Loader_DLL.xex 0x830B1668: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B1668(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548)) >> 2) & 0x1);
}

/* Loader_DLL.xex 0x830B16A0: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B16A0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548)) >> 4) & 0x7);
}

/* Loader_DLL.xex 0x830B16E8: get u32@0x2f18 */
ts4_word ts4_get_u32_off2f18_830B16E8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12056));
}

/* Loader_DLL.xex 0x830B1718: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B1718(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548)) >> 7) & 0x1);
}

/* Loader_DLL.xex 0x830B1748: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B1748(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548)) >> 8) & 0x7);
}

/* Loader_DLL.xex 0x830B1780: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B1780(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548)) >> 11) & 0x7);
}

/* Loader_DLL.xex 0x830B17B8: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B17B8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548)) >> 17) & 0x7);
}

/* Loader_DLL.xex 0x830B17E8: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B17E8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548)) >> 14) & 0x7);
}

/* Loader_DLL.xex 0x830B1818: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B1818(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548)) >> 20) & 0x7);
}

/* Loader_DLL.xex 0x830B1850: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B1850(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548)) >> 23) & 0x7);
}

/* Loader_DLL.xex 0x830B1888: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B1888(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548))) >> 29);
}

/* Loader_DLL.xex 0x830B18B8: get u32@0x2934 */
ts4_word ts4_get_u32_off2934_830B18B8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10548)) >> 26) & 0x7);
}

/* Loader_DLL.xex 0x830B18E0: get u8@0x2903 */
ts4_word ts4_get_u8_off2903_830B18E0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10499));
}

/* Loader_DLL.xex 0x830B1900: get u8@0x2902 */
ts4_word ts4_get_u8_off2902_830B1900(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10498));
}

/* Loader_DLL.xex 0x830B1920: get u8@0x2901 */
ts4_word ts4_get_u8_off2901_830B1920(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10497));
}

/* Loader_DLL.xex 0x830B1940: get u8@0x28ff */
ts4_word ts4_get_u8_off28ff_830B1940(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10495));
}

/* Loader_DLL.xex 0x830B1960: get u8@0x28fe */
ts4_word ts4_get_u8_off28fe_830B1960(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10494));
}

/* Loader_DLL.xex 0x830B1980: get u8@0x28fd */
ts4_word ts4_get_u8_off28fd_830B1980(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10493));
}

/* Loader_DLL.xex 0x830B19D0: get u32@0x2944 */
ts4_word ts4_get_u32_off2944_830B19D0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10564)) & 0x3f);
}

/* Loader_DLL.xex 0x830B19E0: set u32@0x2f00, fn_830B3380 */
ts4_word ts4_set_u32_off2f00_830B19E0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12032) = (ts4_word)a1;
    return fn_830B3380((ts4_word)a0, (ts4_word)(a0 + 12852));
}

/* Loader_DLL.xex 0x830B19F0: get u32@0x2f00 */
ts4_word ts4_get_u32_off2f00_830B19F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12032));
}

/* Loader_DLL.xex 0x830B1B98: get u32@0x2948 */
ts4_word ts4_get_u32_off2948_830B1B98(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10568)) >> 15) & 0x1);
}

/* Loader_DLL.xex 0x830B1BC0: get u32@0x2a00 */
ts4_word ts4_get_u32_off2a00_830B1BC0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10752));
}

/* Loader_DLL.xex 0x830B1C00: get u32@0x2f04 */
ts4_word ts4_get_u32_off2f04_830B1C00(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12036));
}

/* Loader_DLL.xex 0x830B1C40: get u32@0x2f08 */
ts4_word ts4_get_u32_off2f08_830B1C40(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12040));
}

/* Loader_DLL.xex 0x830B1C80: get u32@0x2f0c */
ts4_word ts4_get_u32_off2f0c_830B1C80(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12044));
}

/* Loader_DLL.xex 0x830B1CC0: get u32@0x2f10 */
ts4_word ts4_get_u32_off2f10_830B1CC0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12048));
}

/* Loader_DLL.xex 0x830B1CC8: set u32@0x2f1c */
void ts4_set_u32_off2f1c_830B1CC8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12060) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830B1CD0: get u32@0x2f1c */
ts4_word ts4_get_u32_off2f1c_830B1CD0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12060));
}

/* Loader_DLL.xex 0x830B20C8: get u32@0x292c */
ts4_word ts4_get_u32_off292c_830B20C8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10540)) & 0xf);
}

/* Loader_DLL.xex 0x830B20D8: get u32@0x292c */
ts4_word ts4_get_u32_off292c_830B20D8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10540)) >> 4) & 0xf);
}

/* Loader_DLL.xex 0x830B20E8: get u32@0x292c */
ts4_word ts4_get_u32_off292c_830B20E8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10540)) >> 8) & 0xf);
}

/* Loader_DLL.xex 0x830B20F8: get u32@0x292c */
ts4_word ts4_get_u32_off292c_830B20F8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10540)) >> 12) & 0xf);
}

/* Loader_DLL.xex 0x830B2108: get u16@0x292c */
ts4_word ts4_get_u16_off292c_830B2108(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)(a0) + 10540)) & 0xf);
}

/* Loader_DLL.xex 0x830B2118: get u32@0x292c */
ts4_word ts4_get_u32_off292c_830B2118(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10540)) >> 20) & 0xf);
}

/* Loader_DLL.xex 0x830B2128: get u8@0x292c */
ts4_word ts4_get_u8_off292c_830B2128(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)(a0) + 10540)) & 0xf);
}

/* Loader_DLL.xex 0x830B2138: get u32@0x292c */
ts4_word ts4_get_u32_off292c_830B2138(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10540))) >> 28);
}

/* Loader_DLL.xex 0x830B2148: get u32@0x2930 */
ts4_word ts4_get_u32_off2930_830B2148(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10544)) & 0xf);
}

/* Loader_DLL.xex 0x830B2158: get u32@0x2930 */
ts4_word ts4_get_u32_off2930_830B2158(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10544)) >> 4) & 0xf);
}

/* Loader_DLL.xex 0x830B2168: get u32@0x2930 */
ts4_word ts4_get_u32_off2930_830B2168(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10544)) >> 8) & 0xf);
}

/* Loader_DLL.xex 0x830B2178: get u32@0x2930 */
ts4_word ts4_get_u32_off2930_830B2178(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10544)) >> 12) & 0xf);
}

/* Loader_DLL.xex 0x830B2188: get u16@0x2930 */
ts4_word ts4_get_u16_off2930_830B2188(ts4_word a0)
{
    return ((*(unsigned short *)((char *)(ts4_word)(a0) + 10544)) & 0xf);
}

/* Loader_DLL.xex 0x830B2198: get u32@0x2930 */
ts4_word ts4_get_u32_off2930_830B2198(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10544)) >> 20) & 0xf);
}

/* Loader_DLL.xex 0x830B21A8: get u8@0x2930 */
ts4_word ts4_get_u8_off2930_830B21A8(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)(a0) + 10544)) & 0xf);
}

/* Loader_DLL.xex 0x830B21B8: get u32@0x2930 */
ts4_word ts4_get_u32_off2930_830B21B8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10544))) >> 28);
}

/* Loader_DLL.xex 0x830B2208: get u32@0x294c */
ts4_word ts4_get_u32_off294c_830B2208(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10572)) & 0x1);
}

/* Loader_DLL.xex 0x830B2218: fn  */
ts4_word ts4_fn_830B2218(ts4_word a0, ts4_word a1)
{
    return (((a0) >> 3) ^ a1);
}

/* Loader_DLL.xex 0x830B23C0: get u32@0x2fac */
ts4_word ts4_get_u32_off2fac_830B23C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12204));
}

/* Loader_DLL.xex 0x830B2458: get u32@0x2fb0 */
ts4_word ts4_get_u32_off2fb0_830B2458(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12208));
}

/* Loader_DLL.xex 0x830B24F0: get u32@0x2fb4 */
ts4_word ts4_get_u32_off2fb4_830B24F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12212));
}

/* Loader_DLL.xex 0x830B2588: get u32@0x2fb8 */
ts4_word ts4_get_u32_off2fb8_830B2588(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12216));
}

/* Loader_DLL.xex 0x830B2628: get u32@0x2978 */
ts4_word ts4_get_u32_off2978_830B2628(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10616)) & 0x3);
}

/* Loader_DLL.xex 0x830B2660: get u32@0x29c0 */
ts4_word ts4_get_u32_off29c0_830B2660(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10688)) & 0x1);
}

/* Loader_DLL.xex 0x830B2690: get u32@0x2948 */
ts4_word ts4_get_u32_off2948_830B2690(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10568)) >> 21) & 0x1);
}

/* Loader_DLL.xex 0x830B26C0: get u32@0x28d8 */
ts4_word ts4_get_u32_off28d8_830B26C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10456));
}

/* Loader_DLL.xex 0x830B26E8: get u32@0x293c */
ts4_word ts4_get_u32_off293c_830B26E8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10556)) >> 4) & 0x1);
}

/* Loader_DLL.xex 0x830B2718: get u8@0x293c */
ts4_word ts4_get_u8_off293c_830B2718(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10556));
}

/* Loader_DLL.xex 0x830B2748: get u32@0x29cc */
ts4_word ts4_get_u32_off29cc_830B2748(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10700));
}

/* Loader_DLL.xex 0x830B2778: get u32@0x29c4 */
ts4_word ts4_get_u32_off29c4_830B2778(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10692));
}

/* Loader_DLL.xex 0x830B27A0: get u32@0x29d0 */
ts4_word ts4_get_u32_off29d0_830B27A0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10704));
}

/* Loader_DLL.xex 0x830B27D0: get u32@0x29c8 */
ts4_word ts4_get_u32_off29c8_830B27D0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10696));
}

/* Loader_DLL.xex 0x830B27F8: get u32@0x2efc */
ts4_word ts4_get_u32_off2efc_830B27F8(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 12028)) >> 20) & 0x7);
}

/* Loader_DLL.xex 0x830B2860: get u32@0x2efc */
ts4_word ts4_get_u32_off2efc_830B2860(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 12028)) >> 17) & 0x7);
}

/* Loader_DLL.xex 0x830B2890: get u32@0x2940 */
ts4_word ts4_get_u32_off2940_830B2890(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10560)) >> 3) & 0x1);
}

/* Loader_DLL.xex 0x830B28C0: get u32@0x2940 */
ts4_word ts4_get_u32_off2940_830B28C0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10560)) >> 2) & 0x1);
}

/* Loader_DLL.xex 0x830B28F0: get u32@0x2940 */
ts4_word ts4_get_u32_off2940_830B28F0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 10560)) >> 5) & 0x1);
}

/* Loader_DLL.xex 0x830B2918: get u8@0x2942 */
ts4_word ts4_get_u8_off2942_830B2918(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 10562));
}

/* Loader_DLL.xex 0x830B2920: set u32@0x35f0 */
void ts4_set_u32_off35f0_830B2920(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 13808) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830B2928: get u32@0x35f0 */
ts4_word ts4_get_u32_off35f0_830B2928(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 13808));
}

/* Loader_DLL.xex 0x830B2930: get u32@0x2efc, u32@0x2efc */
void ts4_get_u32_off2efc_830B2930(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12028) = (ts4_word)((((a1 << 23) | (a1 >> 9)) & 0x3f800000) | ((*(ts4_word *)((char *)(ts4_word)(a0) + 12028)) & 0xc07fffff));
    return;
}

/* Loader_DLL.xex 0x830B2940: get u32@0x2efc */
ts4_word ts4_get_u32_off2efc_830B2940(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 12028)) >> 23) & 0x7f);
}

/* Loader_DLL.xex 0x830B2E00: get u8@0x2f44 */
ts4_word ts4_get_u8_off2f44_830B2E00(ts4_word a0, ts4_word a1)
{
    return (*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12100));
}

/* Loader_DLL.xex 0x830B2FD0: get u8@0x2f5e */
ts4_word ts4_get_u8_off2f5e_830B2FD0(ts4_word a0, ts4_word a1)
{
    return (*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12126));
}

/* Loader_DLL.xex 0x830B3050: get u8@0x2f78 */
ts4_word ts4_get_u8_off2f78_830B3050(ts4_word a0, ts4_word a1)
{
    return (*(unsigned char *)((char *)(ts4_word)((a0 + a1)) + 12152));
}

/* Loader_DLL.xex 0x830B37C8: tailcall fn_830B37D0 */
ts4_word ts4_tailcall_fn_830B37D0_830B37C8(ts4_word a0)
{
    return fn_830B37D0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830B45C0: tailcall fn_830D2EC0 */
ts4_word ts4_tailcall_fn_830D2EC0_830B45C0(ts4_word a0, ts4_word a1)
{
    return fn_830D2EC0((ts4_word)a1, (ts4_word)(a0 + 15216), (ts4_word)1);
}

/* Loader_DLL.xex 0x830B46A8: tailcall fn_830D2FA8 */
ts4_word ts4_tailcall_fn_830D2FA8_830B46A8(ts4_word a0, ts4_word a1)
{
    return fn_830D2FA8((ts4_word)a1, (ts4_word)(a0 + 15216), (ts4_word)1);
}

/* Loader_DLL.xex 0x830B4948: fn  */
ts4_word ts4_fn_830B4948(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830B4960: fn  */
ts4_word ts4_fn_830B4960(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830B4A90: fn  */
void ts4_fn_830B4A90(void)
{
    return;
}

/* Loader_DLL.xex 0x830B4A98: fn  */
void ts4_fn_830B4A98(void)
{
    return;
}

/* Loader_DLL.xex 0x830B6040: fn  */
ts4_word ts4_fn_830B6040(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830B60A0: fn  */
ts4_word ts4_fn_830B60A0(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830B60B8: fn  */
void ts4_fn_830B60B8(void)
{
    return;
}

/* Loader_DLL.xex 0x830B60C0: fn  */
ts4_word ts4_fn_830B60C0(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830B61B0: fn  */
void ts4_fn_830B61B0(void)
{
    return;
}

/* Loader_DLL.xex 0x830B61B8: fn  */
void ts4_fn_830B61B8(void)
{
    return;
}

/* Loader_DLL.xex 0x830B8388: fn  */
ts4_word ts4_fn_830B8388(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830B83A0: get u32@0x1b8 */
ts4_word ts4_get_u32_off1b8_830B83A0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(a0) + 440))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x830B8C50: fn  */
void ts4_fn_830B8C50(void)
{
    return;
}

/* Loader_DLL.xex 0x830B8C58: tailcall fn_830B86E0 */
ts4_word ts4_tailcall_fn_830B86E0_830B8C58(ts4_word a0)
{
    return fn_830B86E0((ts4_word)a0, (ts4_word)0);
}

/* Loader_DLL.xex 0x830B9328: fn  */
void ts4_fn_830B9328(void)
{
    return;
}

/* Loader_DLL.xex 0x830B9460: set u32@0x35f0 */
void ts4_set_u32_off35f0_830B9460(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 13808) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830B9490: set u32@0x4174 */
void ts4_set_u32_off4174_830B9490(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16756) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830B9498: set u32@0x4170 */
void ts4_set_u32_off4170_830B9498(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16752) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830B94F8: tailcall fn_830B88A8 */
ts4_word ts4_tailcall_fn_830B88A8_830B94F8(ts4_word a0, ts4_word a1)
{
    return fn_830B88A8((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830B9500: get u32@0x417c */
ts4_word ts4_get_u32_off417c_830B9500(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16764));
}

/* Loader_DLL.xex 0x830B9508: get u32@0x4184 */
ts4_word ts4_get_u32_off4184_830B9508(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16772));
}

/* Loader_DLL.xex 0x830B9510: fn  */
ts4_word ts4_fn_830B9510(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830B9528: fn  */
void ts4_fn_830B9528(void)
{
    return;
}

/* Loader_DLL.xex 0x830B9530: call_seq fn_830ACE48 */
ts4_word ts4_call_seq_fn_830ACE48_830B9530(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    fn_830ACE48((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    return 0;
}

/* Loader_DLL.xex 0x830B9570: call_seq u32@0x30, u32@0x20, fn_830AEE68 */
ts4_word ts4_call_seq_u32_off30_830B9570(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    fn_830AEE68((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) & 0xfffff000), (ts4_word)(t1 & 0xfffff000));
    return 0;
}

/* Loader_DLL.xex 0x830B9870: fn  */
ts4_word ts4_fn_830B9870(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830B98B8: fn  */
void ts4_fn_830B98B8(void)
{
    return;
}

/* Loader_DLL.xex 0x830B98C0: fn  */
ts4_word ts4_fn_830B98C0(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830B9928: fn  */
void ts4_fn_830B9928(void)
{
    return;
}

/* Loader_DLL.xex 0x830B9930: fn  */
void ts4_fn_830B9930(void)
{
    return;
}

/* Loader_DLL.xex 0x830B99A8: set u32@0xc */
void ts4_set_u32_offc_830B99A8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830B99B0: fn  */
ts4_word ts4_fn_830B99B0(ts4_word a0, ts4_word a1)
{
    return ((a1 & 0x3) | a0);
}

/* Loader_DLL.xex 0x830B99C0: fn  */
void ts4_fn_830B99C0(void)
{
    return;
}

/* Loader_DLL.xex 0x830B99D8: get u32@0x2a9c */
ts4_word ts4_get_u32_off2a9c_830B99D8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10908)) + -2);
}

/* Loader_DLL.xex 0x830B9A78: fn  */
void ts4_fn_830B9A78(void)
{
    return;
}

/* Loader_DLL.xex 0x830B9BC8: set u32@0x14, u32@0x8, u32@0x4, u32@0xc, u32@0x10, u32@0x0 */
ts4_word ts4_set_u32_off14_830B9BC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return fn_830B9C30((ts4_word)a0);
}

/* Loader_DLL.xex 0x830B9E78: set u32@0x4, u32@0x8, u32@0xc */
ts4_word ts4_set_u32_off4_830B9E78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(a1 | a3);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(3221225472);
    return (a0 + 16);
}

/* Loader_DLL.xex 0x830B9F10: get u32@0x30, u32@0x34, u32@0x3b24, u32@0x3b20, u32@0x3b18, u32@0x3b1c */
void ts4_get_u32_off30_830B9F10(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 15140);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 15136);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 15128);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 15132);
    *(ts4_word *)((char *)(ts4_word)(a0) + 13616) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 13620) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 13624) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 13628) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 13632) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 13636) = (ts4_word)t6;
    return;
}

/* Loader_DLL.xex 0x830B9F48: get u32@0x3534, u32@0x3530, u32@0x3538, u32@0x353c, u32@0x3540, u32@0x3544 */
void ts4_get_u32_off3534_830B9F48(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 13620);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 13616);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 13624);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 13628);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 13632);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 13636);
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 15140) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 15136) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 15128) = (ts4_word)t5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 15132) = (ts4_word)t6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(t1 + -160);
    return;
}

/* Loader_DLL.xex 0x830BA728: tailcall fn_830BA770 */
ts4_word ts4_tailcall_fn_830BA770_830BA728(ts4_word a0)
{
    return fn_830BA770((ts4_word)a0);
}

/* Loader_DLL.xex 0x830BB258: get u32@0x2a9c */
ts4_word ts4_get_u32_off2a9c_830BB258(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10908));
}

/* Loader_DLL.xex 0x830BB260: tailcall fn_830BB150 */
ts4_word ts4_tailcall_fn_830BB150_830BB260(ts4_word a0)
{
    return fn_830BB150((ts4_word)a0);
}

/* Loader_DLL.xex 0x830BBB18: call_seq u32@0x2a9c, u32@0x2ab0, fn_830BB150 */
ts4_word ts4_call_seq_u32_off2a9c_830BBB18(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 10908);
    *(ts4_word *)((char *)(ts4_word)(a0) + 10928) = (ts4_word)t1;
    fn_830BB150((ts4_word)a0);
    return t1;
}

/* Loader_DLL.xex 0x830BBCF8: get u32@0x8, fn_830BBC00 */
ts4_word ts4_get_u32_off8_830BBCF8(ts4_word a0)
{
    return fn_830BBC00((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
}

/* Loader_DLL.xex 0x830BC2E8: fn  */
ts4_word ts4_fn_830BC2E8(ts4_word a0)
{
    return (a0 & 0xfffffffe);
}

/* Loader_DLL.xex 0x830BC2F0: fn  */
ts4_word ts4_fn_830BC2F0(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830BC320: fn  */
ts4_word ts4_fn_830BC320(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830BC338: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_830BC338(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a0;
    return;
}

/* Loader_DLL.xex 0x830BC348: fn  */
ts4_word ts4_fn_830BC348(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830BC388: fn  */
void ts4_fn_830BC388(void)
{
    return;
}

/* Loader_DLL.xex 0x830BC390: fn  */
ts4_word ts4_fn_830BC390(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830BC3D8: fn  */
void ts4_fn_830BC3D8(void)
{
    return;
}

/* Loader_DLL.xex 0x830BC3E0: fn  */
void ts4_fn_830BC3E0(void)
{
    return;
}

/* Loader_DLL.xex 0x830BC468: fn  */
ts4_word ts4_fn_830BC468(ts4_word a0)
{
    return ((a0 + 127) & 0xffffff80);
}

/* Loader_DLL.xex 0x830BC4F8: fn  */
void ts4_fn_830BC4F8(void)
{
    return;
}

/* Loader_DLL.xex 0x830BC500: fn  */
void ts4_fn_830BC500(void)
{
    return;
}

/* Loader_DLL.xex 0x830BC508: fn  */
void ts4_fn_830BC508(void)
{
    return;
}

/* Loader_DLL.xex 0x830BC510: fn  */
void ts4_fn_830BC510(void)
{
    return;
}

/* Loader_DLL.xex 0x830BC518: get u32@0x78 */
ts4_word ts4_get_u32_off78_830BC518(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 120));
}

/* Loader_DLL.xex 0x830BC588: fn  */
ts4_word ts4_fn_830BC588(ts4_word a0, ts4_word a1)
{
    return ((a1 & 0x3) | (a0 & 0xfffffffc));
}

/* Loader_DLL.xex 0x830BC9A0: fn  */
ts4_word ts4_fn_830BC9A0(ts4_word a0)
{
    return (a0 + 1090519040);
}

/* Loader_DLL.xex 0x830BCD70: if_get u32@0x68, KeUnlockL2 */
ts4_word ts4_if_get_u32_off68_830BCD70(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    if ((int)t1 == 0) {
        return a0;
    }
    return KeUnlockL2((ts4_word)0);
}

/* Loader_DLL.xex 0x830BF4F0: fn  */
ts4_word ts4_fn_830BF4F0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830C0390: fn  */
void ts4_fn_830C0390(void)
{
    return;
}

/* Loader_DLL.xex 0x830C0398: fn  */
void ts4_fn_830C0398(void)
{
    return;
}

/* Loader_DLL.xex 0x830C03A0: fn  */
ts4_word ts4_fn_830C03A0(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830C03B8: fn  */
ts4_word ts4_fn_830C03B8(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830C0608: set u32@0x0, u16@0x4 */
void ts4_set_u32_off0_830C0608(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)3;
    *(unsigned short *)((char *)(ts4_word)(a0) + 4) = (unsigned short)0;
    return;
}

/* Loader_DLL.xex 0x830C0620: fn  */
void ts4_fn_830C0620(void)
{
    return;
}

/* Loader_DLL.xex 0x830C0628: set u32@0x0, u32@0x0 */
void ts4_set_u32_off0_830C0628(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C0728: fn  */
void ts4_fn_830C0728(void)
{
    return;
}

/* Loader_DLL.xex 0x830C0730: set u32@0x30 */
void ts4_set_u32_off30_830C0730(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830C0830: fn  */
ts4_word ts4_fn_830C0830(ts4_word a0)
{
    return (a0 & 0xffffff80);
}

/* Loader_DLL.xex 0x830C0838: fn  */
ts4_word ts4_fn_830C0838(ts4_word a0)
{
    return ((a0 + 127) & 0xffffff80);
}

/* Loader_DLL.xex 0x830C0850: fn  */
ts4_word ts4_fn_830C0850(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830C0868: get u32@0x8, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off8_830C0868(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    return (((((((((t1 << 30) | (t1 >> 2)) & 0x8000000) | (t2 & 0xf7ffffff)) << 6) | (((((t1 << 30) | (t1 >> 2)) & 0x8000000) | (t2 & 0xf7ffffff)) >> 26)) & 0x3) | ((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) & 0xfffffffc)) & 0x3f);
}

/* Loader_DLL.xex 0x830C0888: get u32@0x4, u32@0x8, u32@0x0, u8@0x7, u32@0x8, u32@0x0 */
void ts4_get_u32_off4_830C0888(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 7) = (unsigned char)((a1 & 0x3c) | (t1 & 0xffffffc3));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((((a1 << 28) | (a1 >> 4)) & 0x20000000) | (t2 & 0xdfffffff));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((((a1 << 26) | (a1 >> 6)) & 0x4000000) | (t3 & 0xfbffffff));
    return;
}

/* Loader_DLL.xex 0x830C0918: fn  */
void ts4_fn_830C0918(void)
{
    return;
}

/* Loader_DLL.xex 0x830C0920: fn  */
void ts4_fn_830C0920(void)
{
    return;
}

/* Loader_DLL.xex 0x830C0928: fn  */
ts4_word ts4_fn_830C0928(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830C09B0: fn  */
void ts4_fn_830C09B0(void)
{
    return;
}

/* Loader_DLL.xex 0x830C09B8: fn  */
void ts4_fn_830C09B8(void)
{
    return;
}

/* Loader_DLL.xex 0x830C09C0: fn  */
void ts4_fn_830C09C0(void)
{
    return;
}

/* Loader_DLL.xex 0x830C09C8: fn  */
void ts4_fn_830C09C8(void)
{
    return;
}

/* Loader_DLL.xex 0x830C09D0: fn  */
void ts4_fn_830C09D0(void)
{
    return;
}

/* Loader_DLL.xex 0x830C09D8: fn  */
void ts4_fn_830C09D8(void)
{
    return;
}

/* Loader_DLL.xex 0x830C09E0: fn  */
void ts4_fn_830C09E0(void)
{
    return;
}

/* Loader_DLL.xex 0x830C09E8: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C09E8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) & 0x1);
}

/* Loader_DLL.xex 0x830C09F8: get u32@0x8, u32@0x4 */
ts4_word ts4_get_u32_off8_830C09F8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return (t1 + (*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Loader_DLL.xex 0x830C0A08: if_get u32@0xc */
ts4_word ts4_if_get_u32_offc_830C0A08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        return (t1 + a0);
    }
    return 0;
}

/* Loader_DLL.xex 0x830C0A20: fn  */
ts4_word ts4_fn_830C0A20(ts4_word a0, ts4_word a1)
{
    return (((a1 << 3) + a0) + 20);
}

/* Loader_DLL.xex 0x830C0A58: fn  */
ts4_word ts4_fn_830C0A58(ts4_word a0)
{
    return (a0 + 40);
}

/* Loader_DLL.xex 0x830C0A60: get u32@0x30 */
ts4_word ts4_get_u32_off30_830C0A60(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 48));
}

/* Loader_DLL.xex 0x830C0A68: get u32@0x2c */
ts4_word ts4_get_u32_off2c_830C0A68(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 44));
}

/* Loader_DLL.xex 0x830C0A70: fn  */
ts4_word ts4_fn_830C0A70(ts4_word a0)
{
    return (a0 + 872);
}

/* Loader_DLL.xex 0x830C0AB0: get u32@0x370 */
ts4_word ts4_get_u32_off370_830C0AB0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 880));
}

/* Loader_DLL.xex 0x830C0AB8: get u32@0x36c */
ts4_word ts4_get_u32_off36c_830C0AB8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 876));
}

/* Loader_DLL.xex 0x830C0AC0: get u32@0x368 */
ts4_word ts4_get_u32_off368_830C0AC0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 872)) >> 5) & 0x1);
}

/* Loader_DLL.xex 0x830C0AD0: fn  */
ts4_word ts4_fn_830C0AD0(ts4_word a0, ts4_word a1)
{
    return ((((int)a1 * 416) + a0) + 68);
}

/* Loader_DLL.xex 0x830C0AE0: get u32@0x18 */
ts4_word ts4_get_u32_off18_830C0AE0(ts4_word a0)
{
    return ((((*(ts4_word *)((char *)(ts4_word)(a0) + 24)) + 9) << 2) + a0);
}

/* Loader_DLL.xex 0x830C0B10: fn  */
void ts4_fn_830C0B10(void)
{
    return;
}

/* Loader_DLL.xex 0x830C0B18: fn  */
void ts4_fn_830C0B18(void)
{
    return;
}

/* Loader_DLL.xex 0x830C0B20: fn  */
void ts4_fn_830C0B20(void)
{
    return;
}

/* Loader_DLL.xex 0x830C0B28: if_tailcall fn_833E3AD0 */
ts4_word ts4_if_tailcall_fn_833E3AD0_830C0B28(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 == (ts4_word)a1) {
        return a0;
    }
    return fn_833E3AD0((ts4_word)a0, (ts4_word)a1, (ts4_word)12);
}

/* Loader_DLL.xex 0x830C1000: get u32@0x36a8, fn_8340D830 */
ts4_word ts4_get_u32_off36a8_830C1000(ts4_word a0)
{
    return fn_8340D830((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 13992)), (ts4_word)(2977955840));
}

/* Loader_DLL.xex 0x830C1010: fn  */
void ts4_fn_830C1010(void)
{
    return;
}

/* Loader_DLL.xex 0x830C11F8: fn  */
void ts4_fn_830C11F8(void)
{
    return;
}

/* Loader_DLL.xex 0x830C1200: fn  */
void ts4_fn_830C1200(void)
{
    return;
}

/* Loader_DLL.xex 0x830C1320: fn  */
void ts4_fn_830C1320(void)
{
    return;
}

/* Loader_DLL.xex 0x830C1590: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_830C1590(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8340C4F8((ts4_word)a2, (ts4_word)(((a1 + 120) << 4) + a0), (ts4_word)(a3 << 4));
}

/* Loader_DLL.xex 0x830C15B0: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_830C15B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8340C4F8((ts4_word)a2, (ts4_word)(((a1 + 376) << 4) + a0), (ts4_word)(a3 << 4));
}

/* Loader_DLL.xex 0x830C1900: get u32@0x368 */
ts4_word ts4_get_u32_off368_830C1900(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 872)) >> 6) & 0x1);
}

/* Loader_DLL.xex 0x830C19A0: get u32@0x0, u32@0x4, u64@0x0, u64@0x8, u64@0x10, u64@0x18 */
ts4_word ts4_get_u32_off0_830C19A0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 0) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 8) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 16) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 24) = (ts4_u64)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 32) = (ts4_u64)0;
    return fn_8340C4F8((ts4_word)(a0 + 40), (ts4_word)t1, (ts4_word)t2);
}

/* Loader_DLL.xex 0x830C19D0: set u64@0x0, u64@0x8, u64@0x10, u64@0x18, u64@0x20, u32@0x0 */
void ts4_set_u64_off0_830C19D0(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 0) = (ts4_u64)0;
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 8) = (ts4_u64)0;
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 16) = (ts4_u64)0;
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 24) = (ts4_u64)0;
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 32) = (ts4_u64)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)7;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(4294901760);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830C1D38: call_seq u32@0x0, u32@0x4, fn_833E3A30, fn_8340C4F8 */
ts4_word ts4_call_seq_u32_off0_830C1D38(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)872);
    t4 = fn_8340C4F8((ts4_word)(a0 + 872), (ts4_word)t1, (ts4_word)t2);
    return t4;
}

/* Loader_DLL.xex 0x830C2238: get u32@0x2ed8, fn_830C1080 */
ts4_word ts4_get_u32_off2ed8_830C2238(ts4_word a0)
{
    return fn_830C1080((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 11992)));
}

/* Loader_DLL.xex 0x830C2598: fn  */
void ts4_fn_830C2598(void)
{
    return;
}

/* Loader_DLL.xex 0x830C2918: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_830C2918(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C2920: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_830C2920(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C2928: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_830C2928(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C2930: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_830C2930(ts4_word a0)
{
    return fn_8340C4F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C2938: tailcall fn_8340C4F8 */
ts4_word ts4_tailcall_fn_8340C4F8_830C2938(ts4_word a0, ts4_word a1)
{
    return fn_8340C4F8((ts4_word)a1, (ts4_word)a0);
}

/* Loader_DLL.xex 0x830C2948: set u32@0x0 */
void ts4_set_u32_off0_830C2948(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C2A88: get u8@0x0, u8@0x0 */
ts4_word ts4_get_u8_off0_830C2A88(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    return (t1 - (*(unsigned char *)((char *)(ts4_word)(a1) + 0)));
}

/* Loader_DLL.xex 0x830C2AD0: get u32@0x0, fn_830C37E8 */
ts4_word ts4_get_u32_off0_830C2AD0(ts4_word a0)
{
    return fn_830C37E8((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C2AE8: get u32@0x0, fn_830C37E8 */
ts4_word ts4_get_u32_off0_830C2AE8(ts4_word a0)
{
    return fn_830C37E8((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C2B58: get u32@0xc */
ts4_word ts4_get_u32_offc_830C2B58(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x830C2B60: get u32@0x10 */
ts4_word ts4_get_u32_off10_830C2B60(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x830C2BF0: get u32@0x4 */
ts4_word ts4_get_u32_off4_830C2BF0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830C2BF8: get u32@0x8 */
ts4_word ts4_get_u32_off8_830C2BF8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x830C2C00: set u32@0x4 */
void ts4_set_u32_off4_830C2C00(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830C2C20: tailcall fn_830C2B68 */
ts4_word ts4_tailcall_fn_830C2B68_830C2C20(ts4_word a0, ts4_word a1)
{
    return fn_830C2B68((ts4_word)a0, (ts4_word)0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C2D60: get u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x0, u32@0x4 */
void ts4_get_u32_off4_830C2D60(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)t3;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)t4;
    return;
}

/* Loader_DLL.xex 0x830C2D88: get u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x4, u32@0x8 */
void ts4_get_u32_off0_830C2D88(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t3;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t4;
    return;
}

/* Loader_DLL.xex 0x830C2DB0: call_seq fn_830C2B00, fn_830C2B00 */
ts4_word ts4_call_seq_fn_830C2B00_830C2DB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    fn_830C2B00((ts4_word)a0, (ts4_word)a3, (ts4_word)a4);
    fn_830C2B00((ts4_word)(a0 + 20), (ts4_word)a1, (ts4_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x830C2E08: get u32@0x20, u32@0xc */
ts4_word ts4_get_u32_off20_830C2E08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    return (t1 + (*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
}

/* Loader_DLL.xex 0x830C2E18: set u32@0x2558, u32@0x255c */
void ts4_set_u32_off2558_830C2E18(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 9560) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 9564) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x830C2EB8: set u32@0x255c */
void ts4_set_u32_off255c_830C2EB8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 9564) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x830C2EC8: get u32@0x255c */
ts4_word ts4_get_u32_off255c_830C2EC8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 9564));
}

/* Loader_DLL.xex 0x830C3520: tailcall fn_830C3528 */
ts4_word ts4_tailcall_fn_830C3528_830C3520(ts4_word a0)
{
    return fn_830C3528((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C37D8: get u32@0x0, u32@0x4db8 */
ts4_word ts4_get_u32_off0_830C37D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 19896));
}

/* Loader_DLL.xex 0x830C46D8: set u32@0x58, u32@0x5c */
void ts4_set_u32_off58_830C46D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x830C4C70: call_seq fn_830C60B8, fn_830C4CA8 */
ts4_word ts4_call_seq_fn_830C60B8_830C4C70(ts4_word a0)
{
    ts4_word t2;

    fn_830C60B8((ts4_word)a0);
    t2 = fn_830C4CA8((ts4_word)a0);
    return t2;
}

/* Loader_DLL.xex 0x830C4D08: get u32@0x64 */
ts4_word ts4_get_u32_off64_830C4D08(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 100));
}

/* Loader_DLL.xex 0x830C4D10: call_seq fn_830C60B8, u32@0x70 */
ts4_word ts4_call_seq_fn_830C60B8_830C4D10(ts4_word a0)
{
    fn_830C60B8((ts4_word)a0);
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 112)) + -1);
}

/* Loader_DLL.xex 0x830C4D48: get u32@0x70 */
ts4_word ts4_get_u32_off70_830C4D48(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 112)) + -1);
}

/* Loader_DLL.xex 0x830C4D58: if_get u32@0x50, u32@0x6c */
ts4_word ts4_if_get_u32_off50_830C4D58(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t1 < 0) {
        return 0;
    }
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 108)) + (a1 << 3));
}

/* Loader_DLL.xex 0x830C56E8: set u32@0x8, u32@0x0, u32@0x4, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off8_830C56E8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830C6048: if_get u32@0x70, u32@0x6c */
ts4_word ts4_if_get_u32_off70_830C6048(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    if ((ts4_word)t1 == 0) {
        return 0;
    }
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 108)) + (t1 << 3)) + -8);
}

/* Loader_DLL.xex 0x830C6BE0: call_seq fn_830C3528, u32@0x26bc */
ts4_word ts4_call_seq_fn_830C3528_830C6BE0(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_830C3528((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 9916) = (ts4_word)1;
    return t1;
}

/* Loader_DLL.xex 0x830C6C60: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C6C60(ts4_word a0)
{
    return ((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16);
}

/* Loader_DLL.xex 0x830C6C78: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C6C78(ts4_word a0)
{
    return ((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16);
}

/* Loader_DLL.xex 0x830C6C90: get u32@0x0 */
ts4_word ts4_get_u32_off0_830C6C90(ts4_word a0)
{
    return ((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 368);
}

/* Loader_DLL.xex 0x830C6D40: get u32@0x0, fn_830C3358 */
ts4_word ts4_get_u32_off0_830C6D40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830C3358((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 368), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830C6DD8: get u32@0x0, fn_830C3438 */
ts4_word ts4_get_u32_off0_830C6DD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830C3438((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 368), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830C6E50: get u32@0x0, fn_830C4600 */
ts4_word ts4_get_u32_off0_830C6E50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830C4600((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830C6E68: get u32@0x0, fn_830C46E8 */
ts4_word ts4_get_u32_off0_830C6E68(ts4_word a0, ts4_word a1)
{
    return fn_830C46E8((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C6E80: get u32@0x0, fn_830C4748 */
ts4_word ts4_get_u32_off0_830C6E80(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830C4748((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830C6E98: get u32@0x0, fn_830C47B0 */
ts4_word ts4_get_u32_off0_830C6E98(ts4_word a0)
{
    return fn_830C47B0((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C6EB0: get u32@0x0, fn_830C48B0 */
ts4_word ts4_get_u32_off0_830C6EB0(ts4_word a0, ts4_word a1)
{
    return fn_830C48B0((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C6EC8: get u32@0x0, fn_830C4998 */
ts4_word ts4_get_u32_off0_830C6EC8(ts4_word a0)
{
    return fn_830C4998((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C6EE0: get u32@0x0, fn_830C4B18 */
ts4_word ts4_get_u32_off0_830C6EE0(ts4_word a0)
{
    return fn_830C4B18((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C6EF8: get u32@0x0, fn_830C4C08 */
ts4_word ts4_get_u32_off0_830C6EF8(ts4_word a0, ts4_word a1)
{
    return fn_830C4C08((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C6F58: get u32@0x0, fn_830C4CA8 */
ts4_word ts4_get_u32_off0_830C6F58(ts4_word a0)
{
    return fn_830C4CA8((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C6F88: call_seq u32@0x0, fn_830C60B8, u32@0x80 */
ts4_word ts4_call_seq_u32_off0_830C6F88(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    fn_830C60B8((ts4_word)((((int)t1 * 9936) + a0) + 16));
    return ((*(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 128)) + -1);
}

/* Loader_DLL.xex 0x830C6FE0: if_get u32@0x0, u32@0x60, u32@0x7c */
ts4_word ts4_if_get_u32_off0_830C6FE0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 96);
    if ((int)t2 < 0) {
        return 0;
    }
    return ((*(ts4_word *)((char *)(ts4_word)((((int)t1 * 9936) + a0)) + 124)) + (a1 << 3));
}

/* Loader_DLL.xex 0x830C7010: get u32@0x0, fn_830C4D80 */
ts4_word ts4_get_u32_off0_830C7010(ts4_word a0)
{
    return fn_830C4D80((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C7028: get u32@0x0, fn_830C4E40 */
ts4_word ts4_get_u32_off0_830C7028(ts4_word a0)
{
    return fn_830C4E40((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C7250: get u32@0x4db4 */
ts4_word ts4_get_u32_off4db4_830C7250(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 19892)) >> 1) & 0x1);
}

/* Loader_DLL.xex 0x830C7260: get u32@0x4db4 */
ts4_word ts4_get_u32_off4db4_830C7260(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 19892)) >> 2) & 0x1);
}

/* Loader_DLL.xex 0x830C7270: get u32@0x4db4 */
ts4_word ts4_get_u32_off4db4_830C7270(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 19892)) >> 3) & 0x1);
}

/* Loader_DLL.xex 0x830C72A0: get u32@0x4db4 */
ts4_word ts4_get_u32_off4db4_830C72A0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 19892)) >> 6) & 0x1);
}

/* Loader_DLL.xex 0x830C72C0: tailcall fn_830C72C8 */
ts4_word ts4_tailcall_fn_830C72C8_830C72C0(ts4_word a0)
{
    return fn_830C72C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C7368: fn  */
void ts4_fn_830C7368(void)
{
    return;
}

/* Loader_DLL.xex 0x830C7398: tailcall fn_830C7830 */
ts4_word ts4_tailcall_fn_830C7830_830C7398(ts4_word a0)
{
    return fn_830C7830((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C73A0: tailcall fn_830C7958 */
ts4_word ts4_tailcall_fn_830C7958_830C73A0(ts4_word a0)
{
    return fn_830C7958((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C73C8: get u32@0x0, fn_830C37E8 */
ts4_word ts4_get_u32_off0_830C73C8(ts4_word a0)
{
    return fn_830C37E8((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16));
}

/* Loader_DLL.xex 0x830C7428: tailcall fn_830C6CC8 */
ts4_word ts4_tailcall_fn_830C6CC8_830C7428(ts4_word a0, ts4_word a1)
{
    return fn_830C6CC8((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830C7430: get u32@0x0, fn_830C3358 */
ts4_word ts4_get_u32_off0_830C7430(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830C3358((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 368), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830C74C8: get u32@0x0, fn_830C3438 */
ts4_word ts4_get_u32_off0_830C74C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830C3438((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 368), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830C74E0: tailcall fn_830C7A00 */
ts4_word ts4_tailcall_fn_830C7A00_830C74E0(ts4_word a0)
{
    return fn_830C7A00((ts4_word)a0);
}

/* Loader_DLL.xex 0x830C74E8: get u32@0x0, fn_830C4600 */
ts4_word ts4_get_u32_off0_830C74E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830C4600((ts4_word)((((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)) * 9936) + a0) + 16), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830C7500: tailcall fn_830C6DF0 */
ts4_word ts4_tailcall_fn_830C6DF0_830C7500(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830C6DF0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}
