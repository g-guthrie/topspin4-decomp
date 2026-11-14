/* SM1: validate-and-set a boolean state flag at +0x28 via a callee; returns the callee's nonzero error, else 0. */
typedef struct Ts4Flagged { char pad[1]; } Ts4Flagged;
#define SET_FLAG(NAME, CALLEE, OFF) \
    int NAME(Ts4Flagged *t, unsigned enable) { \
        int r; \
        if (enable) { \
            if (*((unsigned char *)t + OFF) != 0) return 0; \
            r = CALLEE(t, enable); \
            if (r != 0) return r; \
            *((unsigned char *)t + OFF) = 1; \
            return 0; \
        } \
        r = CALLEE(t, 0); \
        if (r != 0) return r; \
        *((unsigned char *)t + OFF) = 0; \
        return 0; \
    }
extern int fn_8831D7E0(void *, unsigned);
extern int fn_8831F808(void *, unsigned);
extern int fn_8830C980(void *, unsigned);
extern int ts4_call_seq_fn_8832EDB0_88383308(void *, unsigned);
extern int ts4_call_seq_fn_8832EDB0_88383340(void *, unsigned);
extern int ts4_call_seq_fn_8832EDB0_88383378(void *, unsigned);
extern int ts4_call_seq_fn_8832EDB0_883833B0(void *, unsigned);
extern int ts4_call_seq_fn_8832EDB0_883833E8(void *, unsigned);
extern int ts4_fn_883E63B8(void *, unsigned);
extern int ts4_if_call_seq_fn_8832EDB0_883294B8(void *, unsigned);
extern int fn_88377078(void *, unsigned);

/* Swing_DLL.xex 0x88309BF0 */
SET_FLAG(ts4_set_state_flag_88309BF0, fn_8831D7E0, 0x28)
/* Swing_DLL.xex 0x88309C60 */
SET_FLAG(ts4_set_state_flag_88309C60, fn_8831F808, 0x0)
/* Swing_DLL.xex 0x8830D258 */
SET_FLAG(ts4_set_state_flag_8830D258, fn_8830C980, 0x14)
/* Swing_DLL.xex 0x8831F330 */
SET_FLAG(ts4_set_state_flag_8831F330, ts4_call_seq_fn_8832EDB0_88383308, 0x4e8)
/* Swing_DLL.xex 0x8831F3A0 */
SET_FLAG(ts4_set_state_flag_8831F3A0, ts4_call_seq_fn_8832EDB0_88383340, 0x4e8)
/* Swing_DLL.xex 0x8831F410 */
SET_FLAG(ts4_set_state_flag_8831F410, ts4_call_seq_fn_8832EDB0_88383378, 0x4e8)
/* Swing_DLL.xex 0x8831F480 */
SET_FLAG(ts4_set_state_flag_8831F480, ts4_call_seq_fn_8832EDB0_883833B0, 0x4e8)
/* Swing_DLL.xex 0x8831F4F0 */
SET_FLAG(ts4_set_state_flag_8831F4F0, ts4_call_seq_fn_8832EDB0_883833E8, 0x4e8)
/* Swing_DLL.xex 0x88320600 */
SET_FLAG(ts4_set_state_flag_88320600, ts4_fn_883E63B8, 0x134)
/* Swing_DLL.xex 0x88329CB0 */
SET_FLAG(ts4_set_state_flag_88329CB0, ts4_if_call_seq_fn_8832EDB0_883294B8, 0x0)
/* Swing_DLL.xex 0x88334820 */
SET_FLAG(ts4_set_state_flag_88334820, fn_88377078, 0x3c)
