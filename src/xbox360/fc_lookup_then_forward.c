/* Swing_DLL.xex, MSVC 16.00.10224.00 /O2 /Oi. One macro per cluster; one line per original address. */
typedef unsigned int u32;

int fn_88309DB8(void *, void *);
int fn_88322CA8(void *, void *);
int fn_8832F930(void *, void *);
int fn_8832BFC0(void *, void *);
void fn_8830B110(void *, int);
void fn_8830B178(void *, int);
void fn_8830B458(void *, int);
void fn_8830B548(void *, int);
void fn_8830B820(void *, int);
void fn_8830B940(void *, int);
void fn_8830BF10(void *, int);
void fn_8830C8D0(void *, int);
void fn_8830C930(void *, int);
void fn_8830E3B8(void *, int);
void fn_8830E6C8(void *, int);
void fn_88324DB0(void *, int);
void fn_883250D8(void *, int);
void fn_88325260(void *, int);
void fn_883252E8(void *, int);
void fn_88325810(void *, int);
void fn_88326520(void *, int);
void fn_88326BF8(void *, int);
void fn_88328CA0(void *, int);
void fn_8832C330(void *, int);
void fn_8832CBA8(void *, int);
void fn_8832CC28(void *, int);
void fn_8832CC38(void *, int);
void fn_8832FA48(void *, int);
void fn_8832FDE0(void *, int);
void fn_8832FE00(void *, int);
void fn_883300B0(void *, int);
void fn_88330258(void *, int);
void fn_883304F8(void *, int);
void fn_883CF098(void *, int);

/* Calls lookup(a, &out); if it returns 0, calls handler(out, arg). */
#define LOOKUP_THEN_FORWARD(name, lookup, handler) \
void name(void *a, int arg) \
{ \
    void *out; \
    if (!lookup(a, &out)) { \
        handler(out, arg); \
    } \
}

/* Swing_DLL.xex 0x88308B18 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88308B18, fn_88309DB8, fn_8830B110)

/* Swing_DLL.xex 0x88308C80 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88308C80, fn_88309DB8, fn_8830B178)

/* Swing_DLL.xex 0x88308CC8 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88308CC8, fn_88309DB8, fn_8830B458)

/* Swing_DLL.xex 0x88308D10 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88308D10, fn_88309DB8, fn_8830E6C8)

/* Swing_DLL.xex 0x88309078 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88309078, fn_88309DB8, fn_8830B548)

/* Swing_DLL.xex 0x883090C0 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_883090C0, fn_88309DB8, fn_8830B820)

/* Swing_DLL.xex 0x88309210 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88309210, fn_88309DB8, fn_8830B940)

/* Swing_DLL.xex 0x883093F0 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_883093F0, fn_88309DB8, fn_8830E3B8)

/* Swing_DLL.xex 0x88309520 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88309520, fn_88309DB8, fn_8830BF10)

/* Swing_DLL.xex 0x88309568 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88309568, fn_88309DB8, fn_8830C8D0)

/* Swing_DLL.xex 0x883095B0 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_883095B0, fn_88309DB8, fn_8830C930)

/* Swing_DLL.xex 0x88316FB0 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88316FB0, fn_88322CA8, fn_88326520)

/* Swing_DLL.xex 0x883172D0 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_883172D0, fn_88322CA8, fn_88324DB0)

/* Swing_DLL.xex 0x883173D8 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_883173D8, fn_88322CA8, fn_88325260)

/* Swing_DLL.xex 0x88317420 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88317420, fn_88322CA8, fn_883252E8)

/* Swing_DLL.xex 0x88317468 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88317468, fn_88322CA8, fn_88326BF8)

/* Swing_DLL.xex 0x883174B0 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_883174B0, fn_88322CA8, fn_88325810)

/* Swing_DLL.xex 0x88317610 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88317610, fn_88322CA8, fn_883250D8)

/* Swing_DLL.xex 0x883178C8 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_883178C8, fn_88322CA8, fn_88328CA0)

/* Swing_DLL.xex 0x88317978 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88317978, fn_88322CA8, fn_883CF098)

/* Swing_DLL.xex 0x88317AA8 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88317AA8, fn_8832F930, fn_8832FA48)

/* Swing_DLL.xex 0x88317C20 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88317C20, fn_8832F930, fn_8832FDE0)

/* Swing_DLL.xex 0x88317C68 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88317C68, fn_8832F930, fn_8832FE00)

/* Swing_DLL.xex 0x88317D38 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88317D38, fn_8832F930, fn_883304F8)

/* Swing_DLL.xex 0x88317D80 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88317D80, fn_8832F930, fn_883300B0)

/* Swing_DLL.xex 0x88317E20 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88317E20, fn_8832F930, fn_88330258)

/* Swing_DLL.xex 0x88318348 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88318348, fn_8832BFC0, fn_8832C330)

/* Swing_DLL.xex 0x88318390 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88318390, fn_8832BFC0, fn_8832CBA8)

/* Swing_DLL.xex 0x883183D8 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_883183D8, fn_8832BFC0, fn_8832CC28)

/* Swing_DLL.xex 0x88318420 */
LOOKUP_THEN_FORWARD(ts4_lookup_then_forward_88318420, fn_8832BFC0, fn_8832CC38)

