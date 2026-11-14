/* Constructors: run base constructor, then install derived vtable */
typedef struct Ts4Object { void *vtable; } Ts4Object;
extern void fn_88617D88(Ts4Object *object);
extern void fn_8841B550(Ts4Object *object);
extern void fn_88723B58(Ts4Object *object);
extern void fn_88723BE0(Ts4Object *object);
extern void fn_88723C70(Ts4Object *object);
extern void fn_8872CD50(Ts4Object *object);
extern void fn_8873C048(Ts4Object *object);
extern void fn_887EC668(Ts4Object *object);
extern void ts4_call_seq_fn_887F4BA0_887F5400(Ts4Object *object);
extern void fn_888B1D08(Ts4Object *object);
extern char lbl_880F8978;
extern char lbl_880F8950;
extern char lbl_880F8188;
extern char lbl_880F814C;
extern char lbl_880F8D50;
extern char lbl_880F3144;
extern char lbl_880F33E0;
extern char lbl_880F28EC;
extern char lbl_880F2E18;
extern char lbl_880F2DA8;
extern char lbl_880F2D38;
extern char lbl_880F3018;
extern char lbl_880F2E88;
extern char lbl_880EA60C;
extern char lbl_880EA318;
extern char lbl_880E7084;
extern char lbl_880E46C8;
extern char lbl_880DCE70;
extern char lbl_880DC680;
extern char lbl_880DB834;
extern char lbl_880DB97C;
extern char lbl_880DB954;
extern char lbl_880DB250;
extern char lbl_880DB5D0;
extern char lbl_880DB558;
extern char lbl_880DB648;
extern char lbl_880DB398;
extern char lbl_880DB328;
extern char lbl_880DBCB4;
extern char lbl_880DBDA8;
extern char lbl_880D7030;
extern char lbl_880D6BC0;
extern char lbl_880D5A3C;

/* Calls base_ctor on object, then stores the address of vtable_symbol at offset 0. */
#define TS4_CTOR(name, base_ctor, vtable_symbol) \
    Ts4Object *name(Ts4Object *object) \
    { \
        base_ctor(object); \
        object->vtable = &vtable_symbol; \
        return object; \
    }

TS4_CTOR(ts4_ctor_set_vtable_886188B0, fn_88617D88, lbl_880F8978) /* Swing_DLL.xex 0x886188B0 */
TS4_CTOR(ts4_ctor_set_vtable_88618900, fn_88617D88, lbl_880F8950) /* Swing_DLL.xex 0x88618900 */
TS4_CTOR(ts4_ctor_set_vtable_8861B248, fn_88617D88, lbl_880F8188) /* Swing_DLL.xex 0x8861B248 */
TS4_CTOR(ts4_ctor_set_vtable_8861B298, fn_88617D88, lbl_880F814C) /* Swing_DLL.xex 0x8861B298 */
TS4_CTOR(ts4_ctor_set_vtable_8861DB00, fn_88617D88, lbl_880F8D50) /* Swing_DLL.xex 0x8861DB00 */
TS4_CTOR(ts4_ctor_set_vtable_886F8CE0, fn_88617D88, lbl_880F3144) /* Swing_DLL.xex 0x886F8CE0 */
TS4_CTOR(ts4_ctor_set_vtable_88702490, fn_88617D88, lbl_880F33E0) /* Swing_DLL.xex 0x88702490 */
TS4_CTOR(ts4_ctor_set_vtable_88710478, fn_88617D88, lbl_880F28EC) /* Swing_DLL.xex 0x88710478 */
TS4_CTOR(ts4_ctor_set_vtable_8872B9A8, fn_88723B58, lbl_880F2E18) /* Swing_DLL.xex 0x8872B9A8 */
TS4_CTOR(ts4_ctor_set_vtable_8872B9E8, fn_88723BE0, lbl_880F2DA8) /* Swing_DLL.xex 0x8872B9E8 */
TS4_CTOR(ts4_ctor_set_vtable_8872BA28, fn_88723C70, lbl_880F2D38) /* Swing_DLL.xex 0x8872BA28 */
TS4_CTOR(ts4_ctor_set_vtable_88732100, fn_8872CD50, lbl_880F3018) /* Swing_DLL.xex 0x88732100 */
TS4_CTOR(ts4_ctor_set_vtable_8874AD88, fn_8873C048, lbl_880F2E88) /* Swing_DLL.xex 0x8874AD88 */
TS4_CTOR(ts4_ctor_set_vtable_887C7E30, fn_88617D88, lbl_880EA60C) /* Swing_DLL.xex 0x887C7E30 */
TS4_CTOR(ts4_ctor_set_vtable_887CC040, fn_887EC668, lbl_880EA318) /* Swing_DLL.xex 0x887CC040 */
TS4_CTOR(ts4_ctor_set_vtable_887D3108, fn_88617D88, lbl_880E7084) /* Swing_DLL.xex 0x887D3108 */
TS4_CTOR(ts4_ctor_set_vtable_887F5598, ts4_call_seq_fn_887F4BA0_887F5400, lbl_880E46C8) /* Swing_DLL.xex 0x887F5598 */
TS4_CTOR(ts4_ctor_set_vtable_88890288, fn_8841B550, lbl_880DCE70) /* Swing_DLL.xex 0x88890288 */
TS4_CTOR(ts4_ctor_set_vtable_888B82F8, fn_888B1D08, lbl_880DC680) /* Swing_DLL.xex 0x888B82F8 */
TS4_CTOR(ts4_ctor_set_vtable_888C7850, fn_88617D88, lbl_880DB834) /* Swing_DLL.xex 0x888C7850 */
TS4_CTOR(ts4_ctor_set_vtable_888C79F8, fn_88617D88, lbl_880DB97C) /* Swing_DLL.xex 0x888C79F8 */
TS4_CTOR(ts4_ctor_set_vtable_888C7F98, fn_88617D88, lbl_880DB954) /* Swing_DLL.xex 0x888C7F98 */
TS4_CTOR(ts4_ctor_set_vtable_888CA568, fn_88617D88, lbl_880DB250) /* Swing_DLL.xex 0x888CA568 */
TS4_CTOR(ts4_ctor_set_vtable_888CADF0, fn_88617D88, lbl_880DB5D0) /* Swing_DLL.xex 0x888CADF0 */
TS4_CTOR(ts4_ctor_set_vtable_888CB088, fn_88617D88, lbl_880DB558) /* Swing_DLL.xex 0x888CB088 */
TS4_CTOR(ts4_ctor_set_vtable_888CB918, fn_88617D88, lbl_880DB648) /* Swing_DLL.xex 0x888CB918 */
TS4_CTOR(ts4_ctor_set_vtable_888CCBA8, fn_88617D88, lbl_880DB398) /* Swing_DLL.xex 0x888CCBA8 */
TS4_CTOR(ts4_ctor_set_vtable_888CDD48, fn_88617D88, lbl_880DB328) /* Swing_DLL.xex 0x888CDD48 */
TS4_CTOR(ts4_ctor_set_vtable_888CDF28, fn_88617D88, lbl_880DBCB4) /* Swing_DLL.xex 0x888CDF28 */
TS4_CTOR(ts4_ctor_set_vtable_888CEDB8, fn_88617D88, lbl_880DBDA8) /* Swing_DLL.xex 0x888CEDB8 */
TS4_CTOR(ts4_ctor_set_vtable_88912FA8, fn_88617D88, lbl_880D7030) /* Swing_DLL.xex 0x88912FA8 */
TS4_CTOR(ts4_ctor_set_vtable_88918428, fn_88617D88, lbl_880D6BC0) /* Swing_DLL.xex 0x88918428 */
TS4_CTOR(ts4_ctor_set_vtable_88937598, fn_88617D88, lbl_880D5A3C) /* Swing_DLL.xex 0x88937598 */
