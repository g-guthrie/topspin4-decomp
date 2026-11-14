/* Swing_DLL.xex 0x88883EE0-0x88887AD8, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_88568CB0(void *, int);
extern void fn_88617D28(void *);
extern char lbl_880D6B70[];
extern char lbl_880DF1F8[];
extern char lbl_880DF40C[];
extern char lbl_880F799C[];

void ts4_forward_with_180_888842E0(void *object)
{
    fn_88568CB0(object, 384);
}

void ts4_store_u8_8_and_forward_88886678(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}

void ts4_store_u8_8_and_forward_888869F8(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
