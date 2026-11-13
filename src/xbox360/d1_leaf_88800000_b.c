/* Swing_DLL.xex 0x88800748-0x88804BE8, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_8860BBD8(void *);
extern void fn_88617D28(void *);
extern void fn_88804AB8(void *);
extern char lbl_880E3738[];
extern char lbl_880E3770[];
extern char lbl_880E37D8[];
extern char lbl_880E3838[];
extern char lbl_880E39F0[];
extern char lbl_880E3A8C[];

void ts4_store_u8_8_and_forward_888032D0(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}

void ts4_store_u8_8_and_forward_88803420(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
