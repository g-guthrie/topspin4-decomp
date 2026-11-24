/* Swing_DLL.xex 0x885C48A0-0x885C496C, executable version 0.0.0.3. */

typedef struct Ts4BlendConfig {
    unsigned char reserved0[0x8C];
    int enabled;
    unsigned char reserved1[4];
    int lock_first;
    unsigned char reserved2[4];
    int lock_second;
} Ts4BlendConfig;

void ts4_short_pair_blend_885C48A0(
    Ts4BlendConfig *config,
    int mode,
    short low,
    short high,
    short *first,
    short *second
)
{
    if (low >= high) {
        *first = 0;
        *second = high;
    } else {
        *first = (short)((high - low) / 2);
        *second = (short)((high + low) / 2);
    }
    if (mode == 1) {
        if (config->enabled == 1 && config->lock_first == 0) {
            short average = (short)((*first + *second) / 2);
            *first = average;
            *second = average;
        }
    } else if (config->enabled == 1 && config->lock_second == 0) {
        short average = (short)((*first + *second) / 2);
        *first = average;
        *second = average;
    }
}
