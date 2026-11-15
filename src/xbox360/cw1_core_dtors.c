/* CW1: scalar-deleting destructors of objects with a secondary vtable (Swing_DLL.xex 0x88151810 ...). */
typedef unsigned int u32;

extern char lbl_880D1F18;
extern char lbl_880D1F54;
extern char lbl_880D1F64;
extern void ts4_tsu_cleanup_end(void *object);

#define CW1_DUAL_DTOR(name, off, second_vtable) \
    void *name(char *object, u32 delete_flags) \
    { \
        *(void **)(object + (off)) = &second_vtable; \
        *(void **)object = &lbl_880D1F18; \
        if ((delete_flags & 1U) != 0) { \
            ts4_tsu_cleanup_end(object); \
        } \
        return object; \
    }

CW1_DUAL_DTOR(ts4_runtime_process_record_family_51810, 0x20, lbl_880D1F64) /* Swing_DLL.xex 0x88151810 */
CW1_DUAL_DTOR(ts4_runtime_process_record_family_51878, 0x1c, lbl_880D1F64) /* Swing_DLL.xex 0x88151878 */
CW1_DUAL_DTOR(ts4_runtime_process_record_family_51cd0, 0x1c, lbl_880D1F54) /* Swing_DLL.xex 0x88151CD0 */
