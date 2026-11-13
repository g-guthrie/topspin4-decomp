/* Swing_DLL.xex 0x88644700-0x8864F774, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_88617D28(void *);
extern void ts4_call_seq_u32_lbl_88D45B20_886496F0(void *);
extern void fn_889BD910(void *, int);
extern char lbl_880C88D9[];
extern char lbl_880C88DA[];
extern char lbl_880D6B70[];
extern char lbl_880F58D8[];
extern char lbl_880F6024[];
extern char lbl_88D49304[];

void ts4_store_u8_8_and_forward_8864F760(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
