/* Swing_DLL.xex 0x88418500-0x8841AA98, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern char lbl_8803A310[];
extern char lbl_8803C474[];

void ts4_init_if_set_u16_6_table_0_8841AA78(char *object)
{
    if (object != 0) {
        *(unsigned short *)(object + 0x6) = 1;
        *(char **)(object) = lbl_8803A310;
    }
}
