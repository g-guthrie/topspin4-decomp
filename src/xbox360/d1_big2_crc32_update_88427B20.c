/* Swing_DLL.xex 0x88427B20-0x88427C04, executable version 0.0.0.3. */

typedef unsigned int u32;

typedef struct Ts4CrcState {
    unsigned char reserved[8];
    u32 value;
} Ts4CrcState;

int ts4_crc32_update_88427B20(Ts4CrcState *state, const unsigned char *data, int length)
{
    u32 crc = state->value;
    int index;

    for (index = 0; index < length; index++) {
        u32 entry = (data[index] ^ crc) & 0xFF;
        int bit;

        for (bit = 0; bit < 8; bit++) {
            if (entry & 1) {
                entry = (entry >> 1) ^ 0xEDB88320u;
            } else {
                entry >>= 1;
            }
        }
        crc = (crc >> 8) ^ entry;
    }
    state->value = crc;
    return length;
}
