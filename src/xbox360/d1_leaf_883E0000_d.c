/* Swing_DLL.xex 0x883E0778-0x883EE670, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

unsigned int ts4_get_bits_0_1c_7_883E0778(const char *object)
{
    return (*(const unsigned int *)(object) >> 4) & 0x7u;
}

unsigned int ts4_get_bits_24_1b_1_883E1880(const char *object)
{
    return (*(const unsigned int *)(object + 0x24) >> 5) & 0x1u;
}
