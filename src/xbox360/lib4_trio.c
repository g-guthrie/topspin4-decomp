/* trio 1.10 printf core (narrow char copy) as linked into Swing_DLL.xex. See lib4_trio.h for license. */
#include "lib4_trio.h"

#define NO_POSITION (-1)
#define QUALIFIER_POSITION '$'
#define NIL '\0'

/* trio_copy_max: strncpy(target, source, max - 1) and terminate. */
#ifdef _MSC_VER
static __forceinline
#else
static inline
#endif
int trio_copy_max(char *target, unsigned int max, const char *source)
{
    ts4_copy_bytes(target, source, max - 1);
    *(volatile char *)&target[max - 1] = (char)0;
    return 1;
}

#define trio_length(string) strlen(string)

/* 0x8819CA18 */
int lib4_trio_TrioIsQualifier_8819CA18(const char character)
{
    switch (character) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case '+':
    case '-':
    case ' ':
    case '#':
    case '.':
    case '*':
    case 'h':
    case 'l':
    case 'L':
    case 'q':
    case 'I':
    case 'Z':
    case 'w':
    case 'j':
    case 'z':
    case 't':
    case '^':
        return 1;
    default:
        return 0;
    }
}

/* 0x8819CB30 TrioSetLocale. The original statics were never aliased by the lconv strings; the loads are
 * kept in locals here to give the same code. */
void fn_8819CB30(void)
{
    const char *string;

    internalLocaleValues = ts4_get_u32_lbl_88C311F0_88567FB8();
    if (internalLocaleValues) {
        string = internalLocaleValues->decimal_point;
        if ((string) && (string[0] != NIL)) {
            char first = string[0];
            internalDecimalPointLength = trio_length(string);
            if (internalDecimalPointLength == 1) {
                internalDecimalPoint = first;
            } else {
                internalDecimalPoint = NIL;
                trio_copy_max(internalDecimalPointString, 6, string);
            }
        }
        string = internalLocaleValues->thousands_sep;
        if ((string) && (string[0] != NIL)) {
            trio_copy_max(internalThousandSeparator, 6, string);
            internalThousandSeparatorLength = trio_length(internalThousandSeparator);
        }
        string = internalLocaleValues->grouping;
        if ((string) && (string[0] != NIL)) {
            trio_copy_max(internalGrouping, 64, string);
        }
    }
}

/* 0x8819CC70 */
int lib4_trio_TrioGetPosition_8819CC70(const char *format, int *indexPointer)
{
    char *tmpformat;
    int number = 0;
    int index = *indexPointer;

    number = (int)ts4_tailcall_fn_88564828_88564B00(&format[index], &tmpformat, 10);
    index = (int)(tmpformat - format);
    if ((number != 0) && (QUALIFIER_POSITION == format[index++])) {
        *indexPointer = index;
        return number - 1;
    }
    return NO_POSITION;
}

/* 0x8819CEB0 */
double lib4_trio_TrioLogarithm_8819CEB0(double number, int base)
{
    double result;

    if (number <= TRIO_ZERO) {
        result = (number == TRIO_ZERO) ? fn_8819F650() : fn_8819F6A0();
    } else {
        if (base == 10)
            result = fn_885640B0(number);
        else
            result = fn_885640B0(number) / fn_885640B0((double)base);
    }
    return result;
}

/* trionan.c */
extern double lbl_88D45990;
extern double lbl_88D45998;
extern double lbl_88D459A0;

static double trio_make_double(const unsigned char *values)
{
    volatile double result;
    int i;

    const unsigned char *order = lbl_880CDC60 + 8;
    for (i = 0; i < (int)sizeof(double); i++) {
        ((volatile unsigned char *)&result)[*--order] = values[i];
    }
    return result;
}

/* 0x8819F5F0 trio_pinf */
double fn_8819F5F0(void)
{
    if (lbl_88D45990 == TRIO_ZERO) {
        lbl_88D45990 = trio_make_double(lbl_880CDC60 + 0x28);
    }
    return lbl_88D45990;
}

/* 0x8819F650 trio_ninf */
double fn_8819F650(void)
{
    if (lbl_88D45998 == TRIO_ZERO) {
        lbl_88D45998 = -fn_8819F5F0();
    }
    return lbl_88D45998;
}

/* 0x8819F6A0 trio_nan */
double fn_8819F6A0(void)
{
    if (lbl_88D459A0 == TRIO_ZERO) {
        lbl_88D459A0 = trio_make_double(lbl_880CDC60 + 0x30);
    }
    return lbl_88D459A0;
}

extern const char lbl_880DD7B0[]; /* "unknown" (trio_error without strerror) */
extern const char lbl_880CDCD0[]; /* internalNullString "(nil)" */
extern const char lbl_880CDCD8[]; /* internalDigitsLower, internalDigitsUpper at +0x28 */
#define internalDigitsLower lbl_880CDCD8
#define internalDigitsUpper (lbl_880CDCD8 + 0x28)
#define internalNullString lbl_880CDCD0

/* 0x8819DD48 */
void lib4_trio_TrioWriteNumber_8819DD48(trio_class_t *self, trio_uintmax_t number, unsigned long flags,
                                        int width, int precision, int base)
{
    int isNegative;
    int isNumberZero;
    int isPrecisionZero;
    int ignoreNumber;
    char buffer[64 * (1 + 5) + 1];
    char *bufferend;
    char *pointer;
    const char *digits;
    int i;
    int count;

    digits = (flags & FLAGS_UPPER) ? internalDigitsUpper : internalDigitsLower;
    if (base == NO_BASE)
        base = BASE_DECIMAL;

    isNumberZero = (number == 0);
    isPrecisionZero = (precision == 0);
    ignoreNumber = (isNumberZero && isPrecisionZero && !((flags & FLAGS_ALTERNATIVE) && (base == BASE_OCTAL)));

    if (flags & FLAGS_UNSIGNED) {
        isNegative = 0;
        flags &= ~FLAGS_SHOWSIGN;
    } else {
        isNegative = ((trio_intmax_t)number < 0);
        if (isNegative)
            number = -((trio_intmax_t)number);
    }

    if (flags & FLAGS_QUAD)
        number &= (unsigned __int64)-1;
    else if (flags & FLAGS_LONG)
        number &= (unsigned long)-1;
    else
        number &= (unsigned int)-1;

    /* Build number */
    pointer = bufferend = &buffer[sizeof(buffer) - 1];
    *pointer-- = NIL;
    for (i = 1; i < (int)sizeof(buffer); i++) {
        *pointer-- = digits[number % base];
        number /= base;
        if (number == 0)
            break;
    }

    if (!ignoreNumber) {
        width -= (bufferend - pointer) - 1;
    }

    if (NO_PRECISION != precision) {
        precision -= (bufferend - pointer) - 1;
        if (precision < 0)
            precision = 0;
        flags |= FLAGS_NILPADDING;
    }

    count = (!((flags & FLAGS_LEFTADJUST) || (precision == NO_PRECISION))) ? precision : 0;

    if (isNegative || (flags & FLAGS_SHOWSIGN) || (flags & FLAGS_SPACE))
        width--;
    if ((flags & FLAGS_ALTERNATIVE) && !isNumberZero) {
        switch (base) {
        case BASE_BINARY:
        case BASE_HEX:
            width -= 2;
            break;
        case BASE_OCTAL:
            if (!(flags & FLAGS_NILPADDING) || (count == 0))
                width--;
            break;
        default:
            break;
        }
    }

    if (!((flags & FLAGS_LEFTADJUST) || ((flags & FLAGS_NILPADDING) && (precision == NO_PRECISION)))) {
        while (width-- > count)
            self->OutStream(self, CHAR_ADJUST);
    }

    if (isNegative)
        self->OutStream(self, '-');
    else if (flags & FLAGS_SHOWSIGN)
        self->OutStream(self, '+');
    else if (flags & FLAGS_SPACE)
        self->OutStream(self, ' ');

    if ((flags & FLAGS_ALTERNATIVE) && !isNumberZero) {
        switch (base) {
        case BASE_BINARY:
            self->OutStream(self, '0');
            self->OutStream(self, (flags & FLAGS_UPPER) ? 'B' : 'b');
            break;
        case BASE_OCTAL:
            if (!(flags & FLAGS_NILPADDING) || (count == 0))
                self->OutStream(self, '0');
            break;
        case BASE_HEX:
            self->OutStream(self, '0');
            self->OutStream(self, (flags & FLAGS_UPPER) ? 'X' : 'x');
            break;
        default:
            break;
        }
    }

    if (flags & FLAGS_NILPADDING) {
        if (precision == NO_PRECISION)
            precision = width;
        while (precision-- > 0) {
            self->OutStream(self, '0');
            width--;
        }
    }

    if (!ignoreNumber) {
        while (*(++pointer)) {
            self->OutStream(self, *pointer);
        }
    }

    if (flags & FLAGS_LEFTADJUST) {
        while (width-- > 0)
            self->OutStream(self, CHAR_ADJUST);
    }
}

/* 0x8819E108: TrioWriteStringCharacter for FLAGS_ALTERNATIVE (the caller tests the flag). */
void lib4_trio_TrioWriteStringCharacterAlt_8819E108(trio_class_t *self, int ch)
{
    if (!trio_isprint(ch)) {
        self->OutStream(self, CHAR_BACKSLASH);
        switch (ch) {
        case '\007': self->OutStream(self, 'a'); break;
        case '\b': self->OutStream(self, 'b'); break;
        case '\f': self->OutStream(self, 'f'); break;
        case '\n': self->OutStream(self, 'n'); break;
        case '\r': self->OutStream(self, 'r'); break;
        case '\t': self->OutStream(self, 't'); break;
        case '\v': self->OutStream(self, 'v'); break;
        case '\\': self->OutStream(self, '\\'); break;
        default:
            self->OutStream(self, 'x');
            lib4_trio_TrioWriteNumber_8819DD48(self, (trio_uintmax_t)ch, FLAGS_UNSIGNED | FLAGS_NILPADDING, 2, 2,
                                               BASE_HEX);
            break;
        }
    } else if (ch == CHAR_BACKSLASH) {
        self->OutStream(self, CHAR_BACKSLASH);
        self->OutStream(self, CHAR_BACKSLASH);
    } else {
        self->OutStream(self, ch);
    }
}

/* 0x8819E278 */
void lib4_trio_TrioWriteString_8819E278(trio_class_t *self, const char *string, unsigned long flags, int width,
                                        int precision)
{
    int length;
    int ch;

    if (string == NULL) {
        string = internalNullString;
        length = 5;
        flags &= (~FLAGS_QUOTE);
        width = 0;
    } else {
        length = trio_length(string);
    }
    if ((NO_PRECISION != precision) && (precision < length)) {
        length = precision;
    }
    width -= length;

    if (flags & FLAGS_QUOTE)
        self->OutStream(self, CHAR_QUOTE);

    if (!(flags & FLAGS_LEFTADJUST)) {
        while (width-- > 0)
            self->OutStream(self, CHAR_ADJUST);
    }

    while (length-- > 0) {
        ch = (int)((unsigned char)(*string++));
        if (flags & FLAGS_ALTERNATIVE)
            lib4_trio_TrioWriteStringCharacterAlt_8819E108(self, ch);
        else
            self->OutStream(self, ch);
    }

    if (flags & FLAGS_LEFTADJUST) {
        while (width-- > 0)
            self->OutStream(self, CHAR_ADJUST);
    }
    if (flags & FLAGS_QUOTE)
        self->OutStream(self, CHAR_QUOTE);
}


/* In TrioWriteDouble the compiler addressed the locale block from internalDecimalPointString (lbl_88C6A694). */
struct trio_locale_lengths {
    int decimalPointLength;
    int thousandSeparatorLength;
};
extern struct trio_locale_lengths lbl_88C6A694[];
extern const char lbl_880DD7B8[]; /* "NAN" */
extern const char lbl_880DD7BC[]; /* "nan" */
extern const char lbl_880DD7C0[]; /* "-INF" */
extern const char lbl_880DD7C8[]; /* "-inf" */
extern const char lbl_880DD7D0[]; /* "INF" */
extern const char lbl_880DD7D4[]; /* "inf" */

#define KD(i) (g_ts4_script_constants[(i) / 8])

/* 0x8819E4F0 */
void lib4_trio_TrioWriteDouble_8819E4F0(trio_class_t *self, double number, unsigned long flags, int width,
                                        int precision, int base)
{
    double integerNumber;
    double fractionNumber;
    double workNumber;
    int integerDigits;
    int fractionDigits;
    int exponentDigits;
    int baseDigits;
    int integerThreshold;
    int fractionThreshold;
    int expectedWidth;
    int exponent = 0;
    unsigned int uExponent = 0;
    int exponentBase;
    double dblBase;
    double dblIntegerBase;
    double dblFractionBase;
    double integerAdjust;
    double fractionAdjust;
    int isNegative;
    int isExponentNegative = 0;
    int requireTwoDigitExponent;
    int isHex;
    const char *digits;
    int i;
    int index;
    int hasOnlyZeroes;
    int zeroes = 0;
    int trailingZeroes;
    int keepTrailingZeroes;
    int keepDecimalPoint;
    double epsilon;

    switch (ts4_map_input_flag_8819F760(number, &isNegative)) {
    case TRIO_FP_NAN:
        lib4_trio_TrioWriteString_8819E278(self, (flags & FLAGS_UPPER) ? lbl_880DD7B8 : lbl_880DD7BC, flags, width,
                                           precision);
        return;

    case TRIO_FP_INFINITE:
        if (isNegative) {
            lib4_trio_TrioWriteString_8819E278(self, (flags & FLAGS_UPPER) ? lbl_880DD7C0 : lbl_880DD7C8, flags,
                                               width, precision);
            return;
        } else {
            lib4_trio_TrioWriteString_8819E278(self, (flags & FLAGS_UPPER) ? lbl_880DD7D0 : lbl_880DD7D4, flags,
                                               width, precision);
            return;
        }

    default:
        break;
    }

    if (flags & FLAGS_LONGDOUBLE) {
        baseDigits = (base == 10) ? 15 : (int)floor(KD(0x580) / ts4_radix_constant_8819CF40(base));
        epsilon = KD(0x588);
    } else if (flags & FLAGS_SHORT) {
        baseDigits = (base == BASE_DECIMAL) ? 6 : (int)floor(KD(0x590) / ts4_radix_constant_8819CF40(base));
        epsilon = KD(0x598);
    } else {
        baseDigits = (base == BASE_DECIMAL) ? 15 : (int)floor(KD(0x580) / ts4_radix_constant_8819CF40(base));
        epsilon = KD(0x588);
    }

    digits = (flags & FLAGS_UPPER) ? internalDigitsUpper : internalDigitsLower;
    isHex = (base == BASE_HEX);
    if (base == NO_BASE)
        base = BASE_DECIMAL;
    dblBase = (double)base;
    keepTrailingZeroes = !((flags & FLAGS_ROUNDING) || ((flags & FLAGS_FLOAT_G) && !(flags & FLAGS_ALTERNATIVE)));

    if (flags & FLAGS_ROUNDING)
        precision = baseDigits;

    if (precision == NO_PRECISION) {
        if (isHex) {
            keepTrailingZeroes = 0;
            precision = 24;
        } else {
            precision = 6;
        }
    }

    if (isNegative)
        number = -number;

    if (isHex)
        flags |= FLAGS_FLOAT_E;

    if (flags & FLAGS_FLOAT_G) {
        if (precision == 0)
            precision = 1;

        if ((number < KD(0x5a0)) || (number > fn_88563A38(base, (double)precision))) {
            flags |= FLAGS_FLOAT_E;
        } else if (number < KD(0x78)) {
            workNumber = lib4_trio_TrioLogarithm_8819CEB0(number, base);
            workNumber = fabs(workNumber);
            if (workNumber - floor(workNumber) < KD(0x5a8))
                workNumber--;
            zeroes = (int)floor(workNumber);
        }
    }

    if (flags & FLAGS_FLOAT_E) {
        workNumber = lib4_trio_TrioLogarithm_8819CEB0(number, base);
        if (ts4_check_kind_8819F700(workNumber) == -1) {
            exponent = 0;
            if (flags & FLAGS_FLOAT_G)
                flags &= ~FLAGS_FLOAT_E;
        } else {
            exponent = (int)floor(workNumber);
            number /= fn_88563A38(dblBase, (double)exponent);
            isExponentNegative = (exponent < 0);
            uExponent = (isExponentNegative) ? -exponent : exponent;
            if (isHex)
                uExponent *= 4;
            flags &= ~FLAGS_QUOTE;
        }
    }

    integerNumber = floor(number);
    fractionNumber = number - integerNumber;

    integerDigits = (integerNumber > epsilon) ? 1 + (int)lib4_trio_TrioLogarithm_8819CEB0(integerNumber, base) : 1;
    fractionDigits = ((flags & FLAGS_FLOAT_G) && (zeroes == 0)) ? precision - integerDigits : zeroes + precision;

    dblFractionBase = ts4_pow_small_8819CCE8(base, fractionDigits);

    workNumber = number + KD(0x10) / dblFractionBase;
    if (floor(number) != floor(workNumber)) {
        if (flags & FLAGS_FLOAT_E) {
            exponent++;
            isExponentNegative = (exponent < 0);
            uExponent = (isExponentNegative) ? -exponent : exponent;
            if (isHex)
                uExponent *= 4;
            workNumber = (number + KD(0x10) / dblFractionBase) / dblBase;
            integerNumber = floor(workNumber);
            fractionNumber = workNumber - integerNumber;
        } else {
            integerNumber = floor(number + KD(0x10));
            fractionNumber = KD(0x58);
            integerDigits =
                (integerNumber > epsilon) ? 1 + (int)lib4_trio_TrioLogarithm_8819CEB0(integerNumber, base) : 1;
        }
    }

    integerAdjust = fractionAdjust = KD(0x10);
    if (flags & FLAGS_ROUNDING) {
        if (integerDigits > baseDigits) {
            integerThreshold = baseDigits;
            fractionDigits = 0;
            dblFractionBase = KD(0x78);
            fractionThreshold = 0;
            precision = 0;
            integerAdjust = ts4_pow_small_8819CCE8(base, integerDigits - integerThreshold - 1);
            fractionAdjust = KD(0x58);
        } else {
            integerThreshold = integerDigits;
            fractionThreshold = fractionDigits - integerThreshold;
            fractionAdjust = KD(0x78);
        }
    } else {
        integerThreshold = 0x7fffffff;
        fractionThreshold = 0x7fffffff;
    }

    fractionAdjust /= dblFractionBase;
    hasOnlyZeroes = (floor((fractionNumber + fractionAdjust) * dblFractionBase) < epsilon);
    keepDecimalPoint = ((flags & FLAGS_ALTERNATIVE) || !((precision == 0) || (!keepTrailingZeroes && hasOnlyZeroes)));
    if (flags & FLAGS_FLOAT_E) {
        exponentDigits = (uExponent == 0)
                             ? 1
                             : (int)fn_88564D28(lib4_trio_TrioLogarithm_8819CEB0((double)(uExponent + 1),
                                                                                 (int)((isHex) ? KD(0x88) : base)));
    } else
        exponentDigits = 0;
    requireTwoDigitExponent = ((base == BASE_DECIMAL) && (exponentDigits == 1));

    expectedWidth = integerDigits + fractionDigits + (keepDecimalPoint ? lbl_88C6A694[-1].decimalPointLength : 0);
    if (isNegative || (flags & FLAGS_SHOWSIGN) || (flags & FLAGS_SPACE))
        expectedWidth += sizeof("-") - 1;
    if (exponentDigits > 0)
        expectedWidth += exponentDigits + ((requireTwoDigitExponent ? sizeof("E+0") : sizeof("E+")) - 1);
    if (isHex)
        expectedWidth += sizeof("0X") - 1;

    if (flags & FLAGS_NILPADDING) {
        if (isNegative)
            self->OutStream(self, '-');
        else if (flags & FLAGS_SHOWSIGN)
            self->OutStream(self, '+');
        else if (flags & FLAGS_SPACE)
            self->OutStream(self, ' ');
        if (isHex) {
            self->OutStream(self, '0');
            self->OutStream(self, (flags & FLAGS_UPPER) ? 'X' : 'x');
        }
        if (!(flags & FLAGS_LEFTADJUST)) {
            for (i = expectedWidth; i < width; i++) {
                self->OutStream(self, '0');
            }
        }
    } else {
        if (!(flags & FLAGS_LEFTADJUST)) {
            for (i = expectedWidth; i < width; i++) {
                self->OutStream(self, CHAR_ADJUST);
            }
        }
        if (isNegative)
            self->OutStream(self, '-');
        else if (flags & FLAGS_SHOWSIGN)
            self->OutStream(self, '+');
        else if (flags & FLAGS_SPACE)
            self->OutStream(self, ' ');
        if (isHex) {
            self->OutStream(self, '0');
            self->OutStream(self, (flags & FLAGS_UPPER) ? 'X' : 'x');
        }
    }

    dblIntegerBase = KD(0x78) / ts4_pow_small_8819CCE8(base, integerDigits - 1);
    for (i = 0; i < integerDigits; i++) {
        workNumber = floor(((integerNumber + integerAdjust) * dblIntegerBase));
        if (i > integerThreshold) {
            self->OutStream(self, digits[0]);
        } else {
            self->OutStream(self, digits[(int)fn_88564D68(workNumber, dblBase)]);
        }
        dblIntegerBase *= dblBase;
    }

    trailingZeroes = 0;

    if (keepDecimalPoint) {
        if (internalDecimalPoint) {
            self->OutStream(self, internalDecimalPoint);
        } else {
            for (i = 0; i < lbl_88C6A694[-1].decimalPointLength; i++) {
                self->OutStream(self, ((char *)lbl_88C6A694)[i]);
            }
        }
    }

    for (i = 0; i < fractionDigits; i++) {
        if ((integerDigits > integerThreshold) || (i > fractionThreshold)) {
            trailingZeroes++;
        } else {
            fractionNumber *= dblBase;
            fractionAdjust *= dblBase;
            workNumber = floor(fractionNumber + fractionAdjust);
            fractionNumber -= workNumber;
            index = (int)fn_88564D68(workNumber, dblBase);
            if (index == 0) {
                trailingZeroes++;
            } else {
                while (trailingZeroes > 0) {
                    self->OutStream(self, digits[0]);
                    trailingZeroes--;
                }
                self->OutStream(self, digits[index]);
            }
        }
    }

    if (keepTrailingZeroes) {
        while (trailingZeroes > 0) {
            self->OutStream(self, digits[0]);
            trailingZeroes--;
        }
    }

    if (exponentDigits > 0) {
        self->OutStream(self, isHex ? ((flags & FLAGS_UPPER) ? 'P' : 'p') : ((flags & FLAGS_UPPER) ? 'E' : 'e'));
        self->OutStream(self, (isExponentNegative) ? '-' : '+');

        if (requireTwoDigitExponent)
            self->OutStream(self, '0');

        if (isHex)
            base = 10;
        exponentBase = (int)ts4_pow_small_8819CCE8(base, exponentDigits - 1);
        for (i = 0; i < exponentDigits; i++) {
            self->OutStream(self, digits[(uExponent / exponentBase) % base]);
            exponentBase /= base;
        }
    }
    if (flags & FLAGS_LEFTADJUST) {
        for (i = expectedWidth; i < width; i++) {
            self->OutStream(self, CHAR_ADJUST);
        }
    }
}

typedef struct {
    trio_class_t *data;
    trio_parameter_t *parameter;
} trio_reference_t;

/* trio_print_pointer (inlined into TrioFormatProcess). */
static void trio_print_pointer(void *ref, void *pointer)
{
    trio_reference_t *self = (trio_reference_t *)ref;
    unsigned long flags;
    trio_uintmax_t number;

    if (NULL == pointer) {
        /* The compiler knew internalNullString starts with '('. */
        const char *string = internalNullString;
        int ch = '(';
        do {
            self->data->OutStream(self->data, ch);
            ch = *++string;
        } while (ch);
    } else {
        number = (trio_uintmax_t)((char *)pointer - (char *)0);
        flags = self->parameter->flags;
        flags |= (FLAGS_UNSIGNED | FLAGS_ALTERNATIVE | FLAGS_NILPADDING);
        lib4_trio_TrioWriteNumber_8819DD48(self->data, number, flags, POINTER_WIDTH, NO_PRECISION, BASE_HEX);
    }
}

/* 0x8819EFD8 */
int lib4_trio_TrioFormatProcess_8819EFD8(trio_class_t *data, const char *format, trio_parameter_t *parameters)
{
    int charlen;
    int i;
    int ch;
    void *pointer;
    int precision;
    int base;
    int index;

    index = 0;
    i = 0;
    (void)fn_88567BA0(NULL, 0);

    while (format[index]) {
        if ((unsigned char)format[index] >= 0x80) {
            charlen = fn_88567BA0(&format[index], 5);
            if (charlen != -1) {
                while (charlen-- > 0) {
                    data->OutStream(data, format[index++]);
                }
                continue;
            }
        }
        if (CHAR_IDENTIFIER == format[index]) {
            if (CHAR_IDENTIFIER == format[index + 1]) {
                data->OutStream(data, CHAR_IDENTIFIER);
                index += 2;
            } else {
                unsigned long flags;
                int width;

                while (parameters[i].type == FORMAT_PARAMETER)
                    i++;

                flags = parameters[i].flags;

                width = parameters[i].width;
                if (flags & FLAGS_WIDTH_PARAMETER) {
                    width = (int)parameters[width].data.number.as_signed;
                    if (width < 0) {
                        flags |= FLAGS_LEFTADJUST;
                        flags &= ~FLAGS_NILPADDING;
                        width = -width;
                    }
                }

                if (flags & FLAGS_PRECISION) {
                    precision = parameters[i].precision;
                    if (flags & FLAGS_PRECISION_PARAMETER) {
                        precision = (int)parameters[precision].data.number.as_signed;
                        if (precision < 0) {
                            precision = NO_PRECISION;
                        }
                    }
                } else {
                    precision = NO_PRECISION;
                }

                base = parameters[i].base;
                if (flags & FLAGS_BASE_PARAMETER) {
                    base = (int)parameters[base].data.number.as_signed;
                }

                switch (parameters[i].type) {
                case FORMAT_CHAR:
                    if (flags & FLAGS_QUOTE)
                        data->OutStream(data, CHAR_QUOTE);
                    if (!(flags & FLAGS_LEFTADJUST)) {
                        while (--width > 0)
                            data->OutStream(data, CHAR_ADJUST);
                    }
                    ch = (int)parameters[i].data.number.as_signed;
                    if (flags & FLAGS_ALTERNATIVE)
                        lib4_trio_TrioWriteStringCharacterAlt_8819E108(data, ch);
                    else
                        data->OutStream(data, ch);
                    if (flags & FLAGS_LEFTADJUST) {
                        while (--width > 0)
                            data->OutStream(data, CHAR_ADJUST);
                    }
                    if (flags & FLAGS_QUOTE)
                        data->OutStream(data, CHAR_QUOTE);
                    break;

                case FORMAT_INT:
                    lib4_trio_TrioWriteNumber_8819DD48(data, parameters[i].data.number.as_unsigned, flags, width,
                                                       precision, base);
                    break;

                case FORMAT_DOUBLE:
                    lib4_trio_TrioWriteDouble_8819E4F0(data, parameters[i].data.longdoubleNumber, flags, width, precision, base);
                    break;

                case FORMAT_STRING:
                    lib4_trio_TrioWriteString_8819E278(data, parameters[i].data.string, flags, width, precision);
                    break;

                case FORMAT_POINTER: {
                    trio_reference_t reference;

                    reference.data = data;
                    reference.parameter = &parameters[i];
                    trio_print_pointer(&reference, parameters[i].data.pointer);
                } break;

                case FORMAT_COUNT:
                    pointer = parameters[i].data.pointer;
                    if (NULL != pointer) {
                        if (flags & FLAGS_SIZE_T)
                            *(unsigned int *)pointer = (unsigned int)data->committed;
                        else if (flags & FLAGS_PTRDIFF_T)
                            *(int *)pointer = (int)data->committed;
                        else if (flags & FLAGS_INTMAX_T)
                            *(trio_intmax_t *)pointer = (trio_intmax_t)data->committed;
                        else if (flags & FLAGS_QUAD)
                            *(unsigned __int64 *)pointer = (unsigned __int64)data->committed;
                        else if (flags & FLAGS_LONG)
                            *(long *)pointer = (long)data->committed;
                        else if (flags & FLAGS_SHORT)
                            *(short *)pointer = (short)data->committed;
                        else
                            *(int *)pointer = (int)data->committed;
                    }
                    break;

                case FORMAT_PARAMETER:
                    break;

                case FORMAT_ERRNO:
                    lib4_trio_TrioWriteString_8819E278(data, lbl_880DD7B0, flags, width, precision);
                    break;

                default:
                    break;
                }

                index = parameters[i].indexAfterSpecifier;
                i++;
            }
        } else {
            data->OutStream(data, format[index++]);
        }
    }
    return data->processed;
}

#define NO_SIZE (-1)
#define MAX_BASE 36
#define FLAGS_ALL_SIZES (FLAGS_ALL_VARSIZES | FLAGS_SHORTSHORT | FLAGS_SHORT)
#define TRIO_EINVAL 2
#define TRIO_ETOOMANY 3
#define TRIO_EDBLREF 4
#define TRIO_EGAP 5
#define TRIO_ERROR_RETURN(x, y) (-((x) + ((y) << 8)))

/* 0x8819D060: TrioParse (print-only, no argarray, no sticky/varsize/user
 * specifiers). */
int lib4_trio_TrioParse_8819D060(const char *format, trio_parameter_t *parameters, va_list *arglist)
{
    unsigned short usedEntries[MAX_PARAMETERS];
    int parameterPosition;
    int currentParam;
    int maxParam = -1;
    unsigned long flags;
    int width;
    int precision;
    int varsize;
    int base;
    int index;
    int dots;
    int positional;
    int indices[MAX_PARAMETERS];
    int pos = 0;
    char ch;
    int charlen;
    int save_errno;
    int i;
    int num;
    char *tmpformat;

    memset(usedEntries, 0, sizeof(usedEntries));

    save_errno = *ts4_if_call_seq_fn_8856CD88_88567ED8();
    index = 0;
    parameterPosition = 0;
    (void)fn_88567BA0(NULL, 0);

    while (format[index]) {
        if ((unsigned char)format[index] >= 0x80) {
            charlen = fn_88567BA0(&format[index], 5);
            index += (charlen > 0) ? charlen : 1;
            continue;
        }
        if (CHAR_IDENTIFIER == format[index++]) {
            if (CHAR_IDENTIFIER == format[index]) {
                index++;
                continue;
            }

            flags = 0;
            dots = 0;
            currentParam = lib4_trio_TrioGetPosition_8819CC70(format, &index);
            positional = (NO_POSITION != currentParam);
            if (!positional)
                currentParam = parameterPosition;
            if (currentParam >= MAX_PARAMETERS)
                return TRIO_ERROR_RETURN(TRIO_ETOOMANY, index);

            if (currentParam > maxParam)
                maxParam = currentParam;

            width = NO_WIDTH;
            precision = NO_PRECISION;
            base = NO_BASE;
            varsize = NO_SIZE;

            while (lib4_trio_TrioIsQualifier_8819CA18(format[index])) {
                ch = format[index++];

                switch (ch) {
                case ' ':
                    flags |= FLAGS_SPACE;
                    break;

                case '+':
                    flags |= FLAGS_SHOWSIGN;
                    break;

                case '-':
                    flags |= FLAGS_LEFTADJUST;
                    flags &= ~FLAGS_NILPADDING;
                    break;

                case '#':
                    flags |= FLAGS_ALTERNATIVE;
                    break;

                case '.':
                    if (dots == 0) {
                        dots++;
                        if ('.' == format[index])
                            break;
                        flags |= FLAGS_PRECISION;
                        if ('*' == format[index]) {
                            index++;
                            flags |= FLAGS_PRECISION_PARAMETER;
                            precision = lib4_trio_TrioGetPosition_8819CC70(format, &index);
                            if (precision == NO_POSITION) {
                                parameterPosition++;
                                if (positional)
                                    precision = parameterPosition;
                                else {
                                    precision = currentParam;
                                    currentParam = precision + 1;
                                }
                            } else {
                                if (!positional)
                                    currentParam = precision + 1;
                                if (width > maxParam)
                                    maxParam = precision;
                            }
                            if (currentParam > maxParam)
                                maxParam = currentParam;
                        } else {
                            precision = (int)ts4_tailcall_fn_88564828_88564B00(&format[index], &tmpformat, BASE_DECIMAL);
                            index = (int)(tmpformat - format);
                        }
                    } else if (dots == 1) {
                        dots++;
                        flags |= FLAGS_BASE;
                        if ('*' == format[index]) {
                            index++;
                            flags |= FLAGS_BASE_PARAMETER;
                            base = lib4_trio_TrioGetPosition_8819CC70(format, &index);
                            if (base == NO_POSITION) {
                                parameterPosition++;
                                if (positional)
                                    base = parameterPosition;
                                else {
                                    base = currentParam;
                                    currentParam = base + 1;
                                }
                            } else {
                                if (!positional)
                                    currentParam = base + 1;
                                if (base > maxParam)
                                    maxParam = base;
                            }
                            if (currentParam > maxParam)
                                maxParam = currentParam;
                        } else {
                            base = (int)ts4_tailcall_fn_88564828_88564B00(&format[index], &tmpformat, BASE_DECIMAL);
                            if (base > MAX_BASE)
                                return TRIO_ERROR_RETURN(TRIO_EINVAL, index);
                            index = (int)(tmpformat - format);
                        }
                    } else {
                        return TRIO_ERROR_RETURN(TRIO_EINVAL, index);
                    }
                    break;

                case '*':
                    flags |= (FLAGS_WIDTH | FLAGS_WIDTH_PARAMETER);
                    width = lib4_trio_TrioGetPosition_8819CC70(format, &index);
                    if (width == NO_POSITION) {
                        parameterPosition++;
                        if (positional)
                            width = parameterPosition;
                        else {
                            width = currentParam;
                            currentParam = width + 1;
                        }
                    } else {
                        if (!positional)
                            currentParam = width + 1;
                        if (width > maxParam)
                            maxParam = width;
                    }
                    if (currentParam > maxParam)
                        maxParam = currentParam;
                    break;

                case '0':
                    if (!(flags & FLAGS_LEFTADJUST))
                        flags |= FLAGS_NILPADDING;
                    /* FALLTHROUGH */
                case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                    flags |= FLAGS_WIDTH;
                    width = (int)ts4_tailcall_fn_88564828_88564B00(&format[index - 1], &tmpformat, BASE_DECIMAL);
                    index = (int)(tmpformat - format);
                    break;

                case 'h':
                    if (flags & FLAGS_SHORTSHORT)
                        return TRIO_ERROR_RETURN(TRIO_EINVAL, index);
                    else if (flags & FLAGS_SHORT)
                        flags |= FLAGS_SHORTSHORT;
                    else
                        flags |= FLAGS_SHORT;
                    break;

                case 'l':
                    if (flags & FLAGS_QUAD)
                        return TRIO_ERROR_RETURN(TRIO_EINVAL, index);
                    else if (flags & FLAGS_LONG)
                        flags |= FLAGS_QUAD;
                    else
                        flags |= FLAGS_LONG;
                    break;

                case 'L':
                    flags |= FLAGS_LONGDOUBLE;
                    break;

                case 'z':
                    flags |= FLAGS_SIZE_T;
                    flags |= FLAGS_LONG;
                    break;

                case 't':
                    flags |= FLAGS_PTRDIFF_T;
                    flags |= FLAGS_LONG;
                    break;

                case 'j':
                    flags |= FLAGS_INTMAX_T;
                    flags |= FLAGS_QUAD;
                    break;

                case 'q':
                    flags |= FLAGS_QUAD;
                    break;

                case 'I':
                    if (flags & FLAGS_FIXED_SIZE)
                        return TRIO_ERROR_RETURN(TRIO_EINVAL, index);
                    if (flags & (FLAGS_ALL_SIZES | FLAGS_LONGDOUBLE | FLAGS_WIDECHAR | FLAGS_VARSIZE_PARAMETER))
                        return TRIO_ERROR_RETURN(TRIO_EINVAL, index);
                    if ((format[index] == '6') && (format[index + 1] == '4')) {
                        varsize = 8;
                        index += 2;
                    } else if ((format[index] == '3') && (format[index + 1] == '2')) {
                        varsize = 4;
                        index += 2;
                    } else if ((format[index] == '1') && (format[index + 1] == '6')) {
                        varsize = 2;
                        index += 2;
                    } else if (format[index] == '8') {
                        varsize = 1;
                        index++;
                    } else
                        return TRIO_ERROR_RETURN(TRIO_EINVAL, index);
                    flags |= FLAGS_FIXED_SIZE;
                    break;

                case 'w':
                    flags |= FLAGS_WIDECHAR;
                    break;

                case 'Z':
                    break;

                default:
                    return TRIO_ERROR_RETURN(TRIO_EINVAL, index);
                }
            }

            if (flags & FLAGS_WIDTH_PARAMETER) {
                usedEntries[width] += 1;
                parameters[pos].type = FORMAT_PARAMETER;
                parameters[pos].flags = 0;
                indices[width] = pos;
                width = pos++;
            }
            if (flags & FLAGS_PRECISION_PARAMETER) {
                usedEntries[precision] += 1;
                parameters[pos].type = FORMAT_PARAMETER;
                parameters[pos].flags = 0;
                indices[precision] = pos;
                precision = pos++;
            }
            if (flags & FLAGS_BASE_PARAMETER) {
                usedEntries[base] += 1;
                parameters[pos].type = FORMAT_PARAMETER;
                parameters[pos].flags = 0;
                indices[base] = pos;
                base = pos++;
            }
            if (flags & FLAGS_VARSIZE_PARAMETER) {
                usedEntries[varsize] += 1;
                parameters[pos].type = FORMAT_PARAMETER;
                parameters[pos].flags = 0;
                indices[varsize] = pos;
                varsize = pos++;
            }

            indices[currentParam] = pos;

            ch = format[index++];
            switch (ch) {
            case 'C':
                flags |= FLAGS_WIDECHAR;
                /* FALLTHROUGH */
            case 'c':
                if (flags & FLAGS_LONG)
                    flags |= FLAGS_WIDECHAR;
                else if (flags & FLAGS_SHORT)
                    flags &= ~FLAGS_WIDECHAR;
                parameters[pos].type = FORMAT_CHAR;
                break;

            case 'S':
                flags |= FLAGS_WIDECHAR;
                /* FALLTHROUGH */
            case 's':
                if (flags & FLAGS_LONG)
                    flags |= FLAGS_WIDECHAR;
                else if (flags & FLAGS_SHORT)
                    flags &= ~FLAGS_WIDECHAR;
                parameters[pos].type = FORMAT_STRING;
                break;

            case '[':
                break;

            case 'i':
                parameters[pos].type = FORMAT_INT;
                break;

            case 'u':
                flags |= FLAGS_UNSIGNED;
                parameters[pos].type = FORMAT_INT;
                break;

            case 'd':
                flags &= ~FLAGS_BASE_PARAMETER;
                base = BASE_DECIMAL;
                parameters[pos].type = FORMAT_INT;
                break;

            case 'o':
                flags |= FLAGS_UNSIGNED;
                flags &= ~FLAGS_BASE_PARAMETER;
                base = BASE_OCTAL;
                parameters[pos].type = FORMAT_INT;
                break;

            case 'X':
                flags |= FLAGS_UPPER;
                /* FALLTHROUGH */
            case 'x':
                flags |= FLAGS_UNSIGNED;
                flags &= ~FLAGS_BASE_PARAMETER;
                base = BASE_HEX;
                parameters[pos].type = FORMAT_INT;
                break;

            case 'E':
                flags |= FLAGS_UPPER;
                /* FALLTHROUGH */
            case 'e':
                flags |= FLAGS_FLOAT_E;
                parameters[pos].type = FORMAT_DOUBLE;
                break;

            case 'G':
                flags |= FLAGS_UPPER;
                /* FALLTHROUGH */
            case 'g':
                flags |= FLAGS_FLOAT_G;
                parameters[pos].type = FORMAT_DOUBLE;
                break;

            case 'F':
                flags |= FLAGS_UPPER;
                /* FALLTHROUGH */
            case 'f':
                parameters[pos].type = FORMAT_DOUBLE;
                break;

            case 'p':
                flags |= FLAGS_LONG;
                parameters[pos].type = FORMAT_POINTER;
                break;

            case 'n':
                parameters[pos].type = FORMAT_COUNT;
                break;

            case 'A':
                flags |= FLAGS_UPPER;
                /* FALLTHROUGH */
            case 'a':
                base = BASE_HEX;
                parameters[pos].type = FORMAT_DOUBLE;
                break;

            case 'm':
                parameters[pos].type = FORMAT_ERRNO;
                break;

            default:
                return TRIO_ERROR_RETURN(TRIO_EINVAL, index);
            }

            usedEntries[currentParam] += 1;

            parameters[pos].indexAfterSpecifier = index;
            parameters[pos].flags = flags;
            parameters[pos].width = width;
            parameters[pos].precision = precision;
            parameters[pos].base = (base == NO_BASE) ? BASE_DECIMAL : base;
            parameters[pos].varsize = varsize;
            pos++;
            if (!positional)
                parameterPosition++;
        }
    }

    for (num = 0; num <= maxParam; num++) {
        if (usedEntries[num] != 1) {
            if (usedEntries[num] == 0)
                return TRIO_ERROR_RETURN(TRIO_EGAP, num);
            else
                return TRIO_ERROR_RETURN(TRIO_EDBLREF, num);
        }
        i = indices[num];
        if ((parameters[i].type != FORMAT_PARAMETER) && (parameters[i].flags & FLAGS_IGNORE))
            continue;
        switch (parameters[i].type) {
        case FORMAT_GROUP:
        case FORMAT_STRING:
            parameters[i].data.string = (char *)LIB4_VA_PTR(*arglist);
            break;

        case FORMAT_POINTER:
        case FORMAT_COUNT:
        case FORMAT_UNKNOWN:
            parameters[i].data.pointer = LIB4_VA_PTR(*arglist);
            break;

        case FORMAT_CHAR:
        case FORMAT_INT:
            if (parameters[i].flags & (FLAGS_VARSIZE_PARAMETER | FLAGS_FIXED_SIZE)) {
                if (parameters[i].flags & FLAGS_VARSIZE_PARAMETER)
                    varsize = (int)parameters[parameters[i].varsize].data.number.as_unsigned;
                else
                    varsize = parameters[i].varsize;
                parameters[i].flags &= ~FLAGS_ALL_VARSIZES;
                if (varsize <= (int)sizeof(int))
                    ;
                else if (varsize <= (int)sizeof(long))
                    parameters[i].flags |= FLAGS_LONG;
                else if (varsize <= (int)sizeof(__int64))
                    parameters[i].flags |= FLAGS_QUAD;
                else
                    parameters[i].flags |= FLAGS_INTMAX_T;
            }
            if (parameters[i].flags & FLAGS_SIZE_T)
                parameters[i].data.number.as_unsigned = (trio_uintmax_t)*(unsigned int *)(LIB4_VA_NEXT(*arglist) - 4);
            else if (parameters[i].flags & FLAGS_PTRDIFF_T)
                parameters[i].data.number.as_unsigned = (trio_uintmax_t)LIB4_VA_INT(*arglist);
            else if (parameters[i].flags & FLAGS_INTMAX_T)
                parameters[i].data.number.as_unsigned = (trio_uintmax_t)LIB4_VA_I64(*arglist);
            else if (parameters[i].flags & FLAGS_QUAD)
                parameters[i].data.number.as_unsigned = (trio_uintmax_t)LIB4_VA_I64(*arglist);
            else if (parameters[i].flags & FLAGS_LONG)
                parameters[i].data.number.as_unsigned = (trio_uintmax_t)LIB4_VA_INT(*arglist);
            else
                parameters[i].data.number.as_unsigned = (trio_uintmax_t)LIB4_VA_INT(*arglist);
            break;

        case FORMAT_PARAMETER:
            if (parameters[i].flags & FLAGS_IGNORE)
                parameters[i].data.pointer = LIB4_VA_PTR(*arglist);
            else
                parameters[i].data.number.as_unsigned = (trio_uintmax_t)LIB4_VA_INT(*arglist);
            break;

        case FORMAT_DOUBLE:
            if (parameters[i].flags & FLAGS_LONGDOUBLE)
                parameters[i].data.longdoubleNumber = LIB4_VA_DBL(*arglist);
            else
                parameters[i].data.longdoubleNumber = LIB4_VA_DBL(*arglist);
            break;

        case FORMAT_ERRNO:
            parameters[i].data.errorNumber = save_errno;
            break;

        default:
            break;
        }
    }
    return num;
}

/* 0x8819F480 */
int fn_8819F480(void *destination, int destinationSize, void (*OutStream)(trio_class_t *, int),
                const char *format, va_list *arglist)
{
    int status;
    trio_class_t data;
    trio_parameter_t parameters[MAX_PARAMETERS];

    memset(&data, 0, sizeof(data));
    data.OutStream = OutStream;
    data.location = destination;
    data.max = destinationSize;
    data.error = 0;

    if (NULL == internalLocaleValues) {
        fn_8819CB30();
    }

    status = lib4_trio_TrioParse_8819D060(format, parameters, arglist);
    if (status < 0)
        return status;

    status = lib4_trio_TrioFormatProcess_8819EFD8(&data, format, parameters);
    if (data.error != 0) {
        status = data.error;
    }
    return status;
}

void ts4_if_get_u32_off18_8819F5A8(trio_class_t *self, int output);

/* 0x8819C9A8 trio_vsnprintf */
int fn_8819C9A8(char *buffer, unsigned int max, const char *format, va_list args)
{
    int status;

    status = fn_8819F480(&buffer, max > 0 ? (int)max - 1 : 0, ts4_if_get_u32_off18_8819F5A8, format, &args);
    if (max > 0)
        *buffer = NIL;
    return status;
}
