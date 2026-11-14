/* Loader_DLL.xex 0x830A02A8-0x830A0300, executable version 0.0.0.3.
 * Field-address and field-load helpers. */

char *ts4l_field_address_2af0_830A02A8(char *object)
{
    return object + 0x2af0;
}

char *ts4l_field_address_4_830A02F0(char *object)
{
    return object + 0x4;
}

unsigned int ts4l_get_u32_8b4_830A02F8(const char *object)
{
    return *(const unsigned int *)(object + 0x8b4);
}
