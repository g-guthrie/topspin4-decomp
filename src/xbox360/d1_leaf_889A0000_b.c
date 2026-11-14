/* Swing_DLL.xex 0x889A0430-0x889AF7D8, executable version 0.0.0.3.
 * Small leaf functions whose instructions are a single idiom; the names
 * describe that behaviour and end in the function address. */

extern void fn_881512B8(void *);
extern void fn_881B9148(void *);
extern void fn_88617D28(void *);
extern void fn_889988E0(void *);
extern void ts4_get_u32_off0_8899AD88(void *);
extern void fn_8899FAE8(void *);
extern void ts4_session_event_post_8899FE40(void *);
extern void ts4_get_u32_g_ts4_session_context_889A01E8(void *);
extern void fn_889AC440(void *);
extern void fn_889AC4B0(void *);
extern char lbl_880D24B8[];
extern char lbl_880D24E0[];

void ts4_store_u8_8_and_forward_889A0C80(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}

void ts4_store_u8_8_and_forward_889A2690(char *object)
{
    *(unsigned char *)(object + 0x8) = 0;
    fn_881B9148(object + 0x10);
}
