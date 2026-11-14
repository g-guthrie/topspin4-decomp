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

extern char lbl_880D5870[];
extern char lbl_880E14EC[];
extern char lbl_880E93EC[];
extern char lbl_880E9810[];
extern char lbl_880EE650[];
extern char lbl_88C476C0[];
extern char lbl_88C69510[];
extern char lbl_88C69544[];
extern char lbl_88C69734[];
extern char lbl_88C698A4[];
extern char lbl_88C6E1A8[];
extern char ts4_call_seq_u32_off34_8820F580[];
extern char ts4_call_seq_u32_off44_8820FBC0[];
extern char ts4_forward_float_from_ptr_881FBF90[];
extern char ts4_get_881FBF88[];
extern char ts4_get_u32_off0_881DD418[];
extern char ts4_get_u32_off70_887795B8[];
extern char ts4_if_call_seq_u32_lbl_88D41FC4_8820F5B8[];
extern char ts4_if_call_seq_u32_lbl_88D41FC4_8820FBF8[];
extern char ts4_noop_88778370[];
extern char ts4_vcall_slot9_881DD468[];
ts4_word KeTlsSetValue();
ts4_word fn_881C6D48();
ts4_word fn_881C70D8();
ts4_word fn_881C7920();
ts4_word fn_881DA660();
ts4_word fn_881DA880();
ts4_word fn_881DAFA8();
ts4_word fn_88580EB8();
ts4_word fn_88938F38();
ts4_word fn_889D01F8();
ts4_word fn_889D0270();
ts4_word fn_889D02D8();
ts4_word ts4_get_u32_lbl_88D4E11C_88581A90();
ts4_word ts4_if_call_seq_u32_off0_881C8A60();
ts4_word ts4_memset();
ts4_word ts4_set_u32_off0_889D18A0();

/* Swing_DLL.xex 0x8816CCE0: if_get u32@0x0, u32@0x0, u32@0x4, u32@0x30, vcall, u32@0x0 */
float ts4_if_get_u32_off0_8816CCE0(ts4_word a0)
{
    ts4_word s50;
    float s54;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t12;
    ts4_word t10;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(volatile ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(t2) + 48))))((ts4_word)t1, (ts4_word)t3, (ts4_word)3);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0);
    t7 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)(t5 & 0xff) == 0) {
        s50 = (ts4_word)(ts4_word)lbl_880D5870;
        t12 = *(volatile ts4_word *)((char *)(ts4_word)(t6) + 0);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)(t12) + 56))))((ts4_word)t6, (ts4_word)a0, (ts4_word)t7, (ts4_word)(ts4_word)&s54, (ts4_word)4, (ts4_word)(ts4_word)&s50, (ts4_word)t12, (ts4_word)(ts4_word)lbl_880D5870);
        return (s54);
    }
    t10 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(volatile ts4_word *)((char *)(ts4_word)((*(volatile ts4_word *)((char *)(ts4_word)(t6) + 0))) + 36))))((ts4_word)t6, (ts4_word)a0, (ts4_word)t7, (ts4_word)4);
    return (*(float *)((char *)(ts4_word)(t10) + 0));
}

/* Swing_DLL.xex 0x881DD520: call_seq lbl_88C698A4, u32@0x10, fn_881C6D48, u32@0x8, u32@0x8, fn_881DA660 */
void ts4_call_seq_lbl_88C698A4_881DD520(void)
{
    ts4_word s50;
    ts4_word s54;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C698A4) + 16);
    t2 = fn_881C6D48();
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8);
    s50 = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)((t3 & 0xff000001) | (((t3 & 0xfffffffe) + 2) & 0xfffffe));
    t4 = fn_881DA660((ts4_word)t2);
    t5 = fn_881DAFA8((ts4_word)t4, (ts4_word)(ts4_word)lbl_880E14EC, (ts4_word)4);
    s54 = (ts4_word)t5;
    fn_881C7920((ts4_word)(ts4_word)&s50, (ts4_word)(ts4_word)&s54, (ts4_word)27, (ts4_word)0, (ts4_word)0);
    t7 = s50;
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)(ts4_word)ts4_get_u32_off0_881DD418;
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 16) = (ts4_word)(ts4_word)ts4_vcall_slot9_881DD468;
    ts4_if_call_seq_u32_off0_881C8A60((ts4_word)t1, (ts4_word)(ts4_word)&s50);
    fn_881DA880((ts4_word)t5);
    fn_881C70D8((ts4_word)(ts4_word)&s50);
    return;
}

/* Swing_DLL.xex 0x881FBFA8: call_seq lbl_88C69734, u32@0x10, fn_881C6D48, u32@0x8, u32@0x8, fn_881DA660 */
void ts4_call_seq_lbl_88C69734_881FBFA8(void)
{
    ts4_word s50;
    ts4_word s54;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C69734) + 16);
    t2 = fn_881C6D48();
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8);
    s50 = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)((t3 & 0xff000001) | (((t3 & 0xfffffffe) + 2) & 0xfffffe));
    t4 = fn_881DA660((ts4_word)t2);
    t5 = fn_881DAFA8((ts4_word)t4, (ts4_word)(ts4_word)lbl_880E9810, (ts4_word)10);
    s54 = (ts4_word)t5;
    fn_881C7920((ts4_word)(ts4_word)&s50, (ts4_word)(ts4_word)&s54, (ts4_word)22, (ts4_word)0, (ts4_word)0);
    t7 = s50;
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)(ts4_word)ts4_get_881FBF88;
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 16) = (ts4_word)(ts4_word)ts4_forward_float_from_ptr_881FBF90;
    ts4_if_call_seq_u32_off0_881C8A60((ts4_word)t1, (ts4_word)(ts4_word)&s50);
    fn_881DA880((ts4_word)t5);
    fn_881C70D8((ts4_word)(ts4_word)&s50);
    return;
}

/* Swing_DLL.xex 0x8820F680: call_seq lbl_88C69544, u32@0x10, fn_881C6D48, u32@0x8, u32@0x8, fn_881DA660 */
void ts4_call_seq_lbl_88C69544_8820F680(void)
{
    ts4_word s50;
    ts4_word s54;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C69544) + 16);
    t2 = fn_881C6D48();
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8);
    s50 = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)((t3 & 0xff000001) | (((t3 & 0xfffffffe) + 2) & 0xfffffe));
    t4 = fn_881DA660((ts4_word)t2);
    t5 = fn_881DAFA8((ts4_word)t4, (ts4_word)(ts4_word)lbl_880E93EC, (ts4_word)9);
    s54 = (ts4_word)t5;
    fn_881C7920((ts4_word)(ts4_word)&s50, (ts4_word)(ts4_word)&s54, (ts4_word)26, (ts4_word)0, (ts4_word)0);
    t7 = s50;
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)(ts4_word)ts4_call_seq_u32_off34_8820F580;
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 16) = (ts4_word)(ts4_word)ts4_if_call_seq_u32_lbl_88D41FC4_8820F5B8;
    ts4_if_call_seq_u32_off0_881C8A60((ts4_word)t1, (ts4_word)(ts4_word)&s50);
    fn_881DA880((ts4_word)t5);
    fn_881C70D8((ts4_word)(ts4_word)&s50);
    return;
}

/* Swing_DLL.xex 0x8820FCC0: call_seq lbl_88C69510, u32@0x10, fn_881C6D48, u32@0x8, u32@0x8, fn_881DA660 */
void ts4_call_seq_lbl_88C69510_8820FCC0(void)
{
    ts4_word s50;
    ts4_word s54;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C69510) + 16);
    t2 = fn_881C6D48();
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8);
    s50 = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)((t3 & 0xff000001) | (((t3 & 0xfffffffe) + 2) & 0xfffffe));
    t4 = fn_881DA660((ts4_word)t2);
    t5 = fn_881DAFA8((ts4_word)t4, (ts4_word)(ts4_word)lbl_880E93EC, (ts4_word)9);
    s54 = (ts4_word)t5;
    fn_881C7920((ts4_word)(ts4_word)&s50, (ts4_word)(ts4_word)&s54, (ts4_word)26, (ts4_word)0, (ts4_word)0);
    t7 = s50;
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)(ts4_word)ts4_call_seq_u32_off44_8820FBC0;
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 16) = (ts4_word)(ts4_word)ts4_if_call_seq_u32_lbl_88D41FC4_8820FBF8;
    ts4_if_call_seq_u32_off0_881C8A60((ts4_word)t1, (ts4_word)(ts4_word)&s50);
    fn_881DA880((ts4_word)t5);
    fn_881C70D8((ts4_word)(ts4_word)&s50);
    return;
}

/* Swing_DLL.xex 0x887B5BD8: call_seq lbl_88C476C0, u32@0x10, fn_881C6D48, u32@0x8, u32@0x8, fn_881DA660 */
void ts4_call_seq_lbl_88C476C0_887B5BD8(void)
{
    ts4_word s50;
    ts4_word s54;
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;
    ts4_word t7;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)((ts4_word)lbl_88C476C0) + 16);
    t2 = fn_881C6D48();
    t3 = *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8);
    s50 = (ts4_word)t2;
    *(volatile ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)((t3 & 0xff000001) | (((t3 & 0xfffffffe) + 2) & 0xfffffe));
    t4 = fn_881DA660((ts4_word)t2);
    t5 = fn_881DAFA8((ts4_word)t4, (ts4_word)(ts4_word)lbl_880EE650, (ts4_word)5);
    s54 = (ts4_word)t5;
    fn_881C7920((ts4_word)(ts4_word)&s50, (ts4_word)(ts4_word)&s54, (ts4_word)20, (ts4_word)0, (ts4_word)0);
    t7 = s50;
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)(ts4_word)ts4_get_u32_off70_887795B8;
    *(volatile ts4_word *)((char *)(ts4_word)(t7) + 16) = (ts4_word)(ts4_word)ts4_noop_88778370;
    ts4_if_call_seq_u32_off0_881C8A60((ts4_word)t1, (ts4_word)(ts4_word)&s50);
    fn_881DA880((ts4_word)t5);
    fn_881C70D8((ts4_word)(ts4_word)&s50);
    return;
}

/* Swing_DLL.xex 0x889399B8: call_seq ts4_memset, u16@0x4, fn_88938F38, u32@0x8, fn_88938F38, u16@0x6 */
void ts4_call_seq_ts4_memset_889399B8(ts4_word a0, ts4_word a1)
{
    ts4_word s54;
    unsigned short h50;
    ts4_word t3;

    ts4_memset((ts4_word)(a0 + 4), (ts4_word)0, (ts4_word)16);
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 4) = (unsigned short)2;
    fn_88938F38((ts4_word)a1, (ts4_word)(ts4_word)&s54, (ts4_word)4);
    t3 = s54;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    fn_88938F38((ts4_word)a1, (ts4_word)(ts4_word)&h50, (ts4_word)2);
    *(volatile unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)(h50);
    return;
}

/* Swing_DLL.xex 0x889D14C8: if_call_seq fn_889D01F8, ts4_set_u32_off0_889D18A0, u32@lbl_88C6E1A8, KeTlsSetValue, u32@0x10, u32@0x14 */
void ts4_if_call_seq_fn_889D01F8_889D14C8(ts4_word a0, ts4_word a1)
{
    ts4_word t115;
    ts4_word s50;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t9;
    ts4_word t12;
    ts4_word t14;

    s50 = (ts4_word)28;
    t1 = fn_889D01F8((ts4_word)(ts4_word)&s50);
    t2 = ts4_set_u32_off0_889D18A0((ts4_word)t1, (ts4_word)a1, (ts4_word)0, (ts4_word)a0);
    KeTlsSetValue((ts4_word)(*(volatile ts4_word *)lbl_88C6E1A8), (ts4_word)t2);
    t5 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16);
    t6 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20);
    t115 = (*(volatile ts4_word *)((char *)(ts4_word)(a0) + 12));
    fn_889D02D8((ts4_word)t115, (ts4_word)t6, (ts4_word)t5);
    t9 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t9 != 0) {
        fn_889D0270((ts4_word)t9);
    }
    t12 = *(volatile ts4_word *)lbl_88C6E1A8;
    t14 = KeTlsSetValue((ts4_word)t12, (ts4_word)(*(volatile ts4_word *)((char *)(ts4_word)(t2) + 16)));
    fn_88580EB8((ts4_word)(ts4_get_u32_lbl_88D4E11C_88581A90((ts4_word)t14)), (ts4_word)0, (ts4_word)t2);
    return;
}
