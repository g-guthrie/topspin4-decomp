/* Swing_DLL.xex 0x885ED9B8-0x885EDA9C, executable version 0.0.0.3. */

extern void ts4_forward_88421460(void *destination, int value, unsigned int size);
extern void ts4_field_8_vcall_10_8841D460(void *sink, const void *data, unsigned int size);

int ts4_write_tga_885ED9B8(unsigned char *pixels, void *sink, int width, int height)
{
    unsigned char header[0x12];
    int row;

    ts4_forward_88421460(header, 0, 0x12);
    header[2] = 2;
    *(unsigned short *)(header + 0xE) = (unsigned short)(((height >> 8) & 0xFF) | ((height & 0xFF) << 8));
    *(unsigned short *)(header + 0xC) = (unsigned short)(((width >> 8) & 0xFF) | ((width & 0xFF) << 8));
    for (row = 0; row < height; row++) {
        int column;

        for (column = 0; column < width; column++) {
            unsigned char *pixel = pixels + (row * width + column) * 4;
            unsigned char b0 = pixel[0];
            unsigned char b1 = pixel[1];
            unsigned char b2 = pixel[2];
            unsigned char b3 = pixel[3];

            pixel[0] = b3;
            pixel[1] = b2;
            pixel[2] = b1;
            pixel[3] = b0;
        }
    }
    header[0x10] = 0x20;
    ts4_field_8_vcall_10_8841D460(sink, header, 0x12);
    ts4_field_8_vcall_10_8841D460(sink, pixels, width * height * 4);
    return 1;
}
