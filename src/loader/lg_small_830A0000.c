/* Loader_DLL.xex 0x830A0000-0x830AE550, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char __imp_KeCertMonitorData[];
extern char lbl_83084C60[];
extern char lbl_83084C80[];
extern char lbl_83084CA8[];
extern char lbl_83084CD4[];
extern char lbl_83085968[];
extern char lbl_83085D50[];
extern char lbl_83085D60[];
extern char lbl_83085D7C[];
extern char lbl_83085DA8[];
extern char lbl_83085DB0[];
extern char lbl_83085E48[];
extern char lbl_83085F50[];
extern char lbl_83085F98[];
extern char lbl_83086B00[];
extern char lbl_83544EC4[];
extern char lbl_83544EC8[];
extern char lbl_83544EDC[];
extern char lbl_83544EE4[];
extern char lbl_83544EEC[];
extern char lbl_83544FA8[];
ts4_word fn_830A23D8();
ts4_word fn_830A2740();
ts4_word fn_830A29D0();
ts4_word fn_830A3290();
ts4_word fn_830A3590();
ts4_word fn_830A4258();
ts4_word fn_830A4380();
ts4_word fn_830A4548();
ts4_word fn_830A45E0();
ts4_word fn_830A4680();
ts4_word fn_830A4848();
ts4_word fn_830A4A10();
ts4_word fn_830A4AA0();
ts4_word fn_830A50C0();
ts4_word fn_830A76C0();
ts4_word fn_830AA9F0();
ts4_word fn_830AAAE8();
ts4_word fn_830AAC58();
ts4_word fn_830AACF0();
ts4_word fn_830AC190();
ts4_word fn_830AC6F8();
ts4_word fn_830AC7F8();
ts4_word fn_830ACE48();
ts4_word fn_830ACED8();
ts4_word fn_830AEE68();
ts4_word fn_830AF1B8();
ts4_word fn_830AF2B0();
ts4_word fn_830B37D0();
ts4_word fn_830B5E58();
ts4_word fn_830B86E0();
ts4_word fn_830B8C60();
ts4_word fn_830B95A8();
ts4_word fn_830BBA98();
ts4_word fn_830BBB98();
ts4_word fn_830BBC00();
ts4_word fn_8310D380();
ts4_word fn_83112388();
ts4_word fn_83112858();
ts4_word fn_83112948();
ts4_word fn_83112998();
ts4_word fn_83112A88();
ts4_word fn_83112B88();
ts4_word fn_831137A0();
ts4_word fn_83116020();
ts4_word fn_83119C60();
ts4_word fn_8321C470();
ts4_word fn_8321C528();
ts4_word fn_8321C650();
ts4_word fn_8321C6C0();
ts4_word fn_8321D5F8();
ts4_word fn_8321DCF0();
ts4_word fn_833E0AB0();
ts4_word fn_833E1758();
ts4_word fn_833E22A0();
ts4_word fn_833E27A8();
ts4_word fn_833E2820();
ts4_word fn_833E3AD0();
ts4_word fn_8340A360();
ts4_word fn_8340AED8();
ts4_word fn_8340B1F0();
ts4_word fn_8340BCE8();
ts4_word fn_8340BD08();
ts4_word fn_8340CE90();
ts4_word fn_8340D710();
ts4_word fn_8340D830();
ts4_word fn_8340D860();
ts4_word fn_83488E48();
ts4_word fn_8348B158();
ts4_word fn_8348B1A0();
ts4_word fn_8348B210();
ts4_word fn_8348B258();
ts4_word fn_8348B298();

/* Loader_DLL.xex 0x830A0000: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_830A0000(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A0010: loop_set u32@0x4, u32@0x0, u32@0x100, u8@0x104 */
void ts4_loop_set_u32_off4_830A0010(ts4_word a0)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p3;

    c1 = (ts4_word)32;
    lv2 = (ts4_word)(a0 + -4);
    do {
        *(ts4_word *)((char *)(ts4_word)(lv2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(ts4_word)((lv2 + 8)) + 0) = (ts4_word)0;
        p3 = (ts4_word)(lv2 + 8);
        lv2 = p3;
    } while (--c1 != 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 256) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 260) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x830A0308: set u8@0x8b8 */
void ts4_set_u8_off8b8_830A0308(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 2232) = (unsigned char)1;
    return;
}

/* Loader_DLL.xex 0x830A0318: fn  */
ts4_word ts4_fn_830A0318(ts4_word a0)
{
    return (a0 + 64);
}

/* Loader_DLL.xex 0x830A03F0: get u8@0x0, u8@0x0 */
void ts4_get_u8_off0_830A03F0(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Loader_DLL.xex 0x830A0400: get u8@0x10 */
ts4_word ts4_get_u8_off10_830A0400(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x830A0430: addr lbl_83085E48, u32@0x0 */
void ts4_addr_lbl_83085E48_830A0430(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085E48;
    return;
}

/* Loader_DLL.xex 0x830A0520: call_seq fn_83488E48, fn_833E1758 */
ts4_word ts4_call_seq_fn_83488E48_830A0520(ts4_word a0)
{
    fn_83488E48((ts4_word)a0);
    fn_833E1758((ts4_word)a0);
    return a0;
}

/* Loader_DLL.xex 0x830A06C0: call_seq fn_830A3590 */
ts4_word ts4_call_seq_fn_830A3590_830A06C0(ts4_word a0)
{
    fn_830A3590((ts4_word)a0);
    return a0;
}

/* Loader_DLL.xex 0x830A0BA8: fn  */
ts4_word ts4_fn_830A0BA8(ts4_word a0)
{
    return (a0 + 144);
}

/* Loader_DLL.xex 0x830A0BB0: get u32@0x970 */
ts4_word ts4_get_u32_off970_830A0BB0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 2416));
}

/* Loader_DLL.xex 0x830A0BB8: get u32@0x974 */
ts4_word ts4_get_u32_off974_830A0BB8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 2420));
}

/* Loader_DLL.xex 0x830A0BC0: get u32@lbl_83544EDC */
ts4_word ts4_get_u32_lbl_83544EDC_830A0BC0(ts4_word a0)
{
    return (((1 << a0) & (*(ts4_word *)lbl_83544EDC)) != 0);
}

/* Loader_DLL.xex 0x830A0C18: get u32@lbl_83544EE4 */
ts4_word ts4_get_u32_lbl_83544EE4_830A0C18(ts4_word a0)
{
    return (((1 << a0) & (*(ts4_word *)lbl_83544EE4)) != 0);
}

/* Loader_DLL.xex 0x830A0C68: set u32@lbl_83544EEC */
void ts4_set_u32_lbl_83544EEC_830A0C68(void)
{
    *(ts4_word *)lbl_83544EEC = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x830A0DD0: addr lbl_83084C60, fn_8310D380 */
ts4_word ts4_addr_lbl_83084C60_830A0DD0(void)
{
    return fn_8310D380((ts4_word)(ts4_word)lbl_83084C60);
}

/* Loader_DLL.xex 0x830A0E50: if_get u32@0x0, u32@0x8, vcall */
ts4_word ts4_if_get_u32_off0_830A0E50(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)1);
    }
    return 0;
}

/* Loader_DLL.xex 0x830A0E90: if_get u32@0x4, u32@0x4, lbl_83085968, fn_83112B88 */
ts4_word ts4_if_get_u32_off4_830A0E90(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    if ((ts4_word)t1 == 19) {
        return fn_83112B88((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)lbl_83085968, (ts4_word)(a0 + 12));
    }
    return 0;
}

/* Loader_DLL.xex 0x830A0EC0: tailcall fn_8321D5F8 */
ts4_word ts4_tailcall_fn_8321D5F8_830A0EC0(ts4_word a0)
{
    return fn_8321D5F8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A0EC8: tailcall fn_8321DCF0 */
ts4_word ts4_tailcall_fn_8321DCF0_830A0EC8(ts4_word a0)
{
    return fn_8321DCF0((ts4_word)a0, (ts4_word)0);
}

/* Loader_DLL.xex 0x830A0F60: addr lbl_83084C80, fn_8310D380 */
ts4_word ts4_addr_lbl_83084C80_830A0F60(void)
{
    return fn_8310D380((ts4_word)(ts4_word)lbl_83084C80);
}

/* Loader_DLL.xex 0x830A0FE8: if_get u32@0x0, u32@0x8, vcall */
ts4_word ts4_if_get_u32_off0_830A0FE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)1);
    }
    return 0;
}

/* Loader_DLL.xex 0x830A11A8: addr lbl_83084CA8, fn_8310D380 */
ts4_word ts4_addr_lbl_83084CA8_830A11A8(void)
{
    return fn_8310D380((ts4_word)(ts4_word)lbl_83084CA8);
}

/* Loader_DLL.xex 0x830A1220: if_get u32@0x0, u32@0x8, vcall */
ts4_word ts4_if_get_u32_off0_830A1220(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)1);
    }
    return 0;
}

/* Loader_DLL.xex 0x830A1318: addr lbl_83084CD4, fn_8310D380 */
ts4_word ts4_addr_lbl_83084CD4_830A1318(void)
{
    return fn_8310D380((ts4_word)(ts4_word)lbl_83084CD4);
}

/* Loader_DLL.xex 0x830A13A0: if_get u32@0x0, u32@0x8, vcall */
ts4_word ts4_if_get_u32_off0_830A13A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0, (ts4_word)1);
    }
    return 0;
}

/* Loader_DLL.xex 0x830A1528: addr lbl_83085D7C, u32@0x0 */
void ts4_addr_lbl_83085D7C_830A1528(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085D7C;
    return;
}

/* Loader_DLL.xex 0x830A15F0: addr lbl_83085D60, u32@0x0 */
void ts4_addr_lbl_83085D60_830A15F0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085D60;
    return;
}

/* Loader_DLL.xex 0x830A1690: addr lbl_83085DB0, u32@0x4, u32@0x0 */
void ts4_addr_lbl_83085DB0_830A1690(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085DB0;
    return;
}

/* Loader_DLL.xex 0x830A16A8: addr lbl_83085DA8, u32@0x0 */
void ts4_addr_lbl_83085DA8_830A16A8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085DA8;
    return;
}

/* Loader_DLL.xex 0x830A1848: fn  */
void ts4_fn_830A1848(void)
{
    return;
}

/* Loader_DLL.xex 0x830A1850: fn  */
void ts4_fn_830A1850(void)
{
    return;
}

/* Loader_DLL.xex 0x830A1858: fn  */
void ts4_fn_830A1858(void)
{
    return;
}

/* Loader_DLL.xex 0x830A1860: fn  */
void ts4_fn_830A1860(void)
{
    return;
}

/* Loader_DLL.xex 0x830A1868: get u32@0x4, fn_8340AED8 */
ts4_word ts4_get_u32_off4_830A1868(ts4_word a0)
{
    return fn_8340AED8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
}

/* Loader_DLL.xex 0x830A1870: fn  */
void ts4_fn_830A1870(void)
{
    return;
}

/* Loader_DLL.xex 0x830A1878: fn  */
void ts4_fn_830A1878(void)
{
    return;
}

/* Loader_DLL.xex 0x830A18D0: get u32@0x4, lbl_83085F50, u32@0x0, fn_8340A360 */
ts4_word ts4_get_u32_off4_830A18D0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085F50;
    return fn_8340A360((ts4_word)t1);
}

/* Loader_DLL.xex 0x830A1948: fn  */
void ts4_fn_830A1948(void)
{
    return;
}

/* Loader_DLL.xex 0x830A1B98: addr lbl_83085E48, u32@0x0 */
void ts4_addr_lbl_83085E48_830A1B98(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085E48;
    return;
}

/* Loader_DLL.xex 0x830A1C20: get u32@0x0 */
ts4_word ts4_get_u32_off0_830A1C20(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830A1C28: get u32@0x4 */
ts4_word ts4_get_u32_off4_830A1C28(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830A1C30: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830A1C30(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) / (int)20);
}

/* Loader_DLL.xex 0x830A1C48: get u32@0x4 */
ts4_word ts4_get_u32_off4_830A1C48(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + -20);
}

/* Loader_DLL.xex 0x830A1C58: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A1C58(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A1C70: tailcall fn_830A23D8 */
ts4_word ts4_tailcall_fn_830A23D8_830A1C70(ts4_word a0)
{
    return fn_830A23D8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A1D68: fn  */
void ts4_fn_830A1D68(void)
{
    return;
}

/* Loader_DLL.xex 0x830A1D70: fn  */
void ts4_fn_830A1D70(void)
{
    return;
}

/* Loader_DLL.xex 0x830A1DE8: if_call_seq u32@0x4, u32@0x0, fn_830A4258 */
ts4_word ts4_if_call_seq_u32_off4_830A1DE8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p4;
    ts4_word t1;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p4 = (ts4_word)a0;
    if ((ts4_word)a1 != (ts4_word)a0) {
        t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
        fn_830A4258((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)t1);
        p4 = (ts4_word)a0;
    }
    return p4;
}

/* Loader_DLL.xex 0x830A1E50: if_get u32@0x4, u32@0x0, fn_830A4680 */
ts4_word ts4_if_get_u32_off4_830A1E50(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t2 == (ts4_word)t1) {
        return a0;
    }
    return fn_830A4680((ts4_word)a0, (ts4_word)t2, (ts4_word)t1);
}

/* Loader_DLL.xex 0x830A1EA0: get u32@0x0 */
ts4_word ts4_get_u32_off0_830A1EA0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830A1EA8: fn  */
void ts4_fn_830A1EA8(void)
{
    return;
}

/* Loader_DLL.xex 0x830A1EB0: fn  */
void ts4_fn_830A1EB0(void)
{
    return;
}

/* Loader_DLL.xex 0x830A1EB8: get u32@0x0 */
ts4_word ts4_get_u32_off0_830A1EB8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + a0);
}

/* Loader_DLL.xex 0x830A1EC8: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830A1EC8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return (((t1 << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + a0);
}

/* Loader_DLL.xex 0x830A1EE0: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830A1EE0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) >> 4);
}

/* Loader_DLL.xex 0x830A1EF8: get u32@0x4 */
ts4_word ts4_get_u32_off4_830A1EF8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + -16);
}

/* Loader_DLL.xex 0x830A1F08: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A1F08(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A20F0: fn  */
void ts4_fn_830A20F0(void)
{
    return;
}

/* Loader_DLL.xex 0x830A20F8: fn  */
void ts4_fn_830A20F8(void)
{
    return;
}

/* Loader_DLL.xex 0x830A2100: get u32@0x0 */
ts4_word ts4_get_u32_off0_830A2100(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830A2108: get u32@0x4 */
ts4_word ts4_get_u32_off4_830A2108(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830A2110: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A2110(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A21A0: if_get u32@0x8, u32@0x4, fn_830A2740, u32@0x0, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off8_830A21A0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    if ((ts4_word)t2 != (ts4_word)t1) {
        if ((ts4_word)t2 != 0) {
            *(ts4_word *)((char *)(ts4_word)(t2) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
        }
        *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 4);
        return a0;
    }
    return fn_830A2740((ts4_word)a0, (ts4_word)t2, (ts4_word)a1);
}

/* Loader_DLL.xex 0x830A21E0: fn  */
void ts4_fn_830A21E0(void)
{
    return;
}

/* Loader_DLL.xex 0x830A21E8: fn  */
void ts4_fn_830A21E8(void)
{
    return;
}

/* Loader_DLL.xex 0x830A21F0: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830A21F0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) / (int)12);
}

/* Loader_DLL.xex 0x830A2208: get u32@0x0 */
ts4_word ts4_get_u32_off0_830A2208(ts4_word a0, ts4_word a1)
{
    return (((a1 + (a1 << 1)) << 2) + (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A2220: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A2220(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A2238: call_seq u32@0x4, u32@0x0, fn_830A4AA0, fn_830A29D0 */
ts4_word ts4_call_seq_u32_off4_830A2238(ts4_word a0)
{
    ts4_word t1;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    fn_830A4AA0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)t1);
    t4 = fn_830A29D0((ts4_word)a0);
    return t4;
}

/* Loader_DLL.xex 0x830A2308: fn  */
void ts4_fn_830A2308(void)
{
    return;
}

/* Loader_DLL.xex 0x830A2310: fn  */
void ts4_fn_830A2310(void)
{
    return;
}

/* Loader_DLL.xex 0x830A23C0: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A23C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A2660: get u32@0x0 */
ts4_word ts4_get_u32_off0_830A2660(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830A2668: get u32@0x4 */
ts4_word ts4_get_u32_off4_830A2668(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830A2670: call_seq u32@0x4, fn_830A4380, u32@0x4, fn_830A4A10, u32@0x4 */
ts4_word ts4_call_seq_u32_off4_830A2670(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = fn_830A4380((ts4_word)a2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)a1);
    fn_830A4A10((ts4_word)t2, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    return a1;
}

/* Loader_DLL.xex 0x830A26B0: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A26B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A2850: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A2850(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A29B0: get u32@0x0 */
ts4_word ts4_get_u32_off0_830A29B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830A29B8: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A29B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A2A50: fn  */
void ts4_fn_830A2A50(void)
{
    return;
}

/* Loader_DLL.xex 0x830A2A58: fn  */
void ts4_fn_830A2A58(void)
{
    return;
}

/* Loader_DLL.xex 0x830A2A60: fn  */
void ts4_fn_830A2A60(void)
{
    return;
}

/* Loader_DLL.xex 0x830A2A68: fn  */
void ts4_fn_830A2A68(void)
{
    return;
}

/* Loader_DLL.xex 0x830A2A70: fn  */
void ts4_fn_830A2A70(void)
{
    return;
}

/* Loader_DLL.xex 0x830A2A78: tailcall fn_830A3290 */
ts4_word ts4_tailcall_fn_830A3290_830A2A78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_830A3290((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830A2AE8: set u32@0x0 */
void ts4_set_u32_off0_830A2AE8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A2AF8: if_tailcall fn_833E3AD0 */
ts4_word ts4_if_tailcall_fn_833E3AD0_830A2AF8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a2 == 0) {
        return a0;
    }
    return fn_833E3AD0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830A2B08: get u32@0x0 */
ts4_word ts4_get_u32_off0_830A2B08(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830A2B10: get u32@0x4 */
ts4_word ts4_get_u32_off4_830A2B10(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830A2B18: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830A2B18(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return (t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A2C78: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A2C78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    return;
}

/* Loader_DLL.xex 0x830A2D68: set u32@0x0 */
void ts4_set_u32_off0_830A2D68(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A2D78: get u32@0x4, u32@0x0 */
ts4_word ts4_get_u32_off4_830A2D78(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) >> 2);
}

/* Loader_DLL.xex 0x830A2E08: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A2E08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    return;
}

/* Loader_DLL.xex 0x830A2EF8: set u32@0x0 */
void ts4_set_u32_off0_830A2EF8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A2F98: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A2F98(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    return;
}

/* Loader_DLL.xex 0x830A3098: set u32@0x0 */
void ts4_set_u32_off0_830A3098(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A30A8: fn  */
void ts4_fn_830A30A8(void)
{
    return;
}

/* Loader_DLL.xex 0x830A30B0: if_tailcall fn_833E22A0 */
ts4_word ts4_if_tailcall_fn_833E22A0_830A30B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a2 == 0) {
        return a0;
    }
    return fn_833E22A0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830A3118: fn  */
void ts4_fn_830A3118(void)
{
    return;
}

/* Loader_DLL.xex 0x830A3120: fn  */
void ts4_fn_830A3120(void)
{
    return;
}

/* Loader_DLL.xex 0x830A3128: fn  */
void ts4_fn_830A3128(void)
{
    return;
}

/* Loader_DLL.xex 0x830A3670: fn  */
void ts4_fn_830A3670(void)
{
    return;
}

/* Loader_DLL.xex 0x830A3678: tailcall fn_830A4258 */
ts4_word ts4_tailcall_fn_830A4258_830A3678(ts4_word a0)
{
    return fn_830A4258((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A3680: if_tailcall fn_830A4680 */
ts4_word ts4_if_tailcall_fn_830A4680_830A3680(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 == (ts4_word)a2) {
        return a0;
    }
    return fn_830A4680((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A3690: if_tailcall fn_830A4848 */
ts4_word ts4_if_tailcall_fn_830A4848_830A3690(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 == (ts4_word)a2) {
        return a0;
    }
    return fn_830A4848((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A36A0: tailcall fn_830A4A10 */
ts4_word ts4_tailcall_fn_830A4A10_830A36A0(ts4_word a0)
{
    return fn_830A4A10((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A3778: fn  */
void ts4_fn_830A3778(void)
{
    return;
}

/* Loader_DLL.xex 0x830A3780: if_get u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_830A3780(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    return;
}

/* Loader_DLL.xex 0x830A3798: tailcall fn_830A4AA0 */
ts4_word ts4_tailcall_fn_830A4AA0_830A3798(ts4_word a0)
{
    return fn_830A4AA0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A3818: if_get u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_830A3818(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 >= (ts4_word)t2) {
        return a0;
    }
    return a1;
}

/* Loader_DLL.xex 0x830A39E0: tailcall fn_830A4380 */
ts4_word ts4_tailcall_fn_830A4380_830A39E0(ts4_word a0)
{
    return fn_830A4380((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A39E8: loop_get u32@0x0, u32@0x0 */
ts4_word ts4_loop_get_u32_off0_830A39E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word c2;
    ts4_word lv3;
    ts4_word p4;
    ts4_word t1;

    if ((ts4_word)a1 == 0) {
        return a0;
    }
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    c2 = (ts4_word)a1;
    lv3 = (ts4_word)a0;
    do {
        *(ts4_word *)((char *)(ts4_word)(lv3) + 0) = (ts4_word)t1;
        p4 = (ts4_word)(lv3 + 4);
        lv3 = p4;
    } while (--c2 != 0);
    return lv3;
}

/* Loader_DLL.xex 0x830A3E68: get u32@0x8, u32@0x0 */
ts4_word ts4_get_u32_off8_830A3E68(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((int)(t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) / (int)20);
}

/* Loader_DLL.xex 0x830A3F00: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A3F00(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    return;
}

/* Loader_DLL.xex 0x830A3F98: fn  */
void ts4_fn_830A3F98(void)
{
    return;
}

/* Loader_DLL.xex 0x830A3FA0: get u32@0x4, u8@0x0 */
void ts4_get_u32_off4_830A3FA0(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x830A3FB0: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_830A3FB0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A4048: call_seq fn_830A50C0 */
ts4_word ts4_call_seq_fn_830A50C0_830A4048(ts4_word a0)
{
    fn_830A50C0();
    return a0;
}

/* Loader_DLL.xex 0x830A4078: set u32@lbl_83544FA8 */
void ts4_set_u32_lbl_83544FA8_830A4078(void)
{
    *(volatile ts4_word *)lbl_83544FA8 = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A4088: get u32@0x4, u8@0x0 */
void ts4_get_u32_off4_830A4088(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x830A4098: fn  */
void ts4_fn_830A4098(void)
{
    return;
}

/* Loader_DLL.xex 0x830A40A0: set u32@0x0 */
void ts4_set_u32_off0_830A40A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A4240: tailcall fn_830A4548 */
ts4_word ts4_tailcall_fn_830A4548_830A4240(ts4_word a0)
{
    return fn_830A4548((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A4248: tailcall fn_830A45E0 */
ts4_word ts4_tailcall_fn_830A45E0_830A4248(ts4_word a0)
{
    return fn_830A45E0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A4250: fn  */
void ts4_fn_830A4250(void)
{
    return;
}

/* Loader_DLL.xex 0x830A42F8: if_tailcall fn_830A4680 */
ts4_word ts4_if_tailcall_fn_830A4680_830A42F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 == (ts4_word)a2) {
        return a0;
    }
    return fn_830A4680((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A4308: if_tailcall fn_830A4848 */
ts4_word ts4_if_tailcall_fn_830A4848_830A4308(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a1 == (ts4_word)a2) {
        return a0;
    }
    return fn_830A4848((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A4318: tailcall fn_830A4A10 */
ts4_word ts4_tailcall_fn_830A4A10_830A4318(ts4_word a0)
{
    return fn_830A4A10((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A4320: fn  */
void ts4_fn_830A4320(void)
{
    return;
}

/* Loader_DLL.xex 0x830A4328: tailcall fn_830A4AA0 */
ts4_word ts4_tailcall_fn_830A4AA0_830A4328(ts4_word a0)
{
    return fn_830A4AA0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A44E8: fn  */
ts4_word ts4_fn_830A44E8(ts4_word a0)
{
    return ((a0 + 7) & 0xfffffff8);
}

/* Loader_DLL.xex 0x830A4678: fn  */
void ts4_fn_830A4678(void)
{
    return;
}

/* Loader_DLL.xex 0x830A4A98: fn  */
void ts4_fn_830A4A98(void)
{
    return;
}

/* Loader_DLL.xex 0x830A4C68: set u8@0x0 */
void ts4_set_u8_off0_830A4C68(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x830A4C78: fn  */
ts4_word ts4_fn_830A4C78(void)
{
    return -2;
}

/* Loader_DLL.xex 0x830A4C80: get u32@0x8, u32@0x0 */
ts4_word ts4_get_u32_off8_830A4C80(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    return ((t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + -1);
}

/* Loader_DLL.xex 0x830A4C98: set u8@0x0 */
void ts4_set_u8_off0_830A4C98(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x830A4CA8: fn  */
ts4_word ts4_fn_830A4CA8(void)
{
    return -2;
}

/* Loader_DLL.xex 0x830A4CB0: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_830A4CB0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return (t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A4D38: call_seq lbl_83085D50, fn_833E2820, fn_833E27A8 */
ts4_word ts4_call_seq_lbl_83085D50_830A4D38(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_833E2820((ts4_word)(ts4_word)lbl_83085D50);
    t2 = fn_833E27A8((ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x830A4D68: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_830A4D68(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return (t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A4DC0: fn  */
void ts4_fn_830A4DC0(void)
{
    return;
}

/* Loader_DLL.xex 0x830A4EB0: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_830A4EB0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return (t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A4EC0: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_830A4EC0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    return (t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A4F78: fn  */
void ts4_fn_830A4F78(void)
{
    return;
}

/* Loader_DLL.xex 0x830A4FE0: call_seq lbl_83085D50, fn_833E2820, fn_833E27A8 */
ts4_word ts4_call_seq_lbl_83085D50_830A4FE0(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_833E2820((ts4_word)(ts4_word)lbl_83085D50);
    t2 = fn_833E27A8((ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x830A5010: tailcall fn_833E0AB0 */
ts4_word ts4_tailcall_fn_833E0AB0_830A5010(ts4_word a0)
{
    return fn_833E0AB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A5060: set u32@lbl_83544FA8 */
void ts4_set_u32_lbl_83544FA8_830A5060(void)
{
    *(volatile ts4_word *)lbl_83544FA8 = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A50A0: if_tail fn_8340CE90, fn_8340CE90 */
ts4_word ts4_if_tail_fn_8340CE90_830A50A0(int a0)
{
    if ((int)a0 <= 20) {
        return fn_8340CE90((ts4_word)1);
    }
    return fn_8340CE90((ts4_word)(1 << (a0 + -20)));
}

/* Loader_DLL.xex 0x830A5238: tailcall fn_830A50C0 */
ts4_word ts4_tailcall_fn_830A50C0_830A5238(ts4_word a0)
{
    return fn_830A50C0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A5240: fn  */
void ts4_fn_830A5240(void)
{
    return;
}

/* Loader_DLL.xex 0x830A5248: tailcall fn_833E1758 */
ts4_word ts4_tailcall_fn_833E1758_830A5248(ts4_word a0)
{
    return fn_833E1758((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A5250: tailcall fn_833E0AB0 */
ts4_word ts4_tailcall_fn_833E0AB0_830A5250(ts4_word a0)
{
    return fn_833E0AB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A52A0: fn  */
void ts4_fn_830A52A0(void)
{
    return;
}

/* Loader_DLL.xex 0x830A5300: get u32@0x0, fn_83112998 */
ts4_word ts4_get_u32_off0_830A5300(ts4_word a0, ts4_word a1)
{
    return fn_83112998((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830A5308: fn  */
void ts4_fn_830A5308(void)
{
    return;
}

/* Loader_DLL.xex 0x830A5310: get u32@0x0, fn_8348B298 */
ts4_word ts4_get_u32_off0_830A5310(ts4_word a0, ts4_word a1)
{
    return fn_8348B298((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830A5318: get u32@0x0, fn_83112388 */
ts4_word ts4_get_u32_off0_830A5318(ts4_word a0)
{
    return fn_83112388((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)0);
}

/* Loader_DLL.xex 0x830A5328: get u32@0x0, fn_8348B258 */
ts4_word ts4_get_u32_off0_830A5328(ts4_word a0)
{
    return fn_8348B258((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A5330: get u32@0x0 */
ts4_word ts4_get_u32_off0_830A5330(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x830A5338: set u32@0x0 */
void ts4_set_u32_off0_830A5338(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A5348: get u32@0x0, fn_8321C650 */
ts4_word ts4_get_u32_off0_830A5348(ts4_word a0)
{
    return fn_8321C650((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A5350: get u32@0x0, fn_8321C6C0 */
ts4_word ts4_get_u32_off0_830A5350(ts4_word a0)
{
    return fn_8321C6C0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A5358: get u32@0x0, fn_8321C528 */
ts4_word ts4_get_u32_off0_830A5358(ts4_word a0, ts4_word a1)
{
    return fn_8321C528((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830A5360: get u32@0x0, fn_8321C470 */
ts4_word ts4_get_u32_off0_830A5360(ts4_word a0, ts4_word a1)
{
    return fn_8321C470((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830A5368: get u32@0x0, fn_8348B210 */
ts4_word ts4_get_u32_off0_830A5368(ts4_word a0, ts4_word a1)
{
    return fn_8348B210((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830A5370: set u32@0x0 */
void ts4_set_u32_off0_830A5370(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A5380: get u32@0x0, fn_83112B88 */
ts4_word ts4_get_u32_off0_830A5380(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83112B88((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830A5388: get u32@0x0, fn_831137A0 */
ts4_word ts4_get_u32_off0_830A5388(ts4_word a0, ts4_word a1)
{
    return fn_831137A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830A5390: set u32@0x0 */
void ts4_set_u32_off0_830A5390(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A53A0: set u32@0x0 */
void ts4_set_u32_off0_830A53A0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A53B0: set u32@0x0 */
void ts4_set_u32_off0_830A53B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A53C0: set u32@0x0 */
void ts4_set_u32_off0_830A53C0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A53D0: set u32@0x0 */
void ts4_set_u32_off0_830A53D0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x830A53E0: get u32@0x0, fn_83112948 */
ts4_word ts4_get_u32_off0_830A53E0(ts4_word a0, ts4_word a1)
{
    return fn_83112948((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830A53E8: get u32@0x0, fn_83112858 */
ts4_word ts4_get_u32_off0_830A53E8(ts4_word a0, ts4_word a1)
{
    return fn_83112858((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830A53F0: get u32@0x0, fn_83112A88 */
ts4_word ts4_get_u32_off0_830A53F0(ts4_word a0, ts4_word a1)
{
    return fn_83112A88((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x830A53F8: set  */
void ts4_set_830A53F8(ts4_word a0, float f1, float f2, float f3)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    *(float *)((char *)(ts4_word)(a0) + 4) = f2;
    *(float *)((char *)(ts4_word)(a0) + 8) = f3;
    return;
}

/* Loader_DLL.xex 0x830A5408: get u32@0x0, fn_8348B1A0 */
ts4_word ts4_get_u32_off0_830A5408(ts4_word a0)
{
    return fn_8348B1A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A54C8: get u32@0x0, fn_83119C60 */
ts4_word ts4_get_u32_off0_830A54C8(ts4_word a0, ts4_word a1)
{
    return fn_83119C60((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)), (ts4_word)0, (ts4_word)a1, (ts4_word)253);
}

/* Loader_DLL.xex 0x830A5540: get u32@0x0, fn_8348B158 */
ts4_word ts4_get_u32_off0_830A5540(ts4_word a0)
{
    return fn_8348B158((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x830A5548: fn  */
void ts4_fn_830A5548(void)
{
    return;
}

/* Loader_DLL.xex 0x830A5550: get u32@0xc */
ts4_word ts4_get_u32_offc_830A5550(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x830A5798: addr lbl_83085F98, u32@0x0 */
void ts4_addr_lbl_83085F98_830A5798(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085F98;
    return;
}

/* Loader_DLL.xex 0x830A59D0: if_call_seq fn_8340B1F0, fn_83116020 */
ts4_word ts4_if_call_seq_fn_8340B1F0_830A59D0(void)
{
    ts4_word loc50[2];
    ts4_word t1;

    t1 = fn_8340B1F0((ts4_word)255, (ts4_word)255, (ts4_word)(ts4_word)&loc50[0]);
    if ((ts4_word)t1 == 0) {
        fn_83116020((ts4_word)(ts4_word)&loc50[0]);
    }
    return 0;
}

/* Loader_DLL.xex 0x830A5BB8: call_seq fn_8340BD08, fn_8340BCE8 */
ts4_word ts4_call_seq_fn_8340BD08_830A5BB8(ts4_word a0)
{
    ts4_word t2;

    fn_8340BD08((ts4_word)a0);
    t2 = fn_8340BCE8((ts4_word)(a0 + 8));
    return t2;
}

/* Loader_DLL.xex 0x830A5BF0: call_seq fn_8340BD08, fn_8340BCE8 */
ts4_word ts4_call_seq_fn_8340BD08_830A5BF0(ts4_word a0)
{
    fn_8340BD08((ts4_word)a0);
    fn_8340BCE8((ts4_word)(a0 + 8));
    return a0;
}

/* Loader_DLL.xex 0x830A5CA8: fn  */
ts4_word ts4_fn_830A5CA8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830A5CB0: set u32@0x0 */
ts4_word ts4_set_u32_off0_830A5CB0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return 0;
}

/* Loader_DLL.xex 0x830A5CC8: fn  */
ts4_word ts4_fn_830A5CC8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830A5CD0: get u32@0x0, u32@0x4 */
ts4_word ts4_get_u32_off0_830A5CD0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 4))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A5CE0: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_830A5CE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a2) + 0))) + 0))))((ts4_word)a2);
}

/* Loader_DLL.xex 0x830A5CF8: tailcall fn_830AAAE8 */
ts4_word ts4_tailcall_fn_830AAAE8_830A5CF8(ts4_word a0)
{
    return fn_830AAAE8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A5D00: get u32@lbl_83544EC8, u32@lbl_83544EC4, fn_830B95A8 */
ts4_word ts4_get_u32_lbl_83544EC8_830A5D00(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_83544EC8;
    return fn_830B95A8((ts4_word)(*(ts4_word *)lbl_83544EC4), (ts4_word)t1);
}

/* Loader_DLL.xex 0x830A5D18: call_seq fn_830B8C60 */
ts4_word ts4_call_seq_fn_830B8C60_830A5D18(ts4_word a0, ts4_word a1)
{
    fn_830B8C60((ts4_word)a0, (ts4_word)a1, (ts4_word)0);
    return 0;
}

/* Loader_DLL.xex 0x830A5D40: call_seq fn_830B86E0 */
ts4_word ts4_call_seq_fn_830B86E0_830A5D40(ts4_word a0)
{
    fn_830B86E0((ts4_word)a0, (ts4_word)0);
    return 0;
}

/* Loader_DLL.xex 0x830A5DA8: call_seq fn_830B5E58 */
ts4_word ts4_call_seq_fn_830B5E58_830A5DA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    fn_830B5E58((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)0);
    return 0;
}

/* Loader_DLL.xex 0x830A5DD0: call_seq fn_830B37D0 */
ts4_word ts4_call_seq_fn_830B37D0_830A5DD0(void)
{
    fn_830B37D0();
    return 0;
}

/* Loader_DLL.xex 0x830A5DF8: call_seq fn_830AACF0 */
ts4_word ts4_call_seq_fn_830AACF0_830A5DF8(ts4_word a0)
{
    fn_830AACF0((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x830A5E20: call_seq fn_830AAC58 */
ts4_word ts4_call_seq_fn_830AAC58_830A5E20(ts4_word a0)
{
    fn_830AAC58((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x830A5E48: tailcall fn_830AF1B8 */
ts4_word ts4_tailcall_fn_830AF1B8_830A5E48(ts4_word a0)
{
    return fn_830AF1B8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A5F70: tailcall fn_830AA9F0 */
ts4_word ts4_tailcall_fn_830AA9F0_830A5F70(ts4_word a0)
{
    return fn_830AA9F0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A5FA0: if_set u32@0x0 */
ts4_word ts4_if_set_u32_off0_830A5FA0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    return 0;
}

/* Loader_DLL.xex 0x830A6038: fn  */
ts4_word ts4_fn_830A6038(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830A6078: fn  */
ts4_word ts4_fn_830A6078(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830A60D8: call_seq fn_830BBA98 */
ts4_word ts4_call_seq_fn_830BBA98_830A60D8(ts4_word a0)
{
    fn_830BBA98((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x830A6100: call_seq fn_830BBB98 */
ts4_word ts4_call_seq_fn_830BBB98_830A6100(ts4_word a0)
{
    fn_830BBB98((ts4_word)a0);
    return 0;
}

/* Loader_DLL.xex 0x830A6128: tailcall fn_830BBC00 */
ts4_word ts4_tailcall_fn_830BBC00_830A6128(ts4_word a0)
{
    return fn_830BBC00((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A6148: fn  */
ts4_word ts4_fn_830A6148(ts4_word a0)
{
    return (a0 & 0x3f);
}

/* Loader_DLL.xex 0x830A61D0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_830A61D0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(1686110208));
}

/* Loader_DLL.xex 0x830A61D8: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_830A61D8(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612368384));
}

/* Loader_DLL.xex 0x830A61E0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_830A61E0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612368384));
}

/* Loader_DLL.xex 0x830A6200: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_830A6200(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(2977955840));
}

/* Loader_DLL.xex 0x830A6208: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_830A6208(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(1686110208));
}

/* Loader_DLL.xex 0x830A6210: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_830A6210(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(612368384));
}

/* Loader_DLL.xex 0x830A6218: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_830A6218(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(612368384));
}

/* Loader_DLL.xex 0x830A6238: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_830A6238(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(2977955840));
}

/* Loader_DLL.xex 0x830A6240: fn  */
void ts4_fn_830A6240(void)
{
    return;
}

/* Loader_DLL.xex 0x830A6248: fn  */
ts4_word ts4_fn_830A6248(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830A6280: fn  */
void ts4_fn_830A6280(void)
{
    return;
}

/* Loader_DLL.xex 0x830A6288: get u32@0x2a9c */
ts4_word ts4_get_u32_off2a9c_830A6288(ts4_word a0, ts4_word a1)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 10908)) - a1);
}

/* Loader_DLL.xex 0x830A62D8: fn  */
void ts4_fn_830A62D8(void)
{
    return;
}

/* Loader_DLL.xex 0x830A66E0: set u32@0x30 */
void ts4_set_u32_off30_830A66E0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830A66E8: fn  */
void ts4_fn_830A66E8(void)
{
    return;
}

/* Loader_DLL.xex 0x830A66F0: fn  */
void ts4_fn_830A66F0(void)
{
    return;
}

/* Loader_DLL.xex 0x830A66F8: fn  */
void ts4_fn_830A66F8(void)
{
    return;
}

/* Loader_DLL.xex 0x830A6AA0: call_seq lbl_83086B00, fn_833E3AD0 */
ts4_word ts4_call_seq_lbl_83086B00_830A6AA0(ts4_word a0)
{
    fn_833E3AD0((ts4_word)a0, (ts4_word)(ts4_word)lbl_83086B00, (ts4_word)1104);
    return 0;
}

/* Loader_DLL.xex 0x830A6F28: if_set u32@0x0 */
void ts4_if_set_u32_off0_830A6F28(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x830A77A0: tailcall fn_830A76C0 */
ts4_word ts4_tailcall_fn_830A76C0_830A77A0(ts4_word a0)
{
    return fn_830A76C0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830A7988: get u32@0x4 */
ts4_word ts4_get_u32_off4_830A7988(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x830A9F70: if_get u32@0xc, fn_830BBC00 */
ts4_word ts4_if_get_u32_offc_830A9F70(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((ts4_word)t1 == 0) {
        return t1;
    }
    return fn_830BBC00((ts4_word)t1);
}

/* Loader_DLL.xex 0x830A9FA0: fn  */
ts4_word ts4_fn_830A9FA0(void)
{
    return 1;
}

/* Loader_DLL.xex 0x830AA028: fn  */
ts4_word ts4_fn_830AA028(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830AA040: fn  */
ts4_word ts4_fn_830AA040(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830AA058: fn  */
ts4_word ts4_fn_830AA058(ts4_word a0)
{
    return ((int)a0 >> 16);
}

/* Loader_DLL.xex 0x830AA128: if_get u32@__imp_KeCertMonitorData, u32@0x0, u32@0x4, u32@0x4 */
ts4_word ts4_if_get_u32__imp_KeCertMonitorData_830AA128(ts4_word a0)
{
    ts4_word t2;
    ts4_word t4;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)__imp_KeCertMonitorData)) + 0);
    if ((ts4_word)t2 == 0) {
        return a0;
    }
    t4 = *(ts4_word *)((char *)(ts4_word)(t2) + 4);
    if ((ts4_word)t4 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))(t4))((ts4_word)a0);
}

/* Loader_DLL.xex 0x830AA218: tailcall fn_833E3AD0 */
ts4_word ts4_tailcall_fn_833E3AD0_830AA218(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833E3AD0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830AA220: tailcall fn_833E3AD0 */
ts4_word ts4_tailcall_fn_833E3AD0_830AA220(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833E3AD0((ts4_word)a0, (ts4_word)a1, (ts4_word)(a2 << 2));
}

/* Loader_DLL.xex 0x830AA2A8: fn  */
ts4_word ts4_fn_830AA2A8(ts4_word a0)
{
    return (a0 + -4);
}

/* Loader_DLL.xex 0x830AA2B0: fn  */
void ts4_fn_830AA2B0(void)
{
    return;
}

/* Loader_DLL.xex 0x830AA2B8: fn  */
ts4_word ts4_fn_830AA2B8(ts4_word a0)
{
    return (a0 + 4);
}

/* Loader_DLL.xex 0x830AA2E8: fn  */
void ts4_fn_830AA2E8(void)
{
    return;
}

/* Loader_DLL.xex 0x830AA2F0: fn  */
void ts4_fn_830AA2F0(void)
{
    return;
}

/* Loader_DLL.xex 0x830AABF0: if_call_seq u32@0x2a88, fn_8340D860, fn_8340D860, u32@0x2a88 */
ts4_word ts4_if_call_seq_u32_off2a88_830AABF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 10888);
    p3 = (ts4_word)a0;
    if ((ts4_word)t1 != 0) {
        t2 = fn_8340D860();
        p3 = (ts4_word)t2;
    }
    t4 = fn_8340D860((ts4_word)p3);
    *(ts4_word *)((char *)(ts4_word)(a0) + 10888) = (ts4_word)t4;
    return t4;
}

/* Loader_DLL.xex 0x830AAC50: get u32@0x2a88 */
ts4_word ts4_get_u32_off2a88_830AAC50(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 10888));
}

/* Loader_DLL.xex 0x830AAF70: set u32@0x354c */
void ts4_set_u32_off354c_830AAF70(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 13644) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830AAFA0: set u32@0x0 */
void ts4_set_u32_off0_830AAFA0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x830AB448: fn  */
ts4_word ts4_fn_830AB448(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830AB4D4: fn  */
ts4_word ts4_fn_830AB4D4(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    return a7;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;}

/* Loader_DLL.xex 0x830AB4E0: fn  */
ts4_word ts4_fn_830AB4E0(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830AB4F8: fn  */
ts4_word ts4_fn_830AB4F8(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830AB580: fn  */
ts4_word ts4_fn_830AB580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    return a7;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;}

/* Loader_DLL.xex 0x830AB588: fn  */
ts4_word ts4_fn_830AB588(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830AB5A0: fn  */
void ts4_fn_830AB5A0(void)
{
    return;
}

/* Loader_DLL.xex 0x830AB5A8: fn  */
void ts4_fn_830AB5A8(void)
{
    return;
}

/* Loader_DLL.xex 0x830AB5C8: tailcall fn_830AF2B0 */
ts4_word ts4_tailcall_fn_830AF2B0_830AB5C8(ts4_word a0)
{
    return fn_830AF2B0((ts4_word)a0);
}

/* Loader_DLL.xex 0x830AB5D0: fn  */
ts4_word ts4_fn_830AB5D0(ts4_word a0)
{
    return (a0 & 0x3f);
}

/* Loader_DLL.xex 0x830AB7C8: fn  */
ts4_word ts4_fn_830AB7C8(ts4_word a0)
{
    return ((a0 >> 8) & 0x1);
}

/* Loader_DLL.xex 0x830AB838: get u32@0x2c */
ts4_word ts4_get_u32_off2c_830AB838(ts4_word a0)
{
    return ((((*(ts4_word *)((char *)(ts4_word)(a0) + 44)) >> 6) & 0xf) + 1);
}

/* Loader_DLL.xex 0x830AB920: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_830AB920(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((((a1 << 30) | (a1 >> 2)) & 0x3fffffff) | ((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) & 0xc0000000));
    return;
}

/* Loader_DLL.xex 0x830AB948: fn  */
void ts4_fn_830AB948(void)
{
    return;
}

/* Loader_DLL.xex 0x830AB950: fn  */
void ts4_fn_830AB950(void)
{
    return;
}

/* Loader_DLL.xex 0x830AB958: fn  */
void ts4_fn_830AB958(void)
{
    return;
}

/* Loader_DLL.xex 0x830AB960: fn  */
void ts4_fn_830AB960(void)
{
    return;
}

/* Loader_DLL.xex 0x830ABA60: fn  */
ts4_word ts4_fn_830ABA60(void)
{
    return 0;
}

/* Loader_DLL.xex 0x830AC2E8: call_seq fn_830AC190 */
ts4_word ts4_call_seq_fn_830AC190_830AC2E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word loc60[1];
    ts4_word loc64[1];
    ts4_word loc68[2];
    ts4_word t1;

    t1 = fn_830AC190((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)(ts4_word)&loc68[0], (ts4_word)(ts4_word)&loc64[0], (ts4_word)(ts4_word)&loc60[0]);
    return t1;
}

/* Loader_DLL.xex 0x830AD4F0: get u32@0x2c */
ts4_word ts4_get_u32_off2c_830AD4F0(ts4_word a0)
{
    return ((((*(ts4_word *)((char *)(ts4_word)(a0) + 44)) >> 6) & 0xf) + 1);
}

/* Loader_DLL.xex 0x830AD6B8: get u32@0x30, u32@0x20, fn_830AEE68 */
ts4_word ts4_get_u32_off30_830AD6B8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return fn_830AEE68((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) & 0xfffff000), (ts4_word)(t1 & 0xfffff000));
}

/* Loader_DLL.xex 0x830AD8F8: tailcall fn_830AC6F8 */
ts4_word ts4_tailcall_fn_830AC6F8_830AD8F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830AC6F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830AD9D0: tailcall fn_830ACE48 */
ts4_word ts4_tailcall_fn_830ACE48_830AD9D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_830ACE48((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x830AD9F0: tailcall fn_830ACE48 */
ts4_word ts4_tailcall_fn_830ACE48_830AD9F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_830ACE48((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x830ADA08: get u32@0x30, u32@0x20, fn_830AEE68 */
ts4_word ts4_get_u32_off30_830ADA08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return fn_830AEE68((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) & 0xfffff000), (ts4_word)(t1 & 0xfffff000));
}

/* Loader_DLL.xex 0x830ADA20: tailcall fn_830AC6F8 */
ts4_word ts4_tailcall_fn_830AC6F8_830ADA20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830AC6F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830ADAE0: tailcall fn_830ACE48 */
ts4_word ts4_tailcall_fn_830ACE48_830ADAE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_830ACE48((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x830ADB00: tailcall fn_830ACE48 */
ts4_word ts4_tailcall_fn_830ACE48_830ADB00(ts4_word a0)
{
    return fn_830ACE48((ts4_word)a0);
}

/* Loader_DLL.xex 0x830ADB08: get u32@0x30, u32@0x20, fn_830AEE68 */
ts4_word ts4_get_u32_off30_830ADB08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return fn_830AEE68((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) & 0xfffff000), (ts4_word)(t1 & 0xfffff000));
}

/* Loader_DLL.xex 0x830ADB20: get u32@0x24 */
ts4_word ts4_get_u32_off24_830ADB20(ts4_word a0)
{
    return ((((*(ts4_word *)((char *)(ts4_word)(a0) + 36))) >> 26) + 1);
}

/* Loader_DLL.xex 0x830ADB30: tailcall fn_830AC6F8 */
ts4_word ts4_tailcall_fn_830AC6F8_830ADB30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830AC6F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830ADBF0: tailcall fn_830ACE48 */
ts4_word ts4_tailcall_fn_830ACE48_830ADBF0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_830ACE48((ts4_word)a0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x830ADC10: tailcall fn_830ACE48 */
ts4_word ts4_tailcall_fn_830ACE48_830ADC10(ts4_word a0)
{
    return fn_830ACE48((ts4_word)a0);
}

/* Loader_DLL.xex 0x830ADC18: get u32@0x30, u32@0x20, fn_830AEE68 */
ts4_word ts4_get_u32_off30_830ADC18(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return fn_830AEE68((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) & 0xfffff000), (ts4_word)(t1 & 0xfffff000));
}

/* Loader_DLL.xex 0x830ADC30: tailcall fn_830AC7F8 */
ts4_word ts4_tailcall_fn_830AC7F8_830ADC30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830AC7F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830ADD00: tailcall fn_830ACED8 */
ts4_word ts4_tailcall_fn_830ACED8_830ADD00(ts4_word a0)
{
    return fn_830ACED8((ts4_word)a0);
}

/* Loader_DLL.xex 0x830ADD08: get u32@0x30, u32@0x20, fn_830AEE68 */
ts4_word ts4_get_u32_off30_830ADD08(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return fn_830AEE68((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) & 0xfffff000), (ts4_word)(t1 & 0xfffff000));
}

/* Loader_DLL.xex 0x830ADD20: tailcall fn_830AC6F8 */
ts4_word ts4_tailcall_fn_830AC6F8_830ADD20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_830AC6F8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x830ADDF8: tailcall fn_830ACE48 */
ts4_word ts4_tailcall_fn_830ACE48_830ADDF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    return fn_830ACE48((ts4_word)a0, (ts4_word)0, (ts4_word)0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x830ADE18: tailcall fn_830ACE48 */
ts4_word ts4_tailcall_fn_830ACE48_830ADE18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_830ACE48((ts4_word)a0, (ts4_word)a1, (ts4_word)0, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x830ADE30: get u32@0x30, u32@0x20, fn_830AEE68 */
ts4_word ts4_get_u32_off30_830ADE30(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 48);
    return fn_830AEE68((ts4_word)a0, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 32)) & 0xfffff000), (ts4_word)(t1 & 0xfffff000));
}

/* Loader_DLL.xex 0x830AE138: get u32@0x1c, u32@0x18, fn_830ACE48 */
ts4_word ts4_get_u32_off1c_830AE138(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    return fn_830ACE48((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)0, (ts4_word)((t1 >> 22) & 0x3f), (ts4_word)((t1) >> 28), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830AE160: get u32@0x1c, u32@0x18, fn_830ACE48 */
ts4_word ts4_get_u32_off1c_830AE160(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    return fn_830ACE48((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)a1, (ts4_word)((t1 >> 22) & 0x3f), (ts4_word)((t1) >> 28), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4);
}

/* Loader_DLL.xex 0x830AE180: get u32@0x18, u32@0x30, u32@0x20, fn_830AEE68 */
ts4_word ts4_get_u32_off18_830AE180(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 48);
    return fn_830AEE68((ts4_word)t1, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 32)) & 0xfffff000), (ts4_word)(t2 & 0xfffff000));
}

/* Loader_DLL.xex 0x830AE218: get u32@0x1c, u32@0x18, fn_830ACED8 */
ts4_word ts4_get_u32_off1c_830AE218(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    return fn_830ACED8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 24)), (ts4_word)((t1) >> 28), (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x830AE238: get u32@0x18, u32@0x30, u32@0x20, fn_830AEE68 */
ts4_word ts4_get_u32_off18_830AE238(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 48);
    return fn_830AEE68((ts4_word)t1, (ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 32)) & 0xfffff000), (ts4_word)(t2 & 0xfffff000));
}

/* Loader_DLL.xex 0x830AE458: fn  */
void ts4_fn_830AE458(void)
{
    return;
}

/* Loader_DLL.xex 0x830AE4C0: fn  */
ts4_word ts4_fn_830AE4C0(ts4_word a0)
{
    return (((((a0) >> 20) + 512) & 0x1000) + (a0 & 0x1fffffff));
}

/* Loader_DLL.xex 0x830AE500: fn  */
void ts4_fn_830AE500(void)
{
    return;
}

/* Loader_DLL.xex 0x830AE508: fn  */
void ts4_fn_830AE508(void)
{
    return;
}

/* Loader_DLL.xex 0x830AE510: fn  */
ts4_word ts4_fn_830AE510(ts4_word a0)
{
    return ((int)a0 >> 16);
}
