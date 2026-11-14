/* Swing_DLL.xex 0x885DFF10-0x885E0CB8, executable version 0.0.0.3. */
typedef unsigned int u32;

extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern float fn_885DD0D8(void *obj, u32 code);
extern void fn_885DD4C8(float v, char *buf);
extern char lbl_880B9788[], lbl_880B4598[], lbl_880B4540[], lbl_880B9804[];
extern u32 lbl_88C42CC8[];

typedef void (*Ts4ReportCb)(void *dst, const void *str, u32 a, u32 size, void *arg);

/* Float property read: asserts the object, reads the value selected by CODE into *out,
   and when a callback is given formats it and reports it. */
#define TS4_FLOAT_PROPERTY_REPORT(NAME, CODE, SZ, OFF, LINE) \
    u32 NAME(void *obj, u32 unused, float *out, Ts4ReportCb cb, void *dst) \
    { \
        char buf[0x20]; \
        float v; \
        (void)unused; \
        if (obj == 0) fn_885DC838(obj, lbl_880B4540, lbl_880B4598, lbl_880B9788, LINE); \
        v = fn_885DD0D8(obj, CODE); \
        *out = v; \
        if (cb && dst) { \
            fn_885DD4C8(v, buf); \
            cb(dst, lbl_880B9804, lbl_88C42CC8[OFF / 4], SZ, buf); \
        } \
        return 1; \
    }

TS4_FLOAT_PROPERTY_REPORT(ts4_report_float_property_885DFF10, 130, 103, 412, 3379) /* 0x885DFF10 */
TS4_FLOAT_PROPERTY_REPORT(ts4_report_float_property_885DFFB0, 129, 104, 416, 3411) /* 0x885DFFB0 */
TS4_FLOAT_PROPERTY_REPORT(ts4_report_float_property_885E0170, 1000, 9, 36, 3516) /* 0x885E0170 */
TS4_FLOAT_PROPERTY_REPORT(ts4_report_float_property_885E0210, 1001, 69, 276, 3546) /* 0x885E0210 */
TS4_FLOAT_PROPERTY_REPORT(ts4_report_float_property_885E02B0, 1002, 70, 280, 3577) /* 0x885E02B0 */
TS4_FLOAT_PROPERTY_REPORT(ts4_report_float_property_885E0AD8, 166, 24, 96, 4163) /* 0x885E0AD8 */
TS4_FLOAT_PROPERTY_REPORT(ts4_report_float_property_885E0B78, 167, 75, 300, 4195) /* 0x885E0B78 */
TS4_FLOAT_PROPERTY_REPORT(ts4_report_float_property_885E0C18, 168, 25, 100, 4225) /* 0x885E0C18 */
