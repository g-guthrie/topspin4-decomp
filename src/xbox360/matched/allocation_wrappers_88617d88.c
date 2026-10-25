/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Allocation wrappers of two closed shapes that compile to exact objdiff
 * matches with the Xbox 360 compiler (see docs/matching-build.md). Each one
 * allocates through fn_88613268, passes a non-null result to fn_88617D88,
 * stores a label address in the first word (one shape also clears one more
 * word) and returns the result. The function names are the existing
 * symbols.txt names; prototypes and roles are unknown, and the C forms are
 * reconstructions of the shape only. Each function states its address range.
 *
 * The fn_88613268 declaration follows container_factory_wrappers.c and the
 * fn_88617D88 declaration follows matched/runtime_exhibition_scene.c. Other
 * units declare the fn_88613268 result as void * or ts4_u8 *; the original
 * return type is not established (see docs/methodology.md).
 */
typedef unsigned int ts4_u32;

extern void *lbl_88D45B38;
extern ts4_u32 fn_88613268(void *heap, ts4_u32 size, ts4_u32 alignment, ts4_u32 flags, ts4_u32 pool);
extern void *fn_88617D88(void *object);
extern ts4_u32 lbl_880C13C0;
extern ts4_u32 lbl_880C13E8;
extern ts4_u32 lbl_880D23E0;
extern ts4_u32 lbl_880D2D94;
extern ts4_u32 lbl_880D5644;
extern ts4_u32 lbl_880D5A3C;
extern char lbl_880D6BC0;
extern ts4_u32 lbl_880D7030;
extern ts4_u32 lbl_880DB250;
extern ts4_u32 lbl_880DB328;
extern ts4_u32 lbl_880DB398;
extern ts4_u32 lbl_880DB558;
extern ts4_u32 lbl_880DB5D0;
extern ts4_u32 lbl_880DB648;
extern ts4_u32 lbl_880DB834;
extern ts4_u32 lbl_880DB954;
extern ts4_u32 lbl_880DB97C;
extern ts4_u32 lbl_880DBCB4;
extern ts4_u32 lbl_880DBDA8;
extern ts4_u32 lbl_880DBE48;
extern ts4_u32 lbl_880DC524;
extern ts4_u32 lbl_880DD88C;
extern ts4_u32 lbl_880DF940;
extern ts4_u32 lbl_880E06B0;
extern ts4_u32 lbl_880E1724;
extern ts4_u32 lbl_880E3748;
extern ts4_u32 lbl_880E39A0;
extern ts4_u32 lbl_880E3D84;
extern ts4_u32 lbl_880E499C;
extern ts4_u32 lbl_880E4C64;
extern ts4_u32 lbl_880E7084;
extern ts4_u32 lbl_880E70AC;
extern ts4_u32 lbl_880E7140;
extern ts4_u32 lbl_880E7168;
extern ts4_u32 lbl_880E7190;
extern ts4_u32 lbl_880E71B8;
extern ts4_u32 lbl_880E71E0;
extern ts4_u32 lbl_880E7208;
extern ts4_u32 lbl_880E7230;
extern ts4_u32 lbl_880E7258;
extern ts4_u32 lbl_880EF958;
extern ts4_u32 lbl_880EF9D0;
extern ts4_u32 lbl_880EFC8C;
extern ts4_u32 lbl_880EFE8C;
extern ts4_u32 lbl_880F30CC;
extern ts4_u32 lbl_880F30F4;
extern ts4_u32 lbl_880F311C;
extern ts4_u32 lbl_880F3494;
extern ts4_u32 lbl_880F37DC;
extern ts4_u32 lbl_880F3804;
extern ts4_u32 lbl_880F4678;
extern ts4_u32 lbl_880F4788;
extern ts4_u32 lbl_880F47C8;
extern ts4_u32 lbl_880F4868;
extern ts4_u32 lbl_880F4A64;
extern ts4_u32 lbl_880F4A90;
extern ts4_u32 lbl_880F4AD0;
extern ts4_u32 lbl_880F4B10;
extern ts4_u32 lbl_880F4B50;
extern ts4_u32 lbl_880F4B90;
extern ts4_u32 lbl_880F4BD0;
extern ts4_u32 lbl_880F4C10;
extern ts4_u32 lbl_880F4C90;
extern ts4_u32 lbl_880F4CD0;
extern ts4_u32 lbl_880F4D50;
extern ts4_u32 lbl_880F4D8C;
extern ts4_u32 lbl_880F50D4;
extern ts4_u32 lbl_880F53DC;
extern ts4_u32 lbl_880F5FC4;
extern ts4_u32 lbl_880F6024;
extern ts4_u32 lbl_880F6394;
extern ts4_u32 lbl_880F7EE4;
extern const void *const lbl_880F814C[];
extern const void *const lbl_880F8188[];
extern ts4_u32 lbl_880F8310;
extern ts4_u32 lbl_880F8950;
extern ts4_u32 lbl_880F8978;
extern ts4_u32 lbl_880F8D50;

/* Swing_DLL.xex 0x881503C8-0x88150440. */
ts4_u32 fn_881503C8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880C13C0; return value; } return 0; }

/* Swing_DLL.xex 0x88150440-0x881504B8. */
ts4_u32 fn_88150440(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880C13C0; return value; } return 0; }

/* Swing_DLL.xex 0x881504B8-0x88150530. */
ts4_u32 fn_881504B8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880C13E8; return value; } return 0; }

/* Swing_DLL.xex 0x88150530-0x881505A8. */
ts4_u32 fn_88150530(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880C13E8; return value; } return 0; }

/* Swing_DLL.xex 0x881547A0-0x88154818. */
ts4_u32 fn_881547A0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D23E0; return value; } return 0; }

/* Swing_DLL.xex 0x88154818-0x88154890. */
ts4_u32 fn_88154818(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D23E0; return value; } return 0; }

/* Swing_DLL.xex 0x88157FE0-0x88158058. */
ts4_u32 fn_88157FE0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D2D94; return value; } return 0; }

/* Swing_DLL.xex 0x88158058-0x881580D0. */
ts4_u32 fn_88158058(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D2D94; return value; } return 0; }

/* Swing_DLL.xex 0x881682D8-0x88168350. */
ts4_u32 fn_881682D8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D5644; return value; } return 0; }

/* Swing_DLL.xex 0x88168350-0x881683C8. */
ts4_u32 fn_88168350(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D5644; return value; } return 0; }

/* Swing_DLL.xex 0x8816EB58-0x8816EBD0. */
ts4_u32 fn_8816EB58(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D5A3C; return value; } return 0; }

/* Swing_DLL.xex 0x8816EBD0-0x8816EC48. */
ts4_u32 fn_8816EBD0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D5A3C; return value; } return 0; }

/* Swing_DLL.xex 0x88173010-0x88173088. */
ts4_u32 fn_88173010(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D6BC0; return value; } return 0; }

/* Swing_DLL.xex 0x88173088-0x88173100. */
ts4_u32 fn_88173088(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D6BC0; return value; } return 0; }

/* Swing_DLL.xex 0x88174CF0-0x88174D68. */
ts4_u32 fn_88174CF0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D7030; return value; } return 0; }

/* Swing_DLL.xex 0x88174D68-0x88174DE0. */
ts4_u32 fn_88174D68(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880D7030; return value; } return 0; }

/* Swing_DLL.xex 0x88182CA0-0x88182D18. */
ts4_u32 fn_88182CA0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DBDA8; return value; } return 0; }

/* Swing_DLL.xex 0x88182D18-0x88182D90. */
ts4_u32 fn_88182D18(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DBDA8; return value; } return 0; }

/* Swing_DLL.xex 0x88182E40-0x88182EB8. */
ts4_u32 fn_88182E40(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DBE48; return value; } return 0; }

/* Swing_DLL.xex 0x88182EB8-0x88182F30. */
ts4_u32 fn_88182EB8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DBE48; return value; } return 0; }

/* Swing_DLL.xex 0x88182FE0-0x88183058. */
ts4_u32 fn_88182FE0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DBCB4; return value; } return 0; }

/* Swing_DLL.xex 0x88183058-0x881830D0. */
ts4_u32 fn_88183058(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DBCB4; return value; } return 0; }

/* Swing_DLL.xex 0x88183180-0x881831F8. */
ts4_u32 fn_88183180(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB328; return value; } return 0; }

/* Swing_DLL.xex 0x881831F8-0x88183270. */
ts4_u32 fn_881831F8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB328; return value; } return 0; }

/* Swing_DLL.xex 0x88183490-0x88183508. */
ts4_u32 fn_88183490(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB398; return value; } return 0; }

/* Swing_DLL.xex 0x88183508-0x88183580. */
ts4_u32 fn_88183508(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB398; return value; } return 0; }

/* Swing_DLL.xex 0x88183940-0x881839B8. */
ts4_u32 fn_88183940(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 36, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB648; return value; } return 0; }

/* Swing_DLL.xex 0x881839B8-0x88183A30. */
ts4_u32 fn_881839B8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 36, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB648; return value; } return 0; }

/* Swing_DLL.xex 0x88183D40-0x88183DB8. */
ts4_u32 fn_88183D40(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB558; return value; } return 0; }

/* Swing_DLL.xex 0x88183DB8-0x88183E30. */
ts4_u32 fn_88183DB8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB558; return value; } return 0; }

/* Swing_DLL.xex 0x88183F90-0x88184008. */
ts4_u32 fn_88183F90(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB5D0; return value; } return 0; }

/* Swing_DLL.xex 0x88184008-0x88184080. */
ts4_u32 fn_88184008(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB5D0; return value; } return 0; }

/* Swing_DLL.xex 0x88184710-0x88184788. */
ts4_u32 fn_88184710(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB250; return value; } return 0; }

/* Swing_DLL.xex 0x88184788-0x88184800. */
ts4_u32 fn_88184788(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB250; return value; } return 0; }

/* Swing_DLL.xex 0x88184EE0-0x88184F58. */
ts4_u32 fn_88184EE0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB954; return value; } return 0; }

/* Swing_DLL.xex 0x88184F58-0x88184FD0. */
ts4_u32 fn_88184F58(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB954; return value; } return 0; }

/* Swing_DLL.xex 0x88185080-0x881850F8. */
ts4_u32 fn_88185080(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB97C; return value; } return 0; }

/* Swing_DLL.xex 0x881850F8-0x88185170. */
ts4_u32 fn_881850F8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB97C; return value; } return 0; }

/* Swing_DLL.xex 0x881852D0-0x88185348. */
ts4_u32 fn_881852D0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 36, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB834; return value; } return 0; }

/* Swing_DLL.xex 0x88185348-0x881853C0. */
ts4_u32 fn_88185348(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 36, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DB834; return value; } return 0; }

/* Swing_DLL.xex 0x88188CF0-0x88188D68. */
ts4_u32 fn_88188CF0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DC524; return value; } return 0; }

/* Swing_DLL.xex 0x88188D68-0x88188DE0. */
ts4_u32 fn_88188D68(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DC524; return value; } return 0; }

/* Swing_DLL.xex 0x881A4CB0-0x881A4D28. */
ts4_u32 fn_881A4CB0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DD88C; return value; } return 0; }

/* Swing_DLL.xex 0x881A4D28-0x881A4DA0. */
ts4_u32 fn_881A4D28(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DD88C; return value; } return 0; }

/* Swing_DLL.xex 0x881A72A8-0x881A7320. */
ts4_u32 fn_881A72A8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DF940; return value; } return 0; }

/* Swing_DLL.xex 0x881A7320-0x881A7398. */
ts4_u32 fn_881A7320(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880DF940; return value; } return 0; }

/* Swing_DLL.xex 0x881ABE38-0x881ABEB0. */
ts4_u32 fn_881ABE38(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E06B0; return value; } return 0; }

/* Swing_DLL.xex 0x881ABEB0-0x881ABF28. */
ts4_u32 fn_881ABEB0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E06B0; return value; } return 0; }

/* Swing_DLL.xex 0x881AF4B8-0x881AF530. */
ts4_u32 fn_881AF4B8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E1724; return value; } return 0; }

/* Swing_DLL.xex 0x881AF530-0x881AF5A8. */
ts4_u32 fn_881AF530(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E1724; return value; } return 0; }

/* Swing_DLL.xex 0x881B2B90-0x881B2C08. */
ts4_u32 fn_881B2B90(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E3748; return value; } return 0; }

/* Swing_DLL.xex 0x881B2C08-0x881B2C80. */
ts4_u32 fn_881B2C08(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E3748; return value; } return 0; }

/* Swing_DLL.xex 0x881B3D40-0x881B3DB8. */
ts4_u32 fn_881B3D40(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E39A0; return value; } return 0; }

/* Swing_DLL.xex 0x881B3DB8-0x881B3E30. */
ts4_u32 fn_881B3DB8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E39A0; return value; } return 0; }

/* Swing_DLL.xex 0x881B7010-0x881B7088. */
ts4_u32 fn_881B7010(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E3D84; return value; } return 0; }

/* Swing_DLL.xex 0x881B7088-0x881B7100. */
ts4_u32 fn_881B7088(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E3D84; return value; } return 0; }

/* Swing_DLL.xex 0x881B89C8-0x881B8A40. */
ts4_u32 fn_881B89C8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E499C; return value; } return 0; }

/* Swing_DLL.xex 0x881B8A40-0x881B8AB8. */
ts4_u32 fn_881B8A40(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E499C; return value; } return 0; }

/* Swing_DLL.xex 0x881BA288-0x881BA300. */
ts4_u32 fn_881BA288(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E4C64; return value; } return 0; }

/* Swing_DLL.xex 0x881BA300-0x881BA378. */
ts4_u32 fn_881BA300(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E4C64; return value; } return 0; }

/* Swing_DLL.xex 0x881BC478-0x881BC4F0. */
ts4_u32 fn_881BC478(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E70AC; return value; } return 0; }

/* Swing_DLL.xex 0x881BC4F0-0x881BC568. */
ts4_u32 fn_881BC4F0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E70AC; return value; } return 0; }

/* Swing_DLL.xex 0x881BC568-0x881BC5E0. */
ts4_u32 fn_881BC568(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E7084; return value; } return 0; }

/* Swing_DLL.xex 0x881BC5E0-0x881BC658. */
ts4_u32 fn_881BC5E0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880E7084; return value; } return 0; }

/* Swing_DLL.xex 0x881BC7B8-0x881BC838. */
ts4_u32 fn_881BC7B8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7140; return value; } return 0; }

/* Swing_DLL.xex 0x881BC838-0x881BC8B8. */
ts4_u32 fn_881BC838(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7140; return value; } return 0; }

/* Swing_DLL.xex 0x881BC8B8-0x881BC938. */
ts4_u32 fn_881BC8B8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7168; return value; } return 0; }

/* Swing_DLL.xex 0x881BC938-0x881BC9B8. */
ts4_u32 fn_881BC938(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7168; return value; } return 0; }

/* Swing_DLL.xex 0x881BC9B8-0x881BCA38. */
ts4_u32 fn_881BC9B8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7230; return value; } return 0; }

/* Swing_DLL.xex 0x881BCA38-0x881BCAB8. */
ts4_u32 fn_881BCA38(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7230; return value; } return 0; }

/* Swing_DLL.xex 0x881BCAB8-0x881BCB38. */
ts4_u32 fn_881BCAB8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7258; return value; } return 0; }

/* Swing_DLL.xex 0x881BCB38-0x881BCBB8. */
ts4_u32 fn_881BCB38(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7258; return value; } return 0; }

/* Swing_DLL.xex 0x881BCBB8-0x881BCC38. */
ts4_u32 fn_881BCBB8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E71E0; return value; } return 0; }

/* Swing_DLL.xex 0x881BCC38-0x881BCCB8. */
ts4_u32 fn_881BCC38(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E71E0; return value; } return 0; }

/* Swing_DLL.xex 0x881BCCB8-0x881BCD38. */
ts4_u32 fn_881BCCB8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7208; return value; } return 0; }

/* Swing_DLL.xex 0x881BCD38-0x881BCDB8. */
ts4_u32 fn_881BCD38(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7208; return value; } return 0; }

/* Swing_DLL.xex 0x881BCDB8-0x881BCE38. */
ts4_u32 fn_881BCDB8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7190; return value; } return 0; }

/* Swing_DLL.xex 0x881BCE38-0x881BCEB8. */
ts4_u32 fn_881BCE38(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E7190; return value; } return 0; }

/* Swing_DLL.xex 0x881BCEB8-0x881BCF38. */
ts4_u32 fn_881BCEB8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E71B8; return value; } return 0; }

/* Swing_DLL.xex 0x881BCF38-0x881BCFB8. */
ts4_u32 fn_881BCF38(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E71B8; return value; } return 0; }

/* Swing_DLL.xex 0x88216030-0x882160A8. */
ts4_u32 fn_88216030(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880EF958; return value; } return 0; }

/* Swing_DLL.xex 0x882170B8-0x88217130. */
ts4_u32 fn_882170B8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880EF9D0; return value; } return 0; }

/* Swing_DLL.xex 0x88217130-0x882171A8. */
ts4_u32 fn_88217130(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880EF9D0; return value; } return 0; }

/* Swing_DLL.xex 0x88217340-0x882173B8. */
ts4_u32 fn_88217340(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880EF958; return value; } return 0; }

/* Swing_DLL.xex 0x88219F80-0x88219FF8. */
ts4_u32 fn_88219F80(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880EFC8C; return value; } return 0; }

/* Swing_DLL.xex 0x88219FF8-0x8821A070. */
ts4_u32 fn_88219FF8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880EFC8C; return value; } return 0; }

/* Swing_DLL.xex 0x8821A660-0x8821A6D8. */
ts4_u32 fn_8821A660(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880EFE8C; return value; } return 0; }

/* Swing_DLL.xex 0x8821A6D8-0x8821A750. */
ts4_u32 fn_8821A6D8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880EFE8C; return value; } return 0; }

/* Swing_DLL.xex 0x88235830-0x882358A8. */
ts4_u32 fn_88235830(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F30CC; return value; } return 0; }

/* Swing_DLL.xex 0x882358A8-0x88235920. */
ts4_u32 fn_882358A8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F30CC; return value; } return 0; }

/* Swing_DLL.xex 0x88235920-0x882359A0. */
ts4_u32 fn_88235920(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F311C; return value; } return 0; }

/* Swing_DLL.xex 0x882359A0-0x88235A20. */
ts4_u32 fn_882359A0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F311C; return value; } return 0; }

/* Swing_DLL.xex 0x88235A20-0x88235AA0. */
ts4_u32 fn_88235A20(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F30F4; return value; } return 0; }

/* Swing_DLL.xex 0x88235AA0-0x88235B20. */
ts4_u32 fn_88235AA0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F30F4; return value; } return 0; }

/* Swing_DLL.xex 0x882621C8-0x88262240. */
ts4_u32 fn_882621C8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F3494; return value; } return 0; }

/* Swing_DLL.xex 0x88262240-0x882622B8. */
ts4_u32 fn_88262240(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F3494; return value; } return 0; }

/* Swing_DLL.xex 0x88267328-0x882673A0. */
ts4_u32 fn_88267328(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F3804; return value; } return 0; }

/* Swing_DLL.xex 0x882673A0-0x88267418. */
ts4_u32 fn_882673A0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F3804; return value; } return 0; }

/* Swing_DLL.xex 0x88267418-0x88267498. */
ts4_u32 fn_88267418(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F37DC; return value; } return 0; }

/* Swing_DLL.xex 0x88267498-0x88267518. */
ts4_u32 fn_88267498(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F37DC; return value; } return 0; }

/* Swing_DLL.xex 0x8826E738-0x8826E7B8. */
ts4_u32 fn_8826E738(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4678; return value; } return 0; }

/* Swing_DLL.xex 0x8826E7B8-0x8826E838. */
ts4_u32 fn_8826E7B8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4678; return value; } return 0; }

/* Swing_DLL.xex 0x8826E908-0x8826E988. */
ts4_u32 fn_8826E908(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 36, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4788; return value; } return 0; }

/* Swing_DLL.xex 0x8826E988-0x8826EA08. */
ts4_u32 fn_8826E988(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 36, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4788; return value; } return 0; }

/* Swing_DLL.xex 0x8826EA08-0x8826EA88. */
ts4_u32 fn_8826EA08(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 36, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F47C8; return value; } return 0; }

/* Swing_DLL.xex 0x8826EA88-0x8826EB08. */
ts4_u32 fn_8826EA88(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 36, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F47C8; return value; } return 0; }

/* Swing_DLL.xex 0x8826ED88-0x8826EE08. */
ts4_u32 fn_8826ED88(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4868; return value; } return 0; }

/* Swing_DLL.xex 0x8826EE08-0x8826EE88. */
ts4_u32 fn_8826EE08(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4868; return value; } return 0; }

/* Swing_DLL.xex 0x8826EF38-0x8826EFB0. */
ts4_u32 fn_8826EF38(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F4A64; return value; } return 0; }

/* Swing_DLL.xex 0x8826EFB0-0x8826F028. */
ts4_u32 fn_8826EFB0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F4A64; return value; } return 0; }

/* Swing_DLL.xex 0x8826F028-0x8826F0A8. */
ts4_u32 fn_8826F028(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4A90; return value; } return 0; }

/* Swing_DLL.xex 0x8826F0A8-0x8826F128. */
ts4_u32 fn_8826F0A8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4A90; return value; } return 0; }

/* Swing_DLL.xex 0x8826F128-0x8826F1A8. */
ts4_u32 fn_8826F128(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4AD0; return value; } return 0; }

/* Swing_DLL.xex 0x8826F1A8-0x8826F228. */
ts4_u32 fn_8826F1A8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4AD0; return value; } return 0; }

/* Swing_DLL.xex 0x8826F228-0x8826F2A8. */
ts4_u32 fn_8826F228(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4B10; return value; } return 0; }

/* Swing_DLL.xex 0x8826F2A8-0x8826F328. */
ts4_u32 fn_8826F2A8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4B10; return value; } return 0; }

/* Swing_DLL.xex 0x8826F328-0x8826F3A8. */
ts4_u32 fn_8826F328(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4B50; return value; } return 0; }

/* Swing_DLL.xex 0x8826F3A8-0x8826F428. */
ts4_u32 fn_8826F3A8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4B50; return value; } return 0; }

/* Swing_DLL.xex 0x8826F428-0x8826F4A8. */
ts4_u32 fn_8826F428(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4B90; return value; } return 0; }

/* Swing_DLL.xex 0x8826F4A8-0x8826F528. */
ts4_u32 fn_8826F4A8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4B90; return value; } return 0; }

/* Swing_DLL.xex 0x8826F688-0x8826F708. */
ts4_u32 fn_8826F688(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4BD0; return value; } return 0; }

/* Swing_DLL.xex 0x8826F708-0x8826F788. */
ts4_u32 fn_8826F708(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4BD0; return value; } return 0; }

/* Swing_DLL.xex 0x8826F788-0x8826F808. */
ts4_u32 fn_8826F788(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 48, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4C10; return value; } return 0; }

/* Swing_DLL.xex 0x8826F808-0x8826F888. */
ts4_u32 fn_8826F808(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 48, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4C10; return value; } return 0; }

/* Swing_DLL.xex 0x8826F938-0x8826F9B8. */
ts4_u32 fn_8826F938(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4C90; return value; } return 0; }

/* Swing_DLL.xex 0x8826F9B8-0x8826FA38. */
ts4_u32 fn_8826F9B8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4C90; return value; } return 0; }

/* Swing_DLL.xex 0x8826FA38-0x8826FAB8. */
ts4_u32 fn_8826FA38(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4CD0; return value; } return 0; }

/* Swing_DLL.xex 0x8826FAB8-0x8826FB38. */
ts4_u32 fn_8826FAB8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4CD0; return value; } return 0; }

/* Swing_DLL.xex 0x8826FBE8-0x8826FC68. */
ts4_u32 fn_8826FBE8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4D50; return value; } return 0; }

/* Swing_DLL.xex 0x8826FC68-0x8826FCE8. */
ts4_u32 fn_8826FC68(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4D50; return value; } return 0; }

/* Swing_DLL.xex 0x8826FCE8-0x8826FD68. */
ts4_u32 fn_8826FCE8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4D8C; return value; } return 0; }

/* Swing_DLL.xex 0x8826FD68-0x8826FDE8. */
ts4_u32 fn_8826FD68(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4D8C; return value; } return 0; }

/* Swing_DLL.xex 0x88273968-0x882739E0. */
ts4_u32 fn_88273968(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F50D4; return value; } return 0; }

/* Swing_DLL.xex 0x882739E0-0x88273A58. */
ts4_u32 fn_882739E0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F50D4; return value; } return 0; }

/* Swing_DLL.xex 0x882760F0-0x88276168. */
ts4_u32 fn_882760F0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F53DC; return value; } return 0; }

/* Swing_DLL.xex 0x88276168-0x882761E0. */
ts4_u32 fn_88276168(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F53DC; return value; } return 0; }

/* Swing_DLL.xex 0x88279708-0x88279780. */
ts4_u32 fn_88279708(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F5FC4; return value; } return 0; }

/* Swing_DLL.xex 0x88279780-0x882797F8. */
ts4_u32 fn_88279780(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F5FC4; return value; } return 0; }

/* Swing_DLL.xex 0x882798A8-0x88279928. */
ts4_u32 fn_882798A8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F6024; return value; } return 0; }

/* Swing_DLL.xex 0x88279928-0x882799A8. */
ts4_u32 fn_88279928(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 32, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)(value + 28) = (ts4_u32)0; *(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F6024; return value; } return 0; }

/* Swing_DLL.xex 0x8827C498-0x8827C510. */
ts4_u32 fn_8827C498(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F6394; return value; } return 0; }

/* Swing_DLL.xex 0x8827C510-0x8827C588. */
ts4_u32 fn_8827C510(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F6394; return value; } return 0; }

/* Swing_DLL.xex 0x88283D78-0x88283DF0. */
ts4_u32 fn_88283D78(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F7EE4; return value; } return 0; }

/* Swing_DLL.xex 0x88283DF0-0x88283E68. */
ts4_u32 fn_88283DF0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F7EE4; return value; } return 0; }

/* Swing_DLL.xex 0x882841F8-0x88284270. */
ts4_u32 fn_882841F8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F814C; return value; } return 0; }

/* Swing_DLL.xex 0x88284270-0x882842E8. */
ts4_u32 fn_88284270(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F814C; return value; } return 0; }

/* Swing_DLL.xex 0x882842E8-0x88284360. */
ts4_u32 fn_882842E8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F8188; return value; } return 0; }

/* Swing_DLL.xex 0x88284360-0x882843D8. */
ts4_u32 fn_88284360(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F8188; return value; } return 0; }

/* Swing_DLL.xex 0x88284538-0x882845B0. */
ts4_u32 fn_88284538(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F8310; return value; } return 0; }

/* Swing_DLL.xex 0x882845B0-0x88284628. */
ts4_u32 fn_882845B0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F8310; return value; } return 0; }

/* Swing_DLL.xex 0x88284E28-0x88284EA0. */
ts4_u32 fn_88284E28(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F8950; return value; } return 0; }

/* Swing_DLL.xex 0x88284EA0-0x88284F18. */
ts4_u32 fn_88284EA0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F8950; return value; } return 0; }

/* Swing_DLL.xex 0x88284F18-0x88284F90. */
ts4_u32 fn_88284F18(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F8978; return value; } return 0; }

/* Swing_DLL.xex 0x88284F90-0x88285008. */
ts4_u32 fn_88284F90(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 28, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F8978; return value; } return 0; }

/* Swing_DLL.xex 0x88285D48-0x88285DC0. */
ts4_u32 fn_88285D48(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 40, 4, 0, 2); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F8D50; return value; } return 0; }

/* Swing_DLL.xex 0x88285DC0-0x88285E38. */
ts4_u32 fn_88285DC0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 40, 4, 0, 0); if (value != 0) { fn_88617D88((void *)value); *(ts4_u32 *)value = (ts4_u32)&lbl_880F8D50; return value; } return 0; }
