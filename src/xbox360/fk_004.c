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
extern char lbl_880D5A64[];
extern char lbl_880D6B70[];
extern char lbl_880DC520[];
extern char lbl_880F3350[];
extern char lbl_880F3420[];
extern char lbl_880F3428[];
extern char lbl_880F342C[];
extern char lbl_880F3430[];
extern char lbl_880F3444[];
extern char lbl_880F3454[];
extern char lbl_880F3458[];
extern char lbl_880F34BC[];
extern char lbl_880F3794[];
extern char lbl_880F3798[];
extern char lbl_880F444C[];
extern char lbl_880F4464[];
extern char lbl_880F4468[];
extern char lbl_880F4518[];
extern char lbl_880F4640[];
extern char lbl_880F4650[];
extern char lbl_880F4654[];
extern char lbl_880F4788[];
extern char lbl_880F47C8[];
extern char lbl_880F4804[];
extern char lbl_880F4808[];
extern char lbl_880F482C[];
extern char lbl_880F4BCC[];
extern char lbl_880F4C10[];
extern char lbl_880F4E04[];
extern char lbl_880F4E18[];
extern char lbl_880F4E2C[];
extern char lbl_880F4E40[];
extern char lbl_880F4E54[];
extern char lbl_880F5408[];
extern char lbl_880F54B0[];
extern char lbl_880F54E0[];
extern char lbl_880F55B8[];
extern char lbl_880F5638[];
extern char lbl_880F5688[];
extern char lbl_880F5758[];
extern char lbl_880F57A8[];
extern char lbl_880F57F8[];
extern char lbl_880F5848[];
extern char lbl_880F5860[];
extern char lbl_880F5890[];
extern char lbl_880F58A8[];
extern char lbl_880F58C0[];
extern char lbl_880F5918[];
extern char lbl_880F5930[];
extern char lbl_880F77E0[];
extern char lbl_880F7810[];
extern char lbl_880F78DC[];
extern char lbl_880F7940[];
extern char lbl_880F799C[];
extern char lbl_880F7D28[];
extern char lbl_880F7DEC[];
extern char lbl_880F7EA0[];
extern char lbl_880F7FC0[];
extern char lbl_880F8018[];
extern char lbl_880F8070[];
extern char lbl_880F824C[];
extern char lbl_880F82E0[];
extern char lbl_880F8338[];
extern char lbl_880F85AC[];
extern char lbl_880F8B94[];
extern char lbl_880F8CC0[];
extern char lbl_8814B440[];
extern char lbl_88CACF08[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
extern char lbl_88D45B40[];
ts4_word KeTlsGetValue();
ts4_word fn_8816D1A8();
ts4_word fn_881AC6A0();
ts4_word fn_88255AA0();
ts4_word fn_8825B3A8();
ts4_word fn_8825B918();
ts4_word fn_8825C6C0();
ts4_word fn_8825C8E8();
ts4_word fn_8825D140();
ts4_word fn_8825E5F8();
ts4_word fn_8825EBD0();
ts4_word fn_8825F798();
ts4_word fn_8825FD78();
ts4_word fn_882604C0();
ts4_word fn_882609C8();
ts4_word fn_882619C0();
ts4_word fn_882781B0();
ts4_word fn_882782A8();
ts4_word fn_88278368();
ts4_word fn_8827D280();
ts4_word fn_8827DC68();
ts4_word fn_8841A590();
ts4_word fn_8841FC98();
ts4_word fn_884CE5D0();
ts4_word fn_88562DC0();
ts4_word fn_88569098();
ts4_word ts4_if_get_ts4_memset_886098F0();
ts4_word fn_8860BBD8();
ts4_word fn_8860D250();
ts4_word fn_88613268();
ts4_word fn_88613570();
ts4_word fn_88616160();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_8861B128();
ts4_word fn_8861B4D8();
ts4_word fn_88621250();
ts4_word fn_88622888();
ts4_word ts4_call_seq_fn_8861B128_88622BF0();
ts4_word fn_88622D18();
ts4_word fn_88623C60();
ts4_word fn_88626638();
ts4_word fn_8862A190();
ts4_word fn_88636A70();
ts4_word fn_886391E0();
ts4_word fn_88639B88();
ts4_word fn_88647608();
ts4_word fn_8864F5B0();
ts4_word ts4_call_seq_lbl_880F5878_88652260();
ts4_word ts4_call_seq_fn_88617D88_88658910();
ts4_word fn_88658E40();
ts4_word ts4_call_seq_fn_88617D88_8867BA58();
ts4_word fn_8867C870();
ts4_word ts4_call_seq_fn_88617D88_88681410();
ts4_word ts4_call_seq_fn_88617D88_88681D60();
ts4_word ts4_call_seq_fn_88617D88_88682A28();
ts4_word fn_88690B48();
ts4_word fn_8869BC48();
ts4_word fn_886A04C8();
ts4_word fn_886A9050();
ts4_word fn_886D0EB0();
ts4_word fn_886D7878();
ts4_word fn_886E7EF0();
ts4_word ts4_call_seq_fn_88617D88_886E9490();
ts4_word fn_886E9BC8();
ts4_word ts4_if_call_seq_u32_off0_886F9C80();
ts4_word fn_88745F58();
ts4_word fn_888860A0();
ts4_word fn_8890F1E8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8823FA40: set u32@0x14, u32@0x1c, u32@0x20, u32@0x18, u32@0x24, u32@0x3c */
void ts4_set_u32_off14_8823FA40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 180) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 196) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 236) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 268) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 300) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 308) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 312) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 304) = (ts4_word)((9961472) | 38528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 316) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88240098: if_call_seq lbl_880F3420, u32@0x0, fn_8825B3A8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F3420_88240098(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3420;
    fn_8825B3A8((ts4_word)(a0 + 4));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8825AE60: get u32@0x0, u32@0x14, vcall */
ts4_word ts4_get_u32_off0_8825AE60(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20))))((ts4_word)a0);
    return ((t3 & 0xff) == 0);
}

/* Swing_DLL.xex 0x8825AE98: get u32@lbl_88D45B1C, u32@0x27c, u32@0x0 */
void ts4_get_u32_lbl_88D45B1C_8825AE98(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636));
    return;
}

/* Swing_DLL.xex 0x8825AEB0: get u32@0x4, u32@0x0 */
void ts4_get_u32_off4_8825AEB0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    return;
}

/* Swing_DLL.xex 0x8825B8B8: if_call_seq u32@0x110, lbl_880F3444, u32@0x0, u32@0x110, fn_8825B918, ts4_if_call_seq_u32_off0_886F9C80 */
ts4_word ts4_if_call_seq_u32_off110_8825B8B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 272);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3444;
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)0;
        fn_8825B918((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(ts4_word)lbl_880F3444, (ts4_word)t1);
    }
    ts4_if_call_seq_u32_off0_886F9C80((ts4_word)(a0 + 336));
    t5 = fn_88745F58((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x8825BE08: if_call_seq lbl_880F3350, u32@0x0, ts4_object_finalize, fn_88745F58, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F3350_8825BE08(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3350;
    ts4_object_finalize((ts4_word)(a0 + 300));
    fn_88745F58((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8825C298: if_call_seq lbl_880F3430, u32@0x0, fn_8825FD78, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F3430_8825C298(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3430;
    fn_8825FD78((ts4_word)(a0 + 32));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8825C2F8: call_seq u32@0x10, u32@0x10, fn_8825F798, u8@0xa0, u8@0xa0, u8@0xa1 */
ts4_word ts4_call_seq_u32_off10_8825C2F8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    fn_8825F798((ts4_word)(a0 + 32), (ts4_word)(a1 + 32));
    *(unsigned char *)((char *)(ts4_word)(a0) + 160) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 160));
    *(unsigned char *)((char *)(ts4_word)(a0) + 161) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 161));
    return a0;
}

/* Swing_DLL.xex 0x8825C358: call_seq lbl_880F3430, u32@0x0, u32@0x10, u32@0x10, fn_8825EBD0, u8@0xa0 */
ts4_word ts4_call_seq_lbl_880F3430_8825C358(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3430;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    fn_8825EBD0((ts4_word)(a0 + 32), (ts4_word)(a1 + 32));
    *(unsigned char *)((char *)(ts4_word)(a0) + 160) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 160));
    *(unsigned char *)((char *)(ts4_word)(a0) + 161) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 161));
    return a0;
}

/* Swing_DLL.xex 0x8825C728: if_call_seq lbl_880F342C, u32@0x0, fn_8825C8E8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F342C_8825C728(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F342C;
    fn_8825C8E8((ts4_word)(a0 + 8));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8825C788: if_call_seq lbl_880F3428, u32@0x0, fn_8825C8E8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F3428_8825C788(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3428;
    fn_8825C8E8((ts4_word)(a0 + 12));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8825C7E8: call_seq fn_88255AA0, u32@0x0, u32@0x4, u32@0x8, fn_88255AA0, u32@0xc */
ts4_word ts4_call_seq_fn_88255AA0_8825C7E8(ts4_word a0)
{
    ts4_word loc50[1];

    loc50[0] = (ts4_word)0;
    fn_88255AA0((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_88255AA0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8825D1A8: if_call_seq u32@0x10, u32@0xc, u32@0x4, fn_8825D140, u32@0xc, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off10_8825D1A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t4 = fn_8825D140((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 4)));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 4) = (ts4_word)0;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t7;
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        p10 = (ts4_word)t4;
    }
    return p10;
}

/* Swing_DLL.xex 0x8825DF18: get u32@0x8, u32@0x8, u32@0x8, u32@0x8 */
void ts4_get_u32_off8_8825DF18(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x8825E048: get u32@0x4, u32@0x4, u32@0x8, u32@0x8, u8@0xc, u8@0xc */
void ts4_get_u32_off4_8825E048(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 13));
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(float *)((char *)(ts4_word)(a0) + 24) = (*(float *)((char *)(ts4_word)(a1) + 24));
    *(float *)((char *)(ts4_word)(a0) + 28) = (*(float *)((char *)(ts4_word)(a1) + 28));
    *(float *)((char *)(ts4_word)(a0) + 32) = (*(float *)((char *)(ts4_word)(a1) + 32));
    *(float *)((char *)(ts4_word)(a0) + 36) = (*(float *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64));
    return;
}

/* Swing_DLL.xex 0x8825E668: if_call_seq u32@0x8, u32@0x4, u32@0x4, fn_8825E5F8, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_8825E668(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t4 = fn_8825E5F8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4)));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4) = (ts4_word)0;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t7;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p10 = (ts4_word)t4;
    }
    return p10;
}

/* Swing_DLL.xex 0x8825FFB0: if_call_seq lbl_880F3454, u32@0x0, fn_882604C0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F3454_8825FFB0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3454;
    fn_882604C0((ts4_word)(a0 + 4));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88260580: set u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off0_88260580(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x882605A0: if_call_seq lbl_880F3458, u32@0x0, fn_882609C8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F3458_882605A0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3458;
    fn_882609C8((ts4_word)(a0 + 4));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88260D28: call_seq fn_88255AA0, u32@0x0, fn_88255AA0, u32@0x4, u32@0x0, fn_88613570 */
ts4_word ts4_call_seq_fn_88255AA0_88260D28(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t4;

    loc50[0] = (ts4_word)0;
    fn_88255AA0((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    fn_88255AA0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    t4 = fn_88613570((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)96, (ts4_word)8, (ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t4;
    return a0;
}

/* Swing_DLL.xex 0x88261A30: if_call_seq u32@0x8, u32@0x4, u32@0x4, fn_882619C0, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_88261A30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t4 = fn_882619C0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4)));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4) = (ts4_word)0;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t7;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p10 = (ts4_word)t4;
    }
    return p10;
}

/* Swing_DLL.xex 0x88261C70: get u32@0x8, u32@0x8, u32@0xc, u32@0x10, u32@0x8, u32@0xc */
void ts4_get_u32_off8_88261C70(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t4;
    return;
}

/* Swing_DLL.xex 0x88261DE8: if_call_seq lbl_880F34BC, u32@0x84, u32@0x0, u32@0x80, u32@0x7c, u32@0x78 */
ts4_word ts4_if_call_seq_lbl_880F34BC_88261DE8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F34BC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)0;
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x882622B8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_886E9490 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882622B8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_886E9490((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88262310: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_886E9490 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88262310(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_886E9490((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88262368: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886E7EF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88262368(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)144, (ts4_word)16, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886E7EF0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882623C0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886E7EF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882623C0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)144, (ts4_word)16, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886E7EF0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88262418: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886E9BC8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88262418(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)256, (ts4_word)16, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886E9BC8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88262470: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886E9BC8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88262470(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)256, (ts4_word)16, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886E9BC8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882624C8: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882624C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 4), (ts4_word)16, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88262BB0: if_call_seq lbl_880F3798, lbl_880D6B70, u32@0x0, u32@0x8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F3798_88262BB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3798;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_880D6B70;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88262D90: if_call_seq lbl_880F3794, u32@0x0, fn_886D0EB0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F3794_88262D90(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3794;
    fn_886D0EB0((ts4_word)(a0 + 48));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88263C38: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88263C38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 3), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88263C98: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88263C98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 1)) << 2), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88263D00: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88263D00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 2), (ts4_word)2, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88267070: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88267070(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 5), (ts4_word)16, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88267278: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886D7878 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88267278(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)356, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886D7878((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882672D0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886D7878 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882672D0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)356, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886D7878((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88269580: if_call_seq u32@0x60, ts4_destroy_owned_object, u32@0x48, ts4_destroy_owned_object, u32@0x30, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off60_88269580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p15;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t7 != 0) {
        ts4_destroy_owned_object((ts4_word)t7);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t10 != 0) {
        ts4_destroy_owned_object((ts4_word)t10);
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p15 = (ts4_word)t13;
    if ((ts4_word)t13 != 0) {
        t14 = ts4_destroy_owned_object((ts4_word)t13);
        p15 = (ts4_word)t14;
    }
    return p15;
}

/* Swing_DLL.xex 0x88269E88: if_get u32@0x18, u32@0x48, u32@0x30, u8@0x32b, u8@0x0 */
void ts4_if_get_u32_off18_88269E88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    unsigned char t4;

    (void)a2;
    t4 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 24))) + 72))) + 48))) + 811);
    if ((ts4_word)t4 != 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a3) + 0) = (unsigned char)((((3155623936) | 35317) - a1) == 0);
    return;
}

/* Swing_DLL.xex 0x88269EE8: if_get u32@0x1c, u32@lbl_88D45B1C, u32@0x28, u32@0x27c, u8@0x0 */
void ts4_if_get_u32_off1c_88269EE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)lbl_88D45B1C;
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 40);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 636);
    if ((ts4_word)t3 == (ts4_word)t4) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a3) + 0) = (unsigned char)((t3 - a1) != 0);
    return;
}

/* Swing_DLL.xex 0x88269FB0: if_call_seq lbl_880F444C, u32@0x0, fn_8890F1E8, lbl_880D19F0, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F444C_88269FB0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F444C;
    fn_8890F1E8((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826A410: if_call_seq lbl_880F4468, u32@0x0, fn_8890F1E8, fn_8890F1E8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F4468_8826A410(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4468;
    fn_8890F1E8((ts4_word)(a0 + 92));
    fn_8890F1E8((ts4_word)(a0 + 20));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826A520: if_call_seq lbl_880F4804, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
ts4_word ts4_if_call_seq_lbl_880F4804_8826A520(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4804;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x8826A580: if_get u32@0x18, lbl_880F4464, u32@0x0, u32@0x0, u32@0x0, vcall */
ts4_word ts4_if_get_u32_off18_8826A580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4464;
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826A648: if_call_seq lbl_880F4BCC, u32@0x0, fn_8890F1E8, fn_8890F1E8, fn_8890F1E8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F4BCC_8826A648(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4BCC;
    fn_8890F1E8((ts4_word)(a0 + 148));
    fn_8890F1E8((ts4_word)(a0 + 80));
    fn_8890F1E8((ts4_word)(a0 + 12));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826A7A0: if_call_seq lbl_880F4518, u32@0x8, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F4518_8826A7A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4518;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x8826A8D8: if_call_seq lbl_880F4E18, u32@0x8, u32@0x0, fn_8860BBD8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F4E18_8826A8D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4E18;
    fn_8860BBD8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826A940: if_call_seq lbl_880F4E2C, u32@0x0, fn_8890F1E8, lbl_880D5A64, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F4E2C_8826A940(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4E2C;
    fn_8890F1E8((ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D5A64;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826A9B0: if_call_seq lbl_880F4650, u32@0x0, fn_8890F1E8, fn_8890F1E8, u32@0x4, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F4650_8826A9B0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4650;
    fn_8890F1E8((ts4_word)(a0 + 92));
    fn_8890F1E8((ts4_word)(a0 + 24));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8826AC68: if_get u32@0x8, u32@0x4, u32@0x0, u8@0x0, u8@0x0, u8@0x1 */
void ts4_if_get_u32_off8_8826AC68(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((int)t2 >= (int)t1) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(unsigned char *)((char *)(ts4_word)((((t2 << 2) + t3) + a0)) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 0));
    *(unsigned char *)((char *)(ts4_word)((((t2 << 2) + t3) + a0)) + 1) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 1));
    *(unsigned char *)((char *)(ts4_word)((((t2 << 2) + t3) + a0)) + 2) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 2));
    *(unsigned char *)((char *)(ts4_word)((((t2 << 2) + t3) + a0)) + 3) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 3));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1);
    return;
}

/* Swing_DLL.xex 0x8826B918: set u8@0x0, u32@0x4 */
void ts4_set_u8_off0_8826B918(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8826C140: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886A04C8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826C140(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)280, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886A04C8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826CD50: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8867C870 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826CD50(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)148, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8867C870((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826E550: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826E550(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)((a1 + (a1 << 1)) << 4), (ts4_word)16, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8826E838: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4654, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826E838(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4654;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826E8A0: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4654, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826E8A0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4654;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826E988: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F4788, u32@0x1c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826E988(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4788;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826EA88: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F47C8, u32@0x1c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826EA88(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F47C8;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826EB08: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4808, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826EB08(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4808;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826EB80: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4808, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826EB80(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4808;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826EBF8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F482C, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826EBF8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F482C;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826EC68: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F482C, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826EC68(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F482C;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826ECD8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88690B48 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826ECD8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)216, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88690B48((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826ED30: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88690B48 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826ED30(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)216, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88690B48((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826EE88: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_8867BA58 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826EE88(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)8, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_8867BA58((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826EEE0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_8867BA58 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826EEE0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)64, (ts4_word)8, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_8867BA58((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826F528: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8869BC48 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826F528(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)384, (ts4_word)16, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8869BC48((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826F580: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8869BC48 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826F580(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)384, (ts4_word)16, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8869BC48((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826F5D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886A9050 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826F5D8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1440, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886A9050((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826F630: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886A9050 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826F630(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1440, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886A9050((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826F788: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F4C10, u32@0x1c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826F788(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4C10;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826F808: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F4C10, u32@0x1c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826F808(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4C10;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826F888: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88682A28 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826F888(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88682A28((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826F8E0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88682A28 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826F8E0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88682A28((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826FB38: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88681D60 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826FB38(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)76, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88681D60((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826FB90: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88681D60 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826FB90(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)76, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88681D60((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826FDE8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88681410 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826FDE8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88681410((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826FE40: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88681410 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826FE40(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88681410((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826FE98: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4E04, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826FE98(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4E04;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826FF08: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4E04, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826FF08(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4E04;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826FF78: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4E40, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826FF78(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)16, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4E40;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826FFE8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4E40, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826FFE8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)16, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4E40;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88270058: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4E54, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88270058(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4E54;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882700C8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4E54, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882700C8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4E54;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88270138: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4640, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88270138(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4640;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882701A0: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F4640, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882701A0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4640;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88271478: get u32@0x18, u32@0x18, u8@0x1c, u8@0x1c, u8@0x1d, u8@0x1d */
float ts4_get_u32_off18_88271478(ts4_word a0, ts4_word a1)
{
    float t22;

    *(float *)((char *)(ts4_word)(a0) + 0) = (*(float *)((char *)(ts4_word)(a1) + 0));
    *(float *)((char *)(ts4_word)(a0) + 4) = (*(float *)((char *)(ts4_word)(a1) + 4));
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(a1) + 8));
    *(float *)((char *)(ts4_word)(a0) + 12) = (*(float *)((char *)(ts4_word)(a1) + 12));
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)((char *)(ts4_word)(a1) + 16));
    *(float *)((char *)(ts4_word)(a0) + 20) = (*(float *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 28));
    *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 29));
    *(unsigned char *)((char *)(ts4_word)(a0) + 30) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 30));
    *(unsigned char *)((char *)(ts4_word)(a0) + 31) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 31));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(float *)((char *)(ts4_word)(a0) + 44) = (*(float *)((char *)(ts4_word)(a1) + 44));
    *(float *)((char *)(ts4_word)(a0) + 48) = (*(float *)((char *)(ts4_word)(a1) + 48));
    *(float *)((char *)(ts4_word)(a0) + 52) = (*(float *)((char *)(ts4_word)(a1) + 52));
    *(float *)((char *)(ts4_word)(a0) + 56) = (*(float *)((char *)(ts4_word)(a1) + 56));
    *(float *)((char *)(ts4_word)(a0) + 60) = (*(float *)((char *)(ts4_word)(a1) + 60));
    *(float *)((char *)(ts4_word)(a0) + 64) = (*(float *)((char *)(ts4_word)(a1) + 64));
    *(float *)((char *)(ts4_word)(a0) + 68) = (*(float *)((char *)(ts4_word)(a1) + 68));
    t22 = *(float *)((char *)(ts4_word)(a1) + 72);
    *(float *)((char *)(ts4_word)(a0) + 72) = t22;
    *(float *)((char *)(ts4_word)(a0) + 76) = (*(float *)((char *)(ts4_word)(a1) + 76));
    *(float *)((char *)(ts4_word)(a0) + 80) = (*(float *)((char *)(ts4_word)(a1) + 80));
    *(float *)((char *)(ts4_word)(a0) + 84) = (*(float *)((char *)(ts4_word)(a1) + 84));
    *(float *)((char *)(ts4_word)(a0) + 88) = (*(float *)((char *)(ts4_word)(a1) + 88));
    *(float *)((char *)(ts4_word)(a0) + 92) = (*(float *)((char *)(ts4_word)(a1) + 92));
    *(float *)((char *)(ts4_word)(a0) + 96) = (*(float *)((char *)(ts4_word)(a1) + 96));
    *(float *)((char *)(ts4_word)(a0) + 100) = (*(float *)((char *)(ts4_word)(a1) + 100));
    return t22;
}

/* Swing_DLL.xex 0x88272080: fn  */
ts4_word ts4_fn_88272080(ts4_word a0)
{
    return (a0 + 20);
}

/* Swing_DLL.xex 0x88272088: fn  */
ts4_word ts4_fn_88272088(ts4_word a0)
{
    return (a0 + 136);
}

/* Swing_DLL.xex 0x88272090: fn  */
ts4_word ts4_fn_88272090(ts4_word a0)
{
    return (a0 + 16);
}

/* Swing_DLL.xex 0x88272098: fn  */
ts4_word ts4_fn_88272098(ts4_word a0)
{
    return (a0 + 52);
}

/* Swing_DLL.xex 0x882720A0: fn  */
ts4_word ts4_fn_882720A0(ts4_word a0)
{
    return (a0 + 4);
}

/* Swing_DLL.xex 0x882723F0: set u8@0x0, u8@0x1, u8@0x2, u8@0x3, u8@0x4, u8@0x5 */
void ts4_set_u8_off0_882723F0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 2) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 3) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 7) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 9) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 10) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 11) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 14) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 15) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 17) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 18) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 19) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 21) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 22) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 23) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 25) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 26) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 27) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 30) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 31) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 33) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 35) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 37) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 38) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 39) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88273620: fn  */
ts4_word ts4_fn_88273620(ts4_word a0)
{
    return (a0 + 12);
}

/* Swing_DLL.xex 0x88273690: get u8@0x22 */
ts4_word ts4_get_u8_off22_88273690(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 34));
}

/* Swing_DLL.xex 0x88273A58: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88658E40 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88273A58(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)180, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88658E40((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88273AB0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88658E40 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88273AB0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)180, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88658E40((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88273B08: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88658910 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88273B08(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)128, (ts4_word)8, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88658910((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88273B60: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88617D88_88658910 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88273B60(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)128, (ts4_word)8, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_88617D88_88658910((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88273BB8: get  */
float ts4_get_88273BB8(void)
{
    return (*(float *)lbl_8814B440);
}

/* Swing_DLL.xex 0x88273BC8: if_call_seq lbl_880F5848, u32@0x8, u32@0x0, fn_8860BBD8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F5848_88273BC8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5848;
    fn_8860BBD8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88273CD0: if_call_seq lbl_880F5848, u32@0x10, u32@0x0, u32@0x14, u32@0x8, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880F5848_88273CD0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5848;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_8860BBD8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88273D40: if_call_seq lbl_880F5848, u32@0x10, u32@0x0, u32@0x8, fn_8860BBD8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F5848_88273D40(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5848;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_8860BBD8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88273E08: if_call_seq lbl_880F5848, u32@0x14, u32@0x0, u32@0x10, u32@0x8, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880F5848_88273E08(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F5848;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_8860BBD8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88274DE0: get u32@0x0, u32@0x2c */
ts4_word ts4_get_u32_off0_88274DE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(float *)((char *)(ts4_word)(a0) + 64) = (*(float *)((char *)(ts4_word)(a0) + 60));
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 44))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88276260: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_882782A8, lbl_880F5408, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276260(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)84, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_882782A8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5408;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276360: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88278368, lbl_880F54E0, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276360(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)84, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88278368((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F54E0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882763E0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_882782A8, lbl_880F55B8, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882763E0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)100, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_882782A8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F55B8;
        *(ts4_word *)((char *)(ts4_word)(t2) + 88) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 92) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 96) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276470: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_882782A8, lbl_880F55B8, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276470(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)100, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_882782A8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F55B8;
        *(ts4_word *)((char *)(ts4_word)(t2) + 88) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 92) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 96) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276610: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_882782A8, lbl_880F5688, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276610(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_882782A8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5688;
        *(ts4_word *)((char *)(ts4_word)(t2) + 84) = (ts4_word)1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276698: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_882782A8, lbl_880F5688, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276698(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_882782A8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5688;
        *(ts4_word *)((char *)(ts4_word)(t2) + 84) = (ts4_word)1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276720: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88278368, lbl_880F5638, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276720(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88278368((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5638;
        *(ts4_word *)((char *)(ts4_word)(t2) + 84) = (ts4_word)1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882767A8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88278368, lbl_880F5638, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882767A8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88278368((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5638;
        *(ts4_word *)((char *)(ts4_word)(t2) + 84) = (ts4_word)1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276830: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_882782A8, lbl_880F5758, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276830(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_882782A8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5758;
        *(ts4_word *)((char *)(ts4_word)(t2) + 84) = (ts4_word)1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882768B8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_882782A8, lbl_880F5758, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882768B8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_882782A8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5758;
        *(ts4_word *)((char *)(ts4_word)(t2) + 84) = (ts4_word)1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276940: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88278368, lbl_880F57A8, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276940(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88278368((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F57A8;
        *(ts4_word *)((char *)(ts4_word)(t2) + 84) = (ts4_word)1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882769C8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88278368, lbl_880F57A8, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882769C8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88278368((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F57A8;
        *(ts4_word *)((char *)(ts4_word)(t2) + 84) = (ts4_word)1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276A50: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_882781B0, lbl_880F57F8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276A50(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_882781B0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F57F8;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276AC8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_882781B0, lbl_880F57F8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276AC8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_882781B0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F57F8;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276B40: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880F5878_88652260 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276B40(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_lbl_880F5878_88652260((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276B98: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_lbl_880F5878_88652260 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276B98(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_lbl_880F5878_88652260((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276BF0: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F5890, u32@0x4, u32@0x0, u32@0xc */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276BF0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)28, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5890;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276C70: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F5890, u32@0x4, u32@0x0, u32@0xc */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276C70(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)28, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5890;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276D68: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F58A8, u32@0x4, u32@0x0, u32@0xc */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276D68(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F58A8;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276E58: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F58C0, u32@0x4, u32@0x0, u32@0xc */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276E58(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F58C0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276ED0: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F5860, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276ED0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5860;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276F48: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F5860, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276F48(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)20, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5860;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276FC0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8864F5B0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276FC0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8864F5B0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88277018: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8864F5B0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88277018(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8864F5B0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882770E8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F5918, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882770E8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5918;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882771D8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F5930, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882771D8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5930;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88278308: call_seq fn_88617D88, lbl_880F54B0, u32@0x0, fn_8816D1A8, u32@0x2c, u32@0x34 */
ts4_word ts4_call_seq_fn_88617D88_88278308(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F54B0;
    fn_8816D1A8((ts4_word)(a0 + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)((983040) | 65535);
    return a0;
}

/* Swing_DLL.xex 0x88278738: if_call_seq fn_884CE5D0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884CE5D0_88278738(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884CE5D0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)6);
    }
    return a0;
}

/* Swing_DLL.xex 0x882797F8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88647608 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882797F8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)60, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88647608((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88279850: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88647608 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88279850(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)60, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88647608((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88279C68: if_get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_if_get_u32_off0_88279C68(ts4_word a0, ts4_word a1)
{
    float t4;
    float t5;
    float t6;
    float t7;

    if ((ts4_word)a0 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    t4 = *(float *)((char *)(ts4_word)(a1) + 16);
    t5 = *(float *)((char *)(ts4_word)(a1) + 28);
    t6 = *(float *)((char *)(ts4_word)(a1) + 24);
    t7 = *(float *)((char *)(ts4_word)(a1) + 20);
    *(float *)((char *)(ts4_word)(a0) + 16) = t4;
    *(float *)((char *)(ts4_word)(a0) + 20) = t7;
    *(float *)((char *)(ts4_word)(a0) + 24) = t6;
    *(float *)((char *)(ts4_word)(a0) + 28) = t5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    return;
}

/* Swing_DLL.xex 0x88279F08: call_seq fn_8841FC98 */
ts4_word ts4_call_seq_fn_8841FC98_88279F08(ts4_word a0, ts4_word a1)
{
    fn_8841FC98((ts4_word)a0, (ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x88279F38: get u32@0x4 */
ts4_word ts4_get_u32_off4_88279F38(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Swing_DLL.xex 0x8827A758: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8827A758(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 4), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x8827B8B8: if_call_seq u32@0x0, ts4_object_finalize, ts4_object_finalize, u32@0x10, ts4_destroy_owned_object, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8827B8B8(ts4_word a0)
{
    ts4_word p8;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    ts4_object_finalize((ts4_word)(a0 + 4));
    ts4_object_finalize((ts4_word)(a0 + 16));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((a0 + 4)) + 0);
    p8 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        t7 = ts4_destroy_owned_object((ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x8827BFF0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88639B88 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8827BFF0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88639B88((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8827C048: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88639B88 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8827C048(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88639B88((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8827C588: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886391E0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8827C588(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)164, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886391E0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8827C5E0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886391E0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8827C5E0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)164, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886391E0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8827C638: if_call_seq lbl_880F7DEC, u32@0x0, u32@lbl_88D45B40, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F7DEC_8827C638(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7DEC;
    *(ts4_word *)lbl_88D45B40 = (ts4_word)0;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x8827C690: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_8827C690(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)2;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x8827C6A8: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_8827C6A8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)3;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
    return;
}

/* Swing_DLL.xex 0x8827C760: if_call_seq lbl_880F7EA0, u32@0x24, u32@0x0, fn_8861B4D8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F7EA0_8827C760(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7EA0;
    fn_8861B4D8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8827CFB8: get u32@0x14, u32@0x0, u32@0xc */
ts4_word ts4_get_u32_off14_8827CFB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8827CFD0: get u32@0x14, u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off14_8827CFD0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8827CFE8: get u32@0x14, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off14_8827CFE8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8827D030: get u32@0x14, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off14_8827D030(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8827D048: get u32@0x14, u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off14_8827D048(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8827D060: get u32@0x18, lbl_880F824C, u32@0x0, u32@0x0, u32@0x40, vcall */
ts4_word ts4_get_u32_off18_8827D060(ts4_word a0)
{
    ts4_word t1;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F824C;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 64))))((ts4_word)t1);
    ts4_if_get_ts4_memset_886098F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)));
    t10 = fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F799C;
    return t10;
}

/* Swing_DLL.xex 0x8827D4B0: if_get u32@0x40, u32@0x1c, u32@0x48, u32@0x3c, u32@0x38, u32@0x24 */
ts4_word ts4_if_get_u32_off40_8827D4B0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word p15;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t18;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)a1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    t5 = *(ts4_word *)((char *)(ts4_word)(t1) + (a1 << 2));
    if ((int)a1 == (int)(t2 + -1)) {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36));
    } else {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    }
    loc50[0] = (ts4_word)p8;
    t9 = fn_8827D280((ts4_word)a0, (ts4_word)a1);
    p15 = (ts4_word)0;
    if ((int)t9 != 0) {
        t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        t13 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 8))))((ts4_word)t10, (ts4_word)t4, (ts4_word)t9, (ts4_word)t5, (ts4_word)2);
        p15 = (ts4_word)t13;
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((int)t9 >= (int)t16) {
        memcpy((ts4_word)t3, (ts4_word)t4, (ts4_word)t16);
        return 0;
    }
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t18) + 0))) + 44))))((ts4_word)t18, (ts4_word)t3, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t4, (ts4_word)p15);
    return 0;
}

/* Swing_DLL.xex 0x8827D588: get u32@0x50, u32@0x50 */
ts4_word ts4_get_u32_off50_8827D588(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)a1;
    return t1;
}

/* Swing_DLL.xex 0x8827D5E8: if_call_seq lbl_880F7940, u32@lbl_88D45B1C, u32@0x0, u32@0x224, u32@0x220, u32@0x224 */
ts4_word ts4_if_call_seq_lbl_880F7940_8827D5E8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7940;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 548);
    if ((ts4_word)a0 == (ts4_word)t2) {
        *(ts4_word *)((char *)(ts4_word)(t1) + 548) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 544));
    }
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8827DA88: call_seq fn_8861B128, lbl_880F8338, u8@0x24, u32@0x0, u32@0x28, u32@0x2c */
ts4_word ts4_call_seq_fn_8861B128_8827DA88(ts4_word a0)
{
    fn_8861B128((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8338;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8827E578: get fn_8827DC68, u32@0x0, u32@0x0, u32@0x44, vcall */
ts4_word ts4_get_fn_8827DC68_8827E578(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    fn_8827DC68();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 68))))((ts4_word)a0, (ts4_word)t3);
    return t5;
}

/* Swing_DLL.xex 0x8827EC80: get u8@0x9e */
ts4_word ts4_get_u8_off9e_8827EC80(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 158));
}

/* Swing_DLL.xex 0x8827EC88: get u8@0x64 */
ts4_word ts4_get_u8_off64_8827EC88(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 100));
}

/* Swing_DLL.xex 0x8827ED18: get u32@0x4, u32@0x3c */
ts4_word ts4_get_u32_off4_8827ED18(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 60)) + 24);
}

/* Swing_DLL.xex 0x8827EE00: get u32@0x4, u32@0x14, u32@0x18, u32@0x2c, u32@0x4, u32@0x34 */
ts4_word ts4_get_u32_off4_8827EE00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 44);
    t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 52);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 28))))((ts4_word)t4, (ts4_word)((t5 + t6) + t3), (ts4_word)2);
    t12 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 12))))((ts4_word)t4, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
    return t12;
}

/* Swing_DLL.xex 0x8827EE90: get u32@0x14, u32@0x8 */
ts4_word ts4_get_u32_off14_8827EE90(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 8));
}

/* Swing_DLL.xex 0x8827EEF0: get u32@0x18 */
ts4_word ts4_get_u32_off18_8827EEF0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x8827F030: get u32@0x14, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off14_8827F030(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8827F2B8: if_call_seq lbl_880F7810, lbl_880D6B70, u32@0x0, u32@0x44, fn_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F7810_8827F2B8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7810;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(ts4_word)lbl_880D6B70;
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8827F938: if_call_seq lbl_880F77E0, u32@lbl_88D45B1C, u32@0x0, u32@0x238, fn_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F77E0_8827F938(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F77E0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 568) = (ts4_word)0;
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8827FA70: if_call_seq lbl_880F78DC, lbl_880D19F0, u32@0x0, u32@0x14, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F78DC_8827FA70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F78DC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)lbl_880D19F0;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88280190: if_call_seq lbl_880DC520, u32@0x0, fn_88616160, u32@0x4, ts4_destroy_owned_object, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880DC520_88280190(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DC520;
    fn_88616160();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x882804F0: if_call_seq lbl_880F8070, u32@0x0, ts4_object_finalize, u32@0x24, ts4_destroy_owned_object, lbl_880F7940 */
ts4_word ts4_if_call_seq_lbl_880F8070_882804F0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8070;
    ts4_object_finalize((ts4_word)(a0 + 36));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    t5 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7940;
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 548);
    if ((ts4_word)a0 == (ts4_word)t6) {
        *(ts4_word *)((char *)(ts4_word)(t5) + 548) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 544));
    }
    t8 = fn_88617D28((ts4_word)a0);
    return t8;
}

/* Swing_DLL.xex 0x882806A8: if_call_seq lbl_880F8CC0, u32@0x0, ts4_object_finalize, u32@0x74, ts4_destroy_owned_object, lbl_880F8B94 */
ts4_word ts4_if_call_seq_lbl_880F8CC0_882806A8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8CC0;
    ts4_object_finalize((ts4_word)(a0 + 116));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8B94;
    t5 = fn_88617D28((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x88280958: if_call_seq u32@0x8, u32@0x4, u32@0x4, fn_8825C6C0, u32@0x4, u32@0x8 */
ts4_word ts4_if_call_seq_u32_off8_88280958(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p10;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t4 = fn_8825C6C0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4)));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(t5) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 4) = (ts4_word)0;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)t7;
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
        p10 = (ts4_word)t4;
    }
    return p10;
}

/* Swing_DLL.xex 0x882817B0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x0, u32@0x0, u32@0x0, lbl_880F82E0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882817B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t5 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)t4;
        *(unsigned char *)((char *)(ts4_word)(t2) + 16) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F82E0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)t5;
        if ((int)t6 != -1) {
            fn_88569098((ts4_word)t5, (ts4_word)t6);
        }
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882818C0: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x0, u32@0x0, u32@0x0, lbl_880F7D28 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882818C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F7D28;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)t6;
        *(ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)t4;
        *(ts4_word *)((char *)(ts4_word)(t2) + 28) = (ts4_word)t3;
        *(ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 16) = (unsigned char)1;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88281B00: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x0, u32@0x0, u32@0x0, lbl_880F85AC */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88281B00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)28, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 16) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F85AC;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)t6;
        *(ts4_word *)((char *)(ts4_word)(t2) + 20) = (ts4_word)t4;
        *(ts4_word *)((char *)(ts4_word)(t2) + 24) = (ts4_word)t3;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882823E0: if_call_seq u32@0x0, u32@0x4, u32@0x8, u32@0x0, u32@0x4, fn_881AC6A0 */
ts4_word ts4_if_call_seq_u32_off0_882823E0(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    fn_881AC6A0((ts4_word)a0, (ts4_word)(((int)(t2 - t1) >> 1) + 1));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)t4;
    if ((ts4_word)t2 != (ts4_word)t1) {
        t5 = fn_88562DC0((ts4_word)t4, (ts4_word)t1, (ts4_word)(t2 - t1));
        p6 = (ts4_word)(t5 + (t2 - t1));
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p6;
    *(unsigned short *)((char *)(ts4_word)(p6) + 0) = (unsigned short)0;
    return a0;
}

/* Swing_DLL.xex 0x88283E68: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88636A70 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88283E68(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88636A70((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88283EC0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88636A70 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88283EC0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88636A70((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88283F18: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F7FC0, u8@0x1c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88283F18(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 28) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F7FC0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 29) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 40) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88283FA8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F7FC0, u8@0x1c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88283FA8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 28) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F7FC0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 29) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 40) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284038: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F8018, u8@0x1c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284038(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 28) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8018;
        *(unsigned char *)((char *)(ts4_word)(t2) + 29) = (unsigned char)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882840C0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F8018, u8@0x1c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882840C0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(unsigned char *)((char *)(ts4_word)(t2) + 28) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F8018;
        *(unsigned char *)((char *)(ts4_word)(t2) + 29) = (unsigned char)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284148: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88623C60 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284148(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)76, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88623C60((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882841A0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88623C60 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882841A0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)76, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88623C60((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882843D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88622D18 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882843D8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88622D18((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284430: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88622D18 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284430(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)48, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88622D18((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284488: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_8861B128_88622BF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284488(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)60, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_8861B128_88622BF0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882844E0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_8861B128_88622BF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882844E0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)60, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_8861B128_88622BF0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882847F0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88622888 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882847F0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)11764, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88622888((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284848: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8862A190 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284848(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)396, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8862A190((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882848A0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8862A190 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882848A0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)396, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8862A190((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284A58: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88626638 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284A58(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)80, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88626638((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284AB0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88626638 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284AB0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)80, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88626638((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284B08: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88621250 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284B08(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88621250((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284B60: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88621250 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284B60(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88621250((ts4_word)t2);
        return t3;
    }
    return 0;
}
