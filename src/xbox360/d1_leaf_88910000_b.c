/* Swing_DLL.xex 0x88912DB0-0x8891B100, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_8860BBD8(void *);
extern void fn_88617D28(void *);
extern void fn_88918EA8(void *);
extern void fn_8893B3E0(void *);
extern char lbl_880CF0C7[];
extern char lbl_880CFC4E[];
extern char lbl_880D2CF8[];
extern char lbl_880D6B70[];
extern char lbl_880D6BC0[];
extern char lbl_880D7030[];
extern char lbl_880D7228[];

void ts4_store_u8_8_and_forward_88912F80(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
