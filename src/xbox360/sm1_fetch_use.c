/* SM1: fetch a value through an out-parameter, and if that succeeds hand it plus a float to a second callee. */
#define FETCH_THEN_USE(NAME, GET, USE) \
    int NAME(void *t, float x) { \
        int value; \
        int r = GET(t, &value); \
        if (r == 0) r = USE(value, x); \
        return r; \
    }
extern int fn_88322CA8(void *, int *);
extern int fn_88326660(int, float);
extern int ts4_if_get_u32_off4c_883251A0(int, float);
extern int ts4_if_get_u32_off4c_883268B8(int, float);
extern int ts4_if_get_u32_off4c_88325200(int, float);
extern int ts4_if_set_u32_off0_8832F930(void *, int *);
extern int fn_88330450(int, float);
extern int fn_88330480(int, float);

/* Swing_DLL.xex 0x883170A8 */
FETCH_THEN_USE(ts4_fetch_then_use_float_883170A8, fn_88322CA8, fn_88326660)
/* Swing_DLL.xex 0x883176B0 */
FETCH_THEN_USE(ts4_fetch_then_use_float_883176B0, fn_88322CA8, ts4_if_get_u32_off4c_883251A0)
/* Swing_DLL.xex 0x883176F8 */
FETCH_THEN_USE(ts4_fetch_then_use_float_883176F8, fn_88322CA8, ts4_if_get_u32_off4c_883268B8)
/* Swing_DLL.xex 0x88317740 */
FETCH_THEN_USE(ts4_fetch_then_use_float_88317740, fn_88322CA8, ts4_if_get_u32_off4c_88325200)
/* Swing_DLL.xex 0x88317A60 */
FETCH_THEN_USE(ts4_fetch_then_use_float_88317A60, ts4_if_set_u32_off0_8832F930, fn_88330450)
/* Swing_DLL.xex 0x88317AF0 */
FETCH_THEN_USE(ts4_fetch_then_use_float_88317AF0, ts4_if_set_u32_off0_8832F930, fn_88330480)
