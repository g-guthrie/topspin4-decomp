/* Scalar-deleting destructors that reset the vtable first */
typedef unsigned int u32;

typedef struct Ts4Object {
    void *vtable;
} Ts4Object;

extern void ts4_tsu_cleanup_end(Ts4Object *object);

extern char lbl_880C13C0;
extern void fn_88617D28(Ts4Object *object);
extern char lbl_880C13E8;
extern char lbl_880D23E0;
extern char lbl_880D24B8;
extern char lbl_880D24E0;
extern char lbl_880D2D94;
extern char lbl_880D2D10;
extern void fn_88935DF8(Ts4Object *object);
extern char lbl_880D2A68;
extern void fn_88934458(Ts4Object *object);
extern char lbl_880D2E4C;
extern void fn_88937648(Ts4Object *object);
extern char lbl_880D4C88;
extern void fn_8815F140(Ts4Object *object);
extern char lbl_880D5240;
extern void fn_88955818(Ts4Object *object);
extern char lbl_880D5528;
extern void fn_88951608(Ts4Object *object);
extern char lbl_880D5570;
extern char lbl_880D55B8;
extern char lbl_880D5600;
extern char lbl_880D5A3C;
extern char lbl_880D6470;
extern void fn_889293A0(Ts4Object *object);
extern char lbl_880D6898;
extern char lbl_880D66B0;
extern char lbl_880D67D0;
extern char lbl_880D6590;
extern char lbl_880D6968;
extern char lbl_880D2CF8;
extern void fn_8893B3E0(Ts4Object *object);
extern char lbl_880D7030;
extern char lbl_880D7228;
extern void fn_8860BBD8(Ts4Object *object);
extern char lbl_880D7244;
extern char lbl_880D7310;
extern void ts4_if_call_seq_lbl_880D72B0_88912A38(Ts4Object *object);
extern char lbl_880D7380;
extern char lbl_880D73C4;
extern char lbl_880D73FC;
extern char lbl_880DBD30;
extern char lbl_880DBDA8;
extern char lbl_880DBDD0;
extern char lbl_880DBE48;
extern char lbl_880DBCB4;
extern char lbl_880DB328;
extern char lbl_880DB3C0;
extern char lbl_880DB398;
extern char lbl_880DB5F8;
extern char lbl_880DB648;
extern char lbl_880DB6C0;
extern void fn_889017B8(Ts4Object *object);
extern char lbl_880DB76C;
extern char lbl_880DB558;
extern char lbl_880DB5A8;
extern char lbl_880DB5D0;
extern char lbl_880DB698;
extern char lbl_880DB228;
extern char lbl_880DB250;
extern char lbl_880DB278;
extern char lbl_880DB80C;
extern char lbl_880DB88C;
extern char lbl_880DB954;
extern char lbl_880DB97C;
extern char lbl_880DB4E0;
extern char lbl_880DB834;
extern char lbl_880DC550;
extern char lbl_880DCE14;
extern char lbl_880DF1F8;
extern char lbl_880DF40C;
extern char lbl_880DF490;
extern void fn_88636CF0(Ts4Object *object);
extern char lbl_880DF8D8;
extern char lbl_880DF9D0;
extern void fn_8861B4D8(Ts4Object *object);
extern char lbl_880E16AC;
extern char lbl_880E1674;
extern char lbl_880E3738;
extern char lbl_880E3838;
extern char lbl_880E37D8;
extern void fn_88804AB8(Ts4Object *object);
extern char lbl_880E39F0;
extern char lbl_880E3A8C;
extern char lbl_880E46C8;
extern void fn_887F4E30(Ts4Object *object);
extern char lbl_880E4528;
extern void fn_887F4698(Ts4Object *object);
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
extern void fn_887EB6F0(Ts4Object *object);
extern char lbl_880EA60C;
extern char lbl_880E4BA0;
extern char lbl_880EF46C;
extern char lbl_880E3770;
extern char lbl_880EF6B8;
extern char lbl_880EF958;
extern char lbl_880F33E0;
extern char lbl_880F2D38;
extern void fn_887201F0(Ts4Object *object);
extern char lbl_880F2DA8;
extern void fn_88720180(Ts4Object *object);
extern char lbl_880F2E18;
extern void fn_88720108(Ts4Object *object);
extern char lbl_880F3018;
extern void fn_887239C0(Ts4Object *object);
extern char lbl_880F3144;
extern char lbl_880F2EF8;
extern void fn_88723A60(Ts4Object *object);
extern char lbl_880F2C98;
extern char lbl_880F37DC;
extern char lbl_880F4808;
extern char lbl_880F482C;
extern char lbl_880F4868;
extern char lbl_880F4890;
extern char lbl_880F43A4;
extern char lbl_880F4550;
extern char lbl_880F4640;
extern char lbl_880F4E18;
extern char lbl_880F58D8;
extern char lbl_880F6024;
extern char lbl_880F62F0;
extern char lbl_880F6400;
extern void fn_88638FC8(Ts4Object *object);
extern char lbl_880F7F0C;
extern char lbl_880F814C;
extern char lbl_880F8188;
extern char lbl_880F8310;
extern char lbl_880F7B80;
extern void fn_882804F0(Ts4Object *object);
extern char lbl_880F8928;
extern char lbl_880F8950;
extern char lbl_880F8978;
extern char lbl_880F8B3C;
extern char lbl_880F8C74;
extern void ts4_loop_call_seq_u32_off4_886178A0(Ts4Object *object);
extern char lbl_880F8B94;
extern char lbl_880F8C78;
extern void fn_882806A8(Ts4Object *object);
extern char lbl_880F8D50;
extern char lbl_880F7C54;
extern char lbl_880F7F38;

/* Installs a vtable, runs the base destructor, then releases the object when bit 0 of delete_flags is set. */
#define TS4_DTOR(name, vtable_symbol, base_dtor) \
    Ts4Object *name(Ts4Object *object, u32 delete_flags) \
    { \
        object->vtable = &vtable_symbol; \
        base_dtor(object); \
        if ((delete_flags & 1U) != 0) { \
            ts4_tsu_cleanup_end(object); \
        } \
        return object; \
    }

TS4_DTOR(ts4_dtor_vtable_base_881500A8, lbl_880C13C0, fn_88617D28) /* Swing_DLL.xex 0x881500A8 */
TS4_DTOR(ts4_dtor_vtable_base_88150260, lbl_880C13E8, fn_88617D28) /* Swing_DLL.xex 0x88150260 */
TS4_DTOR(ts4_dtor_vtable_base_88151D28, lbl_880D23E0, fn_88617D28) /* Swing_DLL.xex 0x88151D28 */
TS4_DTOR(ts4_dtor_vtable_base_881520A0, lbl_880D24B8, fn_88617D28) /* Swing_DLL.xex 0x881520A0 */
TS4_DTOR(ts4_dtor_vtable_base_88152178, lbl_880D24E0, fn_88617D28) /* Swing_DLL.xex 0x88152178 */
TS4_DTOR(ts4_dtor_vtable_base_88156EF8, lbl_880D2D94, fn_88617D28) /* Swing_DLL.xex 0x88156EF8 */
TS4_DTOR(ts4_dtor_vtable_base_88157010, lbl_880D2D10, fn_88935DF8) /* Swing_DLL.xex 0x88157010 */
TS4_DTOR(ts4_dtor_vtable_base_88157130, lbl_880D2A68, fn_88934458) /* Swing_DLL.xex 0x88157130 */
TS4_DTOR(ts4_dtor_vtable_base_88157B18, lbl_880D2E4C, fn_88937648) /* Swing_DLL.xex 0x88157B18 */
TS4_DTOR(ts4_dtor_vtable_base_8815F2D0, lbl_880D4C88, fn_8815F140) /* Swing_DLL.xex 0x8815F2D0 */
TS4_DTOR(ts4_dtor_vtable_base_8815F5C0, lbl_880D5240, fn_88955818) /* Swing_DLL.xex 0x8815F5C0 */
TS4_DTOR(ts4_dtor_vtable_base_8815F748, lbl_880D5528, fn_88951608) /* Swing_DLL.xex 0x8815F748 */
TS4_DTOR(ts4_dtor_vtable_base_8815F7E0, lbl_880D5570, fn_88951608) /* Swing_DLL.xex 0x8815F7E0 */
TS4_DTOR(ts4_dtor_vtable_base_8815F8B8, lbl_880D55B8, fn_88951608) /* Swing_DLL.xex 0x8815F8B8 */
TS4_DTOR(ts4_dtor_vtable_base_8815F998, lbl_880D5600, fn_88951608) /* Swing_DLL.xex 0x8815F998 */
TS4_DTOR(ts4_dtor_vtable_base_8816D270, lbl_880D5A3C, fn_88617D28) /* Swing_DLL.xex 0x8816D270 */
TS4_DTOR(ts4_dtor_vtable_base_8816F3E8, lbl_880D6470, fn_889293A0) /* Swing_DLL.xex 0x8816F3E8 */
TS4_DTOR(ts4_dtor_vtable_base_8816F448, lbl_880D6898, fn_889293A0) /* Swing_DLL.xex 0x8816F448 */
TS4_DTOR(ts4_dtor_vtable_base_8816F4A8, lbl_880D66B0, fn_889293A0) /* Swing_DLL.xex 0x8816F4A8 */
TS4_DTOR(ts4_dtor_vtable_base_8816F508, lbl_880D67D0, fn_889293A0) /* Swing_DLL.xex 0x8816F508 */
TS4_DTOR(ts4_dtor_vtable_base_8816F568, lbl_880D6590, fn_889293A0) /* Swing_DLL.xex 0x8816F568 */
TS4_DTOR(ts4_dtor_vtable_base_8816F5C8, lbl_880D6968, fn_889293A0) /* Swing_DLL.xex 0x8816F5C8 */
TS4_DTOR(ts4_dtor_vtable_base_881722E0, lbl_880D2CF8, fn_8893B3E0) /* Swing_DLL.xex 0x881722E0 */
TS4_DTOR(ts4_dtor_vtable_base_88174218, lbl_880D7030, fn_88617D28) /* Swing_DLL.xex 0x88174218 */
TS4_DTOR(ts4_dtor_vtable_base_88176DB8, lbl_880D7228, fn_8860BBD8) /* Swing_DLL.xex 0x88176DB8 */
TS4_DTOR(ts4_dtor_vtable_base_88176E78, lbl_880D7244, fn_88617D28) /* Swing_DLL.xex 0x88176E78 */
TS4_DTOR(ts4_dtor_vtable_base_881773F8, lbl_880D7310, ts4_if_call_seq_lbl_880D72B0_88912A38) /* Swing_DLL.xex 0x881773F8 */
TS4_DTOR(ts4_dtor_vtable_base_88177548, lbl_880D7380, ts4_if_call_seq_lbl_880D72B0_88912A38) /* Swing_DLL.xex 0x88177548 */
TS4_DTOR(ts4_dtor_vtable_base_88177698, lbl_880D73C4, ts4_if_call_seq_lbl_880D72B0_88912A38) /* Swing_DLL.xex 0x88177698 */
TS4_DTOR(ts4_dtor_vtable_base_881777E8, lbl_880D73FC, ts4_if_call_seq_lbl_880D72B0_88912A38) /* Swing_DLL.xex 0x881777E8 */
TS4_DTOR(ts4_dtor_vtable_base_8817B690, lbl_880DBD30, fn_88617D28) /* Swing_DLL.xex 0x8817B690 */
TS4_DTOR(ts4_dtor_vtable_base_8817B8D8, lbl_880DBDA8, fn_88617D28) /* Swing_DLL.xex 0x8817B8D8 */
TS4_DTOR(ts4_dtor_vtable_base_8817B938, lbl_880DBDD0, fn_88617D28) /* Swing_DLL.xex 0x8817B938 */
TS4_DTOR(ts4_dtor_vtable_base_8817BAC8, lbl_880DBE48, fn_88617D28) /* Swing_DLL.xex 0x8817BAC8 */
TS4_DTOR(ts4_dtor_vtable_base_8817C848, lbl_880DBCB4, fn_88617D28) /* Swing_DLL.xex 0x8817C848 */
TS4_DTOR(ts4_dtor_vtable_base_8817C910, lbl_880DB328, fn_88617D28) /* Swing_DLL.xex 0x8817C910 */
TS4_DTOR(ts4_dtor_vtable_base_8817C970, lbl_880DB3C0, fn_88617D28) /* Swing_DLL.xex 0x8817C970 */
TS4_DTOR(ts4_dtor_vtable_base_8817CCA0, lbl_880DB398, fn_88617D28) /* Swing_DLL.xex 0x8817CCA0 */
TS4_DTOR(ts4_dtor_vtable_base_8817CE08, lbl_880DB5F8, fn_88617D28) /* Swing_DLL.xex 0x8817CE08 */
TS4_DTOR(ts4_dtor_vtable_base_8817CED0, lbl_880DB648, fn_88617D28) /* Swing_DLL.xex 0x8817CED0 */
TS4_DTOR(ts4_dtor_vtable_base_8817D058, lbl_880DB6C0, fn_889017B8) /* Swing_DLL.xex 0x8817D058 */
TS4_DTOR(ts4_dtor_vtable_base_8817D0B8, lbl_880DB76C, fn_88617D28) /* Swing_DLL.xex 0x8817D0B8 */
TS4_DTOR(ts4_dtor_vtable_base_8817D118, lbl_880DB558, fn_88617D28) /* Swing_DLL.xex 0x8817D118 */
TS4_DTOR(ts4_dtor_vtable_base_8817D1E0, lbl_880DB5A8, fn_88617D28) /* Swing_DLL.xex 0x8817D1E0 */
TS4_DTOR(ts4_dtor_vtable_base_8817D240, lbl_880DB5D0, fn_88617D28) /* Swing_DLL.xex 0x8817D240 */
TS4_DTOR(ts4_dtor_vtable_base_8817D4C8, lbl_880DB698, fn_88617D28) /* Swing_DLL.xex 0x8817D4C8 */
TS4_DTOR(ts4_dtor_vtable_base_8817D658, lbl_880DB228, fn_88617D28) /* Swing_DLL.xex 0x8817D658 */
TS4_DTOR(ts4_dtor_vtable_base_8817D758, lbl_880DB250, fn_88617D28) /* Swing_DLL.xex 0x8817D758 */
TS4_DTOR(ts4_dtor_vtable_base_8817D7B8, lbl_880DB278, fn_88617D28) /* Swing_DLL.xex 0x8817D7B8 */
TS4_DTOR(ts4_dtor_vtable_base_8817DAE0, lbl_880DB80C, fn_88617D28) /* Swing_DLL.xex 0x8817DAE0 */
TS4_DTOR(ts4_dtor_vtable_base_8817DB40, lbl_880DB88C, fn_88617D28) /* Swing_DLL.xex 0x8817DB40 */
TS4_DTOR(ts4_dtor_vtable_base_8817DD58, lbl_880DB954, fn_88617D28) /* Swing_DLL.xex 0x8817DD58 */
TS4_DTOR(ts4_dtor_vtable_base_8817DE20, lbl_880DB97C, fn_88617D28) /* Swing_DLL.xex 0x8817DE20 */
TS4_DTOR(ts4_dtor_vtable_base_8817DE80, lbl_880DB4E0, fn_88617D28) /* Swing_DLL.xex 0x8817DE80 */
TS4_DTOR(ts4_dtor_vtable_base_8817DF30, lbl_880DB834, fn_88617D28) /* Swing_DLL.xex 0x8817DF30 */
TS4_DTOR(ts4_dtor_vtable_base_881887A0, lbl_880DC550, fn_8860BBD8) /* Swing_DLL.xex 0x881887A0 */
TS4_DTOR(ts4_dtor_vtable_base_88189C58, lbl_880DCE14, fn_88617D28) /* Swing_DLL.xex 0x88189C58 */
TS4_DTOR(ts4_dtor_vtable_base_881A5278, lbl_880DF1F8, fn_88617D28) /* Swing_DLL.xex 0x881A5278 */
TS4_DTOR(ts4_dtor_vtable_base_881A57A8, lbl_880DF40C, fn_88617D28) /* Swing_DLL.xex 0x881A57A8 */
TS4_DTOR(ts4_dtor_vtable_base_881A5870, lbl_880DF490, fn_88636CF0) /* Swing_DLL.xex 0x881A5870 */
TS4_DTOR(ts4_dtor_vtable_base_881A6540, lbl_880DF8D8, fn_88617D28) /* Swing_DLL.xex 0x881A6540 */
TS4_DTOR(ts4_dtor_vtable_base_881A7888, lbl_880DF9D0, fn_8861B4D8) /* Swing_DLL.xex 0x881A7888 */
TS4_DTOR(ts4_dtor_vtable_base_881AD448, lbl_880E16AC, fn_88617D28) /* Swing_DLL.xex 0x881AD448 */
TS4_DTOR(ts4_dtor_vtable_base_881AD648, lbl_880E1674, fn_8860BBD8) /* Swing_DLL.xex 0x881AD648 */
TS4_DTOR(ts4_dtor_vtable_base_881AD6A8, lbl_880E3738, fn_8860BBD8) /* Swing_DLL.xex 0x881AD6A8 */
TS4_DTOR(ts4_dtor_vtable_base_881B2278, lbl_880E3838, fn_88617D28) /* Swing_DLL.xex 0x881B2278 */
TS4_DTOR(ts4_dtor_vtable_base_881B2378, lbl_880E37D8, fn_88804AB8) /* Swing_DLL.xex 0x881B2378 */
TS4_DTOR(ts4_dtor_vtable_base_881B39D8, lbl_880E39F0, fn_88617D28) /* Swing_DLL.xex 0x881B39D8 */
TS4_DTOR(ts4_dtor_vtable_base_881B3A38, lbl_880E3A8C, fn_88617D28) /* Swing_DLL.xex 0x881B3A38 */
TS4_DTOR(ts4_dtor_vtable_base_881B8510, lbl_880E46C8, fn_887F4E30) /* Swing_DLL.xex 0x881B8510 */
TS4_DTOR(ts4_dtor_vtable_base_881B8610, lbl_880E4528, fn_887F4698) /* Swing_DLL.xex 0x881B8610 */
TS4_DTOR(ts4_dtor_vtable_base_881BB4A0, lbl_880E7084, fn_88617D28) /* Swing_DLL.xex 0x881BB4A0 */
TS4_DTOR(ts4_dtor_vtable_base_881BB550, lbl_880E7140, fn_88617D28) /* Swing_DLL.xex 0x881BB550 */
TS4_DTOR(ts4_dtor_vtable_base_881BB5B0, lbl_880E7168, fn_88617D28) /* Swing_DLL.xex 0x881BB5B0 */
TS4_DTOR(ts4_dtor_vtable_base_881BB610, lbl_880E7190, fn_88617D28) /* Swing_DLL.xex 0x881BB610 */
TS4_DTOR(ts4_dtor_vtable_base_881BB670, lbl_880E71B8, fn_88617D28) /* Swing_DLL.xex 0x881BB670 */
TS4_DTOR(ts4_dtor_vtable_base_881BB6D0, lbl_880E71E0, fn_88617D28) /* Swing_DLL.xex 0x881BB6D0 */
TS4_DTOR(ts4_dtor_vtable_base_881BB730, lbl_880E7208, fn_88617D28) /* Swing_DLL.xex 0x881BB730 */
TS4_DTOR(ts4_dtor_vtable_base_881BB790, lbl_880E7230, fn_88617D28) /* Swing_DLL.xex 0x881BB790 */
TS4_DTOR(ts4_dtor_vtable_base_881BB7F0, lbl_880E7258, fn_88617D28) /* Swing_DLL.xex 0x881BB7F0 */
TS4_DTOR(ts4_dtor_vtable_base_88211510, lbl_880EA318, fn_887EB6F0) /* Swing_DLL.xex 0x88211510 */
TS4_DTOR(ts4_dtor_vtable_base_88211E80, lbl_880EA60C, fn_88617D28) /* Swing_DLL.xex 0x88211E80 */
TS4_DTOR(ts4_dtor_vtable_base_88212A60, lbl_880E4BA0, fn_8860BBD8) /* Swing_DLL.xex 0x88212A60 */
TS4_DTOR(ts4_dtor_vtable_base_88212D18, lbl_880EF46C, fn_8860BBD8) /* Swing_DLL.xex 0x88212D18 */
TS4_DTOR(ts4_dtor_vtable_base_882131B0, lbl_880E3770, fn_8860BBD8) /* Swing_DLL.xex 0x882131B0 */
TS4_DTOR(ts4_dtor_vtable_base_88213638, lbl_880EF6B8, fn_8860BBD8) /* Swing_DLL.xex 0x88213638 */
TS4_DTOR(ts4_dtor_vtable_base_88213740, lbl_880EF958, fn_88617D28) /* Swing_DLL.xex 0x88213740 */
TS4_DTOR(ts4_dtor_vtable_base_8821BF60, lbl_880F33E0, fn_88617D28) /* Swing_DLL.xex 0x8821BF60 */
TS4_DTOR(ts4_dtor_vtable_base_8821D440, lbl_880F2D38, fn_887201F0) /* Swing_DLL.xex 0x8821D440 */
TS4_DTOR(ts4_dtor_vtable_base_8821D4A0, lbl_880F2DA8, fn_88720180) /* Swing_DLL.xex 0x8821D4A0 */
TS4_DTOR(ts4_dtor_vtable_base_8821D500, lbl_880F2E18, fn_88720108) /* Swing_DLL.xex 0x8821D500 */
TS4_DTOR(ts4_dtor_vtable_base_8821D560, lbl_880F3018, fn_887239C0) /* Swing_DLL.xex 0x8821D560 */
TS4_DTOR(ts4_dtor_vtable_base_8821D828, lbl_880F3144, fn_88617D28) /* Swing_DLL.xex 0x8821D828 */
TS4_DTOR(ts4_dtor_vtable_base_882252E0, lbl_880F2EF8, fn_88723A60) /* Swing_DLL.xex 0x882252E0 */
TS4_DTOR(ts4_dtor_vtable_base_88225340, lbl_880F2C98, fn_88723A60) /* Swing_DLL.xex 0x88225340 */
TS4_DTOR(ts4_dtor_vtable_base_88262A38, lbl_880F37DC, fn_88617D28) /* Swing_DLL.xex 0x88262A38 */
TS4_DTOR(ts4_dtor_vtable_base_88269D50, lbl_880F4808, fn_8860BBD8) /* Swing_DLL.xex 0x88269D50 */
TS4_DTOR(ts4_dtor_vtable_base_88269DB0, lbl_880F482C, fn_8860BBD8) /* Swing_DLL.xex 0x88269DB0 */
TS4_DTOR(ts4_dtor_vtable_base_8826A278, lbl_880F4868, fn_88617D28) /* Swing_DLL.xex 0x8826A278 */
TS4_DTOR(ts4_dtor_vtable_base_8826A2D8, lbl_880F4890, fn_88617D28) /* Swing_DLL.xex 0x8826A2D8 */
TS4_DTOR(ts4_dtor_vtable_base_8826A3B0, lbl_880F43A4, fn_88617D28) /* Swing_DLL.xex 0x8826A3B0 */
TS4_DTOR(ts4_dtor_vtable_base_8826A4C0, lbl_880F4550, fn_88617D28) /* Swing_DLL.xex 0x8826A4C0 */
TS4_DTOR(ts4_dtor_vtable_base_8826AB68, lbl_880F4640, fn_8860BBD8) /* Swing_DLL.xex 0x8826AB68 */
TS4_DTOR(ts4_dtor_vtable_base_8826B6B8, lbl_880F4E18, fn_8860BBD8) /* Swing_DLL.xex 0x8826B6B8 */
TS4_DTOR(ts4_dtor_vtable_base_88273DA8, lbl_880F58D8, fn_88617D28) /* Swing_DLL.xex 0x88273DA8 */
TS4_DTOR(ts4_dtor_vtable_base_882787A0, lbl_880F6024, fn_88617D28) /* Swing_DLL.xex 0x882787A0 */
TS4_DTOR(ts4_dtor_vtable_base_8827BF88, lbl_880F62F0, fn_8861B4D8) /* Swing_DLL.xex 0x8827BF88 */
TS4_DTOR(ts4_dtor_vtable_base_8827C0A0, lbl_880F6400, fn_88638FC8) /* Swing_DLL.xex 0x8827C0A0 */
TS4_DTOR(ts4_dtor_vtable_base_8827C7C8, lbl_880F7F0C, fn_88617D28) /* Swing_DLL.xex 0x8827C7C8 */
TS4_DTOR(ts4_dtor_vtable_base_8827CDA8, lbl_880F814C, fn_88617D28) /* Swing_DLL.xex 0x8827CDA8 */
TS4_DTOR(ts4_dtor_vtable_base_8827CE08, lbl_880F8188, fn_88617D28) /* Swing_DLL.xex 0x8827CE08 */
TS4_DTOR(ts4_dtor_vtable_base_8827DA28, lbl_880F8310, fn_88617D28) /* Swing_DLL.xex 0x8827DA28 */
TS4_DTOR(ts4_dtor_vtable_base_8827F048, lbl_880F7B80, fn_882804F0) /* Swing_DLL.xex 0x8827F048 */
TS4_DTOR(ts4_dtor_vtable_base_8827F198, lbl_880F8928, fn_88617D28) /* Swing_DLL.xex 0x8827F198 */
TS4_DTOR(ts4_dtor_vtable_base_8827F1F8, lbl_880F8950, fn_88617D28) /* Swing_DLL.xex 0x8827F1F8 */
TS4_DTOR(ts4_dtor_vtable_base_8827F258, lbl_880F8978, fn_88617D28) /* Swing_DLL.xex 0x8827F258 */
TS4_DTOR(ts4_dtor_vtable_base_8827F8D8, lbl_880F8B3C, fn_88636CF0) /* Swing_DLL.xex 0x8827F8D8 */
TS4_DTOR(ts4_dtor_vtable_base_8827FBD8, lbl_880F8C74, ts4_loop_call_seq_u32_off4_886178A0) /* Swing_DLL.xex 0x8827FBD8 */
TS4_DTOR(ts4_dtor_vtable_base_8827FC88, lbl_880F8B94, fn_88617D28) /* Swing_DLL.xex 0x8827FC88 */
TS4_DTOR(ts4_dtor_vtable_base_8827FCE8, lbl_880F8C78, fn_882806A8) /* Swing_DLL.xex 0x8827FCE8 */
TS4_DTOR(ts4_dtor_vtable_base_8827FEB0, lbl_880F8D50, fn_88617D28) /* Swing_DLL.xex 0x8827FEB0 */
TS4_DTOR(ts4_dtor_vtable_base_8827FF58, lbl_880F7C54, fn_88617D28) /* Swing_DLL.xex 0x8827FF58 */
TS4_DTOR(ts4_dtor_vtable_base_88286D70, lbl_880F7F38, fn_88617D28) /* Swing_DLL.xex 0x88286D70 */
