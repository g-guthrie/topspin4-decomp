/* SM1 (/O1): tear down a global singleton: finalize it, report a failure through the context, then clear the global. */
#define SINGLETON_SHUTDOWN(NAME, GLOBAL, FINALIZE, CTX, MSG, REPORT, LINE) \
    int NAME(void) { \
        if (GLOBAL != 0) { \
            int r = FINALIZE(GLOBAL); \
            if (r != 0) return r; \
            REPORT(*(void **)(CTX + 4), GLOBAL, &MSG, LINE); \
            GLOBAL = 0; \
        } \
        return 0; \
    }
extern void *lbl_88CAC9AC;
extern int fn_883E8B28(void *);
extern char lbl_88039A20;
extern char *lbl_88B3302C;
extern void fn_88315F10(void *, void *, void *, int);
extern void *lbl_88CAC9B0;
extern int ts4_release_buffer_883E8C08(void *);
extern void *lbl_88CAC9B4;
extern int fn_883E8EB8(void *);
extern void *lbl_88CAC9B8;
extern int fn_883E9170(void *);
extern void *lbl_88CAC9BC;
extern int fn_883E9758(void *);
extern void *lbl_88CAC9C4;
extern int fn_883EA1F8(void *);
extern void *lbl_88CAC9C0;
extern int fn_883EBC90(void *);

/* Swing_DLL.xex 0x883E8B98 */
SINGLETON_SHUTDOWN(ts4_singleton_shutdown_883E8B98, lbl_88CAC9AC, fn_883E8B28, lbl_88B3302C, lbl_88039A20, fn_88315F10, 0x431)
/* Swing_DLL.xex 0x883E8D80 */
SINGLETON_SHUTDOWN(ts4_singleton_shutdown_883E8D80, lbl_88CAC9B0, ts4_release_buffer_883E8C08, lbl_88B3302C, lbl_88039A20, fn_88315F10, 0x4c2)
/* Swing_DLL.xex 0x883E9000 */
SINGLETON_SHUTDOWN(ts4_singleton_shutdown_883E9000, lbl_88CAC9B4, fn_883E8EB8, lbl_88B3302C, lbl_88039A20, fn_88315F10, 0x551)
/* Swing_DLL.xex 0x883E92B8 */
SINGLETON_SHUTDOWN(ts4_singleton_shutdown_883E92B8, lbl_88CAC9B8, fn_883E9170, lbl_88B3302C, lbl_88039A20, fn_88315F10, 0x5d5)
/* Swing_DLL.xex 0x883E9880 */
SINGLETON_SHUTDOWN(ts4_singleton_shutdown_883E9880, lbl_88CAC9BC, fn_883E9758, lbl_88B3302C, lbl_88039A20, fn_88315F10, 0x6ab)
/* Swing_DLL.xex 0x883EA470 */
SINGLETON_SHUTDOWN(ts4_singleton_shutdown_883EA470, lbl_88CAC9C4, fn_883EA1F8, lbl_88B3302C, lbl_88039A20, fn_88315F10, 0xa79)
/* Swing_DLL.xex 0x883EBDC0 */
SINGLETON_SHUTDOWN(ts4_singleton_shutdown_883EBDC0, lbl_88CAC9C0, fn_883EBC90, lbl_88B3302C, lbl_88039A20, fn_88315F10, 0x926)
