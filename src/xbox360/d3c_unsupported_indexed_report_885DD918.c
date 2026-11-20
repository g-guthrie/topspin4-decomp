/* Swing_DLL.xex 0x885DD918-0x885DFD38, executable version 0.0.0.3. */
typedef unsigned int u32;

extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern void fn_885DCE58(void *p, u32 size, u32 z, u32 flag);
extern char lbl_880B9788[], lbl_880B4598[], lbl_880B4540[], lbl_880B97F0[];
extern u32 lbl_88C42CC8[];

typedef void (*Ts4ReportCb)(void *dst, const void *str, u32 a, u32 size, u32 idx, u32 flag);

/* Indexed property report that always reports "false" (unsupported property). */
#define TS4_UNSUPPORTED_INDEXED_REPORT(NAME, SZO, DESC, OFF, LINE) \
    u32 NAME(void *obj, u32 idx, void *out, Ts4ReportCb cb, void *dst) \
    { \
        if (obj == 0) fn_885DC838(obj, lbl_880B4540, lbl_880B4598, lbl_880B9788, LINE); \
        if (out) fn_885DCE58(out, SZO, 0, 0); \
        if (cb && dst) cb(dst, lbl_880B97F0, lbl_88C42CC8[OFF / 4], DESC, idx, 0); \
        return 0; \
    }

TS4_UNSUPPORTED_INDEXED_REPORT(ts4_report_unsupported_indexed_885DD918, 38, 63, 252, 988) /* 0x885DD918 */
TS4_UNSUPPORTED_INDEXED_REPORT(ts4_report_unsupported_indexed_885DF9A0, 32, 52, 208, 2576) /* 0x885DF9A0 */
TS4_UNSUPPORTED_INDEXED_REPORT(ts4_report_unsupported_indexed_885DFC90, 41, 101, 404, 2744) /* 0x885DFC90 */
