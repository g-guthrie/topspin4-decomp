/* SM1 (/O1): forward a call to the child object stored at +8, or return 0 when there is none. */
typedef struct Ts4Parent8 { int pad[2]; void *child; } Ts4Parent8;
#define FWD_CHILD(NAME, CALLEE) \
    int NAME(Ts4Parent8 *t) { \
        void *p = t->child; \
        if (p) { \
            int r = CALLEE(p); \
            if (r != 0) return r; \
        } \
        return 0; \
    }
extern int fn_883FC7B0(void *);
extern int fn_883FBDC0(void *);
extern int ts4_get_u32_off80_883FB590(void *);
extern int ts4_get_u32_off80_883FB598(void *);
extern int fn_883FB5A0(void *);
extern int ts4_if_get_u8_off1c_883DF9F0(void *);
extern int ts4_get_u32_off80_883FB610(void *);
extern int ts4_get_u32_off80_883FB618(void *);

/* Swing_DLL.xex 0x883E40C0 */
FWD_CHILD(ts4_forward_to_child_nonzero_883E40C0, fn_883FC7B0)
/* Swing_DLL.xex 0x883E41F0 */
FWD_CHILD(ts4_forward_to_child_nonzero_883E41F0, fn_883FBDC0)
/* Swing_DLL.xex 0x883E4228 */
FWD_CHILD(ts4_forward_to_child_nonzero_883E4228, ts4_get_u32_off80_883FB590)
/* Swing_DLL.xex 0x883E4260 */
FWD_CHILD(ts4_forward_to_child_nonzero_883E4260, ts4_get_u32_off80_883FB598)
/* Swing_DLL.xex 0x883E4328 */
FWD_CHILD(ts4_forward_to_child_nonzero_883E4328, fn_883FB5A0)
/* Swing_DLL.xex 0x883E4360 */
FWD_CHILD(ts4_forward_to_child_nonzero_883E4360, ts4_if_get_u8_off1c_883DF9F0)
/* Swing_DLL.xex 0x883E4398 */
FWD_CHILD(ts4_forward_to_child_nonzero_883E4398, ts4_get_u32_off80_883FB610)
/* Swing_DLL.xex 0x883E43D0 */
FWD_CHILD(ts4_forward_to_child_nonzero_883E43D0, ts4_get_u32_off80_883FB618)
