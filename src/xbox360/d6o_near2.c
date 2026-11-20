/* Swing_DLL.xex 0x8842B648-0x88442F88, executable version 0.0.0.3. */
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wdeprecated-non-prototype"
#pragma clang diagnostic ignored "-Wunused-function"
#endif
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
static inline unsigned long long __mftb(void) { return 0; }
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
#include "ts4_vector.h"

extern char fn_88434910[];
extern char lbl_88001A20[];
extern char lbl_88001A68[];
extern char lbl_8802B120[];
extern char lbl_8803A258[];
extern char lbl_8803A280[];
extern char lbl_8803A2EC[];
extern char lbl_8803A308[];
extern char lbl_8803A374[];
extern char lbl_8803A974[];
extern char lbl_8803B558[];
extern char lbl_8803B570[];
extern char lbl_8803B618[];
extern char lbl_8803C474[];
extern char lbl_8803DCB4[];
extern char lbl_8803DDEC[];
extern char lbl_8803E744[];
extern char lbl_8803F500[];
extern char lbl_8803F5D4[];
extern char lbl_88040148[];
extern char lbl_88040154[];
extern char lbl_88040344[];
extern char lbl_88040740[];
extern char lbl_8804074C[];
extern char lbl_88040758[];
extern char lbl_88040B78[];
extern char lbl_88040B80[];
extern char lbl_88041080[];
extern char lbl_880418CC[];
extern char lbl_880418D8[];
extern char lbl_880418E8[];
extern char lbl_8804190C[];
extern char lbl_8804201C[];
extern char lbl_8804202C[];
extern char lbl_88042C44[];
extern char lbl_88042C5C[];
extern char lbl_88042D08[];
extern char lbl_88042D18[];
extern char lbl_88042DA4[];
extern char lbl_88042DB4[];
extern char lbl_880E1DE4[];
extern char lbl_88B3C7EC[];
extern char lbl_88B3D184[];
extern char lbl_88B3D1E4[];
extern char lbl_88B3D1F8[];
extern char lbl_88B3D3C8[];
extern char lbl_88CACF08[];
extern char lbl_88CAD32C[];
extern char lbl_88CAD340[];
extern char lbl_88CAD574[];
ts4_word KeTlsSetValue();
ts4_word fn_88316808();
ts4_word fn_88419568();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_8841C5E8();
ts4_word fn_8841C678();
ts4_word fn_8841D598();
ts4_word fn_8841DA58();
ts4_word fn_8841EF70();
ts4_word fn_884210E8();
ts4_word fn_884214A8();
ts4_word fn_88421B10();
ts4_word fn_88421BF8();
ts4_word fn_884224B0();
ts4_word fn_88422638();
ts4_word fn_88423788();
ts4_word fn_88424C88();
ts4_word fn_88426440();
ts4_word fn_8842AC78();
ts4_word ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480();
ts4_word fn_8842B568();
ts4_word fn_88431250();
ts4_word fn_88432BE0();
ts4_word fn_88434990();
ts4_word fn_88435838();
ts4_word fn_88470208();
ts4_word fn_88471DC8();
ts4_word fn_884C5468();
ts4_word fn_885E7378();
ts4_word fn_885E7AD8();
ts4_word fn_885E7BA8();
ts4_word ts4_call_seq_fn_8841A510_8841A7C8();
ts4_word ts4_call_seq_fn_88428B48_88433F90();
ts4_word ts4_call_seq_u32_off4_88428B48();
ts4_word ts4_find_entry_by_name_884278D0();
ts4_word ts4_forward_88421460();
ts4_word ts4_get_u32_off0_8841EAC8();
ts4_word ts4_get_u32_off0_88428960();
ts4_word ts4_get_u32_off0_88428978();
ts4_word ts4_get_u32_off0_88428980();
ts4_word ts4_get_u32_off0_88428988();
ts4_word ts4_get_u32_off0_88428998();
ts4_word ts4_get_u32_off0_884289B8();
ts4_word ts4_get_u32_off0_884289C8();
ts4_word ts4_get_u32_off0_88428A60();
ts4_word ts4_get_u32_off0_88428B30();
ts4_word ts4_get_u32_off4_88426130();
ts4_word ts4_get_u32_off4_88426138();
ts4_word ts4_get_u32_off4_88428AC0();
ts4_word ts4_get_u32_off8_8841EF28();
ts4_word ts4_get_u32_off8_88426140();
ts4_word ts4_if_call_seq_fn_88309DB8_88309438();
ts4_word ts4_if_call_seq_fn_88426110_8841F670();
ts4_word ts4_if_call_seq_u32_off4_88428890();
ts4_word ts4_if_call_seq_u32_off4_88428AC8();
ts4_word ts4_if_get_fn_8832BFC0_883168A8();
ts4_word ts4_index_u16_array_at_field0_884289F8();
ts4_word ts4_index_u64_array_at_field0_88428A88();
ts4_word ts4_lookup_then_forward_88317468();
ts4_word ts4_tailcall_memcpy_88421450();
extern char fn_88421120[];
extern char g_ts4_true_string[];
extern char lbl_88029198[];
extern char lbl_8803A514[];
extern char lbl_8803A570[];
extern char lbl_8803BC48[];
extern char lbl_8803BC70[];
extern char lbl_8803BC7C[];
extern char lbl_8803C3F8[];
extern char lbl_8803C404[];
extern char lbl_8803D1C8[];
extern char lbl_8803E660[];
extern char lbl_8803E670[];
extern char lbl_8803E6E0[];
extern char lbl_8803E7C4[];
extern char lbl_8803E7F8[];
extern char lbl_8803E820[];
extern char lbl_8803F49C[];
extern char lbl_8803F52C[];
extern char lbl_8803F53C[];
extern char lbl_8803F54C[];
extern char lbl_8803F55C[];
extern char lbl_8803F9E8[];
extern char lbl_8803FC80[];
extern char lbl_8803FCA0[];
extern char lbl_88040134[];
extern char lbl_880407B0[];
extern char lbl_880407BC[];
extern char lbl_880407C8[];
extern char lbl_880408F8[];
extern char lbl_8804090C[];
extern char lbl_88040CE8[];
extern char lbl_88040CF8[];
extern char lbl_88040D08[];
extern char lbl_88040D18[];
extern char lbl_880410F0[];
extern char lbl_88041AB0[];
extern char lbl_88041AC8[];
extern char lbl_88041AE8[];
extern char lbl_880D1B30[];
extern char lbl_880D2F08[];
extern char lbl_880DD510[];
extern char lbl_88B3C464[];
extern char lbl_88B3C520[];
extern char lbl_88B3D18C[];
extern char lbl_88B3D1AC[];
extern char lbl_88B3D1EC[];
extern char lbl_88CAD560[];
extern char lbl_88CAD564[];
ts4_word fn_8832EDB0();
ts4_word fn_884054F0();
ts4_word fn_88408B18();
ts4_word fn_88413498();
ts4_word fn_8841A3F8();
ts4_word fn_8841C428();
ts4_word fn_8841ED08();
ts4_word ts4_last_node_nonzero_8841EF38();
ts4_word fn_88421338();
ts4_word fn_884223A0();
ts4_word fn_88423660();
ts4_word fn_88424D80();
ts4_word fn_88428C10();
ts4_word fn_8842A378();
ts4_word fn_88430C80();
ts4_word fn_884312B8();
ts4_word fn_88431B10();
ts4_word fn_88474120();
ts4_word fn_88475AE8();
ts4_word fn_885646F8();
ts4_word fn_8857C3D8();
ts4_word ts4_get_u32_off0_884289A8();
ts4_word ts4_get_u32_off0_88428A18();
ts4_word ts4_get_u32_off0_88428A28();
ts4_word ts4_get_u32_off0_88428A70();
ts4_word ts4_get_u32_offd0_884736C8();
ts4_word ts4_if_call_seq_RtlInitAnsiString_8857C370();
ts4_word ts4_if_call_seq_fn_884214A8_88428B98();
ts4_word ts4_if_call_seq_fn_885844E8_8857C468();
ts4_word ts4_if_call_seq_lbl_8803E76C_88425178();
ts4_word ts4_if_call_seq_u32_off0_884288F8();
ts4_word ts4_if_get_u32_0xc_8841A820();
ts4_word ts4_if_get_u32_lbl_88C32048_8857A1E0();
ts4_word ts4_sum_list_field_1C_8841ECE0();
extern char fn_88436868[];
extern char lbl_8803BC50[];
extern char lbl_8803CB5C[];
extern char lbl_88041554[];
extern char lbl_88041928[];
extern char lbl_88041AA4[];
extern char lbl_88041FEC[];
extern char lbl_88041FF8[];
extern char lbl_88042C0C[];
extern char lbl_8804812C[];
extern char lbl_88048144[];
extern char lbl_88049804[];
extern char lbl_8807FF50[];
extern char lbl_8807FF74[];
extern char lbl_88080278[];
extern char lbl_8808029C[];
extern char lbl_8808030C[];
extern char lbl_88080CE4[];
extern char lbl_88080CF4[];
extern char lbl_88080D04[];
extern char lbl_8808122C[];
extern char lbl_88081250[];
extern char lbl_88081830[];
extern char lbl_88081980[];
extern char lbl_88081E00[];
extern char lbl_88081E10[];
extern char lbl_88081E20[];
extern char lbl_88081E44[];
extern char lbl_88081E74[];
extern char lbl_88082070[];
extern char lbl_880820E8[];
extern char lbl_8808212C[];
extern char lbl_88082540[];
extern char lbl_88082D30[];
extern char lbl_88082DFC[];
extern char lbl_8808338C[];
ts4_word fn_8841C9F0();
ts4_word fn_88426178();
ts4_word fn_88436D30();
ts4_word fn_88441FF8();
ts4_word fn_8844EF88();
ts4_word fn_88451948();
ts4_word fn_88462090();
ts4_word fn_88475F30();
ts4_word fn_885E76C0();
ts4_word ts4_call_seq_fn_88466AB0_88467768();
ts4_word ts4_call_seq_fn_88467768_884544F8();
ts4_word ts4_call_seq_fn_88557200_88528678();
ts4_word ts4_call_seq_lbl_88049700_88436488();
ts4_word ts4_call_seq_u32_lbl_88CACF08_885E7B40();
ts4_word ts4_if_get_u8_offd_884263F0();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
#ifdef _MSC_VER
#pragma function(memcpy)
#endif

/* Swing_DLL.xex 0x8842B648: if_call_seq lbl_880E1DE4, u16@lbl_88B3D184, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off4_88428AC0, ts4_get_u32_off8_88426140, lbl_88040758 */
ts4_word ts4_if_call_seq_lbl_880E1DE4_8842B648(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[2]; ts4_word loc68[2]; ts4_word loc70[4]; } LL;
    unsigned short t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t17;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned short *)lbl_88B3D184;
    if ((ts4_word)t1 == 65535) {
        ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880E1DE4);
        t3 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc58[0]);
        t4 = ts4_get_u32_off8_88426140((ts4_word)t3);
        ts4_find_entry_by_name_884278D0((ts4_word)t4, (ts4_word)(ts4_word)lbl_88040758, (ts4_word)(ts4_word)&LL.loc50[0]);
        t6 = LL.loc50[0];
        *(unsigned short *)lbl_88B3D184 = (unsigned short)t6;
    }
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880E1DE4);
    t10 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t10) + 0) = (unsigned short)(*(unsigned short *)lbl_88B3D184);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8804074C);
    t13 = ts4_get_u32_off0_88428A60((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)0);
    memcpy((ts4_word)t13, (ts4_word)a1, (ts4_word)64);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc70[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88040740);
    t16 = ts4_get_u32_off0_88428A60((ts4_word)(ts4_word)&LL.loc70[0], (ts4_word)0);
    t17 = memcpy((ts4_word)t16, (ts4_word)a2, (ts4_word)64);
    return t17;
}

/* Swing_DLL.xex 0x8842B850: if_call_seq lbl_880E1DE4, u16@lbl_88B3D18C, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off4_88428AC0, ts4_get_u32_off8_88426140, lbl_880407C8 */
ts4_word ts4_if_call_seq_lbl_880E1DE4_8842B850(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    struct { ts4_word loc50[2]; ts4_word loc58[2]; ts4_word loc60[2]; ts4_word loc68[2]; ts4_word loc70[4]; } LL;
    unsigned short t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t17;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned short *)lbl_88B3D18C;
    if ((ts4_word)t1 == 65535) {
        ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880E1DE4);
        t3 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&LL.loc58[0]);
        t4 = ts4_get_u32_off8_88426140((ts4_word)t3);
        ts4_find_entry_by_name_884278D0((ts4_word)t4, (ts4_word)(ts4_word)lbl_880407C8, (ts4_word)(ts4_word)&LL.loc50[0]);
        t6 = LL.loc50[0];
        *(unsigned short *)lbl_88B3D18C = (unsigned short)t6;
    }
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880E1DE4);
    t10 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&LL.loc60[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t10) + 0) = (unsigned short)(*(unsigned short *)lbl_88B3D18C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880407BC);
    t13 = ts4_get_u32_off0_88428A70((ts4_word)(ts4_word)&LL.loc68[0], (ts4_word)0);
    memcpy((ts4_word)t13, (ts4_word)a1, (ts4_word)48);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&LL.loc70[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880407B0);
    t16 = ts4_get_u32_off0_88428A70((ts4_word)(ts4_word)&LL.loc70[0], (ts4_word)0);
    t17 = memcpy((ts4_word)t16, (ts4_word)a2, (ts4_word)48);
    return t17;
}

/* Swing_DLL.xex 0x88442EE8: if_call_seq u32@0x3c, u32@0x38, fn_8841C678, u32@0x4, u32@0x0, u32@0x4 */
static ts4_word ts4_if_call_seq_u32_off3c_88442EE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    t3 = (a0 + 52);
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        fn_8841C678((ts4_word)t3, (ts4_word)56);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(t3) + 4);
    t7 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    t8 = (t6 + 1);
    *(ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)t8;
    t9 = memcpy((ts4_word)(((int)t6 * 56) + t7), (ts4_word)a1, (ts4_word)56);
    t10 = *(ts4_word *)((char *)(ts4_word)((((int)t6 * 56) + t7)) + 32);
    if ((ts4_word)t10 == 0) {
        *(ts4_word *)((char *)(ts4_word)((((int)t6 * 56) + t7)) + 48) = (ts4_word)1;
        *(ts4_word *)((char *)(ts4_word)((((int)t6 * 56) + t7)) + 40) = (ts4_word)(ts4_word)lbl_8803E660;
        *(ts4_word *)((char *)(ts4_word)((((int)t6 * 56) + t7)) + 32) = (ts4_word)(ts4_word)lbl_8803E660;
    }
    return t9;
}
