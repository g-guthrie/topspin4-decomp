/* Swing_DLL.xex 0x887F21D8-0x887FC29C, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_887F4698(void *);
extern void fn_887F4E30(void *);
extern void fn_887FB3B0(void *);
extern char lbl_880C963A[];
extern char lbl_880C963B[];
extern char lbl_880E4528[];
extern char lbl_880E46C8[];

void ts4_store_u8_8_and_forward_887F21D8(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
