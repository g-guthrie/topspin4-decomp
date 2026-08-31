typedef unsigned int u32;

typedef struct Ts4Block94 {
    unsigned char first_80[0x80];
    u32 words[5];
} Ts4Block94;

extern void *memcpy(void *destination, const void *source, unsigned long size);

/* Swing_DLL.xex 0x881546E8. */
void ts4_copy_block94(Ts4Block94 *destination, const Ts4Block94 *source)
{
    if (destination != 0) {
        memcpy(destination, source, 0x80);
        destination->words[0] = source->words[0];
        destination->words[1] = source->words[1];
        destination->words[2] = source->words[2];
        destination->words[3] = source->words[3];
        destination->words[4] = source->words[4];
    }
}
