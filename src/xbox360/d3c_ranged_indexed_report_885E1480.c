/* Swing_DLL.xex 0x885E1480-0x885E1930, executable version 0.0.0.3. */
typedef unsigned int u32;

extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern u32 ts4_read_indexed_u32_property_885DCDA8(void *obj, u32 code, u32 idx);
extern u32 ts4_if_call_seq_u32_off44_885DCD38(void *obj, u32 code);
extern void fn_885DCE58(void *p, u32 size, u32 z, u32 flag);
extern char lbl_880B9788[], lbl_880B4598[], lbl_880B4540[], lbl_880B97F0[], lbl_880B9964[], lbl_880B9958[];
extern u32 lbl_88C42CC8[];

typedef void (*Ts4ReportCb)(void *dst, const void *str, u32 a, u32 size, u32 idx, u32 flag);

/* Range-checked indexed property check: element IDX (0..15) of property 0xc must equal 1 while
   property 0x87 equals K; the result is reported through the output slot and callback. */
#define TS4_RANGED_INDEXED_REPORT(NAME, K, SZ, OFF, LINE) \
    u32 NAME(void *obj, int idx, void *out, Ts4ReportCb cb, void *dst) \
    { \
        u32 k; \
        u32 r; \
        if (obj == 0) fn_885DC838(0, lbl_880B4540, lbl_880B4598, lbl_880B9788, LINE); \
        if (idx >= 0x10) fn_885DC838(0, lbl_880B4540, lbl_880B9964, lbl_880B9788, LINE + 1); \
        if (idx < 0) fn_885DC838(0, lbl_880B4540, lbl_880B9958, lbl_880B9788, LINE + 2); \
        k = ts4_if_call_seq_u32_off44_885DCD38(obj, 0x87); \
        if (ts4_read_indexed_u32_property_885DCDA8(obj, 0xc, idx) == 1 && k == K) { \
            if (out) fn_885DCE58(out, SZ, idx, 1); \
            if (cb && dst) cb(dst, lbl_880B97F0, lbl_88C42CC8[OFF / 4], SZ, idx, 1); \
            r = 1; \
        } else { \
            if (out) fn_885DCE58(out, SZ, idx, 0); \
            if (cb && dst) cb(dst, lbl_880B97F0, lbl_88C42CC8[OFF / 4], SZ, idx, 0); \
            r = 0; \
        } \
        return r; \
    }

TS4_RANGED_INDEXED_REPORT(ts4_report_ranged_indexed_885E1480, 0, 1, 4, 561) /* 0x885E1480 */
TS4_RANGED_INDEXED_REPORT(ts4_report_ranged_indexed_885E1610, 1, 2, 8, 619) /* 0x885E1610 */
TS4_RANGED_INDEXED_REPORT(ts4_report_ranged_indexed_885E17A0, 2, 3, 12, 677) /* 0x885E17A0 */
