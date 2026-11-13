/* Swing_DLL.xex 0x88155DC8-0x88155EA0, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Ts4Block98 {
    u8 a[0x40];
    u8 b[0x20];
    u8 c[0x10];
    u8 d[0x10];
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
    u32 w4;
    u8 e0;
    u8 e1;
    u8 e2;
    u8 e3;
} Ts4Block98;

void ts4_copy_block98_88155DC8(Ts4Block98 *destination, const Ts4Block98 *source)
{
    int i;

    for (i = 0; i < 0x40; i++) {
        destination->a[i] = source->a[i];
    }
    for (i = 0; i < 0x20; i++) {
        destination->b[i] = source->b[i];
    }
    for (i = 0; i < 0x10; i++) {
        destination->c[i] = source->c[i];
    }
    for (i = 0; i < 0x10; i++) {
        destination->d[i] = source->d[i];
    }
    destination->w0 = source->w0;
    destination->w1 = source->w1;
    destination->w2 = source->w2;
    destination->w3 = source->w3;
    destination->w4 = source->w4;
    destination->e0 = source->e0;
    destination->e1 = source->e1;
    destination->e2 = source->e2;
    destination->e3 = source->e3;
}
