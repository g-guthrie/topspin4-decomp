/* Zero-initialising constructor for a 0x184-byte record (fields named by offset). */
typedef unsigned int u32;

extern void *ts4_memset(void *destination, int value, unsigned int size);

typedef struct Ts4Record184 {
    u32 words_00[9];
    unsigned char pad_24[0x60];
    u32 words_84[7];
    unsigned char block_a0[0x40];
    unsigned char block_e0[0x40];
    unsigned char block_120[0x10];
    unsigned char block_130[0x10];
    unsigned char block_140[0x10];
    u32 words_150[2];
    unsigned char kind_158;
    unsigned char mode_159;
    unsigned short half_15a;
    unsigned short half_15c;
    unsigned char bytes_15e[14];
    u32 words_16c[5];
    unsigned char flag_180;
} Ts4Record184;

/* Swing_DLL.xex 0x88151180 */
void ts4_record184_init_88151180(Ts4Record184 *self)
{
    u32 zero = 0;

    self->words_00[0] = zero;
    self->words_00[1] = zero;
    self->words_00[2] = zero;
    self->words_00[3] = zero;
    self->words_00[4] = zero;
    self->words_00[5] = zero;
    self->words_00[6] = zero;
    self->words_00[7] = zero;
    self->words_00[8] = zero;
    self->words_84[0] = zero;
    self->words_84[1] = zero;
    self->words_84[2] = zero;
    self->words_84[3] = zero;
    self->words_84[4] = zero;
    self->words_84[5] = zero;
    self->words_84[6] = zero;
    ts4_memset(self->block_a0, 0, 0x40);
    ts4_memset(self->block_e0, 0, 0x40);
    ts4_memset(self->block_120, 0, 0x10);
    ts4_memset(self->block_130, 0, 0x10);
    ts4_memset(self->block_140, 0, 0x10);
    self->words_150[0] = zero;
    self->words_150[1] = zero;
    self->kind_158 = 8;
    self->mode_159 = 2;
    self->half_15a = 0;
    self->half_15c = 0;
    self->bytes_15e[0] = 0;
    self->bytes_15e[1] = 0;
    self->bytes_15e[2] = 0;
    self->bytes_15e[3] = 0;
    self->bytes_15e[4] = 0;
    self->bytes_15e[5] = 0;
    self->bytes_15e[6] = 0;
    self->bytes_15e[7] = 0;
    self->bytes_15e[8] = 0;
    self->bytes_15e[9] = 0;
    self->bytes_15e[10] = 0;
    self->bytes_15e[11] = 0;
    self->bytes_15e[12] = 0;
    self->bytes_15e[13] = 0;
    self->words_16c[0] = zero;
    self->words_16c[1] = zero;
    self->words_16c[2] = zero;
    self->words_16c[3] = zero;
    self->words_16c[4] = zero;
    self->flag_180 = 0;
}
