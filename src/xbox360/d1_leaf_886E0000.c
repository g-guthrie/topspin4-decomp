/* Swing_DLL.xex 0x886E1D88-0x886EED2C, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_886E1850(void *);
extern void ts4_object_finalize(void *);

int ts4_return_3_886E62B0(void)
{
    return 3;
}

void ts4_set_u32_78_886E6348(char *object, unsigned int value)
{
    *(unsigned int *)(object + 0x78) = value;
}

void ts4_set_u32_7c_886E6350(char *object, unsigned int value)
{
    *(unsigned int *)(object + 0x7c) = value;
}

void ts4_set_u32_80_886E6358(char *object, unsigned int value)
{
    *(unsigned int *)(object + 0x80) = value;
}

void ts4_set_u32_84_886E6360(char *object, unsigned int value)
{
    *(unsigned int *)(object + 0x84) = value;
}

void ts4_store_u32_1c_0_886E6368(char *object)
{
    *(unsigned int *)(object + 0x1c) = 0;
}

void ts4_store_u32_1c_0_886E6378(char *object)
{
    *(unsigned int *)(object + 0x1c) = 0;
}
