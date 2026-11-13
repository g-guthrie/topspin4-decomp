/* Swing_DLL.xex, MSVC 16.00.10224.00 /O2 /Oi. One macro per cluster; one line per original address. */
typedef unsigned int u32;

void *fn_8832AAF8(void *);
void *fn_8833A0E0(void *);
void *fn_8833A560(void *);
void *fn_8833A628(void *);
void *fn_8833A8B0(void *);
void *fn_8833BAB8(void *);
void *fn_8833BE50(void *);
void *fn_8833C290(void *);
void *fn_8833C330(void *);
void *fn_8833CB90(void *);
void *fn_8833CCA0(void *);
void *fn_8833CEC8(void *);
void *fn_8833CF50(void *);
void *fn_8833CFB8(void *);
void *fn_8833D338(void *);
void *fn_8833D550(void *);
void *fn_8833D978(void *);
void *fn_8833DA00(void *);
void *fn_8833DAB0(void *);
void *fn_8833DC58(void *);
void *fn_8833DF48(void *);
void *fn_8833E0D0(void *);
void *fn_8833E770(void *);
void *fn_8833E8D8(void *);
void *fn_8833EBD0(void *);
void *fn_883404E0(void *);
void *fn_883405D8(void *);
void *fn_88340660(void *);
void *fn_88340898(void *);
void *fn_88341ED0(void *);
void *fn_883420D8(void *);
void *fn_883428B0(void *);
void *fn_88343470(void *);
void *fn_883434E8(void *);
void *fn_88343638(void *);
void *fn_88343800(void *);
void *fn_883438A0(void *);
void *fn_88343BF0(void *);
void *fn_88343C80(void *);
void *fn_88343EB0(void *);
void *fn_88343F30(void *);
void *fn_88344D28(void *);
void *fn_883451F0(void *);
void *fn_88345298(void *);
void *fn_88345508(void *);
void *fn_883457F0(void *);
void *fn_88345F68(void *);
void *fn_883461C8(void *);
void *fn_88346258(void *);
void *fn_88346598(void *);
void *fn_88346668(void *);
void *fn_88347130(void *);
void *fn_883472D8(void *);
void *fn_88347370(void *);
void *fn_88347650(void *);
void *fn_883476D8(void *);
void *fn_88348490(void *);
void *fn_883486A8(void *);
void *fn_88349A80(void *);
void *fn_88349C80(void *);
void *fn_88349DB8(void *);
void *fn_8834A060(void *);
void *fn_8834A7B8(void *);
void *fn_8834AAA0(void *);
void *fn_8834B188(void *);
void *fn_8834B2A8(void *);
void *fn_8834C5A0(void *);
void *fn_8834C6C0(void *);
void *fn_8834C9F8(void *);
void *fn_8834D3D8(void *);
void *fn_8834D720(void *);
void *fn_8834D830(void *);
void *fn_8834D8D8(void *);
void *fn_8834DBA0(void *);
void *fn_8834DFC0(void *);
void *fn_8834F798(void *);
void *fn_88350490(void *);
void *fn_88350560(void *);
void *fn_883507C8(void *);
void *fn_88350B00(void *);
void *fn_88350C38(void *);
void *fn_88352190(void *);
void *fn_883524E0(void *);
void *fn_88352600(void *);
void *fn_88352BF0(void *);
void *fn_88352FB8(void *);
void *fn_88353138(void *);
void *fn_88354BE8(void *);
void *fn_88354D38(void *);
void *fn_88356908(void *);
void *fn_88356AD8(void *);
void *fn_88356B50(void *);
void *fn_88356BD8(void *);
void *fn_88356C50(void *);
void *fn_883582E0(void *);
void *fn_88358690(void *);
void *fn_88358738(void *);
void *fn_8835D8A0(void *);
void *fn_8835DC40(void *);
void *fn_8835DDB8(void *);
void *fn_8835E190(void *);
void *fn_88363410(void *);
void *fn_883636A0(void *);
void *fn_88363830(void *);
void *fn_88363C00(void *);
void *fn_88366C90(void *);
void *fn_88366EA8(void *);
void *fn_88367020(void *);
void *fn_883673F0(void *);
void *fn_88369B68(void *);
void *fn_88369D80(void *);
void *fn_88369EF8(void *);
void *fn_8836A2C8(void *);
void *fn_8836B8A0(void *);
void *fn_8836B940(void *);
void *fn_8836B9C0(void *);
void *fn_8836BAA0(void *);
void *fn_8836C040(void *);
void *fn_8836C2C8(void *);
void *fn_8836C938(void *);
void *fn_8836CE50(void *);
void *fn_8836D198(void *);
void *fn_8836D228(void *);
void *fn_8836D820(void *);
void *fn_8836DEB8(void *);
void *fn_8836DFB8(void *);
void *fn_8836E420(void *);
void *fn_8836E4D0(void *);
void *fn_8836E610(void *);
void *fn_8836EA80(void *);
void *fn_8836EBA0(void *);
void *fn_8836F040(void *);
void *fn_8836F1E8(void *);
void *fn_8836F9C8(void *);
void *fn_883703A8(void *);
void *fn_88370BE0(void *);
void *fn_883711D0(void *);
void *fn_88371270(void *);
void *fn_883714C8(void *);
void *fn_8839CA60(void *);

/* Thunk: converts a pointer to an embedded member at offset 0x1C into the containing object
   (NULL stays NULL) and tail-calls the target with it. */
#define ADJUST_MINUS_28_THUNK(name, target) \
void *name(char *member) \
{ \
    return target(member ? member - 28 : 0); \
}

/* Swing_DLL.xex 0x8832ADF0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8832ADF0, fn_8832AAF8)

/* Swing_DLL.xex 0x8833A438 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833A438, fn_8833A0E0)

/* Swing_DLL.xex 0x8833B408 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833B408, fn_8833A560)

/* Swing_DLL.xex 0x8833B420 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833B420, fn_8833A628)

/* Swing_DLL.xex 0x8833B438 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833B438, fn_8833A8B0)

/* Swing_DLL.xex 0x8833C170 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833C170, fn_8833BAB8)

/* Swing_DLL.xex 0x8833C188 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833C188, fn_8833BE50)

/* Swing_DLL.xex 0x8833CDA0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833CDA0, fn_8833C290)

/* Swing_DLL.xex 0x8833CDB8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833CDB8, fn_8833C330)

/* Swing_DLL.xex 0x8833CDD0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833CDD0, fn_8833CB90)

/* Swing_DLL.xex 0x8833CDE8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833CDE8, fn_8833CCA0)

/* Swing_DLL.xex 0x8833D728 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833D728, fn_8833CEC8)

/* Swing_DLL.xex 0x8833D740 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833D740, fn_8833CF50)

/* Swing_DLL.xex 0x8833D7D0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833D7D0, fn_8833CFB8)

/* Swing_DLL.xex 0x8833D7E8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833D7E8, fn_8833D338)

/* Swing_DLL.xex 0x8833D800 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833D800, fn_8833D550)

/* Swing_DLL.xex 0x8833DDC8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833DDC8, fn_8833D978)

/* Swing_DLL.xex 0x8833DDE0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833DDE0, fn_8833DA00)

/* Swing_DLL.xex 0x8833DDF8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833DDF8, fn_8833DAB0)

/* Swing_DLL.xex 0x8833DE10 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833DE10, fn_8833DC58)

/* Swing_DLL.xex 0x8833EAB8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833EAB8, fn_8833DF48)

/* Swing_DLL.xex 0x8833EB88 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833EB88, fn_8833E0D0)

/* Swing_DLL.xex 0x8833EBA0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833EBA0, fn_8833E770)

/* Swing_DLL.xex 0x8833EBB8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833EBB8, fn_8833E8D8)

/* Swing_DLL.xex 0x8833EC60 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8833EC60, fn_8833EBD0)

/* Swing_DLL.xex 0x883407E0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883407E0, fn_883404E0)

/* Swing_DLL.xex 0x88340868 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88340868, fn_883405D8)

/* Swing_DLL.xex 0x88340880 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88340880, fn_88340660)

/* Swing_DLL.xex 0x88342698 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88342698, fn_88341ED0)

/* Swing_DLL.xex 0x883426B0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883426B0, fn_883420D8)

/* Swing_DLL.xex 0x883426C8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883426C8, fn_88340898)

/* Swing_DLL.xex 0x883435F0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883435F0, fn_883428B0)

/* Swing_DLL.xex 0x88343608 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88343608, fn_88343470)

/* Swing_DLL.xex 0x88343620 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88343620, fn_883434E8)

/* Swing_DLL.xex 0x88343718 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88343718, fn_88343638)

/* Swing_DLL.xex 0x88343D48 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88343D48, fn_88343800)

/* Swing_DLL.xex 0x88343D88 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88343D88, fn_883438A0)

/* Swing_DLL.xex 0x88343DA0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88343DA0, fn_88343BF0)

/* Swing_DLL.xex 0x88343DB8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88343DB8, fn_88343C80)

/* Swing_DLL.xex 0x883441F0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883441F0, fn_88343EB0)

/* Swing_DLL.xex 0x88344208 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88344208, fn_88343F30)

/* Swing_DLL.xex 0x883454C0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883454C0, fn_88344D28)

/* Swing_DLL.xex 0x883454D8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883454D8, fn_883451F0)

/* Swing_DLL.xex 0x883454F0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883454F0, fn_88345298)

/* Swing_DLL.xex 0x883456F8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883456F8, fn_88345508)

/* Swing_DLL.xex 0x88346138 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88346138, fn_883457F0)

/* Swing_DLL.xex 0x883461B0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883461B0, fn_88345F68)

/* Swing_DLL.xex 0x88346488 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88346488, fn_88346258)

/* Swing_DLL.xex 0x883464A0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883464A0, fn_883461C8)

/* Swing_DLL.xex 0x88347248 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88347248, fn_88346598)

/* Swing_DLL.xex 0x88347260 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88347260, fn_88346668)

/* Swing_DLL.xex 0x883472C0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883472C0, fn_88347130)

/* Swing_DLL.xex 0x88347540 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88347540, fn_88347370)

/* Swing_DLL.xex 0x88347558 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88347558, fn_883472D8)

/* Swing_DLL.xex 0x88348810 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88348810, fn_88347650)

/* Swing_DLL.xex 0x883488F0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883488F0, fn_883476D8)

/* Swing_DLL.xex 0x88348908 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88348908, fn_88348490)

/* Swing_DLL.xex 0x88348920 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88348920, fn_883486A8)

/* Swing_DLL.xex 0x88349D48 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88349D48, fn_88349A80)

/* Swing_DLL.xex 0x88349DA0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88349DA0, fn_88349C80)

/* Swing_DLL.xex 0x88349EA8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88349EA8, fn_88349DB8)

/* Swing_DLL.xex 0x8834A718 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834A718, fn_8834A060)

/* Swing_DLL.xex 0x8834A868 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834A868, fn_8834A7B8)

/* Swing_DLL.xex 0x8834B248 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834B248, fn_8834AAA0)

/* Swing_DLL.xex 0x8834B290 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834B290, fn_8834B188)

/* Swing_DLL.xex 0x8834B360 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834B360, fn_8834B2A8)

/* Swing_DLL.xex 0x8834C8B8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834C8B8, fn_8834C5A0)

/* Swing_DLL.xex 0x8834C8D0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834C8D0, fn_8834C6C0)

/* Swing_DLL.xex 0x8834D4D0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834D4D0, fn_8834C9F8)

/* Swing_DLL.xex 0x8834D560 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834D560, fn_8834D3D8)

/* Swing_DLL.xex 0x8834DAC8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834DAC8, fn_8834D830)

/* Swing_DLL.xex 0x8834DAE0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834DAE0, fn_8834D8D8)

/* Swing_DLL.xex 0x8834DAF8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834DAF8, fn_8834D720)

/* Swing_DLL.xex 0x8834DDC8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834DDC8, fn_8834DBA0)

/* Swing_DLL.xex 0x8834E2D8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834E2D8, fn_8834DFC0)

/* Swing_DLL.xex 0x8834FA40 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8834FA40, fn_8834F798)

/* Swing_DLL.xex 0x88350BC0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88350BC0, fn_88350490)

/* Swing_DLL.xex 0x88350BD8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88350BD8, fn_88350B00)

/* Swing_DLL.xex 0x88350BF0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88350BF0, fn_88350560)

/* Swing_DLL.xex 0x88350C08 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88350C08, fn_883507C8)

/* Swing_DLL.xex 0x88350C20 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88350C20, fn_8839CA60)

/* Swing_DLL.xex 0x88351508 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88351508, fn_88350C38)

/* Swing_DLL.xex 0x88352EB0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88352EB0, fn_88352190)

/* Swing_DLL.xex 0x88352EC8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88352EC8, fn_883524E0)

/* Swing_DLL.xex 0x88352EE0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88352EE0, fn_88352600)

/* Swing_DLL.xex 0x88352EF8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88352EF8, fn_88352BF0)

/* Swing_DLL.xex 0x88353210 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88353210, fn_88352FB8)

/* Swing_DLL.xex 0x88353228 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88353228, fn_88353138)

/* Swing_DLL.xex 0x88354F28 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88354F28, fn_88354BE8)

/* Swing_DLL.xex 0x88354F40 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88354F40, fn_88354D38)

/* Swing_DLL.xex 0x88356CF0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88356CF0, fn_88356908)

/* Swing_DLL.xex 0x88356D08 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88356D08, fn_88356AD8)

/* Swing_DLL.xex 0x88356D20 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88356D20, fn_88356B50)

/* Swing_DLL.xex 0x88356D38 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88356D38, fn_88356BD8)

/* Swing_DLL.xex 0x88356D50 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88356D50, fn_88356C50)

/* Swing_DLL.xex 0x88358708 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88358708, fn_883582E0)

/* Swing_DLL.xex 0x88358720 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88358720, fn_88358690)

/* Swing_DLL.xex 0x883592F8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883592F8, fn_88358738)

/* Swing_DLL.xex 0x8835DD08 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8835DD08, fn_8835D8A0)

/* Swing_DLL.xex 0x8835DD20 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8835DD20, fn_8835DC40)

/* Swing_DLL.xex 0x8835E178 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8835E178, fn_8835DDB8)

/* Swing_DLL.xex 0x88360D20 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88360D20, fn_8835E190)

/* Swing_DLL.xex 0x88363768 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88363768, fn_88363410)

/* Swing_DLL.xex 0x88363780 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88363780, fn_883636A0)

/* Swing_DLL.xex 0x88363BE8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88363BE8, fn_88363830)

/* Swing_DLL.xex 0x88365188 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88365188, fn_88363C00)

/* Swing_DLL.xex 0x88366F70 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88366F70, fn_88366C90)

/* Swing_DLL.xex 0x88366F88 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88366F88, fn_88366EA8)

/* Swing_DLL.xex 0x883673D8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883673D8, fn_88367020)

/* Swing_DLL.xex 0x883687D0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883687D0, fn_883673F0)

/* Swing_DLL.xex 0x88369E48 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88369E48, fn_88369B68)

/* Swing_DLL.xex 0x88369E60 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88369E60, fn_88369D80)

/* Swing_DLL.xex 0x8836A2B0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836A2B0, fn_88369EF8)

/* Swing_DLL.xex 0x8836B2D0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836B2D0, fn_8836A2C8)

/* Swing_DLL.xex 0x8836BA58 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836BA58, fn_8836B8A0)

/* Swing_DLL.xex 0x8836BA70 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836BA70, fn_8836B940)

/* Swing_DLL.xex 0x8836BA88 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836BA88, fn_8836B9C0)

/* Swing_DLL.xex 0x8836BE48 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836BE48, fn_8836BAA0)

/* Swing_DLL.xex 0x8836C2B0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836C2B0, fn_8836C040)

/* Swing_DLL.xex 0x8836CB10 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836CB10, fn_8836C2C8)

/* Swing_DLL.xex 0x8836CB28 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836CB28, fn_8836C938)

/* Swing_DLL.xex 0x8836D108 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836D108, fn_8836CE50)

/* Swing_DLL.xex 0x8836D210 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836D210, fn_8836D198)

/* Swing_DLL.xex 0x8836D750 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836D750, fn_8836D228)

/* Swing_DLL.xex 0x8836E598 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836E598, fn_8836D820)

/* Swing_DLL.xex 0x8836E5B0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836E5B0, fn_8836DEB8)

/* Swing_DLL.xex 0x8836E5C8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836E5C8, fn_8836E420)

/* Swing_DLL.xex 0x8836E5E0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836E5E0, fn_8836E4D0)

/* Swing_DLL.xex 0x8836E5F8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836E5F8, fn_8836DFB8)

/* Swing_DLL.xex 0x8836E9A8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836E9A8, fn_8836E610)

/* Swing_DLL.xex 0x8836EFA8 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836EFA8, fn_8836EA80)

/* Swing_DLL.xex 0x8836F028 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836F028, fn_8836EBA0)

/* Swing_DLL.xex 0x8836F128 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836F128, fn_8836F040)

/* Swing_DLL.xex 0x8836F900 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_8836F900, fn_8836F1E8)

/* Swing_DLL.xex 0x88370310 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88370310, fn_8836F9C8)

/* Swing_DLL.xex 0x88371468 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88371468, fn_883703A8)

/* Swing_DLL.xex 0x88371480 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88371480, fn_88370BE0)

/* Swing_DLL.xex 0x88371498 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88371498, fn_883711D0)

/* Swing_DLL.xex 0x883714B0 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_883714B0, fn_88371270)

/* Swing_DLL.xex 0x88373870 */
ADJUST_MINUS_28_THUNK(ts4_adjust_minus_28_thunk_88373870, fn_883714C8)

