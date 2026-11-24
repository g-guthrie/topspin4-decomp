/* Swing_DLL.xex 0x883C7068-0x883CF0C8, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

unsigned int ts4_get_bits_60_f_1_883C7068(const char *object)
{
    return (*(const unsigned int *)(object + 0x60) >> 17) & 0x1u;
}
