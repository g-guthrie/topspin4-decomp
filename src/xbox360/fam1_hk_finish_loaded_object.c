/* Family FAM1: Havok finish-loaded-object callbacks. Each one placement-constructs a loaded object in place:
 * `new (p) T(hkFinishLoadedObjectFlag{1})`. The flag struct is built before the placement-new null check, and
 * the inlined constructor call becomes a tail call to the class's finishing constructor. */

/* hkFinishLoadedObjectFlag: passed by value in r4. */
typedef struct ts4_hk_finish_flag {
    int finishing;
} ts4_hk_finish_flag;

/* Construct the object at p in place with the "finishing" flag set (no-op for a null p). */
#define TS4_HK_FINISH_LOADED(A, ctor)                                                                        \
    extern void ctor(void *object, ts4_hk_finish_flag flag);                                                \
    void ts4_hk_finish_loaded_object_##A(void *object)                                                      \
    {                                                                                                        \
        ts4_hk_finish_flag flag;                                                                             \
        flag.finishing = 1;                                                                                  \
        if (object)                                                                                          \
            ctor(object, flag);                                                                              \
    }

TS4_HK_FINISH_LOADED(88437200, ts4_forward_to_fn_88437248) /* Swing_DLL.xex 0x88437200 */
TS4_HK_FINISH_LOADED(88437950, fn_8843FFA0) /* Swing_DLL.xex 0x88437950 */
TS4_HK_FINISH_LOADED(884379F0, fn_88441FF8) /* Swing_DLL.xex 0x884379F0 */
TS4_HK_FINISH_LOADED(88437C50, ts4_forward_to_fn_88437C98) /* Swing_DLL.xex 0x88437C50 */
TS4_HK_FINISH_LOADED(88437DB8, ts4_init_object_88444740) /* Swing_DLL.xex 0x88437DB8 */
TS4_HK_FINISH_LOADED(88437E08, fn_884430E8) /* Swing_DLL.xex 0x88437E08 */
TS4_HK_FINISH_LOADED(88438190, ts4_forward_to_fn_884381D8) /* Swing_DLL.xex 0x88438190 */
TS4_HK_FINISH_LOADED(88438668, ts4_addr_lbl_88081E00_88446CB8) /* Swing_DLL.xex 0x88438668 */
TS4_HK_FINISH_LOADED(884386C8, ts4_addr_lbl_88081E10_88446CD0) /* Swing_DLL.xex 0x884386C8 */
TS4_HK_FINISH_LOADED(88438728, fn_88446CE8) /* Swing_DLL.xex 0x88438728 */
TS4_HK_FINISH_LOADED(88438788, fn_88448290) /* Swing_DLL.xex 0x88438788 */
TS4_HK_FINISH_LOADED(884387E8, fn_88448BB8) /* Swing_DLL.xex 0x884387E8 */
TS4_HK_FINISH_LOADED(88468460, fn_884685D8) /* Swing_DLL.xex 0x88468460 */
TS4_HK_FINISH_LOADED(88468768, ts4_call_seq_lbl_88086FCC_88478CE8) /* Swing_DLL.xex 0x88468768 */
TS4_HK_FINISH_LOADED(88468888, ts4_call_seq_lbl_88087004_884796F8) /* Swing_DLL.xex 0x88468888 */
TS4_HK_FINISH_LOADED(884688E8, fn_88468998) /* Swing_DLL.xex 0x884688E8 */
TS4_HK_FINISH_LOADED(88468D28, fn_884748C0) /* Swing_DLL.xex 0x88468D28 */
TS4_HK_FINISH_LOADED(88468F58, ts4_call_seq_lbl_88087078_8847B788) /* Swing_DLL.xex 0x88468F58 */
TS4_HK_FINISH_LOADED(884692E0, ts4_call_seq_lbl_880870F4_8847E988) /* Swing_DLL.xex 0x884692E0 */
TS4_HK_FINISH_LOADED(88469570, ts4_call_seq_lbl_88087154_88481278) /* Swing_DLL.xex 0x88469570 */
TS4_HK_FINISH_LOADED(88469710, fn_88469758) /* Swing_DLL.xex 0x88469710 */
TS4_HK_FINISH_LOADED(88469850, fn_88469898) /* Swing_DLL.xex 0x88469850 */
TS4_HK_FINISH_LOADED(88469A70, fn_88469AB8) /* Swing_DLL.xex 0x88469A70 */
TS4_HK_FINISH_LOADED(88469E10, fn_88486018) /* Swing_DLL.xex 0x88469E10 */
TS4_HK_FINISH_LOADED(8846A010, fn_8846D5E0) /* Swing_DLL.xex 0x8846A010 */
TS4_HK_FINISH_LOADED(8846A070, ts4_if_addr_lbl_88086ED0_88475A78) /* Swing_DLL.xex 0x8846A070 */
TS4_HK_FINISH_LOADED(8846A0D8, ts4_if_call_seq_u32_off0_88487020) /* Swing_DLL.xex 0x8846A0D8 */
TS4_HK_FINISH_LOADED(8846A288, ts4_set_wrap_byte_8847FBC8) /* Swing_DLL.xex 0x8846A288 */
TS4_HK_FINISH_LOADED(884A1230, fn_884A1278) /* Swing_DLL.xex 0x884A1230 */
TS4_HK_FINISH_LOADED(884A13F0, fn_884A1438) /* Swing_DLL.xex 0x884A13F0 */
TS4_HK_FINISH_LOADED(884A1578, ts4_call_seq_fn_8843AE88_884A15C0) /* Swing_DLL.xex 0x884A1578 */
TS4_HK_FINISH_LOADED(884A1830, fn_884A1878) /* Swing_DLL.xex 0x884A1830 */
