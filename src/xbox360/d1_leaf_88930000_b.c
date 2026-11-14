/* Swing_DLL.xex 0x88930F40-0x8893E27C, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_8893CBE0(void *);
extern char lbl_880CFF37[];
extern char lbl_880D050B[];
extern char lbl_880D19F0[];
extern char lbl_880D5A64[];
extern char lbl_880D5AD8[];
extern char lbl_880D5B34[];
extern char lbl_880D5C10[];
extern void ts4_noop_889330D0(void *);

void ts4_store_u8_8_and_forward_88934F20(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
