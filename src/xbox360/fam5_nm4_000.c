/* Small functions produced by the asm2c translator (FAM4 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM5: near misses of the translator fixed by a per-function search over
   source-level variants (commutative operand order, int-widened byte/half
   locals, address of a parameter instead of a stack copy, ...).
   The original address is in the comment above each definition. Parameters
   are untyped words (a0 = this/first argument); field accesses are by byte
   offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#endif
typedef unsigned long ts4_word;
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;
#include "ts4_vector.h"

extern char lbl_880C1320[];
extern char lbl_880E9EF4[];
extern char lbl_880F4460[];
extern char lbl_880F44EC[];
extern char lbl_88C6B478[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B38[];
ts4_word fn_88150600();
ts4_word fn_881506A0();
ts4_word fn_881519D0();
ts4_word fn_88199068();
ts4_word fn_8819B2A0();
ts4_word fn_8819B448();
ts4_word fn_881F7958();
ts4_word ts4_loop_call_seq_u32_off2c_8831CB38();
ts4_word fn_8832B030();
ts4_word fn_8841C678();
ts4_word fn_885651F8();
ts4_word fn_8860D360();
ts4_word fn_8860DBC8();
ts4_word fn_88627EC0();
ts4_word fn_8862C0E8();
ts4_word fn_886F7C08();
ts4_word fn_886F8450();
ts4_word fn_887DF4F0();
ts4_word fn_88923530();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_handle_forward0_88610948();
ts4_word ts4_handle_forward0_88610AC8();
ts4_word ts4_handle_forward_88150770();
ts4_word ts4_handle_forward_88610778();
ts4_word ts4_if_call_seq_u32_off0_88200E58();
ts4_word ts4_if_call_seq_u32_off0_8820BE00();

/* Swing_DLL.xex 0x8819B148: loop_call_seq u8@0x0, fn_8819B448 */
ts4_word ts4_loop_call_seq_u8_off0_8819B148(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p3;
    ts4_word p5;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        lv1 = (ts4_word)a1;
        do {
            t2 = *(unsigned char *)((char *)(ts4_word)(lv1) + 0);
            p3 = (ts4_word)(lv1 + 1);
            lv1 = p3;
        } while ((ts4_word)t2 != 0);
        p5 = (ts4_word)((lv1 - a1) + -1);
    } else {
        p5 = (ts4_word)0;
    }
    fn_8819B448((ts4_word)a0, (ts4_word)a1, (ts4_word)p5);
    return a0;
}

/* Swing_DLL.xex 0x8819B1A8: loop_call_seq u8@0x0, fn_8819B2A0 */
ts4_word ts4_loop_call_seq_u8_off0_8819B1A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word lv1;
    ts4_word p3;
    ts4_word p5;
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a1 != 0) {
        lv1 = (ts4_word)a1;
        do {
            t2 = *(unsigned char *)((char *)(ts4_word)(lv1) + 0);
            p3 = (ts4_word)(lv1 + 1);
            lv1 = p3;
        } while ((ts4_word)t2 != 0);
        p5 = (ts4_word)((lv1 - a1) + -1);
    } else {
        p5 = (ts4_word)0;
    }
    fn_8819B2A0((ts4_word)a0, (ts4_word)a1, (ts4_word)p5);
    return a0;
}

/* Swing_DLL.xex 0x8820B418: if_addr fn_881F7958, lbl_880E9EF4, u32@0x0, u32@0xc, fn_881519D0, u32@0x0 */
ts4_word ts4_if_addr_fn_881F7958_8820B418(ts4_word a0)
{
    ts4_word q82;
    ts4_word q81;
    ts4_word q80;
    ts4_word p7;
    ts4_word p10;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;

    t1 = fn_881F7958((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9EF4;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    t2 = fn_881519D0((ts4_word)t1);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
    loc50[1] = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(t5 + 16);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    loc50[0] = (ts4_word)1000;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    t6 = fn_88199068((ts4_word)0, (ts4_word)16, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t6 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t6) + 0) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t6) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t6) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)(t6) + 12) = (ts4_word)0;
        p7 = (ts4_word)t6;
    } else {
        p7 = (ts4_word)0;
    }
    q80 = a0 + 12;
    ts4_if_call_seq_u32_off0_8820BE00((ts4_word)(q80));
    *(volatile ts4_word *)((char *)(ts4_word)((q80)) + 0) = (ts4_word)p7;
    q81 = a0 + 24;
    if ((int)(q81) != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)((q81)) + 0) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)((q81)) + 4) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)((q81)) + 24) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)((q81)) + 8) = (ts4_word)0;
        *(volatile ts4_word *)((char *)(ts4_word)((q81)) + 16) = (ts4_word)0;
    }
    loc58[0] = (ts4_word)1000;
    loc58[1] = (ts4_word)0;
    t9 = fn_88199068((ts4_word)0, (ts4_word)4, (ts4_word)(ts4_word)&loc58[0]);
    if ((ts4_word)t9 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t9) + 0) = (ts4_word)0;
        p10 = (ts4_word)t9;
    } else {
        p10 = (ts4_word)0;
    }
    q82 = a0 + 20;
    ts4_if_call_seq_u32_off0_88200E58((ts4_word)(q82));
    *(volatile ts4_word *)((char *)(ts4_word)((q82)) + 0) = (ts4_word)p10;
    return a0;
}

/* Swing_DLL.xex 0x8831CB38: loop_call_seq u32@0x2c, u32@0x118, u32@0x8, u32@0x88, ts4_loop_call_seq_u32_off2c_8831CB38, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_off2c_8831CB38(ts4_word a0, ts4_word a1)
{
    ts4_word q80;
    ts4_word lv2;
    ts4_word p7;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    *(ts4_word *)((char *)(ts4_word)(a0) + 280) = (ts4_word)a1;
    lv2 = (ts4_word)t1;
    q80 = a0 + 44;
    while ((ts4_word)lv2 != (ts4_word)(q80)) {
        ((ts4_word (*)())ts4_loop_call_seq_u32_off2c_8831CB38)((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv2) + 8))) + 136)), (ts4_word)a1);
        p7 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(lv2) + 0));
        lv2 = p7;
    }
    return 0;
}

/* Swing_DLL.xex 0x8832B178: loop_call_seq u32@0x60, u32@0x0, u8@0x24, fn_8832B030 */
ts4_word ts4_loop_call_seq_u32_off60_8832B178(ts4_word a0, ts4_word a1)
{
    ts4_word q80;
    ts4_word lv2;
    ts4_word p7;
    ts4_word t3;

    lv2 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 96));
    q80 = a0 + 96;
    while ((ts4_word)lv2 != (ts4_word)(q80)) {
        t3 = *(ts4_word *)((char *)(ts4_word)(lv2) + 0);
        if ((ts4_word)(a1 & 0xff) == 0 || (ts4_word)(*(unsigned char *)((char *)(ts4_word)(lv2) + 36)) != 0) {
            fn_8832B030((ts4_word)a0, (ts4_word)lv2);
        }
        p7 = (ts4_word)t3;
        lv2 = p7;
    }
    return 0;
}

/* Swing_DLL.xex 0x88425710: fn  */
void ts4_fn_88425710(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word q83;
    ts4_word q82;
    ts4_word q81;
    ts4_word q80;
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv6;
    __vector4 vv7;
    __vector4 vv8;
    __vector4 vv9;
    __vector4 vv10;
    __vector4 vv11;
    __vector4 vv12;

    vv1 = *(__vector4 *)((ts4_word)(a0));
    vv2 = *(__vector4 *)((ts4_word)(a2));
    vv3 = *(__vector4 *)((ts4_word)(a1));
    vv4 = __vmaddfp(vv2, vv3, vv1);
    *(__vector4 *)((ts4_word)(a0)) = vv4;
    q80 = a0 + 16;
    vv5 = *(__vector4 *)((ts4_word)((q80)));
    q81 = a2 + 16;
    vv6 = *(__vector4 *)((ts4_word)(q81));
    vv7 = *(__vector4 *)((ts4_word)(a1));
    vv8 = __vmaddfp(vv6, vv7, vv5);
    *(__vector4 *)((ts4_word)((q80))) = vv8;
    q82 = a0 + 32;
    vv9 = *(__vector4 *)((ts4_word)((q82)));
    vv10 = *(__vector4 *)((ts4_word)(a1));
    q83 = a2 + 32;
    vv11 = *(__vector4 *)((ts4_word)(q83));
    vv12 = __vmaddfp(vv11, vv10, vv9);
    *(__vector4 *)((ts4_word)((q82))) = vv12;
    return;
}

/* Swing_DLL.xex 0x884D34A8: if_call_seq u32@0x20, u32@0x1c, fn_8841C678, u32@0x4, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_off20_884D34A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word q80;
    ts4_word p4;
    ts4_word loc50[2];
    ts4_word t1;
    int t2;
    ts4_word t3;
    ts4_word t5;

    q80 = a0 + 24;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    loc50[0] = (ts4_word)a1;
    loc50[1] = (ts4_word)a2;
    p4 = (ts4_word)a0;
    if ((int)t2 == (int)(t1 & 0x3fffffff)) {
        t3 = fn_8841C678((ts4_word)(q80), (ts4_word)8, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 & 0x3fffffff), (ts4_word)t2);
        p4 = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)((q80)) + 4);
    *(ts4_u64 *)((char *)(ts4_word)((t5 << 3)) + (*(ts4_word *)((char *)(ts4_word)((q80)) + 0))) = (ts4_u64)(*(ts4_u64 *)((char *)loc50 + 0));
    *(ts4_word *)((char *)(ts4_word)((q80)) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)((q80)) + 4)) + 1);
    return p4;
}

/* Swing_DLL.xex 0x88670268: addr lbl_880F4460, u32@0x0, u32@0x30 */
void ts4_addr_lbl_880F4460_88670268(ts4_word a0)
{
    ts4_word q80;
    __vector4 vv1;

    vv1 = __vspltisw(0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F4460;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    q80 = a0 + 16;
    *(__vector4 *)((ts4_word)((q80))) = vv1;
    *(__vector4 *)((ts4_word)((q80) + 16)) = vv1;
    return;
}

/* Swing_DLL.xex 0x8867BAB8: if_get u32@0x0, u32@0x0, u32@0x4, u32@0x30, u32@0x310 */
ts4_word ts4_if_get_u32_off0_8867BAB8(ts4_word a0)
{
    unsigned char b70;
    ts4_word p4;
    int t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0);
    b70 = !((int)t2 != (int)((2147418112) | 65535)) || ((int)t2 < 0);
    p4 = (ts4_word)b70;
    if ((ts4_word)(p4 & 0xff) != 0) {
        return 0;
    }
    return (((int)t2 >= (int)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 48))) + 784))) & 0xff);
}

/* Swing_DLL.xex 0x8867BB18: if_get u32@0x0, u32@0x0, u32@0x4, u32@0x30, u32@0x310 */
ts4_word ts4_if_get_u32_off0_8867BB18(ts4_word a0)
{
    unsigned char b70;
    ts4_word p4;
    int t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0);
    b70 = !((int)t2 != (int)((2147418112) | 65535)) || ((int)t2 < 0);
    p4 = (ts4_word)b70;
    if ((ts4_word)(p4 & 0xff) != 0) {
        return 0;
    }
    return (((int)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 48))) + 784)) >= (int)t2) & 0xff);
}

/* Swing_DLL.xex 0x8867E7B0: addr lbl_880F44EC, u32@0x0, u32@0x30, u32@0x34, u32@0x38, u32@0x3c */
void ts4_addr_lbl_880F44EC_8867E7B0(ts4_word a0)
{
    ts4_word q80;
    __vector4 vv1;

    vv1 = __vspltisw(0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F44EC;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)((4118282240) | 1402);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)((4118282240) | 1402);
    q80 = a0 + 32;
    *(__vector4 *)((ts4_word)(q80)) = vv1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 88) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 89) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 91) = (unsigned char)1;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 90) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 92) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 93) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 94) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 95) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 96) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 97) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 98) = (unsigned char)0;
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 99) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x886C5478: get u32@0x34, u32@0x4, u32@0x0 */
void ts4_get_u32_off34_886C5478(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    __vector4 vv5;
    __vector4 vv6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    t2 = *(ts4_word *)((char *)(ts4_word)(((a1 << 3) + t1)) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(((a1 << 3) + t1)) + 0);
    t4 = *(unsigned char *)((char *)(ts4_word)(t2) + a2);
    vv5 = *(__vector4 *)((ts4_word)((((t4 + a3) << 5) + t3)));
    *(__vector4 *)((ts4_word)(a4)) = vv5;
    vv6 = *(__vector4 *)((ts4_word)((((t4 + a3) << 5) + t3) + 16));
    *(__vector4 *)((ts4_word)(a4 + 16)) = vv6;
    return;
}

/* Swing_DLL.xex 0x886FE3D0: if_get ts4_handle_forward_88150770, u32@0x0, u32@0x28, vcall, u32@0x0 */
ts4_word ts4_if_get_fn_88150770_886FE3D0(ts4_args3 sp0, ts4_word a2)
{
    unsigned char b70;
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t8;

    loc50[0] = (ts4_word)((815595520) | 12359);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    t3 = loc58[1];
    b70 = !((ts4_word)t2 != 0) || ((ts4_word)t3 == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b70;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t8 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 40))))((ts4_word)t2, (ts4_word)(ts4_word)&loc58[0], (ts4_word)t3, (ts4_word)72);
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t8;
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x8873A6B8: loop_call_seq fn_88627EC0, lbl_880C1320, fn_886F7C08, ts4_assign_formatted_text, fn_88150600, ts4_destroy_owned_object */
void ts4_loop_call_seq_fn_88627EC0_8873A6B8(ts4_word a0, ts4_args3 sp1)
{
    unsigned char b70;
    ts4_word p14;
    ts4_word lv17;
    ts4_word p20;
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t6;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = fn_886F7C08(sp1, (ts4_word)((4184276992) | 2499), (ts4_word)(ts4_word)lbl_880C1320);
    ts4_assign_formatted_text((ts4_word)(ts4_word)&loc50[0], (ts4_word)t3);
    fn_88150600((ts4_word)(a0 + 40), (ts4_word)(ts4_word)&loc50[0]);
    t6 = loc50[0];
    ts4_destroy_owned_object((ts4_word)t6);
    t8 = fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)t3);
    t9 = *(ts4_word *)((char *)(ts4_word)(t8) + 0);
    t10 = *(ts4_word *)((char *)(ts4_word)(t8) + 4);
    t11 = *(ts4_word *)((char *)(ts4_word)(t8) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t9;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t10;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t11;
    b70 = !((ts4_word)t9 != 0) || ((ts4_word)t10 == (ts4_word)((983040) | 65535));
    p14 = (ts4_word)b70;
    if ((ts4_word)(p14 & 0xff) == 0) {
        lv17 = (ts4_word)275;
        do {
            fn_886F8450((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
            p20 = (ts4_word)(lv17 + -1);
            lv17 = p20;
        } while ((int)p20 != 0);
    }
    return;
}

/* Swing_DLL.xex 0x8878C120: loop_get ts4_handle_forward0_88610AC8, ts4_handle_forward_88150770, u32@0x0, u32@0x4, u32@0x0, u32@0x50 */
void ts4_loop_get_fn_88610AC8_8878C120(ts4_word a0, ts4_word a1)
{
    unsigned char b70;
    ts4_word lv4;
    ts4_word lv5;
    ts4_word p8;
    ts4_word p33;
    ts4_word p34;
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word loc78[3];
    ts4_word loc68[3];
    ts4_word loc88[3];
    ts4_word t2;
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t14;
    ts4_word t19;
    ts4_word t20;
    ts4_word t22;
    ts4_word t29;
    ts4_word t30;
    ts4_word t31;
    ts4_word t32;

    ts4_handle_forward0_88610AC8((ts4_word)(ts4_word)&loc58[0], (ts4_word)a1);
    t2 = loc58[1];
    t3 = loc58[0];
    lv4 = (ts4_word)t2;
    lv5 = (ts4_word)t3;
    do {
        b70 = !((ts4_word)lv5 != 0) || ((ts4_word)lv4 == (ts4_word)((983040) | 65535));
        p8 = (ts4_word)b70;
        if ((ts4_word)(p8 & 0xff) != 0) {
            return;
        }
        loc50[0] = (ts4_word)((4262526976) | 53560);
        t9 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
        t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 0);
        t11 = *(ts4_word *)((char *)(ts4_word)(t9) + 4);
        t14 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 80))))((ts4_word)t10, (ts4_word)t9, (ts4_word)t11, (ts4_word)1);
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc68[0], (ts4_word)t14);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)(ts4_word)&loc68[0]);
        t19 = loc68[0];
        if ((ts4_word)t19 != 0) {
            t20 = *(ts4_word *)lbl_88D45B38;
            if ((ts4_word)t20 != 0) {
                t22 = fn_8860D360((ts4_word)t20, (ts4_word)t19);
                if ((ts4_word)t22 != 0) {
                    fn_8860DBC8((ts4_word)t22, (ts4_word)t19);
                } else {
                    fn_8860DBC8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t20) + 36)), (ts4_word)t19);
                }
            } else {
                fn_885651F8((ts4_word)t19, (ts4_word)t19);
            }
        }
        t29 = ts4_handle_forward0_88610948((ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc58[0]);
        t30 = *(ts4_word *)((char *)(ts4_word)(t29) + 0);
        t31 = *(ts4_word *)((char *)(ts4_word)(t29) + 4);
        t32 = *(ts4_word *)((char *)(ts4_word)(t29) + 8);
        loc58[0] = (ts4_word)t30;
        loc58[1] = (ts4_word)t31;
        loc58[2] = (ts4_word)t32;
        p33 = (ts4_word)t31;
        p34 = (ts4_word)t30;
        lv4 = p33;
        lv5 = p34;
    } while (1);
}

/* Swing_DLL.xex 0x887E1B80: if_call_seq u32@0x4, u32@0x18, u32@0x1c, u32@0x20, ts4_handle_forward_88610778, fn_887DF4F0 */
void ts4_if_call_seq_u32_off4_887E1B80(ts4_word a0, ts4_word a1)
{
    unsigned char b70;
    ts4_word p3;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc68[3];
    ts4_word t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    b70 = !((ts4_word)t1 != (ts4_word)((594477056) | 11937) && (ts4_word)t1 != (ts4_word)((799539200) | 34051)) || ((ts4_word)t1 == (ts4_word)((1437335552) | 51868));
    p3 = (ts4_word)b70;
    if ((ts4_word)(p3 & 0xff) == 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
        t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
        loc50[0] = (ts4_word)((3945791488) | 12967);
        loc58[0] = (ts4_word)t4;
        loc58[1] = (ts4_word)t5;
        loc58[2] = (ts4_word)t6;
        ts4_handle_forward_88610778((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
        (void)loc68[2];
        fn_887DF4F0((ts4_word)a0, (ts4_word)a1, *(ts4_args3 *)&loc68[0], (ts4_word)0, (ts4_word)0);
    }
    return;
}

/* Swing_DLL.xex 0x88934100: loop_call_seq u32@lbl_88D45AD4, u32@0xbc, u32@0xc4, u32@0xc0, ts4_handle_forward0_88610AC8, u32@lbl_88C6B478 */
ts4_word ts4_loop_call_seq_u32_lbl_88D45AD4_88934100(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    unsigned char b70;
    unsigned char b71;
    ts4_word p6;
    ts4_word lv10;
    ts4_word lv11;
    ts4_word p13;
    ts4_word p22;
    ts4_word p23;
    ts4_word loc68[3];
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word loc78[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t8;
    ts4_word t9;
    ts4_word t14;
    ts4_word t15;
    ts4_word t16;
    ts4_word t18;
    ts4_word t19;
    ts4_word t20;
    ts4_word t21;

    (void)a1;
    t1 = *(ts4_word *)lbl_88D45AD4;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 188);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 196);
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 192);
    loc68[0] = (ts4_word)t2;
    loc68[2] = (ts4_word)t3;
    loc68[1] = (ts4_word)t4;
    b70 = !((ts4_word)t2 != 0) || ((ts4_word)t4 == (ts4_word)((983040) | 65535));
    p6 = (ts4_word)b70;
    if ((ts4_word)(p6 & 0xff) == 0) {
        ts4_handle_forward0_88610AC8((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc68[0], (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)t3, (ts4_word)t2);
        t8 = loc58[1];
        t9 = loc58[0];
        lv10 = (ts4_word)t8;
        lv11 = (ts4_word)t9;
        do {
            b71 = !((ts4_word)lv11 != 0) || ((ts4_word)lv10 == (ts4_word)((983040) | 65535));
            p13 = (ts4_word)b71;
            if ((ts4_word)(p13 & 0xff) != 0) {
                return 0;
            }
            t14 = *(ts4_word *)lbl_88C6B478;
            t15 = fn_881506A0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
            t16 = *(ts4_word *)((char *)(ts4_word)(t15) + 0);
            if ((ts4_word)t16 == (ts4_word)t14 && (ts4_word)(loc58[1]) == (ts4_word)a0) {
                return 1;
            }
            t18 = ts4_handle_forward0_88610948((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc58[0]);
            t19 = *(ts4_word *)((char *)(ts4_word)(t18) + 0);
            t20 = *(ts4_word *)((char *)(ts4_word)(t18) + 4);
            t21 = *(ts4_word *)((char *)(ts4_word)(t18) + 8);
            loc58[0] = (ts4_word)t19;
            loc58[1] = (ts4_word)t20;
            loc58[2] = (ts4_word)t21;
            p22 = (ts4_word)t20;
            p23 = (ts4_word)t19;
            lv10 = p22;
            lv11 = p23;
        } while (1);
    }
    return 0;
}

/* Swing_DLL.xex 0x8895B6D0: if_call_seq fn_88627EC0, lbl_880C1320, fn_886F7C08, fn_8862C0E8, u32@0x20, u32@0x24 */
ts4_word ts4_if_call_seq_fn_88627EC0_8895B6D0(ts4_word a0, ts4_args3 sp1)
{
    unsigned char b70;
    ts4_word p8;
    ts4_word p11;
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = fn_886F7C08(sp1, (ts4_word)((2506162176) | 21586), (ts4_word)(ts4_word)lbl_880C1320);
    t4 = fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)t3);
    t5 = loc50[0];
    t6 = loc50[1];
    b70 = !((ts4_word)t5 != 0) || ((ts4_word)t6 == (ts4_word)((983040) | 65535));
    p8 = (ts4_word)b70;
    p11 = (ts4_word)t4;
    if ((ts4_word)(p8 & 0xff) == 0) {
        t9 = loc50[2];
        *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t5;
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t6;
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t9;
        t10 = fn_88923530((ts4_word)t9, *(ts4_args3 *)&loc50[0], (ts4_word)((3134980096) | 59410));
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t10;
        p11 = (ts4_word)t10;
    }
    return p11;
}
