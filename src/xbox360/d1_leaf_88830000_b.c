/* Swing_DLL.xex 0x888382B8-0x8883D798, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_8860BBD8(void *);
extern void fn_88617D28(void *);
extern char lbl_880E165C[];
extern char lbl_880E1674[];
extern char lbl_880E16AC[];
extern char lbl_880E3738[];

void ts4_store_u8_8_and_forward_8883C298(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
