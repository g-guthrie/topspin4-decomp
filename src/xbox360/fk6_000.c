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
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;
#include "ts4_vector.h"

extern char lbl_88001A20[];
extern char lbl_88086F5C[];
extern char lbl_88086F6C[];
extern char lbl_880C1320[];
extern char lbl_880C8FA7[];
extern char lbl_880DC520[];
extern char lbl_880DCF18[];
extern char lbl_880DFEDC[];
extern char lbl_880E39F0[];
extern char lbl_880F1D38[];
extern char lbl_880F216C[];
extern char lbl_880F2190[];
extern char lbl_880F285C[];
extern char lbl_8814B440[];
extern char lbl_88C6C014[];
extern char lbl_88C6C058[];
extern char lbl_88C6C21C[];
extern char lbl_88C6C220[];
extern char lbl_88C6E1A8[];
extern char lbl_88D26F84[];
extern char lbl_88D3E3B4[];
extern char lbl_88D459E8[];
extern char lbl_88D45A60[];
extern char lbl_88D45AE0[];
extern char lbl_88D45B30[];
extern char lbl_88D48848[];
extern char lbl_88D4BD54[];
extern char lbl_88D4BFE4[];
extern char ts4_get_u32_lbl_88D4BD54_88AFF040[];
ts4_word KeTlsSetValue();
ts4_word fn_8816D1A8();
ts4_word fn_881898E8();
ts4_word fn_88198D48();
ts4_word fn_8822BF98();
ts4_word fn_88423730();
ts4_word fn_88475E20();
ts4_word fn_8852CD50();
ts4_word fn_88531FF8();
ts4_word fn_88563470();
ts4_word fn_88580EB8();
ts4_word fn_885B4B80();
ts4_word fn_885B4CE8();
ts4_word ts4_crc32_cstr_seed_88608590();
ts4_word ts4_handle_fwd_slot6c_8860A988();
ts4_word fn_8860F6A0();
ts4_word fn_88617D88();
ts4_word fn_88625478();
ts4_word fn_886290B0();
ts4_word fn_8862BF38();
ts4_word fn_887CFAC0();
ts4_word fn_887F0CA0();
ts4_word fn_88864D78();
ts4_word ts4_format_save_path_entry_88867E68();
ts4_word fn_88886548();
ts4_word fn_88923530();
ts4_word fn_8892EE88();
ts4_word fn_88933EF8();
ts4_word fn_8899BE28();
ts4_word fn_889D01F8();
ts4_word fn_889D0270();
ts4_word fn_889D02D8();
ts4_word ts4_call_seq_lbl_880F2148_88736F30();
ts4_word ts4_clone_byte_with_object_context();
ts4_word ts4_create_object_8818A190();
ts4_word ts4_dtor_set_vtable_base_destroy_field4_88188868();
ts4_word ts4_find_record_by_key_881ACD38();
ts4_word ts4_find_service();
ts4_word ts4_fn_885CD2B8();
ts4_word ts4_forward_varargs_8856A2E0(ts4_word, ts4_word, ...);
ts4_word ts4_get_u32_lbl_88D4E11C_88581A90();
ts4_word ts4_get_u32_off0_8816CD98();
ts4_word ts4_get_u32_off0_8822AFE8();
ts4_word ts4_get_u32_off4_885B5160();
ts4_word ts4_handle_forward0_88610B48();
ts4_word ts4_handle_forward_88150770();
ts4_word ts4_handle_forward_88610520();
ts4_word ts4_handle_forward_886105A0();
ts4_word ts4_handle_forward_88610A48();
ts4_word ts4_if_call_seq_fn_8892EE88_8817F5E0();
ts4_word ts4_if_call_seq_fn_8892EE88_8822CB68();
ts4_word ts4_if_call_seq_fn_88933EF8_889396A8();
ts4_word ts4_init_range_and_run_service_88164ED0();
ts4_word ts4_is_id_165_to_167_885CD310();
ts4_word ts4_object_finalize();
ts4_word ts4_set_u32_off0_889D18A0();

/* Swing_DLL.xex 0x8818A0F8: if_call_seq u32@lbl_88D3E3B4, u32@lbl_88D4BFE4, u32@lbl_88D4BFE4, u32@lbl_88D4BD54, u32@lbl_88D4BFE4, ts4_find_service */
ts4_word ts4_if_call_seq_u32_lbl_88D3E3B4_8818A0F8(void)
{
    ts4_word p13;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t12;

    t1 = *(ts4_word *)lbl_88D3E3B4;
    p13 = (ts4_word)t1;
    if (0 == (ts4_word)t1) {
        t3 = *(ts4_word *)lbl_88D4BFE4;
        if ((ts4_word)(t3 & 0x1) == 0) {
            *(ts4_word *)lbl_88D4BFE4 = (ts4_word)(t3 | 1);
            *(ts4_word *)lbl_88D4BD54 = (ts4_word)(t3 & 0x1);
            t4 = ts4_find_service((ts4_word)((165347328) | 1352));
            if ((ts4_word)t4 != 0) {
                t5 = ts4_create_object_8818A190((ts4_word)t4);
                *(ts4_word *)lbl_88D4BD54 = (ts4_word)t5;
                fn_88198D48((ts4_word)t5, (ts4_word)(ts4_word)lbl_880DCF18, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t4) + 36)), (ts4_word)18);
                *(ts4_word *)(128 + (char *)(ts4_word)((*(ts4_word *)lbl_88D4BD54))) = (ts4_word)t4;
            }
            fn_88563470((ts4_word)(ts4_word)ts4_get_u32_lbl_88D4BD54_88AFF040);
        }
        t12 = *(ts4_word *)lbl_88D4BD54;
        *(ts4_word *)lbl_88D3E3B4 = (ts4_word)t12;
        p13 = (ts4_word)t12;
    }
    return p13;
}

/* Swing_DLL.xex 0x88389CD8: if_get u32@0x16c, u32@0x168, u32@0x118, u32@0x11c, u8@0x0 */
ts4_word ts4_if_get_u32_off16c_88389CD8(ts4_word a0, ts4_word a1)
{
    unsigned char b80;
    ts4_word p6;
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 364);
    b80 = (unsigned char)(!((ts4_word)t1 != 0 && (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 360)) >= (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 280))) || ((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 284)) & 0x8) != 0));
    p6 = (ts4_word)b80;
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)p6;
    return 0;
}

/* Swing_DLL.xex 0x883AD058: if_get u32@0x24, u8@0x0 */
ts4_word ts4_if_get_u32_off24_883AD058(ts4_word a0, ts4_word a1)
{
    unsigned char b80;
    ts4_word p3;
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return 37;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    b80 = (unsigned char)(!((ts4_word)(t1 & 0x40) == 0) || ((ts4_word)(t1 & 0x10) != 0));
    p3 = (ts4_word)b80;
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)p3;
    return 0;
}

/* Swing_DLL.xex 0x88428690: if_call_seq fn_88423730, u32@0x10, u8@0x0, u32@0x8, u32@0x0, u8@0x0 */
ts4_word ts4_if_call_seq_fn_88423730_88428690(ts4_word a0, ts4_word a1, int a2, ts4_word a3)
{
    ts4_word h1;
    ts4_word t104;
    int t1;
    ts4_word t3;
    ts4_word t4;

    h1 = (ts4_word)(a1 + 8);
    t1 = fn_88423730((ts4_word)h1, (ts4_word)a2);
    if ((int)t1 <= (int)(*(volatile ts4_word *)((char *)(ts4_word)(a1) + 16))) {
        t3 = *(volatile ts4_word *)((char *)(ts4_word)(h1) + 8);
        t4 = *(volatile ts4_word *)((char *)(ts4_word)(h1) + 0);
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)1;
        t104 = (*(volatile ts4_word *)(t4 + (char *)(ts4_word)(((1 + (t3 + t1)) << 2))));
        *(volatile ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)t104;
        return a0;
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88454C10: if_call_seq u32@0x8, fn_88531FF8, u8@0x84, u32@0x0, u32@0x4, u32@0x8 */
void ts4_if_call_seq_u32_off8_88454C10(ts4_word a0, ts4_word a1)
{
    ts4_word h1;
    h1 = (ts4_word)(a0 + 48);
    fn_88531FF8((ts4_word)h1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8)), (ts4_word)a1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 132) = (unsigned char)0;
    if ((ts4_word)h1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(h1) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(h1) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(h1) + 8) = (ts4_word)(2147483648);
    }
    fn_8852CD50((ts4_word)h1);
    *(unsigned short *)((char *)(ts4_word)(a0) + 134) = (unsigned short)25;
    *(float *)((char *)(ts4_word)(a0) + 60) = (*(float *)lbl_88001A20);
    return;
}

/* Swing_DLL.xex 0x884774D0: if_get fn_88475E20, u32@0x88, u32@0x0, u32@0x84, u32@0x80, lbl_88086F6C */
void ts4_if_get_fn_88475E20_884774D0(ts4_word a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;

    fn_88475E20((ts4_word)a0, (ts4_word)a1);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 136);
    if ((int)(t2 & 0x80000000) == 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 132);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t3) + 8))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88086F6C, (ts4_word)4, (ts4_word)t5, (ts4_word)(t4 << 2), (ts4_word)(t2 << 2));
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    if ((int)(t9 & 0x80000000) == 0) {
        t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t11 = *(ts4_word *)((char *)(ts4_word)(a0) + 144);
        t12 = *(ts4_word *)((char *)(ts4_word)(a0) + 140);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t10) + 8))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88086F5C, (ts4_word)4, (ts4_word)t12, (ts4_word)(t11 << 2), (ts4_word)(t9 << 2));
    }
    return;
}

/* Swing_DLL.xex 0x884D3C08: get u32@0x0, u32@lbl_88D26F84, u32@0x0, u32@0xc, vcall, u32@0x10 */
void ts4_get_u32_off0_884D3C08(int a0, ts4_word a1)
{
    ts4_word t202;
    ts4_word t102;
    ts4_word t2;

    t2 = *(ts4_word *)lbl_88D26F84;
    t202 = (*(ts4_word *)(0 + (char *)(ts4_word)(t2)));
    t102 = t202;
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 16))))((ts4_word)a0, (ts4_word)a1, (ts4_word)(((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((t102)) + 12))))((ts4_word)t2)));
    return;
}

/* Swing_DLL.xex 0x885B5058: if_call_seq ts4_get_u32_off4_885B5160, fn_885B4B80, u16@0x0, ts4_is_id_165_to_167_885CD310, u16@0x0, ts4_fn_885CD2B8 */
ts4_word ts4_if_call_seq_fn_885B5160_885B5058(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[8];
    int t2;
    ts4_word t4;

    ts4_get_u32_off4_885B5160((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_885B4B80((ts4_word)a0, (ts4_word)a1);
    if ((ts4_word)t2 == 0) {
        return t2;
    }
    t4 = ts4_is_id_165_to_167_885CD310((ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 0)));
    return (fn_885B4CE8((ts4_word)(ts4_fn_885CD2B8((ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 0)))), (ts4_word)t4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)t2, (ts4_word)a2));
}

/* Swing_DLL.xex 0x885ECFF0: if_get u8@0xc, u8@0xd, u8@0xd, u8@0xc, u16@0x10, u16@0x10 */
void ts4_if_get_u8_offc_885ECFF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    unsigned char t2;
    unsigned char t8;
    unsigned short t9;
    unsigned short t14;
    unsigned short t19;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 == 19) {
        t2 = *(volatile unsigned char *)((char *)(ts4_word)(a0) + 13);
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)0;
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)t2;
        *(volatile unsigned short *)((char *)(ts4_word)(a0) + 16) |= 1024;
    }
    t8 = *(volatile unsigned char *)(12 + (char *)(ts4_word)(a0));
    if ((ts4_word)t8 != 24 && (ts4_word)t8 != 31) {
        return;
    }
    t9 = *(volatile unsigned short *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)(t9 & 0x8) != 0) {
        *(volatile unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)4;
        *(volatile unsigned short *)((char *)(ts4_word)(a0) + 16) = (unsigned short)(((*(volatile unsigned short *)((char *)(ts4_word)(a0) + 16)) & 0xffff) & 0xfffffff7);
    }
    t14 = *(volatile unsigned short *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)(t14 & 0x10) != 0) {
        *(volatile unsigned char *)(13 + (char *)(ts4_word)(a0)) = (unsigned char)6;
        *(volatile unsigned short *)((char *)(ts4_word)(a0) + 16) = (unsigned short)(((*(volatile unsigned short *)((char *)(ts4_word)(a0) + 16)) & 0xffff) & 0xffffffef);
    }
    t19 = *(volatile unsigned short *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)(t19 & 0x20) == 0) {
        return;
    }
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)8;
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 16) = (unsigned short)(((*(volatile unsigned short *)((char *)(ts4_word)(a0) + 16)) & 0xffff) & 0xffffffdf);
    return;
}

/* Swing_DLL.xex 0x8862BE08: if_set u32@0x0, u32@0x8, u32@0x4, fn_8860F6A0, u32@0x0, u32@0x30 */
ts4_word ts4_if_set_u32_off0_8862BE08(int a0, ts4_word a1)
{
    ts4_word t317;
    ts4_word t217;
    ts4_word t117;
    ts4_word loc70[128];
    ts4_word loc270[1034];
    ts4_word loc50[4];
    ts4_word loc60[4];
    ts4_word t1;
    ts4_word t4;
    unsigned char t7;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    t1 = fn_8860F6A0((ts4_word)a1, (ts4_word)(ts4_word)&loc70[0]);
    if ((ts4_word)t1 != 0) {
        t217 = (*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0));
        t117 = t217;
        t4 = ((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(t117) + 48))))((ts4_word)t1);
        if ((ts4_word)(t4 & 0xff) != 0) {
            fn_886290B0((ts4_word)(ts4_word)&loc270[0]);
            loc270[0] = (ts4_word)(ts4_word)lbl_880DC520;
            fn_88625478((ts4_word)(ts4_word)&loc270[0], (ts4_word)(ts4_word)&loc70[0]);
            t7 = *(volatile unsigned char *)((char *)loc270 + 4128);
            if ((ts4_word)t7 != 0) {
                t317 = (*(volatile ts4_word *)((char *)(ts4_word)(t1) + 0));
                t11 = ts4_handle_forward_88610520((ts4_word)(ts4_word)&loc50[0], (ts4_word)(((ts4_word (*)(ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(t317) + 40))))((ts4_word)(ts4_word)&loc60[0], (ts4_word)t1)), (ts4_word)(ts4_word)&loc270[0]);
                t12 = *(volatile ts4_word *)((char *)(ts4_word)(t11) + 0);
                t13 = *(volatile ts4_word *)((char *)(ts4_word)(t11) + 4);
                t14 = *(ts4_word *)((char *)(ts4_word)(t11) + 8);
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t12;
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t13;
                *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t14;
            }
            ts4_dtor_set_vtable_base_destroy_field4_88188868((ts4_word)(ts4_word)&loc270[0]);
        }
    }
    return a0;
}

/* Swing_DLL.xex 0x8862C0E8: if_set u32@0x0, u32@0x8, u32@0x4, fn_8860F6A0, u32@0x0, u32@0x30 */
ts4_word ts4_if_set_u32_off0_8862C0E8(ts4_word a0, ts4_word a1)
{
    ts4_word loc70[256];
    ts4_word loc470[1034];
    ts4_word loc60[4];
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t13;

    *(ts4_word *)(0 + (char *)(ts4_word)(a0)) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    t1 = fn_8860F6A0((ts4_word)a1, (ts4_word)(ts4_word)&loc70[0]);
    if ((ts4_word)t1 != 0) {
        if ((ts4_word)((((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 48))))((ts4_word)t1)) & 0xff) != 0) {
            fn_886290B0((ts4_word)(ts4_word)&loc470[0]);
            loc470[0] = (ts4_word)(ts4_word)lbl_880DC520;
            fn_88625478((ts4_word)(ts4_word)&loc470[0], (ts4_word)(ts4_word)&loc70[0]);
            t10 = ts4_handle_forward_886105A0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)(ts4_word)&loc60[0], (ts4_word)t1)), (ts4_word)(ts4_word)&loc470[0]);
            t11 = *(ts4_word *)((char *)(ts4_word)(t10) + 0);
            t12 = *(ts4_word *)((char *)(ts4_word)(t10) + 4);
            t13 = *(ts4_word *)((char *)(ts4_word)(t10) + 8);
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t11;
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t12;
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t13;
            ts4_dtor_set_vtable_base_destroy_field4_88188868((ts4_word)(ts4_word)&loc470[0], (ts4_word)t13, (ts4_word)t12, (ts4_word)t11, (ts4_word)t10);
        }
    }
    return a0;
}

/* Swing_DLL.xex 0x8864E850: fn  */
void ts4_fn_8864E850(ts4_word a0)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv6;

    vv1 = __vspltisw(0);
    vv2 = __vupkd3d(vv1, 1);
    vv3 = __vpermwi(vv2, 234);
    vv4 = __vpermwi(vv2, 186);
    vv5 = __vpermwi(vv2, 174);
    vv6 = __vpermwi(vv2, 171);
    *(__vector4 *)((ts4_word)(a0)) = vv3;
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv4;
    *(__vector4 *)((ts4_word)(a0 + 32)) = vv5;
    *(__vector4 *)((ts4_word)(a0 + 48)) = vv6;
    return;
}

/* Swing_DLL.xex 0x8864F0B0: fn  */
void ts4_fn_8864F0B0(int a0)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv6;

    vv1 = __vspltisw(0);
    vv2 = __vupkd3d(vv1, 1);
    vv3 = __vpermwi(vv2, 234);
    vv4 = __vpermwi(vv2, 186);
    vv5 = __vpermwi(vv2, 174);
    vv6 = __vpermwi(vv2, 171);
    *(__vector4 *)((ts4_word)(a0)) = vv3;
    *(__vector4 *)((ts4_word)(a0 + 16)) = vv4;
    *(volatile __vector4 *)((ts4_word)(a0 + 32)) = vv5;
    *(__vector4 *)((ts4_word)(a0 + 48)) = vv6;
    return;
}

/* Swing_DLL.xex 0x8865FE20: loop_get u32@0x10, u32@0x14, u8@0x89, u32@0x10, u32@0x14, u32@0x14 */
void ts4_loop_get_u32_off10_8865FE20(ts4_word a0)
{
    ts4_word lv3;
    ts4_word t1;
    ts4_word p7;
    int t2;
    unsigned char t4;
    ts4_word t5;

    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t1 >= (ts4_word)(t1 + t2)) {
        return;
    }
    lv3 = (ts4_word)t1;
    do {
        t4 = *(unsigned char *)(137 + (char *)(ts4_word)(((((((ts4_word)lv3 % 20) << 1) + ((ts4_word)lv3 % 20)) << 4) + a0)));
        if (t4) {
            return;
        }
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(((*(ts4_word *)((char *)(ts4_word)(a0) + 20))) + -1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((int)(t5 + 1) % 20);
        p7 = (ts4_word)(lv3 + 1);
        lv3 = p7;
    } while ((ts4_word)p7 < (ts4_word)(t1 + t2));
    return;
}

/* Swing_DLL.xex 0x886688A8: if_get u32@0x20, u8@0xd7, u8@0x99, u8@0x99, u32@0xd0, u32@0xd0 */
void ts4_if_get_u32_off20_886688A8(ts4_word a0)
{
    ts4_word t1;
    unsigned char t2;
    unsigned char t4;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 215);
    if (0 != (ts4_word)t2) {
        return;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(t1) + 153);
    if (0 != (ts4_word)t4) {
        return;
    }
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 208);
    if ((ts4_word)t6 == (ts4_word)((3374514176) | 34673)) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 40))) + 72) += 1;
    return;
}

/* Swing_DLL.xex 0x8866DE40: loop_get u32@0x98, u32@0x94, u32@0x0, u32@0x8, u32@0xc, u32@0x8 */
void ts4_loop_get_u32_off98_8866DE40(ts4_word a0, ts4_word a1)
{
    ts4_word lv4;
    ts4_word p17;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t7;
    ts4_word t9;
    int t11;
    ts4_word t21;
    ts4_word t22;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 152);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 148);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv4 = (ts4_word)t2;
        do {
            t7 = *(ts4_word *)((char *)(ts4_word)(lv4) + 8);
            if ((ts4_word)t7 == (ts4_word)t3) {
                t9 = *(ts4_word *)((char *)(ts4_word)(lv4) + 12);
                if ((ts4_word)t9 == 0) {
                    break;
                }
                t11 = *(ts4_word *)((char *)(ts4_word)(lv4) + 4);
                if ((int)t11 == 0) {
                    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 48))))((ts4_word)t9);
                }
                *(ts4_word *)((char *)(ts4_word)(lv4) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(lv4) + 4)) + 1);
                break;
            }
            p17 = (ts4_word)(lv4 + 16);
            lv4 = p17;
        } while ((ts4_word)p17 != (ts4_word)t1);
    }
    t21 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t21 != (ts4_word)((3301834752) | 61120)) {
        t22 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t22) + 0))) + 36))))((ts4_word)t22, (ts4_word)a1);
    }
    return;
}

/* Swing_DLL.xex 0x886C4E68: fn  */
__vector4 ts4_fn_886C4E68(__vector4 vp1)
{
    __vector4 vv1;
    __vector4 vv2;
    __vector4 vv3;
    __vector4 vv4;
    __vector4 vv5;
    __vector4 vv7;
    __vector4 vv6;
    __vector4 vv8;
    __vector4 vv9;
    __vector4 vv10;
    __vector4 vv11;
    __vector4 vv12;
    __vector4 vv13;
    __vector4 vv14;
    __vector4 vv15;
    __vector4 vv16;
    __vector4 vv17;
    __vector4 vv18;
    __vector4 vv19;
    __vector4 vv20;
    __vector4 vv21;
    __vector4 vv22;
    __vector4 vv23;
    __vector4 vv24;
    __vector4 vv25;

    vv1 = __vspltisw(0);
    vv2 = __vpermwi(vp1, 99);
    vv3 = __vpermwi(vp1, 135);
    vv4 = __vspltisw(1);
    vv5 = __vupkd3d(vv1, 1);
    vv6 = __vcfsx(vv4, 1);
    vv7 = __vpermwi(vv5, 186);
    vv8 = __vpermwi(vv5, 234);
    vv9 = __vpermwi(vv7, 135);
    vv10 = __vpermwi(vv7, 99);
    vv11 = __vmulfp(vv2, vv9);
    vv12 = __vnmsubfp(vv3, vv10, vv11);
    vv13 = __vmsum3fp(vv12, vv12);
    vv14 = __vrsqrtefp(vv13);
    vv15 = __vmulfp(vv6, vv13);
    vv16 = __vcmpeqfp(vv1, vv13);
    vv17 = __vmulfp(vv14, vv14);
    vv18 = __vnmsubfp(vv15, vv17, vv6);
    vv19 = __vmaddfp(vv14, vv18, vv14);
    vv20 = __vmulfp(vv12, vv19);
    vv21 = __vsel(vv20, vv8, vv16);
    vv22 = __vpermwi(vv21, 99);
    vv23 = __vpermwi(vv21, 135);
    vv24 = __vmulfp(vv22, vv3);
    vv25 = __vnmsubfp(vv23, vv2, vv24);
    return vv25;
}

/* Swing_DLL.xex 0x886F01A8: if_get u32@0x68, u8@0x44, u8@0x45, u8@0x46, u8@0x3c */
ts4_word ts4_if_get_u32_off68_886F01A8(ts4_word a0)
{
    unsigned char b80;
    ts4_word p7;
    ts4_word t1;
    unsigned char t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t2 = *(unsigned char *)((char *)(ts4_word)(t1) + 68);
    b80 = !(((ts4_word)t2 == 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t1) + 69)) == 0) && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t1) + 70)) == 0) || ((ts4_word)(*(unsigned char *)((char *)(ts4_word)(t1) + 60)) != 0);
    p7 = (ts4_word)b80;
    return (p7 & 0xff);
}

/* Swing_DLL.xex 0x886FBF18: if_call_seq u32@0x14, u32@0x4, ts4_handle_forward_88150770, ts4_get_u32_off0_8822AFE8, ts4_handle_forward_88150770, lbl_880C8FA7 */
ts4_word ts4_if_call_seq_u32_off14_886FBF18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word h1;
    unsigned char b80;
    ts4_word p5;
    ts4_word p11;
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc54[1];
    int t1;
    ts4_word t7;
    ts4_word t9;
    ts4_word t10;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    h1 = (ts4_word)(a0 + 20);
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    b80 = !((int)t1 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(h1) + 4)) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    p11 = (ts4_word)a0;
    if ((ts4_word)(p5 & 0xff) == 0) {
        loc50[0] = (ts4_word)((938999808) | 59541);
        t7 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)h1, (ts4_word)(ts4_word)&loc50[0]);
        ts4_get_u32_off0_8822AFE8((ts4_word)t7, (ts4_word)a1);
        loc54[0] = (ts4_word)((23920640) | 45776);
        t9 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)h1, (ts4_word)(ts4_word)&loc54[0]);
        t10 = ts4_clone_byte_with_object_context((ts4_word)t9, (ts4_word)(ts4_word)lbl_880C8FA7);
        p11 = (ts4_word)t10;
    }
    return p11;
}

/* Swing_DLL.xex 0x88708770: if_addr ts4_crc32_cstr_seed_88608590, ts4_handle_forward_88610A48, lbl_880F1D38, ts4_forward_varargs_8856A2E0, ts4_handle_forward_88150770, ts4_handle_forward_88150770 */
ts4_word ts4_if_addr_fn_88608590_88708770(ts4_args3 sp0, ts4_word a2, ts4_word a3)
{
    int b80;
    ts4_word t134;
    ts4_word p6;
    ts4_word p35;
    ts4_word loc50[1];
    ts4_word loc88[3];
    ts4_word loc80[2];
    ts4_word loc7c[1];
    ts4_word loc78[1];
    ts4_word loc54[1];
    ts4_word loc98[3];
    ts4_word loc60[1];
    ts4_word loca8[3];
    ts4_word loc5c[1];
    ts4_word locb8[3];
    ts4_word loc58[1];
    ts4_word loc64[1];
    ts4_word loc68[1];
    ts4_word loc6c[1];
    ts4_word locc8[3];
    ts4_word loc70[1];
    ts4_word locd8[3];
    ts4_word loc74[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t12;
    ts4_word t11;
    int t15;
    ts4_word t19;
    ts4_word t20;
    ts4_word t21;
    ts4_word t22;
    ts4_word t23;
    ts4_word t24;
    ts4_word t25;
    ts4_word t26;
    ts4_word t27;
    ts4_word t28;
    ts4_word t29;
    ts4_word t30;
    ts4_word t34;

    t1 = ts4_crc32_cstr_seed_88608590((ts4_word)0, (ts4_word)a3);
    loc50[0] = (ts4_word)t1;
    t2 = ts4_handle_forward_88610A48((ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t3 = loc88[0];
    b80 = !((ts4_word)t3 != 0) || ((ts4_word)(loc88[1]) == (ts4_word)((983040) | 65535));
    p6 = (ts4_word)b80;
    p35 = (ts4_word)t2;
    if ((ts4_word)(p6 & 0xff) == 0) {
        ts4_forward_varargs_8856A2E0((ts4_word)a2, (ts4_word)(ts4_word)lbl_880F1D38, (ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc7c[0], (ts4_word)(ts4_word)&loc80[0]);
        loc54[0] = (ts4_word)((3081895936) | 13899);
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc98[0], (ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc54[0]);
        loc58[0] = (ts4_word)((3233087488) | 1757);
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loca8[0], (ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc58[0]);
        loc5c[0] = (ts4_word)((1505492992) | 22375);
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&locb8[0], (ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc5c[0]);
        t11 = loc98[0];
        t12 = loc98[1];
        t134 = (*(volatile ts4_word *)((char *)(ts4_word)(t11) + 0));
        t15 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(t134) + 68))))((ts4_word)t11, (ts4_word)(ts4_word)&loc98[0], (ts4_word)t12);
        if ((int)t15 == 4) {
            loc60[0] = (ts4_word)((3081895936) | 13899);
            ts4_handle_fwd_slot6c_8860A988((ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc60[0]);
            loc64[0] = (ts4_word)((3233087488) | 1757);
            ts4_handle_fwd_slot6c_8860A988((ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc64[0]);
            loc68[0] = (ts4_word)((1505492992) | 22375);
            ts4_handle_fwd_slot6c_8860A988((ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc68[0]);
            loc6c[0] = (ts4_word)((3081895936) | 13899);
            t19 = ts4_init_range_and_run_service_88164ED0((ts4_word)(ts4_word)&locc8[0], (ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc6c[0]);
            t20 = *(volatile ts4_word *)((char *)(ts4_word)(t19) + 0);
            t21 = *(volatile ts4_word *)((char *)(ts4_word)(t19) + 4);
            t22 = *(volatile ts4_word *)((char *)(ts4_word)(t19) + 8);
            loc70[0] = (ts4_word)((3233087488) | 1757);
            loc98[0] = (ts4_word)t20;
            loc98[1] = (ts4_word)t21;
            loc98[2] = (ts4_word)t22;
            t23 = ts4_init_range_and_run_service_88164ED0((ts4_word)(ts4_word)&locd8[0], (ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc70[0]);
            t24 = *(volatile ts4_word *)((char *)(ts4_word)(t23) + 0);
            t25 = *(volatile ts4_word *)((char *)(ts4_word)(t23) + 4);
            t26 = *(ts4_word *)((char *)(ts4_word)(t23) + 8);
            loc74[0] = (ts4_word)((1505492992) | 22375);
            loca8[0] = (ts4_word)t24;
            loca8[1] = (ts4_word)t25;
            loca8[2] = (ts4_word)t26;
            t27 = ts4_init_range_and_run_service_88164ED0((ts4_word)(ts4_word)&locc8[0], (ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc74[0], (ts4_word)t24, (ts4_word)t23);
            t28 = *(volatile ts4_word *)((char *)(ts4_word)(t27) + 0);
            t29 = *(volatile ts4_word *)((char *)(ts4_word)(t27) + 4);
            t30 = *(volatile ts4_word *)((char *)(ts4_word)(t27) + 8);
            locb8[0] = (ts4_word)t28;
            locb8[1] = (ts4_word)t29;
            locb8[2] = (ts4_word)t30;
        }
        ts4_get_u32_off0_8816CD98((ts4_word)(ts4_word)&loc98[0], (ts4_word)(ts4_word)&loc78[0]);
        ts4_get_u32_off0_8816CD98((ts4_word)(ts4_word)&loca8[0], (ts4_word)(ts4_word)&loc7c[0]);
        t34 = ts4_get_u32_off0_8816CD98((ts4_word)(ts4_word)&locb8[0], (ts4_word)(ts4_word)&loc80[0]);
        p35 = (ts4_word)t34;
    }
    return p35;
}

/* Swing_DLL.xex 0x8871FFB0: call_seq fn_88617D88, lbl_880F285C, u32@0x0, u32@0x1c, u32@0x24, u32@0x20 */
ts4_word ts4_call_seq_fn_88617D88_8871FFB0(ts4_word a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)(0 + (char *)(ts4_word)(a0)) = (ts4_word)(ts4_word)lbl_880F285C;
    *(volatile ts4_word *)(28 + (char *)(ts4_word)(a0)) = (ts4_word)0;
    *(ts4_word *)(32 + (char *)(ts4_word)(a0)) = (ts4_word)((983040) | 65535);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    fn_8816D1A8((ts4_word)(a0 + 40));
    *(volatile ts4_word *)lbl_88D45AE0 = (ts4_word)a0;
    return a0;
}

/* Swing_DLL.xex 0x887464A8: call_seq ts4_call_seq_lbl_880F2148_88736F30, lbl_880F2190, u32@0x0, u32@0x14, u32@0x1c, u32@0x18 */
ts4_word ts4_call_seq_ts4_call_seq_lbl_880F2148_88736F30_887464A8(ts4_word a0)
{
    ts4_call_seq_lbl_880F2148_88736F30((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2190;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)((983040) | 65535);
    return a0;
}

/* Swing_DLL.xex 0x88746500: call_seq ts4_call_seq_lbl_880F2148_88736F30, lbl_880F216C, u32@0x0, u32@0x14, u32@0x1c, u32@0x18 */
ts4_word ts4_call_seq_ts4_call_seq_lbl_880F2148_88736F30_88746500(ts4_word a0)
{
    ts4_call_seq_lbl_880F2148_88736F30((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F216C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)(24 + (char *)(ts4_word)(a0)) = (ts4_word)((983040) | 65535);
    return a0;
}

/* Swing_DLL.xex 0x88778D90: if_get u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off0_88778D90(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char b80;
    ts4_word p5;
    int t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    b80 = !((int)t1 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    return ((p5 & 0xff) == 0);
}

/* Swing_DLL.xex 0x8878F8F0: if_call_seq u32@0x0, u32@0x8, u32@0x4, lbl_880C1320, fn_8822BF98, u32@lbl_88D45A60 */
ts4_word ts4_if_call_seq_u32_off0_8878F8F0(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[4];
    ts4_word loc60[6];
    ts4_word t1;
    ts4_word t7;
    ts4_word t9;

    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    t1 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)a1);
    if ((ts4_word)(t1 & 0xff) == 0) {
        ts4_handle_forward0_88610B48((ts4_word)(ts4_word)&loc60[0], (ts4_word)((*(volatile ts4_word *)lbl_88D45A60) + 708));
        (void)loc60[2];
        fn_8862BF38((ts4_word)(ts4_word)&loc50[0], *(volatile ts4_args3 *)&loc60[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)));
        t7 = loc50[0];
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t7;
        t9 = loc50[2];
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(loc50[1]);
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t9;
    }
    return a0;
}

/* Swing_DLL.xex 0x887D3BB0: loop_get ts4_object_finalize, fn_887CFAC0, u32@lbl_88C6C220, u32@lbl_88C6C21C, u32@0x0, u32@0x4 */
ts4_word ts4_loop_get_ts4_object_finalize_887D3BB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word p7;
    ts4_word lv10;
    ts4_word p18;
    ts4_word p21;
    ts4_word loc58[3];
    ts4_word loc50[2];
    float t3;
    float t4;
    ts4_word t8;
    ts4_word t9;
    ts4_word t11;
    ts4_word t12;
    ts4_word t14;
    float t15;
    ts4_word t24;

    ts4_object_finalize((ts4_word)a0);
    fn_887CFAC0((ts4_word)(ts4_word)&loc58[0], (ts4_word)a2, (ts4_word)0);
    t3 = *(float *)((char *)loc58 + 0);
    t4 = *(float *)lbl_8814B440;
    if (!(t3 < t4)) {
        p7 = (ts4_word)(*(ts4_word *)lbl_88C6C21C);
    } else {
        p7 = (ts4_word)(*(ts4_word *)lbl_88C6C220);
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    lv10 = (ts4_word)t8;
    t9 = *(ts4_word *)(4 + (char *)(ts4_word)(a1));
    while ((ts4_word)lv10 != (ts4_word)t9) {
        t11 = *(volatile ts4_word *)((char *)(ts4_word)(lv10) + 0);
        t12 = *(ts4_word *)((char *)(ts4_word)(t11) + 0);
        loc50[0] = (ts4_word)t11;
        t14 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t12) + 64))))((ts4_word)t11);
        t15 = *(volatile float *)((char *)(ts4_word)(t14) + 0);
        if (!(t15 < t4)) {
            p18 = (ts4_word)(*(ts4_word *)lbl_88C6C21C);
        } else {
            p18 = (ts4_word)(*(ts4_word *)lbl_88C6C220);
        }
        if ((ts4_word)p7 == (ts4_word)p18) {
            fn_881898E8((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
        }
        p21 = (ts4_word)(lv10 + 4);
        lv10 = p21;
    }
    t24 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((int)(t24 - (*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0))) >> 2);
}

/* Swing_DLL.xex 0x887F1CC0: get u32@0x0, lbl_88C6C014, fn_887F0CA0, u32@0x44, vcall */
ts4_word ts4_get_u32_off0_887F1CC0(int a0)
{

    return (((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 68))))((ts4_word)a0, (ts4_word)(fn_887F0CA0((ts4_word)a0, (ts4_word)(ts4_word)lbl_88C6C014)), (ts4_word)1));
}

/* Swing_DLL.xex 0x88800BF8: call_seq fn_88617D88, lbl_880E39F0, u32@0x0, u32@0x1c, u32@0x24, u32@0x20 */
ts4_word ts4_call_seq_fn_88617D88_88800BF8(int a0)
{
    fn_88617D88((ts4_word)a0);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E39F0;
    *(volatile ts4_word *)(28 + (char *)(ts4_word)(a0)) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)((983040) | 65535);
    *(volatile unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88836378: if_get u32@0x8, u32@0x10, u32@0x14, u32@0x10, u32@0x10 */
ts4_word ts4_if_get_u32_off8_88836378(ts4_word a0)
{
    unsigned char b80;
    ts4_word p5;
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    if ((int)t1 != 4 && (int)t1 != 9) {
        b80 = !((int)t1 != 7) || ((int)t1 == 2);
        p5 = (ts4_word)b80;
        if ((ts4_word)(p5 & 0xff) != 0) {
            return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 16));
        }
        return 0;
    }
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 16))) + 20));
}

/* Swing_DLL.xex 0x88840AF8: if_call_seq u32@lbl_88D459E8, u32@0x24, ts4_find_record_by_key_881ACD38, u32@0x4, u32@0xd1c, u32@0xd00 */
ts4_word ts4_if_call_seq_u32_lbl_88D459E8_88840AF8(ts4_word a0)
{
    ts4_word p7;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D459E8)) + 36);
    t3 = ts4_find_record_by_key_881ACD38((ts4_word)(t2 + 3316), (ts4_word)(ts4_word)&a0);
    t4 = *(volatile ts4_word *)((char *)(ts4_word)(t3) + 4);
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 3356);
    p7 = (ts4_word)(t4 - t5);
    if ((int)(t4 - t5) < 0) {
        p7 = (ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 3328)) + (t4 - t5));
    }
    return p7;
}

/* Swing_DLL.xex 0x888680A0: loop_call_seq u32@lbl_88D45B30, u32@0x20, u32@0x1c, u32@0x0, u32@0x4, u32@0x0 */
void ts4_loop_call_seq_u32_lbl_88D45B30_888680A0(ts4_word a0, ts4_word a1)
{
    ts4_word lv4;
    ts4_word p13;
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;

    t1 = *(ts4_word *)lbl_88D45B30;
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 32);
    lv4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 28));
    while ((ts4_word)t2 != (ts4_word)lv4) {
        t7 = *(ts4_word *)((char *)(ts4_word)(lv4) + 0);
        if ((ts4_word)a1 == (ts4_word)t7) {
            t9 = *(ts4_word *)((char *)(ts4_word)(lv4) + 4);
            if ((ts4_word)t9 == 0) {
                break;
            }
            t10 = fn_88886548((ts4_word)t9, (ts4_word)((347537408) | 24449));
            t11 = fn_88864D78((ts4_word)(t10 + 4));
            ts4_format_save_path_entry_88867E68((ts4_word)a1, (ts4_word)t11, (ts4_word)a0, (ts4_word)512, (ts4_word)(ts4_word)lbl_880DFEDC);
            break;
        }
        p13 = (ts4_word)(lv4 + 8);
        lv4 = p13;
    }
    return;
}

/* Swing_DLL.xex 0x88932988: if_get u8@0x24, u8@0x27, u32@0x1c, u8@0x25 */
ts4_word ts4_if_get_u8_off24_88932988(ts4_word a0)
{
    ts4_word p3;
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 36);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)-1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 39) = (unsigned char)1;
    p3 = (ts4_word)1;
    if ((ts4_word)t1 == 0 || (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 37)) == 0) {
        p3 = (ts4_word)0;
    }
    return (p3 & 0xff);
}

/* Swing_DLL.xex 0x8893CA30: if_call_seq fn_88933EF8, ts4_if_call_seq_fn_88933EF8_889396A8, ts4_if_call_seq_fn_88933EF8_889396A8 */
ts4_word ts4_if_call_seq_fn_88933EF8_8893CA30(ts4_word a0, ts4_u64 a1)
{
    ts4_word t1;

    t1 = fn_88933EF8((ts4_word)a0, (ts4_word)64);
    if ((ts4_word)(t1 & 0xff) != 0) {
        ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a0, (ts4_word)((ts4_u64)a1 >> 32));
        ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a0, (ts4_word)(ts4_word)a1);
    }
    return a0;
}

/* Swing_DLL.xex 0x88948018: if_call_seq ts4_crc32_cstr_seed_88608590, ts4_handle_forward_88150770, ts4_get_u32_off0_8816CD98 */
void ts4_if_call_seq_fn_88608590_88948018(ts4_args3 sp0, ts4_word a2, float f1)
{
    unsigned char b81;
    unsigned char b80;
    ts4_word p4;
    ts4_word p10;
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t5;
    ts4_word t7;

    t1 = sp0.w[0];
    b80 = (unsigned char)(!(0 != (ts4_word)t1) || ((ts4_word)(sp0.w[1]) == (ts4_word)((983040) | 65535)));
    p4 = (ts4_word)b80;
    if ((ts4_word)(p4 & 0xff) == 0) {
        t5 = ts4_crc32_cstr_seed_88608590((ts4_word)0, (ts4_word)a2);
        loc50[0] = (ts4_word)t5;
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
        t7 = loc58[0];
        b81 = (unsigned char)(!((ts4_word)t7 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535)));
        p10 = (ts4_word)b81;
        if ((ts4_word)(p10 & 0xff) == 0) {
            ts4_get_u32_off0_8816CD98((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&f1);
        }
    }
    return;
}

/* Swing_DLL.xex 0x889B8460: call_seq fn_8899BE28, fn_88923530, fn_8892EE88, ts4_if_call_seq_fn_8892EE88_8817F5E0, u32@0x68, ts4_if_call_seq_fn_8892EE88_8822CB68 */
ts4_word ts4_call_seq_fn_8899BE28_889B8460(ts4_word a0, ts4_args3 sp1)
{
    ts4_word loc50[5];
    ts4_word t3;
    ts4_word t6;

    fn_8899BE28((ts4_word)a0, sp1);
    t3 = fn_88923530((ts4_word)(sp1.w[2]), sp1, (ts4_word)((3550412800) | 28037));
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)((983040) | 65535);
    loc50[2] = (ts4_word)0;
    fn_8892EE88((ts4_word)(t3 + 60), *(ts4_args3 *)&loc50[0], (ts4_word)1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)(ts4_if_call_seq_fn_8892EE88_8817F5E0((ts4_word)(t3 + 60), *(ts4_args3 *)&loc50[0]));
    loc50[2] = (ts4_word)0;
    loc50[0] = (ts4_word)0;
    loc50[1] = (ts4_word)((983040) | 65535);
    loc50[2] = (ts4_word)0;
    t6 = ts4_if_call_seq_fn_8892EE88_8822CB68((ts4_word)(t3 + 72), *(ts4_args3 *)&loc50[0]);
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)t6;
    return t6;
}

/* Swing_DLL.xex 0x889BCB80: loop_get u32@0x2e8, u32@0x2e4, u32@0x0, ts4_crc32_cstr_seed_88608590, ts4_handle_forward_88150770, u32@0x0 */
void ts4_loop_get_u32_off2e8_889BCB80(ts4_word a0, ts4_args3 sp1)
{
    ts4_word lv4;
    ts4_word p14;
    ts4_word p16;
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t10;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 744);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 740);
    if ((ts4_word)t2 != (ts4_word)t1) {
        lv4 = (ts4_word)t2;
        do {
            t6 = ts4_crc32_cstr_seed_88608590((ts4_word)0, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(lv4) + 0)));
            p14 = (ts4_word)lv4;
            if ((ts4_word)t6 == (ts4_word)((1401749504) | 2036)) {
                if ((ts4_word)(lv4 + 12) != (ts4_word)t1) {
                    loc50[0] = (ts4_word)((3548250112) | 44178);
                    t7 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
                    t8 = *(volatile ts4_word *)((char *)(ts4_word)(t7) + 0);
                    t9 = *(volatile ts4_word *)(4 + (char *)(ts4_word)(t7));
                    t10 = *(ts4_word *)((char *)(ts4_word)((lv4 + 12)) + 0);
                    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t8) + 0))) + 64))))((ts4_word)t8, (ts4_word)t7, (ts4_word)t9, (ts4_word)t10);
                    return;
                }
                p14 = (ts4_word)(lv4 + 12);
            }
            p16 = (ts4_word)(p14 + 12);
            lv4 = p16;
        } while ((ts4_word)p16 != (ts4_word)t1);
        return;
    }
    return;
}

/* Swing_DLL.xex 0x889C61F8: if_get u32@0x0, u32@0x8, u32@0x0, u8@0x1, u8@0x0, u32@0x8 */
void ts4_if_get_u32_off0_889C61F8(ts4_word a0, int a1)
{
    ts4_word t1;
    int t2;
    int t3;
    unsigned char t4;
    unsigned char t5;

    t2 = *(ts4_word *)(8 + (char *)(ts4_word)(a0));
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((int)t2 >= (int)t3) {
        return;
    }
    t4 = *(volatile unsigned char *)(t2 + (char *)(ts4_word)(t1));
    t5 = *(unsigned char *)((char *)(ts4_word)((t1 + t2)) + 1);
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)t4;
    *(ts4_word *)(8 + (char *)(ts4_word)(a0)) = (ts4_word)(2 + t2);
    *(unsigned char *)((char *)(ts4_word)(a1) + 1) = (unsigned char)t5;
    return;
}

/* Swing_DLL.xex 0x889D14C8: if_call_seq fn_889D01F8, ts4_set_u32_off0_889D18A0, u32@lbl_88C6E1A8, KeTlsSetValue, u32@0x10, u32@0x14 */
void ts4_if_call_seq_fn_889D01F8_889D14C8(ts4_word a0, int a1)
{
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t12;

    loc50[0] = (ts4_word)28;
    t1 = fn_889D01F8((ts4_word)(ts4_word)&loc50[0]);
    t2 = ts4_set_u32_off0_889D18A0((ts4_word)t1, (ts4_word)a1, (ts4_word)0, (ts4_word)a0);
    KeTlsSetValue((ts4_word)(*(ts4_word *)lbl_88C6E1A8), (ts4_word)t2);
    t6 = *(ts4_word *)(20 + (char *)(ts4_word)(a0));
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    fn_889D02D8((ts4_word)(*(ts4_word *)(12 + (char *)(ts4_word)(a0))), (ts4_word)t6, (ts4_word)t5);
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if (t9) {
        fn_889D0270((ts4_word)t9);
    }
    t12 = *(ts4_word *)lbl_88C6E1A8;
    fn_88580EB8((ts4_word)(ts4_get_u32_lbl_88D4E11C_88581A90((ts4_word)(KeTlsSetValue((ts4_word)t12, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 16)))))), (ts4_word)0, (ts4_word)t2);
    return;
}

/* Swing_DLL.xex 0x889D2BD0: addr lbl_88C6C058, lbl_88D48848, u32@lbl_88C6C058, u32@-0x4, u32@0x4, u32@lbl_88D48848 */
void ts4_addr_lbl_88C6C058_889D2BD0(void)
{

    *(ts4_word *)lbl_88D48848 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C6C058) + -4));
    *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D48848) + 4) = (ts4_word)(*(ts4_word *)lbl_88C6C058);
    return;
}
