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
extern char lbl_880D1F0C[];
extern char lbl_880D3BA8[];
extern char lbl_880E196C[];
extern char lbl_880E7620[];
extern char lbl_880F20E8[];
extern char lbl_880F7940[];
extern char lbl_880F7AEC[];
extern char lbl_880F7B28[];
extern char lbl_880F7C10[];
extern char lbl_880F7D28[];
extern char lbl_880F7DB0[];
extern char lbl_880F7EA0[];
extern char lbl_880F7F38[];
extern char lbl_880F80D0[];
extern char lbl_880F81C0[];
extern char lbl_880F8280[];
extern char lbl_880F83C0[];
extern char lbl_880F86A8[];
extern char lbl_880F8748[];
extern char lbl_880F8888[];
extern char lbl_880F89A0[];
extern char lbl_880F8A40[];
extern char lbl_880F8BF4[];
extern char lbl_880F8C44[];
extern char lbl_880F8CF8[];
extern char lbl_880F8D28[];
extern char lbl_88C4589D[];
extern char lbl_88D41F80[];
extern char lbl_88D41FC0[];
extern char lbl_88D4528C[];
extern char lbl_88D45290[];
extern char lbl_88D45930[];
extern char lbl_88D45B06[];
extern char lbl_88D45B14[];
extern char lbl_88D45B18[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B2C[];
extern char lbl_88D45B38[];
ts4_word RtlInitializeCriticalSection();
ts4_word fn_88150310();
ts4_word fn_881506A0();
ts4_word fn_88152DF8();
ts4_word ts4_if_call_seq_u32_off8_88160D30();
ts4_word fn_881705B0();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_88198CE0();
ts4_word fn_881A4F30();
ts4_word fn_881A5088();
ts4_word fn_881A50F0();
ts4_word fn_881B9148();
ts4_word fn_88280A50();
ts4_word fn_88280E60();
ts4_word fn_883C6460();
ts4_word fn_883CB4A0();
ts4_word fn_883CB4F0();
ts4_word fn_8857A1E0();
ts4_word fn_8857A720();
ts4_word fn_8857A8A0();
ts4_word fn_88606788();
ts4_word fn_88608590();
ts4_word fn_88609F90();
ts4_word fn_8860BBD8();
ts4_word fn_8860C128();
ts4_word fn_8860D250();
ts4_word ts4_loop_call_seq_RtlEnterCriticalSection_8860D8E8();
ts4_word fn_8860DCF8();
ts4_word fn_8860FA68();
ts4_word fn_8860FF08();
ts4_word fn_88613268();
ts4_word fn_88613418();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_88618998();
ts4_word ts4_if_call_seq_u8_off68_886195A0();
ts4_word fn_88619628();
ts4_word fn_886197F0();
ts4_word fn_8861A720();
ts4_word fn_8861AA20();
ts4_word fn_8861B128();
ts4_word fn_8861B4D8();
ts4_word ts4_if_call_seq_u8_off824_8861B790();
ts4_word fn_8861B8E0();
ts4_word fn_8861C4F0();
ts4_word fn_8861C830();
ts4_word fn_8861E938();
ts4_word fn_88625478();
ts4_word fn_88625798();
ts4_word ts4_name_keys_register_88626F70();
ts4_word fn_88627B30();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88628E70();
ts4_word fn_8862BB50();
ts4_word fn_8862BE08();
ts4_word fn_8862C0E8();
ts4_word fn_8862C210();
ts4_word fn_8862CC90();
ts4_word fn_8862E858();
ts4_word fn_886328B0();
ts4_word fn_886376E0();
ts4_word fn_886378F0();
ts4_word fn_88637BF0();
ts4_word fn_88637F10();
ts4_word fn_88638100();
ts4_word fn_88638188();
ts4_word fn_88638210();
ts4_word fn_88638418();
ts4_word fn_88638770();
ts4_word fn_88638918();
ts4_word fn_8863A8F0();
ts4_word fn_8863AA58();
ts4_word fn_8863AE08();
ts4_word fn_8863B6E8();
ts4_word fn_8863B7B8();
ts4_word fn_8863B9F0();
ts4_word fn_8863DC80();
ts4_word fn_8863DF58();
ts4_word fn_8863EF50();
ts4_word ts4_if_call_seq_fn_88162BB8_8863EFF0();
ts4_word fn_8863F068();
ts4_word fn_8863F858();
ts4_word fn_88640150();
ts4_word fn_88640968();
ts4_word fn_886412C0();
ts4_word fn_88641970();
ts4_word fn_88641A58();
ts4_word fn_88644138();
ts4_word fn_88883CD0();
ts4_word fn_888860A0();
ts4_word fn_88888338();
ts4_word fn_888D7230();
ts4_word fn_888D72F0();
ts4_word fn_888DF110();
ts4_word fn_8892AF80();
ts4_word fn_8892EB28();
ts4_word ts4_if_call_seq_u32_off8_8892ED88();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_assign_text_from_c_string();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x8860D608: if_call_seq fn_88883CD0, u8@0x0 */
ts4_word ts4_if_call_seq_fn_88883CD0_8860D608(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t1) + 0) = (unsigned char)a0;
    }
    return t1;
}

/* Swing_DLL.xex 0x8860D648: call_seq lbl_880F7AEC, u32@0x0, u32@lbl_88D45B38, fn_8860D250, u32@0x4, u32@0x8 */
ts4_word ts4_call_seq_lbl_880F7AEC_8860D648(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7AEC;
    t2 = fn_8860D250((ts4_word)(*(ts4_word *)lbl_88D45B38));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return a0;
}

/* Swing_DLL.xex 0x8860D6A0: call_seq lbl_880F7AEC, u32@0x0, u32@lbl_88D45B38, fn_8860D250, u32@0x4, u32@0x8 */
ts4_word ts4_call_seq_lbl_880F7AEC_8860D6A0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7AEC;
    t2 = fn_8860D250((ts4_word)(*(ts4_word *)lbl_88D45B38));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return a0;
}

/* Swing_DLL.xex 0x8860D9D0: get u32@0x184 */
ts4_word ts4_get_u32_off184_8860D9D0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 388));
}

/* Swing_DLL.xex 0x8860DB28: set u8@0x170 */
void ts4_set_u8_off170_8860DB28(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 368) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8860DB38: set u8@0x170 */
void ts4_set_u8_off170_8860DB38(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 368) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8860E0A0: fn  */
ts4_word ts4_fn_8860E0A0(ts4_word a0)
{
    return (a0 + 36);
}

/* Swing_DLL.xex 0x8860E0A8: get u32@lbl_88D45B1C, u32@0x224, u32@0x0, u32@0x28, vcall, u32@0x0 */
ts4_word ts4_get_u32_lbl_88D45B1C_8860E0A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 548);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t2, (ts4_word)a1, (ts4_word)33, (ts4_word)a2);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t7 = loc50[0];
    t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t6) + 92))))((ts4_word)a0, (ts4_word)t7, (ts4_word)a1, (ts4_word)a2);
    return t9;
}

/* Swing_DLL.xex 0x8860E178: get u32@0x2c, u32@0x4c */
ts4_word ts4_get_u32_off2c_8860E178(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 76))))((ts4_word)(a0 + 44), (ts4_word)0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8860E2C8: get u32@0x2dd0, u32@0x4, vcall, u32@0x2dd0, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off2dd0_8860E2C8(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 11728))) + 4))))((ts4_word)(a1 + 11728));
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 11728);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t4) + 8))))((ts4_word)(a1 + 11728));
    return a0;
}

/* Swing_DLL.xex 0x8860E4F8: get u32@0x24, u32@0x0, u32@0x44 */
ts4_word ts4_get_u32_off24_8860E4F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 68))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8860E510: get u32@0x24, u32@0x0, u32@0x40 */
ts4_word ts4_get_u32_off24_8860E510(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 64))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8860E528: get u32@0x24, u32@0x0, u32@0x3c */
ts4_word ts4_get_u32_off24_8860E528(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 60))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8860E540: get u32@0x24, u32@0x0, u32@0x30, vcall */
ts4_word ts4_get_u32_off24_8860E540(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 48))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8860E580: get u32@0x24, u32@0x0, u32@0x34, vcall */
ts4_word ts4_get_u32_off24_8860E580(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 52))))((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8860ED60: get u32@0x4, u32@0x0, u32@0x58, vcall */
ts4_word ts4_get_u32_off4_8860ED60(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;

    loc50[0] = (ts4_word)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 88))))((ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    return t4;
}

/* Swing_DLL.xex 0x8860EE68: get u32@0x18 */
ts4_word ts4_get_u32_off18_8860EE68(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

/* Swing_DLL.xex 0x8860EED0: set u32@0x4, u32@0x8, lbl_880F7D28, u32@0x18, u32@0xc, u32@0x0 */
void ts4_set_u32_off4_8860EED0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7D28;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8860EF80: set u32@0x4, u32@0x8, lbl_880F7DB0, u32@0x18, u32@0xc, u32@0x0 */
void ts4_set_u32_off4_8860EF80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7DB0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 21) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 540) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 544) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 548) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 552) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 556) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 560) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 564) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 568) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 572) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 576) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 580) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8860EFF0: set u8@0x0, u32@0x4, u8@0x1 */
void ts4_set_u8_off0_8860EFF0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 1) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8860F510: if_call_seq u32@0x0, fn_886328B0 */
ts4_word ts4_if_call_seq_u32_off0_8860F510(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p4 = (ts4_word)0;
    if ((int)t1 != -1) {
        t2 = fn_886328B0((ts4_word)(t1 + a0));
        p4 = (ts4_word)((t2 & 0xff) == 0);
    }
    return p4;
}

/* Swing_DLL.xex 0x8860F608: get u32@0x0, u32@0x14, u32@0x10, u32@0x4 */
void ts4_get_u32_off0_8860F608(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)7;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x8860F620: get u32@0x0, u32@0x0, u32@0x14, u32@0x10, u32@0x0, u32@0x4 */
void ts4_get_u32_off0_8860F620(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)6;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x8860F640: get u32@0x0, u32@0x0, u32@0x14, u32@0x10, u32@0x0, u32@0x8 */
void ts4_get_u32_off0_8860F640(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t2;
    return;
}

/* Swing_DLL.xex 0x8860F660: get u32@0x0, u32@0x14, u32@0x10, u32@0x18, u32@0x0 */
void ts4_get_u32_off0_8860F660(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x8860F680: get u32@0x0, u32@0x14, u32@0x10, u32@0x0 */
void ts4_get_u32_off0_8860F680(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    return;
}

/* Swing_DLL.xex 0x8860F698: set u32@0xc */
void ts4_set_u32_offc_8860F698(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x8860F998: if_get u32@lbl_88D45B1C, u32@0x224, u32@0x0, u32@0x28, vcall, fn_88609F90 */
ts4_word ts4_if_get_u32_lbl_88D45B1C_8860F998(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p3;
    ts4_word p14;
    ts4_word loc50[1];
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    if ((ts4_word)a3 != 0) {
        p3 = (ts4_word)a3;
    } else {
        p3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 548));
    }
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p3) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)p3, (ts4_word)a1, (ts4_word)1025, (ts4_word)0);
    t7 = loc50[0];
    if ((ts4_word)t7 != 0) {
        t8 = fn_88609F90((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
        t9 = loc50[0];
        t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 88))))((ts4_word)t10, (ts4_word)(ts4_word)&loc50[0]);
        p14 = (ts4_word)t8;
    } else {
        p14 = (ts4_word)((983040) | 65535);
    }
    return p14;
}

/* Swing_DLL.xex 0x8860FE28: get u32@0x0, u32@0x28, vcall, fn_881506A0 */
ts4_word ts4_get_u32_off0_8860FE28(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0]);
    fn_881506A0((ts4_word)a0, (ts4_word)t3);
    return a0;
}

/* Swing_DLL.xex 0x8860FE78: set u32@0x8, u32@0x0, u32@0x4 */
void ts4_set_u32_off8_8860FE78(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(a1 + 96);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8860FFC0: set u32@0x0, u32@0x8, u32@0x4, u32@0xc, u32@0xc, u32@0x0 */
void ts4_set_u32_off0_8860FFC0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    return;
}

/* Swing_DLL.xex 0x88610000: call_seq u32@0x0, u32@0x8, u32@0x4, fn_8860FF08 */
ts4_word ts4_call_seq_u32_off0_88610000(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    fn_8860FF08((ts4_word)a0, (ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x88610048: set u32@0x0, u32@0x8, u32@0x4, u32@0xc */
void ts4_set_u32_off0_88610048(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x88610098: get u32@0x0, u32@0x4, vcall, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_88610098(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc58[3];
    ts4_word loc50[1];
    ts4_word t3;

    (void)a1;
    loc58[0] = (ts4_word)a0;
    loc58[1] = (ts4_word)a2;
    loc58[2] = (ts4_word)0;
    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc58[0]);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    return t3;
}

/* Swing_DLL.xex 0x886101F0: call_seq u32@0x0, u32@0x4, u32@0x8, u32@0x4, u32@0x4, fn_88609F90 */
ts4_word ts4_call_seq_u32_off0_886101F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    t3 = fn_88609F90((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)), (ts4_word)a3, (ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t3;
    return a0;
}

/* Swing_DLL.xex 0x886102B0: set u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off0_886102B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    *(ts4_word *)((char *)(ts4_word)(a7) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a7) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a7) + 4) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x886102D0: set u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off0_886102D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a4) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a4) + 4) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x886102F0: call_seq u32@0x0, u32@0x4, u32@0x4, fn_8860FA68, u32@0x4 */
ts4_word ts4_call_seq_u32_off0_886102F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = fn_8860FA68((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a2, (ts4_word)t1, (ts4_word)1, (ts4_word)0, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)t3;
    return t3;
}

/* Swing_DLL.xex 0x886108F8: call_seq u32@0x0, u32@0x8, u32@0x4, u32@0xc, fn_8860FF08 */
ts4_word ts4_call_seq_u32_off0_886108F8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((983040) | 65535);
    fn_8860FF08((ts4_word)a0, (ts4_word)a1);
    return a0;
}

/* Swing_DLL.xex 0x886111A0: call_seq ts4_object_finalize, ts4_object_finalize */
ts4_word ts4_call_seq_ts4_object_finalize_886111A0(ts4_word a0)
{
    ts4_word t2;

    ts4_object_finalize((ts4_word)(a0 + 20));
    t2 = ts4_object_finalize((ts4_word)(a0 + 8));
    return t2;
}

/* Swing_DLL.xex 0x886111D8: get u32@0x4, u32@0x2c, u32@0xc */
ts4_word ts4_get_u32_off4_886111D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    return ((*(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 44)) + (a2 << 4))) + 12)) & 0x1f);
}

/* Swing_DLL.xex 0x88611618: get u32@0x0, ts4_find_service */
ts4_word ts4_get_u32_off0_88611618(ts4_word a0)
{
    return ts4_find_service((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x88611E28: get u32@lbl_88D45B1C, u32@0x2b8, fn_8860C128 */
ts4_word ts4_get_u32_lbl_88D45B1C_88611E28(void)
{
    return fn_8860C128((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 696)));
}

/* Swing_DLL.xex 0x88613040: set u8@0x189 */
void ts4_set_u8_off189_88613040(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 393) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886135E8: if_call_seq u32@0x4, u32@lbl_88D45B38, fn_88883CD0, u32@0xc, u8@0x20 */
ts4_word ts4_if_call_seq_u32_off4_886135E8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)lbl_88D45B38;
    t3 = fn_88883CD0((ts4_word)0);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)t1;
    }
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t2) + 32) = (unsigned char)0;
    }
    return t3;
}

/* Swing_DLL.xex 0x88613858: call_seq fn_88606788, ts4_loop_call_seq_RtlEnterCriticalSection_8860D8E8 */
ts4_word ts4_call_seq_fn_88606788_88613858(ts4_word a0)
{
    ts4_word t2;

    fn_88606788((ts4_word)a0);
    t2 = ts4_loop_call_seq_RtlEnterCriticalSection_8860D8E8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x88613EA0: if_get u8@0x25, u32@0x40 */
void ts4_if_get_u8_off25_88613EA0(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 37);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88614300: get u32@0x148c, u32@0x4, vcall, u8@0x0, u32@0x4, u8@0x1 */
ts4_word ts4_get_u32_off148c_88614300(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 5260))) + 4))))((ts4_word)(a0 + 5260));
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 1) = (unsigned char)0;
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 5260))) + 8))))((ts4_word)(a0 + 5260));
    return t6;
}

/* Swing_DLL.xex 0x88614358: set u8@0x14d0 */
void ts4_set_u8_off14d0_88614358(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 5328) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88614368: set u8@0x14d0 */
void ts4_set_u8_off14d0_88614368(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 5328) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88614378: if_call_seq u32@0x210, u32@0x0, u8@0x234, u32@0x22c, u32@0x8, u32@0x214 */
ts4_word ts4_if_call_seq_u32_off210_88614378(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 528);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 564) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 556) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 532) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 536) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 544) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 548) = (ts4_word)0;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8857A1E0((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 528) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x88618858: call_seq u32@lbl_88D45B38, fn_88613418, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_u32_lbl_88D45B38_88618858(ts4_word a0)
{
    ts4_word t3;

    fn_88613418((ts4_word)(*(ts4_word *)lbl_88D45B38));
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t3 = fn_881B9148((ts4_word)(a0 + 16));
    return t3;
}

/* Swing_DLL.xex 0x88618B68: call_seq lbl_880F7AEC, u32@0x0, u32@lbl_88D45B38, fn_8860D250, u32@0x4, u32@0x0 */
ts4_word ts4_call_seq_lbl_880F7AEC_88618B68(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7AEC;
    t1 = *(ts4_word *)lbl_88D45B38;
    t2 = fn_8860D250((ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    t4 = fn_88618998((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t4;
    return a0;
}

/* Swing_DLL.xex 0x8861A9B0: call_seq fn_88617D88, lbl_880F7B28, u32@0x1c, u32@0x0, u8@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_8861A9B0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7B28;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)lbl_88D45B2C = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x8861AB10: if_get u32@0x0, u32@0x44, vcall, u32@0x0, u8@0x14d8, fn_8861AA20 */
ts4_word ts4_if_get_u32_off0_8861AB10(ts4_word a0, ts4_word a1)
{
    ts4_word t4;
    unsigned char t5;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 68))))((ts4_word)a0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t4 != 0) {
        t5 = *(unsigned char *)((char *)(ts4_word)(a1) + 5336);
        if ((ts4_word)t5 != 0) {
            fn_8861AA20((ts4_word)a1, (ts4_word)t4);
        }
        *(ts4_word *)((char *)(ts4_word)(a1) + 5312) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 5312)) + 1);
    }
    return a0;
}

/* Swing_DLL.xex 0x8861AD18: get u32@0x0, u32@0x38, vcall, u32@0x20, u32@lbl_88D45B38, fn_88613268 */
ts4_word ts4_get_u32_off0_8861AD18(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t6 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)t3, (ts4_word)t4, (ts4_word)0, (ts4_word)2);
    return t6;
}

/* Swing_DLL.xex 0x8861B468: call_seq fn_88617D88, lbl_880F7F38, u8@0x1c, u32@0x0, u8@0x1d */
ts4_word ts4_call_seq_fn_88617D88_8861B468(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7F38;
    *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x8861B5E8: call_seq fn_88617D88, lbl_880F7C10, u32@0x20, u32@0x0 */
ts4_word ts4_call_seq_fn_88617D88_8861B5E8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7C10;
    return a0;
}

/* Swing_DLL.xex 0x8861C560: if_call_seq u32@0x14, u32@0xc, u32@0xc, u32@0x4, u32@0x0, fn_8861C4F0 */
ts4_word ts4_if_call_seq_u32_off14_8861C560(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p7 = (ts4_word)a0;
    if ((int)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t2 + 4);
        t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        p6 = (ts4_word)a0;
        if ((ts4_word)t3 != (ts4_word)(t2 + 4)) {
            t5 = fn_8861C4F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((t2 + 4)) + 0)), (ts4_word)a0);
            p6 = (ts4_word)t5;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t2;
        p7 = (ts4_word)p6;
    }
    return p7;
}

/* Swing_DLL.xex 0x8861CDC0: call_seq u32@0x4, u32@0x4, fn_8861C830, u32@0x4 */
ts4_word ts4_call_seq_u32_off4_8861CDC0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t3 = fn_8861C830((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)((983040) | 65535);
    return t3;
}

/* Swing_DLL.xex 0x8861DB40: call_seq u8@0x8, fn_881B9148, u32@0x40, ts4_tsu_cleanup_end, u32@0x40 */
ts4_word ts4_call_seq_u8_off8_8861DB40(ts4_word a0)
{
    ts4_word t3;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    t3 = ts4_tsu_cleanup_end((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    return t3;
}

/* Swing_DLL.xex 0x8861DBF0: call_seq fn_88617D88, lbl_880F8D28, u32@0x0, fn_88152DF8, fn_88152DF8, fn_88152DF8 */
ts4_word ts4_call_seq_fn_88617D88_8861DBF0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8D28;
    fn_88152DF8((ts4_word)(a0 + 28));
    fn_88152DF8((ts4_word)(a0 + 40));
    fn_88152DF8((ts4_word)(a0 + 52));
    return a0;
}

/* Swing_DLL.xex 0x8861F270: call_seq u32@0x0, u32@0x4, u32@0x8, u32@0x38, u8@0x3c, fn_88152DF8 */
ts4_word ts4_call_seq_u32_off0_8861F270(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 60) = (unsigned char)0;
    fn_88152DF8((ts4_word)(a0 + 80));
    fn_88152DF8((ts4_word)(a0 + 92));
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8861F4B0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_8861F4B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 33) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 35) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8861F7A8: call_seq ts4_if_call_seq_u8_off68_886195A0, u32@0x174 */
ts4_word ts4_call_seq_fn_886195A0_8861F7A8(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_if_call_seq_u8_off68_886195A0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 372) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8861F858: call_seq fn_886197F0, lbl_880F8748, u32@0x64, u32@0x0 */
ts4_word ts4_call_seq_fn_886197F0_8861F858(ts4_word a0)
{
    fn_886197F0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)16;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8748;
    return a0;
}

/* Swing_DLL.xex 0x8861F958: call_seq fn_88619628, u32@0x1d4, u32@0x1d8, u32@0x1dc */
ts4_word ts4_call_seq_fn_88619628_8861F958(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_88619628();
    *(ts4_word *)((char *)(ts4_word)(a0) + 468) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 472) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 476) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8861FE98: call_seq fn_886197F0, lbl_880F8888, u32@0x178, u32@0x0, u32@0x17c, u32@0x180 */
ts4_word ts4_call_seq_fn_886197F0_8861FE98(ts4_word a0)
{
    fn_886197F0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 376) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8888;
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 392) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 393) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 396) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x886200F8: get fn_88619628, u32@0x38, u32@0x20, u32@0x64, u32@0x24, u32@0x38 */
ts4_word ts4_get_fn_88619628_886200F8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;

    fn_88619628();
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 56);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 100);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)t2;
    loc50[0] = (ts4_word)t3;
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t10 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0, (ts4_word)t7, (ts4_word)t6, (ts4_word)t5, (ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(a1 + 84), (ts4_word)-1);
    return t10;
}

/* Swing_DLL.xex 0x88620190: call_seq fn_886197F0, lbl_880F8A40, u32@0x178, u32@0x0, u32@0x17c, u32@0x184 */
ts4_word ts4_call_seq_fn_886197F0_88620190(ts4_word a0)
{
    fn_886197F0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 376) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8A40;
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)16;
    return a0;
}

/* Swing_DLL.xex 0x886203A0: call_seq u32@0x180, fn_888860A0, ts4_if_call_seq_u8_off68_886195A0 */
ts4_word ts4_call_seq_u32_off180_886203A0(ts4_word a0)
{
    ts4_word t3;

    fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 384)));
    t3 = ts4_if_call_seq_u8_off68_886195A0((ts4_word)a0);
    return t3;
}

/* Swing_DLL.xex 0x88620480: call_seq fn_886197F0, lbl_880F89A0, u32@0x178, u32@0x0, u32@0x184, u32@0x188 */
ts4_word ts4_call_seq_fn_886197F0_88620480(ts4_word a0)
{
    fn_886197F0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 376) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F89A0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 392) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 396) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88621028: call_seq fn_886197F0, lbl_880F86A8, u32@0x178, u32@0x0, u32@0x17c, u32@0x180 */
ts4_word ts4_call_seq_fn_886197F0_88621028(ts4_word a0)
{
    fn_886197F0();
    *(ts4_word *)((char *)(ts4_word)(a0) + 376) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F86A8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 396) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 400) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88621358: if_get u32@0x30, u32@0x0, u32@0x0, vcall, u32@0x30, fn_8861A720 */
ts4_word ts4_if_get_u32_off30_88621358(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t1 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)1);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    t6 = fn_8861A720((ts4_word)a0);
    return t6;
}

/* Swing_DLL.xex 0x88621CE8: set u8@0x0, u32@0x4, u8@0x8, u32@0xc, u8@0x14, u32@0x18 */
void ts4_set_u8_off0_88621CE8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)-1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)3;
    *(unsigned char *)((char *)(ts4_word)(a0) + 20) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 37) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88621E50: get u32@0x2c, u32@0x14, vcall, u8@0x8, fn_881B9148 */
ts4_word ts4_get_u32_off2c_88621E50(ts4_word a0)
{
    ts4_word t4;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 20))))((ts4_word)(a0 + 44));
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t4 = fn_881B9148((ts4_word)(a0 + 16));
    return t4;
}

/* Swing_DLL.xex 0x88622AC0: call_seq fn_8861B128, lbl_880F8280, u8@0x24, u32@0x0, u8@0x123, u8@0x222 */
ts4_word ts4_call_seq_fn_8861B128_88622AC0(ts4_word a0)
{
    fn_8861B128((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8280;
    *(unsigned char *)((char *)(ts4_word)(a0) + 291) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 546) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88622BF0: call_seq fn_8861B128, lbl_880F81C0, u8@0x28, u8@0x30, u32@0x0, u32@0x2c */
ts4_word ts4_call_seq_fn_8861B128_88622BF0(ts4_word a0)
{
    fn_8861B128((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F81C0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)((0) | 32768);
    *(unsigned char *)((char *)(ts4_word)(a0) + 57) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 49) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88622D98: call_seq fn_8861B128, lbl_880F80D0, u8@0x24, u32@0x0, u8@0x25, u32@0x28 */
ts4_word ts4_call_seq_fn_8861B128_88622D98(ts4_word a0)
{
    fn_8861B128((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F80D0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 37) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88624030: addr lbl_880F7EA0, u32@0x24, u32@0x0, fn_8861B4D8 */
ts4_word ts4_addr_lbl_880F7EA0_88624030(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7EA0;
    return fn_8861B4D8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(ts4_word)lbl_880F7EA0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88624370: if_call_seq u8@0x824, fn_8861B8E0, u8@0x824, lbl_880E196C, ts4_if_call_seq_u8_off824_8861B790, fn_8861B8E0 */
ts4_word ts4_if_call_seq_u8_off824_88624370(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    *(unsigned char *)((char *)(ts4_word)(a0) + 2084) = (unsigned char)0;
    t1 = fn_8861B8E0();
    *(unsigned char *)((char *)(ts4_word)(a0) + 2084) = (unsigned char)1;
    if ((ts4_word)(t1 & 0xff) == 1) {
        ts4_if_call_seq_u8_off824_8861B790((ts4_word)a0, (ts4_word)8, (ts4_word)(ts4_word)lbl_880E196C);
        fn_8861B8E0((ts4_word)a0, (ts4_word)a1);
        ts4_if_call_seq_u8_off824_8861B790((ts4_word)a0, (ts4_word)9, (ts4_word)(ts4_word)lbl_880D3BA8);
    }
    return t1;
}

/* Swing_DLL.xex 0x886256B8: get u32@0x0, fn_88625478 */
ts4_word ts4_get_u32_off0_886256B8(ts4_word a0, ts4_word a1)
{
    return fn_88625478((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
}

/* Swing_DLL.xex 0x88625D40: if_call_seq u32@0x28, lbl_880F8C44, u32@0x0, fn_8861E938, ts4_tsu_cleanup_end, fn_88617D28 */
ts4_word ts4_if_call_seq_u32_off28_88625D40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8C44;
    if ((ts4_word)t1 != 0) {
        fn_8861E938((ts4_word)t1);
        ts4_tsu_cleanup_end((ts4_word)t1);
    }
    t5 = fn_88617D28((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x886265E8: call_seq fn_881A50F0, u32@0x20c, u32@0x210 */
ts4_word ts4_call_seq_fn_881A50F0_886265E8(ts4_word a0)
{
    fn_881A50F0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 524) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 528) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x88627AD0: call_seq u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
ts4_word ts4_call_seq_u32_off0_88627AD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    fn_881705B0((ts4_word)a0, (ts4_word)256);
    return a0;
}

/* Swing_DLL.xex 0x88627BB0: get u32@0x4, u32@0x4, u32@0x4, u32@0x4, fn_88627B30 */
ts4_word ts4_get_u32_off4_88627BB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    ts4_word t2;

    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)t1;
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    return fn_88627B30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a2, (ts4_word)t2, (ts4_word)(a3 + 8), (ts4_word)(a3 + 20), (ts4_word)a5, (ts4_word)t1, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88627DE8: call_seq lbl_880F8CF8, u32@0x0, fn_88625798, fn_881A5088, u32@0x28, fn_881A4F30 */
ts4_word ts4_call_seq_lbl_880F8CF8_88627DE8(ts4_word a0)
{
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8CF8;
    fn_88625798();
    fn_881A5088((ts4_word)(a0 + 40));
    fn_881A4F30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_880D19F0;
    t5 = fn_8860BBD8((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x88627E48: call_seq lbl_880F8CF8, lbl_880D1F0C, u32@0x4, u32@0x0, u32@0x8, u32@0x28 */
ts4_word ts4_call_seq_lbl_880F8CF8_88627E48(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8CF8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_880D1F0C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    t1 = fn_88280E60();
    *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(t1) + 4) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    RtlInitializeCriticalSection((ts4_word)(a0 + 12));
    return a0;
}

/* Swing_DLL.xex 0x886291E0: set u32@0x14, u32@0x18, u32@0x1c, u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off14_886291E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((983040) | 65535);
    return;
}

/* Swing_DLL.xex 0x88629210: if_call_seq lbl_880F20E8, u32@0x0, ts4_object_finalize, ts4_object_finalize, u32@0x14, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_lbl_880F20E8_88629210(ts4_word a0)
{
    ts4_word p8;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F20E8;
    ts4_object_finalize((ts4_word)(a0 + 20));
    ts4_object_finalize((ts4_word)(a0 + 8));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t3 != 0) {
        ts4_destroy_owned_object((ts4_word)t3);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)((a0 + 8)) + 0);
    p8 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        t7 = ts4_destroy_owned_object((ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x88629DC0: call_seq fn_88617D88, lbl_880F8BF4, u8@0x1c, u32@0x0, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_88629DC0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F8BF4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8862A120: if_call_seq lbl_880F83C0, u32@0x0, fn_8892AF80, lbl_880F7940, u32@lbl_88D45B1C, u32@0x0 */
ts4_word ts4_if_call_seq_lbl_880F83C0_8862A120(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F83C0;
    fn_8892AF80((ts4_word)(a0 + 44));
    t2 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F7940;
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 548);
    if ((ts4_word)a0 == (ts4_word)t3) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 548) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 544));
    }
    t5 = fn_88617D28((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x8862BA60: call_seq ts4_if_call_seq_u32_lbl_88D45B38_88628E70, ts4_name_keys_register_88626F70, fn_88888338 */
ts4_word ts4_call_seq_fn_88628E70_8862BA60(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_if_call_seq_u32_lbl_88D45B38_88628E70();
    t2 = ts4_name_keys_register_88626F70((ts4_word)t1);
    t3 = fn_88888338((ts4_word)t2);
    return t3;
}

/* Swing_DLL.xex 0x8862BCB0: get u32@0x0, fn_8862BB50 */
ts4_word ts4_get_u32_off0_8862BCB0(ts4_word a0)
{
    return fn_8862BB50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x8862BF00: call_seq u32@0x0, fn_8862BE08 */
ts4_word ts4_call_seq_u32_off0_8862BF00(ts4_word a0, ts4_word a1)
{
    fn_8862BE08((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return a0;
}

/* Swing_DLL.xex 0x8862C1D8: call_seq u32@0x0, fn_8862C0E8 */
ts4_word ts4_call_seq_u32_off0_8862C1D8(ts4_word a0, ts4_word a1)
{
    fn_8862C0E8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return a0;
}

/* Swing_DLL.xex 0x8862C300: get u32@0x0, fn_8862C210 */
ts4_word ts4_get_u32_off0_8862C300(ts4_word a0, ts4_word a1)
{
    return fn_8862C210((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
}

/* Swing_DLL.xex 0x8862C5C0: get u32@0x4, u32@0x0, u32@0x4, fn_8862C210 */
ts4_word ts4_get_u32_off4_8862C5C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    return fn_8862C210((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t2, (ts4_word)t1);
}

/* Swing_DLL.xex 0x8862D338: call_seq ts4_assign_formatted_text, ts4_if_call_seq_u32_off8_88160D30, ts4_destroy_owned_object */
ts4_word ts4_call_seq_ts4_assign_formatted_text_8862D338(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t4;

    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0]);
    ts4_if_call_seq_u32_off8_88160D30((ts4_word)(a0 + 5316), (ts4_word)(ts4_word)&loc50[0]);
    t3 = loc50[0];
    t4 = ts4_destroy_owned_object((ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x8862D510: set u8@0x9, fn_8892EB28, ts4_if_call_seq_u32_off8_8892ED88, u32@0x0, u32@0x0, u32@0x20 */
ts4_word ts4_set_u8_off9_8862D510(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    *(unsigned char *)((char *)(ts4_word)(a1) + 9) = (unsigned char)1;
    fn_8892EB28((ts4_word)(a1 + 36), (ts4_word)0);
    t2 = ts4_if_call_seq_u32_off8_8892ED88((ts4_word)(a1 + 36), (ts4_word)0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t3) + 40))))((ts4_word)a0, (ts4_word)t2, (ts4_word)t5, (ts4_word)t4);
    return t7;
}

/* Swing_DLL.xex 0x8862E040: if_get u32@0x28, fn_8862CC90 */
ts4_word ts4_if_get_u32_off28_8862E040(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((int)t1 == 0) {
        return 1;
    }
    return fn_8862CC90((ts4_word)t1);
}

/* Swing_DLL.xex 0x8862E058: if_get u32@0x24, fn_8862CC90 */
ts4_word ts4_if_get_u32_off24_8862E058(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((int)t1 == 0) {
        return 1;
    }
    return fn_8862CC90((ts4_word)t1);
}

/* Swing_DLL.xex 0x8862E070: if_get u32@0x20, fn_8862CC90 */
ts4_word ts4_if_get_u32_off20_8862E070(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((int)t1 == 0) {
        return 1;
    }
    return fn_8862CC90((ts4_word)t1);
}

/* Swing_DLL.xex 0x8862EAE8: tailcall fn_8862E858 */
ts4_word ts4_tailcall_fn_8862E858_8862EAE8(ts4_word a0)
{
    return fn_8862E858((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88631030: get u32@0x14c8, u32@0x14c4, fn_88150310 */
ts4_word ts4_get_u32_off14c8_88631030(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 5320);
    return fn_88150310((ts4_word)(a0 + 5316), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 5316)), (ts4_word)t1);
}

/* Swing_DLL.xex 0x88634520: call_seq ts4_object_finalize, u32@0x2c, u32@0x28, fn_88280A50, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_ts4_object_finalize_88634520(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    ts4_object_finalize((ts4_word)(a0 + 28));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    fn_88280A50((ts4_word)(a0 + 40), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)), (ts4_word)t2);
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t5 = fn_881B9148((ts4_word)(a0 + 16));
    return t5;
}

/* Swing_DLL.xex 0x886373C0: if_get u32@0x84, u32@0x4, vcall, u32@0xc, u8@0x111, fn_883CB4A0 */
ts4_word ts4_if_get_u32_off84_886373C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t4;
    ts4_word t9;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4))))((ts4_word)(a0 + 132));
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    *(unsigned char *)((char *)(ts4_word)(a1) + 273) = (unsigned char)a2;
    if ((int)t4 != 0) {
        fn_883CB4A0((ts4_word)t4, (ts4_word)a2);
    }
    t9 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
    return t9;
}

/* Swing_DLL.xex 0x88637958: call_seq u32@0x0, fn_88608590, u32@0x4, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_88637958(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a2;
    t1 = fn_88608590((ts4_word)0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)1;
    return a0;
}

/* Swing_DLL.xex 0x886379A0: get u32@lbl_88D45B18, u32@0xc, fn_8860DCF8 */
ts4_word ts4_get_u32_lbl_88D45B18_886379A0(ts4_word a0)
{
    return fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B18)) + 12)), (ts4_word)a0, (ts4_word)16, (ts4_word)2);
}

/* Swing_DLL.xex 0x886379C0: get u32@lbl_88D45B18, fn_886376E0 */
ts4_word ts4_get_u32_lbl_88D45B18_886379C0(ts4_word a0)
{
    return fn_886376E0((ts4_word)(*(ts4_word *)lbl_88D45B18), (ts4_word)a0);
}

/* Swing_DLL.xex 0x886379D0: get u32@lbl_88D45B18, fn_886378F0 */
ts4_word ts4_get_u32_lbl_88D45B18_886379D0(ts4_word a0)
{
    return fn_886378F0((ts4_word)(*(ts4_word *)lbl_88D45B18), (ts4_word)a0);
}

/* Swing_DLL.xex 0x88638618: call_seq u32@0xc, u32@lbl_88D45B18, u32@0xc, u32@0xc, fn_88637F10, u32@lbl_88D45B18 */
ts4_word ts4_call_seq_u32_offc_88638618(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)lbl_88D45B18;
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)t1;
    t4 = fn_88637F10((ts4_word)t2);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B18)) + 12) = (ts4_word)t3;
    return t4;
}

/* Swing_DLL.xex 0x88638668: get u32@lbl_88D45B18, fn_88638188 */
ts4_word ts4_get_u32_lbl_88D45B18_88638668(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_88638188((ts4_word)(*(ts4_word *)lbl_88D45B18), (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x88638678: get u32@lbl_88D45B18, fn_88638100 */
ts4_word ts4_get_u32_lbl_88D45B18_88638678(void)
{
    return fn_88638100((ts4_word)(*(ts4_word *)lbl_88D45B18));
}

/* Swing_DLL.xex 0x88638698: get u32@lbl_88D45B18, fn_88638210 */
ts4_word ts4_get_u32_lbl_88D45B18_88638698(void)
{
    return fn_88638210((ts4_word)(*(ts4_word *)lbl_88D45B18));
}

/* Swing_DLL.xex 0x886389E8: if_get u32@0x84, u32@0x4, vcall, fn_88638770, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off84_886389E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[3];
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t12;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4))))((ts4_word)(a0 + 132));
    t4 = fn_88638770((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t4 != 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
        t7 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
        loc50[0] = (ts4_word)t5;
        loc50[1] = (ts4_word)t6;
        loc50[2] = (ts4_word)t7;
        fn_883CB4F0((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)0);
    }
    t12 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
    return t12;
}

/* Swing_DLL.xex 0x88638A70: if_get u32@0x84, u32@0x4, vcall, fn_88637BF0, u8@0x6c, u32@0x1c */
ts4_word ts4_if_get_u32_off84_88638A70(ts4_word a0)
{
    unsigned char t5;
    ts4_word t13;

    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4))))((ts4_word)(a0 + 132));
    fn_88637BF0((ts4_word)a0);
    t5 = *(unsigned char *)((char *)(ts4_word)(a0) + 108);
    if ((ts4_word)t5 != 0) {
        fn_88638418((ts4_word)(a0 + 48), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
        fn_883C6460((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 32)));
    }
    t13 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 132)) + 0))) + 8))))((ts4_word)(a0 + 132));
    return t13;
}

/* Swing_DLL.xex 0x88638C40: get u32@lbl_88D45B18, fn_88638918 */
ts4_word ts4_get_u32_lbl_88D45B18_88638C40(void)
{
    return fn_88638918((ts4_word)(*(ts4_word *)lbl_88D45B18));
}

/* Swing_DLL.xex 0x88638DD8: if_call_seq u32@lbl_88D45B18, fn_88638188, u32@lbl_88D45930, fn_888D7230 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B18_88638DD8(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t4;

    (void)a0;
    fn_88638188((ts4_word)(*(ts4_word *)lbl_88D45B18), (ts4_word)a1, (ts4_word)0);
    t3 = *(ts4_word *)lbl_88D45930;
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = fn_888D7230((ts4_word)t3, (ts4_word)a1);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88638E28: if_call_seq u32@lbl_88D45B18, fn_88638188, u32@lbl_88D45930, fn_888D72F0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B18_88638E28(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t4;

    (void)a0;
    fn_88638188((ts4_word)(*(ts4_word *)lbl_88D45B18), (ts4_word)a1, (ts4_word)1);
    t3 = *(ts4_word *)lbl_88D45930;
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = fn_888D72F0((ts4_word)t3, (ts4_word)a1);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x886390D0: if_call_seq u32@lbl_88D45B18, fn_88638210, u32@lbl_88D45930, fn_888DF110 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B18_886390D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p5;
    ts4_word t3;
    ts4_word t4;

    (void)a0;
    fn_88638210((ts4_word)(*(ts4_word *)lbl_88D45B18));
    t3 = *(ts4_word *)lbl_88D45930;
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = fn_888DF110((ts4_word)t3, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x886399F0: set u8@0x0, u8@0x1, u8@0x2 */
void ts4_set_u8_off0_886399F0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)76;
    *(unsigned char *)((char *)(ts4_word)(a1) + 1) = (unsigned char)90;
    *(unsigned char *)((char *)(ts4_word)(a1) + 2) = (unsigned char)88;
    return;
}

/* Swing_DLL.xex 0x88639A10: fn  */
ts4_word ts4_fn_88639A10(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (a1 << 1);
}

/* Swing_DLL.xex 0x88639A18: fn  */
ts4_word ts4_fn_88639A18(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639AE8: call_seq u32@0x0, u32@0x28, fn_8857A8A0, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_88639AE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    loc50[0] = (ts4_word)t1;
    t3 = fn_8857A8A0((ts4_word)t2, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3, (ts4_word)a4);
    t4 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t4;
    return t3;
}

/* Swing_DLL.xex 0x88639B30: call_seq u32@0x0, u32@0x24, fn_8857A720, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_88639B30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    loc50[0] = (ts4_word)t1;
    t3 = fn_8857A720((ts4_word)t2, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3, (ts4_word)a4);
    t4 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t4;
    return t3;
}

/* Swing_DLL.xex 0x88639D18: get u8@lbl_88C4589D */
ts4_word ts4_get_u8_lbl_88C4589D_88639D18(void)
{
    return (*(unsigned char *)lbl_88C4589D);
}

/* Swing_DLL.xex 0x88639D38: get u8@lbl_88D45B06 */
ts4_word ts4_get_u8_lbl_88D45B06_88639D38(void)
{
    return (*(unsigned char *)lbl_88D45B06);
}

/* Swing_DLL.xex 0x88639DC0: get u32@lbl_88D4528C */
ts4_word ts4_get_u32_lbl_88D4528C_88639DC0(void)
{
    return (*(ts4_word *)lbl_88D4528C);
}

/* Swing_DLL.xex 0x88639DD8: fn  */
ts4_word ts4_fn_88639DD8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639DE0: fn  */
ts4_word ts4_fn_88639DE0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639E68: fn  */
ts4_word ts4_fn_88639E68(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639E70: fn  */
ts4_word ts4_fn_88639E70(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639E78: fn  */
ts4_word ts4_fn_88639E78(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639E90: fn  */
ts4_word ts4_fn_88639E90(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639EC0: get u32@lbl_88D4528C */
ts4_word ts4_get_u32_lbl_88D4528C_88639EC0(void)
{
    return (*(ts4_word *)lbl_88D4528C);
}

/* Swing_DLL.xex 0x88639ED8: fn  */
ts4_word ts4_fn_88639ED8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639EE0: fn  */
ts4_word ts4_fn_88639EE0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639F80: fn  */
ts4_word ts4_fn_88639F80(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639F88: fn  */
ts4_word ts4_fn_88639F88(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639F90: fn  */
ts4_word ts4_fn_88639F90(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639FA8: fn  */
ts4_word ts4_fn_88639FA8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x88639FC0: get u32@0x4, u32@0x24c */
ts4_word ts4_get_u32_off4_88639FC0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 588));
}

/* Swing_DLL.xex 0x88639FD0: get  */
float ts4_get_88639FD0(ts4_word a0, ts4_word a1)
{
    float t14;

    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(a0) + 0));
    *(float *)((char *)(ts4_word)(a1) + 60) = (*(float *)((char *)(ts4_word)(a0) + 60));
    *(float *)((char *)(ts4_word)(a1) + 12) = (*(float *)((char *)(ts4_word)(a0) + 48));
    *(float *)((char *)(ts4_word)(a1) + 48) = (*(float *)((char *)(ts4_word)(a0) + 12));
    *(float *)((char *)(ts4_word)(a1) + 32) = (*(float *)((char *)(ts4_word)(a0) + 4));
    *(float *)((char *)(ts4_word)(a1) + 16) = (*(float *)((char *)(ts4_word)(a0) + 8));
    *(float *)((char *)(ts4_word)(a1) + 44) = (*(float *)((char *)(ts4_word)(a0) + 52));
    *(float *)((char *)(ts4_word)(a1) + 28) = (*(float *)((char *)(ts4_word)(a0) + 56));
    *(float *)((char *)(ts4_word)(a1) + 56) = (*(float *)((char *)(ts4_word)(a0) + 28));
    *(float *)((char *)(ts4_word)(a1) + 52) = (*(float *)((char *)(ts4_word)(a0) + 44));
    *(float *)((char *)(ts4_word)(a1) + 8) = (*(float *)((char *)(ts4_word)(a0) + 16));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(a0) + 32));
    *(float *)((char *)(ts4_word)(a1) + 40) = (*(float *)((char *)(ts4_word)(a0) + 20));
    t14 = *(float *)((char *)(ts4_word)(a0) + 40);
    *(float *)((char *)(ts4_word)(a1) + 20) = t14;
    *(float *)((char *)(ts4_word)(a1) + 36) = (*(float *)((char *)(ts4_word)(a0) + 36));
    *(float *)((char *)(ts4_word)(a1) + 24) = (*(float *)((char *)(ts4_word)(a0) + 24));
    return t14;
}

/* Swing_DLL.xex 0x8863A0A0: get u32@lbl_88D45B14, fn_88883CD0 */
ts4_word ts4_get_u32_lbl_88D45B14_8863A0A0(void)
{
    return fn_88883CD0((ts4_word)(*(ts4_word *)lbl_88D45B14));
}

/* Swing_DLL.xex 0x8863A0B0: get u32@0x4c, u32@0x0, u32@0x50, u32@0x4 */
void ts4_get_u32_off4c_8863A0B0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 80));
    return;
}

/* Swing_DLL.xex 0x8863A118: get u32@0x4c, u32@0x0, u32@0x50, u32@0x4 */
void ts4_get_u32_off4c_8863A118(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 76));
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 80));
    return;
}

/* Swing_DLL.xex 0x8863A178: if_get u32@0xf4, u32@0xf4, u8@0xf8 */
void ts4_if_get_u32_offf4_8863A178(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 244);
    if ((ts4_word)a1 == (ts4_word)t1) {
        if ((ts4_word)(a2 & 0xff) == 0) {
            return;
        }
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 248) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8863A208: get u8@0x49a */
ts4_word ts4_get_u8_off49a_8863A208(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 1178));
}

/* Swing_DLL.xex 0x8863A210: get u8@0x0, u8@0x49a */
void ts4_get_u8_off0_8863A210(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 1178) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x8863A220: get u8@0x499 */
ts4_word ts4_get_u8_off499_8863A220(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 1177));
}

/* Swing_DLL.xex 0x8863A228: get u8@0x0, u8@0x499 */
void ts4_get_u8_off0_8863A228(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 1177) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x8863A310: get u32@0x0, u32@0x28, vcall, u32@0x0, u32@0x47c, u32@0x4 */
ts4_word ts4_get_u32_off0_8863A310(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 40))))((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1148) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 1152) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 1156) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 8));
    return t3;
}

/* Swing_DLL.xex 0x8863A3C0: call_seq u32@lbl_88D45B14, fn_88883CD0, u32@0x0, u32@0x238, u32@0x0 */
ts4_word ts4_call_seq_u32_lbl_88D45B14_8863A3C0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88883CD0((ts4_word)(*(ts4_word *)lbl_88D45B14));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 568) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)a1;
    return t3;
}

/* Swing_DLL.xex 0x8863A448: set u8@0x49c */
void ts4_set_u8_off49c_8863A448(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 1180) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8863A4C8: addr lbl_880E7620, u32@0x0, u32@lbl_88D41F80 */
void ts4_addr_lbl_880E7620_8863A4C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7620;
    *(ts4_word *)lbl_88D41F80 = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8863A518: call_seq u32@0x4, u32@lbl_88D45B14, fn_88883CD0, u32@0x0, u32@0x238, u32@0x0 */
ts4_word ts4_call_seq_u32_off4_8863A518(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_88883CD0((ts4_word)(*(ts4_word *)lbl_88D45B14));
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    *(ts4_word *)((char *)(ts4_word)(t1) + 568) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)a1;
    return t4;
}

/* Swing_DLL.xex 0x8863A5A0: get u32@0x4, u8@0x49c */
void ts4_get_u32_off4_8863A5A0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 1180) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8863A638: if_get u32@0xf4, u32@0xf4, u8@0xf8 */
void ts4_if_get_u32_offf4_8863A638(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 244);
    if ((ts4_word)a2 == (ts4_word)t1) {
        if ((ts4_word)(a3 & 0xff) == 0) {
            return;
        }
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 244) = (ts4_word)a2;
    *(unsigned char *)((char *)(ts4_word)(a1) + 248) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x8863A6D0: get u32@0x4, u8@0x49a */
ts4_word ts4_get_u32_off4_8863A6D0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 1178));
}

/* Swing_DLL.xex 0x8863A6E0: get u32@0x4, u8@0x0, u8@0x49a */
void ts4_get_u32_off4_8863A6E0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(unsigned char *)((char *)(ts4_word)(t1) + 1178) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x8863A6F0: get u32@0x4, u8@0x499 */
ts4_word ts4_get_u32_off4_8863A6F0(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 1177));
}

/* Swing_DLL.xex 0x8863A700: get u32@0x4, u8@0x0, u8@0x499 */
void ts4_get_u32_off4_8863A700(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(unsigned char *)((char *)(ts4_word)(t1) + 1177) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Swing_DLL.xex 0x8863A728: get u32@0x0, u32@0x28, u32@0x4, vcall, u32@0x0, u32@0x47c */
ts4_word ts4_get_u32_off0_8863A728(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 40);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(t3) + 1148) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
    *(ts4_word *)((char *)(ts4_word)(t3) + 1152) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 4));
    *(ts4_word *)((char *)(ts4_word)(t3) + 1156) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 8));
    return t4;
}

/* Swing_DLL.xex 0x8863AB48: call_seq ts4_object_finalize, ts4_object_finalize */
ts4_word ts4_call_seq_ts4_object_finalize_8863AB48(ts4_word a0)
{
    ts4_word t2;

    ts4_object_finalize((ts4_word)(a0 + 1032));
    t2 = ts4_object_finalize((ts4_word)(a0 + 1044));
    return t2;
}

/* Swing_DLL.xex 0x8863B098: get u32@0x4, fn_8863AA58 */
ts4_word ts4_get_u32_off4_8863B098(ts4_word a0)
{
    return fn_8863AA58((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x8863B0A0: get u32@0x4, fn_8863A8F0 */
ts4_word ts4_get_u32_off4_8863B0A0(ts4_word a0)
{
    return fn_8863A8F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x8863B0A8: call_seq u32@0x4, ts4_object_finalize, ts4_object_finalize */
ts4_word ts4_call_seq_u32_off4_8863B0A8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    ts4_object_finalize((ts4_word)(t1 + 1032));
    t3 = ts4_object_finalize((ts4_word)(t1 + 1044));
    return t3;
}

/* Swing_DLL.xex 0x8863C1C8: call_seq u32@lbl_88D41FC0, fn_88198CE0, ts4_if_atomic_interlocked_dec_881876D0, fn_88198CE0 */
ts4_word ts4_call_seq_u32_lbl_88D41FC0_8863C1C8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D41FC0));
    ts4_if_atomic_interlocked_dec_881876D0((ts4_word)a0);
    t4 = fn_88198CE0((ts4_word)t2);
    return t4;
}

/* Swing_DLL.xex 0x8863C638: get u32@0x4, fn_8863B9F0 */
ts4_word ts4_get_u32_off4_8863C638(ts4_word a0)
{
    return fn_8863B9F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x8863C670: get u32@0x4, fn_8863B6E8 */
ts4_word ts4_get_u32_off4_8863C670(ts4_word a0)
{
    return fn_8863B6E8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x8863C678: get u32@0x4, fn_8863B7B8 */
ts4_word ts4_get_u32_off4_8863C678(ts4_word a0)
{
    return fn_8863B7B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x8863C680: call_seq u32@lbl_88D41FC0, fn_88198CE0, ts4_if_atomic_interlocked_dec_881876D0, fn_88198CE0 */
ts4_word ts4_call_seq_u32_lbl_88D41FC0_8863C680(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t4;

    (void)a0;
    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D41FC0));
    ts4_if_atomic_interlocked_dec_881876D0((ts4_word)a1);
    t4 = fn_88198CE0((ts4_word)t2);
    return t4;
}

/* Swing_DLL.xex 0x8863DD80: get u32@0x4, fn_8863DC80 */
ts4_word ts4_get_u32_off4_8863DD80(ts4_word a0)
{
    return fn_8863DC80((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x8863EEF8: get u32@0x4, fn_8863DF58 */
ts4_word ts4_get_u32_off4_8863EEF8(ts4_word a0)
{
    return fn_8863DF58((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x8863EFE8: get u32@0x4, fn_8863EF50 */
ts4_word ts4_get_u32_off4_8863EFE8(ts4_word a0)
{
    return fn_8863EF50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x8863FAC0: get u32@0x4, ts4_if_call_seq_fn_88162BB8_8863EFF0 */
ts4_word ts4_get_u32_off4_8863FAC0(ts4_word a0)
{
    return ts4_if_call_seq_fn_88162BB8_8863EFF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x8863FAC8: call_seq fn_8863F068 */
ts4_word ts4_call_seq_fn_8863F068_8863FAC8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    fn_8863F068((ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
    return a0;
}

/* Swing_DLL.xex 0x8863FB00: call_seq u32@lbl_88D41FC0, fn_88198CE0, u32@lbl_88D41FC0, fn_88198CE0, fn_88198CE0, u32@lbl_88D45290 */
ts4_word ts4_call_seq_u32_lbl_88D41FC0_8863FB00(void)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;

    t2 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D41FC0));
    t4 = fn_88198CE0((ts4_word)(*(ts4_word *)lbl_88D41FC0));
    fn_88198CE0((ts4_word)t4);
    fn_8863F858((ts4_word)(*(ts4_word *)lbl_88D45290));
    t8 = fn_88198CE0((ts4_word)t2);
    return t8;
}

/* Swing_DLL.xex 0x88640808: get u32@0x4, fn_88640150 */
ts4_word ts4_get_u32_off4_88640808(ts4_word a0)
{
    return fn_88640150((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x88640898: call_seq ts4_assign_text_from_c_string, fn_8863AE08 */
ts4_word ts4_call_seq_ts4_assign_text_from_c_string_88640898(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t2 = fn_8863AE08((ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x88641200: call_seq ts4_assign_text_from_c_string, fn_8863AE08 */
ts4_word ts4_call_seq_ts4_assign_text_from_c_string_88641200(void)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_8863AE08((ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x88641240: get u32@0x4, fn_88640968 */
ts4_word ts4_get_u32_off4_88641240(ts4_word a0)
{
    return fn_88640968((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x88641E68: get u32@0x4, fn_88641970 */
ts4_word ts4_get_u32_off4_88641E68(ts4_word a0)
{
    return fn_88641970((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x88641E70: get u32@0x4, fn_88641A58 */
ts4_word ts4_get_u32_off4_88641E70(ts4_word a0)
{
    return fn_88641A58((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x88641E78: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886412C0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88641E78(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886412C0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x886446C0: get u32@0x4, fn_88644138 */
ts4_word ts4_get_u32_off4_886446C0(ts4_word a0)
{
    return fn_88644138((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Swing_DLL.xex 0x886446E8: set u32@0x0 */
void ts4_set_u32_off0_886446E8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88644790: get u32@0x0, u32@0x10 */
void ts4_get_u32_off0_88644790(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16) = (ts4_word)-1;
    return;
}

/* Swing_DLL.xex 0x886447B0: get u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off0_886447B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16));
}

/* Swing_DLL.xex 0x886447C0: get u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_off0_886447C0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16)) + 1) != 0);
}

/* Swing_DLL.xex 0x886447D8: set u32@0x0 */
void ts4_set_u32_off0_886447D8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886447E8: set u32@0x0 */
void ts4_set_u32_off0_886447E8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x886447F0: set u32@0x0 */
void ts4_set_u32_off0_886447F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88644808: get u32@0x4 */
ts4_word ts4_get_u32_off4_88644808(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) != 0);
}

/* Swing_DLL.xex 0x88644818: get u32@0x4, u32@0x10 */
ts4_word ts4_get_u32_off4_88644818(ts4_word a0, ts4_word a1)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 16))) + (a1 << 2)));
}

/* Swing_DLL.xex 0x88644830: get u32@0x4, u32@0x8 */
ts4_word ts4_get_u32_off4_88644830(ts4_word a0, ts4_word a1)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 8))) + (a1 << 2)));
}
