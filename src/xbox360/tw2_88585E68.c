/* Twin of 0x88585F00 (ts4_if_call_seq_u32_off2c_88585F00 in src/xbox360/fam6_w_000.c). */
#if defined(__clang__)
#pragma GCC diagnostic ignored "-Wmacro-redefined"
#endif
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;
typedef struct ts4_sv { ts4_word v; } ts4_sv; /* a one-word struct passed by value */
#ifdef _MSC_VER
#ifdef __cplusplus
#endif
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
extern char g_ts4_event_value[];
extern char lbl_88C6B4AC[];
extern char lbl_88C6B8EC[];
extern char lbl_88C6C018[];
extern char lbl_88CACF08[];
extern char lbl_88CAD32C[];
extern char lbl_88D2EE2C[];
ts4_word NtWaitForSingleObjectEx();
ts4_word NtReadFile();
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
#ifndef _MSC_VER
#define memset ts4_host_memset
#endif

/* Swing_DLL.xex 0x88585E68: if_call_seq u32@0x2c, lbl_88D2EE2C, u32@0x28, u32@0x8, u32@0x8, NtReadFile */
ts4_word ts4_if_call_seq_u32_off2c_88585E68(ts4_word a0, int a1, int a2, ts4_u64 a3)
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
    t204 = (*(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE2C) + 4));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t104 = t204;
    *(ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88D2EE2C) + 4) = (ts4_word)(t104 + 1);
    t4 = NtReadFile((ts4_word)t2, (ts4_word)t1, (ts4_word)0, (ts4_word)0, (ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)&loc58[0]);
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
