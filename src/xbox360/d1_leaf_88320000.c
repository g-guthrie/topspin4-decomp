/* Swing_DLL.xex 0x88320040-0x8832CC34, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_8831A7F0(void *);
extern void ts4_fn_883E63B8(void *);

int ts4_set_u8_232_return_0_8832CC28(char *object, unsigned char value)
{
    *(unsigned char *)(object + 0x232) = value;
    return 0;
}
