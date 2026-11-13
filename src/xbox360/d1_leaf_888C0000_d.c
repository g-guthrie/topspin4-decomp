/* Swing_DLL.xex 0x888C0388-0x888C7970, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);

void ts4_store_u8_21_8_and_forward_10_888C7958(char *object)
{
    *(unsigned char *)(object + 0x21) = 0;
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
