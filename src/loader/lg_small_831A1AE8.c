/* Loader_DLL.xex 0x831A1AE8-0x8321EB00, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char fn_831CC630[];
extern char lbl_830009F8[];
extern char lbl_83000AE8[];
extern char lbl_8300EB74[];
extern char lbl_83019614[];
extern char lbl_83085988[];
extern char lbl_8352A0A8[];
extern char lbl_83531690[];
ts4_word fn_8310D380();
ts4_word fn_83120518();
ts4_word fn_83120540();
ts4_word fn_8316F128();
ts4_word fn_831A1878();
ts4_word fn_831A1880();
ts4_word fn_831B22D8();
ts4_word fn_831B2F70();
ts4_word fn_831B3018();
ts4_word fn_831B35F8();
ts4_word fn_831B36F0();
ts4_word fn_831B3E18();
ts4_word fn_831B3E98();
ts4_word fn_831B4168();
ts4_word fn_831B4AF8();
ts4_word fn_831B5058();
ts4_word fn_831B50B0();
ts4_word fn_831B5290();
ts4_word fn_831B5348();
ts4_word fn_831B6320();
ts4_word fn_831B73D8();
ts4_word fn_831B88B0();
ts4_word fn_831BAF50();
ts4_word fn_831C1690();
ts4_word fn_831C6E20();
ts4_word fn_831C7888();
ts4_word fn_831CC758();
ts4_word fn_831D0588();
ts4_word fn_831DDA08();
ts4_word fn_831EF1A8();
ts4_word fn_831EF280();
ts4_word fn_831EF3D8();
ts4_word fn_831EF578();
ts4_word fn_831F2E18();
ts4_word fn_831F3B08();
ts4_word fn_831F45E8();
ts4_word fn_831FF158();
ts4_word fn_832087B0();
ts4_word fn_83208B08();
ts4_word fn_8320C048();
ts4_word fn_8320C058();
ts4_word fn_8320C068();
ts4_word fn_8320C2A8();
ts4_word fn_832107B0();
ts4_word fn_83210E98();
ts4_word fn_832118B8();
ts4_word fn_83218488();
ts4_word fn_83219130();
ts4_word fn_83219850();
ts4_word fn_8321AA60();
ts4_word fn_8321B8C8();
ts4_word fn_8321BC08();
ts4_word fn_8321C3C8();
ts4_word fn_8321CB40();
ts4_word fn_8321CE60();
ts4_word fn_8321D538();
ts4_word fn_8321D5E8();
ts4_word fn_8321D608();
ts4_word fn_8321DB70();
ts4_word fn_8321DCD0();
ts4_word fn_8321DCE0();
ts4_word fn_8321DD88();
ts4_word fn_833E25A8();
ts4_word fn_833E3A30();
ts4_word fn_833E71B8();
ts4_word fn_8340A360();
ts4_word fn_8340AED8();
ts4_word fn_8340CEF0();
ts4_word fn_8340D380();
ts4_word fn_8340D540();
ts4_word fn_8340D710();
ts4_word fn_8340D830();

/* Loader_DLL.xex 0x831A1AE8: tailcall fn_831A1880 */
ts4_word ts4_tailcall_fn_831A1880_831A1AE8(ts4_word a0)
{
    return fn_831A1880((ts4_word)(a0 + -4));
}

/* Loader_DLL.xex 0x831A1B08: tailcall fn_831A1878 */
ts4_word ts4_tailcall_fn_831A1878_831A1B08(ts4_word a0)
{
    return fn_831A1878((ts4_word)(a0 + -4));
}

/* Loader_DLL.xex 0x831B13C0: fn  */
void ts4_fn_831B13C0(void)
{
    return;
}

/* Loader_DLL.xex 0x831B1470: set  */
void ts4_set_831B1470(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 2060) = f1;
    *(float *)((char *)(ts4_word)(a0) + 2064) = (-f1);
    return;
}

/* Loader_DLL.xex 0x831B1480: get u32@0x800, u32@0x808, u32@0x804 */
void ts4_get_u32_off800_831B1480(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 2048);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2056) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 2052) = (ts4_word)((t1 - a1) & 0x1ff);
    return;
}

/* Loader_DLL.xex 0x831B1498: get u32@0x808 */
ts4_word ts4_get_u32_off808_831B1498(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 2056));
}

/* Loader_DLL.xex 0x831B14A0: get  */
float ts4_get_831B14A0(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 2068));
}

/* Loader_DLL.xex 0x831B14A8: fn  */
void ts4_fn_831B14A8(void)
{
    return;
}

/* Loader_DLL.xex 0x831B1558: set  */
void ts4_set_831B1558(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4108) = f1;
    return;
}

/* Loader_DLL.xex 0x831B1560: set  */
void ts4_set_831B1560(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4112) = f1;
    return;
}

/* Loader_DLL.xex 0x831B1568: set u32@0x1004 */
void ts4_set_u32_off1004_831B1568(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4100) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831B1570: set u32@0x1008 */
void ts4_set_u32_off1008_831B1570(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4104) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831B1578: get  */
float ts4_get_831B1578(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 4116));
}

/* Loader_DLL.xex 0x831B1580: get  */
float ts4_get_831B1580(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 4120));
}

/* Loader_DLL.xex 0x831B1588: fn  */
void ts4_fn_831B1588(void)
{
    return;
}

/* Loader_DLL.xex 0x831B1678: set  */
void ts4_set_831B1678(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 16400) = f1;
    return;
}

/* Loader_DLL.xex 0x831B1680: set u32@0x4004 */
void ts4_set_u32_off4004_831B1680(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16388) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831B1688: set u32@0x4008 */
void ts4_set_u32_off4008_831B1688(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 16392) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831B1690: get u32@0x4004 */
ts4_word ts4_get_u32_off4004_831B1690(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16388));
}

/* Loader_DLL.xex 0x831B1698: get u32@0x4008 */
ts4_word ts4_get_u32_off4008_831B1698(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16392));
}

/* Loader_DLL.xex 0x831B16A0: get  */
float ts4_get_831B16A0(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 16404));
}

/* Loader_DLL.xex 0x831B16A8: get  */
float ts4_get_831B16A8(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 16408));
}

/* Loader_DLL.xex 0x831B16B0: fn  */
void ts4_fn_831B16B0(void)
{
    return;
}

/* Loader_DLL.xex 0x831B1760: get u32@0x2000, u32@0x2008, u32@0x2004 */
void ts4_get_u32_off2000_831B1760(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8192);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8200) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8196) = (ts4_word)((t1 - a1) & 0x7ff);
    return;
}

/* Loader_DLL.xex 0x831B1778: get u32@0x2008 */
ts4_word ts4_get_u32_off2008_831B1778(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8200));
}

/* Loader_DLL.xex 0x831B1780: get  */
float ts4_get_831B1780(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 8212));
}

/* Loader_DLL.xex 0x831B1788: fn  */
void ts4_fn_831B1788(void)
{
    return;
}

/* Loader_DLL.xex 0x831B1838: set  */
void ts4_set_831B1838(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 4108) = f1;
    *(float *)((char *)(ts4_word)(a0) + 4112) = (-f1);
    return;
}

/* Loader_DLL.xex 0x831B1848: get u32@0x1000, u32@0x1008, u32@0x1004 */
void ts4_get_u32_off1000_831B1848(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4096);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4104) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4100) = (ts4_word)((t1 - a1) & 0x3ff);
    return;
}

/* Loader_DLL.xex 0x831B1860: get u32@0x1008 */
ts4_word ts4_get_u32_off1008_831B1860(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4104));
}

/* Loader_DLL.xex 0x831B1868: get  */
float ts4_get_831B1868(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 4116));
}

/* Loader_DLL.xex 0x831B1870: fn  */
void ts4_fn_831B1870(void)
{
    return;
}

/* Loader_DLL.xex 0x831B1878: call_seq fn_833E3A30, u32@0x2000 */
ts4_word ts4_call_seq_fn_833E3A30_831B1878(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)8192);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8192) = (ts4_word)0;
    return t1;
}

/* Loader_DLL.xex 0x831B18F0: get  */
void ts4_get_831B18F0(ts4_word a0)
{
    float t1;

    t1 = *(float *)lbl_830009F8;
    *(float *)((char *)(ts4_word)(a0) + 0) = t1;
    *(float *)((char *)(ts4_word)(a0) + 4) = t1;
    return;
}

/* Loader_DLL.xex 0x831B1908: fn  */
void ts4_fn_831B1908(void)
{
    return;
}

/* Loader_DLL.xex 0x831B1CF0: fn  */
void ts4_fn_831B1CF0(void)
{
    return;
}

/* Loader_DLL.xex 0x831B1EB0: fn  */
void ts4_fn_831B1EB0(void)
{
    return;
}

/* Loader_DLL.xex 0x831B1FA0: fn  */
void ts4_fn_831B1FA0(void)
{
    return;
}

/* Loader_DLL.xex 0x831B4278: if_tail fn_831B4168, fn_831B3E18, fn_831B3E98, fn_831B36F0 */
ts4_word ts4_if_tail_fn_831B4168_831B4278(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a2 == 1) {
        return fn_831B36F0((ts4_word)a0);
    }
    if ((ts4_word)a2 == 2) {
        return fn_831B3E98((ts4_word)a0);
    }
    if ((ts4_word)a1 == 1) {
        return fn_831B3E18((ts4_word)a0);
    }
    return fn_831B4168((ts4_word)a0);
}

/* Loader_DLL.xex 0x831B42A0: if_tail fn_831B35F8, fn_831B2F70, fn_831B3018, fn_831B22D8 */
ts4_word ts4_if_tail_fn_831B35F8_831B42A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    if ((ts4_word)a2 == 1) {
        return fn_831B22D8((ts4_word)a0, (ts4_word)a3);
    }
    if ((ts4_word)a2 == 2) {
        return fn_831B3018((ts4_word)a0, (ts4_word)a3);
    }
    if ((ts4_word)a1 == 1) {
        return fn_831B2F70((ts4_word)a0, (ts4_word)a3);
    }
    return fn_831B35F8((ts4_word)a0, (ts4_word)a3);
}

/* Loader_DLL.xex 0x831B4360: call_seq fn_833E3A30, u32@0x400 */
ts4_word ts4_call_seq_fn_833E3A30_831B4360(ts4_word a0)
{
    fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)1024);
    *(ts4_word *)((char *)(ts4_word)(a0) + 1024) = (ts4_word)0;
    return a0;
}

/* Loader_DLL.xex 0x831B43A0: call_seq fn_833E3A30, u32@0x800 */
ts4_word ts4_call_seq_fn_833E3A30_831B43A0(ts4_word a0)
{
    fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)2048);
    *(ts4_word *)((char *)(ts4_word)(a0) + 2048) = (ts4_word)0;
    return a0;
}

/* Loader_DLL.xex 0x831B44E0: fn  */
void ts4_fn_831B44E0(void)
{
    return;
}

/* Loader_DLL.xex 0x831B4840: call_seq fn_833E3A30, u32@0x2000 */
ts4_word ts4_call_seq_fn_833E3A30_831B4840(ts4_word a0)
{
    fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)8192);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8192) = (ts4_word)0;
    return a0;
}

/* Loader_DLL.xex 0x831B4AE8: fn  */
void ts4_fn_831B4AE8(void)
{
    return;
}

/* Loader_DLL.xex 0x831B4AF0: fn  */
void ts4_fn_831B4AF0(void)
{
    return;
}

/* Loader_DLL.xex 0x831B9FB8: if_tail fn_831B5290, fn_831B5058, fn_831B50B0, fn_831B4AF8 */
ts4_word ts4_if_tail_fn_831B5290_831B9FB8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a2 == 1) {
        return fn_831B4AF8((ts4_word)a0);
    }
    if ((ts4_word)a2 == 2) {
        return fn_831B50B0((ts4_word)a0);
    }
    if ((ts4_word)a1 == 1) {
        return fn_831B5058((ts4_word)a0);
    }
    return fn_831B5290((ts4_word)a0);
}

/* Loader_DLL.xex 0x831B9FE0: if_tail fn_831B88B0, fn_831B6320, fn_831B73D8, fn_831B5348 */
ts4_word ts4_if_tail_fn_831B88B0_831B9FE0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    if ((ts4_word)a2 == 1) {
        return fn_831B5348((ts4_word)a0, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
    }
    if ((ts4_word)a2 == 2) {
        return fn_831B73D8((ts4_word)a0, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
    }
    if ((ts4_word)a1 == 1) {
        return fn_831B6320((ts4_word)a0, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
    }
    return fn_831B88B0((ts4_word)a0, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
}

/* Loader_DLL.xex 0x831BAF08: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x14 */
void ts4_set_u32_off0_831BAF08(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(float *)((char *)(ts4_word)(a0) + 16) = (*(float *)lbl_830009F8);
    return;
}

/* Loader_DLL.xex 0x831BAF30: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_831BAF30(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x831BB1A0: if_tail fn_831BAF50, fn_831BAF50 */
ts4_word ts4_if_tail_fn_831BAF50_831BB1A0(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_831BAF50((ts4_word)a2);
    }
    return fn_831BAF50((ts4_word)a2);
}

/* Loader_DLL.xex 0x831BB230: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_831BB230(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x831BB240: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_831BB240(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x831BB250: fn  */
ts4_word ts4_fn_831BB250(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831BB258: fn  */
void ts4_fn_831BB258(void)
{
    return;
}

/* Loader_DLL.xex 0x831BB260: fn  */
void ts4_fn_831BB260(void)
{
    return;
}

/* Loader_DLL.xex 0x831BB268: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_831BB268(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x831BB278: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_831BB278(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x831BB408: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_831BB408(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831BB710: set u32@0x58, u32@0x64 */
ts4_word ts4_set_u32_off58_831BB710(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 88) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 100) = (ts4_word)a2;
    return 0;
}

/* Loader_DLL.xex 0x831BCA88: if_get u32@0x1bc, u32@0x1c0, u32@0x1c0, u32@0x1c8, u32@0x1c8 */
ts4_word ts4_if_get_u32_off1bc_831BCA88(ts4_word a0, ts4_word a1)
{
    int t1;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 444);
    if ((int)t1 != 0) {
        return ((int)a1 >> (*(ts4_word *)((char *)(ts4_word)(a0) + 456)));
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 448);
    if ((int)t3 != 0) {
        return (a1 << (*(ts4_word *)((char *)(ts4_word)(a0) + 456)));
    }
    return a1;
}

/* Loader_DLL.xex 0x831BD2E0: get  */
ts4_word ts4_get_831BD2E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    return ((short)(*(unsigned short *)((char *)(ts4_word)((a3 << 1)) + a0)));
}

/* Loader_DLL.xex 0x831BD2F0: get  */
ts4_word ts4_get_831BD2F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    return ((int)(*(ts4_word *)((char *)(ts4_word)((a3 + (a3 << 1))) + a0)) >> 8);
}

/* Loader_DLL.xex 0x831BD308: get u8@0x2, u16@0x0 */
ts4_word ts4_get_u8_off2_831BD308(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    unsigned char t1;

    (void)a1;
    (void)a2;
    t1 = *(unsigned char *)((char *)(ts4_word)(((a3 + (a3 << 1)) + a0)) + 2);
    return ((int)((((signed char)t1) << 16) | (*(unsigned short *)((char *)(ts4_word)(((a3 + (a3 << 1)) + a0)) + 0))) >> 4);
}

/* Loader_DLL.xex 0x831BD388: set  */
void ts4_set_831BD388(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    *(unsigned short *)((char *)(ts4_word)((a3 << 1)) + a1) = (unsigned short)a0;
    return;
}

/* Loader_DLL.xex 0x831BD400: fn  */
ts4_word ts4_fn_831BD400(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831BD4E0: fn  */
void ts4_fn_831BD4E0(void)
{
    return;
}

/* Loader_DLL.xex 0x831BF310: if_fn  */
ts4_word ts4_if_fn_831BF310(int a0, ts4_word a1)
{
    if ((int)a0 >= 0) {
        return ((((int)(1 << a1) >> 1) + a0) & ~((1 << a1) + -1));
    }
    return (((((int)(1 << a1) >> 1) + a0) + -1) & ~((1 << a1) + -1));
}

/* Loader_DLL.xex 0x831BF720: fn  */
void ts4_fn_831BF720(void)
{
    return;
}

/* Loader_DLL.xex 0x831BF728: fn  */
void ts4_fn_831BF728(void)
{
    return;
}

/* Loader_DLL.xex 0x831BF730: fn  */
void ts4_fn_831BF730(void)
{
    return;
}

/* Loader_DLL.xex 0x831BF738: fn  */
ts4_word ts4_fn_831BF738(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831BF798: fn  */
ts4_word ts4_fn_831BF798(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831C0FD8: get u32@0x28 */
ts4_word ts4_get_u32_off28_831C0FD8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 40));
}

/* Loader_DLL.xex 0x831C0FE0: get u32@0x20 */
ts4_word ts4_get_u32_off20_831C0FE0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x831C0FE8: set u32@0xc */
void ts4_set_u32_offc_831C0FE8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831C0FF0: fn  */
void ts4_fn_831C0FF0(void)
{
    return;
}

/* Loader_DLL.xex 0x831C1910: tailcall fn_831C1690 */
ts4_word ts4_tailcall_fn_831C1690_831C1910(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    return fn_831C1690((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)0);
}

/* Loader_DLL.xex 0x831C1918: tailcall fn_831C1690 */
ts4_word ts4_tailcall_fn_831C1690_831C1918(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    return fn_831C1690((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6, (ts4_word)((a7 ^ 2876637184) ^ 14558));
}

/* Loader_DLL.xex 0x831C6758: fn  */
ts4_word ts4_fn_831C6758(void)
{
    return 1;
}

/* Loader_DLL.xex 0x831C6840: fn  */
ts4_word ts4_fn_831C6840(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831C6B98: fn  */
ts4_word ts4_fn_831C6B98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return (((int)a1 * (int)a2) + a0);
}

/* Loader_DLL.xex 0x831C6EA0: addr lbl_8300EB74, fn_831C6E20 */
ts4_word ts4_addr_lbl_8300EB74_831C6EA0(ts4_word a0)
{
    return fn_831C6E20((ts4_word)(ts4_word)lbl_8300EB74, (ts4_word)a0);
}

/* Loader_DLL.xex 0x831C7958: call_seq fn_831C7888 */
ts4_word ts4_call_seq_fn_831C7888_831C7958(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_831C7888((ts4_word)a0, (ts4_word)a1);
    return (t1 - a1);
}

/* Loader_DLL.xex 0x831C8B28: get u32@0x11c, u32@0x78, u32@0x0, u32@0x58, u32@0x0 */
void ts4_get_u32_off11c_831C8B28(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 284);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 120);
    t3 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(((int)(*(ts4_word *)((char *)(ts4_word)(t1) + 88)) * (int)t2) + t3);
    return;
}

/* Loader_DLL.xex 0x831CC730: if_get u32@0x0, u32@0x24c, fn_831CC630, u32@0x204, u32@0x1e4 */
void ts4_if_get_u32_off0_831CC730(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 588);
    if ((int)t2 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 516) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 484) = (ts4_word)(ts4_word)fn_831CC630;
    return;
}

/* Loader_DLL.xex 0x831CC8F0: call_seq fn_831CC758 */
ts4_word ts4_call_seq_fn_831CC758_831CC8F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = fn_831CC758((ts4_word)a1, (ts4_word)a2, (ts4_word)a0, (ts4_word)0);
    return ((t1 << 4) + t1);
}

/* Loader_DLL.xex 0x831CD7A8: if_addr lbl_83019614 */
ts4_word ts4_if_addr_lbl_83019614_831CD7A8(ts4_word a0)
{
    if ((ts4_word)a0 >= 9) {
        return 0;
    }
    return (*(ts4_word *)((char *)(ts4_word)((a0 << 2)) + (ts4_word)lbl_83019614));
}

/* Loader_DLL.xex 0x831CE078: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_831CE078(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x831CE088: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_831CE088(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x831CE098: fn  */
void ts4_fn_831CE098(void)
{
    return;
}

/* Loader_DLL.xex 0x831CE0A0: fn  */
void ts4_fn_831CE0A0(void)
{
    return;
}

/* Loader_DLL.xex 0x831CE1A8: if_fn  */
ts4_word ts4_if_fn_831CE1A8(ts4_word a0)
{
    if ((int)(a0 & 0xffff) != 16) {
        if ((int)(a0 & 0xffff) != 20) {
            if ((int)(a0 & 0xffff) != 24) {
                return 255;
            }
            return 2;
        }
        return 1;
    }
    return 0;
}

/* Loader_DLL.xex 0x831CE1E8: fn  */
void ts4_fn_831CE1E8(void)
{
    return;
}

/* Loader_DLL.xex 0x831CE1F8: get u32@0x4c */
ts4_word ts4_get_u32_off4c_831CE1F8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 76));
}

/* Loader_DLL.xex 0x831CE200: get u32@0x8 */
ts4_word ts4_get_u32_off8_831CE200(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x831CE208: get u32@0xc */
ts4_word ts4_get_u32_offc_831CE208(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 12));
}

/* Loader_DLL.xex 0x831CE210: get u32@0x30 */
ts4_word ts4_get_u32_off30_831CE210(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 48));
}

/* Loader_DLL.xex 0x831CE218: get u32@0x34 */
ts4_word ts4_get_u32_off34_831CE218(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
}

/* Loader_DLL.xex 0x831CE220: get u32@0xc */
ts4_word ts4_get_u32_offc_831CE220(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) + -36);
}

/* Loader_DLL.xex 0x831CE230: get u32@0xc */
ts4_word ts4_get_u32_offc_831CE230(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 12)) + -16);
}

/* Loader_DLL.xex 0x831CF6C0: fn  */
ts4_word ts4_fn_831CF6C0(ts4_word a0)
{
    ts4_word loc14[1];
    unsigned char t1;
    unsigned char t2;
    unsigned char t3;
    unsigned char t4;

    loc14[0] = (ts4_word)a0;
    t1 = *(unsigned char *)((char *)loc14 + 2);
    t2 = *(unsigned char *)((char *)loc14 + 3);
    t3 = *(unsigned char *)((char *)loc14 + 1);
    t4 = *(unsigned char *)((char *)loc14 + 0);
    return (((((((((((((t4 << 8) | (t4 >> 24)) & 0xff00) | (t3 & 0xffff00ff)) & 0xffff) << 8) | ((((((t4 << 8) | (t4 >> 24)) & 0xff00) | (t3 & 0xffff00ff)) & 0xffff) >> 24)) & 0xffffff00) | (t1 & 0xff)) << 8) | ((((((((((t4 << 8) | (t4 >> 24)) & 0xff00) | (t3 & 0xffff00ff)) & 0xffff) << 8) | ((((((t4 << 8) | (t4 >> 24)) & 0xff00) | (t3 & 0xffff00ff)) & 0xffff) >> 24)) & 0xffffff00) | (t1 & 0xff)) >> 24)) & 0xffffff00) | (t2 & 0xff));
}

/* Loader_DLL.xex 0x831CF778: fn  */
void ts4_fn_831CF778(void)
{
    return;
}

/* Loader_DLL.xex 0x831CF780: fn  */
void ts4_fn_831CF780(void)
{
    return;
}

/* Loader_DLL.xex 0x831CFD60: get u32@0x24, u32@0x74, u32@0x48 */
ts4_word ts4_get_u32_off24_831CFD60(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 116);
    return (((t1 - t2) << 3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 72)));
}

/* Loader_DLL.xex 0x831D07C8: tailcall fn_831D0588 */
ts4_word ts4_tailcall_fn_831D0588_831D07C8(ts4_word a0)
{
    return fn_831D0588((ts4_word)a0);
}

/* Loader_DLL.xex 0x831D5080: set u32@0xc, u32@0x10, u32@0x4 */
void ts4_set_u32_offc_831D5080(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)32;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831D5340: get u32@0x0, u32@0xc, u32@0x10, u32@0x4, u32@0x8 */
void ts4_get_u32_off0_831D5340(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)32;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t1;
    return;
}

/* Loader_DLL.xex 0x831D5410: get u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x14 */
void ts4_get_u32_off0_831D5410(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)t5;
    return;
}

/* Loader_DLL.xex 0x831D5440: get u32@0x14, u32@0x18, u32@0x1c, u32@0x20, u32@0x24, u32@0x0 */
void ts4_get_u32_off14_831D5440(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;
    ts4_word t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 20);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    t4 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    t5 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)t2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)t5;
    return;
}

/* Loader_DLL.xex 0x831D5530: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_831D5530(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4));
    *(ts4_word *)((char *)(ts4_word)(a1) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 8));
    *(ts4_word *)((char *)(ts4_word)(a1) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    *(ts4_word *)((char *)(ts4_word)(a1) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 16));
    return;
}

/* Loader_DLL.xex 0x831D5560: get u32@0x0, u32@0x0, u32@0x4, u32@0x4, u32@0x8, u32@0x8 */
void ts4_get_u32_off0_831D5560(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4));
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 8));
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 16));
    return;
}

/* Loader_DLL.xex 0x831D5590: get u32@0x4, u32@0x18, u32@0x10, u32@0x24 */
ts4_word ts4_get_u32_off4_831D5590(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return ((((t1 - t2) << 3) - t3) + (*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
}

/* Loader_DLL.xex 0x831D5770: fn  */
void ts4_fn_831D5770(void)
{
    return;
}

/* Loader_DLL.xex 0x831DD400: if_get u32@0x0, u32@0xc, u32@0xc, u32@0x10 */
ts4_word ts4_if_get_u32_off0_831DD400(ts4_word a0)
{
    int t1;
    int t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((int)t1 != 1) {
        t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
        if ((int)t3 != 1 || (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 16)) != 2) {
            return 0;
        }
        return 1;
    }
    return 1;
}

/* Loader_DLL.xex 0x831DDA60: tailcall fn_831DDA08 */
ts4_word ts4_tailcall_fn_831DDA08_831DDA60(ts4_word a0, ts4_word a1)
{
    return fn_831DDA08((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x831DEFA0: if_get u16@0x14, u16@0x6c, u16@0x16 */
ts4_word ts4_if_get_u16_off14_831DEFA0(ts4_word a0, ts4_word a1)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 20);
    if ((int)((short)t1) <= 1) {
        if ((int)((short)t1) != 1 || (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 22)) == (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 108))) {
            return 1;
        }
        return 0;
    }
    return 0;
}

/* Loader_DLL.xex 0x831E8A08: fn  */
ts4_word ts4_fn_831E8A08(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return (((int)a1 * (int)a2) + a0);
}

/* Loader_DLL.xex 0x831EB790: fn  */
ts4_word ts4_fn_831EB790(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return (((int)a1 * (int)a2) + a0);
}

/* Loader_DLL.xex 0x831EB7A0: get  */
ts4_word ts4_get_831EB7A0(ts4_word a0, ts4_word a1)
{
    return ((short)(*(unsigned short *)((char *)(ts4_word)((a1 << 1)) + a0)));
}

/* Loader_DLL.xex 0x831EB7B0: get u8@0x0, u16@0x1 */
ts4_word ts4_get_u8_off0_831EB7B0(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(((a1 + (a1 << 1)) + a0)) + 0);
    return ((((signed char)t1) << 16) | (*(unsigned short *)((char *)(ts4_word)(((a1 + (a1 << 1)) + a0)) + 1)));
}

/* Loader_DLL.xex 0x831EB7D8: get u8@0x2, u16@0x0 */
ts4_word ts4_get_u8_off2_831EB7D8(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(((a1 + (a1 << 1)) + a0)) + 2);
    return ((int)((((signed char)t1) << 16) | (*(unsigned short *)((char *)(ts4_word)(((a1 + (a1 << 1)) + a0)) + 0))) >> 4);
}

/* Loader_DLL.xex 0x831EBD00: loop_set u8@0x0, u8@0x0, u8@0x0 */
void ts4_loop_set_u8_off0_831EBD00(ts4_word a0, ts4_word a1, int a2, ts4_word a3)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word p5;
    unsigned char t3;

    (void)a0;
    *(unsigned char *)((char *)(ts4_word)(a3) + 0) = (unsigned char)0;
    if ((int)a2 <= 0) {
        return;
    }
    c1 = (ts4_word)a2;
    lv2 = (ts4_word)0;
    do {
        t3 = *(unsigned char *)((char *)(ts4_word)(lv2) + a1);
        *(unsigned char *)((char *)(ts4_word)(a3) + 0) = (unsigned char)((t3 & lv2) ^ (*(unsigned char *)((char *)(ts4_word)(a3) + 0)));
        p5 = (ts4_word)(lv2 + 1);
        lv2 = p5;
    } while (--c1 != 0);
    return;
}

/* Loader_DLL.xex 0x831ED2B0: fn  */
ts4_word ts4_fn_831ED2B0(void)
{
    return (2147745792);
}

/* Loader_DLL.xex 0x831ED418: fn  */
ts4_word ts4_fn_831ED418(void)
{
    return (2147745792);
}

/* Loader_DLL.xex 0x831ED488: if_fn  */
ts4_word ts4_if_fn_831ED488(int a0)
{
    if ((int)a0 >= 0) {
        return a0;
    }
    return (~(a0 | a0));
}

/* Loader_DLL.xex 0x831ED498: if_get u32@0x0, u32@0x0 */
void ts4_if_get_u32_off0_831ED498(ts4_word a0, int a1, double f1)
{
    ts4_word p2;
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + 2384)) + 0);
    p2 = (ts4_word)t1;
    if ((int)a1 > (int)t1) {
        p2 = (ts4_word)a1;
    }
    *(ts4_word *)((char *)(ts4_word)(((a0 + 65536) + 2384)) + 0) = (ts4_word)p2;
    *(double *)((char *)(ts4_word)(((a0 + 65536) + 2376)) + 0) = (f1 + (*(double *)((char *)(ts4_word)(((a0 + 65536) + 2376)) + 0)));
    return;
}

/* Loader_DLL.xex 0x831ED5E0: if_get u32@0x0, u32@0x0, u32@0x3c, u32@0x1d4, u16@0x1d8, u32@0x0 */
ts4_word ts4_if_get_u32_off0_831ED5E0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word t1;
    int t3;
    ts4_word t4;

    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)a2 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)0;
    }
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 60);
    t4 = *(ts4_word *)((char *)(ts4_word)(a1) + 468);
    if ((int)t3 <= 2) {
        return t4;
    }
    if ((ts4_word)a2 == 0) {
        return t4;
    }
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a1) + 472));
    return t4;
}

/* Loader_DLL.xex 0x831EF718: if_get u32@0x0, u32@0x60, fn_831EF280, fn_831EF578, fn_831EF3D8, fn_831EF1A8 */
ts4_word ts4_if_get_u32_off0_831EF718(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 96);
    if ((int)t2 != 61) {
        if ((int)t2 != 78) {
            if ((int)t2 != 94) {
                return fn_831EF1A8((ts4_word)a0);
            }
            return fn_831EF3D8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
        }
        return fn_831EF578((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    }
    return fn_831EF280((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x831F2DF8: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_831F2DF8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x831F2F68: if_tail fn_831F2E18, fn_831F2E18 */
ts4_word ts4_if_tail_fn_831F2E18_831F2F68(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_831F2E18((ts4_word)a2);
    }
    return fn_831F2E18((ts4_word)a2);
}

/* Loader_DLL.xex 0x831F3538: get u32@0x98, u32@0x98 */
void ts4_get_u32_off98_831F3538(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 152)) + 1);
    return;
}

/* Loader_DLL.xex 0x831F3548: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_831F3548(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x831F3600: set u32@0x4 */
void ts4_set_u32_off4_831F3600(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x831F3610: set u32@0x4 */
void ts4_set_u32_off4_831F3610(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831F3620: get u32@0x2c */
ts4_word ts4_get_u32_off2c_831F3620(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 44));
}

/* Loader_DLL.xex 0x831F3628: fn  */
ts4_word ts4_fn_831F3628(ts4_word a0)
{
    return (a0 + 56);
}

/* Loader_DLL.xex 0x831F3630: set u32@0x74 */
void ts4_set_u32_off74_831F3630(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x831F36C8: set u32@0x74 */
void ts4_set_u32_off74_831F36C8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 116) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x831F36D8: get u32@0x84, u32@0x4, u32@0x0, fn_8320C2A8 */
ts4_word ts4_get_u32_off84_831F36D8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 132))) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return fn_8320C2A8((ts4_word)a0);
}

/* Loader_DLL.xex 0x831F3AE0: get u32@0x20 */
ts4_word ts4_get_u32_off20_831F3AE0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 32));
}

/* Loader_DLL.xex 0x831F3AE8: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_831F3AE8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x831F3C00: if_tail fn_831F3B08, fn_831F3B08 */
ts4_word ts4_if_tail_fn_831F3B08_831F3C00(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_831F3B08((ts4_word)a2);
    }
    return fn_831F3B08((ts4_word)a2);
}

/* Loader_DLL.xex 0x831F3C88: if_tail fn_831F3B08, fn_831F3B08 */
ts4_word ts4_if_tail_fn_831F3B08_831F3C88(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_831F3B08((ts4_word)a2);
    }
    return fn_831F3B08((ts4_word)a2);
}

/* Loader_DLL.xex 0x831F42E0: if_set u32@0x104, fn_8320C048 */
ts4_word ts4_if_set_u32_off104_831F42E0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return fn_8320C048((ts4_word)a0);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)1;
    return a0;
}

/* Loader_DLL.xex 0x831F42F8: if_set u32@0x104, fn_8320C058 */
ts4_word ts4_if_set_u32_off104_831F42F8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return fn_8320C058((ts4_word)a0);
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 260) = (ts4_word)0;
    return a0;
}

/* Loader_DLL.xex 0x831F4310: if_get u32@0x104, fn_8320C068 */
ts4_word ts4_if_get_u32_off104_831F4310(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return fn_8320C068((ts4_word)a0);
    }
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 260));
}

/* Loader_DLL.xex 0x831F4440: set u32@0x108 */
void ts4_set_u32_off108_831F4440(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 264) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831F4448: if_get u32@0x18, u32@0x0 */
ts4_word ts4_if_get_u32_off18_831F4448(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 24);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x831F4468: get u32@0x2c */
ts4_word ts4_get_u32_off2c_831F4468(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 44));
}

/* Loader_DLL.xex 0x831F4480: if_get u32@0x28, u32@0x0 */
ts4_word ts4_if_get_u32_off28_831F4480(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x831F44A0: get u32@0x24 */
ts4_word ts4_get_u32_off24_831F44A0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 36));
}

/* Loader_DLL.xex 0x831F44A8: if_get u32@0x0, u32@0x4, u32@0x0, u32@0x0 */
ts4_word ts4_if_get_u32_off0_831F44A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 0);
    if ((ts4_word)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(t1) + 4));
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Loader_DLL.xex 0x831F45B0: get u32@0x0, u32@0x4, u32@0x0 */
void ts4_get_u32_off0_831F45B0(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a1) + 4) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831F45C0: fn  */
void ts4_fn_831F45C0(void)
{
    return;
}

/* Loader_DLL.xex 0x831F45C8: addr lbl_83531690, fn_8316F128 */
ts4_word ts4_addr_lbl_83531690_831F45C8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8316F128((ts4_word)(ts4_word)lbl_83531690, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x831F46D8: get u32@0x214 */
ts4_word ts4_get_u32_off214_831F46D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 532));
}

/* Loader_DLL.xex 0x831F46E0: get u32@0x220 */
ts4_word ts4_get_u32_off220_831F46E0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 544));
}

/* Loader_DLL.xex 0x831F46E8: if_get u32@0x21c, u32@0x21c */
void ts4_if_get_u32_off21c_831F46E8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 540);
    if ((ts4_word)a1 <= (ts4_word)t1) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 540) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831F4700: if_get u32@0x228, u32@0x228 */
void ts4_if_get_u32_off228_831F4700(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 552);
    if ((ts4_word)a1 <= (ts4_word)t1) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 552) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x831F4890: get u32@0x8 */
ts4_word ts4_get_u32_off8_831F4890(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) != 0);
}

/* Loader_DLL.xex 0x831F48A0: get u32@0xfc */
ts4_word ts4_get_u32_offfc_831F48A0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 252)) != 0);
}

/* Loader_DLL.xex 0x831F48B0: get u32@0xb8, u32@0x0 */
ts4_word ts4_get_u32_offb8_831F48B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 184))) + 0));
}

/* Loader_DLL.xex 0x831F48C0: get u32@0xb8, u32@0x10, u32@0x0 */
ts4_word ts4_get_u32_offb8_831F48C0(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 16);
    return (t2 + (*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
}

/* Loader_DLL.xex 0x831F48D8: get u32@0xb8, u32@0x14, u32@0x10, u32@0x0 */
ts4_word ts4_get_u32_offb8_831F48D8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 20);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 16);
    return ((t2 + t3) + (*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
}

/* Loader_DLL.xex 0x831F48F8: get u32@0xb8, u32@0x18, u32@0x0 */
ts4_word ts4_get_u32_offb8_831F48F8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
    return (t2 + (*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
}

/* Loader_DLL.xex 0x831F4910: get u32@0xb8, u32@0x1c, u32@0x18, u32@0x0 */
ts4_word ts4_get_u32_offb8_831F4910(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
    return ((t2 + t3) + (*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
}

/* Loader_DLL.xex 0x831F4930: get u32@0xb8, u32@0xbc, u32@0x1c, u32@0x18, u32@0x0 */
ts4_word ts4_get_u32_offb8_831F4930(ts4_word a0)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 184);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 188);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 28);
    t4 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
    return (((t3 - t2) + t4) + (*(ts4_word *)((char *)(ts4_word)(t1) + 0)));
}

/* Loader_DLL.xex 0x831F4CF0: fn  */
void ts4_fn_831F4CF0(void)
{
    return;
}

/* Loader_DLL.xex 0x831F4F60: if_tail fn_831F45E8, fn_831F45E8 */
ts4_word ts4_if_tail_fn_831F45E8_831F4F60(ts4_word a0, int a1, ts4_word a2)
{
    (void)a0;
    if ((int)a1 == 0) {
        return fn_831F45E8((ts4_word)a2);
    }
    return fn_831F45E8((ts4_word)a2);
}

/* Loader_DLL.xex 0x831F4F78: if_get u32@0x24, fn_831F45E8, u32@0x24 */
ts4_word ts4_if_get_u32_off24_831F4F78(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 36);
    if ((int)t1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
        return a0;
    }
    return fn_831F45E8((ts4_word)a0);
}

/* Loader_DLL.xex 0x831F6270: fn  */
void ts4_fn_831F6270(void)
{
    return;
}

/* Loader_DLL.xex 0x831F6278: fn  */
ts4_word ts4_fn_831F6278(ts4_word a0)
{
    return ((a0) >> 1);
}

/* Loader_DLL.xex 0x831F6280: fn  */
ts4_word ts4_fn_831F6280(ts4_word a0)
{
    return ((a0) >> 2);
}

/* Loader_DLL.xex 0x831F6288: fn  */
ts4_word ts4_fn_831F6288(ts4_word a0)
{
    return ((a0) >> 1);
}

/* Loader_DLL.xex 0x831F6290: fn  */
ts4_word ts4_fn_831F6290(ts4_word a0)
{
    return ((a0) >> 2);
}

/* Loader_DLL.xex 0x831F6298: fn  */
ts4_word ts4_fn_831F6298(ts4_word a0)
{
    return ((a0) >> 3);
}

/* Loader_DLL.xex 0x831F6310: get u32@0x0, u8@0x0, u32@0x0, u32@0x0 */
void ts4_get_u32_off0_831F6310(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0) = (unsigned char)(((int)a1 >> 8) + 128);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 1);
    return;
}

/* Loader_DLL.xex 0x831F6330: get u32@0x0, u16@0x0, u32@0x0, u32@0x0 */
void ts4_get_u32_off0_831F6330(ts4_word a0, ts4_word a1)
{
    *(unsigned short *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0) = (unsigned short)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0)) + 2);
    return;
}

/* Loader_DLL.xex 0x831F63A8: fn  */
ts4_word ts4_fn_831F63A8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return ((int)(((int)a0 * (int)a1) + ((int)a2 * (int)a3)) >> 8);
}

/* Loader_DLL.xex 0x831FA288: fn  */
void ts4_fn_831FA288(void)
{
    return;
}

/* Loader_DLL.xex 0x831FA290: fn  */
void ts4_fn_831FA290(void)
{
    return;
}

/* Loader_DLL.xex 0x831FA298: fn  */
ts4_word ts4_fn_831FA298(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831FA2A0: fn  */
void ts4_fn_831FA2A0(void)
{
    return;
}

/* Loader_DLL.xex 0x831FA2A8: fn  */
void ts4_fn_831FA2A8(void)
{
    return;
}

/* Loader_DLL.xex 0x831FA2B0: fn  */
void ts4_fn_831FA2B0(void)
{
    return;
}

/* Loader_DLL.xex 0x831FA2B8: fn  */
void ts4_fn_831FA2B8(void)
{
    return;
}

/* Loader_DLL.xex 0x831FA2C0: fn  */
void ts4_fn_831FA2C0(void)
{
    return;
}

/* Loader_DLL.xex 0x831FA2C8: fn  */
ts4_word ts4_fn_831FA2C8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831FA2D0: fn  */
ts4_word ts4_fn_831FA2D0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831FA2D8: fn  */
ts4_word ts4_fn_831FA2D8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831FA2E0: fn  */
void ts4_fn_831FA2E0(void)
{
    return;
}

/* Loader_DLL.xex 0x831FA2E8: fn  */
ts4_word ts4_fn_831FA2E8(void)
{
    return 0;
}

/* Loader_DLL.xex 0x831FA2F0: fn  */
void ts4_fn_831FA2F0(void)
{
    return;
}

/* Loader_DLL.xex 0x831FA2F8: fn  */
void ts4_fn_831FA2F8(void)
{
    return;
}

/* Loader_DLL.xex 0x831FF300: get u32@0x4, u32@0x14, fn_831FF158 */
ts4_word ts4_get_u32_off4_831FF300(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 4);
    return fn_831FF158((ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)), (ts4_word)(-(int)t1), (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x831FF318: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10 */
void ts4_set_u32_off0_831FF318(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83200E38: fn  */
ts4_word ts4_fn_83200E38(void)
{
    return (2147745792);
}

/* Loader_DLL.xex 0x832014E8: fn  */
void ts4_fn_832014E8(void)
{
    return;
}

/* Loader_DLL.xex 0x832014F0: fn  */
void ts4_fn_832014F0(void)
{
    return;
}

/* Loader_DLL.xex 0x832014F8: fn  */
void ts4_fn_832014F8(void)
{
    return;
}

/* Loader_DLL.xex 0x83201500: fn  */
void ts4_fn_83201500(void)
{
    return;
}

/* Loader_DLL.xex 0x83201508: fn  */
void ts4_fn_83201508(void)
{
    return;
}

/* Loader_DLL.xex 0x83201510: fn  */
ts4_word ts4_fn_83201510(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83201518: fn  */
void ts4_fn_83201518(void)
{
    return;
}

/* Loader_DLL.xex 0x83201520: fn  */
ts4_word ts4_fn_83201520(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83201528: fn  */
ts4_word ts4_fn_83201528(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83201530: fn  */
ts4_word ts4_fn_83201530(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83201538: fn  */
ts4_word ts4_fn_83201538(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83201540: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_83201540(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x83201550: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83201550(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((613154816) | 32768));
}

/* Loader_DLL.xex 0x832015D0: get u32@0x8 */
ts4_word ts4_get_u32_off8_832015D0(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + 6);
}

/* Loader_DLL.xex 0x83201680: set u32@0x28, u32@0x10, u32@0x18, u32@0x2c */
void ts4_set_u32_off28_83201680(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83201698: fn  */
void ts4_fn_83201698(void)
{
    return;
}

/* Loader_DLL.xex 0x83201DD0: get u32@0x2c */
ts4_word ts4_get_u32_off2c_83201DD0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 44));
}

/* Loader_DLL.xex 0x83203248: fn  */
ts4_word ts4_fn_83203248(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return (((int)a1 * (int)a2) + a0);
}

/* Loader_DLL.xex 0x83206A00: fn  */
ts4_word ts4_fn_83206A00(void)
{
    return 0;
}

/* Loader_DLL.xex 0x832093B8: if_get u32@0x0, u32@0x3c, u32@0xb0, u16@0x22, fn_83208B08, fn_832087B0 */
ts4_word ts4_if_get_u32_off0_832093B8(ts4_word a0)
{
    ts4_word t1;
    int t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 60);
    if (((int)t2 >= 3 && (int)(*(ts4_word *)((char *)(ts4_word)(t1) + 176)) == 0) && (ts4_word)(*(unsigned short *)((char *)(ts4_word)(t1) + 34)) == 2) {
        return fn_832087B0((ts4_word)a0);
    }
    return fn_83208B08((ts4_word)a0);
}

/* Loader_DLL.xex 0x8320BFC8: fn  */
void ts4_fn_8320BFC8(void)
{
    return;
}

/* Loader_DLL.xex 0x8320C3F8: fn  */
ts4_word ts4_fn_8320C3F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return (((int)a1 * (int)a2) + a0);
}

/* Loader_DLL.xex 0x8320C408: fn  */
ts4_word ts4_fn_8320C408(ts4_word a0, ts4_word a1)
{
    return ((a1 << 1) + a0);
}

/* Loader_DLL.xex 0x8320C418: fn  */
ts4_word ts4_fn_8320C418(ts4_word a0, ts4_word a1)
{
    return ((a1 + (a1 << 1)) + a0);
}

/* Loader_DLL.xex 0x8320C438: get  */
ts4_word ts4_get_8320C438(ts4_word a0, ts4_word a1)
{
    return ((short)(*(unsigned short *)((char *)(ts4_word)((a1 << 1)) + a0)));
}

/* Loader_DLL.xex 0x8320C448: get u8@0x0, u16@0x1 */
ts4_word ts4_get_u8_off0_8320C448(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(((a1 + (a1 << 1)) + a0)) + 0);
    return ((((signed char)t1) << 16) | (*(unsigned short *)((char *)(ts4_word)(((a1 + (a1 << 1)) + a0)) + 1)));
}

/* Loader_DLL.xex 0x8320C470: get u8@0x2, u16@0x0 */
ts4_word ts4_get_u8_off2_8320C470(ts4_word a0, ts4_word a1)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(((a1 + (a1 << 1)) + a0)) + 2);
    return ((int)((((signed char)t1) << 16) | (*(unsigned short *)((char *)(ts4_word)(((a1 + (a1 << 1)) + a0)) + 0))) >> 4);
}

/* Loader_DLL.xex 0x8320D710: if_tailcall fn_8321B8C8 */
ts4_word ts4_if_tailcall_fn_8321B8C8_8320D710(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return 258;
    }
    return fn_8321B8C8((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8320E1F8: if_get u32@0x38, u32@0x34 */
ts4_word ts4_if_get_u32_off38_8320E1F8(ts4_word a0)
{
    if ((ts4_word)a0 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)) == (int)((1281753088) | 21364)) {
        return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
    }
    return -1;
}

/* Loader_DLL.xex 0x8320F0C0: get u32@0x3c */
ts4_word ts4_get_u32_off3c_8320F0C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x83210068: get u32@0x3c */
ts4_word ts4_get_u32_off3c_83210068(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x832109F8: tailcall fn_832107B0 */
ts4_word ts4_tailcall_fn_832107B0_832109F8(ts4_word a0)
{
    return fn_832107B0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83210FA8: get u32@0x28 */
ts4_word ts4_get_u32_off28_83210FA8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 40));
}

/* Loader_DLL.xex 0x83211300: get u32@0x14 */
ts4_word ts4_get_u32_off14_83211300(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 20)) & 0x7fffffff) + -1);
}

/* Loader_DLL.xex 0x83211598: get u32@0x2c */
ts4_word ts4_get_u32_off2c_83211598(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 44));
}

/* Loader_DLL.xex 0x832133C0: tailcall fn_832118B8 */
ts4_word ts4_tailcall_fn_832118B8_832133C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    return fn_832118B8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)0, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5);
}

/* Loader_DLL.xex 0x83213870: get u32@0x3c */
ts4_word ts4_get_u32_off3c_83213870(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x83215C18: get u32@0x3c */
ts4_word ts4_get_u32_off3c_83215C18(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x83215F38: get u32@0x3c */
ts4_word ts4_get_u32_off3c_83215F38(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x83218480: get u32@0x3c */
ts4_word ts4_get_u32_off3c_83218480(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x83218560: get u32@lbl_8352A0A8, fn_8340D710 */
ts4_word ts4_get_u32_lbl_8352A0A8_83218560(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_8340D710((ts4_word)a1, (ts4_word)(*(ts4_word *)lbl_8352A0A8));
}

/* Loader_DLL.xex 0x83218570: get u32@lbl_8352A0A8, fn_8340D830 */
ts4_word ts4_get_u32_lbl_8352A0A8_83218570(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_8340D830((ts4_word)a1, (ts4_word)(*(ts4_word *)lbl_8352A0A8));
}

/* Loader_DLL.xex 0x83218580: get u32@lbl_8352A0A8, fn_8340D710 */
ts4_word ts4_get_u32_lbl_8352A0A8_83218580(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352A0A8));
}

/* Loader_DLL.xex 0x83218590: get u32@lbl_8352A0A8, fn_8340D830 */
ts4_word ts4_get_u32_lbl_8352A0A8_83218590(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)(*(ts4_word *)lbl_8352A0A8));
}

/* Loader_DLL.xex 0x83218710: if_get u32@0x40, u32@0x3c, u32@0x0 */
ts4_word ts4_if_get_u32_off40_83218710(ts4_word a0, ts4_word a1)
{
    if (((ts4_word)a0 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)) == (int)((1281753088) | 20853)) && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x83218A50: if_get u32@0x40, u32@0x0 */
ts4_word ts4_if_get_u32_off40_83218A50(ts4_word a0, ts4_word a1)
{
    if (((ts4_word)a0 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)) == (int)((1281753088) | 20853)) && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x83218DE0: if_get u32@0x40, u32@0x3c, u32@0x0 */
ts4_word ts4_if_get_u32_off40_83218DE0(ts4_word a0, ts4_word a1)
{
    if (((ts4_word)a0 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)) == (int)((1279655936) | 20561)) && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x832190F0: if_get u32@0x40, u32@0x0 */
ts4_word ts4_if_get_u32_off40_832190F0(ts4_word a0, ts4_word a1)
{
    if (((ts4_word)a0 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)) == (int)((1279655936) | 20561)) && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x83219248: tailcall fn_83219130 */
ts4_word ts4_tailcall_fn_83219130_83219248(ts4_word a0, ts4_word a1)
{
    return fn_83219130((ts4_word)a0, (ts4_word)0, (ts4_word)1, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83219258: tailcall fn_83219130 */
ts4_word ts4_tailcall_fn_83219130_83219258(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83219130((ts4_word)a0, (ts4_word)a1, (ts4_word)2, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83219448: if_get u32@0x40, u32@0x3c, u32@0x0 */
ts4_word ts4_if_get_u32_off40_83219448(ts4_word a0, ts4_word a1)
{
    if (((ts4_word)a0 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)) == (int)((1279655936) | 18516)) && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 60));
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x832196F8: if_call_seq fn_83218488 */
ts4_word ts4_if_call_seq_fn_83218488_832196F8(void)
{
    ts4_word p2;
    int t1;

    t1 = fn_83218488();
    p2 = (ts4_word)t1;
    if ((int)t1 > 0) {
        p2 = (ts4_word)((t1 & 0xffff) | 2147942400);
    }
    return p2;
}

/* Loader_DLL.xex 0x83219810: if_get u32@0x40, u32@0x1c, u32@0x0 */
ts4_word ts4_if_get_u32_off40_83219810(ts4_word a0, ts4_word a1)
{
    if (((ts4_word)a0 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 64)) == (int)((1279655936) | 18516)) && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 28));
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x83219968: tailcall fn_83219850 */
ts4_word ts4_tailcall_fn_83219850_83219968(ts4_word a0, ts4_word a1)
{
    return fn_83219850((ts4_word)a0, (ts4_word)0, (ts4_word)1, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83219978: tailcall fn_83219850 */
ts4_word ts4_tailcall_fn_83219850_83219978(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83219850((ts4_word)a0, (ts4_word)a1, (ts4_word)2, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83219CE0: if_get u32@0x38, u32@0x0 */
ts4_word ts4_if_get_u32_off38_83219CE0(ts4_word a0, ts4_word a1)
{
    if (((ts4_word)a0 != 0 && (int)(*(ts4_word *)((char *)(ts4_word)(a0) + 56)) == (int)((1281753088) | 21364)) && (ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)0;
        return 0;
    }
    return ((2147942400) | 87);
}

/* Loader_DLL.xex 0x8321A440: tailcall fn_83210E98 */
ts4_word ts4_tailcall_fn_83210E98_8321A440(ts4_word a0)
{
    return fn_83210E98((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321A8A8: set u32@0x0, u32@0x8, u32@0x4 */
void ts4_set_u32_off0_8321A8A8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(a0 + 12);
    return;
}

/* Loader_DLL.xex 0x8321A8C0: get u32@0x0 */
ts4_word ts4_get_u32_off0_8321A8C0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 0));
}

/* Loader_DLL.xex 0x8321A8F0: get u32@0x8 */
ts4_word ts4_get_u32_off8_8321A8F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8321B350: tailcall fn_8321AA60 */
ts4_word ts4_tailcall_fn_8321AA60_8321B350(ts4_word a0)
{
    return fn_8321AA60((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321B6D8: tailcall fn_833E25A8 */
ts4_word ts4_tailcall_fn_833E25A8_8321B6D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_833E25A8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8321B6E0: tailcall fn_833E71B8 */
ts4_word ts4_tailcall_fn_833E71B8_8321B6E0(ts4_word a0, ts4_word a1)
{
    return fn_833E71B8((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8321B6E8: fn  */
ts4_word ts4_fn_8321B6E8(void)
{
    return -2;
}

/* Loader_DLL.xex 0x8321B6F0: tailcall fn_8340CEF0 */
ts4_word ts4_tailcall_fn_8340CEF0_8321B6F0(void)
{
    return fn_8340CEF0((ts4_word)0, (ts4_word)1, (ts4_word)0, (ts4_word)0);
}

/* Loader_DLL.xex 0x8321B708: tailcall fn_8340A360 */
ts4_word ts4_tailcall_fn_8340A360_8321B708(ts4_word a0)
{
    return fn_8340A360((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321B710: tailcall fn_8340AED8 */
ts4_word ts4_tailcall_fn_8340AED8_8321B710(ts4_word a0)
{
    return fn_8340AED8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321B718: tailcall fn_8340D380 */
ts4_word ts4_tailcall_fn_8340D380_8321B718(void)
{
    return fn_8340D380((ts4_word)0, (ts4_word)0, (ts4_word)((2147418112) | 65535), (ts4_word)0);
}

/* Loader_DLL.xex 0x8321B730: tailcall fn_8340A360 */
ts4_word ts4_tailcall_fn_8340A360_8321B730(ts4_word a0)
{
    return fn_8340A360((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321B738: call_seq u32@0x0, fn_8340D540 */
ts4_word ts4_call_seq_u32_off0_8321B738(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word loc50[2];
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    loc50[0] = (ts4_word)a1;
    loc50[1] = (ts4_word)t1;
    t2 = fn_8340D540((ts4_word)2, (ts4_word)(ts4_word)&loc50[0], (ts4_word)0, (ts4_word)a2, (ts4_word)a3);
    return t2;
}

/* Loader_DLL.xex 0x8321B918: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x0 */
void ts4_set_u32_off0_8321B918(ts4_word a0, ts4_word a1)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)20;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x8321BB48: tailcall fn_8321D5E8 */
ts4_word ts4_tailcall_fn_8321D5E8_8321BB48(ts4_word a0)
{
    return fn_8321D5E8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321BB50: tailcall fn_8321D608 */
ts4_word ts4_tailcall_fn_8321D608_8321BB50(ts4_word a0)
{
    return fn_8321D608((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321BB58: tailcall fn_8321DB70 */
ts4_word ts4_tailcall_fn_8321DB70_8321BB58(ts4_word a0)
{
    return fn_8321DB70((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321BB60: tailcall fn_8321DCD0 */
ts4_word ts4_tailcall_fn_8321DCD0_8321BB60(ts4_word a0)
{
    return fn_8321DCD0((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321BB68: tailcall fn_8321DCE0 */
ts4_word ts4_tailcall_fn_8321DCE0_8321BB68(ts4_word a0)
{
    return fn_8321DCE0((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321BB70: tailcall fn_8321DD88 */
ts4_word ts4_tailcall_fn_8321DD88_8321BB70(ts4_word a0)
{
    return fn_8321DD88((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321BB78: tailcall fn_83120518 */
ts4_word ts4_tailcall_fn_83120518_8321BB78(ts4_word a0)
{
    return fn_83120518((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321BB80: tailcall fn_83120540 */
ts4_word ts4_tailcall_fn_83120540_8321BB80(ts4_word a0)
{
    return fn_83120540((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321BB88: addr lbl_83085988 */
ts4_word ts4_addr_lbl_83085988_8321BB88(void)
{
    return (ts4_word)lbl_83085988;
}

/* Loader_DLL.xex 0x8321BB98: addr lbl_83000AE8 */
ts4_word ts4_addr_lbl_83000AE8_8321BB98(void)
{
    return (ts4_word)lbl_83000AE8;
}

/* Loader_DLL.xex 0x8321C718: fn  */
void ts4_fn_8321C718(void)
{
    return;
}

/* Loader_DLL.xex 0x8321C720: addr lbl_83085988, fn_8310D380 */
ts4_word ts4_addr_lbl_83085988_8321C720(void)
{
    return fn_8310D380((ts4_word)(ts4_word)lbl_83085988);
}

/* Loader_DLL.xex 0x8321C730: fn  */
ts4_word ts4_fn_8321C730(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8321C738: fn  */
ts4_word ts4_fn_8321C738(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8321C740: call_seq fn_8321BC08, u32@0x4, fn_83120540, u32@0x4 */
ts4_word ts4_call_seq_fn_8321BC08_8321C740(ts4_word a0)
{
    ts4_word t3;

    fn_8321BC08();
    t3 = fn_83120540((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return t3;
}

/* Loader_DLL.xex 0x8321C908: if_get u32@0x0, u32@0x4, fn_8321C3C8 */
ts4_word ts4_if_get_u32_off0_8321C908(ts4_word a0, ts4_word a1, ts4_word a2)
{
    int t1;

    (void)a0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a2) + 0);
    if ((int)t1 != 1) {
        return ((2147942400) | 87);
    }
    return fn_8321C3C8((ts4_word)a1, (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 4)));
}

/* Loader_DLL.xex 0x8321CB30: addr lbl_83085988, fn_8310D380 */
ts4_word ts4_addr_lbl_83085988_8321CB30(void)
{
    return fn_8310D380((ts4_word)(ts4_word)lbl_83085988);
}

/* Loader_DLL.xex 0x8321D500: if_call_seq fn_8321CB40 */
ts4_word ts4_if_call_seq_fn_8321CB40_8321D500(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    if ((ts4_word)a0 != 0) {
        fn_8321CB40((ts4_word)a0, (ts4_word)1);
    }
    return 0;
}

/* Loader_DLL.xex 0x8321D530: tailcall fn_8321CE60 */
ts4_word ts4_tailcall_fn_8321CE60_8321D530(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    return fn_8321CE60((ts4_word)a2);
}

/* Loader_DLL.xex 0x8321D5E0: tailcall fn_8321D538 */
ts4_word ts4_tailcall_fn_8321D538_8321D5E0(ts4_word a0)
{
    return fn_8321D538((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321D5F8: get u32@0x0, u32@0x8 */
ts4_word ts4_get_u32_off0_8321D5F8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321D618: get u32@0x0, u32@0x50 */
ts4_word ts4_get_u32_off0_8321D618(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 80))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321DCC0: get u32@0x0, u32@0x54 */
ts4_word ts4_get_u32_off0_8321DCC0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 84))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321DCF0: get u32@0x0, u32@0x60 */
ts4_word ts4_get_u32_off0_8321DCF0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 96))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321DD00: get u32@0x0, u32@0x68 */
ts4_word ts4_get_u32_off0_8321DD00(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 104))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321DD10: get u32@0x0, u32@0x6c */
ts4_word ts4_get_u32_off0_8321DD10(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 108))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321DD98: get u32@0x0, u32@0x38 */
ts4_word ts4_get_u32_off0_8321DD98(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 56))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x8321EA90: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8321EA90(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32809));
}

/* Loader_DLL.xex 0x8321EAA0: tailcall fn_8340D710 */
ts4_word ts4_tailcall_fn_8340D710_8321EAA0(ts4_word a0)
{
    return fn_8340D710((ts4_word)a0, (ts4_word)((546045952) | 32809));
}

/* Loader_DLL.xex 0x8321EAB0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8321EAB0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32809));
}

/* Loader_DLL.xex 0x8321EAC0: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_8321EAC0(ts4_word a0)
{
    return fn_8340D830((ts4_word)a0, (ts4_word)((546045952) | 32809));
}
