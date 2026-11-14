/* Swing_DLL.xex 0x886FC0A8-0x887DBC70, executable version 0.0.0.3. */
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdeprecated-non-prototype"
#endif
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

extern char lbl_880C1320[];
extern char lbl_880D3A88[];
extern char lbl_880D4488[];
extern char lbl_880D4AD4[];
extern char lbl_880D7A20[];
extern char lbl_880D9F94[];
extern char lbl_880DFEDC[];
extern char lbl_880DFFF8[];
extern char lbl_880E4BA0[];
extern char lbl_880E4BBC[];
extern char lbl_880E4CE8[];
extern char lbl_880E70D8[];
extern char lbl_880EA218[];
extern char lbl_880EA718[];
extern char lbl_880ECE4C[];
extern char lbl_880ECE64[];
extern char lbl_880ED610[];
extern char lbl_880EF3B0[];
extern char lbl_880EF47C[];
extern char lbl_880EF5D4[];
extern char lbl_880EF6F0[];
extern char lbl_880EF7C4[];
extern char lbl_880EF980[];
extern char lbl_880EF9F8[];
extern char lbl_880EFCDC[];
extern char lbl_880EFD3C[];
extern char lbl_880EFD64[];
extern char lbl_880EFD8C[];
extern char lbl_880EFDB4[];
extern char lbl_880EFDE0[];
extern char lbl_880EFE08[];
extern char lbl_880EFE30[];
extern char lbl_880F1070[];
extern char lbl_880F1078[];
extern char lbl_880F1080[];
extern char lbl_880F1F58[];
extern char lbl_880F2118[];
extern char lbl_880F2148[];
extern char lbl_880F21E8[];
extern char lbl_880F2254[];
extern char lbl_880F27E8[];
extern char lbl_880F2810[];
extern char lbl_880F30A4[];
extern char lbl_880F3388[];
extern char lbl_8814B440[];
extern char lbl_88C6C204[];
extern char lbl_88C6C21C[];
extern char lbl_88C6C220[];
extern char lbl_88C6CD7C[];
extern char lbl_88C6CD84[];
extern char lbl_88C6CD88[];
extern char lbl_88D3E414[];
extern char lbl_88D41FC4[];
extern char lbl_88D45910[];
extern char lbl_88D45A10[];
extern char lbl_88D45A24[];
extern char lbl_88D45A60[];
extern char lbl_88D45A78[];
extern char lbl_88D45AB4[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B34[];
extern char lbl_88D45B38[];
extern char ts4_ascii_lower_to_upper_88564790[];
ts4_word RtlEnterCriticalSection();
ts4_word ts4_loop_call_seq_u32_off0_88150378();
ts4_word fn_88150600();
ts4_word fn_8815D480();
ts4_word fn_88163B90();
ts4_word fn_881643D0();
ts4_word fn_88165E80();
ts4_word fn_8816CF48();
ts4_word fn_8816D090();
ts4_word fn_8816D1A8();
ts4_word fn_8817EA90();
ts4_word fn_88180070();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_8819A9D8();
ts4_word fn_8819AD80();
ts4_word fn_881A5020();
ts4_word fn_881A50F0();
ts4_word fn_881A52D8();
ts4_word fn_881AA7A0();
ts4_word fn_881AAE70();
ts4_word fn_881AB4F0();
ts4_word ts4_find_record_by_key_881AC778();
ts4_word fn_881D4050();
ts4_word fn_881F41E8();
ts4_word fn_88213D38();
ts4_word fn_88216460();
ts4_word fn_88218AD0();
ts4_word ts4_loop_call_seq_u32_offc_88219E68();
ts4_word ts4_if_call_seq_u32_off8_8821FD70();
ts4_word ts4_vector_push_back_construct_88220060();
ts4_word fn_88223DA0();
ts4_word fn_8822AE40();
ts4_word ts4_loop_call_seq_u32_off20_88233618();
ts4_word fn_8823DD50();
ts4_word fn_88287FA0();
ts4_word fn_885651F8();
ts4_word fn_8857C8C8();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_886131F0();
ts4_word fn_88613268();
ts4_word fn_88617788();
ts4_word ts4_if_call_seq_lbl_880F7EE4_88617D28();
ts4_word fn_88617D88();
ts4_word fn_8862BE08();
ts4_word fn_8862C0E8();
ts4_word fn_886EFA20();
ts4_word fn_886EFA70();
ts4_word fn_886EFAC0();
ts4_word fn_886EFD38();
ts4_word fn_886FBF18();
ts4_word fn_886FC638();
ts4_word fn_88702A88();
ts4_word fn_8870EA08();
ts4_word fn_8870FE00();
ts4_word fn_88713FD0();
ts4_word fn_88717408();
ts4_word fn_8871B7E0();
ts4_word fn_88721A08();
ts4_word fn_88722B80();
ts4_word fn_8872D070();
ts4_word fn_88731540();
ts4_word fn_88739D80();
ts4_word fn_88748350();
ts4_word fn_88748B18();
ts4_word fn_8874FCD8();
ts4_word fn_88754C40();
ts4_word fn_88755E58();
ts4_word fn_887561A8();
ts4_word fn_88756638();
ts4_word fn_887568C0();
ts4_word fn_88758018();
ts4_word fn_8875EB68();
ts4_word fn_8876D210();
ts4_word fn_8876D2C0();
ts4_word fn_8876D560();
ts4_word fn_88771868();
ts4_word fn_88773A18();
ts4_word fn_88778208();
ts4_word fn_88778BE8();
ts4_word fn_887818A0();
ts4_word fn_8878C820();
ts4_word fn_887A33A8();
ts4_word fn_887BD430();
ts4_word fn_887CB978();
ts4_word fn_887CDAA0();
ts4_word fn_887CE250();
ts4_word fn_887CE478();
ts4_word fn_887CFC48();
ts4_word fn_887D0378();
ts4_word fn_887D0C80();
ts4_word fn_887D9A10();
ts4_word fn_887E94F8();
ts4_word fn_887EA048();
ts4_word fn_887EDF40();
ts4_word fn_887EFAE8();
ts4_word fn_8882ED00();
ts4_word fn_888348A0();
ts4_word fn_888AD568();
ts4_word ts4_if_call_seq_fn_8817EA90_888D85B0();
ts4_word fn_888DDD70();
ts4_word fn_888F67B8();
ts4_word fn_88912A38();
ts4_word fn_889C63A0();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_call_seq_fn_887143E0_88719CD8();
ts4_word ts4_call_seq_lbl_880D72B0_88912AC0();
ts4_word ts4_call_seq_u32_off0_8817B998();
ts4_word ts4_call_seq_u32_off0_881B1B08();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_gp0_xdata_get_bool_88163C60();
ts4_word ts4_if_call_seq_fn_88734098_8876CE68();
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88211A60();
ts4_word ts4_if_call_seq_u32_off4_8817E430();
ts4_word ts4_if_call_seq_u32_offc_882124A8();
ts4_word ts4_memset();
ts4_word ts4_object_finalize();
ts4_word ts4_tailcall_XamContentGetCreator_8857B2E8();
ts4_word ts4_tailcall_fn_88565410_885654D8();
ts4_word ts4_tailcall_fn_88584548_8857AFE8();



































/* Swing_DLL.xex 0x88757908: if_call_seq lbl_880F1070, fn_881643D0, lbl_880F1078, fn_881643D0, lbl_880D3A88, fn_881643D0 */
ts4_word ts4_if_call_seq_lbl_880F1070_88757908(ts4_word a0, ts4_word a1)
{
    ts4_word p7;
    ts4_word p9;
    ts4_word p11;
    ts4_word p13;
    ts4_word p15;
    ts4_word t1;
    ts4_word t14;
    ts4_word t2;
    ts4_word t12;
    ts4_word t3;
    ts4_word t10;
    ts4_word t4;
    ts4_word t8;
    ts4_word t5;
    ts4_word t6;

    t1 = fn_881643D0((ts4_word)a1, (ts4_word)(ts4_word)lbl_880F1070);
    if ((ts4_word)(t1 & 0xff) != 0) {
        t14 = fn_88754C40((ts4_word)a0, (ts4_word)((438304768) | 338), (ts4_word)0);
        p15 = (ts4_word)t14;
    } else {
        t2 = fn_881643D0((ts4_word)a1, (ts4_word)(ts4_word)lbl_880F1078);
        if ((ts4_word)(t2 & 0xff) != 0) {
            t12 = fn_88754C40((ts4_word)a0, (ts4_word)((438304768) | 339), (ts4_word)0);
            p13 = (ts4_word)t12;
        } else {
            t3 = fn_881643D0((ts4_word)a1, (ts4_word)(ts4_word)lbl_880D3A88);
            if ((ts4_word)(t3 & 0xff) != 0) {
                t10 = fn_88754C40((ts4_word)a0, (ts4_word)((438304768) | 340), (ts4_word)0);
                p11 = (ts4_word)t10;
            } else {
                t4 = fn_881643D0((ts4_word)a1, (ts4_word)(ts4_word)lbl_880F1080);
                if ((ts4_word)(t4 & 0xff) != 0) {
                    t8 = fn_88754C40((ts4_word)a0, (ts4_word)((438304768) | 369), (ts4_word)0);
                    p9 = (ts4_word)t8;
                } else {
                    t5 = fn_881643D0((ts4_word)a1, (ts4_word)(ts4_word)lbl_880D4AD4);
                    p7 = (ts4_word)t5;
                    if ((ts4_word)(t5 & 0xff) != 0) {
                        t6 = fn_88754C40((ts4_word)a0, (ts4_word)((438304768) | 380), (ts4_word)0);
                        p7 = (ts4_word)t6;
                    }
                    p9 = (ts4_word)p7;
                }
                p11 = (ts4_word)p9;
            }
            p13 = (ts4_word)p11;
        }
        p15 = (ts4_word)p13;
    }
    return p15;
}








































/* Swing_DLL.xex 0x8879DEE8: if_get u32@0x10, u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x10, lbl_880E4BA0 */
ts4_word ts4_if_get_u32_off10_8879DEE8(ts4_word a0)
{
    ts4_word p5;
    ts4_word p27;
    ts4_word p28;
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t15;
    ts4_word t18;
    ts4_word t19;
    ts4_word t20;
    ts4_word t21;
    ts4_word t22;
    ts4_word t26;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t3 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t3 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 16) = (ts4_word)t1;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)0;
        *(volatile unsigned char *)((char *)(ts4_word)(t3) + 12) = (unsigned char)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 20) = (ts4_word)(*(ts4_word *)lbl_88C6C204);
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 24) = (ts4_word)((3751936000) | 45041);
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 28) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880E4CE8;
        p5 = (ts4_word)t3;
    } else {
        p5 = (ts4_word)0;
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(p5) + 16);
    fn_887EDF40((ts4_word)(*(ts4_word *)lbl_88D45A10), (ts4_word)(a0 + 924), (ts4_word)t6);
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p5) + 0))) + 12))))((ts4_word)p5);
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p5) + 0))) + 0))))((ts4_word)p5, (ts4_word)1);
    t15 = *(ts4_word *)lbl_88D45A10;
    t18 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 688))) + 48))))((ts4_word)(t15 + 688));
    p28 = (ts4_word)t18;
    if ((ts4_word)(t18 & 0xff) != 0) {
        t19 = fn_887EFAE8((ts4_word)t15);
        p27 = (ts4_word)t19;
        if ((ts4_word)(t19 & 0xff) == 0) {
            t20 = fn_887EA048((ts4_word)(ts4_word)&loc50[0], (ts4_word)t15);
            t21 = *(ts4_word *)((char *)(ts4_word)(t20) + 0);
            t22 = fn_887EA048((ts4_word)(ts4_word)&loc54[0], (ts4_word)t15);
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 204) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t22) + 0));
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 208) = (ts4_word)((4047372288) | 47660);
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 212) = (ts4_word)t21;
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 216) = (ts4_word)-1;
            *(volatile unsigned char *)((char *)(ts4_word)(a0) + 220) = (unsigned char)0;
            fn_88778BE8((ts4_word)a0, (ts4_word)14);
            ts4_tailcall_fn_88584548_8857AFE8((ts4_word)160);
            t26 = fn_887E94F8((ts4_word)t15);
            p27 = (ts4_word)t26;
        }
        p28 = (ts4_word)p27;
    }
    return p28;
}

























