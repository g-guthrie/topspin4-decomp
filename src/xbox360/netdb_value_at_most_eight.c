typedef unsigned int u32;

typedef struct Ts4NetDbFlagState {
    unsigned char reserved[0xC];
    int flag;
} Ts4NetDbFlagState;

/* Swing_DLL.xex 0x88152660. */
unsigned char ts4_netdb_value_at_most_eight(
    Ts4NetDbFlagState *state,
    u32 value
)
{
    unsigned char result = value <= 8U;

    if (result == 0 && state->flag == 0) {
        state->flag = 1;
    }
    return result;
}
