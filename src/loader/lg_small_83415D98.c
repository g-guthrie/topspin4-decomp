/* Loader_DLL.xex 0x83415D98-0x835165E8, executable version 0.0.0.3.
   Small accessors, thunks and call sequences (generated, byte-verified). a0 = this/first argument; fields by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char fn_8344CDF8[];
extern char fn_83516530[];
extern char fn_83516798[];
extern char fn_83516850[];
extern char fn_83516860[];
extern char fn_83516870[];
extern char fn_83516880[];
extern char fn_83516890[];
extern char fn_835168D0[];
extern char fn_83516910[];
extern char fn_83516938[];
extern char lbl_83005EE0[];
extern char lbl_83075870[];
extern char lbl_83075BE4[];
extern char lbl_8307A458[];
extern char lbl_830858D4[];
extern char lbl_83085968[];
extern char lbl_83085DB8[];
extern char lbl_83085DDC[];
extern char lbl_83085DFC[];
extern char lbl_83085E64[];
extern char lbl_83085E80[];
extern char lbl_83085EB8[];
extern char lbl_83085EF0[];
extern char lbl_83085F20[];
extern char lbl_8352D368[];
extern char lbl_8352DB60[];
extern char lbl_8352F750[];
extern char lbl_8352FE2C[];
extern char lbl_8352FE44[];
extern char lbl_8352FE5C[];
extern char lbl_8352FE74[];
extern char lbl_8352FE8C[];
extern char lbl_8352FEA4[];
extern char lbl_8352FEBC[];
extern char lbl_83542D90[];
extern char lbl_83544784[];
extern char lbl_83544EB8[];
extern char lbl_83544EBC[];
extern char lbl_83544EC0[];
extern char lbl_83544ECC[];
ts4_word fn_830A23D8();
ts4_word fn_830A3208();
ts4_word fn_830AAC58();
ts4_word fn_830AACF0();
ts4_word fn_830E30E8();
ts4_word fn_830E3178();
ts4_word fn_83109390();
ts4_word fn_83112B88();
ts4_word fn_831137A0();
ts4_word fn_83113EF8();
ts4_word fn_83113F88();
ts4_word fn_8311F9F8();
ts4_word fn_83140C58();
ts4_word fn_833C6758();
ts4_word fn_833E1758();
ts4_word fn_833E3A30();
ts4_word fn_833E3AD0();
ts4_word fn_833E4920();
ts4_word fn_833E79E0();
ts4_word fn_833FAF30();
ts4_word fn_8340CE50();
ts4_word fn_8340CE98();
ts4_word fn_8340D0D8();
ts4_word fn_8340D830();
ts4_word fn_83410100();
ts4_word fn_83410108();
ts4_word fn_83416210();
ts4_word fn_83417F78();
ts4_word fn_8343FD80();
ts4_word fn_8344BC08();
ts4_word fn_8344BD78();
ts4_word fn_8344C3C0();
ts4_word fn_8344C440();
ts4_word fn_8344E298();
ts4_word fn_8344E300();
ts4_word fn_8344EF30();
ts4_word fn_8344EFB0();
ts4_word fn_83453A60();
ts4_word fn_83453DF8();
ts4_word fn_83456D18();
ts4_word fn_8345A5B8();
ts4_word fn_8345A6A0();
ts4_word fn_8345BD20();
ts4_word fn_8345E408();
ts4_word fn_834615D8();
ts4_word fn_8346AFB8();
ts4_word fn_8346B268();
ts4_word fn_8346BA70();
ts4_word fn_8346C190();
ts4_word fn_8346C328();
ts4_word fn_8346DB30();
ts4_word fn_8346DCC8();
ts4_word fn_8346DF78();
ts4_word fn_83470750();
ts4_word fn_834710E0();
ts4_word fn_83476CB0();
ts4_word fn_834773C8();
ts4_word fn_83485658();
ts4_word fn_83488638();
ts4_word fn_83488780();
ts4_word fn_83488BA0();
ts4_word fn_834897E0();
ts4_word fn_83489908();
ts4_word fn_8348BAD8();
ts4_word fn_8348CDB8();
ts4_word fn_8348CEE0();
ts4_word fn_8348E7D8();
ts4_word fn_8348E990();
ts4_word fn_83492080();
ts4_word fn_83492878();
ts4_word fn_834970A8();
ts4_word fn_83499640();
ts4_word fn_8349A030();
ts4_word fn_834D3358();
ts4_word fn_83514B48();
ts4_word fn_83515340();

/* Loader_DLL.xex 0x83415D98: tailcall fn_83410100 */
ts4_word ts4_tailcall_fn_83410100_83415D98(ts4_word a0, ts4_word a1)
{
    return fn_83410100((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83415DA0: tailcall fn_83410108 */
ts4_word ts4_tailcall_fn_83410108_83415DA0(ts4_word a0)
{
    return fn_83410108((ts4_word)a0);
}

/* Loader_DLL.xex 0x83415ED8: get u16@0x0, u32@0x4, fn_83416210 */
ts4_word ts4_get_u16_off0_83415ED8(ts4_word a0)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(ts4_word)(a0) + 0);
    return fn_83416210((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)t1);
}

/* Loader_DLL.xex 0x8341C0D8: tailcall fn_83417F78 */
ts4_word ts4_tailcall_fn_83417F78_8341C0D8(ts4_word a0, ts4_word a1)
{
    return fn_83417F78((ts4_word)a0, (ts4_word)0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8341C0E8: tailcall fn_83417F78 */
ts4_word ts4_tailcall_fn_83417F78_8341C0E8(ts4_word a0, ts4_word a1)
{
    return fn_83417F78((ts4_word)a0, (ts4_word)0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83443170: get u32@0x1bc, u32@0xdc, u32@0x94, u32@0x1a4, u32@0xc, u32@0x10 */
void ts4_get_u32_off1bc_83443170(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 444);
    *(ts4_word *)((char *)(ts4_word)(a0) + 220) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 148) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 420) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 16) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 164) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x834434D0: get u32@0x0, u32@0xc, vcall */
ts4_word ts4_get_u32_off0_834434D0(ts4_word a0)
{
    ts4_word loc50[50];
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 12))))((ts4_word)a0, (ts4_word)(ts4_word)&loc50[0]);
    return t3;
}

/* Loader_DLL.xex 0x834436B0: get u32@0x0, u32@0x6c, u32@0x0, u32@0x14 */
void ts4_get_u32_off0_834436B0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 108) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83443850: tailcall fn_8344E300 */
ts4_word ts4_tailcall_fn_8344E300_83443850(ts4_word a0)
{
    return fn_8344E300((ts4_word)a0);
}

/* Loader_DLL.xex 0x83443858: tailcall fn_8344E298 */
ts4_word ts4_tailcall_fn_8344E298_83443858(ts4_word a0)
{
    return fn_8344E298((ts4_word)a0);
}

/* Loader_DLL.xex 0x83443BD8: get u32@0x164, u32@0x18 */
ts4_word ts4_get_u32_off164_83443BD8(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 356))) + 24))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83444850: set u32@0x4, u32@0x14, u32@0x0, u32@0x18, u32@0x1c, u32@0x20 */
ts4_word ts4_set_u32_off4_83444850(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)a4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a5;
    return (a0 + 36);
}

/* Loader_DLL.xex 0x83445D10: set u32@0x670 */
void ts4_set_u32_off670_83445D10(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1648) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x83445FC0: if_get u32@0x54c, lbl_83075870, fn_8343FD80 */
ts4_word ts4_if_get_u32_off54c_83445FC0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1356);
    if ((ts4_word)t1 != 0) {
        return ((ts4_word (*)(ts4_word))(t1))((ts4_word)a0);
    }
    return fn_8343FD80((ts4_word)a0, (ts4_word)(ts4_word)lbl_83075870);
}

/* Loader_DLL.xex 0x83445FE0: if_get u32@0x620 */
ts4_word ts4_if_get_u32_off620_83445FE0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1568);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return ((ts4_word (*)(ts4_word))(t1))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83446290: if_set u8@0x698 */
void ts4_if_set_u8_off698_83446290(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned char *)((char *)(ts4_word)(a0) + 1688) = (unsigned char)a1;
    return;
}

/* Loader_DLL.xex 0x83447220: set u32@0x66c */
void ts4_set_u32_off66c_83447220(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 1644) = (ts4_word)a1;
    return;
}

/* Loader_DLL.xex 0x834472D0: if_get u32@0x8 */
ts4_word ts4_if_get_u32_off8_834472D0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        return ((*(ts4_word *)((char *)(ts4_word)(a1) + 8)) & a2);
    }
    return 0;
}

/* Loader_DLL.xex 0x834472F8: if_get u32@0xc */
ts4_word ts4_if_get_u32_offc_834472F8(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(a1) + 12));
    }
    return 0;
}

/* Loader_DLL.xex 0x83447318: if_get u8@0x1d */
ts4_word ts4_if_get_u8_off1d_83447318(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a0 != 0 && (ts4_word)a1 != 0) {
        return (*(unsigned char *)((char *)(ts4_word)(a1) + 29));
    }
    return 0;
}

/* Loader_DLL.xex 0x83449D78: if_get u32@0x550, lbl_83075BE4, fn_8343FD80 */
ts4_word ts4_if_get_u32_off550_83449D78(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1360);
    if ((ts4_word)t1 != 0) {
        return ((ts4_word (*)(ts4_word))(t1))((ts4_word)a0);
    }
    return fn_8343FD80((ts4_word)a0, (ts4_word)(ts4_word)lbl_83075BE4);
}

/* Loader_DLL.xex 0x8344A268: fn  */
void ts4_fn_8344A268(void)
{
    return;
}

/* Loader_DLL.xex 0x8344A280: fn  */
void ts4_fn_8344A280(void)
{
    return;
}

/* Loader_DLL.xex 0x8344C580: if_get u32@lbl_8352D368, fn_8344BC08, fn_8344C3C0 */
ts4_word ts4_if_get_u32_lbl_8352D368_8344C580(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)lbl_8352D368;
    if ((int)t1 != 0) {
        return fn_8344C3C0((ts4_word)a0, (ts4_word)a1);
    }
    return fn_8344BC08((ts4_word)a0);
}

/* Loader_DLL.xex 0x8344C598: if_get u32@lbl_8352D368, fn_8344BD78, fn_8344C440 */
ts4_word ts4_if_get_u32_lbl_8352D368_8344C598(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)lbl_8352D368;
    if ((int)t1 != 0) {
        return fn_8344C440((ts4_word)a0, (ts4_word)a1);
    }
    return fn_8344BD78((ts4_word)a0);
}

/* Loader_DLL.xex 0x8344C6D8: tailcall fn_833E3AD0 */
ts4_word ts4_tailcall_fn_833E3AD0_8344C6D8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a0;
    return fn_833E3AD0((ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8344C6E8: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_8344C6E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a0;
    return fn_833E3A30((ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8344C6F8: addr lbl_8307A458 */
ts4_word ts4_addr_lbl_8307A458_8344C6F8(void)
{
    return (ts4_word)lbl_8307A458;
}

/* Loader_DLL.xex 0x8344CFA8: get u32@0x1b8, fn_8344CDF8, u32@0x0 */
void ts4_get_u32_off1b8_8344CFA8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 440))) + 0) = (ts4_word)(ts4_word)fn_8344CDF8;
    return;
}

/* Loader_DLL.xex 0x8344D048: get u32@0x0, u32@0x14, u32@0x0, u32@0x18, u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_8344D048(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 20) = (ts4_word)54;
    *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 24) = (ts4_word)a1;
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8344E350: get u32@0x4, u32@0x0, vcall, u32@0x80 */
ts4_word ts4_get_u32_off4_8344E350(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))))((ts4_word)a0, (ts4_word)0, (ts4_word)132);
    *(ts4_word *)((char *)(ts4_word)(t3) + 128) = (ts4_word)0;
    return t3;
}

/* Loader_DLL.xex 0x8344E390: get u32@0x4, u32@0x0, vcall, u32@0x114 */
ts4_word ts4_get_u32_off4_8344E390(ts4_word a0)
{
    ts4_word t3;

    t3 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 0))))((ts4_word)a0, (ts4_word)0, (ts4_word)280);
    *(ts4_word *)((char *)(ts4_word)(t3) + 276) = (ts4_word)0;
    return t3;
}

/* Loader_DLL.xex 0x8344EF88: tailcall fn_833E3AD0 */
ts4_word ts4_tailcall_fn_833E3AD0_8344EF88(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_833E3AD0((ts4_word)a1, (ts4_word)a0, (ts4_word)(a2 << 7));
}

/* Loader_DLL.xex 0x8344EFA0: tailcall fn_833E3A30 */
ts4_word ts4_tailcall_fn_833E3A30_8344EFA0(ts4_word a0, ts4_word a1)
{
    return fn_833E3A30((ts4_word)a0, (ts4_word)0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8344F778: fn  */
void ts4_fn_8344F778(void)
{
    return;
}

/* Loader_DLL.xex 0x8344FFB8: tailcall fn_8344EFB0 */
ts4_word ts4_tailcall_fn_8344EFB0_8344FFB8(ts4_word a0, ts4_word a1)
{
    return fn_8344EFB0((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x834502A0: call_seq fn_8344EFB0, fn_8344EFB0 */
ts4_word ts4_call_seq_fn_8344EFB0_834502A0(ts4_word a0)
{
    ts4_word t2;

    fn_8344EFB0((ts4_word)a0, (ts4_word)255);
    t2 = fn_8344EFB0((ts4_word)a0, (ts4_word)217);
    return t2;
}

/* Loader_DLL.xex 0x83451EF0: fn  */
void ts4_fn_83451EF0(void)
{
    return;
}

/* Loader_DLL.xex 0x83453CD8: tailcall fn_83453A60 */
ts4_word ts4_tailcall_fn_83453A60_83453CD8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_83453A60((ts4_word)a0, (ts4_word)a1, (ts4_word)8, (ts4_word)15, (ts4_word)8, (ts4_word)0, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x83453F50: tailcall fn_83453DF8 */
ts4_word ts4_tailcall_fn_83453DF8_83453F50(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83453DF8((ts4_word)a0, (ts4_word)15, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x83456258: if_get u8@-0x1, fn_8340D830 */
ts4_word ts4_if_get_u8_0x1_83456258(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_8340D830((ts4_word)(a1 - (*(unsigned char *)((char *)(ts4_word)(a1) + -1))), (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x834562D0: if_get u8@-0x1, fn_8340D830 */
ts4_word ts4_if_get_u8_0x1_834562D0(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 == 0) {
        return a0;
    }
    return fn_8340D830((ts4_word)(a1 - (*(unsigned char *)((char *)(ts4_word)(a1) + -1))), (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x834562F0: get u32@0x4, u32@0x2c */
ts4_word ts4_get_u32_off4_834562F0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a1;
    (void)a2;
    return ((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4))) + 44)) - a3);
}

/* Loader_DLL.xex 0x83456430: get u32@0xc, fn_833E79E0 */
ts4_word ts4_get_u32_offc_83456430(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_833E79E0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 12)));
}

/* Loader_DLL.xex 0x834564D8: fn  */
ts4_word ts4_fn_834564D8(void)
{
    return ((983040) | 16960);
}

/* Loader_DLL.xex 0x834564E8: fn  */
void ts4_fn_834564E8(void)
{
    return;
}

/* Loader_DLL.xex 0x83456D88: set u32@0x98, fn_83456D18 */
ts4_word ts4_set_u32_off98_83456D88(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 152) = (ts4_word)0;
    return fn_83456D18((ts4_word)a0);
}

/* Loader_DLL.xex 0x83457038: fn  */
ts4_word ts4_fn_83457038(void)
{
    return 0;
}

/* Loader_DLL.xex 0x8345A270: get u32@0x1c8, u32@0x13c, u32@0x5c, u32@0x74, u32@0x60 */
void ts4_get_u32_off1c8_8345A270(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 456);
    *(ts4_word *)((char *)(ts4_word)(t1) + 92) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 316));
    *(ts4_word *)((char *)(ts4_word)(t1) + 96) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 116));
    return;
}

/* Loader_DLL.xex 0x8345A3C0: set u32@0x0 */
void ts4_set_u32_off0_8345A3C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)a2;
    return;
}

/* Loader_DLL.xex 0x8345A3C8: set u32@0x0 */
void ts4_set_u32_off0_8345A3C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a0;
    (void)a1;
    (void)a2;
    *(ts4_word *)((char *)(ts4_word)(a3) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8345A808: tailcall fn_8345A5B8 */
ts4_word ts4_tailcall_fn_8345A5B8_8345A808(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8345A5B8((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8345A810: tailcall fn_8345A6A0 */
ts4_word ts4_tailcall_fn_8345A6A0_8345A810(ts4_word a0)
{
    return fn_8345A6A0((ts4_word)a0);
}

/* Loader_DLL.xex 0x8345AD78: get u32@0x70, u32@0x0, fn_8344EF30 */
ts4_word ts4_get_u32_off70_8345AD78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 112);
    return fn_8344EF30((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 0)), (ts4_word)a2, (ts4_word)a3, (ts4_word)0, (ts4_word)a4, (ts4_word)t1);
}

/* Loader_DLL.xex 0x8345BA48: get u32@0x1c8, u32@0x24, u32@0x74, u32@0x2c */
void ts4_get_u32_off1c8_8345BA48(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 456);
    *(ts4_word *)((char *)(ts4_word)(t1) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(t1) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 116));
    return;
}

/* Loader_DLL.xex 0x8345BEF8: tailcall fn_8345BD20 */
ts4_word ts4_tailcall_fn_8345BD20_8345BEF8(ts4_word a0)
{
    return fn_8345BD20((ts4_word)a0);
}

/* Loader_DLL.xex 0x8345E568: call_seq fn_8345E408, u32@0x18, u32@0x1c */
ts4_word ts4_call_seq_fn_8345E408_8345E568(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8345E408((ts4_word)a0, (ts4_word)127, (ts4_word)7);
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    return t1;
}

/* Loader_DLL.xex 0x83461200: fn  */
void ts4_fn_83461200(void)
{
    return;
}

/* Loader_DLL.xex 0x83461BE0: tailcall fn_834615D8 */
ts4_word ts4_tailcall_fn_834615D8_83461BE0(ts4_word a0)
{
    return fn_834615D8((ts4_word)a0);
}

/* Loader_DLL.xex 0x834624B0: fn  */
void ts4_fn_834624B0(void)
{
    return;
}

/* Loader_DLL.xex 0x83463970: fn  */
void ts4_fn_83463970(void)
{
    return;
}

/* Loader_DLL.xex 0x83465A80: addr lbl_83005EE0 */
ts4_word ts4_addr_lbl_83005EE0_83465A80(void)
{
    return (ts4_word)lbl_83005EE0;
}

/* Loader_DLL.xex 0x83465B10: tailcall fn_8340D830 */
ts4_word ts4_tailcall_fn_8340D830_83465B10(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return fn_8340D830((ts4_word)a1, (ts4_word)(612433920));
}

/* Loader_DLL.xex 0x83467CA0: get u32@0x50, u16@0x0, u32@0x148, u32@0x0, u16@0x0, u8@0x80 */
ts4_word ts4_get_u32_off50_83467CA0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    ts4_word t1;
    unsigned short t2;
    ts4_word t3;
    ts4_word t4;
    unsigned short t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 80);
    t2 = *(unsigned short *)((char *)(ts4_word)(a2) + 0);
    t3 = *(ts4_word *)((char *)(ts4_word)(a0) + 328);
    t4 = *(ts4_word *)((char *)(ts4_word)(a3) + 0);
    t5 = *(unsigned short *)((char *)(ts4_word)(t1) + 0);
    *(unsigned char *)((char *)(ts4_word)(t4) + a4) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(((((int)(((int)((short)t5) * (int)((short)t2)) + 4) >> 3) & 0x3ff) + t3)) + 128));
    return (((int)((short)t5) * (int)((short)t2)) + 4);
}

/* Loader_DLL.xex 0x83469780: get u32@0x24, u32@0x28 */
ts4_word ts4_get_u32_off24_83469780(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a1) + 36);
    return ((ts4_word (*)(ts4_word, ts4_word))(t1))((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 40)), (ts4_word)a0);
}

/* Loader_DLL.xex 0x8346A4A0: fn  */
ts4_word ts4_fn_8346A4A0(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8346A4B0: fn  */
ts4_word ts4_fn_8346A4B0(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8346A4C0: fn  */
void ts4_fn_8346A4C0(void)
{
    return;
}

/* Loader_DLL.xex 0x8346A4C8: fn  */
ts4_word ts4_fn_8346A4C8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8346A4D8: fn  */
ts4_word ts4_fn_8346A4D8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8346A4E8: fn  */
ts4_word ts4_fn_8346A4E8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x8346A4F8: fn  */
void ts4_fn_8346A4F8(void)
{
    return;
}

/* Loader_DLL.xex 0x8346A500: fn  */
void ts4_fn_8346A500(void)
{
    return;
}

/* Loader_DLL.xex 0x8346B248: tailcall fn_8346AFB8 */
ts4_word ts4_tailcall_fn_8346AFB8_8346B248(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8346AFB8((ts4_word)a0, (ts4_word)-1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8346B378: tailcall fn_8346B268 */
ts4_word ts4_tailcall_fn_8346B268_8346B378(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8346B268((ts4_word)a0, (ts4_word)-1, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
}

/* Loader_DLL.xex 0x8346B768: get u32@lbl_8352DB60, u32@lbl_8352DB60 */
void ts4_get_u32_lbl_8352DB60_8346B768(void)
{
    *(ts4_word *)lbl_8352DB60 = (ts4_word)((*(ts4_word *)lbl_8352DB60) + 1);
    return;
}

/* Loader_DLL.xex 0x8346BDB0: tailcall fn_8346BA70 */
ts4_word ts4_tailcall_fn_8346BA70_8346BDB0(ts4_word a0)
{
    return fn_8346BA70((ts4_word)a0, (ts4_word)16);
}

/* Loader_DLL.xex 0x8346C2E0: if_tail fn_8346C190, fn_8346C190 */
ts4_word ts4_if_tail_fn_8346C190_8346C2E0(int a0, ts4_word a1, ts4_word a2, int a3)
{
    if ((int)a3 == 10 && (int)a0 < 0) {
        return fn_8346C190((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)1);
    }
    return fn_8346C190((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x8346C320: tailcall fn_8346C190 */
ts4_word ts4_tailcall_fn_8346C190_8346C320(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8346C190((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x8346C4A0: tailcall fn_8346C328 */
ts4_word ts4_tailcall_fn_8346C328_8346C4A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    return fn_8346C328((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3, (ts4_word)0);
}

/* Loader_DLL.xex 0x8346C4A8: tailcall fn_833FAF30 */
ts4_word ts4_tailcall_fn_833FAF30_8346C4A8(ts4_word a0, ts4_word a1)
{
    return fn_833FAF30((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8346C4B0: tailcall fn_833FAF30 */
ts4_word ts4_tailcall_fn_833FAF30_8346C4B0(ts4_word a0, ts4_word a1)
{
    return fn_833FAF30((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8346C7C0: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
ts4_word ts4_set_u32_off0_8346C7C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a4;
    return 1;
}

/* Loader_DLL.xex 0x8346C940: set u32@0x0, u32@0x4, u32@0x8, u32@0xc */
ts4_word ts4_set_u32_off0_8346C940(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    return 1;
}

/* Loader_DLL.xex 0x8346D1D8: loop_get u8@0x0, u16@0x0, u16@0x8 */
void ts4_loop_get_u8_off0_8346D1D8(ts4_word a0, ts4_word a1)
{
    ts4_word c1;
    ts4_word lv2;
    ts4_word lv3;
    ts4_word p5;
    ts4_word p6;

    c1 = (ts4_word)4;
    lv2 = (ts4_word)(a1 + -2);
    lv3 = (ts4_word)(a0 + -1);
    do {
        *(unsigned short *)((char *)(ts4_word)((lv2 + 2)) + 0) = (unsigned short)(*(unsigned char *)((char *)(ts4_word)((lv3 + 1)) + 0));
        p5 = (ts4_word)(lv2 + 2);
        p6 = (ts4_word)(lv3 + 1);
        lv2 = p5;
        lv3 = p6;
    } while (--c1 != 0);
    *(unsigned short *)((char *)(ts4_word)(a1) + 8) = (unsigned short)0;
    return;
}

/* Loader_DLL.xex 0x8346E2B8: tailcall fn_8346DB30 */
ts4_word ts4_tailcall_fn_8346DB30_8346E2B8(ts4_word a0, ts4_word a1)
{
    return fn_8346DB30((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8346E3A0: tailcall fn_8346DF78 */
ts4_word ts4_tailcall_fn_8346DF78_8346E3A0(ts4_word a0)
{
    return fn_8346DF78((ts4_word)a0);
}

/* Loader_DLL.xex 0x8346E3A8: tailcall fn_8346DCC8 */
ts4_word ts4_tailcall_fn_8346DCC8_8346E3A8(ts4_word a0, ts4_word a1)
{
    return fn_8346DCC8((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x83470948: tailcall fn_83470750 */
ts4_word ts4_tailcall_fn_83470750_83470948(ts4_word a0)
{
    return fn_83470750((ts4_word)a0);
}

/* Loader_DLL.xex 0x83471268: if_tail fn_834710E0, fn_834710E0 */
ts4_word ts4_if_tail_fn_834710E0_83471268(ts4_word a0, ts4_word a1, int a2, ts4_word a3)
{
    if ((int)a2 == 1) {
        return fn_834710E0((ts4_word)a0, (ts4_word)a1, (ts4_word)((131072) | 1), (ts4_word)2, (ts4_word)a3);
    }
    return fn_834710E0((ts4_word)a0, (ts4_word)a1, (ts4_word)((262144) | 1), (ts4_word)4, (ts4_word)a3);
}

/* Loader_DLL.xex 0x834715B8: tailcall fn_834710E0 */
ts4_word ts4_tailcall_fn_834710E0_834715B8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_834710E0((ts4_word)a0, (ts4_word)a1, (ts4_word)((262144) | 1), (ts4_word)4, (ts4_word)((a2) >> 2));
}

/* Loader_DLL.xex 0x83472D08: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_83472D08(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83472D80: set u32@0x0, u32@0x4, u32@0x8 */
void ts4_set_u32_off0_83472D80(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83472D98: get u32@0x0, fn_833E1758 */
ts4_word ts4_get_u32_off0_83472D98(ts4_word a0)
{
    return fn_833E1758((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 0)));
}

/* Loader_DLL.xex 0x83472F58: fn  */
ts4_word ts4_fn_83472F58(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x834739F8: fn  */
ts4_word ts4_fn_834739F8(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83473A08: fn  */
ts4_word ts4_fn_83473A08(void)
{
    return ((2147483648) | 16385);
}

/* Loader_DLL.xex 0x83473C08: fn  */
void ts4_fn_83473C08(void)
{
    return;
}

/* Loader_DLL.xex 0x83473C10: set  */
void ts4_set_83473C10(ts4_word a0, float f1, float f2, float f3, float f4)
{
    *(float *)((char *)(ts4_word)(a0) + 0) = f1;
    *(float *)((char *)(ts4_word)(a0) + 4) = f2;
    *(float *)((char *)(ts4_word)(a0) + 8) = f3;
    *(float *)((char *)(ts4_word)(a0) + 12) = f4;
    return;
}

/* Loader_DLL.xex 0x83473CA8: fn  */
void ts4_fn_83473CA8(void)
{
    return;
}

/* Loader_DLL.xex 0x83473CC0: fn  */
void ts4_fn_83473CC0(void)
{
    return;
}

/* Loader_DLL.xex 0x83476D00: fn  */
void ts4_fn_83476D00(void)
{
    return;
}

/* Loader_DLL.xex 0x83476D08: fn  */
void ts4_fn_83476D08(void)
{
    return;
}

/* Loader_DLL.xex 0x834773C0: fn  */
void ts4_fn_834773C0(void)
{
    return;
}

/* Loader_DLL.xex 0x834775C0: call_seq fn_830E3178 */
ts4_word ts4_call_seq_fn_830E3178_834775C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_830E3178((ts4_word)a0, (ts4_word)2, (ts4_word)a1, (ts4_word)4, (ts4_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x83477600: call_seq fn_830E30E8 */
ts4_word ts4_call_seq_fn_830E30E8_83477600(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_830E30E8((ts4_word)a0, (ts4_word)4, (ts4_word)a1, (ts4_word)2, (ts4_word)a2);
    return a0;
}

/* Loader_DLL.xex 0x83477650: fn  */
void ts4_fn_83477650(void)
{
    return;
}

/* Loader_DLL.xex 0x83477668: fn  */
void ts4_fn_83477668(void)
{
    return;
}

/* Loader_DLL.xex 0x83484048: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484048(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x834840E8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_834840E8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484188: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484188(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484228: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484228(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x834842C8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_834842C8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484368: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484368(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484408: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484408(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x834844A8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_834844A8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484548: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484548(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x834845E8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_834845E8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484688: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484688(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484728: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484728(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x834847C8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_834847C8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484868: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484868(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484908: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484908(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x834849A8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_834849A8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484A48: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484A48(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484AE8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484AE8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484B88: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484B88(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484C28: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484C28(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484CC8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484CC8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484D68: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484D68(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484E08: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484E08(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484EA8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484EA8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484F48: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484F48(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83484FE8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83484FE8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83485088: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83485088(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83485128: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83485128(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x834851C8: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_834851C8(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83485268: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83485268(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x83485308: tailcall fn_83476CB0 */
ts4_word ts4_tailcall_fn_83476CB0_83485308(ts4_word a0)
{
    return fn_83476CB0((ts4_word)a0);
}

/* Loader_DLL.xex 0x834853A0: tailcall fn_834773C8 */
ts4_word ts4_tailcall_fn_834773C8_834853A0(ts4_word a0)
{
    return fn_834773C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83485438: tailcall fn_834773C8 */
ts4_word ts4_tailcall_fn_834773C8_83485438(ts4_word a0)
{
    return fn_834773C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x834854D0: tailcall fn_834773C8 */
ts4_word ts4_tailcall_fn_834773C8_834854D0(ts4_word a0)
{
    return fn_834773C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83485568: tailcall fn_834773C8 */
ts4_word ts4_tailcall_fn_834773C8_83485568(ts4_word a0)
{
    return fn_834773C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x83485600: tailcall fn_834773C8 */
ts4_word ts4_tailcall_fn_834773C8_83485600(ts4_word a0)
{
    return fn_834773C8((ts4_word)a0);
}

/* Loader_DLL.xex 0x834856E8: tailcall fn_83485658 */
ts4_word ts4_tailcall_fn_83485658_834856E8(ts4_word a0)
{
    return fn_83485658((ts4_word)a0);
}

/* Loader_DLL.xex 0x83485730: tailcall fn_83485658 */
ts4_word ts4_tailcall_fn_83485658_83485730(ts4_word a0)
{
    return fn_83485658((ts4_word)a0);
}

/* Loader_DLL.xex 0x83485778: tailcall fn_83485658 */
ts4_word ts4_tailcall_fn_83485658_83485778(ts4_word a0)
{
    return fn_83485658((ts4_word)a0);
}

/* Loader_DLL.xex 0x834857C0: tailcall fn_83485658 */
ts4_word ts4_tailcall_fn_83485658_834857C0(ts4_word a0)
{
    return fn_83485658((ts4_word)a0);
}

/* Loader_DLL.xex 0x83486698: fn  */
void ts4_fn_83486698(void)
{
    return;
}

/* Loader_DLL.xex 0x834866B0: fn  */
void ts4_fn_834866B0(void)
{
    return;
}

/* Loader_DLL.xex 0x83488978: if_get u32@lbl_83544784, fn_83488638, fn_83488780 */
ts4_word ts4_if_get_u32_lbl_83544784_83488978(ts4_word a0, ts4_word a1)
{
    int t1;

    t1 = *(ts4_word *)lbl_83544784;
    if ((int)t1 != 0) {
        return fn_83488780((ts4_word)a0, (ts4_word)a1);
    }
    return fn_83488638((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x834889F0: fn  */
ts4_word ts4_fn_834889F0(void)
{
    return 1;
}

/* Loader_DLL.xex 0x83488A48: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u32@0x10, u32@0x0 */
void ts4_set_u32_off0_83488A48(ts4_word a0, ts4_word a1)
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

/* Loader_DLL.xex 0x83488DD0: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_83488DD0(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83488DE0: if_get u32@0x20, u32@0x20 */
ts4_word ts4_if_get_u32_off20_83488DE0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 32);
    if ((ts4_word)t1 != 0) {
        return 0;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)a1;
    return 1;
}

/* Loader_DLL.xex 0x83488E00: get u32@0x28 */
ts4_word ts4_get_u32_off28_83488E00(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 40));
}

/* Loader_DLL.xex 0x83488E08: call_seq u32@0x24, fn_8340CE50, u32@0x24, fn_8340D0D8 */
ts4_word ts4_call_seq_u32_off24_83488E08(ts4_word a0)
{
    fn_8340CE50((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)), (ts4_word)-1);
    fn_8340D0D8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 36)));
    return 0;
}

/* Loader_DLL.xex 0x83488F80: fn  */
ts4_word ts4_fn_83488F80(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83488F88: get u32@0x0, u32@0x0 */
ts4_word ts4_get_u32_off0_83488F88(ts4_word a0)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0);
}

/* Loader_DLL.xex 0x83489060: get u32@0x1c */
ts4_word ts4_get_u32_off1c_83489060(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 28));
}

/* Loader_DLL.xex 0x83489330: set u32@0x8, u32@0x0, u32@0xc, u32@0x10 */
void ts4_set_u32_off8_83489330(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)-1;
    return;
}

/* Loader_DLL.xex 0x83489720: fn  */
void ts4_fn_83489720(void)
{
    return;
}

/* Loader_DLL.xex 0x83489728: fn  */
void ts4_fn_83489728(void)
{
    return;
}

/* Loader_DLL.xex 0x83489730: fn  */
ts4_word ts4_fn_83489730(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83489738: fn  */
ts4_word ts4_fn_83489738(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83489740: fn  */
ts4_word ts4_fn_83489740(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83489748: fn  */
ts4_word ts4_fn_83489748(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83489750: get u32@0x4, lbl_83085968, fn_83112B88 */
ts4_word ts4_get_u32_off4_83489750(ts4_word a0)
{
    return fn_83112B88((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)), (ts4_word)(ts4_word)lbl_83085968, (ts4_word)(a0 + 12));
}

/* Loader_DLL.xex 0x83489768: fn  */
void ts4_fn_83489768(void)
{
    return;
}

/* Loader_DLL.xex 0x83489770: call_seq fn_8340CE98, u32@0x8 */
ts4_word ts4_call_seq_fn_8340CE98_83489770(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8340CE98();
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t1;
    return t1;
}

/* Loader_DLL.xex 0x834897A0: fn  */
ts4_word ts4_fn_834897A0(void)
{
    return 0;
}

/* Loader_DLL.xex 0x834897A8: get u32@0xc, u32@0xc */
void ts4_get_u32_offc_834897A8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(a1 + (*(ts4_word *)((char *)(ts4_word)(a0) + 12)));
    return;
}

/* Loader_DLL.xex 0x834897B8: fn  */
void ts4_fn_834897B8(void)
{
    return;
}

/* Loader_DLL.xex 0x834897C0: get u32@0x28, u32@0x2c, u32@0x28 */
ts4_word ts4_get_u32_off28_834897C0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 40);
    t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 44);
    *(ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)(t1 + a1);
    return (t2 + t1);
}

/* Loader_DLL.xex 0x83489840: set u8@0x10 */
void ts4_set_u8_off10_83489840(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)1;
    return;
}

/* Loader_DLL.xex 0x83489880: get u32@0xc, u32@0x8 */
ts4_word ts4_get_u32_offc_83489880(ts4_word a0)
{
    ts4_word t1;

    t1 = *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12);
    return (((*(volatile ts4_word *)((char *)(ts4_word)(a0) + 8)) - t1) == 0);
}

/* Loader_DLL.xex 0x83489898: get u32@0x8 */
ts4_word ts4_get_u32_off8_83489898(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x834898A0: get u32@0x4 */
ts4_word ts4_get_u32_off4_834898A0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x834898A8: set u32@0x0, u32@0x4, u32@0x8, u32@0xc, u8@0x10 */
void ts4_set_u32_off0_834898A8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    return;
}

/* Loader_DLL.xex 0x834898C8: get u32@0x1c */
ts4_word ts4_get_u32_off1c_834898C8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(ts4_word)(a0) + 28)) != 0);
}

/* Loader_DLL.xex 0x83489968: if_get u32@0x1c, u32@0x24 */
void ts4_if_get_u32_off1c_83489968(ts4_word a0)
{
    int t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 28);
    if ((int)t1 != 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)1;
    return;
}

/* Loader_DLL.xex 0x834899F8: set u32@0x4, u32@0x18, u32@0x1c, u32@0x20, u32@0x24, u32@0x14 */
void ts4_set_u32_off4_834899F8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a2) + 11048));
    return;
}

/* Loader_DLL.xex 0x83489A20: fn  */
void ts4_fn_83489A20(void)
{
    return;
}

/* Loader_DLL.xex 0x83489A28: fn  */
void ts4_fn_83489A28(void)
{
    return;
}

/* Loader_DLL.xex 0x83489A30: fn  */
void ts4_fn_83489A30(void)
{
    return;
}

/* Loader_DLL.xex 0x83489A38: fn  */
ts4_word ts4_fn_83489A38(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83489A40: addr lbl_83085DFC, u32@0x0 */
void ts4_addr_lbl_83085DFC_83489A40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085DFC;
    return;
}

/* Loader_DLL.xex 0x83489D68: fn  */
ts4_word ts4_fn_83489D68(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83489D70: fn  */
ts4_word ts4_fn_83489D70(void)
{
    return 1;
}

/* Loader_DLL.xex 0x83489D78: addr lbl_830858D4 */
ts4_word ts4_addr_lbl_830858D4_83489D78(void)
{
    return (ts4_word)lbl_830858D4;
}

/* Loader_DLL.xex 0x83489D88: get u32@0x8, u32@0x8 */
ts4_word ts4_get_u32_off8_83489D88(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(t1 + -1);
    return (t1 + -1);
}

/* Loader_DLL.xex 0x83489DA0: get u32@0x8, u32@0x8 */
void ts4_get_u32_off8_83489DA0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 8)) + 1);
    return;
}

/* Loader_DLL.xex 0x83489DB0: get u32@0x0, u32@0x8, vcall, fn_8311F9F8 */
ts4_word ts4_get_u32_off0_83489DB0(ts4_word a0)
{
    ts4_word t3;
    ts4_word t4;

    t3 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 8))))((ts4_word)a0);
    t4 = fn_8311F9F8((ts4_word)t3);
    return t4;
}

/* Loader_DLL.xex 0x83489E70: addr lbl_83085DDC, u32@0x0 */
void ts4_addr_lbl_83085DDC_83489E70(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085DDC;
    return;
}

/* Loader_DLL.xex 0x83489E80: fn  */
ts4_word ts4_fn_83489E80(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83489E88: fn  */
ts4_word ts4_fn_83489E88(void)
{
    return 1;
}

/* Loader_DLL.xex 0x83489E90: addr lbl_830858D4 */
ts4_word ts4_addr_lbl_830858D4_83489E90(void)
{
    return (ts4_word)lbl_830858D4;
}

/* Loader_DLL.xex 0x83489EA0: get u32@0x38, u32@0x38 */
ts4_word ts4_get_u32_off38_83489EA0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 56);
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)(t1 + -1);
    return (t1 + -1);
}

/* Loader_DLL.xex 0x83489EB8: get u32@0x38, u32@0x38 */
void ts4_get_u32_off38_83489EB8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 56) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 56)) + 1);
    return;
}

/* Loader_DLL.xex 0x83489F30: fn  */
ts4_word ts4_fn_83489F30(void)
{
    return 0;
}

/* Loader_DLL.xex 0x83489F38: if_get u32@0xc, u32@0x0 */
ts4_word ts4_if_get_u32_offc_83489F38(ts4_word a0, ts4_word a1)
{
    if ((ts4_word)a1 != 0) {
        *(ts4_word *)((char *)(ts4_word)(a1) + 0) = (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12));
    }
    return 0;
}

/* Loader_DLL.xex 0x8348A028: get u32@0x10, u32@0x14 */
ts4_word ts4_get_u32_off10_8348A028(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 16);
    return (t1 - (*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
}

/* Loader_DLL.xex 0x8348A038: get u32@0x10 */
ts4_word ts4_get_u32_off10_8348A038(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Loader_DLL.xex 0x8348A040: set u32@0x8 */
ts4_word ts4_set_u32_off8_8348A040(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x8348A050: get u32@0x8 */
ts4_word ts4_get_u32_off8_8348A050(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8348A0A8: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_8348A0A8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1);
    return;
}

/* Loader_DLL.xex 0x8348A0B8: addr lbl_83085F20, u32@0x0 */
void ts4_addr_lbl_83085F20_8348A0B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085F20;
    return;
}

/* Loader_DLL.xex 0x8348A0C8: get u32@0xc, u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_offc_8348A0C8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 36))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x8348A0E0: get u32@0xc, u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_offc_8348A0E0(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x8348A0F8: get u32@0xc, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_offc_8348A0F8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x8348A110: get u32@0xc, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_offc_8348A110(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1);
}

/* Loader_DLL.xex 0x8348A128: set u32@0x8 */
ts4_word ts4_set_u32_off8_8348A128(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    return 0;
}

/* Loader_DLL.xex 0x8348A138: get u32@0x8 */
ts4_word ts4_get_u32_off8_8348A138(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 8));
}

/* Loader_DLL.xex 0x8348A190: get u32@0x4, u32@0x4 */
void ts4_get_u32_off4_8348A190(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 4)) + 1);
    return;
}

/* Loader_DLL.xex 0x8348A1A0: addr lbl_83085EF0, u32@0x0, u32@0xc, u32@0x0, u32@0x4 */
ts4_word ts4_addr_lbl_83085EF0_8348A1A0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085EF0;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 4))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Loader_DLL.xex 0x8348A1C0: set u32@0x8, u32@0xc, lbl_83085EF0, u32@0x4, u32@0x0 */
void ts4_set_u32_off8_8348A1C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085EF0;
    return;
}

/* Loader_DLL.xex 0x8348A1E0: get u32@0x8c4 */
ts4_word ts4_get_u32_off8c4_8348A1E0(ts4_word a0)
{
    return (((*(ts4_word *)((char *)(ts4_word)(a0) + 2244)) + -1) == 0);
}

/* Loader_DLL.xex 0x8348A1F8: get u32@0x8bc, fn_83113F88 */
ts4_word ts4_get_u32_off8bc_8348A1F8(ts4_word a0, ts4_word a1)
{
    return fn_83113F88((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 2236)), (ts4_word)a1);
}

/* Loader_DLL.xex 0x8348A200: call_seq u32@0x8bc, fn_83113EF8, u32@0x8bc */
ts4_word ts4_call_seq_u32_off8bc_8348A200(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_83113EF8((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 2236)));
    *(ts4_word *)((char *)(ts4_word)(a0) + 2236) = (ts4_word)0;
    return t2;
}

/* Loader_DLL.xex 0x8348A688: fn  */
void ts4_fn_8348A688(void)
{
    return;
}

/* Loader_DLL.xex 0x8348A6D8: get u32@0x3c */
ts4_word ts4_get_u32_off3c_8348A6D8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x8348AA20: get u32@0x3c */
ts4_word ts4_get_u32_off3c_8348AA20(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 60));
}

/* Loader_DLL.xex 0x8348AD98: fn  */
void ts4_fn_8348AD98(void)
{
    return;
}

/* Loader_DLL.xex 0x8348AE10: get u8@0x8d */
ts4_word ts4_get_u8_off8d_8348AE10(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 141));
}

/* Loader_DLL.xex 0x8348AE68: fn  */
ts4_word ts4_fn_8348AE68(ts4_word a0)
{
    return (a0 + 16);
}

/* Loader_DLL.xex 0x8348AE70: get u32@0x4 */
ts4_word ts4_get_u32_off4_8348AE70(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Loader_DLL.xex 0x8348AE78: set u32@lbl_83544ECC */
void ts4_set_u32_lbl_83544ECC_8348AE78(void)
{
    *(ts4_word *)lbl_83544ECC = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8348AEF0: fn  */
void ts4_fn_8348AEF0(void)
{
    return;
}

/* Loader_DLL.xex 0x8348AEF8: fn  */
void ts4_fn_8348AEF8(void)
{
    return;
}

/* Loader_DLL.xex 0x8348AF00: get u32@lbl_83544ECC */
ts4_word ts4_get_u32_lbl_83544ECC_8348AF00(void)
{
    return (*(ts4_word *)lbl_83544ECC);
}

/* Loader_DLL.xex 0x8348B080: fn  */
void ts4_fn_8348B080(void)
{
    return;
}

/* Loader_DLL.xex 0x8348B088: fn  */
void ts4_fn_8348B088(void)
{
    return;
}

/* Loader_DLL.xex 0x8348B0D0: get u32@lbl_83544EB8 */
ts4_word ts4_get_u32_lbl_83544EB8_8348B0D0(void)
{
    return (*(ts4_word *)lbl_83544EB8);
}

/* Loader_DLL.xex 0x8348B0E0: fn  */
void ts4_fn_8348B0E0(void)
{
    return;
}

/* Loader_DLL.xex 0x8348B0E8: fn  */
ts4_word ts4_fn_8348B0E8(void)
{
    return 1;
}

/* Loader_DLL.xex 0x8348B258: call_seq fn_83488BA0, fn_83109390 */
ts4_word ts4_call_seq_fn_83488BA0_8348B258(ts4_word a0)
{
    ts4_word loc50[4];
    ts4_word loc60[8];
    ts4_word t2;

    fn_83488BA0((ts4_word)(ts4_word)&loc60[0], (ts4_word)(ts4_word)&loc50[0]);
    t2 = fn_83109390((ts4_word)a0, (ts4_word)(ts4_word)&loc60[0]);
    return t2;
}

/* Loader_DLL.xex 0x8348B358: set u32@0x4, u32@0x8, lbl_83085E64, u32@0x0 */
void ts4_set_u32_off4_8348B358(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085E64;
    return;
}

/* Loader_DLL.xex 0x8348BBD0: tailcall fn_8348BAD8 */
ts4_word ts4_tailcall_fn_8348BAD8_8348BBD0(ts4_word a0)
{
    return fn_8348BAD8((ts4_word)a0, (ts4_word)-1);
}

/* Loader_DLL.xex 0x8348BE40: set u32@0x8, u32@0x0, u32@0xc, u32@0x10 */
void ts4_set_u32_off8_8348BE40(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)-1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)-1;
    return;
}

/* Loader_DLL.xex 0x8348C058: call_seq u32@0x10, fn_8340CE98, u32@0x8, u32@0xc */
ts4_word ts4_call_seq_u32_off10_8348C058(ts4_word a0)
{
    ts4_word t1;

    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    t1 = fn_8340CE98();
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)t1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t1;
    return t1;
}

/* Loader_DLL.xex 0x8348C098: addr lbl_83085DFC, u32@0x0 */
void ts4_addr_lbl_83085DFC_8348C098(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085DFC;
    return;
}

/* Loader_DLL.xex 0x8348C0A8: addr lbl_83085DFC, u32@0x0 */
void ts4_addr_lbl_83085DFC_8348C0A8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085DFC;
    return;
}

/* Loader_DLL.xex 0x8348C0B8: set u32@0x4 */
void ts4_set_u32_off4_8348C0B8(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8348C0C8: get u32@0x8, u32@0x4, u32@0xc */
void ts4_get_u32_off8_8348C0C8(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)t1;
    return;
}

/* Loader_DLL.xex 0x8348C280: call_seq fn_83489908, u32@0x0 */
ts4_word ts4_call_seq_fn_83489908_8348C280(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    (void)a0;
    (void)a1;
    t1 = fn_83489908();
    *(ts4_word *)((char *)(ts4_word)(a2) + 0) = (ts4_word)t1;
    return t1;
}

/* Loader_DLL.xex 0x8348C2B0: if_call_seq fn_83489908, fn_834897E0 */
ts4_word ts4_if_call_seq_fn_83489908_8348C2B0(void)
{
    ts4_word p3;
    ts4_word t1;
    ts4_word t2;

    t1 = fn_83489908();
    p3 = (ts4_word)t1;
    if ((ts4_word)t1 != 0) {
        t2 = fn_834897E0((ts4_word)t1, (ts4_word)-1);
        p3 = (ts4_word)t2;
    }
    return p3;
}

/* Loader_DLL.xex 0x8348C3D0: get u32@lbl_83544EB8 */
ts4_word ts4_get_u32_lbl_83544EB8_8348C3D0(void)
{
    return (*(ts4_word *)lbl_83544EB8);
}

/* Loader_DLL.xex 0x8348C3E0: addr lbl_83085DDC, u32@0x4, u32@0x0, u32@0x8, u16@0xc, u16@0x216 */
void ts4_addr_lbl_83085DDC_8348C3E0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085DDC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 12) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 534) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 1056) = (unsigned short)0;
    *(unsigned short *)((char *)(ts4_word)(a0) + 1578) = (unsigned short)0;
    return;
}

/* Loader_DLL.xex 0x8348C458: set u32@0x8, u32@0xc, lbl_83085F20, u32@0x10, u32@0x4, u32@0x0 */
void ts4_set_u32_off8_8348C458(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)a1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)a2;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085F20;
    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8348C530: get u32@lbl_83544ECC, u8@0x8d */
ts4_word ts4_get_u32_lbl_83544ECC_8348C530(void)
{
    return (*(unsigned char *)((char *)(ts4_word)((*(ts4_word *)lbl_83544ECC)) + 141));
}

/* Loader_DLL.xex 0x8348C540: get u32@lbl_83544EB8, u32@0x974, u32@0xc */
ts4_word ts4_get_u32_lbl_83544EB8_8348C540(void)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_83544EB8)) + 2420))) + 12));
}

/* Loader_DLL.xex 0x8348CE38: if_get u32@0x0, fn_8348CDB8 */
ts4_word ts4_if_get_u32_off0_8348CE38(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 0);
    if ((ts4_word)t1 == 0) {
        return a0;
    }
    return fn_8348CDB8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8348CEC0: if_addr lbl_83544EC0, u32@lbl_83544EC0, fn_8348CDB8 */
ts4_word ts4_if_addr_lbl_83544EC0_8348CEC0(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_83544EC0;
    if ((ts4_word)t1 == 0) {
        return (ts4_word)lbl_83544EC0;
    }
    return fn_8348CDB8((ts4_word)(ts4_word)lbl_83544EC0);
}

/* Loader_DLL.xex 0x8348CF60: if_addr lbl_83544EBC, u32@lbl_83544EBC, fn_8348CDB8 */
ts4_word ts4_if_addr_lbl_83544EBC_8348CF60(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_83544EBC;
    if ((ts4_word)t1 == 0) {
        return (ts4_word)lbl_83544EBC;
    }
    return fn_8348CDB8((ts4_word)(ts4_word)lbl_83544EBC);
}

/* Loader_DLL.xex 0x8348D000: get u32@lbl_83544EB8, u32@0x970, u32@0x2af8 */
ts4_word ts4_get_u32_lbl_83544EB8_8348D000(void)
{
    return ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)lbl_83544EB8)) + 2416))) + 11000))))((ts4_word)0);
}

/* Loader_DLL.xex 0x8348DF90: if_addr lbl_83544EBC, u32@lbl_83544EBC, fn_8348CDB8 */
ts4_word ts4_if_addr_lbl_83544EBC_8348DF90(void)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_83544EBC;
    if ((ts4_word)t1 == 0) {
        return (ts4_word)lbl_83544EBC;
    }
    return fn_8348CDB8((ts4_word)(ts4_word)lbl_83544EBC);
}

/* Loader_DLL.xex 0x8348E198: addr lbl_83085DB8, u32@0x0, fn_830A23D8 */
ts4_word ts4_addr_lbl_83085DB8_8348E198(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085DB8;
    return fn_830A23D8((ts4_word)(a0 + 8));
}

/* Loader_DLL.xex 0x8348E1B0: addr lbl_83085DB8, u32@0x0, u32@0x8, u32@0xc, u32@0x10, u32@0x18 */
void ts4_addr_lbl_83085DB8_8348E1B0(ts4_word a0)
{
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085DB8;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 28) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 32) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 36) = (ts4_word)0;
    *(volatile ts4_word *)((char *)(ts4_word)(a0) + 40) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x8348F1A8: call_seq u32@0x4, fn_830AACF0, u8@0x8c */
ts4_word ts4_call_seq_u32_off4_8348F1A8(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_830AACF0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    *(unsigned char *)((char *)(ts4_word)(a0) + 140) = (unsigned char)0;
    return t2;
}

/* Loader_DLL.xex 0x8348FBD0: get u32@lbl_83544EB8, fn_8348E990 */
ts4_word ts4_get_u32_lbl_83544EB8_8348FBD0(void)
{
    return fn_8348E990((ts4_word)((*(ts4_word *)lbl_83544EB8) + 144), (ts4_word)5, (ts4_word)5);
}

/* Loader_DLL.xex 0x8348FBE8: get u32@lbl_83544EB8, fn_8348E990 */
ts4_word ts4_get_u32_lbl_83544EB8_8348FBE8(void)
{
    return fn_8348E990((ts4_word)((*(ts4_word *)lbl_83544EB8) + 144), (ts4_word)6, (ts4_word)6);
}

/* Loader_DLL.xex 0x8348FD98: call_seq u32@0xc, fn_831137A0, fn_8348E7D8 */
ts4_word ts4_call_seq_u32_offc_8348FD98(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_831137A0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)a1);
    t3 = fn_8348E7D8((ts4_word)(a0 + 12));
    return t3;
}

/* Loader_DLL.xex 0x8348FE98: addr lbl_83085DFC, u32@0x4, u32@0x0 */
void ts4_addr_lbl_83085DFC_8348FE98(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085DFC;
    return;
}

/* Loader_DLL.xex 0x83490440: addr lbl_83085EB8, u32@0x4, u32@0x0, u32@0x8 */
void ts4_addr_lbl_83085EB8_83490440(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085EB8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83490460: addr lbl_83085E80, u32@0x4, u32@0x0, u32@0xc, u32@0x8 */
void ts4_addr_lbl_83085E80_83490460(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_83085E80;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    return;
}

/* Loader_DLL.xex 0x83490480: tailcall fn_830A3208 */
ts4_word ts4_tailcall_fn_830A3208_83490480(ts4_word a0)
{
    return fn_830A3208((ts4_word)(a0 + 8));
}

/* Loader_DLL.xex 0x834922C8: call_seq fn_83492080, fn_8348CEE0 */
ts4_word ts4_call_seq_fn_83492080_834922C8(void)
{
    ts4_word t1;
    ts4_word t2;

    t1 = fn_83492080();
    t2 = fn_8348CEE0((ts4_word)t1);
    return t2;
}

/* Loader_DLL.xex 0x83492380: call_seq u32@0x4, fn_830AAC58, u8@0x8c */
ts4_word ts4_call_seq_u32_off4_83492380(ts4_word a0)
{
    ts4_word t2;

    t2 = fn_830AAC58((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 4)));
    *(unsigned char *)((char *)(ts4_word)(a0) + 140) = (unsigned char)1;
    return t2;
}

/* Loader_DLL.xex 0x83492920: tailcall fn_83492878 */
ts4_word ts4_tailcall_fn_83492878_83492920(ts4_word a0)
{
    return fn_83492878((ts4_word)a0);
}

/* Loader_DLL.xex 0x8349D158: tailcall fn_8349A030 */
ts4_word ts4_tailcall_fn_8349A030_8349D158(ts4_word a0, ts4_word a1)
{
    return fn_8349A030((ts4_word)a0, (ts4_word)a1);
}

/* Loader_DLL.xex 0x8349D160: tailcall fn_834970A8 */
ts4_word ts4_tailcall_fn_834970A8_8349D160(ts4_word a0)
{
    return fn_834970A8((ts4_word)a0);
}

/* Loader_DLL.xex 0x8349D168: tailcall fn_83499640 */
ts4_word ts4_tailcall_fn_83499640_8349D168(ts4_word a0)
{
    return fn_83499640((ts4_word)a0);
}

/* Loader_DLL.xex 0x8349E960: fn  */
void ts4_fn_8349E960(void)
{
    return;
}

/* Loader_DLL.xex 0x834AA1B0: get u32@0x5b8, u32@0x558 */
ts4_word ts4_get_u32_off5b8_834AA1B0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1464);
    return ((((((int)(((int)a1 >> 8) & 0xfffffe00) * (int)t1) & 0xfffe0000) - ((*(ts4_word *)((char *)(ts4_word)(a0) + 1368)) << 17)) + 65536) | (((int)((int)((short)a1) * (int)t1) >> 8) & 0xffff));
}

/* Loader_DLL.xex 0x834AA538: get u32@0x5b0, u32@0x558 */
ts4_word ts4_get_u32_off5b0_834AA538(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 1456);
    return ((((((int)(((int)a1 >> 8) & 0xfffffe00) * (int)t1) & 0xfffe0000) - ((*(ts4_word *)((char *)(ts4_word)(a0) + 1368)) << 17)) + 65536) | (((int)((int)((short)a1) * (int)t1) >> 8) & 0xffff));
}

/* Loader_DLL.xex 0x834B8568: get u16@0x34, fn_83514B48 */
ts4_word ts4_get_u16_off34_834B8568(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_83514B48((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)0, (ts4_word)(((*(unsigned short *)((char *)(ts4_word)(a1) + 52))) >> 1));
}

/* Loader_DLL.xex 0x834D38C0: get u16@0x34, fn_834D3358 */
ts4_word ts4_get_u16_off34_834D38C0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_834D3358((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)0, (ts4_word)0, (ts4_word)(((*(unsigned short *)((char *)(ts4_word)(a1) + 52))) >> 1));
}

/* Loader_DLL.xex 0x83515D58: tailcall fn_83515340 */
ts4_word ts4_tailcall_fn_83515340_83515D58(ts4_word a0)
{
    return fn_83515340((ts4_word)a0);
}

/* Loader_DLL.xex 0x83515D60: addr lbl_8352F750, fn_833E3A30 */
ts4_word ts4_addr_lbl_8352F750_83515D60(void)
{
    return fn_833E3A30((ts4_word)(ts4_word)lbl_8352F750, (ts4_word)0, (ts4_word)44);
}

/* Loader_DLL.xex 0x83515D78: addr fn_83516530, fn_833E4920 */
ts4_word ts4_addr_fn_83516530_83515D78(void)
{
    return fn_833E4920((ts4_word)(ts4_word)fn_83516530);
}

/* Loader_DLL.xex 0x83515D88: addr fn_83516798, fn_833E4920 */
ts4_word ts4_addr_fn_83516798_83515D88(void)
{
    return fn_833E4920((ts4_word)(ts4_word)fn_83516798);
}

/* Loader_DLL.xex 0x83515E60: addr fn_83516860, fn_833E4920 */
ts4_word ts4_addr_fn_83516860_83515E60(void)
{
    return fn_833E4920((ts4_word)(ts4_word)fn_83516860);
}

/* Loader_DLL.xex 0x83515E70: addr fn_83516870, fn_833E4920 */
ts4_word ts4_addr_fn_83516870_83515E70(void)
{
    return fn_833E4920((ts4_word)(ts4_word)fn_83516870);
}

/* Loader_DLL.xex 0x83515E80: addr fn_83516850, fn_833E4920 */
ts4_word ts4_addr_fn_83516850_83515E80(void)
{
    return fn_833E4920((ts4_word)(ts4_word)fn_83516850);
}

/* Loader_DLL.xex 0x83515E90: addr fn_83516880, fn_833E4920 */
ts4_word ts4_addr_fn_83516880_83515E90(void)
{
    return fn_833E4920((ts4_word)(ts4_word)fn_83516880);
}

/* Loader_DLL.xex 0x83515EA0: addr fn_83516890, fn_833E4920 */
ts4_word ts4_addr_fn_83516890_83515EA0(void)
{
    return fn_833E4920((ts4_word)(ts4_word)fn_83516890);
}

/* Loader_DLL.xex 0x83515EB0: addr fn_835168D0, fn_833E4920 */
ts4_word ts4_addr_fn_835168D0_83515EB0(void)
{
    return fn_833E4920((ts4_word)(ts4_word)fn_835168D0);
}

/* Loader_DLL.xex 0x83515F68: addr fn_83516910, fn_833E4920 */
ts4_word ts4_addr_fn_83516910_83515F68(void)
{
    return fn_833E4920((ts4_word)(ts4_word)fn_83516910);
}

/* Loader_DLL.xex 0x83516040: addr fn_83516938, fn_833E4920 */
ts4_word ts4_addr_fn_83516938_83516040(void)
{
    return fn_833E4920((ts4_word)(ts4_word)fn_83516938);
}

/* Loader_DLL.xex 0x835164E8: addr lbl_83542D90, fn_833C6758 */
ts4_word ts4_addr_lbl_83542D90_835164E8(void)
{
    return fn_833C6758((ts4_word)(ts4_word)lbl_83542D90);
}

/* Loader_DLL.xex 0x83516530: fn  */
void ts4_fn_83516530(void)
{
    return;
}

/* Loader_DLL.xex 0x83516538: fn  */
void ts4_fn_83516538(void)
{
    return;
}

/* Loader_DLL.xex 0x83516540: fn  */
void ts4_fn_83516540(void)
{
    return;
}

/* Loader_DLL.xex 0x83516548: addr lbl_8352FE8C, fn_83140C58 */
ts4_word ts4_addr_lbl_8352FE8C_83516548(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8352FE8C);
}

/* Loader_DLL.xex 0x83516558: addr lbl_8352FE74, fn_83140C58 */
ts4_word ts4_addr_lbl_8352FE74_83516558(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8352FE74);
}

/* Loader_DLL.xex 0x83516568: addr lbl_8352FE5C, fn_83140C58 */
ts4_word ts4_addr_lbl_8352FE5C_83516568(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8352FE5C);
}

/* Loader_DLL.xex 0x83516578: addr lbl_8352FE44, fn_83140C58 */
ts4_word ts4_addr_lbl_8352FE44_83516578(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8352FE44);
}

/* Loader_DLL.xex 0x83516588: addr lbl_8352FE2C, fn_83140C58 */
ts4_word ts4_addr_lbl_8352FE2C_83516588(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8352FE2C);
}

/* Loader_DLL.xex 0x83516598: addr lbl_8352FEBC, fn_83140C58 */
ts4_word ts4_addr_lbl_8352FEBC_83516598(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8352FEBC);
}

/* Loader_DLL.xex 0x835165A8: addr lbl_8352FEA4, fn_83140C58 */
ts4_word ts4_addr_lbl_8352FEA4_835165A8(void)
{
    return fn_83140C58((ts4_word)(ts4_word)lbl_8352FEA4);
}
