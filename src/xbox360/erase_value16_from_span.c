typedef unsigned int u32;

typedef struct Ts4Value16 {
    u32 words[4];
} Ts4Value16;

typedef struct Ts4ValueSpan16 {
    Ts4Value16 *begin;
    Ts4Value16 *end;
} Ts4ValueSpan16;

/* Swing_DLL.xex 0x8816FA88. */
Ts4Value16 *ts4_erase_value16_from_span(
    Ts4ValueSpan16 *span,
    Ts4Value16 *position
)
{
    Ts4Value16 *source = position + 1;

    if (source != span->end) {
        Ts4Value16 *current = position;
        int count = span->end - source;
        if (count > 0) {
            do {
                Ts4Value16 *next = current + 1;
                *current = *next;
                current = next;
            } while (--count != 0);
        }
    }
    span->end--;
    return position;
}
