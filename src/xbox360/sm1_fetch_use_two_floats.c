/* SM1: fetch a value through an out-parameter; on success hand it plus two floats to a second callee. */
#define FETCH_THEN_USE2(NAME, GET, USE) \
    int NAME(void *t, float x, float y) { \
        int value; \
        int r = GET(t, &value); \
        if (r == 0) r = USE(value, x, y); \
        return r; \
    }
extern int fn_88322CA8(void *, int *);
extern int fn_88326760(int, float, float);
extern int ts4_clamp_pair_88328C18(int, float, float);
extern int ts4_if_set_u32_off0_8832F930(void *, int *);
extern int ts4_set_clamped_pair_883304A0(int, float, float);

/* Swing_DLL.xex 0x88317550 */
FETCH_THEN_USE2(ts4_fetch_then_use_two_floats_88317550, fn_88322CA8, fn_88326760)
/* Swing_DLL.xex 0x88317658 */
FETCH_THEN_USE2(ts4_fetch_then_use_two_floats_88317658, fn_88322CA8, ts4_clamp_pair_88328C18)
/* Swing_DLL.xex 0x88317B38 */
FETCH_THEN_USE2(ts4_fetch_then_use_two_floats_88317B38, ts4_if_set_u32_off0_8832F930, ts4_set_clamped_pair_883304A0)
