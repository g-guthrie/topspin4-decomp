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

extern char lbl_88028B5C[];
extern char lbl_88028BB4[];
extern char lbl_88028D18[];
extern char lbl_88028DE4[];
extern char lbl_88028EA4[];
extern char lbl_88028F78[];
extern char lbl_88028F80[];
extern char lbl_88028FA0[];
extern char lbl_880291FC[];
extern char lbl_88029204[];
extern char lbl_8802924C[];
extern char lbl_880292C8[];
extern char lbl_88029348[];
extern char lbl_8802936C[];
extern char lbl_880293EC[];
extern char lbl_880293F4[];
extern char lbl_88029544[];
extern char lbl_8802B0B4[];
extern char lbl_8802B7FC[];
extern char lbl_8802BA10[];
extern char lbl_8802BAA0[];
extern char lbl_8802BB80[];
extern char lbl_8802BDD8[];
extern char lbl_8802BE04[];
extern char lbl_8802BE30[];
extern char lbl_8802BE4C[];
extern char lbl_8802BE58[];
extern char lbl_8802BE90[];
extern char lbl_880C1320[];
extern char lbl_88B3302C[];
extern char lbl_88B3AA40[];
extern char lbl_88C6E260[];
extern char lbl_88C74994[];
extern char lbl_88C922E4[];
extern char lbl_88C922F4[];
extern char ts4_adjust_minus_28_thunk_8832ADF0[];
extern char ts4_forward_88315998[];
extern char ts4_forward_883159A0[];
extern char ts4_forward_883159A8[];
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word ts4_if_get_u32_offe4_88309B78();
ts4_word fn_8830C628();
ts4_word fn_8830F378();
ts4_word fn_88314478();
ts4_word fn_88315C60();
ts4_word fn_88315F10();
ts4_word ts4_if_call_seq_u32_off4_88316460();
ts4_word fn_883179C0();
ts4_word ts4_addr_lbl_88028B5C_88318518();
ts4_word fn_88318550();
ts4_word fn_88318638();
ts4_word fn_883194F0();
ts4_word fn_88319E00();
ts4_word ts4_call_seq_u32_off158_88319F08();
ts4_word fn_8831A058();
ts4_word ts4_if_call_seq_fn_8857A1E0_8831A740();
ts4_word fn_8831A830();
ts4_word fn_8831CBA8();
ts4_word fn_8831CD30();
ts4_word fn_8831CE30();
ts4_word fn_8831DAC0();
ts4_word ts4_if_call_seq_u32_off11c_8831E730();
ts4_word fn_8831E890();
ts4_word fn_88322CA8();
ts4_word fn_88324160();
ts4_word fn_88324B90();
ts4_word fn_88324EE0();
ts4_word fn_88326940();
ts4_word fn_88327480();
ts4_word fn_88327878();
ts4_word fn_883290D0();
ts4_word ts4_strlen_88329658();
ts4_word fn_883296A0();
ts4_word fn_8832AEE0();
ts4_word ts4_if_get_u32_offd8_8832AFB0();
ts4_word fn_8832D4F0();
ts4_word fn_8832E508();
ts4_word fn_8832E690();
ts4_word fn_8832EDB0();
ts4_word fn_883300E8();
ts4_word fn_88330278();
ts4_word fn_883306D8();
ts4_word ts4_addr_lbl_88029348_88332070();
ts4_word ts4_if_get_u32_off44_88334890();
ts4_word fn_88335DF8();
ts4_word fn_88336050();
ts4_word ts4_if_get_u32_off108_88376FC0();
ts4_word fn_88377118();
ts4_word fn_88381F90();
ts4_word fn_88396320();
ts4_word fn_88397970();
ts4_word fn_883A3000();
ts4_word lib2_FLAC__stream_decoder_finish_883A5320();
ts4_word fn_883A69B0();
ts4_word fn_883ACE00();
ts4_word ts4_set_u32_off34_883ACE40();
ts4_word ts4_fn_883E63B8();
ts4_word ts4_tailcall_fn_88582F30_8857A128();
ts4_word fn_8857A1E0();
ts4_word fn_8857ACB8();
ts4_word ts4_tailcall_fn_88584548_8857AFE8();
ts4_word fn_8857BFA8();
ts4_word fn_8857C040();
ts4_word ts4_memset();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x88319FE8: call_seq u32@0x0, u32@0x4, u32@0x8, ts4_addr_lbl_88028B5C_88318518, u32@0x140, u32@0x138 */
ts4_word ts4_call_seq_u32_off0_88319FE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    ts4_addr_lbl_88028B5C_88318518((ts4_word)(a0 + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 320) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 312) = (ts4_word)(a0 + 312);
    *(ts4_word *)((char *)(ts4_word)(a0) + 316) = (ts4_word)(a0 + 312);
    *(ts4_word *)((char *)(ts4_word)(a0) + 332) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 324) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 328) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 308) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 336) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8831A5C0: call_seq fn_8832EDB0, ts4_call_seq_u32_off158_88319F08 */
ts4_word ts4_call_seq_fn_8832EDB0_8831A5C0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)256, (ts4_word)456);
    t2 = ts4_call_seq_u32_off158_88319F08((ts4_word)a0, (ts4_word)a1);
    return t2;
}

/* Swing_DLL.xex 0x8831ACF0: if_call_seq lbl_88028EA4, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_if_call_seq_lbl_88028EA4_8831ACF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 == 0) {
        return 37;
    }
    if ((ts4_word)(a1 & 0xff) == 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88028EA4, (ts4_word)639);
    }
    return 0;
}

/* Swing_DLL.xex 0x8831AD58: if_call_seq RtlEnterCriticalSection */
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_8831AD58(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return 37;
    }
    RtlEnterCriticalSection();
    return 0;
}

/* Swing_DLL.xex 0x8831AD98: if_call_seq RtlLeaveCriticalSection */
ts4_word ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return 37;
    }
    RtlLeaveCriticalSection();
    return 0;
}

/* Swing_DLL.xex 0x8831FF38: if_call_seq u32@0x1c0, ts4_if_call_seq_fn_8857A1E0_8831A740, u32@0x1c0 */
ts4_word ts4_if_call_seq_u32_off1c0_8831FF38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 448);
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_if_call_seq_fn_8857A1E0_8831A740((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 448) = (ts4_word)0;
        p4 = (ts4_word)t2;
    }
    return p4;
}

/* Swing_DLL.xex 0x88320300: call_seq fn_8832EDB0, ts4_call_seq_u32_off158_88319F08 */
ts4_word ts4_call_seq_fn_8832EDB0_88320300(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)256, (ts4_word)480);
    t2 = ts4_call_seq_u32_off158_88319F08((ts4_word)a0, (ts4_word)a1);
    return t2;
}

/* Swing_DLL.xex 0x88328670: tailcall fn_88327480 */
ts4_word ts4_tailcall_fn_88327480_88328670(ts4_word a0)
{
    return fn_88327480((ts4_word)a0, (ts4_word)95);
}

/* Swing_DLL.xex 0x88329598: call_seq fn_8832EDB0, ts4_call_seq_u32_off158_88319F08 */
ts4_word ts4_call_seq_fn_8832EDB0_88329598(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)256, (ts4_word)452);
    t2 = ts4_call_seq_u32_off158_88319F08((ts4_word)a0, (ts4_word)a1);
    return t2;
}

/* Swing_DLL.xex 0x8832BFC0: if_set u32@0x0 */
ts4_word ts4_if_set_u32_off0_8832BFC0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    if ((ts4_word)a0 == 0) {
        return 36;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a0;
    return 0;
}

/* Swing_DLL.xex 0x8832C2E8: if_get u32@0x238, u32@0x0, u32@0x23c, u32@0x4, u32@0x240, u32@0x8 */
ts4_word ts4_if_get_u32_off238_8832C2E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 568));
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 572));
        *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 576));
    }
    if ((ts4_word)a2 != 0) {
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 580));
    }
    if ((ts4_word)a3 != 0) {
        *(float *)((char *)(ts4_word)(a3) + 0) = (*(float *)((char *)(ts4_word)(a0) + 584));
    }
    return 0;
}

/* Swing_DLL.xex 0x8832E758: addr lbl_880292C8, lbl_88028B5C, u32@0x0, u32@0x10 */
void ts4_addr_lbl_880292C8_8832E758(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880292C8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_88028B5C;
    return;
}

/* Swing_DLL.xex 0x8832F930: if_set u32@0x0 */
ts4_word ts4_if_set_u32_off0_8832F930(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 == 0) {
        return 36;
    }
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)a0;
    return 0;
}

/* Swing_DLL.xex 0x88330948: if_get u32@0x14, u32@0x5538, fn_883306D8 */
ts4_word ts4_if_get_u32_off14_88330948(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t2;

    (void)a1;
    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 21816);
    if ((ts4_word)a0 == (ts4_word)t2) {
        return 36;
    }
    return fn_883306D8((ts4_word)a0, (ts4_word)0, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
}

/* Swing_DLL.xex 0x88332D48: call_seq u32@0x0, u32@0x4, u32@0x8, ts4_addr_lbl_88028B5C_88318518, u32@0x140, u32@0x138 */
ts4_word ts4_call_seq_u32_off0_88332D48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    ts4_addr_lbl_88028B5C_88318518((ts4_word)(a0 + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 320) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 312) = (ts4_word)(a0 + 312);
    *(ts4_word *)((char *)(ts4_word)(a0) + 316) = (ts4_word)(a0 + 312);
    *(ts4_word *)((char *)(ts4_word)(a0) + 332) = (ts4_word)(a0 + 332);
    *(ts4_word *)((char *)(ts4_word)(a0) + 336) = (ts4_word)(a0 + 332);
    *(ts4_word *)((char *)(ts4_word)(a0) + 340) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 324) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 308) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 329) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 330) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88335550: if_call_seq u32@0x44, ts4_if_get_u32_offe4_88309B78, u32@0x9c, ts4_if_get_u32_off44_88334890 */
ts4_word ts4_if_call_seq_u32_off44_88335550(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != 0) {
        ts4_if_get_u32_offe4_88309B78((ts4_word)t1);
    }
    t5 = ts4_if_get_u32_off44_88334890((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 156)), (ts4_word)a1);
    return t5;
}

/* Swing_DLL.xex 0x88339910: call_seq fn_8832AEE0, ts4_addr_lbl_88028B5C_88318518, lbl_880291FC, lbl_88029544, u32@0x0, u32@0x168 */
ts4_word ts4_call_seq_fn_8832AEE0_88339910(ts4_word a0)
{
    fn_8832AEE0();
    ts4_addr_lbl_88028B5C_88318518((ts4_word)(a0 + 360));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880291FC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 360) = (ts4_word)(ts4_word)lbl_88029544;
    *(ts4_word *)((char *)(ts4_word)(a0) + 660) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88339B50: if_call_seq lbl_88028B5C, u32@0x168, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88028B5C_88339B50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 360) = (ts4_word)(ts4_word)lbl_88028B5C;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x8837B2D0: call_seq ts4_addr_lbl_88029348_88332070, lbl_8802BE4C, u32@0x18, u32@0x0, u32@0x1c, u32@0x20 */
ts4_word ts4_call_seq_fn_88332070_8837B2D0(ts4_word a0)
{
    ts4_addr_lbl_88029348_88332070((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8802BE4C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)32;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)300;
    return a0;
}

