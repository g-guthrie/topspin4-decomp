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
ts4_word fn_8830C628();
ts4_word fn_8830F378();
ts4_word fn_88314478();
ts4_word fn_88315C60();
ts4_word fn_88315F10();
ts4_word ts4_if_call_seq_u32_off4_88316460();
ts4_word fn_883179C0();
ts4_word fn_88318550();
ts4_word fn_88318638();
ts4_word fn_883194F0();
ts4_word fn_88319E00();
ts4_word fn_8831A058();
ts4_word fn_8831A830();
ts4_word ts4_if_call_seq_lbl_88028EA4_8831ACF0();
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_8831AD58();
ts4_word ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98();
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
ts4_word ts4_tailcall_fn_88327480_88328670();
ts4_word fn_883290D0();
ts4_word ts4_strlen_88329658();
ts4_word fn_883296A0();
ts4_word fn_8832AEE0();
ts4_word ts4_if_get_u32_offd8_8832AFB0();
ts4_word ts4_if_set_u32_off0_8832BFC0();
ts4_word ts4_if_get_u32_off238_8832C2E8();
ts4_word fn_8832D4F0();
ts4_word fn_8832E508();
ts4_word fn_8832E690();
ts4_word ts4_addr_lbl_880292C8_8832E758();
ts4_word fn_8832EDB0();
ts4_word ts4_if_set_u32_off0_8832F930();
ts4_word fn_883300E8();
ts4_word fn_88330278();
ts4_word fn_883306D8();
ts4_word ts4_if_get_u32_off14_88330948();
ts4_word fn_88335DF8();
ts4_word fn_88336050();
ts4_word ts4_if_call_seq_lbl_88028B5C_88339B50();
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

/* Swing_DLL.xex 0x88309A30: if_tailcall fn_883179C0 */
ts4_word ts4_if_tailcall_fn_883179C0_88309A30(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return 37;
    }
    return fn_883179C0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88309A90: fn  */
ts4_word ts4_fn_88309A90(void)
{
    return 78;
}

/* Swing_DLL.xex 0x88309A98: get u32@0x14, u32@0x0 */
ts4_word ts4_get_u32_off14_88309A98(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    return 0;
}

/* Swing_DLL.xex 0x88309AA8: get u32@0x0, u32@0x8, u32@0x10, u32@0x18, vcall, u32@0x18 */
ts4_word ts4_get_u32_off0_88309AA8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 16);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 24))))((ts4_word)a0, (ts4_word)t3, (ts4_word)t2, (ts4_word)(a1 + 20));
    *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)t5;
    return t5;
}

/* Swing_DLL.xex 0x88309B78: if_get u32@0xe4, u32@0xf4, u32@0xf0, ts4_memset, u32@0x9c, vcall */
ts4_word ts4_if_get_u32_offe4_88309B78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t5;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 228);
    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        ts4_memset((ts4_word)t1, (ts4_word)0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 240)));
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 156);
    if ((ts4_word)t5 != 0) {
        t6 = ((ts4_word (*)(ts4_word))(t5))((ts4_word)(a0 + 28));
        return t6;
    }
    return 0;
}

/* Swing_DLL.xex 0x88309CD0: call_seq fn_8831A058, lbl_88028BB4, u32@0x1d8, u32@0x0, u32@0x1dc, u32@0x1c0 */
ts4_word ts4_call_seq_fn_8831A058_88309CD0(ts4_word a0)
{
    fn_8831A058((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 472) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88028BB4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 476) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 448) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 452) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 456) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 460) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 464) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 468) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8830B110: if_get u8@0x15, u32@0x551c */
ts4_word ts4_if_get_u8_off15_8830B110(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    if ((int)a1 < 0) {
        return 37;
    }
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 21);
    if ((ts4_word)t1 != 0) {
        return 32;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 21788) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x8830B820: if_get u32@0x5360, u32@0x0 */
ts4_word ts4_if_get_u32_off5360_8830B820(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 21344));
    return 0;
}

/* Swing_DLL.xex 0x8830B908: if_get  */
ts4_word ts4_if_get_8830B908(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a1 != 0) {
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 21356));
    }
    if ((ts4_word)a2 != 0) {
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 21348));
    }
    if ((ts4_word)a3 != 0) {
        *(float *)((char *)(ts4_word)(a3) + 0) = (*(float *)((char *)(ts4_word)(a0) + 21352));
    }
    return 0;
}

/* Swing_DLL.xex 0x8830BC40: if_get u32@0x5538, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off5538_8830BC40(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 21816);
    if ((ts4_word)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
        return 81;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
    return 0;
}

/* Swing_DLL.xex 0x8830BD38: if_get u8@0x663c, u8@0x0 */
ts4_word ts4_if_get_u8_off663c_8830BD38(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 26172));
    }
    return 0;
}

/* Swing_DLL.xex 0x8830C088: if_get u32@0x1110, u32@0x0 */
ts4_word ts4_if_get_u32_off1110_8830C088(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4368);
    if ((ts4_word)t1 == 0) {
        return 33;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
    return 0;
}

/* Swing_DLL.xex 0x8830C108: if_get u32@0x5198, u32@0x0, u32@0x519c, u32@0x0 */
ts4_word ts4_if_get_u32_off5198_8830C108(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20888));
    }
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20892));
    }
    return 0;
}

/* Swing_DLL.xex 0x8830C8A8: if_get u32@lbl_88B3302C, u32@0x0 */
ts4_word ts4_if_get_u32_lbl_88B3302C_8830C8A8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)lbl_88B3302C);
    return 0;
}

/* Swing_DLL.xex 0x8830C8D0: if_call_seq u32@0x4, u8@0x663c, fn_8857ACB8 */
ts4_word ts4_if_call_seq_u32_off4_8830C8D0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((int)t1 != -1) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 26172) = (unsigned char)1;
    }
    fn_8857ACB8((ts4_word)(a0 + 26176), (ts4_word)a1, (ts4_word)124);
    return 0;
}

/* Swing_DLL.xex 0x8830C930: if_call_seq fn_8857ACB8 */
ts4_word ts4_if_call_seq_fn_8857ACB8_8830C930(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    fn_8857ACB8((ts4_word)a1, (ts4_word)(a0 + 26176), (ts4_word)124);
    return 0;
}

/* Swing_DLL.xex 0x8830F2F8: if_call_seq lbl_88028D18, u32@0x0, ts4_addr_lbl_880292C8_8832E758, lbl_88028B5C, lbl_880C1320, u32@0x5a28 */
ts4_word ts4_if_call_seq_lbl_88028D18_8830F2F8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88028D18;
    ts4_addr_lbl_880292C8_8832E758((ts4_word)(a0 + 24572));
    *(ts4_word *)((char *)(ts4_word)(a0) + 23080) = (ts4_word)(ts4_word)lbl_88028B5C;
    ts4_if_call_seq_u32_off4_88316460((ts4_word)(a0 + 21952), (ts4_word)(ts4_word)lbl_880C1320, (ts4_word)0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88310728: tailcall fn_8830F378 */
ts4_word ts4_tailcall_fn_8830F378_88310728(ts4_word a0)
{
    return fn_8830F378((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88314958: tailcall fn_88314478 */
ts4_word ts4_tailcall_fn_88314478_88314958(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88314478((ts4_word)a0, (ts4_word)a1, (ts4_word)(a2 | 128));
}

/* Swing_DLL.xex 0x883159B0: addr ts4_forward_88315998, ts4_forward_883159A0, u32@0x48, ts4_forward_883159A8, u32@0x38, u32@0x3c */
void ts4_addr_ts4_forward_88315998_883159B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(ts4_word)ts4_forward_88315998;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(ts4_word)ts4_forward_883159A0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(ts4_word)ts4_forward_883159A8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88316068: tailcall fn_88315C60 */
ts4_word ts4_tailcall_fn_88315C60_88316068(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_88315C60((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)1);
}

/* Swing_DLL.xex 0x883163B8: get u32@lbl_88B3302C, u32@0x4, fn_88315C60 */
ts4_word ts4_get_u32_lbl_88B3302C_883163B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)1);
}

/* Swing_DLL.xex 0x883163E0: get u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_get_u32_lbl_88B3302C_883163E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x883166F8: get u32@lbl_88C6E260, u32@lbl_88C6E260 */
ts4_word ts4_get_u32_lbl_88C6E260_883166F8(void)
{
    *(ts4_word *)lbl_88C6E260 = (ts4_word)((*(ts4_word *)lbl_88C6E260) + 1);
    return 0;
}

/* Swing_DLL.xex 0x88316BB0: if_get ts4_if_set_u32_off0_8832BFC0, u32@0x0, u32@0x70, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88316BB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p6;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 112))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88316F78: if_call_seq fn_88322CA8, ts4_tailcall_fn_88327480_88328670 */
ts4_word ts4_if_call_seq_fn_88322CA8_88316F78(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_tailcall_fn_88327480_88328670((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88317138: if_call_seq fn_88322CA8, fn_88324160 */
ts4_word ts4_if_call_seq_fn_88322CA8_88317138(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_88324160((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88317278: if_call_seq fn_88322CA8, fn_88324B90 */
ts4_word ts4_if_call_seq_fn_88322CA8_88317278(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_88324B90((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88317318: if_call_seq fn_88322CA8, fn_88327878 */
ts4_word ts4_if_call_seq_fn_88322CA8_88317318(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_88327878((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x883174F8: if_call_seq fn_88322CA8, fn_88324EE0 */
ts4_word ts4_if_call_seq_fn_88322CA8_883174F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_88324EE0((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88317A28: if_call_seq ts4_if_set_u32_off0_8832F930, ts4_if_get_u32_off14_88330948 */
ts4_word ts4_if_call_seq_fn_8832F930_88317A28(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_if_set_u32_off0_8832F930((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_if_get_u32_off14_88330948((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88317DC8: if_call_seq ts4_if_set_u32_off0_8832F930, fn_883300E8 */
ts4_word ts4_if_call_seq_fn_8832F930_88317DC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_if_set_u32_off0_8832F930((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_883300E8((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88317E68: if_call_seq ts4_if_set_u32_off0_8832F930, fn_88330278 */
ts4_word ts4_if_call_seq_fn_8832F930_88317E68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_if_set_u32_off0_8832F930((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_88330278((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88317EC0: if_get ts4_if_set_u32_off0_8832BFC0, u32@0x0, u32@0x14, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88317EC0(ts4_word a0)
{
    ts4_word p6;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 20))))((ts4_word)t2, (ts4_word)1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88317F08: if_call_seq ts4_if_set_u32_off0_8832BFC0, fn_8831CD30 */
ts4_word ts4_if_call_seq_fn_8832BFC0_88317F08(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8831CD30((ts4_word)t2, (ts4_word)a1, (ts4_word)0);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88317F50: if_call_seq ts4_if_set_u32_off0_8832BFC0, fn_8831CE30 */
ts4_word ts4_if_call_seq_fn_8832BFC0_88317F50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8831CE30((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x883180C8: if_get ts4_if_set_u32_off0_8832BFC0, u32@0x0, u32@0x34, vcall */
ts4_word ts4_if_get_fn_8832BFC0_883180C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 52))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)a7);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88318138: if_get ts4_if_set_u32_off0_8832BFC0, u32@0x0, u32@0x40, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88318138(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 64))))((ts4_word)t2, (ts4_word)a1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88318208: if_get ts4_if_set_u32_off0_8832BFC0, u32@0x0, u32@0x48, vcall */
ts4_word ts4_if_get_fn_8832BFC0_88318208(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p6;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p6 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 72))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88318260: if_call_seq ts4_if_set_u32_off0_8832BFC0, fn_8832D4F0 */
ts4_word ts4_if_call_seq_fn_8832BFC0_88318260(ts4_word a0)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = fn_8832D4F0((ts4_word)t2, (ts4_word)1);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88318300: if_call_seq ts4_if_set_u32_off0_8832BFC0, ts4_if_get_u32_off238_8832C2E8 */
ts4_word ts4_if_call_seq_fn_8832BFC0_88318300(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_if_get_u32_off238_8832C2E8((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88318518: addr lbl_88028B5C, u32@0x108, u32@0x0, u8@0x10c, u32@0x114, u32@0x110 */
void ts4_addr_lbl_88028B5C_88318518(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88028B5C;
    *(unsigned char *)((char *)(ts4_word)(a0) + 268) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 288) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88318650: if_call_seq u32@0x118, u32@lbl_88C74994, fn_8832EDB0, u32@0x11c, u32@lbl_88C74994, fn_8832EDB0 */
ts4_word ts4_if_call_seq_u32_off118_88318650(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 280);
    if ((ts4_word)t1 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)4, (ts4_word)(*(ts4_word *)lbl_88C74994));
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 284);
    if ((ts4_word)t5 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)4, (ts4_word)(*(ts4_word *)lbl_88C74994));
    }
    return 0;
}

/* Swing_DLL.xex 0x883188A0: if_call_seq u32@lbl_88B3302C, u32@0x2c, ts4_if_call_seq_RtlEnterCriticalSection_8831AD58, u32@lbl_88B3302C, u32@0x14, u32@lbl_88B3302C */
ts4_word ts4_if_call_seq_u32_lbl_88B3302C_883188A0(ts4_word a0)
{

    if ((int)a0 != 0) {
        ts4_if_call_seq_RtlEnterCriticalSection_8831AD58((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 44)));
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 20) = (ts4_word)1;
    } else {
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 20) = (ts4_word)0;
        ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 44)));
    }
    return 0;
}

/* Swing_DLL.xex 0x88318910: if_call_seq u32@0x4, u32@0x0, u32@0x0, u32@0x0, u32@0x4, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_88318910(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 308) = (unsigned char)0;
    fn_88318550((ts4_word)(a0 + 12));
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 332);
    if ((ts4_word)t6 != 0) {
        ts4_if_call_seq_lbl_88028EA4_8831ACF0((ts4_word)t6, (ts4_word)0);
    }
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_88028DE4, (ts4_word)312);
    return 0;
}

/* Swing_DLL.xex 0x883189A8: call_seq u32@0x18c, u32@0x160, u32@0x180, u32@0x24, u32@0x20, u32@0x174 */
ts4_word ts4_call_seq_u32_off18c_883189A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 396) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 352) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 372) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 436) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 440) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 344) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 360) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 364) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 368) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 356) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 340) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 348) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 432) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 332) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 336) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 376) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a2;
    ts4_memset((ts4_word)(a0 + 300), (ts4_word)0, (ts4_word)32);
    ts4_memset((ts4_word)(a0 + 44), (ts4_word)0, (ts4_word)256);
    ts4_memset((ts4_word)(a0 + 400), (ts4_word)0, (ts4_word)32);
    return 0;
}

/* Swing_DLL.xex 0x88319BF0: if_call_seq fn_883194F0, u32@0x0 */
ts4_word ts4_if_call_seq_fn_883194F0_88319BF0(ts4_word a0, ts4_word a1)
{
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = fn_883194F0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)4, (ts4_word)1, (ts4_word)(ts4_word)&loc54[0]);
    if ((ts4_word)a1 != 0) {
        t2 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t2;
    }
    return t1;
}

/* Swing_DLL.xex 0x88319E40: if_get u32@0x18, u32@0x1c, u32@0x174, u32@0x14, u32@0x14 */
ts4_word ts4_if_get_u32_off18_88319E40(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 372) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t1;
    if ((ts4_word)(t1 + a1) <= (ts4_word)t2) {
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(t2 - a1);
    return 0;
}

/* Swing_DLL.xex 0x88319E70: if_get u32@0x174, u32@0x0 */
ts4_word ts4_if_get_u32_off174_88319E70(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 372));
    return 0;
}

/* Swing_DLL.xex 0x88319E90: if_set u32@0x0 */
ts4_word ts4_if_set_u32_off0_88319E90(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(a0 + 44);
    }
    return 0;
}

/* Swing_DLL.xex 0x88319EA8: if_call_seq fn_883296A0, u8@0x12b */
ts4_word ts4_if_call_seq_fn_883296A0_88319EA8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    fn_883296A0((ts4_word)(a0 + 44), (ts4_word)a1, (ts4_word)256);
    *(unsigned char *)((char *)(ts4_word)(a0) + 299) = (unsigned char)0;
    return 0;
}

/* Swing_DLL.xex 0x88319F08: call_seq u32@0x158, fn_8832EDB0 */
ts4_word ts4_call_seq_u32_off158_88319F08(ts4_word a0, ts4_word a1)
{
    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)256, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 344)));
    return 0;
}

/* Swing_DLL.xex 0x8831A5A0: if_get u32@0x1c, u32@0x1c0, u32@0x1c0 */
ts4_word ts4_if_get_u32_off1c_8831A5A0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 448) = (ts4_word)a1;
    if ((ts4_word)a1 > (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 448) = (ts4_word)t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x8831A740: if_call_seq fn_8857A1E0 */
ts4_word ts4_if_call_seq_fn_8857A1E0_8831A740(ts4_word a0)
{
    if ((int)a0 == -1) {
        return 19;
    }
    fn_8857A1E0();
    return 0;
}

/* Swing_DLL.xex 0x8831A8F0: call_seq ts4_tailcall_fn_88584548_8857AFE8 */
ts4_word ts4_call_seq_fn_8857AFE8_8831A8F0(ts4_word a0)
{
    ts4_tailcall_fn_88584548_8857AFE8((ts4_word)a0);
    return 0;
}

/* Swing_DLL.xex 0x8831AC10: call_seq fn_8857A1E0 */
ts4_word ts4_call_seq_fn_8857A1E0_8831AC10(void)
{
    fn_8857A1E0();
    return 0;
}

/* Swing_DLL.xex 0x8831ADD8: if_call_seq fn_8857BFA8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_8857BFA8_8831ADD8(ts4_word a0)
{
    ts4_word t1;

    if ((int)a0 == -1) {
        return 37;
    }
    t1 = fn_8857BFA8((ts4_word)0, (ts4_word)0, (ts4_word)((0) | 65535), (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return 0;
}

/* Swing_DLL.xex 0x8831AE40: if_call_seq fn_8857A1E0 */
ts4_word ts4_if_call_seq_fn_8857A1E0_8831AE40(ts4_word a0)
{
    if ((int)a0 == -1) {
        return 37;
    }
    fn_8857A1E0();
    return 0;
}

/* Swing_DLL.xex 0x8831AE80: if_call_seq ts4_tailcall_fn_88582F30_8857A128 */
ts4_word ts4_if_call_seq_fn_8857A128_8831AE80(ts4_word a0)
{
    if ((int)a0 == -1) {
        return 37;
    }
    ts4_tailcall_fn_88582F30_8857A128((ts4_word)a0, (ts4_word)-1);
    return 0;
}

/* Swing_DLL.xex 0x8831AEC8: if_call_seq fn_8857C040 */
ts4_word ts4_if_call_seq_fn_8857C040_8831AEC8(ts4_word a0)
{
    if ((int)a0 == -1) {
        return 37;
    }
    fn_8857C040((ts4_word)a0, (ts4_word)1, (ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x8831AF10: fn  */
ts4_word ts4_fn_8831AF10(void)
{
    return 80;
}

/* Swing_DLL.xex 0x8831C988: if_get u32@0x14, u32@0x0 */
ts4_word ts4_if_get_u32_off14_8831C988(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20));
    return 0;
}

/* Swing_DLL.xex 0x8831D098: if_call_seq u32@0x14, fn_8830C628, u32@0x14, u32@0x1104, ts4_if_call_seq_RtlEnterCriticalSection_8831AD58, u32@0x44 */
ts4_word ts4_if_call_seq_u32_off14_8831D098(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    if ((ts4_word)(a2 & 0xff) != 0) {
        fn_8830C628((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)1);
        ts4_if_call_seq_RtlEnterCriticalSection_8831AD58((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 4356)));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68));
    if ((ts4_word)(a2 & 0xff) != 0) {
        ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 4356)));
    }
    return 0;
}

/* Swing_DLL.xex 0x8831D110: if_call_seq u32@0x14, fn_8830C628, u32@0x14, u32@0x1104, ts4_if_call_seq_RtlEnterCriticalSection_8831AD58, u32@0x48 */
ts4_word ts4_if_call_seq_u32_off14_8831D110(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    if ((ts4_word)(a2 & 0xff) != 0) {
        fn_8830C628((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)1);
        ts4_if_call_seq_RtlEnterCriticalSection_8831AD58((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 4356)));
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 72));
    if ((ts4_word)(a2 & 0xff) != 0) {
        ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 4356)));
    }
    return 0;
}

/* Swing_DLL.xex 0x8831D188: if_get u32@0x98, u32@0x1c */
ts4_word ts4_if_get_u32_off98_8831D188(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 152);
    if ((ts4_word)t1 == 0) {
        return 82;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a0;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t1))((ts4_word)(a0 + 28), (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8831D2D8: if_get u32@0xa4, u32@0x0 */
ts4_word ts4_if_get_u32_offa4_8831D2D8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 164));
    return 0;
}

/* Swing_DLL.xex 0x8831D450: if_call_seq fn_883296A0, u32@0x88, u32@0x0, u32@0x8c, u32@0x0, u32@0xb8 */
ts4_word ts4_if_call_seq_fn_883296A0_8831D450(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        fn_883296A0((ts4_word)a1, (ts4_word)(a0 + 104), (ts4_word)32);
    }
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 136));
    }
    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 140));
    }
    if ((ts4_word)a4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 184));
    }
    if ((ts4_word)a5 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 188));
    }
    return 0;
}

/* Swing_DLL.xex 0x8831D4D8: if_get u32@0xd4, u32@0x0 */
ts4_word ts4_if_get_u32_offd4_8831D4D8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 212));
    }
    return 0;
}

/* Swing_DLL.xex 0x8831D578: if_get u32@0x10c, u32@0x0 */
ts4_word ts4_if_get_u32_off10c_8831D578(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    if ((ts4_word)a1 != 0) {
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 260));
    }
    if ((ts4_word)a2 != 0) {
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 256));
    }
    if ((ts4_word)a3 != 0) {
        *(float *)((char *)(ts4_word)(a3) + 0) = (*(float *)((char *)(ts4_word)(a0) + 264));
    }
    if ((ts4_word)a4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 268));
    }
    return 0;
}

/* Swing_DLL.xex 0x8831D5C0: set u32@0xc0 */
ts4_word ts4_set_u32_offc0_8831D5C0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x8831D5D0: set u32@0x50 */
ts4_word ts4_set_u32_off50_8831D5D0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x8831D5E0: if_get u32@0x50, u32@0x0 */
ts4_word ts4_if_get_u32_off50_8831D5E0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80));
    return 0;
}

/* Swing_DLL.xex 0x8831DB88: if_get u32@0x14, fn_8831CBA8 */
ts4_word ts4_if_get_u32_off14_8831DB88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 == 0) {
        return 81;
    }
    return fn_8831CBA8((ts4_word)a0, (ts4_word)a1, (ts4_word)1, (ts4_word)0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8831E9B0: tailcall ts4_if_call_seq_u32_off11c_8831E730 */
ts4_word ts4_tailcall_fn_8831E730_8831E9B0(ts4_word a0)
{
    return ts4_if_call_seq_u32_off11c_8831E730((ts4_word)a0, (ts4_word)1);
}

/* Swing_DLL.xex 0x8831E9B8: get u32@0x0, u32@0x4c, vcall, fn_8831E890 */
ts4_word ts4_get_u32_off0_8831E9B8(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 76))))((ts4_word)a0);
    t4 = fn_8831E890((ts4_word)a0, (ts4_word)a1);
    return t4;
}

/* Swing_DLL.xex 0x8831F0C0: if_get u32@0x128, u32@0x0, u32@0x12c, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off128_8831F0C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 296));
    }
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 300));
    }
    if ((ts4_word)a3 == 0) {
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)16384;
    return 0;
}

/* Swing_DLL.xex 0x8831F0F8: if_call_seq u32@0x128, u32@0x14, u32@0x4b0, u32@0x4ac, fn_8832EDB0 */
ts4_word ts4_if_call_seq_u32_off128_8831F0F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 296);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 1200);
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 1196);
        p5 = (ts4_word)t3;
        if ((int)t3 < (int)t4) {
            p5 = (ts4_word)t4;
        }
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)16384, (ts4_word)(p5 << 16));
    }
    return 0;
}

/* Swing_DLL.xex 0x88320358: call_seq fn_8832AEE0, lbl_88028F78, u32@0x0, ts4_memset, u32@0x16c */
ts4_word ts4_call_seq_fn_8832AEE0_88320358(ts4_word a0)
{
    fn_8832AEE0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88028F78;
    ts4_memset((ts4_word)(a0 + 188), (ts4_word)0, (ts4_word)172);
    *(ts4_word *)((char *)(ts4_word)(a0) + 364) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x883204E0: if_call_seq u32@0x28, fn_883290D0, u32@0x28, u32@0x16c, lbl_88028F80, u32@lbl_88B3302C */
ts4_word ts4_if_call_seq_u32_off28_883204E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t1 != 0) {
        fn_883290D0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 364);
    if ((ts4_word)t4 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t4, (ts4_word)(ts4_word)lbl_88028F80, (ts4_word)126);
        *(ts4_word *)((char *)(ts4_word)(a0) + 364) = (ts4_word)0;
    }
    t9 = ts4_if_get_u32_offd8_8832AFB0((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x883207A8: if_call_seq u32@0x28, fn_883290D0, u32@0x28, u32@0x16c, lbl_88028FA0, u32@lbl_88B3302C */
ts4_word ts4_if_call_seq_u32_off28_883207A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t1 != 0) {
        fn_883290D0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 364);
    if ((ts4_word)t4 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t4, (ts4_word)(ts4_word)lbl_88028FA0, (ts4_word)142);
        *(ts4_word *)((char *)(ts4_word)(a0) + 364) = (ts4_word)0;
    }
    t9 = ts4_if_get_u32_offd8_8832AFB0((ts4_word)a0);
    return t9;
}

/* Swing_DLL.xex 0x88320828: fn  */
ts4_word ts4_fn_88320828(void)
{
    return 16;
}

/* Swing_DLL.xex 0x88320EE0: tailcall fn_883194F0 */
ts4_word ts4_tailcall_fn_883194F0_88320EE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_883194F0((ts4_word)a0, (ts4_word)a1, (ts4_word)1, (ts4_word)a2, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88320F18: set u32@0x2c4 */
ts4_word ts4_set_u32_off2c4_88320F18(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 708) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x88320F28: if_call_seq ts4_strlen_88329658, fn_883296A0 */
ts4_word ts4_if_call_seq_fn_88329658_88320F28(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t1;

    t1 = ts4_strlen_88329658((ts4_word)a1);
    if ((int)t1 >= 256) {
        p3 = (ts4_word)37;
    } else {
        fn_883296A0((ts4_word)(a0 + 1), (ts4_word)a1, (ts4_word)256);
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x88322810: if_call_seq fn_8832EDB0, u32@0x34, ts4_strlen_88329658, fn_8832EDB0 */
ts4_word ts4_if_call_seq_fn_8832EDB0_88322810(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)2048, (ts4_word)76);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_strlen_88329658((ts4_word)t2);
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)2, (ts4_word)(t3 + 1));
    }
    return 0;
}

/* Swing_DLL.xex 0x88322A48: set u32@0x0, u32@0x4, u32@0x10, u32@0x14, u8@0x28, u32@0x8 */
void ts4_set_u32_off0_88322A48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88322A78: call_seq fn_8831A830, u8@0x34 */
ts4_word ts4_call_seq_fn_8831A830_88322A78(ts4_word a0)
{
    fn_8831A830((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)1;
    return 0;
}

/* Swing_DLL.xex 0x88322BD8: if_get  */
ts4_word ts4_if_get_88322BD8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 36));
    return 0;
}

/* Swing_DLL.xex 0x88323F88: if_get u32@0x4c */
ts4_word ts4_if_get_u32_off4c_88323F88(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t1 == 0) {
        return 36;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 180));
    return 0;
}

/* Swing_DLL.xex 0x88323FC0: if_get u32@0x4c */
ts4_word ts4_if_get_u32_off4c_88323FC0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t1 == 0) {
        return 36;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 184));
    return 0;
}

/* Swing_DLL.xex 0x883257D8: if_get u32@0x4c, u32@0x0, u32@0x1c, u32@0x0 */
ts4_word ts4_if_get_u32_off4c_883257D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
        return 36;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 28));
    return 0;
}

/* Swing_DLL.xex 0x88325810: if_get u32@0x4c, u32@0x1a4 */
ts4_word ts4_if_get_u32_off4c_88325810(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t1 == 0) {
        return 36;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 420) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x88325930: if_get u32@0x4c, u32@0x20, u32@0x0 */
ts4_word ts4_if_get_u32_off4c_88325930(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    if ((ts4_word)t1 == 0) {
        return 36;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 32));
    return 0;
}

/* Swing_DLL.xex 0x88325A08: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_88325A08(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)32, (ts4_word)424);
    return 0;
}

/* Swing_DLL.xex 0x88326BF8: tailcall fn_88326940 */
ts4_word ts4_tailcall_fn_88326940_88326BF8(ts4_word a0, ts4_word a1)
{
    return fn_88326940((ts4_word)a0, (ts4_word)a1, (ts4_word)1, (ts4_word)0);
}

/* Swing_DLL.xex 0x88329028: set u32@0x14, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off14_88329028(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x883293D0: if_get u32@0x4, u32@0x0 */
ts4_word ts4_if_get_u32_off4_883293D0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    return 0;
}

/* Swing_DLL.xex 0x883293F0: if_get u32@0x8, u32@0x0 */
ts4_word ts4_if_get_u32_off8_883293F0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    return 0;
}

/* Swing_DLL.xex 0x883294B8: if_call_seq fn_8832EDB0, u32@0x14, u32@0x4, fn_8832EDB0 */
ts4_word ts4_if_call_seq_fn_8832EDB0_883294B8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)32, (ts4_word)24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t2 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)32, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) << 2));
    }
    return 0;
}

/* Swing_DLL.xex 0x88329528: set u32@0x1c0, u32@0x0 */
ts4_word ts4_set_u32_off1c0_88329528(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 448) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x88329578: if_get u32@0x14, u32@0x1c0, u32@0x1c0 */
ts4_word ts4_if_get_u32_off14_88329578(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 448) = (ts4_word)a1;
    if ((ts4_word)a1 > (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 448) = (ts4_word)t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x88329630: if_set u32@0x0 */
ts4_word ts4_if_set_u32_off0_88329630(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)17;
    return 0;
}

/* Swing_DLL.xex 0x8832BF80: call_seq lbl_8802924C, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_call_seq_lbl_8802924C_8832BF80(ts4_word a0)
{
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8802924C, (ts4_word)30);
    return 0;
}

/* Swing_DLL.xex 0x8832CC38: if_get u8@0x232, u8@0x0 */
ts4_word ts4_if_get_u8_off232_8832CC38(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 562));
    return 0;
}

/* Swing_DLL.xex 0x8832E800: get u32@0x78, u32@0x20, u32@0x78, fn_8832E508 */
ts4_word ts4_get_u32_off78_8832E800(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 120));
    return fn_8832E508((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 120)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x8832E878: call_seq fn_8832E690, u32@0x154, ts4_if_call_seq_lbl_88028EA4_8831ACF0, u32@0x154 */
ts4_word ts4_call_seq_fn_8832E690_8832E878(ts4_word a0)
{
    ts4_word t3;

    fn_8832E690((ts4_word)(a0 + 16));
    t3 = ts4_if_call_seq_lbl_88028EA4_8831ACF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 340)), (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 340) = (ts4_word)0;
    return t3;
}

/* Swing_DLL.xex 0x8832E8C0: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_8832E8C0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)(1048576), (ts4_word)360);
    return 0;
}

/* Swing_DLL.xex 0x8832F8F0: call_seq ts4_memset, u32@0xc0 */
ts4_word ts4_call_seq_ts4_memset_8832F8F0(ts4_word a0)
{
    ts4_memset((ts4_word)a0, (ts4_word)0, (ts4_word)192);
    *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8832FA48: if_get  */
ts4_word ts4_if_get_8832FA48(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 64));
    return 0;
}

/* Swing_DLL.xex 0x8832FD08: if_get u8@0x61, u8@0x0 */
ts4_word ts4_if_get_u8_off61_8832FD08(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 97));
    return 0;
}

/* Swing_DLL.xex 0x8832FDE0: if_get u8@0x60, u8@0x0 */
ts4_word ts4_if_get_u8_off60_8832FDE0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 96));
    return 0;
}

/* Swing_DLL.xex 0x883300B0: if_get u32@0x1c, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off1c_883300B0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
        return 16;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t1;
    return 0;
}

/* Swing_DLL.xex 0x88330258: if_get u32@0x38, u32@0x0 */
ts4_word ts4_if_get_u32_off38_88330258(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56));
    return 0;
}

/* Swing_DLL.xex 0x883302D0: if_call_seq fn_8832EDB0, u32@0x3c, ts4_strlen_88329658, fn_8832EDB0, u32@0x28, fn_8832EDB0 */
ts4_word ts4_if_call_seq_fn_8832EDB0_883302D0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t9;

    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)64, (ts4_word)100);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_strlen_88329658((ts4_word)t2);
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)2, (ts4_word)(t3 + 1));
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t6 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)64, (ts4_word)100);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t9 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)16384, (ts4_word)308);
    }
    return 0;
}

/* Swing_DLL.xex 0x88331660: call_seq ts4_fn_883E63B8 */
ts4_word ts4_call_seq_fn_883E63B8_88331660(ts4_word a0)
{
    ts4_fn_883E63B8((ts4_word)(a0 + 16));
    return 0;
}

/* Swing_DLL.xex 0x88332070: addr lbl_88029348, u32@0xc, u32@0x4, u32@0x8, u32@0x0, u32@0x10 */
void ts4_addr_lbl_88029348_88332070(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(a0 + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88029348;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88332928: tailcall fn_88318638 */
ts4_word ts4_tailcall_fn_88318638_88332928(ts4_word a0)
{
    return fn_88318638((ts4_word)(a0 + 12), (ts4_word)0);
}

/* Swing_DLL.xex 0x883330F0: if_call_seq fn_8831E890, u32@0x158, lbl_8802936C, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_if_call_seq_fn_8831E890_883330F0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_8831E890((ts4_word)a0, (ts4_word)0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 344);
    if ((ts4_word)t2 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t2, (ts4_word)(ts4_word)lbl_8802936C, (ts4_word)98);
        *(ts4_word *)((char *)(ts4_word)(a0) + 344) = (ts4_word)0;
    }
    if ((ts4_word)(a1 & 0xff) != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8802936C, (ts4_word)121);
    }
    return 0;
}

/* Swing_DLL.xex 0x88333170: fn  */
ts4_word ts4_fn_88333170(void)
{
    return 14;
}

/* Swing_DLL.xex 0x883331E0: if_call_seq fn_8831DAC0, u32@0x138, u32@0x16c, u32@0x170, u32@0x17c, u64@0x150 */
ts4_word ts4_if_call_seq_fn_8831DAC0_883331E0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8831DAC0();
    if ((int)t1 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 312) = (ts4_word)a1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 364) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 368) = (ts4_word)-1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)2;
        *(ts4_u64 *)((char *)(ts4_word)(a0) + 336) = (ts4_u64)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 316) = (ts4_word)0;
    }
    return t1;
}

/* Swing_DLL.xex 0x88333F88: addr lbl_880293EC, u32@0x8, u32@0x0, u32@0xc, u32@0x10, u32@0x14 */
void ts4_addr_lbl_880293EC_88333F88(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880293EC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88334230: if_call_seq u32@0x10, lbl_880293F4, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off10_88334230(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_880293F4, (ts4_word)234);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t6 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t6, (ts4_word)(ts4_word)lbl_880293F4, (ts4_word)239);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x883342A8: if_call_seq u32@0x14, u32@0x8, u32@0xc, fn_8832EDB0, u32@0xc, fn_8832EDB0 */
ts4_word ts4_if_call_seq_u32_off14_883342A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)32, (ts4_word)((int)t2 * (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 12))));
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)32, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) << 3));
    }
    return 0;
}

/* Swing_DLL.xex 0x88334890: if_get u32@0x44, u32@0x108, fn_88377118, u32@0x44, ts4_if_get_u32_off108_88376FC0, u32@0x104 */
ts4_word ts4_if_get_u32_off44_88334890(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 264);
    if ((ts4_word)t2 == 0) {
        return 20;
    }
    t3 = fn_88377118((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)2);
    loc50[0] = (ts4_word)a2;
    ts4_if_get_u32_off108_88376FC0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 68)), (ts4_word)(ts4_word)&loc50[0], (ts4_word)2);
    t6 = loc50[0];
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 260);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t6;
    if ((ts4_word)t7 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(t7))((ts4_word)a0, (ts4_word)a1, (ts4_word)t6, (ts4_word)2);
    }
    return t3;
}

/* Swing_DLL.xex 0x88334920: if_get u32@0xc0, u32@0x0 */
ts4_word ts4_if_get_u32_offc0_88334920(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 192));
    return 0;
}

/* Swing_DLL.xex 0x88334940: fn  */
ts4_word ts4_fn_88334940(void)
{
    return 2;
}

/* Swing_DLL.xex 0x883349D0: if_get u32@0x58, u32@0x0 */
ts4_word ts4_if_get_u32_off58_883349D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    if ((ts4_word)a1 != 0) {
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 80));
    }
    if ((ts4_word)a2 != 0) {
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 76));
    }
    if ((ts4_word)a3 != 0) {
        *(float *)((char *)(ts4_word)(a3) + 0) = (*(float *)((char *)(ts4_word)(a0) + 84));
    }
    if ((ts4_word)a4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88));
    }
    return 0;
}

/* Swing_DLL.xex 0x88334A50: if_get  */
ts4_word ts4_if_get_88334A50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a1 != 0) {
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 96));
    }
    if ((ts4_word)a2 != 0) {
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 100));
    }
    if ((ts4_word)a3 != 0) {
        *(float *)((char *)(ts4_word)(a3) + 0) = (*(float *)((char *)(ts4_word)(a0) + 104));
    }
    return 0;
}

/* Swing_DLL.xex 0x88334AC8: if_get  */
ts4_word ts4_if_get_88334AC8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 != 0) {
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 108));
    }
    if ((ts4_word)a2 != 0) {
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 112));
    }
    return 0;
}

/* Swing_DLL.xex 0x88334B80: if_get  */
ts4_word ts4_if_get_88334B80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a1 != 0) {
        *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 116));
    }
    if ((ts4_word)a2 != 0) {
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 120));
    }
    if ((ts4_word)a3 != 0) {
        *(float *)((char *)(ts4_word)(a3) + 0) = (*(float *)((char *)(ts4_word)(a0) + 124));
    }
    return 0;
}

/* Swing_DLL.xex 0x88334C38: if_get u32@0x80, u32@0x0, u32@0x84, u32@0x0 */
ts4_word ts4_if_get_u32_off80_88334C38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128));
    }
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 132));
    }
    return 0;
}

/* Swing_DLL.xex 0x88335300: if_get u32@0x90, u32@0x0 */
ts4_word ts4_if_get_u32_off90_88335300(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 144));
    return 0;
}

/* Swing_DLL.xex 0x883356D8: if_get u32@0xe0, u32@0x0 */
ts4_word ts4_if_get_u32_offe0_883356D8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 224));
    return 0;
}

/* Swing_DLL.xex 0x88335860: if_set u32@0x0, u32@0x0, u32@0x94 */
ts4_word ts4_if_set_u32_off0_88335860(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    if ((ts4_word)a4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
    }
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 148))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
}

/* Swing_DLL.xex 0x88335AA8: if_get u32@0x20, u32@0x0 */
ts4_word ts4_if_get_u32_off20_88335AA8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32));
    return 0;
}

/* Swing_DLL.xex 0x88335AC8: if_set u32@0x3c */
ts4_word ts4_if_set_u32_off3c_88335AC8(ts4_word a0, ts4_word a1)
{
    if ((int)a1 < -1) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x88335AE8: set u32@0x28 */
ts4_word ts4_set_u32_off28_88335AE8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x88335AF8: if_get u32@0x28, u32@0x0 */
ts4_word ts4_if_get_u32_off28_88335AF8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40));
    return 0;
}

/* Swing_DLL.xex 0x88335C40: set u32@0xb8 */
ts4_word ts4_set_u32_offb8_88335C40(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x88335C50: if_get u32@0xb8, u32@0x0 */
ts4_word ts4_if_get_u32_offb8_88335C50(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 184));
    return 0;
}

/* Swing_DLL.xex 0x88335C70: set u32@0xbc */
ts4_word ts4_set_u32_offbc_88335C70(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)a1;
    return 0;
}

/* Swing_DLL.xex 0x88335C80: if_get u32@0xbc, u32@0x0 */
ts4_word ts4_if_get_u32_offbc_88335C80(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 37;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 188));
    return 0;
}

/* Swing_DLL.xex 0x88339B48: tailcall ts4_if_call_seq_lbl_88028B5C_88339B50 */
ts4_word ts4_tailcall_fn_88339B50_88339B48(ts4_word a0)
{
    return ts4_if_call_seq_lbl_88028B5C_88339B50((ts4_word)(a0 + -360));
}

/* Swing_DLL.xex 0x8833A0D0: set u32@0x0 */
ts4_word ts4_set_u32_off0_8833A0D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)a2;
    return 0;
}

/* Swing_DLL.xex 0x8833A4F8: if_call_seq u32@0x14, u32@0x4bc, fn_88396320, fn_88397970 */
ts4_word ts4_if_call_seq_u32_off14_8833A4F8(ts4_word a0)
{
    ts4_word t3;

    t3 = fn_88396320((ts4_word)(a0 + 312), (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 1212)));
    if ((int)t3 != 0) {
        return 44;
    }
    fn_88397970((ts4_word)(a0 + 312));
    return 0;
}

/* Swing_DLL.xex 0x88340780: if_call_seq fn_8832EDB0 */
ts4_word ts4_if_call_seq_fn_8832EDB0_88340780(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 49480));
    if ((ts4_word)t1 != 0) {
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)16384, (ts4_word)((int)(*(ts4_word *)((char *)(ts4_word)(a0) + ((0) | 49488))) * (int)((65536) | 16444)));
    }
    return 0;
}

/* Swing_DLL.xex 0x8834DAC0: fn  */
ts4_word ts4_fn_8834DAC0(void)
{
    return 25;
}

/* Swing_DLL.xex 0x88350490: if_call_seq u32@0x124, lbl_8802B0B4, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0xe4 */
ts4_word ts4_if_call_seq_u32_off124_88350490(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t11;
    ts4_word t13;
    ts4_word t20;
    ts4_word t21;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 292);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8802B0B4, (ts4_word)867);
        *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((ts4_word)t6 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t6, (ts4_word)(ts4_word)lbl_8802B0B4, (ts4_word)872);
        *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 276);
    if ((ts4_word)t11 != 0) {
        t13 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 272))) + 18616);
        if ((ts4_word)t13 != 0) {
            fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t13, (ts4_word)(ts4_word)lbl_8802B0B4, (ts4_word)879);
            *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 272))) + 18616) = (ts4_word)0;
        }
        t20 = *(ts4_word *)lbl_88B3302C;
        t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 276);
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t20) + 4)), (ts4_word)t21, (ts4_word)(ts4_word)lbl_8802B0B4, (ts4_word)883);
        *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88360E28: if_call_seq lbl_88B3AA40, fn_883A3000, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_88B3AA40_88360E28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{

    if ((ts4_word)a2 == (ts4_word)(ts4_word)lbl_88B3AA40) {
        fn_883A3000((ts4_word)a0, (ts4_word)a1, (ts4_word)a3, (ts4_word)a4, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)lbl_88B3AA40);
    } else {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)a2;
    }
    if ((ts4_word)a4 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)a2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8836B608: if_call_seq u32@0x108, fn_88319E00, u64@0x0 */
ts4_word ts4_if_call_seq_u32_off108_8836B608(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    t2 = fn_88319E00((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 264)), (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 == 0) {
        t3 = loc50[0];
        *(ts4_u64 *)((char *)(ts4_word)(a1) + 0) = (ts4_u64)t3;
        return t2;
    }
    return 1;
}

/* Swing_DLL.xex 0x8836B668: if_get u32@0x108, u32@0x0, u32@0xc, vcall, u64@0x0 */
ts4_word ts4_if_get_u32_off108_8836B668(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 264);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t4 == 0) {
        t5 = loc50[0];
        *(ts4_u64 *)((char *)(ts4_word)(a1) + 0) = (ts4_u64)t5;
        return t4;
    }
    return 1;
}

/* Swing_DLL.xex 0x8836B8A0: if_call_seq u32@0x114, lib2_FLAC__stream_decoder_finish_883A5320, u32@0x114, fn_883A69B0, u32@0x114, u32@0xe8 */
ts4_word ts4_if_call_seq_u32_off114_8836B8A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;
    ts4_word t11;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 276);
    if ((ts4_word)t1 != 0) {
        lib2_FLAC__stream_decoder_finish_883A5320((ts4_word)a0, (ts4_word)t1);
        fn_883A69B0((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 276)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 276) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 232);
    if ((ts4_word)t6 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t6, (ts4_word)(ts4_word)lbl_8802B7FC, (ts4_word)578);
        *(ts4_word *)((char *)(ts4_word)(a0) + 232) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    *(ts4_word *)((char *)(ts4_word)(a0) + 240) = (ts4_word)0;
    if ((ts4_word)t11 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t11, (ts4_word)(ts4_word)lbl_8802B7FC, (ts4_word)585);
        *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x8836CE28: call_seq fn_88319E00 */
ts4_word ts4_call_seq_fn_88319E00_8836CE28(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t2;

    fn_88319E00((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc50[0];
    return t2;
}

/* Swing_DLL.xex 0x88374A00: set u32@0x0 */
ts4_word ts4_set_u32_off0_88374A00(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)1;
    return 0;
}

/* Swing_DLL.xex 0x88374A10: call_seq lbl_8802BA10, fn_883296A0 */
ts4_word ts4_call_seq_lbl_8802BA10_88374A10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a0;
    (void)a1;
    fn_883296A0((ts4_word)a2, (ts4_word)(ts4_word)lbl_8802BA10, (ts4_word)a3);
    return 0;
}

/* Swing_DLL.xex 0x88374A48: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_88374A48(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0)) | 252);
    return 0;
}

/* Swing_DLL.xex 0x88374E88: call_seq fn_88336050, lbl_8802BAA0, u32@0xac, u32@0x0, u8@0xb4 */
ts4_word ts4_call_seq_fn_88336050_88374E88(ts4_word a0)
{
    fn_88336050((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8802BAA0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 180) = (unsigned char)1;
    return a0;
}

/* Swing_DLL.xex 0x88374ED8: fn  */
ts4_word ts4_fn_88374ED8(void)
{
    return 77;
}

/* Swing_DLL.xex 0x88375358: call_seq fn_8832EDB0, fn_88335DF8 */
ts4_word ts4_call_seq_fn_8832EDB0_88375358(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)512, (ts4_word)16);
    t2 = fn_88335DF8((ts4_word)a0, (ts4_word)a1);
    return t2;
}

/* Swing_DLL.xex 0x88376810: if_call_seq u32@0x14, lbl_8802BB80, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x14 */
ts4_word ts4_if_call_seq_u32_off14_88376810(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8802BB80, (ts4_word)90);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t6 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t6, (ts4_word)(ts4_word)lbl_8802BB80, (ts4_word)98);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    }
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8802BB80, (ts4_word)102);
    return 0;
}

/* Swing_DLL.xex 0x88378BD8: get u32@0x0, u32@0x54 */
ts4_word ts4_get_u32_off0_88378BD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 84))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x883796C8: if_get fn_883ACE00, u32@0x18, u32@0x0, u32@0xac, vcall */
ts4_word ts4_if_get_fn_883ACE00_883796C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_883ACE00((ts4_word)a0);
    if ((int)t1 == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 172))))((ts4_word)t2, (ts4_word)a1, (ts4_word)2, (ts4_word)((a1 + a2) + -1), (ts4_word)2);
    }
    return 0;
}

/* Swing_DLL.xex 0x88379720: if_get ts4_set_u32_off34_883ACE40, u32@0x18, u32@0x0, u32@0xa4, vcall */
ts4_word ts4_if_get_fn_883ACE40_88379720(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_set_u32_off34_883ACE40((ts4_word)a0, (ts4_word)a1);
    if ((int)t1 == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 164))))((ts4_word)t2, (ts4_word)a1);
    }
    return 0;
}

/* Swing_DLL.xex 0x883799D8: get u8@0x5c, u8@0x0 */
ts4_word ts4_get_u8_off5c_883799D8(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a0) + 92)) == 0);
    return 0;
}

/* Swing_DLL.xex 0x883799F0: get u32@0x80, u32@0x0, u32@0x8c */
ts4_word ts4_get_u32_off80_883799F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 140))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88379A08: get u32@0x80, u32@0x0, u32@0x90 */
ts4_word ts4_get_u32_off80_88379A08(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 144))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88379A20: get u32@0x80, u32@0x0, u32@0x94 */
ts4_word ts4_get_u32_off80_88379A20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 148))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8837AA48: call_seq lbl_8802BDD8, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_call_seq_lbl_8802BDD8_8837AA48(ts4_word a0)
{
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8802BDD8, (ts4_word)74);
    return 0;
}

/* Swing_DLL.xex 0x8837AD28: call_seq lbl_8802BE04, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_call_seq_lbl_8802BE04_8837AD28(ts4_word a0)
{
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8802BE04, (ts4_word)75);
    return 0;
}

/* Swing_DLL.xex 0x8837B080: call_seq lbl_8802BE30, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_call_seq_lbl_8802BE30_8837B080(ts4_word a0)
{
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8802BE30, (ts4_word)73);
    return 0;
}

/* Swing_DLL.xex 0x8837B338: if_call_seq u32@0x18, lbl_8802BE58, u32@lbl_88B3302C, u32@0x4, fn_88315F10, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off18_8837B338(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t1 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t1, (ts4_word)(ts4_word)lbl_8802BE58, (ts4_word)104);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t6 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t6, (ts4_word)(ts4_word)lbl_8802BE58, (ts4_word)110);
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    }
    fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a0, (ts4_word)(ts4_word)lbl_8802BE58, (ts4_word)116);
    return 0;
}

/* Swing_DLL.xex 0x8837FF48: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_8837FF48(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)8192, (ts4_word)156);
    return 0;
}

/* Swing_DLL.xex 0x883810C8: if_get u8@0x6d0, fn_88318550, u32@0x2a4, u32@0x0, u32@0x8, vcall */
ts4_word ts4_if_get_u8_off6d0_883810C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char t1;
    ts4_word t4;
    ts4_word t9;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 1744);
    if ((ts4_word)t1 != 0) {
        fn_88318550((ts4_word)(a0 + 1448));
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 676);
    if ((ts4_word)t4 != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 8))))((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 676) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 672) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 680) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 684) = (ts4_word)0;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 724);
    if ((ts4_word)t9 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t9, (ts4_word)(ts4_word)lbl_8802BE90, (ts4_word)396);
        *(ts4_word *)((char *)(ts4_word)(a0) + 724) = (ts4_word)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88381458: if_get u8@0x50, lbl_88C922E4, u32@lbl_88C922E4, u32@0x4, u32@0x8, u32@0xc */
ts4_word ts4_if_get_u8_off50_88381458(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t1 != 0) {
        return 0;
    }
    *(ts4_word *)lbl_88C922E4 = (ts4_word)(67108864);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C922E4) + 4) = (ts4_word)((67108864) | 1);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C922E4) + 8) = (ts4_word)((67108864) | 2);
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C922E4) + 12) = (ts4_word)((67108864) | 3);
    *(unsigned char *)((char *)(ts4_word)(a0) + 80) = (unsigned char)1;
    *(unsigned char *)lbl_88C922F4 = (unsigned char)1;
    return 0;
}

/* Swing_DLL.xex 0x88381850: if_get u32@0x0, u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_88381850(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a0;
    (void)a1;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(t1 | 4252);
    }
    if ((ts4_word)a3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    }
    if ((ts4_word)a4 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)((0) | 48000);
    }
    if ((ts4_word)a5 == 0) {
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)5;
    return 0;
}

/* Swing_DLL.xex 0x88382750: tailcall fn_88381F90 */
ts4_word ts4_tailcall_fn_88381F90_88382750(ts4_word a0)
{
    return fn_88381F90((ts4_word)a0);
}

/* Swing_DLL.xex 0x88383308: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_88383308(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)((0) | 32768), (ts4_word)29656);
    return 0;
}

/* Swing_DLL.xex 0x88383340: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_88383340(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)((0) | 32768), (ts4_word)2288);
    return 0;
}

/* Swing_DLL.xex 0x88383378: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_88383378(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)((0) | 32768), (ts4_word)10728);
    return 0;
}

/* Swing_DLL.xex 0x883833B0: call_seq fn_8832EDB0 */
ts4_word ts4_call_seq_fn_8832EDB0_883833B0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)((0) | 32768), (ts4_word)11504);
    return 0;
}
