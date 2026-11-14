/* Swing_DLL.xex 0x88771768-0x8877D624, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_8860BBD8(void *);
extern void ts4_call_seq_lbl_880EFA80_88771440(void *);
extern char lbl_880C91A3[];
extern char lbl_880E3738[];
extern char lbl_880E3770[];
extern char lbl_880E4BA0[];
extern char lbl_880EF46C[];
extern char lbl_880EF6B8[];

void ts4_store_u8_8_and_forward_8877D610(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
