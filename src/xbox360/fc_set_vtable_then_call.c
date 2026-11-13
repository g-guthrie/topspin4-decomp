/* Swing_DLL.xex, MSVC 16.00.10224.00 /O2 /Oi. One macro per cluster; one line per original address. */
typedef unsigned int u32;

extern char lbl_880D2CF8;
extern char lbl_880D6470;
extern char lbl_880D6590;
extern char lbl_880D66B0;
extern char lbl_880D67D0;
extern char lbl_880D6898;
extern char lbl_880D6968;
extern char lbl_880D6AF4;
extern char lbl_880D6BC0;
extern char lbl_880D7030;
extern char lbl_880D7228;
extern char lbl_880DB228;
extern char lbl_880DB250;
extern char lbl_880DB278;
extern char lbl_880DB328;
extern char lbl_880DB398;
extern char lbl_880DB4E0;
extern char lbl_880DB558;
extern char lbl_880DB5A8;
extern char lbl_880DB5D0;
extern char lbl_880DB5F8;
extern char lbl_880DB648;
extern char lbl_880DB698;
extern char lbl_880DB6C0;
extern char lbl_880DB76C;
extern char lbl_880DB80C;
extern char lbl_880DB834;
extern char lbl_880DB88C;
extern char lbl_880DB954;
extern char lbl_880DB97C;
extern char lbl_880DBCB4;
extern char lbl_880DBD30;
extern char lbl_880DBDA8;
extern char lbl_880DBDD0;
extern char lbl_880DC550;
extern char lbl_880DCE14;
extern char lbl_880DF1F8;
extern char lbl_880DF40C;
extern char lbl_880DF8D8;
extern char lbl_880DF9D0;
extern char lbl_880E1674;
extern char lbl_880E16AC;
extern char lbl_880E3738;
extern char lbl_880E3770;
extern char lbl_880E37D8;
extern char lbl_880E3838;
extern char lbl_880E39F0;
extern char lbl_880E3A8C;
extern char lbl_880E4528;
extern char lbl_880E46C8;
extern char lbl_880E4BA0;
extern char lbl_880E7084;
extern char lbl_880E7140;
extern char lbl_880E7168;
extern char lbl_880E7190;
extern char lbl_880E71B8;
extern char lbl_880E71E0;
extern char lbl_880E7208;
extern char lbl_880E7230;
extern char lbl_880E7258;
extern char lbl_880EA318;
extern char lbl_880EA60C;
extern char lbl_880EF46C;
extern char lbl_880EF6B8;
extern char lbl_880EF750;
extern char lbl_880F2C98;
extern char lbl_880F2D38;
extern char lbl_880F2DA8;
extern char lbl_880F2E18;
extern char lbl_880F3018;
extern char lbl_880F3144;
extern char lbl_880F33E0;
extern char lbl_880F37DC;
extern char lbl_880F43A4;
extern char lbl_880F4550;
extern char lbl_880F4640;
extern char lbl_880F4808;
extern char lbl_880F482C;
extern char lbl_880F4890;
extern char lbl_880F4E18;
extern char lbl_880F58D8;
extern char lbl_880F6024;
extern char lbl_880F62F0;
extern char lbl_880F6400;
extern char lbl_880F7B80;
extern char lbl_880F7C54;
extern char lbl_880F7F0C;
extern char lbl_880F7F38;
extern char lbl_880F814C;
extern char lbl_880F8188;
extern char lbl_880F8928;
extern char lbl_880F8950;
extern char lbl_880F8978;
extern char lbl_880F8B94;
extern char lbl_880F8C74;
extern char lbl_880F8C78;
extern char lbl_880F8D50;
void fn_881F41E8(void *);
void fn_882804F0(void *);
void fn_882806A8(void *);
void fn_8860BBD8(void *);
void fn_886178A0(void *);
void fn_88617D28(void *);
void fn_8861B4D8(void *);
void fn_88638FC8(void *);
void fn_88720108(void *);
void fn_88720180(void *);
void fn_887201F0(void *);
void fn_887239C0(void *);
void fn_88723A60(void *);
void fn_887EB6F0(void *);
void fn_887F4698(void *);
void fn_887F4E30(void *);
void fn_88804AB8(void *);
void fn_889017B8(void *);
void fn_889293A0(void *);
void fn_8893B3E0(void *);

/* Stores the address of a read-only table (vtable-like) into *self, then tail-calls base_init(self). */
#define SET_VTABLE_THEN_CALL(name, table, base_init) \
void name(void **self) \
{ \
    *self = &table; \
    base_init(self); \
}

/* Swing_DLL.xex 0x88617AE8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88617AE8, lbl_880F8C74, fn_886178A0)

/* Swing_DLL.xex 0x886188A0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_886188A0, lbl_880F8978, fn_88617D28)

/* Swing_DLL.xex 0x886188F0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_886188F0, lbl_880F8950, fn_88617D28)

/* Swing_DLL.xex 0x88618988 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88618988, lbl_880F8928, fn_88617D28)

/* Swing_DLL.xex 0x8861B238 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8861B238, lbl_880F8188, fn_88617D28)

/* Swing_DLL.xex 0x8861B288 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8861B288, lbl_880F814C, fn_88617D28)

/* Swing_DLL.xex 0x8861B458 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8861B458, lbl_880F7F38, fn_88617D28)

/* Swing_DLL.xex 0x8861B4C8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8861B4C8, lbl_880F7F0C, fn_88617D28)

/* Swing_DLL.xex 0x8861D120 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8861D120, lbl_880F7C54, fn_88617D28)

/* Swing_DLL.xex 0x8861DAF0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8861DAF0, lbl_880F8D50, fn_88617D28)

/* Swing_DLL.xex 0x8861E520 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8861E520, lbl_880F8B94, fn_88617D28)

/* Swing_DLL.xex 0x88622D08 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88622D08, lbl_880F7B80, fn_882804F0)

/* Swing_DLL.xex 0x886256C0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_886256C0, lbl_880F7C54, fn_88617D28)

/* Swing_DLL.xex 0x88625728 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88625728, lbl_880F7C54, fn_88617D28)

/* Swing_DLL.xex 0x88625890 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88625890, lbl_880F8C78, fn_882806A8)

/* Swing_DLL.xex 0x88626628 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88626628, lbl_880F7B80, fn_882804F0)

/* Swing_DLL.xex 0x88639070 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88639070, lbl_880F6400, fn_88638FC8)

/* Swing_DLL.xex 0x88639B78 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88639B78, lbl_880F62F0, fn_8861B4D8)

/* Swing_DLL.xex 0x886471A8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_886471A8, lbl_880F6024, fn_88617D28)

/* Swing_DLL.xex 0x8864F5A0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8864F5A0, lbl_880F58D8, fn_88617D28)

/* Swing_DLL.xex 0x8865A868 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8865A868, lbl_880F4640, fn_8860BBD8)

/* Swing_DLL.xex 0x8865ABD8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8865ABD8, lbl_880F4E18, fn_8860BBD8)

/* Swing_DLL.xex 0x886704F8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_886704F8, lbl_880F482C, fn_8860BBD8)

/* Swing_DLL.xex 0x88670858 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88670858, lbl_880F4808, fn_8860BBD8)

/* Swing_DLL.xex 0x8867A010 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8867A010, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x8867A120 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8867A120, lbl_880F43A4, fn_88617D28)

/* Swing_DLL.xex 0x8867B9F0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8867B9F0, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x8867BA48 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8867BA48, lbl_880F4890, fn_88617D28)

/* Swing_DLL.xex 0x8867D770 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8867D770, lbl_880F43A4, fn_88617D28)

/* Swing_DLL.xex 0x8867D948 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8867D948, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x8867DE98 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8867DE98, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x88681400 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88681400, lbl_880F43A4, fn_88617D28)

/* Swing_DLL.xex 0x88681590 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88681590, lbl_880F43A4, fn_88617D28)

/* Swing_DLL.xex 0x88681710 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88681710, lbl_880F43A4, fn_88617D28)

/* Swing_DLL.xex 0x88681D50 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88681D50, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x88681EE8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88681EE8, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x88682068 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88682068, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x88682E08 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88682E08, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x88682F88 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88682F88, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x8868CAC0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8868CAC0, lbl_880F43A4, fn_88617D28)

/* Swing_DLL.xex 0x8868CF40 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8868CF40, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x8868D0C0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8868D0C0, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x8868D240 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8868D240, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x8868D3C0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8868D3C0, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x88693F50 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88693F50, lbl_880F4550, fn_88617D28)

/* Swing_DLL.xex 0x886CD190 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_886CD190, lbl_880F37DC, fn_88617D28)

/* Swing_DLL.xex 0x886E81C8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_886E81C8, lbl_880F33E0, fn_88617D28)

/* Swing_DLL.xex 0x886F8CD0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_886F8CD0, lbl_880F3144, fn_88617D28)

/* Swing_DLL.xex 0x886FDCA8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_886FDCA8, lbl_880F33E0, fn_88617D28)

/* Swing_DLL.xex 0x88723040 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88723040, lbl_880F2E18, fn_88720108)

/* Swing_DLL.xex 0x88723050 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88723050, lbl_880F2DA8, fn_88720180)

/* Swing_DLL.xex 0x88723060 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88723060, lbl_880F2D38, fn_887201F0)

/* Swing_DLL.xex 0x8872B998 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8872B998, lbl_880F3018, fn_887239C0)

/* Swing_DLL.xex 0x8872CD40 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8872CD40, lbl_880F2C98, fn_88723A60)

/* Swing_DLL.xex 0x88779578 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88779578, lbl_880EF6B8, fn_8860BBD8)

/* Swing_DLL.xex 0x887798B0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887798B0, lbl_880EF46C, fn_8860BBD8)

/* Swing_DLL.xex 0x88779B80 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88779B80, lbl_880E3738, fn_8860BBD8)

/* Swing_DLL.xex 0x88779F60 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88779F60, lbl_880E3770, fn_8860BBD8)

/* Swing_DLL.xex 0x8877A260 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8877A260, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x8877A2C0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8877A2C0, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x8877A320 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8877A320, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x8877A390 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8877A390, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x8877A3F0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8877A3F0, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x8877A458 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8877A458, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x8877A4C0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8877A4C0, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x8877A4D0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8877A4D0, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x8877A530 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8877A530, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x8877A598 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8877A598, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x88782310 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88782310, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x887B53D8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887B53D8, lbl_880EF750, fn_881F41E8)

/* Swing_DLL.xex 0x887C7E20 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887C7E20, lbl_880EA60C, fn_88617D28)

/* Swing_DLL.xex 0x887CC030 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887CC030, lbl_880EA318, fn_887EB6F0)

/* Swing_DLL.xex 0x887D2BD8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887D2BD8, lbl_880E7258, fn_88617D28)

/* Swing_DLL.xex 0x887D2C48 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887D2C48, lbl_880E7230, fn_88617D28)

/* Swing_DLL.xex 0x887D2CB8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887D2CB8, lbl_880E7208, fn_88617D28)

/* Swing_DLL.xex 0x887D2D28 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887D2D28, lbl_880E71E0, fn_88617D28)

/* Swing_DLL.xex 0x887D2D98 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887D2D98, lbl_880E71B8, fn_88617D28)

/* Swing_DLL.xex 0x887D2E08 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887D2E08, lbl_880E7190, fn_88617D28)

/* Swing_DLL.xex 0x887D2E78 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887D2E78, lbl_880E7168, fn_88617D28)

/* Swing_DLL.xex 0x887D2EE8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887D2EE8, lbl_880E7140, fn_88617D28)

/* Swing_DLL.xex 0x887D30F8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887D30F8, lbl_880E7084, fn_88617D28)

/* Swing_DLL.xex 0x887E95F0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887E95F0, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x887EA140 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887EA140, lbl_880E4BA0, fn_8860BBD8)

/* Swing_DLL.xex 0x887F4B90 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887F4B90, lbl_880E4528, fn_887F4698)

/* Swing_DLL.xex 0x887F4C08 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887F4C08, lbl_880E4528, fn_887F4698)

/* Swing_DLL.xex 0x887F4C50 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887F4C50, lbl_880E4528, fn_887F4698)

/* Swing_DLL.xex 0x887F4CA0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887F4CA0, lbl_880E4528, fn_887F4698)

/* Swing_DLL.xex 0x887F4CE8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887F4CE8, lbl_880E4528, fn_887F4698)

/* Swing_DLL.xex 0x887F4EB8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887F4EB8, lbl_880E4528, fn_887F4698)

/* Swing_DLL.xex 0x887F4FF0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_887F4FF0, lbl_880E46C8, fn_887F4E30)

/* Swing_DLL.xex 0x88800748 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88800748, lbl_880E3A8C, fn_88617D28)

/* Swing_DLL.xex 0x88800BE8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88800BE8, lbl_880E39F0, fn_88617D28)

/* Swing_DLL.xex 0x888011C0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888011C0, lbl_880E39F0, fn_88617D28)

/* Swing_DLL.xex 0x88803140 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88803140, lbl_880E3738, fn_8860BBD8)

/* Swing_DLL.xex 0x88803168 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88803168, lbl_880E3770, fn_8860BBD8)

/* Swing_DLL.xex 0x888032E8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888032E8, lbl_880E3838, fn_88617D28)

/* Swing_DLL.xex 0x88804B78 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88804B78, lbl_880E37D8, fn_88804AB8)

/* Swing_DLL.xex 0x88804BD8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88804BD8, lbl_880E37D8, fn_88804AB8)

/* Swing_DLL.xex 0x88838638 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88838638, lbl_880E3738, fn_8860BBD8)

/* Swing_DLL.xex 0x88838660 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88838660, lbl_880E1674, fn_8860BBD8)

/* Swing_DLL.xex 0x88838700 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88838700, lbl_880E1674, fn_8860BBD8)

/* Swing_DLL.xex 0x88838740 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88838740, lbl_880E1674, fn_8860BBD8)

/* Swing_DLL.xex 0x888387B0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888387B0, lbl_880E1674, fn_8860BBD8)

/* Swing_DLL.xex 0x8883D788 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8883D788, lbl_880E16AC, fn_88617D28)

/* Swing_DLL.xex 0x88878F20 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88878F20, lbl_880DF9D0, fn_8861B4D8)

/* Swing_DLL.xex 0x8887CAC0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8887CAC0, lbl_880DF8D8, fn_88617D28)

/* Swing_DLL.xex 0x88886690 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88886690, lbl_880DF40C, fn_88617D28)

/* Swing_DLL.xex 0x88887AC8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88887AC8, lbl_880DF1F8, fn_88617D28)

/* Swing_DLL.xex 0x88890C58 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88890C58, lbl_880DCE14, fn_88617D28)

/* Swing_DLL.xex 0x888AE178 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888AE178, lbl_880DC550, fn_8860BBD8)

/* Swing_DLL.xex 0x888AEE48 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888AEE48, lbl_880DC550, fn_8860BBD8)

/* Swing_DLL.xex 0x888AEE58 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888AEE58, lbl_880DC550, fn_8860BBD8)

/* Swing_DLL.xex 0x888AF1C8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888AF1C8, lbl_880DC550, fn_8860BBD8)

/* Swing_DLL.xex 0x888AF288 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888AF288, lbl_880DC550, fn_8860BBD8)

/* Swing_DLL.xex 0x888C7840 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888C7840, lbl_880DB834, fn_88617D28)

/* Swing_DLL.xex 0x888C7970 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888C7970, lbl_880DB4E0, fn_88617D28)

/* Swing_DLL.xex 0x888C79E8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888C79E8, lbl_880DB97C, fn_88617D28)

/* Swing_DLL.xex 0x888C7F88 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888C7F88, lbl_880DB954, fn_88617D28)

/* Swing_DLL.xex 0x888C9578 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888C9578, lbl_880DB88C, fn_88617D28)

/* Swing_DLL.xex 0x888C9608 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888C9608, lbl_880DB80C, fn_88617D28)

/* Swing_DLL.xex 0x888CA4D0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CA4D0, lbl_880DB278, fn_88617D28)

/* Swing_DLL.xex 0x888CA558 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CA558, lbl_880DB250, fn_88617D28)

/* Swing_DLL.xex 0x888CA8A0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CA8A0, lbl_880DB228, fn_88617D28)

/* Swing_DLL.xex 0x888CAB18 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CAB18, lbl_880DB698, fn_88617D28)

/* Swing_DLL.xex 0x888CADE0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CADE0, lbl_880DB5D0, fn_88617D28)

/* Swing_DLL.xex 0x888CAFD8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CAFD8, lbl_880DB5A8, fn_88617D28)

/* Swing_DLL.xex 0x888CB078 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CB078, lbl_880DB558, fn_88617D28)

/* Swing_DLL.xex 0x888CB0E0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CB0E0, lbl_880DB76C, fn_88617D28)

/* Swing_DLL.xex 0x888CB908 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CB908, lbl_880DB648, fn_88617D28)

/* Swing_DLL.xex 0x888CBD40 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CBD40, lbl_880DB5F8, fn_88617D28)

/* Swing_DLL.xex 0x888CCB98 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CCB98, lbl_880DB398, fn_88617D28)

/* Swing_DLL.xex 0x888CDD38 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CDD38, lbl_880DB328, fn_88617D28)

/* Swing_DLL.xex 0x888CDF18 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CDF18, lbl_880DBCB4, fn_88617D28)

/* Swing_DLL.xex 0x888CED18 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CED18, lbl_880DBDD0, fn_88617D28)

/* Swing_DLL.xex 0x888CEDA8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CEDA8, lbl_880DBDA8, fn_88617D28)

/* Swing_DLL.xex 0x888CF0C8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_888CF0C8, lbl_880DBD30, fn_88617D28)

/* Swing_DLL.xex 0x889048D8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_889048D8, lbl_880DB6C0, fn_889017B8)

/* Swing_DLL.xex 0x88912DB0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88912DB0, lbl_880D7228, fn_8860BBD8)

/* Swing_DLL.xex 0x88912F98 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88912F98, lbl_880D7030, fn_88617D28)

/* Swing_DLL.xex 0x88918418 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88918418, lbl_880D6BC0, fn_88617D28)

/* Swing_DLL.xex 0x8891B0F0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_8891B0F0, lbl_880D2CF8, fn_8893B3E0)

/* Swing_DLL.xex 0x889270B0 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_889270B0, lbl_880D6AF4, fn_88617D28)

/* Swing_DLL.xex 0x88929A50 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88929A50, lbl_880D6968, fn_889293A0)

/* Swing_DLL.xex 0x88929AC8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88929AC8, lbl_880D6590, fn_889293A0)

/* Swing_DLL.xex 0x88929AD8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88929AD8, lbl_880D67D0, fn_889293A0)

/* Swing_DLL.xex 0x88929AE8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88929AE8, lbl_880D66B0, fn_889293A0)

/* Swing_DLL.xex 0x88929AF8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88929AF8, lbl_880D6898, fn_889293A0)

/* Swing_DLL.xex 0x88929BC8 */
SET_VTABLE_THEN_CALL(ts4_set_vtable_then_call_88929BC8, lbl_880D6470, fn_889293A0)

