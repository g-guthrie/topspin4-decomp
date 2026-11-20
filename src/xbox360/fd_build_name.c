typedef unsigned int u32;
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
#else
#include <string.h>
#endif
extern char lbl_880D589C[];
extern char lbl_880DFD90[];
extern char lbl_880DFD98[];
extern char lbl_880DFDA4[];
extern char lbl_880DFE98[];
extern char lbl_880E1054[];
extern char lbl_880E1064[];
extern char lbl_880E106C[];
extern char lbl_880E1078[];
extern char lbl_880E1084[];
extern char lbl_880E1464[];
extern char lbl_880E1480[];
extern char lbl_880E148C[];
extern char lbl_880E1494[];
extern char lbl_880E149C[];
extern char lbl_880E14E4[];
extern char lbl_880E14EC[];
extern char lbl_880E14F4[];
extern char lbl_880E1534[];
extern char lbl_880E1540[];
extern char lbl_880E1548[];
extern char lbl_880E1550[];
extern char lbl_880E155C[];
extern char lbl_880E156C[];
extern char lbl_880E1574[];
extern char lbl_880E1584[];
extern char lbl_880E1590[];
extern char lbl_880E15A0[];
extern char lbl_880E15A8[];
extern char lbl_880E15B0[];
extern char lbl_880E15B8[];
extern char lbl_880E15C0[];
extern char lbl_880E15D4[];
extern char lbl_880E15E4[];
extern char lbl_880E15EC[];
extern char lbl_880E15F8[];
extern char lbl_880E1608[];
extern int fn_88608590(int, const char *);
extern void fn_88564EF0(char *dst, const char *src, u32 room);

/* Copy the literal STR1 into a 124-byte stack buffer (bounded), optionally append
   the caller's suffix, optionally append a second literal STR2, then intern the
   resulting string via fn_88608590(0, buf) and store the result in *out. */
#define TS4_BUILD_NAME_BODY(STR1) \
    char buf[124]; \
    const char *s = STR1; \
    char *d = buf; \
    while (d != buf + 124) { \
        char c = *s; \
        if (!c) break; \
        *d = c; d++; s++; \
    } \
    *d = 0; \
    if (suffix) \
        fn_88564EF0(buf, suffix, 124 - strlen(buf));

#define TS4_BUILD_NAME(NAME, STR1) \
    int *NAME(int *out, const char *suffix) \
    { \
        TS4_BUILD_NAME_BODY(STR1) \
        *out = fn_88608590(0, buf); \
        return out; \
    }

#define TS4_BUILD_NAME2(NAME, STR1, STR2) \
    int *NAME(int *out, const char *suffix) \
    { \
        TS4_BUILD_NAME_BODY(STR1) \
        fn_88564EF0(buf, STR2, 124 - strlen(buf)); \
        *out = fn_88608590(0, buf); \
        return out; \
    }

/* Swing_DLL.xex 0x88838DB0 */
TS4_BUILD_NAME(ts4_build_name_from_literal_88838DB0, lbl_880E15F8)
/* Swing_DLL.xex 0x88839118 */
TS4_BUILD_NAME(ts4_build_name_from_literal_88839118, lbl_880E15D4)
/* Swing_DLL.xex 0x888391C8 */
TS4_BUILD_NAME(ts4_build_name_from_literal_888391C8, lbl_880E15C0)
/* Swing_DLL.xex 0x88839360 */
TS4_BUILD_NAME(ts4_build_name_from_literal_88839360, lbl_880E15B8)
/* Swing_DLL.xex 0x888397B0 */
TS4_BUILD_NAME(ts4_build_name_from_literal_888397B0, lbl_880E1590)
/* Swing_DLL.xex 0x88839860 */
TS4_BUILD_NAME(ts4_build_name_from_literal_88839860, lbl_880E1584)
/* Swing_DLL.xex 0x88839978 */
TS4_BUILD_NAME(ts4_build_name_from_literal_88839978, lbl_880E1574)
/* Swing_DLL.xex 0x88839A28 */
TS4_BUILD_NAME(ts4_build_name_from_literal_88839A28, lbl_880E156C)
/* Swing_DLL.xex 0x88839F60 */
TS4_BUILD_NAME(ts4_build_name_from_literal_88839F60, lbl_880E1548)
/* Swing_DLL.xex 0x8883A0F8 */
TS4_BUILD_NAME(ts4_build_name_from_literal_8883A0F8, lbl_880E1534)
/* Swing_DLL.xex 0x8883A528 */
TS4_BUILD_NAME(ts4_build_name_from_literal_8883A528, lbl_880E14F4)
/* Swing_DLL.xex 0x8883AB00 */
TS4_BUILD_NAME(ts4_build_name_from_literal_8883AB00, lbl_880E1054)
/* Swing_DLL.xex 0x8883ABB0 */
TS4_BUILD_NAME(ts4_build_name_from_literal_8883ABB0, lbl_880E148C)
/* Swing_DLL.xex 0x8883AC60 */
TS4_BUILD_NAME(ts4_build_name_from_literal_8883AC60, lbl_880E1480)
/* Swing_DLL.xex 0x8883AFC8 */
TS4_BUILD_NAME(ts4_build_name_from_literal_8883AFC8, lbl_880DFE98)
/* Swing_DLL.xex 0x8883B078 */
TS4_BUILD_NAME(ts4_build_name_from_literal_8883B078, lbl_880E1464)
/* Swing_DLL.xex 0x88865950 */
TS4_BUILD_NAME(ts4_build_name_from_literal_88865950, lbl_880DFD98)
/* Swing_DLL.xex 0x88865A00 */
TS4_BUILD_NAME(ts4_build_name_from_literal_88865A00, lbl_880DFD90)
/* Swing_DLL.xex 0x88838CC8 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_88838CC8, lbl_880E15F8, lbl_880E1608)
/* Swing_DLL.xex 0x88838E60 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_88838E60, lbl_880E15EC, lbl_880E1084)
/* Swing_DLL.xex 0x88838F48 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_88838F48, lbl_880E15E4, lbl_880E1540)
/* Swing_DLL.xex 0x88839030 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_88839030, lbl_880E15E4, lbl_880E1084)
/* Swing_DLL.xex 0x88839278 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_88839278, lbl_880D589C, lbl_880E1084)
/* Swing_DLL.xex 0x88839410 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_88839410, lbl_880E15B0, lbl_880E1540)
/* Swing_DLL.xex 0x888394F8 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_888394F8, lbl_880E15B0, lbl_880E1084)
/* Swing_DLL.xex 0x888395E0 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_888395E0, lbl_880E15A8, lbl_880E1084)
/* Swing_DLL.xex 0x888396C8 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_888396C8, lbl_880E15A0, lbl_880E1084)
/* Swing_DLL.xex 0x88839CA8 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_88839CA8, lbl_880E1548, lbl_880E155C)
/* Swing_DLL.xex 0x88839D90 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_88839D90, lbl_880E1548, lbl_880E1550)
/* Swing_DLL.xex 0x88839E78 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_88839E78, lbl_880E1548, lbl_880E149C)
/* Swing_DLL.xex 0x8883A010 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_8883A010, lbl_880E1534, lbl_880E1540)
/* Swing_DLL.xex 0x8883A5D8 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_8883A5D8, lbl_880E14E4, lbl_880E14EC)
/* Swing_DLL.xex 0x8883A6C0 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_8883A6C0, lbl_880E14E4, lbl_880E1084)
/* Swing_DLL.xex 0x8883A868 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_8883A868, lbl_880E1494, lbl_880E149C)
/* Swing_DLL.xex 0x8883A950 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_8883A950, lbl_880E1494, lbl_880E1084)
/* Swing_DLL.xex 0x8883AD10 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_8883AD10, lbl_880E1064, lbl_880E1084)
/* Swing_DLL.xex 0x8883ADF8 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_8883ADF8, lbl_880E1064, lbl_880E1078)
/* Swing_DLL.xex 0x8883AEE0 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_8883AEE0, lbl_880E1064, lbl_880E106C)
/* Swing_DLL.xex 0x88865868 */
TS4_BUILD_NAME2(ts4_build_name_from_two_literals_88865868, lbl_880DFD98, lbl_880DFDA4)
