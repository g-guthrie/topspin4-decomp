typedef unsigned int u32;

typedef struct Ts4Span16 {
    u32 *begin;
    u32 *current;
    u32 *end;
} Ts4Span16;

extern void ts4_span16_grow_and_append(
    Ts4Span16 *span,
    u32 *current,
    const u32 *value,
    int count
);

/* Swing_DLL.xex 0x88152530. */
void ts4_span16_append(Ts4Span16 *span, const u32 *value)
{
    u32 *current = span->current;

    if (current != span->end) {
        if (current != 0) {
            current[0] = value[0];
            current[1] = value[1];
            current[2] = value[2];
            current[3] = value[3];
        }
        span->current = (u32 *)((char *)span->current + 0x10);
        return;
    }
    ts4_span16_grow_and_append(span, current, value, 1);
}
