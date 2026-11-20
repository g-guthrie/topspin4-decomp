/* Swing_DLL.xex 0x887C7DA0-0x887CC040, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_88617D28(void *);
extern void fn_887EB6F0(void *);
extern char lbl_880EA318[];
extern char lbl_880EA60C[];

void ts4_store_u8_8_and_forward_887C7DA0(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}

void ts4_store_u8_8_and_forward_887CBC58(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}

void ts4_store_u8_8_and_forward_887CC018(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
