/* Swing_DLL.xex 0x885DEE78-0x885DF550, executable version 0.0.0.3. */
typedef unsigned int u32;

extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern u32 ts4_read_indexed_u32_property_885DCDA8(void *obj, u32 code, u32 idx);
extern void fn_885DCE58(void *p, u32 size, u32 z, u32 flag);
extern char lbl_880B9788[], lbl_880B4598[], lbl_880B4540[], lbl_880B97F0[];
extern u32 lbl_88C42CC8[];

typedef void (*Ts4ReportCb)(void *dst, const void *str, u32 a, u32 size, u32 idx, u32 flag);

/* Indexed property check: true when element IDX of the property CODE is zero. */
#define TS4_ZERO_INDEXED_REPORT(NAME, CODE, SZO, DESC, OFF, LINE) \
    u32 NAME(void *obj, u32 idx, void *out, Ts4ReportCb cb, void *dst) \
    { \
        u32 r; \
        if (obj == 0) fn_885DC838(obj, lbl_880B4540, lbl_880B4598, lbl_880B9788, LINE); \
        if (ts4_read_indexed_u32_property_885DCDA8(obj, CODE, idx) == 0) { \
            if (out) fn_885DCE58(out, SZO, 0, 1); \
            if (cb && dst) cb(dst, lbl_880B97F0, lbl_88C42CC8[OFF / 4], DESC, idx, 1); \
            r = 1; \
        } else { \
            if (out) fn_885DCE58(out, SZO, 0, 0); \
            if (cb && dst) cb(dst, lbl_880B97F0, lbl_88C42CC8[OFF / 4], DESC, idx, 0); \
            r = 0; \
        } \
        return r; \
    }

TS4_ZERO_INDEXED_REPORT(ts4_report_zero_indexed_885DEE78, 23, 27, 46, 184, 2047) /* 0x885DEE78 */
TS4_ZERO_INDEXED_REPORT(ts4_report_zero_indexed_885DF310, 22, 30, 49, 196, 2261) /* 0x885DF310 */
TS4_ZERO_INDEXED_REPORT(ts4_report_zero_indexed_885DF430, 37, 34, 57, 228, 2316) /* 0x885DF430 */
