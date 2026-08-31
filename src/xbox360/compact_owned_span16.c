typedef unsigned int u32;

typedef struct Ts4OwnedElement16 {
    u32 words[4];
} Ts4OwnedElement16;

typedef struct Ts4OwnedSpan16 {
    Ts4OwnedElement16 *begin;
    Ts4OwnedElement16 *end;
} Ts4OwnedSpan16;

extern void fn_88171A38(
    Ts4OwnedElement16 *destination,
    const Ts4OwnedElement16 *source
);
extern void fn_88929290(Ts4OwnedElement16 *element);

/* Swing_DLL.xex 0x88170048. */
Ts4OwnedElement16 *ts4_compact_owned_span16(
    Ts4OwnedSpan16 *span,
    Ts4OwnedElement16 *destination,
    const Ts4OwnedElement16 *source
)
{
    Ts4OwnedElement16 *current_destination = destination;
    int count = span->end - source;

    while (count > 0) {
        fn_88171A38(current_destination, source);
        current_destination->words[3] = source->words[3];
        count--;
        source++;
        current_destination++;
    }
    {
        Ts4OwnedElement16 *current = current_destination;
        Ts4OwnedElement16 *end = span->end;
        while (current != end) {
            fn_88929290(current);
            current++;
        }
    }
    span->end = current_destination;
    return destination;
}
