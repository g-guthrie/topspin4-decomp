/* Family FAM1: destructors of singleton classes. Each destructor installs its class vtable, clears the
 * class's file-static instance pointer and runs the base-class destructor (a tail call); the scalar-deleting
 * variant inlines that destructor and frees the object when bit 0 of the flags is set.
 * The instance pointers are file statics of the original translation units: declaring them static here gives
 * the same code (an extern global schedules the vtable address differently). */

extern void ts4_tsu_cleanup_end(void *object);
extern void fn_88756848(void *self);
extern void ts4_if_call_seq_lbl_880F2254_88721C40(void *self);
extern void ts4_if_call_seq_lbl_880F63C0_88638FC8(void *self);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *self);
extern char lbl_880D4B88[];
extern char lbl_880D5078[];
extern char lbl_880D50F0[];
extern char lbl_880D5168[];
extern char lbl_880D5EF0[];
extern char lbl_880DB300[];
extern char lbl_880DB450[];
extern char lbl_880DB620[];
extern char lbl_880DB7BC[];
extern char lbl_880DBC04[];
extern char lbl_880E0660[];
extern char lbl_880E06D8[];
extern char lbl_880E0700[];
extern char lbl_880E4C8C[];
extern char lbl_880E731C[];
extern char lbl_880EF370[];
extern char lbl_880F2118[];
extern char lbl_880F22A8[];
extern char lbl_880F5118[];
extern char lbl_880F7B28[];

/* File-static singleton instance pointers. */
static void *g_ts4_session_state;
static void *lbl_88D45878;
static void *lbl_88D4588C;
static void *lbl_88D458A0;
static void *lbl_88D458D8;
static void *lbl_88D45914;
static void *lbl_88D45938;
static void *lbl_88D4593C;
static void *lbl_88D45944;
static void *lbl_88D45960;
static void *lbl_88D459C8;
static void *lbl_88D459CC;
static void *lbl_88D459D0;
static void *lbl_88D45A28;
static void *lbl_88D45A08;
static void *lbl_88D45A64;
static void *lbl_88D45A6C;
static void *lbl_88D45AD4;
static void *lbl_88D45B08;
static void *lbl_88D45B2C;

/* ~T(): vtable, clear the instance pointer, base destructor. */
#define TS4_SINGLETON_DTOR(A, vtbl, instance, base_dtor)                                                    \
    void ts4_singleton_dtor_##A(void **self)                                                                \
    {                                                                                                        \
        *self = vtbl;                                                                                        \
        instance = 0;                                                                                        \
        base_dtor(self);                                                                                     \
    }

/* Scalar-deleting destructor: inlined ~T(), then free the object if (flags & 1). */
#define TS4_SINGLETON_DELETING_DTOR(A, vtbl, instance, base_dtor)                                           \
    void *ts4_singleton_deleting_dtor_##A(void **self, unsigned int flags)                                  \
    {                                                                                                        \
        *self = vtbl;                                                                                        \
        instance = 0;                                                                                        \
        base_dtor(self);                                                                                     \
        if (flags & 1)                                                                                       \
            ts4_tsu_cleanup_end(self);                                                                       \
        return self;                                                                                         \
    }

TS4_SINGLETON_DELETING_DTOR(88152038, lbl_880D5EF0, g_ts4_session_state, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88152038 */
TS4_SINGLETON_DELETING_DTOR(8815FF38, lbl_880D5078, lbl_88D45878, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x8815FF38 */
TS4_SINGLETON_DELETING_DTOR(88160210, lbl_880D4B88, lbl_88D4588C, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88160210 */
TS4_SINGLETON_DELETING_DTOR(88160600, lbl_880D5168, lbl_88D458A0, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88160600 */
TS4_SINGLETON_DELETING_DTOR(88160730, lbl_880D50F0, lbl_88D458D8, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88160730 */
TS4_SINGLETON_DELETING_DTOR(8817C8A8, lbl_880DB300, lbl_88D45914, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x8817C8A8 */
TS4_SINGLETON_DELETING_DTOR(8817CE68, lbl_880DB620, lbl_88D45938, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x8817CE68 */
TS4_SINGLETON_DELETING_DTOR(8817CFA0, lbl_880DBC04, lbl_88D4593C, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x8817CFA0 */
TS4_SINGLETON_DELETING_DTOR(8817D5A0, lbl_880DB7BC, lbl_88D45944, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x8817D5A0 */
TS4_SINGLETON_DELETING_DTOR(8817DDB8, lbl_880DB450, lbl_88D45960, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x8817DDB8 */
TS4_SINGLETON_DELETING_DTOR(881AA7F8, lbl_880E06D8, lbl_88D459C8, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x881AA7F8 */
TS4_SINGLETON_DELETING_DTOR(881AA860, lbl_880E0700, lbl_88D459CC, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x881AA860 */
TS4_SINGLETON_DELETING_DTOR(881AA8C8, lbl_880E0660, lbl_88D459D0, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x881AA8C8 */
TS4_SINGLETON_DELETING_DTOR(881BD6C0, lbl_880E731C, lbl_88D45A28, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x881BD6C0 */
TS4_SINGLETON_DELETING_DTOR(88211638, lbl_880E4C8C, lbl_88D45A08, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88211638 */
TS4_SINGLETON_DELETING_DTOR(88213AD0, lbl_880EF370, lbl_88D45A64, ts4_if_call_seq_lbl_880F63C0_88638FC8) /* Swing_DLL.xex 0x88213AD0 */
TS4_SINGLETON_DELETING_DTOR(8821AD20, lbl_880F22A8, lbl_88D45A6C, ts4_if_call_seq_lbl_880F2254_88721C40) /* Swing_DLL.xex 0x8821AD20 */
TS4_SINGLETON_DELETING_DTOR(8821C908, lbl_880F2118, lbl_88D45AD4, fn_88756848) /* Swing_DLL.xex 0x8821C908 */
TS4_SINGLETON_DELETING_DTOR(88273628, lbl_880F5118, lbl_88D45B08, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88273628 */
TS4_SINGLETON_DELETING_DTOR(8827CF00, lbl_880F7B28, lbl_88D45B2C, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x8827CF00 */
TS4_SINGLETON_DTOR(8861A990, lbl_880F7B28, lbl_88D45B2C, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x8861A990 */
TS4_SINGLETON_DTOR(8872B110, lbl_880F22A8, lbl_88D45A6C, ts4_if_call_seq_lbl_880F2254_88721C40) /* Swing_DLL.xex 0x8872B110 */
TS4_SINGLETON_DTOR(88756950, lbl_880F2118, lbl_88D45AD4, fn_88756848) /* Swing_DLL.xex 0x88756950 */
TS4_SINGLETON_DTOR(8878BE78, lbl_880EF370, lbl_88D45A64, ts4_if_call_seq_lbl_880F63C0_88638FC8) /* Swing_DLL.xex 0x8878BE78 */
TS4_SINGLETON_DTOR(887CBD20, lbl_880E4C8C, lbl_88D45A08, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x887CBD20 */
TS4_SINGLETON_DTOR(887CD8F0, lbl_880E731C, lbl_88D45A28, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x887CD8F0 */
TS4_SINGLETON_DTOR(887EB378, lbl_880E4C8C, lbl_88D45A08, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x887EB378 */
TS4_SINGLETON_DTOR(88866460, lbl_880E0660, lbl_88D459D0, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88866460 */
TS4_SINGLETON_DTOR(888664D0, lbl_880E0700, lbl_88D459CC, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x888664D0 */
TS4_SINGLETON_DTOR(88866638, lbl_880E06D8, lbl_88D459C8, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88866638 */
TS4_SINGLETON_DTOR(888C7F10, lbl_880DB450, lbl_88D45960, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x888C7F10 */
TS4_SINGLETON_DTOR(888CAA20, lbl_880DB7BC, lbl_88D45944, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x888CAA20 */
TS4_SINGLETON_DTOR(888CB710, lbl_880DBC04, lbl_88D4593C, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x888CB710 */
TS4_SINGLETON_DTOR(888CB958, lbl_880DB620, lbl_88D45938, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x888CB958 */
TS4_SINGLETON_DTOR(888CDDA0, lbl_880DB300, lbl_88D45914, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x888CDDA0 */
TS4_SINGLETON_DTOR(88934F38, lbl_880D5EF0, g_ts4_session_state, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88934F38 */
TS4_SINGLETON_DTOR(889459F0, lbl_880D50F0, lbl_88D458D8, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x889459F0 */
TS4_SINGLETON_DTOR(88945D88, lbl_880D5168, lbl_88D458A0, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88945D88 */
TS4_SINGLETON_DTOR(88947700, lbl_880D4B88, lbl_88D4588C, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88947700 */
TS4_SINGLETON_DTOR(88947FB0, lbl_880D5078, lbl_88D45878, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88947FB0 */
TS4_SINGLETON_DTOR(88998AF0, lbl_880D5EF0, g_ts4_session_state, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x88998AF0 */
TS4_SINGLETON_DTOR(889A26F0, lbl_880D5EF0, g_ts4_session_state, ts4_if_call_seq_lbl_880F7EE4_88617D28) /* Swing_DLL.xex 0x889A26F0 */
