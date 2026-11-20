/* Swing_DLL.xex 0x88991220-0x8899F268, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_888860A0(void *);
extern void fn_88934458(void *);
extern void fn_88935DF8(void *);
extern void fn_88937648(void *);
extern void fn_8893B3E0(void *);
extern void fn_8893D2A0(void *);
extern void fn_8893EFD8(void *);
extern void fn_8898FE30(void *);
extern void fn_8898FEB0(void *);
extern void ts4_call_seq_lbl_880D2570_8899A0D8(void *);
extern void fn_8899A158(void *);
extern void fn_8899A270(void *);
extern char lbl_880D052A[];
extern char lbl_880D052B[];
extern char lbl_880D19F0[];
extern char lbl_880D1F18[];
extern char lbl_880D2A68[];
extern char lbl_880D2CF8[];
extern char lbl_880D2D10[];
extern char lbl_880D2E4C[];
extern char lbl_880D5B34[];
extern char lbl_880D5C10[];
extern void ts4_clear_intrusive_list(void *);

void ts4_store_u8_8_and_forward_88998988(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
