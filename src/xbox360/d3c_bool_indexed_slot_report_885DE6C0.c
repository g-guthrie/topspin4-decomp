/* Swing_DLL.xex 0x885DE6C0-0x885DEA38, executable version 0.0.0.3. */
typedef unsigned int u32;

extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern u32 ts4_read_indexed_u32_property_885DCDA8(void *obj, u32 code, u32 idx);
extern void fn_885DCE58(void *p, u32 size, u32 idx, u32 flag);
extern char lbl_880B9788[], lbl_880B4598[], lbl_880B4540[], lbl_880B97F0[];
extern u32 lbl_88C42CC8[];

typedef void (*Ts4ReportCb)(void *dst, const void *str, u32 a, u32 size, u32 idx, u32 flag);

/* Indexed boolean property check that also records the element index in the output slot. */
#define TS4_BOOL_INDEXED_SLOT_REPORT(NAME, CODE, CMP, SZO, DESC, OFF, LINE) \
    u32 NAME(void *obj, u32 idx, void *out, Ts4ReportCb cb, void *dst) \
    { \
        u32 r; \
        if (obj == 0) fn_885DC838(obj, lbl_880B4540, lbl_880B4598, lbl_880B9788, LINE); \
        if (ts4_read_indexed_u32_property_885DCDA8(obj, CODE, idx) == CMP) { \
            if (out) fn_885DCE58(out, SZO, idx, 1); \
            if (cb && dst) cb(dst, lbl_880B97F0, lbl_88C42CC8[OFF / 4], DESC, idx, 1); \
            r = 1; \
        } else { \
            if (out) fn_885DCE58(out, SZO, idx, 0); \
            if (cb && dst) cb(dst, lbl_880B97F0, lbl_88C42CC8[OFF / 4], DESC, idx, 0); \
            r = 0; \
        } \
        return r; \
    }

TS4_BOOL_INDEXED_SLOT_REPORT(ts4_report_bool_indexed_slot_885DE6C0, 14, 1, 19, 33, 132, 1676) /* 0x885DE6C0 */
TS4_BOOL_INDEXED_SLOT_REPORT(ts4_report_bool_indexed_slot_885DE7E8, 14, 2, 20, 34, 136, 1726) /* 0x885DE7E8 */
TS4_BOOL_INDEXED_SLOT_REPORT(ts4_report_bool_indexed_slot_885DE910, 14, 3, 21, 35, 140, 1777) /* 0x885DE910 */
