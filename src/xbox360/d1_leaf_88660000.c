/* Swing_DLL.xex 0x886602E8-0x8866DD74, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_88668650(void *);
extern void fn_88668D70(void *);
extern void fn_88668DF8(void *);
extern void fn_8890DDA8(void *);

unsigned int ts4_get_u32_5bc_886602E8(const char *object)
{
    return *(const unsigned int *)(object + 0x5bc);
}

void ts4_store_u32_90_m1_88660CD0(char *object)
{
    *(unsigned int *)(object + 0x90) = -1;
}

void ts4_forward_adjusted_4_88662F08(char *object)
{
    fn_8890DDA8(object + 0x4);
}

void ts4_store_u8_2c_0_886631F8(char *object)
{
    *(unsigned char *)(object + 0x2c) = 0;
}
