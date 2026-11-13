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
ts4_word ts4_call_seq_fn_8861B128_8827DA88();
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

/* Swing_DLL.xex 0x88284628: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_8861B128_8827DA88 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284628(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)576, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_8861B128_8827DA88((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284680: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_8861B128_8827DA88 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284680(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)576, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_8861B128_8827DA88((ts4_word)t2);
        return t3;
    }
    return 0;
}

