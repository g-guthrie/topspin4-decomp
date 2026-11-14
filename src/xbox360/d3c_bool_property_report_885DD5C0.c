/* Swing_DLL.xex 0x885DD5C0-0x885DF99C, executable version 0.0.0.3. */
typedef unsigned int u32;

extern void fn_885DC838(void *obj, const void *a, const void *b, const void *c, u32 line);
extern u32 ts4_if_call_seq_u32_off44_885DCD38(void *obj, u32 code);
extern void fn_885DCE58(void *p, u32 size, u32 z, u32 flag);
extern char lbl_880B9788[], lbl_880B4598[], lbl_880B4540[], lbl_880B9778[];
extern u32 lbl_88C42CC8[];

typedef void (*Ts4ReportCb)(void *dst, const void *str, u32 a, u32 size, u32 flag);

/* Property check: asserts the object exists, tests the property selected by CODE
   against the expected value CMP, reports the boolean through the output slot and callback. */
#define TS4_BOOL_PROPERTY_REPORT(NAME, CODE, CMP, SZ, DESC, OFF, LINE) \
    u32 NAME(void *obj, u32 unused, void *out, Ts4ReportCb cb, void *dst) \
    { \
        u32 r; \
        (void)unused; \
        if (obj == 0) fn_885DC838(obj, lbl_880B4540, lbl_880B4598, lbl_880B9788, LINE); \
        if (ts4_if_call_seq_u32_off44_885DCD38(obj, CODE) == CMP) { \
            if (out) fn_885DCE58(out, SZ, 0, 1); \
            if (cb && dst) cb(dst, lbl_880B9778, lbl_88C42CC8[OFF / 4], DESC, 1); \
            r = 1; \
        } else { \
            if (out) fn_885DCE58(out, SZ, 0, 0); \
            if (cb && dst) cb(dst, lbl_880B9778, lbl_88C42CC8[OFF / 4], DESC, 0); \
            r = 0; \
        } \
        return r; \
    }

TS4_BOOL_PROPERTY_REPORT(ts4_report_bool_property_885DD5C0, 127, 1, 4, 4, 16, 733) /* 0x885DD5C0 */
TS4_BOOL_PROPERTY_REPORT(ts4_report_bool_property_885DDE08, 170, 2, 12, 18, 72, 1262) /* 0x885DDE08 */
TS4_BOOL_PROPERTY_REPORT(ts4_report_bool_property_885DE030, 170, 1, 14, 20, 80, 1367) /* 0x885DE030 */
TS4_BOOL_PROPERTY_REPORT(ts4_report_bool_property_885DE148, 171, 1, 40, 92, 368, 1421) /* 0x885DE148 */
TS4_BOOL_PROPERTY_REPORT(ts4_report_bool_property_885DE260, 165, 3, 15, 21, 84, 1471) /* 0x885DE260 */
TS4_BOOL_PROPERTY_REPORT(ts4_report_bool_property_885DE378, 165, 1, 16, 22, 88, 1521) /* 0x885DE378 */
TS4_BOOL_PROPERTY_REPORT(ts4_report_bool_property_885DE490, 165, 2, 17, 23, 92, 1571) /* 0x885DE490 */
TS4_BOOL_PROPERTY_REPORT(ts4_report_bool_property_885DE5A8, 615, 1, 18, 32, 128, 1622) /* 0x885DE5A8 */
TS4_BOOL_PROPERTY_REPORT(ts4_report_bool_property_885DEA38, 582, 1, 23, 38, 152, 1828) /* 0x885DEA38 */
TS4_BOOL_PROPERTY_REPORT(ts4_report_bool_property_885DF888, 926, 1, 22, 36, 144, 2527) /* 0x885DF888 */
