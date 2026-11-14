/* Swing_DLL.xex 0x889C5A28-0x889C5EC0, executable version 0.0.0.3. */
typedef void (*Ts4Callback)(void);

extern void ts4_assign_formatted_text(void *object, const char *text);
extern void ts4_destroy_owned_object(void *owned);
extern void fn_889124A8(
    void *owner, void *name, Ts4Callback callback, int a, int b, int c
);

extern char lbl_880D73AC[];
extern char lbl_880D73B4[];
extern char lbl_880D73BC[];
extern void ts4_loop_get_u32_off0_889C5788(void);
extern void ts4_if_call_seq_u32_off0_889C5900(void);
extern void ts4_loop_get_u32_off0_889C56E0(void);

/* Swing_DLL.xex 0x889C5A28. */
void ts4_register_three_callbacks_889C5A28(void *owner)
{
    void *name;

    ts4_assign_formatted_text(&name, lbl_880D73AC);
    fn_889124A8(owner, &name, ts4_loop_get_u32_off0_889C5788, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D73B4);
    fn_889124A8(owner, &name, ts4_if_call_seq_u32_off0_889C5900, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D73BC);
    fn_889124A8(owner, &name, ts4_loop_get_u32_off0_889C56E0, 0, 0, 0);
    ts4_destroy_owned_object(name);
}

extern char lbl_880D733C[];
extern char lbl_880D7354[];
extern char lbl_880D736C[];
extern void fn_889C5CA0(void);
extern void ts4_if_get_u32_lbl_88D45910_889C5B80(void);
extern void ts4_call_seq_fn_888F70A0_889C5D90(void);

/* Swing_DLL.xex 0x889C5DF0. */
void ts4_register_three_callbacks_889C5DF0(void *owner)
{
    void *name;

    ts4_assign_formatted_text(&name, lbl_880D733C);
    fn_889124A8(owner, &name, fn_889C5CA0, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D7354);
    fn_889124A8(owner, &name, ts4_if_get_u32_lbl_88D45910_889C5B80, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D736C);
    fn_889124A8(owner, &name, ts4_call_seq_fn_888F70A0_889C5D90, 0, 0, 0);
    ts4_destroy_owned_object(name);
}
