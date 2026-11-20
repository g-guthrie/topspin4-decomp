/* Scalar-deleting destructors without a base destructor call */
typedef unsigned int u32;

typedef struct Ts4Object {
    void *vtable;
} Ts4Object;

extern void ts4_tsu_cleanup_end(Ts4Object *object);

extern char lbl_880D1F18;
extern char lbl_880D5B34;
extern char lbl_880D5A64;
extern char lbl_880D5C10;
extern char lbl_880D6B70;
extern char lbl_880D63EC;
extern char lbl_880DBE70;
extern char lbl_880DB2A4;
extern char lbl_880DC604;
extern char lbl_8803A308;
extern char lbl_880DD088;
extern char lbl_880DD750;
extern char lbl_88087B80;
extern char lbl_88088DD4;
extern char lbl_880E165C;
extern char lbl_880E3EE4;
extern void fn_881BD828(Ts4Object *object);
extern char lbl_880F2298;
extern char lbl_880F27B4;
extern char lbl_880F2480;
extern char lbl_880F3378;
extern char lbl_880F336C;
extern char lbl_880F228C;
extern char lbl_880F213C;
extern char lbl_880F3784;
extern char lbl_880F4460;
extern char lbl_880F436C;
extern char lbl_880F48B8;
extern char lbl_880F4508;
extern char lbl_880F45D0;
extern char lbl_880F799C;
extern char lbl_880F9018;
extern char lbl_880D19F0;
extern char lbl_880F907C;
extern char lbl_880F909C;
extern char lbl_880F93F8;
extern char lbl_88028B5C;
extern char lbl_88029324;

/* Installs a vtable, then releases the object when bit 0 of delete_flags is set (no base destructor call). */
#define TS4_DTOR(name, vtable_symbol, release) \
    Ts4Object *name(Ts4Object *object, u32 delete_flags) \
    { \
        object->vtable = &vtable_symbol; \
        if ((delete_flags & 1U) != 0) { \
            release(object); \
        } \
        return object; \
    }

TS4_DTOR(ts4_dtor_vtable_only_88156EB0, lbl_880D1F18, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88156EB0 */
TS4_DTOR(ts4_dtor_vtable_only_88156FC0, lbl_880D5B34, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88156FC0 */
TS4_DTOR(ts4_dtor_vtable_only_88157AD0, lbl_880D5A64, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88157AD0 */
TS4_DTOR(ts4_dtor_vtable_only_8816D510, lbl_880D5C10, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8816D510 */
TS4_DTOR(ts4_dtor_vtable_only_8816F628, lbl_880D6B70, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8816F628 */
TS4_DTOR(ts4_dtor_vtable_only_8816F6C0, lbl_880D63EC, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8816F6C0 */
TS4_DTOR(ts4_dtor_vtable_only_88177938, lbl_880D6B70, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88177938 */
TS4_DTOR(ts4_dtor_vtable_only_8817BB28, lbl_880DBE70, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8817BB28 */
TS4_DTOR(ts4_dtor_vtable_only_8817D9B8, lbl_880DB2A4, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8817D9B8 */
TS4_DTOR(ts4_dtor_vtable_only_88188648, lbl_880DC604, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88188648 */
TS4_DTOR(ts4_dtor_vtable_only_8818A0A0, lbl_8803A308, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8818A0A0 */
TS4_DTOR(ts4_dtor_vtable_only_8818B5F8, lbl_880DD088, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8818B5F8 */
TS4_DTOR(ts4_dtor_vtable_only_88199A28, lbl_880DD750, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88199A28 */
TS4_DTOR(ts4_dtor_vtable_only_881A7790, lbl_88087B80, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x881A7790 */
TS4_DTOR(ts4_dtor_vtable_only_881A77D8, lbl_88088DD4, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x881A77D8 */
TS4_DTOR(ts4_dtor_vtable_only_881AD588, lbl_880E165C, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x881AD588 */
TS4_DTOR(ts4_dtor_vtable_only_881B7F68, lbl_880E3EE4, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x881B7F68 */
TS4_DTOR(ts4_dtor_vtable_only_881BDB58, lbl_880DD088, fn_881BD828) /* Swing_DLL.xex 0x881BDB58 */
TS4_DTOR(ts4_dtor_vtable_only_8821C070, lbl_880F2298, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8821C070 */
TS4_DTOR(ts4_dtor_vtable_only_8821C1F0, lbl_880F27B4, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8821C1F0 */
TS4_DTOR(ts4_dtor_vtable_only_8821C238, lbl_880F2480, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8821C238 */
TS4_DTOR(ts4_dtor_vtable_only_8821C368, lbl_880F3378, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8821C368 */
TS4_DTOR(ts4_dtor_vtable_only_8821CA78, lbl_880F336C, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8821CA78 */
TS4_DTOR(ts4_dtor_vtable_only_88224E18, lbl_880F228C, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88224E18 */
TS4_DTOR(ts4_dtor_vtable_only_88260920, lbl_880F228C, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88260920 */
TS4_DTOR(ts4_dtor_vtable_only_88261C28, lbl_880F213C, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88261C28 */
TS4_DTOR(ts4_dtor_vtable_only_88262CF8, lbl_880F3784, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88262CF8 */
TS4_DTOR(ts4_dtor_vtable_only_88269F18, lbl_880F4460, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88269F18 */
TS4_DTOR(ts4_dtor_vtable_only_8826A478, lbl_880F436C, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8826A478 */
TS4_DTOR(ts4_dtor_vtable_only_8826A758, lbl_880F48B8, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8826A758 */
TS4_DTOR(ts4_dtor_vtable_only_8826A7F0, lbl_880F4508, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8826A7F0 */
TS4_DTOR(ts4_dtor_vtable_only_8826ABC8, lbl_880F45D0, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8826ABC8 */
TS4_DTOR(ts4_dtor_vtable_only_882712C8, lbl_880F3784, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x882712C8 */
TS4_DTOR(ts4_dtor_vtable_only_8827CE68, lbl_880F799C, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8827CE68 */
TS4_DTOR(ts4_dtor_vtable_only_8827FF10, lbl_880F9018, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x8827FF10 */
TS4_DTOR(ts4_dtor_vtable_only_88286DD0, lbl_880D19F0, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88286DD0 */
TS4_DTOR(ts4_dtor_vtable_only_88287040, lbl_880F907C, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88287040 */
TS4_DTOR(ts4_dtor_vtable_only_882870F8, lbl_880F909C, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x882870F8 */
TS4_DTOR(ts4_dtor_vtable_only_882871E0, lbl_880F93F8, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x882871E0 */
TS4_DTOR(ts4_dtor_vtable_only_88309A48, lbl_88028B5C, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88309A48 */
TS4_DTOR(ts4_dtor_vtable_only_88331528, lbl_88029324, ts4_tsu_cleanup_end) /* Swing_DLL.xex 0x88331528 */
