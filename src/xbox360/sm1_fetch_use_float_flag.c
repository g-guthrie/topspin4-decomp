/* SM1: fetch a value through an out-parameter; on success hand it, a float and a zero flag to a second callee. */
#define FETCH_THEN_USE_Z(NAME, GET, USE, FLAG) \
    int NAME(void *t, float x) { \
        int value; \
        int r = GET(t, &value); \
        if (r == 0) r = USE(value, x, FLAG); \
        return r; \
    }
extern int fn_88322CA8(void *, int *);
extern int fn_88323DC0(int, float, int);
extern int fn_88323FF8(int, float, int);

/* Swing_DLL.xex 0x88317060 */
FETCH_THEN_USE_Z(ts4_fetch_then_use_float_flag_88317060, fn_88322CA8, fn_88323DC0, 0x0)
/* Swing_DLL.xex 0x883170F0 */
FETCH_THEN_USE_Z(ts4_fetch_then_use_float_flag_883170F0, fn_88322CA8, fn_88323FF8, 0x1)
