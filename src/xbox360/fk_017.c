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

extern char lbl_880D19F0[];
extern char lbl_880F6E5C[];
extern char lbl_880F75FC[];
extern char lbl_880F78DC[];
extern char lbl_880F799C[];
extern char lbl_880F79D0[];
extern char lbl_880F7A28[];
extern char lbl_880F7AF8[];
extern char lbl_880F7D74[];
extern char lbl_880F8C74[];
extern char lbl_88C475A8[];
extern char lbl_88C6D110[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B38[];
ts4_word fn_8856A3A0();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word fn_8857B6D8();
ts4_word fn_886074E8();
ts4_word fn_88607740();
ts4_word fn_88608590();
ts4_word fn_886090A0();
ts4_word fn_886095B8();
ts4_word fn_8860A168();
ts4_word fn_88883CD0();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_memset();

/* Swing_DLL.xex 0x88601BA8: fn  */
ts4_word ts4_fn_88601BA8(void)
{
    return 8;
}

/* Swing_DLL.xex 0x88602928: get u16@0xc */
ts4_word ts4_get_u16_offc_88602928(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x88602930: set u32@0x44 */
ts4_word ts4_set_u32_off44_88602930(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602940: set u32@0x40 */
ts4_word ts4_set_u32_off40_88602940(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602950: set u32@0x3c */
ts4_word ts4_set_u32_off3c_88602950(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602960: set u32@0x38 */
ts4_word ts4_set_u32_off38_88602960(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602970: set u32@0x34 */
ts4_word ts4_set_u32_off34_88602970(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x886029A0: set u32@0x28 */
ts4_word ts4_set_u32_off28_886029A0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x886029C0: set u32@0x20 */
ts4_word ts4_set_u32_off20_886029C0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x886029D0: set u32@0x1c */
ts4_word ts4_set_u32_off1c_886029D0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x886029E0: set u32@0x18 */
ts4_word ts4_set_u32_off18_886029E0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x886029F0: set u32@0x14 */
ts4_word ts4_set_u32_off14_886029F0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602A00: set u32@0x10 */
ts4_word ts4_set_u32_off10_88602A00(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602A30: get u16@0x1c */
ts4_word ts4_get_u16_off1c_88602A30(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x88602A38: get u16@0x1a */
ts4_word ts4_get_u16_off1a_88602A38(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 26));
}

/* Swing_DLL.xex 0x88602A40: get u16@0x18 */
ts4_word ts4_get_u16_off18_88602A40(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x88602A48: get u16@0x16 */
ts4_word ts4_get_u16_off16_88602A48(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x88602A50: get u16@0x14 */
ts4_word ts4_get_u16_off14_88602A50(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x88602A58: get u16@0x12 */
ts4_word ts4_get_u16_off12_88602A58(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 18));
}

/* Swing_DLL.xex 0x88602A60: get u16@0x10 */
ts4_word ts4_get_u16_off10_88602A60(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x88602A68: get u32@0xc */
ts4_word ts4_get_u32_offc_88602A68(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x88602A80: set u32@0x20 */
ts4_word ts4_set_u32_off20_88602A80(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602B30: get u16@0x10 */
ts4_word ts4_get_u16_off10_88602B30(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x88602B38: get u32@0xc */
ts4_word ts4_get_u32_offc_88602B38(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x88602B40: set u32@0x20 */
ts4_word ts4_set_u32_off20_88602B40(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602B50: set u32@0x1c */
ts4_word ts4_set_u32_off1c_88602B50(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602B80: set u32@0x14 */
ts4_word ts4_set_u32_off14_88602B80(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88602BB0: set u16@0xc */
ts4_word ts4_set_u16_offc_88602BB0(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)1;
    return 1;
}

/* Swing_DLL.xex 0x88602BD8: fn  */
ts4_word ts4_fn_88602BD8(void)
{
    return 8;
}

/* Swing_DLL.xex 0x88602C20: fn  */
ts4_word ts4_fn_88602C20(void)
{
    return 10;
}

/* Swing_DLL.xex 0x88602E00: fn  */
ts4_word ts4_fn_88602E00(void)
{
    return 68;
}

/* Swing_DLL.xex 0x886031C0: fn  */
ts4_word ts4_fn_886031C0(void)
{
    return 14;
}

/* Swing_DLL.xex 0x88603B88: get u32@0xc */
ts4_word ts4_get_u32_offc_88603B88(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x88603BF8: get u32@0xc */
ts4_word ts4_get_u32_offc_88603BF8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x88603C38: if_get u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_88603C38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t1 < 4) {
        return -1;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(t1 + -4);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    return 4;
}

/* Swing_DLL.xex 0x88603CC8: if_get u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_88603CC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((ts4_word)t1 < 4) {
        return -1;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) + -4);
    return 4;
}

/* Swing_DLL.xex 0x88603D48: set u64@0x0 */
ts4_word ts4_set_u64_off0_88603D48(ts4_word a0, ts4_u64 a1)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 0) = (ts4_u64)a1;
    return 8;
}

/* Swing_DLL.xex 0x88603E08: call_seq memcpy */
ts4_word ts4_call_seq_memcpy_88603E08(ts4_word a0, ts4_word a1, ts4_word a2)
{
    memcpy((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return a2;
}

/* Swing_DLL.xex 0x88603E38: fn  */
ts4_word ts4_fn_88603E38(void)
{
    return 8;
}

/* Swing_DLL.xex 0x88603F20: fn  */
ts4_word ts4_fn_88603F20(void)
{
    return 12;
}

/* Swing_DLL.xex 0x88604418: fn  */
ts4_word ts4_fn_88604418(void)
{
    return 16;
}

/* Swing_DLL.xex 0x88605488: fn  */
ts4_word ts4_fn_88605488(ts4_word a0)
{
    return (a0 + 12);
}

/* Swing_DLL.xex 0x88605DC8: fn  */
ts4_word ts4_fn_88605DC8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88605E68: get u32@0x0 */
ts4_word ts4_get_u32_off0_88605E68(ts4_word a0, ts4_word a1)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a1);
}

/* Swing_DLL.xex 0x88605E78: get u32@0x0 */
ts4_word ts4_get_u32_off0_88605E78(ts4_word a0, ts4_word a1)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a1);
}

/* Swing_DLL.xex 0x88605E90: fn  */
ts4_word ts4_fn_88605E90(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88605E98: fn  */
ts4_word ts4_fn_88605E98(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88605EA0: fn  */
ts4_word ts4_fn_88605EA0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88605EA8: fn  */
ts4_word ts4_fn_88605EA8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88605EC0: fn  */
ts4_word ts4_fn_88605EC0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88605EC8: fn  */
ts4_word ts4_fn_88605EC8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88605ED0: call_seq lbl_880F75FC, fn_8856A3A0 */
ts4_word ts4_call_seq_lbl_880F75FC_88605ED0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = fn_8856A3A0((ts4_word)a1, (ts4_word)(ts4_word)lbl_880F75FC);
    return (t1 == 0);
}

/* Swing_DLL.xex 0x88605F18: addr lbl_880F7D74, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
void ts4_addr_lbl_880F7D74_88605F18(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7D74;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88605F58: if_addr lbl_88C475A8, lbl_88C475A8, u32@0x50 */
ts4_word ts4_if_addr_lbl_88C475A8_88605F58(ts4_word a0)
{
    if ((ts4_word)a0 < 21) {
        return (*(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_88C475A8));
    }
    return (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C475A8) + 80));
}

/* Swing_DLL.xex 0x88605F80: fn  */
ts4_word ts4_fn_88605F80(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88606020: set u32@0x0, u64@0x4, u64@0xc, u32@0x14, u8@0x18 */
void ts4_set_u32_off0_88606020(ts4_word a0, ts4_word a1, ts4_u64 a2, ts4_u64 a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 4) = (ts4_u64)a2;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 12) = (ts4_u64)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88606050: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_88606050(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886063A8: set u8@0x208 */
void ts4_set_u8_off208_886063A8(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 520) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x886063B0: set u32@0x0, u32@0x4, u8@0x208 */
void ts4_set_u32_off0_886063B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 520) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x886063C8: fn  */
ts4_word ts4_fn_886063C8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886063E8: set u32@0x0 */
void ts4_set_u32_off0_886063E8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88606400: set u8@0x0 */
void ts4_set_u8_off0_88606400(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88606530: fn  */
ts4_word ts4_fn_88606530(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606538: fn  */
ts4_word ts4_fn_88606538(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606548: get u32@-0xc */
ts4_word ts4_get_u32_0xc_88606548(ts4_word a0, ts4_word a1)
{
    return ((a0 - (*(ts4_word *)((char *)(ts4_word)(a1) + -12))) == 0);
}

/* Swing_DLL.xex 0x88606570: fn  */
ts4_word ts4_fn_88606570(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606578: fn  */
ts4_word ts4_fn_88606578(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886065F0: fn  */
ts4_word ts4_fn_886065F0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606680: get u32@0x4, u32@0x8, u32@0x0, u32@0x50 */
ts4_word ts4_get_u32_off4_88606680(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 80))))((ts4_word)t1, (ts4_word)t2, (ts4_word)a2);
}

/* Swing_DLL.xex 0x886066A0: get u32@0x4, u32@0xc, u32@0x0, u32@0x50 */
ts4_word ts4_get_u32_off4_886066A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 80))))((ts4_word)t1, (ts4_word)t2, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88606760: get u32@0x34 */
ts4_word ts4_get_u32_off34_88606760(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 52)) - a1) == 0);
}

/* Swing_DLL.xex 0x88606930: fn  */
ts4_word ts4_fn_88606930(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606938: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_88606938(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88606958: fn  */
ts4_word ts4_fn_88606958(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606968: fn  */
ts4_word ts4_fn_88606968(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88606AD8: fn  */
ts4_word ts4_fn_88606AD8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606AE0: fn  */
ts4_word ts4_fn_88606AE0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88606AE8: fn  */
ts4_word ts4_fn_88606AE8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88606AF0: get u32@0x0, u32@0x50 */
ts4_word ts4_get_u32_off0_88606AF0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 80))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88606B10: fn  */
ts4_word ts4_fn_88606B10(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606B20: fn  */
ts4_word ts4_fn_88606B20(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606B38: fn  */
ts4_word ts4_fn_88606B38(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606B40: fn  */
ts4_word ts4_fn_88606B40(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606B48: fn  */
ts4_word ts4_fn_88606B48(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606B50: fn  */
ts4_word ts4_fn_88606B50(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606B58: fn  */
ts4_word ts4_fn_88606B58(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606B60: fn  */
ts4_word ts4_fn_88606B60(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606B68: fn  */
ts4_word ts4_fn_88606B68(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606B78: set u8@0x0, u8@0x1, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u8_off0_88606B78(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88606B98: get u32@0x0, u32@0x1c, vcall, u32@0x0, u32@0x4, vcall */
ts4_word ts4_get_u32_off0_88606B98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0, (ts4_word)a3, (ts4_word)a4);
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    return t6;
}

/* Swing_DLL.xex 0x88606BF0: fn  */
ts4_word ts4_fn_88606BF0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606BF8: fn  */
ts4_word ts4_fn_88606BF8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606C00: fn  */
ts4_word ts4_fn_88606C00(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606C08: fn  */
ts4_word ts4_fn_88606C08(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606C10: fn  */
ts4_word ts4_fn_88606C10(void)
{
    return -1;
}

/* Swing_DLL.xex 0x88606C18: fn  */
ts4_word ts4_fn_88606C18(void)
{
    return -1;
}

/* Swing_DLL.xex 0x88606C28: fn  */
ts4_word ts4_fn_88606C28(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606C40: set u32@0x4, u32@0x8, lbl_880F799C, u32@0xc, u32@0x0, u8@0x10 */
void ts4_set_u32_off4_88606C40(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F799C;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88606CB0: fn  */
ts4_word ts4_fn_88606CB0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606CB8: fn  */
ts4_word ts4_fn_88606CB8(void)
{
    return -1;
}

/* Swing_DLL.xex 0x88606DA0: get  */
ts4_word ts4_get_88606DA0(ts4_word a0, ts4_word a1)
{
    return (*(unsigned short *)((char *)(ts4_word)(((a1 + 84) << 1)) + a0));
}

/* Swing_DLL.xex 0x88606DB0: get  */
ts4_word ts4_get_88606DB0(ts4_word a0, ts4_word a1)
{
    return (*(unsigned short *)((char *)(ts4_word)(((a1 + 78) << 1)) + a0));
}

/* Swing_DLL.xex 0x88606E00: get  */
ts4_word ts4_get_88606E00(ts4_word a0, ts4_word a1)
{
    return (*(unsigned short *)((char *)(ts4_word)(((a1 + 33) << 2)) + a0));
}

/* Swing_DLL.xex 0x88606E40: get  */
ts4_word ts4_get_88606E40(ts4_word a0, ts4_word a1)
{
    return (*(unsigned char *)((char *)(ts4_word)(((a1 + 12) << 2)) + a0));
}

/* Swing_DLL.xex 0x88606E50: get  */
ts4_word ts4_get_88606E50(ts4_word a0, ts4_word a1)
{
    return (*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + a0));
}

/* Swing_DLL.xex 0x88606E68: set u16@0x0, u16@0x2 */
void ts4_set_u16_off0_88606E68(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 0) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 2) = (unsigned short)0;
    return;
}

/* Swing_DLL.xex 0x88606EA0: set u8@0x0, u8@0x1, u8@0x2 */
void ts4_set_u8_off0_88606EA0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)63;
    *(unsigned char *)((char *)(ts4_word)(a1) + 1) = (unsigned char)63;
    *(unsigned char *)((char *)(ts4_word)(a1) + 2) = (unsigned char)63;
    return;
}

/* Swing_DLL.xex 0x88606EC0: fn  */
ts4_word ts4_fn_88606EC0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88606EC8: get u32@lbl_88D45B20 */
ts4_word ts4_get_u32_lbl_88D45B20_88606EC8(void)
{
    return (*(ts4_word *)lbl_88D45B20);
}

/* Swing_DLL.xex 0x88606ED8: set u32@0x14, u32@0x10 */
void ts4_set_u32_off14_88606ED8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)2;
    return;
}

/* Swing_DLL.xex 0x88606EE8: set u32@0x14, u32@0x10 */
void ts4_set_u32_off14_88606EE8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x88606F20: if_set u32@0x10, u32@0x20, u32@0x18, u32@0x1c */
void ts4_if_set_u32_off10_88606F20(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    if ((ts4_word)a1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a4;
    return;
}

/* Swing_DLL.xex 0x886077B8: get u32@0x0, fn_88607740 */
ts4_word ts4_get_u32_off0_886077B8(ts4_word a0)
{
    return fn_88607740((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x886079C8: get u32@0x4 */
ts4_word ts4_get_u32_off4_886079C8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Swing_DLL.xex 0x886079D0: fn  */
ts4_word ts4_fn_886079D0(void)
{
    return 1;
}

/* Swing_DLL.xex 0x886079D8: get u32@0x4, u32@0x4, fn_886074E8 */
ts4_word ts4_get_u32_off4_886079D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    return fn_886074E8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x88607A10: addr lbl_880F7A28, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880F7A28_88607A10(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7A28;
    return;
}

/* Swing_DLL.xex 0x88607AC8: get u32@0x18, u32@0x14 */
ts4_word ts4_get_u32_off18_88607AC8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 20))) >> 2);
}

/* Swing_DLL.xex 0x88607AF8: get u32@0x4 */
ts4_word ts4_get_u32_off4_88607AF8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Swing_DLL.xex 0x88607B00: get u32@0x4, u32@0x0, u32@0x28, vcall, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off4_88607B00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4));
    *(ts4_word *)((char *)(ts4_word)(a3) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 8));
    return t4;
}

/* Swing_DLL.xex 0x88608068: set u8@0x0, u32@0x4, u32@0x8 */
void ts4_set_u8_off0_88608068(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((65536) | 18438);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)10937;
    return;
}

/* Swing_DLL.xex 0x886082B8: addr lbl_880F8C74, u32@0x4, u32@0x0, u32@0x8, u32@0x18, u32@0x1c */
void ts4_addr_lbl_880F8C74_886082B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8C74;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886082E0: set u32@0x64 */
void ts4_set_u32_off64_886082E0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x886082E8: if_get u32@0x60, u32@0x64 */
void ts4_if_get_u32_off60_886082E8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    if ((int)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 100) = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x88608320: fn  */
ts4_word ts4_fn_88608320(void)
{
    return 0;
}

/* Swing_DLL.xex 0x886083B0: get u32@lbl_88D45B1C, u32@0x27c, u32@0x0 */
void ts4_get_u32_lbl_88D45B1C_886083B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return;
}

/* Swing_DLL.xex 0x886084B0: get u32@lbl_88D45B1C, u32@0x238 */
ts4_word ts4_get_u32_lbl_88D45B1C_886084B0(void)
{
    return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 568)) != 0);
}

/* Swing_DLL.xex 0x88608838: get u32@lbl_88D45B38 */
ts4_word ts4_get_u32_lbl_88D45B38_88608838(void)
{
    return (*(ts4_word *)lbl_88D45B38);
}

/* Swing_DLL.xex 0x88608BD0: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_88608BD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88608C28: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_88608C28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88608C88: fn  */
ts4_word ts4_fn_88608C88(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88608DB0: set u32@0x0 */
void ts4_set_u32_off0_88608DB0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88608E00: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_88608E00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88608E18: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_88608E18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88608E30: set u32@0x0 */
void ts4_set_u32_off0_88608E30(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88608E40: set u32@0x0 */
void ts4_set_u32_off0_88608E40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88608E90: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_88608E90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88608F70: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_88608F70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88608F88: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_88608F88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88609048: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_88609048(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88609150: call_seq u32@0x0, fn_886090A0 */
ts4_word ts4_call_seq_u32_off0_88609150(ts4_word a0, ts4_word a1)
{
    fn_886090A0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return a0;
}

/* Swing_DLL.xex 0x88609198: set u32@0x0, u8@0x4, u32@0x8, u32@0x20c, u32@0x210, u32@0x214 */
void ts4_set_u32_off0_88609198(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 524) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 528) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 532) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 536) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 544) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 548) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 552) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 556) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 560) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 564) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 568) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88609270: get u32@0x0, u32@0x4, u32@0x0, u32@0x58 */
ts4_word ts4_get_u32_off0_88609270(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    (void)a1;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 88))))((ts4_word)t2, (ts4_word)a0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88609310: get u32@0x0, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_88609310(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 68))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88609328: set u32@0x0 */
void ts4_set_u32_off0_88609328(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88609338: set u32@0x0 */
void ts4_set_u32_off0_88609338(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88609348: set u32@0x0 */
void ts4_set_u32_off0_88609348(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88609398: get u32@0x14 */
ts4_word ts4_get_u32_off14_88609398(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x88609428: fn  */
ts4_word ts4_fn_88609428(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88609430: addr lbl_880F7AF8, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u8@0x10 */
void ts4_addr_lbl_880F7AF8_88609430(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7AF8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88609458: get u32@0xc, u32@0xc */
ts4_word ts4_get_u32_offc_88609458(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return t1;
}

/* Swing_DLL.xex 0x88609880: get fn_886095B8 */
ts4_word ts4_get_fn_886095B8_88609880(ts4_word a0, ts4_word a1)
{
    return fn_886095B8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + a0)));
}

/* Swing_DLL.xex 0x88609890: get u32@0x24, u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off24_88609890(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 56))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x886098A8: get u32@0x24, u32@0x0, u32@0x30 */
ts4_word ts4_get_u32_off24_886098A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 48))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x886098C0: get u32@0x24, u32@0x0, u32@0x2c */
ts4_word ts4_get_u32_off24_886098C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 44))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x886098D8: get u32@0x24, u32@0x0, u32@0x28 */
ts4_word ts4_get_u32_off24_886098D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x886098F0: if_get ts4_memset, u32@0x0, u32@0x34, vcall, lbl_880F6E5C, fn_8856A3A0 */
ts4_word ts4_if_get_ts4_memset_886098F0(ts4_word a0)
{
    ts4_word p9;
    ts4_word loc50[1];
    ts4_word t5;
    ts4_word t8;

    ts4_memset((ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)3);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 52))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t5 = fn_8856A3A0((ts4_word)(ts4_word)lbl_880F6E5C, (ts4_word)(ts4_word)&loc50[0]);
    p9 = (ts4_word)t5;
    if ((int)t5 == 0) {
        t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)1);
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x88609970: set u32@0x20 */
void ts4_set_u32_off20_88609970(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88609AB8: call_seq u32@0x0, ts4_tailcall_fn_88582F30_8857A128, u8@0x50 */
ts4_word ts4_call_seq_u32_off0_88609AB8(ts4_word a0)
{
    ts4_tailcall_fn_88582F30_8857A128((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)-1);
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 80));
}

/* Swing_DLL.xex 0x88609C80: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_88609C80(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8860A4D8: get u32@0x0, u32@0x0, u32@0xc, u32@0x30, vcall, u32@0xc */
ts4_word ts4_get_u32_off0_8860A4D8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 48))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t5;
    return t5;
}

/* Swing_DLL.xex 0x8860A520: set u32@0x4, u32@0x0 */
ts4_word ts4_set_u32_off4_8860A520(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)a0;
    return a2;
}

/* Swing_DLL.xex 0x8860A680: call_seq u32@0x0, u32@0x4, u32@0x4, fn_8860A168, u32@0x4 */
ts4_word ts4_call_seq_u32_off0_8860A680(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_8860A168((ts4_word)t1, (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)));
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)t3;
    return t3;
}

/* Swing_DLL.xex 0x8860A808: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_8860A808(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8860AC08: set u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off0_8860AC08(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x8860AC80: set u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off0_8860AC80(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x8860ACA0: get u32@0x4, lbl_88C6D110, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off4_8860ACA0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)(ts4_word)lbl_88C6D110, (ts4_word)2);
}

/* Swing_DLL.xex 0x8860B498: get u32@0x4, u32@0x2c, u32@0xc */
ts4_word ts4_get_u32_off4_8860B498(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((((*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 44)) + (a1 << 4))) + 12)) & 0x1f) - a2) == 0);
}

/* Swing_DLL.xex 0x8860B598: addr lbl_880F79D0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880F79D0_8860B598(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F79D0;
    return;
}

/* Swing_DLL.xex 0x8860B5B0: get u32@0x0, u32@0x4, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off0_8860B5B0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 68))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2);
}

/* Swing_DLL.xex 0x8860B5D0: get u32@0x0, u32@0x4, u32@0x0, u32@0x40 */
ts4_word ts4_get_u32_off0_8860B5D0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 64))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8860B5F8: get u32@0x0, u32@0x4, u32@0x0, u32@0x0, u32@0x40 */
ts4_word ts4_get_u32_off0_8860B5F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t3) + 64))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2, (ts4_word)t4);
}

/* Swing_DLL.xex 0x8860B620: get u32@0x0, u32@0x4, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off0_8860B620(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2);
}

/* Swing_DLL.xex 0x8860B640: get u32@0x0, u32@0x4, u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off0_8860B640(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2);
}

/* Swing_DLL.xex 0x8860B660: get u32@0x0, u32@0x4, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off0_8860B660(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2);
}

/* Swing_DLL.xex 0x8860B680: get u32@0x0, u32@0x4, u32@0x0, u32@0x8, vcall */
ts4_word ts4_get_u32_off0_8860B680(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)a0, (ts4_word)t1, (ts4_word)a1, (ts4_word)t2);
    return a0;
}

/* Swing_DLL.xex 0x8860B6D0: get u8@0x18 */
ts4_word ts4_get_u8_off18_8860B6D0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x8860B6D8: if_set u8@0x18 */
void ts4_if_set_u8_off18_8860B6D8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)(a1 & 0xff) == 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x8860BE40: call_seq u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14, u32@0x30 */
ts4_word ts4_call_seq_u32_off4_8860BE40(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    t1 = fn_8857B6D8((ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    t2 = fn_8857B6D8((ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    t3 = fn_8857B6D8((ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8860BF38: get u32@0x4c, u32@0x18, u32@0x0 */
void ts4_get_u32_off4c_8860BF38(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 76))) + 24));
    return;
}

/* Swing_DLL.xex 0x8860C208: call_seq u32@0x0, fn_88608590, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_8860C208(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = fn_88608590((ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
    return a0;
}

/* Swing_DLL.xex 0x8860C248: call_seq fn_88608590, u32@0x0 */
ts4_word ts4_call_seq_fn_88608590_8860C248(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_88608590((ts4_word)a1, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return a0;
}

/* Swing_DLL.xex 0x8860C288: call_seq fn_88608590, u32@0x0 */
ts4_word ts4_call_seq_fn_88608590_8860C288(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88608590((ts4_word)0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return a0;
}

/* Swing_DLL.xex 0x8860C2C0: addr lbl_880F78DC, lbl_880D19F0, u32@0x0, u32@0x14 */
void ts4_addr_lbl_880F78DC_8860C2C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F78DC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x8860C350: set u8@0x2c */
void ts4_set_u8_off2c_8860C350(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x8860C398: set u32@0x0, u32@0x4, u8@0x8, u8@0x9 */
void ts4_set_u32_off0_8860C398(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 9) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8860C3B8: set u32@0x0, u8@0x4, u8@0x5 */
void ts4_set_u32_off0_8860C3B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8860C3D0: get u32@lbl_88D45B1C, u32@0x238 */
ts4_word ts4_get_u32_lbl_88D45B1C_8860C3D0(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 568));
}

/* Swing_DLL.xex 0x8860C3E0: tailcall fn_88608590 */
ts4_word ts4_tailcall_fn_88608590_8860C3E0(ts4_word a0)
{
    return fn_88608590((ts4_word)0, (ts4_word)a0);
}

/* Swing_DLL.xex 0x8860C478: get u32@lbl_88D45B38, u32@0x2c, u32@0x2c */
void ts4_get_u32_lbl_88D45B38_8860C478(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45B38;
    *(ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 44)) - a0);
    return;
}

/* Swing_DLL.xex 0x8860C490: get u32@lbl_88D45B38, u32@0x2c, u32@0x2c */
void ts4_get_u32_lbl_88D45B38_8860C490(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45B38;
    *(ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)(a0 + (*(ts4_word *)((char *)(ts4_word)(t1) + 44)));
    return;
}

/* Swing_DLL.xex 0x8860CE38: set u32@0x0, u32@0x8, u32@0xc, ts4_memset */
ts4_word ts4_set_u32_off0_8860CE38(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return ts4_memset((ts4_word)(a0 + 16), (ts4_word)0, (ts4_word)40);
}

/* Swing_DLL.xex 0x8860D118: get u32@0x178, u32@0x0, u32@0x40 */
ts4_word ts4_get_u32_off178_8860D118(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 64))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8860D130: get u32@0x178, u32@0x0, u32@0x3c */
ts4_word ts4_get_u32_off178_8860D130(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 60))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8860D148: get u32@0x178, u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off178_8860D148(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 376);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 56))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8860D160: get u32@0x178, u32@0x34 */
ts4_word ts4_get_u32_off178_8860D160(ts4_word a0, ts4_word a1)
{
    return (((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 376))) + 52)) - a1) == 0);
}

/* Swing_DLL.xex 0x8860D208: if_call_seq fn_88883CD0, u32@0xc */
ts4_word ts4_if_call_seq_fn_88883CD0_8860D208(void)
{
    ts4_word t1;

    t1 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 12));
    }
    return 0;
}

/* Swing_DLL.xex 0x8860D2D8: if_call_seq fn_88883CD0, u32@0x10 */
ts4_word ts4_if_call_seq_fn_88883CD0_8860D2D8(void)
{
    ts4_word t1;

    t1 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 16));
    }
    return 0;
}

/* Swing_DLL.xex 0x8860D320: if_call_seq fn_88883CD0, u32@0x10, u32@0x8 */
ts4_word ts4_if_call_seq_fn_88883CD0_8860D320(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)a0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)a0;
    }
    return t1;
}

/* Swing_DLL.xex 0x8860D448: get u32@0x0, u32@0x24, u32@0x48 */
ts4_word ts4_get_u32_off0_8860D448(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 72))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2);
}
