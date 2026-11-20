#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/* Swing_DLL.xex 0x8834D830-0x88554404, executable version 0.0.0.3. */
/* Small accessor / thunk / call-sequence functions produced by tools/asm2c
   and verified byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360,
   MSVC 16.00.10224.00). The original address is in the comment above each
   definition. Parameters are untyped words (a0 = this/first argument); field
   accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
typedef unsigned int ts4_u32;
#ifdef _MSC_VER
unsigned __int64 __mftb(void);
#pragma intrinsic(__mftb)
#else
static inline __attribute__((unused)) unsigned long long __mftb(void) { return 0; }
#endif
typedef struct ts4_Rec { ts4_u32 tag; ts4_u32 stamp; ts4_u32 pad; ts4_u32 tag2; } ts4_Rec;
typedef struct ts4_Rec12 { ts4_u32 tag; ts4_u32 stamp; ts4_u32 pad; } ts4_Rec12;
typedef struct ts4_TlsBuf { ts4_u32 pad0; void *cur; ts4_u32 pad1; void *end; } ts4_TlsBuf;
extern ts4_u32 lbl_88CAD338;
ts4_word KeTlsGetValue();
#define ts4_trace1(T) do { ts4_TlsBuf *tb_ = (ts4_TlsBuf *)KeTlsGetValue(lbl_88CAD338); \
    if ((ts4_Rec12 *)tb_->cur < (ts4_Rec12 *)tb_->end) { ts4_Rec12 *rc_ = (ts4_Rec12 *)tb_->cur; \
        rc_->tag = (ts4_u32)(T); rc_->stamp = (ts4_u32)__mftb(); tb_->cur = rc_ + 1; } } while (0)
#define ts4_trace2(T, U) do { ts4_TlsBuf *tb_ = (ts4_TlsBuf *)KeTlsGetValue(lbl_88CAD338); \
    if ((ts4_Rec *)tb_->cur < (ts4_Rec *)tb_->end) { ts4_Rec *rc_ = (ts4_Rec *)tb_->cur; \
        rc_->tag = (ts4_u32)(T); rc_->tag2 = (ts4_u32)(U); rc_->stamp = (ts4_u32)__mftb(); tb_->cur = rc_ + 1; } } while (0)

extern char lbl_88007998[];
extern char lbl_8802AEDC[];
extern char lbl_8803BC50[];
extern char lbl_880818D4[];
extern char lbl_88081980[];
extern char lbl_88081D34[];
extern char lbl_88086A7C[];
extern char lbl_8808726C[];
extern char lbl_880878D8[];
extern char lbl_880878F8[];
extern char lbl_88087904[];
extern char lbl_8808790C[];
extern char lbl_88087918[];
extern char lbl_88B3302C[];
extern char lbl_88C8EAA0[];
extern char lbl_88C8EAA4[];
extern char lbl_88C8EAA8[];
extern char lbl_88CACF08[];
extern char lbl_88CAD32C[];
ts4_word KeTlsSetValue();
ts4_word fn_88315F10();
ts4_word ts4_read_u8_to_u8_883199C0();
ts4_word fn_88319C40();
ts4_word fn_8839A4E0();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_8841C678();
ts4_word fn_8841ED08();
ts4_word fn_88420E00();
ts4_word fn_884214A8();
ts4_word fn_8846B678();
ts4_word fn_8846D4A0();
ts4_word fn_88470870();
ts4_word fn_884758C0();
ts4_word fn_88475AE8();
ts4_word fn_88475B08();
ts4_word fn_88477140();
ts4_word fn_88488828();
ts4_word fn_88489498();
ts4_word fn_88489C28();
ts4_word fn_8848C370();
ts4_word fn_884909E8();
ts4_word fn_88490B30();
ts4_word fn_884911B8();
ts4_word fn_8849F8B0();
ts4_word fn_884B3FF8();
ts4_word fn_884BB3B0();
ts4_word fn_884BB418();
ts4_word fn_884BB5F8();
ts4_word fn_8850C2F8();
ts4_word fn_8850C3D0();
ts4_word fn_88510C48();
ts4_word fn_885283E8();
ts4_word fn_88553928();
ts4_word fn_885E76C0();
ts4_word fn_885E78C8();
ts4_word fn_885EA1A8();
ts4_word ts4_call_seq_fn_8847EF68_884A4898();
ts4_word ts4_call_seq_u32_off4_88428B48();
ts4_word ts4_get_u32_off4_88426130();
ts4_word ts4_get_u32_off4_88428AC0();
ts4_word ts4_get_u32_off7c_8846AA10();
ts4_word ts4_get_u32_off8_8841EF28();
ts4_word ts4_if_call_seq_u32_off118_8848E3E0();
ts4_word ts4_if_call_seq_u32_off4_88428AC8();
ts4_word ts4_if_get_u32_offb8_8848F838();
ts4_word ts4_noop_884927F8();
ts4_word ts4_set_u32_off0_884BE220();
ts4_word ts4_sum_list_field_1C_8841ECE0();
ts4_word ts4_tailcall_fn_885127C0_885134F8();
ts4_word ts4_tailcall_memcpy_88421450();
ts4_word ts4_traced_vcall_all_8848CEA0();
ts4_word ts4_traced_vcall_all_8848D050();
ts4_word ts4_traced_vcall_all_8848D3B0();

/* Swing_DLL.xex 0x8834D830: if_call_seq u32@lbl_88C8EAA8, u32@lbl_88C8EAA8, u32@lbl_88C8EAA0, u32@lbl_88C8EAA0, fn_8839A4E0, u32@lbl_88C8EAA0 */
ts4_word ts4_if_call_seq_u32_lbl_88C8EAA8_8834D830(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t8;
    ts4_word t14;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t2 = ((*(ts4_word *)lbl_88C8EAA8) + -1);
    *(ts4_word *)lbl_88C8EAA8 = (ts4_word)t2;
    if ((int)t2 <= 0) {
        t4 = *(ts4_word *)lbl_88C8EAA0;
        if ((ts4_word)t4 != 0) {
            fn_8839A4E0((ts4_word)t4);
            *(ts4_word *)lbl_88C8EAA0 = (ts4_word)0;
        }
        t8 = *(ts4_word *)lbl_88C8EAA4;
        if ((ts4_word)t8 != 0) {
            fn_8839A4E0((ts4_word)t8);
            *(ts4_word *)lbl_88C8EAA4 = (ts4_word)0;
        }
        *(ts4_word *)lbl_88C8EAA8 = (ts4_word)0;
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 5664);
    if ((ts4_word)t14 != 0) {
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t14, (ts4_word)(ts4_word)lbl_8802AEDC, (ts4_word)338);
        *(ts4_word *)((char *)(ts4_word)(a0) + 5660) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 5664) = (ts4_word)0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8841A740: if_get u32@0x14, u32@0x14, u32@lbl_88CACF08, KeTlsGetValue, u32@0x14, u32@0x14 */
ts4_word ts4_if_get_u32_off14_8841A740(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t6;
    ts4_word t13;

    if ((ts4_word)a0 != 0) {
        t2 = ((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) + 1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t2;
    }
    t4 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    if ((ts4_word)t4 != 0) {
        t6 = ((*(ts4_word *)((char *)(ts4_word)(t4) + 20)) + -1);
        *(ts4_word *)((char *)(ts4_word)(t4) + 20) = (ts4_word)t6;
        if ((int)t6 == 0) {
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 16))))((ts4_word)t4, (ts4_word)1);
        }
    }
    t13 = KeTlsSetValue((ts4_word)(*(ts4_word *)lbl_88CACF08), (ts4_word)a0);
    return t13;
}

/* Swing_DLL.xex 0x8842B480: call_seq ts4_call_seq_u32_off4_88428B48, u32@0x4, ts4_sum_list_field_1C_8841ECE0, fn_8841ED08, u32@0x0, ts4_if_call_seq_u32_off4_88428AC8 */
ts4_word ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    unsigned short t9;
    ts4_word t10;
    ts4_word t11;

    t1 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t3 = ts4_sum_list_field_1C_8841ECE0((ts4_word)t2);
    t4 = (t3 + -1);
    t5 = fn_8841ED08((ts4_word)t2, (ts4_word)t4);
    t7 = ts4_if_call_seq_u32_off4_88428AC8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0)));
    t8 = ts4_get_u32_off4_88428AC0((ts4_word)t7);
    t9 = *(unsigned short *)((char *)(ts4_word)(t8) + 18);
    t10 = ts4_get_u32_off4_88426130((ts4_word)t5);
    t11 = ts4_get_u32_off8_8841EF28((ts4_word)t10);
    return (t11 + t9);
}

/* Swing_DLL.xex 0x8843A2D8: if_addr lbl_880818D4, ts4_trace1, u32@0x40, u32@0x40, u32@0x18, u32@0x0 */
ts4_word ts4_if_addr_lbl_880818D4_8843A2D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;
    unsigned char t10;
    ts4_word t11;

    ts4_trace1((ts4_word)(ts4_word)lbl_880818D4);
    t3 = ((*(ts4_word *)((char *)(ts4_word)(a3) + 64)) + 1);
    *(ts4_word *)((char *)(ts4_word)(a3) + 64) = (ts4_word)t3;
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 32))))((ts4_word)a0, (ts4_word)t4, (ts4_word)a2, (ts4_word)a3);
    t9 = ((*(ts4_word *)((char *)(ts4_word)(a3) + 64)) + -1);
    *(ts4_word *)((char *)(ts4_word)(a3) + 64) = (ts4_word)t9;
    t10 = *(unsigned char *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t10 != 0) {
        t11 = (t9 + 8);
        *(ts4_word *)((char *)(ts4_word)((t11 << 2)) + a3) = (ts4_word)0;
    }
    ts4_trace1((ts4_word)(ts4_word)lbl_8803BC50);
    return a0;
}

/* Swing_DLL.xex 0x8843A3C8: addr lbl_880818D4, ts4_trace1, u32@0x18, u32@0x8, u32@0x0, u32@0x10 */
static void ts4_if_get_u32_lbl_88CAD338_8843A3C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;

    ts4_trace1((ts4_word)(ts4_word)lbl_880818D4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    loc50[3] = (ts4_word)a2;
    loc50[1] = (ts4_word)0;
    loc50[0] = (ts4_word)t2;
    loc50[2] = (ts4_word)t3;
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    ts4_trace1((ts4_word)(ts4_word)lbl_8803BC50);
    return;
}

/* Swing_DLL.xex 0x8843BF30: loop_addr lbl_88081980, ts4_trace1, u32@0x14, u32@0x8, vcall, u32@0x0 */
static void ts4_loop_get_u32_lbl_88CAD338_8843BF30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv6;
    ts4_word p17;
    ts4_word loc60[130];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    int t5;
    ts4_word t9;
    ts4_word t10;
    int t16;

    ts4_trace1((ts4_word)(ts4_word)lbl_88081980);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t3 = (a0 + 20);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 8))))((ts4_word)t3);
    lv6 = (ts4_word)t5;
    while ((int)lv6 != -1) {
        t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 20))))((ts4_word)t3, (ts4_word)lv6, (ts4_word)(ts4_word)&loc60[0]);
        t10 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
        loc50[3] = (ts4_word)a2;
        loc50[0] = (ts4_word)t9;
        loc50[1] = (ts4_word)lv6;
        loc50[2] = (ts4_word)t10;
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 16))))((ts4_word)t9, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
        t16 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 12))))((ts4_word)t3, (ts4_word)lv6);
        p17 = (ts4_word)t16;
        lv6 = p17;
    }
    ts4_trace1((ts4_word)(ts4_word)lbl_8803BC50);
    return;
}

/* Swing_DLL.xex 0x88442248: get u32@0x5c, u32@lbl_88CACF08, KeTlsGetValue, u32@0x0, u32@0x0, vcall */
ts4_word ts4_get_u32_off5c_88442248(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t17;
    ts4_word t18;
    ts4_word t19;

    t2 = ((*(ts4_word *)((char *)(ts4_word)(a0) + 92)) + 1);
    t4 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t7 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 0))))((ts4_word)t4, (ts4_word)64, (ts4_word)(t2 << 6), (ts4_word)37);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    ts4_tailcall_memcpy_88421450((ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)), (ts4_word)(t8 << 6));
    t11 = *(ts4_word *)lbl_88CACF08;
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    t13 = KeTlsGetValue((ts4_word)t11);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 4))))((ts4_word)t13, (ts4_word)t12);
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)t7;
    t18 = (t17 + 1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)t18;
    t19 = (((t18 << 6) + t7) + -64);
    return t19;
}

/* Swing_DLL.xex 0x88444DB8: if_call_seq lbl_88081D34, ts4_trace1, u32@0x34, u32@0x8, u32@0x10, fn_885283E8 */
static void ts4_if_call_seq_u32_lbl_88CAD338_88444DB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p5;
    ts4_word loc60[28];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    ts4_trace1((ts4_word)(ts4_word)lbl_88081D34);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    loc60[16] = (ts4_word)0;
    loc60[17] = (ts4_word)0;
    loc50[3] = (ts4_word)a2;
    loc50[0] = (ts4_word)t2;
    loc50[2] = (ts4_word)t3;
    loc50[1] = (ts4_word)0;
    p5 = (ts4_word)0;
    if ((ts4_word)t2 != 0) {
        t4 = (t2 + 16);
        p5 = (ts4_word)t4;
    }
    fn_885283E8((ts4_word)(ts4_word)&loc60[0], (ts4_word)p5, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    ts4_trace1((ts4_word)(ts4_word)lbl_8803BC50);
    return;
}

/* Swing_DLL.xex 0x8846B598: if_get u32@0x8, fn_88488828, u32@0x50, u32@0x8, u32@lbl_88CAD32C, u32@0x0 */
static void ts4_if_get_u32_off8_8846B598(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    unsigned char t9;

    fn_88488828((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t3 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 8);
        t5 = *(ts4_word *)lbl_88CAD32C;
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 96))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t5, (ts4_word)t4);
        t9 = *(unsigned char *)((char *)(ts4_word)(t8) + 0);
        if ((ts4_word)t9 == 0) {
            ts4_trace1((ts4_word)(ts4_word)lbl_88086A7C);
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 12))))((ts4_word)t3, (ts4_word)a0);
            ts4_trace1((ts4_word)(ts4_word)lbl_8803BC50);
        }
    }
    return;
}

/* Swing_DLL.xex 0x8846C178: if_get u32@0x84, u32@0x84, fn_88490B30, ts4_traced_vcall_all_8848CEA0, fn_8848C370, u8@0x8d */
ts4_word ts4_if_get_u32_off84_8846C178(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[4];
    int t1;
    ts4_word t25;
    ts4_word t6;
    unsigned short t7;
    ts4_word t9;
    unsigned short t12;
    ts4_word t18;
    ts4_word t19;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 132);
    if ((int)t1 != 0) {
        loc50[1] = (ts4_word)a2;
        t25 = *(ts4_word *)((char *)(ts4_word)(a1) + 124);
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)2;
        fn_88489498((ts4_word)t25, (ts4_word)(ts4_word)&loc50[0]);
        *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
        return a0;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 132) = (ts4_word)1;
    fn_88490B30((ts4_word)a1, (ts4_word)a2);
    ts4_traced_vcall_all_8848CEA0((ts4_word)a1, (ts4_word)a2);
    fn_8848C370((ts4_word)a2);
    *(unsigned char *)((char *)(ts4_word)(a1) + 141) = (unsigned char)0;
    ts4_if_get_u32_offb8_8848F838((ts4_word)a1, (ts4_word)a2);
    t6 = *(ts4_word *)((char *)(ts4_word)(a2) + 84);
    if ((ts4_word)t6 != 0) {
        t7 = *(unsigned short *)((char *)(ts4_word)(a2) + 80);
        t9 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t9, (ts4_word)t6, (ts4_word)((t7 << 5) | (t7 >> 27)), (ts4_word)2);
        *(ts4_word *)((char *)(ts4_word)(a2) + 84) = (ts4_word)0;
        *(unsigned short *)((char *)(ts4_word)(a2) + 80) = (unsigned short)0;
    }
    t12 = *(unsigned short *)((char *)(ts4_word)(a2) + 4);
    if ((ts4_word)t12 == 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 20))))((ts4_word)a2);
    }
    fn_88475B08((ts4_word)a2);
    t18 = *(ts4_word *)((char *)(ts4_word)(a1) + 132);
    *(unsigned char *)((char *)(ts4_word)(a1) + 141) = (unsigned char)1;
    t19 = (t18 + -1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 132) = (ts4_word)t19;
    if (((int)t19 == 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a1) + 140)) == 0) && (int)(*(ts4_word *)((char *)(ts4_word)(a1) + 128)) != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 128) = (ts4_word)0;
        fn_88489C28((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 124)));
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return a0;
}

/* Swing_DLL.xex 0x8846C370: if_get u32@0x88, u32@0x84, u32@0x84, u32@0x18, u32@0x0, u32@0x10 */
ts4_word ts4_if_get_u32_off88_8846C370(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t29;
    ts4_word t3;
    int t4;
    ts4_word t7;
    ts4_word t10;
    int t11;
    ts4_word t12;
    ts4_word t15;
    ts4_word t18;
    ts4_word t23;
    ts4_word t26;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((int)(t1 + t2) != 0) {
        loc50[1] = (ts4_word)a1;
        t29 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)13;
        fn_88489498((ts4_word)t29, (ts4_word)(ts4_word)&loc50[0]);
        return 0;
    }
    t3 = (t2 + 1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)t3;
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 24);
    if ((int)t4 == 0) {
        t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 16))))((ts4_word)a1);
        *(ts4_word *)((char *)(ts4_word)(a1) + 24) = (ts4_word)t7;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)a0;
    fn_88475AE8((ts4_word)a1);
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 236);
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 232);
    t12 = (a0 + 228);
    if ((int)t11 == (int)(t10 & 0x3fffffff)) {
        fn_8841C678((ts4_word)t12, (ts4_word)4);
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(t12) + 4);
    *(ts4_word *)((char *)(ts4_word)((t15 << 2)) + (*(ts4_word *)((char *)(ts4_word)(t12) + 0))) = (ts4_word)a1;
    t18 = ((*(ts4_word *)((char *)(ts4_word)(t12) + 4)) + 1);
    *(ts4_word *)((char *)(ts4_word)(t12) + 4) = (ts4_word)t18;
    fn_884909E8((ts4_word)a0, (ts4_word)a1);
    ts4_traced_vcall_all_8848D050((ts4_word)a0, (ts4_word)a1);
    fn_88477140((ts4_word)a1);
    t23 = ((*(ts4_word *)((char *)(ts4_word)(a0) + 132)) + -1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)t23;
    if (((int)t23 == 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 140)) == 0) && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)) != 0) {
        t26 = *(ts4_word *)((char *)(ts4_word)(a0) + 124);
        *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
        fn_88489C28((ts4_word)t26);
    }
    return a1;
}

/* Swing_DLL.xex 0x8847AD48: if_call_seq u32@0x8, u32@0x84, u32@0x84, u32@0x38, fn_88470870, ts4_if_call_seq_u32_off118_8848E3E0 */
ts4_word ts4_if_call_seq_u32_off8_8847AD48(ts4_word a0, ts4_word a1)
{
    ts4_word p12;
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    t3 = ((*(ts4_word *)((char *)(ts4_word)(t1) + 132)) + 1);
    *(ts4_word *)((char *)(ts4_word)(t1) + 132) = (ts4_word)t3;
    fn_88470870((ts4_word)t1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)));
    t6 = ts4_if_call_seq_u32_off118_8848E3E0((ts4_word)t1, (ts4_word)a0);
    t8 = ((*(ts4_word *)((char *)(ts4_word)(t1) + 132)) + -1);
    *(ts4_word *)((char *)(ts4_word)(t1) + 132) = (ts4_word)t8;
    p12 = (ts4_word)t6;
    if (((int)t8 == 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t1) + 140)) == 0) && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 128)) != 0) {
        t11 = ts4_get_u32_off7c_8846AA10((ts4_word)t1);
        p12 = (ts4_word)t11;
    }
    return p12;
}

/* Swing_DLL.xex 0x8847ADD0: if_call_seq u32@0x30, fn_88475AE8, u32@0x8, u32@0x4, fn_8841C678, u32@0x4 */
static ts4_word ts4_if_call_seq_u32_off30_8847ADD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    int t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;
    int t11;
    ts4_word t14;
    ts4_word t17;
    ts4_word t18;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((int)t1 < 2) {
        t4 = (t1 + 5);
        t5 = *(ts4_word *)((char *)(ts4_word)((t4 << 2)) + a0);
        if ((ts4_word)t5 == 0) {
            *(ts4_word *)((char *)(ts4_word)((t4 << 2)) + a0) = (ts4_word)a1;
            fn_88475AE8((ts4_word)a1);
        }
    }
    t9 = (a0 + 44);
    t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 8);
    t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
    if ((int)t11 == (int)(t10 & 0x3fffffff)) {
        fn_8841C678((ts4_word)t9, (ts4_word)4);
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
    *(ts4_word *)((char *)(ts4_word)((t14 << 2)) + (*(ts4_word *)((char *)(ts4_word)(t9) + 0))) = (ts4_word)a1;
    t17 = ((*(ts4_word *)((char *)(ts4_word)(t9) + 4)) + 1);
    *(ts4_word *)((char *)(ts4_word)(t9) + 4) = (ts4_word)t17;
    t18 = fn_88475AE8((ts4_word)a1);
    return t18;
}

/* Swing_DLL.xex 0x8848E420: if_call_seq u32@0x8, u8@0x25, u8@0x25, u32@0x84, u32@0x84, u32@0x118 */
ts4_word ts4_if_call_seq_u32_off8_8848E420(ts4_word a0, ts4_word a1, int a2, ts4_word a3, ts4_word a4)
{
    ts4_word p12;
    ts4_word p16;
    ts4_word t1;
    int t3;
    ts4_word t15;
    ts4_word t6;
    ts4_word t8;
    ts4_word t11;

    (void)a3;
    (void)a4;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    *(unsigned char *)((char *)(ts4_word)(t1) + 37) = (unsigned char)((((1 << 6) | (1 >> 26)) & 0xffffffc0) | ((*(unsigned char *)((char *)(ts4_word)(t1) + 37)) & 0x3f));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    if ((int)t3 != 0) {
        if ((int)a2 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 280)) != 0) {
            ts4_traced_vcall_all_8848D3B0();
        }
        t15 = fn_8849F8B0((ts4_word)a1);
        p16 = (ts4_word)t15;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)1;
        if ((int)a2 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 280)) != 0) {
            ts4_traced_vcall_all_8848D3B0((ts4_word)a0, (ts4_word)a1);
        }
        t6 = fn_8849F8B0((ts4_word)a1);
        t8 = ((*(ts4_word *)((char *)(ts4_word)(a0) + 132)) + -1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)t8;
        p12 = (ts4_word)t6;
        if (((int)t8 == 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 140)) == 0) && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)) != 0) {
            t11 = ts4_get_u32_off7c_8846AA10((ts4_word)a0);
            p12 = (ts4_word)t11;
        }
        p16 = (ts4_word)p12;
    }
    return p16;
}

/* Swing_DLL.xex 0x8848F1E0: if_call_seq u8@0x26, u16@0x22, u8@0x26, u32@0x44, u16@0x22, u32@0x44 */
ts4_word ts4_if_call_seq_u8_off26_8848F1E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p8;
    ts4_word p15;
    unsigned char t1;
    unsigned short t2;
    ts4_word t3;
    ts4_word t4;
    int t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t12;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 38);
    t2 = *(unsigned short *)((char *)(ts4_word)(a1) + 34);
    *(unsigned char *)((char *)(ts4_word)(a1) + 38) = (unsigned char)((t1 & 0xff) & 0xffffffcf);
    p15 = (ts4_word)a0;
    if ((ts4_word)t2 == 65535) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        t4 = (a0 + 64);
        *(unsigned short *)((char *)(ts4_word)(a1) + 34) = (unsigned short)t3;
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
        p8 = (ts4_word)a0;
        if ((int)t5 == (int)(t6 & 0x3fffffff)) {
            t7 = fn_8841C678((ts4_word)t4, (ts4_word)4);
            p8 = (ts4_word)t7;
        }
        t9 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
        *(ts4_word *)((char *)(ts4_word)((t9 << 2)) + (*(ts4_word *)((char *)(ts4_word)(t4) + 0))) = (ts4_word)a1;
        t12 = ((*(ts4_word *)((char *)(ts4_word)(t4) + 4)) + 1);
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t12;
        p15 = (ts4_word)p8;
    }
    return p15;
}

/* Swing_DLL.xex 0x8848F310: if_call_seq u8@0x26, u16@0x22, u8@0x26, u32@0x44, u16@0x22, u32@0x44 */
ts4_word ts4_if_call_seq_u8_off26_8848F310(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p8;
    ts4_word p15;
    unsigned char t1;
    unsigned short t2;
    ts4_word t3;
    ts4_word t4;
    int t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t12;

    (void)a2;
    (void)a3;
    (void)a4;
    t1 = *(unsigned char *)((char *)(ts4_word)(a1) + 38);
    t2 = *(unsigned short *)((char *)(ts4_word)(a1) + 34);
    *(unsigned char *)((char *)(ts4_word)(a1) + 38) = (unsigned char)(((t1 & 0xff) & 0xffffffcf) | 16);
    p15 = (ts4_word)a0;
    if ((ts4_word)t2 == 65535) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        t4 = (a0 + 64);
        *(unsigned short *)((char *)(ts4_word)(a1) + 34) = (unsigned short)t3;
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
        p8 = (ts4_word)a0;
        if ((int)t5 == (int)(t6 & 0x3fffffff)) {
            t7 = fn_8841C678((ts4_word)t4, (ts4_word)4);
            p8 = (ts4_word)t7;
        }
        t9 = *(ts4_word *)((char *)(ts4_word)(t4) + 4);
        *(ts4_word *)((char *)(ts4_word)((t9 << 2)) + (*(ts4_word *)((char *)(ts4_word)(t4) + 0))) = (ts4_word)a1;
        t12 = ((*(ts4_word *)((char *)(ts4_word)(t4) + 4)) + 1);
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t12;
        p15 = (ts4_word)p8;
    }
    return p15;
}

/* Swing_DLL.xex 0x8849BA88: call_seq lbl_880878D8, ts4_trace1, u32@0x4, u32@0x8, u8@0x25, u8@0x25 */
ts4_word ts4_call_seq_lbl_880878D8_8849BA88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[6];
    ts4_word t2;
    ts4_word t4;
    ts4_word t11;

    ts4_trace1((ts4_word)(ts4_word)lbl_880878D8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 4);
    t4 = ((*(ts4_word *)((char *)(ts4_word)(a2) + 8)) + 92);
    *(unsigned char *)((char *)(ts4_word)(t2) + 37) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(t2) + 37)) & 0x3f);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)(2147483648);
    ts4_noop_884927F8((ts4_word)t2);
    fn_884911B8((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 24)), (ts4_word)t4, (ts4_word)(ts4_word)&loc50[0]);
    ts4_trace1((ts4_word)(ts4_word)lbl_8803BC50);
    t11 = fn_885EA1A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a2, (ts4_word)a2, (ts4_word)a0, (ts4_word)0);
    return t11;
}

/* Swing_DLL.xex 0x8849BC88: call_seq lbl_8808726C, lbl_880878F8, ts4_trace2, u32@0x0, u32@0x14, u32@0x10 */
static ts4_word ts4_if_call_seq_u32_lbl_88CAD338_8849BC88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t9;

    ts4_trace2((ts4_word)(ts4_word)lbl_8808726C, (ts4_word)(ts4_word)lbl_880878F8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 20);
    t4 = (t2 + 416);
    fn_8850C2F8((ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 16)), (ts4_word)t3);
    ts4_trace1((ts4_word)(ts4_word)lbl_88007998);
    t9 = fn_885EA1A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a2, (ts4_word)a2, (ts4_word)0, (ts4_word)0);
    return t9;
}

/* Swing_DLL.xex 0x8849BD50: loop_call_seq lbl_8808726C, lbl_88087904, ts4_trace2, u32@0x0, u32@0x1c, u32@0x10 */
static ts4_word ts4_loop_call_seq_u32_lbl_88CAD338_8849BD50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word c13;
    ts4_word lv15;
    ts4_word p16;
    ts4_word p17;
    ts4_word p19;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t12;
    ts4_word t14;
    ts4_word t21;
    ts4_word t22;
    ts4_word t23;
    ts4_word t28;

    ts4_trace2((ts4_word)(ts4_word)lbl_8808726C, (ts4_word)(ts4_word)lbl_88087904);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 28);
    t4 = *(ts4_word *)((char *)(ts4_word)(a2) + 16);
    t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 696);
    t6 = *(ts4_word *)((char *)(ts4_word)(t3) + 8);
    t7 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
    t8 = *(ts4_word *)((char *)(ts4_word)(t3) + 16);
    *(ts4_word *)((char *)(ts4_word)(a2) + 20) = (ts4_word)t5;
    p19 = (ts4_word)t2;
    if ((ts4_word)t4 == 0) {
        t12 = ((*(ts4_word *)((char *)(ts4_word)(t3) + 24)) + 15);
        p17 = (ts4_word)((t12) >> 4);
        if ((int)((t12) >> 4) > 0) {
            c13 = (ts4_word)((t12) >> 4);
            t14 = (t8 + -4);
            lv15 = (ts4_word)t14;
            do {
                *(ts4_word *)((char *)(ts4_word)(lv15) + 4) = (ts4_word)0;
                *(ts4_word *)((char *)(ts4_word)(lv15) + 8) = (ts4_word)0;
                *(ts4_word *)((char *)(ts4_word)(lv15) + 12) = (ts4_word)0;
                *(ts4_word *)((char *)(ts4_word)((lv15 + 16)) + 0) = (ts4_word)0;
                p16 = (ts4_word)(lv15 + 16);
                lv15 = p16;
            } while (--c13 != 0);
            p17 = (ts4_word)0;
        }
        p19 = (ts4_word)p17;
    }
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t22 = *(ts4_word *)((char *)(ts4_word)(a2) + 24);
    t23 = (t21 + 416);
    fn_88510C48((ts4_word)t23, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 16)), (ts4_word)t22, (ts4_word)t7, (ts4_word)t6, (ts4_word)t8, (ts4_word)t4, (ts4_word)p19);
    ts4_trace1((ts4_word)(ts4_word)lbl_88007998);
    t28 = fn_885EA1A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a2, (ts4_word)a2, (ts4_word)0, (ts4_word)0);
    return t28;
}

/* Swing_DLL.xex 0x8849BE78: call_seq lbl_8808726C, lbl_8808790C, ts4_trace2, u32@0x0, u32@0x14, u32@0x10 */
static ts4_word ts4_if_call_seq_u32_lbl_88CAD338_8849BE78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t11;

    ts4_trace2((ts4_word)(ts4_word)lbl_8808726C, (ts4_word)(ts4_word)lbl_8808790C);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 20);
    *(unsigned char *)((char *)loc50 + 0) = (unsigned char)0;
    t4 = (t2 + 416);
    t5 = *(ts4_word *)((char *)(ts4_word)(a2) + 16);
    fn_8850C3D0((ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 24)), (ts4_word)t5, (ts4_word)t3, (ts4_word)(ts4_word)&loc50[0]);
    *(unsigned char *)((char *)(ts4_word)(a2) + 28) = (unsigned char)(*(unsigned char *)((char *)loc50 + 0));
    ts4_trace1((ts4_word)(ts4_word)lbl_88007998);
    t11 = fn_885EA1A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a2, (ts4_word)a2, (ts4_word)0, (ts4_word)0);
    return t11;
}

/* Swing_DLL.xex 0x8849BF58: call_seq lbl_8808726C, lbl_88087918, ts4_trace2, u32@0x10, u32@0x0, u32@0x8 */
ts4_word ts4_call_seq_lbl_8808726C_8849BF58(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t11;

    ts4_trace2((ts4_word)(ts4_word)lbl_8808726C, (ts4_word)(ts4_word)lbl_88087918);
    t2 = *(ts4_word *)((char *)(ts4_word)(a2) + 16);
    t4 = ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 416);
    t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
    t6 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    ts4_tailcall_fn_885127C0_885134F8((ts4_word)t4, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 16)), (ts4_word)t6, (ts4_word)t5);
    ts4_trace1((ts4_word)(ts4_word)lbl_88007998);
    t11 = fn_885EA1A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a2, (ts4_word)a2, (ts4_word)0, (ts4_word)0);
    return t11;
}

/* Swing_DLL.xex 0x884A3F88: if_call_seq u32@0x8, u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_884758C0 */
static ts4_word ts4_if_call_seq_u32_off8_884A3F88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p19;
    ts4_word p26;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    ts4_word t15;
    int t16;
    ts4_word t17;
    ts4_word t18;
    ts4_word t20;
    ts4_word t23;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t1 == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t4 = fn_8841A510((ts4_word)t3, (ts4_word)208, (ts4_word)21);
        *(unsigned short *)((char *)(ts4_word)(t4) + 4) = (unsigned short)208;
        t5 = fn_884758C0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t5;
    }
    fn_8846B678((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    t9 = (a0 + 12);
    t10 = fn_8846D4A0((ts4_word)a1, (ts4_word)t9);
    p26 = (ts4_word)t10;
    if ((ts4_word)(a2 & 0xff) != 0) {
        t11 = *(ts4_word *)lbl_88CACF08;
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)0;
        loc50[1] = (ts4_word)0;
        t12 = KeTlsGetValue((ts4_word)t11);
        t13 = fn_8841A510((ts4_word)t12, (ts4_word)80, (ts4_word)47);
        *(unsigned short *)((char *)(ts4_word)(t13) + 4) = (unsigned short)80;
        t14 = ts4_call_seq_fn_8847EF68_884A4898((ts4_word)t13);
        t15 = fn_884B3FF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)t14);
        *(unsigned char *)((char *)(ts4_word)(t14) + 64) = (unsigned char)0;
        t16 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
        t17 = *(ts4_word *)((char *)(ts4_word)(t9) + 8);
        p19 = (ts4_word)t15;
        if ((int)t16 == (int)(t17 & 0x3fffffff)) {
            t18 = fn_8841C678((ts4_word)t9, (ts4_word)4);
            p19 = (ts4_word)t18;
        }
        t20 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
        *(ts4_word *)((char *)(ts4_word)((t20 << 2)) + (*(ts4_word *)((char *)(ts4_word)(t9) + 0))) = (ts4_word)t14;
        t23 = ((*(ts4_word *)((char *)(ts4_word)(t9) + 4)) + 1);
        *(ts4_word *)((char *)(ts4_word)(t9) + 4) = (ts4_word)t23;
        p26 = (ts4_word)p19;
    }
    return p26;
}

/* Swing_DLL.xex 0x884BDA28: get u32@0xc, ts4_set_u32_off0_884BE220, fn_884BB5F8, fn_88420E00, fn_88420E00, fn_884BB3B0 */
ts4_word ts4_get_u32_offc_884BDA28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc90[18];
    ts4_word loc50[16];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t10;
    ts4_word t16;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    t2 = (a0 + 192);
    t3 = (t1 + 16);
    ts4_set_u32_off0_884BE220((ts4_word)t2, (ts4_word)a2);
    fn_884BB5F8((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc90[0]);
    t6 = (a0 + 80);
    t7 = (t3 + 32);
    fn_88420E00((ts4_word)t6, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t7);
    t9 = (a0 + 64);
    t10 = (t3 + 16);
    fn_88420E00((ts4_word)t9, (ts4_word)(ts4_word)&loc90[0], (ts4_word)t10);
    fn_884BB3B0((ts4_word)a0, (ts4_word)a3);
    fn_884BB418((ts4_word)a0, (ts4_word)a3);
    t16 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 32))))((ts4_word)a2, (ts4_word)t9, (ts4_word)t6, (ts4_word)(4294901760), (ts4_word)a3);
    return t16;
}

/* Swing_DLL.xex 0x884D7C98: if_call_seq fn_885E78C8, fn_884214A8, u32@0x68, fn_885E76C0, u32@0x8, u32@0x4 */
ts4_word ts4_if_call_seq_fn_885E78C8_884D7C98(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word t1;
    int t2;
    ts4_word t15;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    int t8;
    ts4_word t11;
    ts4_word t14;

    t1 = (a0 + 112);
    t2 = fn_885E78C8((ts4_word)t1, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 == 0) {
        t15 = loc50[0];
        return t15;
    }
    t3 = fn_884214A8((ts4_word)a1);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    fn_885E76C0((ts4_word)t1, (ts4_word)t3, (ts4_word)t4);
    t6 = (a0 + 100);
    t7 = *(ts4_word *)((char *)(ts4_word)(t6) + 8);
    t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 4);
    if ((int)t8 == (int)(t7 & 0x3fffffff)) {
        fn_8841C678((ts4_word)t6, (ts4_word)4);
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(t6) + 4);
    *(ts4_word *)((char *)(ts4_word)((t11 << 2)) + (*(ts4_word *)((char *)(ts4_word)(t6) + 0))) = (ts4_word)t3;
    t14 = ((*(ts4_word *)((char *)(ts4_word)(t6) + 4)) + 1);
    *(ts4_word *)((char *)(ts4_word)(t6) + 4) = (ts4_word)t14;
    return t4;
}

/* Swing_DLL.xex 0x885542E8: call_seq u32@0x20, u32@0x0, u32@0x10, u16@0x10, u32@0x14, u16@0x14 */
ts4_word ts4_call_seq_u32_off20_885542E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc60[10];
    ts4_word t1;
    float t2;
    float t3;
    float t4;
    ts4_word t5;
    float t6;
    unsigned short t7;
    float t8;
    float t9;
    ts4_word t10;
    float t11;
    float t12;
    unsigned short t13;
    float t14;
    ts4_word t15;
    float t16;
    unsigned short t17;
    ts4_word t19;
    ts4_word t20;
    ts4_word t21;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 32);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a3;
    t2 = *(float *)((char *)(ts4_word)(a1) + 28);
    t3 = *(float *)((char *)(ts4_word)(a1) + 16);
    loc60[4] = (ts4_word)0;
    t4 = *(float *)((char *)(ts4_word)(a2) + 0);
    loc60[5] = (ts4_word)0;
    loc60[6] = (ts4_word)0;
    loc60[7] = (ts4_word)0;
    loc60[9] = (ts4_word)0;
    loc60[8] = (ts4_word)16;
    t5 = ((int)(((t4 - t3) * t2)) + -1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t5;
    t6 = *(float *)((char *)(ts4_word)(a1) + 28);
    t7 = *(unsigned short *)((char *)(ts4_word)(a0) + 16);
    t8 = *(float *)((char *)(ts4_word)(a2) + 4);
    t9 = *(float *)((char *)(ts4_word)(a1) + 20);
    loc60[0] = (ts4_word)((short)t7);
    t10 = ((int)(((t8 - t9) * t6)) + -1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t10;
    t11 = *(float *)((char *)(ts4_word)(a1) + 28);
    t12 = *(float *)((char *)(ts4_word)(a2) + 8);
    t13 = *(unsigned short *)((char *)(ts4_word)(a0) + 20);
    t14 = *(float *)((char *)(ts4_word)(a1) + 24);
    loc60[1] = (ts4_word)((short)t13);
    t15 = ((int)(((t12 - t14) * t11)) + -1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t15;
    t16 = *(float *)((char *)(ts4_word)(a2) + 12);
    t17 = *(unsigned short *)((char *)(ts4_word)(a0) + 24);
    t19 = ((int)((t16 * (*(float *)((char *)(ts4_word)(a1) + 28)))) + 2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t19;
    t20 = (((int)t19 >> 16) + 1);
    loc60[2] = (ts4_word)((short)t17);
    loc60[3] = (ts4_word)t20;
    t21 = fn_88553928((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0], (ts4_word)t1, (ts4_word)((short)t13), (ts4_word)t20, (ts4_word)((short)t17), (ts4_word)t17, (ts4_word)((int)t19 >> 16));
    return t21;
}
