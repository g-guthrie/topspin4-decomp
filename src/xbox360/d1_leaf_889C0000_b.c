/* Swing_DLL.xex 0x889C09C8-0x889C92A4, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881B9148(void *);
extern void fn_889122D8(void *);
extern void fn_889BE668(void *);
extern void ts4_if_call_seq_fn_889BD910_889BFAB8(void *);
extern void ts4_if_call_seq_fn_889BD910_889BFB60(void *);
extern void ts4_if_call_seq_fn_889BD910_889BFBD0(void *);
extern void fn_889BFC40(void *);
extern void fn_889BFDA8(void *);
extern void fn_889C0298(void *);
extern void ts4_if_call_seq_fn_889BD910_889C0778(void *);
extern void ts4_finish_889C0878(void *);
extern void fn_889C8148(void *);

void ts4_store_u8_8_and_forward_889C7E80(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
