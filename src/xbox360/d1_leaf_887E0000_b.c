/* Swing_DLL.xex 0x887E95F0-0x887EB6EC, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_8860BBD8(void *);
extern char lbl_880E4BA0[];

void ts4_store_u8_8_and_forward_887EB3E8(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}

void ts4_store_u8_8_and_forward_887EB6D8(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
