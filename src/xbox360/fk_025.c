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

extern char g_ts4_session_context[];
extern char lbl_880CF0C7[];
extern char lbl_880CFC4E[];
extern char lbl_880D0830[];
extern char lbl_880D19F0[];
extern char lbl_880D5A64[];
extern char lbl_880D6B70[];
extern char lbl_880D6D50[];
extern char lbl_880D7058[];
extern char lbl_880D7074[];
extern char lbl_880D72B0[];
extern char lbl_880DB278[];
extern char lbl_880DB300[];
extern char lbl_880DB350[];
extern char lbl_880DB358[];
extern char lbl_880DB450[];
extern char lbl_880DB478[];
extern char lbl_880DB4E0[];
extern char lbl_880DB580[];
extern char lbl_880DB620[];
extern char lbl_880DB6C0[];
extern char lbl_880DB76C[];
extern char lbl_880DB7BC[];
extern char lbl_880DB7E4[];
extern char lbl_880DBD30[];
extern char lbl_8814B440[];
extern char lbl_88C6B4AC[];
extern char lbl_88C6B910[];
extern char lbl_88C6B914[];
extern char lbl_88C6B918[];
extern char lbl_88C6B91C[];
extern char lbl_88C6B920[];
extern char lbl_88C6B924[];
extern char lbl_88C6B928[];
extern char lbl_88C6B92C[];
extern char lbl_88C6B930[];
extern char lbl_88D3CD50[];
extern char lbl_88D45908[];
extern char lbl_88D4590C[];
extern char lbl_88D45914[];
extern char lbl_88D4592C[];
extern char lbl_88D45938[];
extern char lbl_88D45944[];
extern char lbl_88D45960[];
extern char lbl_88D459DC[];
extern char lbl_88D459E0[];
extern char lbl_88D45AD4[];
extern char lbl_88D45AF4[];
extern char lbl_88D45AF8[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
extern char lbl_88D45CC0[];
extern char lbl_88D46350[];
extern char lbl_88D4BD24[];
extern char lbl_88D4BD34[];
ts4_word fn_88150310();
ts4_word fn_8816D1A8();
ts4_word fn_881705B0();
ts4_word fn_88174B90();
ts4_word fn_88174C40();
ts4_word fn_88177110();
ts4_word fn_88178C40();
ts4_word fn_8817E720();
ts4_word fn_881816D8();
ts4_word fn_881882D0();
ts4_word fn_881A6A00();
ts4_word fn_881B9148();
ts4_word ts4_if_atomic_interlocked_dec_88288530();
ts4_word fn_882908C0();
ts4_word fn_88290C68();
ts4_word fn_8841B618();
ts4_word ts4_tailcall_fn_885827E0_88563110();
ts4_word fn_8857A1E0();
ts4_word fn_8857B598();
ts4_word fn_8860BBD8();
ts4_word fn_8860DCF8();
ts4_word fn_88613268();
ts4_word fn_88614938();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_886220F8();
ts4_word fn_8862BE08();
ts4_word fn_8862C0E8();
ts4_word fn_886E0E60();
ts4_word fn_886F1FC0();
ts4_word fn_8883B578();
ts4_word ts4_if_call_seq_u32_lbl_88D459E4_8883F238();
ts4_word fn_8886B8E0();
ts4_word fn_8886FE50();
ts4_word fn_8886FED0();
ts4_word fn_88870500();
ts4_word fn_888705A0();
ts4_word fn_88871108();
ts4_word fn_888718A8();
ts4_word fn_88871A50();
ts4_word fn_88871BD8();
ts4_word fn_888860A0();
ts4_word fn_888C04D8();
ts4_word fn_888C39A0();
ts4_word fn_888C6FE0();
ts4_word fn_888CB3F0();
ts4_word fn_888CC2C8();
ts4_word fn_888CC890();
ts4_word fn_888CCCC8();
ts4_word fn_888CEBA8();
ts4_word fn_888D3330();
ts4_word fn_888D3648();
ts4_word fn_888D73B0();
ts4_word fn_888D8078();
ts4_word fn_888DA428();
ts4_word fn_888DA698();
ts4_word fn_888DA850();
ts4_word fn_888DDA80();
ts4_word fn_888DF008();
ts4_word fn_888E38A8();
ts4_word fn_888E3908();
ts4_word fn_888F14D8();
ts4_word fn_888F4E70();
ts4_word fn_888F70A0();
ts4_word fn_888FBEB0();
ts4_word fn_88901010();
ts4_word fn_88901810();
ts4_word fn_88904C40();
ts4_word fn_88906EE8();
ts4_word fn_88907128();
ts4_word fn_88908258();
ts4_word fn_88908B80();
ts4_word fn_8890F008();
ts4_word fn_88912090();
ts4_word fn_889124A8();
ts4_word fn_88915DC8();
ts4_word fn_88917490();
ts4_word fn_88917CF0();
ts4_word fn_88917EE0();
ts4_word fn_88917FC8();
ts4_word fn_88918908();
ts4_word fn_889189B0();
ts4_word fn_88918EA8();
ts4_word fn_889254C8();
ts4_word fn_8892AF80();
ts4_word fn_8892AFF0();
ts4_word fn_88936BB0();
ts4_word fn_88938660();
ts4_word fn_889393C0();
ts4_word fn_88939470();
ts4_word fn_889395D8();
ts4_word fn_889396A8();
ts4_word fn_8893B328();
ts4_word ts4_read_scaled_counter_8893C808();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x888C2A88: get u32@0x40, u32@0x54, u32@0x0 */
ts4_word ts4_get_u32_off40_888C2A88(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    return (t2 - (*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
}

/* Swing_DLL.xex 0x888C2B30: get u32@0x1c, fn_8886FE50 */
ts4_word ts4_get_u32_off1c_888C2B30(ts4_word a0)
{
    return fn_8886FE50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x888C2B38: get u32@0x1c, fn_8886FED0 */
ts4_word ts4_get_u32_off1c_888C2B38(ts4_word a0)
{
    return fn_8886FED0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x888C2DF8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_888C2DF8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)-1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888C2E38: get u32@0x8, u32@0x4c */
ts4_word ts4_get_u32_off8_888C2E38(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 76))))((ts4_word)(a0 + 8), (ts4_word)0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x888C2E50: fn  */
ts4_word ts4_fn_888C2E50(void)
{
    return 1;
}

/* Swing_DLL.xex 0x888C3028: if_get u32@0x10, u32@0x30, vcall, u32@0x8, u32@lbl_88D4592C, u32@0x28 */
ts4_word ts4_if_get_u32_off10_888C3028(ts4_word a0)
{
    ts4_word p17;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t9;
    ts4_word t16;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 48))))((ts4_word)(a0 + 16));
    p17 = (ts4_word)t3;
    if ((ts4_word)(t3 & 0xff) != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t6 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D4592C)) + 40);
        t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 36))))((ts4_word)t6, (ts4_word)t4, (ts4_word)0);
        if ((ts4_word)t9 != 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 0))))((ts4_word)t9, (ts4_word)1);
        }
        t16 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 16)) + 0))) + 20))))((ts4_word)(a0 + 16));
        p17 = (ts4_word)t16;
    }
    return p17;
}

/* Swing_DLL.xex 0x888C30D0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_set_u32_off0_888C30D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888C32B0: if_call_seq ts4_find_service, fn_8841B618 */
ts4_word ts4_if_call_seq_ts4_find_service_888C32B0(void)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_find_service((ts4_word)((1680605184) | 34887));
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8841B618((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x888C34A8: get u32@lbl_88D45908, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_lbl_88D45908_888C34A8(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45908;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
}

/* Swing_DLL.xex 0x888C3A00: if_call_seq fn_888C39A0, u32@lbl_88D4590C */
ts4_word ts4_if_call_seq_fn_888C39A0_888C3A00(ts4_word a0)
{
    ts4_word p4;
    ts4_word t1;

    t1 = fn_888C39A0((ts4_word)a0);
    p4 = (ts4_word)0;
    if ((int)t1 != -1) {
        p4 = (ts4_word)((t1 << 5) + (*(ts4_word *)lbl_88D4590C));
    }
    return p4;
}

/* Swing_DLL.xex 0x888C3B30: get u32@0x80, u8@0x59, u32@0x80, u8@0x5a, u32@0x80, u8@0x55 */
void ts4_get_u32_off80_888C3B30(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 89) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 90) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 85) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 87) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 252) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 258) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 257) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 128))) + 64) = (ts4_word)((1621229568) | 50229);
    *(unsigned char *)((char *)(ts4_word)(a0) + 188) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 189) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x888C3CA8: if_get u32@0x30, u32@0x1c */
void ts4_if_get_u32_off30_888C3CA8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((int)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 28) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x888C3CC0: if_get u32@0x34, u8@0x1, u32@0x30, u32@0x1c, u32@0x34, u8@0x1 */
void ts4_if_get_u32_off34_888C3CC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    unsigned char t2;
    ts4_word t3;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((int)t1 == 0) {
        return;
    }
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 1);
    if ((ts4_word)t2 != 1) {
        return;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((int)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 28) = (ts4_word)((2991849472) | 16214);
    }
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 52))) + 1) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888C41F0: if_get u8@0x9b, u32@0x10 */
ts4_word ts4_if_get_u8_off9b_888C41F0(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 155);
    if ((ts4_word)t1 == 1) {
        return ((a1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 16))) == 0);
    }
    return 0;
}

/* Swing_DLL.xex 0x888C42B8: if_get ts4_find_service, u32@0x0, u32@0x4c, vcall, u32@0x20 */
ts4_word ts4_if_get_ts4_find_service_888C42B8(ts4_word a0)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t4;

    t1 = ts4_find_service((ts4_word)((3626237952) | 45703));
    p5 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t4;
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x888C4310: get u32@0x34, u8@0x7c, u32@0x90, u32@0xa0 */
void ts4_get_u32_off34_888C4310(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 52))) + 124) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888C4330: get u32@0x2c, u32@0x0, u32@0x44, u32@0x10, u32@0x68, u32@0x68 */
void ts4_get_u32_off2c_888C4330(ts4_word a0)
{
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 0) = (ts4_word)((375062528) | 48617);
    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 68))) + 16);
    *(ts4_word *)((char *)(ts4_word)(t3) + 104) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 104)) + 1);
    return;
}

/* Swing_DLL.xex 0x888C4358: get u32@0x44, u32@0x20, u32@0x20 */
void ts4_get_u32_off44_888C4358(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    *(ts4_word *)((char *)(ts4_word)(t1) + 32) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 32)) + 1);
    return;
}

/* Swing_DLL.xex 0x888C4370: get u32@0x10, u32@0x24 */
void ts4_get_u32_off10_888C4370(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 36) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x888C4380: get ts4_find_service, u32@0x0, u32@0x4c, vcall, u32@0x10 */
ts4_word ts4_get_ts4_find_service_888C4380(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = ts4_find_service((ts4_word)((1670447104) | 60230));
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t4;
    return t4;
}

/* Swing_DLL.xex 0x888C45E8: get ts4_find_service, u32@0x0, u32@0x4c, vcall, u32@0x30 */
ts4_word ts4_get_ts4_find_service_888C45E8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = ts4_find_service((ts4_word)((1670447104) | 60230));
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)t4;
    return t4;
}

/* Swing_DLL.xex 0x888C46F8: tailcall ts4_find_service */
ts4_word ts4_tailcall_ts4_find_service_888C46F8(void)
{
    return ts4_find_service((ts4_word)((1077805056) | 43548));
}

/* Swing_DLL.xex 0x888C5320: get u32@lbl_88D45AD4, u32@0x6c, fn_886F1FC0 */
ts4_word ts4_get_u32_lbl_88D45AD4_888C5320(void)
{
    return fn_886F1FC0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 108)), (ts4_word)((2056912896) | 51182));
}

/* Swing_DLL.xex 0x888C54C0: get u32@lbl_88D45B1C, u32@0x234, fn_88614938 */
ts4_word ts4_get_u32_lbl_88D45B1C_888C54C0(ts4_word a0)
{
    return fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)a0);
}

/* Swing_DLL.xex 0x888C55F8: if_get u32@0x54, u32@0x54, u8@0x5d */
void ts4_if_get_u32_off54_888C55F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((int)t1 != -1) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)a1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 93) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x888C56D8: if_call_seq u32@0x2c, u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off2c_888C56D8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t4 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)t1);
    if ((ts4_word)t4 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t4) + 16));
    }
    return -1;
}

/* Swing_DLL.xex 0x888C5750: get u32@0x60, u32@0x0 */
void ts4_get_u32_off60_888C5750(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 96))) + 0) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x888C61C0: if_addr lbl_88D4BD24, u32@lbl_88D4BD34, u32@lbl_88D4BD34, u32@0x0, u32@0x4, u32@0x8 */
void ts4_if_addr_lbl_88D4BD24_888C61C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    ts4_word t5;

    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)lbl_88D4BD34;
    if ((ts4_word)(t1 & 0x1) == 0) {
        *(ts4_word *)lbl_88D4BD34 = (ts4_word)(t1 | 1);
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D4BD24) + 0) = (ts4_word)((3751936000) | 45041);
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D4BD24) + 4) = (ts4_word)((966918144) | 43504);
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D4BD24) + 8) = (ts4_word)((1815281664) | 16157);
        *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D4BD24) + 12) = (ts4_word)((375062528) | 48617);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    *(ts4_word *)((char *)(ts4_word)(t5) + 620) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + (ts4_word)lbl_88D4BD24));
    return;
}

/* Swing_DLL.xex 0x888C6308: set u8@0x140 */
void ts4_set_u8_off140_888C6308(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 320) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x888C6310: get u32@0x1c, fn_88870500 */
ts4_word ts4_get_u32_off1c_888C6310(ts4_word a0)
{
    return fn_88870500((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x888C6318: get u32@0x1c, fn_888705A0 */
ts4_word ts4_get_u32_off1c_888C6318(ts4_word a0)
{
    return fn_888705A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x888C6C28: get u32@0x0, u32@0x4, u32@0x0, u32@0x8 */
void ts4_get_u32_off0_888C6C28(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x888C7228: set u32@lbl_88D46350 */
void ts4_set_u32_lbl_88D46350_888C7228(ts4_word a0)
{
    *(ts4_word *)lbl_88D46350 = (ts4_word)a0;
    return;
}

/* Swing_DLL.xex 0x888C7238: if_get ts4_find_service, u32@0x0, u32@0x30, vcall, u32@0x0, u32@0x4c */
ts4_word ts4_if_get_ts4_find_service_888C7238(void)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    t1 = ts4_find_service((ts4_word)((2354708480) | 18722));
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 48))))((ts4_word)t1);
    p8 = (ts4_word)t4;
    if ((ts4_word)(t4 & 0xff) != 0) {
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)0);
        *(unsigned char *)((char *)(ts4_word)(t7) + 1926) = (unsigned char)0;
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x888C72A8: if_call_seq ts4_find_service, u8@0x20 */
ts4_word ts4_if_call_seq_ts4_find_service_888C72A8(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_find_service((ts4_word)((1540030464) | 58561));
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t1) + 32) = (unsigned char)a0;
    }
    return t1;
}

/* Swing_DLL.xex 0x888C7318: if_call_seq ts4_find_service, u8@0x8 */
ts4_word ts4_if_call_seq_ts4_find_service_888C7318(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_find_service((ts4_word)((4250861568) | 29032));
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(t1) + 8) = (unsigned char)a0;
    }
    return t1;
}

/* Swing_DLL.xex 0x888C7358: set u8@0x34 */
void ts4_set_u8_off34_888C7358(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888C74C0: addr lbl_88D45CC0, u8@0x8 */
void ts4_addr_lbl_88D45CC0_888C74C0(void)
{
    *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 8) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x888C74D8: addr lbl_88D45CC0, u8@0x8 */
void ts4_addr_lbl_88D45CC0_888C74D8(void)
{
    *(unsigned char *)((char *)(ts4_word)((ts4_word)lbl_88D45CC0) + 8) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x888C7980: call_seq fn_88617D88, lbl_880DB4E0, u8@0x20, u32@0x0, u8@0x21, u32@0x1c */
ts4_word ts4_call_seq_fn_88617D88_888C7980(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB4E0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 33) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888C7F30: call_seq fn_88617D88, lbl_880DB450, u32@0x0, u32@0x20, u32@0x1c, u32@lbl_88D45960 */
ts4_word ts4_call_seq_fn_88617D88_888C7F30(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB450;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)55;
    *(ts4_word *)lbl_88D45960 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x888C8138: call_seq u32@0x20, u32@0x1c, ts4_object_finalize, u8@0x8, fn_881B9148 */
ts4_word ts4_call_seq_u32_off20_888C8138(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)-1;
    ts4_object_finalize((ts4_word)(a0 + 52));
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t2 = fn_881B9148((ts4_word)(a0 + 16));
    return t2;
}

/* Swing_DLL.xex 0x888CA040: call_seq u32@lbl_88C6B920, fn_88901010, u32@lbl_88C6B920, u32@0x8 */
ts4_word ts4_call_seq_u32_lbl_88C6B920_888CA040(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_88901010((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C6B920));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B920);
    return t2;
}

/* Swing_DLL.xex 0x888CA088: if_call_seq u32@0x10, u32@0x68, u32@0x10, u32@0x6c, u32@0xc, u32@0x48 */
ts4_word ts4_if_call_seq_u32_off10_888CA088(ts4_word a0)
{
    ts4_word p14;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(t1) + 104) = (ts4_word)-1;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(t2) + 108) = (ts4_word)-1;
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 72);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
    *(ts4_word *)((char *)(ts4_word)(t4) + 96) = (ts4_word)-1;
    t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 68);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 16))) + 112) = (ts4_word)-1;
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t9 = *(ts4_word *)lbl_88C6B910;
    t10 = *(ts4_word *)((char *)(ts4_word)(t8) + 36);
    p14 = (ts4_word)t8;
    if ((ts4_word)t10 != (ts4_word)t9) {
        t11 = fn_88901010((ts4_word)a0, (ts4_word)t9, (ts4_word)t6, (ts4_word)t5, (ts4_word)t4, (ts4_word)t3, (ts4_word)t2, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B910);
        p14 = (ts4_word)t11;
    }
    return p14;
}

/* Swing_DLL.xex 0x888CA4E0: call_seq fn_88617D88, lbl_880DB278, u32@0x1c, u32@0x0, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_888CA4E0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB278;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)240;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888CA720: call_seq u32@lbl_88D459E0, fn_8883B578, u32@0x4 */
ts4_word ts4_call_seq_u32_lbl_88D459E0_888CA720(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    t2 = fn_8883B578((ts4_word)(*(ts4_word *)lbl_88D459E0), (ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)a1;
    return t2;
}

/* Swing_DLL.xex 0x888CAA40: call_seq fn_88617D88, lbl_880DB7BC, u32@0x1c, u32@0x0, u32@0x20, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_888CAA40(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB7BC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)lbl_88D45944 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x888CB0F0: call_seq fn_88617D88, lbl_880DB76C, u8@0x1c, u32@0x0, u8@0x30 */
ts4_word ts4_call_seq_fn_88617D88_888CB0F0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB76C;
    *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x888CB3A8: if_call_seq u32@0x48, fn_888860A0, u32@0x48, u32@0x4c */
ts4_word ts4_if_call_seq_u32_off48_888CB3A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Swing_DLL.xex 0x888CB978: call_seq fn_88617D88, lbl_880DB620, u32@0x20, u32@0x0, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_fn_88617D88_888CB978(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB620;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)lbl_88D45938 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x888CCB50: if_call_seq u32@0x68, fn_889254C8, u32@0x68 */
ts4_word ts4_if_call_seq_u32_off68_888CCB50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_889254C8((ts4_word)t1, (ts4_word)1);
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x888CCE88: if_call_seq fn_888CCCC8, fn_888C6FE0 */
ts4_word ts4_if_call_seq_fn_888CCCC8_888CCE88(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    loc50[3] = (ts4_word)0;
    loc50[4] = (ts4_word)0;
    loc50[5] = (ts4_word)0;
    t1 = fn_888CCCC8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)(t1 & 0xff) != 0) {
        t2 = loc50[5];
        fn_888C6FE0((ts4_word)t2);
    }
    return 1;
}

/* Swing_DLL.xex 0x888CD390: if_call_seq u32@0x20, ts4_destroy_owned_object, u32@0x14, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off20_888CD390(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x888CDDC0: call_seq fn_88617D88, lbl_880DB300, u32@0x0, u8@0x1c, u32@lbl_88D45914 */
ts4_word ts4_call_seq_fn_88617D88_888CDDC0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB300;
    *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)0;
    *(ts4_word *)lbl_88D45914 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x888CF0D8: call_seq fn_88617D88, lbl_880DBD30, u32@0x2c, u32@0x0, u32@0x30, u32@0x34 */
ts4_word ts4_call_seq_fn_88617D88_888CF0D8(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DBD30;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888D3808: call_seq u32@0x44, u32@lbl_88C6B920, fn_88901010, u32@lbl_88C6B920, u32@0x8, u32@0x40 */
ts4_word ts4_call_seq_u32_off44_888D3808(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t3 = fn_88901010((ts4_word)t1, (ts4_word)(*(ts4_word *)lbl_88C6B920));
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B920);
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 64))) + 1772) = (ts4_word)((2188050432) | 12168);
    return t3;
}

/* Swing_DLL.xex 0x888D6720: call_seq u32@lbl_88D45B1C, u32@0x234, fn_88614938, u32@0x10, ts4_if_call_seq_u32_lbl_88D459E4_8883F238, fn_886220F8 */
ts4_word ts4_call_seq_u32_lbl_88D45B1C_888D6720(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t3 = fn_88614938((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 564)), (ts4_word)a1);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 16);
    t5 = ts4_if_call_seq_u32_lbl_88D459E4_8883F238((ts4_word)t3);
    fn_886220F8((ts4_word)t5, (ts4_word)t4);
    t7 = fn_888CB3F0((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    return t7;
}

/* Swing_DLL.xex 0x888D7480: if_call_seq u32@0x18, u32@0x4, u32@0x8, u32@0xc, u32@0x14, u32@0x20 */
ts4_word ts4_if_call_seq_u32_off18_888D7480(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
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
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)1;
    p3 = (ts4_word)t1;
    if ((int)t1 != 0) {
        t2 = fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
        p3 = (ts4_word)t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return p3;
}

/* Swing_DLL.xex 0x888DA978: get u32@0x1c, fn_88871108 */
ts4_word ts4_get_u32_off1c_888DA978(ts4_word a0)
{
    return fn_88871108((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
}

/* Swing_DLL.xex 0x888DAEE8: if_call_seq u32@lbl_88D45B1C, u32@0x27c, fn_888D73B0, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B1C_888DAEE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[1];
    ts4_word t2;
    ts4_word t3;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636);
    loc50[0] = (ts4_word)t2;
    t3 = fn_888D73B0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)t2);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
        *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
        *(ts4_word *)((char *)(ts4_word)(t3) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
        *(ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
        *(ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
        *(float *)((char *)(ts4_word)(t3) + 24) = (*(float *)((char *)(ts4_word)(a1) + 24));
        *(float *)((char *)(ts4_word)(t3) + 28) = (*(float *)((char *)(ts4_word)(a1) + 28));
        *(float *)((char *)(ts4_word)(t3) + 32) = (*(float *)((char *)(ts4_word)(a1) + 32));
        *(unsigned char *)((char *)(ts4_word)(t3) + 36) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 36));
        *(ts4_word *)((char *)(ts4_word)(t3) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
        *(float *)((char *)(ts4_word)(t3) + 44) = (*(float *)((char *)(ts4_word)(a1) + 44));
    }
    return t3;
}

/* Swing_DLL.xex 0x888DBFB0: tailcall fn_888D8078 */
ts4_word ts4_tailcall_fn_888D8078_888DBFB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_888D8078((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)a2);
}

/* Swing_DLL.xex 0x888DCA10: call_seq ts4_find_service, fn_888DA428 */
ts4_word ts4_call_seq_ts4_find_service_888DCA10(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_find_service((ts4_word)((4109369344) | 37424));
    t2 = fn_888DA428((ts4_word)t1, (ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x888DDA10: call_seq u32@0x10, ts4_if_atomic_interlocked_dec_88288530, u32@0xc, ts4_if_atomic_interlocked_dec_88288530 */
ts4_word ts4_call_seq_u32_off10_888DDA10(ts4_word a0)
{
    ts4_word t4;

    ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    t4 = ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    return t4;
}

/* Swing_DLL.xex 0x888DDA48: call_seq u32@0x4, ts4_if_atomic_interlocked_dec_88288530, u32@0x8, ts4_if_atomic_interlocked_dec_88288530 */
ts4_word ts4_call_seq_u32_off4_888DDA48(ts4_word a0)
{
    ts4_word t4;

    ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    t4 = ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    return t4;
}

/* Swing_DLL.xex 0x888DDAD8: call_seq fn_888C04D8, fn_888DDA80, u32@0x4, ts4_if_atomic_interlocked_dec_88288530, u32@0x8, ts4_if_atomic_interlocked_dec_88288530 */
ts4_word ts4_call_seq_fn_888C04D8_888DDAD8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t10;

    t1 = fn_888C04D8((ts4_word)a0);
    fn_888DDA80((ts4_word)t1);
    ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    t10 = ts4_if_atomic_interlocked_dec_88288530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    return t10;
}

/* Swing_DLL.xex 0x888DDB28: get ts4_find_service, u32@0x0, u32@0x4c, vcall, fn_881882D0 */
ts4_word ts4_get_ts4_find_service_888DDB28(void)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    t1 = ts4_find_service((ts4_word)((2354708480) | 18722));
    t4 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 76))))((ts4_word)t1, (ts4_word)0);
    t5 = fn_881882D0((ts4_word)(t4 + 464), (ts4_word)(t4 + 616));
    return t5;
}

/* Swing_DLL.xex 0x888DE030: call_seq fn_88617D88, lbl_880DB7E4, u8@0x20, u32@0x1c, u32@0x0, u32@0x24 */
ts4_word ts4_call_seq_fn_88617D88_888DE030(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 32) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB7E4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 228) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 232));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 224) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 244) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 248) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888DE250: call_seq u32@0x0, fn_8816D1A8, u32@0x10 */
ts4_word ts4_call_seq_u32_off0_888DE250(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888DE4C8: call_seq fn_88617D88, lbl_880DB580, u32@0x0, fn_8816D1A8 */
ts4_word ts4_call_seq_fn_88617D88_888DE4C8(ts4_word a0)
{
    float t3;

    fn_88617D88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB580;
    fn_8816D1A8((ts4_word)(a0 + 28));
    t3 = *(float *)lbl_8814B440;
    *(float *)((char *)(ts4_word)(a0) + 40) = t3;
    *(float *)((char *)(ts4_word)(a0) + 44) = t3;
    return a0;
}

/* Swing_DLL.xex 0x888DF388: call_seq lbl_880DB350, u32@0x4, u32@0x0, fn_8892AFF0, u32@0x5c, u32@0x60 */
ts4_word ts4_call_seq_lbl_880DB350_888DF388(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB350;
    fn_8892AFF0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 612) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 613) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 616) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 620) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 624) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x888DF3F8: call_seq lbl_880DB358, u32@0x0, fn_8892AF80, fn_8860BBD8 */
ts4_word ts4_call_seq_lbl_880DB358_888DF3F8(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB358;
    fn_8892AF80((ts4_word)(a0 + 16));
    t2 = fn_8860BBD8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x888DF440: call_seq lbl_880DB358, u32@0x4, u32@0x0, u32@0x8, u32@0xc, fn_8892AFF0 */
ts4_word ts4_call_seq_lbl_880DB358_888DF440(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB358;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    fn_8892AFF0((ts4_word)(a0 + 16));
    *(unsigned char *)((char *)(ts4_word)(a0) + 100) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x888DF4B0: call_seq fn_8892AFF0 */
ts4_word ts4_call_seq_fn_8892AFF0_888DF4B0(ts4_word a0)
{
    fn_8892AFF0((ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x888E3678: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
void ts4_set_u32_off0_888E3678(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x888E6680: call_seq fn_888CC2C8, fn_888CC890, fn_888DF008, fn_888DA850 */
ts4_word ts4_call_seq_fn_888CC2C8_888E6680(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = fn_888CC2C8();
    fn_888CC890((ts4_word)t1);
    fn_888DF008((ts4_word)a0);
    t4 = fn_888DA850((ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x888E7A80: if_addr lbl_88D45908, u32@0x4, fn_888860A0, u32@lbl_88D45908, u32@0x0, u32@0x14 */
ts4_word ts4_if_addr_lbl_88D45908_888E7A80(void)
{
    ts4_word p10;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    fn_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D45908) + 4)));
    t3 = *(ts4_word *)lbl_88D45908;
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 20))))((ts4_word)t3);
    t7 = *(ts4_word *)lbl_88D45908;
    p10 = (ts4_word)t6;
    if ((ts4_word)t7 != 0) {
        fn_8892AF80((ts4_word)t7);
        t9 = ts4_tsu_cleanup_end((ts4_word)t7);
        p10 = (ts4_word)t9;
    }
    return p10;
}

/* Swing_DLL.xex 0x888E8070: call_seq u32@0x0, fn_8862BE08 */
ts4_word ts4_call_seq_u32_off0_888E8070(ts4_word a0, ts4_word a1)
{
    fn_8862BE08((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return a0;
}

/* Swing_DLL.xex 0x888E80A8: call_seq u32@0x0, fn_8862C0E8 */
ts4_word ts4_call_seq_u32_off0_888E80A8(ts4_word a0, ts4_word a1)
{
    fn_8862C0E8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
    return a0;
}

/* Swing_DLL.xex 0x888EC410: call_seq fn_888E3908, fn_888E38A8, ts4_object_finalize, ts4_object_finalize, u32@0x1c */
ts4_word ts4_call_seq_fn_888E3908_888EC410(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = fn_888E3908();
    fn_888E38A8((ts4_word)t1);
    ts4_object_finalize((ts4_word)(a0 + 32));
    t4 = ts4_object_finalize((ts4_word)(a0 + 44));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t4;
}

/* Swing_DLL.xex 0x888F02E0: if_get fn_888D3648, fn_888D3330, u32@0xc0, u32@0xbc, fn_88150310, u32@0x34 */
ts4_word ts4_if_get_fn_888D3648_888F02E0(ts4_word a0)
{
    ts4_word p22;
    ts4_word t3;
    ts4_word t8;
    ts4_word t13;
    ts4_word t18;
    ts4_word t21;

    fn_888D3648();
    fn_888D3330((ts4_word)a0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 192);
    fn_88150310((ts4_word)(a0 + 188), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 188)), (ts4_word)t3);
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 52))) + 125) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t8 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 0))))((ts4_word)t8, (ts4_word)1);
    }
    t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    if ((ts4_word)t13 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 0))))((ts4_word)t13, (ts4_word)1);
    }
    t18 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)0;
    p22 = (ts4_word)t18;
    if ((ts4_word)t18 != 0) {
        t21 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t18) + 0))) + 0))))((ts4_word)t18, (ts4_word)1);
        p22 = (ts4_word)t21;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)0;
    return p22;
}

/* Swing_DLL.xex 0x888F0AB8: if_call_seq u32@lbl_88D45AF4, fn_886E0E60, u32@lbl_88D45AF8, fn_886E0E60, u32@0x20, u8@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45AF4_888F0AB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AF4;
    if ((ts4_word)t1 != 0) {
        fn_886E0E60((ts4_word)t1);
    }
    t4 = *(ts4_word *)lbl_88D45AF8;
    if ((ts4_word)t4 != 0) {
        fn_886E0E60((ts4_word)t4);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t7 = fn_881B9148((ts4_word)(a0 + 16));
    return t7;
}

/* Swing_DLL.xex 0x888F1758: if_call_seq fn_888DA698, u32@0x1c, fn_888718A8, u32@0x1c, fn_88871BD8, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_fn_888DA698_888F1758(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t9;

    fn_888DA698((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t2 != 0) {
        fn_888718A8((ts4_word)t2);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        if ((ts4_word)t4 != 0) {
            fn_88871BD8((ts4_word)t4);
            ts4_tsu_cleanup_end((ts4_word)t4);
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t9 = fn_881B9148((ts4_word)(a0 + 16));
    return t9;
}

/* Swing_DLL.xex 0x888F1930: if_call_seq u32@0x1c, fn_88871A50, u8@0x143 */
ts4_word ts4_if_call_seq_u32_off1c_888F1930(ts4_word a0)
{
    ts4_word p3;
    ts4_word p4;
    ts4_word t2;

    t2 = fn_88871A50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28)));
    if ((ts4_word)(t2 & 0xff) != 0) {
        p3 = (ts4_word)1;
        p4 = (ts4_word)1;
    } else {
        p3 = (ts4_word)0;
        p4 = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 323) = (unsigned char)p3;
    return p4;
}

/* Swing_DLL.xex 0x888F1D00: call_seq lbl_880D0830, fn_88290C68, u32@0xc, fn_882908C0, u32@0x10 */
ts4_word ts4_call_seq_lbl_880D0830_888F1D00(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88290C68((ts4_word)((ts4_word)lbl_880D0830 + -360));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t1;
    t2 = fn_882908C0((ts4_word)(ts4_word)lbl_880D0830);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x888F5D50: call_seq u32@0x1c, u8@0x7c8, fn_888F14D8, u32@0x28, u8@0x43, u8@0x35 */
ts4_word ts4_call_seq_u32_off1c_888F5D50(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28))) + 1992) = (unsigned char)0;
    t2 = fn_888F14D8();
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    *(unsigned char *)((char *)(ts4_word)(a0) + 67) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 53) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(t3) + 564) = (unsigned char)0;
    return t2;
}

/* Swing_DLL.xex 0x888F7B20: get fn_888F70A0, u32@0x3c, u32@0x14, vcall */
ts4_word ts4_get_fn_888F70A0_888F7B20(ts4_word a0)
{
    ts4_word t4;

    fn_888F70A0();
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 60))) + 20))))((ts4_word)(a0 + 60));
    return t4;
}

/* Swing_DLL.xex 0x888F7B60: call_seq fn_888F70A0, fn_888CEBA8 */
ts4_word ts4_call_seq_fn_888F70A0_888F7B60(ts4_word a0)
{
    ts4_word t2;

    fn_888F70A0();
    t2 = fn_888CEBA8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x888F9A48: call_seq fn_888F4E70, fn_888F4E70, fn_888F4E70, fn_888F4E70 */
ts4_word ts4_call_seq_fn_888F4E70_888F9A48(ts4_word a0)
{
    ts4_word t4;

    fn_888F4E70((ts4_word)(a0 + 28));
    fn_888F4E70((ts4_word)(a0 + 88));
    fn_888F4E70((ts4_word)(a0 + 148));
    t4 = fn_888F4E70((ts4_word)(a0 + 208));
    return t4;
}

/* Swing_DLL.xex 0x888FA018: if_call_seq fn_888F4E70, u32@0x18, ts4_destroy_owned_object, u32@0xc, ts4_destroy_owned_object, u32@0x4 */
ts4_word ts4_if_call_seq_fn_888F4E70_888FA018(ts4_word a0)
{
    ts4_word p12;
    ts4_word t2;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;

    fn_888F4E70((ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    fn_881816D8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t7);
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p12 = (ts4_word)t10;
    if ((ts4_word)t10 != 0) {
        t11 = ts4_destroy_owned_object((ts4_word)t10);
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x888FA388: if_get u32@0x5c, u32@0x58, fn_8817E720, u32@0x0, u32@0x68, vcall */
ts4_word ts4_if_get_u32_off5c_888FA388(ts4_word a0)
{
    ts4_word t1;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    fn_8817E720((ts4_word)(a0 + 88), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)), (ts4_word)t1);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 104))))((ts4_word)a0);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    if ((int)t7 != 0) {
        fn_888860A0((ts4_word)t7);
        *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    if ((int)t10 != 0) {
        fn_888860A0((ts4_word)(t10 + -8));
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    t13 = fn_881B9148((ts4_word)(a0 + 16));
    return t13;
}

/* Swing_DLL.xex 0x888FB920: call_seq fn_888F70A0, fn_888CEBA8, u8@0xe6 */
ts4_word ts4_call_seq_fn_888F70A0_888FB920(ts4_word a0)
{
    ts4_word t2;

    fn_888F70A0();
    t2 = fn_888CEBA8((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 230) = (unsigned char)1;
    return t2;
}

/* Swing_DLL.xex 0x888FDAA0: if_call_seq u8@0x8, fn_881B9148, u32@lbl_88D459DC, fn_8886B8E0 */
ts4_word ts4_if_call_seq_u8_off8_888FDAA0(ts4_word a0)
{
    ts4_word p4;
    ts4_word t2;
    ts4_word t3;

    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    fn_881B9148((ts4_word)(a0 + 16));
    t2 = *(ts4_word *)lbl_88D459DC;
    p4 = (ts4_word)t2;
    if ((ts4_word)t2 != 0) {
        t3 = fn_8886B8E0((ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x888FE500: set u8@0x98, fn_888FBEB0 */
ts4_word ts4_set_u8_off98_888FE500(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 152) = (unsigned char)1;
    return fn_888FBEB0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88901580: call_seq u32@lbl_88C6B928, fn_88901010, u32@lbl_88C6B928, u32@0x8 */
ts4_word ts4_call_seq_u32_lbl_88C6B928_88901580(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_88901010((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C6B928));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B928);
    return t2;
}

/* Swing_DLL.xex 0x889015C8: call_seq u32@lbl_88C6B930, fn_88901010, u32@lbl_88C6B930, u32@0x8 */
ts4_word ts4_call_seq_u32_lbl_88C6B930_889015C8(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_88901010((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C6B930));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B930);
    return t2;
}

/* Swing_DLL.xex 0x88901610: call_seq u32@lbl_88C6B924, fn_88901010, u32@lbl_88C6B924, u32@0x8 */
ts4_word ts4_call_seq_u32_lbl_88C6B924_88901610(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_88901010((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C6B924));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B924);
    return t2;
}

/* Swing_DLL.xex 0x88901658: call_seq u32@lbl_88C6B914, u32@0x8, u32@lbl_88C6B914, fn_88901010, u32@lbl_88C6B914, u32@0x8 */
ts4_word ts4_call_seq_u32_lbl_88C6B914_88901658(ts4_word a0)
{
    ts4_word t3;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B914);
    t3 = fn_88901010((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C6B914));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B914);
    return t3;
}

/* Swing_DLL.xex 0x889016A8: call_seq u32@lbl_88C6B91C, fn_88901010, u32@lbl_88C6B91C, u32@0x8 */
ts4_word ts4_call_seq_u32_lbl_88C6B91C_889016A8(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_88901010((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C6B91C));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B91C);
    return t2;
}

/* Swing_DLL.xex 0x889016F0: call_seq u32@lbl_88C6B918, fn_88901010, u32@lbl_88C6B918, u32@0x8 */
ts4_word ts4_call_seq_u32_lbl_88C6B918_889016F0(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_88901010((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C6B918));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B918);
    return t2;
}

/* Swing_DLL.xex 0x88903230: call_seq u32@0x44, u32@lbl_88C6B91C, fn_88901010, u32@lbl_88C6B91C, u32@0x8 */
ts4_word ts4_call_seq_u32_off44_88903230(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    t3 = fn_88901010((ts4_word)t1, (ts4_word)(*(ts4_word *)lbl_88C6B91C));
    *(ts4_word *)((char *)(ts4_word)(t1) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B91C);
    return t3;
}

/* Swing_DLL.xex 0x88903278: if_call_seq u32@0x40, u8@0x6a4, u32@0x44, u32@lbl_88C6B918, fn_88901010, u32@lbl_88C6B918 */
ts4_word ts4_if_call_seq_u32_off40_88903278(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p11;
    unsigned char t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    t2 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 64))) + 1700);
    if ((ts4_word)t2 == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        t5 = fn_88901010((ts4_word)t3, (ts4_word)(*(ts4_word *)lbl_88C6B918));
        *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B918);
        p11 = (ts4_word)t5;
    } else {
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        *(ts4_word *)((char *)(ts4_word)(t7) + 8) = (ts4_word)(*(ts4_word *)lbl_88C6B92C);
        *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 0) = (ts4_word)((3711369216) | 38317);
        p11 = (ts4_word)a0;
    }
    return p11;
}

/* Swing_DLL.xex 0x889048E8: call_seq fn_88901810, lbl_880DB6C0, u8@0x88, u32@0x0 */
ts4_word ts4_call_seq_fn_88901810_889048E8(ts4_word a0)
{
    fn_88901810((ts4_word)a0);
    *(unsigned char *)((char *)(ts4_word)(a0) + 136) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DB6C0;
    return a0;
}

/* Swing_DLL.xex 0x88905750: call_seq fn_8857B598, fn_88904C40, ts4_tailcall_fn_885827E0_88563110 */
ts4_word ts4_call_seq_fn_8857B598_88905750(void)
{
    ts4_word t1;

    t1 = fn_8857B598((ts4_word)-2, (ts4_word)4);
    fn_88904C40((ts4_word)t1);
    ts4_tailcall_fn_885827E0_88563110((ts4_word)0);
    return 0;
}

/* Swing_DLL.xex 0x88907110: tailcall fn_88906EE8 */
ts4_word ts4_tailcall_fn_88906EE8_88907110(void)
{
    return fn_88906EE8((ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88907630: call_seq ts4_find_service, fn_88907128 */
ts4_word ts4_call_seq_ts4_find_service_88907630(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = ts4_find_service((ts4_word)((4109369344) | 37424));
    t2 = fn_88907128((ts4_word)t1, (ts4_word)a0, (ts4_word)((4175822848) | 38444), (ts4_word)1);
    return t2;
}

/* Swing_DLL.xex 0x88908D18: tailcall fn_88908B80 */
ts4_word ts4_tailcall_fn_88908B80_88908D18(ts4_word a0)
{
    return fn_88908B80((ts4_word)a0, (ts4_word)0, (ts4_word)1);
}

/* Swing_DLL.xex 0x88908D50: call_seq u32@0x238, fn_88908B80, u8@0x2d8 */
ts4_word ts4_call_seq_u32_off238_88908D50(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 568) = (ts4_word)1;
    t1 = fn_88908B80((ts4_word)a0, (ts4_word)1, (ts4_word)1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 728) = (unsigned char)0;
    return t1;
}

/* Swing_DLL.xex 0x88909288: set u8@0x38, fn_88908258 */
ts4_word ts4_set_u8_off38_88909288(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)1;
    return fn_88908258((ts4_word)a0);
}

/* Swing_DLL.xex 0x8890C5A8: fn  */
ts4_word ts4_fn_8890C5A8(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Swing_DLL.xex 0x8890C5B8: set  */
void ts4_set_8890C5B8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 8) = f1;
    return;
}

/* Swing_DLL.xex 0x8890C5C8: set  */
void ts4_set_8890C5C8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    return;
}

/* Swing_DLL.xex 0x8890CAD8: get u32@0x224, vcall, u32@0x0 */
ts4_word ts4_get_u32_off224_8890CAD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((a0 + a1)) + 548))))((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x8890D700: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_8890D700(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((t1 << 4) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Swing_DLL.xex 0x8890D718: get u32@0x0 */
ts4_word ts4_get_u32_off0_8890D718(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Swing_DLL.xex 0x8890D720: set u32@0x8, u32@0xc, u32@0x18, u32@0x1c */
void ts4_set_u32_off8_8890D720(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8890D760: get u32@0x24 */
ts4_word ts4_get_u32_off24_8890D760(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Swing_DLL.xex 0x8890D7D0: addr lbl_880D6B70, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D6B70_8890D7D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    return;
}

/* Swing_DLL.xex 0x8890D9E0: set u32@0x8, u32@0xc, u32@0x18, u32@0x1c, u32@0x0, u32@0x4 */
void ts4_set_u32_off8_8890D9E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8890E0E0: if_call_seq u32@0x10, fn_888860A0, u32@0x10, u32@0x14, u32@0x0, fn_888860A0 */
ts4_word ts4_if_call_seq_u32_off10_8890E0E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t1 != 0) {
        fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)t4;
    if ((int)t4 != 0) {
        t5 = fn_888860A0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x8890E148: call_seq u32@lbl_88D45B38, fn_88613268, u32@0x0, u32@0x4, u32@lbl_88D45B38, fn_88613268 */
ts4_word ts4_call_seq_u32_lbl_88D45B38_8890E148(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1040, (ts4_word)16, (ts4_word)0, (ts4_word)2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)64;
    t4 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)4;
    return t4;
}

/* Swing_DLL.xex 0x8890EF58: set u32@0x10, fn_88178C40 */
ts4_word ts4_set_u32_off10_8890EF58(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
    return fn_88178C40((ts4_word)(a0 + 4), (ts4_word)a1);
}

/* Swing_DLL.xex 0x8890F120: call_seq fn_8890F008 */
ts4_word ts4_call_seq_fn_8890F008_8890F120(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8890F008((ts4_word)(a0 + 32));
    return ((t1 & 0xff) == 0);
}

/* Swing_DLL.xex 0x8890F150: tailcall fn_8890F008 */
ts4_word ts4_tailcall_fn_8890F008_8890F150(ts4_word a0)
{
    return fn_8890F008((ts4_word)(a0 + 12));
}

/* Swing_DLL.xex 0x8890F1D8: tailcall fn_881705B0 */
ts4_word ts4_tailcall_fn_881705B0_8890F1D8(ts4_word a0)
{
    return fn_881705B0((ts4_word)(a0 + 20), (ts4_word)16);
}

/* Swing_DLL.xex 0x88911CF0: if_call_seq u32@0x50, fn_888860A0, u32@0x50, u32@0x54, u32@0x50, u32@0x54 */
ts4_word ts4_if_call_seq_u32_off50_88911CF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;
    ts4_word t6;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((int)t1 != 0) {
        fn_888860A0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t6 = fn_88150310((ts4_word)(a0 + 44), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)), (ts4_word)t4);
    return t6;
}

/* Swing_DLL.xex 0x889125C0: tailcall fn_889124A8 */
ts4_word ts4_tailcall_fn_889124A8_889125C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_889124A8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88912AC0: call_seq lbl_880D72B0, u32@0x4, u32@0x0, u32@0x8, u32@0xc, u32@0x10 */
ts4_word ts4_call_seq_lbl_880D72B0_88912AC0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D72B0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    fn_88177110((ts4_word)(a0 + 8));
    fn_88912090((ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x88912B28: fn  */
ts4_word ts4_fn_88912B28(void)
{
    return 196;
}

/* Swing_DLL.xex 0x88912DC0: addr lbl_880D7058, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_880D7058_88912DC0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7058;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88913358: get u32@0x0, fn_88174C40 */
ts4_word ts4_get_u32_off0_88913358(ts4_word a0, ts4_word a1)
{
    return fn_88174C40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
}

/* Swing_DLL.xex 0x88913360: get u32@0x0, fn_88174C40 */
ts4_word ts4_get_u32_off0_88913360(ts4_word a0, ts4_word a1)
{
    return fn_88174C40((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
}

/* Swing_DLL.xex 0x88913418: get u32@0x0, fn_88174B90 */
ts4_word ts4_get_u32_off0_88913418(ts4_word a0, ts4_word a1)
{
    return fn_88174B90((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
}

/* Swing_DLL.xex 0x88913420: get u32@0x0, fn_88174B90 */
ts4_word ts4_get_u32_off0_88913420(ts4_word a0, ts4_word a1)
{
    return fn_88174B90((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
}

/* Swing_DLL.xex 0x889136E8: if_call_seq lbl_880D7074, u32@0x0, fn_881A6A00, u32@0x28, ts4_destroy_owned_object, fn_88617D28 */
ts4_word ts4_if_call_seq_lbl_880D7074_889136E8(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D7074;
    fn_881A6A00((ts4_word)(a0 + 60));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t2 != 0) {
        ts4_destroy_owned_object((ts4_word)t2);
    }
    t5 = fn_88617D28((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x88913F30: get u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off0_88913F30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0, (ts4_word)(a0 + 8), (ts4_word)a2);
}

/* Swing_DLL.xex 0x88915980: if_get u32@g_ts4_session_context, u32@0x40, u32@0x8, u32@0x4, u32@0x1f0, u32@0x1f4 */
void ts4_if_get_u32_g_ts4_session_context_88915980(void)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t18;
    ts4_word t19;
    ts4_word t20;

    t1 = *(ts4_word *)g_ts4_session_context;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    if ((ts4_word)t3 > 31) {
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(ts4_word *)((char *)(ts4_word)(t4) + 496) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 500) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 504) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 508) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 8);
    if ((ts4_word)t7 > 32) {
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 4);
        *(ts4_word *)((char *)(ts4_word)(t8) + 512) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 516) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 520) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 524) = (ts4_word)0;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 8);
    if ((ts4_word)t11 > 33) {
        t12 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
        *(ts4_word *)((char *)(ts4_word)(t12) + 528) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t12) + 532) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t12) + 536) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t12) + 540) = (ts4_word)0;
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t15 = *(ts4_word *)((char *)(ts4_word)(t14) + 8);
    if ((ts4_word)t15 > 34) {
        t16 = *(ts4_word *)((char *)(ts4_word)(t14) + 4);
        *(ts4_word *)((char *)(ts4_word)(t16) + 544) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 548) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 552) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 556) = (ts4_word)0;
    }
    t18 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t19 = *(ts4_word *)((char *)(ts4_word)(t18) + 8);
    if ((ts4_word)t19 <= 35) {
        return;
    }
    t20 = *(ts4_word *)((char *)(ts4_word)(t18) + 4);
    *(ts4_word *)((char *)(ts4_word)(t20) + 560) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t20) + 564) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t20) + 568) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t20) + 572) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88915A48: addr lbl_880D6B70, u32@0xc, u32@0x0, u8@0x10, u8@0x11, u8@0x12 */
void ts4_addr_lbl_880D6B70_88915A48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6B70;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 17) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 18) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 19) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88915AC0: set u8@0x38, u32@0x3c */
void ts4_set_u8_off38_88915AC0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88915AD0: set u32@0xc, u32@0x8, u32@0x18 */
void ts4_set_u32_offc_88915AD0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88915AE8: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915AE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915B08: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915B08(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915B28: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915B28(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915B48: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915B48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915B68: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915B68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915B88: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915B88(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915BA8: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915BA8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915BC8: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915BC8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915BE8: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915BE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915C08: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915C08(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915C28: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915C28(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915C48: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915C48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915C68: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915C68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915C88: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915C88(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915CA8: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915CA8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915CC8: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915CC8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915CE8: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915CE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915D08: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915D08(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915D70: if_get u32@g_ts4_session_context, u32@0x3c, u8@0x50, u32@0xb8, u32@0x70, u32@0x9c */
void ts4_if_get_u32_g_ts4_session_context_88915D70(ts4_word a0)
{
    unsigned char t3;

    t3 = *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 60))) + 80);
    if ((ts4_word)t3 != 1) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 112) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 156) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x88915DA0: if_get u8@0x38, u32@0x4, u32@0x2d4, u32@0x2d4 */
void ts4_if_get_u8_off38_88915DA0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 56);
    if ((ts4_word)t1 != 1) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 724);
    if ((int)a2 <= (int)t3) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t2) + 724) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x88915E10: tailcall fn_88915DC8 */
ts4_word ts4_tailcall_fn_88915DC8_88915E10(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88915DC8((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88915E28: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915E28(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915E48: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915E48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915E68: addr lbl_880D5A64, lbl_880D19F0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_880D5A64_88915E68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)lbl_880D5A64;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D19F0;
    return;
}

/* Swing_DLL.xex 0x88915E88: get u8@0x4c4, u8@0xd */
void ts4_get_u8_off4c4_88915E88(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a1) + 13) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 1220));
    return;
}

/* Swing_DLL.xex 0x88915E98: get u8@0xd, u8@0x4c4 */
void ts4_get_u8_offd_88915E98(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 1220) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 13));
    return;
}

/* Swing_DLL.xex 0x889166A8: set u8@0xf0, u8@0x38, u32@0x38, u8@0x39d, u32@0xac, u8@0x255 */
void ts4_set_u8_offf0_889166A8(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 240) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 56) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56))) + 925) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 172))) + 597) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88916EA8: set u32@0xc, u8@0x10 */
void ts4_set_u32_offc_88916EA8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88916EB8: if_get u32@0x8, u8@0x22d */
void ts4_if_get_u32_off8_88916EB8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(t1) + 557) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88916ED0: if_get u32@0x8, u8@0x22f */
void ts4_if_get_u32_off8_88916ED0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(t1) + 559) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88916F10: get u32@0x8, u8@0x1ce */
void ts4_get_u32_off8_88916F10(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + 462) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88916FD0: if_call_seq u32@g_ts4_session_context, u32@0x40, u32@0x8, u32@0x4, u32@0x1a0, u32@0x1a4 */
ts4_word ts4_if_call_seq_u32_g_ts4_session_context_88916FD0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t19;

    t1 = *(ts4_word *)g_ts4_session_context;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    if ((ts4_word)t3 > 26) {
        t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
        *(ts4_word *)((char *)(ts4_word)(t4) + 416) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 420) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 424) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t4) + 428) = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 8);
    if ((ts4_word)t7 > 28) {
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 4);
        *(ts4_word *)((char *)(ts4_word)(t8) + 448) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 452) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 456) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t8) + 460) = (ts4_word)0;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 8);
    if ((ts4_word)t11 > 29) {
        t12 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
        *(ts4_word *)((char *)(ts4_word)(t12) + 464) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t12) + 468) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t12) + 472) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t12) + 476) = (ts4_word)0;
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(t1) + 64);
    t15 = *(ts4_word *)((char *)(ts4_word)(t14) + 8);
    if ((ts4_word)t15 > 30) {
        t16 = *(ts4_word *)((char *)(ts4_word)(t14) + 4);
        *(ts4_word *)((char *)(ts4_word)(t16) + 480) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 484) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 488) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t16) + 492) = (ts4_word)0;
    }
    ts4_object_finalize((ts4_word)(a0 + 8));
    t19 = ts4_object_finalize((ts4_word)(a0 + 20));
    return t19;
}

/* Swing_DLL.xex 0x88918390: tailcall fn_88917490 */
ts4_word ts4_tailcall_fn_88917490_88918390(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88917490((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889183A8: tailcall fn_88917CF0 */
ts4_word ts4_tailcall_fn_88917CF0_889183A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88917CF0((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889183C0: tailcall fn_88917EE0 */
ts4_word ts4_tailcall_fn_88917EE0_889183C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88917EE0((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889183D8: tailcall fn_88917FC8 */
ts4_word ts4_tailcall_fn_88917FC8_889183D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88917FC8((ts4_word)a2, (ts4_word)a0, (ts4_word)a1);
}

/* Swing_DLL.xex 0x889183F0: if_get u32@0x8, u32@0x42c, u32@0x230 */
void ts4_if_get_u32_off8_889183F0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 560) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 1068));
    return;
}

/* Swing_DLL.xex 0x88918D80: if_call_seq u32@0x14, ts4_destroy_owned_object, u32@0x8, ts4_destroy_owned_object */
ts4_word ts4_if_call_seq_u32_off14_88918D80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p6 = (ts4_word)t4;
    if ((ts4_word)t4 != 0) {
        t5 = ts4_destroy_owned_object((ts4_word)t4);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x88918DC8: set u32@0x8, u32@0xc, u32@0x10, u32@0x14, u32@0x18, u32@0x1c */
void ts4_set_u32_off8_88918DC8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x889192D8: tailcall fn_889395D8 */
ts4_word ts4_tailcall_fn_889395D8_889192D8(ts4_word a0, ts4_word a1)
{
    return fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x88919338: tailcall fn_889395D8 */
ts4_word ts4_tailcall_fn_889395D8_88919338(ts4_word a0, ts4_word a1)
{
    return fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x889194A8: tailcall fn_88939470 */
ts4_word ts4_tailcall_fn_88939470_889194A8(ts4_word a0, ts4_word a1)
{
    return fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)3);
}

/* Swing_DLL.xex 0x88919520: tailcall fn_889395D8 */
ts4_word ts4_tailcall_fn_889395D8_88919520(ts4_word a0, ts4_word a1)
{
    return fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1068));
}

/* Swing_DLL.xex 0x88919DB8: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_88918908, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_88919DB8(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1252, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_88918908((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x88919E38: addr lbl_88D3CD50, fn_889189B0, u32@0x418, u32@0x0, u32@0x8, vcall */
ts4_word ts4_addr_lbl_88D3CD50_88919E38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;
    ts4_word t8;

    t1 = fn_889189B0((ts4_word)(ts4_word)lbl_88D3CD50);
    *(ts4_word *)((char *)(ts4_word)(t1) + 1048) = (ts4_word)a1;
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1, (ts4_word)a0);
    fn_88917490((ts4_word)a3, (ts4_word)t1, (ts4_word)a2);
    t8 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 0))))((ts4_word)t1, (ts4_word)0);
    return t8;
}

/* Swing_DLL.xex 0x88919EB0: if_get u32@g_ts4_session_context, u32@0xc, fn_8860DCF8, fn_889189B0, u32@0x0, u32@0x8 */
ts4_word ts4_if_get_u32_g_ts4_session_context_88919EB0(ts4_word a0)
{
    ts4_word p6;
    ts4_word t3;
    ts4_word t4;

    t3 = fn_8860DCF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)g_ts4_session_context)) + 12)), (ts4_word)1492, (ts4_word)4, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        t4 = fn_889189B0((ts4_word)t3);
        p6 = (ts4_word)t4;
    } else {
        p6 = (ts4_word)0;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p6) + 0))) + 8))))((ts4_word)p6, (ts4_word)a0);
    return p6;
}

/* Swing_DLL.xex 0x8891B098: addr lbl_880CFC4E, fn_88918EA8 */
ts4_word ts4_addr_lbl_880CFC4E_8891B098(void)
{
    return fn_88918EA8((ts4_word)(ts4_word)lbl_880CFC4E);
}

/* Swing_DLL.xex 0x8891B0A8: addr lbl_880CF0C7, fn_88918EA8 */
ts4_word ts4_addr_lbl_880CF0C7_8891B0A8(void)
{
    return fn_88918EA8((ts4_word)(ts4_word)lbl_880CF0C7);
}

/* Swing_DLL.xex 0x8891B0B8: call_seq fn_8893B328, u8@0x38, u32@0x3c */
ts4_word ts4_call_seq_fn_8893B328_8891B0B8(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8893B328();
    *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    return t1;
}

/* Swing_DLL.xex 0x8891B100: call_seq fn_88938660, lbl_880D6D50, u8@0x34, u32@0x0, u8@0x38, u32@0x3c */
ts4_word ts4_call_seq_fn_88938660_8891B100(ts4_word a0)
{
    fn_88938660();
    *(unsigned char *)((char *)(ts4_word)(a0) + 52) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880D6D50;
    *(unsigned char *)((char *)(ts4_word)(a0) + 56) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)-1;
    return a0;
}

/* Swing_DLL.xex 0x8891B158: if_call_seq fn_88936BB0, ts4_read_scaled_counter_8893C808, u8@0x42c, ts4_read_scaled_counter_8893C808 */
ts4_word ts4_if_call_seq_fn_88936BB0_8891B158(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t2;
    unsigned char t3;
    ts4_word t4;

    fn_88936BB0((ts4_word)a1, (ts4_word)(a0 + 1068));
    t2 = ts4_read_scaled_counter_8893C808((ts4_word)a1, (ts4_word)(a0 + 1072));
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 1068);
    p5 = (ts4_word)t2;
    if ((ts4_word)t3 != 0) {
        t4 = ts4_read_scaled_counter_8893C808((ts4_word)a1, (ts4_word)(a0 + 1076));
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x8891B2E8: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_8891B2E8(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    return t7;
}

/* Swing_DLL.xex 0x8891B390: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_8891B390(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    t9 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1072)));
    return t9;
}

/* Swing_DLL.xex 0x8891B4A0: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x42c */
ts4_word ts4_get_u32_off0_8891B4A0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t7 = fn_889396A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 1068)));
    return t7;
}

/* Swing_DLL.xex 0x8891B4F0: call_seq fn_88939470, fn_889395D8, fn_889395D8 */
ts4_word ts4_call_seq_fn_88939470_8891B4F0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)3);
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
    t3 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1076));
    return t3;
}

/* Swing_DLL.xex 0x8891B550: call_seq fn_88939470, fn_889395D8, fn_889395D8 */
ts4_word ts4_call_seq_fn_88939470_8891B550(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)3);
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
    t3 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1076));
    return t3;
}

/* Swing_DLL.xex 0x8891B860: call_seq fn_88939470, fn_889395D8, fn_889395D8, fn_889395D8, fn_889395D8, fn_889395D8 */
ts4_word ts4_call_seq_fn_88939470_8891B860(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    fn_88939470((ts4_word)a1, (ts4_word)(a0 + 1068), (ts4_word)3);
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1072));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1076));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1080));
    fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1084));
    t6 = fn_889395D8((ts4_word)a1, (ts4_word)(a0 + 1088));
    return t6;
}
