/* Swing_DLL.xex 0x885DDBE8-0x885DDE08, executable version 0.0.0.3. */
typedef unsigned int u32;

extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern u32 ts4_if_call_seq_u32_off44_885DCD38(void *obj, u32 code);
extern void fn_885DCE58(void *p, u32 size, u32 z, u32 flag);
extern char lbl_880B9788[], lbl_880B4598[], lbl_880B4540[], lbl_880B9778[];
extern u32 lbl_88C42CC8[];

typedef void (*Ts4ReportCb)(void *dst, const void *str, u32 a, u32 size, u32 flag);

/* Property check: asserts the object, tests whether the property selected by CODE is non-zero,
   reports the boolean through the output slot and callback. */
#define TS4_NONZERO_PROPERTY_REPORT(NAME, CODE, SZO, DESC, OFF, LINE) \
    u32 NAME(void *obj, u32 unused, void *out, Ts4ReportCb cb, void *dst) \
    { \
        u32 r; \
        (void)unused; \
        if (obj == 0) fn_885DC838(obj, lbl_880B4540, lbl_880B4598, lbl_880B9788, LINE); \
        if (ts4_if_call_seq_u32_off44_885DCD38(obj, CODE) != 0) { \
            if (out) fn_885DCE58(out, SZO, 0, 1); \
            if (cb && dst) cb(dst, lbl_880B9778, lbl_88C42CC8[OFF / 4], DESC, 1); \
            r = 1; \
        } else { \
            if (out) fn_885DCE58(out, SZO, 0, 0); \
            if (cb && dst) cb(dst, lbl_880B9778, lbl_88C42CC8[OFF / 4], DESC, 0); \
            r = 0; \
        } \
        return r; \
    }

TS4_NONZERO_PROPERTY_REPORT(ts4_report_nonzero_property_885DDBE8, 934, 10, 16, 64, 1154) /* 0x885DDBE8 */
TS4_NONZERO_PROPERTY_REPORT(ts4_report_nonzero_property_885DDCF8, 935, 11, 17, 68, 1208) /* 0x885DDCF8 */
