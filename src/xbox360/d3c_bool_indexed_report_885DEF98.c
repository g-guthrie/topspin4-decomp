/* Swing_DLL.xex 0x885DEF98-0x885E130C, executable version 0.0.0.3. */
typedef unsigned int u32;

extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern u32 ts4_read_indexed_u32_property_885DCDA8(void *obj, u32 code, u32 idx);
extern void fn_885DCE58(void *p, u32 size, u32 z, u32 flag);
extern char lbl_880B9788[], lbl_880B4598[], lbl_880B4540[], lbl_880B97F0[];
extern u32 lbl_88C42CC8[];

typedef void (*Ts4ReportCb)(void *dst, const void *str, u32 a, u32 size, u32 idx, u32 flag);

/* Indexed boolean property check: asserts the object, tests element IDX of the property CODE
   against CMP, reports the boolean through the output slot and callback. */
#define TS4_BOOL_INDEXED_REPORT(NAME, CODE, CMP, SZT, SZF, DESC, OFF, LINE) \
    u32 NAME(void *obj, u32 idx, void *out, Ts4ReportCb cb, void *dst) \
    { \
        u32 r; \
        if (obj == 0) fn_885DC838(obj, lbl_880B4540, lbl_880B4598, lbl_880B9788, LINE); \
        if (ts4_read_indexed_u32_property_885DCDA8(obj, CODE, idx) == CMP) { \
            if (out) fn_885DCE58(out, SZT, 0, 1); \
            if (cb && dst) cb(dst, lbl_880B97F0, lbl_88C42CC8[OFF / 4], DESC, idx, 1); \
            r = 1; \
        } else { \
            if (out) fn_885DCE58(out, SZF, 0, 0); \
            if (cb && dst) cb(dst, lbl_880B97F0, lbl_88C42CC8[OFF / 4], DESC, idx, 0); \
            r = 0; \
        } \
        return r; \
    }

TS4_BOOL_INDEXED_REPORT(ts4_report_bool_indexed_885DEF98, 23, 1, 28, 28, 47, 188, 2102) /* 0x885DEF98 */
TS4_BOOL_INDEXED_REPORT(ts4_report_bool_indexed_885DF0C0, 22, 1, 29, 29, 48, 192, 2155) /* 0x885DF0C0 */
TS4_BOOL_INDEXED_REPORT(ts4_report_bool_indexed_885DF1E8, 22, 2, 30, 30, 49, 196, 2208) /* 0x885DF1E8 */
TS4_BOOL_INDEXED_REPORT(ts4_report_bool_indexed_885DF550, 37, 1, 35, 35, 58, 232, 2371) /* 0x885DF550 */
TS4_BOOL_INDEXED_REPORT(ts4_report_bool_indexed_885DF678, 37, 2, 36, 36, 59, 236, 2426) /* 0x885DF678 */
TS4_BOOL_INDEXED_REPORT(ts4_report_bool_indexed_885E11E8, 7, 1, 43, 4, 105, 420, 447) /* 0x885E11E8 */
