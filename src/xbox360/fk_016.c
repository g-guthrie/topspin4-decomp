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

extern char lbl_880F9574[];
extern char lbl_880F9820[];
ts4_word fn_88278620();
ts4_word fn_885FA208();
ts4_word fn_886042C8();
ts4_word fn_886049F0();
ts4_word fn_8864DFF0();
ts4_word fn_8899F760();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();

/* Swing_DLL.xex 0x885F5600: get u32@0x48 */
ts4_word ts4_get_u32_off48_885F5600(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 72)) + 70);
}

/* Swing_DLL.xex 0x885F5658: get u32@0x48 */
ts4_word ts4_get_u32_off48_885F5658(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 72)) + 74);
}

/* Swing_DLL.xex 0x885F5900: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F5900(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 16);
}

/* Swing_DLL.xex 0x885F5940: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F5940(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 16);
}

/* Swing_DLL.xex 0x885F5B68: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F5B68(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 16);
}

/* Swing_DLL.xex 0x885F5D08: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F5D08(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 16);
}

/* Swing_DLL.xex 0x885F5F40: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F5F40(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 16);
}

/* Swing_DLL.xex 0x885F5FF0: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F5FF0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 16);
}

/* Swing_DLL.xex 0x885F6038: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F6038(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 16);
}

/* Swing_DLL.xex 0x885F61D0: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F61D0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 42);
}

/* Swing_DLL.xex 0x885F6350: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F6350(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) + 20);
}

/* Swing_DLL.xex 0x885F92A8: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F92A8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F92B0: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F92B0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F92B8: get u16@0x12 */
ts4_word ts4_get_u16_off12_885F92B8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 18));
}

/* Swing_DLL.xex 0x885F92C0: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F92C0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F92C8: get u16@0xe */
ts4_word ts4_get_u16_offe_885F92C8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 14));
}

/* Swing_DLL.xex 0x885F92D0: get u16@0xc */
ts4_word ts4_get_u16_offc_885F92D0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F92D8: set u32@0x18 */
ts4_word ts4_set_u32_off18_885F92D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F92E8: set u32@0x14 */
ts4_word ts4_set_u32_off14_885F92E8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9318: set u16@0xc */
ts4_word ts4_set_u16_offc_885F9318(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)1;
    return 1;
}

/* Swing_DLL.xex 0x885F9350: set u32@0x10 */
ts4_word ts4_set_u32_off10_885F9350(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9370: get u16@0xc */
ts4_word ts4_get_u16_offc_885F9370(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9378: set u32@0x18 */
ts4_word ts4_set_u32_off18_885F9378(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9388: set u32@0x14 */
ts4_word ts4_set_u32_off14_885F9388(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F93A8: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F93A8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F93B0: get u32@0xc */
ts4_word ts4_get_u32_offc_885F93B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F93B8: set u64@0x20 */
ts4_word ts4_set_u64_off20_885F93B8(ts4_word a0, ts4_u64 a1)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 32) = (ts4_u64)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F93C8: set u32@0x14 */
ts4_word ts4_set_u32_off14_885F93C8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F93D8: set u32@0x10 */
ts4_word ts4_set_u32_off10_885F93D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9408: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F9408(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F9410: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F9410(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9418: get u32@0xc */
ts4_word ts4_get_u32_offc_885F9418(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9420: set u64@0x30 */
ts4_word ts4_set_u64_off30_885F9420(ts4_word a0, ts4_u64 a1)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 48) = (ts4_u64)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9430: set u32@0x20 */
ts4_word ts4_set_u32_off20_885F9430(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9440: set u32@0x1c */
ts4_word ts4_set_u32_off1c_885F9440(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9450: set u32@0x18 */
ts4_word ts4_set_u32_off18_885F9450(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9460: set u32@0x14 */
ts4_word ts4_set_u32_off14_885F9460(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9490: set u32@0xc */
ts4_word ts4_set_u32_offc_885F9490(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F94A0: get u32@0x48 */
ts4_word ts4_get_u32_off48_885F94A0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 72));
}

/* Swing_DLL.xex 0x885F94B8: get u16@0x3e */
ts4_word ts4_get_u16_off3e_885F94B8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 62));
}

/* Swing_DLL.xex 0x885F94C0: get u16@0x3c */
ts4_word ts4_get_u16_off3c_885F94C0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 60));
}

/* Swing_DLL.xex 0x885F94C8: get u16@0x3a */
ts4_word ts4_get_u16_off3a_885F94C8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 58));
}

/* Swing_DLL.xex 0x885F94D0: get u16@0x38 */
ts4_word ts4_get_u16_off38_885F94D0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 56));
}

/* Swing_DLL.xex 0x885F94D8: get u16@0x36 */
ts4_word ts4_get_u16_off36_885F94D8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 54));
}

/* Swing_DLL.xex 0x885F94E0: get u16@0x34 */
ts4_word ts4_get_u16_off34_885F94E0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 52));
}

/* Swing_DLL.xex 0x885F94E8: get u16@0x32 */
ts4_word ts4_get_u16_off32_885F94E8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 50));
}

/* Swing_DLL.xex 0x885F9528: get u32@0x20 */
ts4_word ts4_get_u32_off20_885F9528(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Swing_DLL.xex 0x885F9530: get u32@0x1c */
ts4_word ts4_get_u32_off1c_885F9530(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x885F9538: get u32@0x18 */
ts4_word ts4_get_u32_off18_885F9538(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x885F9540: get u32@0x14 */
ts4_word ts4_get_u32_off14_885F9540(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F9548: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F9548(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9550: get u16@0xe */
ts4_word ts4_get_u16_offe_885F9550(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 14));
}

/* Swing_DLL.xex 0x885F9558: get u16@0xc */
ts4_word ts4_get_u16_offc_885F9558(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9560: get u16@0xc */
ts4_word ts4_get_u16_offc_885F9560(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9580: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F9580(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9588: get u16@0xe */
ts4_word ts4_get_u16_offe_885F9588(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 14));
}

/* Swing_DLL.xex 0x885F9590: get u16@0xc */
ts4_word ts4_get_u16_offc_885F9590(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9598: set u64@0x18 */
ts4_word ts4_set_u64_off18_885F9598(ts4_word a0, ts4_u64 a1)
{
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 24) = (ts4_u64)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F95B8: set u32@0x10 */
ts4_word ts4_set_u32_off10_885F95B8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F95E8: get u16@0xc */
ts4_word ts4_get_u16_offc_885F95E8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F95F0: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F95F0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F95F8: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F95F8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9600: get u32@0xc */
ts4_word ts4_get_u32_offc_885F9600(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9608: set u32@0x10 */
ts4_word ts4_set_u32_off10_885F9608(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9668: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F9668(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F9670: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F9670(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F9678: get u16@0x12 */
ts4_word ts4_get_u16_off12_885F9678(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 18));
}

/* Swing_DLL.xex 0x885F9680: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F9680(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9688: get u16@0xe */
ts4_word ts4_get_u16_offe_885F9688(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 14));
}

/* Swing_DLL.xex 0x885F9690: get u16@0xc */
ts4_word ts4_get_u16_offc_885F9690(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9698: set u32@0xc */
ts4_word ts4_set_u32_offc_885F9698(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F96A8: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F96A8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F96B0: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F96B0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F96B8: get u16@0x12 */
ts4_word ts4_get_u16_off12_885F96B8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 18));
}

/* Swing_DLL.xex 0x885F96C0: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F96C0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F96C8: get u16@0xe */
ts4_word ts4_get_u16_offe_885F96C8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 14));
}

/* Swing_DLL.xex 0x885F96D0: get u16@0xc */
ts4_word ts4_get_u16_offc_885F96D0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F96D8: set u32@0xc */
ts4_word ts4_set_u32_offc_885F96D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F96E8: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F96E8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F96F0: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F96F0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F96F8: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F96F8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9700: get u32@0xc */
ts4_word ts4_get_u32_offc_885F9700(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9708: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F9708(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9710: set u32@0xc */
ts4_word ts4_set_u32_offc_885F9710(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9720: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F9720(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9728: set u32@0x20 */
ts4_word ts4_set_u32_off20_885F9728(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F97D0: get u32@0x20 */
ts4_word ts4_get_u32_off20_885F97D0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Swing_DLL.xex 0x885F97D8: get u16@0x1c */
ts4_word ts4_get_u16_off1c_885F97D8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x885F97E0: get u16@0x1a */
ts4_word ts4_get_u16_off1a_885F97E0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 26));
}

/* Swing_DLL.xex 0x885F97E8: get u16@0x18 */
ts4_word ts4_get_u16_off18_885F97E8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x885F97F0: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F97F0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F97F8: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F97F8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F9800: get u16@0x12 */
ts4_word ts4_get_u16_off12_885F9800(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 18));
}

/* Swing_DLL.xex 0x885F9808: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F9808(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9810: get u16@0xe */
ts4_word ts4_get_u16_offe_885F9810(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 14));
}

/* Swing_DLL.xex 0x885F9818: get u16@0xc */
ts4_word ts4_get_u16_offc_885F9818(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9820: set u32@0x28 */
ts4_word ts4_set_u32_off28_885F9820(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9840: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F9840(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9848: get u32@0xc */
ts4_word ts4_get_u32_offc_885F9848(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9850: set u32@0x10 */
ts4_word ts4_set_u32_off10_885F9850(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9860: set u16@0xc */
ts4_word ts4_set_u16_offc_885F9860(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)1;
    return 1;
}

/* Swing_DLL.xex 0x885F9878: get u16@0xc */
ts4_word ts4_get_u16_offc_885F9878(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9880: set u32@0x10 */
ts4_word ts4_set_u32_off10_885F9880(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9890: set u16@0xc */
ts4_word ts4_set_u16_offc_885F9890(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)1;
    return 1;
}

/* Swing_DLL.xex 0x885F98A8: get u16@0x40 */
ts4_word ts4_get_u16_off40_885F98A8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 64));
}

/* Swing_DLL.xex 0x885F98B0: get u32@0x3c */
ts4_word ts4_get_u32_off3c_885F98B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Swing_DLL.xex 0x885F98B8: get u32@0x38 */
ts4_word ts4_get_u32_off38_885F98B8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 56));
}

/* Swing_DLL.xex 0x885F98C0: get u32@0x34 */
ts4_word ts4_get_u32_off34_885F98C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
}

/* Swing_DLL.xex 0x885F98E0: get u32@0x24 */
ts4_word ts4_get_u32_off24_885F98E0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Swing_DLL.xex 0x885F98E8: get u32@0x20 */
ts4_word ts4_get_u32_off20_885F98E8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Swing_DLL.xex 0x885F98F0: get u16@0x1c */
ts4_word ts4_get_u16_off1c_885F98F0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x885F98F8: get u16@0x1a */
ts4_word ts4_get_u16_off1a_885F98F8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 26));
}

/* Swing_DLL.xex 0x885F9900: get u16@0x18 */
ts4_word ts4_get_u16_off18_885F9900(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x885F9908: get u16@0x16 */
ts4_word ts4_get_u16_off16_885F9908(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x885F9910: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F9910(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F9918: get u16@0x12 */
ts4_word ts4_get_u16_off12_885F9918(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 18));
}

/* Swing_DLL.xex 0x885F9920: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F9920(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9928: get u16@0xe */
ts4_word ts4_get_u16_offe_885F9928(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 14));
}

/* Swing_DLL.xex 0x885F9930: get u16@0xc */
ts4_word ts4_get_u16_offc_885F9930(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F9938: set u16@0x14 */
ts4_word ts4_set_u16_off14_885F9938(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 20) = (unsigned short)0;
    return 1;
}

/* Swing_DLL.xex 0x885F9950: set u32@0x10 */
ts4_word ts4_set_u32_off10_885F9950(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F9970: get u32@0x18 */
ts4_word ts4_get_u32_off18_885F9970(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x885F9978: get u16@0x14 */
ts4_word ts4_get_u16_off14_885F9978(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x885F9980: get u16@0x12 */
ts4_word ts4_get_u16_off12_885F9980(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 18));
}

/* Swing_DLL.xex 0x885F9988: get u16@0x10 */
ts4_word ts4_get_u16_off10_885F9988(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x885F9990: get u16@0xe */
ts4_word ts4_get_u16_offe_885F9990(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 14));
}

/* Swing_DLL.xex 0x885F9998: get u16@0xc */
ts4_word ts4_get_u16_offc_885F9998(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x885F99A0: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F99A0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 16)) << 3) + 12);
}

/* Swing_DLL.xex 0x885F9A90: fn  */
ts4_word ts4_fn_885F9A90(void)
{
    return 20;
}

/* Swing_DLL.xex 0x885F9C50: fn  */
ts4_word ts4_fn_885F9C50(void)
{
    return 18;
}

/* Swing_DLL.xex 0x885F9CD0: fn  */
ts4_word ts4_fn_885F9CD0(void)
{
    return 10;
}

/* Swing_DLL.xex 0x885FA048: fn  */
ts4_word ts4_fn_885FA048(void)
{
    return 10;
}

/* Swing_DLL.xex 0x885FA2C0: fn  */
ts4_word ts4_fn_885FA2C0(void)
{
    return 10;
}

/* Swing_DLL.xex 0x885FA2D8: addr lbl_880F9820, u32@0x4, u32@0x0, u16@0x8, u8@0xa, u8@0xb */
void ts4_addr_lbl_880F9820_885FA2D8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F9820;
    *(unsigned short *)((char *)(ts4_word)(a0) + 8) = (unsigned short)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 10) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 11) = (unsigned char)22;
    *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)0;
    return;
}

/* Swing_DLL.xex 0x885FA308: get u32@0x18 */
ts4_word ts4_get_u32_off18_885FA308(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 24)) + 26);
}

/* Swing_DLL.xex 0x885FA358: get u32@0x14 */
ts4_word ts4_get_u32_off14_885FA358(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + 22);
}

/* Swing_DLL.xex 0x885FA408: fn  */
ts4_word ts4_fn_885FA408(void)
{
    return 16;
}

/* Swing_DLL.xex 0x885FA4F0: fn  */
ts4_word ts4_fn_885FA4F0(void)
{
    return 10;
}

/* Swing_DLL.xex 0x885FA598: fn  */
ts4_word ts4_fn_885FA598(void)
{
    return 18;
}

/* Swing_DLL.xex 0x885FA648: fn  */
ts4_word ts4_fn_885FA648(void)
{
    return 20;
}

/* Swing_DLL.xex 0x885FA728: fn  */
ts4_word ts4_fn_885FA728(void)
{
    return 18;
}

/* Swing_DLL.xex 0x885FA7E0: fn  */
ts4_word ts4_fn_885FA7E0(void)
{
    return 14;
}

/* Swing_DLL.xex 0x885FA878: fn  */
ts4_word ts4_fn_885FA878(void)
{
    return 14;
}

/* Swing_DLL.xex 0x885FA970: fn  */
ts4_word ts4_fn_885FA970(void)
{
    return 20;
}

/* Swing_DLL.xex 0x885FA9F8: fn  */
ts4_word ts4_fn_885FA9F8(void)
{
    return 12;
}

/* Swing_DLL.xex 0x885FAAE8: fn  */
ts4_word ts4_fn_885FAAE8(void)
{
    return 20;
}

/* Swing_DLL.xex 0x885FAB70: fn  */
ts4_word ts4_fn_885FAB70(void)
{
    return 12;
}

/* Swing_DLL.xex 0x885FAC80: fn  */
ts4_word ts4_fn_885FAC80(void)
{
    return 8;
}

/* Swing_DLL.xex 0x885FAD68: fn  */
ts4_word ts4_fn_885FAD68(void)
{
    return 12;
}

/* Swing_DLL.xex 0x885FB250: fn  */
ts4_word ts4_fn_885FB250(void)
{
    return 14;
}

/* Swing_DLL.xex 0x885FB2E8: fn  */
ts4_word ts4_fn_885FB2E8(void)
{
    return 14;
}

/* Swing_DLL.xex 0x885FB360: fn  */
ts4_word ts4_fn_885FB360(void)
{
    return 10;
}

/* Swing_DLL.xex 0x885FB3F0: fn  */
ts4_word ts4_fn_885FB3F0(void)
{
    return 14;
}

/* Swing_DLL.xex 0x885FB5A0: fn  */
ts4_word ts4_fn_885FB5A0(void)
{
    return 16;
}

/* Swing_DLL.xex 0x885FB7A8: fn  */
ts4_word ts4_fn_885FB7A8(void)
{
    return 12;
}

/* Swing_DLL.xex 0x885FB818: fn  */
ts4_word ts4_fn_885FB818(void)
{
    return 10;
}

/* Swing_DLL.xex 0x885FDF30: if_call_seq fn_8864DFF0, fn_8899F760, fn_885FA208 */
ts4_word ts4_if_call_seq_fn_8864DFF0_885FDF30(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    fn_8864DFF0();
    t2 = fn_8899F760((ts4_word)88);
    if ((ts4_word)t2 != 0) {
        t3 = fn_885FA208((ts4_word)t2, (ts4_word)a0, (ts4_word)a1);
        p4 = (ts4_word)t3;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x88600290: if_call_seq u32@0x0, fn_886042C8, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_88600290(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t2;

    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    t2 = fn_886042C8((ts4_word)a1, (ts4_word)(a0 + 12), (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 < 0) {
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) - t2);
    return 1;
}

/* Swing_DLL.xex 0x886005B8: if_call_seq u32@0x18, fn_88278620, u32@0x14, u32@0x18, memcpy */
ts4_word ts4_if_call_seq_u32_off18_886005B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a2;
        t1 = fn_88278620((ts4_word)a2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t1;
        memcpy((ts4_word)t1, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    }
    return 1;
}

/* Swing_DLL.xex 0x88600618: if_call_seq u32@0x10, fn_88278620, u32@0xc, u32@0x10, memcpy */
ts4_word ts4_if_call_seq_u32_off10_88600618(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
        t1 = fn_88278620((ts4_word)a2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t1;
        memcpy((ts4_word)t1, (ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    }
    return 1;
}

/* Swing_DLL.xex 0x886009C0: if_call_seq u32@0x0, fn_886042C8, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_886009C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t2;

    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    t2 = fn_886042C8((ts4_word)a1, (ts4_word)(a0 + 12), (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 < 0) {
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) - t2);
    return 1;
}

/* Swing_DLL.xex 0x88600AF8: set u32@0x10 */
ts4_word ts4_set_u32_off10_88600AF8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88600B08: set u16@0xc */
ts4_word ts4_set_u16_offc_88600B08(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)1;
    return 1;
}

/* Swing_DLL.xex 0x88600B70: fn  */
ts4_word ts4_fn_88600B70(void)
{
    return 14;
}

/* Swing_DLL.xex 0x88600D70: fn  */
ts4_word ts4_fn_88600D70(ts4_word a0)
{
    return (a0 + 4);
}

/* Swing_DLL.xex 0x88600F98: call_seq lbl_880F9574, u32@0x0, fn_886049F0 */
ts4_word ts4_call_seq_lbl_880F9574_88600F98(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F9574;
    fn_886049F0((ts4_word)(a0 + 4), (ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x88600FD8: get u16@0x1c */
ts4_word ts4_get_u16_off1c_88600FD8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 28));
}

/* Swing_DLL.xex 0x88600FE0: get u16@0x1a */
ts4_word ts4_get_u16_off1a_88600FE0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 26));
}

/* Swing_DLL.xex 0x88600FE8: get u16@0x18 */
ts4_word ts4_get_u16_off18_88600FE8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x88600FF0: get u16@0x16 */
ts4_word ts4_get_u16_off16_88600FF0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 22));
}

/* Swing_DLL.xex 0x88600FF8: get u16@0x14 */
ts4_word ts4_get_u16_off14_88600FF8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x88601000: get u16@0x12 */
ts4_word ts4_get_u16_off12_88601000(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 18));
}

/* Swing_DLL.xex 0x88601008: get u16@0x10 */
ts4_word ts4_get_u16_off10_88601008(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x88601010: get u16@0xe */
ts4_word ts4_get_u16_offe_88601010(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 14));
}

/* Swing_DLL.xex 0x88601018: get u16@0xc */
ts4_word ts4_get_u16_offc_88601018(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x88601020: set u32@0xc */
ts4_word ts4_set_u32_offc_88601020(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88601030: get u16@0x18 */
ts4_word ts4_get_u16_off18_88601030(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x88601038: get u32@0x14 */
ts4_word ts4_get_u32_off14_88601038(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x88601040: get u32@0x10 */
ts4_word ts4_get_u32_off10_88601040(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x88601048: get u32@0xc */
ts4_word ts4_get_u32_offc_88601048(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x88601050: set u32@0x14 */
ts4_word ts4_set_u32_off14_88601050(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88601060: set u32@0x10 */
ts4_word ts4_set_u32_off10_88601060(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88601080: set u32@0x18 */
ts4_word ts4_set_u32_off18_88601080(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88601090: set u32@0x14 */
ts4_word ts4_set_u32_off14_88601090(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x886010D0: get u16@0xc */
ts4_word ts4_get_u16_offc_886010D0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x886010D8: set u32@0x1c */
ts4_word ts4_set_u32_off1c_886010D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x886010E8: set u32@0x18 */
ts4_word ts4_set_u32_off18_886010E8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88601158: get u16@0x14 */
ts4_word ts4_get_u16_off14_88601158(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x88601160: get u32@0x10 */
ts4_word ts4_get_u32_off10_88601160(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x88601168: get u32@0xc */
ts4_word ts4_get_u32_offc_88601168(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x88601190: set u32@0x28 */
ts4_word ts4_set_u32_off28_88601190(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x886011B0: set u32@0x20 */
ts4_word ts4_set_u32_off20_886011B0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return 1;
}

/* Swing_DLL.xex 0x88601260: get u16@0x10 */
ts4_word ts4_get_u16_off10_88601260(ts4_word a0)
{
    return (*(unsigned short *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x88601268: get u32@0xc */
ts4_word ts4_get_u32_offc_88601268(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Swing_DLL.xex 0x886013F8: fn  */
ts4_word ts4_fn_886013F8(void)
{
    return 12;
}

/* Swing_DLL.xex 0x88601570: fn  */
ts4_word ts4_fn_88601570(void)
{
    return 18;
}

/* Swing_DLL.xex 0x886016D0: fn  */
ts4_word ts4_fn_886016D0(void)
{
    return 10;
}

/* Swing_DLL.xex 0x886017F0: fn  */
ts4_word ts4_fn_886017F0(void)
{
    return 28;
}

/* Swing_DLL.xex 0x886018B8: fn  */
ts4_word ts4_fn_886018B8(void)
{
    return 18;
}

/* Swing_DLL.xex 0x88601B50: fn  */
ts4_word ts4_fn_88601B50(void)
{
    return 14;
}
