/* CX50: front-end callback registration, Swing_DLL.xex 0x889C60A0. */
typedef void (*Ts4Callback)(void);

extern void ts4_assign_formatted_text(void *object, const char *text);
extern void ts4_destroy_owned_object(void *owned);
extern void fn_889124A8(void *owner, void *name, Ts4Callback callback, int a, int b, int c);

extern char lbl_880D72D0[];
extern char lbl_880D72EC[];
extern void fn_889C5FF8(void);
extern void ts4_fn_889C5F00(void);

/* 0x889C60A0 */
void ts4_cx50_register_two_889C60A0(void *owner)
{
    void *name;

    ts4_assign_formatted_text(&name, lbl_880D72D0);
    fn_889124A8(owner, &name, fn_889C5FF8, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D72EC);
    fn_889124A8(owner, &name, ts4_fn_889C5F00, 0, 0, 0);
    ts4_destroy_owned_object(name);
}
