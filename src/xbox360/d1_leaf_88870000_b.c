/* Swing_DLL.xex 0x88871C90-0x8887EA74, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_88617D28(void *);
extern void fn_8861B4D8(void *);
extern void fn_8887E558(void *);
extern char lbl_880C9D1A[];
extern char lbl_880C9D1B[];
extern char lbl_880DF8D8[];
extern char lbl_880DF9D0[];

void ts4_store_u8_8_and_forward_88871C90(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}

void ts4_store_u8_8_and_forward_8887CB28(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}

void ts4_forward_global_8887EA58(void)
{
    fn_8887E558(lbl_880C9D1B);
}

void ts4_forward_global_8887EA68(void)
{
    fn_8887E558(lbl_880C9D1A);
}
