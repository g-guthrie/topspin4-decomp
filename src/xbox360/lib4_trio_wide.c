/* trio 1.10 printf core, second copy built with a 16-bit wchar_t character type
 * (TRIO "wide" build) as linked into Swing_DLL.xex. See lib4_trio.h for license. */
#include "lib4_trio.h"

typedef unsigned short trio_wchar_t;

#define NO_POSITION (-1)
#define QUALIFIER_POSITION '$'
#define NIL 0

void lib4_trio_wide_TrioWriteNumber_881A07C8(trio_class_t *self, trio_uintmax_t number, unsigned long flags,
                                             int width, int precision, int base);

long lib4_trio_wide_wcstol_8819F8B0(const trio_wchar_t *string, trio_wchar_t **endp);

/* 0x8819FA70 */
LIB4_NOINLINE int lib4_trio_wide_TrioGetPosition_8819FA70(const trio_wchar_t *format, int *indexPointer)
{
    trio_wchar_t *tmpformat;
    int number = 0;
    int index = *indexPointer;

    number = (int)lib4_trio_wide_wcstol_8819F8B0(&format[index], &tmpformat);
    index = (int)(tmpformat - format);
    if ((number != 0) && (QUALIFIER_POSITION == format[index++])) {
        *indexPointer = index;
        return number - 1;
    }
    return NO_POSITION;
}

extern const trio_wchar_t lbl_880CDBB8[]; /* internalDigitsLower, internalDigitsUpper at +0x50 */
#define internalDigitsLower lbl_880CDBB8
#define internalDigitsUpper (lbl_880CDBB8 + 0x28)

/* 0x881A07C8 (not matched: the original keeps the out-of-frame NIL store at &buffer[sizeof(buffer) - 1],
 * an upstream wide-build bug, which this compiler run removes as dead). */
void lib4_trio_wide_TrioWriteNumber_881A07C8(trio_class_t *self, trio_uintmax_t number, unsigned long flags,
                                             int width, int precision, int base)
{
    int isNegative;
    int isNumberZero;
    int isPrecisionZero;
    int ignoreNumber;
    trio_wchar_t buffer[64 * (1 + 5) + 1];
    trio_wchar_t *bufferend;
    trio_wchar_t *pointer;
    const trio_wchar_t *digits;
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

/* 0x881A0B90: TrioWriteStringCharacter for FLAGS_ALTERNATIVE (the caller tests the flag). */
LIB4_NOINLINE void lib4_trio_wide_TrioWriteStringCharacterAlt_881A0B90(trio_class_t *self, int ch)
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
            lib4_trio_wide_TrioWriteNumber_881A07C8(self, (trio_uintmax_t)ch, FLAGS_UNSIGNED | FLAGS_NILPADDING, 2, 2,
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

extern const trio_wchar_t lbl_880CDB70[]; /* internalNullString L"(nil)" */
#define internalNullString lbl_880CDB70

/* 0x881A0D00 */
void lib4_trio_wide_TrioWriteString_881A0D00(trio_class_t *self, const trio_wchar_t *string, unsigned long flags,
                                             int width, int precision)
{
    int length;
    int ch;

    if (string == NULL) {
        string = internalNullString;
        length = sizeof("(nil)") * sizeof(trio_wchar_t) - 1;
        flags &= (~FLAGS_QUOTE);
        width = 0;
    } else {
        const trio_wchar_t *p = string;
        while (*p)
            p++;
        length = (int)(p - string);
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
        ch = *string++;
        if (flags & FLAGS_ALTERNATIVE)
            lib4_trio_wide_TrioWriteStringCharacterAlt_881A0B90(self, ch);
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

void lib4_trio_wide_TrioWriteDouble_881A0E68(trio_class_t *self, double number, unsigned long flags, int width,
                                             int precision, int base);

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
        const trio_wchar_t *string = internalNullString;
        trio_wchar_t ch = '(';
        do {
            self->data->OutStream(self->data, ch);
            ch = *++string;
        } while (ch);
    } else {
        number = (trio_uintmax_t)((trio_wchar_t *)pointer - (trio_wchar_t *)0);
        flags = self->parameter->flags;
        flags |= (FLAGS_UNSIGNED | FLAGS_ALTERNATIVE | FLAGS_NILPADDING);
        lib4_trio_wide_TrioWriteNumber_881A07C8(self->data, number, flags, POINTER_WIDTH, NO_PRECISION, BASE_HEX);
    }
}

/* 0x881A18E0: TrioFormatProcess (wide copy: no multibyte skipping, no %m). */
int lib4_trio_wide_TrioFormatProcess_881A18E0(trio_class_t *data, const trio_wchar_t *format,
                                              trio_parameter_t *parameters)
{
    int i;
    int ch;
    void *pointer;
    int precision;
    int base;
    int index;

    index = 0;
    i = 0;

    while (format[index]) {
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
                        lib4_trio_wide_TrioWriteStringCharacterAlt_881A0B90(data, ch);
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
                    lib4_trio_wide_TrioWriteNumber_881A07C8(data, parameters[i].data.number.as_unsigned, flags, width,
                                                       precision, base);
                    break;

                case FORMAT_DOUBLE:
                    lib4_trio_wide_TrioWriteDouble_881A0E68(data, parameters[i].data.longdoubleNumber, flags, width, precision, base);
                    break;

                case FORMAT_STRING:
                    lib4_trio_wide_TrioWriteString_881A0D00(data, (trio_wchar_t *)parameters[i].data.string, flags, width, precision);
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

/* TrioIsQualifier (wide); matched separately. The original was in this translation unit, which let
 * the compiler keep the loaded character in a volatile register across the call in TrioParse. */
int ts4_is_format_char_8819F958(int ch);

#define NO_SIZE (-1)
#define MAX_BASE 36
#define FLAGS_ALL_SIZES (FLAGS_ALL_VARSIZES | FLAGS_SHORTSHORT | FLAGS_SHORT)
#define TRIO_EINVAL 2
#define TRIO_ETOOMANY 3
#define TRIO_EDBLREF 4
#define TRIO_EGAP 5
#define TRIO_ERROR_RETURN(x, y) (-((x) + ((y) << 8)))

/* 0x8819FAF0: TrioParse (wide copy; not matched, see ts4_is_format_char_8819F958 above) (print-only, no argarray, no sticky/varsize/user
 * specifiers). */
int lib4_trio_wide_TrioParse_8819FAF0(const trio_wchar_t *format, trio_parameter_t *parameters, va_list *arglist)
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
    trio_wchar_t ch;
    int save_errno;
    int i;
    int num;
    trio_wchar_t *tmpformat;

    memset(usedEntries, 0, sizeof(usedEntries));

    save_errno = *ts4_if_call_seq_fn_8856CD88_88567ED8();
    index = 0;
    parameterPosition = 0;

    while (format[index]) {
        if (CHAR_IDENTIFIER == format[index++]) {
            if (CHAR_IDENTIFIER == format[index]) {
                index++;
                continue;
            }

            flags = 0;
            dots = 0;
            currentParam = lib4_trio_wide_TrioGetPosition_8819FA70(format, &index);
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

            while (ts4_is_format_char_8819F958(format[index])) {
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
                            precision = lib4_trio_wide_TrioGetPosition_8819FA70(format, &index);
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
                            precision = (int)lib4_trio_wide_wcstol_8819F8B0(&format[index], &tmpformat);
                            index = (int)(tmpformat - format);
                        }
                    } else if (dots == 1) {
                        dots++;
                        flags |= FLAGS_BASE;
                        if ('*' == format[index]) {
                            index++;
                            flags |= FLAGS_BASE_PARAMETER;
                            base = lib4_trio_wide_TrioGetPosition_8819FA70(format, &index);
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
                            base = (int)lib4_trio_wide_wcstol_8819F8B0(&format[index], &tmpformat);
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
                    width = lib4_trio_wide_TrioGetPosition_8819FA70(format, &index);
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
                    width = (int)lib4_trio_wide_wcstol_8819F8B0(&format[index - 1], &tmpformat);
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

/* 0x881A1CE0: TrioFormat (the wide copy has no locale initialisation). */
int lib4_trio_wide_TrioFormat_881A1CE0(void *destination, int destinationSize,
                                       void (*OutStream)(trio_class_t *, int), const trio_wchar_t *format,
                                       va_list *arglist)
{
    int status;
    trio_class_t data;
    trio_parameter_t parameters[MAX_PARAMETERS];

    memset(&data, 0, sizeof(data));
    data.OutStream = OutStream;
    data.location = destination;
    data.max = destinationSize;
    data.error = 0;

    status = lib4_trio_wide_TrioParse_8819FAF0(format, parameters, arglist);
    if (status < 0)
        return status;

    status = lib4_trio_wide_TrioFormatProcess_881A18E0(&data, format, parameters);
    if (data.error != 0) {
        status = data.error;
    }
    return status;
}
