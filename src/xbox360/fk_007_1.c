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
ts4_word ts4_strlen_88329658();
ts4_word fn_8832EDB0();
ts4_word fn_8836CD70();
ts4_word ts4_call_seq_fn_88336050_88374E88();
ts4_word fn_88375208();
ts4_word fn_88388048();
ts4_word fn_88396180();
ts4_word fn_883961D8();
ts4_word ts4_if_call_seq_u32_off510_88396230();
ts4_word ts4_if_call_seq_u32_off43c_883962A8();
ts4_word fn_88399560();
ts4_word aud1_check_mode_8839A678();
ts4_word fn_883A3218();
ts4_word fn_883A3950();
ts4_word fn_883AA340();
ts4_word aud1__ov_open1_883AA9E0();
ts4_word fn_883AAC28();
ts4_word ts4_addr_lbl_8802BC90_883AC348();
ts4_word ts4_if_get_u32_offc_883AC3D8();
ts4_word fn_883AD0D0();
ts4_word aud1__vorbis_block_ripcord_883BBE98();
ts4_word fn_883BC3B8();
ts4_word fn_883BFF30();
ts4_word fn_883C03D8();
ts4_word fn_883C1EB8();
ts4_word fn_883C1FD0();
ts4_word fn_883C72E0();
ts4_word fn_883C8F98();
ts4_word fn_883CA4F0();
ts4_word fn_883CE7E0();
ts4_word ts4_hash_bytes_883D1D68();
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

/* Swing_DLL.xex 0x883AE450: call_seq ts4_addr_lbl_8802BC90_883AC348, lbl_8802F8D0, u32@0x0 */
ts4_word ts4_call_seq_fn_883AC348_883AE450(ts4_word a0)
{
    float t2;

    ts4_addr_lbl_8802BC90_883AC348((ts4_word)a0);
    t2 = *(float *)lbl_88001A20;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8802F8D0;
    *(float *)((char *)(ts4_word)(a0) + 80) = t2;
    return a0;
}

/* Swing_DLL.xex 0x883AE498: get ts4_if_get_u32_offc_883AC3D8 */
ts4_word ts4_get_fn_883AC3D8_883AE498(ts4_word a0)
{
    *(float *)((char *)(ts4_word)(a0) + 80) = (*(float *)lbl_88001A20);
    return ts4_if_get_u32_offc_883AC3D8((ts4_word)a0);
}

/* Swing_DLL.xex 0x883BBF50: if_call_seq aud1__vorbis_block_ripcord_883BBE98, u32@0x44, fn_8836CD70, ts4_memset */
ts4_word ts4_if_call_seq_fn_883BBE98_883BBF50(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;

    t1 = aud1__vorbis_block_ripcord_883BBE98();
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 68);
        if ((ts4_word)t2 != 0) {
            fn_8836CD70((ts4_word)a0, (ts4_word)t2);
        }
        ts4_memset((ts4_word)a1, (ts4_word)0, (ts4_word)104);
        p6 = (ts4_word)0;
    }
    return p6;
}

