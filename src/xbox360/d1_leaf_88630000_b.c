/* Swing_DLL.xex 0x886386A8-0x88639B88, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_8861B4D8(void *);
extern void fn_88638FC8(void *);
extern char lbl_880F62F0[];
extern char lbl_880F6400[];

void ts4_store_u8_8_and_forward_886386A8(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
