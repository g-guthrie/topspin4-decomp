/* Swing_DLL.xex 0x8842D210-0x8842D298, executable version 0.0.0.3. */
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
extern short lbl_88B3D1E4;
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
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();

/* Swing_DLL.xex 0x8842D210: if_call_seq lbl_88040B78, ts4_if_call_seq_u32_off4_88428890, ts4_get_u32_off0_88428B30, u16@lbl_88B3D1E4, ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480, u16@lbl_88B3D1E4 */
ts4_word ts4_if_call_seq_lbl_88040B78_8842D210(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[2];
    ts4_word loc58[2];
    ts4_word loc60[2];
    ts4_word loc68[2];
    ts4_word t6;

    ts4_if_call_seq_u32_off4_88428890((ts4_word)(ts4_word)&loc50[0], (ts4_word)a1, (ts4_word)(ts4_word)lbl_88040B78);
    ts4_get_u32_off0_88428B30((ts4_word)(ts4_word)&loc58[0], (ts4_word)a0);
    if (lbl_88B3D1E4 == -1) {
        lbl_88B3D1E4 = (unsigned short)ts4_call_seq_ts4_call_seq_u32_off4_88428B48_8842B480((ts4_word)(ts4_word)&loc50[0]);
    }
    t6 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return fn_8842B568(ts4_call_seq_u32_off4_88428B48((ts4_word)(ts4_word)&loc68[0], ts4_if_call_seq_u32_off4_88428AC8((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0], (ts4_word)(ts4_word)lbl_88040B80)), (ts4_word)t6, (ts4_word)a2);
}
