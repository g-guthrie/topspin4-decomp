/* Swing_DLL.xex 0x8876D080-0x8876E71C, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern char lbl_880D6B70[];

void ts4_store_u8_8_and_forward_8876E708(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
