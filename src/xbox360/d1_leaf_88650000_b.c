/* Swing_DLL.xex 0x88657AC8-0x8865ABE8, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_8860BBD8(void *);
extern char lbl_880D19F0[];
extern char lbl_880D6B70[];
extern char lbl_880F3784[];
extern char lbl_880F436C[];
extern char lbl_880F43E0[];
extern char lbl_880F4508[];
extern char lbl_880F45D0[];
extern char lbl_880F4640[];
extern char lbl_880F48B8[];
extern char lbl_880F4E18[];

void ts4_store_u8_8_and_forward_88657AC8(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
