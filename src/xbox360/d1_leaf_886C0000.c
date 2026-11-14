/* Swing_DLL.xex 0x886C3420-0x886CDFD8, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_886C71C8(void *);
extern void ts4_data_condition_eval_886C9F08(void *);
extern void fn_886CB3A8(void *);
extern void ts4_object_finalize(void *);

void ts4_forward_adjusted_30_886CDFD0(char *object)
{
    fn_886CB3A8(object + 0x30);
}
