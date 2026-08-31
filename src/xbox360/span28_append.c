typedef unsigned int u32;

typedef struct Ts4Span28Value {
    u32 words[7];
} Ts4Span28Value;

typedef struct Ts4Span28 {
    Ts4Span28Value *begin;
    Ts4Span28Value *current;
    Ts4Span28Value *end;
} Ts4Span28;

extern void ts4_span28_grow_and_append(
    Ts4Span28 *span,
    Ts4Span28Value *current,
    const Ts4Span28Value *value,
    int count,
    int copy
);

/* Swing_DLL.xex 0x8816FD60. */
void ts4_span28_append(Ts4Span28 *span, const Ts4Span28Value *value)
{
    Ts4Span28Value *current = span->current;

    if (current != span->end) {
        if (current != 0) {
            *current = *value;
        }
        span->current += 1;
        return;
    }
    ts4_span28_grow_and_append(span, current, value, 1, 1);
}
