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

extern char fn_88434F80[];
extern char fn_88455760[];
extern char fn_884557A8[];
extern char fn_88456710[];
extern char fn_88458FD8[];
extern char fn_8845A400[];
extern char fn_8845A498[];
extern char fn_8845C208[];
extern char lbl_88001A20[];
extern char lbl_8803A308[];
extern char lbl_880410E4[];
extern char lbl_88041AA4[];
extern char lbl_88041AE8[];
extern char lbl_8807FEDC[];
extern char lbl_8807FF50[];
extern char lbl_8807FF74[];
extern char lbl_8807FF98[];
extern char lbl_8808001C[];
extern char lbl_88080078[];
extern char lbl_88080084[];
extern char lbl_88080090[];
extern char lbl_880800A4[];
extern char lbl_8808019C[];
extern char lbl_8808029C[];
extern char lbl_8808030C[];
extern char lbl_8808039C[];
extern char lbl_88080410[];
extern char lbl_880804FC[];
extern char lbl_8808062C[];
extern char lbl_880807A4[];
extern char lbl_880807C8[];
extern char lbl_88080AD8[];
extern char lbl_88080B6C[];
extern char lbl_88080BC4[];
extern char lbl_88080C84[];
extern char lbl_88080CE4[];
extern char lbl_88080D04[];
extern char lbl_88080DB0[];
extern char lbl_88080E0C[];
extern char lbl_8808109C[];
extern char lbl_8808113C[];
extern char lbl_880811AC[];
extern char lbl_88081250[];
extern char lbl_8808129C[];
extern char lbl_880818B0[];
extern char lbl_880818F0[];
extern char lbl_88081990[];
extern char lbl_88081B14[];
extern char lbl_88081D80[];
extern char lbl_88081D9C[];
extern char lbl_88081DE4[];
extern char lbl_88081E00[];
extern char lbl_88081E10[];
extern char lbl_88081EE4[];
extern char lbl_88081F60[];
extern char lbl_88082034[];
extern char lbl_880820E8[];
extern char lbl_880824E0[];
extern char lbl_880827A8[];
extern char lbl_880829C4[];
extern char lbl_88082A00[];
extern char lbl_88082A64[];
extern char lbl_88C21EE0[];
extern char lbl_88CACF08[];
ts4_word KeTlsGetValue();
ts4_word fn_8841A510();
ts4_word fn_8841A590();
ts4_word fn_884350B0();
ts4_word fn_88435198();
ts4_word fn_88435378();
ts4_word ts4_ref_holder_dtor_88436F58();
ts4_word fn_88437790();
ts4_word fn_88437A70();
ts4_word fn_88437BB0();
ts4_word fn_88437D30();
ts4_word ts4_ref_holder_dtor_88437EE8();
ts4_word fn_88438270();
ts4_word fn_884384B8();
ts4_word ts4_ref_holder_dtor_member_8843A1C8();
ts4_word fn_8843B590();
ts4_word fn_8843C100();
ts4_word fn_8843C1E0();
ts4_word fn_8843CAF8();
ts4_word fn_8843F5E0();
ts4_word fn_88440A08();
ts4_word fn_88441E80();
ts4_word fn_88443038();
ts4_word fn_884430E8();
ts4_word fn_88443170();
ts4_word fn_88444778();
ts4_word fn_884464C0();
ts4_word fn_88446EE0();
ts4_word fn_88447F20();
ts4_word fn_88448048();
ts4_word fn_88448320();
ts4_word fn_88448DF8();
ts4_word fn_8844BB30();
ts4_word fn_8844CF28();
ts4_word fn_8844D060();
ts4_word fn_8844D990();
ts4_word fn_8844DE78();
ts4_word fn_8844ECB0();
ts4_word fn_8844EF88();
ts4_word fn_88452650();
ts4_word fn_88452CA0();
ts4_word fn_88453940();
ts4_word fn_88453B08();
ts4_word fn_884555E8();
ts4_word fn_884557F8();
ts4_word fn_884568A8();
ts4_word fn_88457488();
ts4_word fn_88457608();
ts4_word fn_884588B0();
ts4_word fn_88459F18();
ts4_word fn_8845B140();
ts4_word fn_8845C138();
ts4_word fn_8845CF60();
ts4_word fn_8845DFF8();
ts4_word fn_8845EDC8();
ts4_word fn_8845F690();
ts4_word fn_8845F838();
ts4_word fn_88461E10();
ts4_word fn_885219D0();
ts4_word fn_885221B8();
ts4_word fn_88522A00();
ts4_word fn_88522EF8();
ts4_word fn_88523E08();
ts4_word fn_88524710();
ts4_word fn_8852C9F0();
ts4_word fn_8852CB30();
ts4_word fn_8852DD38();
ts4_word fn_8852E0C0();
ts4_word fn_88537FC8();
ts4_word ts4_tsu_cleanup_end();

/* Swing_DLL.xex 0x884372E0: if_call_seq fn_8843B590, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8843B590_884372E0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8843B590();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x884373B8: if_call_seq fn_8843C100, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8843C100_884373B8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8843C100();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x884374A0: if_call_seq lbl_8807FF50, lbl_8803A308, u32@0x10, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue */
ts4_word ts4_if_call_seq_lbl_8807FF50_884374A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_8807FF50;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88437518: if_call_seq fn_8843CAF8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8843CAF8_88437518(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8843CAF8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x884383D8: if_call_seq fn_884464C0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884464C0_884383D8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884464C0((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)40);
    }
    return a0;
}

/* Swing_DLL.xex 0x88438568: if_call_seq fn_884384B8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_884384B8_88438568(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_884384B8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88438E68: if_call_seq fn_8844BB30, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8844BB30_88438E68(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8844BB30((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88439A48: addr lbl_8803A308, u32@0x0 */
void ts4_addr_lbl_8803A308_88439A48(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x8843AF20: if_call_seq lbl_88080084, lbl_880800A4, lbl_88080090, u32@0x14, lbl_88080078, u32@0x10 */
ts4_word ts4_if_call_seq_lbl_88080084_8843AF20(ts4_word a0, ts4_word a1)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 20) = (ts4_word)(ts4_word)lbl_88080084;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_880800A4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)lbl_88080090;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)lbl_88080078;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x884425D8: if_call_seq fn_88441E80, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88441E80_884425D8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88441E80();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x884431F0: if_call_seq fn_88437BB0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88437BB0_884431F0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88437BB0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88444A98: call_seq lbl_88080AD8, u32@0x0, ts4_ref_holder_dtor_88436F58, ts4_ref_holder_dtor_88437EE8 */
ts4_word ts4_call_seq_lbl_88080AD8_88444A98(ts4_word a0)
{
    ts4_word t2;

    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080AD8;
    ts4_ref_holder_dtor_88436F58((ts4_word)(a0 + 48));
    t2 = ts4_ref_holder_dtor_88437EE8((ts4_word)a0);
    return t2;
}

/* Swing_DLL.xex 0x884481F8: if_call_seq fn_88446EE0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88446EE0_884481F8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88446EE0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88448F90: if_call_seq fn_88448320, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88448320_88448F90(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88448320();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88449008: addr lbl_8803A308, u32@0x0 */
void ts4_addr_lbl_8803A308_88449008(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    return;
}

/* Swing_DLL.xex 0x8844BAA0: get u32@0x18 */
ts4_word ts4_get_u32_off18_8844BAA0(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 24));
}

