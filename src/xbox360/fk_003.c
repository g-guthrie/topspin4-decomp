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

extern char lbl_880D61F4[];
extern char lbl_880DD088[];
extern char lbl_880E4BA0[];
extern char lbl_880E94A4[];
extern char lbl_880E96D8[];
extern char lbl_880E9AC0[];
extern char lbl_880E9BF0[];
extern char lbl_880E9C68[];
extern char lbl_880E9DF8[];
extern char lbl_880E9F50[];
extern char lbl_880EA174[];
extern char lbl_880EA1C8[];
extern char lbl_880EA318[];
extern char lbl_880EA5E4[];
extern char lbl_880EF46C[];
extern char lbl_880EF4A0[];
extern char lbl_880EF4BC[];
extern char lbl_880EF4D8[];
extern char lbl_880EF6C4[];
extern char lbl_880EF750[];
extern char lbl_880EF7B8[];
extern char lbl_880EF7EC[];
extern char lbl_880EFE30[];
extern char lbl_880EFE8C[];
extern char lbl_880F20FC[];
extern char lbl_880F2138[];
extern char lbl_880F22A8[];
extern char lbl_880F2480[];
extern char lbl_880F2508[];
extern char lbl_880F28EC[];
extern char lbl_880F30CC[];
extern char lbl_880F31D8[];
extern char lbl_880F3350[];
extern char lbl_880F3430[];
extern char lbl_88C69458[];
extern char lbl_88C69474[];
extern char lbl_88C6948C[];
extern char lbl_88C694A8[];
extern char lbl_88C694C0[];
extern char lbl_88C694DC[];
extern char lbl_88C694F4[];
extern char lbl_88C69510[];
extern char lbl_88C69528[];
extern char lbl_88C69544[];
extern char lbl_88C6955C[];
extern char lbl_88C69578[];
extern char lbl_88C69594[];
extern char lbl_88C695AC[];
extern char lbl_88C695C8[];
extern char lbl_88C695E0[];
extern char lbl_88C695FC[];
extern char lbl_88C69614[];
extern char lbl_88C69630[];
extern char lbl_88C69648[];
extern char lbl_88C69664[];
extern char lbl_88C6967C[];
extern char lbl_88C69698[];
extern char lbl_88C696B0[];
extern char lbl_88C696CC[];
extern char lbl_88C696E4[];
extern char lbl_88C69700[];
extern char lbl_88C69718[];
extern char lbl_88C69734[];
extern char lbl_88C6974C[];
extern char lbl_88C69768[];
extern char lbl_88C69780[];
extern char lbl_88C6979C[];
extern char lbl_88C697B4[];
extern char lbl_88D41FC0[];
extern char lbl_88D41FC4[];
extern char lbl_88D45A60[];
extern char lbl_88D45A6C[];
extern char lbl_88D45AD4[];
extern char lbl_88D45B1C[];
extern char lbl_88D45B38[];
ts4_word fn_88150600();
ts4_word fn_881519D0();
ts4_word fn_8816D1A8();
ts4_word ts4_if_atomic_interlocked_dec_881876D0();
ts4_word fn_8818EB10();
ts4_word fn_8818F1D8();
ts4_word fn_88199068();
ts4_word fn_881992A8();
ts4_word fn_8819ACC8();
ts4_word fn_8819B0C8();
ts4_word fn_8819C190();
ts4_word fn_881BD170();
ts4_word fn_881C38D0();
ts4_word fn_881C5BD8();
ts4_word fn_881C86B0();
ts4_word fn_881C88B0();
ts4_word fn_881CCD90();
ts4_word fn_881CCDF0();
ts4_word fn_881CCEE0();
ts4_word fn_881CE5B8();
ts4_word fn_881E1D70();
ts4_word fn_881E9010();
ts4_word fn_881F08F0();
ts4_word fn_881F2498();
ts4_word fn_881F4108();
ts4_word fn_881F41E8();
ts4_word fn_881F5DE0();
ts4_word fn_881F7958();
ts4_word fn_881FC068();
ts4_word fn_881FD7D8();
ts4_word fn_88201580();
ts4_word fn_882016F8();
ts4_word fn_88204E00();
ts4_word ts4_addr_fn_881F7958_88206B20();
ts4_word fn_882072F0();
ts4_word fn_8820AC88();
ts4_word fn_8820AF78();
ts4_word fn_8820B138();
ts4_word fn_8820B418();
ts4_word fn_8820CFB8();
ts4_word fn_8820D100();
ts4_word fn_8820E000();
ts4_word ts4_if_addr_lbl_880C1320_8820EF88();
ts4_word fn_8820F160();
ts4_word fn_8820F448();
ts4_word fn_8820F740();
ts4_word fn_8820FD80();
ts4_word fn_88212420();
ts4_word fn_88222338();
ts4_word fn_88223540();
ts4_word fn_88223B10();
ts4_word fn_88225790();
ts4_word fn_8822B6E0();
ts4_word fn_88255AA0();
ts4_word fn_88608590();
ts4_word fn_8860BBD8();
ts4_word fn_8860D250();
ts4_word fn_88613268();
ts4_word fn_88613570();
ts4_word fn_88617D28();
ts4_word fn_88617D88();
ts4_word fn_886E81D8();
ts4_word fn_887104B8();
ts4_word fn_8871FFB0();
ts4_word fn_88720018();
ts4_word ts4_call_seq_fn_88255AA0_88721960();
ts4_word fn_88721CB0();
ts4_word fn_887261D0();
ts4_word fn_88736DE8();
ts4_word fn_88745F58();
ts4_word fn_88746018();
ts4_word fn_887727B8();
ts4_word fn_88773078();
ts4_word fn_88773218();
ts4_word fn_8877DC48();
ts4_word fn_887816A0();
ts4_word fn_88781FC8();
ts4_word fn_88782060();
ts4_word fn_887823A8();
ts4_word fn_887827A8();
ts4_word fn_887855B8();
ts4_word fn_88785A00();
ts4_word ts4_singleton_service_ctor_8878BE98();
ts4_word fn_8879C218();
ts4_word fn_887A15A8();
ts4_word fn_887B53E8();
ts4_word ts4_call_seq_fn_881F1060_887B5CF8();
ts4_word fn_887B5E20();
ts4_word fn_887B6808();
ts4_word fn_887C4558();
ts4_word fn_887C8050();
ts4_word fn_887CB7B0();
ts4_word ts4_service_ctor_vec_887CBE90();
ts4_word fn_887CC248();
ts4_word fn_887EC668();
#ifndef _MSC_VER
#define memcpy ts4_host_memcpy
#endif
ts4_word memcpy();
ts4_word ts4_assign_formatted_text();
ts4_word ts4_destroy_owned_object();
ts4_word ts4_object_finalize();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x881F1B40: addr lbl_88C697B4 */
ts4_word ts4_addr_lbl_88C697B4_881F1B40(void)
{
    return (ts4_word)lbl_88C697B4;
}

/* Swing_DLL.xex 0x881F1B50: if_call_seq lbl_880E94A4, u32@0x4, u32@0x0, fn_8818EB10, u32@0x10, fn_88199068 */
ts4_word ts4_if_call_seq_lbl_880E94A4_881F1B50(ts4_word a0, ts4_word a1)
{
    ts4_word p3;
    ts4_word loc50[2];
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E94A4;
    fn_8818EB10((ts4_word)(a0 + 8), (ts4_word)a1);
    loc50[1] = (ts4_word)0;
    loc50[0] = (ts4_word)1000;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    t2 = fn_88199068((ts4_word)0, (ts4_word)16, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 12) = (ts4_word)0;
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    fn_881F2498((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)((a0 + 16)) + 0) = (ts4_word)p3;
    return a0;
}

/* Swing_DLL.xex 0x881F2748: addr lbl_88C69780 */
ts4_word ts4_addr_lbl_88C69780_881F2748(void)
{
    return (ts4_word)lbl_88C69780;
}

/* Swing_DLL.xex 0x881F2758: if_call_seq fn_88199068, fn_881F4108 */
ts4_word ts4_if_call_seq_fn_88199068_881F2758(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)36, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881F4108((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881F27D0: addr lbl_88C6979C */
ts4_word ts4_addr_lbl_88C6979C_881F27D0(void)
{
    return (ts4_word)lbl_88C6979C;
}

/* Swing_DLL.xex 0x881F27E0: get u32@0xc */
ts4_word ts4_get_u32_offc_881F27E0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 12));
}

/* Swing_DLL.xex 0x881F33B8: call_seq fn_881F5DE0, u8@0x23, u8@0x23 */
ts4_word ts4_call_seq_fn_881F5DE0_881F33B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a0;
    t1 = fn_881F5DE0((ts4_word)a1);
    *(float *)((char *)(ts4_word)(t1) + 0) = (*(float *)((char *)(ts4_word)(a2) + 0));
    *(unsigned char *)((char *)(ts4_word)(a1) + 35) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a1) + 35)) | 128);
    return t1;
}

/* Swing_DLL.xex 0x881F3430: call_seq fn_881F5DE0, u8@0x23, u8@0x23 */
ts4_word ts4_call_seq_fn_881F5DE0_881F3430(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a0;
    t1 = fn_881F5DE0((ts4_word)a1);
    *(float *)((char *)(ts4_word)(t1) + 4) = (*(float *)((char *)(ts4_word)(a2) + 0));
    *(unsigned char *)((char *)(ts4_word)(a1) + 35) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a1) + 35)) | 128);
    return t1;
}

/* Swing_DLL.xex 0x881F34A8: call_seq fn_881F5DE0, u8@0x23, u8@0x23 */
ts4_word ts4_call_seq_fn_881F5DE0_881F34A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a0;
    t1 = fn_881F5DE0((ts4_word)a1);
    *(float *)((char *)(ts4_word)(t1) + 8) = (*(float *)((char *)(ts4_word)(a2) + 0));
    *(unsigned char *)((char *)(ts4_word)(a1) + 35) = (unsigned char)((*(unsigned char *)((char *)(ts4_word)(a1) + 35)) | 128);
    return t1;
}

/* Swing_DLL.xex 0x881F4290: call_seq fn_8819B0C8, u8@0x22, u8@0x22 */
ts4_word ts4_call_seq_fn_8819B0C8_881F4290(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    return t1;
}

/* Swing_DLL.xex 0x881F78C0: addr lbl_88C69768 */
ts4_word ts4_addr_lbl_88C69768_881F78C0(void)
{
    return (ts4_word)lbl_88C69768;
}

/* Swing_DLL.xex 0x881F78D0: addr lbl_88C6974C */
ts4_word ts4_addr_lbl_88C6974C_881F78D0(void)
{
    return (ts4_word)lbl_88C6974C;
}

/* Swing_DLL.xex 0x881F78E0: if_call_seq fn_88199068, fn_881F7958 */
ts4_word ts4_if_call_seq_fn_88199068_881F78E0(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)12, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881F7958((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881F79D8: if_call_seq lbl_880E96D8, u32@0x0, fn_881C88B0, lbl_880DD088, u32@0x0, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880E96D8_881F79D8(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E96D8;
    fn_881C88B0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881F9080: if_get u32@0x20, u32@lbl_88D41FC0 */
ts4_word ts4_if_get_u32_off20_881F9080(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((int)t1 != 0) {
        return t1;
    }
    return (*(ts4_word *)lbl_88D41FC0);
}

/* Swing_DLL.xex 0x881FBD30: if_call_seq u32@0x14, fn_881992A8, u32@0x14, u32@0x1c, fn_881C5BD8 */
ts4_word ts4_if_call_seq_u32_off14_881FBD30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t1 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a1;
    fn_881C5BD8((ts4_word)a0);
    return 1;
}

/* Swing_DLL.xex 0x881FBEF0: addr lbl_88C69718 */
ts4_word ts4_addr_lbl_88C69718_881FBEF0(void)
{
    return (ts4_word)lbl_88C69718;
}

/* Swing_DLL.xex 0x881FBF00: if_call_seq fn_88199068, fn_881FC068 */
ts4_word ts4_if_call_seq_fn_88199068_881FBF00(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)104, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881FC068((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881FBF78: addr lbl_88C69734 */
ts4_word ts4_addr_lbl_88C69734_881FBF78(void)
{
    return (ts4_word)lbl_88C69734;
}

/* Swing_DLL.xex 0x881FD1A0: addr lbl_88C696E4 */
ts4_word ts4_addr_lbl_88C696E4_881FD1A0(void)
{
    return (ts4_word)lbl_88C696E4;
}

/* Swing_DLL.xex 0x881FD1B0: if_call_seq fn_88199068, fn_881FD7D8 */
ts4_word ts4_if_call_seq_fn_88199068_881FD1B0(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)184, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881FD7D8((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x881FD228: addr lbl_88C69700 */
ts4_word ts4_addr_lbl_88C69700_881FD228(void)
{
    return (ts4_word)lbl_88C69700;
}

/* Swing_DLL.xex 0x881FD408: get u32@0x60 */
ts4_word ts4_get_u32_off60_881FD408(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 96));
}

/* Swing_DLL.xex 0x881FD410: get u32@0x68 */
ts4_word ts4_get_u32_off68_881FD410(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 104));
}

/* Swing_DLL.xex 0x881FD4A0: get u8@0xa4 */
ts4_word ts4_get_u8_offa4_881FD4A0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(unsigned char *)((char *)(ts4_word)(a1) + 164));
}

/* Swing_DLL.xex 0x881FD4A8: get u8@0x22 */
ts4_word ts4_get_u8_off22_881FD4A8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return ((*(unsigned char *)((char *)(ts4_word)(a1) + 34)) != 0);
}

/* Swing_DLL.xex 0x882011B0: addr lbl_88C696B0 */
ts4_word ts4_addr_lbl_88C696B0_882011B0(void)
{
    return (ts4_word)lbl_88C696B0;
}

/* Swing_DLL.xex 0x882011C0: if_addr fn_88199068, fn_881F4108, lbl_880E9AC0, u32@0x0, fn_881519D0, u32@0x0 */
ts4_word ts4_if_addr_fn_88199068_882011C0(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t6;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)40, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_881F4108((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880E9AC0;
        t3 = fn_881519D0((ts4_word)t2);
        t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 16))))((ts4_word)t3);
        *(ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)(t6 + 16);
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x88201258: if_addr fn_881F4108, lbl_880E9AC0, u32@0x0, fn_881519D0, u32@0x0, u32@0x10 */
ts4_word ts4_if_addr_fn_881F4108_88201258(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    if ((ts4_word)a0 != 0) {
        t1 = fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9AC0;
        t2 = fn_881519D0((ts4_word)t1);
        t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(t5 + 16);
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x882012D0: addr lbl_88C696CC */
ts4_word ts4_addr_lbl_88C696CC_882012D0(void)
{
    return (ts4_word)lbl_88C696CC;
}

/* Swing_DLL.xex 0x88201448: if_call_seq u32@lbl_88D41FC4, fn_881E9010, ts4_if_atomic_interlocked_dec_881876D0 */
ts4_word ts4_if_call_seq_u32_lbl_88D41FC4_88201448(ts4_word a0)
{
    ts4_word p5;
    ts4_word loc50[1];
    ts4_word t3;
    ts4_word t4;

    fn_881E9010((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)lbl_88D41FC4), (ts4_word)(a0 + 36));
    t3 = loc50[0];
    p5 = (ts4_word)t3;
    if ((ts4_word)t3 != 0) {
        t4 = ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t3);
        p5 = (ts4_word)t4;
    }
    return p5;
}

/* Swing_DLL.xex 0x88201488: call_seq fn_8819B0C8, u8@0x22, u8@0x22, fn_8819B0C8 */
ts4_word ts4_call_seq_fn_8819B0C8_88201488(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    t3 = fn_8819B0C8((ts4_word)(a0 + 36), (ts4_word)(a1 + 36));
    return t3;
}

/* Swing_DLL.xex 0x88201698: get fn_881519D0, u32@0x0, u32@0x10, vcall, u8@0x4, u32@0x0 */
ts4_word ts4_get_fn_881519D0_88201698(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = fn_881519D0();
    t4 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(t4 + 16);
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x882037A8: call_seq fn_8819B0C8, u8@0x4, u8@0x4, u8@0x5, u8@0x5, u8@0x6 */
ts4_word ts4_call_seq_fn_8819B0C8_882037A8(ts4_word a0, ts4_word a1)
{
    fn_8819B0C8();
    *(unsigned char *)((char *)(ts4_word)(a0) + 4) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 4));
    *(unsigned char *)((char *)(ts4_word)(a0) + 5) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 5));
    *(unsigned char *)((char *)(ts4_word)(a0) + 6) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 6));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    return a0;
}

/* Swing_DLL.xex 0x882043F8: if_call_seq u32@0x18, fn_8818F1D8, fn_88201580, u32@0x4, u32@0x0, u32@0x18 */
ts4_word ts4_if_call_seq_u32_off18_882043F8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = fn_8818F1D8((ts4_word)a0);
    if ((ts4_word)t2 != 0) {
        fn_88201580((ts4_word)(t2 + 8), (ts4_word)a1);
    }
    *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)0;
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28)) + 1);
    if ((ts4_word)t5 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t5) + 0) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t2;
        return t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x88204630: if_call_seq u32@0x14, fn_8818F1D8, fn_882016F8, u32@0x0, u32@0x4, u32@0x14 */
ts4_word ts4_if_call_seq_u32_off14_88204630(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = fn_8818F1D8((ts4_word)a0);
    if ((ts4_word)t2 != 0) {
        fn_882016F8((ts4_word)(t2 + 8), (ts4_word)a1);
    }
    *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 28)) + 1);
    if ((ts4_word)t5 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t5) + 4) = (ts4_word)t2;
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t2;
        return t2;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t2;
    return t2;
}

/* Swing_DLL.xex 0x882049C8: addr lbl_88C6967C */
ts4_word ts4_addr_lbl_88C6967C_882049C8(void)
{
    return (ts4_word)lbl_88C6967C;
}

/* Swing_DLL.xex 0x882049D8: if_call_seq fn_88199068, fn_88204E00 */
ts4_word ts4_if_call_seq_fn_88199068_882049D8(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)168, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_88204E00((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88204A50: addr lbl_88C69698 */
ts4_word ts4_addr_lbl_88C69698_88204A50(void)
{
    return (ts4_word)lbl_88C69698;
}

/* Swing_DLL.xex 0x88204A60: get u8@0x8d */
ts4_word ts4_get_u8_off8d_88204A60(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(unsigned char *)((char *)(ts4_word)(a1) + 141));
}

/* Swing_DLL.xex 0x88204A68: get u8@0x0, u8@0x8d */
void ts4_get_u8_off0_88204A68(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 141) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x88204A90: get u8@0x0, u32@0x7c */
void ts4_get_u8_off0_88204A90(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(ts4_word *)((char *)(ts4_word)(a1) + 124) = (ts4_word)((*(unsigned char *)((char *)(ts4_word)(a2) + 0)) == 0);
    return;
}

/* Swing_DLL.xex 0x88204AA8: get u8@0x98 */
ts4_word ts4_get_u8_off98_88204AA8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(unsigned char *)((char *)(ts4_word)(a1) + 152));
}

/* Swing_DLL.xex 0x88204AB0: get u8@0x0, u8@0x98 */
void ts4_get_u8_off0_88204AB0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 152) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x88204AC0: get  */
float ts4_get_88204AC0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 132));
}

/* Swing_DLL.xex 0x88204AC8: get  */
float ts4_get_88204AC8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 156));
}

/* Swing_DLL.xex 0x88204AD0: get  */
float ts4_get_88204AD0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(ts4_word)(a1) + 160));
}

/* Swing_DLL.xex 0x88204AD8: get u8@0x0, u8@0xa4 */
void ts4_get_u8_off0_88204AD8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 164) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x88204E90: if_call_seq lbl_880E9BF0, u32@0x0, fn_881E1D70, fn_8820D100, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880E9BF0_88204E90(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9BF0;
    fn_881E1D70((ts4_word)(a0 + 116));
    fn_8820D100((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88206840: call_seq fn_8820F160, u32@0x78, u32@0x78, u8@0x8c, u8@0x8c */
ts4_word ts4_call_seq_fn_8820F160_88206840(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8820F160();
    *(ts4_word *)((char *)(ts4_word)(a0) + 120) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 120));
    *(float *)((char *)(ts4_word)(a0) + 128) = (*(float *)((char *)(ts4_word)(a1) + 128));
    *(unsigned char *)((char *)(ts4_word)(a0) + 140) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 140));
    *(float *)((char *)(ts4_word)(a0) + 136) = (*(float *)((char *)(ts4_word)(a1) + 136));
    return t1;
}

/* Swing_DLL.xex 0x88206A88: addr lbl_88C69648 */
ts4_word ts4_addr_lbl_88C69648_88206A88(void)
{
    return (ts4_word)lbl_88C69648;
}

/* Swing_DLL.xex 0x88206A98: if_call_seq fn_88199068, ts4_addr_fn_881F7958_88206B20 */
ts4_word ts4_if_call_seq_fn_88199068_88206A98(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)16, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = ts4_addr_fn_881F7958_88206B20((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88206B10: addr lbl_88C69664 */
ts4_word ts4_addr_lbl_88C69664_88206B10(void)
{
    return (ts4_word)lbl_88C69664;
}

/* Swing_DLL.xex 0x88206B78: call_seq fn_8819B0C8, fn_881C86B0 */
ts4_word ts4_call_seq_fn_8819B0C8_88206B78(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    t2 = fn_881C86B0((ts4_word)(a0 + 8), (ts4_word)(a1 + 8));
    return t2;
}

/* Swing_DLL.xex 0x88207140: get u32@0x34 */
ts4_word ts4_get_u32_off34_88207140(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
}

/* Swing_DLL.xex 0x88207148: get u32@0x24 */
ts4_word ts4_get_u32_off24_88207148(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Swing_DLL.xex 0x88207250: get u32@0x88 */
ts4_word ts4_get_u32_off88_88207250(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 136));
}

/* Swing_DLL.xex 0x88207258: addr lbl_88C69614 */
ts4_word ts4_addr_lbl_88C69614_88207258(void)
{
    return (ts4_word)lbl_88C69614;
}

/* Swing_DLL.xex 0x88207268: if_call_seq fn_88199068, fn_882072F0 */
ts4_word ts4_if_call_seq_fn_88199068_88207268(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)192, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_882072F0((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882072E0: addr lbl_88C69630 */
ts4_word ts4_addr_lbl_88C69630_882072E0(void)
{
    return (ts4_word)lbl_88C69630;
}

/* Swing_DLL.xex 0x88207420: if_call_seq lbl_880E9DF8, u32@0x5c, u32@0x0, u32@0x58, fn_8820AC88, u32@0x3c */
ts4_word ts4_if_call_seq_lbl_880E9DF8_88207420(ts4_word a0)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t8;
    ts4_word t11;

    *(ts4_word *)((char *)(ts4_word)(a0) + 92) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9DF8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    fn_8820AC88((ts4_word)(a0 + 72));
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 60);
    if ((ts4_word)t2 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t2);
    }
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t5 != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)t5);
    }
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((ts4_word)t8 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t8);
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    }
    t11 = fn_881F41E8((ts4_word)a0);
    return t11;
}

/* Swing_DLL.xex 0x88209318: get u32@0x7c */
ts4_word ts4_get_u32_off7c_88209318(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 124));
}

/* Swing_DLL.xex 0x8820A298: if_get u32@0x0, u32@0x28, vcall, u32@0x0, u32@0x2c, vcall */
ts4_word ts4_if_get_u32_off0_8820A298(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t6;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 40))))((ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 44))))((ts4_word)a0);
    if ((ts4_word)a1 >= (ts4_word)t3) {
        return 0;
    }
    if ((ts4_word)t6 != 0) {
        fn_8820AF78((ts4_word)(a0 + 12), (ts4_word)((int)t6 * (int)a1), (ts4_word)t6);
    }
    fn_8820B138((ts4_word)(a0 + 44), (ts4_word)a1);
    return 1;
}

/* Swing_DLL.xex 0x8820B380: addr lbl_88C695E0 */
ts4_word ts4_addr_lbl_88C695E0_8820B380(void)
{
    return (ts4_word)lbl_88C695E0;
}

/* Swing_DLL.xex 0x8820B390: if_call_seq fn_88199068, fn_8820B418 */
ts4_word ts4_if_call_seq_fn_88199068_8820B390(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)68, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_8820B418((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8820B408: addr lbl_88C695FC */
ts4_word ts4_addr_lbl_88C695FC_8820B408(void)
{
    return (ts4_word)lbl_88C695FC;
}

/* Swing_DLL.xex 0x8820BE00: if_call_seq u32@0x0, u32@0x4, fn_881992A8, fn_881992A8, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off0_8820BE00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p6;
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    p6 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 4);
        if ((ts4_word)t2 != 0) {
            fn_881992A8((ts4_word)0, (ts4_word)t2);
        }
        t5 = fn_881992A8((ts4_word)0, (ts4_word)t1);
        p6 = (ts4_word)t5;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return p6;
}

/* Swing_DLL.xex 0x8820BE68: addr lbl_88C695AC */
ts4_word ts4_addr_lbl_88C695AC_8820BE68(void)
{
    return (ts4_word)lbl_88C695AC;
}

/* Swing_DLL.xex 0x8820BF08: if_call_seq fn_881F4108, lbl_880E9F50, u32@0x24, u32@0x0, u32@0x28, u32@0x2c */
ts4_word ts4_if_call_seq_fn_881F4108_8820BF08(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881F4108((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E9F50;
        *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x8820BF80: addr lbl_88C695C8 */
ts4_word ts4_addr_lbl_88C695C8_8820BF80(void)
{
    return (ts4_word)lbl_88C695C8;
}

/* Swing_DLL.xex 0x8820C5D0: call_seq fn_8819B0C8, u8@0x22, u8@0x22, u32@0x24, u32@0x24 */
ts4_word ts4_call_seq_fn_8819B0C8_8820C5D0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    return t1;
}

/* Swing_DLL.xex 0x8820C620: addr lbl_88C69578 */
ts4_word ts4_addr_lbl_88C69578_8820C620(void)
{
    return (ts4_word)lbl_88C69578;
}

/* Swing_DLL.xex 0x8820C630: if_call_seq fn_88199068, fn_8820CFB8 */
ts4_word ts4_if_call_seq_fn_88199068_8820C630(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)116, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_8820CFB8((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8820C6A8: addr lbl_88C69594 */
ts4_word ts4_addr_lbl_88C69594_8820C6A8(void)
{
    return (ts4_word)lbl_88C69594;
}

/* Swing_DLL.xex 0x8820CA58: call_seq fn_8820E000, fn_8819ACC8 */
ts4_word ts4_call_seq_fn_8820E000_8820CA58(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a1;
    t1 = fn_8820E000((ts4_word)a2);
    fn_8819ACC8((ts4_word)a0, (ts4_word)t1);
    return a0;
}

/* Swing_DLL.xex 0x8820CAE0: get u32@0x50 */
ts4_word ts4_get_u32_off50_8820CAE0(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 80));
}

/* Swing_DLL.xex 0x8820CB70: get u32@0x54 */
ts4_word ts4_get_u32_off54_8820CB70(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(ts4_word)(a1) + 84));
}

/* Swing_DLL.xex 0x8820CB78: call_seq u32@0x0, ts4_if_addr_lbl_880C1320_8820EF88 */
ts4_word ts4_call_seq_u32_off0_8820CB78(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word loc50[1];
    ts4_word t2;

    (void)a0;
    loc50[0] = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 0));
    t2 = ts4_if_addr_lbl_880C1320_8820EF88((ts4_word)a1, (ts4_word)(ts4_word)&loc50[0]);
    return t2;
}

/* Swing_DLL.xex 0x8820D998: get  */
float ts4_get_8820D998(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 64));
}

/* Swing_DLL.xex 0x8820D9A0: get  */
float ts4_get_8820D9A0(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 60));
}

/* Swing_DLL.xex 0x8820DB68: if_call_seq fn_8820F448, u8@0x70, fn_8819C190 */
ts4_word ts4_if_call_seq_fn_8820F448_8820DB68(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    t1 = fn_8820F448((ts4_word)(a0 + 52), (ts4_word)a1);
    if ((ts4_word)(t1 & 0xff) != 0) {
        *(unsigned char *)((char *)(ts4_word)(a0) + 112) = (unsigned char)1;
    }
    t3 = fn_8819C190((ts4_word)(a0 + 52), (ts4_word)a1);
    return t3;
}

/* Swing_DLL.xex 0x8820F4D8: addr lbl_88C6955C */
ts4_word ts4_addr_lbl_88C6955C_8820F4D8(void)
{
    return (ts4_word)lbl_88C6955C;
}

/* Swing_DLL.xex 0x8820F4E8: addr lbl_88C69528 */
ts4_word ts4_addr_lbl_88C69528_8820F4E8(void)
{
    return (ts4_word)lbl_88C69528;
}

/* Swing_DLL.xex 0x8820F4F8: if_call_seq fn_88199068, fn_8820F740 */
ts4_word ts4_if_call_seq_fn_88199068_8820F4F8(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)96, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_8820F740((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8820F570: addr lbl_88C69544 */
ts4_word ts4_addr_lbl_88C69544_8820F570(void)
{
    return (ts4_word)lbl_88C69544;
}

/* Swing_DLL.xex 0x8820F580: call_seq u32@0x34, fn_8818EB10 */
ts4_word ts4_call_seq_u32_off34_8820F580(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    fn_8818EB10((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 52)) + 12));
    return a0;
}

/* Swing_DLL.xex 0x8820F7B8: if_call_seq u32@0x34, ts4_if_atomic_interlocked_dec_881876D0, u32@0x34, fn_881CCDF0, fn_881992A8 */
ts4_word ts4_if_call_seq_u32_off34_8820F7B8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)0;
    }
    fn_881CCDF0((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8820FB28: addr lbl_88C694F4 */
ts4_word ts4_addr_lbl_88C694F4_8820FB28(void)
{
    return (ts4_word)lbl_88C694F4;
}

/* Swing_DLL.xex 0x8820FB38: if_call_seq fn_88199068, fn_8820FD80 */
ts4_word ts4_if_call_seq_fn_88199068_8820FB38(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)72, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_8820FD80((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8820FBB0: addr lbl_88C69510 */
ts4_word ts4_addr_lbl_88C69510_8820FBB0(void)
{
    return (ts4_word)lbl_88C69510;
}

/* Swing_DLL.xex 0x8820FBC0: call_seq u32@0x44, fn_8818EB10 */
ts4_word ts4_call_seq_u32_off44_8820FBC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a1;
    fn_8818EB10((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 68)) + 12));
    return a0;
}

/* Swing_DLL.xex 0x8820FDF8: if_call_seq u32@0x44, ts4_if_atomic_interlocked_dec_881876D0, u32@0x44, fn_881CCDF0, fn_881992A8 */
ts4_word ts4_if_call_seq_u32_off44_8820FDF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 68);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 68) = (ts4_word)0;
    }
    fn_881CCDF0((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88210E78: addr lbl_88C694C0 */
ts4_word ts4_addr_lbl_88C694C0_88210E78(void)
{
    return (ts4_word)lbl_88C694C0;
}

/* Swing_DLL.xex 0x88210E88: if_call_seq fn_88199068, fn_881CCD90, lbl_880EA174, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_88210E88(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)52, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        fn_881CCD90((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880EA174;
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x88210F08: if_call_seq fn_881CCD90, lbl_880EA174, u32@0x0 */
ts4_word ts4_if_call_seq_fn_881CCD90_88210F08(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        fn_881CCD90((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA174;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88210F68: addr lbl_88C694DC */
ts4_word ts4_addr_lbl_88C694DC_88210F68(void)
{
    return (ts4_word)lbl_88C694DC;
}

/* Swing_DLL.xex 0x88210FD8: call_seq fn_881CCEE0 */
ts4_word ts4_call_seq_fn_881CCEE0_88210FD8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_881CCEE0((ts4_word)a0, (ts4_word)a1);
    return ((t1 & 0xff) != 0);
}

/* Swing_DLL.xex 0x88211010: addr lbl_88C6948C */
ts4_word ts4_addr_lbl_88C6948C_88211010(void)
{
    return (ts4_word)lbl_88C6948C;
}

/* Swing_DLL.xex 0x88211020: if_call_seq fn_88199068, ts4_addr_fn_881F7958_88206B20, lbl_880EA1C8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88199068_88211020(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)32, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        ts4_addr_fn_881F7958_88206B20((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(t1) + 0) = (ts4_word)(ts4_word)lbl_880EA1C8;
        return t1;
    }
    return 0;
}

/* Swing_DLL.xex 0x882110A0: if_call_seq ts4_addr_fn_881F7958_88206B20, lbl_880EA1C8, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88206B20_882110A0(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        ts4_addr_fn_881F7958_88206B20((ts4_word)a0);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA1C8;
        return a0;
    }
    return 0;
}

/* Swing_DLL.xex 0x88211100: addr lbl_88C694A8 */
ts4_word ts4_addr_lbl_88C694A8_88211100(void)
{
    return (ts4_word)lbl_88C694A8;
}

/* Swing_DLL.xex 0x88211118: call_seq fn_881CE5B8 */
ts4_word ts4_call_seq_fn_881CE5B8_88211118(ts4_word a0, ts4_word a1)
{
    fn_881CE5B8((ts4_word)a0, (ts4_word)a1);
    return 1;
}

/* Swing_DLL.xex 0x88211148: addr lbl_88C69458 */
ts4_word ts4_addr_lbl_88C69458_88211148(void)
{
    return (ts4_word)lbl_88C69458;
}

/* Swing_DLL.xex 0x88211238: addr lbl_88C69474 */
ts4_word ts4_addr_lbl_88C69474_88211238(void)
{
    return (ts4_word)lbl_88C69474;
}

/* Swing_DLL.xex 0x882114A0: if_call_seq fn_8819B0C8, u8@0x22, u8@0x22, u32@0x24, fn_881F08F0, fn_881C38D0 */
ts4_word ts4_if_call_seq_fn_8819B0C8_882114A0(ts4_word a0, ts4_word a1)
{
    ts4_word p8;
    ts4_word loc50[1];
    ts4_word t4;
    ts4_word t6;
    ts4_word t7;

    fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 34));
    t4 = fn_881F08F0((ts4_word)(ts4_word)&loc50[0], (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36)));
    fn_881C38D0((ts4_word)(a0 + 36), (ts4_word)t4);
    t6 = loc50[0];
    p8 = (ts4_word)t6;
    if ((ts4_word)t6 != 0) {
        t7 = ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t6);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x88211A08: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887CC248 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88211A08(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)888, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887CC248((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88211A60: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x0, u32@0x0, fn_887CB7B0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88211A60(ts4_word a0, ts4_word a1)
{
    ts4_word p6;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
        t5 = fn_887CB7B0((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t3);
        p6 = (ts4_word)t5;
    } else {
        p6 = (ts4_word)0;
    }
    return p6;
}

/* Swing_DLL.xex 0x88211C30: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887EC668, lbl_880EA318, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88211C30(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)84, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_887EC668((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EA318;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88211CA8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887EC668, lbl_880EA318, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88211CA8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)84, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_887EC668((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EA318;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88211D20: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_service_ctor_vec_887CBE90 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88211D20(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_service_ctor_vec_887CBE90((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88211D78: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_service_ctor_vec_887CBE90 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88211D78(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_service_ctor_vec_887CBE90((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88211FD0: if_call_seq lbl_880EA5E4, u32@lbl_88D45B1C, u32@0x0, u32@0x280, fn_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880EA5E4_88211FD0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D45B1C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA5E4;
    *(ts4_word *)((char *)(ts4_word)(t1) + 640) = (ts4_word)0;
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88212370: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887C8050 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88212370(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)380, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887C8050((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882123C8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887C8050 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882123C8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)380, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887C8050((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882124A8: if_call_seq u32@0xc, ts4_if_atomic_interlocked_dec_881876D0, u32@0xc, u32@0x10, ts4_if_atomic_interlocked_dec_881876D0, u32@0x10 */
ts4_word ts4_if_call_seq_u32_offc_882124A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p22;
    ts4_word t1;
    ts4_word t4;
    ts4_word t7;
    ts4_word t14;
    ts4_word t17;
    ts4_word t20;
    ts4_word t21;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t4 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t4);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t7 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t7);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)));
    ts4_destroy_owned_object((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)));
    t14 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    if ((ts4_word)t14 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t14);
        *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    }
    t17 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    if ((ts4_word)t17 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t17);
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    }
    t20 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    p22 = (ts4_word)t20;
    if ((ts4_word)t20 != 0) {
        t21 = ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t20);
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
        p22 = (ts4_word)t21;
    }
    return p22;
}

/* Swing_DLL.xex 0x882125E0: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_882125E0(ts4_word a0, ts4_word a1)
{
    ts4_word t10;
    ts4_word t11;
    ts4_word t16;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    fn_881C38D0((ts4_word)(a0 + 16), (ts4_word)(a1 + 16));
    fn_881C38D0((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    fn_881C38D0((ts4_word)(a0 + 20), (ts4_word)(a1 + 20));
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 36));
    *(unsigned char *)((char *)(ts4_word)(a0) + 76) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 76));
    fn_88150600((ts4_word)(a0 + 24), (ts4_word)(a1 + 24));
    t10 = *(ts4_word *)((char *)(ts4_word)(a1) + 40);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)t10;
    t11 = *(ts4_word *)((char *)(ts4_word)(a1) + 44);
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)t11;
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    t16 = fn_88150600((ts4_word)(a0 + 64), (ts4_word)(a1 + 64), (ts4_word)t11, (ts4_word)t10);
    *(unsigned char *)((char *)(ts4_word)(a0) + 77) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 77));
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 80));
    return t16;
}

/* Swing_DLL.xex 0x882126B8: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_882126B8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    fn_881C38D0((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    fn_881C38D0((ts4_word)(a0 + 16), (ts4_word)(a1 + 16));
    fn_881C38D0((ts4_word)(a0 + 20), (ts4_word)(a1 + 20));
    fn_88150600((ts4_word)(a0 + 24), (ts4_word)(a1 + 24));
    *(unsigned char *)((char *)(ts4_word)(a0) + 36) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40));
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 44));
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 48));
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 52));
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 56));
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 60));
    fn_88150600((ts4_word)(a0 + 64), (ts4_word)(a1 + 64));
    *(unsigned char *)((char *)(ts4_word)(a0) + 76) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 76));
    *(unsigned char *)((char *)(ts4_word)(a0) + 77) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 77));
    *(ts4_word *)((char *)(ts4_word)(a0) + 80) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 80));
    return a0;
}

/* Swing_DLL.xex 0x88212D78: if_call_seq lbl_880EF4BC, u32@0x0, fn_8877DC48, lbl_880E4BA0, u32@0x0, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880EF4BC_88212D78(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF4BC;
    fn_8877DC48((ts4_word)(a0 + 36));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    fn_8860BBD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88212DF0: if_call_seq lbl_880EF4D8, u32@0x0, fn_8877DC48, lbl_880E4BA0, u32@0x0, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880EF4D8_88212DF0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF4D8;
    fn_8877DC48((ts4_word)(a0 + 100));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    fn_8860BBD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88212E68: if_call_seq lbl_880EF4A0, u32@0x0, fn_8877DC48, lbl_880E4BA0, u32@0x0, fn_8860BBD8 */
ts4_word ts4_if_call_seq_lbl_880EF4A0_88212E68(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF4A0;
    fn_8877DC48((ts4_word)(a0 + 44));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880E4BA0;
    fn_8860BBD8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88213210: if_call_seq fn_88199068, fn_887816A0 */
ts4_word ts4_if_call_seq_fn_88199068_88213210(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)544, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_887816A0((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88213288: if_call_seq fn_88199068, fn_887B5E20 */
ts4_word ts4_if_call_seq_fn_88199068_88213288(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)112, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_887B5E20((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88213370: if_call_seq fn_88199068, fn_887B6808 */
ts4_word ts4_if_call_seq_fn_88199068_88213370(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)180, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_887B6808((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88213440: if_call_seq fn_88199068, ts4_call_seq_fn_881F1060_887B5CF8 */
ts4_word ts4_if_call_seq_fn_88199068_88213440(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)152, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = ts4_call_seq_fn_881F1060_887B5CF8((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88213510: if_call_seq fn_88199068, fn_887B53E8 */
ts4_word ts4_if_call_seq_fn_88199068_88213510(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)48, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_887B53E8((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88213588: if_call_seq lbl_880EF750, u32@0x0, fn_881F41E8, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880EF750_88213588(ts4_word a0, ts4_word a1)
{

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EF750;
    fn_881F41E8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x882136C8: get u32@lbl_88D45A60, u32@0x204, u32@0x4, vcall, u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_lbl_88D45A60_882136C8(void)
{
    ts4_word t1;
    ts4_word t10;

    t1 = *(ts4_word *)lbl_88D45A60;
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 516))) + 4))))((ts4_word)(t1 + 516));
    ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 8))))((ts4_word)t1);
    t10 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 516))) + 8))))((ts4_word)(t1 + 516));
    return t10;
}

/* Swing_DLL.xex 0x88213840: if_call_seq fn_88199068, fn_887C4558 */
ts4_word ts4_if_call_seq_fn_88199068_88213840(void)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    loc50[0] = (ts4_word)1000;
    loc50[1] = (ts4_word)0;
    t1 = fn_88199068((ts4_word)0, (ts4_word)288, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 != 0) {
        t2 = fn_887C4558((ts4_word)t1);
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88213A30: if_call_seq u32@0x1c, ts4_if_atomic_interlocked_dec_881876D0, u32@0x1c, fn_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_u32_off1c_88213A30(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((ts4_word)t1 != 0) {
        ts4_if_atomic_interlocked_dec_881876D0((ts4_word)t1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    }
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88214848: if_call_seq u32@lbl_88D45B38, fn_8860D250, fn_88613570 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88214848(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45B38;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8860D250((ts4_word)t1);
        p3 = (ts4_word)t2;
    } else {
        p3 = (ts4_word)0;
    }
    t4 = fn_88613570((ts4_word)p3, (ts4_word)(a1 << 6), (ts4_word)4, (ts4_word)a0);
    return t4;
}

/* Swing_DLL.xex 0x88215110: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887827A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88215110(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887827A8((ts4_word)t2, (ts4_word)a0);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88215360: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88781FC8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88215360(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1620, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88781FC8((ts4_word)t2, (ts4_word)a0);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882153D0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88782060 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882153D0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)1672, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88782060((ts4_word)t2, (ts4_word)a0);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88215860: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88785A00 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88215860(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)560, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88785A00((ts4_word)t2, (ts4_word)a0);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882158D0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887823A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882158D0(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)4260, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887823A8((ts4_word)t2, (ts4_word)a0);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88215940: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887855B8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88215940(ts4_word a0)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)2168, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887855B8((ts4_word)t2, (ts4_word)a0);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88215AF8: if_call_seq u32@lbl_88D45B38, fn_88613268, u32@0x4, u32@0x0, u32@0x8, u8@0xc */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88215AF8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)548, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)3;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 12) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 13) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 14) = (unsigned char)0;
        *(unsigned char *)((char *)(ts4_word)(t2) + 15) = (unsigned char)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 532) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 536) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 540) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 544) = (ts4_word)0;
        *(unsigned short *)((char *)(ts4_word)(t2) + 18) = (unsigned short)0;
        *(unsigned short *)((char *)(ts4_word)(t2) + 274) = (unsigned short)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88215B88: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880EF46C, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88215B88(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)15416, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EF46C;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 15412) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882171A8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880EF6C4, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882171A8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EF6C4;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217218: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880EF6C4, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217218(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)12, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EF6C4;
        *(ts4_word *)((char *)(ts4_word)(t2) + 8) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882173B8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887A15A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882173B8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)840, (ts4_word)8, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887A15A8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217410: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887A15A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217410(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)840, (ts4_word)8, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887A15A8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217618: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880EF7B8, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217618(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EF7B8;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217680: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880EF7B8, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217680(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EF7B8;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882176E8: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880EF7EC, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882176E8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EF7EC;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217750: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880EF7EC, u32@0x4, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217750(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)8, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EF7EC;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882177B8: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_singleton_service_ctor_8878BE98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882177B8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_singleton_service_ctor_8878BE98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217810: if_call_seq u32@lbl_88D45B38, fn_88613268, ts4_singleton_service_ctor_8878BE98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217810(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = ts4_singleton_service_ctor_8878BE98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217868: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8879C218 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217868(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)76, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8879C218((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882178C0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8879C218 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882178C0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)76, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8879C218((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882185C0: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_882185C0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    fn_881BD170((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 40));
    return a0;
}

/* Swing_DLL.xex 0x8821A350: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88773218 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A350(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)140, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88773218((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A3A8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88773218 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A3A8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)140, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88773218((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A400: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88773078 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A400(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)208, (ts4_word)16, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88773078((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A458: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88773078 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A458(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)208, (ts4_word)16, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88773078((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A560: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880EFE30, u32@0x0, fn_8816D1A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A560(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EFE30;
        fn_8816D1A8((ts4_word)(t2 + 28));
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A5E0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880EFE30, u32@0x0, fn_8816D1A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A5E0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)40, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EFE30;
        fn_8816D1A8((ts4_word)(t2 + 28));
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A660: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880EFE8C, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A660(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EFE8C;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A6D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880EFE8C, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A6D8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880EFE8C;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A750: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887727B8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A750(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)200, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887727B8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A7A8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887727B8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A7A8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)200, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887727B8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821AF48: if_call_seq lbl_880F2138, u32@0x0, fn_88223B10, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F2138_8821AF48(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2138;
    fn_88223B10((ts4_word)(a0 + 4));
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8821B378: fn  */
ts4_word ts4_fn_8821B378(void)
{
    return 16;
}

/* Swing_DLL.xex 0x8821B420: fn  */
ts4_word ts4_fn_8821B420(void)
{
    return 8;
}

/* Swing_DLL.xex 0x8821B428: if_call_seq lbl_880F20FC, u32@0x0, ts4_object_finalize, fn_88745F58, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880F20FC_8821B428(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F20FC;
    ts4_object_finalize((ts4_word)(a0 + 300));
    fn_88745F58((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8821B560: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_8821B560(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    fn_8822B6E0((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    return a0;
}

/* Swing_DLL.xex 0x8821B688: call_seq u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
ts4_word ts4_call_seq_u32_off0_8821B688(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    fn_88150600((ts4_word)(a0 + 24), (ts4_word)(a1 + 24));
    fn_88150600((ts4_word)(a0 + 36), (ts4_word)(a1 + 36));
    return a0;
}

/* Swing_DLL.xex 0x8821C010: call_seq u32@0x0, u32@0x8, u32@0x4, u32@0xc, u32@0x14, u32@0x10 */
ts4_word ts4_call_seq_u32_off0_8821C010(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((983040) | 65535);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)((983040) | 65535);
    fn_8816D1A8((ts4_word)(a0 + 24));
    fn_8816D1A8((ts4_word)(a0 + 36));
    return a0;
}

/* Swing_DLL.xex 0x8821D7B0: if_call_seq u32@0x2c, ts4_destroy_owned_object, u32@0x20, ts4_destroy_owned_object, fn_88617D28, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_u32_off2c_8821D7B0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    ts4_word t4;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    if ((ts4_word)t1 != 0) {
        ts4_destroy_owned_object((ts4_word)t1);
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t4 != 0) {
        ts4_destroy_owned_object((ts4_word)t4);
    }
    fn_88617D28((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8821FC18: call_seq u32@0x0, u32@0x4, u32@0x8, fn_88255AA0, u32@0xc */
ts4_word ts4_call_seq_u32_off0_8821FC18(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    fn_88255AA0((ts4_word)(a0 + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8821FFE8: if_call_seq u32@0xc, u32@0x4, u32@0x0, ts4_assign_formatted_text, u32@0x4, u32@0x4 */
ts4_word ts4_if_call_seq_u32_offc_8821FFE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p5;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        p5 = (ts4_word)t2;
        if ((ts4_word)t2 != 0) {
            t4 = ts4_assign_formatted_text((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)a1);
            p5 = (ts4_word)t4;
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 12);
        return p5;
    }
    t7 = fn_88225790((ts4_word)a0, (ts4_word)t2, (ts4_word)a1);
    return t7;
}

/* Swing_DLL.xex 0x882224D8: call_seq fn_88608590, fn_88222338 */
ts4_word ts4_call_seq_fn_88608590_882224D8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_88608590((ts4_word)0, (ts4_word)a2);
    t2 = fn_88222338((ts4_word)a0, (ts4_word)a1, (ts4_word)t1);
    return t2;
}

/* Swing_DLL.xex 0x88223C30: call_seq lbl_880F3430, u32@0x0, fn_88223540, u32@0x10, u8@0xa0, u8@0xa1 */
ts4_word ts4_call_seq_lbl_880F3430_88223C30(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F3430;
    fn_88223540((ts4_word)(a0 + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 160) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 161) = (unsigned char)0;
    return a0;
}

/* Swing_DLL.xex 0x88224E60: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_88224E60(ts4_word a0, ts4_word a1)
{
    float t8;
    float t9;
    float t10;
    float t11;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(unsigned char *)((char *)(ts4_word)(a0) + 12) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 13) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 13));
    *(unsigned char *)((char *)(ts4_word)(a0) + 14) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 14));
    *(unsigned char *)((char *)(ts4_word)(a0) + 15) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 15));
    t8 = *(float *)((char *)(ts4_word)(a1) + 16);
    t9 = *(float *)((char *)(ts4_word)(a1) + 28);
    t10 = *(float *)((char *)(ts4_word)(a1) + 24);
    t11 = *(float *)((char *)(ts4_word)(a1) + 20);
    *(float *)((char *)(ts4_word)(a0) + 16) = t8;
    *(float *)((char *)(ts4_word)(a0) + 20) = t11;
    *(float *)((char *)(ts4_word)(a0) + 24) = t10;
    *(float *)((char *)(ts4_word)(a0) + 28) = t9;
    *(float *)((char *)(ts4_word)(a0) + 32) = (*(float *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 40));
    *(unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 41));
    *(unsigned char *)((char *)(ts4_word)(a0) + 42) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 42));
    *(unsigned char *)((char *)(ts4_word)(a0) + 43) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 43));
    *(unsigned char *)((char *)(ts4_word)(a0) + 44) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 44));
    *(unsigned char *)((char *)(ts4_word)(a0) + 45) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 45));
    *(unsigned char *)((char *)(ts4_word)(a0) + 46) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 46));
    *(unsigned char *)((char *)(ts4_word)(a0) + 47) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 47));
    return;
}

/* Swing_DLL.xex 0x88228478: call_seq u32@0x0, lbl_880F2508, u32@0x4, u32@0x14, u32@0x8, u32@0xc */
ts4_word ts4_call_seq_u32_off0_88228478(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_880F2508;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 48) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 49) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 24) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 64) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 60) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 72) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 52) = (ts4_word)(ts4_word)lbl_880F2508;
    *(ts4_word *)((char *)(ts4_word)(a0) + 84) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 92) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 93) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 68) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 104) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 96) = (ts4_word)(ts4_word)lbl_880F2508;
    *(ts4_word *)((char *)(ts4_word)(a0) + 128) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 132) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 136) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 137) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 112) = (unsigned char)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 144) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 160) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 140) = (ts4_word)(ts4_word)lbl_880F2508;
    *(ts4_word *)((char *)(ts4_word)(a0) + 172) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 176) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 180) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 181) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 156) = (unsigned char)0;
    memcpy((ts4_word)(a0 + 8), (ts4_word)a1, (ts4_word)176);
    *(ts4_word *)((char *)(ts4_word)(a0) + 184) = (ts4_word)0;
    return a0;
}

/* Swing_DLL.xex 0x8822AF50: if_call_seq u32@lbl_88D45AD4, u32@lbl_88D45B38, fn_88613268, fn_88746018, lbl_880F3350, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45AD4_8822AF50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t7;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AD4;
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + ((65536) | 22144)));
    }
    t7 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)336, (ts4_word)4, (ts4_word)p4, (ts4_word)2);
    if ((ts4_word)t7 != 0) {
        fn_88746018((ts4_word)t7);
        *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)(ts4_word)lbl_880F3350;
        return t7;
    }
    return 0;
}

/* Swing_DLL.xex 0x8822AFE8: get u32@0x0, u32@0x4, u32@0x0, u32@0x28, vcall, u32@0x0 */
ts4_word ts4_get_u32_off0_8822AFE8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 40))))((ts4_word)t1, (ts4_word)a0, (ts4_word)t2, (ts4_word)4);
    *(ts4_word *)((char *)(ts4_word)(t5) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return t5;
}

/* Swing_DLL.xex 0x8822B1B0: if_get u32@0x0, u32@0x0, u32@0x4, u32@0x30, vcall, u32@0x0 */
ts4_word ts4_if_get_u32_off0_8822B1B0(ts4_word a0)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t11;
    ts4_word t14;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t2) + 48))))((ts4_word)t1, (ts4_word)t3, (ts4_word)7);
    t6 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)(t5 & 0xff) == 0) {
        loc50[0] = (ts4_word)(ts4_word)lbl_880D61F4;
        t8 = *(ts4_word *)((char *)(ts4_word)(t6) + 0);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t8) + 56))))((ts4_word)t6, (ts4_word)a0, (ts4_word)t7, (ts4_word)(ts4_word)&loc54[0], (ts4_word)4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t8, (ts4_word)(ts4_word)lbl_880D61F4);
        t11 = loc54[0];
        return t11;
    }
    t14 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t6) + 0))) + 36))))((ts4_word)t6, (ts4_word)a0, (ts4_word)t7, (ts4_word)4);
    return (*(ts4_word *)((char *)(ts4_word)(t14) + 0));
}

/* Swing_DLL.xex 0x8822BC48: if_call_seq u32@lbl_88D45AD4, u32@lbl_88D45B38, fn_88613268, fn_887104B8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45AD4_8822BC48(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t7;
    ts4_word t8;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AD4;
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + ((65536) | 22144)));
    }
    t7 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)324, (ts4_word)4, (ts4_word)p4, (ts4_word)2);
    if ((ts4_word)t7 != 0) {
        t8 = fn_887104B8((ts4_word)t7);
        return t8;
    }
    return 0;
}

/* Swing_DLL.xex 0x8822BCC0: if_call_seq u32@lbl_88D45AD4, u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F28EC, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45AD4_8822BCC0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t7;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AD4;
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + ((65536) | 22144)));
    }
    t7 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)28, (ts4_word)4, (ts4_word)p4, (ts4_word)2);
    if ((ts4_word)t7 != 0) {
        fn_88617D88((ts4_word)t7);
        *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)(ts4_word)lbl_880F28EC;
        return t7;
    }
    return 0;
}

/* Swing_DLL.xex 0x8822BD58: if_call_seq u32@lbl_88D45AD4, u32@lbl_88D45B38, fn_88613268, fn_886E81D8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45AD4_8822BD58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t7;
    ts4_word t8;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AD4;
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + ((65536) | 22144)));
    }
    t7 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)p4, (ts4_word)2);
    if ((ts4_word)t7 != 0) {
        t8 = fn_886E81D8((ts4_word)t7);
        return t8;
    }
    return 0;
}

/* Swing_DLL.xex 0x8822BDD0: if_call_seq u32@lbl_88D45AD4, u32@lbl_88D45B38, fn_88613268, fn_887261D0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45AD4_8822BDD0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t7;
    ts4_word t8;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AD4;
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + ((65536) | 22144)));
    }
    t7 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)92, (ts4_word)4, (ts4_word)p4, (ts4_word)2);
    if ((ts4_word)t7 != 0) {
        t8 = fn_887261D0((ts4_word)t7);
        return t8;
    }
    return 0;
}

/* Swing_DLL.xex 0x8822C018: if_get u32@0x4, u32@0x0, u32@0x0, u32@0x0, u32@0x30, vcall */
ts4_word ts4_if_get_u32_off4_8822C018(ts4_word a0, ts4_word a1)
{
    ts4_word loc50[1];
    ts4_word loc54[1];
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;
    ts4_word t9;
    ts4_word t12;
    ts4_word t15;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t1 == (ts4_word)((983040) | 65535)) {
        return (*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t6 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 48))))((ts4_word)t3, (ts4_word)t1, (ts4_word)7);
    t7 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t8 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)(t6 & 0xff) == 0) {
        loc50[0] = (ts4_word)(ts4_word)lbl_880F31D8;
        t9 = *(ts4_word *)((char *)(ts4_word)(t7) + 0);
        ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)(t9) + 56))))((ts4_word)t7, (ts4_word)a0, (ts4_word)t8, (ts4_word)(ts4_word)&loc54[0], (ts4_word)4, (ts4_word)(ts4_word)&loc50[0], (ts4_word)t9, (ts4_word)(ts4_word)lbl_880F31D8);
        t12 = loc54[0];
        return t12;
    }
    t15 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t7) + 0))) + 36))))((ts4_word)t7, (ts4_word)a0, (ts4_word)t8, (ts4_word)4);
    return (*(ts4_word *)((char *)(ts4_word)(t15) + 0));
}

/* Swing_DLL.xex 0x8822D2A8: if_call_seq u32@lbl_88D45AD4, u32@lbl_88D45B38, fn_88613268, ts4_call_seq_fn_88255AA0_88721960 */
ts4_word ts4_if_call_seq_u32_lbl_88D45AD4_8822D2A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;
    ts4_word t7;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AD4;
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + ((65536) | 22144)));
    }
    t7 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)16, (ts4_word)4, (ts4_word)p4, (ts4_word)2);
    if ((ts4_word)t7 != 0) {
        ts4_call_seq_fn_88255AA0_88721960((ts4_word)t7);
        return t7;
    }
    return 0;
}

/* Swing_DLL.xex 0x88234420: if_call_seq u32@lbl_88D45AD4, u32@lbl_88D45B38, fn_88613268, fn_88255AA0, u32@0x0, u32@0x4 */
ts4_word ts4_if_call_seq_u32_lbl_88D45AD4_88234420(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word p10;
    ts4_word loc50[1];
    ts4_word t1;
    ts4_word t7;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)lbl_88D45AD4;
    p4 = (ts4_word)0;
    if ((ts4_word)t1 != 0) {
        p4 = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + ((65536) | 22144)));
    }
    t7 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)16, (ts4_word)4, (ts4_word)p4, (ts4_word)2);
    if ((ts4_word)t7 != 0) {
        loc50[0] = (ts4_word)0;
        fn_88255AA0((ts4_word)(ts4_word)&loc50[0]);
        *(ts4_word *)((char *)(ts4_word)(t7) + 0) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t7) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)(t7) + 8) = (ts4_word)0;
        fn_88255AA0((ts4_word)(t7 + 8));
        *(ts4_word *)((char *)(ts4_word)(t7) + 12) = (ts4_word)0;
        p10 = (ts4_word)t7;
    } else {
        p10 = (ts4_word)0;
    }
    return p10;
}

/* Swing_DLL.xex 0x88235780: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88720018 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88235780(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88720018((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882357D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88720018 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882357D8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)68, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88720018((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88235830: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F30CC, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88235830(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F30CC;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882358A8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F30CC, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882358A8(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F30CC;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88235B20: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88721CB0, lbl_880F22A8, u32@0x0, u32@lbl_88D45A6C */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88235B20(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88721CB0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F22A8;
        *(ts4_word *)lbl_88D45A6C = (ts4_word)t2;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88235BA0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88721CB0, lbl_880F22A8, u32@0x0, u32@lbl_88D45A6C */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88235BA0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)44, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        fn_88721CB0((ts4_word)t2);
        *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F22A8;
        *(ts4_word *)lbl_88D45A6C = (ts4_word)t2;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88235C20: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88736DE8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88235C20(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88736DE8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88235C78: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88736DE8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88235C78(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)116, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88736DE8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88235CD0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8871FFB0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88235CD0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8871FFB0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88235D28: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8871FFB0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88235D28(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)52, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8871FFB0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8823F818: if_addr lbl_880F2480, lbl_880F2508, u32@0x0, u32@0x4, u32@0x4, u32@0x8 */
void ts4_if_addr_lbl_880F2480_8823F818(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2480;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F2508;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 24));
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 28));
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 32));
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 36));
    *(unsigned char *)((char *)(ts4_word)(a0) + 40) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 40));
    *(unsigned char *)((char *)(ts4_word)(a0) + 41) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 41));
    return;
}
