/* Swing_DLL.xex 0x886D48C8-0x886D9958, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_886D0E20(void *);

void ts4_store_u32_160_and_forward_30_886D48C8(char *object)
{
    *(unsigned int *)(object + 0x160) = 0;
    fn_886D0E20(object + 0x30);
}

void ts4_store_u32_0_4_8_2c_30_34_0_886D9938(char *object)
{
    *(unsigned int *)(object) = 0;
    *(unsigned int *)(object + 0x4) = 0;
    *(unsigned int *)(object + 0x8) = 0;
    *(unsigned int *)(object + 0x2c) = 0;
    *(unsigned int *)(object + 0x30) = 0;
    *(unsigned int *)(object + 0x34) = 0;
}
