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
ts4_word fn_88436F58();
ts4_word ts4_if_call_seq_fn_8843B590_884372E0();
ts4_word ts4_if_call_seq_fn_8843C100_884373B8();
ts4_word ts4_if_call_seq_lbl_8807FF50_884374A0();
ts4_word ts4_if_call_seq_fn_8843CAF8_88437518();
ts4_word fn_88437790();
ts4_word fn_88437A70();
ts4_word fn_88437BB0();
ts4_word fn_88437D30();
ts4_word fn_88437EE8();
ts4_word fn_88438270();
ts4_word ts4_if_call_seq_fn_884464C0_884383D8();
ts4_word fn_884384B8();
ts4_word ts4_if_call_seq_fn_884384B8_88438568();
ts4_word ts4_if_call_seq_fn_8844BB30_88438E68();
ts4_word ts4_addr_lbl_8803A308_88439A48();
ts4_word fn_8843A1C8();
ts4_word ts4_if_call_seq_lbl_88080084_8843AF20();
ts4_word fn_8843B590();
ts4_word fn_8843C100();
ts4_word fn_8843C1E0();
ts4_word fn_8843CAF8();
ts4_word fn_8843F5E0();
ts4_word fn_88440A08();
ts4_word fn_88441E80();
ts4_word ts4_if_call_seq_fn_88441E80_884425D8();
ts4_word fn_88443038();
ts4_word fn_884430E8();
ts4_word fn_88443170();
ts4_word ts4_if_call_seq_fn_88437BB0_884431F0();
ts4_word fn_88444778();
ts4_word ts4_call_seq_lbl_88080AD8_88444A98();
ts4_word fn_884464C0();
ts4_word fn_88446EE0();
ts4_word fn_88447F20();
ts4_word fn_88448048();
ts4_word ts4_if_call_seq_fn_88446EE0_884481F8();
ts4_word fn_88448320();
ts4_word fn_88448DF8();
ts4_word ts4_if_call_seq_fn_88448320_88448F90();
ts4_word ts4_addr_lbl_8803A308_88449008();
ts4_word ts4_get_u32_off18_8844BAA0();
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

/* Swing_DLL.xex 0x88435218: call_seq fn_88435198, fn_88434F80, lbl_880410E4, fn_884350B0 */
ts4_word ts4_call_seq_fn_88435198_88435218(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    fn_88435198((ts4_word)a0, (ts4_word)a1);
    t2 = fn_884350B0((ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)(ts4_word)lbl_880410E4, (ts4_word)(ts4_word)fn_88434F80);
    return t2;
}

/* Swing_DLL.xex 0x88435260: tailcall fn_88435198 */
ts4_word ts4_tailcall_fn_88435198_88435260(ts4_word a0)
{
    return fn_88435198((ts4_word)a0);
}

/* Swing_DLL.xex 0x884354E8: addr lbl_88041AE8, fn_88435378 */
ts4_word ts4_addr_lbl_88041AE8_884354E8(ts4_word a0, ts4_word a1)
{
    return fn_88435378((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AE8, (ts4_word)1);
}

/* Swing_DLL.xex 0x884354F8: addr lbl_88041AA4, fn_88435378 */
ts4_word ts4_addr_lbl_88041AA4_884354F8(ts4_word a0, ts4_word a1)
{
    return fn_88435378((ts4_word)a0, (ts4_word)a1, (ts4_word)(ts4_word)lbl_88041AA4, (ts4_word)0);
}

/* Swing_DLL.xex 0x88436E00: if_addr lbl_8807FEDC, u16@0x6, u32@0x0, u32@0xc */
void ts4_if_addr_lbl_8807FEDC_88436E00(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8807FEDC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)5;
    return;
}

/* Swing_DLL.xex 0x88436E28: addr lbl_8807FEDC */
ts4_word ts4_addr_lbl_8807FEDC_88436E28(void)
{
    return (ts4_word)lbl_8807FEDC;
}

/* Swing_DLL.xex 0x88436E40: if_call_seq ts4_addr_lbl_8803A308_88439A48, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88439A48_88436E40(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_addr_lbl_8803A308_88439A48((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88436EA8: if_call_seq lbl_8807FF50, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_8807FF50_88436EA8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8807FF50;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88436F40: addr lbl_8807FF98 */
ts4_word ts4_addr_lbl_8807FF98_88436F40(void)
{
    return (ts4_word)lbl_8807FF98;
}

/* Swing_DLL.xex 0x88436F50: fn  */
ts4_word ts4_fn_88436F50(void)
{
    return -1;
}

/* Swing_DLL.xex 0x88436FD8: call_seq fn_88436F58 */
ts4_word ts4_call_seq_fn_88436F58_88436FD8(ts4_word a0)
{
    fn_88436F58((ts4_word)a0);
    return a0;
}

/* Swing_DLL.xex 0x88437008: if_call_seq fn_8843A1C8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8843A1C8_88437008(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8843A1C8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88437088: if_addr lbl_8808001C, u16@0x6, u32@0x0, u32@0xc */
void ts4_if_addr_lbl_8808001C_88437088(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808001C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)6;
    return;
}

/* Swing_DLL.xex 0x884370B0: addr lbl_8808001C */
ts4_word ts4_addr_lbl_8808001C_884370B0(void)
{
    return (ts4_word)lbl_8808001C;
}

/* Swing_DLL.xex 0x884370C0: fn  */
ts4_word ts4_fn_884370C0(void)
{
    return 64;
}

/* Swing_DLL.xex 0x884370C8: if_call_seq lbl_88080078, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88080078_884370C8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080078;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88437110: if_call_seq lbl_88080084, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88080084_88437110(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080084;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x88437158: if_call_seq lbl_88080090, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88080090_88437158(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080090;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884371A0: if_call_seq lbl_880800A4, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_880800A4_884371A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880800A4;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884372C8: tailcall ts4_if_call_seq_fn_8843B590_884372E0 */
ts4_word ts4_tailcall_fn_884372E0_884372C8(ts4_word a0)
{
    return ts4_if_call_seq_fn_8843B590_884372E0((ts4_word)(a0 + -12));
}

/* Swing_DLL.xex 0x884372D0: tailcall ts4_if_call_seq_fn_8843B590_884372E0 */
ts4_word ts4_tailcall_fn_884372E0_884372D0(ts4_word a0)
{
    return ts4_if_call_seq_fn_8843B590_884372E0((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x884372D8: tailcall ts4_if_call_seq_fn_8843B590_884372E0 */
ts4_word ts4_tailcall_fn_884372E0_884372D8(ts4_word a0)
{
    return ts4_if_call_seq_fn_8843B590_884372E0((ts4_word)(a0 + -20));
}

/* Swing_DLL.xex 0x884373A0: addr lbl_8808019C */
ts4_word ts4_addr_lbl_8808019C_884373A0(void)
{
    return (ts4_word)lbl_8808019C;
}

/* Swing_DLL.xex 0x884373B0: tailcall ts4_if_call_seq_fn_8843C100_884373B8 */
ts4_word ts4_tailcall_fn_884373B8_884373B0(ts4_word a0)
{
    return ts4_if_call_seq_fn_8843C100_884373B8((ts4_word)(a0 + -20));
}

/* Swing_DLL.xex 0x88437478: addr lbl_8808029C */
ts4_word ts4_addr_lbl_8808029C_88437478(void)
{
    return (ts4_word)lbl_8808029C;
}

/* Swing_DLL.xex 0x88437488: get u8@0x4 */
ts4_word ts4_get_u8_off4_88437488(ts4_word a0)
{
    return ((*(unsigned char *)((char *)(ts4_word)(a0) + 4)) == 0);
}

/* Swing_DLL.xex 0x88437498: tailcall ts4_if_call_seq_lbl_8807FF50_884374A0 */
ts4_word ts4_tailcall_fn_884374A0_88437498(ts4_word a0)
{
    return ts4_if_call_seq_lbl_8807FF50_884374A0((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x88437510: tailcall ts4_if_call_seq_fn_8843CAF8_88437518 */
ts4_word ts4_tailcall_fn_88437518_88437510(ts4_word a0)
{
    return ts4_if_call_seq_fn_8843CAF8_88437518((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x884375D0: addr lbl_8808030C */
ts4_word ts4_addr_lbl_8808030C_884375D0(void)
{
    return (ts4_word)lbl_8808030C;
}

/* Swing_DLL.xex 0x88437670: if_call_seq fn_88436F58, lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4 */
ts4_word ts4_if_call_seq_fn_88436F58_88437670(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88436F58((ts4_word)(a0 + 20));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88437738: addr lbl_8808039C */
ts4_word ts4_addr_lbl_8808039C_88437738(void)
{
    return (ts4_word)lbl_8808039C;
}

/* Swing_DLL.xex 0x88437760: if_addr lbl_88080410, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_88080410_88437760(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080410;
    return;
}

/* Swing_DLL.xex 0x88437780: addr lbl_88080410 */
ts4_word ts4_addr_lbl_88080410_88437780(void)
{
    return (ts4_word)lbl_88080410;
}

/* Swing_DLL.xex 0x88437810: if_call_seq fn_88437790, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88437790_88437810(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88437790();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88437898: if_addr lbl_880804FC, u16@0x6, u32@0x0, u32@0xc */
void ts4_if_addr_lbl_880804FC_88437898(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880804FC;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)7;
    return;
}

/* Swing_DLL.xex 0x884378C0: addr lbl_880804FC */
ts4_word ts4_addr_lbl_880804FC_884378C0(void)
{
    return (ts4_word)lbl_880804FC;
}

/* Swing_DLL.xex 0x884378D0: if_call_seq fn_8843F5E0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8843F5E0_884378D0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8843F5E0();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x884379B0: if_addr lbl_8808062C, u16@0x6, u32@0x0 */
void ts4_if_addr_lbl_8808062C_884379B0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808062C;
    return;
}

/* Swing_DLL.xex 0x884379D0: addr lbl_8808062C */
ts4_word ts4_addr_lbl_8808062C_884379D0(void)
{
    return (ts4_word)lbl_8808062C;
}

/* Swing_DLL.xex 0x88437A68: tailcall fn_88437A70 */
ts4_word ts4_tailcall_fn_88437A70_88437A68(ts4_word a0)
{
    return fn_88437A70((ts4_word)a0, (ts4_word)0);
}

/* Swing_DLL.xex 0x88437B28: if_call_seq fn_884430E8, lbl_880807C8, lbl_880807A4, u32@0x0, u32@0x10, u32@0xc */
ts4_word ts4_if_call_seq_fn_884430E8_88437B28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p2;
    ts4_word t1;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    p2 = (ts4_word)a0;
    if ((ts4_word)a0 != 0) {
        t1 = fn_884430E8((ts4_word)a0, (ts4_word)1);
        *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880807C8;
        *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_880807A4;
        *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)22;
        p2 = (ts4_word)t1;
    }
    return p2;
}

/* Swing_DLL.xex 0x88437D18: tailcall fn_88437D30 */
ts4_word ts4_tailcall_fn_88437D30_88437D18(ts4_word a0)
{
    return fn_88437D30((ts4_word)(a0 + -20));
}

/* Swing_DLL.xex 0x88437D20: tailcall fn_88437D30 */
ts4_word ts4_tailcall_fn_88437D30_88437D20(ts4_word a0)
{
    return fn_88437D30((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x88437ED8: addr lbl_88080AD8 */
ts4_word ts4_addr_lbl_88080AD8_88437ED8(void)
{
    return (ts4_word)lbl_88080AD8;
}

/* Swing_DLL.xex 0x88437F68: if_call_seq fn_88437EE8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88437EE8_88437F68(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88437EE8((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88437FD0: get u32@0x34, u32@0x0, u32@0x14 */
ts4_word ts4_get_u32_off34_88437FD0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 20))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88437FE8: if_call_seq ts4_call_seq_lbl_88080AD8_88444A98, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88444A98_88437FE8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_call_seq_lbl_88080AD8_88444A98((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88438070: if_addr lbl_88080B6C, u16@0x6, u32@0x0, u32@0xc */
void ts4_if_addr_lbl_88080B6C_88438070(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080B6C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)23;
    return;
}

/* Swing_DLL.xex 0x88438098: addr lbl_88080B6C */
ts4_word ts4_addr_lbl_88080B6C_88438098(void)
{
    return (ts4_word)lbl_88080B6C;
}

/* Swing_DLL.xex 0x88438140: if_addr lbl_88080BC4, u16@0x6, u32@0x0, u32@0xc */
void ts4_if_addr_lbl_88080BC4_88438140(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080BC4;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)20;
    return;
}

/* Swing_DLL.xex 0x88438168: addr lbl_88080BC4 */
ts4_word ts4_addr_lbl_88080BC4_88438168(void)
{
    return (ts4_word)lbl_88080BC4;
}

/* Swing_DLL.xex 0x88438250: tailcall fn_88438270 */
ts4_word ts4_tailcall_fn_88438270_88438250(ts4_word a0)
{
    return fn_88438270((ts4_word)(a0 + -20));
}

/* Swing_DLL.xex 0x88438258: tailcall fn_88438270 */
ts4_word ts4_tailcall_fn_88438270_88438258(ts4_word a0)
{
    return fn_88438270((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x88438268: tailcall fn_88438270 */
ts4_word ts4_tailcall_fn_88438270_88438268(ts4_word a0)
{
    return fn_88438270((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x884382F0: if_addr lbl_88080C84, u16@0x6, u32@0x0, u32@0xc */
void ts4_if_addr_lbl_88080C84_884382F0(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080C84;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)27;
    return;
}

/* Swing_DLL.xex 0x88438318: addr lbl_88080C84 */
ts4_word ts4_addr_lbl_88080C84_88438318(void)
{
    return (ts4_word)lbl_88080C84;
}

/* Swing_DLL.xex 0x88438328: if_call_seq lbl_88080CE4, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88080CE4_88438328(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080CE4;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x884383C0: addr lbl_88080D04 */
ts4_word ts4_addr_lbl_88080D04_884383C0(void)
{
    return (ts4_word)lbl_88080D04;
}

/* Swing_DLL.xex 0x884383D0: tailcall ts4_if_call_seq_fn_884464C0_884383D8 */
ts4_word ts4_tailcall_fn_884383D8_884383D0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884464C0_884383D8((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x884384A0: addr lbl_88080DB0 */
ts4_word ts4_addr_lbl_88080DB0_884384A0(void)
{
    return (ts4_word)lbl_88080DB0;
}

/* Swing_DLL.xex 0x884384B0: tailcall ts4_if_call_seq_fn_884384B8_88438568 */
ts4_word ts4_tailcall_fn_88438568_884384B0(ts4_word a0)
{
    return ts4_if_call_seq_fn_884384B8_88438568((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x884385E8: if_addr lbl_8807FF74, u32@0x0 */
void ts4_if_addr_lbl_8807FF74_884385E8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8807FF74;
    return;
}

/* Swing_DLL.xex 0x88438600: addr lbl_8807FF74 */
ts4_word ts4_addr_lbl_8807FF74_88438600(void)
{
    return (ts4_word)lbl_8807FF74;
}

/* Swing_DLL.xex 0x88438628: if_addr lbl_88080E0C, u16@0x6, u32@0x0, u32@0xc */
void ts4_if_addr_lbl_88080E0C_88438628(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080E0C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)2;
    return;
}

/* Swing_DLL.xex 0x88438650: addr lbl_88080E0C */
ts4_word ts4_addr_lbl_88080E0C_88438650(void)
{
    return (ts4_word)lbl_88080E0C;
}

/* Swing_DLL.xex 0x88438860: if_addr lbl_8808109C, u16@0x6, u32@0x0, u32@0xc */
void ts4_if_addr_lbl_8808109C_88438860(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808109C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)14;
    return;
}

/* Swing_DLL.xex 0x88438888: addr lbl_8808109C */
ts4_word ts4_addr_lbl_8808109C_88438888(void)
{
    return (ts4_word)lbl_8808109C;
}

/* Swing_DLL.xex 0x88438898: if_call_seq ts4_addr_lbl_8803A308_88449008, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88449008_88438898(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    ts4_addr_lbl_8803A308_88449008((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88438900: get u8@0x6c, u8@0x0 */
void ts4_get_u8_off6c_88438900(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(*(unsigned char *)((char *)(ts4_word)(a1) + 108));
    return;
}

/* Swing_DLL.xex 0x88438D10: addr lbl_8808113C */
ts4_word ts4_addr_lbl_8808113C_88438D10(void)
{
    return (ts4_word)lbl_8808113C;
}

/* Swing_DLL.xex 0x88438D70: addr lbl_880811AC */
ts4_word ts4_addr_lbl_880811AC_88438D70(void)
{
    return (ts4_word)lbl_880811AC;
}

/* Swing_DLL.xex 0x88438D80: if_call_seq fn_88436F58, lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4 */
ts4_word ts4_if_call_seq_fn_88436F58_88438D80(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88436F58((ts4_word)(a0 + 16));
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88438E50: addr lbl_88081250 */
ts4_word ts4_addr_lbl_88081250_88438E50(void)
{
    return (ts4_word)lbl_88081250;
}

/* Swing_DLL.xex 0x88438E60: tailcall ts4_if_call_seq_fn_8844BB30_88438E68 */
ts4_word ts4_tailcall_fn_88438E68_88438E60(ts4_word a0)
{
    return ts4_if_call_seq_fn_8844BB30_88438E68((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x88438EE8: if_addr lbl_8808129C, u16@0x6, u32@0x0, u32@0xc */
void ts4_if_addr_lbl_8808129C_88438EE8(ts4_word a0)
{
    if ((ts4_word)a0 == 0) {
        return;
    }
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8808129C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)4;
    return;
}

/* Swing_DLL.xex 0x88438F10: addr lbl_8808129C */
ts4_word ts4_addr_lbl_8808129C_88438F10(void)
{
    return (ts4_word)lbl_8808129C;
}

/* Swing_DLL.xex 0x88438F20: fn  */
ts4_word ts4_fn_88438F20(void)
{
    return 96;
}

/* Swing_DLL.xex 0x88438F28: if_call_seq lbl_8803A308, u32@0x0, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_lbl_8803A308_88438F28(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word t2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_8803A308;
    if ((ts4_word)(a1 & 0x1) != 0) {
        t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t2, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88439538: call_seq fn_884568A8, fn_884555E8, fn_885221B8, fn_88453940, fn_885219D0 */
ts4_word ts4_call_seq_fn_884568A8_88439538(ts4_word a0)
{
    ts4_word t5;

    fn_884568A8((ts4_word)a0);
    fn_884555E8((ts4_word)a0);
    fn_885221B8((ts4_word)a0);
    fn_88453940((ts4_word)a0);
    t5 = fn_885219D0((ts4_word)a0);
    return t5;
}

/* Swing_DLL.xex 0x88439588: call_seq fn_8845F838, fn_88524710, fn_88523E08, fn_8845F690, fn_88522EF8, fn_8845EDC8 */
ts4_word ts4_call_seq_fn_8845F838_88439588(ts4_word a0)
{
    ts4_word t15;

    fn_8845F838();
    fn_88524710((ts4_word)a0, (ts4_word)1, (ts4_word)1);
    fn_88523E08((ts4_word)a0);
    fn_8845F690((ts4_word)a0);
    fn_88522EF8((ts4_word)a0);
    fn_8845EDC8((ts4_word)a0);
    fn_8845DFF8((ts4_word)a0);
    fn_8845CF60((ts4_word)a0);
    fn_8845C138((ts4_word)a0);
    fn_8845B140((ts4_word)a0);
    fn_88459F18((ts4_word)a0);
    fn_88522A00((ts4_word)a0);
    fn_884588B0((ts4_word)a0);
    fn_88457608((ts4_word)a0);
    t15 = fn_8844D990((ts4_word)a0);
    return t15;
}

/* Swing_DLL.xex 0x88439718: fn  */
ts4_word ts4_fn_88439718(void)
{
    return -1;
}

/* Swing_DLL.xex 0x88439810: fn  */
ts4_word ts4_fn_88439810(void)
{
    return 2;
}

/* Swing_DLL.xex 0x884399E0: get u32@0x0, lbl_880818B0, u32@0x4, vcall, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_884399E0(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_880818B0, (ts4_word)1, (ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x88439A40: fn  */
ts4_word ts4_fn_88439A40(void)
{
    return 8;
}

/* Swing_DLL.xex 0x8843A0A8: fn  */
ts4_word ts4_fn_8843A0A8(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8843A128: get u32@0x4 */
ts4_word ts4_get_u32_off4_8843A128(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 4));
}

/* Swing_DLL.xex 0x8843A1C0: fn  */
ts4_word ts4_fn_8843A1C0(ts4_word a0)
{
    return (a0 + 20);
}

/* Swing_DLL.xex 0x8843A490: fn  */
ts4_word ts4_fn_8843A490(void)
{
    return 2;
}

/* Swing_DLL.xex 0x8843A498: get u32@0x0, lbl_880818F0, u32@0x4, vcall, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_8843A498(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_880818F0, (ts4_word)1, (ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x8843AE80: fn  */
ts4_word ts4_fn_8843AE80(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    return a7;

    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;}

/* Swing_DLL.xex 0x8843AF08: tailcall ts4_if_call_seq_lbl_88080084_8843AF20 */
ts4_word ts4_tailcall_fn_8843AF20_8843AF08(ts4_word a0)
{
    return ts4_if_call_seq_lbl_88080084_8843AF20((ts4_word)(a0 + -8));
}

/* Swing_DLL.xex 0x8843AF18: tailcall ts4_if_call_seq_lbl_88080084_8843AF20 */
ts4_word ts4_tailcall_fn_8843AF20_8843AF18(ts4_word a0)
{
    return ts4_if_call_seq_lbl_88080084_8843AF20((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x8843AFB0: fn  */
ts4_word ts4_fn_8843AFB0(ts4_word a0)
{
    return (a0 + 48);
}

/* Swing_DLL.xex 0x8843B738: get u8@0x40 */
ts4_word ts4_get_u8_off40_8843B738(ts4_word a0)
{
    return (*(unsigned char *)((char *)(ts4_word)(a0) + 64));
}

/* Swing_DLL.xex 0x8843B740: fn  */
ts4_word ts4_fn_8843B740(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8843B748: fn  */
ts4_word ts4_fn_8843B748(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8843B7F0: get u32@0x44, u32@0x0, u32@0x0, u32@0x2c */
ts4_word ts4_get_u32_off44_8843B7F0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t2;

    t2 = *(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 68))) + 0);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 44))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x8843BA30: get u32@0x34 */
ts4_word ts4_get_u32_off34_8843BA30(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 52));
}

/* Swing_DLL.xex 0x8843BA38: if_get u32@0x34 */
ts4_word ts4_if_get_u32_off34_8843BA38(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    if ((int)(a1 + 1) < (int)t1) {
        return (a1 + 1);
    }
    return -1;
}

/* Swing_DLL.xex 0x8843BA50: get u32@0x30 */
ts4_word ts4_get_u32_off30_8843BA50(ts4_word a0, ts4_word a1)
{
    return (*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 48))) + (a1 << 2)));
}

/* Swing_DLL.xex 0x8843C290: if_fn  */
ts4_word ts4_if_fn_8843C290(ts4_word a0)
{
    if ((ts4_word)a0 != 0) {
        return (a0 + 16);
    }
    return 0;
}

/* Swing_DLL.xex 0x8843C2A8: get u32@0x0, lbl_88081990, u32@0x4, vcall, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_8843C2A8(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88081990, (ts4_word)1, (ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x8843CA00: fn  */
ts4_word ts4_fn_8843CA00(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8843CBC8: if_get u32@0x8, u32@0x24, u32@0x18 */
ts4_word ts4_if_get_u32_off8_8843CBC8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t2;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t2 = *(ts4_word *)((char *)(ts4_word)(t1) + 36);
    t3 = *(ts4_word *)((char *)(ts4_word)(t1) + 24);
    if ((int)(a1 + 1) < (int)(t2 + t3)) {
        return (a1 + 1);
    }
    return -1;
}

/* Swing_DLL.xex 0x8843D2D0: fn  */
ts4_word ts4_fn_8843D2D0(ts4_word a0)
{
    return (a0 + 20);
}

/* Swing_DLL.xex 0x8843DD30: fn  */
ts4_word ts4_fn_8843DD30(ts4_word a0)
{
    return (a0 + 20);
}

/* Swing_DLL.xex 0x8843E288: set u32@0xc, u32@0x18 */
void ts4_set_u32_offc_8843E288(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 24) = (ts4_word)0;
    return;
}

/* Swing_DLL.xex 0x8843E5D0: fn  */
ts4_word ts4_fn_8843E5D0(ts4_word a0, ts4_word a1)
{
    return ((a1 << 4) + a0);
}

/* Swing_DLL.xex 0x8843E5E8: get u32@0x40 */
void ts4_get_u32_off40_8843E5E8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    float t4;
    float t5;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 64);
    *(float *)((char *)(ts4_word)(a1) + 0) = (*(float *)((char *)(ts4_word)(t1) + 0));
    *(float *)((char *)(ts4_word)(a1) + 4) = (*(float *)((char *)(ts4_word)(t1) + 16));
    t4 = *(float *)((char *)(ts4_word)(t1) + 32);
    t5 = *(float *)lbl_88001A20;
    *(float *)((char *)(ts4_word)(a1) + 8) = t4;
    *(float *)((char *)(ts4_word)(a1) + 12) = t5;
    return;
}

/* Swing_DLL.xex 0x8843F718: get  */
float ts4_get_8843F718(ts4_word a0)
{
    return (*(float *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x8843F720: fn  */
ts4_word ts4_fn_8843F720(void)
{
    return 18;
}

/* Swing_DLL.xex 0x8843F728: get u32@0x0, lbl_88081B14, u32@0x4, vcall, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_8843F728(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88081B14, (ts4_word)1, (ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x88440AB0: if_call_seq fn_88440A08, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88440A08_88440AB0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88440A08((ts4_word)(a0 + -16), (ts4_word)a1);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Swing_DLL.xex 0x884415C0: tailcall fn_8843C1E0 */
ts4_word ts4_tailcall_fn_8843C1E0_884415C0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    return fn_8843C1E0((ts4_word)a1, (ts4_word)(a0 + 48), (ts4_word)(a0 + 64), (ts4_word)a3, (ts4_word)a3);
}

/* Swing_DLL.xex 0x88441970: if_get u32@0x54, u32@0x50, u32@lbl_88CACF08, KeTlsGetValue, u32@0x0, u32@0x4 */
ts4_word ts4_if_get_u32_off54_88441970(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5, ts4_word a6, ts4_word a7)
{
    ts4_word p8;
    ts4_word t1;
    ts4_word t2;
    ts4_word t4;
    ts4_word t7;

    (void)a1;
    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    (void)a6;
    (void)a7;
    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 84);
    p8 = (ts4_word)a0;
    if ((int)t1 > 1) {
        t2 = *(ts4_word *)((char *)(ts4_word)(a0) + 80);
        t4 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        t7 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t4) + 0))) + 4))))((ts4_word)t4, (ts4_word)t2);
        p8 = (ts4_word)t7;
    }
    return p8;
}

/* Swing_DLL.xex 0x884419C8: get u32@0x58, u32@lbl_88CACF08, KeTlsGetValue, u32@0x0, u32@0x4, vcall */
ts4_word ts4_get_u32_off58_884419C8(ts4_word a0)
{
    ts4_word t1;
    ts4_word t3;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 88);
    t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t3) + 0))) + 4))))((ts4_word)t3, (ts4_word)t1);
    return t6;
}

/* Swing_DLL.xex 0x884425D0: tailcall ts4_if_call_seq_fn_88441E80_884425D8 */
ts4_word ts4_tailcall_fn_884425D8_884425D0(ts4_word a0)
{
    return ts4_if_call_seq_fn_88441E80_884425D8((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x884427F0: if_call_seq fn_88443170, u32@0x0 */
ts4_word ts4_if_call_seq_fn_88443170_884427F0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = fn_88443170((ts4_word)(a0 + -16), (ts4_word)a1);
    if ((ts4_word)t1 != 0) {
        return (*(ts4_word *)((char *)(ts4_word)(t1) + 0));
    }
    return 0;
}

/* Swing_DLL.xex 0x884431E8: tailcall ts4_if_call_seq_fn_88437BB0_884431F0 */
ts4_word ts4_tailcall_fn_884431F0_884431E8(ts4_word a0)
{
    return ts4_if_call_seq_fn_88437BB0_884431F0((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x88443390: call_seq fn_88443038, lbl_880807C8, lbl_880807A4, u32@0x0, u32@0x10 */
ts4_word ts4_call_seq_fn_88443038_88443390(ts4_word a0, ts4_word a1, ts4_word a2)
{
    fn_88443038((ts4_word)a0, (ts4_word)a1, (ts4_word)a2);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880807C8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 16) = (ts4_word)(ts4_word)lbl_880807A4;
    return a0;
}

/* Swing_DLL.xex 0x88444898: if_get u32@0xc */
ts4_word ts4_if_get_u32_offc_88444898(ts4_word a0, ts4_word a1)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    if ((int)(a1 + 1) < (int)t1) {
        return (a1 + 1);
    }
    return -1;
}

/* Swing_DLL.xex 0x884448B0: if_call_seq fn_88444778, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88444778_884448B0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88444778();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88444AE0: get u32@0x34, u32@0x0, u32@0x1c */
ts4_word ts4_get_u32_off34_88444AE0(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 52);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 28))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88444F98: set u8@0x0 */
void ts4_set_u8_off0_88444F98(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x884453A8: get u32@0x10 */
ts4_word ts4_get_u32_off10_884453A8(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 16));
}

/* Swing_DLL.xex 0x884453B0: get u32@0x0, lbl_88081D80, u32@0x4, vcall, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_884453B0(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88081D80, (ts4_word)1, (ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x88445B48: get u32@0x0, lbl_88081D9C, u32@0x4, vcall, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_88445B48(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88081D9C, (ts4_word)1, (ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x88445F18: tailcall fn_8843C1E0 */
ts4_word ts4_tailcall_fn_8843C1E0_88445F18(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    (void)a2;
    return fn_8843C1E0((ts4_word)a1, (ts4_word)(a0 + 48), (ts4_word)(a0 + 32), (ts4_word)a3, (ts4_word)a3);
}

/* Swing_DLL.xex 0x884460E8: fn  */
ts4_word ts4_fn_884460E8(ts4_word a0)
{
    return (a0 & 0xff);
}

/* Swing_DLL.xex 0x884460F0: fn  */
ts4_word ts4_fn_884460F0(ts4_word a0)
{
    return ((a0) >> 8);
}

/* Swing_DLL.xex 0x88446A88: get u32@0x0, lbl_88081DE4, u32@0x4, vcall, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_88446A88(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88081DE4, (ts4_word)1, (ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x88446AE8: fn  */
ts4_word ts4_fn_88446AE8(void)
{
    return 1;
}

/* Swing_DLL.xex 0x88446BA8: set lbl_88080E0C, u16@0x6, u32@0x0, u32@0x8, u32@0xc */
void ts4_set_lbl_88080E0C_88446BA8(ts4_word a0, float f1)
{
    *(float *)((char *)(ts4_word)(a0) + 16) = f1;
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88080E0C;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)0;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)2;
    return;
}

/* Swing_DLL.xex 0x88446C88: if_fn  */
ts4_word ts4_if_fn_88446C88(ts4_word a0, ts4_word a1)
{
    if ((int)a0 != 1) {
        if ((int)a0 != 2) {
            return (a1 << 2);
        }
        return ((a1 << 1) + 1);
    }
    return (a1 + 2);
}

/* Swing_DLL.xex 0x88446CB8: addr lbl_88081E00, u16@0x6, u32@0x0 */
void ts4_addr_lbl_88081E00_88446CB8(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88081E00;
    return;
}

/* Swing_DLL.xex 0x88446CD0: addr lbl_88081E10, u16@0x6, u32@0x0 */
void ts4_addr_lbl_88081E10_88446CD0(ts4_word a0)
{
    *(unsigned short *)((char *)(ts4_word)(a0) + 6) = (unsigned short)1;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88081E10;
    return;
}

/* Swing_DLL.xex 0x88448120: if_call_seq fn_88447F20, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88447F20_88448120(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88447F20();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)37);
    }
    return a0;
}

/* Swing_DLL.xex 0x88448188: if_call_seq fn_88448048, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88448048_88448188(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88448048();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)37);
    }
    return a0;
}

/* Swing_DLL.xex 0x884481F0: tailcall ts4_if_call_seq_fn_88446EE0_884481F8 */
ts4_word ts4_tailcall_fn_884481F8_884481F0(ts4_word a0)
{
    return ts4_if_call_seq_fn_88446EE0_884481F8((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x88448260: if_fn  */
ts4_word ts4_if_fn_88448260(ts4_word a0, ts4_word a1)
{
    if ((int)a0 != 1) {
        if ((int)a0 != 2) {
            return (a1 + (a1 << 1));
        }
        return ((a1 << 1) + 1);
    }
    return (a1 + 2);
}

/* Swing_DLL.xex 0x88448F20: if_call_seq fn_88448DF8, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88448DF8_88448F20(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88448DF8();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)37);
    }
    return a0;
}

/* Swing_DLL.xex 0x88448F88: tailcall ts4_if_call_seq_fn_88448320_88448F90 */
ts4_word ts4_tailcall_fn_88448F90_88448F88(ts4_word a0)
{
    return ts4_if_call_seq_fn_88448320_88448F90((ts4_word)(a0 + -16));
}

/* Swing_DLL.xex 0x88449000: fn  */
ts4_word ts4_fn_88449000(void)
{
    return -1;
}

/* Swing_DLL.xex 0x8844A8A0: if_call_seq lbl_88081EE4, u32@0x0, ts4_tsu_cleanup_end */
ts4_word ts4_if_call_seq_lbl_88081EE4_8844A8A0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3, ts4_word a4, ts4_word a5)
{
    ts4_word p2;

    (void)a2;
    (void)a3;
    (void)a4;
    (void)a5;
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_88081EE4;
    p2 = (ts4_word)a0;
    if ((ts4_word)(a1 & 0x1) != 0) {
        ts4_tsu_cleanup_end((ts4_word)a0);
        p2 = (ts4_word)a0;
    }
    return p2;
}

/* Swing_DLL.xex 0x8844A978: fn  */
ts4_word ts4_fn_8844A978(ts4_word a0)
{
    return (a0 + 16);
}

/* Swing_DLL.xex 0x8844AF78: get u32@0x14 */
ts4_word ts4_get_u32_off14_8844AF78(ts4_word a0)
{
    return (*(ts4_word *)((char *)(ts4_word)(a0) + 20));
}

/* Swing_DLL.xex 0x8844B448: get u32@0x14, ts4_get_u32_off18_8844BAA0, u32@0x0, u32@0x20, vcall */
ts4_word ts4_get_u32_off14_8844B448(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;

    t2 = ts4_get_u32_off18_8844BAA0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 20)));
    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 32))))((ts4_word)a0, (ts4_word)t2, (ts4_word)a2, (ts4_word)a3);
    return a0;
}

/* Swing_DLL.xex 0x8844B498: get u32@0x14, ts4_get_u32_off18_8844BAA0, u32@0x0, u32@0x10, vcall */
ts4_word ts4_get_u32_off14_8844B498(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t5;

    t2 = ts4_get_u32_off18_8844BAA0((ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 20)));
    t5 = ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t2) + 0))) + 16))))((ts4_word)t2, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t5;
}

/* Swing_DLL.xex 0x8844B9A0: fn  */
ts4_word ts4_fn_8844B9A0(void)
{
    return 0;
}

/* Swing_DLL.xex 0x8844BE50: get u32@0x0, lbl_88081F60, u32@0x4, vcall, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_off0_8844BE50(ts4_word a0, ts4_word a1)
{
    ts4_word t6;

    ((ts4_word (*)(ts4_word, ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 4))))((ts4_word)a1, (ts4_word)(ts4_word)lbl_88081F60, (ts4_word)1, (ts4_word)a0);
    t6 = ((ts4_word (*)(ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0))) + 24))))((ts4_word)a1);
    return t6;
}

/* Swing_DLL.xex 0x8844BED0: get u8@0x17 */
ts4_word ts4_get_u8_off17_8844BED0(ts4_word a0)
{
    unsigned char t1;

    t1 = *(unsigned char *)((char *)(ts4_word)(a0) + 23);
    return ((t1 + 1) + ((t1 + 1) << 1));
}

/* Swing_DLL.xex 0x8844CEC0: get u32@0x8, u32@0xc, fn_8852DD38, u32@0x0, u32@0x0, vcall */
ts4_word ts4_get_u32_off8_8844CEC0(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    fn_8852DD38((ts4_word)(a0 + 48), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)t1, (ts4_word)a1);
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)1);
    return t6;
}

/* Swing_DLL.xex 0x8844CF18: tailcall fn_8852C9F0 */
ts4_word ts4_tailcall_fn_8852C9F0_8844CF18(ts4_word a0)
{
    return fn_8852C9F0((ts4_word)(a0 + 48));
}

/* Swing_DLL.xex 0x8844CF20: tailcall fn_8852CB30 */
ts4_word ts4_tailcall_fn_8852CB30_8844CF20(ts4_word a0)
{
    return fn_8852CB30((ts4_word)(a0 + 48));
}

/* Swing_DLL.xex 0x8844D0E8: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_8844D060 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8844D0E8(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)64, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)64;
    t4 = fn_8844D060((ts4_word)t3, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t4;
}

/* Swing_DLL.xex 0x8844D850: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_8844D060, lbl_88082034 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8844D850(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)64, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)64;
    fn_8844D060((ts4_word)t3, (ts4_word)a1, (ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082034;
    return t3;
}

/* Swing_DLL.xex 0x8844DEF0: if_call_seq fn_8844DE78, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_8844DE78_8844DEF0(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_8844DE78((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)31);
    }
    return a0;
}

/* Swing_DLL.xex 0x8844E070: tailcall fn_8844CF28 */
ts4_word ts4_tailcall_fn_8844CF28_8844E070(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8844CF28((ts4_word)a0, (ts4_word)a2, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8844E140: tailcall fn_88461E10 */
ts4_word ts4_tailcall_fn_88461E10_8844E140(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_88461E10((ts4_word)a0, (ts4_word)a2, (ts4_word)a1);
}

/* Swing_DLL.xex 0x8844E4E8: call_seq fn_8844EF88, lbl_880820E8, u32@0x0 */
ts4_word ts4_call_seq_fn_8844EF88_8844E4E8(ts4_word a0, ts4_word a1)
{
    fn_8844EF88((ts4_word)a0, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)lbl_880820E8;
    return a0;
}

/* Swing_DLL.xex 0x8844EAB8: get u8@lbl_88C21EE0, u8@0x0 */
void ts4_get_u8_lbl_88C21EE0_8844EAB8(ts4_word a0)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 0) = (unsigned char)(*(unsigned char *)lbl_88C21EE0);
    return;
}

/* Swing_DLL.xex 0x88451350: tailcall fn_8844ECB0 */
ts4_word ts4_tailcall_fn_8844ECB0_88451350(ts4_word a0, ts4_word a1, ts4_word a2)
{
    return fn_8844ECB0((ts4_word)a0, (ts4_word)a2, (ts4_word)a1);
}

/* Swing_DLL.xex 0x88451360: set u8@0x0 */
ts4_word ts4_set_u8_off0_88451360(ts4_word a0, ts4_word a1, ts4_word a2)
{
    (void)a0;
    *(unsigned char *)((char *)(ts4_word)(a1) + 0) = (unsigned char)0;
    return a2;
}

/* Swing_DLL.xex 0x88451528: set u8@0x1e23 */
void ts4_set_u8_off1e23_88451528(ts4_word a0, ts4_word a1)
{
    *(unsigned char *)((char *)(ts4_word)(a0) + 7715) = (unsigned char)a1;
    return;
}

/* Swing_DLL.xex 0x88452BA8: if_call_seq fn_88452650, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88452650_88452BA8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88452650();
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)39);
    }
    return a0;
}

/* Swing_DLL.xex 0x88452D78: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88452CA0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88452D78(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)24, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)24;
    t4 = fn_88452CA0((ts4_word)t3, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t4;
}

/* Swing_DLL.xex 0x884538D0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88452CA0, lbl_880824E0 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_884538D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)24, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)24;
    fn_88452CA0((ts4_word)t3, (ts4_word)a1, (ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880824E0;
    return t3;
}

/* Swing_DLL.xex 0x884542C8: if_call_seq fn_88453B08, u32@lbl_88CACF08, KeTlsGetValue, u16@0x4, fn_8841A590 */
ts4_word ts4_if_call_seq_fn_88453B08_884542C8(ts4_word a0, ts4_word a1)
{
    ts4_word t3;

    fn_88453B08((ts4_word)a0);
    if ((ts4_word)(a1 & 0x1) != 0) {
        t3 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
        fn_8841A590((ts4_word)t3, (ts4_word)a0, (ts4_word)(*(unsigned short *)((char *)(ts4_word)(a0) + 4)), (ts4_word)31);
    }
    return a0;
}

/* Swing_DLL.xex 0x884543C8: call_seq u32@0x8, u32@0x80, fn_8852DD38, u32@0x30, u8@0x84 */
ts4_word ts4_call_seq_u32_off8_884543C8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t3;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    t3 = fn_8852DD38((ts4_word)(a0 + 48), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 128)), (ts4_word)t1, (ts4_word)a1);
    *(ts4_word *)((char *)(ts4_word)(a0) + 48) = (ts4_word)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 132) = (unsigned char)1;
    return t3;
}

/* Swing_DLL.xex 0x88455700: get u32@0xc, u32@0x0, u32@0x10 */
ts4_word ts4_get_u32_offc_88455700(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 16))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88455730: get u32@0xc, u32@0x0, u32@0x18 */
ts4_word ts4_get_u32_offc_88455730(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 24))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x88455748: get u32@0xc, u32@0x0, u32@0x20 */
ts4_word ts4_get_u32_offc_88455748(ts4_word a0, ts4_word a1, ts4_word a2)
{
    ts4_word t1;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 12);
    return ((ts4_word (*)(ts4_word, ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(t1) + 0))) + 32))))((ts4_word)t1, (ts4_word)a1, (ts4_word)a2);
}

/* Swing_DLL.xex 0x884562B8: get u32@0x8, u32@0xc, fn_8852DD38, u32@0x0, u32@0x0, vcall */
ts4_word ts4_get_u32_off8_884562B8(ts4_word a0, ts4_word a1)
{
    ts4_word t1;
    ts4_word t6;

    t1 = *(ts4_word *)((char *)(ts4_word)(a0) + 8);
    fn_8852DD38((ts4_word)(a0 + 16), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a0) + 12)), (ts4_word)t1, (ts4_word)a1);
    t6 = ((ts4_word (*)(ts4_word, ts4_word))((*(ts4_word *)((char *)(ts4_word)((*(ts4_word *)((char *)(ts4_word)(a0) + 0))) + 0))))((ts4_word)a0, (ts4_word)1);
    return t6;
}

/* Swing_DLL.xex 0x88456310: tailcall fn_8852C9F0 */
ts4_word ts4_tailcall_fn_8852C9F0_88456310(ts4_word a0)
{
    return fn_8852C9F0((ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x88456318: tailcall fn_8852CB30 */
ts4_word ts4_tailcall_fn_8852CB30_88456318(ts4_word a0)
{
    return fn_8852CB30((ts4_word)(a0 + 16));
}

/* Swing_DLL.xex 0x88456320: get u32@0x4, fn_8852E0C0 */
ts4_word ts4_get_u32_off4_88456320(ts4_word a0, ts4_word a1)
{
    return fn_8852E0C0((ts4_word)(a0 + 16), (ts4_word)(*(ts4_word *)((char *)(ts4_word)(a1) + 4)), (ts4_word)a1);
}

/* Swing_DLL.xex 0x88456430: tailcall fn_884557F8 */
ts4_word ts4_tailcall_fn_884557F8_88456430(ts4_word a0)
{
    return fn_884557F8((ts4_word)a0);
}

/* Swing_DLL.xex 0x88456790: addr fn_88456710, fn_88455760, fn_884557A8, u32@0x0, fn_884557F8, u32@0x4 */
void ts4_addr_fn_88456710_88456790(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_88456710;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)fn_88455760;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)fn_884557A8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)fn_884557F8;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)0;
    *(unsigned char *)((char *)(ts4_word)(a0) + 17) = (unsigned char)1;
    return;
}

/* Swing_DLL.xex 0x88457540: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88457488 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88457540(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;
    ts4_word t4;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)32, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)32;
    t4 = fn_88457488((ts4_word)t3, (ts4_word)a0, (ts4_word)a1, (ts4_word)a2, (ts4_word)a3);
    return t4;
}

/* Swing_DLL.xex 0x88457598: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u16@0x4, fn_88457488, lbl_880827A8 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_88457598(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)32, (ts4_word)31);
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)32;
    fn_88457488((ts4_word)t3, (ts4_word)a1, (ts4_word)a0, (ts4_word)a2, (ts4_word)a3);
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880827A8;
    return t3;
}

/* Swing_DLL.xex 0x88459ED0: addr fn_88458FD8, fn_8845A400, fn_8845A498, u32@0x0, fn_8845C208, u32@0x4 */
void ts4_addr_fn_88458FD8_88459ED0(ts4_word a0)
{
    *(ts4_word *)((char *)(ts4_word)(a0) + 0) = (ts4_word)(ts4_word)fn_88458FD8;
    *(ts4_word *)((char *)(ts4_word)(a0) + 4) = (ts4_word)(ts4_word)fn_8845A400;
    *(ts4_word *)((char *)(ts4_word)(a0) + 8) = (ts4_word)(ts4_word)fn_8845A498;
    *(ts4_word *)((char *)(ts4_word)(a0) + 12) = (ts4_word)(ts4_word)fn_8845C208;
    *(unsigned char *)((char *)(ts4_word)(a0) + 16) = (unsigned char)1;
    *(unsigned char *)((char *)(ts4_word)(a0) + 17) = (unsigned char)0;
    return;
}

/* Swing_DLL.xex 0x8845B518: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x8, lbl_88082A00, u16@0x4 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8845B518(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    (void)a1;
    (void)a2;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)16, (ts4_word)31);
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)16;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082A00;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)-1;
    return t3;
}

/* Swing_DLL.xex 0x8845B580: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x8, lbl_880829C4, u16@0x4 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8845B580(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    (void)a1;
    (void)a2;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)16, (ts4_word)31);
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)16;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_880829C4;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)-1;
    return t3;
}

/* Swing_DLL.xex 0x8845C4D0: call_seq u32@lbl_88CACF08, KeTlsGetValue, fn_8841A510, u32@0x8, lbl_88082A64, u16@0x4 */
ts4_word ts4_call_seq_u32_lbl_88CACF08_8845C4D0(ts4_word a0, ts4_word a1, ts4_word a2, ts4_word a3)
{
    ts4_word t2;
    ts4_word t3;

    (void)a0;
    (void)a2;
    t2 = KeTlsGetValue((ts4_word)(*(ts4_word *)lbl_88CACF08));
    t3 = fn_8841A510((ts4_word)t2, (ts4_word)32, (ts4_word)31);
    *(ts4_word *)((char *)(ts4_word)(t3) + 8) = (ts4_word)a3;
    *(unsigned short *)((char *)(ts4_word)(t3) + 4) = (unsigned short)32;
    *(ts4_word *)((char *)(ts4_word)(t3) + 0) = (ts4_word)(ts4_word)lbl_88082A64;
    *(unsigned short *)((char *)(ts4_word)(t3) + 6) = (unsigned short)1;
    *(unsigned short *)((char *)(ts4_word)(t3) + 12) = (unsigned short)-1;
    fn_88537FC8((ts4_word)((*(ts4_word *)((char *)(ts4_word)(a1) + 0)) + 32), (ts4_word)(t3 + 16));
    return t3;
}
