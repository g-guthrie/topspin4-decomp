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

extern char g_ts4_default_script_value[];
extern char lbl_880C1320[];
extern char lbl_880D35C0[];
extern char lbl_880DD088[];
extern char lbl_880E3A40[];
extern char lbl_880E3EF0[];
extern char lbl_880E3F00[];
extern char lbl_880E3F10[];
extern char lbl_880E4528[];
extern char lbl_880E46C8[];
extern char lbl_880E4760[];
extern char lbl_880E7494[];
extern char lbl_880E75A8[];
extern char lbl_880E7620[];
extern char lbl_880E7750[];
extern char lbl_880E7810[];
extern char lbl_880E78A8[];
extern char lbl_880E7990[];
extern char lbl_880E7AF4[];
extern char lbl_880E7B80[];
extern char lbl_880E7C30[];
extern char lbl_880E8230[];
extern char lbl_880E83EC[];
extern char lbl_880E8424[];
extern char lbl_880E8588[];
extern char lbl_880E86D8[];
extern char lbl_880E8738[];
extern char lbl_880E8798[];
extern char lbl_880E87F8[];
extern char lbl_880E8858[];
extern char lbl_880E8C58[];
extern char lbl_880E9154[];
extern char lbl_880E9158[];
extern char lbl_880E9168[];
extern char lbl_880E9378[];
extern char lbl_8814B440[];
extern char lbl_88C697D0[];
extern char lbl_88C697EC[];
extern char lbl_88C69804[];
extern char lbl_88C69820[];
extern char lbl_88C6983C[];
extern char lbl_88C69854[];
extern char lbl_88C69870[];
extern char lbl_88C69888[];
extern char lbl_88C698A4[];
extern char lbl_88C698BC[];
extern char lbl_88C698D8[];
extern char lbl_88C698F0[];
extern char lbl_88C6990C[];
extern char lbl_88C69924[];
extern char lbl_88C69940[];
extern char lbl_88C69958[];
extern char lbl_88C69974[];
extern char lbl_88C6998C[];
extern char lbl_88C699A8[];
extern char lbl_88C699C0[];
extern char lbl_88C699DC[];
extern char lbl_88C699F4[];
extern char lbl_88C69A10[];
extern char lbl_88C69A28[];
extern char lbl_88C69A44[];
extern char lbl_88C69A78[];
extern char lbl_88C69A94[];
extern char lbl_88C69AE4[];
extern char lbl_88C69B00[];
extern char lbl_88C69B18[];
extern char lbl_88C69B34[];
extern char lbl_88C69B4C[];
extern char lbl_88C69BB0[];
extern char lbl_88C69BCC[];
extern char lbl_88C69BE4[];
extern char lbl_88C69C00[];
extern char lbl_88C69C18[];
extern char lbl_88C69C34[];
extern char lbl_88C69C4C[];
extern char lbl_88C69C68[];
extern char lbl_88C69C80[];
extern char lbl_88C69C9C[];
extern char lbl_88C69CC4[];
extern char lbl_88C69CE0[];
extern char lbl_88C69CF8[];
extern char lbl_88C69D14[];
extern char lbl_88C69D2C[];
extern char lbl_88C69D48[];
extern char lbl_88C69D98[];
extern char lbl_88C69DB4[];
extern char lbl_88C69DE8[];
extern char lbl_88C69E04[];
extern char lbl_88C69E20[];
extern char lbl_88C69E3C[];
extern char lbl_88D41F80[];
extern char lbl_88D41F9C[];
extern char lbl_88D41FC4[];
extern char lbl_88D45B38[];
ts4_word fn_881519D0();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_8818EB10();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word fn_8819ACC8();
ts4_word fn_8819B0C8();
ts4_word fn_8819B1A8();
ts4_word fn_8819B2A0();
ts4_word fn_8819B308();
ts4_word fn_881B18E0();
ts4_word fn_881B19A0();
ts4_word fn_881C23E8();
ts4_word fn_881C2590();
ts4_word fn_881C5F68();
ts4_word fn_881C6998();
ts4_word fn_881C7078();
ts4_word fn_881C86B0();
ts4_word fn_881C8D98();
ts4_word fn_881C8E18();
ts4_word fn_881CCD90();
ts4_word fn_881CCDF0();
ts4_word fn_881CDFE0();
ts4_word ts4_call_seq_fn_8819B0C8_881CE548();
ts4_word fn_881CEB10();
ts4_word fn_881D4050();
ts4_word fn_881D4788();
ts4_word ts4_addr_fn_88206B20_881D58B8();
ts4_word fn_881D6CA0();
ts4_word fn_881DA460();
ts4_word fn_881DBA10();
ts4_word fn_881DD5E0();
ts4_word fn_881DDE58();
ts4_word fn_881E88D0();
ts4_word fn_881E92C0();
ts4_word fn_881EC4A0();
ts4_word fn_881F0598();
ts4_word fn_881F07F8();
ts4_word fn_881F1060();
ts4_word ts4_if_get_u32_off24_881F1598();
ts4_word fn_881F26C0();
ts4_word fn_881F4108();
ts4_word fn_881F41E8();
ts4_word fn_881F4D38();
ts4_word fn_881F8B58();
ts4_word fn_881FBA58();
ts4_word fn_88202CD8();
ts4_word ts4_addr_fn_881F7958_88206B20();
ts4_word fn_8820AC88();
ts4_word fn_8820FD80();
ts4_word fn_8820FE68();
ts4_word fn_885630C0();
ts4_word ts4_tailcall_fn_885655E8_88565748();
ts4_word fn_88566FE8();
ts4_word fn_88569190();
ts4_word fn_88613268();
ts4_word fn_887D2B40();
ts4_word fn_887E1020();
ts4_word fn_887EE4B0();
ts4_word fn_887F4BA0();
ts4_word ts4_call_seq_fn_887F4BA0_887F5400();
ts4_word fn_887F9418();
ts4_word fn_887FC8F0();
ts4_word fn_888006F0();
ts4_word fn_88800758();
ts4_word fn_88800BF8();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_text_from_c_string();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x881B3F30: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88800BF8, lbl_880E3A40, u32@0x28, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B3F30(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88800BF8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 40) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3A40;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B3FB0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88800BF8, lbl_880E3A40, u32@0x28, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B3FB0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88800BF8((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 40) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3A40;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B4030: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88800758 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B4030(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)2252, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88800758((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B4088: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88800758 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B4088(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)2252, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88800758((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B40E0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888006F0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B40E0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888006F0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B4138: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888006F0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B4138(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888006F0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B45F0: if_get u32@0x4 */
void ts4_if_get_u32_off4_881B45F0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(float *)((char *)(ts4_word)(a0) + 8) = (*(float *)((char *)(ts4_word)(t1) + 0));
    return;
}

/* Swing_DLL.xex 0x881B4640: if_get u32@0x4, u32@0x0, u32@0x8 */
void ts4_if_get_u32_off4_881B4640(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    return;
}

/* Swing_DLL.xex 0x881B4658: if_get u32@0x4, u8@0x0, u8@0x8 */
void ts4_if_get_u32_off4_881B4658(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(t1) + 0));
    return;
}

/* Swing_DLL.xex 0x881B46A8: if_get u32@0x4, u8@0x8, u8@0x0 */
ts4_word ts4_if_get_u32_off4_881B46A8(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        t2 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
        return ((t2 - (*(unsigned char *)((char *)(ts4_word)(t1) + 0))) != 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x881B4710: if_get u32@0x4, u32@0x8, u32@0x0 */
ts4_word ts4_if_get_u32_off4_881B4710(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        return ((t2 - (*(ts4_word *)((char *)(ts4_word)(t1) + 0))) != 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x881B4DB8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880E3EF0, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B4DB8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3EF0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B4E20: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880E3F00, u32@0x8, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B4E20(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3F00;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B4E90: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880E3F10, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B4E90(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3F10;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B4EF8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880E3F00, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B4EF8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E3F00;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B6098: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887FC8F0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B6098(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887FC8F0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7440: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887FC8F0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7440(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887FC8F0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7E08: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887F9418 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7E08(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887F9418((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7E60: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887F9418 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7E60(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887F9418((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B8828: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_887F4BA0_887F5400, lbl_880E46C8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B8828(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)328, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        ts4_call_seq_fn_887F4BA0_887F5400((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880E46C8;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B88A0: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_887F4BA0_887F5400 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B88A0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)328, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_call_seq_fn_887F4BA0_887F5400((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B88F8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887F4BA0, lbl_880E4760, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B88F8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)232, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887F4BA0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880E4760;
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B8960: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887F4BA0, lbl_880E4528, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B8960(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)232, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887F4BA0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880E4528;
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B8EE8: if_get u32@0x0, u32@0x4, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_881B8EE8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + -1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 0));
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x881BA428: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887EE4B0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881BA428(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)776, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887EE4B0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881BA480: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887EE4B0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881BA480(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)776, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887EE4B0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881BC050: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x24, u32@0x2c, u32@0x30, memcpy */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881BC050(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 36) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 44) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 48) = (ts4_word)0;
        memcpy((ts4_word)t2, (ts4_word)a0, (ts4_word)68);
        p4 = (ts4_word)t2;
    } else {
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x881BC658: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887E1020 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881BC658(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)908, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887E1020((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881BC6B0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887E1020 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881BC6B0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)908, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887E1020((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881BCFB8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887D2B40 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881BCFB8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)80, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887D2B40((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881BD010: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887D2B40 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881BD010(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)80, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887D2B40((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881BDBA0: addr lbl_88C69DE8 */
ts4_word ts4_addr_lbl_88C69DE8_881BDBA0(void)
{
    return (ts4_word)lbl_88C69DE8;
}

/* Swing_DLL.xex 0x881BDBB0: addr lbl_88C69E04 */
ts4_word ts4_addr_lbl_88C69E04_881BDBB0(void)
{
    return (ts4_word)lbl_88C69E04;
}

/* Swing_DLL.xex 0x881BDBC0: addr lbl_88C69E20 */
ts4_word ts4_addr_lbl_88C69E20_881BDBC0(void)
{
    return (ts4_word)lbl_88C69E20;
}

/* Swing_DLL.xex 0x881BDBD0: addr lbl_88C69E3C */
ts4_word ts4_addr_lbl_88C69E3C_881BDBD0(void)
{
    return (ts4_word)lbl_88C69E3C;
}

/* Swing_DLL.xex 0x881C1E40: get u32@0x14 */
void ts4_get_u32_off14_881C1E40(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(float *)((char *)(ts4_word)(t1) + 12) = (*(float *)((char *)(ts4_word)(t1) + 20));
    return;
}

/* Swing_DLL.xex 0x881C2180: get  */
void ts4_get_881C2180(ts4_word a0)
{
    *(float *)((char *)(ts4_word)(a0) + 20) = (*(float *)lbl_8814B440);
    return;
}

/* Swing_DLL.xex 0x881C2330: if_call_seq u32@0x2d0, u32@0x2d4, fn_881C23E8, u32@0x2d0, u32@0x2d4, u32@0x2d8 */
ts4_word ts4_if_call_seq_u32_off2d0_881C2330(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 720);
    if ((ts4_word)t1 != 0) {
        fn_881C23E8((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 724)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 720) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 724) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 728) = (ts4_word)0;
    t5 = fn_881C2590((ts4_word)a0, (ts4_word)30);
    return t5;
}

/* Swing_DLL.xex 0x881C3A58: get u32@0x0, u32@0x24, vcall, fn_88199068, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_881C3A58(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 36))))((ts4_word)a1);
    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t4 = fn_88199068((ts4_word)0, (ts4_word)t3, (ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t4;
    t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t5) + 40))))((ts4_word)a1, (ts4_word)t4, (ts4_word)t3, (ts4_word)0, (ts4_word)t5);
    return 1;
}

/* Swing_DLL.xex 0x881C3D30: addr lbl_88C69D98 */
ts4_word ts4_addr_lbl_88C69D98_881C3D30(void)
{
    return (ts4_word)lbl_88C69D98;
}

/* Swing_DLL.xex 0x881C3E38: addr lbl_88C69DB4 */
ts4_word ts4_addr_lbl_88C69DB4_881C3E38(void)
{
    return (ts4_word)lbl_88C69DB4;
}

/* Swing_DLL.xex 0x881C3E48: if_call_seq lbl_880E75A8, u32@0x0, fn_881F41E8, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880E75A8_881C3E48(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E75A8;
    fn_881F41E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881C4A20: call_seq fn_8819B0C8, u8@0x22, u8@0x22, u8@0x25, u8@0x25, u32@0x28 */
ts4_word ts4_call_seq_fn_8819B0C8_881C4A20(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    *(unsigned char *)((char *)(ts4_word)(a0) + 37) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 37));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 36));
    return t1;
}

/* Swing_DLL.xex 0x881C5CB0: if_call_seq lbl_880E7620, u32@0x0, u32@lbl_88D41F80, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E7620_881C5CB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7620;
    *(ts4_word *)lbl_88D41F80 = (ts4_word)0;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x881C6208: call_seq u32@0x0, fn_8819B308, fn_881B19A0, u32@0x18, fn_881B18E0 */
ts4_word ts4_call_seq_u32_off0_881C6208(ts4_word a0, ts4_word a1)
{
    ts4_word t4;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)6;
    fn_8819B308((ts4_word)(a0 + 16));
    fn_881B19A0((ts4_word)(a0 + 24));
    t4 = fn_881B18E0((ts4_word)(a0 + 24), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24)), (ts4_word)(a1 + 8));
    return t4;
}

/* Swing_DLL.xex 0x881C6390: call_seq u32@0x380, u32@0x384, u32@0x388, fn_881C6998, fn_881C5F68 */
ts4_word ts4_call_seq_u32_off380_881C6390(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 896) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 900) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 904) = (ts4_word)0;
    fn_881C6998((ts4_word)a0, (ts4_word)16);
    fn_881C5F68((ts4_word)(a0 + 912));
    return a0;
}

/* Swing_DLL.xex 0x881C8A60: if_call_seq u32@0x0, u32@0x4, fn_881C8D98, fn_881C8E18, fn_881C7078 */
ts4_word ts4_if_call_seq_u32_off0_881C8A60(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word loc58[1];
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = fn_881C8D98((ts4_word)t2, (ts4_word)(t1 + 4), (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
    p7 = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        t4 = loc50[0];
        t5 = loc54[0];
        t6 = fn_881C8E18((ts4_word)t2, (ts4_word)(t1 + 4), (ts4_word)t5, (ts4_word)t4);
        p7 = (ts4_word)t6;
    }
    t8 = fn_881C7078((ts4_word)(p7 + 4), (ts4_word)a1);
    return t8;
}

/* Swing_DLL.xex 0x881C8EF8: addr lbl_88C69D2C */
ts4_word ts4_addr_lbl_88C69D2C_881C8EF8(void)
{
    return (ts4_word)lbl_88C69D2C;
}

/* Swing_DLL.xex 0x881C8F08: if_call_seq fn_88199068, fn_881F4108, lbl_880E7750, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_881C8F08(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)84, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E7750;
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x881C8F88: if_call_seq fn_881F4108, lbl_880E7750, u32@0x0 */
ts4_word ts4_if_call_seq_fn_881F4108_881C8F88(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7750;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881C8FE8: addr lbl_88C69D48 */
ts4_word ts4_addr_lbl_88C69D48_881C8FE8(void)
{
    return (ts4_word)lbl_88C69D48;
}

/* Swing_DLL.xex 0x881C8FF8: if_call_seq lbl_880E7750, u32@0x0, fn_881F41E8, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880E7750_881C8FF8(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7750;
    fn_881F41E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881C9420: call_seq fn_8819B0C8, u8@0x22, u8@0x22, u32@0x34, u32@0x34, u32@0x38 */
ts4_word ts4_call_seq_fn_8819B0C8_881C9420(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    *(float *)((char *)(ts4_word)(a0) + 36) = (*(float *)((char *)(ts4_word)(a1) + 36));
    *(float *)((char *)(ts4_word)(a0) + 40) = (*(float *)((char *)(ts4_word)(a1) + 40));
    *(float *)((char *)(ts4_word)(a0) + 44) = (*(float *)((char *)(ts4_word)(a1) + 44));
    *(float *)((char *)(ts4_word)(a0) + 48) = (*(float *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 64));
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 68));
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 72));
    return t1;
}

/* Swing_DLL.xex 0x881CB680: addr lbl_88C69CF8 */
ts4_word ts4_addr_lbl_88C69CF8_881CB680(void)
{
    return (ts4_word)lbl_88C69CF8;
}

/* Swing_DLL.xex 0x881CB790: addr lbl_88C69D14 */
ts4_word ts4_addr_lbl_88C69D14_881CB790(void)
{
    return (ts4_word)lbl_88C69D14;
}

/* Swing_DLL.xex 0x881CB7A0: if_call_seq lbl_880E7810, u32@0x0, fn_881F41E8, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880E7810_881CB7A0(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7810;
    fn_881F41E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881CBAA8: addr lbl_88C69CC4 */
ts4_word ts4_addr_lbl_88C69CC4_881CBAA8(void)
{
    return (ts4_word)lbl_88C69CC4;
}

/* Swing_DLL.xex 0x881CBAB8: if_call_seq fn_88199068, fn_881F4108, lbl_880E78A8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_881CBAB8(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)52, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E78A8;
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x881CBB38: if_call_seq fn_881F4108, lbl_880E78A8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_881F4108_881CBB38(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E78A8;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881CBB98: addr lbl_88C69CE0 */
ts4_word ts4_addr_lbl_88C69CE0_881CBB98(void)
{
    return (ts4_word)lbl_88C69CE0;
}

/* Swing_DLL.xex 0x881CBBA8: if_call_seq lbl_880E78A8, u32@0x0, fn_881F41E8, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880E78A8_881CBBA8(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E78A8;
    fn_881F41E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881CBD88: call_seq fn_8819B0C8, u8@0x22, u8@0x22, u32@0x24, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_fn_8819B0C8_881CBD88(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    return t1;
}

/* Swing_DLL.xex 0x881CC1E8: addr lbl_88C69C80 */
ts4_word ts4_addr_lbl_88C69C80_881CC1E8(void)
{
    return (ts4_word)lbl_88C69C80;
}

/* Swing_DLL.xex 0x881CC1F8: if_call_seq fn_88199068, fn_881F4108, lbl_880E7990, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_881CC1F8(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)76, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E7990;
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x881CC278: if_call_seq fn_881F4108, lbl_880E7990, u32@0x0 */
ts4_word ts4_if_call_seq_fn_881F4108_881CC278(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7990;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881CC2D8: addr lbl_88C69C9C */
ts4_word ts4_addr_lbl_88C69C9C_881CC2D8(void)
{
    return (ts4_word)lbl_88C69C9C;
}

/* Swing_DLL.xex 0x881CC550: if_call_seq lbl_880E7990, u32@0x0, fn_881F41E8, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880E7990_881CC550(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7990;
    fn_881F41E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881CC998: call_seq fn_8819B0C8, u8@0x22, u8@0x22 */
ts4_word ts4_call_seq_fn_8819B0C8_881CC998(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    *(float *)((char *)(ts4_word)(a0) + 36) = (*(float *)((char *)(ts4_word)(a1) + 36));
    *(float *)((char *)(ts4_word)(a0) + 40) = (*(float *)((char *)(ts4_word)(a1) + 40));
    *(float *)((char *)(ts4_word)(a0) + 44) = (*(float *)((char *)(ts4_word)(a1) + 44));
    *(float *)((char *)(ts4_word)(a0) + 48) = (*(float *)((char *)(ts4_word)(a1) + 48));
    *(float *)((char *)(ts4_word)(a0) + 52) = (*(float *)((char *)(ts4_word)(a1) + 52));
    return t1;
}

/* Swing_DLL.xex 0x881CCA30: addr lbl_88C69C4C */
ts4_word ts4_addr_lbl_88C69C4C_881CCA30(void)
{
    return (ts4_word)lbl_88C69C4C;
}

/* Swing_DLL.xex 0x881CCA40: if_call_seq fn_88199068, fn_881CCD90 */
ts4_word ts4_if_call_seq_fn_88199068_881CCA40(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)52, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881CCD90((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881CCAB8: addr lbl_88C69C68 */
ts4_word ts4_addr_lbl_88C69C68_881CCAB8(void)
{
    return (ts4_word)lbl_88C69C68;
}

/* Swing_DLL.xex 0x881CCAC8: get  */
float ts4_get_881CCAC8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 32));
}

/* Swing_DLL.xex 0x881CCAD0: get  */
void ts4_get_881CCAD0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 32) = (*(float *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x881CCAE0: get  */
float ts4_get_881CCAE0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 36));
}

/* Swing_DLL.xex 0x881CCAE8: get  */
void ts4_get_881CCAE8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 36) = (*(float *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x881CCAF8: get  */
float ts4_get_881CCAF8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 40));
}

/* Swing_DLL.xex 0x881CCB00: get  */
void ts4_get_881CCB00(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 40) = (*(float *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x881CCB10: get  */
float ts4_get_881CCB10(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 44));
}

/* Swing_DLL.xex 0x881CCB18: get  */
void ts4_get_881CCB18(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 44) = (*(float *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x881CCB28: get  */
float ts4_get_881CCB28(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 48));
}

/* Swing_DLL.xex 0x881CCB30: get  */
void ts4_get_881CCB30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(ts4_word)(a1) + 48) = (*(float *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x881CCE80: call_seq ts4_call_seq_fn_8819B0C8_881CE548 */
ts4_word ts4_call_seq_fn_881CE548_881CCE80(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = ts4_call_seq_fn_8819B0C8_881CE548((ts4_word)a0, (ts4_word)a1);
    *(float *)((char *)(ts4_word)(a0) + 32) = (*(float *)((char *)(ts4_word)(a1) + 32));
    *(float *)((char *)(ts4_word)(a0) + 36) = (*(float *)((char *)(ts4_word)(a1) + 36));
    *(float *)((char *)(ts4_word)(a0) + 40) = (*(float *)((char *)(ts4_word)(a1) + 40));
    *(float *)((char *)(ts4_word)(a0) + 44) = (*(float *)((char *)(ts4_word)(a1) + 44));
    *(float *)((char *)(ts4_word)(a0) + 48) = (*(float *)((char *)(ts4_word)(a1) + 48));
    return t1;
}

/* Swing_DLL.xex 0x881CD1B0: addr lbl_88C69C18 */
ts4_word ts4_addr_lbl_88C69C18_881CD1B0(void)
{
    return (ts4_word)lbl_88C69C18;
}

/* Swing_DLL.xex 0x881CD1C0: if_addr fn_88199068, fn_881F4108, lbl_880E7B80, u32@0x0, fn_881519D0, u32@0x0 */
ts4_word ts4_if_addr_fn_88199068_881CD1C0(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)44, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881F4108((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E7B80;
        t3 = fn_881519D0((ts4_word)t2);
        t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 16))))((ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(t1) + 40) = (ts4_word)(t6 + 16);
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x881CD258: if_addr fn_881F4108, lbl_880E7B80, u32@0x0, fn_881519D0, u32@0x0, u32@0x10 */
ts4_word ts4_if_addr_fn_881F4108_881CD258(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    if ((ts4_word)a0 != 0) {
        t1 = fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7B80;
        t2 = fn_881519D0((ts4_word)t1);
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(t5 + 16);
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881CD2D0: addr lbl_88C69C34 */
ts4_word ts4_addr_lbl_88C69C34_881CD2D0(void)
{
    return (ts4_word)lbl_88C69C34;
}

/* Swing_DLL.xex 0x881CE0D8: addr lbl_88C69BE4 */
ts4_word ts4_addr_lbl_88C69BE4_881CE0D8(void)
{
    return (ts4_word)lbl_88C69BE4;
}

/* Swing_DLL.xex 0x881CE0E8: if_call_seq fn_88199068, ts4_addr_fn_881F7958_88206B20, lbl_880E7C30, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_881CE0E8(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)32, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        ts4_addr_fn_881F7958_88206B20((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E7C30;
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x881CE168: if_call_seq ts4_addr_fn_881F7958_88206B20, lbl_880E7C30, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88206B20_881CE168(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        ts4_addr_fn_881F7958_88206B20((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E7C30;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881CE1C8: addr lbl_88C69C00 */
ts4_word ts4_addr_lbl_88C69C00_881CE1C8(void)
{
    return (ts4_word)lbl_88C69C00;
}

/* Swing_DLL.xex 0x881CE1D8: get  */
float ts4_get_881CE1D8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 16));
}

/* Swing_DLL.xex 0x881CE238: get  */
float ts4_get_881CE238(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 20));
}

/* Swing_DLL.xex 0x881CE298: get  */
float ts4_get_881CE298(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 24));
}

/* Swing_DLL.xex 0x881CE2F8: get  */
float ts4_get_881CE2F8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 28));
}

/* Swing_DLL.xex 0x881CE870: addr lbl_88C69BB0 */
ts4_word ts4_addr_lbl_88C69BB0_881CE870(void)
{
    return (ts4_word)lbl_88C69BB0;
}

/* Swing_DLL.xex 0x881CE880: if_call_seq fn_88199068, fn_881CEB10 */
ts4_word ts4_if_call_seq_fn_88199068_881CE880(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)68, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881CEB10((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881CE8F8: addr lbl_88C69BCC */
ts4_word ts4_addr_lbl_88C69BCC_881CE8F8(void)
{
    return (ts4_word)lbl_88C69BCC;
}

/* Swing_DLL.xex 0x881CE940: addr lbl_880C1320 */
ts4_word ts4_addr_lbl_880C1320_881CE940(void)
{
    return (ts4_word)lbl_880C1320;
}

/* Swing_DLL.xex 0x881D12E0: call_seq u32@0x14, u32@lbl_88D41FC4, fn_881E88D0 */
ts4_word ts4_call_seq_u32_off14_881D12E0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    fn_881E88D0((ts4_word)(*(ts4_word *)lbl_88D41FC4), (ts4_word)t1, (ts4_word)1);
    return 0;
}

/* Swing_DLL.xex 0x881D1318: call_seq u32@0x14, u32@lbl_88D41FC4, fn_881E88D0 */
ts4_word ts4_call_seq_u32_off14_881D1318(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    fn_881E88D0((ts4_word)(*(ts4_word *)lbl_88D41FC4), (ts4_word)t1, (ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x881D1FC8: call_seq u32@0x0, u32@0x4, u32@0x6c, fn_88202CD8 */
ts4_word ts4_call_seq_u32_off0_881D1FC8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    fn_88202CD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 108)), (ts4_word)(t2 + 96));
    return 0;
}

/* Swing_DLL.xex 0x881D3FE0: addr lbl_88C69B4C */
ts4_word ts4_addr_lbl_88C69B4C_881D3FE0(void)
{
    return (ts4_word)lbl_88C69B4C;
}

/* Swing_DLL.xex 0x881D3FF0: if_call_seq fn_88199068, fn_881D4050 */
ts4_word ts4_if_call_seq_fn_88199068_881D3FF0(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)24, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881D4050((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881D46C8: get  */
float ts4_get_881D46C8(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 56));
}

/* Swing_DLL.xex 0x881D46D0: addr lbl_88C69AE4 */
ts4_word ts4_addr_lbl_88C69AE4_881D46D0(void)
{
    return (ts4_word)lbl_88C69AE4;
}

/* Swing_DLL.xex 0x881D46E0: addr lbl_88C69B00 */
ts4_word ts4_addr_lbl_88C69B00_881D46E0(void)
{
    return (ts4_word)lbl_88C69B00;
}

/* Swing_DLL.xex 0x881D46F0: addr lbl_88C69B18 */
ts4_word ts4_addr_lbl_88C69B18_881D46F0(void)
{
    return (ts4_word)lbl_88C69B18;
}

/* Swing_DLL.xex 0x881D4700: if_call_seq fn_88199068, fn_881D4788 */
ts4_word ts4_if_call_seq_fn_88199068_881D4700(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)80, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881D4788((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881D4778: addr lbl_88C69B34 */
ts4_word ts4_addr_lbl_88C69B34_881D4778(void)
{
    return (ts4_word)lbl_88C69B34;
}

/* Swing_DLL.xex 0x881D5200: fn  */
ts4_word ts4_fn_881D5200(ts4_word a0)
{
    return (a0 + 64);
}

/* Swing_DLL.xex 0x881D5208: addr lbl_88C69A78 */
ts4_word ts4_addr_lbl_88C69A78_881D5208(void)
{
    return (ts4_word)lbl_88C69A78;
}

/* Swing_DLL.xex 0x881D52F8: addr lbl_88C69A94 */
ts4_word ts4_addr_lbl_88C69A94_881D52F8(void)
{
    return (ts4_word)lbl_88C69A94;
}

/* Swing_DLL.xex 0x881D5308: if_call_seq lbl_880E8230, u32@0x24, u32@0x0, fn_881F41E8, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880E8230_881D5308(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8230;
    fn_881F41E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881D56E8: call_seq fn_8819B0C8, u8@0x22, u8@0x22, u8@0x38, u8@0x38, u32@0x24 */
ts4_word ts4_call_seq_fn_8819B0C8_881D56E8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    *(float *)((char *)(ts4_word)(a0) + 40) = (*(float *)((char *)(ts4_word)(a1) + 40));
    *(float *)((char *)(ts4_word)(a0) + 44) = (*(float *)((char *)(ts4_word)(a1) + 44));
    *(float *)((char *)(ts4_word)(a0) + 48) = (*(float *)((char *)(ts4_word)(a1) + 48));
    *(float *)((char *)(ts4_word)(a0) + 52) = (*(float *)((char *)(ts4_word)(a1) + 52));
    *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    return t1;
}

/* Swing_DLL.xex 0x881D57B8: if_addr lbl_880E8424, u32@lbl_88D41F80, u32@0x0, u32@0x0, u32@0x8, u32@0x70 */
ts4_word ts4_if_addr_lbl_880E8424_881D57B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)lbl_88D41F80;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8424;
    p6 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 112))))((ts4_word)t1, (ts4_word)t3);
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    return p6;
}

/* Swing_DLL.xex 0x881D5820: addr lbl_88C69A28 */
ts4_word ts4_addr_lbl_88C69A28_881D5820(void)
{
    return (ts4_word)lbl_88C69A28;
}

/* Swing_DLL.xex 0x881D5830: if_call_seq fn_88199068, ts4_addr_fn_88206B20_881D58B8 */
ts4_word ts4_if_call_seq_fn_88199068_881D5830(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)64, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = ts4_addr_fn_88206B20_881D58B8((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881D58A8: addr lbl_88C69A44 */
ts4_word ts4_addr_lbl_88C69A44_881D58A8(void)
{
    return (ts4_word)lbl_88C69A44;
}

/* Swing_DLL.xex 0x881D6950: set u32@0x20 */
void ts4_set_u32_off20_881D6950(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x881D6B08: get u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off0_881D6B08(ts4_word a0, ts4_word a1, ts4_word a2, float f1)
{
    ts4_word t1;

    (void)a1;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(float *)((char *)(ts4_word)(a0) + 60) = f1;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t1) + 32))))((ts4_word)a0, (ts4_word)0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x881D6B20: get u32@0x20 */
ts4_word ts4_get_u32_off20_881D6B20(ts4_word a0, ts4_word a1)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32))) + (a1 << 2)));
}

/* Swing_DLL.xex 0x881D6B30: get u32@0x30 */
ts4_word ts4_get_u32_off30_881D6B30(ts4_word a0, ts4_word a1)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 48)) + ((a1 + (a1 << 1)) << 2));
}

/* Swing_DLL.xex 0x881D6BF8: get u32@0x5c */
ts4_word ts4_get_u32_off5c_881D6BF8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 92));
}

/* Swing_DLL.xex 0x881D6C00: set u32@0x5c */
void ts4_set_u32_off5c_881D6C00(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x881D6C08: addr lbl_88C699F4 */
ts4_word ts4_addr_lbl_88C699F4_881D6C08(void)
{
    return (ts4_word)lbl_88C699F4;
}

/* Swing_DLL.xex 0x881D6C18: if_call_seq fn_88199068, fn_881D6CA0 */
ts4_word ts4_if_call_seq_fn_88199068_881D6C18(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)132, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881D6CA0((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881D6C90: addr lbl_88C69A10 */
ts4_word ts4_addr_lbl_88C69A10_881D6C90(void)
{
    return (ts4_word)lbl_88C69A10;
}

/* Swing_DLL.xex 0x881D6D90: if_call_seq lbl_880E8588, u32@0x38, u32@0x0, fn_8820AC88, u32@0x24, ts4_if_atomic_interlocked_dec_881876D0 */
ts4_word ts4_if_call_seq_lbl_880E8588_881D6D90(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8588;
    fn_8820AC88((ts4_word)(a0 + 40));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t2 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    }
    t5 = fn_881F41E8((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x881D9C90: if_get u32@0xc, u32@0x28, fn_881DA460, u32@0x10, u32@0x384, u32@0x380 */
ts4_word ts4_if_get_u32_offc_881D9C90(ts4_word a0)
{
    ts4_word p8;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;
    ts4_word t12;

    t3 = fn_881DA460((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 40)));
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 900);
    if ((ts4_word)t5 > 0) {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 896));
    } else {
        p8 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t12 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t9) + 140))))((ts4_word)t3, (ts4_word)(p8 + 16), (ts4_word)t10);
    return t12;
}

/* Swing_DLL.xex 0x881DB200: if_call_seq lbl_880E86D8, u32@0x0, fn_881F41E8, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880E86D8_881DB200(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E86D8;
    fn_881F41E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881DB260: addr lbl_88C698F0 */
ts4_word ts4_addr_lbl_88C698F0_881DB260(void)
{
    return (ts4_word)lbl_88C698F0;
}

/* Swing_DLL.xex 0x881DB270: if_call_seq fn_88199068, fn_881F4108, lbl_880E86D8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_881DB270(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)144, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E86D8;
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DB2F0: if_call_seq fn_881F4108, lbl_880E86D8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_881F4108_881DB2F0(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E86D8;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DB350: addr lbl_88C6990C */
ts4_word ts4_addr_lbl_88C6990C_881DB350(void)
{
    return (ts4_word)lbl_88C6990C;
}

/* Swing_DLL.xex 0x881DB360: addr lbl_88C69924 */
ts4_word ts4_addr_lbl_88C69924_881DB360(void)
{
    return (ts4_word)lbl_88C69924;
}

/* Swing_DLL.xex 0x881DB370: if_call_seq fn_88199068, fn_881F4108, u32@0x70, lbl_880E8738, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_881DB370(void)
{
    ts4_word p3;
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)144, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 112) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E8738;
        p3 = (ts4_word)t1;
    } else {
        p3 = (ts4_word)0;
    }
    return p3;
}

/* Swing_DLL.xex 0x881DB3E8: if_call_seq fn_881F4108, lbl_880E8738, u32@0x70, u32@0x0 */
ts4_word ts4_if_call_seq_fn_881F4108_881DB3E8(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8738;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DB450: addr lbl_88C69940 */
ts4_word ts4_addr_lbl_88C69940_881DB450(void)
{
    return (ts4_word)lbl_88C69940;
}

/* Swing_DLL.xex 0x881DB460: addr lbl_88C69958 */
ts4_word ts4_addr_lbl_88C69958_881DB460(void)
{
    return (ts4_word)lbl_88C69958;
}

/* Swing_DLL.xex 0x881DB470: if_call_seq fn_88199068, fn_881F4108, lbl_880E8798, u32@0x70, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_881DB470(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)144, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 112) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E8798;
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DB4F8: if_call_seq fn_881F4108, lbl_880E8798, u32@0x70, u32@0x0 */
ts4_word ts4_if_call_seq_fn_881F4108_881DB4F8(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8798;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DB560: addr lbl_88C69974 */
ts4_word ts4_addr_lbl_88C69974_881DB560(void)
{
    return (ts4_word)lbl_88C69974;
}

/* Swing_DLL.xex 0x881DB570: addr lbl_88C6998C */
ts4_word ts4_addr_lbl_88C6998C_881DB570(void)
{
    return (ts4_word)lbl_88C6998C;
}

/* Swing_DLL.xex 0x881DB580: if_call_seq fn_88199068, fn_881F4108, lbl_880E87F8, u32@0x70, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_881DB580(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)144, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 112) = (ts4_word)2;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E87F8;
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DB608: if_call_seq fn_881F4108, lbl_880E87F8, u32@0x70, u32@0x0 */
ts4_word ts4_if_call_seq_fn_881F4108_881DB608(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E87F8;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DB670: addr lbl_88C699A8 */
ts4_word ts4_addr_lbl_88C699A8_881DB670(void)
{
    return (ts4_word)lbl_88C699A8;
}

/* Swing_DLL.xex 0x881DB680: addr lbl_88C699C0 */
ts4_word ts4_addr_lbl_88C699C0_881DB680(void)
{
    return (ts4_word)lbl_88C699C0;
}

/* Swing_DLL.xex 0x881DB690: if_call_seq fn_88199068, fn_881F4108, lbl_880E8858, u32@0x70, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_881DB690(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)160, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881F4108((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 112) = (ts4_word)3;
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E8858;
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DB718: if_call_seq fn_881F4108, lbl_880E8858, u32@0x70, u32@0x0 */
ts4_word ts4_if_call_seq_fn_881F4108_881DB718(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)3;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8858;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DB780: addr lbl_88C699DC */
ts4_word ts4_addr_lbl_88C699DC_881DB780(void)
{
    return (ts4_word)lbl_88C699DC;
}

/* Swing_DLL.xex 0x881DB790: call_seq fn_881F4D38, lbl_880E7AF4, fn_881CDFE0 */
ts4_word ts4_call_seq_fn_881F4D38_881DB790(ts4_word a0, ts4_word a1)
{
    fn_881F4D38();
    fn_881CDFE0((ts4_word)a1, (ts4_word)(ts4_word)lbl_880E7AF4, (ts4_word)(a0 + 116));
    return 1;
}

/* Swing_DLL.xex 0x881DB800: call_seq fn_8819B0C8, u8@0x22, u8@0x22, u32@0x74, u32@0x74, u32@0x78 */
ts4_word ts4_call_seq_fn_8819B0C8_881DB800(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 116));
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120));
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 124));
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 128));
    return t1;
}

/* Swing_DLL.xex 0x881DB938: set u8@0x24 */
void ts4_set_u8_off24_881DB938(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x881DB948: get u8@0x20 */
ts4_word ts4_get_u8_off20_881DB948(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 32));
}

/* Swing_DLL.xex 0x881DB950: set u32@0x24 */
void ts4_set_u32_off24_881DB950(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x881DB958: tailcall fn_8819B0C8 */
ts4_word ts4_tailcall_fn_8819B0C8_881DB958(ts4_word a0)
{
    return fn_8819B0C8((ts4_word)(a0 + 28));
}

/* Swing_DLL.xex 0x881DB9A0: addr lbl_88C69854 */
ts4_word ts4_addr_lbl_88C69854_881DB9A0(void)
{
    return (ts4_word)lbl_88C69854;
}

/* Swing_DLL.xex 0x881DB9B0: if_call_seq fn_88199068, fn_881DBA10 */
ts4_word ts4_if_call_seq_fn_88199068_881DB9B0(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)40, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881DBA10((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DBAF8: addr lbl_88C69870 */
ts4_word ts4_addr_lbl_88C69870_881DBAF8(void)
{
    return (ts4_word)lbl_88C69870;
}

/* Swing_DLL.xex 0x881DC8C8: call_seq fn_881B19A0, fn_881B19A0, fn_881B19A0, fn_881B19A0, fn_881B19A0, fn_881B19A0 */
ts4_word ts4_call_seq_fn_881B19A0_881DC8C8(ts4_word a0)
{
    ts4_word t7;

    fn_881B19A0((ts4_word)(a0 + 192));
    fn_881B19A0((ts4_word)(a0 + 160));
    fn_881B19A0((ts4_word)(a0 + 128));
    fn_881B19A0((ts4_word)(a0 + 96));
    fn_881B19A0((ts4_word)(a0 + 64));
    fn_881B19A0((ts4_word)(a0 + 32));
    t7 = fn_881B19A0((ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x881DD418: get u32@0x0, u32@0x20, vcall, fn_8819ACC8 */
ts4_word ts4_get_u32_off0_881DD418(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;

    (void)a1;
    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 32))))((ts4_word)a2);
    fn_8819ACC8((ts4_word)a0, (ts4_word)t3);
    return a0;
}

/* Swing_DLL.xex 0x881DD488: addr lbl_88C69888 */
ts4_word ts4_addr_lbl_88C69888_881DD488(void)
{
    return (ts4_word)lbl_88C69888;
}

/* Swing_DLL.xex 0x881DD498: if_call_seq fn_88199068, fn_881DD5E0 */
ts4_word ts4_if_call_seq_fn_88199068_881DD498(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)40, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881DD5E0((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DD510: addr lbl_88C698A4 */
ts4_word ts4_addr_lbl_88C698A4_881DD510(void)
{
    return (ts4_word)lbl_88C698A4;
}

/* Swing_DLL.xex 0x881DD920: if_get fn_8819B0C8, u32@0xc, u32@0x0, u32@0x50, vcall */
ts4_word ts4_if_get_fn_8819B0C8_881DD920(ts4_word a0)
{
    ts4_word p6;
    ts4_word t2;
    ts4_word t5;

    fn_8819B0C8((ts4_word)(a0 + 16));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p6 = (ts4_word)t2;
    if ((int)t2 != 0) {
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 80))))((ts4_word)t2, (ts4_word)1);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x881DDA10: addr lbl_88C698BC */
ts4_word ts4_addr_lbl_88C698BC_881DDA10(void)
{
    return (ts4_word)lbl_88C698BC;
}

/* Swing_DLL.xex 0x881DDA20: if_call_seq fn_88199068, fn_881DDE58 */
ts4_word ts4_if_call_seq_fn_88199068_881DDA20(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)128, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881DDE58((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881DDA98: addr lbl_88C698D8 */
ts4_word ts4_addr_lbl_88C698D8_881DDA98(void)
{
    return (ts4_word)lbl_88C698D8;
}

/* Swing_DLL.xex 0x881DDAA8: get u32@0x2c */
ts4_word ts4_get_u32_off2c_881DDAA8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 44));
}

/* Swing_DLL.xex 0x881DDAC8: get u32@0x4c */
ts4_word ts4_get_u32_off4c_881DDAC8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 76));
}

/* Swing_DLL.xex 0x881DDAD0: get u32@0x40 */
ts4_word ts4_get_u32_off40_881DDAD0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 64));
}

/* Swing_DLL.xex 0x881DDAD8: get u32@0x34 */
ts4_word ts4_get_u32_off34_881DDAD8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 52));
}

/* Swing_DLL.xex 0x881DDAE0: get u32@0x0, u32@0x34 */
void ts4_get_u32_off0_881DDAE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x881DDE20: call_seq lbl_88D41F9C, fn_881B19A0, lbl_88C698A4, fn_881F8B58 */
ts4_word ts4_call_seq_lbl_88D41F9C_881DDE20(void)
{
    ts4_word t2;

    fn_881B19A0((ts4_word)(ts4_word)lbl_88D41F9C);
    t2 = fn_881F8B58((ts4_word)(ts4_word)lbl_88C698A4);
    return t2;
}

/* Swing_DLL.xex 0x881DF038: get u32@0x0, u32@0x50 */
ts4_word ts4_get_u32_off0_881DF038(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 80))))((ts4_word)a0, (ts4_word)1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x881E0B80: if_call_seq lbl_880E7494, lbl_880C1320, ts4_assign_text_from_c_string, u32@0x70, u32@-0xc, fn_8819B2A0 */
ts4_word ts4_if_call_seq_lbl_880E7494_881E0B80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p1;
    ts4_word t3;
    ts4_word t7;

    if ((ts4_word)(a3 & 0xff) != 0) {
        p1 = (ts4_word)(ts4_word)lbl_880E7494;
    } else {
        p1 = (ts4_word)(ts4_word)lbl_880C1320;
    }
    ts4_assign_text_from_c_string((ts4_word)a0, (ts4_word)p1);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 112);
    fn_8819B2A0((ts4_word)a0, (ts4_word)t3, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + -12)));
    fn_8819B1A8((ts4_word)a0, (ts4_word)(ts4_word)lbl_880D35C0);
    t7 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    fn_8819B2A0((ts4_word)a0, (ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + -12)));
    return a0;
}

/* Swing_DLL.xex 0x881E1B68: if_get u32@0x10, u32@0xc, u32@0x384, u32@0x28, u32@0x380, u32@g_ts4_default_script_value */
ts4_word ts4_if_get_u32_off10_881E1B68(ts4_word a0)
{
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 900);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 40);
    if ((ts4_word)t3 > 0) {
        p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 896));
    } else {
        p7 = (ts4_word)(*(ts4_word *)g_ts4_default_script_value);
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t8) + 92))))((ts4_word)t4, (ts4_word)(p7 + 16), (ts4_word)t9);
}

/* Swing_DLL.xex 0x881E1DE0: if_call_seq u32@0x4, u32@0x8, fn_881F26C0, u32@0x4, fn_881992A8, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off4_881E1DE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word p7;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p7 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t3 = fn_881F26C0((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        p6 = (ts4_word)t3;
        if ((ts4_word)t4 != 0) {
            t5 = fn_881992A8((ts4_word)0, (ts4_word)t4);
            p6 = (ts4_word)t5;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p7 = (ts4_word)p6;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p7;
}

/* Swing_DLL.xex 0x881E1F00: addr lbl_88C69820 */
ts4_word ts4_addr_lbl_88C69820_881E1F00(void)
{
    return (ts4_word)lbl_88C69820;
}

/* Swing_DLL.xex 0x881E1F98: if_call_seq fn_8820FD80, lbl_880E8C58, u8@0x48, u32@0x0, u32@0x4c, u32@0x50 */
ts4_word ts4_if_call_seq_fn_8820FD80_881E1F98(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_8820FD80((ts4_word)a0);
        *(unsigned char *)((char *)(ts4_word)(a0) + 72) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E8C58;
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881E2010: addr lbl_88C6983C */
ts4_word ts4_addr_lbl_88C6983C_881E2010(void)
{
    return (ts4_word)lbl_88C6983C;
}

/* Swing_DLL.xex 0x881E2020: if_call_seq u32@0x50, fn_881992A8, u32@0x44, ts4_if_atomic_interlocked_dec_881876D0, u32@0x44, fn_881CCDF0 */
ts4_word ts4_if_call_seq_u32_off50_881E2020(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t1 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t4 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    }
    fn_881CCDF0((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881E20A8: call_seq fn_8820FE68, u8@0x48 */
ts4_word ts4_call_seq_fn_8820FE68_881E20A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8820FE68((ts4_word)a0, (ts4_word)a1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 72) = (unsigned char)0;
    return t1;
}

/* Swing_DLL.xex 0x881E92B0: get u32@lbl_88D41FC4, fn_881E92C0 */
ts4_word ts4_get_u32_lbl_88D41FC4_881E92B0(ts4_word a0)
{
    return fn_881E92C0((ts4_word)(*(ts4_word *)lbl_88D41FC4), (ts4_word)a0);
}

/* Swing_DLL.xex 0x881EC030: tailcall fn_8819B0C8 */
ts4_word ts4_tailcall_fn_8819B0C8_881EC030(ts4_word a0)
{
    return fn_8819B0C8((ts4_word)(a0 + 100));
}

/* Swing_DLL.xex 0x881EC418: if_call_seq u32@0x0, lbl_880E9154, ts4_tailcall_fn_885655E8_88565748, lbl_880E9158, fn_88569190, fn_881EC4A0 */
ts4_word ts4_if_call_seq_u32_off0_881EC418(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t4;

    t2 = ts4_tailcall_fn_885655E8_88565748((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)(ts4_word)lbl_880E9154);
    if ((ts4_word)t2 == 0) {
        return t2;
    }
    fn_88569190((ts4_word)t2, (ts4_word)(ts4_word)lbl_880E9158);
    t4 = fn_881EC4A0((ts4_word)a0, (ts4_word)t2, (ts4_word)0, (ts4_word)a2, (ts4_word)0);
    fn_88569190((ts4_word)t2, (ts4_word)(ts4_word)lbl_880E9168);
    fn_88566FE8((ts4_word)t2);
    return t4;
}

/* Swing_DLL.xex 0x881ED4C8: if_call_seq u32@0x0, u32@0x0, u32@-0xc, u32@-0xc, fn_885630C0 */
ts4_word ts4_if_call_seq_u32_off0_881ED4C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + -12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + -12);
    if ((int)t3 != (int)t4) {
        return 1;
    }
    t5 = fn_885630C0((ts4_word)t1, (ts4_word)t2, (ts4_word)t3);
    return (t5 != 0);
}

/* Swing_DLL.xex 0x881EDD30: call_seq fn_881FBA58, u32@0x4, u32@0x0 */
ts4_word ts4_call_seq_fn_881FBA58_881EDD30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc58[1];
    ts4_word t1;

    t1 = fn_881FBA58((ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return a0;
}

/* Swing_DLL.xex 0x881F0538: if_call_seq lbl_880E9378, u32@0x0, fn_881F0598, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880E9378_881F0538(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9378;
    fn_881F0598((ts4_word)(a0 + 4));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881F06C8: addr lbl_88C69804 */
ts4_word ts4_addr_lbl_88C69804_881F06C8(void)
{
    return (ts4_word)lbl_88C69804;
}

/* Swing_DLL.xex 0x881F0A98: addr lbl_88C697D0 */
ts4_word ts4_addr_lbl_88C697D0_881F0A98(void)
{
    return (ts4_word)lbl_88C697D0;
}

/* Swing_DLL.xex 0x881F0AA8: if_call_seq fn_88199068, fn_881F1060 */
ts4_word ts4_if_call_seq_fn_88199068_881F0AA8(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)72, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881F1060((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881F0B20: addr lbl_88C697EC */
ts4_word ts4_addr_lbl_88C697EC_881F0B20(void)
{
    return (ts4_word)lbl_88C697EC;
}

/* Swing_DLL.xex 0x881F0BF8: if_call_seq ts4_if_get_u32_off24_881F1598, u32@0x0, fn_8818EB10, ts4_if_atomic_interlocked_dec_881876D0 */
ts4_word ts4_if_call_seq_fn_881F1598_881F0BF8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t4;

    (void)a1;
    t1 = ts4_if_get_u32_off24_881F1598((ts4_word)(ts4_word)&loc50[0], (ts4_word)a2);
    fn_8818EB10((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0)) + 12));
    t4 = loc50[0];
    if ((ts4_word)t4 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t4);
    }
    return a0;
}

/* Swing_DLL.xex 0x881F1410: if_get u32@0x24, fn_881F07F8, u32@0x0, u32@0x28, vcall */
ts4_word ts4_if_get_u32_off24_881F1410(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p6;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    t2 = fn_881F07F8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    p6 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t5 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)t2, (ts4_word)a2);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x881F1720: get u32@0x3c */
ts4_word ts4_get_u32_off3c_881F1720(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 60)) + -1) == 0);
}

/* Swing_DLL.xex 0x881F1738: set u32@0x3c */
void ts4_set_u32_off3c_881F1738(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)((a1 & 0xff) != 0);
    return;
}
