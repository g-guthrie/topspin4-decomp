#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wmacro-redefined"
#endif
/* Small functions produced by the asm2c translator (FAM4/FAM5 fork) and verified
   byte-for-byte with tools/fn_check.py (Swing_DLL.xex, Xbox 360, MSVC 16.00.10224.00).
   FAM6: FAM5 near misses fixed by a per-function hill climb over source-level
   variants. Besides FAM5's mutations (operand order, retyped locals, volatile
   reloads, statement swaps, if/else inversion, members for `this`), it uses:
   a ||/&& condition kept in an unsigned char/int temporary; compound
   assignment; resized/reordered stack arrays; a load hoisted out of both
   branches or above a store; strlen() instead of an inline byte scan (the
   intrinsic returns through `clrrwi`); a one-word struct argument read from
   memory (also `clrrwi`). Callers and callees sit in different files.
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
typedef struct ts4_sv { ts4_word v; } ts4_sv; /* a one-word struct passed by value */
#ifdef _MSC_VER
#ifdef __cplusplus
extern "C"
#endif
unsigned int strlen(const char *);
#pragma intrinsic(strlen)
#else
#include <string.h>
#endif
typedef struct ts4_args3 { ts4_word w[3]; } ts4_args3;

extern char fn_8845F798[];
extern char fn_88466E80[];
extern char fn_88467030[];
extern char fn_88467F60[];
extern char lbl_880C1320[];
extern char lbl_880C8FA6[];
extern char lbl_880C95B6[];
extern char lbl_880CA837[];
extern char lbl_880CBA06[];
extern char lbl_880D1EE8[];
extern char lbl_880D8234[];
extern char lbl_880D875C[];
extern char lbl_880D90D4[];
extern char lbl_880DAE20[];
extern char lbl_880DAF20[];
extern char lbl_880DC3F0[];
extern char lbl_880DF0EC[];
extern char lbl_880E6D30[];
extern char lbl_880E6DB0[];
extern char lbl_880E6E30[];
extern char lbl_880E6EB8[];
extern char lbl_880ECCC0[];
extern char lbl_880EE9A0[];
extern char lbl_880F0174[];
extern char lbl_880F0184[];
extern char lbl_880F0190[];
extern char lbl_880F019C[];
extern char lbl_880F01AC[];
extern char lbl_880F01C0[];
extern char lbl_880F5A60[];
extern char lbl_8814B440[];
extern char lbl_88C6B4AC[];
extern char lbl_88C6B8EC[];
extern char lbl_88C6C018[];
extern char lbl_88CACF08[];
extern char lbl_88CAD32C[];
extern char lbl_88D2EE2C[];
extern char lbl_88D44040[];
extern char lbl_88D458F0[];
extern char lbl_88D45934[];
extern char lbl_88D45954[];
extern char lbl_88D45964[];
extern char lbl_88D459E0[];
extern char lbl_88D45A60[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B20[];
extern char lbl_88D45B38[];
extern char lbl_88D48828[];
ts4_word KeTlsGetValue();
ts4_word NtWaitForSingleObjectEx();
ts4_word NtWriteFile();
ts4_word NtWriteFileGather();
ts4_word fn_88150600();
ts4_word fn_881643D0();
ts4_word fn_88169350();
ts4_word fn_8816CAA0();
float fn_8816CCE0();
ts4_word fn_8816D1A8();
ts4_word fn_8816D220();
ts4_word fn_881ABB20();
ts4_word fn_881AD260();
ts4_word fn_881B19A0();
ts4_word fn_881B91A0();
ts4_word fn_882160A8();
ts4_word fn_8822BF98();
ts4_word fn_882382A8();
ts4_word fn_8825D858();
ts4_word fn_88421338();
ts4_word fn_88423660();
ts4_word fn_88423730();
ts4_word fn_88423788();
ts4_word fn_88451F18();
ts4_word fn_884D5020();
ts4_word fn_884F0660();
ts4_word fn_884F18D0();
ts4_word fn_885635D0(ts4_word, ts4_word, ...);
ts4_word fn_885646F8();
ts4_word fn_8857A878();
ts4_word fn_8857AFF0();
ts4_word fn_885EB698();
ts4_word fn_88605620();
ts4_word fn_8860A9E0();
ts4_word fn_8860AB08();
ts4_word fn_8860FF08();
ts4_word fn_886115C0();
ts4_word fn_88613350();
ts4_word fn_88614F48();
ts4_word fn_88627EC0();
ts4_word fn_8862BE08();
ts4_word fn_8862C0E8();
ts4_word ts4_loop_get_u32_off48_886ECE38();
ts4_word fn_886F6128();
ts4_word fn_88713970();
ts4_word fn_88722CA8();
ts4_word fn_887316D0();
ts4_word fn_88732788();
ts4_word fn_887552C0();
ts4_word fn_8879CC98();
ts4_word fn_8879CD88();
ts4_word fn_887BA228();
ts4_word fn_887BAB70();
ts4_word fn_887F0CA0();
ts4_word fn_8884C268();
ts4_word fn_88853540();
ts4_word fn_888AD568();
ts4_word fn_888C2560();
ts4_word fn_888C28A0();
ts4_word fn_888C4B70();
ts4_word fn_888C4E08();
ts4_word fn_888C75E8();
ts4_word fn_888E9C98();
ts4_word fn_888FA4E0();
ts4_word fn_88914028();
ts4_word fn_88923458();
ts4_word fn_88923530();
ts4_word fn_8892F038();
ts4_word fn_88939040();
ts4_word fn_889393C0();
ts4_word fn_88955970();
ts4_word fn_88960168();
ts4_word fn_889728D8(ts4_args3, ts4_word, float);
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif
ts4_word memset();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_call_seq_fn_8841A510_8841A7C8();
ts4_word ts4_call_seq_u32_off18_88837CB0();
ts4_word ts4_change_display_game_mode();
ts4_word ts4_clone_byte_with_object_context();
ts4_word ts4_copy_bytes();
ts4_word ts4_crt_nh_malloc_88565258();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_find_service();
ts4_word ts4_get_u32__imp_KeTimeStampBundle_8857B830();
ts4_word ts4_get_u32_off0_8816CD98();
ts4_word ts4_get_u32_off0_8822AFE8();
ts4_word ts4_gp0_xdata_get_bool_88163C60();
ts4_word ts4_gp0_xdata_get_int32_88163D18();
ts4_word ts4_handle_forward_88150770();
ts4_word ts4_handle_forward_88610A48();
ts4_word ts4_handle_forward_cached_8860FE90();
ts4_word ts4_hash_find_881AB900();
ts4_word ts4_if_addr_ts4_handle_forward_88150770_88731540();
ts4_word ts4_if_call_seq_fn_88933EF8_889396A8();
ts4_word ts4_if_call_seq_u32_off2c_888FA420();
ts4_word ts4_if_get_u32_0xc_8841A820();
ts4_word ts4_if_get_u32_off0_8816CE90();
ts4_word ts4_if_get_u32_off4_8822C018();
ts4_word ts4_if_get_u8_off35_888E63A8();
ts4_word ts4_lua_pushlstring_88823FC0();
ts4_word ts4_lua_pushnil_88824188();
ts4_word ts4_memset();
ts4_word ts4_registry_dispatch_888860A0();
ts4_word ts4_script_string_equals();
ts4_word ts4_tailcall_memcpy_88421450();

/* Swing_DLL.xex 0x881907E8: if_call_seq u32@0x10, fn_8857AFF0, u64@0x0, u64@0x8, u32@0x10, u64@0x0 */
void ts4_if_call_seq_u32_off10_881907E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word loc50[4];
    int t1;
    ts4_u64 t3;
    ts4_u64 t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((int)t1 != 0) {
        fn_8857AFF0((ts4_word)(ts4_word)&loc50[0]);
        t3 = *(ts4_u64 *)((char *)(ts4_word)(a0) + 0);
        t4 = *(ts4_u64 *)((char *)(ts4_word)(a0) + 8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
        *(ts4_u64 *)((char *)(ts4_word)(a0) + 8) = (ts4_u64)(((*(ts4_u64 *)((char *)loc50 + 0)) - t3) + t4);
        *(ts4_u64 *)((char *)(ts4_word)(a0) + 0) = (ts4_u64)0;
    }
    return;
}

/* Swing_DLL.xex 0x881B1B68: loop_call_seq u32@0x0, u8@0x0, ts4_lua_pushlstring_88823FC0, ts4_lua_pushnil_88824188, u32@0x0, u32@0x0 */
ts4_word ts4_loop_call_seq_u32_off0_881B1B68(int a0, ts4_word a1, ts4_word a2)
{
    ts4_word h2;
    ts4_word h1;

    h1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)a2 == 0) {
        ts4_lua_pushnil_88824188((ts4_word)h1);
    } else {
        ts4_lua_pushlstring_88823FC0((ts4_word)h1, (ts4_word)a2, (ts4_word)(ts4_word)strlen((const char *)(ts4_word)a2));
    }
    h2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((int)((*(ts4_word *)((char *)(ts4_word)(h2) + 12)) - (*(ts4_word *)((char *)(ts4_word)(h2) + 16))) >> 4);
    return a0;
}

/* Swing_DLL.xex 0x8821AC30: if_get u32@0x80, u32@0x80, u16@0x8e, u16@0x8e, u8@0xa4, u8@0xa4 */
ts4_word ts4_if_get_u32_off80_8821AC30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    unsigned char b80;
    ts4_word p17;
    ts4_word t1;
    ts4_word t2;
    unsigned short t3;
    unsigned short t4;
    unsigned char t7;
    unsigned char t8;
    unsigned short t9;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 128);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 128);
    if ((ts4_word)t1 != (ts4_word)t2) {
        return ((ts4_word)t1 < (ts4_word)t2);
    }
    t3 = *(unsigned short *)((char *)(ts4_word)(a0) + 142);
    t4 = *(unsigned short *)((char *)(ts4_word)(a1) + 142);
    if ((int)((short)t3) == (int)((short)t4)) {
        t7 = *(unsigned char *)((char *)(ts4_word)(a0) + 164);
        t8 = *(unsigned char *)((char *)(ts4_word)(a1) + 164);
        if ((ts4_word)t7 == (ts4_word)t8) {
            t9 = *(unsigned short *)((char *)(ts4_word)(a0) + 148);
            return ((int)((short)t9) < (int)((short)(*(unsigned short *)((char *)(ts4_word)(a1) + 148))));
        }
    }
    b80 = !((int)((short)t3) >= (int)((short)t4)) || ((int)((signed char)(*(unsigned char *)((char *)(ts4_word)(a0) + 164))) < (int)((signed char)(*(unsigned char *)((char *)(ts4_word)(a1) + 164))));
    p17 = (ts4_word)b80;
    return (p17 & 0xff);
}

/* Swing_DLL.xex 0x88421530: loop_call_seq u8@0x0, u32@lbl_88CACF08, KeTlsGetValue, ts4_call_seq_fn_8841A510_8841A7C8, ts4_copy_bytes */
ts4_word ts4_loop_call_seq_u8_off0_88421530(int a0, int a1)
{
    ts4_word p4;
    ts4_word t6;
    ts4_word t7;

    p4 = (ts4_word)(ts4_word)strlen((const char *)(ts4_word)a0);
    if ((int)p4 > (int)a1) {
        p4 = (ts4_word)a1;
    }
    t6 = KeTlsGetValue((ts4_word)(*(volatile ts4_word *)lbl_88CACF08));
    t7 = ts4_call_seq_fn_8841A510_8841A7C8((ts4_word)t6, (ts4_word)(p4 + 1), (ts4_word)22);
    if ((int)p4 != 0) {
        ts4_copy_bytes((ts4_word)t7, (ts4_word)a0, (ts4_word)p4);
    }
    *(volatile unsigned char *)(p4 + (char *)(ts4_word)(t7)) = (unsigned char)0;
    return t7;
}

/* Swing_DLL.xex 0x88439108: loop_get u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_loop_get_u32_off0_88439108(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p10;
    ts4_word p11;

    (void)a3;
    (void)a4;
    (void)a5;
    c1 = (ts4_word)32;
    lv2 = (ts4_word)1;
    lv3 = (ts4_word)(a0 + 52);
    do {
        if ((ts4_word)(lv2 & a1) != 0) {
            *(ts4_word *)((char *)(ts4_word)(lv3) + 0) = (ts4_word)(a2 | (*(ts4_word *)((char *)(ts4_word)(lv3) + 0)));
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

/* Swing_DLL.xex 0x884391C8: loop_get u32@0x0, u32@0x0, u32@0x0, u32@0x0 */
void ts4_loop_get_u32_off0_884391C8(ts4_word a0, ts4_word a1, int a2, int a3, ts4_word a4, ts4_word a5)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p11;
    ts4_word p10;

    (void)a3;
    (void)a4;
    (void)a5;
    lv2 = (ts4_word)1;
    c1 = (ts4_word)32;
    lv3 = (ts4_word)(a0 + 52);
    do {
        if ((ts4_word)(lv2 & a1) != 0) {
            *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0) &= ~a2;
        }
        if (0 != (ts4_word)(a2 & lv2)) {
            *(volatile ts4_word *)((char *)(ts4_word)(lv3) + 0) &= ~a1;
        }
        p10 = (ts4_word)((lv2 << 1) | (lv2 >> 31));
        p11 = (ts4_word)(lv3 + 4);
        lv3 = p11;
        lv2 = p10;
    } while (--c1 != 0);
    return;
}

/* Swing_DLL.xex 0x8845F838: call_seq fn_88466E80, fn_8845F798, fn_88467030, fn_88467F60, fn_88451F18 */
void ts4_call_seq_fn_88466E80_8845F838(ts4_word a0)
{
    ts4_word loc50[6];

    loc50[0] = (ts4_word)(ts4_word)fn_8845F798;
    loc50[1] = (ts4_word)(ts4_word)fn_88466E80;
    *(unsigned char *)((char *)loc50 + 16) = (unsigned char)0;
    loc50[2] = (ts4_word)(ts4_word)fn_88467030;
    loc50[3] = (ts4_word)(ts4_word)fn_88467F60;
    *(unsigned char *)(17 + (char *)loc50) = (unsigned char)1;
    fn_88451F18((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)1, (ts4_word)1, (ts4_word)(ts4_word)fn_8845F798);
    return;
}

/* Swing_DLL.xex 0x88478B50: set u32@0x8, u32@0xc, u32@0x10, u32@0x0, u32@0x4, u32@0x14 */
void ts4_set_u32_off8_88478B50(int a0, int a1)
{
    int t1;

    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    *(ts4_word *)(12 + (char *)(ts4_word)(a1)) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(a0 + 12);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)12;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)16;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(t1 + (t1 << 1));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(((((int)t1 * 308) + 51) & 0xfffffff0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(t1 + (t1 << 1));
    return;
}

/* Swing_DLL.xex 0x88480F60: set u32@0x8, u32@0xc, u32@0x0, u32@0x4, u32@0x10, u32@0x14 */
void ts4_set_u32_off8_88480F60(int a0, ts4_word a1)
{
    int t1;

    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    *(ts4_word *)(12 + (char *)(ts4_word)(a1)) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(12 + a0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)12;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)16;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)((t1 + (t1 << 1)) << 1);
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(((((int)t1 * 1332) + 83) & 0xfffffff0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)((t1 + (t1 << 1)) << 1);
    return;
}

/* Swing_DLL.xex 0x88485E78: set u32@0x8, u32@0xc, u32@0x10, u32@0x0, u32@0x4, u32@0x14 */
void ts4_set_u32_off8_88485E78(ts4_word a0, int a1)
{
    int t1;

    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(a0 + 12);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 20) = (ts4_word)12;
    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)16;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(((((t1 + (t1 << 2)) << 4) + 51) & 0xfffffff0) + 16);
    return;
}

/* Swing_DLL.xex 0x884D5680: loop_call_seq u32@0x20, fn_88423730, u32@0x8, fn_88423788, fn_884D5020, fn_88423660 */
void ts4_loop_call_seq_u32_off20_884D5680(ts4_word a0, ts4_word a1, int a2, ts4_word a3)
{
    ts4_word t120;
    ts4_word lv1;
    ts4_word lv2;
    ts4_word p16;
    int p17;
    ts4_word t3;
    int t4;
    ts4_word t5;
    int t6;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;
    ts4_word t20;

    if ((int)a2 > 0) {
        lv1 = (ts4_word)(a1 + -24);
        lv2 = (ts4_word)a2;
        do {
            t3 = *(ts4_word *)((char *)(ts4_word)(lv1) + 32);
            if (t3) {
                t4 = fn_88423730((ts4_word)a3, (ts4_word)t3);
                t5 = *(ts4_word *)((char *)(ts4_word)(a3) + 8);
                if ((int)t4 <= (int)t5) {
                    t6 = fn_88423788((ts4_word)a3, (ts4_word)t3, (ts4_word)0);
                    if ((int)t6 != 0) {
                        fn_884D5020((ts4_word)a0, (ts4_word)t3, (ts4_word)1);
                        fn_88423660((ts4_word)a3, (ts4_word)t3, (ts4_word)0);
                    }
                }
            }
            t12 = *(ts4_word *)lbl_88CACF08;
            t13 = *(volatile ts4_word *)((char *)(ts4_word)((lv1 + 24)) + 0);
            t14 = KeTlsGetValue((ts4_word)t12);
            ts4_if_get_u32_0xc_8841A820((ts4_word)t14, (ts4_word)t13);
            p16 = (ts4_word)(lv1 + 24);
            p17 = (ts4_word)(lv2 + -1);
            lv1 = p16;
            lv2 = p17;
        } while ((int)p17 != 0);
    }
    t120 = (*(volatile ts4_word *)lbl_88CACF08);
    t20 = KeTlsGetValue((ts4_word)t120);
    ts4_if_get_u32_0xc_8841A820((ts4_word)t20, (ts4_word)a1);
    return;
}

/* Swing_DLL.xex 0x88522340: loop_get u16@0x0, u16@0x0 */
void ts4_loop_get_u16_off0_88522340(int a0, ts4_word a1, ts4_word a2)
{
    ts4_word lv1;
    ts4_word lv2;
    ts4_word p5;
    unsigned short t4;
    ts4_word p6;

    (void)a0;
    lv2 = (ts4_word)0;
    lv1 = (ts4_word)a1;
    do {
        t4 = *(unsigned short *)((char *)(ts4_word)(lv1) + 0);
        if (65535 == (ts4_word)t4) {
            *(volatile unsigned short *)((char *)(ts4_word)((lv2 << 1)) + a1) = (unsigned short)a2;
            return;
        }
        p6 = (ts4_word)(1 + lv2);
        p5 = (ts4_word)(lv1 + 2);
        lv1 = p5;
        lv2 = p6;
    } while ((int)p6 < 3);
    return;
}

/* Swing_DLL.xex 0x88585F00: if_call_seq u32@0x2c, lbl_88D2EE2C, u32@0x28, u32@0x8, u32@0x8, NtWriteFile */
ts4_word ts4_if_call_seq_u32_off2c_88585F00(ts4_word a0, int a1, int a2, ts4_u64 a3)
{
    ts4_word t204;
    ts4_word t104;
    ts4_word p7;
    int p9;
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word t2;
    ts4_word t1;
    int t4;

    *(volatile ts4_u64 *)(0 + (char *)loc58) = (ts4_u64)a3;
    t1 = *(ts4_word *)(44 + (char *)(ts4_word)(a0));
    t204 = (*(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE2C) + 8));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t104 = t204;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE2C) + 8) = (ts4_word)(t104 + 1);
    t4 = NtWriteFile((ts4_word)t2, (ts4_word)t1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0]);
    p7 = (ts4_word)t4;
    if ((int)t4 == 259) {
        NtWaitForSingleObjectEx((ts4_word)t1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
        p7 = (ts4_word)(loc50[0]);
    }
    p9 = (ts4_word)p7;
    if ((int)p7 >= 0 && (ts4_word)a2 != (ts4_word)(loc50[1])) {
        p9 = (ts4_word)((3221225472) | 389);
    }
    return p9;
}

/* Swing_DLL.xex 0x88585F98: if_call_seq u32@0x2c, lbl_88D2EE2C, u32@0x28, u32@0x8, u32@0x8, NtWriteFileGather */
ts4_word ts4_if_call_seq_u32_off2c_88585F98(ts4_word a0, ts4_word a1, int a2, ts4_u64 a3)
{
    ts4_word t206;
    ts4_word t106;
    int p7;
    ts4_word loc50[2];
    int p9;
    ts4_word loc58[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    int t6;

    *(volatile ts4_u64 *)((char *)loc58 + 0) = (ts4_u64)a3;
    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t206 = (*(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE2C) + 8));
    t106 = t206;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE2C) + 8) = (ts4_word)(t106 + 1);
    t4 = NtWriteFileGather((ts4_word)t2, (ts4_word)t1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0]);
    p7 = (ts4_word)t4;
    if ((int)t4 == 259) {
        NtWaitForSingleObjectEx((ts4_word)t1, (ts4_word)0, (ts4_word)0, (ts4_word)0);
        t6 = loc50[0];
        p7 = (ts4_word)t6;
    }
    p9 = (ts4_word)p7;
    if ((int)p7 >= 0 && (ts4_word)a2 != (ts4_word)(loc50[1])) {
        p9 = (ts4_word)((3221225472) | 389);
    }
    return p9;
}

/* Swing_DLL.xex 0x885CF410: if_get u32@0xb8, u32@0xbc, u32@0x0, u32@0x1c, u32@0x18, u32@0xc0 */
void ts4_if_get_u32_offb8_885CF410(ts4_word a0, ts4_word a1, int a2, ts4_word a3)
{
    ts4_word t211;
    ts4_word t111;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t8;
    ts4_word t10;
    ts4_word t11;

    (void)a1;
    (void)a2;
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 188);
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    t5 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t4 = *(ts4_word *)(28 + (char *)(ts4_word)(t1));
    if ((ts4_word)t2 != (ts4_word)(t5 + (t4 + t3))) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 188) = (ts4_word)(t3 + t5);
    t6 = *(ts4_word *)(192 + (char *)(ts4_word)(a0));
    if ((ts4_word)t6 != 0 && (ts4_word)t6 != 255) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 192) = (ts4_word)(t6 + -1);
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 264);
    if (0 == (ts4_word)t8) {
        return;
    }
    t10 = *(ts4_word *)((char *)(ts4_word)(t1) + 8);
    t211 = ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 36)));
    t111 = t211;
    t11 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
    ((void (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))(t111))((ts4_word)t8, (ts4_word)t11, (ts4_word)t10, (ts4_word)a3, (ts4_word)t2, (ts4_word)((t4 + t3) + t5), (ts4_word)(t3 + t5));
    return;
}

/* Swing_DLL.xex 0x885EB780: if_get u32@0x10, u32@0xc, u32@0x20, fn_88421338, fn_885EB698, u8@0x1 */
void ts4_if_get_u32_off10_885EB780(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, int a4, int a5)
{
    ts4_word p5;
    ts4_word p7;
    ts4_word p14;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t9;
    ts4_word t10;
    ts4_word t13;

    (void)a3;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)(t1 & 0x3fffffff) > (int)(t2 + 70) && (int)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) & a2) != 0) {
        if ((int)a4 != 0 || (int)a5 != 0) {
            p7 = (ts4_word)0;
            p5 = (ts4_word)0;
            if ((ts4_word)a1 != 0) {
                t4 = fn_88421338((ts4_word)a1);
                p7 = (ts4_word)(t4 + 1);
                p5 = (ts4_word)((int)(p7) % 2);
            }
            t9 = fn_885EB698((ts4_word)(a0 + 8), (ts4_word)(p5 + p7));
            *(unsigned char *)((char *)(ts4_word)(t9) + 0) = (unsigned char)67;
            *(unsigned char *)((char *)(ts4_word)(t9) + 1) = (unsigned char)(p5 + p7);
            *(unsigned short *)((char *)(ts4_word)(t9) + 2) = (unsigned short)a4;
            if ((int)a5 == 0) {
                p14 = (ts4_word)0;
            } else {
                t10 = *(ts4_word *)lbl_88CAD32C;
                t13 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t10) + 0))) + 60))))((ts4_word)t10, (ts4_word)a5);
                p14 = (ts4_word)t13;
            }
            *(unsigned short *)((char *)(ts4_word)(t9) + 4) = (unsigned short)p14;
            if ((int)p7 > 0) {
                ts4_tailcall_memcpy_88421450((ts4_word)(t9 + 6), (ts4_word)a1, (ts4_word)p7);
                if ((int)p5 != 0) {
                    *(unsigned char *)((char *)(ts4_word)((t9 + p7)) + 6) = (unsigned char)0;
                }
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x88605860: if_call_seq u8@0x4f, u32@0xe8, u32@0xe8, u8@0x4f, fn_8857A878, u32@0xd4 */
ts4_word ts4_if_call_seq_u8_off4f_88605860(ts4_word a0)
{
    ts4_word t321;
    ts4_word t221;
    ts4_word t121;
    ts4_word p17;
    ts4_word loc60[128];
    ts4_word loc50[4];
    unsigned char t1;
    ts4_word t11;
    ts4_word t14;
    int t15;
    ts4_word t21;
    ts4_word t19;
    ts4_word t3;
    ts4_word t4;
    ts4_word t6;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 79);
    if ((ts4_word)t1 == 0) {
        loc50[0] = (ts4_word)256;
        memset((ts4_word)(ts4_word)&loc60[0], (ts4_word)0, (ts4_word)256);
        t221 = (*(volatile ts4_word *)((char *)(ts4_word)(a0) + 80));
        t121 = t221;
        t11 = fn_884F18D0((ts4_word)t121, (ts4_word)2, (ts4_word)0, (ts4_word)0, (ts4_word)(a0 + 84), (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
        if (t11) {
            return t11;
        }
        ts4_registry_dispatch_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        t14 = *(ts4_word *)lbl_88D45B38;
        if ((ts4_word)t14 == 0) {
            p17 = (ts4_word)(ts4_crt_nh_malloc_88565258((ts4_word)(65536)));
        } else {
            t15 = fn_88613350((ts4_word)t14, (ts4_word)(65536));
            p17 = (ts4_word)t15;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)p17;
        memset((ts4_word)p17, (ts4_word)0, (ts4_word)(65536));
        t19 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        t321 = (*(ts4_word *)(80 + (char *)(ts4_word)(a0)));
        t21 = fn_884F0660((ts4_word)t321, (ts4_word)(ts4_word)&loc60[0], (ts4_word)(65536), (ts4_word)t19, (ts4_word)20, (ts4_word)(a0 + 212), (ts4_word)(a0 + 232));
        if ((ts4_word)t21 != 997) {
            ts4_registry_dispatch_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
            *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
            *(ts4_word *)(8 + (char *)(ts4_word)(a0)) = (ts4_word)0;
            return t21;
        }
        *(unsigned char *)(79 + (char *)(ts4_word)(a0)) = (unsigned char)1;
    } else {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 232);
        if ((ts4_word)t3 != 997) {
            *(unsigned char *)((char *)(ts4_word)(a0) + 79) = (unsigned char)0;
            t4 = fn_8857A878((ts4_word)(a0 + 232));
            if (t4) {
                ts4_registry_dispatch_888860A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
                *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
                *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
                return t4;
            }
            *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 212));
            t6 = fn_88605620((ts4_word)a0);
            return t6;
        }
    }
    return 1;
}

/* Swing_DLL.xex 0x8860CDD8: call_seq ts4_crt_nh_malloc_88565258, u32@0x17c, u32@0x184, u32@0x180, ts4_memset */
void ts4_call_seq_ts4_crt_nh_malloc_88565258_8860CDD8(ts4_word a0)
{
    ts4_word t1;

    t1 = ts4_crt_nh_malloc_88565258((ts4_word)((2752512) | 47488));
    *(ts4_word *)((char *)(ts4_word)(a0) + 380) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 384) = (ts4_word)((0) | 50000);
    *(ts4_word *)((char *)(ts4_word)(a0) + 388) = (ts4_word)0;
    ts4_memset((ts4_word)t1, (ts4_word)0, (ts4_word)((2752512) | 47488));
    return;
}

/* Swing_DLL.xex 0x88628688: if_call_seq fn_88627EC0, ts4_handle_forward_88150770, ts4_gp0_xdata_get_bool_88163C60, u8@0x1c */
void ts4_if_call_seq_fn_88627EC0_88628688(ts4_word a0, ts4_args3 sp1)
{
    unsigned char b80;
    ts4_word p7;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t4;
    ts4_word t8;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    loc50[0] = (ts4_word)((719388672) | 1435);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc58[0];
    b80 = !((ts4_word)t4 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p7 = (ts4_word)b80;
    if ((ts4_word)(p7 & 0xff) == 0) {
        t8 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)(ts4_word)&loc58[0]);
        *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)t8;
    }
    return;
}

/* Swing_DLL.xex 0x88628D48: if_call_seq fn_88627EC0, ts4_handle_forward_88150770, ts4_gp0_xdata_get_bool_88163C60, u8@0x1d, ts4_handle_forward_88150770, ts4_gp0_xdata_get_bool_88163C60 */
void ts4_if_call_seq_fn_88627EC0_88628D48(ts4_word a0, ts4_args3 sp1)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p7;
    ts4_word p14;
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc54[1];
    ts4_word loc68[3];
    ts4_word t4;
    ts4_word t8;
    ts4_word t11;
    ts4_word t15;

    (void)sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    loc50[0] = (ts4_word)((1843920896) | 17104);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t4 = loc58[0];
    b80 = !((ts4_word)t4 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p7 = (ts4_word)b80;
    if ((ts4_word)(p7 & 0xff) == 0) {
        t8 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)(ts4_word)&loc58[0]);
        *(unsigned char *)((char *)(ts4_word)(a0) + 29) = (unsigned char)t8;
    }
    loc54[0] = (ts4_word)((451870720) | 29254);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc54[0]);
    t11 = loc68[0];
    b81 = !((ts4_word)t11 != 0) || ((ts4_word)(loc68[1]) == (ts4_word)((983040) | 65535));
    p14 = (ts4_word)b81;
    if ((ts4_word)(p14 & 0xff) == 0) {
        t15 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)(ts4_word)&loc68[0]);
        *(unsigned char *)((char *)(ts4_word)(a0) + 28) = (unsigned char)t15;
    }
    return;
}

/* Swing_DLL.xex 0x8862CB00: if_call_seq lbl_880DAE20, fn_8862C0E8, fn_8860A9E0 */
void ts4_if_call_seq_lbl_880DAE20_8862CB00(void)
{
    unsigned char b80;
    ts4_word p6;
    ts4_word loc50[6];
    ts4_word t2;

    fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880DAE20);
    t2 = loc50[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
    p6 = (ts4_word)b80;
    if ((ts4_word)(p6 & 0xff) == 0) {
        fn_8860A9E0((ts4_word)(ts4_word)&loc50[0]);
    }
    return;
}

/* Swing_DLL.xex 0x8862F850: if_call_seq fn_88150600, u32@0x0, u32@0x4, u8@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_fn_88150600_8862F850(ts4_word a0, ts4_args3 sp1, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word loc50[64];
    ts4_word t1;
    ts4_word t8;
    ts4_word t9;
    ts4_word t14;
    ts4_word t15;
    ts4_word t18;
    ts4_word t7;

    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = sp1.w[0];
    b80 = !((ts4_word)t1 != 0) || ((ts4_word)(sp1.w[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t8 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
        t9 = *(ts4_word *)((char *)(ts4_word)(a3) + 4);
        if ((ts4_word)t8 != (ts4_word)t9) {
            *(unsigned char *)((char *)(ts4_word)(t8) + 0) = (unsigned char)0;
            *(ts4_word *)((char *)(ts4_word)(a3) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a3) + 0));
        }
        memset((ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)256);
        t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        (void)sp1.w[2];
        fn_88614F48((ts4_word)t14, (ts4_word)(t15 - t14), sp1, (ts4_word)(ts4_word)&loc50[0]);
        t18 = fn_8816CAA0((ts4_word)a3, (ts4_word)(ts4_word)&loc50[0]);
        return t18;
    }
    t7 = fn_88150600((ts4_word)a3, (ts4_word)a0);
    return t7;
}

/* Swing_DLL.xex 0x8864D5D0: if_call_seq u32@0x0, u32@0x20, u32@0x24, lbl_88D44040, u8@0xc, u32@0x10 */
ts4_word ts4_if_call_seq_u32_off0_8864D5D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t4;

    if ((int)(*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0)) == 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)1;
        return -1;
    }
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)a2;
    *(unsigned char *)(12 + (char *)(ts4_word)(a0)) = (unsigned char)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    memset((ts4_word)(ts4_word)lbl_88D44040, (ts4_word)0, (ts4_word)512);
    t4 = fn_885635D0((ts4_word)((*(ts4_word *)(24 + (char *)(ts4_word)(a0)))), (ts4_word)(ts4_word)lbl_880F5A60, (ts4_word)(174 + a0));
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t4;
    *(volatile unsigned char *)(13 + (char *)(ts4_word)(a0)) = (unsigned char)0;
    *(volatile ts4_word *)(4 + (char *)(ts4_word)(a0)) = (ts4_word)1;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_u64 *)(304 + (char *)(ts4_word)(a0)) = (ts4_u64)((ts4_s64)(ts4_word)(ts4_get_u32__imp_KeTimeStampBundle_8857B830((ts4_word)t4)));
    return 0;
}

/* Swing_DLL.xex 0x886C52F0: if_set u32@0x0, u32@0x14, u32@0x4, u32@0x0, u32@0x58, vcall */
void ts4_if_set_u32_off0_886C52F0(int a0, ts4_word a1)
{
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;

    *(volatile ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)6;
    t2 = *(ts4_word *)(4 + (char *)(ts4_word)((*(volatile ts4_word *)(20 + (char *)(ts4_word)(a1)))));
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 88))))((ts4_word)t2, (ts4_word)(a1 + 20));
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
    if (t6) {
        *(unsigned char *)((char *)(ts4_word)(t6) + 0) = (unsigned char)0;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)a1 == (ts4_word)t7) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x886EF530: if_get u32@0x34, u32@0xc, u32@0x54, u32@0x54, u32@0x64, u32@0x54 */
ts4_word ts4_if_get_u32_off34_886EF530(ts4_word a0, ts4_word a1)
{
    unsigned char b80;
    ts4_word p13;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t2;
    int t4;
    ts4_word t9;
    int t10;
    ts4_word t15;
    int t17;
    ts4_word t25;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 12);
        if ((ts4_word)t2 != 0) {
            t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
            if ((int)t4 == 0) {
                *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t2) + 100));
            }
            t9 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
            t10 = *(ts4_word *)((char *)(ts4_word)(t9) + 0);
            b80 = !((int)t10 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t9) + 4)) == (ts4_word)((983040) | 65535));
            p13 = (ts4_word)b80;
            if ((ts4_word)(p13 & 0xff) == 0) {
                t15 = ts4_loop_get_u32_off48_886ECE38((ts4_word)a0);
                if ((ts4_word)t15 != 0) {
                    t17 = *(ts4_word *)((char *)(ts4_word)(a1) + 44);
                    if ((int)t17 == 0) {
                        *(ts4_word *)((char *)(ts4_word)(a1) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84));
                    }
                    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 92))))((ts4_word)t15, (ts4_word)a1);
                    t25 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 52))))((ts4_word)t15, (ts4_word)0, (ts4_word)-1);
                    return t25;
                }
            }
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x886F3B98: if_get u32@0x54, u32@0x68, u8@0x44, u8@0x45, u8@0x46, u8@0x3c */
void ts4_if_get_u32_off54_886F3B98(ts4_word a0)
{
    unsigned char b80;
    ts4_word p8;
    int t1;
    ts4_word t2;
    unsigned char t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    if ((int)t1 != 1) {
        return;
    }
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    t3 = *(unsigned char *)((char *)(ts4_word)(t2) + 68);
    b80 = !(((ts4_word)t3 == 0 && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t2) + 69)) == 0) && (ts4_word)(*(unsigned char *)((char *)(ts4_word)(t2) + 70)) == 0) || ((ts4_word)(*(unsigned char *)((char *)(ts4_word)(t2) + 60)) != 0);
    p8 = (ts4_word)b80;
    if ((ts4_word)(p8 & 0xff) == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x886F7738: if_call_seq ts4_handle_forward_88150770, fn_8816CCE0 */
ts4_word ts4_if_call_seq_fn_88150770_886F7738(ts4_word a0)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;
    float t9;
    ts4_word t10;
    ts4_word t8;

    loc50[0] = (ts4_word)((1131806720) | 63066);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t9 = fn_8816CCE0((ts4_word)(ts4_word)&loc58[0]);
        *(float *)((char *)loc50 + 0) = t9;
        t10 = loc50[0];
        return t10;
    }
    *(float *)((char *)loc50 + 0) = (*(float *)lbl_8814B440);
    t8 = loc50[0];
    return t8;
}

/* Swing_DLL.xex 0x886F7A70: if_call_seq u32@0x0, u32@0x0, ts4_handle_forward_88150770, fn_88169350, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_886F7A70(ts4_word a0, ts4_args3 sp1, ts4_word a3, ts4_word a4)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p5;
    ts4_word p10;
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;
    ts4_word t12;

    t1 = *(ts4_word *)((char *)(ts4_word)(a4) + 0);
    t2 = sp1.w[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(sp1.w[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)a3);
        t7 = loc58[0];
        b81 = !((ts4_word)t7 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
        p10 = (ts4_word)b81;
        if ((ts4_word)(p10 & 0xff) == 0) {
            fn_88169350((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
            t12 = loc50[0];
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t12;
        }
    }
    return a0;
}

/* Swing_DLL.xex 0x886F7B38: if_call_seq u32@0x0, ts4_handle_forward_88150770, fn_886115C0, u32@0x0, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_886F7B38(ts4_word a0, ts4_args3 sp1, ts4_word a3, ts4_word a4)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p4;
    ts4_word p9;
    ts4_word loc58[3];
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t6;
    ts4_word t10;

    t1 = sp1.w[0];
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a4;
    b80 = !((ts4_word)t1 != 0) || ((ts4_word)(sp1.w[1]) == (ts4_word)((983040) | 65535));
    p4 = (ts4_word)b80;
    if ((ts4_word)(p4 & 0xff) == 0) {
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&a3);
        t6 = loc58[0];
        b81 = !((ts4_word)t6 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
        p9 = (ts4_word)b81;
        if ((ts4_word)(p9 & 0xff) == 0) {
            t10 = fn_886115C0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc58[0]);
            *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t10) + 0));
        }
    }
    return a0;
}

/* Swing_DLL.xex 0x886F7C08: if_get ts4_handle_forward_88150770, u32@0x0, u32@0x50, vcall */
ts4_word ts4_if_get_fn_88150770_886F7C08(ts4_args3 sp0, ts4_word a2, ts4_word a3)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p4;
    ts4_word p9;
    ts4_word p13;
    ts4_word p14;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t12;

    t1 = sp0.w[0];
    b80 = !((ts4_word)t1 != 0) || ((ts4_word)(sp0.w[1]) == (ts4_word)((983040) | 65535));
    p4 = (ts4_word)b80;
    if ((ts4_word)(p4 & 0xff) == 0) {
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&a2);
        t6 = loc50[0];
        t7 = loc50[1];
        b81 = !((ts4_word)t6 != 0) || ((ts4_word)t7 == (ts4_word)((983040) | 65535));
        p9 = (ts4_word)b81;
        if ((ts4_word)(p9 & 0xff) == 0) {
            t12 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 80))))((ts4_word)t6, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t7, (ts4_word)1);
            p13 = (ts4_word)t12;
        } else {
            p13 = (ts4_word)a3;
        }
        p14 = (ts4_word)p13;
    } else {
        p14 = (ts4_word)a3;
    }
    return p14;
}

/* Swing_DLL.xex 0x886F7DA0: if_call_seq u32@0x0, ts4_handle_forward_88150770, ts4_gp0_xdata_get_int32_88163D18 */
ts4_word ts4_if_call_seq_u32_off0_886F7DA0(ts4_args3 sp0, ts4_word a2, ts4_word a3)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p5;
    ts4_word p10;
    ts4_word p12;
    ts4_word p13;
    ts4_word p14;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;

    (void)a2;
    t1 = sp0.w[0];
    t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    b80 = !((ts4_word)t1 != 0) || ((ts4_word)(sp0.w[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&sp0);
        t7 = loc50[0];
        t8 = loc50[1];
        b81 = !((ts4_word)t7 != 0) || ((ts4_word)t8 == (ts4_word)((983040) | 65535));
        p10 = (ts4_word)b81;
        if ((ts4_word)(p10 & 0xff) == 0) {
            if ((ts4_word)t8 == (ts4_word)((983040) | 65535)) {
                p12 = (ts4_word)0;
            } else {
                t11 = ts4_gp0_xdata_get_int32_88163D18((ts4_word)(ts4_word)&loc50[0]);
                p12 = (ts4_word)t11;
            }
            p13 = (ts4_word)p12;
        } else {
            p13 = (ts4_word)t2;
        }
        p14 = (ts4_word)p13;
    } else {
        p14 = (ts4_word)t2;
    }
    return p14;
}

/* Swing_DLL.xex 0x886FDCB8: if_call_seq ts4_handle_forward_88150770, ts4_gp0_xdata_get_int32_88163D18, ts4_get_u32_off0_8822AFE8 */
ts4_word ts4_if_call_seq_fn_88150770_886FDCB8(ts4_args3 sp0, ts4_word a2)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc54[1];
    ts4_word t2;
    int t7;

    loc50[0] = (ts4_word)((1688403968) | 64992);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t7 = ts4_gp0_xdata_get_int32_88163D18((ts4_word)(ts4_word)&loc58[0]);
        if ((int)t7 != -1) {
            if ((int)t7 > 0) {
                if ((ts4_word)(a2 & 0xff) == 1) {
                    loc54[0] = (ts4_word)(t7 + -1);
                    ts4_get_u32_off0_8822AFE8((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc54[0]);
                }
                return 1;
            }
            return 0;
        }
        return 1;
    }
    return 1;
}

/* Swing_DLL.xex 0x886FE320: if_get ts4_handle_forward_88150770, u32@0x0, u32@0x4, u32@0x0, u32@0x4, u32@0x3c */
ts4_word ts4_if_get_fn_88150770_886FE320(ts4_word a0, ts4_args3 sp1, ts4_word a3)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word t2;
    ts4_word t6;
    ts4_word t7;

    loc50[0] = (ts4_word)((815595520) | 12359);
    ts4_handle_forward_88150770((ts4_word)a0, (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t6 = *(ts4_word *)((char *)(ts4_word)(t2) + 0);
        t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t6) + 60))))((ts4_word)t2, (ts4_word)a0, (ts4_word)t7, (ts4_word)a3, (ts4_word)72, (ts4_word)20);
    }
    return a0;
}

/* Swing_DLL.xex 0x886FE488: if_call_seq ts4_handle_forward_88150770, fn_882382A8, fn_8825D858 */
ts4_word ts4_if_call_seq_fn_88150770_886FE488(ts4_args3 sp0, ts4_word a2)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word loc70[20];
    ts4_word t2;

    loc50[0] = (ts4_word)((815595520) | 12359);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        fn_882382A8((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc58[0]);
        fn_8825D858((ts4_word)a2, (ts4_word)(ts4_word)&loc70[0]);
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x88703E18: if_call_seq ts4_handle_forward_88150770, lbl_880C8FA6, ts4_clone_byte_with_object_context */
void ts4_if_call_seq_ts4_handle_forward_88150770_88703E18(ts4_word a0)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;

    loc50[0] = (ts4_word)((2726625280) | 38856);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(a0 + 8), (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880C8FA6);
    }
    return;
}

/* Swing_DLL.xex 0x887075A8: if_call_seq ts4_handle_forward_88150770, ts4_if_get_u32_off0_8816CE90 */
ts4_word ts4_if_call_seq_fn_88150770_887075A8(ts4_word a0)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t7;

    loc50[0] = (ts4_word)((1327890432) | 65080);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        t7 = ts4_if_get_u32_off0_8816CE90((ts4_word)(ts4_word)&loc58[0]);
        return t7;
    }
    return 1;
}

/* Swing_DLL.xex 0x8870FB20: if_call_seq ts4_handle_forward_88150770, ts4_get_u32_off0_8816CD98 */
ts4_word ts4_if_call_seq_fn_88150770_8870FB20(ts4_args3 sp0, float f1, ts4_word a3)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p4;
    ts4_word p9;
    ts4_word loc50[4];
    ts4_word t1;
    ts4_word t6;

    t1 = sp0.w[0];
    b80 = !((ts4_word)t1 != 0) || ((ts4_word)(sp0.w[1]) == (ts4_word)((983040) | 65535));
    p4 = (ts4_word)b80;
    if ((ts4_word)(p4 & 0xff) == 0) {
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&sp0, (ts4_word)a3);
        t6 = loc50[0];
        b81 = !((ts4_word)t6 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
        p9 = (ts4_word)b81;
        if ((ts4_word)(p9 & 0xff) == 0) {
            ts4_get_u32_off0_8816CD98((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&f1);
            return 1;
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x88714908: if_call_seq u32@0x0, ts4_handle_forward_88150770, ts4_if_get_u32_off0_8816CE90 */
ts4_word ts4_if_call_seq_u32_off0_88714908(ts4_args3 sp0, ts4_word a2, ts4_word a3)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p5;
    ts4_word p10;
    ts4_word p12;
    ts4_word p13;
    ts4_word p14;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;

    (void)a2;
    t1 = sp0.w[0];
    t2 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    b80 = !((ts4_word)t1 != 0) || ((ts4_word)(sp0.w[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&sp0);
        t7 = loc50[0];
        t8 = loc50[1];
        b81 = !((ts4_word)t7 != 0) || ((ts4_word)t8 == (ts4_word)((983040) | 65535));
        p10 = (ts4_word)b81;
        if ((ts4_word)(p10 & 0xff) == 0) {
            if ((ts4_word)t8 == (ts4_word)((983040) | 65535)) {
                p12 = (ts4_word)0;
            } else {
                t11 = ts4_if_get_u32_off0_8816CE90((ts4_word)(ts4_word)&loc50[0]);
                p12 = (ts4_word)t11;
            }
            p13 = (ts4_word)p12;
        } else {
            p13 = (ts4_word)t2;
        }
        p14 = (ts4_word)p13;
    } else {
        p14 = (ts4_word)t2;
    }
    return p14;
}

/* Swing_DLL.xex 0x887197C8: if_get u32@0x0, u32@0x40, vcall, u32@0x0, u32@0x4, u32@0x0 */
void ts4_if_get_u32_off0_887197C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    unsigned char b80;
    ts4_word p7;
    ts4_word loc50[4];
    ts4_word t3;
    int t4;
    ts4_word t15;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 0);
    b80 = !((int)t4 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t3) + 4)) == (ts4_word)((983040) | 65535));
    p7 = (ts4_word)b80;
    if ((ts4_word)(p7 & 0xff) != 0) {
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 36))))((ts4_word)a0);
    }
    t15 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 64))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    fn_88713970(*(ts4_args3 *)((char *)(ts4_word)(t15) + 0), (ts4_word)a2, (ts4_word)a1, (ts4_word)0);
    return;
}

/* Swing_DLL.xex 0x88722000: if_set ts4_handle_forward_88150770, ts4_handle_forward_88150770, u32@0x7c, u32@0x0, u32@0x50, vcall */
void ts4_if_set_ts4_handle_forward_88150770_88722000(ts4_word a0, ts4_word a1)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p5;
    ts4_word p10;
    ts4_word loc50[1];
    ts4_word loc78[3];
    ts4_word loc54[1];
    ts4_word loc68[3];
    ts4_word loc58[3];
    ts4_word t2;
    ts4_word t7;
    ts4_word t8;
    ts4_word t13;
    ts4_word t15;
    ts4_word t31;
    ts4_word t16;
    ts4_word t29;
    ts4_word t17;
    ts4_word t27;
    ts4_word t18;
    ts4_word t25;
    ts4_word t19;
    ts4_word t23;
    ts4_word t20;
    ts4_word t21;

    loc50[0] = (ts4_word)((2536505344) | 57108);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc78[0], (ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc78[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc78[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)(p5 & 0xff);
        return;
    }
    loc54[0] = (ts4_word)((437977088) | 14216);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc68[0], (ts4_word)a1, (ts4_word)(ts4_word)&loc54[0]);
    t7 = loc68[0];
    t8 = loc68[1];
    b81 = !((ts4_word)t7 != 0) || ((ts4_word)t8 == (ts4_word)((983040) | 65535));
    p10 = (ts4_word)b81;
    if ((ts4_word)(p10 & 0xff) == 0) {
        t13 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 80))))((ts4_word)t7, (ts4_word)(ts4_word)&loc68[0], (ts4_word)t8, (ts4_word)1);
        ts4_assign_formatted_text((ts4_word)(ts4_word)&loc58[0], (ts4_word)t13);
        t15 = fn_8822BF98((ts4_word)(ts4_word)lbl_880F0174, (ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)(t15 & 0xff) != 0) {
            t31 = loc58[0];
            *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)1;
            ts4_destroy_owned_object((ts4_word)t31);
            return;
        }
        t16 = fn_8822BF98((ts4_word)(ts4_word)lbl_880F0184, (ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)(t16 & 0xff) != 0) {
            t29 = loc58[0];
            *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)3;
            ts4_destroy_owned_object((ts4_word)t29);
            return;
        }
        t17 = fn_8822BF98((ts4_word)(ts4_word)lbl_880F0190, (ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)(t17 & 0xff) != 0) {
            t27 = loc58[0];
            *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)4;
            ts4_destroy_owned_object((ts4_word)t27);
            return;
        }
        t18 = fn_8822BF98((ts4_word)(ts4_word)lbl_880F019C, (ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)(t18 & 0xff) != 0) {
            t25 = loc58[0];
            *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)5;
            ts4_destroy_owned_object((ts4_word)t25);
            return;
        }
        t19 = fn_8822BF98((ts4_word)(ts4_word)lbl_880F01AC, (ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)(t19 & 0xff) != 0) {
            t23 = loc58[0];
            *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)2;
            ts4_destroy_owned_object((ts4_word)t23);
            return;
        }
        t20 = fn_8822BF98((ts4_word)(ts4_word)lbl_880F01C0, (ts4_word)(ts4_word)&loc58[0]);
        if ((ts4_word)(t20 & 0xff) != 0) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)6;
        }
        t21 = loc58[0];
        ts4_destroy_owned_object((ts4_word)t21);
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)2;
    return;
}

/* Swing_DLL.xex 0x88724240: if_call_seq u32@0x0, u32@0x4, ts4_find_service, u32@0x0, u32@0x14, u32@0x18 */
void ts4_if_call_seq_u32_off0_88724240(ts4_word a0)
{
    unsigned char b80;
    ts4_word p8;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t3;
    int t5;
    ts4_word t9;
    ts4_word t12;
    ts4_word t13;
    ts4_word t14;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        t3 = ts4_find_service((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t3;
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    b80 = !((int)t5 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)) == (ts4_word)((983040) | 65535));
    p8 = (ts4_word)b80;
    if ((ts4_word)(p8 & 0xff) != 0) {
        t9 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)(a0 + 8));
        if ((ts4_word)(t9 & 0xff) == 0) {
            fn_88722CA8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 + 8)) + 0)));
            t12 = loc50[0];
            t13 = loc50[1];
            t14 = loc50[2];
            *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t12;
            *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t13;
            *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t14;
        }
    }
    return;
}

/* Swing_DLL.xex 0x88724620: loop_get u32@0x10c, lbl_880C1320, fn_8822BF98, u32@0x0, fn_88722CA8, fn_88923530 */
ts4_word ts4_loop_get_u32_off10c_88724620(ts4_word a0)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p8;
    ts4_word p21;
    ts4_word p31;
    ts4_word lv35;
    ts4_word lv36;
    ts4_word p41;
    ts4_word p42;
    ts4_word p43;
    ts4_word p46;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t9;
    ts4_word t10;
    ts4_word t14;
    ts4_word t15;
    ts4_word t18;
    ts4_word t22;
    ts4_word t23;
    ts4_word t27;
    ts4_word t29;
    ts4_word t30;
    ts4_word t32;
    ts4_word t33;
    ts4_word t34;
    ts4_word t37;
    ts4_word t38;
    ts4_word t40;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 268);
    if ((ts4_word)t1 == 0) {
        t2 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)(a0 + 256));
        if ((ts4_word)(t2 & 0xff) == 0) {
            fn_88722CA8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 + 256)) + 0)));
            t5 = loc50[0];
            b80 = !((ts4_word)t5 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
            p8 = (ts4_word)b80;
            if ((ts4_word)(p8 & 0xff) == 0) {
                t9 = loc50[2];
                t10 = fn_88923530((ts4_word)t9, *(ts4_args3 *)&loc50[0], (ts4_word)((3317366784) | 46560));
                *(ts4_word *)((char *)(ts4_word)(a0) + 268) = (ts4_word)t10;
            }
        }
    }
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 284);
    if ((ts4_word)t14 == 0) {
        t15 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)(a0 + 272));
        if ((ts4_word)(t15 & 0xff) == 0) {
            fn_88722CA8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 + 272)) + 0)));
            t18 = loc50[0];
            b81 = !((ts4_word)t18 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
            p21 = (ts4_word)b81;
            if ((ts4_word)(p21 & 0xff) == 0) {
                t22 = loc50[2];
                t23 = fn_88923530((ts4_word)t22, *(ts4_args3 *)&loc50[0], (ts4_word)((1330839552) | 54990));
                *(ts4_word *)((char *)(ts4_word)(a0) + 284) = (ts4_word)t23;
            }
        }
    }
    t27 = *(ts4_word *)((char *)(ts4_word)(a0) + 296);
    t29 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636);
    p31 = (ts4_word)t27;
    if ((ts4_word)t29 != (ts4_word)t27) {
        t30 = ts4_find_service((ts4_word)t27);
        *(ts4_word *)((char *)(ts4_word)(a0) + 292) = (ts4_word)t30;
        p31 = (ts4_word)t30;
    }
    t32 = *(ts4_word *)((char *)(ts4_word)(a0) + 292);
    p46 = (ts4_word)p31;
    if ((ts4_word)t32 != 0) {
        t33 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
        t34 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        p43 = (ts4_word)p31;
        lv35 = (ts4_word)p31;
        lv36 = (ts4_word)t34;
        while ((ts4_word)lv36 != (ts4_word)t33) {
            t37 = *(ts4_word *)((char *)(ts4_word)(lv36) + 0);
            t38 = *(ts4_word *)((char *)(ts4_word)(a0) + 292);
            t40 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t37) + 16))))((ts4_word)lv36, (ts4_word)t38, (ts4_word)2);
            p41 = (ts4_word)t40;
            p42 = (ts4_word)(lv36 + 44);
            lv35 = p41;
            lv36 = p42;
            p43 = (ts4_word)lv35;
        }
        p46 = (ts4_word)p43;
    }
    return p46;
}

/* Swing_DLL.xex 0x88724A48: if_call_seq u32@0x44, u32@0x40, u32@lbl_88D45B1C, u32@0x27c, ts4_find_service, u32@0x44 */
void ts4_if_call_seq_u32_off44_88724A48(ts4_word a0)
{
    unsigned char b80;
    ts4_word p11;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t5;
    int t8;
    ts4_word t12;
    ts4_word t15;
    ts4_word t16;
    ts4_word t17;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 == 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
        t4 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636);
        if ((ts4_word)t4 != (ts4_word)t2) {
            t5 = ts4_find_service((ts4_word)t2);
            *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)t5;
        }
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    b80 = !((int)t8 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 88)) == (ts4_word)((983040) | 65535));
    p11 = (ts4_word)b80;
    if ((ts4_word)(p11 & 0xff) != 0) {
        t12 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)(a0 + 72));
        if ((ts4_word)(t12 & 0xff) == 0) {
            fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 + 72)) + 0)));
            t15 = loc50[0];
            t16 = loc50[1];
            t17 = loc50[2];
            *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)t15;
            *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)t16;
            *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)t17;
        }
    }
    return;
}

/* Swing_DLL.xex 0x88724E80: if_call_seq fn_886F6128, u32@0x48, u32@0x4c, lbl_880C1320, fn_8822BF98, u32@0x0 */
void ts4_if_call_seq_fn_886F6128_88724E80(ts4_word a0)
{
    unsigned char b80;
    unsigned char b81;
    unsigned char b82;
    ts4_word p5;
    ts4_word p18;
    ts4_word p32;
    ts4_word loc50[6];
    int t2;
    ts4_word t6;
    ts4_word t9;
    ts4_word t10;
    ts4_word t11;
    int t15;
    ts4_word t19;
    ts4_word t22;
    ts4_word t23;
    ts4_word t24;
    int t29;
    ts4_word t33;
    ts4_word t36;
    ts4_word t37;
    ts4_word t38;

    fn_886F6128();
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 72);
    b80 = !((int)t2 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 76)) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) != 0) {
        t6 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)(a0 + 60));
        if ((ts4_word)(t6 & 0xff) == 0) {
            fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 + 60)) + 0)));
            t9 = loc50[0];
            t10 = loc50[1];
            t11 = loc50[2];
            *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)t9;
            *(ts4_word *)((char *)(ts4_word)(a0) + 76) = (ts4_word)t10;
            *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)t11;
        }
    }
    t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 96);
    b81 = !((int)t15 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 100)) == (ts4_word)((983040) | 65535));
    p18 = (ts4_word)b81;
    if ((ts4_word)(p18 & 0xff) != 0) {
        t19 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)(a0 + 84));
        if ((ts4_word)(t19 & 0xff) == 0) {
            fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 + 84)) + 0)));
            t22 = loc50[0];
            t23 = loc50[1];
            t24 = loc50[2];
            *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)t22;
            *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)t23;
            *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)t24;
        }
    }
    t29 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    b82 = !((int)t29 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 124)) == (ts4_word)((983040) | 65535));
    p32 = (ts4_word)b82;
    if ((ts4_word)(p32 & 0xff) != 0) {
        t33 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)(a0 + 108));
        if ((ts4_word)(t33 & 0xff) == 0) {
            fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 + 108)) + 0)));
            t36 = loc50[0];
            t37 = loc50[1];
            t38 = loc50[2];
            *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)t36;
            *(ts4_word *)((char *)(ts4_word)(a0) + 124) = (ts4_word)t37;
            *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)t38;
        }
    }
    return;
}

/* Swing_DLL.xex 0x8872AE58: loop_get u32@0x28, u32@0x2c, lbl_880C1320, fn_8822BF98, u32@0x0, fn_8862BE08 */
void ts4_loop_get_u32_off28_8872AE58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word lv19;
    ts4_word p24;
    ts4_word lv29;
    ts4_word p34;
    ts4_word loc50[4];
    int t1;
    ts4_word t7;
    ts4_word t10;
    ts4_word t11;
    ts4_word t12;
    ts4_word t17;
    ts4_word t20;
    ts4_word t27;
    ts4_word t30;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    b80 = !((int)t1 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 44)) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) != 0) {
        t7 = fn_8822BF98((ts4_word)(ts4_word)lbl_880C1320, (ts4_word)(a0 + 52));
        if ((ts4_word)(t7 & 0xff) == 0) {
            fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)((a0 + 52)) + 0)));
            t10 = loc50[0];
            t11 = loc50[1];
            t12 = loc50[2];
            *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t10;
            *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)t11;
            *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)t12;
        }
    }
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 104);
    lv19 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 100));
    while ((ts4_word)lv19 != (ts4_word)t17) {
        t20 = *(ts4_word *)((char *)(ts4_word)(lv19) + 0);
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t20) + 0))) + 12))))((ts4_word)t20, (ts4_word)0);
        p24 = (ts4_word)(lv19 + 4);
        lv19 = p24;
    }
    t27 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    lv29 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 84));
    while ((ts4_word)lv29 != (ts4_word)t27) {
        t30 = *(ts4_word *)((char *)(ts4_word)(lv29) + 0);
        ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t30) + 0))) + 36))))((ts4_word)t30);
        p34 = (ts4_word)(lv29 + 4);
        lv29 = p34;
    }
    return;
}

/* Swing_DLL.xex 0x88731478: if_get u32@0x0, ts4_assign_formatted_text, ts4_handle_forward_88150770, u32@0x0, u32@0x50, vcall */
ts4_word ts4_if_get_u32_off0_88731478(ts4_word a0, ts4_args3 sp1, ts4_word a3, ts4_word a4)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p6;
    ts4_word p11;
    ts4_word loc50[4];
    ts4_word t3;
    ts4_word t8;
    ts4_word t9;
    ts4_word t14;

    ts4_assign_formatted_text((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a4) + 0)));
    t3 = sp1.w[0];
    b80 = !((ts4_word)t3 != 0) || ((ts4_word)(sp1.w[1]) == (ts4_word)((983040) | 65535));
    p6 = (ts4_word)b80;
    if ((ts4_word)(p6 & 0xff) == 0) {
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&sp1, (ts4_word)a3);
        t8 = loc50[0];
        t9 = loc50[1];
        b81 = !((ts4_word)t8 != 0) || ((ts4_word)t9 == (ts4_word)((983040) | 65535));
        p11 = (ts4_word)b81;
        if ((ts4_word)(p11 & 0xff) == 0) {
            t14 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t8) + 0))) + 80))))((ts4_word)t8, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t9, (ts4_word)1);
            fn_8816CAA0((ts4_word)a0, (ts4_word)t14);
        }
    }
    return a0;
}

/* Swing_DLL.xex 0x88733F28: if_call_seq ts4_handle_forward_88610A48, u32@lbl_88D45AD4, u32@0x6c, fn_887316D0 */
ts4_word ts4_if_call_seq_fn_88610A48_88733F28(ts4_args3 sp0)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word p11;
    ts4_word loc50[2];
    ts4_word loc58[3];
    ts4_word t1;
    ts4_word t2;
    ts4_word t10;

    loc50[0] = (ts4_word)((3286761472) | 61210);
    t1 = ts4_handle_forward_88610A48((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    b80 = ((ts4_word)t2 == 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    p11 = (ts4_word)t1;
    if ((ts4_word)(p5 & 0xff) == 0) {
        (void)loc58[2];
        t10 = fn_887316D0((ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45AD4)) + 108)), *(ts4_args3 *)&loc58[0]);
        p11 = (ts4_word)t10;
    }
    return p11;
}

/* Swing_DLL.xex 0x88734000: if_call_seq ts4_handle_forward_88150770, fn_88169350, u32@lbl_88D45AD4, fn_88732788 */
void ts4_if_call_seq_ts4_handle_forward_88150770_88734000(ts4_args3 sp0)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t8;

    loc50[0] = (ts4_word)((938999808) | 59541);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        fn_88169350((ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc58[0]);
        t8 = loc54[0];
        fn_88732788((ts4_word)((*(ts4_word *)lbl_88D45AD4) + 16), (ts4_word)t8);
    }
    return;
}

/* Swing_DLL.xex 0x88757C58: if_call_seq fn_8816D1A8, ts4_if_addr_ts4_handle_forward_88150770_88731540, ts4_handle_forward_88150770, lbl_880C1320, fn_881643D0, ts4_if_get_u32_off4_8822C018 */
void ts4_if_call_seq_fn_8816D1A8_88757C58(ts4_args3 sp0)
{
    unsigned char b80;
    ts4_word p9;
    ts4_word loc60[4];
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word loc70[6];
    ts4_word loc58[2];
    ts4_word t4;
    ts4_word t6;
    ts4_word t10;
    ts4_word t15;

    fn_8816D1A8((ts4_word)(ts4_word)&loc60[0]);
    loc50[0] = (ts4_word)((2171731968) | 35718);
    ts4_if_addr_ts4_handle_forward_88150770_88731540((ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
    loc54[0] = (ts4_word)((1878130688) | 24076);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc54[0]);
    t4 = fn_881643D0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880C1320);
    if ((ts4_word)(t4 & 0xff) == 0) {
        t6 = loc70[0];
        b80 = !((ts4_word)t6 != 0) || ((ts4_word)(loc70[1]) == (ts4_word)((983040) | 65535));
        p9 = (ts4_word)b80;
        if ((ts4_word)(p9 & 0xff) == 0) {
            loc58[0] = (ts4_word)(p9 & 0xff);
            t10 = ts4_if_get_u32_off4_8822C018((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc58[0]);
            if ((ts4_word)t10 != 0) {
                fn_887552C0((ts4_word)(ts4_word)&loc60[0], (ts4_word)t10);
            }
        }
    }
    t15 = loc60[0];
    ts4_destroy_owned_object((ts4_word)t15);
    return;
}

/* Swing_DLL.xex 0x88791C00: if_call_seq lbl_880ECCC0, fn_8862C0E8, ts4_handle_forward_88150770, ts4_get_u32_off0_8822AFE8 */
ts4_word ts4_if_call_seq_lbl_880ECCC0_88791C00(void)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p5;
    ts4_word p10;
    ts4_word loc58[3];
    ts4_word loc50[1];
    ts4_word loc68[3];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t7;

    fn_8862C0E8((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880ECCC0);
    t2 = loc58[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        loc50[0] = (ts4_word)((1688403968) | 64992);
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
        t7 = loc68[0];
        b81 = !((ts4_word)t7 != 0) || ((ts4_word)(loc68[1]) == (ts4_word)((983040) | 65535));
        p10 = (ts4_word)b81;
        if ((ts4_word)(p10 & 0xff) == 0) {
            loc54[0] = (ts4_word)(p10 & 0xff);
            ts4_get_u32_off0_8822AFE8((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc54[0]);
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x88791CC8: if_call_seq lbl_880ECCC0, fn_8862C0E8, ts4_handle_forward_88150770, ts4_get_u32_off0_8822AFE8 */
ts4_word ts4_if_call_seq_lbl_880ECCC0_88791CC8(void)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p5;
    ts4_word p10;
    ts4_word loc58[3];
    ts4_word loc50[1];
    ts4_word loc68[3];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t7;

    fn_8862C0E8((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880ECCC0);
    t2 = loc58[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        loc50[0] = (ts4_word)((1688403968) | 64992);
        ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
        t7 = loc68[0];
        b81 = !((ts4_word)t7 != 0) || ((ts4_word)(loc68[1]) == (ts4_word)((983040) | 65535));
        p10 = (ts4_word)b81;
        if ((ts4_word)(p10 & 0xff) == 0) {
            loc54[0] = (ts4_word)-1;
            ts4_get_u32_off0_8822AFE8((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc54[0]);
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x88795820: loop_call_seq u32@0xbc, u32@0xb8, u8@0x3c, u8@0x118, lbl_880EE9A0, ts4_script_string_equals */
void ts4_loop_call_seq_u32_offbc_88795820(ts4_word a0)
{
    unsigned char b80;
    ts4_word lv3;
    ts4_word p4;
    ts4_word p13;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    ts4_word t14;
    ts4_word t15;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 188);
    lv3 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 184));
    while ((ts4_word)lv3 != (ts4_word)t1) {
        *(unsigned char *)((char *)(ts4_word)(lv3) + 60) = (unsigned char)0;
        p4 = (ts4_word)(lv3 + 64);
        lv3 = p4;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 280) = (unsigned char)1;
    t6 = ts4_script_string_equals((ts4_word)(a0 + 96), (ts4_word)(ts4_word)lbl_880EE9A0);
    if ((ts4_word)(t6 & 0xff) != 0) {
        fn_888E9C98((ts4_word)(*(ts4_word *)lbl_88D45954));
        ts4_change_display_game_mode((ts4_word)((3711369216) | 38317));
    } else {
        t7 = ts4_script_string_equals((ts4_word)(a0 + 96), (ts4_word)(ts4_word)lbl_880D1EE8);
        if ((ts4_word)(t7 & 0xff) != 0) {
            fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D90D4);
            t9 = loc50[0];
            b80 = !((ts4_word)t9 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
            p13 = (ts4_word)b80;
            if ((ts4_word)(p13 & 0xff) == 0) {
                t14 = loc50[2];
                t15 = fn_88923530((ts4_word)t14, *(ts4_args3 *)&loc50[0], (ts4_word)((776994816) | 51458));
                *(unsigned char *)((char *)(ts4_word)(t15) + 8) = (unsigned char)0;
            }
        }
    }
    return;
}

/* Swing_DLL.xex 0x887966E0: if_call_seq u32@lbl_88D458F0, ts4_hash_find_881AB900, u32@0x14, fn_8884C268, u32@0x40, u32@0x88 */
ts4_word ts4_if_call_seq_u32_lbl_88D458F0_887966E0(void)
{
    ts4_word loc50[3];
    ts4_word t2;
    ts4_word t4;

    loc50[1] = (ts4_word)((983040) | 65535);
    loc50[0] = (ts4_word)0;
    loc50[2] = (ts4_word)0;
    t2 = ts4_hash_find_881AB900((ts4_word)(*(ts4_word *)lbl_88D458F0), (ts4_word)((2117402624) | 60948), *(ts4_args3 *)&loc50[0]);
    t4 = fn_8884C268((ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t2) + 20)));
    if ((ts4_word)t4 != 0) {
        *(volatile ts4_word *)((char *)(ts4_word)(t2) + 136) = (ts4_word)(((((35736 | (2470772736)) - (*(volatile ts4_word *)((char *)(ts4_word)(t4) + 64))) == 0) ^ 1) + 2);
    }
    return 0;
}

/* Swing_DLL.xex 0x88798080: if_call_seq fn_88150600, u32@0x2c, u32@0x28, u32@0x24, u32@0x0, fn_8862C0E8 */
ts4_word ts4_if_call_seq_fn_88150600_88798080(ts4_word a0, ts4_word a1)
{
    unsigned char b80;
    ts4_word p9;
    ts4_word p12;
    ts4_word p13;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t10;
    ts4_word t11;

    t1 = fn_88150600((ts4_word)(a0 + 40), (ts4_word)a1);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 44);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((int)(t2 - t3) != 0) {
        t5 = fn_8862C0E8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)((a0 + 40)) + 0)));
        t6 = loc50[0];
        b80 = !((ts4_word)t6 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
        p9 = (ts4_word)b80;
        p12 = (ts4_word)t5;
        if ((ts4_word)(p9 & 0xff) == 0) {
            t10 = loc50[2];
            t11 = fn_88923458((ts4_word)t10, *(ts4_args3 *)&loc50[0], (ts4_word)12);
            *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t11;
            p12 = (ts4_word)t11;
        }
        p13 = (ts4_word)p12;
    } else {
        *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
        p13 = (ts4_word)t1;
    }
    return p13;
}

/* Swing_DLL.xex 0x887BADD0: if_call_seq fn_887BAB70, u32@lbl_88D45A60, fn_8879CC98, fn_887BA228, fn_881ABB20, ts4_call_seq_u32_off18_88837CB0 */
ts4_word ts4_if_call_seq_fn_887BAB70_887BADD0(ts4_word a0, ts4_word a1)
{
    unsigned char b80;
    ts4_word p7;
    ts4_word loc80[16];
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t4;

    fn_887BAB70((ts4_word)(ts4_word)&loc80[0], (ts4_word)a1);
    fn_8879CC98((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)lbl_88D45A60), (ts4_word)(ts4_word)&loc80[0]);
    t4 = loc50[0];
    b80 = !((ts4_word)t4 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
    p7 = (ts4_word)b80;
    if ((ts4_word)(p7 & 0xff) == 0) {
        loc60[0] = (ts4_word)0;
        loc60[1] = (ts4_word)0;
        loc60[6] = (ts4_word)0;
        loc60[2] = (ts4_word)0;
        loc60[4] = (ts4_word)0;
        fn_881ABB20((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
        ts4_call_seq_u32_off18_88837CB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
        fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
        fn_887BA228((ts4_word)(ts4_word)&loc80[0]);
        return 1;
    }
    fn_887BA228((ts4_word)(ts4_word)&loc80[0]);
    return 0;
}

/* Swing_DLL.xex 0x887BAEB0: if_call_seq fn_887BAB70, u32@lbl_88D45A60, fn_8879CD88, fn_887BA228, fn_882160A8, ts4_call_seq_u32_off18_88837CB0 */
ts4_word ts4_if_call_seq_fn_887BAB70_887BAEB0(ts4_word a0, ts4_word a1)
{
    unsigned char b80;
    ts4_word p7;
    ts4_word loc80[16];
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t4;

    fn_887BAB70((ts4_word)(ts4_word)&loc80[0], (ts4_word)a1);
    fn_8879CD88((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)lbl_88D45A60), (ts4_word)(ts4_word)&loc80[0]);
    t4 = loc50[0];
    b80 = !((ts4_word)t4 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
    p7 = (ts4_word)b80;
    if ((ts4_word)(p7 & 0xff) == 0) {
        loc60[0] = (ts4_word)0;
        loc60[1] = (ts4_word)0;
        loc60[6] = (ts4_word)0;
        loc60[2] = (ts4_word)0;
        loc60[4] = (ts4_word)0;
        fn_882160A8((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
        ts4_call_seq_u32_off18_88837CB0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)&loc60[0]);
        fn_881B19A0((ts4_word)(ts4_word)&loc60[0]);
        fn_887BA228((ts4_word)(ts4_word)&loc80[0]);
        return 1;
    }
    fn_887BA228((ts4_word)(ts4_word)&loc80[0]);
    return 0;
}

/* Swing_DLL.xex 0x887D5120: if_set u32@0x98, ts4_handle_forward_88150770, fn_88169350, ts4_find_service, u32@0x0, u32@0x4c */
void ts4_if_set_u32_off98_887D5120(ts4_word a0, ts4_args3 sp1)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc54[1];
    ts4_word t2;
    ts4_word t8;
    ts4_word t9;
    ts4_word t12;
    ts4_word t15;
    ts4_word t18;

    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    loc50[0] = (ts4_word)((3293380608) | 59701);
    ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp1, (ts4_word)(ts4_word)&loc50[0]);
    t2 = loc58[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        fn_88169350((ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc58[0]);
        t8 = loc54[0];
        t9 = ts4_find_service((ts4_word)t8);
        if ((ts4_word)t9 != 0) {
            t12 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t9) + 0))) + 76))))((ts4_word)t9, (ts4_word)0);
            *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)t12;
        }
    }
    t15 = ts4_find_service((ts4_word)((797245440) | 25246));
    if ((ts4_word)t15 != 0) {
        t18 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t15) + 0))) + 76))))((ts4_word)t15, (ts4_word)0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)t18;
    } else {
        *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x887DBA08: if_call_seq lbl_880E6D30, fn_8862BE08, lbl_880E6DB0, fn_8862BE08, lbl_880E6E30, fn_8862BE08 */
void ts4_if_call_seq_lbl_880E6D30_887DBA08(ts4_word a0, ts4_word a1)
{
    unsigned char b80;
    unsigned char b81;
    unsigned char b82;
    unsigned char b83;
    unsigned char b84;
    unsigned char b85;
    unsigned char b86;
    unsigned char b87;
    ts4_word p8;
    ts4_word p13;
    ts4_word p23;
    ts4_word p28;
    ts4_word p37;
    ts4_word p42;
    ts4_word p51;
    ts4_word p56;
    ts4_word loc58[3];
    ts4_word loc78[3];
    ts4_word loc68[3];
    ts4_word loc88[3];
    ts4_word loc50[2];
    ts4_word t5;
    ts4_word t39;
    ts4_word t43;
    ts4_word t48;
    ts4_word t53;
    ts4_word t10;
    ts4_word t20;
    ts4_word t25;

    fn_8862BE08((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880E6D30);
    fn_8862BE08((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)lbl_880E6DB0);
    fn_8862BE08((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)lbl_880E6E30);
    fn_8862BE08((ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)lbl_880E6EB8);
    t5 = loc58[0];
    if ((ts4_word)(a1 & 0xff) != 0) {
        b80 = !((ts4_word)t5 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
        p37 = (ts4_word)b80;
        if ((ts4_word)(p37 & 0xff) == 0) {
            t39 = loc68[0];
            b81 = !((ts4_word)t39 != 0) || ((ts4_word)(loc68[1]) == (ts4_word)((983040) | 65535));
            p42 = (ts4_word)b81;
            if ((ts4_word)(p42 & 0xff) == 0) {
                t43 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)(ts4_word)&loc58[0]);
                *(unsigned char *)((char *)(ts4_word)(a0) + 21) = (unsigned char)t43;
                ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)lbl_880C95B6);
                ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)lbl_880C95B6);
            }
        }
        t48 = loc78[0];
        b82 = !((ts4_word)t48 != 0) || ((ts4_word)(loc78[1]) == (ts4_word)((983040) | 65535));
        p51 = (ts4_word)b82;
        if ((ts4_word)(p51 & 0xff) == 0) {
            t53 = loc88[0];
            b83 = !((ts4_word)t53 != 0) || ((ts4_word)(loc88[1]) == (ts4_word)((983040) | 65535));
            p56 = (ts4_word)b83;
            if ((ts4_word)(p56 & 0xff) == 0) {
                ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)lbl_880C95B6);
                ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)lbl_880C95B6);
                return;
            }
            return;
        }
        return;
    }
    b84 = !((ts4_word)t5 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p8 = (ts4_word)b84;
    if ((ts4_word)(p8 & 0xff) == 0) {
        t10 = loc68[0];
        b85 = !((ts4_word)t10 != 0) || ((ts4_word)(loc68[1]) == (ts4_word)((983040) | 65535));
        p13 = (ts4_word)b85;
        if ((ts4_word)(p13 & 0xff) == 0) {
            *(unsigned char *)((char *)loc50 + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 21));
            ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
            *(unsigned char *)((char *)loc50 + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 21));
            ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc50[0]);
        }
    }
    t20 = loc78[0];
    b86 = !((ts4_word)t20 != 0) || ((ts4_word)(loc78[1]) == (ts4_word)((983040) | 65535));
    p23 = (ts4_word)b86;
    if ((ts4_word)(p23 & 0xff) == 0) {
        t25 = loc88[0];
        b87 = !((ts4_word)t25 != 0) || ((ts4_word)(loc88[1]) == (ts4_word)((983040) | 65535));
        p28 = (ts4_word)b87;
        if ((ts4_word)(p28 & 0xff) == 0) {
            *(unsigned char *)((char *)loc50 + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 21));
            ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc78[0], (ts4_word)(ts4_word)&loc50[0]);
            *(unsigned char *)((char *)loc50 + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a0) + 21));
            ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc88[0], (ts4_word)(ts4_word)&loc50[0]);
        }
    }
    return;
}

/* Swing_DLL.xex 0x887ED958: loop_call_seq fn_88627EC0, fn_88923530, u32@0x1c, u32@0x2c, fn_881B91A0, u32@0x2c */
ts4_word ts4_loop_call_seq_fn_88627EC0_887ED958(ts4_word a0, ts4_args3 sp1)
{
    ts4_word c7;
    ts4_word lv8;
    ts4_word p10;
    ts4_word t1;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;

    t1 = sp1.w[2];
    fn_88627EC0((ts4_word)a0, sp1);
    t3 = fn_88923530((ts4_word)t1, sp1, (ts4_word)((2483421184) | 52047));
    t4 = *(ts4_word *)((char *)(ts4_word)(t3) + 28);
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)t4;
    t5 = fn_881B91A0((ts4_word)(a0 + 48), (ts4_word)t4);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t6 != 0) {
        lv8 = (ts4_word)0;
        c7 = (ts4_word)t6;
        do {
            *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((a0 + 48)) + 0))) + lv8) = (ts4_word)0;
            p10 = (ts4_word)(lv8 + 20);
            lv8 = p10;
        } while (--c7 != 0);
        *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
        return t5;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 8) = (unsigned char)0;
    return t5;
}

/* Swing_DLL.xex 0x887F17D0: if_get u32@0xe0, u32@lbl_88D45B1C, u32@0x27c, u32@0xc, lbl_88C6C018, u32@lbl_88C6C018 */
void ts4_if_get_u32_offe0_887F17D0(ts4_word a0)
{
    ts4_word t211;
    ts4_word t111;
    ts4_word t1;
    ts4_word p5;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 224);
    if (t1) {
        t211 = (*(ts4_word *)(12 + (char *)(ts4_word)(t1)));
        p5 = (ts4_word)t211;
    } else {
        t111 = (*(ts4_word *)(636 + (char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C))));
        p5 = (ts4_word)t111;
    }
    if ((ts4_word)p5 != (ts4_word)(*(ts4_word *)lbl_88C6C018)) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 72))))((ts4_word)a0, (ts4_word)(fn_887F0CA0((ts4_word)a0, (ts4_word)(ts4_word)lbl_88C6C018)), (ts4_word)1);
    }
    return;
}

/* Swing_DLL.xex 0x887F1A88: get u32@0x38, u32@0x0, lbl_88D48828, fn_887F0CA0, u32@0x48, vcall */
ts4_word ts4_get_u32_off38_887F1A88(int a0, int a1)
{

    return (((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)(72 + (char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)))))))((ts4_word)a0, (ts4_word)(fn_887F0CA0((ts4_word)a0, (ts4_word)(((*(volatile ts4_word *)((char *)(ts4_word)(a1) + 56)) << 2) + (ts4_word)lbl_88D48828))), (ts4_word)1));
}

/* Swing_DLL.xex 0x8884CD98: loop_get u32@0x4, u32@0xc, ts4_find_service, u32@0x4, fn_8892F038, u32@0x4 */
ts4_word ts4_loop_get_u32_off4_8884CD98(ts4_word a0, int a1)
{
    ts4_word t319;
    ts4_word t219;
    ts4_word t119;
    ts4_word p13;
    ts4_word p16;
    ts4_word lv17;
    ts4_word p21;
    ts4_word t3;
    ts4_word t2;
    ts4_word t8;
    ts4_word t11;
    int t12;
    int t18;

    t2 = *(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 12);
    if ((ts4_word)t2 == 0) {
        t3 = ts4_find_service((ts4_word)((3690266624) | 36475));
        fn_8892F038((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)0, (ts4_word)t3, (ts4_word)0, (ts4_word)0, (ts4_word)0);
    }
    t8 = *(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 4))) + 12);
    t319 = (*(volatile ts4_word *)((char *)(ts4_word)(t8) + 0));
    t219 = t319;
    t11 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t219) + 76))))((ts4_word)t8, (ts4_word)0);
    t12 = *(ts4_word *)((char *)(ts4_word)(t11) + 0);
    *(volatile ts4_word *)(16 + (char *)(ts4_word)(t11)) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t11) + 12) = (ts4_word)0;
    p13 = (ts4_word)0;
    if ((int)t12 != -1) {
        p13 = (ts4_word)(t12 + t11);
    }
    p16 = (ts4_word)0;
    if ((int)t12 != -1) {
        t119 = (*(ts4_word *)((char *)(ts4_word)(t11) + 4));
        p16 = (ts4_word)((((int)t119 * 660) + t12) + t11);
    }
    if ((ts4_word)p13 != (ts4_word)p16) {
        lv17 = (ts4_word)(p13 + 632);
        do {
            t18 = *(volatile ts4_word *)(16 + (char *)(ts4_word)(lv17));
            if ((int)t18 == (int)a1) {
                fn_881AD260((ts4_word)(lv17 + -632));
                *(volatile ts4_word *)((char *)(ts4_word)(lv17) + -8) = (ts4_word)((3751936000) | 45041);
                *(volatile ts4_word *)((char *)(ts4_word)(lv17) + 0) = (ts4_word)(45041 | (3751936000));
                *(volatile ts4_word *)((char *)(ts4_word)(lv17) + 4) = (ts4_word)((3751936000) | 45041);
                *(volatile ts4_word *)((char *)(ts4_word)(lv17) + -4) = (ts4_word)((91947008) | 19160);
                *(volatile ts4_word *)(8 + (char *)(ts4_word)(lv17)) = (ts4_word)0;
                *(volatile ts4_word *)((char *)(ts4_word)(lv17) + 16) = (ts4_word)a1;
                *(volatile unsigned char *)((char *)(ts4_word)(lv17) + 14) = (unsigned char)0;
            }
            p21 = (ts4_word)(lv17 + 660);
            lv17 = p21;
        } while ((ts4_word)(p21 + -632) != (ts4_word)p16);
    }
    return t11;
}

/* Swing_DLL.xex 0x88855060: if_get u32@0x54, u32@0x50, u32@lbl_88D459E0, fn_88853540 */
ts4_word ts4_if_get_u32_off54_88855060(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;
    ts4_word t1;

    (void)a2;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
    if (0 != (int)(t1 - t2)) {
        return fn_88853540((ts4_word)(*(volatile ts4_word *)lbl_88D459E0), (ts4_word)a1, *(ts4_sv *)((char *)(ts4_word)(a0) + 80), (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)(t1 - t2), (ts4_word)t2);
    }
    return a0;
}

/* Swing_DLL.xex 0x88885C18: if_get u32@lbl_88D45B1C, u32@lbl_88D45B20, fn_8816D220, u32@0x0, u32@0x4, vcall */
void ts4_if_get_u32_lbl_88D45B1C_88885C18(void)
{
    ts4_word t129;
    ts4_word p7;
    ts4_word p18;
    ts4_word p25;
    ts4_word t1;
    ts4_word t3;
    ts4_word t13;
    ts4_word t16;
    ts4_word t19;
    ts4_word t20;
    ts4_word t23;
    ts4_word t29;

    t1 = *(ts4_word *)lbl_88D45B1C;
    t3 = fn_8816D220((ts4_word)(*(volatile ts4_word *)lbl_88D45B20), (ts4_word)((1868562432) | 62886));
    p7 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t129 = (*(ts4_word *)((char *)(ts4_word)(t3) + 0));
        p7 = (ts4_word)(((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)(t129) + 4))))((ts4_word)t3));
    }
    *(ts4_word *)((char *)(ts4_word)(t1) + 676) = (ts4_word)p7;
    if ((ts4_word)p7 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p7) + 0))) + 40))))((ts4_word)p7, (ts4_word)1, (ts4_word)2048, (ts4_word)4, (ts4_word)((0) | 32768), (ts4_word)((0) | 32768));
    }
    t13 = fn_8816D220((ts4_word)(*(ts4_word *)lbl_88D45B20), (ts4_word)((1233649664) | 13377));
    if ((ts4_word)t13 == 0) {
        p18 = (ts4_word)0;
    } else {
        t16 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t13) + 0))) + 4))))((ts4_word)t13);
        p18 = (ts4_word)t16;
    }
    t19 = *(ts4_word *)lbl_88D45B20;
    *(volatile unsigned char *)((char *)(ts4_word)(p18) + 40) = (unsigned char)0;
    t20 = fn_8816D220((ts4_word)t19, (ts4_word)((2994536448) | 21324));
    if ((ts4_word)t20 == 0) {
        p25 = (ts4_word)0;
    } else {
        t23 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t20) + 0))) + 4))))((ts4_word)t20);
        p25 = (ts4_word)t23;
    }
    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(p25) + 0))) + 80))))((ts4_word)p25, (ts4_word)(ts4_word)lbl_880DF0EC);
    t29 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(p18) + 36) = (ts4_word)p25;
    *(ts4_word *)((char *)(ts4_word)(t29) + 544) = (ts4_word)p18;
    *(ts4_word *)((char *)(ts4_word)(t29) + 548) = (ts4_word)p18;
    return;
}

/* Swing_DLL.xex 0x888B9D50: if_call_seq u8@0xf0, lbl_880DC3F0, u8@0xf0, fn_8862BE08, lbl_880CA837, ts4_clone_byte_with_object_context */
void ts4_if_call_seq_u8_offf0_888B9D50(ts4_word a0)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p6;
    ts4_word p14;
    ts4_word loc60[6];
    ts4_word loc50[4];
    unsigned char t1;
    ts4_word t11;
    ts4_word t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 240);
    if ((ts4_word)t1 != 0) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 240) = (unsigned char)0;
        fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880DC3F0);
        t11 = loc50[0];
        b80 = !((ts4_word)t11 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
        p14 = (ts4_word)b80;
        if ((ts4_word)(p14 & 0xff) == 0) {
            ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc50[0], (ts4_word)((ts4_word)lbl_880CA837 + 2343));
            return;
        }
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 240) = (unsigned char)1;
    fn_8862BE08((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880DC3F0);
    t3 = loc60[0];
    b81 = !((ts4_word)t3 != 0) || ((ts4_word)(loc60[1]) == (ts4_word)((983040) | 65535));
    p6 = (ts4_word)b81;
    if ((ts4_word)(p6 & 0xff) == 0) {
        ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)lbl_880CA837);
    }
    return;
}

/* Swing_DLL.xex 0x888C5120: loop_call_seq u8@0x234, u8@0x235, u8@0x28e, u8@0x28c, u32@0x238, u32@0x2dc */
ts4_word ts4_loop_call_seq_u8_off234_888C5120(ts4_word a0)
{
    unsigned char b80;
    ts4_word p6;
    ts4_word lv9;
    ts4_word p11;
    unsigned char t1;
    unsigned char t3;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 564);
    if ((ts4_word)t1 == 0 || (ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 565)) != 0) {
        t3 = *(unsigned char *)((char *)(ts4_word)(a0) + 654);
        b80 = !((ts4_word)t3 == 0) && !((ts4_word)(*(unsigned char *)((char *)(ts4_word)(a0) + 652)) != 1);
        p6 = (ts4_word)b80;
        if ((ts4_word)(p6 & 0xff) != 0 || (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 568)) == 1) {
            *(ts4_word *)((char *)(ts4_word)(a0) + 732) = (ts4_word)1;
            *(ts4_word *)((char *)(ts4_word)(a0) + 736) = (ts4_word)4;
            fn_888C4E08((ts4_word)a0);
            lv9 = (ts4_word)0;
            do {
                fn_888C4B70((ts4_word)a0, (ts4_word)((int)lv9 >> 1), (ts4_word)(lv9 & 0x1));
                p11 = (ts4_word)(lv9 + 1);
                lv9 = p11;
            } while ((int)p11 < 4);
            *(unsigned char *)((char *)(ts4_word)(a0) + 564) = (unsigned char)1;
            *(unsigned char *)((char *)(ts4_word)(a0) + 565) = (unsigned char)0;
        }
    }
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 564));
}

/* Swing_DLL.xex 0x888C7718: loop_call_seq u8@0x51, u32@0x0, u32@0x4, u32@0x0, u32@0x4, u32@0xc */
void ts4_loop_call_seq_u8_off51_888C7718(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, int a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t231;
    ts4_word t131;
    ts4_word lv6;
    ts4_word lv9;
    ts4_word p16;
    ts4_word p21;
    unsigned char t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t10;
    ts4_word t12;
    ts4_word t15;
    ts4_word t31;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 81);
    if ((ts4_word)t1 == 0) {
        t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
        if ((ts4_word)t4 != (ts4_word)t5) {
            lv6 = (ts4_word)t4;
            do {
                t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
                if ((ts4_word)t7 != (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16))) {
                    lv9 = (ts4_word)t7;
                    do {
                        t10 = *(ts4_word *)((char *)(ts4_word)(lv9) + 0);
                        t131 = (*(ts4_word *)((char *)(ts4_word)(lv6) + 0));
                        t12 = fn_885646F8((ts4_word)t131, (ts4_word)t10);
                        if (t12) {
                            *(unsigned short *)((char *)(ts4_word)(lv6) + 14) = (unsigned short)(*(unsigned short *)((char *)(ts4_word)(lv9) + 14));
                            break;
                        }
                        t15 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
                        p16 = (ts4_word)(lv9 + 16);
                        lv9 = p16;
                    } while ((ts4_word)p16 != (ts4_word)t15);
                }
                p21 = (ts4_word)(lv6 + 16);
                lv6 = p21;
            } while ((ts4_word)p21 != (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
        }
        fn_888C75E8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 52)));
        fn_888C75E8((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)));
        t231 = (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
        fn_888C75E8((ts4_word)a0, (ts4_word)t231);
        t31 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
        *(unsigned char *)((char *)(ts4_word)(a0) + 81) = (unsigned char)(((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 72)) - t31) != 0);
    }
    return;
}

/* Swing_DLL.xex 0x888CEC78: if_call_seq ts4_handle_forward_88150770, u32@0x0, u32@0x4, ts4_handle_forward_88150770, lbl_880CBA06, ts4_clone_byte_with_object_context */
void ts4_if_call_seq_ts4_handle_forward_88150770_888CEC78(ts4_args3 sp0)
{
    unsigned char b80;
    ts4_word p6;
    ts4_word loc50[1];
    ts4_word loc58[3];
    ts4_word loc54[1];
    ts4_word t1;
    int t2;
    ts4_word t7;

    loc50[0] = (ts4_word)((2954821632) | 20373);
    t1 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc50[0]);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    b80 = !((int)t2 != 0) || ((ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4)) == (ts4_word)((983040) | 65535));
    p6 = (ts4_word)b80;
    if ((ts4_word)(p6 & 0xff) == 0) {
        loc54[0] = (ts4_word)((2954821632) | 20373);
        t7 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&sp0, (ts4_word)(ts4_word)&loc54[0]);
        ts4_clone_byte_with_object_context((ts4_word)t7, (ts4_word)(ts4_word)lbl_880CBA06);
    }
    return;
}

/* Swing_DLL.xex 0x888E00D8: if_call_seq lbl_880DAF20, fn_8862BE08, lbl_880CBA06, ts4_clone_byte_with_object_context */
void ts4_if_call_seq_lbl_880DAF20_888E00D8(void)
{
    unsigned char b80;
    ts4_word p6;
    ts4_word loc50[6];
    ts4_word t2;

    fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880DAF20);
    t2 = loc50[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
    p6 = (ts4_word)b80;
    if ((ts4_word)(p6 & 0xff) == 0) {
        ts4_clone_byte_with_object_context((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880CBA06);
    }
    return;
}

/* Swing_DLL.xex 0x888E75B8: loop_set u32@0x0, u32@0x8, u32@0x4, lbl_880D8234, fn_8862C0E8, fn_8860FF08 */
ts4_word ts4_loop_set_u32_off0_888E75B8(ts4_word a0, ts4_word a1)
{
    unsigned char b80;
    unsigned char b81;
    ts4_word p5;
    ts4_word p11;
    ts4_word loc80[4];
    ts4_word loca0[6];
    ts4_word loc60[4];
    ts4_word loc50[1];
    ts4_word loc90[4];
    ts4_word loc54[1];
    ts4_word loc58[2];
    ts4_word loc70[4];
    ts4_word t2;
    ts4_word t8;
    ts4_word t14;
    ts4_word t16;
    ts4_word t17;
    ts4_word t18;
    ts4_word t19;
    ts4_word t22;
    ts4_word t23;
    ts4_word t26;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    fn_8862C0E8((ts4_word)(ts4_word)&loc80[0], (ts4_word)(ts4_word)lbl_880D8234);
    t2 = loc80[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc80[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        loca0[0] = (ts4_word)0;
        loca0[2] = (ts4_word)0;
        loca0[1] = (ts4_word)((983040) | 65535);
        loca0[3] = (ts4_word)((983040) | 65535);
        fn_8860FF08((ts4_word)(ts4_word)&loca0[0], (ts4_word)(ts4_word)&loc80[0]);
        do {
            ts4_handle_forward_cached_8860FE90((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loca0[0]);
            t8 = loc60[0];
            b81 = !((ts4_word)t8 != 0) || ((ts4_word)(loc60[1]) == (ts4_word)((983040) | 65535));
            p11 = (ts4_word)b81;
            if ((ts4_word)(p11 & 0xff) != 0) {
                return a0;
            }
            loc50[0] = (ts4_word)((4262526976) | 53560);
            ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc90[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
            fn_88169350((ts4_word)(ts4_word)&loc54[0], (ts4_word)(ts4_word)&loc90[0]);
            t14 = loc54[0];
            if ((ts4_word)t14 == (ts4_word)a1) {
                loc58[0] = (ts4_word)((1913651200) | 44303);
                ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc70[0], (ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc58[0]);
                t16 = ts4_gp0_xdata_get_bool_88163C60((ts4_word)(ts4_word)&loc70[0]);
                if ((ts4_word)(t16 & 0xff) != 0) {
                    t17 = loc70[0];
                    t18 = loc70[1];
                    t19 = loc70[2];
                    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t17;
                    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t18;
                    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t19;
                    return a0;
                }
            }
            t22 = loca0[0];
            t23 = loca0[3];
            t26 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t22) + 0))) + 48))))((ts4_word)t22, (ts4_word)(ts4_word)&loca0[0], (ts4_word)t23);
            loca0[3] = (ts4_word)t26;
        } while (1);
    }
    return a0;
}

/* Swing_DLL.xex 0x888FDE30: if_get u8@0x43, fn_888C28A0, u32@0x30, lbl_88C6B8EC, u32@lbl_88D45934, u32@lbl_88D45964 */
void ts4_if_get_u8_off43_888FDE30(ts4_word a0)
{
    unsigned char b80;
    ts4_word p19;
    ts4_word loc50[4];
    unsigned char t1;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;
    ts4_word t10;
    ts4_word t13;
    ts4_word t16;
    ts4_word t23;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 67);
    if ((ts4_word)t1 == 0) {
        fn_888C28A0((ts4_word)a0);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    if ((ts4_word)t4 == (ts4_word)((2627207168) | 39591)) {
        ts4_if_call_seq_u32_off2c_888FA420((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 592));
        return;
    }
    if ((ts4_word)t4 == (ts4_word)((554106880) | 28964)) {
        fn_888FA4E0((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 592));
        return;
    }
    if ((ts4_word)t4 == (ts4_word)((1235222528) | 8458)) {
        ts4_if_get_u8_off35_888E63A8((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 592));
        return;
    }
    if ((ts4_word)t4 == (ts4_word)((203882496) | 60736)) {
        t5 = *(ts4_word *)lbl_88D45934;
        t7 = fn_888AD568((ts4_word)(*(ts4_word *)lbl_88D45964), (ts4_word)((t5 << 2) + (ts4_word)lbl_88C6B8EC));
        if ((ts4_word)t7 != 0) {
            t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 32))))((ts4_word)t7);
            if ((ts4_word)(t10 & 0xff) != 0) {
                t13 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 24))))((ts4_word)t7);
                if ((ts4_word)(t13 & 0xff) != 0) {
                    *(ts4_word *)lbl_88D45934 = (ts4_word)(((*(ts4_word *)lbl_88D45934) + -1) & 0x1);
                    fn_8862BE08((ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_880D875C);
                    t16 = loc50[0];
                    b80 = !((ts4_word)t16 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
                    p19 = (ts4_word)b80;
                    if ((ts4_word)(p19 & 0xff) == 0) {
                        ts4_get_u32_off0_8822AFE8((ts4_word)(ts4_word)&loc50[0], (ts4_word)(((*(ts4_word *)lbl_88D45934) << 2) + (ts4_word)lbl_88C6B8EC));
                    }
                    t23 = *(ts4_word *)lbl_88D45964;
                    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t23) + 0))) + 44))))((ts4_word)t23);
                }
            }
        }
        fn_888C2560((ts4_word)a0);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 44))) + 592));
    return;
}

/* Swing_DLL.xex 0x88914090: if_call_seq fn_88914028, u32@lbl_88D45B1C, u32@0x27c, ts4_handle_forward_88150770, ts4_get_u32_off0_8822AFE8 */
void ts4_if_call_seq_fn_88914028_88914090(ts4_args3 sp0, ts4_word a2)
{
    unsigned char b80;
    ts4_word p7;
    ts4_word loc58[3];
    ts4_word loc50[1];
    ts4_word loc68[3];
    ts4_word loc54[1];
    ts4_word t3;
    ts4_word t9;
    ts4_word t10;

    (void)sp0.w[2];
    fn_88914028((ts4_word)(ts4_word)&loc58[0], sp0, (ts4_word)a2);
    t3 = loc58[0];
    b80 = !((ts4_word)t3 != 0) || ((ts4_word)(loc58[1]) == (ts4_word)((983040) | 65535));
    p7 = (ts4_word)b80;
    if ((ts4_word)(p7 & 0xff) == 0) {
        t9 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_88D45B1C)) + 636);
        loc50[0] = (ts4_word)((4262526976) | 53560);
        loc54[0] = (ts4_word)t9;
        t10 = ts4_handle_forward_88150770((ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc58[0], (ts4_word)(ts4_word)&loc50[0]);
        ts4_get_u32_off0_8822AFE8((ts4_word)t10, (ts4_word)(ts4_word)&loc54[0]);
    }
    return;
}

/* Swing_DLL.xex 0x88923B48: if_get u32@0x0, u32@0x44, vcall, u32@0x0, u32@0x8, u32@0x4 */
void ts4_if_get_u32_off0_88923B48(int a0, ts4_word a1, ts4_word a2)
{
    ts4_word t4;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t9;
    unsigned short t10;
    ts4_word t11;

    if ((ts4_word)(((ts4_word (*)(ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 68))))((ts4_word)a0)) != 0) {
        t4 = *(ts4_word *)(0 + (char *)(ts4_word)(a0));
        t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
        t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 8);
        t7 = *(ts4_word *)((char *)(ts4_word)(t4) + 184);
        t9 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))(t7))((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t5) + 8)), (ts4_word)a1);
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t9;
        t10 = *(unsigned short *)((char *)(ts4_word)(t5) + 4);
        t11 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(t11 + t10);
        *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)t6;
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a2) + 4) = (ts4_word)(65535 | (983040));
    return;
}

/* Swing_DLL.xex 0x88943230: if_get u32@0x0, u32@0x3c, vcall, u32@0x0, u32@0x34, vcall */
ts4_word ts4_if_get_u32_off0_88943230(ts4_word a0)
{
    unsigned char b80;
    ts4_word p7;
    ts4_word loc50[4];
    ts4_word t4;
    ts4_word t9;

    ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 60))))((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0);
    t4 = loc50[0];
    b80 = !((ts4_word)t4 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
    p7 = (ts4_word)b80;
    if ((ts4_word)(p7 & 0xff) != 0) {
        return 0;
    }
    t9 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    (void)loc50[2];
    ((ts4_word (*)(ts4_word, ts4_args3))((*(ts4_word *)((char *)(ts4_word)(t9) + 52))))((ts4_word)a0, *(ts4_args3 *)&loc50[0]);
    return 1;
}

/* Swing_DLL.xex 0x88955A90: if_call_seq fn_88955970, u32@0x30, u32@0x30, fn_8860AB08 */
ts4_word ts4_if_call_seq_fn_88955970_88955A90(ts4_word a0, ts4_args3 sp1, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word t1;
    ts4_word t8;
    ts4_word t10;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = sp1.w[0];
    b80 = !((ts4_word)t1 != 0) || ((ts4_word)(sp1.w[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    if ((ts4_word)(p5 & 0xff) == 0) {
        (void)sp1.w[2];
        t8 = fn_88955970((ts4_word)a0, sp1);
        if ((ts4_word)(t8 & 0xff) != 0) {
            t10 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
            if ((ts4_word)t10 != 0) {
                fn_8860AB08((ts4_word)(ts4_word)&sp1);
            }
            return 0;
        }
        return 1;
    }
    return 0;
}

/* Swing_DLL.xex 0x88978A20: if_call_seq fn_88960168, fn_889728D8 */
ts4_word ts4_if_call_seq_fn_88960168_88978A20(ts4_word a0, ts4_word a1, ts4_word a2, float f1)
{
    unsigned char b80;
    ts4_word p5;
    ts4_word p8;
    ts4_word loc50[6];
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;

    t1 = fn_88960168((ts4_word)(ts4_word)&loc50[0], (ts4_word)a0, (ts4_word)a1);
    t2 = loc50[0];
    b80 = !((ts4_word)t2 != 0) || ((ts4_word)(loc50[1]) == (ts4_word)((983040) | 65535));
    p5 = (ts4_word)b80;
    p8 = (ts4_word)t1;
    if ((ts4_word)(p5 & 0xff) == 0) {
        (void)loc50[2];
        t7 = fn_889728D8(*(ts4_args3 *)&loc50[0], (ts4_word)a2, f1);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x889AF738: get u32@0x0, u32@0xc, u32@lbl_88C6B4AC, vcall, fn_889393C0, u32@0x430 */
void ts4_get_u32_off0_889AF738(ts4_word a0, ts4_word a1)
{
    ts4_word t110;
    ts4_word t3;
    ts4_word t2;
    ts4_word t6;
    int t4;

    t110 = (*(volatile ts4_word *)((char *)(ts4_word)(a0) + 0));
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t110) + 12);
    t3 = *(ts4_word *)lbl_88C6B4AC;
    t4 = ((ts4_word (*)(ts4_word))(t2))((ts4_word)a0);
    fn_889393C0((ts4_word)a1, (ts4_word)t4, (ts4_word)t3);
    t6 = *(volatile ts4_word *)(1072 + (char *)(ts4_word)(a0));
    ts4_if_call_seq_fn_88933EF8_889396A8((ts4_word)a1, (ts4_word)(((t6 + 7)) >> 3));
    fn_88939040((ts4_word)a1, (ts4_word)(((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 1068))) + 4))))((ts4_word)(a0 + 1068))), (ts4_word)(((t6 + 7)) >> 3));
    return;
}

/* Swing_DLL.xex 0x889C6230: if_get u32@0x0, u32@0x8, u32@0x0, u32@0x8, u8@0x0 */
void ts4_if_get_u32_off0_889C6230(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    int t2;
    int t3;
    unsigned char t4;

    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    if ((int)t2 >= (int)t3) {
        return;
    }
    t4 = *(unsigned char *)((char *)(ts4_word)(t1) + t2);
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t2 + 1);
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)t4;
    return;
}
