/* Family A: heap-allocating factory thunks (Swing_DLL.xex).
   Each allocates an object with the shared allocator (fn_88613268), runs the
   shared base constructor fn_88617D88, installs a per-class vtable pointer
   (the 0x20-byte classes also clear the word at +0x1c) and returns the object,
   or NULL if the allocation failed. The last allocator argument (tag 2 or 0)
   distinguishes the two clusters of each size. */
extern "C" {
extern void *lbl_88D45B38;   /* shared allocator heap, placeholder name */
void *fn_88613268(void *heap, int size, int align, int flags, int tag);
void fn_88617D88(void *self);   /* shared base constructor */
extern int lbl_880C13C0;   /* per-class vtable, placeholder name */
extern int lbl_880C13E8;   /* per-class vtable, placeholder name */
extern int lbl_880D23E0;   /* per-class vtable, placeholder name */
extern int lbl_880D2D94;   /* per-class vtable, placeholder name */
extern int lbl_880D5644;   /* per-class vtable, placeholder name */
extern int lbl_880D5A3C;   /* per-class vtable, placeholder name */
extern int lbl_880D6BC0;   /* per-class vtable, placeholder name */
extern int lbl_880D7030;   /* per-class vtable, placeholder name */
extern int lbl_880DB250;   /* per-class vtable, placeholder name */
extern int lbl_880DB328;   /* per-class vtable, placeholder name */
extern int lbl_880DB398;   /* per-class vtable, placeholder name */
extern int lbl_880DB558;   /* per-class vtable, placeholder name */
extern int lbl_880DB5D0;   /* per-class vtable, placeholder name */
extern int lbl_880DB954;   /* per-class vtable, placeholder name */
extern int lbl_880DB97C;   /* per-class vtable, placeholder name */
extern int lbl_880DBCB4;   /* per-class vtable, placeholder name */
extern int lbl_880DBDA8;   /* per-class vtable, placeholder name */
extern int lbl_880DBE48;   /* per-class vtable, placeholder name */
extern int lbl_880DC524;   /* per-class vtable, placeholder name */
extern int lbl_880DD88C;   /* per-class vtable, placeholder name */
extern int lbl_880DF940;   /* per-class vtable, placeholder name */
extern int lbl_880E06B0;   /* per-class vtable, placeholder name */
extern int lbl_880E1724;   /* per-class vtable, placeholder name */
extern int lbl_880E3748;   /* per-class vtable, placeholder name */
extern int lbl_880E39A0;   /* per-class vtable, placeholder name */
extern int lbl_880E3D84;   /* per-class vtable, placeholder name */
extern int lbl_880E499C;   /* per-class vtable, placeholder name */
extern int lbl_880E4C64;   /* per-class vtable, placeholder name */
extern int lbl_880E7084;   /* per-class vtable, placeholder name */
extern int lbl_880E70AC;   /* per-class vtable, placeholder name */
extern int lbl_880E7140;   /* per-class vtable, placeholder name */
extern int lbl_880E7168;   /* per-class vtable, placeholder name */
extern int lbl_880E7190;   /* per-class vtable, placeholder name */
extern int lbl_880E71B8;   /* per-class vtable, placeholder name */
extern int lbl_880E71E0;   /* per-class vtable, placeholder name */
extern int lbl_880E7208;   /* per-class vtable, placeholder name */
extern int lbl_880E7230;   /* per-class vtable, placeholder name */
extern int lbl_880E7258;   /* per-class vtable, placeholder name */
extern int lbl_880EF958;   /* per-class vtable, placeholder name */
extern int lbl_880EF9D0;   /* per-class vtable, placeholder name */
extern int lbl_880EFC8C;   /* per-class vtable, placeholder name */
extern int lbl_880F30F4;   /* per-class vtable, placeholder name */
extern int lbl_880F311C;   /* per-class vtable, placeholder name */
extern int lbl_880F3494;   /* per-class vtable, placeholder name */
extern int lbl_880F37DC;   /* per-class vtable, placeholder name */
extern int lbl_880F3804;   /* per-class vtable, placeholder name */
extern int lbl_880F4678;   /* per-class vtable, placeholder name */
extern int lbl_880F4868;   /* per-class vtable, placeholder name */
extern int lbl_880F4A64;   /* per-class vtable, placeholder name */
extern int lbl_880F4A90;   /* per-class vtable, placeholder name */
extern int lbl_880F4AD0;   /* per-class vtable, placeholder name */
extern int lbl_880F4B10;   /* per-class vtable, placeholder name */
extern int lbl_880F4B50;   /* per-class vtable, placeholder name */
extern int lbl_880F4B90;   /* per-class vtable, placeholder name */
extern int lbl_880F4BD0;   /* per-class vtable, placeholder name */
extern int lbl_880F4C90;   /* per-class vtable, placeholder name */
extern int lbl_880F4CD0;   /* per-class vtable, placeholder name */
extern int lbl_880F4D50;   /* per-class vtable, placeholder name */
extern int lbl_880F4D8C;   /* per-class vtable, placeholder name */
extern int lbl_880F50D4;   /* per-class vtable, placeholder name */
extern int lbl_880F53DC;   /* per-class vtable, placeholder name */
extern int lbl_880F5FC4;   /* per-class vtable, placeholder name */
extern int lbl_880F6024;   /* per-class vtable, placeholder name */
extern int lbl_880F6394;   /* per-class vtable, placeholder name */
extern int lbl_880F7EE4;   /* per-class vtable, placeholder name */
extern int lbl_880F814C;   /* per-class vtable, placeholder name */
extern int lbl_880F8188;   /* per-class vtable, placeholder name */
extern int lbl_880F8310;   /* per-class vtable, placeholder name */
extern int lbl_880F8950;   /* per-class vtable, placeholder name */
extern int lbl_880F8978;   /* per-class vtable, placeholder name */
}

inline void *operator new(unsigned, void *heap, int size, int align, int flags, int tag)
{ return fn_88613268(heap, size, align, flags, tag); }

#define TS4_FACTORY_28(NAME, VTBL, TAG) \
struct NAME##_obj { void *vtbl; char base_fields[24]; \
    NAME##_obj() { fn_88617D88(this); vtbl = &VTBL; } }; \
extern "C" NAME##_obj *NAME(void) \
{ return new(lbl_88D45B38, 28, 4, 0, TAG) NAME##_obj(); }

#define TS4_FACTORY_32(NAME, VTBL, TAG) \
struct NAME##_obj { void *vtbl; char base_fields[24]; unsigned word_1c; \
    NAME##_obj() { fn_88617D88(this); word_1c = 0; vtbl = &VTBL; } }; \
extern "C" NAME##_obj *NAME(void) \
{ return new(lbl_88D45B38, 32, 4, 0, TAG) NAME##_obj(); }

/* cluster ts4_factory_obj28_tag2_881503C8: size 28, tag 2 */
/* Swing_DLL.xex 0x881503C8 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881503C8, lbl_880C13C0, 2)
/* Swing_DLL.xex 0x881504B8 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881504B8, lbl_880C13E8, 2)
/* Swing_DLL.xex 0x881547A0 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881547A0, lbl_880D23E0, 2)
/* Swing_DLL.xex 0x88157FE0 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88157FE0, lbl_880D2D94, 2)
/* Swing_DLL.xex 0x881682D8 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881682D8, lbl_880D5644, 2)
/* Swing_DLL.xex 0x8816EB58 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_8816EB58, lbl_880D5A3C, 2)
/* Swing_DLL.xex 0x88173010 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88173010, lbl_880D6BC0, 2)
/* Swing_DLL.xex 0x88174CF0 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88174CF0, lbl_880D7030, 2)
/* Swing_DLL.xex 0x88182CA0 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88182CA0, lbl_880DBDA8, 2)
/* Swing_DLL.xex 0x88182E40 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88182E40, lbl_880DBE48, 2)
/* Swing_DLL.xex 0x88182FE0 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88182FE0, lbl_880DBCB4, 2)
/* Swing_DLL.xex 0x88183180 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88183180, lbl_880DB328, 2)
/* Swing_DLL.xex 0x88183490 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88183490, lbl_880DB398, 2)
/* Swing_DLL.xex 0x88183D40 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88183D40, lbl_880DB558, 2)
/* Swing_DLL.xex 0x88183F90 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88183F90, lbl_880DB5D0, 2)
/* Swing_DLL.xex 0x88184710 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88184710, lbl_880DB250, 2)
/* Swing_DLL.xex 0x88184EE0 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88184EE0, lbl_880DB954, 2)
/* Swing_DLL.xex 0x88185080 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88185080, lbl_880DB97C, 2)
/* Swing_DLL.xex 0x88188CF0 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88188CF0, lbl_880DC524, 2)
/* Swing_DLL.xex 0x881A4CB0 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881A4CB0, lbl_880DD88C, 2)
/* Swing_DLL.xex 0x881A72A8 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881A72A8, lbl_880DF940, 2)
/* Swing_DLL.xex 0x881ABE38 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881ABE38, lbl_880E06B0, 2)
/* Swing_DLL.xex 0x881AF4B8 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881AF4B8, lbl_880E1724, 2)
/* Swing_DLL.xex 0x881B2B90 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881B2B90, lbl_880E3748, 2)
/* Swing_DLL.xex 0x881B3D40 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881B3D40, lbl_880E39A0, 2)
/* Swing_DLL.xex 0x881B7010 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881B7010, lbl_880E3D84, 2)
/* Swing_DLL.xex 0x881B89C8 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881B89C8, lbl_880E499C, 2)
/* Swing_DLL.xex 0x881BA288 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881BA288, lbl_880E4C64, 2)
/* Swing_DLL.xex 0x881BC478 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881BC478, lbl_880E70AC, 2)
/* Swing_DLL.xex 0x881BC568 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_881BC568, lbl_880E7084, 2)
/* Swing_DLL.xex 0x88216030 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88216030, lbl_880EF958, 2)
/* Swing_DLL.xex 0x882170B8 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_882170B8, lbl_880EF9D0, 2)
/* Swing_DLL.xex 0x88219F80 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88219F80, lbl_880EFC8C, 2)
/* Swing_DLL.xex 0x882621C8 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_882621C8, lbl_880F3494, 2)
/* Swing_DLL.xex 0x88267328 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88267328, lbl_880F3804, 2)
/* Swing_DLL.xex 0x8826EF38 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_8826EF38, lbl_880F4A64, 2)
/* Swing_DLL.xex 0x88273968 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88273968, lbl_880F50D4, 2)
/* Swing_DLL.xex 0x882760F0 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_882760F0, lbl_880F53DC, 2)
/* Swing_DLL.xex 0x88279708 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88279708, lbl_880F5FC4, 2)
/* Swing_DLL.xex 0x8827C498 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_8827C498, lbl_880F6394, 2)
/* Swing_DLL.xex 0x88283D78 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88283D78, lbl_880F7EE4, 2)
/* Swing_DLL.xex 0x882841F8 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_882841F8, lbl_880F814C, 2)
/* Swing_DLL.xex 0x882842E8 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_882842E8, lbl_880F8188, 2)
/* Swing_DLL.xex 0x88284538 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88284538, lbl_880F8310, 2)
/* Swing_DLL.xex 0x88284E28 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88284E28, lbl_880F8950, 2)
/* Swing_DLL.xex 0x88284F18 */ TS4_FACTORY_28(ts4_factory_obj28_tag2_88284F18, lbl_880F8978, 2)
/* cluster ts4_factory_obj28_tag0_88150440: size 28, tag 0 */
/* Swing_DLL.xex 0x88150440 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88150440, lbl_880C13C0, 0)
/* Swing_DLL.xex 0x88150530 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88150530, lbl_880C13E8, 0)
/* Swing_DLL.xex 0x88154818 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88154818, lbl_880D23E0, 0)
/* Swing_DLL.xex 0x88158058 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88158058, lbl_880D2D94, 0)
/* Swing_DLL.xex 0x88168350 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88168350, lbl_880D5644, 0)
/* Swing_DLL.xex 0x8816EBD0 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_8816EBD0, lbl_880D5A3C, 0)
/* Swing_DLL.xex 0x88173088 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88173088, lbl_880D6BC0, 0)
/* Swing_DLL.xex 0x88174D68 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88174D68, lbl_880D7030, 0)
/* Swing_DLL.xex 0x88182D18 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88182D18, lbl_880DBDA8, 0)
/* Swing_DLL.xex 0x88182EB8 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88182EB8, lbl_880DBE48, 0)
/* Swing_DLL.xex 0x88183058 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88183058, lbl_880DBCB4, 0)
/* Swing_DLL.xex 0x881831F8 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881831F8, lbl_880DB328, 0)
/* Swing_DLL.xex 0x88183508 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88183508, lbl_880DB398, 0)
/* Swing_DLL.xex 0x88183DB8 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88183DB8, lbl_880DB558, 0)
/* Swing_DLL.xex 0x88184008 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88184008, lbl_880DB5D0, 0)
/* Swing_DLL.xex 0x88184788 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88184788, lbl_880DB250, 0)
/* Swing_DLL.xex 0x88184F58 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88184F58, lbl_880DB954, 0)
/* Swing_DLL.xex 0x881850F8 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881850F8, lbl_880DB97C, 0)
/* Swing_DLL.xex 0x88188D68 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88188D68, lbl_880DC524, 0)
/* Swing_DLL.xex 0x881A4D28 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881A4D28, lbl_880DD88C, 0)
/* Swing_DLL.xex 0x881A7320 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881A7320, lbl_880DF940, 0)
/* Swing_DLL.xex 0x881ABEB0 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881ABEB0, lbl_880E06B0, 0)
/* Swing_DLL.xex 0x881AF530 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881AF530, lbl_880E1724, 0)
/* Swing_DLL.xex 0x881B2C08 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881B2C08, lbl_880E3748, 0)
/* Swing_DLL.xex 0x881B3DB8 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881B3DB8, lbl_880E39A0, 0)
/* Swing_DLL.xex 0x881B7088 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881B7088, lbl_880E3D84, 0)
/* Swing_DLL.xex 0x881B8A40 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881B8A40, lbl_880E499C, 0)
/* Swing_DLL.xex 0x881BA300 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881BA300, lbl_880E4C64, 0)
/* Swing_DLL.xex 0x881BC4F0 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881BC4F0, lbl_880E70AC, 0)
/* Swing_DLL.xex 0x881BC5E0 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_881BC5E0, lbl_880E7084, 0)
/* Swing_DLL.xex 0x88217130 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88217130, lbl_880EF9D0, 0)
/* Swing_DLL.xex 0x88217340 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88217340, lbl_880EF958, 0)
/* Swing_DLL.xex 0x88219FF8 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88219FF8, lbl_880EFC8C, 0)
/* Swing_DLL.xex 0x88262240 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88262240, lbl_880F3494, 0)
/* Swing_DLL.xex 0x882673A0 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_882673A0, lbl_880F3804, 0)
/* Swing_DLL.xex 0x8826EFB0 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_8826EFB0, lbl_880F4A64, 0)
/* Swing_DLL.xex 0x882739E0 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_882739E0, lbl_880F50D4, 0)
/* Swing_DLL.xex 0x88276168 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88276168, lbl_880F53DC, 0)
/* Swing_DLL.xex 0x88279780 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88279780, lbl_880F5FC4, 0)
/* Swing_DLL.xex 0x8827C510 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_8827C510, lbl_880F6394, 0)
/* Swing_DLL.xex 0x88283DF0 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88283DF0, lbl_880F7EE4, 0)
/* Swing_DLL.xex 0x88284270 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88284270, lbl_880F814C, 0)
/* Swing_DLL.xex 0x88284360 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88284360, lbl_880F8188, 0)
/* Swing_DLL.xex 0x882845B0 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_882845B0, lbl_880F8310, 0)
/* Swing_DLL.xex 0x88284EA0 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88284EA0, lbl_880F8950, 0)
/* Swing_DLL.xex 0x88284F90 */ TS4_FACTORY_28(ts4_factory_obj28_tag0_88284F90, lbl_880F8978, 0)
/* cluster ts4_factory_obj32_tag2_881BC7B8: size 32, tag 2 */
/* Swing_DLL.xex 0x881BC7B8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_881BC7B8, lbl_880E7140, 2)
/* Swing_DLL.xex 0x881BC8B8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_881BC8B8, lbl_880E7168, 2)
/* Swing_DLL.xex 0x881BC9B8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_881BC9B8, lbl_880E7230, 2)
/* Swing_DLL.xex 0x881BCAB8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_881BCAB8, lbl_880E7258, 2)
/* Swing_DLL.xex 0x881BCBB8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_881BCBB8, lbl_880E71E0, 2)
/* Swing_DLL.xex 0x881BCCB8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_881BCCB8, lbl_880E7208, 2)
/* Swing_DLL.xex 0x881BCDB8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_881BCDB8, lbl_880E7190, 2)
/* Swing_DLL.xex 0x881BCEB8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_881BCEB8, lbl_880E71B8, 2)
/* Swing_DLL.xex 0x88235920 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_88235920, lbl_880F311C, 2)
/* Swing_DLL.xex 0x88235A20 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_88235A20, lbl_880F30F4, 2)
/* Swing_DLL.xex 0x88267418 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_88267418, lbl_880F37DC, 2)
/* Swing_DLL.xex 0x8826E738 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826E738, lbl_880F4678, 2)
/* Swing_DLL.xex 0x8826ED88 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826ED88, lbl_880F4868, 2)
/* Swing_DLL.xex 0x8826F028 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826F028, lbl_880F4A90, 2)
/* Swing_DLL.xex 0x8826F128 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826F128, lbl_880F4AD0, 2)
/* Swing_DLL.xex 0x8826F228 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826F228, lbl_880F4B10, 2)
/* Swing_DLL.xex 0x8826F328 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826F328, lbl_880F4B50, 2)
/* Swing_DLL.xex 0x8826F428 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826F428, lbl_880F4B90, 2)
/* Swing_DLL.xex 0x8826F688 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826F688, lbl_880F4BD0, 2)
/* Swing_DLL.xex 0x8826F938 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826F938, lbl_880F4C90, 2)
/* Swing_DLL.xex 0x8826FA38 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826FA38, lbl_880F4CD0, 2)
/* Swing_DLL.xex 0x8826FBE8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826FBE8, lbl_880F4D50, 2)
/* Swing_DLL.xex 0x8826FCE8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_8826FCE8, lbl_880F4D8C, 2)
/* Swing_DLL.xex 0x882798A8 */ TS4_FACTORY_32(ts4_factory_obj32_tag2_882798A8, lbl_880F6024, 2)
/* cluster ts4_factory_obj32_tag0_881BC838: size 32, tag 0 */
/* Swing_DLL.xex 0x881BC838 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_881BC838, lbl_880E7140, 0)
/* Swing_DLL.xex 0x881BC938 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_881BC938, lbl_880E7168, 0)
/* Swing_DLL.xex 0x881BCA38 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_881BCA38, lbl_880E7230, 0)
/* Swing_DLL.xex 0x881BCB38 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_881BCB38, lbl_880E7258, 0)
/* Swing_DLL.xex 0x881BCC38 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_881BCC38, lbl_880E71E0, 0)
/* Swing_DLL.xex 0x881BCD38 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_881BCD38, lbl_880E7208, 0)
/* Swing_DLL.xex 0x881BCE38 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_881BCE38, lbl_880E7190, 0)
/* Swing_DLL.xex 0x881BCF38 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_881BCF38, lbl_880E71B8, 0)
/* Swing_DLL.xex 0x882359A0 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_882359A0, lbl_880F311C, 0)
/* Swing_DLL.xex 0x88235AA0 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_88235AA0, lbl_880F30F4, 0)
/* Swing_DLL.xex 0x88267498 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_88267498, lbl_880F37DC, 0)
/* Swing_DLL.xex 0x8826E7B8 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826E7B8, lbl_880F4678, 0)
/* Swing_DLL.xex 0x8826EE08 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826EE08, lbl_880F4868, 0)
/* Swing_DLL.xex 0x8826F0A8 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826F0A8, lbl_880F4A90, 0)
/* Swing_DLL.xex 0x8826F1A8 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826F1A8, lbl_880F4AD0, 0)
/* Swing_DLL.xex 0x8826F2A8 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826F2A8, lbl_880F4B10, 0)
/* Swing_DLL.xex 0x8826F3A8 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826F3A8, lbl_880F4B50, 0)
/* Swing_DLL.xex 0x8826F4A8 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826F4A8, lbl_880F4B90, 0)
/* Swing_DLL.xex 0x8826F708 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826F708, lbl_880F4BD0, 0)
/* Swing_DLL.xex 0x8826F9B8 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826F9B8, lbl_880F4C90, 0)
/* Swing_DLL.xex 0x8826FAB8 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826FAB8, lbl_880F4CD0, 0)
/* Swing_DLL.xex 0x8826FC68 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826FC68, lbl_880F4D50, 0)
/* Swing_DLL.xex 0x8826FD68 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_8826FD68, lbl_880F4D8C, 0)
/* Swing_DLL.xex 0x88279928 */ TS4_FACTORY_32(ts4_factory_obj32_tag0_88279928, lbl_880F6024, 0)
