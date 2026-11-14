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
typedef struct ts4_args2 { ts4_word w[2]; } ts4_args2;
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;
typedef struct ts4_q8 { ts4_u64 q[8]; } ts4_q8;
#ifdef _MSC_VER
typedef char *ts4_va_list;
#define TS4_VA_START(ap, v) __va_start(&ap, v)
#else
#include <stdarg.h>
typedef va_list ts4_va_list;
#define TS4_VA_START(ap, v) va_start(ap, v)
#endif
#include "ts4_vector.h"
extern ts4_u64 __mftb(void);
#ifdef _MSC_VER
#pragma intrinsic(__mftb)
#endif

extern char fn_8845A698[];
extern char fn_8845AEF0[];
extern char fn_8845EF10[];
extern char fn_8845F1C8[];
extern char fn_8845F410[];
extern char fn_88466E80[];
extern char fn_88467030[];
extern char fn_884677B0[];
extern char fn_88521390[];
extern char fn_88521778[];
extern char fn_88521CB8[];
extern char fn_88522640[];
extern char fn_88522C48[];
extern char fn_885234A0[];
extern char fn_88524258[];
extern char fn_88525208[];
extern char fn_885ECFF0[];
extern char lbl_88001A20[];
extern char lbl_88001A68[];
extern char lbl_88007998[];
extern char lbl_88007B80[];
extern char lbl_8800FC50[];
extern char lbl_88024CDC[];
extern char lbl_88028BDC[];
extern char lbl_88028DFC[];
extern char lbl_88028ED4[];
extern char lbl_880291C4[];
extern char lbl_88029328[];
extern char lbl_88029638[];
extern char lbl_8802974C[];
extern char lbl_88029A3C[];
extern char lbl_8802AEA8[];
extern char lbl_8802AEB4[];
extern char lbl_8802AEBC[];
extern char lbl_8802AEC4[];
extern char lbl_8802B4A0[];
extern char lbl_8802B898[];
extern char lbl_8802BB9C[];
extern char lbl_8802CE9C[];
extern char lbl_8802CEA0[];
extern char lbl_8802CEA4[];
extern char lbl_8802CEA8[];
extern char lbl_8802E854[];
extern char lbl_88039750[];
extern char lbl_8803A308[];
extern char lbl_8803A3B0[];
extern char lbl_8803A768[];
extern char lbl_8803A7C4[];
extern char lbl_8803A804[];
extern char lbl_8803B558[];
extern char lbl_8803B570[];
extern char lbl_8803BC50[];
extern char lbl_8803CB5C[];
extern char lbl_8803CC5C[];
extern char lbl_8803CCD4[];
extern char lbl_8803D1C8[];
extern char lbl_8803F500[];
extern char lbl_88041554[];
extern char lbl_880418E8[];
extern char lbl_880418F8[];
extern char lbl_8804190C[];
extern char lbl_8804191C[];
extern char lbl_88041928[];
extern char lbl_88041AA4[];
extern char lbl_88041AB0[];
extern char lbl_88041AC8[];
extern char lbl_88041AE8[];
extern char lbl_88043124[];
extern char lbl_88043148[];
extern char lbl_88043E74[];
extern char lbl_88048150[];
extern char lbl_8804816C[];
extern char lbl_8804818C[];
extern char lbl_88048608[];
extern char lbl_8804914C[];
extern char lbl_88080D8C[];
extern char lbl_88080DB0[];
extern char lbl_880818D4[];
extern char lbl_88081980[];
extern char lbl_88081B7C[];
extern char lbl_88081B8C[];
extern char lbl_88081BA0[];
extern char lbl_88081D34[];
extern char lbl_88081F80[];
extern char lbl_88082400[];
extern char lbl_88082588[];
extern char lbl_8808260C[];
extern char lbl_88082624[];
extern char lbl_8808262C[];
extern char lbl_88082C3C[];
extern char lbl_880842B8[];
extern char lbl_88086A04[];
extern char lbl_88086A64[];
extern char lbl_88086A7C[];
extern char lbl_880871F0[];
extern char lbl_8808726C[];
extern char lbl_8808772C[];
extern char lbl_88087738[];
extern char lbl_88087740[];
extern char lbl_880878F8[];
extern char lbl_88087904[];
extern char lbl_8808790C[];
extern char lbl_88087C28[];
extern char lbl_88087C34[];
extern char lbl_88087C48[];
extern char lbl_88087C54[];
extern char lbl_88087C60[];
extern char lbl_8808925C[];
extern char lbl_880892C8[];
extern char lbl_88089504[];
extern char lbl_8808BFAC[];
extern char lbl_8808C1BC[];
extern char lbl_8808C1C8[];
extern char lbl_8808C440[];
extern char lbl_8808C570[];
extern char lbl_8808C994[];
extern char lbl_8808C9B8[];
extern char lbl_8808D4C4[];
extern char lbl_8808D5F4[];
extern char lbl_8808D640[];
extern char lbl_8808D660[];
extern char lbl_8808EDE0[];
extern char lbl_8809D7C0[];
extern char lbl_880B0548[];
extern char lbl_880B4540[];
extern char lbl_880B4560[];
extern char lbl_880B45A8[];
extern char lbl_880BC988[];
extern char lbl_880BCA90[];
extern char lbl_880BCAA4[];
extern char lbl_880BCAB4[];
extern char lbl_880C06E0[];
extern char lbl_880C06F0[];
extern char lbl_880C0F8C[];
extern char lbl_880C1320[];
extern char lbl_880D1B40[];
extern char lbl_880D2F08[];
extern char lbl_880D2F14[];
extern char lbl_880D312C[];
extern char lbl_880D5858[];
extern char lbl_880D5928[];
extern char lbl_880D592C[];
extern char lbl_880E19DC[];
extern char lbl_880E9230[];
extern char lbl_880E9244[];
extern char lbl_880E9660[];
extern char lbl_880F20B0[];
extern char lbl_880F3260[];
extern char lbl_880F3268[];
extern char lbl_880F3270[];
extern char lbl_880F3278[];
extern char lbl_880F90BC[];
extern char lbl_8814B440[];
extern char lbl_88B30FA4[];
extern char lbl_88B30FA8[];
extern char lbl_88B31770[];
extern char lbl_88B31774[];
extern char lbl_88B3302C[];
extern char lbl_88B3A5B0[];
extern char lbl_88C26308[];
extern char lbl_88C264DC[];
extern char lbl_88CACF08[];
extern char lbl_88CACFCC[];
extern char lbl_88CACFFC[];
extern char lbl_88CAD02C[];
extern char lbl_88CAD05C[];
extern char lbl_88CAD32C[];
extern char lbl_88CAD338[];
extern char lbl_88CAD340[];
extern char lbl_88D25C34[];
extern char lbl_88D26F54[];
extern char lbl_88D26FD4[];
extern char lbl_88D3E418[];
extern char lbl_88D41FC4[];
extern char lbl_88D45B38[];
extern char lbl_88D49310[];
extern char lbl_88D49350[];
extern char ts4_call_seq_u32_lbl_88CACF08_8845A5A8[];
extern char ts4_if_get_u8_offc_885ECDC0[];
ts4_word KeTlsGetValue();
ts4_word RtlEnterCriticalSection();
ts4_word RtlLeaveCriticalSection();
ts4_word fn_881519D0();
ts4_word fn_8815E358();
float fn_8817A688(ts4_word, ts4_word, float);
ts4_word fn_88188130(ts4_word, float);
ts4_word fn_8818A530();
ts4_word fn_8818EB10();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word fn_88199F00();
ts4_word fn_8819A938();
ts4_word fn_8819ACC8();
ts4_word ts4_call_seq_u32_off0_8819AD80();
ts4_word ts4_if_call_seq_u32_off0_8819B0C8();
ts4_word ts4_if_call_seq_u32_off0_8819C190();
ts4_word fn_881A2508();
ts4_word fn_881A4B80(ts4_word, float);
ts4_word fn_881A4C18(ts4_word, float);
ts4_word fn_881AA7A0();
ts4_word fn_881B19A0();
ts4_word fn_881C60C8();
ts4_word fn_881E0970();
ts4_word fn_881EC8C8();
ts4_word fn_881F7958();
ts4_word fn_88213F70();
ts4_word fn_88225AA0();
ts4_word fn_8822C1C8();
ts4_word fn_8822CF28();
ts4_word fn_88236708();
ts4_word fn_8823F440();
ts4_word fn_88256430();
ts4_word fn_882566A8();
ts4_word fn_88256870();
ts4_word fn_88256AE0();
ts4_word fn_88256CA8();
ts4_word fn_88256F18();
ts4_word fn_882570E0();
ts4_word fn_88257350();
ts4_word fn_88257518();
ts4_word fn_88257788();
ts4_word fn_88257950();
ts4_word fn_88257BC0();
ts4_word fn_882580A0();
ts4_word fn_88258310();
ts4_word fn_882584D8();
ts4_word fn_88258748();
void ts4_loop_call_seq_u32_offc_8825C6C0();
void ts4_loop_call_seq_u32_offc_8825D140();
ts4_word fn_8825DA28();
void ts4_loop_call_seq_u32_offc_8825E5F8();
ts4_word fn_8825EE00();
ts4_word fn_8825EFC8();
ts4_word fn_8825F2D0();
ts4_word fn_8825F480();
ts4_word fn_8825F5E8();
void ts4_loop_call_seq_u32_offc_882619C0();
ts4_word fn_88265158();
ts4_word fn_882683B8();
void ts4_loop_call_seq_lbl_88D49310_8826C6C0();
ts4_word ts4_msg_buffer_alloc_88278620();
ts4_word fn_88290718();
ts4_word fn_88290778();
ts4_word fn_882B10F8();
ts4_word fn_882CDCD8();
ts4_word fn_88309DB8();
ts4_word fn_88315C60();
ts4_word fn_88315F10();
ts4_word fn_883194F0();
ts4_word fn_8831A650();
ts4_word ts4_loop_get_u32_off48_8831C9A8();
ts4_word fn_8831D8A0();
ts4_word fn_8831D9B0();
ts4_word fn_8831DBB0();
ts4_word fn_8831E228();
ts4_word fn_88322CA8();
ts4_word fn_88329680();
ts4_word fn_883296A0();
ts4_word fn_8832EBE0();
ts4_word fn_8832EDB0();
ts4_word fn_8832FEB0(ts4_word, float, float, float, float, float, float, float, float);
ts4_word fn_88331BE0();
ts4_word fn_883320F8();
ts4_word fn_883766B0();
ts4_word fn_88376D10();
ts4_word fn_883AFF60();
ts4_word fn_883B03F0(ts4_word, ts4_word, ts4_word, float);
ts4_word fn_883B0D50();
ts4_word fn_883B1460();
ts4_word fn_884123E0(ts4_word, ts4_word, float, float, ts4_word, ts4_word);
ts4_word fn_8841A328();
ts4_word fn_8841A590();
ts4_word fn_8841C428();
ts4_word fn_8841C678();
ts4_word fn_8841CBF8();
ts4_word fn_8841ED98();
ts4_word fn_8841F3E0();
float fn_8841F6D0();
ts4_word fn_88420E00();
ts4_word fn_88420F08();
ts4_word fn_884210E8();
ts4_word fn_88421338();
ts4_word fn_88423660();
ts4_word fn_88423788();
ts4_word fn_88431B10();
ts4_word fn_8843AE88();
ts4_word fn_8843C308();
ts4_word fn_88451F18();
ts4_word fn_884557F8();
ts4_word fn_88467F60();
ts4_word fn_88472530();
ts4_word fn_884727C8();
ts4_word fn_88487B38();
ts4_word fn_88488090(ts4_word, float);
ts4_word fn_88488828();
ts4_word fn_8848DCF0();
ts4_word fn_8848FE30();
ts4_word fn_88492108();
ts4_word fn_884934E8();
ts4_word fn_884A5A40();
ts4_word fn_884B76C8();
ts4_word fn_884C5468();
ts4_word fn_884C6A10();
ts4_word fn_884D7FD0();
ts4_word fn_884E1F10(float, float, float, float);
ts4_word fn_884E5F78();
ts4_word fn_884E6A28(ts4_word, ts4_word, float, ts4_word, ts4_word);
ts4_word fn_88502840();
ts4_word fn_8850C2F8();
ts4_word fn_8850C3D0();
ts4_word fn_88510C48();
ts4_word fn_885283E8();
ts4_word fn_88540E58();
ts4_word fn_88562EF8();
ts4_word fn_885630C0();
ts4_word fn_885635D0(ts4_word, ts4_word, ...);
double fn_88563A38(double, float);
double fn_88563F20();
ts4_word fn_885651F8();
ts4_word fn_88567440();
ts4_word fn_8857BBB0();
ts4_word fn_8858BE10();
ts4_word fn_8858CA98();
ts4_word fn_885AA560();
ts4_word ts4_pool_free_885B72F0();
ts4_word fn_885C3770();
ts4_word fn_885CD4B0();
ts4_word fn_885DC838(ts4_word, ts4_word, ...);
ts4_word fn_885E4248();
ts4_word fn_885E76C0();
ts4_word fn_885E7AD8();
ts4_word fn_885EA1A8();
ts4_word fn_885ECCD8();
ts4_word fn_885ECDF0();
ts4_word ts4_if_call_seq_fn_88423788_885ECF48();
ts4_word fn_885F2FD0();
ts4_word fn_885F36B8();
ts4_word fn_88606F40();
ts4_word fn_88607170();
ts4_word ts4_if_call_seq_fn_881F04B8_886131F0();
ts4_word fn_886F79F8();
ts4_word fn_88721B58();
ts4_word fn_88755B50();
ts4_word fn_88837880();
ts4_word fn_88887BE0();
ts4_word fn_888C34C0();
ts4_word fn_888C7368();
ts4_word fn_8892EE88();
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word ts4_assign_text_from_c_string();
ts4_word ts4_call_seq_fn_8841A510_8841A7C8();
ts4_word ts4_call_seq_fn_884D7C98_884D7F90();
ts4_word ts4_call_seq_fn_8857B830_8831A8B8();
ts4_word ts4_call_seq_lbl_88049700_88436488();
ts4_word ts4_call_seq_u32_off10_88837820();
ts4_word ts4_call_seq_u32_off4_88428B48();
ts4_word ts4_clone_byte_with_object_context();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_forward_field0_with_minus1_885EAD68();
ts4_word ts4_fvec_resize_88158B28();
ts4_word ts4_get_u32_off0_8822AFE8();
ts4_word ts4_get_u32_off0_8841EAC8();
ts4_word ts4_get_u32_off0_88428980();
ts4_word ts4_get_u32_off0_88428988();
ts4_word ts4_get_u32_off0_884289A8();
ts4_word ts4_get_u32_off0_884289B8();
ts4_word ts4_get_u32_off0_884289C8();
ts4_word ts4_get_u32_off0_884289D8();
ts4_word ts4_get_u32_off0_884289E8();
ts4_word ts4_get_u32_off0_88428A18();
ts4_word ts4_get_u32_off0_885EAD78();
ts4_word ts4_get_u32_off4_88426130();
ts4_word ts4_get_u32_off4_88428AC0();
ts4_word ts4_get_u32_off7c_8846AA28();
ts4_word ts4_get_u32_off8_88427198();
ts4_word ts4_get_u32_off8_88427208();
ts4_word ts4_get_u32_offe0_884761D8();
ts4_word ts4_get_u32_offe4_88476298();
ts4_word ts4_get_u32_offe8_88476280();
ts4_word ts4_if_call_seq_RtlEnterCriticalSection_8831AD58();
ts4_word ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98();
ts4_word ts4_if_call_seq_fn_883296A0_88319EA8();
ts4_word ts4_if_call_seq_u32_off0_882594A0();
ts4_word ts4_if_call_seq_u32_off0_884CCBB8();
ts4_word ts4_if_call_seq_u32_off14_8831D098();
ts4_word ts4_if_call_seq_u32_off14_8831D110();
ts4_word ts4_if_call_seq_u32_off4_88428890();
ts4_word ts4_if_call_seq_u32_offc_88565B10();
ts4_word ts4_if_call_seq_u32_offc_88565B58();
ts4_word ts4_if_call_seq_u8_off7d_881E1480();
ts4_word ts4_if_get_8830B508(ts4_word, float, float, float);
ts4_word ts4_if_get_u32_0xc_8841A820();
ts4_word ts4_if_get_u32_lbl_88D3E414_8819ABC8();
ts4_word ts4_if_get_u32_off0_8832C280(ts4_word, ts4_word, float, float);
ts4_word ts4_if_get_u32_off0_885E9628();
ts4_word ts4_if_get_u32_off188_88319E00();
ts4_word ts4_if_get_u32_off8_8841D058();
ts4_word ts4_if_set_u32_off0_8832BFC0();
ts4_word ts4_if_set_u32_off0_8832F930();
ts4_word ts4_index_u16_array_at_field0_884289F8();
ts4_word ts4_index_u16_array_at_field0_88428A08();
ts4_word ts4_init_descriptor_defaults_883AFBC0();
ts4_word ts4_init_range_and_run_service_opt_88164450();
ts4_word ts4_init_range_and_run_service_opt_88164F60();
ts4_word ts4_init_table256_883B1B08();
ts4_word ts4_lua_pushnumber_888240B8(ts4_word, double);
ts4_word ts4_ref_holder_dtor_8841D638();
ts4_word ts4_set_range_88325050(ts4_word, float, float, float);
ts4_word ts4_set_u32_off8_8847FA60();
ts4_word ts4_strlen_88329658();
ts4_word ts4_tailcall_fn_88315C60_88316068();
ts4_word ts4_tailcall_fn_884D7C98_884D7F38();
ts4_word ts4_tailcall_fn_88565410_885654D8();
ts4_word ts4_tailcall_fn_885654E8_885655D0();
ts4_word ts4_tailcall_fn_885659E8_88565AF8();
ts4_word ts4_tailcall_fn_88565BA8_88565CD8();
double ts4_tailcall_fn_88567A38_88567B98();
ts4_word ts4_tailcall_fn_88582660_8857B840();

/* Swing_DLL.xex 0x8815A8E8: loop_call_seq u32@0x4, u32@0x0, u32@0x4, u32@0x0, u32@0x8, u32@0xc */
ts4_word ts4_loop_call_seq_u32_off4_8815A8E8(ts4_word a0, ts4_word a1, float f1)
{
    ts4_word lv9;
    ts4_word lv10;
    ts4_word p13;
    ts4_word p14;
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t12;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    ts4_fvec_resize_88158B28((ts4_word)(a0 + 8), (ts4_word)((int)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4)) * (int)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))));
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 8);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 12);
    t8 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t6 != (ts4_word)t7) {
        lv9 = (ts4_word)(t8 + -4);
        lv10 = (ts4_word)t6;
        do {
            *(volatile float *)((char *)(ts4_word)((lv9 + 4)) + 0) = ((*(volatile float *)((char *)(ts4_word)(lv10) + 0)) * f1);
            t12 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 12);
            p13 = (ts4_word)(lv9 + 4);
            p14 = (ts4_word)(lv10 + 4);
            lv9 = p13;
            lv10 = p14;
        } while ((ts4_word)p14 != (ts4_word)t12);
    }
    return a0;
}

/* Swing_DLL.xex 0x88163C00: if_call_seq u32@0x30, ts4_init_range_and_run_service_opt_88164450, ts4_clone_byte_with_object_context */
ts4_word ts4_if_call_seq_u32_off30_88163C00(ts4_word a0, ts4_args3 sp1, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_init_range_and_run_service_opt_88164450((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&a3, (ts4_word)0);
        t3 = ts4_clone_byte_with_object_context((ts4_word)t2, (ts4_word)a4);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88163DD0: if_call_seq u32@0x30, ts4_init_range_and_run_service_opt_88164F60, ts4_get_u32_off0_8822AFE8 */
ts4_word ts4_if_call_seq_u32_off30_88163DD0(ts4_word a0, ts4_args3 sp1, ts4_word a3, ts4_word a4)
{
    ts4_word p4;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    p4 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = ts4_init_range_and_run_service_opt_88164F60((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&a3, (ts4_word)0);
        t3 = ts4_get_u32_off0_8822AFE8((ts4_word)t2, (ts4_word)a4);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88179480: if_call_seq u32@0x0, u32@0x10, u32@0xc, u32@0x14, fn_8817A688 */
float ts4_if_call_seq_u32_off0_88179480(ts4_word a0, ts4_word a1, float f1, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    float pf7;
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t4;
    float t6;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)((t1 + a1)) + 16);
    pf7 = f1;
    if ((int)t2 >= 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)((t1 + a1)) + 12);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
        t6 = fn_8817A688((ts4_word)a0, (ts4_word)(t1 + a1), (*(float *)((char *)(ts4_word)((t3 << 2)) + t4)));
        *(float *)((char *)(ts4_word)((t2 << 2)) + t4) = t6;
        pf7 = t6;
    }
    return pf7;
}

/* Swing_DLL.xex 0x8817BDD8: if_call_seq u32@0x24, u32@0x24, u8@0x7, u32@0x154, u32@0x8, u32@0x150 */
void ts4_if_call_seq_u32_off24_8817BDD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t2;
    ts4_word t6;

    if ((ts4_word)a1 != 0) {
        t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36);
        if ((int)t2 != 0 && (ts4_word)(*(volatile unsigned char *)((char *)(ts4_word)(a0) + 7)) != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 336) = (ts4_word)a1;
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 340) = (ts4_word)0;
            fn_888C7368((ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0)));
            t6 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 28);
            fn_888C34C0((ts4_word)(a0 + 356), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)(t6 & 0xffff));
            memset((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 328)), (ts4_word)0, (ts4_word)104);
        } else {
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 340) = (ts4_word)a1;
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
        }
    }
    return;
}

/* Swing_DLL.xex 0x8818A4C8: if_get RtlEnterCriticalSection, u32@0x24, u32@0x0, u32@0x24, u32@0x0, u32@0x8 */
void ts4_if_get_RtlEnterCriticalSection_8818A4C8(ts4_word a0, ts4_word a1)
{

    if ((ts4_word)a1 != 0) {
        RtlEnterCriticalSection((ts4_word)(a0 + 8));
        *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 36));
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a1;
        ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
    }
    return;
}

/* Swing_DLL.xex 0x8818BDE0: if_get u32@0x0, u32@0x1c, vcall, u32@0x10, ts4_tailcall_fn_885659E8_88565AF8, u32@0x10 */
ts4_word ts4_if_get_u32_off0_8818BDE0(ts4_word a0, ts4_word a1, ts4_word a2, int a3)
{
    ts4_word t6;
    int t8;
    int t11;

    if ((ts4_word)a2 == 0) {
        return 0;
    }
    if ((int)a3 != -1) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0, (ts4_word)a3, (ts4_word)0);
    }
    t6 = ts4_tailcall_fn_885659E8_88565AF8((ts4_word)a1, (ts4_word)1, (ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    if ((ts4_word)t6 == 0) {
        t8 = ts4_if_call_seq_u32_offc_88565B10((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
        if ((int)t8 == 0) {
            *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)1;
            return 0;
        }
    }
    t11 = ts4_if_call_seq_u32_offc_88565B58((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
    if ((int)t11 != 0) {
        ts4_tailcall_fn_88565BA8_88565CD8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)));
        *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)1;
        return 0;
    }
    return t6;
}

/* Swing_DLL.xex 0x8818C630: if_call_seq fn_88567440, u32@0x14, u32@0x10, u32@0x8, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88567440_8818C630(ts4_args2 sp0)
{
    ts4_word p3;
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t1 = fn_88567440((ts4_word)(ts4_word)&sp0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 20);
    if ((ts4_word)t2 > 1980) {
        p4 = (ts4_word)(t2 + -1980);
    } else {
        p3 = (ts4_word)t2;
        if ((ts4_word)t2 > 80) {
            p3 = (ts4_word)(t2 + -80);
        }
        p4 = (ts4_word)p3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(t1) + 16);
    t6 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    t7 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    t8 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    return (((((t6 << 6) + t7) << 5) + ((int)t8 / 2)) | ((((((p4 << 4) + t5) + 1) << 5) + (*(ts4_word *)((char *)(ts4_word)(t1) + 12))) << 16));
}

/* Swing_DLL.xex 0x88190B00: if_get u32@0x10, u32@0x0, u32@0x14, u32@0xc, u32@0x8, u32@0x4c */
ts4_word ts4_if_get_u32_off10_88190B00(ts4_word a0)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    int t5;
    ts4_word t11;
    int t12;
    int t13;
    ts4_word t16;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 == 0) {
        return -1;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((ts4_word)t3 < (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t2) + 12))) {
        t5 = *(ts4_word *)((char *)(ts4_word)(t2) + 8);
        p8 = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + (t3 << 2))) + (*(ts4_word *)((char *)(ts4_word)(t1) + 76)));
    } else {
        p8 = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t11 != 0) {
        t13 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
        if ((int)t13 != -1) {
            return ((t13 - (*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + t12);
        }
    }
    t16 = *(ts4_word *)((char *)(ts4_word)(p8) + 24);
    if ((ts4_word)(t16 & 0x1e0000) == 0) {
        return t12;
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 72));
}

/* Swing_DLL.xex 0x88192AC8: if_call_seq u32@0x14, u32@0x1c, u32@0x14, fn_881992A8, u32@0x14, fn_88199068 */
void ts4_if_call_seq_u32_off14_88192AC8(ts4_word a0, ts4_word a1)
{
    ts4_word p11;
    ts4_word loc50[2];
    int t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t3;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((int)t1 == 0 || (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 28)) != (ts4_word)a1) {
        if ((ts4_word)a1 != 0 && (int)a1 != -1) {
            loc50[0] = (ts4_word)1000;
            loc50[1] = (ts4_word)0;
            t6 = fn_88199068((ts4_word)0, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
            t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
            if ((ts4_word)t7 != 0) {
                fn_881992A8((ts4_word)0, (ts4_word)t7);
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t6;
            p11 = (ts4_word)0;
        } else {
            t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
            if ((ts4_word)t3 != 0) {
                fn_881992A8((ts4_word)0, (ts4_word)t3);
            }
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
            p11 = (ts4_word)0;
        }
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)p11;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)-1;
    }
    return;
}

/* Swing_DLL.xex 0x88198B40: loop_get u32@0x84, u32@0x88, u32@0x14, u8@0xc, u32@0x0, u32@0x20 */
ts4_word ts4_loop_get_u32_off84_88198B40(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv4;
    ts4_word lv5;
    ts4_word p44;
    ts4_word p45;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    unsigned char t25;
    ts4_word t28;
    ts4_word t30;
    ts4_word t31;
    ts4_word t33;
    ts4_word t34;
    ts4_word t35;
    ts4_word t37;
    ts4_word t38;
    ts4_word t39;
    ts4_word t41;
    ts4_word t42;
    ts4_word t43;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 20);
    lv4 = (ts4_word)t1;
    lv5 = (ts4_word)t3;
    while ((ts4_word)lv5 != (ts4_word)t2) {
        t25 = *(unsigned char *)((char *)(ts4_word)(lv5) + 12);
        if ((ts4_word)(t25 & 0xffffffc0) != 0) {
            return 0;
        }
        t28 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 32))))((ts4_word)a0, (ts4_word)lv5);
        if ((ts4_word)(t28 & 0xff) == 0 || (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 16)) != (ts4_word)lv4) {
            return 0;
        }
        t30 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t31 = *(ts4_word *)((char *)(ts4_word)(lv5) + 0);
        t33 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t30) + 32))))((ts4_word)a0, (ts4_word)t31);
        if ((ts4_word)(t33 & 0xff) == 0) {
            return 0;
        }
        t34 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t35 = *(ts4_word *)((char *)(ts4_word)(lv5) + 4);
        t37 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t34) + 32))))((ts4_word)a0, (ts4_word)t35);
        if ((ts4_word)(t37 & 0xff) == 0) {
            return 0;
        }
        t38 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t39 = *(ts4_word *)((char *)(ts4_word)(lv5) + 20);
        t41 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t38) + 32))))((ts4_word)a0, (ts4_word)t39);
        if ((ts4_word)(t41 & 0xff) == 0) {
            return 0;
        }
        t42 = *(ts4_word *)((char *)(ts4_word)(lv5) + 20);
        t43 = *(ts4_word *)((char *)(ts4_word)(t42) + 16);
        if ((ts4_word)t43 != (ts4_word)lv5) {
            return 0;
        }
        p44 = (ts4_word)lv5;
        p45 = (ts4_word)t42;
        lv4 = p44;
        lv5 = p45;
    }
    return 1;
}

/* Swing_DLL.xex 0x88199E90: if_call_seq fn_88199F00, u32@0x4, fn_8818A530, u32@0x4, u32@0x0, fn_8818A530 */
ts4_word ts4_if_call_seq_fn_88199F00_88199E90(ts4_word a0)
{
    ts4_word p6;
    ts4_word t5;

    p6 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        fn_88199F00((ts4_word)a0);
        fn_8818A530((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        fn_8818A530((ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
        t5 = fn_881992A8((ts4_word)0, (ts4_word)a0);
        p6 = (ts4_word)t5;
    }
    return p6;
}

/* Swing_DLL.xex 0x881A23E8: if_call_seq u32@0x0, u32@0x8, fn_881A2508, u32@0x0, u32@0x8, fn_881A2508 */
ts4_word ts4_if_call_seq_u32_off0_881A23E8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    double t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    switch ((ts4_word)((t1 - ((0) | 65531)))) {
        case 0:
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        fn_881A2508((ts4_word)a0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((0) | 65531);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t2;
        return a0;
        case 1:
        t4 = *(double *)((char *)(ts4_word)(a1) + 8);
        fn_881A2508((ts4_word)a0);
        *(volatile double *)((char *)(ts4_word)(a0) + 8) = t4;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((0) | 65532);
        return a0;
        case 2:
        case 4:
        fn_881A2508((ts4_word)a0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((0) | 65533);
        if ((int)(a0 + 8) != 0) {
            fn_8818EB10((ts4_word)(a0 + 8), (ts4_word)(a1 + 8));
            return a0;
        }
        return a0;
        case 3:
        fn_881A2508((ts4_word)a0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((0) | 65534);
        if ((int)(a0 + 8) != 0) {
            fn_8819ACC8((ts4_word)(a0 + 8), (ts4_word)(a1 + 8));
            return a0;
        }
        return a0;
        default:
        fn_881A2508((ts4_word)a0);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        return a0;
    }
}

/* Swing_DLL.xex 0x881A4A60: call_seq fn_881A4C18 */
ts4_word ts4_call_seq_fn_881A4C18_881A4A60(ts4_word a0, float f1)
{
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    ts4_word loc50[16];
    ts4_word t1;

    t1 = fn_881A4C18((ts4_word)(ts4_word)&loc50[0], f1);
    vv2 = *(__vector4 *)((ts4_word)(t1));
    vv3 = *(__vector4 *)((ts4_word)(t1 + 16));
    vv4 = *(__vector4 *)((ts4_word)(t1 + 32));
    vv5 = *(__vector4 *)((ts4_word)(t1 + 48));
    *(__vector4 *)((ts4_word)(a0)) = vv2;
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv3;
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv4;
    *(__vector4 *)((ts4_word)(a0 + 48)) = vv5;
    return t1;
}

/* Swing_DLL.xex 0x881A4AC0: call_seq fn_881A4B80 */
ts4_word ts4_call_seq_fn_881A4B80_881A4AC0(ts4_word a0, float f1)
{
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    ts4_word loc50[16];
    ts4_word t1;

    t1 = fn_881A4B80((ts4_word)(ts4_word)&loc50[0], f1);
    vv2 = *(__vector4 *)((ts4_word)(t1));
    vv3 = *(__vector4 *)((ts4_word)(t1 + 16));
    vv4 = *(__vector4 *)((ts4_word)(t1 + 32));
    vv5 = *(__vector4 *)((ts4_word)(t1 + 48));
    *(__vector4 *)((ts4_word)(a0)) = vv2;
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv3;
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv4;
    *(__vector4 *)((ts4_word)(a0 + 48)) = vv5;
    return t1;
}

/* Swing_DLL.xex 0x881A4B20: call_seq fn_88188130 */
ts4_word ts4_call_seq_fn_88188130_881A4B20(ts4_word a0, float f1)
{
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    ts4_word loc50[16];
    ts4_word t1;

    t1 = fn_88188130((ts4_word)(ts4_word)&loc50[0], f1);
    vv2 = *(__vector4 *)((ts4_word)(t1));
    vv3 = *(__vector4 *)((ts4_word)(t1 + 16));
    vv4 = *(__vector4 *)((ts4_word)(t1 + 32));
    vv5 = *(__vector4 *)((ts4_word)(t1 + 48));
    *(__vector4 *)((ts4_word)(a0)) = vv2;
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv3;
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv4;
    *(__vector4 *)((ts4_word)(a0 + 48)) = vv5;
    return t1;
}

/* Swing_DLL.xex 0x881A7608: fn  */
void ts4_fn_881A7608(ts4_word a0, ts4_word a1)
{
    __vector4 vv1;
    __vector4 vv2;

    vv1 = __lvlx((void *)(a1), 0);
    vv2 = __vspltw(vv1, 0);
    *(__vector4 *)((ts4_word)(a0)) = vv2;
    return;
}

/* Swing_DLL.xex 0x881B04C0: if_get u32@0xc, u32@0xc, u8@0x4, u8@0x4, u32@0x10, u32@0x10 */
ts4_word ts4_if_get_u32_offc_881B04C0(ts4_word a0, ts4_word a1)
{
    ts4_word p13;
    ts4_word p14;
    int t1;
    int t2;
    unsigned char t3;
    unsigned char t4;
    int t5;
    int t6;
    int t7;
    int t8;
    int t9;
    int t10;
    ts4_word t11;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 12);
    if ((int)t1 == (int)t2) {
        t3 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 4);
        t4 = *(volatile unsigned char *)((char *)(ts4_word)(a1) + 4);
        if ((ts4_word)t3 == (ts4_word)t4) {
            t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
            t6 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 16);
            if ((int)t5 == (int)t6) {
                t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
                t8 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 20);
                if ((int)t7 == (int)t8) {
                    t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
                    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 24);
                    p13 = (ts4_word)t10;
                    p14 = (ts4_word)t9;
                    if ((int)t9 == (int)t10) {
                        t11 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
                        p13 = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 8));
                        p14 = (ts4_word)t11;
                    }
                    return ((int)p14 < (int)p13);
                }
                return ((int)t8 < (int)t7);
            }
            return ((int)t6 < (int)t5);
        }
        return ((ts4_word)t4 < (ts4_word)t3);
    }
    return ((int)t2 < (int)t1);
}

/* Swing_DLL.xex 0x881B1A98: call_seq u32@0x0, ts4_lua_pushnumber_888240B8, u32@0x0, u32@0x0, u32@0xc, u32@0x10 */
ts4_word ts4_call_seq_u32_off0_881B1A98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t3;
    ts4_word t4;

    ts4_lua_pushnumber_888240B8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), ((double)((ts4_s64)(int)a2)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 12);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((int)(t4 - (*(ts4_word *)((char *)(ts4_word)(t3) + 16))) >> 4);
    return a0;
}

/* Swing_DLL.xex 0x881B1F68: call_seq ts4_tailcall_fn_88565410_885654D8, fn_88562EF8 */
ts4_word ts4_call_seq_ts4_tailcall_fn_88565410_885654D8_881B1F68(ts4_word a0, ts4_word a1, ...)
{
    ts4_va_list ap;
    ts4_word loc60[202];
    ts4_word t2;

    (void)a0;
    TS4_VA_START(ap, a1);
    ts4_tailcall_fn_88565410_885654D8((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)ap);
    t2 = fn_88562EF8((ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Swing_DLL.xex 0x881BAB28: if_get u32@0x90, u32@0x90, u32@0x8c, u32@0x8c, u32@0x8c, u32@0x8c */
ts4_word ts4_if_get_u32_off90_881BAB28(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 144);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
    if ((ts4_word)t2 < (ts4_word)t1) {
        return 1;
    }
    if ((ts4_word)t2 == (ts4_word)t1) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 140);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
        if ((ts4_word)t6 < (ts4_word)t5) {
            return 1;
        }
        if ((ts4_word)t6 == (ts4_word)t5) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
            return ((ts4_word)t7 < (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 136)));
        }
        return 0;
    }
    return 0;
}

/* Swing_DLL.xex 0x881C8D98: loop_get u32@0x0, u32@0x1c, u32@0x14, u32@0x8, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_881C8D98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word lv6;
    ts4_word lv7;
    ts4_word p11;
    ts4_word p12;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(t4 % t2);
    if ((ts4_word)t3 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
        t5 = *(ts4_word *)((char *)(ts4_word)(((t4 % t2) << 2)) + t3);
        lv6 = (ts4_word)0;
        lv7 = (ts4_word)t5;
        while ((ts4_word)lv7 != 0) {
            t8 = *(ts4_word *)((char *)(ts4_word)(lv7) + 12);
            if ((ts4_word)t8 == (ts4_word)t4 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv7) + 0)) == (ts4_word)t1) {
                *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)lv6;
                return lv7;
            }
            t10 = *(ts4_word *)((char *)(ts4_word)(lv7) + 8);
            p11 = (ts4_word)lv7;
            p12 = (ts4_word)t10;
            lv6 = p11;
            lv7 = p12;
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x881CDFE0: call_seq fn_88837880, ts4_call_seq_u32_off10_88837820, fn_881B19A0, ts4_call_seq_u32_off10_88837820, fn_881B19A0, ts4_call_seq_u32_off10_88837820 */
ts4_word ts4_call_seq_fn_88837880_881CDFE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[8];
    ts4_word locb0[8];
    ts4_word loc70[8];
    ts4_word loc90[8];
    ts4_word locd0[8];
    ts4_word t2;
    float t4;
    ts4_word t6;
    float t8;
    ts4_word t10;
    float t12;
    ts4_word t14;
    float t16;

    fn_88837880((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t2 = ts4_call_seq_u32_off10_88837820((ts4_word)(ts4_word)&locb0[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)1);
    t4 = ((float)(*(double *)((char *)(ts4_word)(t2) + 16)));
    fn_881B19A0((ts4_word)(ts4_word)&locb0[0]);
    t6 = ts4_call_seq_u32_off10_88837820((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)2);
    t8 = ((float)(*(double *)((char *)(ts4_word)(t6) + 16)));
    fn_881B19A0((ts4_word)(ts4_word)&loc70[0]);
    t10 = ts4_call_seq_u32_off10_88837820((ts4_word)(ts4_word)&loc90[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)3);
    t12 = ((float)(*(double *)((char *)(ts4_word)(t10) + 16)));
    fn_881B19A0((ts4_word)(ts4_word)&loc90[0]);
    t14 = ts4_call_seq_u32_off10_88837820((ts4_word)(ts4_word)&locd0[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)4);
    t16 = ((float)(*(double *)((char *)(ts4_word)(t14) + 16)));
    fn_881B19A0((ts4_word)(ts4_word)&locd0[0]);
    *(volatile float *)((char *)(ts4_word)(a2) + 0) = t4;
    *(volatile float *)((char *)(ts4_word)(a2) + 4) = t8;
    *(volatile float *)((char *)(ts4_word)(a2) + 8) = t12;
    *(volatile float *)((char *)(ts4_word)(a2) + 12) = t16;
    fn_881B19A0((ts4_word)(ts4_word)&loc50[0]);
    return 1;
}

/* Swing_DLL.xex 0x881E0C00: if_get u32@0x0, u32@0x50, vcall, u8@0x7c, u8@0x7c, u32@0x28 */
ts4_word ts4_if_get_u32_off0_881E0C00(ts4_word a0)
{
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t11;

    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 80))))((ts4_word)a0, (ts4_word)1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 124) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a0) + 124)) | 64);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t6 = ts4_if_call_seq_u8_off7d_881E1480((ts4_word)a0);
    if ((ts4_word)t6 == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    } else {
        t7 = ts4_if_call_seq_u8_off7d_881E1480((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 40)) + 1) % t7);
    }
    t11 = fn_881E0970((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t5;
    return t11;
}

/* Swing_DLL.xex 0x881E3870: if_call_seq u32@0x0, fn_8818EB10, lbl_880C1320, ts4_assign_text_from_c_string, u32@0x8, lbl_880D312C */
ts4_word ts4_if_call_seq_u32_off0_881E3870(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[28];
    int t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((int)t1 != 2 && (int)t1 != 5) {
        if ((int)t1 == 4) {
            fn_885635D0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D5858, (double)((*(double *)((char *)(ts4_word)(a1) + 8))));
            ts4_assign_text_from_c_string((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        } else {
            if ((int)t1 == 1) {
                fn_885635D0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D312C, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 8)));
                ts4_assign_text_from_c_string((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
            } else {
                ts4_assign_text_from_c_string((ts4_word)a0, (ts4_word)(ts4_word)lbl_880C1320);
            }
        }
    } else {
        fn_8818EB10((ts4_word)a0, (ts4_word)(a1 + 16));
    }
    return a0;
}

/* Swing_DLL.xex 0x881ED2A0: if_call_seq u32@0x4, u32@0x1560, u32@-0xc, fn_881AA7A0, lbl_880E9230, ts4_assign_text_from_c_string */
ts4_word ts4_if_call_seq_u32_off4_881ED2A0(ts4_word a0)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    int t3;
    ts4_word t9;
    int t10;
    ts4_word t22;
    int t23;

    t3 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 5472))) + -12);
    if ((int)t3 == 0) {
        fn_881AA7A0((ts4_word)(ts4_word)&loc58[0]);
        ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E9230);
        fn_881EC8C8((ts4_word)(*(ts4_word *)lbl_88D41FC4), (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
        ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc50[0]);
        t9 = loc58[0];
        t10 = *(ts4_word *)((char *)(ts4_word)(t9) + -12);
        if ((int)t10 != 0) {
            ts4_if_call_seq_u32_off0_8819C190((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 5472), (ts4_word)(ts4_word)&loc58[0]);
        } else {
            ts4_if_get_u32_lbl_88D3E414_8819ABC8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E19DC);
            ts4_if_call_seq_u32_off0_8819C190((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 5472), (ts4_word)(ts4_word)&loc50[0]);
            ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc50[0]);
        }
        ts4_assign_text_from_c_string((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880E9244);
        fn_881EC8C8((ts4_word)(*(ts4_word *)lbl_88D41FC4), (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
        ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc50[0]);
        t22 = loc58[0];
        t23 = *(ts4_word *)((char *)(ts4_word)(t22) + -12);
        if ((int)t23 != 0) {
            ts4_if_call_seq_u32_off0_8819C190((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 5476), (ts4_word)(ts4_word)&loc58[0]);
        } else {
            ts4_if_get_u32_lbl_88D3E414_8819ABC8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D2F08);
            ts4_if_call_seq_u32_off0_8819C190((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 5476), (ts4_word)(ts4_word)&loc50[0]);
            ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc50[0]);
        }
        ts4_call_seq_u32_off0_8819AD80((ts4_word)(ts4_word)&loc58[0]);
    }
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 5472);
}

/* Swing_DLL.xex 0x881EEB38: loop_get u32@0x1c, u32@0x14, u32@0x0, u32@0x0, u32@0x0, u32@0xc */
ts4_word ts4_loop_get_u32_off1c_881EEB38(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word lv4;
    ts4_word lv5;
    ts4_word p9;
    ts4_word p10;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(a1 % t1);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)0;
        t3 = *(ts4_word *)((char *)(ts4_word)(((a1 % t1) << 2)) + t2);
        lv4 = (ts4_word)0;
        lv5 = (ts4_word)t3;
        while ((ts4_word)lv5 != 0) {
            t6 = *(ts4_word *)((char *)(ts4_word)(lv5) + 12);
            if ((ts4_word)t6 == (ts4_word)a1 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 0)) == (ts4_word)a1) {
                *(ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)lv4;
                return lv5;
            }
            t8 = *(ts4_word *)((char *)(ts4_word)(lv5) + 8);
            p9 = (ts4_word)lv5;
            p10 = (ts4_word)t8;
            lv4 = p9;
            lv5 = p10;
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x881F4108: addr fn_881F7958, lbl_880E9660, u32@0x0, fn_881519D0, u32@0x0, u32@0x10 */
ts4_word ts4_addr_fn_881F7958_881F4108(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = fn_881F7958((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9660;
    t2 = fn_881519D0((ts4_word)t1);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(t5 + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 32) = (unsigned short)2046;
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 35) = (unsigned char)2;
    return a0;
}

/* Swing_DLL.xex 0x882016F8: if_get u32@lbl_88D3E418, fn_8819A938, u32@0x0, u32@0x10, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_lbl_88D3E418_882016F8(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)lbl_88D3E418;
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        t2 = fn_8819A938((ts4_word)t1);
        p3 = (ts4_word)t2;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(p3) + 0))) + 16))))((ts4_word)p3)) + 16);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    ts4_if_call_seq_u32_off0_8819B0C8((ts4_word)a0, (ts4_word)a1);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a1) + 4));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a1) + 5));
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)(*(volatile unsigned char *)((char *)(ts4_word)(a1) + 6));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 12));
    return a0;
}

/* Swing_DLL.xex 0x88210738: loop_call_seq u32@0x8, u32@0x4, u32@0x0, u32@0x0, u32@0x8, u32@-0xc */
ts4_word ts4_loop_call_seq_u32_off8_88210738(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv3;
    ts4_word p10;
    ts4_word p13;
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    int t7;
    int t8;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    while ((ts4_word)lv3 != (ts4_word)t1) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 0);
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(t4) + 8);
        t7 = *(ts4_word *)((char *)(ts4_word)(t5) + -12);
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + -12);
        if ((int)t8 != (int)t7) {
            p10 = (ts4_word)0;
        } else {
            t9 = fn_885630C0((ts4_word)t6, (ts4_word)t5, (ts4_word)t8);
            p10 = (ts4_word)(t9 == 0);
        }
        if ((ts4_word)(p10 & 0xff) != 0 && (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 36)) & a2) != 0) {
            return t4;
        }
        p13 = (ts4_word)(lv3 + 4);
        lv3 = p13;
    }
    return 0;
}

/* Swing_DLL.xex 0x88213B88: if_call_seq u32@0x8, u32@0x4, fn_88213F70, fn_881C60C8, u32@0x4, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off8_88213B88(ts4_word a0, ts4_word a1)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        p5 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t4 = fn_881C60C8((ts4_word)t2, (ts4_word)a1);
            p5 = (ts4_word)t4;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 56);
        return p5;
    }
    t3 = fn_88213F70((ts4_word)a0, (ts4_word)t2, (ts4_word)a1, (ts4_word)1, (ts4_word)1);
    return t3;
}

/* Swing_DLL.xex 0x88223798: if_get u32@0xc, u32@0x4, fn_88225AA0, u32@0x4, u32@0x4 */
ts4_word ts4_if_get_u32_offc_88223798(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        if ((ts4_word)t2 != 0) {
            *(ts4_q8 *)(t2) = *(ts4_q8 *)(a1);
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 64);
        return a0;
    }
    return fn_88225AA0((ts4_word)a0, (ts4_word)t2, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88223DA0: loop_call_seq u32@0x0, u32@0x4, u32@0x8, ts4_destroy_owned_object, u32@0x0, u32@lbl_88D45B38 */
void ts4_loop_call_seq_u32_off0_88223DA0(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t11;
    ts4_word t13;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    lv4 = (ts4_word)t1;
    while ((ts4_word)lv4 != (ts4_word)t2) {
        ts4_destroy_owned_object((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv4) + 8)));
        p8 = (ts4_word)(lv4 + 32);
        lv4 = p8;
    }
    t11 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t11 != 0) {
        t13 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t13 != 0) {
            ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t13, (ts4_word)t11, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return;
        }
        fn_885651F8((ts4_word)t11, (ts4_word)t11);
        return;
    }
    return;
}

/* Swing_DLL.xex 0x882244F0: if_call_seq u32@0x0, u32@0x4, fn_8822CF28, fn_8823F440, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off0_882244F0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[32];
    ts4_word t1;
    ts4_word t2;
    float t3;
    ts4_word t5;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    loc50[28] = (ts4_word)0;
    t3 = *(float *)lbl_8814B440;
    *(float *)((char *)loc50 + 0) = t3;
    *(float *)((char *)loc50 + 4) = t3;
    *(float *)((char *)loc50 + 8) = t3;
    *(float *)((char *)loc50 + 12) = t3;
    *(float *)((char *)loc50 + 16) = t3;
    *(float *)((char *)loc50 + 20) = t3;
    *(float *)((char *)loc50 + 24) = t3;
    *(float *)((char *)loc50 + 28) = t3;
    *(float *)((char *)loc50 + 32) = t3;
    *(float *)((char *)loc50 + 36) = t3;
    *(float *)((char *)loc50 + 40) = t3;
    *(float *)((char *)loc50 + 44) = t3;
    *(float *)((char *)loc50 + 48) = t3;
    *(float *)((char *)loc50 + 52) = t3;
    *(float *)((char *)loc50 + 56) = t3;
    *(float *)((char *)loc50 + 60) = t3;
    *(float *)((char *)loc50 + 64) = t3;
    *(float *)((char *)loc50 + 68) = t3;
    *(float *)((char *)loc50 + 72) = t3;
    *(float *)((char *)loc50 + 76) = t3;
    *(float *)((char *)loc50 + 80) = t3;
    *(float *)((char *)loc50 + 84) = t3;
    *(float *)((char *)loc50 + 88) = t3;
    *(float *)((char *)loc50 + 92) = t3;
    *(float *)((char *)loc50 + 96) = t3;
    *(float *)((char *)loc50 + 100) = t3;
    *(float *)((char *)loc50 + 104) = t3;
    *(float *)((char *)loc50 + 108) = t3;
    if ((ts4_word)a1 < (ts4_word)((int)(t2 - t1) >> 7)) {
        t5 = fn_8823F440((ts4_word)t2, (ts4_word)t2, (ts4_word)((a1 << 7) + t1), (ts4_word)(t2 - t1), (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t5;
        return t5;
    }
    t4 = fn_8822CF28((ts4_word)a0, (ts4_word)t2, (ts4_word)(a1 - ((int)(t2 - t1) >> 7)), (ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    return t4;
}

/* Swing_DLL.xex 0x88226A50: loop_call_seq u32@0x0, u32@0x4, ts4_if_call_seq_u32_off0_882594A0, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
void ts4_loop_call_seq_u32_off0_88226A50(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t10;
    ts4_word t12;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    lv4 = (ts4_word)t1;
    while ((ts4_word)lv4 != (ts4_word)t2) {
        ts4_if_call_seq_u32_off0_882594A0((ts4_word)lv4);
        p7 = (ts4_word)(lv4 + 16);
        lv4 = p7;
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t10 != 0) {
        t12 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t12 != 0) {
            ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t12, (ts4_word)t10, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return;
        }
        fn_885651F8((ts4_word)t10, (ts4_word)t10);
        return;
    }
    return;
}

/* Swing_DLL.xex 0x8822CB68: if_call_seq fn_8892EE88, fn_8892EE88, u8@0x8, u8@0x9, u8@0x9, u32@0x4 */
ts4_word ts4_if_call_seq_fn_8892EE88_8822CB68(ts4_word a0, ts4_args3 sp1)
{
    unsigned char t4;
    unsigned char t6;

    (void)sp1.w[2];
    fn_8892EE88((ts4_word)a0, sp1, (ts4_word)1);
    fn_8892EE88((ts4_word)a0, sp1, (ts4_word)0);
    t4 = *(unsigned char *)((char *)(ts4_word)(a0) + 8);
    if ((ts4_word)t4 != 0) {
        t6 = *(unsigned char *)((char *)(ts4_word)(a0) + 9);
        if ((ts4_word)t6 != 0) {
            return (a0 - (*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        }
        return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    }
    return 0;
}

/* Swing_DLL.xex 0x882368D8: loop_call_seq lbl_880F20B0, fn_88236708, u32@0x11c, u32@0x120, u32@0x0, lbl_880C1320 */
void ts4_loop_call_seq_lbl_880F20B0_882368D8(ts4_word a0, ts4_word a1)
{
    ts4_word lv12;
    ts4_word p16;
    ts4_word lv22;
    ts4_word p25;
    ts4_word loc60[70];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t19;
    ts4_word t20;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    int t13;
    ts4_word t31;

    fn_88236708((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880F20B0, (ts4_word)(a0 + 4));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 284);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 288);
    if ((ts4_word)t2 != (ts4_word)t3) {
        fn_88256430((ts4_word)a0, (ts4_word)a1);
        return;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 4)) + 0);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_88887BE0((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
    if ((ts4_word)t6 != (ts4_word)t7) {
        t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
        t20 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t7 - t6) / (int)268));
        lv22 = (ts4_word)t19;
        while ((ts4_word)lv22 < (ts4_word)t20) {
            fn_882566A8((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv22) + 0)), (ts4_word)1);
            p25 = (ts4_word)(lv22 + 268);
            lv22 = p25;
        }
    } else {
        t8 = loc50[1];
        t9 = loc50[0];
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t8 - t9) / (int)268));
        t11 = loc50[0];
        lv12 = (ts4_word)t11;
        while ((ts4_word)lv12 != (ts4_word)t8) {
            t13 = *(volatile ts4_word *)((char *)(ts4_word)(lv12) + 0);
            if ((int)t13 == 2) {
                fn_882566A8((ts4_word)a0, (ts4_word)a1, (ts4_word)(lv12 + 4), (ts4_word)0);
            }
            p16 = (ts4_word)(lv12 + 268);
            lv12 = p16;
        }
    }
    t31 = loc50[0];
    if ((ts4_word)t31 != 0) {
        ts4_destroy_owned_object((ts4_word)t31);
    }
    return;
}

/* Swing_DLL.xex 0x88236F20: loop_call_seq lbl_880F20B0, fn_88236708, u32@0x11c, u32@0x120, u32@0x0, lbl_880C1320 */
void ts4_loop_call_seq_lbl_880F20B0_88236F20(ts4_word a0, ts4_word a1)
{
    ts4_word lv12;
    ts4_word p16;
    ts4_word lv22;
    ts4_word p25;
    ts4_word loc60[70];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t19;
    ts4_word t20;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    int t13;
    ts4_word t31;

    fn_88236708((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880F20B0, (ts4_word)(a0 + 4));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 284);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 288);
    if ((ts4_word)t2 != (ts4_word)t3) {
        fn_88256870((ts4_word)a0, (ts4_word)a1);
        return;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 4)) + 0);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_88887BE0((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
    if ((ts4_word)t6 != (ts4_word)t7) {
        t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
        t20 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t7 - t6) / (int)268));
        lv22 = (ts4_word)t19;
        while ((ts4_word)lv22 < (ts4_word)t20) {
            fn_88256AE0((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv22) + 0)), (ts4_word)1);
            p25 = (ts4_word)(lv22 + 268);
            lv22 = p25;
        }
    } else {
        t8 = loc50[1];
        t9 = loc50[0];
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t8 - t9) / (int)268));
        t11 = loc50[0];
        lv12 = (ts4_word)t11;
        while ((ts4_word)lv12 != (ts4_word)t8) {
            t13 = *(volatile ts4_word *)((char *)(ts4_word)(lv12) + 0);
            if ((int)t13 == 2) {
                fn_88256AE0((ts4_word)a0, (ts4_word)a1, (ts4_word)(lv12 + 4), (ts4_word)0);
            }
            p16 = (ts4_word)(lv12 + 268);
            lv12 = p16;
        }
    }
    t31 = loc50[0];
    if ((ts4_word)t31 != 0) {
        ts4_destroy_owned_object((ts4_word)t31);
    }
    return;
}

/* Swing_DLL.xex 0x88237688: loop_call_seq lbl_880F20B0, fn_88236708, u32@0x11c, u32@0x120, u32@0x0, lbl_880F3260 */
void ts4_loop_call_seq_lbl_880F20B0_88237688(ts4_word a0, ts4_word a1)
{
    ts4_word lv12;
    ts4_word p16;
    ts4_word lv22;
    ts4_word p25;
    ts4_word loc60[70];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t19;
    ts4_word t20;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    int t13;
    ts4_word t31;

    fn_88236708((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880F20B0, (ts4_word)(a0 + 4));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 284);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 288);
    if ((ts4_word)t2 != (ts4_word)t3) {
        fn_88256CA8((ts4_word)a0, (ts4_word)a1);
        return;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 4)) + 0);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_88887BE0((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880F3260);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
    if ((ts4_word)t6 != (ts4_word)t7) {
        t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
        t20 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t7 - t6) / (int)268));
        lv22 = (ts4_word)t19;
        while ((ts4_word)lv22 < (ts4_word)t20) {
            fn_88256F18((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv22) + 0)), (ts4_word)1);
            p25 = (ts4_word)(lv22 + 268);
            lv22 = p25;
        }
    } else {
        t8 = loc50[1];
        t9 = loc50[0];
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t8 - t9) / (int)268));
        t11 = loc50[0];
        lv12 = (ts4_word)t11;
        while ((ts4_word)lv12 != (ts4_word)t8) {
            t13 = *(volatile ts4_word *)((char *)(ts4_word)(lv12) + 0);
            if ((int)t13 == 2) {
                fn_88256F18((ts4_word)a0, (ts4_word)a1, (ts4_word)(lv12 + 4), (ts4_word)0);
            }
            p16 = (ts4_word)(lv12 + 268);
            lv12 = p16;
        }
    }
    t31 = loc50[0];
    if ((ts4_word)t31 != 0) {
        ts4_destroy_owned_object((ts4_word)t31);
    }
    return;
}

/* Swing_DLL.xex 0x882377C0: loop_call_seq lbl_880F20B0, fn_88236708, u32@0x11c, u32@0x120, u32@0x0, lbl_880F3260 */
void ts4_loop_call_seq_lbl_880F20B0_882377C0(ts4_word a0, ts4_word a1)
{
    ts4_word lv12;
    ts4_word p16;
    ts4_word lv22;
    ts4_word p25;
    ts4_word loc60[70];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t19;
    ts4_word t20;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    int t13;
    ts4_word t31;

    fn_88236708((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880F20B0, (ts4_word)(a0 + 4));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 284);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 288);
    if ((ts4_word)t2 != (ts4_word)t3) {
        fn_882570E0((ts4_word)a0, (ts4_word)a1);
        return;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 4)) + 0);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_88887BE0((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880F3260);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
    if ((ts4_word)t6 != (ts4_word)t7) {
        t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
        t20 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t7 - t6) / (int)268));
        lv22 = (ts4_word)t19;
        while ((ts4_word)lv22 < (ts4_word)t20) {
            fn_88257350((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv22) + 0)), (ts4_word)1);
            p25 = (ts4_word)(lv22 + 268);
            lv22 = p25;
        }
    } else {
        t8 = loc50[1];
        t9 = loc50[0];
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t8 - t9) / (int)268));
        t11 = loc50[0];
        lv12 = (ts4_word)t11;
        while ((ts4_word)lv12 != (ts4_word)t8) {
            t13 = *(volatile ts4_word *)((char *)(ts4_word)(lv12) + 0);
            if ((int)t13 == 2) {
                fn_88257350((ts4_word)a0, (ts4_word)a1, (ts4_word)(lv12 + 4), (ts4_word)0);
            }
            p16 = (ts4_word)(lv12 + 268);
            lv12 = p16;
        }
    }
    t31 = loc50[0];
    if ((ts4_word)t31 != 0) {
        ts4_destroy_owned_object((ts4_word)t31);
    }
    return;
}

/* Swing_DLL.xex 0x88237B90: loop_call_seq lbl_880F20B0, fn_88236708, u32@0x11c, u32@0x120, u32@0x0, lbl_880F3278 */
void ts4_loop_call_seq_lbl_880F20B0_88237B90(ts4_word a0, ts4_word a1)
{
    ts4_word lv12;
    ts4_word p16;
    ts4_word lv22;
    ts4_word p25;
    ts4_word loc60[70];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t19;
    ts4_word t20;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    int t13;
    ts4_word t31;

    fn_88236708((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880F20B0, (ts4_word)(a0 + 4));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 284);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 288);
    if ((ts4_word)t2 != (ts4_word)t3) {
        fn_88257518((ts4_word)a0, (ts4_word)a1);
        return;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 4)) + 0);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_88887BE0((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880F3278);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
    if ((ts4_word)t6 != (ts4_word)t7) {
        t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
        t20 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t7 - t6) / (int)268));
        lv22 = (ts4_word)t19;
        while ((ts4_word)lv22 < (ts4_word)t20) {
            fn_88257788((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv22) + 0)), (ts4_word)1);
            p25 = (ts4_word)(lv22 + 268);
            lv22 = p25;
        }
    } else {
        t8 = loc50[1];
        t9 = loc50[0];
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t8 - t9) / (int)268));
        t11 = loc50[0];
        lv12 = (ts4_word)t11;
        while ((ts4_word)lv12 != (ts4_word)t8) {
            t13 = *(volatile ts4_word *)((char *)(ts4_word)(lv12) + 0);
            if ((int)t13 == 2) {
                fn_88257788((ts4_word)a0, (ts4_word)a1, (ts4_word)(lv12 + 4), (ts4_word)0);
            }
            p16 = (ts4_word)(lv12 + 268);
            lv12 = p16;
        }
    }
    t31 = loc50[0];
    if ((ts4_word)t31 != 0) {
        ts4_destroy_owned_object((ts4_word)t31);
    }
    return;
}

/* Swing_DLL.xex 0x88237F60: loop_call_seq lbl_880F20B0, fn_88236708, u32@0x11c, u32@0x120, u32@0x0, lbl_880F3270 */
void ts4_loop_call_seq_lbl_880F20B0_88237F60(ts4_word a0, ts4_word a1)
{
    ts4_word lv12;
    ts4_word p16;
    ts4_word lv22;
    ts4_word p25;
    ts4_word loc60[70];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t19;
    ts4_word t20;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    int t13;
    ts4_word t31;

    fn_88236708((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880F20B0, (ts4_word)(a0 + 4));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 284);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 288);
    if ((ts4_word)t2 != (ts4_word)t3) {
        fn_88257950((ts4_word)a0, (ts4_word)a1);
        return;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 4)) + 0);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_88887BE0((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880F3270);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
    if ((ts4_word)t6 != (ts4_word)t7) {
        t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
        t20 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t7 - t6) / (int)268));
        lv22 = (ts4_word)t19;
        while ((ts4_word)lv22 < (ts4_word)t20) {
            fn_88257BC0((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv22) + 0)), (ts4_word)1);
            p25 = (ts4_word)(lv22 + 268);
            lv22 = p25;
        }
    } else {
        t8 = loc50[1];
        t9 = loc50[0];
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t8 - t9) / (int)268));
        t11 = loc50[0];
        lv12 = (ts4_word)t11;
        while ((ts4_word)lv12 != (ts4_word)t8) {
            t13 = *(volatile ts4_word *)((char *)(ts4_word)(lv12) + 0);
            if ((int)t13 == 2) {
                fn_88257BC0((ts4_word)a0, (ts4_word)a1, (ts4_word)(lv12 + 4), (ts4_word)0);
            }
            p16 = (ts4_word)(lv12 + 268);
            lv12 = p16;
        }
    }
    t31 = loc50[0];
    if ((ts4_word)t31 != 0) {
        ts4_destroy_owned_object((ts4_word)t31);
    }
    return;
}

/* Swing_DLL.xex 0x88238A30: loop_call_seq lbl_880F20B0, fn_88236708, u32@0x11c, u32@0x120, u32@0x0, lbl_880F3268 */
void ts4_loop_call_seq_lbl_880F20B0_88238A30(ts4_word a0, ts4_word a1)
{
    ts4_word lv12;
    ts4_word p16;
    ts4_word lv22;
    ts4_word p25;
    ts4_word loc60[70];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t19;
    ts4_word t20;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    int t13;
    ts4_word t31;

    fn_88236708((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880F20B0, (ts4_word)(a0 + 4));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 284);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 288);
    if ((ts4_word)t2 != (ts4_word)t3) {
        fn_882580A0((ts4_word)a0, (ts4_word)a1);
        return;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 4)) + 0);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_88887BE0((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880F3268);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
    if ((ts4_word)t6 != (ts4_word)t7) {
        t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
        t20 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t7 - t6) / (int)268));
        lv22 = (ts4_word)t19;
        while ((ts4_word)lv22 < (ts4_word)t20) {
            fn_88258310((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv22) + 0)), (ts4_word)1);
            p25 = (ts4_word)(lv22 + 268);
            lv22 = p25;
        }
    } else {
        t8 = loc50[1];
        t9 = loc50[0];
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t8 - t9) / (int)268));
        t11 = loc50[0];
        lv12 = (ts4_word)t11;
        while ((ts4_word)lv12 != (ts4_word)t8) {
            t13 = *(volatile ts4_word *)((char *)(ts4_word)(lv12) + 0);
            if ((int)t13 == 2) {
                fn_88258310((ts4_word)a0, (ts4_word)a1, (ts4_word)(lv12 + 4), (ts4_word)0);
            }
            p16 = (ts4_word)(lv12 + 268);
            lv12 = p16;
        }
    }
    t31 = loc50[0];
    if ((ts4_word)t31 != 0) {
        ts4_destroy_owned_object((ts4_word)t31);
    }
    return;
}

/* Swing_DLL.xex 0x88238B68: loop_call_seq lbl_880F20B0, fn_88236708, u32@0x11c, u32@0x120, u32@0x0, lbl_880C1320 */
void ts4_loop_call_seq_lbl_880F20B0_88238B68(ts4_word a0, ts4_word a1)
{
    ts4_word lv12;
    ts4_word p16;
    ts4_word lv22;
    ts4_word p25;
    ts4_word loc60[70];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;
    ts4_word t19;
    ts4_word t20;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    int t13;
    ts4_word t31;

    fn_88236708((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880F20B0, (ts4_word)(a0 + 4));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 284);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 288);
    if ((ts4_word)t2 != (ts4_word)t3) {
        fn_882584D8((ts4_word)a0, (ts4_word)a1);
        return;
    }
    t4 = *(volatile ts4_word *)((char *)(ts4_word)((a0 + 4)) + 0);
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    fn_88887BE0((ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880C1320);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
    if ((ts4_word)t6 != (ts4_word)t7) {
        t19 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 316);
        t20 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 320);
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t7 - t6) / (int)268));
        lv22 = (ts4_word)t19;
        while ((ts4_word)lv22 < (ts4_word)t20) {
            fn_88258748((ts4_word)a0, (ts4_word)a1, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv22) + 0)), (ts4_word)1);
            p25 = (ts4_word)(lv22 + 268);
            lv22 = p25;
        }
    } else {
        t8 = loc50[1];
        t9 = loc50[0];
        fn_8822C1C8((ts4_word)(a0 + 300), (ts4_word)((int)(t8 - t9) / (int)268));
        t11 = loc50[0];
        lv12 = (ts4_word)t11;
        while ((ts4_word)lv12 != (ts4_word)t8) {
            t13 = *(volatile ts4_word *)((char *)(ts4_word)(lv12) + 0);
            if ((int)t13 == 2) {
                fn_88258748((ts4_word)a0, (ts4_word)a1, (ts4_word)(lv12 + 4), (ts4_word)0);
            }
            p16 = (ts4_word)(lv12 + 268);
            lv12 = p16;
        }
    }
    t31 = loc50[0];
    if ((ts4_word)t31 != 0) {
        ts4_destroy_owned_object((ts4_word)t31);
    }
    return;
}

/* Swing_DLL.xex 0x8825C6C0: loop_call_seq u32@0xc, ts4_loop_call_seq_u32_offc_8825C6C0, u32@lbl_88D45B38, u32@0x8, fn_885651F8, u32@0x0 */
void ts4_loop_call_seq_u32_offc_8825C6C0(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word p12;
    ts4_word t5;
    ts4_word t6;

    lv2 = (ts4_word)a1;
    while ((ts4_word)lv2 != 0) {
        ((void (*)())ts4_loop_call_seq_u32_offc_8825C6C0)((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 12)));
        t5 = *(ts4_word *)lbl_88D45B38;
        t6 = *(ts4_word *)((char *)(ts4_word)(lv2) + 8);
        if ((ts4_word)t5 != 0) {
            ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t5, (ts4_word)lv2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        } else {
            fn_885651F8((ts4_word)lv2);
        }
        p12 = (ts4_word)t6;
        lv2 = p12;
    }
    return;
}

/* Swing_DLL.xex 0x8825CD08: loop_call_seq u32@0x0, u32@0x4, fn_886F79F8, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
void ts4_loop_call_seq_u32_off0_8825CD08(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t10;
    ts4_word t12;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    lv4 = (ts4_word)t1;
    while ((ts4_word)lv4 != (ts4_word)t2) {
        fn_886F79F8((ts4_word)lv4);
        p7 = (ts4_word)(lv4 + 20);
        lv4 = p7;
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t10 != 0) {
        t12 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t12 != 0) {
            ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t12, (ts4_word)t10, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return;
        }
        fn_885651F8((ts4_word)t10, (ts4_word)t10);
        return;
    }
    return;
}

/* Swing_DLL.xex 0x8825D140: loop_call_seq u32@0xc, ts4_loop_call_seq_u32_offc_8825D140, u32@0x0, u32@0x8, u32@0x8, u32@0x0 */
void ts4_loop_call_seq_u32_offc_8825D140(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv2;
    ts4_word p11;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    lv2 = (ts4_word)a1;
    while ((ts4_word)lv2 != 0) {
        ((void (*)())ts4_loop_call_seq_u32_offc_8825D140)((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 12)));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t7 = *(ts4_word *)((char *)(ts4_word)(lv2) + 8);
        *(ts4_word *)((char *)(ts4_word)(t6) + -4) = (ts4_word)((int)(lv2 - (*(ts4_word *)((char *)(ts4_word)(t5) + 0))) / (int)20);
        *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + 4);
        p11 = (ts4_word)t7;
        lv2 = p11;
    }
    return;
}

/* Swing_DLL.xex 0x8825E5F8: loop_call_seq u32@0xc, ts4_loop_call_seq_u32_offc_8825E5F8, u32@0x8, fn_88721B58, u32@lbl_88D45B38, fn_885651F8 */
void ts4_loop_call_seq_u32_offc_8825E5F8(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word p13;
    ts4_word t5;
    ts4_word t7;

    lv2 = (ts4_word)a1;
    while ((ts4_word)lv2 != 0) {
        ((void (*)())ts4_loop_call_seq_u32_offc_8825E5F8)((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 12)));
        t5 = *(ts4_word *)((char *)(ts4_word)(lv2) + 8);
        fn_88721B58((ts4_word)(lv2 + 20));
        t7 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t7 != 0) {
            ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t7, (ts4_word)lv2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        } else {
            fn_885651F8((ts4_word)lv2);
        }
        p13 = (ts4_word)t5;
        lv2 = p13;
    }
    return;
}

/* Swing_DLL.xex 0x8825F798: call_seq fn_8825EE00, fn_8825EFC8, fn_8825F2D0, fn_8825F480, fn_8825F5E8, u8@0x70 */
ts4_word ts4_call_seq_fn_8825EE00_8825F798(ts4_word a0, ts4_word a1)
{
    __vector4 vv7;

    fn_8825EE00((ts4_word)a0, (ts4_word)a1);
    fn_8825EFC8((ts4_word)(a0 + 16), (ts4_word)(a1 + 16));
    fn_8825F2D0((ts4_word)(a0 + 32), (ts4_word)(a1 + 32));
    fn_8825F480((ts4_word)(a0 + 48), (ts4_word)(a1 + 48));
    fn_8825F5E8((ts4_word)(a0 + 64), (ts4_word)(a1 + 64));
    *(float *)((char *)(ts4_word)(a0) + 80) = (*(float *)((char *)(ts4_word)(a1) + 80));
    vv7 = *(__vector4 *)((ts4_word)(a1 + 96));
    *(__vector4 *)((ts4_word)(a0 + 96)) = vv7;
    *(unsigned char *)((char *)(ts4_word)(a0) + 112) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 112));
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 116));
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120));
    return a0;
}

/* Swing_DLL.xex 0x8825FF40: loop_call_seq u32@0x0, u32@0x4, fn_8825DA28, u32@0x0, u32@lbl_88D45B38, u32@lbl_88D45B38 */
void ts4_loop_call_seq_u32_off0_8825FF40(ts4_word a0)
{
    ts4_word lv4;
    ts4_word p7;
    ts4_word t1;
    ts4_word t2;
    ts4_word t10;
    ts4_word t12;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    lv4 = (ts4_word)t1;
    while ((ts4_word)lv4 != (ts4_word)t2) {
        fn_8825DA28((ts4_word)lv4);
        p7 = (ts4_word)(lv4 + 4);
        lv4 = p7;
    }
    t10 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t10 != 0) {
        t12 = *(volatile ts4_word *)lbl_88D45B38;
        if ((ts4_word)t12 != 0) {
            ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t12, (ts4_word)t10, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)));
            return;
        }
        fn_885651F8((ts4_word)t10, (ts4_word)t10);
        return;
    }
    return;
}

/* Swing_DLL.xex 0x882619C0: loop_call_seq u32@0xc, ts4_loop_call_seq_u32_offc_882619C0, u32@0x8, fn_88755B50, u32@lbl_88D45B38, fn_885651F8 */
void ts4_loop_call_seq_u32_offc_882619C0(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word p13;
    ts4_word t5;
    ts4_word t7;

    lv2 = (ts4_word)a1;
    while ((ts4_word)lv2 != 0) {
        ((void (*)())ts4_loop_call_seq_u32_offc_882619C0)((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 12)));
        t5 = *(ts4_word *)((char *)(ts4_word)(lv2) + 8);
        fn_88755B50((ts4_word)(lv2 + 24));
        t7 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t7 != 0) {
            ts4_if_call_seq_fn_881F04B8_886131F0((ts4_word)t7, (ts4_word)lv2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
        } else {
            fn_885651F8((ts4_word)lv2);
        }
        p13 = (ts4_word)t5;
        lv2 = p13;
    }
    return;
}

/* Swing_DLL.xex 0x88263000: if_call_seq u32@0x0, u32@0x4, fn_88265158, fn_882683B8, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off0_88263000(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    loc50[0] = (ts4_word)0;
    *(unsigned char *)((char *)loc50 + 8) = (unsigned char)0;
    *(float *)((char *)loc50 + 4) = (*(float *)lbl_8814B440);
    if ((ts4_word)a1 < (ts4_word)((int)(t2 - t1) / (int)12)) {
        t5 = fn_882683B8((ts4_word)t2, (ts4_word)t2, (ts4_word)(((a1 + (a1 << 1)) << 2) + t1), (ts4_word)(t2 - t1), (ts4_word)12);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t5;
        return t5;
    }
    t4 = fn_88265158((ts4_word)a0, (ts4_word)t2, (ts4_word)(a1 - ((int)(t2 - t1) / (int)12)), (ts4_word)(ts4_word)&loc50[0], (ts4_word)12);
    return t4;
}

/* Swing_DLL.xex 0x8826C6C0: loop_call_seq lbl_88D49310, u32@0xc, ts4_loop_call_seq_lbl_88D49310_8826C6C0, u32@0x8, fn_8815E358, u32@0x8 */
void ts4_loop_call_seq_lbl_88D49310_8826C6C0(ts4_word a0, ts4_word a1)
{
    ts4_word lv2;
    ts4_word p9;
    ts4_word t4;
    ts4_word t5;

    lv2 = (ts4_word)a1;
    while ((ts4_word)lv2 != 0) {
#ifdef _MSC_VER
        t4 = ((ts4_word (*)())ts4_loop_call_seq_lbl_88D49310_8826C6C0)((ts4_word)a0, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv2) + 12)));
#else
        ts4_loop_call_seq_lbl_88D49310_8826C6C0((ts4_word)a0, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv2) + 12))); t4 = 0;
#endif
        t5 = *(volatile ts4_word *)((char *)(ts4_word)(lv2) + 8);
        fn_8815E358((ts4_word)t4);
        *(volatile ts4_word *)((char *)(ts4_word)(lv2) + 0) = (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D49310) + 8));
        *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D49310) + 8) = (ts4_word)lv2;
        *(volatile ts4_word *)lbl_88D49350 = (ts4_word)0;
        p9 = (ts4_word)t5;
        lv2 = p9;
    }
    return;
}

/* Swing_DLL.xex 0x882B11F0: call_seq fn_882B10F8, fn_882CDCD8, u32@lbl_88B30FA4, u32@lbl_88B30FA8, fn_882B10F8 */
ts4_word ts4_call_seq_fn_882B10F8_882B11F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;

    *(ts4_word *)lbl_88B30FA4 = (ts4_word)(ts4_word)fn_882B10F8;
    *(ts4_word *)lbl_88B30FA8 = (ts4_word)(ts4_word)fn_882CDCD8;
    t1 = fn_882B10F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    return t1;
}

/* Swing_DLL.xex 0x882B1238: call_seq fn_882B10F8, fn_882CDCD8, u32@lbl_88B30FA4, u32@lbl_88B30FA8, fn_882CDCD8 */
ts4_word ts4_call_seq_fn_882B10F8_882B1238(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;

    *(ts4_word *)lbl_88B30FA4 = (ts4_word)(ts4_word)fn_882B10F8;
    *(ts4_word *)lbl_88B30FA8 = (ts4_word)(ts4_word)fn_882CDCD8;
    t1 = fn_882CDCD8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    return t1;
}

/* Swing_DLL.xex 0x882CDDB8: call_seq fn_882B10F8, fn_882CDCD8, u32@lbl_88B31770, u32@lbl_88B31774, fn_882B10F8 */
ts4_word ts4_call_seq_fn_882B10F8_882CDDB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;

    *(ts4_word *)lbl_88B31770 = (ts4_word)(ts4_word)fn_882B10F8;
    *(ts4_word *)lbl_88B31774 = (ts4_word)(ts4_word)fn_882CDCD8;
    t1 = fn_882B10F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    return t1;
}

/* Swing_DLL.xex 0x882CDE00: call_seq fn_882B10F8, fn_882CDCD8, u32@lbl_88B31770, u32@lbl_88B31774, fn_882CDCD8 */
ts4_word ts4_call_seq_fn_882B10F8_882CDE00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;

    *(ts4_word *)lbl_88B31770 = (ts4_word)(ts4_word)fn_882B10F8;
    *(ts4_word *)lbl_88B31774 = (ts4_word)(ts4_word)fn_882CDCD8;
    t1 = fn_882CDCD8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
    return t1;
}

/* Swing_DLL.xex 0x882DDF30: loop_call_seq u32@0x0, fn_88290718 */
ts4_word ts4_loop_call_seq_u32_off0_882DDF30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word c1;
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;
    ts4_word p7;
    ts4_word p9;
    float t2;
    float t4;

    p7 = (ts4_word)a7;
    p9 = (ts4_word)a6;
    if ((ts4_word)a4 != 0) {
        c1 = (ts4_word)a4;
        t2 = *(float *)lbl_88001A20;
        lv3 = (ts4_word)a3;
        do {
            t4 = *(float *)((char *)(ts4_word)((a2 - a3)) + lv3);
            p5 = (ts4_word)1;
            if (t4 == t2) {
                p5 = (ts4_word)0;
            }
            *(ts4_word *)((char *)(ts4_word)(lv3) + 0) = (ts4_word)p5;
            p6 = (ts4_word)(lv3 + 4);
            lv3 = p6;
        } while (--c1 != 0);
        p7 = (ts4_word)p5;
        p9 = (ts4_word)(a2 - a3);
    }
    fn_88290718((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a4, (ts4_word)a5, (ts4_word)p9, (ts4_word)p7);
    return 0;
}

/* Swing_DLL.xex 0x882DE250: loop_call_seq u32@0x0, fn_88290778 */
ts4_word ts4_loop_call_seq_u32_off0_882DE250(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word c1;
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;
    ts4_word p7;
    ts4_word p9;
    float t2;
    float t4;

    p7 = (ts4_word)a7;
    p9 = (ts4_word)a6;
    if ((ts4_word)a4 != 0) {
        c1 = (ts4_word)a4;
        t2 = *(float *)lbl_88001A20;
        lv3 = (ts4_word)a3;
        do {
            t4 = *(float *)((char *)(ts4_word)((a2 - a3)) + lv3);
            p5 = (ts4_word)1;
            if (t4 == t2) {
                p5 = (ts4_word)0;
            }
            *(ts4_word *)((char *)(ts4_word)(lv3) + 0) = (ts4_word)p5;
            p6 = (ts4_word)(lv3 + 4);
            lv3 = p6;
        } while (--c1 != 0);
        p7 = (ts4_word)p5;
        p9 = (ts4_word)(a2 - a3);
    }
    fn_88290778((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a4, (ts4_word)a4, (ts4_word)a5, (ts4_word)p9, (ts4_word)p7);
    return 0;
}

/* Swing_DLL.xex 0x88308FC8: if_call_seq fn_88309DB8, ts4_if_get_8830B508 */
ts4_word ts4_if_call_seq_fn_88309DB8_88308FC8(ts4_word a0, float f1, float f2, float f3)
{
    ts4_word p4;
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88309DB8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_if_get_8830B508((ts4_word)t2, f1, f2, f3);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x8830C130: if_call_seq fn_8832EBE0 */
ts4_word ts4_if_call_seq_fn_8832EBE0_8830C130(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word loc54[1];
    ts4_word loc50[1];
    float t1;
    int t2;

    if ((ts4_word)a2 != 0 && (ts4_word)a1 != 0) {
        t1 = *(float *)lbl_88001A20;
        *(float *)((char *)loc50 + 0) = t1;
        *(float *)((char *)loc54 + 0) = t1;
        t2 = fn_8832EBE0((ts4_word)(a0 + 24572), (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc54[0]);
        p5 = (ts4_word)t2;
        if ((int)t2 == 0) {
            if ((ts4_word)a3 != 0) {
                *(float *)((char *)(ts4_word)(a3) + 0) = (*(float *)((char *)loc50 + 0));
            }
            if ((ts4_word)a4 != 0) {
                *(float *)((char *)(ts4_word)(a4) + 0) = (*(float *)((char *)loc54 + 0));
            }
            p5 = (ts4_word)0;
        }
        p6 = (ts4_word)p5;
    } else {
        p6 = (ts4_word)37;
    }
    return p6;
}

/* Swing_DLL.xex 0x883175A8: if_call_seq fn_88322CA8, ts4_set_range_88325050 */
ts4_word ts4_if_call_seq_fn_88322CA8_883175A8(ts4_word a0, float f1, float f2, float f3)
{
    ts4_word p4;
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = fn_88322CA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_set_range_88325050((ts4_word)t2, f1, f2, f3);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x88317CB0: if_call_seq ts4_if_set_u32_off0_8832F930, fn_8832FEB0 */
void ts4_if_call_seq_ts4_if_set_u32_off0_8832F930_88317CB0(ts4_word a0, float f1, float f2, float f3, float f4, float f5, float f6, float f7, float f8)
{
    ts4_word loc60[2];
    int t1;
    ts4_word t2;

    t1 = ts4_if_set_u32_off0_8832F930((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    if ((int)t1 == 0) {
        t2 = loc60[0];
        fn_8832FEB0((ts4_word)t2, f1, f2, f3, f4, f5, f6, f7, f8);
    }
    return;
}

/* Swing_DLL.xex 0x88318298: if_call_seq ts4_if_set_u32_off0_8832BFC0, ts4_if_get_u32_off0_8832C280 */
ts4_word ts4_if_call_seq_ts4_if_set_u32_off0_8832BFC0_88318298(ts4_word a0, ts4_word a1, float f1, float f2)
{
    ts4_word p4;
    ts4_word loc50[4];
    int t1;
    ts4_word t2;
    ts4_word t3;

    t1 = ts4_if_set_u32_off0_8832BFC0((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p4 = (ts4_word)t1;
    if ((int)t1 == 0) {
        t2 = loc50[0];
        t3 = ts4_if_get_u32_off0_8832C280((ts4_word)t2, (ts4_word)a1, f1, f2);
        p4 = (ts4_word)t3;
    }
    return p4;
}

/* Swing_DLL.xex 0x8831A780: if_call_seq fn_8857BBB0, u32@0x0, ts4_tailcall_fn_88582660_8857B840 */
ts4_word ts4_if_call_seq_fn_8857BBB0_8831A780(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p4;
    ts4_word loc50[2];
    int t1;
    ts4_word t2;

    t1 = fn_8857BBB0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    if ((int)t1 == 0) {
        ts4_tailcall_fn_88582660_8857B840((ts4_word)t1);
        p4 = (ts4_word)19;
    } else {
        t2 = loc50[0];
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t2;
        p4 = (ts4_word)(((a2 - t2) != 0) ? 22 : 0);
    }
    return p4;
}

/* Swing_DLL.xex 0x8831C9A8: loop_get u32@0x48, u16@0x54, u32@0x14, u32@0x55fc, u32@0x4c, u16@0x54 */
ts4_word ts4_loop_get_u32_off48_8831C9A8(ts4_word a0, int a1)
{
    ts4_word p13;
    ts4_word lv27;
    ts4_word p33;
    int t1;
    ts4_word t41;
    ts4_word t42;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    int t11;
    int t12;
    ts4_word t14;
    ts4_word t17;
    ts4_word t20;
    unsigned short t28;
    ts4_word t36;
    unsigned short t38;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    if ((int)t1 <= 1 || (int)a1 >= (int)((short)(*(unsigned short *)((char *)(ts4_word)(a0) + 84)))) {
        if ((int)a1 >= 128) {
            t41 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
            t42 = *(ts4_word *)((char *)(ts4_word)(t41) + 22012);
            if ((ts4_word)t42 != 0) {
                ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))(t42))((ts4_word)t41, (ts4_word)5, (ts4_word)a0, (ts4_word)0);
            }
            return 14;
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
        *(unsigned short *)((char *)(ts4_word)(a0) + 84) = (unsigned short)a1;
        if ((ts4_word)t5 == 0 || (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 272)) != (ts4_word)((t5 + 15) & 0xfffffff0)) {
            t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
            t8 = *(ts4_word *)((char *)(ts4_word)(((a1 + 307) << 2)) + t7);
            if ((ts4_word)t8 == 0) {
                t11 = *(ts4_word *)((char *)(ts4_word)(t7) + 1200);
                t12 = *(ts4_word *)((char *)(ts4_word)(t7) + 1196);
                p13 = (ts4_word)t11;
                if ((int)t11 < (int)t12) {
                    p13 = (ts4_word)t12;
                }
                t14 = *(ts4_word *)((char *)(ts4_word)(t7) + 1212);
                t17 = ts4_tailcall_fn_88315C60_88316068((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)((((int)t14 * (int)p13) + 4) << 2), (ts4_word)(ts4_word)lbl_88028ED4, (ts4_word)2345, (ts4_word)(2097152), (ts4_word)t14);
                *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + ((a1 + 307) << 2)) = (ts4_word)t17;
                t20 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + ((a1 + 307) << 2));
                if ((ts4_word)t20 == 0) {
                    return 44;
                }
            }
        }
        lv27 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44));
        while ((ts4_word)lv27 != (ts4_word)(a0 + 44)) {
            t28 = *(unsigned short *)((char *)(ts4_word)(a0) + 84);
            ((ts4_word (*)())ts4_loop_get_u32_off48_8831C9A8)((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv27) + 8))) + 136)), (ts4_word)(((short)t28) + 1));
            p33 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv27) + 0));
            lv27 = p33;
        }
        t36 = *(ts4_word *)((char *)(ts4_word)(a0) + 76);
        if ((ts4_word)t36 == 0 || (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 272)) != (ts4_word)((t36 + 15) & 0xfffffff0)) {
            t38 = *(unsigned short *)((char *)(ts4_word)(a0) + 84);
            *(ts4_word *)((char *)(ts4_word)(a0) + 272) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(((((short)t38) + 307) << 2)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 20)))) + 15) & 0xfffffff0);
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x8831D2F8: if_call_seq u32@0xa4, u32@0xa8, fn_88329680, u32@0xa8, u32@0x2c, u32@0xa8 */
ts4_word ts4_if_call_seq_u32_offa4_8831D2F8(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, int a5, ts4_word a6, ts4_word a7)
{
    ts4_word t8;

    if ((int)a1 >= 0 && (int)a1 < (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 164))) {
        if ((ts4_word)a2 != 0) {
            fn_88329680((ts4_word)a2, (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 168)) + ((a1 + (a1 << 1)) << 4)) + 12));
        }
        if ((ts4_word)a4 != 0 && (int)a5 != 0) {
            t8 = *(ts4_word *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 168)) + ((a1 + (a1 << 1)) << 4))) + 44);
            if ((ts4_word)t8 != 0) {
                fn_883296A0((ts4_word)a4, (ts4_word)t8, (ts4_word)a5);
            } else {
                *(volatile unsigned char *)((char *)(ts4_word)(a4) + 0) = (unsigned char)0;
            }
        }
        if ((ts4_word)a3 != 0) {
            fn_88329680((ts4_word)a3, (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 168)) + ((a1 + (a1 << 1)) << 4)) + 28));
        }
        if ((ts4_word)a6 != 0) {
            *(volatile float *)((char *)(ts4_word)(a6) + 0) = (*(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 168))) + ((a1 + (a1 << 1)) << 4)));
        }
        if ((ts4_word)a7 != 0) {
            *(volatile float *)((char *)(ts4_word)(a7) + 0) = (*(float *)((char *)(ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 168)) + ((a1 + (a1 << 1)) << 4))) + 4));
        }
        return 0;
    }
    return 37;
}

/* Swing_DLL.xex 0x8831E730: if_call_seq u32@0x11c, fn_8831DBB0, ts4_if_call_seq_u32_off14_8831D098, ts4_if_call_seq_u32_off14_8831D110, u32@0x11c, u32@0x11c */
ts4_word ts4_if_call_seq_u32_off11c_8831E730(ts4_word a0, ts4_word a1)
{
    ts4_word p19;
    ts4_word p20;
    ts4_word p21;
    ts4_word p22;
    ts4_word p26;
    ts4_word p27;
    ts4_word p28;
    ts4_word p29;
    ts4_word p30;
    ts4_word loc54[1];
    ts4_word loc50[1];
    ts4_word t1;
    int t3;
    int t4;
    int t6;
    int t23;
    ts4_word t25;
    int t12;
    int t13;
    int t14;
    ts4_word t15;
    ts4_word t16;
    int t17;
    ts4_word t10;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 284);
    if ((ts4_word)(t1 & 0x20) != 0) {
        t3 = ts4_if_call_seq_u32_off14_8831D098((ts4_word)a0, (ts4_word)(ts4_word)&loc54[0], (ts4_word)a1);
        p29 = (ts4_word)t3;
        if ((int)t3 == 0) {
            t4 = ts4_if_call_seq_u32_off14_8831D110((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
            p28 = (ts4_word)t4;
            if ((int)t4 == 0) {
                t6 = loc54[0];
                if ((int)t6 == 0) {
                    t23 = loc50[0];
                    if ((int)t23 == 0) {
                        p26 = (ts4_word)t4;
                    } else {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 284)) & 0xffffffdf);
                        t25 = fn_8831DBB0((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)a1);
                        p26 = (ts4_word)t25;
                    }
                    p27 = (ts4_word)p26;
                } else {
                    if ((int)t6 == 1 && (int)(loc50[0]) == 1) {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 284)) & 0xfffffffd);
                        t12 = fn_8831D8A0((ts4_word)a0, (ts4_word)0, (ts4_word)(ts4_word)&loc54[0], (ts4_word)0, (ts4_word)a1);
                        p21 = (ts4_word)t12;
                        if ((int)t12 == 0) {
                            t13 = fn_8831D9B0((ts4_word)a0, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)a1);
                            p20 = (ts4_word)t13;
                            if ((int)t13 == 0) {
                                t14 = fn_8831DBB0((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)a1);
                                p19 = (ts4_word)t14;
                                if ((int)t14 == 0) {
                                    t15 = loc54[0];
                                    t16 = loc50[0];
                                    t17 = fn_8831E228((ts4_word)t16, (ts4_word)t15, (ts4_word)0, (ts4_word)0, (ts4_word)0, (ts4_word)a1);
                                    if ((int)t17 == 0) {
                                        *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 284)) & 0xffffffdf);
                                    }
                                    p19 = (ts4_word)t17;
                                }
                                p20 = (ts4_word)p19;
                            }
                            p21 = (ts4_word)p20;
                        }
                        p22 = (ts4_word)p21;
                    } else {
                        *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 284)) & 0xffffffdf);
                        t10 = fn_8831DBB0((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)a1);
                        p22 = (ts4_word)t10;
                    }
                    p27 = (ts4_word)p22;
                }
                p28 = (ts4_word)p27;
            }
            p29 = (ts4_word)p28;
        }
        p30 = (ts4_word)p29;
    } else {
        t2 = fn_8831DBB0((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)a1);
        p30 = (ts4_word)t2;
    }
    return p30;
}

/* Swing_DLL.xex 0x8831FE90: if_call_seq u32@0x188, ts4_strlen_88329658, fn_883766B0, fn_88329680, ts4_if_call_seq_fn_883296A0_88319EA8, u32@0x188 */
ts4_word ts4_if_call_seq_u32_off188_8831FE90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p9;
    ts4_word loc50[512];
    ts4_word t1;
    int t3;
    int t2;
    int t6;
    ts4_word t8;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 392);
    if ((ts4_word)(t1 & 0x4) != 0) {
        t3 = fn_883766B0((ts4_word)a1);
        if ((int)t3 == 0) {
            return 23;
        }
    } else {
        t2 = ts4_strlen_88329658((ts4_word)a1);
        if ((int)t2 == 0) {
            return 23;
        }
    }
    fn_88329680((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1);
    t6 = ts4_if_call_seq_fn_883296A0_88319EA8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    p9 = (ts4_word)t6;
    if ((int)t6 == 0) {
        t8 = fn_8831A650((ts4_word)a1, (ts4_word)(ts4_word)lbl_880D2F14, (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 392)) >> 2) & 0x1), (ts4_word)a2, (ts4_word)(a0 + 448));
        p9 = (ts4_word)t8;
    }
    return p9;
}

/* Swing_DLL.xex 0x883213E0: loop_call_seq fn_8832EDB0, u32@0x1cc, u32@0x160, u32@0x0, fn_8832EDB0, u32@0x0 */
ts4_word ts4_loop_call_seq_fn_8832EDB0_883213E0(ts4_word a0, ts4_word a1)
{
    ts4_word lv3;
    ts4_word lv5;
    ts4_word lv7;
    ts4_word p10;
    ts4_word p13;
    ts4_word p16;

    fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)8, (ts4_word)716);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 460));
    do {
        if ((ts4_word)lv3 == (ts4_word)(((a0 + 412) != 0) ? (a0 + 460) : 0)) {
            lv5 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 352));
            do {
                if ((ts4_word)lv5 == (ts4_word)(((a0 + 260) != 0) ? (a0 + 352) : 0)) {
                    lv7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 + 588)) + 0));
                    do {
                        if ((ts4_word)lv7 == (ts4_word)(((a0 + 536) != 0) ? (a0 + 588) : 0)) {
                            return 0;
                        }
                        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)8, (ts4_word)172);
                        p10 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv7) + 0));
                        lv7 = p10;
                    } while (1);
                }
                fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)8, (ts4_word)152);
                p13 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 0));
                lv5 = p13;
            } while (1);
        }
        fn_8832EDB0((ts4_word)a1, (ts4_word)0, (ts4_word)8, (ts4_word)124);
        p16 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv3) + 0));
        lv3 = p16;
    } while (1);
}

/* Swing_DLL.xex 0x88329048: if_call_seq lbl_880291C4, u32@lbl_88B3302C, u32@0x4, ts4_tailcall_fn_88315C60_88316068, u32@0x14, u32@0x4 */
ts4_word ts4_if_call_seq_lbl_880291C4_88329048(ts4_word a0, ts4_word a1, ts4_word a2, int a3)
{
    ts4_word t3;

    if ((int)a3 < 0) {
        return 37;
    }
    if ((int)a3 != 0) {
        t3 = ts4_tailcall_fn_88315C60_88316068((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)(a3 << 2), (ts4_word)(ts4_word)lbl_880291C4, (ts4_word)64, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t3;
        if ((ts4_word)t3 == 0) {
            return 44;
        }
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a2;
    return 0;
}

/* Swing_DLL.xex 0x88331A68: if_call_seq u32@0x20, lbl_88029328, u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x14 */
ts4_word ts4_if_call_seq_u32_off20_88331A68(ts4_word a0, ts4_word a1)
{
    ts4_word p4;
    ts4_word t3;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)16384;
    t3 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)16384, (ts4_word)(ts4_word)lbl_88029328, (ts4_word)462, (ts4_word)0, (ts4_word)0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t3;
    if ((ts4_word)t3 == 0) {
        p4 = (ts4_word)44;
    } else {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t3;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t3;
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a1;
        p4 = (ts4_word)0;
    }
    return p4;
}

/* Swing_DLL.xex 0x88332678: loop_call_seq u32@0x24, ts4_if_call_seq_RtlEnterCriticalSection_8831AD58, ts4_call_seq_fn_8857B830_8831A8B8, u32@0x2c, u32@0x4, u32@0xc */
ts4_word ts4_loop_call_seq_u32_off24_88332678(ts4_word a0, ts4_word a1)
{
    ts4_word lv8;
    ts4_word p15;
    ts4_word loc50[4];
    ts4_word t1;
    int t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    int t10;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    ts4_if_call_seq_RtlEnterCriticalSection_8831AD58((ts4_word)t1);
    t3 = ts4_call_seq_fn_8857B830_8831A8B8((ts4_word)(ts4_word)&loc50[0]);
    if ((int)t3 != 0) {
        ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)t1);
        return t3;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    t5 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(t5 - t4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t6 != (ts4_word)(a0 + 12)) {
        lv8 = (ts4_word)t6;
        do {
            t9 = fn_88331BE0((ts4_word)lv8, (ts4_word)a1);
            if ((ts4_word)(t9 & 0xff) != 0) {
                t10 = fn_883320F8((ts4_word)lv8, (ts4_word)a1);
                if ((int)t10 != 0) {
                    ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)t1);
                    return t10;
                }
            }
            p15 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv8) + 0));
            lv8 = p15;
        } while ((ts4_word)p15 != (ts4_word)(a0 + 12));
        ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)t1);
        return 0;
    }
    ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98((ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x8833CCA0: call_seq lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0 */
ts4_word ts4_call_seq_lbl_8802974C_8833CCA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    switch ((ts4_word)(a1)) {
        case 0:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 332));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 332))));
        return 0;
        case 1:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 316));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 316))));
        return 0;
        case 2:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 324));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 324))));
        return 0;
        case 3:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 340));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 340))));
        return 0;
        default:
        return 0;
    }
}

/* Swing_DLL.xex 0x8833D550: if_call_seq lbl_88029A3C, fn_885635D0, lbl_88029A3C, fn_885635D0, lbl_8802974C, fn_885635D0 */
ts4_word ts4_if_call_seq_lbl_88029A3C_8833D550(int a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    float pf18;
    ts4_word p20;
    float t2;
    float t5;
    float t6;
    unsigned char t15;
    unsigned char t19;

    switch ((ts4_word)(a1)) {
        case 0:
        t2 = *(float *)lbl_88028DFC;
        *(volatile float *)((char *)(ts4_word)(a2) + 0) = ((*(float *)((char *)(ts4_word)(a0) + 312)) * t2);
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_88029A3C, (double)(((*(float *)((char *)(ts4_word)(a0) + 312)) * t2)));
        return 0;
        case 1:
        t6 = *(float *)lbl_88028DFC;
        t5 = *(float *)((char *)(ts4_word)(a0) + 316);
        *(float *)((char *)(ts4_word)(a2) + 0) = (t5 * t6);
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_88029A3C, (double)(((*(float *)((char *)(ts4_word)(a0) + 316)) * t6)));
        return 0;
        case 2:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 320));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 320))));
        return 0;
        case 3:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 324));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 324))));
        return 0;
        case 4:
        t15 = *(unsigned char *)((char *)(ts4_word)(a0) + 328);
        if ((ts4_word)t15 != 0) {
            pf18 = (*(float *)lbl_88001A68);
        } else {
            pf18 = (*(float *)lbl_88001A20);
        }
        *(float *)(0 + (char *)(ts4_word)(a2)) = pf18;
        t19 = *(unsigned char *)((char *)(ts4_word)(a0) + 328);
        if ((ts4_word)t19 != 0) {
            p20 = (ts4_word)(ts4_word)lbl_880D5928;
        } else {
            p20 = (ts4_word)(ts4_word)lbl_880D592C;
        }
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_880D1B40, (ts4_word)p20);
        return 0;
        default:
        return 0;
    }
}

/* Swing_DLL.xex 0x8833E8D8: call_seq lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0 */
ts4_word ts4_call_seq_lbl_8802974C_8833E8D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    switch ((ts4_word)(a1)) {
        case 0:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 316));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 316))));
        return 0;
        case 1:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 320));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 320))));
        return 0;
        case 2:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 324));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 324))));
        return 0;
        case 3:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 328));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 328))));
        return 0;
        case 4:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 336));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 336))));
        return 0;
        case 5:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 340));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 340))));
        return 0;
        case 6:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 312));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 312))));
        return 0;
        case 7:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 332));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 332))));
        return 0;
        default:
        return 0;
    }
}

/* Swing_DLL.xex 0x883434E8: if_call_seq lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0 */
ts4_word ts4_if_call_seq_lbl_8802974C_883434E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 != 1) {
            if ((ts4_word)a1 < 3) {
                *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 332));
                fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 332))));
                return 0;
            }
            return 0;
        }
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 328));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 328))));
        return 0;
    }
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 324));
    fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 324))));
    return 0;
}

/* Swing_DLL.xex 0x88343C80: if_call_seq lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0 */
ts4_word ts4_if_call_seq_lbl_8802974C_88343C80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 != 1) {
            if ((ts4_word)a1 < 3) {
                *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 316));
                fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 316))));
                return 0;
            }
            return 0;
        }
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 312));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 312))));
        return 0;
    }
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 320));
    fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 320))));
    return 0;
}

/* Swing_DLL.xex 0x88344418: if_get  */
float ts4_if_get_88344418(ts4_word a0, int a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    float t10;
    float t11;
    float t1;
    float t2;
    float t21;
    float t22;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)(a2 & 0xff) != 0) {
        if ((int)a1 != 16) {
            t10 = *(float *)((char *)(ts4_word)(a0) + 440);
            t11 = *(float *)((char *)(ts4_word)(((a1 + 181) << 2)) + a0);
            *(volatile float *)((char *)(ts4_word)(a3) + 0) = ((t11 - (*(float *)((char *)(ts4_word)(((a1 + 180) << 2)) + a0))) * t10);
        } else {
            *(volatile float *)((char *)(ts4_word)(a3) + 0) = (*(float *)lbl_88001A20);
        }
    } else {
        if ((int)a1 == 0) {
            *(volatile float *)((char *)(ts4_word)(a3) + 0) = (*(float *)lbl_88001A20);
        } else {
            t1 = *(float *)((char *)(ts4_word)(a0) + 444);
            t2 = *(float *)((char *)(ts4_word)(((a1 + 179) << 2)) + a0);
            *(volatile float *)((char *)(ts4_word)(a3) + 0) = ((t2 - (*(float *)((char *)(ts4_word)(((a1 + 180) << 2)) + a0))) * t1);
        }
    }
    t21 = *(float *)((char *)(ts4_word)(a0) + 320);
    t22 = *(float *)((char *)(ts4_word)(a0) + 452);
    return (((*(float *)((char *)(ts4_word)(((a1 + 180) << 2)) + a0)) * t21) + t22);
}

/* Swing_DLL.xex 0x88345298: call_seq lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0 */
ts4_word ts4_call_seq_lbl_8802974C_88345298(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    switch ((ts4_word)(a1)) {
        case 0:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 316));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 316))));
        return 0;
        case 1:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 324));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 324))));
        return 0;
        case 2:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 332));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 332))));
        return 0;
        case 3:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 340));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 340))));
        return 0;
        case 4:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 348));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 348))));
        return 0;
        case 5:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 356));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 356))));
        return 0;
        case 6:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 364));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 364))));
        return 0;
        case 7:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 376));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 376))));
        return 0;
        default:
        return 0;
    }
}

/* Swing_DLL.xex 0x88345F68: call_seq lbl_88029A3C, fn_885635D0, lbl_88029A3C, fn_885635D0, lbl_8802974C, fn_885635D0 */
ts4_word ts4_call_seq_lbl_88029A3C_88345F68(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    float t2;
    float t6;

    switch ((ts4_word)(a1)) {
        case 0:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 324));
        t2 = *(float *)((char *)(ts4_word)(a0) + 320);
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_88029A3C, (double)((t2 * (*(float *)lbl_88028DFC))));
        return 0;
        case 1:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 332));
        t6 = *(float *)lbl_88028DFC;
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_88029A3C, (double)(((*(float *)((char *)(ts4_word)(a0) + 328)) * t6)));
        return 0;
        case 2:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 316));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 312))));
        return 0;
        case 3:
        *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 340));
        fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 336))));
        return 0;
        default:
        return 0;
    }
}

/* Swing_DLL.xex 0x88349C80: if_call_seq lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0 */
ts4_word ts4_if_call_seq_lbl_8802974C_88349C80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 == 1) {
            *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 328));
            fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 328))));
            return 0;
        }
        return 0;
    }
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 316));
    fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 316))));
    return 0;
}

/* Swing_DLL.xex 0x8834B188: if_call_seq lbl_8802974C, fn_885635D0, lbl_8802974C, fn_885635D0 */
ts4_word ts4_if_call_seq_lbl_8802974C_8834B188(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 == 1) {
            *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 316));
            fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 316))));
            return 0;
        }
        return 0;
    }
    *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 324));
    fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 324))));
    return 0;
}

/* Swing_DLL.xex 0x8834D3D8: if_call_seq u32@0x138, u32@0x138, lbl_8802AEC4, fn_88329680, lbl_8802AEBC, fn_88329680 */
ts4_word ts4_if_call_seq_u32_off138_8834D3D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    if ((ts4_word)a1 >= 1) {
        if ((ts4_word)a1 == 1) {
            *(float *)((char *)(ts4_word)(a2) + 0) = (*(float *)((char *)(ts4_word)(a0) + 316));
            fn_885635D0((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802974C, (double)((*(float *)((char *)(ts4_word)(a0) + 316))));
            return 0;
        }
        return 0;
    }
    *(float *)((char *)(ts4_word)(a2) + 0) = ((float)((double)((ts4_s64)(int)(*(ts4_word *)((char *)(ts4_word)(a0) + 312)))));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 312);
    switch ((ts4_word)(t2)) {
        case 0:
        fn_88329680((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802AEC4);
        break;
        case 1:
        fn_88329680((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802AEBC);
        break;
        case 2:
        fn_88329680((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802AEB4);
        break;
        case 3:
        fn_88329680((ts4_word)a3, (ts4_word)(ts4_word)lbl_8802AEA8);
        break;
        case 4:
        fn_88329680((ts4_word)a3, (ts4_word)(ts4_word)lbl_88024CDC);
        break;
        case 5:
        fn_88329680((ts4_word)a3, (ts4_word)(ts4_word)lbl_8800FC50);
        break;
    }
    return 0;
}

/* Swing_DLL.xex 0x88361808: if_addr lbl_88B3A5B0, u32@0x0, u32@0x0, u32@-0x4, u32@0x0 */
ts4_word ts4_if_addr_lbl_88B3A5B0_88361808(ts4_word a0, int a1, int a2, ts4_word a3)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)((a1 << 2)) + (ts4_word)lbl_88B3A5B0);
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t1;
    if ((int)a2 < 0 && (int)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(((int)((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(((a1 << 2) + (ts4_word)lbl_88B3A5B0)) + -4))) * (int)a2) / 128) + t1);
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(((int)((int)((*(ts4_word *)((char *)(ts4_word)((a1 << 2)) + ((ts4_word)lbl_88B3A5B0 + 4))) - t1) * (int)a2) / 128) + t1);
    return 0;
}

/* Swing_DLL.xex 0x8836B3D8: call_seq u32@0x0, u32@0x108, fn_883194F0, u32@0x0 */
ts4_word ts4_call_seq_u32_off0_8836B3D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t4;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    fn_883194F0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 264)), (ts4_word)a1, (ts4_word)1, (ts4_word)t1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc50[0];
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t4;
    return ((t4 == 0) ? 2 : 0);
}

/* Swing_DLL.xex 0x8836CD70: if_get u32@0x500, u32@-0x10, u32@0x500, lbl_8802B898, u32@lbl_88B3302C, u32@0x4 */
ts4_word ts4_if_get_u32_off500_8836CD70(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a7;
    p4 = (ts4_word)a6;
    if ((ts4_word)a1 != 0 && (ts4_word)a0 != 0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1280);
        t2 = *(ts4_word *)((char *)(ts4_word)(a1) + -16);
        *(ts4_word *)((char *)(ts4_word)(a0) + 1280) = (ts4_word)(t1 - t2);
        p4 = (ts4_word)(t1 - t2);
    }
    return fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)a1, (ts4_word)(ts4_word)lbl_8802B898, (ts4_word)81, (ts4_word)a4, (ts4_word)a5, (ts4_word)p4);
}

/* Swing_DLL.xex 0x88376FC0: if_get u32@0x108, u32@0x108, u32@0x0, u32@0x108, ts4_if_get_u32_off188_88319E00, u32@0x0 */
ts4_word ts4_if_get_u32_off108_88376FC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t2;
    int t4;
    ts4_word t5;
    ts4_word t10;
    ts4_word t12;
    ts4_word t13;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a2 == 8) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 264);
        if ((ts4_word)t2 == 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        }
        t4 = ts4_if_get_u32_off188_88319E00((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 264)), (ts4_word)a1);
        if ((int)t4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
            return t4;
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(t5 - (*(ts4_word *)((char *)(ts4_word)(a0) + 196)));
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 108);
    if ((ts4_word)t10 == 0) {
        return 82;
    }
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((ts4_word)(t12 & a2) == 0) {
        return 25;
    }
    t13 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t10))((ts4_word)(a0 + 28), (ts4_word)a1, (ts4_word)a2);
    return t13;
}

/* Swing_DLL.xex 0x883777F0: if_call_seq u32@0x104, lbl_8802BB9C, u32@lbl_88B3302C, u32@0x4, fn_88315C60, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off104_883777F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word p5;
    ts4_word p6;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 260);
    p6 = (ts4_word)t1;
    if ((ts4_word)t1 == 0) {
        t4 = fn_88315C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)44, (ts4_word)(ts4_word)lbl_8802BB9C, (ts4_word)452, (ts4_word)0, (ts4_word)0);
        if ((ts4_word)t4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)t4;
            *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t4;
            *(ts4_word *)((char *)(ts4_word)(t4) + 8) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t4) + 16) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t4) + 20) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t4) + 28) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t4) + 24) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(t4) + 32) = (ts4_word)0;
            *(unsigned char *)((char *)(ts4_word)(t4) + 36) = (unsigned char)1;
            *(unsigned char *)((char *)(ts4_word)(t4) + 37) = (unsigned char)0;
            *(ts4_word *)((char *)(ts4_word)(t4) + 40) = (ts4_word)0;
            p5 = (ts4_word)t4;
        } else {
            p5 = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)p5;
        if ((ts4_word)p5 == 0) {
            return 44;
        }
        p6 = (ts4_word)p5;
    }
    t7 = fn_88376D10((ts4_word)p6, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
    return t7;
}

/* Swing_DLL.xex 0x8838C6E8: call_seq fn_883B0D50, fn_883B1460, fn_883B0D50, fn_883B0D50, fn_883B0D50, fn_883B03F0 */
ts4_word ts4_call_seq_fn_883B0D50_8838C6E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;

    (void)a0;
    (void)a1;
    (void)a2;
    fn_883B0D50((ts4_word)a3, (ts4_word)((a3 + 65536) + -15112), (ts4_word)((a3 + 65536) + -11016), (ts4_word)256);
    fn_883B1460((ts4_word)(a3 + 10256), (ts4_word)((a3 + 65536) + -15112), (ts4_word)((a3 + 65536) + -11016), (ts4_word)256);
    fn_883B0D50((ts4_word)(a3 + 19488), (ts4_word)((a3 + 65536) + -15112), (ts4_word)((a3 + 65536) + -11016), (ts4_word)256);
    fn_883B0D50((ts4_word)(a3 + 29744), (ts4_word)((a3 + 65536) + -15112), (ts4_word)((a3 + 65536) + -11016), (ts4_word)256);
    t5 = fn_883B0D50((ts4_word)((a3 + 65536) + -25536), (ts4_word)((a3 + 65536) + -15112), (ts4_word)((a3 + 65536) + -11016), (ts4_word)256);
    t7 = fn_883B03F0((ts4_word)t5, (ts4_word)256, (ts4_word)((a3 + 65536) + -15280), (*(float *)lbl_8802CEA8));
    t9 = fn_883B03F0((ts4_word)t7, (ts4_word)256, (ts4_word)((a3 + 65536) + -15268), (*(float *)lbl_8802CEA4));
    t11 = fn_883B03F0((ts4_word)t9, (ts4_word)256, (ts4_word)((a3 + 65536) + -15256), (*(float *)lbl_8802CEA0));
    fn_883B03F0((ts4_word)t11, (ts4_word)256, (ts4_word)((a3 + 65536) + -15244), (*(float *)lbl_8802CE9C));
    fn_883AFF60((ts4_word)((a3 + 65536) + -15232));
    ts4_init_descriptor_defaults_883AFBC0((ts4_word)((a3 + 65536) + -15112), (ts4_word)((a3 + 65536) + -15188));
    ts4_init_descriptor_defaults_883AFBC0((ts4_word)((a3 + 65536) + -15112), (ts4_word)((a3 + 65536) + -15152));
    return 0;
}

/* Swing_DLL.xex 0x8838CF18: call_seq fn_883B0D50, fn_883B1460, fn_883B0D50, fn_883B0D50, fn_883B03F0, fn_883B03F0 */
ts4_word ts4_call_seq_fn_883B0D50_8838CF18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t4;
    ts4_word t6;
    ts4_word t8;
    ts4_word t10;

    (void)a0;
    (void)a1;
    (void)a2;
    fn_883B0D50((ts4_word)a3, (ts4_word)((a3 + 65536) + -25368), (ts4_word)((a3 + 65536) + -21272), (ts4_word)256);
    fn_883B1460((ts4_word)(a3 + 10256), (ts4_word)((a3 + 65536) + -25368), (ts4_word)((a3 + 65536) + -21272), (ts4_word)256);
    fn_883B0D50((ts4_word)(a3 + 19488), (ts4_word)((a3 + 65536) + -25368), (ts4_word)((a3 + 65536) + -21272), (ts4_word)256);
    t4 = fn_883B0D50((ts4_word)(a3 + 29744), (ts4_word)((a3 + 65536) + -25368), (ts4_word)((a3 + 65536) + -21272), (ts4_word)256);
    t6 = fn_883B03F0((ts4_word)t4, (ts4_word)256, (ts4_word)((a3 + 65536) + -25536), (*(float *)lbl_8802CEA8));
    t8 = fn_883B03F0((ts4_word)t6, (ts4_word)256, (ts4_word)((a3 + 65536) + -25524), (*(float *)lbl_8802CEA4));
    t10 = fn_883B03F0((ts4_word)t8, (ts4_word)256, (ts4_word)((a3 + 65536) + -25512), (*(float *)lbl_8802CEA0));
    fn_883B03F0((ts4_word)t10, (ts4_word)256, (ts4_word)((a3 + 65536) + -25500), (*(float *)lbl_8802CE9C));
    fn_883AFF60((ts4_word)((a3 + 65536) + -25488));
    ts4_init_descriptor_defaults_883AFBC0((ts4_word)((a3 + 65536) + -25368), (ts4_word)((a3 + 65536) + -25444));
    ts4_init_descriptor_defaults_883AFBC0((ts4_word)((a3 + 65536) + -25368), (ts4_word)((a3 + 65536) + -25408));
    return 0;
}

/* Swing_DLL.xex 0x8838D518: if_call_seq fn_883B0D50, fn_883B0D50, fn_883B0D50, fn_883B03F0, fn_883B03F0, ts4_init_table256_883B1B08 */
ts4_word ts4_if_call_seq_fn_883B0D50_8838D518(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t3;
    ts4_word t5;
    int t8;
    int t9;
    int t10;
    int t11;

    (void)a0;
    (void)a1;
    (void)a2;
    fn_883B0D50((ts4_word)a3, (ts4_word)((a3 + 65536) + -18236), (ts4_word)((a3 + 65536) + -14140), (ts4_word)256);
    fn_883B0D50((ts4_word)(a3 + 10256), (ts4_word)((a3 + 65536) + -18236), (ts4_word)((a3 + 65536) + -14140), (ts4_word)256);
    t3 = fn_883B0D50((ts4_word)(a3 + 20512), (ts4_word)((a3 + 65536) + -18236), (ts4_word)((a3 + 65536) + -14140), (ts4_word)256);
    t5 = fn_883B03F0((ts4_word)t3, (ts4_word)256, (ts4_word)(a3 + 30768), (*(float *)lbl_8802CE9C));
    fn_883B03F0((ts4_word)t5, (ts4_word)256, (ts4_word)(a3 + 30780), (*(float *)lbl_8802CEA0));
    t8 = ts4_init_table256_883B1B08((ts4_word)256, (ts4_word)(a3 + 30792));
    if ((int)t8 < 0) {
        return -101;
    }
    t9 = ts4_init_table256_883B1B08((ts4_word)256, (ts4_word)(a3 + 31828));
    if ((int)t9 < 0) {
        return -101;
    }
    t10 = ts4_init_table256_883B1B08((ts4_word)256, (ts4_word)((a3 + 65536) + -32672));
    if ((int)t10 < 0) {
        return -101;
    }
    t11 = ts4_init_table256_883B1B08((ts4_word)256, (ts4_word)((a3 + 65536) + -31636));
    if ((int)t11 < 0) {
        return -101;
    }
    ts4_init_descriptor_defaults_883AFBC0((ts4_word)((a3 + 65536) + -18236), (ts4_word)((a3 + 65536) + -30600));
    ts4_init_descriptor_defaults_883AFBC0((ts4_word)((a3 + 65536) + -18236), (ts4_word)((a3 + 65536) + -30564));
    return 0;
}

/* Swing_DLL.xex 0x883BEDA8: if_get u32@0x0 */
ts4_word ts4_if_get_u32_off0_883BEDA8(float f1, float f2, float f3, float f4, ts4_word a4, ts4_word a5, float f5, float f6, float f7, float f8, float f9)
{
    float t1;
    float t2;

    (void)f5;
    (void)f6;
    (void)f7;
    (void)f8;
    (void)f9;
    if ((ts4_word)a4 == 0) {
        return -102;
    }
    t1 = *(float *)lbl_88001A20;
    if (!((f4 - f3) > t1)) {
        return -105;
    }
    t2 = *(float *)lbl_88028BDC;
    if (f1 > t1) {
        *(volatile float *)((char *)(ts4_word)(a5) + 24) = ((f4 - f3) / ((((float)((double)((ts4_s64)(ts4_word)a4))) * f1) * t2));
    } else {
        *(volatile float *)((char *)(ts4_word)(a5) + 24) = (f4 - f3);
    }
    *(volatile float *)((char *)(ts4_word)(a5) + 4) = f1;
    if (f2 > t1) {
        *(volatile float *)((char *)(ts4_word)(a5) + 28) = (-((f4 - f3) / ((((float)((double)((ts4_s64)(ts4_word)a4))) * f2) * t2)));
    } else {
        *(volatile float *)((char *)(ts4_word)(a5) + 28) = (-(f4 - f3));
    }
    *(volatile float *)((char *)(ts4_word)(a5) + 8) = f2;
    *(volatile ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)a4;
    *(volatile float *)((char *)(ts4_word)(a5) + 12) = f3;
    *(volatile float *)((char *)(ts4_word)(a5) + 16) = f4;
    *(volatile float *)((char *)(ts4_word)(a5) + 20) = t1;
    return 0;
}

/* Swing_DLL.xex 0x883E6250: if_call_seq u32@0x4, u32@0x0, lbl_88039750, u32@lbl_88B3302C, u32@0x4, fn_88315F10 */
ts4_word ts4_if_call_seq_u32_off4_883E6250(ts4_word a0)
{
    ts4_word p10;
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    p10 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
        fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88B3302C)) + 4)), (ts4_word)t2, (ts4_word)(ts4_word)lbl_88039750, (ts4_word)1369);
        t6 = *(ts4_word *)lbl_88B3302C;
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t9 = fn_88315F10((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t6) + 4)), (ts4_word)t7, (ts4_word)(ts4_word)lbl_88039750, (ts4_word)1370);
        p10 = (ts4_word)t9;
    }
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)0;
    *(ts4_u64 *)((char *)(ts4_word)(a0) + 0) = (ts4_u64)*(ts4_u64 *)((char *)loc50 + 0);
    return p10;
}

/* Swing_DLL.xex 0x88403980: addr fn_8841CBF8, lbl_8803A7C4, ts4_if_get_u32_off8_8841D058, lbl_8803A768, u32@lbl_88CAD340, u32@0x0 */
ts4_word ts4_addr_fn_8841CBF8_88403980(void)
{
    ts4_word loc60[130];
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t7;

    fn_8841CBF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)512);
    ts4_if_get_u32_off8_8841D058((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8803A7C4);
    t3 = *(ts4_word *)lbl_88CAD340;
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 12))))((ts4_word)t3, (ts4_word)3, (ts4_word)((1424162816) | 8483), (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_8803A768, (ts4_word)27);
    t7 = ts4_ref_holder_dtor_8841D638((ts4_word)(ts4_word)&loc50[0]);
    return t7;
}

/* Swing_DLL.xex 0x884039F8: addr fn_8841CBF8, lbl_8803A804, ts4_if_get_u32_off8_8841D058, lbl_8803A768, u32@lbl_88CAD340, u32@0x0 */
ts4_word ts4_addr_fn_8841CBF8_884039F8(void)
{
    ts4_word loc60[130];
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t7;

    fn_8841CBF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)512);
    ts4_if_get_u32_off8_8841D058((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8803A804);
    t3 = *(ts4_word *)lbl_88CAD340;
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 12))))((ts4_word)t3, (ts4_word)3, (ts4_word)((1424162816) | 8484), (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_8803A768, (ts4_word)39);
    t7 = ts4_ref_holder_dtor_8841D638((ts4_word)(ts4_word)&loc50[0]);
    return t7;
}

/* Swing_DLL.xex 0x8840D408: if_get u32@0x10, u32@0x30, u32@0x14, u32@0x28 */
ts4_word ts4_if_get_u32_off10_8840D408(ts4_word a0)
{
    int t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t1 != 0) {
        return ((int)(*(ts4_word *)((char *)(ts4_word)(a0) + 40)) / (int)t1);
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return ((int)t2 / (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Swing_DLL.xex 0x88412A48: call_seq fn_884123E0, u32@0x0, u32@0x0 */
ts4_word ts4_call_seq_fn_884123E0_88412A48(ts4_word a0, float f1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    t2 = fn_884123E0((ts4_word)a5, (ts4_word)a2, (*(float *)((char *)(ts4_word)(a0) + 60)), f1, (ts4_word)a3, (ts4_word)a4);
    *(ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a5) + 0)) + 3) & 0xfffffffc);
    return t2;
}

/* Swing_DLL.xex 0x88419EE0: get u32@0x0, u32@0x8, u32@-0xc */
ts4_word ts4_get_u32_off0_88419EE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    t2 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t2))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(a3 + -16), (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a3) + -12)) + 16), (ts4_word)0);
}

/* Swing_DLL.xex 0x8841B100: get u32@0x18, u32@0x10, u32@0x20, u32@0x1c */
ts4_word ts4_get_u32_off18_8841B100(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t2;
    return ((int)t1 < (int)a1);
}

/* Swing_DLL.xex 0x8841C4E0: if_call_seq u32@0x0, u32@0x8, fn_8841C428, u8@0x10, u32@lbl_88CACF08, KeTlsGetValue */
ts4_word ts4_if_call_seq_u32_off0_8841C4E0(ts4_word a0, int a1)
{
    ts4_word p12;
    int t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t10;
    ts4_word t11;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    p12 = (ts4_word)a0;
    if ((int)a1 != (int)(t2 - t1)) {
        if ((int)a1 > 0) {
            if ((int)t1 != 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 16)) != 0) {
                t6 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
                ts4_if_get_u32_0xc_8841A820((ts4_word)t6, (ts4_word)t1);
            }
            *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)1;
            t10 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
            t11 = ts4_call_seq_fn_8841A510_8841A7C8((ts4_word)t10, (ts4_word)a1, (ts4_word)27);
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t11;
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t11;
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t11 + a1);
            *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)((t11 + a1) + -32);
            return t11;
        }
        t3 = fn_8841C428((ts4_word)a0);
        p12 = (ts4_word)t3;
    }
    return p12;
}

/* Swing_DLL.xex 0x8841EB08: loop_get u32@0x4, u32@0x4, u32@0x4, u8@0x0, u32@0x4, u8@0x0 */
void ts4_loop_get_u32_off4_8841EB08(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv1;
    ts4_word p6;

    lv1 = (ts4_word)a2;
    while ((ts4_word)lv1 != 0) {
        if ((ts4_word)lv1 == (ts4_word)a1) {
            *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
            return;
        }
        p6 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv1) + 4));
        lv1 = p6;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x88420918: loop_get u8@0x0, u8@0x0 */
void ts4_loop_get_u8_off0_88420918(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word lv1;
    ts4_word lv2;
    ts4_word p7;
    ts4_word p8;
    ts4_word locm10[1];
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    lv1 = (ts4_word)a1;
    lv2 = (ts4_word)0;
    do {
        if ((int)lv2 != 3 && (int)lv2 != 11) {
            *(float *)((char *)locm10 + 0) = (*(float *)((char *)(ts4_word)(lv1) + 0));
            t4 = locm10[0];
            if ((ts4_word)(t4 & 0x7f800000) == (ts4_word)(2139095040)) {
                *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
                return;
            }
        }
        p7 = (ts4_word)(lv1 + 4);
        p8 = (ts4_word)(lv2 + 1);
        lv1 = p7;
        lv2 = p8;
    } while ((int)p8 < 12);
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88421370: call_seq ts4_tailcall_fn_88567A38_88567B98 */
float ts4_call_seq_ts4_tailcall_fn_88567A38_88567B98_88421370(ts4_word a0)
{
    double t1;

    t1 = ts4_tailcall_fn_88567A38_88567B98((ts4_word)a0, (ts4_word)0);
    return ((float)t1);
}

/* Swing_DLL.xex 0x88429AB0: call_seq lbl_8803B570, lbl_8803F500, fn_884C5468, lbl_8803B558, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890 */
ts4_word ts4_call_seq_lbl_8803B570_88429AB0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    fn_884C5468((ts4_word)a0, (ts4_word)(ts4_word)lbl_8803F500, (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803B570);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803B558);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803B558);
    t4 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t5 = *(ts4_word *)((char *)(ts4_word)(t4) + 0);
    t6 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t6) + 0) = (unsigned short)t5;
    return t6;
}

/* Swing_DLL.xex 0x884316F8: if_call_seq lbl_88041554, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289B8, ts4_get_u32_off0_884289A8, u8@0x0 */
ts4_word ts4_if_call_seq_lbl_88041554_884316F8(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t3;
    float t4;
    float t5;
    ts4_word t7;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041554);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041554);
    t3 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = *(float *)((char *)(ts4_word)(t3) + 0);
    t5 = *(float *)lbl_88001A20;
    p6 = (ts4_word)1;
    if (t4 == t5) {
        p6 = (ts4_word)0;
    }
    t7 = ts4_get_u32_off0_884289A8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(unsigned char *)((char *)(ts4_word)(t7) + 0) = (unsigned char)p6;
    return t7;
}

/* Swing_DLL.xex 0x88431808: call_seq lbl_8803CB5C, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_index_u16_array_at_field0_884289F8, ts4_index_u16_array_at_field0_884289F8, u16@0x0 */
ts4_word ts4_call_seq_lbl_8803CB5C_88431808(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803CB5C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803CB5C);
    t3 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t4) + 0) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(t3) + 0));
    return t4;
}

/* Swing_DLL.xex 0x88431910: call_seq lbl_88041928, ts4_if_call_seq_u32_off4_88428890, u32@0x4, fn_8841ED98, ts4_get_u32_off4_88426130, ts4_get_u32_off0_88428980 */
ts4_word ts4_call_seq_lbl_88041928_88431910(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[2];
    ts4_word loc50[2];
    ts4_word loc68[2];
    ts4_word loc60[2];
    ts4_word loc78[2];
    ts4_word loc70[2];
    ts4_word loc88[2];
    ts4_word loc80[2];
    ts4_word loc98[2];
    ts4_word loc90[2];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    ts4_word t9;
    ts4_word t13;
    ts4_word t14;
    ts4_word t18;
    ts4_word t19;
    ts4_word t23;
    ts4_word t24;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041928);
    t3 = fn_8841ED98((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)), (ts4_word)(ts4_word)lbl_88041928);
    t4 = ts4_get_u32_off4_88426130((ts4_word)t3);
    loc50[1] = (ts4_word)t4;
    t5 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc58[0]);
    loc50[0] = (ts4_word)t5;
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8804191C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8804191C);
    t8 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
    t9 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc68[0], (ts4_word)0);
    *(float *)((char *)(ts4_word)(t9) + 0) = (*(float *)((char *)(ts4_word)(t8) + 0));
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8804190C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc70[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8804190C);
    t13 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc70[0], (ts4_word)0);
    t14 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc78[0], (ts4_word)0);
    *(float *)((char *)(ts4_word)(t14) + 0) = (*(float *)((char *)(ts4_word)(t13) + 0));
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880418F8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc80[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880418F8);
    t18 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc80[0], (ts4_word)0);
    t19 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc88[0], (ts4_word)0);
    *(float *)((char *)(ts4_word)(t19) + 0) = (*(float *)((char *)(ts4_word)(t18) + 0));
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc98[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880418E8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc90[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_880418E8);
    t23 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc90[0], (ts4_word)0);
    t24 = ts4_get_u32_off0_884289B8((ts4_word)(ts4_word)&loc98[0], (ts4_word)0);
    *(float *)((char *)(ts4_word)(t24) + 0) = (*(float *)((char *)(ts4_word)(t23) + 0));
    return t24;
}

/* Swing_DLL.xex 0x88431B88: call_seq lbl_88041AA4, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, fn_88431B10 */
ts4_word ts4_call_seq_lbl_88041AA4_88431B88(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t3;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041AA4);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AA4);
    t3 = fn_88431B10((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Swing_DLL.xex 0x88431BF0: call_seq lbl_88041AE8, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, fn_88431B10, lbl_88041AC8, ts4_if_call_seq_u32_off4_88428890 */
ts4_word ts4_call_seq_lbl_88041AE8_88431BF0(ts4_word a0, ts4_word a1)
{
    ts4_word loc58[2];
    ts4_word loc50[2];
    ts4_word loc60[2];
    ts4_word loc68[3];
    ts4_word t6;
    ts4_word t7;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041AE8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AE8);
    fn_88431B10((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc60[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AC8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AB0);
    t6 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc60[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t6) + 0) = (ts4_word)-1;
    t7 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc68[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)-1;
    return t7;
}

/* Swing_DLL.xex 0x88434218: addr fn_8841CBF8, lbl_88043148, ts4_if_get_u32_off8_8841D058, lbl_88043124, u32@lbl_88CAD340, u32@0x0 */
ts4_word ts4_addr_fn_8841CBF8_88434218(void)
{
    ts4_word loc60[130];
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t7;

    fn_8841CBF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)512);
    ts4_if_get_u32_off8_8841D058((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_88043148);
    t3 = *(ts4_word *)lbl_88CAD340;
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 12))))((ts4_word)t3, (ts4_word)3, (ts4_word)((1354825728) | 47946), (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_88043124, (ts4_word)57);
    t7 = ts4_ref_holder_dtor_8841D638((ts4_word)(ts4_word)&loc50[0]);
    return t7;
}

/* Swing_DLL.xex 0x88434910: call_seq lbl_88043E74, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289C8, u32@0x0, ts4_index_u16_array_at_field0_884289F8 */
ts4_word ts4_call_seq_lbl_88043E74_88434910(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88043E74);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88043E74);
    t3 = ts4_get_u32_off0_884289C8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    t5 = ts4_index_u16_array_at_field0_884289F8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t5) + 0) = (unsigned short)t4;
    return t5;
}

/* Swing_DLL.xex 0x88434C90: call_seq lbl_8803CB5C, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_index_u16_array_at_field0_88428A08, ts4_index_u16_array_at_field0_88428A08, u16@0x0 */
ts4_word ts4_call_seq_lbl_8803CB5C_88434C90(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803CB5C);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803CB5C);
    t3 = ts4_index_u16_array_at_field0_88428A08((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_index_u16_array_at_field0_88428A08((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(unsigned short *)((char *)(ts4_word)(t4) + 0) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(t3) + 0));
    return t4;
}

/* Swing_DLL.xex 0x88434E40: call_seq lbl_8803D1C8, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_884289D8, ts4_get_u32_off0_884289E8, u32@0x0 */
ts4_word ts4_call_seq_lbl_8803D1C8_88434E40(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803D1C8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803D1C8);
    t3 = ts4_get_u32_off0_884289D8((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_get_u32_off0_884289E8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    return t4;
}

/* Swing_DLL.xex 0x884350B0: get ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_call_seq_u32_off4_88428B48, u32@0x4, ts4_call_seq_u32_off4_88428B48, u32@0x0 */
ts4_word ts4_get_ts4_if_call_seq_u32_off4_88428890_884350B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc70[2];
    ts4_word loc78[3];
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word t3;
    ts4_word t5;
    ts4_word t7;
    ts4_word t9;
    ts4_word t11;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a3);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)a3);
    t3 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc50[0]);
    loc60[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 4));
    t5 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc50[0]);
    loc60[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 0));
    t7 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc58[0]);
    loc68[1] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t7) + 4));
    t9 = ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc58[0]);
    loc68[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 0));
    t11 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(a4))((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc68[0], (ts4_word)a2);
    return t11;
}

/* Swing_DLL.xex 0x88435198: call_seq lbl_8803D1C8, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428988, ts4_get_u32_off0_884289E8, u32@0x0 */
ts4_word ts4_call_seq_lbl_8803D1C8_88435198(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_8803D1C8);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_8803D1C8);
    t3 = ts4_get_u32_off0_88428988((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_get_u32_off0_884289E8((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 0));
    return t4;
}

/* Swing_DLL.xex 0x88435268: call_seq lbl_88048150, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428A18, ts4_get_u32_off0_88428A18, u8@0x0 */
ts4_word ts4_call_seq_lbl_88048150_88435268(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88048150);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88048150);
    t3 = ts4_get_u32_off0_88428A18((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_get_u32_off0_88428A18((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(unsigned char *)((char *)(ts4_word)(t4) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(t3) + 0));
    return t4;
}

/* Swing_DLL.xex 0x884355C0: addr fn_8841CBF8, lbl_8804818C, ts4_if_get_u32_off8_8841D058, lbl_8804816C, u32@lbl_88CAD340, u32@0x0 */
ts4_word ts4_addr_fn_8841CBF8_884355C0(void)
{
    ts4_word loc60[130];
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t7;

    fn_8841CBF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)512);
    ts4_if_get_u32_off8_8841D058((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8804818C);
    t3 = *(ts4_word *)lbl_88CAD340;
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 12))))((ts4_word)t3, (ts4_word)3, (ts4_word)((701890560) | 41973), (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_8804816C, (ts4_word)256);
    t7 = ts4_ref_holder_dtor_8841D638((ts4_word)(ts4_word)&loc50[0]);
    return t7;
}

/* Swing_DLL.xex 0x884358C8: call_seq lbl_88048608, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428A18, ts4_get_u32_off0_88428A18, u8@0x0 */
ts4_word ts4_call_seq_lbl_88048608_884358C8(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t3;
    ts4_word t4;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88048608);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88048608);
    t3 = ts4_get_u32_off0_88428A18((ts4_word)(ts4_word)&loc50[0], (ts4_word)0);
    t4 = ts4_get_u32_off0_88428A18((ts4_word)(ts4_word)&loc58[0], (ts4_word)0);
    *(unsigned char *)((char *)(ts4_word)(t4) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(t3) + 0));
    return t4;
}

/* Swing_DLL.xex 0x884363F8: addr fn_8841CBF8, lbl_8804818C, ts4_if_get_u32_off8_8841D058, lbl_8804914C, u32@lbl_88CAD340, u32@0x0 */
ts4_word ts4_addr_fn_8841CBF8_884363F8(void)
{
    ts4_word loc60[130];
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t7;

    fn_8841CBF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)512);
    ts4_if_get_u32_off8_8841D058((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8804818C);
    t3 = *(ts4_word *)lbl_88CAD340;
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 12))))((ts4_word)t3, (ts4_word)3, (ts4_word)((765067264) | 28478), (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_8804914C, (ts4_word)192);
    t7 = ts4_ref_holder_dtor_8841D638((ts4_word)(ts4_word)&loc50[0]);
    return t7;
}

/* Swing_DLL.xex 0x88436500: call_seq lbl_88041928, ts4_if_call_seq_u32_off4_88428890, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off4_88428AC0, ts4_get_u32_off4_88426130, ts4_get_u32_off0_88428980 */
ts4_word ts4_call_seq_lbl_88041928_88436500(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc68[3];
    ts4_word loc60[2];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)lbl_88041928);
    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041928);
    t3 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc50[0]);
    t4 = ts4_get_u32_off4_88426130((ts4_word)t3);
    loc68[1] = (ts4_word)t4;
    t5 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc50[0]);
    loc68[0] = (ts4_word)t5;
    t6 = ts4_get_u32_off4_88428AC0((ts4_word)(ts4_word)&loc58[0]);
    t7 = ts4_get_u32_off4_88426130((ts4_word)t6);
    loc60[1] = (ts4_word)t7;
    t8 = ts4_get_u32_off0_88428980((ts4_word)(ts4_word)&loc58[0]);
    loc60[0] = (ts4_word)t8;
    t9 = ts4_call_seq_lbl_88049700_88436488((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc60[0]);
    return t9;
}

/* Swing_DLL.xex 0x8843A3C8: if_get u32@lbl_88CAD338, KeTlsGetValue, u32@0xc, u32@0x4, lbl_880818D4, u32@0x0 */
ts4_word ts4_if_get_u32_lbl_88CAD338_8843A3C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_u64 t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    ts4_u64 t15;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 < (ts4_word)t3) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_880818D4;
        t5 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t4 + 12);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t7 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    loc50[3] = (ts4_word)a2;
    loc50[1] = (ts4_word)0;
    loc50[0] = (ts4_word)t6;
    loc50[2] = (ts4_word)t7;
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 16))))((ts4_word)t6, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    t12 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t13 = *(ts4_word *)((char *)(ts4_word)(t12) + 12);
    t14 = *(ts4_word *)((char *)(ts4_word)(t12) + 4);
    if ((ts4_word)t14 < (ts4_word)t13) {
        *(ts4_word *)((char *)(ts4_word)(t14) + 0) = (ts4_word)(ts4_word)lbl_8803BC50;
        t15 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t14) + 4) = (ts4_word)t15;
        *(ts4_word *)((char *)(ts4_word)(t12) + 4) = (ts4_word)(t14 + 12);
    }
    return t12;
}

/* Swing_DLL.xex 0x8843BF30: loop_get u32@lbl_88CAD338, KeTlsGetValue, u32@0xc, u32@0x4, lbl_88081980, u32@0x0 */
ts4_word ts4_loop_get_u32_lbl_88CAD338_8843BF30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv9;
    ts4_word p20;
    ts4_word loc60[130];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_u64 t5;
    int t8;
    ts4_word t12;
    ts4_word t13;
    int t19;
    ts4_word t24;
    ts4_word t25;
    ts4_word t26;
    ts4_u64 t27;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 < (ts4_word)t3) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_88081980;
        t5 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t4 + 12);
    }
    t8 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + 8))))((ts4_word)(a0 + 20));
    lv9 = (ts4_word)t8;
    while ((int)lv9 != -1) {
        t12 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 20)) + 0))) + 20))))((ts4_word)(a0 + 20), (ts4_word)lv9, (ts4_word)(ts4_word)&loc60[0]);
        t13 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
        loc50[3] = (ts4_word)a2;
        loc50[0] = (ts4_word)t12;
        loc50[1] = (ts4_word)lv9;
        loc50[2] = (ts4_word)t13;
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t12) + 0))) + 16))))((ts4_word)t12, (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
        t19 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 20)) + 0))) + 12))))((ts4_word)(a0 + 20), (ts4_word)lv9);
        p20 = (ts4_word)t19;
        lv9 = p20;
    }
    t24 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t25 = *(ts4_word *)((char *)(ts4_word)(t24) + 12);
    t26 = *(ts4_word *)((char *)(ts4_word)(t24) + 4);
    if ((ts4_word)t26 < (ts4_word)t25) {
        *(ts4_word *)((char *)(ts4_word)(t26) + 0) = (ts4_word)(ts4_word)lbl_8803BC50;
        t27 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t26) + 4) = (ts4_word)t27;
        *(ts4_word *)((char *)(ts4_word)(t24) + 4) = (ts4_word)(t26 + 12);
    }
    return t24;
}

/* Swing_DLL.xex 0x88440838: if_get u32@0x0, lbl_88081BA0, u32@0x4, vcall, u32@0x50, u32@0x0 */
ts4_word ts4_if_get_u32_off0_88440838(ts4_word a0, ts4_word a1)
{
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t17;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88081BA0, (ts4_word)1, (ts4_word)a0);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if ((ts4_word)t4 != (ts4_word)(a0 + 112)) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t5) + 8))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88081B8C, (ts4_word)1, (ts4_word)t4, (ts4_word)(t6 << 6), (ts4_word)(t6 << 6), (ts4_word)t6);
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 92);
    t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t10) + 8))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88081B7C, (ts4_word)1, (ts4_word)t12, (ts4_word)(t11 << 6), (ts4_word)(t11 << 6), (ts4_word)t11);
    t17 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t17;
}

/* Swing_DLL.xex 0x88444DB8: if_call_seq u32@lbl_88CAD338, KeTlsGetValue, u32@0xc, u32@0x4, lbl_88081D34, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88CAD338_88444DB8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word p8;
    ts4_word loc60[28];
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_u64 t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    ts4_u64 t15;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 < (ts4_word)t3) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_88081D34;
        t5 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t4 + 12);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t7 = *(ts4_word *)((char *)(ts4_word)(a2) + 8);
    loc60[16] = (ts4_word)0;
    loc60[17] = (ts4_word)0;
    loc50[3] = (ts4_word)a2;
    loc50[0] = (ts4_word)t6;
    loc50[2] = (ts4_word)t7;
    loc50[1] = (ts4_word)0;
    p8 = (ts4_word)0;
    if ((ts4_word)t6 != 0) {
        p8 = (ts4_word)(t6 + 16);
    }
    fn_885283E8((ts4_word)(ts4_word)&loc60[0], (ts4_word)p8, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)), (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a3);
    t12 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t13 = *(ts4_word *)((char *)(ts4_word)(t12) + 12);
    t14 = *(ts4_word *)((char *)(ts4_word)(t12) + 4);
    if ((ts4_word)t14 < (ts4_word)t13) {
        *(ts4_word *)((char *)(ts4_word)(t14) + 0) = (ts4_word)(ts4_word)lbl_8803BC50;
        t15 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t14) + 4) = (ts4_word)t15;
        *(ts4_word *)((char *)(ts4_word)(t12) + 4) = (ts4_word)(t14 + 12);
    }
    return t12;
}

/* Swing_DLL.xex 0x884469F8: call_seq fn_8843C308, lbl_88080DB0, lbl_88080D8C, u32@0x0, u32@0x10, u32@0x18 */
ts4_word ts4_call_seq_fn_8843C308_884469F8(ts4_word a0, float f1)
{
    fn_8843C308((ts4_word)a0, (ts4_word)22);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080DB0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_88080D8C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(2147483648);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(2147483648);
    *(volatile float *)((char *)(ts4_word)(a0) + 60) = f1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 64) = (unsigned char)6;
    return a0;
}

/* Swing_DLL.xex 0x88453B08: if_call_seq lbl_88082400, u32@0x0, u32@0x14, u32@lbl_88CACF08, KeTlsGetValue, u32@0xc */
ts4_word ts4_if_call_seq_lbl_88082400_88453B08(ts4_word a0)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t3;
    ts4_word t5;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88082400;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    p6 = (ts4_word)a0;
    if ((int)(t1 & 0x80000000) == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
        t5 = fn_8841A590((ts4_word)t3, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)((t1 & 0x3fffffff) << 1), (ts4_word)23);
        p6 = (ts4_word)t5;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return p6;
}

/* Swing_DLL.xex 0x88454958: if_call_seq u32@lbl_88CAD338, KeTlsGetValue, u32@0xc, u32@0x4, lbl_8808262C, lbl_8808260C */
ts4_word ts4_if_call_seq_u32_lbl_88CAD338_88454958(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc50[14];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_u64 t5;
    float t6;
    unsigned char t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_u64 t13;
    ts4_word t16;
    ts4_word t17;
    ts4_word t18;
    ts4_word t19;
    ts4_u64 t20;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 < (ts4_word)t3) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_8808262C;
        *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)(ts4_word)lbl_8808260C;
        t5 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t4 + 16);
    }
    *(unsigned char *)((char *)loc50 + 8) = (unsigned char)0;
    t6 = *(float *)lbl_8803A3B0;
    loc50[0] = (ts4_word)(ts4_word)lbl_88082588;
    *(float *)((char *)loc50 + 44) = t6;
    *(float *)((char *)loc50 + 4) = t6;
    fn_88467F60((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_88082588, (ts4_word)0);
    t8 = *(unsigned char *)((char *)loc50 + 8);
    if ((ts4_word)t8 != 0) {
        t10 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
        t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 12);
        t12 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
        if ((ts4_word)t12 < (ts4_word)t11) {
            *(ts4_word *)((char *)(ts4_word)(t12) + 0) = (ts4_word)(ts4_word)lbl_88082624;
            t13 = __mftb();
            *(ts4_word *)((char *)(ts4_word)(t12) + 4) = (ts4_word)t13;
            *(ts4_word *)((char *)(ts4_word)(t10) + 4) = (ts4_word)(t12 + 12);
        }
        fn_884557F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
    }
    t16 = *(ts4_word *)lbl_88CAD338;
    loc50[0] = (ts4_word)(ts4_word)lbl_88081F80;
    t17 = KeTlsGetValue((ts4_word)t16);
    t18 = *(ts4_word *)((char *)(ts4_word)(t17) + 12);
    t19 = *(ts4_word *)((char *)(ts4_word)(t17) + 4);
    if ((ts4_word)t19 < (ts4_word)t18) {
        *(ts4_word *)((char *)(ts4_word)(t19) + 0) = (ts4_word)(ts4_word)lbl_88007998;
        t20 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t19) + 4) = (ts4_word)t20;
        *(ts4_word *)((char *)(ts4_word)(t17) + 4) = (ts4_word)(t19 + 12);
    }
    return t17;
}

/* Swing_DLL.xex 0x8845B140: call_seq ts4_call_seq_u32_lbl_88CACF08_8845A5A8, fn_8845A698, fn_8845AEF0, fn_88467F60, fn_88451F18 */
ts4_word ts4_call_seq_ts4_call_seq_u32_lbl_88CACF08_8845A5A8_8845B140(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t1;

    loc50[0] = (ts4_word)(ts4_word)ts4_call_seq_u32_lbl_88CACF08_8845A5A8;
    *(unsigned char *)((char *)loc50 + 16) = (unsigned char)0;
    loc50[1] = (ts4_word)(ts4_word)fn_8845A698;
    loc50[2] = (ts4_word)(ts4_word)fn_8845AEF0;
    loc50[3] = (ts4_word)(ts4_word)fn_88467F60;
    *(unsigned char *)((char *)loc50 + 17) = (unsigned char)0;
    t1 = fn_88451F18((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)6, (ts4_word)6);
    return t1;
}

/* Swing_DLL.xex 0x8845F690: call_seq fn_8845EF10, fn_8845F410, fn_8845F1C8, fn_88467F60, fn_88451F18 */
ts4_word ts4_call_seq_fn_8845EF10_8845F690(ts4_word a0)
{
    ts4_word loc50[6];
    ts4_word t1;

    loc50[0] = (ts4_word)(ts4_word)fn_8845EF10;
    *(unsigned char *)((char *)loc50 + 16) = (unsigned char)0;
    loc50[1] = (ts4_word)(ts4_word)fn_8845F410;
    loc50[2] = (ts4_word)(ts4_word)fn_8845F1C8;
    loc50[3] = (ts4_word)(ts4_word)fn_88467F60;
    *(unsigned char *)((char *)loc50 + 17) = (unsigned char)0;
    t1 = fn_88451F18((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)5, (ts4_word)5);
    return t1;
}

/* Swing_DLL.xex 0x8845FF60: loop_set u32@0x8, lbl_88082C3C, u16@0x6, u32@0x0, u32@0xc, u32@0xc */
void ts4_loop_set_u32_off8_8845FF60(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;
    ts4_word p7;
    ts4_word lv10;
    ts4_word lv11;
    ts4_word p13;
    ts4_word p14;
    ts4_word p15;
    ts4_word t1;
    ts4_word t4;
    ts4_word t9;
    ts4_word t12;

    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88082C3C;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 12);
    p7 = (ts4_word)a1;
    lv2 = (ts4_word)a1;
    lv3 = (ts4_word)t1;
    while ((ts4_word)lv3 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(lv3) + 12);
        p5 = (ts4_word)lv3;
        p6 = (ts4_word)t4;
        lv2 = p5;
        lv3 = p6;
        p7 = (ts4_word)lv2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)p7;
    t9 = *(ts4_word *)((char *)(ts4_word)(a2) + 12);
    p15 = (ts4_word)a2;
    lv10 = (ts4_word)a2;
    lv11 = (ts4_word)t9;
    while ((ts4_word)lv11 != 0) {
        t12 = *(ts4_word *)((char *)(ts4_word)(lv11) + 12);
        p13 = (ts4_word)lv11;
        p14 = (ts4_word)t12;
        lv10 = p13;
        lv11 = p14;
        p15 = (ts4_word)lv10;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)p15;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 12));
    return;
}

/* Swing_DLL.xex 0x884667B0: get u32@0x0, u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_off0_884667B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    (void)a0;
    (void)a5;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a6);
}

/* Swing_DLL.xex 0x88467898: call_seq fn_884677B0, fn_88466E80, fn_88467030, fn_88467F60, fn_88451F18 */
void ts4_call_seq_fn_884677B0_88467898(ts4_word a0)
{
    ts4_word loc50[6];

    loc50[0] = (ts4_word)(ts4_word)fn_884677B0;
    *(unsigned char *)((char *)loc50 + 16) = (unsigned char)0;
    loc50[1] = (ts4_word)(ts4_word)fn_88466E80;
    loc50[2] = (ts4_word)(ts4_word)fn_88467030;
    loc50[3] = (ts4_word)(ts4_word)fn_88467F60;
    *(unsigned char *)((char *)loc50 + 17) = (unsigned char)0;
    fn_88451F18((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1, (ts4_word)1);
    return;
}

/* Swing_DLL.xex 0x884693F0: if_addr lbl_880842B8, u16@0x6, u32@0x0, u32@0x14, ts4_set_u32_off8_8847FA60 */
void ts4_if_addr_lbl_880842B8_884693F0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880842B8;
    ts4_set_u32_off8_8847FA60((ts4_word)(a0 + 12), (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 20)));
    return;
}

/* Swing_DLL.xex 0x8846A9B8: call_seq u32@0x70, lbl_88086A04, u32@0x54, fn_885F2FD0 */
ts4_word ts4_call_seq_u32_off70_8846A9B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[22];
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    loc50[16] = (ts4_word)0;
    loc50[0] = (ts4_word)(ts4_word)lbl_88086A04;
    loc50[17] = (ts4_word)0;
    t3 = fn_885F2FD0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84)), (ts4_word)a1, (ts4_word)t1, (ts4_word)0, (ts4_word)a2);
    return t3;
}

/* Swing_DLL.xex 0x8846B398: if_get u32@0x8, u32@0x0, u32@0xc, vcall, u32@0x50, u32@0x8 */
ts4_word ts4_if_get_u32_off8_8846B398(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    int t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    unsigned char t11;
    ts4_word t13;
    ts4_word t14;
    ts4_word t15;
    ts4_u64 t16;
    ts4_word t21;
    ts4_word t22;
    ts4_word t23;
    ts4_u64 t24;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 12))))((ts4_word)t1);
    if ((int)t4 == 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
        if ((ts4_word)t5 != 0) {
            t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 8);
            t7 = *(ts4_word *)lbl_88CAD32C;
            t10 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 96))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t7, (ts4_word)t6);
            t11 = *(unsigned char *)((char *)(ts4_word)(t10) + 0);
            if ((ts4_word)t11 == 0) {
                t13 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
                t14 = *(ts4_word *)((char *)(ts4_word)(t13) + 12);
                t15 = *(ts4_word *)((char *)(ts4_word)(t13) + 4);
                if ((ts4_word)t15 < (ts4_word)t14) {
                    *(ts4_word *)((char *)(ts4_word)(t15) + 0) = (ts4_word)(ts4_word)lbl_88086A7C;
                    t16 = __mftb();
                    *(ts4_word *)((char *)(ts4_word)(t15) + 4) = (ts4_word)t16;
                    *(ts4_word *)((char *)(ts4_word)(t13) + 4) = (ts4_word)(t15 + 12);
                }
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5, (ts4_word)a0);
                t21 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
                t22 = *(ts4_word *)((char *)(ts4_word)(t21) + 12);
                t23 = *(ts4_word *)((char *)(ts4_word)(t21) + 4);
                if ((ts4_word)t23 < (ts4_word)t22) {
                    *(ts4_word *)((char *)(ts4_word)(t23) + 0) = (ts4_word)(ts4_word)lbl_8803BC50;
                    t24 = __mftb();
                    *(ts4_word *)((char *)(ts4_word)(t23) + 4) = (ts4_word)t24;
                    *(ts4_word *)((char *)(ts4_word)(t21) + 4) = (ts4_word)(t23 + 12);
                }
            }
        }
    }
    return t4;
}

/* Swing_DLL.xex 0x8846B498: if_get u32@0x8, u32@0x0, u32@0x18, vcall, u32@0x50, u32@0x8 */
ts4_word ts4_if_get_u32_off8_8846B498(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    int t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t10;
    unsigned char t11;
    ts4_word t13;
    ts4_word t14;
    ts4_word t15;
    ts4_u64 t16;
    ts4_word t21;
    ts4_word t22;
    ts4_word t23;
    ts4_u64 t24;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1);
    if ((int)t4 == 0) {
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
        if ((ts4_word)t5 != 0) {
            t6 = *(ts4_word *)((char *)(ts4_word)(t5) + 8);
            t7 = *(ts4_word *)lbl_88CAD32C;
            t10 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 96))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t7, (ts4_word)t6);
            t11 = *(unsigned char *)((char *)(ts4_word)(t10) + 0);
            if ((ts4_word)t11 == 0) {
                t13 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
                t14 = *(ts4_word *)((char *)(ts4_word)(t13) + 12);
                t15 = *(ts4_word *)((char *)(ts4_word)(t13) + 4);
                if ((ts4_word)t15 < (ts4_word)t14) {
                    *(ts4_word *)((char *)(ts4_word)(t15) + 0) = (ts4_word)(ts4_word)lbl_88086A7C;
                    t16 = __mftb();
                    *(ts4_word *)((char *)(ts4_word)(t15) + 4) = (ts4_word)t16;
                    *(ts4_word *)((char *)(ts4_word)(t13) + 4) = (ts4_word)(t15 + 12);
                }
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 12))))((ts4_word)t5, (ts4_word)a0);
                t21 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
                t22 = *(ts4_word *)((char *)(ts4_word)(t21) + 12);
                t23 = *(ts4_word *)((char *)(ts4_word)(t21) + 4);
                if ((ts4_word)t23 < (ts4_word)t22) {
                    *(ts4_word *)((char *)(ts4_word)(t23) + 0) = (ts4_word)(ts4_word)lbl_8803BC50;
                    t24 = __mftb();
                    *(ts4_word *)((char *)(ts4_word)(t23) + 4) = (ts4_word)t24;
                    *(ts4_word *)((char *)(ts4_word)(t21) + 4) = (ts4_word)(t23 + 12);
                }
            }
        }
    }
    return t4;
}

/* Swing_DLL.xex 0x8846B598: if_get u32@0x8, fn_88488828, u32@0x50, u32@0x8, u32@lbl_88CAD32C, u32@0x0 */
ts4_word ts4_if_get_u32_off8_8846B598(ts4_word a0)
{
    ts4_word p24;
    ts4_word p25;
    ts4_word loc50[4];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t8;
    unsigned char t9;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_u64 t14;
    ts4_word t19;
    ts4_word t20;
    ts4_word t21;
    ts4_u64 t22;

    t2 = fn_88488828((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)));
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    p25 = (ts4_word)t2;
    if ((ts4_word)t3 != 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 8);
        t5 = *(ts4_word *)lbl_88CAD32C;
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t5) + 0))) + 96))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)t5, (ts4_word)t4);
        t9 = *(unsigned char *)((char *)(ts4_word)(t8) + 0);
        p24 = (ts4_word)t8;
        if ((ts4_word)t9 == 0) {
            t11 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
            t12 = *(ts4_word *)((char *)(ts4_word)(t11) + 12);
            t13 = *(ts4_word *)((char *)(ts4_word)(t11) + 4);
            if ((ts4_word)t13 < (ts4_word)t12) {
                *(ts4_word *)((char *)(ts4_word)(t13) + 0) = (ts4_word)(ts4_word)lbl_88086A7C;
                t14 = __mftb();
                *(ts4_word *)((char *)(ts4_word)(t13) + 4) = (ts4_word)t14;
                *(ts4_word *)((char *)(ts4_word)(t11) + 4) = (ts4_word)(t13 + 12);
            }
            ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 12))))((ts4_word)t3, (ts4_word)a0);
            t19 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
            t20 = *(ts4_word *)((char *)(ts4_word)(t19) + 12);
            t21 = *(ts4_word *)((char *)(ts4_word)(t19) + 4);
            if ((ts4_word)t21 < (ts4_word)t20) {
                *(ts4_word *)((char *)(ts4_word)(t21) + 0) = (ts4_word)(ts4_word)lbl_8803BC50;
                t22 = __mftb();
                *(ts4_word *)((char *)(ts4_word)(t21) + 4) = (ts4_word)t22;
                *(ts4_word *)((char *)(ts4_word)(t19) + 4) = (ts4_word)(t21 + 12);
            }
            p24 = (ts4_word)t19;
        }
        p25 = (ts4_word)p24;
    }
    return p25;
}

/* Swing_DLL.xex 0x8846B810: call_seq u32@0x70, lbl_88086A64, u32@0x54, fn_885F36B8 */
ts4_word ts4_call_seq_u32_off70_8846B810(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[18];
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    loc50[12] = (ts4_word)0;
    loc50[0] = (ts4_word)(ts4_word)lbl_88086A64;
    loc50[13] = (ts4_word)0;
    t3 = fn_885F36B8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84)), (ts4_word)a1, (ts4_word)t1, (ts4_word)0, (ts4_word)a2);
    return t3;
}

/* Swing_DLL.xex 0x88488E50: if_call_seq fn_88472530, u32@0xfc, u32@0xfc, u64@0x160, RtlLeaveCriticalSection, fn_88488090 */
ts4_word ts4_if_call_seq_fn_88472530_88488E50(ts4_word a0, float f1)
{
    ts4_word loc50[4];
    int t2;

    fn_88472530((ts4_word)(a0 + 320));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 252);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 252) = (ts4_word)(t2 + 1);
    *(volatile ts4_u64 *)((char *)(ts4_word)(a0) + 352) = (ts4_u64)-1;
    RtlLeaveCriticalSection((ts4_word)(a0 + 320));
    loc50[0] = (ts4_word)t2;
    if ((int)t2 == 0) {
        fn_88488090((ts4_word)a0, f1);
        ts4_get_u32_off0_885EAD78((ts4_word)(a0 + 256), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 252)));
    }
    ts4_forward_field0_with_minus1_885EAD68((ts4_word)(a0 + 256));
    fn_88487B38((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    if ((int)t2 == 0) {
        fn_88488828((ts4_word)a0);
    }
    return 0;
}

/* Swing_DLL.xex 0x8848E628: if_get u32@0x48, u32@0x48, u32@0x0, u32@0x0, u32@0xc0, u32@0xc0 */
void ts4_if_get_u32_off48_8848E628(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    if ((ts4_word)a2 == 0) {
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
        return;
    }
    if ((ts4_word)a1 == 0) {
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
        return;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 72);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 72);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
    t5 = *(ts4_word *)((char *)(ts4_word)(t3) + 192);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 192)) < (ts4_word)t5);
    return;
}

/* Swing_DLL.xex 0x88490F78: if_call_seq u32@0x84, u32@0xb8, u32@0xb8, fn_8848FE30, ts4_get_u32_off7c_8846AA28 */
ts4_word ts4_if_call_seq_u32_off84_88490F78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[6];
    int t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 184);
    t3 = *(ts4_word *)((char *)(ts4_word)(a2) + 184);
    if ((int)t1 != 0) {
        loc50[1] = (ts4_word)a1;
        loc50[2] = (ts4_word)a2;
        *(unsigned char *)((char *)loc50 + 0) = (unsigned char)12;
        t5 = ts4_get_u32_off7c_8846AA28((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t3);
        return t5;
    }
    t4 = fn_8848FE30((ts4_word)a0, (ts4_word)t2, (ts4_word)t3);
    return t4;
}

/* Swing_DLL.xex 0x88493338: if_call_seq u32@lbl_88CAD338, KeTlsGetValue, u32@0xc, u32@0x4, lbl_88087740, lbl_88087738 */
ts4_word ts4_if_call_seq_u32_lbl_88CAD338_88493338(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_u64 t5;
    float t7;
    float t8;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_u64 t13;
    ts4_word t17;
    ts4_word t18;
    ts4_word t19;
    ts4_u64 t20;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 < (ts4_word)t3) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_88087740;
        *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)(ts4_word)lbl_88087738;
        t5 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t4 + 16);
    }
    fn_88492108((ts4_word)a1);
    t7 = *(float *)((char *)(ts4_word)(a2) + 0);
    t8 = *(float *)((char *)(ts4_word)(a0) + 12);
    if (!(t7 < t8)) {
        t10 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
        t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 12);
        t12 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
        if ((ts4_word)t12 < (ts4_word)t11) {
            *(ts4_word *)((char *)(ts4_word)(t12) + 0) = (ts4_word)(ts4_word)lbl_8808772C;
            t13 = __mftb();
            *(ts4_word *)((char *)(ts4_word)(t12) + 4) = (ts4_word)t13;
            *(ts4_word *)((char *)(ts4_word)(t10) + 4) = (ts4_word)(t12 + 12);
        }
        fn_884934E8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    }
    t17 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t18 = *(ts4_word *)((char *)(ts4_word)(t17) + 12);
    t19 = *(ts4_word *)((char *)(ts4_word)(t17) + 4);
    if ((ts4_word)t19 < (ts4_word)t18) {
        *(ts4_word *)((char *)(ts4_word)(t19) + 0) = (ts4_word)(ts4_word)lbl_88007998;
        t20 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t19) + 4) = (ts4_word)t20;
        *(ts4_word *)((char *)(ts4_word)(t17) + 4) = (ts4_word)(t19 + 12);
    }
    return t17;
}

/* Swing_DLL.xex 0x88493430: if_call_seq u32@lbl_88CAD338, KeTlsGetValue, u32@0xc, u32@0x4, lbl_88087740, lbl_8808772C */
ts4_word ts4_if_call_seq_u32_lbl_88CAD338_88493430(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_u64 t5;
    float t6;
    float t7;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_u64 t14;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 < (ts4_word)t3) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_88087740;
        *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)(ts4_word)lbl_8808772C;
        t5 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t4 + 16);
    }
    t6 = *(float *)((char *)(ts4_word)(a2) + 0);
    t7 = *(float *)((char *)(ts4_word)(a0) + 12);
    if (!(t6 < t7)) {
        fn_884934E8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    }
    t11 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t12 = *(ts4_word *)((char *)(ts4_word)(t11) + 12);
    t13 = *(ts4_word *)((char *)(ts4_word)(t11) + 4);
    if ((ts4_word)t13 < (ts4_word)t12) {
        *(ts4_word *)((char *)(ts4_word)(t13) + 0) = (ts4_word)(ts4_word)lbl_88007998;
        t14 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t13) + 4) = (ts4_word)t14;
        *(ts4_word *)((char *)(ts4_word)(t11) + 4) = (ts4_word)(t13 + 12);
    }
    return t11;
}

/* Swing_DLL.xex 0x8849BC88: if_call_seq u32@lbl_88CAD338, KeTlsGetValue, u32@0xc, u32@0x4, lbl_8808726C, lbl_880878F8 */
ts4_word ts4_if_call_seq_u32_lbl_88CAD338_8849BC88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_u64 t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_u64 t14;
    ts4_word t16;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 < (ts4_word)t3) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_8808726C;
        *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)(ts4_word)lbl_880878F8;
        t5 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t4 + 16);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t7 = *(ts4_word *)((char *)(ts4_word)(a2) + 20);
    fn_8850C2F8((ts4_word)(t6 + 416), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 16)), (ts4_word)t7);
    t11 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t12 = *(ts4_word *)((char *)(ts4_word)(t11) + 12);
    t13 = *(ts4_word *)((char *)(ts4_word)(t11) + 4);
    if ((ts4_word)t13 < (ts4_word)t12) {
        *(ts4_word *)((char *)(ts4_word)(t13) + 0) = (ts4_word)(ts4_word)lbl_88007998;
        t14 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t13) + 4) = (ts4_word)t14;
        *(ts4_word *)((char *)(ts4_word)(t11) + 4) = (ts4_word)(t13 + 12);
    }
    t16 = fn_885EA1A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a2, (ts4_word)a2, (ts4_word)0, (ts4_word)0);
    return t16;
}

/* Swing_DLL.xex 0x8849BD50: loop_call_seq u32@lbl_88CAD338, KeTlsGetValue, u32@0xc, u32@0x4, lbl_8808726C, lbl_88087904 */
ts4_word ts4_loop_call_seq_u32_lbl_88CAD338_8849BD50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word c14;
    ts4_word lv15;
    ts4_word p16;
    ts4_word p17;
    ts4_word p19;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_u64 t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t21;
    ts4_word t22;
    ts4_word t26;
    ts4_word t27;
    ts4_word t28;
    ts4_u64 t29;
    ts4_word t31;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 < (ts4_word)t3) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_8808726C;
        *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)(ts4_word)lbl_88087904;
        t5 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t4 + 16);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t7 = *(ts4_word *)((char *)(ts4_word)(a2) + 28);
    t8 = *(ts4_word *)((char *)(ts4_word)(a2) + 16);
    t9 = *(ts4_word *)((char *)(ts4_word)(t6) + 696);
    t10 = *(ts4_word *)((char *)(ts4_word)(t7) + 8);
    t11 = *(ts4_word *)((char *)(ts4_word)(t7) + 12);
    t12 = *(ts4_word *)((char *)(ts4_word)(t7) + 16);
    *(ts4_word *)((char *)(ts4_word)(a2) + 20) = (ts4_word)t9;
    p19 = (ts4_word)t6;
    if ((ts4_word)t8 == 0) {
        t13 = *(ts4_word *)((char *)(ts4_word)(t7) + 24);
        p17 = (ts4_word)(((t13 + 15)) >> 4);
        if ((int)(((t13 + 15)) >> 4) > 0) {
            c14 = (ts4_word)(((t13 + 15)) >> 4);
            lv15 = (ts4_word)(t12 + -4);
            do {
                *(ts4_word *)((char *)(ts4_word)(lv15) + 4) = (ts4_word)0;
                *(ts4_word *)((char *)(ts4_word)(lv15) + 8) = (ts4_word)0;
                *(ts4_word *)((char *)(ts4_word)(lv15) + 12) = (ts4_word)0;
                *(ts4_word *)((char *)(ts4_word)((lv15 + 16)) + 0) = (ts4_word)0;
                p16 = (ts4_word)(lv15 + 16);
                lv15 = p16;
            } while (--c14 != 0);
            p17 = (ts4_word)0;
        }
        p19 = (ts4_word)p17;
    }
    t21 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t22 = *(ts4_word *)((char *)(ts4_word)(a2) + 24);
    fn_88510C48((ts4_word)(t21 + 416), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 16)), (ts4_word)t22, (ts4_word)t11, (ts4_word)t10, (ts4_word)t12, (ts4_word)t8, (ts4_word)p19);
    t26 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t27 = *(ts4_word *)((char *)(ts4_word)(t26) + 12);
    t28 = *(ts4_word *)((char *)(ts4_word)(t26) + 4);
    if ((ts4_word)t28 < (ts4_word)t27) {
        *(ts4_word *)((char *)(ts4_word)(t28) + 0) = (ts4_word)(ts4_word)lbl_88007998;
        t29 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t28) + 4) = (ts4_word)t29;
        *(ts4_word *)((char *)(ts4_word)(t26) + 4) = (ts4_word)(t28 + 12);
    }
    t31 = fn_885EA1A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a2, (ts4_word)a2, (ts4_word)0, (ts4_word)0);
    return t31;
}

/* Swing_DLL.xex 0x8849BE78: if_call_seq u32@lbl_88CAD338, KeTlsGetValue, u32@0xc, u32@0x4, lbl_8808726C, lbl_8808790C */
ts4_word ts4_if_call_seq_u32_lbl_88CAD338_8849BE78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_u64 t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t13;
    ts4_word t14;
    ts4_word t15;
    ts4_u64 t16;
    ts4_word t19;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t3 = *(ts4_word *)((char *)(ts4_word)(t2) + 12);
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 < (ts4_word)t3) {
        *(ts4_word *)((char *)(ts4_word)(t4) + 0) = (ts4_word)(ts4_word)lbl_8808726C;
        *(ts4_word *)((char *)(ts4_word)(t4) + 12) = (ts4_word)(ts4_word)lbl_8808790C;
        t5 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t4) + 4) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)(t4 + 16);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t7 = *(ts4_word *)((char *)(ts4_word)(a2) + 20);
    *(unsigned char *)((char *)loc50 + 0) = (unsigned char)0;
    t8 = *(ts4_word *)((char *)(ts4_word)(a2) + 16);
    fn_8850C3D0((ts4_word)(t6 + 416), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 24)), (ts4_word)t8, (ts4_word)t7, (ts4_word)(ts4_word)&loc50[0]);
    *(unsigned char *)((char *)(ts4_word)(a2) + 28) = (unsigned char)(*(unsigned char *)((char *)loc50 + 0));
    t13 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
    t14 = *(ts4_word *)((char *)(ts4_word)(t13) + 12);
    t15 = *(ts4_word *)((char *)(ts4_word)(t13) + 4);
    if ((ts4_word)t15 < (ts4_word)t14) {
        *(ts4_word *)((char *)(ts4_word)(t15) + 0) = (ts4_word)(ts4_word)lbl_88007998;
        t16 = __mftb();
        *(ts4_word *)((char *)(ts4_word)(t15) + 4) = (ts4_word)t16;
        *(ts4_word *)((char *)(ts4_word)(t13) + 4) = (ts4_word)(t15 + 12);
    }
    t19 = fn_885EA1A8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a2, (ts4_word)a2, (ts4_word)0, (ts4_word)0);
    return t19;
}

/* Swing_DLL.xex 0x884A15C0: call_seq fn_8843AE88, lbl_88087C60, lbl_88087C54, lbl_88087C48, u32@0x0, lbl_88087C34 */
ts4_word ts4_call_seq_fn_8843AE88_884A15C0(ts4_word a0)
{
    fn_8843AE88((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88087C60;
    *(ts4_word *)(8 + (char *)(ts4_word)(a0)) = (ts4_word)(ts4_word)lbl_88087C48;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)lbl_88087C34;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_88087C54;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)lbl_88087C28;
    return a0;
}

/* Swing_DLL.xex 0x884A5E50: loop_get u32@0x0, u32@0x10, vcall, u32@0xc, u32@0xc, u32@0x1c */
ts4_word ts4_loop_get_u32_off0_884A5E50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word lv5;
    ts4_word lv6;
    ts4_word p8;
    ts4_word p9;
    ts4_word p11;
    ts4_word t3;
    ts4_word t4;
    ts4_word t13;

    (void)a2;
    (void)a4;
    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a5) + 0))) + 16))))((ts4_word)a5, (ts4_word)a6);
    t4 = *(ts4_word *)((char *)(ts4_word)(a3) + 12);
    p11 = (ts4_word)a3;
    lv5 = (ts4_word)t4;
    lv6 = (ts4_word)a3;
    while ((ts4_word)lv5 != 0) {
        p8 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 12));
        p9 = (ts4_word)lv5;
        lv5 = p8;
        lv6 = p9;
        p11 = (ts4_word)lv6;
    }
    t13 = fn_884A5A40((ts4_word)a0, (ts4_word)(a1 + -12), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(p11) + 28)), (ts4_word)t3);
    return t13;
}

/* Swing_DLL.xex 0x884A5FA0: loop_get u32@0x0, u32@0x0, u32@0x0, u32@0x0, u8@0x30 */
void ts4_loop_get_u32_off0_884A5FA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p10;
    ts4_word p11;

    (void)a3;
    (void)a4;
    (void)a5;
    if ((ts4_word)a1 == 0 && (ts4_word)a2 == 0) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)1;
        return;
    }
    c1 = (ts4_word)32;
    lv2 = (ts4_word)1;
    lv3 = (ts4_word)(a0 + 52);
    do {
        if ((ts4_word)(lv2 & a1) != 0) {
            *(ts4_word *)((char *)(ts4_word)(lv3) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0)) | a2);
        }
        if ((ts4_word)(lv2 & a2) != 0) {
            *(ts4_word *)((char *)(ts4_word)(lv3) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0)) | a1);
        }
        p11 = (ts4_word)(lv3 + 4);
        p10 = (ts4_word)((lv2 << 1) | (lv2 >> 31));
        lv3 = p11;
        lv2 = p10;
    } while (--c1 != 0);
    return;
}

/* Swing_DLL.xex 0x884A6010: loop_get u32@0x0, u32@0x0, u32@0x0, u32@0x0, u8@0x30 */
void ts4_loop_get_u32_off0_884A6010(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p10;
    ts4_word p11;

    (void)a3;
    (void)a4;
    (void)a5;
    if ((ts4_word)a1 == 0 && (ts4_word)a2 == 0) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)0;
        return;
    }
    c1 = (ts4_word)32;
    lv2 = (ts4_word)1;
    lv3 = (ts4_word)(a0 + 52);
    do {
        if ((ts4_word)(lv2 & a1) != 0) {
            *(ts4_word *)((char *)(ts4_word)(lv3) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0)) & ~a2);
        }
        if ((ts4_word)(lv2 & a2) != 0) {
            *(ts4_word *)((char *)(ts4_word)(lv3) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv3) + 0)) & ~a1);
        }
        p11 = (ts4_word)(lv3 + 4);
        p10 = (ts4_word)((lv2 << 1) | (lv2 >> 31));
        lv3 = p11;
        lv2 = p10;
    } while (--c1 != 0);
    return;
}

/* Swing_DLL.xex 0x884B35F8: if_addr fn_88522C48, fn_88522640, fn_88522640, fn_88524258, fn_88524258, fn_885234A0 */
ts4_word ts4_if_addr_fn_88522C48_884B35F8(ts4_word a0)
{
    if ((ts4_word)a0 == (ts4_word)(ts4_word)fn_88522C48) {
        return 1;
    }
    if ((ts4_word)a0 == (ts4_word)(ts4_word)fn_88522640) {
        return 2;
    }
    if ((ts4_word)a0 == (ts4_word)(ts4_word)fn_88524258) {
        return 3;
    }
    if ((ts4_word)a0 == (ts4_word)(ts4_word)fn_885234A0) {
        return 4;
    }
    if ((ts4_word)a0 == (ts4_word)(ts4_word)fn_88521CB8) {
        return 5;
    }
    if ((ts4_word)a0 == (ts4_word)(ts4_word)fn_88521778) {
        return 6;
    }
    if ((ts4_word)a0 == (ts4_word)(ts4_word)fn_88521390) {
        return 7;
    }
    return ((((ts4_word)fn_88525208 - a0) == 0) ? 8 : 0);
}

/* Swing_DLL.xex 0x884B55F8: if_get u32@0x0, u32@0x10, vcall, u32@0xb0, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_884B55F8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc60[130];
    ts4_word loc50[4];
    int t3;
    ts4_word t10;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0);
    if ((int)t3 != 2) {
        if ((int)t3 != 7) {
            *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
            *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
            fn_8841CBF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)512);
            ts4_if_get_u32_off8_8841D058((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880892C8);
            t10 = *(ts4_word *)lbl_88CAD340;
            ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 12))))((ts4_word)t10, (ts4_word)1, (ts4_word)((2881093632) | 57907), (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_8808925C, (ts4_word)236);
            ts4_ref_holder_dtor_8841D638((ts4_word)(ts4_word)&loc50[0]);
            return 1;
        }
        t5 = ts4_get_u32_offe0_884761D8((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t5;
        t6 = ts4_get_u32_offe8_88476280((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t6;
        t7 = ts4_get_u32_offe4_88476298((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t7;
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 176));
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x884B7900: call_seq lbl_88D25C34, ts4_get_u32_off0_8841EAC8, ts4_if_call_seq_u32_off0_884CCBB8, lbl_88D26F54, fn_884B76C8 */
ts4_word ts4_call_seq_lbl_88D25C34_884B7900(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word loc60[6];
    ts4_word loc50[4];

    ts4_if_call_seq_u32_off0_884CCBB8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_get_u32_off0_8841EAC8((ts4_word)(ts4_word)lbl_88D25C34)), (ts4_word)a1, (ts4_word)(ts4_word)lbl_88D25C34);
    loc50[1] = (ts4_word)1;
    loc50[0] = (ts4_word)(ts4_word)&loc60[0];
    fn_884B76C8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_88D26F54, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)0, (ts4_word)1);
    return a0;
}

/* Swing_DLL.xex 0x884C0000: get u32@0x8, u32@0xc, u32@0x10 */
ts4_word ts4_get_u32_off8_884C0000(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((((int)(t1 + a1) % (int)t2) << 5) + (*(volatile ts4_word *)((char *)(ts4_word)(a0) + 16)));
}

/* Swing_DLL.xex 0x884C6B58: if_get u32@0x0, u32@0x24, vcall, lbl_8808BFAC, fn_884210E8, u32@0x0 */
ts4_word ts4_if_get_u32_off0_884C6B58(int a0, int a1)
{
    ts4_word t412;
    ts4_word t312;
    ts4_word t212;
    ts4_word t112;
    ts4_word t3;
    int t4;
    ts4_word t7;
    int t12;

    t412 = (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36));
    t3 = ((ts4_word (*)(ts4_word))(t412))((ts4_word)a0);
    t4 = fn_884210E8((ts4_word)t3, (ts4_word)(ts4_word)lbl_8808BFAC);
    if ((int)t4 != 0) {
        t7 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 28))))((ts4_word)a0);
        if ((int)(*(ts4_word *)((char *)(ts4_word)(t7) + 4)) != 0) {
            t112 = (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
            t212 = (*(ts4_word *)((char *)(ts4_word)(t112) + 32));
            t12 = fn_884C6A10((ts4_word)t7, (ts4_word)(((ts4_word (*)(ts4_word))(t212))((ts4_word)a0)), (ts4_word)a1, (ts4_word)t3, (ts4_word)(ts4_word)lbl_8808BFAC);
            if ((int)t12 == 0) {
                t312 = (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
                ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t312) + 40))))((ts4_word)a0, (ts4_word)(ts4_word)lbl_8808BFAC);
                return 0;
            }
            return 1;
        }
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x884C9648: loop_get u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_884C9648(ts4_word a0, int a1, ts4_word a2)
{
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;
    ts4_word p8;
    int t1;
    int t4;

    if ((int)a1 == 0) {
        return 0;
    }
    t1 = *(volatile ts4_word *)((char *)(ts4_word)((((((int)a1 / 4) - ((int)((int)a1 / 4) % (int)a2)) << 2) + a0)) + 0);
    p8 = (ts4_word)(((int)a1 / 4) - ((int)((int)a1 / 4) % (int)a2));
    if ((int)t1 < 0) {
        lv2 = (ts4_word)(((((int)a1 / 4) - ((int)((int)a1 / 4) % (int)a2)) << 2) + a0);
        lv3 = (ts4_word)(((int)a1 / 4) - ((int)((int)a1 / 4) % (int)a2));
        do {
            t4 = *(volatile ts4_word *)((char *)(ts4_word)((lv2 - (a2 << 2))) + 0);
            p5 = (ts4_word)(lv2 - (a2 << 2));
            p6 = (ts4_word)(lv3 - a2);
            lv2 = p5;
            lv3 = p6;
        } while ((int)t4 < 0);
        p8 = (ts4_word)lv3;
    }
    return (p8 + a2);
}

/* Swing_DLL.xex 0x884C96B8: if_get u8@0x28, u32@0xc, u32@0xc, lbl_8808C1BC, lbl_8808C1C8 */
ts4_word ts4_if_get_u8_off28_884C96B8(ts4_word a0)
{
    unsigned char t1;
    ts4_word t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t1 != 255) {
        return (a0 + 40);
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)t3 == 1) {
        return (ts4_word)lbl_8808C1C8;
    }
    return (((t3 + -2) == 0) ? (ts4_word)lbl_8808C1BC : 0);
}

/* Swing_DLL.xex 0x884CF220: call_seq fn_884D7FD0, lbl_8808C440, u32@0x0, u32@lbl_88C264DC, ts4_tailcall_fn_884D7C98_884D7F38, u32@lbl_88C264DC */
ts4_word ts4_call_seq_fn_884D7FD0_884CF220(ts4_word a0)
{
    fn_884D7FD0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C440;
    ts4_tailcall_fn_884D7C98_884D7F38((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C264DC));
    ts4_call_seq_fn_884D7C98_884D7F90((ts4_word)a0, (ts4_word)(ts4_word)lbl_88CACFCC, (ts4_word)(*(ts4_word *)lbl_88C264DC));
    ts4_call_seq_fn_884D7C98_884D7F90((ts4_word)a0, (ts4_word)(ts4_word)lbl_88CAD05C, (ts4_word)(*(ts4_word *)lbl_88C264DC));
    ts4_call_seq_fn_884D7C98_884D7F90((ts4_word)a0, (ts4_word)(ts4_word)lbl_88CAD02C, (ts4_word)(*(ts4_word *)lbl_88C264DC));
    ts4_call_seq_fn_884D7C98_884D7F90((ts4_word)a0, (ts4_word)(ts4_word)lbl_88CACFFC, (ts4_word)(*(ts4_word *)lbl_88C264DC));
    return a0;
}

/* Swing_DLL.xex 0x884CF848: call_seq fn_884D7FD0, lbl_8808C570, u32@0x0, u32@lbl_88C26308, ts4_tailcall_fn_884D7C98_884D7F38, u32@lbl_88C264DC */
ts4_word ts4_call_seq_fn_884D7FD0_884CF848(ts4_word a0)
{
    fn_884D7FD0((ts4_word)a0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808C570;
    ts4_tailcall_fn_884D7C98_884D7F38((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_88C26308));
    ts4_call_seq_fn_884D7C98_884D7F90((ts4_word)a0, (ts4_word)(ts4_word)lbl_88CACFCC, (ts4_word)(*(ts4_word *)lbl_88C264DC));
    ts4_call_seq_fn_884D7C98_884D7F90((ts4_word)a0, (ts4_word)(ts4_word)lbl_88CAD05C, (ts4_word)(*(ts4_word *)lbl_88C264DC));
    ts4_call_seq_fn_884D7C98_884D7F90((ts4_word)a0, (ts4_word)(ts4_word)lbl_88CAD02C, (ts4_word)(*(ts4_word *)lbl_88C264DC));
    ts4_call_seq_fn_884D7C98_884D7F90((ts4_word)a0, (ts4_word)(ts4_word)lbl_88CACFFC, (ts4_word)(*(ts4_word *)lbl_88C264DC));
    return a0;
}

/* Swing_DLL.xex 0x884D12A8: if_call_seq u32@0x8, u32@0x4, fn_8841C678, u32@0x4, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off8_884D12A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p4;
    ts4_word loc50[2];
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    loc50[0] = (ts4_word)a1;
    loc50[1] = (ts4_word)a2;
    p4 = (ts4_word)a0;
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        t3 = fn_8841C678((ts4_word)a0, (ts4_word)8, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 & 0x3fffffff), (ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_u64 *)((char *)(ts4_word)((t5 << 3)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) = (ts4_u64)(*(ts4_u64 *)((char *)loc50 + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1);
    return p4;
}

/* Swing_DLL.xex 0x884D1BC0: if_get ts4_get_u32_off8_88427208, u32@0x0, u32@0x20, vcall, u32@0x8, u32@0x4 */
ts4_word ts4_if_get_ts4_get_u32_off8_88427208_884D1BC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    int t6;
    ts4_word t9;
    ts4_word t12;

    t1 = ts4_get_u32_off8_88427208((ts4_word)a2);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    loc50[0] = (ts4_word)a1;
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 32))))((ts4_word)t1);
    t5 = *(ts4_word *)((char *)(ts4_word)(a3) + 8);
    t6 = *(ts4_word *)((char *)(ts4_word)(a3) + 4);
    loc50[1] = (ts4_word)t4;
    if ((int)t6 == (int)(t5 & 0x3fffffff)) {
        fn_8841C678((ts4_word)a3, (ts4_word)8);
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a3) + 4);
    *(ts4_u64 *)((char *)(ts4_word)((t9 << 3)) + (*(ts4_word *)((char *)(ts4_word)(a3) + 0))) = (ts4_u64)(*(ts4_u64 *)((char *)loc50 + 0));
    *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 4)) + 1);
    t12 = fn_88421338((ts4_word)a0);
    ts4_get_u32_off8_88427198((ts4_word)a2, (ts4_word)a0, (ts4_word)(t12 + 1));
    return 0;
}

/* Swing_DLL.xex 0x884D7B18: if_addr ts4_get_u32_off0_8841EAC8, lbl_8803CC5C, fn_884210E8, ts4_get_u32_off0_8841EAC8, lbl_8803CCD4, fn_884210E8 */
ts4_word ts4_if_addr_ts4_get_u32_off0_8841EAC8_884D7B18(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc60[130];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t12;
    ts4_word t13;
    ts4_word t16;
    ts4_word t17;
    ts4_word t20;
    ts4_word t26;
    ts4_word t14;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    t1 = ts4_get_u32_off0_8841EAC8((ts4_word)a2);
    t2 = fn_884210E8((ts4_word)t1, (ts4_word)(ts4_word)lbl_8803CC5C);
    if ((int)t2 == 0) {
        t12 = ts4_get_u32_off0_8841EAC8((ts4_word)a1);
        t13 = fn_885E7AD8((ts4_word)(a0 + 56), (ts4_word)t12, (ts4_word)0);
        if ((ts4_word)t13 != 0) {
            t16 = fn_8841F3E0((ts4_word)t13, (ts4_word)0);
            t17 = fn_8841F3E0((ts4_word)a1, (ts4_word)0);
            if ((ts4_word)t17 != (ts4_word)t16) {
                fn_8841CBF8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)512);
                ts4_if_get_u32_off8_8841D058((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_8808C9B8);
                t20 = *(ts4_word *)lbl_88CAD340;
                ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t20) + 0))) + 12))))((ts4_word)t20, (ts4_word)3, (ts4_word)((622329856) | 29212), (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_8808C994, (ts4_word)166);
                ts4_ref_holder_dtor_8841D638((ts4_word)(ts4_word)&loc50[0]);
            }
            t26 = fn_88423788((ts4_word)(a0 + 20), (ts4_word)t13, (ts4_word)-1);
            fn_88423660((ts4_word)(a0 + 20), (ts4_word)a1, (ts4_word)t26);
            fn_88423660((ts4_word)(a0 + 88), (ts4_word)a1, (ts4_word)t13);
            return 0;
        }
        t14 = ts4_get_u32_off0_8841EAC8((ts4_word)a1);
        fn_885E76C0((ts4_word)(a0 + 56), (ts4_word)t14, (ts4_word)a1);
        return 1;
    }
    t3 = ts4_get_u32_off0_8841EAC8((ts4_word)a2);
    t4 = fn_884210E8((ts4_word)t3, (ts4_word)(ts4_word)lbl_8803CCD4);
    if ((int)t4 == 0) {
        t6 = fn_885E7AD8((ts4_word)(a0 + 72), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)0);
        if ((ts4_word)t6 != 0) {
            t7 = fn_88423788((ts4_word)(a0 + 20), (ts4_word)t6, (ts4_word)-1);
            fn_88423660((ts4_word)(a0 + 20), (ts4_word)a1, (ts4_word)t7);
            fn_88423660((ts4_word)(a0 + 88), (ts4_word)a1, (ts4_word)t6);
            return 0;
        }
        fn_885E76C0((ts4_word)(a0 + 72), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)a1);
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x884E1F90: call_seq fn_8841F6D0, fn_8841F6D0, fn_8841F6D0, fn_884E1F10 */
void ts4_call_seq_fn_8841F6D0_884E1F90(void)
{
    float t1;
    float t2;
    float t3;

    t1 = fn_8841F6D0();
    t2 = fn_8841F6D0();
    t3 = fn_8841F6D0();
    fn_884E1F10(t1, t2, t3, (*(float *)lbl_88001A68));
    return;
}

/* Swing_DLL.xex 0x884E6B20: call_seq fn_88420F08, fn_884E6A28 */
void ts4_call_seq_fn_88420F08_884E6B20(ts4_word a0, ts4_word a1, ts4_word a2, float f1, ts4_word a4, ts4_word a5)
{
    ts4_word loc50[6];

    fn_88420F08((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
    fn_884E6A28((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], f1, (ts4_word)a4, (ts4_word)a5);
    return;
}

/* Swing_DLL.xex 0x884E6B70: call_seq fn_88420E00, fn_884E6A28 */
void ts4_call_seq_fn_88420E00_884E6B70(ts4_word a0, ts4_word a1, ts4_word a2, float f1, ts4_word a4, ts4_word a5)
{
    ts4_word loc50[6];

    fn_88420E00((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2);
    fn_884E6A28((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], f1, (ts4_word)a4, (ts4_word)a5);
    return;
}

/* Swing_DLL.xex 0x884EF320: call_seq lbl_8808D660, lbl_8808D640, lbl_8808D5F4, u32@0x0, u32@0x8, u32@0x20 */
void ts4_call_seq_lbl_8808D660_884EF320(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808D660;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_8808D640;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_8808D5F4;
    fn_884E5F78((ts4_word)(*(ts4_word *)lbl_88D26FD4), (ts4_word)(a0 + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(ts4_word)lbl_8808D4C4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_88089504;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x885051A8: if_call_seq u8@0x2, u32@0x0, u8@0x4, u8@0x3, u8@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u8_off2_885051A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[6];
    unsigned char t1;
    float t4;
    float t5;
    unsigned char t8;
    unsigned char t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t6;
    unsigned char t7;
    ts4_word t2;
    unsigned char t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 2);
    if ((ts4_word)t1 != 0) {
        t4 = *(float *)((char *)(ts4_word)(a0) + 8);
        t5 = *(float *)lbl_88001A20;
        if (!(t4 == t5)) {
            t8 = *(unsigned char *)((char *)(ts4_word)(a0) + 3);
            *(float *)((char *)loc50 + 8) = t4;
            t9 = *(unsigned char *)((char *)(ts4_word)(a0) + 4);
            t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 76);
            loc50[3] = (ts4_word)t9;
            loc50[1] = (ts4_word)t10;
            loc50[0] = (ts4_word)(((t8 << 4) | (t8 >> 28)) + a2);
            t11 = fn_88502840((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a3);
            return t11;
        }
        t6 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        t7 = *(unsigned char *)((char *)(ts4_word)(a0) + 4);
        *(unsigned char *)((char *)(ts4_word)(t6) + 3) = (unsigned char)3;
        *(unsigned char *)((char *)(ts4_word)(t6) + 4) = (unsigned char)t7;
        *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(t6 + 16);
        return a0;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 4);
    *(unsigned char *)((char *)(ts4_word)(t2) + 3) = (unsigned char)3;
    *(unsigned char *)((char *)(ts4_word)(t2) + 4) = (unsigned char)t3;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)(t2 + 16);
    return a0;
}

/* Swing_DLL.xex 0x8852E468: if_get u32@0x4, u32@0x4, u32@0x4, u32@0x0, u32@0x14, vcall */
void ts4_if_get_u32_off4_8852E468(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)t1;
        t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a3) + 0))) + 20))))((ts4_word)a3, (ts4_word)t1, (ts4_word)a5);
        *(ts4_word *)((char *)(ts4_word)(a7) + 0) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(a7) + 4) = (ts4_word)t1;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t8 != (ts4_word)t7) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)t7;
        t11 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 20))))((ts4_word)a2, (ts4_word)t7, (ts4_word)a4);
        *(ts4_word *)((char *)(ts4_word)(a6) + 0) = (ts4_word)t11;
        *(ts4_word *)((char *)(ts4_word)(a6) + 4) = (ts4_word)t7;
    }
    return;
}

/* Swing_DLL.xex 0x88539B40: get  */
float ts4_get_88539B40(ts4_word a0)
{
    ts4_word locm10[1];
    ts4_word t2;

    *(float *)((char *)locm10 + 0) = (*(float *)lbl_88001A68);
    t2 = locm10[0];
    locm10[0] = (ts4_word)(((a0 << 28) & 0x80000000) | t2);
    return (*(float *)((char *)locm10 + 0));
}

/* Swing_DLL.xex 0x8853A180: if_get u32@0x0 */
ts4_word ts4_if_get_u32_off0_8853A180(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word p4;
    ts4_word p7;
    ts4_word p8;
    float t1;
    float t2;
    float t5;
    float t6;

    t1 = *(float *)((char *)(ts4_word)(a0) + 0);
    t2 = *(float *)((char *)(ts4_word)(a0) + 4);
    if (t1 > t2) {
        p3 = (ts4_word)0;
        p4 = (ts4_word)128;
    } else {
        p3 = (ts4_word)1;
        p4 = (ts4_word)64;
    }
    t5 = *(float *)((char *)(ts4_word)(a0) + 8);
    t6 = *(float *)((char *)(ts4_word)((p3 << 2)) + a0);
    p7 = (ts4_word)p3;
    p8 = (ts4_word)p4;
    if (t5 > t6) {
        p7 = (ts4_word)2;
        p8 = (ts4_word)32;
    }
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)p7;
    return p8;
}

/* Swing_DLL.xex 0x88542048: if_call_seq fn_88540E58, u32@0xc, u32@0x13c, u32@lbl_88CAD338, KeTlsGetValue, u32@0xc */
ts4_word ts4_if_call_seq_fn_88540E58_88542048(ts4_word a0)
{
    ts4_word t1;
    float t2;
    float t3;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_u64 t10;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_u64 t17;

    t1 = fn_88540E58();
    t2 = *(float *)((char *)(ts4_word)(a0) + 20);
    t3 = *(float *)((char *)(ts4_word)(a0) + 32);
    if (!(t2 < t3) && (int)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 12))) + 316)) != 0) {
        t7 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
        t8 = *(ts4_word *)((char *)(ts4_word)(t7) + 12);
        t9 = *(ts4_word *)((char *)(ts4_word)(t7) + 4);
        if ((ts4_word)t9 < (ts4_word)t8) {
            *(ts4_word *)((char *)(ts4_word)(t9) + 0) = (ts4_word)(ts4_word)lbl_880871F0;
            t10 = __mftb();
            *(ts4_word *)((char *)(ts4_word)(t9) + 4) = (ts4_word)t10;
            *(ts4_word *)((char *)(ts4_word)(t7) + 4) = (ts4_word)(t9 + 12);
        }
        fn_8848DCF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
        t14 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CAD338));
        t15 = *(ts4_word *)((char *)(ts4_word)(t14) + 12);
        t16 = *(ts4_word *)((char *)(ts4_word)(t14) + 4);
        if ((ts4_word)t16 < (ts4_word)t15) {
            *(ts4_word *)((char *)(ts4_word)(t16) + 0) = (ts4_word)(ts4_word)lbl_8803BC50;
            t17 = __mftb();
            *(ts4_word *)((char *)(ts4_word)(t16) + 4) = (ts4_word)t17;
            *(ts4_word *)((char *)(ts4_word)(t14) + 4) = (ts4_word)(t16 + 12);
        }
    }
    return t1;
}

/* Swing_DLL.xex 0x8854F5D0: if_call_seq u32@0x10, u32@lbl_88CACF08, KeTlsGetValue, u32@0x60, fn_8841A328, u32@0x64 */
void ts4_if_call_seq_u32_off10_8854F5D0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word p10;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 == 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 96);
        if ((ts4_word)t4 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t3) + 100) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 100)) + -1);
            *(ts4_word *)((char *)(ts4_word)(t3) + 96) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 0));
            p8 = (ts4_word)t4;
        } else {
            t5 = fn_8841A328((ts4_word)t3, (ts4_word)5);
            p8 = (ts4_word)t5;
        }
        if ((ts4_word)p8 != 0) {
            t9 = fn_884727C8((ts4_word)p8, (ts4_word)a1, (ts4_word)1);
            p10 = (ts4_word)t9;
        } else {
            p10 = (ts4_word)0;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)p10;
        ts4_if_get_u32_off0_885E9628((ts4_word)(a0 + 8));
    }
    return;
}

/* Swing_DLL.xex 0x88557410: get  */
float ts4_get_88557410(ts4_word a0)
{
    return (((float)((double)((ts4_s64)(int)((12345 - ((int)a0 * (int)((1043922944) | 45459))) & 0x7fffffff)))) * (*(float *)lbl_8802E854));
}

/* Swing_DLL.xex 0x885640B0: call_seq fn_88563F20 */
double ts4_call_seq_fn_88563F20_885640B0(void)
{

    return ((fn_88563F20()) * (*(double *)lbl_8808EDE0));
}

/* Swing_DLL.xex 0x88578BE0: if_fn  */
ts4_word ts4_if_fn_88578BE0(ts4_word a0)
{
    if ((ts4_word)(a0 & 0xffff) >= 48) {
        if ((ts4_word)(a0 & 0xffff) < 58) {
            return ((a0 & 0xffff) + -48);
        }
        if ((ts4_word)(a0 & 0xffff) < 65296) {
            if ((ts4_word)(a0 & 0xffff) >= 1632) {
                if ((ts4_word)(a0 & 0xffff) < 1642) {
                    return ((a0 & 0xffff) + -1632);
                }
                if ((ts4_word)(a0 & 0xffff) >= 1776) {
                    if ((ts4_word)(a0 & 0xffff) < 1786) {
                        return ((a0 & 0xffff) + -1776);
                    }
                    if ((ts4_word)(a0 & 0xffff) >= 2406) {
                        if ((ts4_word)(a0 & 0xffff) < 2416) {
                            return ((a0 & 0xffff) + -2406);
                        }
                        if ((ts4_word)(a0 & 0xffff) >= 2534) {
                            if ((ts4_word)(a0 & 0xffff) < 2544) {
                                return ((a0 & 0xffff) + -2534);
                            }
                            if ((ts4_word)(a0 & 0xffff) >= 2662) {
                                if ((ts4_word)(a0 & 0xffff) < 2672) {
                                    return ((a0 & 0xffff) + -2662);
                                }
                                if ((ts4_word)(a0 & 0xffff) >= 2790) {
                                    if ((ts4_word)(a0 & 0xffff) < 2800) {
                                        return ((a0 & 0xffff) + -2790);
                                    }
                                    if ((ts4_word)(a0 & 0xffff) >= 2918) {
                                        if ((ts4_word)(a0 & 0xffff) < 2928) {
                                            return ((a0 & 0xffff) + -2918);
                                        }
                                        if ((ts4_word)(a0 & 0xffff) >= 3174) {
                                            if ((ts4_word)(a0 & 0xffff) < 3184) {
                                                return ((a0 & 0xffff) + -3174);
                                            }
                                            if ((ts4_word)(a0 & 0xffff) >= 3302) {
                                                if ((ts4_word)(a0 & 0xffff) < 3312) {
                                                    return ((a0 & 0xffff) + -3302);
                                                }
                                                if ((ts4_word)(a0 & 0xffff) >= 3430) {
                                                    if ((ts4_word)(a0 & 0xffff) < 3440) {
                                                        return ((a0 & 0xffff) + -3430);
                                                    }
                                                    if ((ts4_word)(a0 & 0xffff) >= 3664) {
                                                        if ((ts4_word)(a0 & 0xffff) < 3674) {
                                                            return ((a0 & 0xffff) + -3664);
                                                        }
                                                        if ((ts4_word)(a0 & 0xffff) >= 3792) {
                                                            if ((ts4_word)(a0 & 0xffff) < 3802) {
                                                                return ((a0 & 0xffff) + -3792);
                                                            }
                                                            if ((ts4_word)(a0 & 0xffff) >= 3872) {
                                                                if ((ts4_word)(a0 & 0xffff) < 3882) {
                                                                    return ((a0 & 0xffff) + -3872);
                                                                }
                                                                if ((ts4_word)(a0 & 0xffff) >= 4160) {
                                                                    if ((ts4_word)(a0 & 0xffff) < 4170) {
                                                                        return ((a0 & 0xffff) + -4160);
                                                                    }
                                                                    if ((ts4_word)(a0 & 0xffff) >= 6112) {
                                                                        if ((ts4_word)(a0 & 0xffff) < 6122) {
                                                                            return ((a0 & 0xffff) + -6112);
                                                                        }
                                                                        if ((ts4_word)(a0 & 0xffff) >= 6160 && (ts4_word)(a0 & 0xffff) < 6170) {
                                                                            return ((a0 & 0xffff) + -6160);
                                                                        }
                                                                        return -1;
                                                                    }
                                                                    return -1;
                                                                }
                                                                return -1;
                                                            }
                                                            return -1;
                                                        }
                                                        return -1;
                                                    }
                                                    return -1;
                                                }
                                                return -1;
                                            }
                                            return -1;
                                        }
                                        return -1;
                                    }
                                    return -1;
                                }
                                return -1;
                            }
                            return -1;
                        }
                        return -1;
                    }
                    return -1;
                }
                return -1;
            }
            return -1;
        }
        if ((ts4_word)(a0 & 0xffff) < 65306) {
            return (((a0 & 0xffff) - 65536) + 240);
        }
        return -1;
    }
    return -1;
}

/* Swing_DLL.xex 0x8858C140: call_seq fn_8858BE10, fn_8858CA98 */
ts4_word ts4_call_seq_fn_8858BE10_8858C140(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t4;

    loc50[0] = (ts4_word)0;
    fn_8858BE10((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0);
    t2 = loc58[1];
    fn_8858CA98((ts4_word)0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t2, (ts4_word)20, (ts4_word)a1);
    t4 = loc50[0];
    return t4;
}

/* Swing_DLL.xex 0x885A6ED0: if_call_seq u32@0x30, u32@0x50, u32@0x54, ts4_pool_free_885B72F0, u32@0x30, memset */
ts4_word ts4_if_call_seq_u32_off30_885A6ED0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t1;
    float t2;
    float t4;
    float t3;
    int t7;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    t2 = *(float *)lbl_88001A20;
    t3 = *(float *)lbl_8802B4A0;
    t4 = *(float *)lbl_88001A68;
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 88) = t2;
    *(float *)((char *)(ts4_word)(a0) + 92) = t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 96) = t4;
    if ((ts4_word)t1 != 0) {
        ts4_pool_free_885B72F0((ts4_word)t1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    }
    t7 = memset((ts4_word)(a0 + 40), (ts4_word)0, (ts4_word)40);
    return t7;
}

/* Swing_DLL.xex 0x885AA110: loop_get u32@0x34, u32@0x2c, u32@0x2c, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off34_885AA110(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word c4;
    ts4_word lv5;
    ts4_word p7;
    ts4_word p8;
    ts4_word p10;
    ts4_word t1;
    ts4_word t3;
    ts4_word t11;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)a1 < (ts4_word)t1) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
        p8 = (ts4_word)t3;
        if ((ts4_word)a1 != 0) {
            c4 = (ts4_word)a1;
            lv5 = (ts4_word)t3;
            do {
                p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv5) + 4));
                lv5 = p7;
            } while (--c4 != 0);
            p8 = (ts4_word)lv5;
        }
        p10 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(p8) + 0));
    } else {
        p10 = (ts4_word)0;
    }
    t11 = *(ts4_word *)((char *)(ts4_word)(p10) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t11) + 0))) + 8))))((ts4_word)t11, (ts4_word)0, (ts4_word)a4, (ts4_word)a2, (ts4_word)a3, (ts4_word)a5, (ts4_word)a6, (ts4_word)a2);
}

/* Swing_DLL.xex 0x885AAD10: get u32@0x30, u32@0xb0, u32@0x0, u32@0x28, vcall, fn_885AA560 */
ts4_word ts4_get_u32_off30_885AAD10(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word loc60[2];
    ts4_word t2;
    ts4_word t5;
    ts4_word t7;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + 176);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)1, (ts4_word)(ts4_word)&a3, (ts4_word)1, (ts4_word)(ts4_word)&a4, (ts4_word)((322371584) | 61441), (ts4_word)a5);
    loc60[0] = (ts4_word)t5;
    fn_885AA560((ts4_word)(ts4_word)&loc60[0]);
    t7 = loc60[0];
    return t7;
}

/* Swing_DLL.xex 0x885C1BD8: if_call_seq fn_88563A38, lbl_880B0548 */
float ts4_if_call_seq_fn_88563A38_885C1BD8(int a0)
{
    double t3;

    if ((int)a0 >= 0 && (int)a0 < 192) {
        return (*(float *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_880B0548));
    }
    t3 = fn_88563A38((*(double *)lbl_88007B80), (((float)((double)((ts4_s64)(int)a0))) * (*(float *)lbl_88029638)));
    return ((float)t3);
}

/* Swing_DLL.xex 0x885C8770: if_get u32@0x4, u32@0x40, lbl_8809D7C0 */
float ts4_if_get_u32_off4_885C8770(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    float t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 64);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + (a2 << 2));
    p4 = (ts4_word)(t2 - t3);
    if ((int)(t2 - t3) >= 72) {
        p4 = (ts4_word)71;
    }
    t5 = *(float *)((char *)(ts4_word)(a0) + 0);
    return (((*(float *)((char *)(ts4_word)((p4 << 2)) + (ts4_word)lbl_8809D7C0)) / ((float)((double)((ts4_s64)(int)(1 << ((int)p4 >> 2)))))) * t5);
}

/* Swing_DLL.xex 0x885CA898: loop_call_seq u32@0x0, fn_885CD4B0, fn_885C3770, u32@0x128, u32@0x128, fn_885C3770 */
void ts4_loop_call_seq_u32_off0_885CA898(ts4_word a0)
{
    ts4_word loc50[2];
    ts4_word t1;
    int t2;
    int t3;
    int t7;
    ts4_word t8;
    int t9;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = fn_885CD4B0((ts4_word)(a0 + 224), (ts4_word)21);
    if ((int)t2 >= 0) {
        t3 = fn_885C3770((ts4_word)(a0 + 224), (ts4_word)7, (ts4_word)(ts4_word)&loc50[0]);
        if ((int)t3 >= 0) {
            do {
                t7 = loc50[0];
                t8 = *(ts4_word *)((char *)(ts4_word)(t1) + 296);
                if ((int)t7 != 127) {
                    *(ts4_word *)((char *)(ts4_word)(t1) + 296) = (ts4_word)(t8 + t7);
                    break;
                }
                *(ts4_word *)((char *)(ts4_word)(t1) + 296) = (ts4_word)(t8 + 127);
                t9 = fn_885C3770((ts4_word)(a0 + 224), (ts4_word)7, (ts4_word)(ts4_word)&loc50[0]);
            } while ((int)t9 >= 0);
        }
    }
    return;
}

/* Swing_DLL.xex 0x885CD2B8: fn  */
ts4_word ts4_fn_885CD2B8(ts4_word a0)
{
    switch ((ts4_word)(((a0 & 0xffff) + -352))) {
        case 0:
        return 1;
        case 1:
        case 5:
        return 2;
        case 2:
        case 3:
        case 4:
        case 6:
        case 7:
        return 3;
        default:
        return 0;
    }
}

/* Swing_DLL.xex 0x885DD0D8: if_call_seq u32@0x44, lbl_880B45A8, lbl_880B4560, lbl_880B4540, fn_885DC838, u32@0x8 */
float ts4_if_call_seq_u32_off44_885DD0D8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)a1 >= (ts4_word)t1) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880B4560, (ts4_word)(ts4_word)lbl_880B45A8, (ts4_word)338);
    }
    return (*(float *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8))) + (a1 << 2)));
}

/* Swing_DLL.xex 0x885E4AB0: if_call_seq fn_885E4248, lbl_880BCAB4, u32@0x0, lbl_880B4540, lbl_880BC988, lbl_880BCAA4 */
ts4_word ts4_if_call_seq_fn_885E4248_885E4AB0(ts4_word a0, int a1, int a2, ts4_word a3)
{

    fn_885E4248((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880BCAB4;
    if ((int)a2 >= (int)((0) | 32768)) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880BCAA4, (ts4_word)(ts4_word)lbl_880BC988, (ts4_word)577, (ts4_word)((0) | 32768), (ts4_word)(ts4_word)lbl_880BCAB4);
    }
    if ((int)a1 >= (int)(65536)) {
        fn_885DC838((ts4_word)0, (ts4_word)(ts4_word)lbl_880B4540, (ts4_word)(ts4_word)lbl_880BCA90, (ts4_word)(ts4_word)lbl_880BC988, (ts4_word)578);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((a2 << 16) + a1);
    return a0;
}

/* Swing_DLL.xex 0x885E76A0: get u32@0x8, u8@0x0 */
void ts4_get_u32_off8_885E76A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)((int)(*(ts4_word *)((char *)(ts4_word)(a1) + 8)) >= (int)a2);
    return;
}

/* Swing_DLL.xex 0x885E8360: addr lbl_880C06F0, lbl_880C06E0 */
ts4_word ts4_addr_lbl_880C06F0_885E8360(ts4_word a0)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    ts4_word locm10[4];
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    vv1 = *(__vector4 *)((ts4_word)(a0));
    vv2 = *(__vector4 *)((ts4_word)((ts4_word)lbl_880C06F0));
    vv3 = *(__vector4 *)((ts4_word)((ts4_word)lbl_880C06E0));
    vv4 = __vmaddfp(vv1, vv3, vv2);
    *(__vector4 *)((ts4_word)((ts4_word)&locm10[0])) = vv4;
    t5 = locm10[1];
    t6 = locm10[0];
    t7 = locm10[3];
    t8 = locm10[2];
    return (((((((((((t7 << 8) | (t7 >> 24)) & 0xffffc000) | (t8 & 0x3fff)) << 8) | (((((t7 << 8) | (t7 >> 24)) & 0xffffc000) | (t8 & 0x3fff)) >> 24)) & 0xffffc000) | (t5 & 0x3fff)) << 2) & 0xffffff00) | ((t6 >> 6) & 0xff));
}

/* Swing_DLL.xex 0x885ED0A8: if_call_seq ts4_if_get_u8_offc_885ECDC0, fn_885ECCD8, fn_885ECDF0, ts4_if_call_seq_fn_88423788_885ECF48, ts4_if_get_u8_offc_885ECDC0, fn_885ECCD8 */
ts4_word ts4_if_call_seq_ts4_if_get_u8_offc_885ECDC0_885ED0A8(ts4_word a0, ts4_word a1, int a2)
{
    ts4_word p2;
    ts4_word p6;
    ts4_word p8;
    ts4_word t5;
    ts4_word t1;
    ts4_word t7;

    if ((int)a2 == 1) {
        fn_885ECDF0((ts4_word)a0, (ts4_word)a1);
        ts4_if_call_seq_fn_88423788_885ECF48((ts4_word)a0, (ts4_word)a1);
        t5 = fn_885ECCD8((ts4_word)a0, (ts4_word)a1, (ts4_word)2, (ts4_word)(ts4_word)ts4_if_get_u8_offc_885ECDC0);
        p6 = (ts4_word)t5;
    } else {
        p2 = (ts4_word)a0;
        if ((int)a2 < 4) {
            t1 = fn_885ECCD8((ts4_word)a0, (ts4_word)a1, (ts4_word)2, (ts4_word)(ts4_word)ts4_if_get_u8_offc_885ECDC0);
            p2 = (ts4_word)t1;
        }
        p6 = (ts4_word)p2;
    }
    p8 = (ts4_word)p6;
    if ((int)a2 < 5) {
        t7 = fn_885ECCD8((ts4_word)a0, (ts4_word)a1, (ts4_word)8, (ts4_word)(ts4_word)fn_885ECFF0);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x885ED758: if_set u32@0x8, lbl_880C0F8C, u32@0xc, u16@0x6, u32@0x0, u32@0x10 */
void ts4_if_set_u32_off8_885ED758(ts4_word a0, ts4_word a1)
{
    unsigned short t100;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880C0F8C;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    if ((ts4_word)(*(volatile unsigned short *)((char *)(ts4_word)(a1) + 4)) == 0) {
        return;
    }
    t100 = (*(volatile unsigned short *)((char *)(ts4_word)(a1) + 6));
    *(volatile unsigned short *)((char *)(ts4_word)(a1) + 6) = (unsigned short)(t100 + 1);
    return;
}

/* Swing_DLL.xex 0x885EDDB0: fn  */
ts4_word ts4_fn_885EDDB0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return (((int)(((int)a0 / (int)a1) - a3) / (int)a2) - a4);
}

/* Swing_DLL.xex 0x885EEE88: if_call_seq u32@0x8, u32@0x4, fn_8841C678, u32@0x4, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off8_885EEE88(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p4;
    ts4_word loc50[2];
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    loc50[0] = (ts4_word)a1;
    loc50[1] = (ts4_word)a2;
    p4 = (ts4_word)a0;
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        t3 = fn_8841C678((ts4_word)a0, (ts4_word)8, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 & 0x3fffffff), (ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_u64 *)((char *)(ts4_word)((t5 << 3)) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) = (ts4_u64)(*(ts4_u64 *)((char *)loc50 + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1);
    return p4;
}

/* Swing_DLL.xex 0x885F2C00: fn  */
ts4_u64 ts4_fn_885F2C00(void)
{
    ts4_u64 t1;

    t1 = __mftb();
    return t1;
}

/* Swing_DLL.xex 0x886049F0: if_call_seq lbl_880F90BC, u8@0x18, u32@0x0, u32@0x4, ts4_msg_buffer_alloc_88278620, u32@0x4 */
ts4_word ts4_if_call_seq_lbl_880F90BC_886049F0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F90BC;
    if ((ts4_word)a1 == 0) {
        t1 = ts4_msg_buffer_alloc_88278620((ts4_word)16384);
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t1;
        *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)0;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)16384;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t3;
    return a0;
}

/* Swing_DLL.xex 0x88606C80: if_fn  */
ts4_word ts4_if_fn_88606C80(ts4_word a0)
{
    if ((int)((short)a0) < -20000) {
        return -1;
    }
    return ((int)20000 < (int)((short)a0));
}

/* Swing_DLL.xex 0x88607708: if_get u32@0x2c, u32@0x38, u32@0xc */
ts4_word ts4_if_get_u32_off2c_88607708(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    if ((ts4_word)a1 != (ts4_word)((983040) | 65535)) {
        t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
        return ((((*(ts4_word *)((char *)(ts4_word)(((a1 << 4) + t1)) + 12))) >> 5) + t2);
    }
    return 0;
}

/* Swing_DLL.xex 0x886083C8: if_call_seq ts4_tailcall_fn_885654E8_885655D0 */
void ts4_if_call_seq_ts4_tailcall_fn_885654E8_885655D0_886083C8(ts4_word a0, ...)
{
    ts4_va_list ap;
    ts4_word loc60[514];

    if ((ts4_word)a0 != 0) {
        TS4_VA_START(ap, a0);
        ts4_tailcall_fn_885654E8_885655D0((ts4_word)(ts4_word)&loc60[0], (ts4_word)2047, (ts4_word)a0, (ts4_word)(ts4_word)ap);
    }
    return;
}

/* Swing_DLL.xex 0x8860A3B8: if_get u32@0x2c */
ts4_word ts4_if_get_u32_off2c_8860A3B8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 != (ts4_word)((983040) | 65535)) {
        return (((ts4_u64)(*(ts4_u64 *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + (a1 << 4))) >> 24) & 0xfffff);
    }
    return ((983040) | 65535);
}

/* Swing_DLL.xex 0x8860A538: call_seq u32@0x4, u32@0x4, fn_88607170, u32@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_off4_8860A538(int a0, ts4_word a1, ts4_word a2, ts4_args3 sp3, ts4_word a5)
{
    int t1;
    ts4_word t2;
    ts4_word t3;
    int t4;

    t1 = *(ts4_word *)(4 + (char *)(ts4_word)(a1));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = sp3.w[1];
    t4 = fn_88607170((ts4_word)t2, (ts4_word)t3, (ts4_word)t1, (ts4_word)a2);
    *(volatile ts4_word *)((char *)(ts4_word)(a5) + 4) = (ts4_word)t4;
    *(volatile ts4_word *)((char *)(ts4_word)(a5) + 0) = (ts4_word)a0;
    return t4;
}

/* Swing_DLL.xex 0x8860A598: call_seq u32@0x4, u32@0x4, fn_88606F40, u32@0x4, u32@0x0 */
ts4_word ts4_call_seq_u32_off4_8860A598(ts4_word a0, ts4_word a1, ts4_args3 sp2, ts4_word a4)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = sp2.w[1];
    t4 = fn_88606F40((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t2, (ts4_word)t1);
    *(volatile ts4_word *)((char *)(ts4_word)(a4) + 4) = (ts4_word)t4;
    *(volatile ts4_word *)((char *)(ts4_word)(a4) + 0) = (ts4_word)a0;
    return t4;
}
