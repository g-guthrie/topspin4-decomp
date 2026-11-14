/* Swing_DLL.xex 0x885E0350-0x885E0EB4, executable version 0.0.0.3. */
typedef unsigned int u32;

extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern float ts4_read_indexed_float_property_885DD148(void *obj, u32 code, u32 idx);
extern void fn_885DD4C8(float v, char *buf);
extern char lbl_880B9788[], lbl_880B4598[], lbl_880B4540[], lbl_880B9820[];
extern u32 lbl_88C42CC8[];

typedef void (*Ts4ReportCb)(void *dst, const void *str, u32 a, u32 size, u32 idx, void *arg);

/* Indexed float property read: asserts the object, reads element IDX of the property CODE into *out,
   and when a callback is given formats it and reports it. */
#define TS4_FLOAT_INDEXED_REPORT(NAME, CODE, SZ, OFF, LINE) \
    u32 NAME(void *obj, u32 idx, float *out, Ts4ReportCb cb, void *dst) \
    { \
        char buf[0x20]; \
        float v; \
        if (obj == 0) fn_885DC838(obj, lbl_880B4540, lbl_880B4598, lbl_880B9788, LINE); \
        v = ts4_read_indexed_float_property_885DD148(obj, CODE, idx); \
        *out = v; \
        if (cb && dst) { \
            fn_885DD4C8(v, buf); \
            cb(dst, lbl_880B9820, lbl_88C42CC8[OFF / 4], SZ, idx, buf); \
        } \
        return 1; \
    }

TS4_FLOAT_INDEXED_REPORT(ts4_report_float_indexed_885E0350, 16, 11, 44, 3620) /* 0x885E0350 */
TS4_FLOAT_INDEXED_REPORT(ts4_report_float_indexed_885E0400, 17, 72, 288, 3654) /* 0x885E0400 */
TS4_FLOAT_INDEXED_REPORT(ts4_report_float_indexed_885E04B0, 18, 73, 292, 3688) /* 0x885E04B0 */
TS4_FLOAT_INDEXED_REPORT(ts4_report_float_indexed_885E0560, 19, 74, 296, 3721) /* 0x885E0560 */
TS4_FLOAT_INDEXED_REPORT(ts4_report_float_indexed_885E0968, 86, 51, 204, 4098) /* 0x885E0968 */
TS4_FLOAT_INDEXED_REPORT(ts4_report_float_indexed_885E0D58, 26, 65, 260, 4293) /* 0x885E0D58 */
TS4_FLOAT_INDEXED_REPORT(ts4_report_float_indexed_885E0E08, 25, 66, 264, 4327) /* 0x885E0E08 */
