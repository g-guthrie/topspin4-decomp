/* Loader_DLL.xex 0x833E18F0-0x8340EA18, executable version 0.0.0.3.
   Variadic wrappers (printf-style): capture the caller's argument list and
   forward it, together with the fixed arguments, to a v-style callee. */
#ifdef _MSC_VER
typedef char *ts4l_va_list;
#define TS4L_VA_START(ap, v) __va_start(&ap, v)
#else
#include <stdarg.h>
typedef va_list ts4l_va_list;
#define TS4L_VA_START(ap, v) va_start(ap, v)
#endif
typedef long ts4l_word;

ts4l_word fn_833E2068();
ts4l_word fn_833E2510();
ts4l_word fn_833E25B8();
ts4l_word fn_833E2760();
ts4l_word fn_833E43D8();
ts4l_word fn_833E5B90();
ts4l_word fn_833E5C38();
ts4l_word fn_833E5DE0();
ts4l_word fn_833EA3A0();
ts4l_word fn_833EA3B8();
ts4l_word fn_833EA3D0();
ts4l_word fn_833EA3E8();
ts4l_word fn_833EB108();
ts4l_word fn_833EB270();
ts4l_word fn_833EB288();
ts4l_word fn_833EB2A0();
ts4l_word fn_833EB2B8();
ts4l_word fn_833EB480();
ts4l_word fn_833EC838();
ts4l_word fn_833F2A70();
ts4l_word fn_833F3C18();
ts4l_word fn_833F7790();
ts4l_word fn_833F77A8();
ts4l_word fn_833F77C0();
ts4l_word fn_833F7F10();
ts4l_word fn_833F7F30();
ts4l_word fn_833F7F50();
ts4l_word fn_8340E5B8();
ts4l_word ts4_tailcall_fn_833EA200_833EA308();

ts4l_word ts4l_forward_varargs_833E18F0(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return ts4_tailcall_fn_833EA200_833EA308(p0, p1, p2, ap);
}

ts4l_word ts4l_forward_varargs_833E1938(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833E5B90(p0, p1, p2, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E1980(ts4l_word p0, ts4l_word p1, ts4l_word p2, ts4l_word p3, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p3);
    return fn_833E5C38(p0, p1, p2, p3, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E19C8(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833E5DE0(p0, p1, p2, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E1AD0(ts4l_word p0, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p0);
    return fn_833EA3A0(p0, ap);
}

ts4l_word ts4l_forward_varargs_833E1B20(ts4l_word p0, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p0);
    return fn_833EA3D0(p0, ap);
}

ts4l_word ts4l_forward_varargs_833E1B70(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833EA3B8(p0, p1, ap);
}

ts4l_word ts4l_forward_varargs_833E1BB8(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833EA3E8(p0, p1, ap);
}

ts4l_word ts4l_forward_varargs_833E1D58(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833EB108(p0, p1, p2, ap);
}

ts4l_word ts4l_forward_varargs_833E1DA0(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833E2510(p0, p1, p2, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E1E28(ts4l_word p0, ts4l_word p1, ts4l_word p2, ts4l_word p3, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p3);
    return fn_833E25B8(p0, p1, p2, p3, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E1EB0(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833E2760(p0, p1, p2, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E1F38(ts4l_word p0, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p0);
    return fn_833EB270(p0, ap);
}

ts4l_word ts4l_forward_varargs_833E1F88(ts4l_word p0, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p0);
    return fn_833EB2A0(p0, ap);
}

ts4l_word ts4l_forward_varargs_833E1FD8(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833EB288(p0, p1, ap);
}

ts4l_word ts4l_forward_varargs_833E2020(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833EB2B8(p0, p1, ap);
}

ts4l_word ts4l_forward_varargs_833E2130(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833E2068((ts4l_word)fn_833EB480, p0, p1, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E2190(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833E2068((ts4l_word)fn_833EB480, p0, p1, p2, ap);
}

ts4l_word ts4l_forward_varargs_833E21E8(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833E2068((ts4l_word)fn_833EC838, p0, p1, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E2248(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833E2068((ts4l_word)fn_833EC838, p0, p1, p2, ap);
}

ts4l_word ts4l_forward_varargs_833E4498(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833E43D8((ts4l_word)fn_833F2A70, p0, p1, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E44F8(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833E43D8((ts4l_word)fn_833F2A70, p0, p1, p2, ap);
}

ts4l_word ts4l_forward_varargs_833E4550(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833E43D8((ts4l_word)fn_833F3C18, p0, p1, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E45B0(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833E43D8((ts4l_word)fn_833F3C18, p0, p1, p2, ap);
}

ts4l_word ts4l_forward_varargs_833E6FE0(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833F7790(p0, p1, ap);
}

ts4l_word ts4l_forward_varargs_833E7028(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833F77A8(p0, p1, ap);
}

ts4l_word ts4l_forward_varargs_833E7070(ts4l_word p0, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p0);
    return fn_833F77A8(p0, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E70C0(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833F77C0(p0, p1, ap);
}

ts4l_word ts4l_forward_varargs_833E7108(ts4l_word p0, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p0);
    return fn_833F77C0(p0, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E77C0(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833F7F10(p0, p1, p2, ap);
}

ts4l_word ts4l_forward_varargs_833E7808(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833F7F30(p0, p1, p2, ap);
}

ts4l_word ts4l_forward_varargs_833E7850(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833F7F30(p0, p1, 0, ap);
}

ts4l_word ts4l_forward_varargs_833E78A0(ts4l_word p0, ts4l_word p1, ts4l_word p2, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p2);
    return fn_833F7F50(p0, p1, p2, ap);
}

ts4l_word ts4l_forward_varargs_833E78E8(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_833F7F50(p0, p1, 0, ap);
}

ts4l_word ts4l_forward_varargs_8340E9C0(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_8340E5B8(25, 0, p0, p1, ap);
}

ts4l_word ts4l_forward_varargs_8340EA18(ts4l_word p0, ts4l_word p1, ...)
{
    ts4l_va_list ap;
    TS4L_VA_START(ap, p1);
    return fn_8340E5B8(25, 0, p0, p1, ap);
}
