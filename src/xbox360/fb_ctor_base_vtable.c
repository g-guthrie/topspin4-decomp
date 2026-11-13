/* Constructors: base ctor, zero field at 0x1C, vtable */
typedef unsigned int u32;

typedef struct Ts4Object {
    void *vtable;
} Ts4Object;

extern void ts4_tsu_cleanup_end(Ts4Object *object);

extern char lbl_880F6024;
extern void fn_88617D88(Ts4Object *object);
extern char lbl_880F4550;
extern char lbl_880F43A4;
extern char lbl_880F4748;
extern char lbl_880F47C8;
extern char lbl_880F4788;
extern char lbl_880F4590;
extern char lbl_880F4D8C;
extern char lbl_880F4D50;
extern char lbl_880F4CD0;
extern char lbl_880F4C90;
extern char lbl_880F4C10;
extern char lbl_880F4BD0;
extern char lbl_880F4B90;
extern char lbl_880F4B50;
extern char lbl_880F4B10;
extern char lbl_880F4AD0;
extern char lbl_880F4A90;
extern char lbl_880F4678;
extern char lbl_880F37DC;
extern char lbl_880F311C;
extern char lbl_880F30F4;
extern char lbl_880E7258;
extern char lbl_880E7230;
extern char lbl_880E7208;
extern char lbl_880E71E0;
extern char lbl_880E71B8;
extern char lbl_880E7190;
extern char lbl_880E7168;
extern char lbl_880E7140;

/* Runs the base constructor, clears the u32 at offset 0x1C, then installs the derived vtable. */
typedef struct Ts4Object28 {
    void *vtable;
    char base_fields[24];
    u32 field_1c;
} Ts4Object28;
#define TS4_CTOR(name, vtable_symbol, base_ctor) \
    Ts4Object28 *name(Ts4Object28 *object) \
    { \
        base_ctor((Ts4Object *)object); \
        object->field_1c = 0; \
        object->vtable = &vtable_symbol; \
        return object; \
    }

TS4_CTOR(ts4_ctor_base_vtable_886471B8, lbl_880F6024, fn_88617D88) /* Swing_DLL.xex 0x886471B8 */
TS4_CTOR(ts4_ctor_base_vtable_8867A020, lbl_880F4550, fn_88617D88) /* Swing_DLL.xex 0x8867A020 */
TS4_CTOR(ts4_ctor_base_vtable_8867A130, lbl_880F43A4, fn_88617D88) /* Swing_DLL.xex 0x8867A130 */
TS4_CTOR(ts4_ctor_base_vtable_8867BA00, lbl_880F4748, fn_88617D88) /* Swing_DLL.xex 0x8867BA00 */
TS4_CTOR(ts4_ctor_base_vtable_8867D780, lbl_880F47C8, fn_88617D88) /* Swing_DLL.xex 0x8867D780 */
TS4_CTOR(ts4_ctor_base_vtable_8867D958, lbl_880F4788, fn_88617D88) /* Swing_DLL.xex 0x8867D958 */
TS4_CTOR(ts4_ctor_base_vtable_8867DEA8, lbl_880F4590, fn_88617D88) /* Swing_DLL.xex 0x8867DEA8 */
TS4_CTOR(ts4_ctor_base_vtable_886815A0, lbl_880F4D8C, fn_88617D88) /* Swing_DLL.xex 0x886815A0 */
TS4_CTOR(ts4_ctor_base_vtable_88681720, lbl_880F4D50, fn_88617D88) /* Swing_DLL.xex 0x88681720 */
TS4_CTOR(ts4_ctor_base_vtable_88681EF8, lbl_880F4CD0, fn_88617D88) /* Swing_DLL.xex 0x88681EF8 */
TS4_CTOR(ts4_ctor_base_vtable_88682078, lbl_880F4C90, fn_88617D88) /* Swing_DLL.xex 0x88682078 */
TS4_CTOR(ts4_ctor_base_vtable_88682E18, lbl_880F4C10, fn_88617D88) /* Swing_DLL.xex 0x88682E18 */
TS4_CTOR(ts4_ctor_base_vtable_88682F98, lbl_880F4BD0, fn_88617D88) /* Swing_DLL.xex 0x88682F98 */
TS4_CTOR(ts4_ctor_base_vtable_8868CAD0, lbl_880F4B90, fn_88617D88) /* Swing_DLL.xex 0x8868CAD0 */
TS4_CTOR(ts4_ctor_base_vtable_8868CF50, lbl_880F4B50, fn_88617D88) /* Swing_DLL.xex 0x8868CF50 */
TS4_CTOR(ts4_ctor_base_vtable_8868D0D0, lbl_880F4B10, fn_88617D88) /* Swing_DLL.xex 0x8868D0D0 */
TS4_CTOR(ts4_ctor_base_vtable_8868D250, lbl_880F4AD0, fn_88617D88) /* Swing_DLL.xex 0x8868D250 */
TS4_CTOR(ts4_ctor_base_vtable_8868D3D0, lbl_880F4A90, fn_88617D88) /* Swing_DLL.xex 0x8868D3D0 */
TS4_CTOR(ts4_ctor_base_vtable_88693F60, lbl_880F4678, fn_88617D88) /* Swing_DLL.xex 0x88693F60 */
TS4_CTOR(ts4_ctor_base_vtable_886CD1A0, lbl_880F37DC, fn_88617D88) /* Swing_DLL.xex 0x886CD1A0 */
TS4_CTOR(ts4_ctor_base_vtable_886F8E88, lbl_880F311C, fn_88617D88) /* Swing_DLL.xex 0x886F8E88 */
TS4_CTOR(ts4_ctor_base_vtable_886F8ED0, lbl_880F30F4, fn_88617D88) /* Swing_DLL.xex 0x886F8ED0 */
TS4_CTOR(ts4_ctor_base_vtable_887D2BE8, lbl_880E7258, fn_88617D88) /* Swing_DLL.xex 0x887D2BE8 */
TS4_CTOR(ts4_ctor_base_vtable_887D2C58, lbl_880E7230, fn_88617D88) /* Swing_DLL.xex 0x887D2C58 */
TS4_CTOR(ts4_ctor_base_vtable_887D2CC8, lbl_880E7208, fn_88617D88) /* Swing_DLL.xex 0x887D2CC8 */
TS4_CTOR(ts4_ctor_base_vtable_887D2D38, lbl_880E71E0, fn_88617D88) /* Swing_DLL.xex 0x887D2D38 */
TS4_CTOR(ts4_ctor_base_vtable_887D2DA8, lbl_880E71B8, fn_88617D88) /* Swing_DLL.xex 0x887D2DA8 */
TS4_CTOR(ts4_ctor_base_vtable_887D2E18, lbl_880E7190, fn_88617D88) /* Swing_DLL.xex 0x887D2E18 */
TS4_CTOR(ts4_ctor_base_vtable_887D2E88, lbl_880E7168, fn_88617D88) /* Swing_DLL.xex 0x887D2E88 */
TS4_CTOR(ts4_ctor_base_vtable_887D2EF8, lbl_880E7140, fn_88617D88) /* Swing_DLL.xex 0x887D2EF8 */
