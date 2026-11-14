/* Swing_DLL.xex 0x883006A8-0x8830D2CC, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void ts4_jpeg_h2v2_downsample_883000A0(void *);
extern void fn_88309E28(void *);

int ts4_set_u8_663c_return_0_8830BD28(char *object, unsigned char value)
{
    *(unsigned char *)(object + 0x663c) = value;
    return 0;
}
