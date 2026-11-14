/* Small accessor / thunk / constructor-like functions (family I, round 3).
   Each function belongs to a cluster of byte-identical functions found in
   Swing_DLL.xex (Xbox 360, MSVC 16.00.10224.00); the original address is in the
   comment above each definition. Bodies were derived from the disassembly and
   verified byte-for-byte with tools/fn_check.py. Parameters are untyped words
   (a0 = this/first argument); field accesses are by byte offset. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
#else
typedef unsigned long long ts4_u64;
#endif
typedef unsigned long ts4_word;

extern char lbl_8803A308[];
extern char lbl_88080078[];
extern char lbl_88080084[];
extern char lbl_88080090[];
extern char lbl_880800A4[];
extern char lbl_880DB648[];
extern char lbl_880DB834[];
extern char lbl_880DD020[];
extern char lbl_880DD088[];
extern char lbl_880DD6D8[];
extern char lbl_880DF3DC[];
extern char lbl_880EA35C[];
extern char lbl_880F4788[];
extern char lbl_880F47C8[];
extern char lbl_880F50FC[];
extern char lbl_880F5408[];
extern char lbl_880F54E0[];
extern char lbl_880F58A8[];
extern char lbl_880F58C0[];
extern char lbl_880F5918[];
extern char lbl_880F5930[];
extern char lbl_880F799C[];
extern char lbl_880F9018[];
extern char lbl_880F907C[];
extern char lbl_880F908C[];
extern char lbl_88D3E3A8[];
extern char lbl_88D45B38[];
ts4_word NetDll_XNetGetTitleXnAddr(ts4_word, ts4_word);
ts4_word NetDll_XNetQosRelease(ts4_word, ts4_word);
ts4_word RtlEnterCriticalSection(ts4_word);
ts4_word RtlLeaveCriticalSection(ts4_word);
ts4_word fn_8818A530(ts4_word);
ts4_word fn_8818B590(ts4_word);
ts4_word fn_88195368();
ts4_word fn_88195DF0(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_88195EE0(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_88198F20();
ts4_word fn_881992A8(ts4_word, ts4_word);
ts4_word fn_8819B0C8(ts4_word, ts4_word);
ts4_word fn_8819B4C8(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_8819C3F0(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_881DFE70(ts4_word);
ts4_word fn_881E0258(ts4_word);
ts4_word fn_881E19C0(ts4_word);
ts4_word fn_881EF198();
ts4_word fn_881EF750();
ts4_word fn_881EFA60();
ts4_word fn_882782A8(ts4_word);
ts4_word fn_88278368(ts4_word);
ts4_word ts4_zlib_inflateInit2__882F3010(ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_8831A7F0(ts4_word);
ts4_word fn_883255A0(ts4_word, ts4_word, ts4_word);
ts4_word fn_88333FB0(ts4_word);
ts4_word fn_88334128(ts4_word);
ts4_word fn_883E63B8(ts4_word);
ts4_word fn_8841ED08(ts4_word);
ts4_word fn_88434E40(ts4_word);
ts4_word fn_88437D30(ts4_word);
ts4_word fn_884448B0(ts4_word);
ts4_word fn_8846C2A8(ts4_word, ts4_word, ts4_word);
ts4_word fn_88470AD0(ts4_word, ts4_word, ts4_word);
ts4_word fn_88475AE8(ts4_word);
ts4_word fn_88475B08(ts4_word);
ts4_word fn_88493D50(ts4_word);
ts4_word fn_884A1328(ts4_word);
ts4_word fn_884A14F8(ts4_word);
ts4_word fn_884A1938(ts4_word);
ts4_word fn_884AA7D8(ts4_word);
ts4_word fn_884AB860(ts4_word);
ts4_word fn_884B1008(ts4_word);
ts4_word fn_884B2308(ts4_word);
ts4_word fn_884EBBC0(ts4_word);
ts4_word fn_885223F0(ts4_word);
ts4_word fn_88522BC0(ts4_word);
ts4_word fn_8857A1E0(ts4_word);
ts4_word fn_8857ACB8(ts4_word, ts4_word);
ts4_word fn_8857B830();
ts4_word fn_8857C040(ts4_word, ts4_word, ts4_word);
ts4_word fn_8857C8C8();
ts4_word fn_885949C0(ts4_word);
ts4_word fn_885A6C48(ts4_word);
ts4_word fn_885A6E08(ts4_word);
ts4_word fn_885B5740(ts4_word);
ts4_word fn_8860BE40(ts4_word);
ts4_word fn_88613268(ts4_word, ts4_word, ts4_word, ts4_word, ts4_word);
ts4_word fn_88617D88(ts4_word);
ts4_word fn_886214A0(ts4_word);
ts4_word fn_88626840(ts4_word);
ts4_word fn_88629B60(ts4_word);
ts4_word fn_88721D08(ts4_word);
ts4_word fn_8872A910(ts4_word);
ts4_word fn_88772FD8(ts4_word);
ts4_word fn_887732E8(ts4_word);
ts4_word fn_88773390(ts4_word);
ts4_word fn_88793C60(ts4_word);
ts4_word fn_88795E40(ts4_word);
ts4_word fn_88798368(ts4_word);
ts4_word fn_887C85E0(ts4_word);
ts4_word fn_887CBD40(ts4_word);
ts4_word fn_887D2F98(ts4_word);
ts4_word fn_887EB298(ts4_word);
ts4_word fn_887EE810(ts4_word);
ts4_word fn_887F13B8(ts4_word);
ts4_word fn_887F90F0(ts4_word);
ts4_word fn_88804BE8(ts4_word);
ts4_word fn_888240B8(ts4_word);
ts4_word fn_88824188(ts4_word);
ts4_word fn_88850648(ts4_word);
ts4_word fn_888663D0(ts4_word);
ts4_word fn_88866480(ts4_word);
ts4_word fn_888682F0(ts4_word);
ts4_word fn_888860A0(ts4_word);
ts4_word fn_88887FA0(ts4_word);
ts4_word fn_888B0CA8(ts4_word);
ts4_word fn_888B0FF8(ts4_word);
ts4_word fn_888B9410(ts4_word);
ts4_word fn_888CA9A0(ts4_word);
ts4_word fn_888CB730(ts4_word);
ts4_word fn_888CB860(ts4_word);
ts4_word fn_888DDF98(ts4_word);
ts4_word fn_888DE030(ts4_word);
ts4_word fn_888DE430(ts4_word);
ts4_word fn_888DF440(ts4_word);
ts4_word fn_888DF630(ts4_word);
ts4_word fn_888DF9C0(ts4_word);
ts4_word fn_8891A388(ts4_word);
ts4_word fn_88951690(ts4_word);
ts4_word fn_88951BB8(ts4_word);
ts4_word fn_889666A8(ts4_word);
ts4_word fn_8896BD28(ts4_word);
ts4_word ts4_forward_885A9E30(ts4_word);
ts4_word ts4_object_finalize(ts4_word);
ts4_word ts4_tsu_cleanup_end(ts4_word);

/* Swing_DLL.xex 0x88167CB0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951BB8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88167CB0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)236, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88951BB8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88167EC0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88951690 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88167EC0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88951690((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881687E0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_889666A8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881687E0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)112, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_889666A8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88168AF0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8896BD28 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88168AF0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)120, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8896BD28((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88173158: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8891A388 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88173158(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)244, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8891A388((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881746E0: tailcall ts4_object_finalize */
ts4_word ts4_tailcall_ts4_object_finalize_881746E0(ts4_word a0)
{
    return ts4_object_finalize((ts4_word)(a0 + 8));
}

/* Swing_DLL.xex 0x88175F48: get u32@0xc, u32@0x8 */
ts4_word ts4_get_u32_offc_88175F48(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 12);
    return ((int)(t1 - (*(ts4_word *)((char *)(a0) + 8))) >> 2);
}

/* Swing_DLL.xex 0x88182F88: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DF630 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88182F88(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)236, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DF630((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183388: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DF440 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183388(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)104, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DF440((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183940: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880DB648, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183940(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DB648;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183A88: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CB860 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183A88(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)160, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CB860((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88183AE0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CB730 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88183AE0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)108, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CB730((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184290: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DE430 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184290(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)100, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DE430((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881843F0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888CA9A0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881843F0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)96, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888CA9A0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881849B8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DE030 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881849B8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)272, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DE030((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88184BC8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DDF98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88184BC8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)120, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DDF98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88185220: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888DF9C0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88185220(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)84, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888DF9C0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881852D0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880DB834, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881852D0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(t2) + 0) = (ts4_word)(ts4_word)lbl_880DB834;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88188ED0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888B9410 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88188ED0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)72, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888B9410((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88188F28: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888B9410 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88188F28(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)72, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888B9410((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88189138: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888B0FF8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88189138(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)172, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888B0FF8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881891E8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888B0CA8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881891E8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)244, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888B0CA8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8818A650: call_seq RtlEnterCriticalSection */
ts4_word ts4_call_seq_RtlEnterCriticalSection_8818A650(ts4_word a0)
{
    RtlEnterCriticalSection((ts4_word)(a0 + 8));
    return 1;
}

/* Swing_DLL.xex 0x8818A678: call_seq RtlLeaveCriticalSection */
ts4_word ts4_call_seq_RtlLeaveCriticalSection_8818A678(ts4_word a0)
{
    RtlLeaveCriticalSection((ts4_word)(a0 + 8));
    return 1;
}

/* Swing_DLL.xex 0x8818AF58: if_call_seq u32@lbl_88D3E3A8, fn_88195368, fn_88195EE0 */
ts4_word ts4_if_call_seq_u32_lbl_88D3E3A8_8818AF58(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D3E3A8;
    if ((ts4_word)t1 == 0) {
        fn_88195368();
    }
    fn_88195EE0((ts4_word)a0, (ts4_word)(a1 + 44), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
    return a0;
}

/* Swing_DLL.xex 0x8818B270: if_call_seq lbl_880DD020, u32@0x0, fn_8818B590, lbl_880DD088, u32@0x0, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880DD020_8818B270(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD020;
    fn_8818B590((ts4_word)a0);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x8818B7B0: get u32@0x10, u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off10_8818B7B0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 28))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88193AF8: if_call_seq u32@lbl_88D3E3A8, fn_88195368, fn_88195DF0 */
ts4_word ts4_if_call_seq_u32_lbl_88D3E3A8_88193AF8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6)
{
    ts4_word t1;

    t1 = *(ts4_word *)lbl_88D3E3A8;
    if ((ts4_word)t1 == 0) {
        fn_88195368();
    }
    fn_88195DF0((ts4_word)a0, (ts4_word)(a1 + 44), (ts4_word)a2, (ts4_word)a3, (ts4_word)a4, (ts4_word)a5, (ts4_word)a6);
    return a0;
}

/* Swing_DLL.xex 0x88197750: get u32@0x0, u32@-0x10, u32@0x0, u32@0x10, vcall, u32@0x0 */
ts4_word ts4_get_u32_off0_88197750(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t2 = *(ts4_word *)((char *)((*(ts4_word *)((char *)(a1) + 0))) + -16);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t2) + 0))) + 16))))((ts4_word)t2);
    t6 = *(ts4_word *)((char *)(a2) + 0);
    t7 = *(ts4_word *)((char *)(a1) + 0);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(t5 + 16);
    t8 = *(ts4_word *)((char *)(t6) + -12);
    fn_8819B4C8((ts4_word)a0, (ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(t7) + -12)), (ts4_word)t6, (ts4_word)t8, (ts4_word)(t5 + 16));
    return a0;
}

/* Swing_DLL.xex 0x88198B38: get u32@-0x8 */
ts4_word ts4_get_u32_0x8_88198B38(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(ts4_word *)((char *)(a1) + -8));
}

/* Swing_DLL.xex 0x881994D8: if_call_seq lbl_880DD6D8, u32@0x0, fn_88198F20, lbl_880DD088, u32@0x0, fn_881992A8 */
ts4_word ts4_if_call_seq_lbl_880DD6D8_881994D8(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD6D8;
    fn_88198F20();
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DD088;
    if ((ts4_word)(a1 & 0x1) != 0) {
        fn_881992A8((ts4_word)0, (ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881A56E0: if_call_seq u32@0x14, lbl_880DF3DC, u32@0x0, fn_8857A1E0, lbl_880F799C, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off14_881A56E0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 20);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880DF3DC;
    if ((int)t1 != -1) {
        fn_8857A1E0((ts4_word)t1);
    }
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F799C;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x881A5CA0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88887FA0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881A5CA0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)552, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88887FA0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AC088: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88866480 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AC088(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88866480((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AC138: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888663D0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AC138(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)56, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888663D0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AC2F0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_888682F0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AC2F0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)172, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_888682F0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881AF460: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88850648 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881AF460(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)112, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88850648((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B1A38: call_seq u32@0x0, fn_88824188, u32@0x0, u32@0x0, u32@0xc, u32@0x10 */
ts4_word ts4_call_seq_u32_off0_881B1A38(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;

    fn_88824188((ts4_word)(*(ts4_word *)((char *)(a1) + 0)));
    t3 = *(ts4_word *)((char *)(a1) + 0);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)a1;
    t4 = *(ts4_word *)((char *)(t3) + 12);
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)((int)(t4 - (*(ts4_word *)((char *)(t3) + 16))) >> 4);
    return a0;
}

/* Swing_DLL.xex 0x881B1B08: call_seq u32@0x0, fn_888240B8, u32@0x0, u32@0x0, u32@0xc, u32@0x10 */
ts4_word ts4_call_seq_u32_off0_881B1B08(ts4_word a0, ts4_word a1)
{
    ts4_word t3;
    ts4_word t4;

    fn_888240B8((ts4_word)(*(ts4_word *)((char *)(a1) + 0)));
    t3 = *(ts4_word *)((char *)(a1) + 0);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)a1;
    t4 = *(ts4_word *)((char *)(t3) + 12);
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)((int)(t4 - (*(ts4_word *)((char *)(t3) + 16))) >> 4);
    return a0;
}

/* Swing_DLL.xex 0x881B31B8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88804BE8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B31B8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)72, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88804BE8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B3210: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88804BE8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B3210(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)72, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88804BE8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B7EB8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887F90F0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B7EB8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)84, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887F90F0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881B8B10: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887F13B8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881B8B10(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)272, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887F13B8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881BA1D8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887EE810 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881BA1D8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)100, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887EE810((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881BA378: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887EB298 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881BA378(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)108, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887EB298((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881BC708: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887D2F98 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_881BC708(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)56, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887D2F98((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x881C1FE0: get u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off0_881C1FE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 0))) + 28))))((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x881CBA48: call_seq fn_8819B0C8, u8@0x22, u8@0x22, u32@0x24, u32@0x24, u32@0x28 */
ts4_word ts4_call_seq_fn_8819B0C8_881CBA48(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_8819B0C8((ts4_word)(a0 + 12), (ts4_word)(a1 + 12));
    *(unsigned char *)((char *)(a0) + 34) = (unsigned char)(*(unsigned char *)((char *)(a1) + 34));
    *(ts4_word *)((char *)(a0) + 36) = (ts4_word)(*(ts4_word *)((char *)(a1) + 36));
    *(ts4_word *)((char *)(a0) + 40) = (ts4_word)(*(ts4_word *)((char *)(a1) + 40));
    *(ts4_word *)((char *)(a0) + 44) = (ts4_word)(*(ts4_word *)((char *)(a1) + 44));
    return t1;
}

/* Swing_DLL.xex 0x881CC2E8: get  */
float ts4_get_881CC2E8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(a1) + 52));
}

/* Swing_DLL.xex 0x881CC2F0: get  */
void ts4_get_881CC2F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(float *)((char *)(a1) + 52) = (*(float *)((char *)(a2) + 0));
    return;
}

/* Swing_DLL.xex 0x881DB940: fn  */
ts4_word ts4_fn_881DB940(ts4_word a0)
{
    return (a0 + 24);
}

/* Swing_DLL.xex 0x881E1B18: call_seq fn_881E19C0, fn_881DFE70 */
ts4_word ts4_call_seq_fn_881E19C0_881E1B18(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_881E19C0((ts4_word)a0);
    fn_881DFE70((ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x881E1B40: call_seq fn_881E19C0, fn_881E0258 */
ts4_word ts4_call_seq_fn_881E19C0_881E1B40(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_881E19C0((ts4_word)a0);
    fn_881E0258((ts4_word)t1);
    return 0;
}

/* Swing_DLL.xex 0x881ED520: get u32@0x0, u32@-0x10, u32@0x0, u32@0x10, vcall, u32@0x0 */
ts4_word ts4_get_u32_off0_881ED520(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;
    ts4_word t5;
    ts4_word t6;
    ts4_word t7;
    ts4_word t8;

    t2 = *(ts4_word *)((char *)((*(ts4_word *)((char *)(a1) + 0))) + -16);
    t5 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t2) + 0))) + 16))))((ts4_word)t2);
    t6 = *(ts4_word *)((char *)(a2) + 0);
    t7 = *(ts4_word *)((char *)(a1) + 0);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(t5 + 16);
    t8 = *(ts4_word *)((char *)(t6) + -12);
    fn_8819C3F0((ts4_word)a0, (ts4_word)t7, (ts4_word)(*(ts4_word *)((char *)(t7) + -12)), (ts4_word)t6, (ts4_word)t8, (ts4_word)(t5 + 16));
    return a0;
}

/* Swing_DLL.xex 0x881EDCD8: call_seq fn_881EF750, u32@0x4, fn_8818A530, u32@0x4, u32@0x0, fn_8818A530 */
ts4_word ts4_call_seq_fn_881EF750_881EDCD8(ts4_word a0)
{
    ts4_word t4;

    fn_881EF750();
    fn_8818A530((ts4_word)(*(ts4_word *)((char *)(a0) + 4)));
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    t4 = fn_8818A530((ts4_word)0);
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    return t4;
}

/* Swing_DLL.xex 0x881EDE38: call_seq fn_881EFA60, u32@0x4, fn_8818A530, u32@0x4, u32@0x0, fn_8818A530 */
ts4_word ts4_call_seq_fn_881EFA60_881EDE38(ts4_word a0)
{
    ts4_word t4;

    fn_881EFA60();
    fn_8818A530((ts4_word)(*(ts4_word *)((char *)(a0) + 4)));
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    t4 = fn_8818A530((ts4_word)0);
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    return t4;
}

/* Swing_DLL.xex 0x881EE2C8: call_seq fn_881EF198, u32@0x4, fn_8818A530, u32@0x4, u32@0x0, fn_8818A530 */
ts4_word ts4_call_seq_fn_881EF198_881EE2C8(ts4_word a0)
{
    ts4_word t4;

    fn_881EF198();
    fn_8818A530((ts4_word)(*(ts4_word *)((char *)(a0) + 4)));
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    t4 = fn_8818A530((ts4_word)0);
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    return t4;
}

/* Swing_DLL.xex 0x881FBF88: get  */
float ts4_get_881FBF88(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return (*(float *)((char *)(a1) + 68));
}

/* Swing_DLL.xex 0x88207198: set u32@0x8 */
void ts4_set_u32_off8_88207198(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x88209310: get u32@0x80 */
ts4_word ts4_get_u32_off80_88209310(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 128));
}

/* Swing_DLL.xex 0x88211570: if_call_seq u32@0x14, lbl_880EA35C, u32@0x0, fn_8857A1E0, lbl_880F799C, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off14_88211570(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 20);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880EA35C;
    if ((int)t1 != -1) {
        fn_8857A1E0((ts4_word)t1);
    }
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F799C;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x88211DD0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887CBD40 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88211DD0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)32, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887CBD40((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882121B0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887C85E0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882121B0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)204, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887C85E0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217008: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88798368 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217008(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)56, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88798368((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217288: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88793C60 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217288(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)204, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88793C60((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88217468: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88795E40 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88217468(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)84, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88795E40((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A1F0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88773390 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A1F0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)96, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88773390((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A2A0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_887732E8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A2A0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)96, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_887732E8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x8821A508: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88772FD8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8821A508(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)88, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88772FD8((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88235678: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8872A910 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88235678(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)104, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8872A910((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882356D0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88721D08 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882356D0(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)100, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88721D08((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88269E10: get u32@0x1c, u32@0x8, u8@0x0 */
void ts4_get_u32_off1c_88269E10(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(unsigned char *)((char *)(a2) + 0) = (unsigned char)(((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 28))) + 8)) - a1) == 0);
    return;
}

/* Swing_DLL.xex 0x88269EC0: get u32@0x18, u32@0x78, u32@0xe0, u8@0x0 */
void ts4_get_u32_off18_88269EC0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(unsigned char *)((char *)(a2) + 0) = (unsigned char)(((*(ts4_word *)((char *)((*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 24))) + 120))) + 224)) - a1) == 0);
    return;
}

/* Swing_DLL.xex 0x8826E908: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F4788, u32@0x1c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826E908(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(t2) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F4788;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8826EA08: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88617D88, lbl_880F47C8, u32@0x1c, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_8826EA08(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)36, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88617D88((ts4_word)t2);
        *(ts4_word *)((char *)(t2) + 28) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F47C8;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88273608: fn  */
ts4_word ts4_fn_88273608(ts4_word a0)
{
    return (a0 + 128);
}

/* Swing_DLL.xex 0x88273810: if_call_seq u32@0x4, lbl_880F50FC, u32@0x0, fn_888860A0, lbl_880F9018, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off4_88273810(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 4);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F50FC;
    fn_888860A0((ts4_word)t1);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F9018;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x882761E0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_882782A8, lbl_880F5408, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882761E0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)84, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_882782A8((ts4_word)t2);
        *(ts4_word *)((char *)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5408;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x882762E0: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88278368, lbl_880F54E0, u32@0x50, u32@0x0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882762E0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)84, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        fn_88278368((ts4_word)t2);
        *(ts4_word *)((char *)(t2) + 80) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F54E0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276CF0: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F58A8, u32@0x4, u32@0x0, u32@0xc */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276CF0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F58A8;
        *(ts4_word *)((char *)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 20) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88276DE0: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F58C0, u32@0x4, u32@0x0, u32@0xc */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88276DE0(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F58C0;
        *(ts4_word *)((char *)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 20) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88277070: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F5918, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88277070(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5918;
        *(ts4_word *)((char *)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 20) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x88277160: if_call_seq u32@lbl_88D45B38, fn_88613268, lbl_880F5930, u32@0x4, u32@0x0, u32@0x8 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88277160(void)
{
    ts4_word t2;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)24, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        *(ts4_word *)((char *)(t2) + 4) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 0) = (ts4_word)(ts4_word)lbl_880F5930;
        *(ts4_word *)((char *)(t2) + 8) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 16) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 12) = (ts4_word)0;
        *(ts4_word *)((char *)(t2) + 20) = (ts4_word)0;
        return t2;
    }
    return 0;
}

/* Swing_DLL.xex 0x8827D000: get u32@0x14, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off14_8827D000(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 20);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8827D1F0: get u32@0x28 */
ts4_word ts4_get_u32_off28_8827D1F0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 40));
}

/* Swing_DLL.xex 0x8827D278: get u32@0x4c */
ts4_word ts4_get_u32_off4c_8827D278(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 76));
}

/* Swing_DLL.xex 0x8827EC90: get u32@0x70 */
ts4_word ts4_get_u32_off70_8827EC90(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 112));
}

/* Swing_DLL.xex 0x88282450: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_8860BE40 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88282450(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)72, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_8860BE40((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88284950: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88626840 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88284950(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)160, (ts4_word)4, (ts4_word)0, (ts4_word)0);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88626840((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x882849A8: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_886214A0 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_882849A8(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)552, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_886214A0((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88285928: if_call_seq u32@lbl_88D45B38, fn_88613268, fn_88629B60 */
ts4_word ts4_if_call_seq_u32_lbl_88D45B38_88285928(void)
{
    ts4_word t2;
    ts4_word t3;

    t2 = fn_88613268((ts4_word)(*(ts4_word *)lbl_88D45B38), (ts4_word)108, (ts4_word)4, (ts4_word)0, (ts4_word)2);
    if ((ts4_word)t2 != 0) {
        t3 = fn_88629B60((ts4_word)t2);
        return t3;
    }
    return 0;
}

/* Swing_DLL.xex 0x88287088: if_call_seq u32@0x4, lbl_880F908C, u32@0x0, fn_888860A0, lbl_880F907C, u32@0x0 */
ts4_word ts4_if_call_seq_u32_off4_88287088(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 4);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F908C;
    fn_888860A0((ts4_word)t1);
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_880F907C;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
    }
    return a0;
}

/* Swing_DLL.xex 0x882911C0: tailcall fn_8857ACB8 */
ts4_word ts4_tailcall_fn_8857ACB8_882911C0(ts4_word a0, ts4_word a1)
{
    return fn_8857ACB8((ts4_word)a1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x882B0EC8: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_882B0EC8(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)0;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x882F3168: tailcall ts4_zlib_inflateInit2__882F3010 */
ts4_word ts4_tailcall_fn_882F3010_882F3168(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return ts4_zlib_inflateInit2__882F3010((ts4_word)a0, (ts4_word)15, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8831A8B8: call_seq fn_8857B830, u32@0x0 */
ts4_word ts4_call_seq_fn_8857B830_8831A8B8(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8857B830();
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)t1;
    return 0;
}

/* Swing_DLL.xex 0x8831A918: call_seq fn_8857C8C8, u32@0x0 */
ts4_word ts4_call_seq_fn_8857C8C8_8831A918(ts4_word a0)
{
    ts4_word t1;

    t1 = fn_8857C8C8();
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)t1;
    return 0;
}

/* Swing_DLL.xex 0x8831CB88: get u32@0x14, fn_88333FB0 */
ts4_word ts4_get_u32_off14_8831CB88(ts4_word a0)
{
    return fn_88333FB0((ts4_word)((*(ts4_word *)((char *)(a0) + 20)) + 22032));
}

/* Swing_DLL.xex 0x8831CB98: get u32@0x14, fn_88334128 */
ts4_word ts4_get_u32_off14_8831CB98(ts4_word a0)
{
    return fn_88334128((ts4_word)((*(ts4_word *)((char *)(a0) + 20)) + 22032));
}

/* Swing_DLL.xex 0x88320040: get u32@0x1c0, fn_8831A7F0 */
ts4_word ts4_get_u32_off1c0_88320040(ts4_word a0)
{
    return fn_8831A7F0((ts4_word)(*(ts4_word *)((char *)(a0) + 448)));
}

/* Swing_DLL.xex 0x88320048: get u32@0x1c0, fn_883E63B8 */
ts4_word ts4_get_u32_off1c0_88320048(ts4_word a0)
{
    return fn_883E63B8((ts4_word)(*(ts4_word *)((char *)(a0) + 448)));
}

/* Swing_DLL.xex 0x88325778: tailcall fn_883255A0 */
ts4_word ts4_tailcall_fn_883255A0_88325778(ts4_word a0, ts4_word a1)
{
    return fn_883255A0((ts4_word)a0, (ts4_word)a1, (ts4_word)1);
}

/* Swing_DLL.xex 0x883B1D98: set u32@0x4, u32@0x8 */
void ts4_set_u32_off4_883B1D98(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)a1;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x883E75E8: get  */
float ts4_get_883E75E8(ts4_word a0)
{
    return (*(float *)((char *)(a0) + 8));
}

/* Swing_DLL.xex 0x883E8318: get  */
float ts4_get_883E8318(ts4_word a0)
{
    return (*(float *)((char *)(a0) + 28));
}

/* Swing_DLL.xex 0x883F7300: set u32@0x0 */
ts4_word ts4_set_u32_off0_883F7300(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(ts4_word *)((char *)(a1) + 0) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x883FFAA8: get u32@0x28 */
ts4_word ts4_get_u32_off28_883FFAA8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 40));
}

/* Swing_DLL.xex 0x8841D448: get u32@0x8, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off8_8841D448(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8841ED70: tailcall fn_8841ED08 */
ts4_word ts4_tailcall_fn_8841ED08_8841ED70(ts4_word a0)
{
    return fn_8841ED08((ts4_word)a0);
}

/* Swing_DLL.xex 0x8841EF30: set u32@0x8 */
void ts4_set_u32_off8_8841EF30(ts4_word a0, ts4_word a1)
{
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)a1;
    return;
}

/* Swing_DLL.xex 0x884250A0: get u32@0x8, u8@0x0 */
void ts4_get_u32_off8_884250A0(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(a0) + 0) = (unsigned char)((*(ts4_word *)((char *)(a1) + 8)) != 0);
    return;
}

/* Swing_DLL.xex 0x884271B0: set u8@0xc */
void ts4_set_u8_offc_884271B0(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(a0) + 12) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x884271B8: get u8@0xc, u8@0x0 */
void ts4_get_u8_offc_884271B8(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(a0) + 0) = (unsigned char)(*(unsigned char *)((char *)(a1) + 12));
    return;
}

/* Swing_DLL.xex 0x88428A38: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428A38(ts4_word a0, ts4_word a1)
{
    return ((a1 << 4) + (*(ts4_word *)((char *)(a0) + 0)));
}

/* Swing_DLL.xex 0x88428A48: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428A48(ts4_word a0, ts4_word a1)
{
    return (((a1 + (a1 << 1)) << 4) + (*(ts4_word *)((char *)(a0) + 0)));
}

/* Swing_DLL.xex 0x88428A70: get u32@0x0 */
ts4_word ts4_get_u32_off0_88428A70(ts4_word a0, ts4_word a1)
{
    return (((a1 + (a1 << 1)) << 4) + (*(ts4_word *)((char *)(a0) + 0)));
}

/* Swing_DLL.xex 0x88428B20: set u32@0x0, u32@0x4 */
void ts4_set_u32_off0_88428B20(ts4_word a0, ts4_word a1, ts4_word a2)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)a1;
    *(ts4_word *)((char *)(a0) + 4) = (ts4_word)a2;
    return;
}

/* Swing_DLL.xex 0x88434EC0: tailcall fn_88434E40 */
ts4_word ts4_tailcall_fn_88434E40_88434EC0(ts4_word a0)
{
    return fn_88434E40((ts4_word)a0);
}

/* Swing_DLL.xex 0x88437D10: tailcall fn_88437D30 */
ts4_word ts4_tailcall_fn_88437D30_88437D10(ts4_word a0)
{
    return fn_88437D30((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x88437D28: tailcall fn_88437D30 */
ts4_word ts4_tailcall_fn_88437D30_88437D28(ts4_word a0)
{
    return fn_88437D30((ts4_word)(a0 + -12));
}

/* Swing_DLL.xex 0x88438660: fn  */
ts4_word ts4_fn_88438660(void)
{
    return 32;
}

/* Swing_DLL.xex 0x884392B0: addr lbl_88080084, lbl_880800A4, lbl_88080090, u32@0x14, lbl_88080078, u32@0x10 */
void ts4_addr_lbl_88080084_884392B0(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 20) = (ts4_word)(ts4_word)lbl_88080084;
    *(ts4_word *)((char *)(a0) + 16) = (ts4_word)(ts4_word)lbl_880800A4;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)(ts4_word)lbl_88080090;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)(ts4_word)lbl_88080078;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x8843A250: get u32@0x10, u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off10_8843A250(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 16);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 28))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8843B750: if_fn  */
ts4_word ts4_if_fn_8843B750(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        return (a0 + 20);
    }
    return 0;
}

/* Swing_DLL.xex 0x8843E5C8: get u32@0x4c */
ts4_word ts4_get_u32_off4c_8843E5C8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 76));
}

/* Swing_DLL.xex 0x88444890: tailcall fn_884448B0 */
ts4_word ts4_tailcall_fn_884448B0_88444890(ts4_word a0)
{
    return fn_884448B0((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x88445B08: addr lbl_88080084, lbl_880800A4, lbl_88080090, u32@0x14, lbl_88080078, u32@0x10 */
void ts4_addr_lbl_88080084_88445B08(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 20) = (ts4_word)(ts4_word)lbl_88080084;
    *(ts4_word *)((char *)(a0) + 16) = (ts4_word)(ts4_word)lbl_880800A4;
    *(ts4_word *)((char *)(a0) + 12) = (ts4_word)(ts4_word)lbl_88080090;
    *(ts4_word *)((char *)(a0) + 8) = (ts4_word)(ts4_word)lbl_88080078;
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x8844B418: get u32@0x14, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off14_8844B418(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 20);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884556E8: get u32@0xc, u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_offc_884556E8(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88460378: get u32@0xc, u32@0x0, u32@0x24 */
ts4_word ts4_get_u32_offc_88460378(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 36))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88464D40: if_fn  */
ts4_word ts4_if_fn_88464D40(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        return (a0 + 20);
    }
    return 0;
}

/* Swing_DLL.xex 0x8846A750: get u32@0x8, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off8_8846A750(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88474010: fn  */
ts4_word ts4_fn_88474010(ts4_word a0)
{
    return (a0 + 152);
}

/* Swing_DLL.xex 0x88474018: fn  */
ts4_word ts4_fn_88474018(ts4_word a0)
{
    return (a0 + 152);
}

/* Swing_DLL.xex 0x88474390: if_get u16@0x9c, u32@0x98, u32@0xa0 */
ts4_word ts4_if_get_u16_off9c_88474390(ts4_word a0, ts4_word a1)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(a0) + 156);
    if ((int)a1 < (int)t1) {
        return (*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 152))) + ((a1 + (a1 << 1)) << 4)));
    }
    return (*(ts4_word *)((char *)(((a1 - t1) << 2)) + (*(ts4_word *)((char *)(a0) + 160))));
}

/* Swing_DLL.xex 0x884743C8: if_get u16@0x9c, u32@0x98, u32@0xa0 */
ts4_word ts4_if_get_u16_off9c_884743C8(ts4_word a0, ts4_word a1)
{
    unsigned short t1;

    t1 = *(unsigned short *)((char *)(a0) + 156);
    if ((int)a1 < (int)t1) {
        return (*(ts4_word *)((char *)((*(ts4_word *)((char *)(a0) + 152))) + ((a1 + (a1 << 1)) << 4)));
    }
    return (*(ts4_word *)((char *)(((a1 - t1) << 2)) + (*(ts4_word *)((char *)(a0) + 160))));
}

/* Swing_DLL.xex 0x88478640: fn  */
ts4_word ts4_fn_88478640(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return a1;
}

/* Swing_DLL.xex 0x8847B630: fn  */
ts4_word ts4_fn_8847B630(ts4_word a0)
{
    return (a0 + 24);
}

/* Swing_DLL.xex 0x8847D158: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_8847D158(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(a2) + 4) = (ts4_word)3;
    *(ts4_word *)((char *)(a2) + 0) = (ts4_word)28;
    return;
}

/* Swing_DLL.xex 0x8847DCE8: set u8@0xc */
void ts4_set_u8_offc_8847DCE8(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(a0) + 12) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x8847DCF0: get u8@0xc, u8@0x0 */
void ts4_get_u8_offc_8847DCF0(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(a0) + 0) = (unsigned char)(*(unsigned char *)((char *)(a1) + 12));
    return;
}

/* Swing_DLL.xex 0x8847DD10: get  */
float ts4_get_8847DD10(ts4_word a0)
{
    return (*(float *)((char *)(a0) + 8));
}

/* Swing_DLL.xex 0x8847E8A0: get  */
float ts4_get_8847E8A0(ts4_word a0)
{
    return (*(float *)((char *)(a0) + 28));
}

/* Swing_DLL.xex 0x88482580: set u32@0x4, u32@0x0 */
void ts4_set_u32_off4_88482580(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    (void)a1;
    *(ts4_word *)((char *)(a2) + 4) = (ts4_word)3;
    *(ts4_word *)((char *)(a2) + 0) = (ts4_word)28;
    return;
}

/* Swing_DLL.xex 0x88493D48: tailcall fn_88493D50 */
ts4_word ts4_tailcall_fn_88493D50_88493D48(ts4_word a0)
{
    return fn_88493D50((ts4_word)(a0 + -12));
}

/* Swing_DLL.xex 0x884A1300: tailcall fn_884A1328 */
ts4_word ts4_tailcall_fn_884A1328_884A1300(ts4_word a0)
{
    return fn_884A1328((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884A1310: tailcall fn_884A1328 */
ts4_word ts4_tailcall_fn_884A1328_884A1310(ts4_word a0)
{
    return fn_884A1328((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x884A14D0: tailcall fn_884A14F8 */
ts4_word ts4_tailcall_fn_884A14F8_884A14D0(ts4_word a0)
{
    return fn_884A14F8((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884A14E0: tailcall fn_884A14F8 */
ts4_word ts4_tailcall_fn_884A14F8_884A14E0(ts4_word a0)
{
    return fn_884A14F8((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x884A1918: tailcall fn_884A1938 */
ts4_word ts4_tailcall_fn_884A1938_884A1918(ts4_word a0)
{
    return fn_884A1938((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x884AA7B8: tailcall fn_884AA7D8 */
ts4_word ts4_tailcall_fn_884AA7D8_884AA7B8(ts4_word a0)
{
    return fn_884AA7D8((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884AA7D0: tailcall fn_884AA7D8 */
ts4_word ts4_tailcall_fn_884AA7D8_884AA7D0(ts4_word a0)
{
    return fn_884AA7D8((ts4_word)(a0 + -44));
}

/* Swing_DLL.xex 0x884AB850: tailcall fn_884AB860 */
ts4_word ts4_tailcall_fn_884AB860_884AB850(ts4_word a0)
{
    return fn_884AB860((ts4_word)(a0 + -44));
}

/* Swing_DLL.xex 0x884B0FE8: tailcall fn_884B1008 */
ts4_word ts4_tailcall_fn_884B1008_884B0FE8(ts4_word a0)
{
    return fn_884B1008((ts4_word)(a0 + -32));
}

/* Swing_DLL.xex 0x884B1000: tailcall fn_884B1008 */
ts4_word ts4_tailcall_fn_884B1008_884B1000(ts4_word a0)
{
    return fn_884B1008((ts4_word)(a0 + -44));
}

/* Swing_DLL.xex 0x884B22F8: tailcall fn_884B2308 */
ts4_word ts4_tailcall_fn_884B2308_884B22F8(ts4_word a0)
{
    return fn_884B2308((ts4_word)(a0 + -44));
}

/* Swing_DLL.xex 0x884BB5E8: set  */
void ts4_set_884BB5E8(ts4_word a0, float f1)
{
    *(float *)((char *)(a0) + 4) = f1;
    return;
}

/* Swing_DLL.xex 0x884C0040: get  */
float ts4_get_884C0040(ts4_word a0)
{
    return (*(float *)((char *)(a0) + 28));
}

/* Swing_DLL.xex 0x884D11E0: get u32@0x8, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off8_884D11E0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 8);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)((*(ts4_word *)((char *)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884D33C8: fn  */
ts4_word ts4_fn_884D33C8(ts4_word a0, ts4_word a1)
{
    (void)a0;
    return a1;
}

/* Swing_DLL.xex 0x884DCDD0: fn  */
ts4_word ts4_fn_884DCDD0(ts4_word a0, ts4_word a1)
{
    return (a0 + a1);
}

/* Swing_DLL.xex 0x884E2168: fn  */
ts4_word ts4_fn_884E2168(ts4_word a0)
{
    return (a0 + 112);
}

/* Swing_DLL.xex 0x884E5160: fn  */
ts4_word ts4_fn_884E5160(ts4_word a0)
{
    return (a0 + 112);
}

/* Swing_DLL.xex 0x884E5168: fn  */
ts4_word ts4_fn_884E5168(ts4_word a0)
{
    return (a0 + 128);
}

/* Swing_DLL.xex 0x884E5820: get u32@0x80 */
ts4_word ts4_get_u32_off80_884E5820(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 128));
}

/* Swing_DLL.xex 0x884EBB98: tailcall fn_884EBBC0 */
ts4_word ts4_tailcall_fn_884EBBC0_884EBB98(ts4_word a0)
{
    return fn_884EBBC0((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884EFFF0: tailcall NetDll_XNetQosRelease */
ts4_word ts4_tailcall_NetDll_XNetQosRelease_884EFFF0(ts4_word a0)
{
    return NetDll_XNetQosRelease((ts4_word)1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x884F0000: tailcall NetDll_XNetGetTitleXnAddr */
ts4_word ts4_tailcall_NetDll_XNetGetTitleXnAddr_884F0000(ts4_word a0)
{
    return NetDll_XNetGetTitleXnAddr((ts4_word)1, (ts4_word)a0);
}

/* Swing_DLL.xex 0x88503A58: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_88503A58(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)((*(ts4_word *)((char *)(a0) + 0)) + -16);
    return;
}

/* Swing_DLL.xex 0x88503E58: get u32@0x0, u32@0x0 */
void ts4_get_u32_off0_88503E58(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 0) = (ts4_word)((*(ts4_word *)((char *)(a0) + 0)) + -16);
    return;
}

/* Swing_DLL.xex 0x88516458: get  */
void ts4_get_88516458(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(a1) + 0) = (*(float *)((char *)(a0) + 0));
    *(float *)((char *)(a1) + 4) = (*(float *)((char *)(a0) + 4));
    *(float *)((char *)(a1) + 8) = (*(float *)((char *)(a0) + 8));
    *(float *)((char *)(a1) + 12) = (*(float *)((char *)(a0) + 12));
    return;
}

/* Swing_DLL.xex 0x88516B20: get  */
void ts4_get_88516B20(ts4_word a0, ts4_word a1)
{
    *(float *)((char *)(a1) + 0) = (*(float *)((char *)(a0) + 0));
    *(float *)((char *)(a1) + 4) = (*(float *)((char *)(a0) + 4));
    *(float *)((char *)(a1) + 8) = (*(float *)((char *)(a0) + 8));
    *(float *)((char *)(a1) + 12) = (*(float *)((char *)(a0) + 12));
    return;
}

/* Swing_DLL.xex 0x88522458: tailcall fn_885223F0 */
ts4_word ts4_tailcall_fn_885223F0_88522458(ts4_word a0)
{
    return fn_885223F0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88522C40: tailcall fn_88522BC0 */
ts4_word ts4_tailcall_fn_88522BC0_88522C40(ts4_word a0)
{
    return fn_88522BC0((ts4_word)a0);
}

/* Swing_DLL.xex 0x88596010: tailcall fn_885949C0 */
ts4_word ts4_tailcall_fn_885949C0_88596010(ts4_word a0)
{
    return fn_885949C0((ts4_word)(a0 + 8));
}

/* Swing_DLL.xex 0x885A5060: get u32@0x44, fn_885B5740 */
ts4_word ts4_get_u32_off44_885A5060(ts4_word a0)
{
    return fn_885B5740((ts4_word)(*(ts4_word *)((char *)(a0) + 68)));
}

/* Swing_DLL.xex 0x885A6E30: tailcall fn_885A6E08 */
ts4_word ts4_tailcall_fn_885A6E08_885A6E30(ts4_word a0)
{
    return fn_885A6E08((ts4_word)(a0 + -36));
}

/* Swing_DLL.xex 0x885A6E40: tailcall fn_885A6C48 */
ts4_word ts4_tailcall_fn_885A6C48_885A6E40(ts4_word a0)
{
    return fn_885A6C48((ts4_word)(a0 + -36));
}

/* Swing_DLL.xex 0x885A7318: tailcall ts4_forward_885A9E30 */
ts4_word ts4_tailcall_ts4_forward_885A9E30_885A7318(ts4_word a0)
{
    return ts4_forward_885A9E30((ts4_word)(a0 + -36));
}

/* Swing_DLL.xex 0x885B9118: set u32@0x0 */
ts4_word ts4_set_u32_off0_885B9118(ts4_word a0, ts4_word a1)
{
    (void)a0;
    *(ts4_word *)((char *)(a1) + 0) = (ts4_word)0;
    return 0;
}

/* Swing_DLL.xex 0x885CE5D8: set u32@0x74 */
void ts4_set_u32_off74_885CE5D8(ts4_word a0)
{
    *(ts4_word *)((char *)(a0) + 116) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x885E9378: if_call_seq u32@0x0, fn_8857A1E0, u32@0x0 */
void ts4_if_call_seq_u32_off0_885E9378(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        fn_8857A1E0((ts4_word)t1);
        *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x885E9498: if_call_seq u32@0x0, fn_8857A1E0, u32@0x0 */
void ts4_if_call_seq_u32_off0_885E9498(ts4_word a0)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(a0) + 0);
    if ((ts4_word)t1 != 0) {
        fn_8857A1E0((ts4_word)t1);
        *(ts4_word *)((char *)(a0) + 0) = (ts4_word)0;
    }
    return;
}

/* Swing_DLL.xex 0x885EAD78: get u32@0x0, fn_8857C040 */
ts4_word ts4_get_u32_off0_885EAD78(ts4_word a0, ts4_word a1)
{
    return fn_8857C040((ts4_word)(*(ts4_word *)((char *)(a0) + 0)), (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x885EAD98: get u32@0x0, fn_8857C040 */
ts4_word ts4_get_u32_off0_885EAD98(ts4_word a0, ts4_word a1)
{
    return fn_8857C040((ts4_word)(*(ts4_word *)((char *)(a0) + 0)), (ts4_word)a1, (ts4_word)0);
}

/* Swing_DLL.xex 0x885F49A8: if_call_seq u32@0x18, u32@0x8, fn_88470AD0, u32@0x18, fn_88475B08, u32@0x18 */
void ts4_if_call_seq_u32_off18_885F49A8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(a0) + 24);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(a0) + 8);
        if ((int)t2 != 0) {
            fn_88470AD0((ts4_word)t2, (ts4_word)a0, (ts4_word)t1);
        }
        fn_88475B08((ts4_word)(*(ts4_word *)((char *)(a0) + 24)));
        *(ts4_word *)((char *)(a0) + 24) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(a0) + 24) = (ts4_word)a1;
    fn_88475AE8((ts4_word)a1);
    t7 = *(ts4_word *)((char *)(a0) + 8);
    if ((int)t7 != 0) {
        fn_8846C2A8((ts4_word)t7, (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(a0) + 24)));
    }
    return;
}

/* Swing_DLL.xex 0x885F4C88: if_call_seq u32@0x18, u32@0x8, fn_88470AD0, u32@0x18, fn_88475B08, u32@0x18 */
void ts4_if_call_seq_u32_off18_885F4C88(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t7;

    t1 = *(ts4_word *)((char *)(a0) + 24);
    if ((ts4_word)t1 != 0) {
        t2 = *(ts4_word *)((char *)(a0) + 8);
        if ((int)t2 != 0) {
            fn_88470AD0((ts4_word)t2, (ts4_word)a0, (ts4_word)t1);
        }
        fn_88475B08((ts4_word)(*(ts4_word *)((char *)(a0) + 24)));
        *(ts4_word *)((char *)(a0) + 24) = (ts4_word)0;
    }
    *(ts4_word *)((char *)(a0) + 24) = (ts4_word)a1;
    fn_88475AE8((ts4_word)a1);
    t7 = *(ts4_word *)((char *)(a0) + 8);
    if ((int)t7 != 0) {
        fn_8846C2A8((ts4_word)t7, (ts4_word)a0, (ts4_word)(*(ts4_word *)((char *)(a0) + 24)));
    }
    return;
}

/* Swing_DLL.xex 0x885F52A8: set u64@0x10 */
ts4_word ts4_set_u64_off10_885F52A8(ts4_word a0, ts4_u64 a1)
{
    *(ts4_u64 *)((char *)(a0) + 16) = (ts4_u64)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F52C8: set u64@0x10 */
ts4_word ts4_set_u64_off10_885F52C8(ts4_word a0, ts4_u64 a1)
{
    *(ts4_u64 *)((char *)(a0) + 16) = (ts4_u64)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F5330: set u64@0x10 */
ts4_word ts4_set_u64_off10_885F5330(ts4_word a0, ts4_u64 a1)
{
    *(ts4_u64 *)((char *)(a0) + 16) = (ts4_u64)a1;
    return 1;
}

/* Swing_DLL.xex 0x885F53C8: get u16@0x30 */
ts4_word ts4_get_u16_off30_885F53C8(ts4_word a0)
{
    return (*(unsigned short *)((char *)(a0) + 48));
}

/* Swing_DLL.xex 0x885F53D0: get u16@0x2e */
ts4_word ts4_get_u16_off2e_885F53D0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(a0) + 46));
}

/* Swing_DLL.xex 0x885F53E0: get u16@0x2a */
ts4_word ts4_get_u16_off2a_885F53E0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(a0) + 42));
}

/* Swing_DLL.xex 0x885F53F0: get u16@0x26 */
ts4_word ts4_get_u16_off26_885F53F0(ts4_word a0)
{
    return (*(unsigned short *)((char *)(a0) + 38));
}

/* Swing_DLL.xex 0x885F59D8: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F59D8(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(a0) + 16)) + 14);
}

/* Swing_DLL.xex 0x885F5A70: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F5A70(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(a0) + 16)) + 14);
}

/* Swing_DLL.xex 0x885F6080: get u32@0x10 */
ts4_word ts4_get_u32_off10_885F6080(ts4_word a0)
{
    return ((*(ts4_word *)((char *)(a0) + 16)) + 14);
}

/* Swing_DLL.xex 0x885F94B0: get u32@0x40 */
ts4_word ts4_get_u32_off40_885F94B0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(a0) + 64));
}
