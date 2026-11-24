/* Swing_DLL.xex 0x88574230-0x8857437C, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: xtoa_s (unsigned long to string with radix). */
typedef unsigned int u32;
extern u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(void);

#define VALIDATE(expr, code) \
    do { \
        int ok_ = !!(expr); \
        if (!ok_) { \
            u32 *e_ = ts4_if_call_seq_fn_8856CD88_88567ED8(); \
            *e_ = (code); \
            fn_8856D2C0(); \
            return (code); \
        } \
    } while (0)

int ts4_crt_xtoa_s_88574230(u32 val, char *buf, u32 size, u32 radix, int is_neg)
{
    char *p;
    char *first;
    u32 digval;
    u32 length;
    VALIDATE(buf != 0, 22);
    VALIDATE(size > 0, 22);
    buf[0] = 0;
    length = is_neg ? 2 : 1;
    VALIDATE(size > length, 34);
    VALIDATE(2 <= radix && radix <= 36, 22);
    length = 0;
    p = buf;
    if (is_neg) {
        *p++ = '-';
        length = 1;
        val = (u32)(-(int)val);
    }
    first = p;
    do {
        digval = val % radix;
        val /= radix;
        if (digval > 9)
            *p++ = (char)(digval + 'a' - 10);
        else
            *p++ = (char)(digval + '0');
        ++length;
    } while (val > 0 && length < size);
    if (length >= size) {
        buf[0] = 0;
        VALIDATE(length < size, 34);
    }
    *p-- = 0;
    do {
        char t = *p;
        *p = *first;
        *first = t;
        --p;
        ++first;
    } while (first < p);
    return 0;
}
