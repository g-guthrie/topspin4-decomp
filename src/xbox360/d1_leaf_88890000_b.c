/* Swing_DLL.xex 0x88890078-0x8889514C, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_88617D28(void *);
extern void fn_88892AD0(void *);
extern char lbl_880CF238[];
extern char lbl_880DCE14[];

void ts4_store_u8_8_and_forward_88890078(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
