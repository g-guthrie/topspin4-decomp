/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l10_varargs_forward_833E18F0.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifdef _MSC_VER
typedef char *ts4_va_list;
#define TS4_VA_START(ap, v) __va_start(&ap, v)
#else
#include <stdarg.h>
typedef va_list ts4_va_list;
#define TS4_VA_START(ap, v) va_start(ap, v)
#endif
typedef long ts4_word;

ts4_word fn_8819C000();
ts4_word fn_8819C918();
ts4_word ts4_tailcall_fn_885654E8_885655D0();
ts4_word ts4_tailcall_fn_88565410_885654D8();
ts4_word fn_88566460();
ts4_word fn_88570D60();
ts4_word fn_8856A218();
ts4_word fn_88572018();
ts4_word fn_885DD340();
ts4_word ts4_if_call_seq_fn_8856A658_88606208();
ts4_word lua3_luaO_pushvfstring_888188F8();
ts4_word ts4_call_worker_clamp_885694D0();

/* Swing_DLL.xex 0x8819BEF0 */
ts4_word ts4_forward_varargs_8819BEF0(ts4_word p0, ts4_word p1, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p1);
    return fn_8819C000(p0, p1, ap);
}

/* Swing_DLL.xex 0x8819C8D0 */
ts4_word ts4_forward_varargs_8819C8D0(ts4_word p0, ts4_word p1, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p1);
    return fn_8819C918(p0, p1, ap);
}

/* Swing_DLL.xex 0x88421058 */
ts4_word ts4_forward_varargs_88421058(ts4_word p0, ts4_word p1, ts4_word p2, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p2);
    return ts4_tailcall_fn_885654E8_885655D0(p0, p1, p2, ap);
}

/* Swing_DLL.xex 0x884210A0 */
ts4_word ts4_forward_varargs_884210A0(ts4_word p0, ts4_word p1, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p1);
    return ts4_tailcall_fn_88565410_885654D8(p0, p1, ap);
}

/* Swing_DLL.xex 0x88566620 */
ts4_word ts4_forward_varargs_88566620(ts4_word p0, ts4_word p1, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p1);
    return fn_88566460((ts4_word)fn_88570D60, p0, p1, 0, ap);
}

/* Swing_DLL.xex 0x8856A2E0 */
ts4_word ts4_forward_varargs_8856A2E0(ts4_word p0, ts4_word p1, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p1);
    return fn_8856A218((ts4_word)fn_88570D60, p0, p1, 0, ap);
}

/* Swing_DLL.xex 0x8856A340 */
ts4_word ts4_forward_varargs_8856A340(ts4_word p0, ts4_word p1, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p1);
    return fn_8856A218((ts4_word)fn_88572018, p0, p1, 0, ap);
}

/* Swing_DLL.xex 0x885DD3F0 */
ts4_word ts4_forward_varargs_885DD3F0(ts4_word p0, ts4_word p1, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p1);
    return fn_885DD340(p0, p1, ap);
}

/* Swing_DLL.xex 0x88606270 */
ts4_word ts4_forward_varargs_88606270(ts4_word p0, ts4_word p1, ts4_word p2, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p2);
    return ts4_if_call_seq_fn_8856A658_88606208(p0, p1, p2, ap);
}

/* Swing_DLL.xex 0x88818C40 */
ts4_word ts4_forward_varargs_88818C40(ts4_word p0, ts4_word p1, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p1);
    return lua3_luaO_pushvfstring_888188F8(p0, p1, ap);
}

/* Swing_DLL.xex 0x88864C60 */
ts4_word ts4_forward_varargs_88864C60(ts4_word p0, ts4_word p1, ts4_word p2, ...)
{
    ts4_va_list ap;
    TS4_VA_START(ap, p2);
    return ts4_call_worker_clamp_885694D0(p0, p1, p2, 0, ap);
}

