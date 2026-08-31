typedef unsigned int u32;

typedef struct Ts4BitCursor {
    u32 *word;
    int bit;
} Ts4BitCursor;

typedef struct Ts4BitLocation {
    u32 *word;
    u32 mask;
} Ts4BitLocation;

extern Ts4BitCursor *fn_8816FE78(
    Ts4BitCursor *output,
    const Ts4BitCursor *source,
    int distance
);

/* Swing_DLL.xex 0x8816FAF0. */
Ts4BitLocation *ts4_advance_bit_cursor_to_location(
    Ts4BitLocation *output,
    const Ts4BitCursor *source,
    int distance
)
{
    Ts4BitCursor copy = *source;
    Ts4BitCursor advanced;
    volatile Ts4BitCursor *result = fn_8816FE78(&advanced, &copy, distance);
    u32 *word = result->word;
    u32 mask = 1u << result->bit;

    output->word = word;
    output->mask = mask;
    return output;
}
