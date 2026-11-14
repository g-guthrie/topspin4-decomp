/* Derived from trio 1.10 (trio.c v1.75, trionan.c v1.26), Copyright (C) 1998 Bjorn Reese and Daniel Stenberg.
 * Permission to use, copy, modify, and distribute this software for any purpose with or without fee is hereby
 * granted, provided that the above copyright notice and this permission notice appear in all copies.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT
 * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE AUTHORS AND
 * CONTRIBUTORS ACCEPT NO RESPONSIBILITY IN ANY CONCEIVABLE MANNER.
 * Upstream: https://sourceforge.net/projects/ctrio/ (trio-1.10.tar.gz). See THIRD_PARTY_NOTICES.md.
 * Altered to match Swing_DLL.xex: printf side only (no scanf, no user-defined specifiers, no argarray),
 * TRIO_EXTENSION off; a second copy of the formatter is built for wchar_t. */
#ifndef LIB4_TRIO_H
#define LIB4_TRIO_H

#ifdef _MSC_VER
typedef char *va_list;
void __cdecl __va_start(va_list *ap, ...);
#define va_start(ap, v) (__va_start(&(ap), (v)))
#define va_end(ap) ((ap) = (va_list)0)
#define LIB4_NOINLINE __declspec(noinline)
void *__cdecl memset(void *dst, int c, unsigned int n);
unsigned int __cdecl strlen(const char *s);
#pragma intrinsic(memset, strlen)
#else
/* Host syntax check only: model va_list as the target's char pointer. */
typedef char *va_list;
#define va_start(ap, v) ((ap) = (va_list)&(v))
#define va_end(ap) ((ap) = (va_list)0)
#include <string.h>
#define LIB4_NOINLINE
#define __int64 long long
#endif
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef unsigned int u32;
typedef __int64 trio_intmax_t;
typedef unsigned __int64 trio_uintmax_t;

/* Every vararg occupies an 8-byte aligned 8-byte slot (Xbox 360 ABI). */
#define LIB4_VA_NEXT(ap) ((ap) = (va_list)((((unsigned long)(ap) + 7) & ~7ul) + 8))
#define LIB4_VA_INT(ap) (*(int *)(LIB4_VA_NEXT(ap) - 4))
#define LIB4_VA_PTR(ap) (*(void **)(LIB4_VA_NEXT(ap) - 4))
#define LIB4_VA_I64(ap) (*(__int64 *)(LIB4_VA_NEXT(ap) - 8))
#define LIB4_VA_DBL(ap) (*(double *)(LIB4_VA_NEXT(ap) - 8))

/* trio_class_t (0x20 bytes) */
typedef struct _trio_class_t {
    void (*OutStream)(struct _trio_class_t *self, int output);
    void (*InStream)(struct _trio_class_t *self, int *input);
    void *location;
    int current;
    int processed;
    int committed;
    int max;
    int error;
} trio_class_t;

/* trio_parameter_t (0x28 bytes): user_name/user_data removed. */
typedef struct {
    int type;
    unsigned long flags;
    int width;
    int precision;
    int base;
    int varsize;
    int indexAfterSpecifier;
    int pad1c;
    union {
        char *string;
        unsigned short *wstring;
        void *pointer;
        union {
            trio_intmax_t as_signed;
            trio_uintmax_t as_unsigned;
        } number;
        double doubleNumber;
        double longdoubleNumber;
        int errorNumber;
    } data;
} trio_parameter_t;

#define MAX_PARAMETERS 64

struct lconv_lib4 {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
};

/* Constant pool and data. */
extern double g_ts4_script_constants[];
#define TRIO_ZERO (g_ts4_script_constants[11])
/* trionan.c rodata: internalEndianMagic, then the 8-byte masks and patterns. */
extern const unsigned char lbl_880CDC60[];
/* trio.c data: internalLocaleValues, internalDecimalPoint, and the block ending in internalGrouping[64]. */
extern struct lconv_lib4 *lbl_88D45988;
extern char lbl_88C46A9F;
#define internalLocaleValues lbl_88D45988
#define internalDecimalPoint lbl_88C46A9F
/* The compiler addressed this static block from internalGrouping (lbl_88C6A6A8); the other members lie before it. */
struct trio_locale_block {
    int decimalPointLength;     /* -0x1c */
    int thousandSeparatorLength; /* -0x18 */
    char decimalPointString[6]; /* -0x14 */
    char pad_e[2];
    char thousandSeparator[6];  /* -0xc */
    char pad_6[6];
};
extern struct trio_locale_block lbl_88C6A6A8[];
#define internalDecimalPointLength (lbl_88C6A6A8[-1].decimalPointLength)
#define internalThousandSeparatorLength (lbl_88C6A6A8[-1].thousandSeparatorLength)
#define internalDecimalPointString (lbl_88C6A6A8[-1].decimalPointString)
#define internalThousandSeparator (lbl_88C6A6A8[-1].thousandSeparator)
#define internalGrouping ((char *)lbl_88C6A6A8)

/* CRT */
struct lconv_lib4 *ts4_get_u32_lbl_88C311F0_88567FB8(void); /* localeconv */
extern char *ts4_copy_bytes(char *dst, const char *src, unsigned int n); /* strncpy */
long ts4_tailcall_fn_88564828_88564B00(const char *s, char **end, int base); /* strtol */
double ts4_call_seq_fn_88563F20_885640B0(double x); /* log10 */
double floor(double x);
#ifdef _MSC_VER
double __cdecl fabs(double x);
#pragma intrinsic(fabs)
#else
double fabs(double x);
#endif
double fn_88564D68(double x, double y); /* fmod */
double fn_88564D28(double x); /* ceil */
double fn_88563A38(double x, double y); /* pow */
int fn_88567BA0(const char *s, unsigned int n); /* mblen */
int *ts4_if_call_seq_fn_8856CD88_88567ED8(void); /* _errno */

int ts4_fn_885E6048(void); /* ___mb_cur_max_func */
const unsigned short *ts4_get_u32_lbl_88C311F4_88567FC8(void); /* __pctype_func */
int ts4_addr_lbl_88C317A0_88568010(int c, int mask); /* _isctype */
#define trio_isprint(c) (ts4_fn_885E6048() > 1 ? ts4_addr_lbl_88C317A0_88568010((c), 0x157) \
                                             : (ts4_get_u32_lbl_88C311F4_88567FC8()[(c)] & 0x157))

/* trio.c flags */
#define FLAGS_STICKY 0x1
#define FLAGS_SPACE 0x2
#define FLAGS_SHOWSIGN 0x4
#define FLAGS_LEFTADJUST 0x8
#define FLAGS_ALTERNATIVE 0x10
#define FLAGS_SHORT 0x20
#define FLAGS_SHORTSHORT 0x40
#define FLAGS_LONG 0x80
#define FLAGS_QUAD 0x100
#define FLAGS_LONGDOUBLE 0x200
#define FLAGS_SIZE_T 0x400
#define FLAGS_PTRDIFF_T 0x800
#define FLAGS_INTMAX_T 0x1000
#define FLAGS_NILPADDING 0x2000
#define FLAGS_UNSIGNED 0x4000
#define FLAGS_UPPER 0x8000
#define FLAGS_WIDTH 0x10000
#define FLAGS_WIDTH_PARAMETER 0x20000
#define FLAGS_PRECISION 0x40000
#define FLAGS_PRECISION_PARAMETER 0x80000
#define FLAGS_BASE 0x100000
#define FLAGS_BASE_PARAMETER 0x200000
#define FLAGS_FLOAT_E 0x400000
#define FLAGS_FLOAT_G 0x800000
#define FLAGS_QUOTE 0x1000000
#define FLAGS_WIDECHAR 0x2000000
#define FLAGS_ALLOC 0x4000000
#define FLAGS_IGNORE 0x8000000
#define FLAGS_IGNORE_PARAMETER 0x10000000
#define FLAGS_VARSIZE_PARAMETER 0x20000000
#define FLAGS_FIXED_SIZE 0x40000000
#define FLAGS_ROUNDING FLAGS_INTMAX_T
#define FLAGS_ALL_VARSIZES (FLAGS_LONG | FLAGS_QUAD | FLAGS_INTMAX_T | FLAGS_PTRDIFF_T | FLAGS_SIZE_T)
#define NO_WIDTH 0
#define NO_PRECISION (-1)
#define NO_BASE (-1)
#define BASE_BINARY 2
#define BASE_OCTAL 8
#define BASE_DECIMAL 10
#define BASE_HEX 16
#define FORMAT_UNKNOWN 0
#define FORMAT_INT 1
#define FORMAT_DOUBLE 2
#define FORMAT_CHAR 3
#define FORMAT_STRING 4
#define FORMAT_POINTER 5
#define FORMAT_COUNT 6
#define FORMAT_PARAMETER 7
#define FORMAT_GROUP 8
#define FORMAT_ERRNO 9
#define CHAR_IDENTIFIER '%'
#define CHAR_BACKSLASH '\\'
#define CHAR_QUOTE '\"'
#define CHAR_ADJUST ' '
#define POINTER_WIDTH 10

/* trionan */
int ts4_map_input_flag_8819F760(double number, int *is_negative); /* trio_fpclassify_and_signbit */
int ts4_check_kind_8819F700(double number); /* trio_isinf */
#define TRIO_FP_INFINITE 0
#define TRIO_FP_NAN 1
/* triomath helpers already reconstructed elsewhere */
double ts4_pow_small_8819CCE8(int base, int exponent); /* TrioPower */
double ts4_radix_constant_8819CF40(int base); /* TrioLogarithmBase */
double fn_8819F5F0(void); /* trio_pinf */
double fn_8819F650(void); /* trio_ninf */
double fn_8819F6A0(void); /* trio_nan */

#endif
