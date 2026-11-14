/* Family LG1: script callback table (region 0x889C49F8). Calls fn_8861D188(owner + 0x20, 0x8000, 4), then
 * registers 15 named callbacks with fn_889124A8; the name is a temporary text object built by
 * ts4_assign_formatted_text and released with ts4_destroy_owned_object (same pattern as
 * src/xbox360/d1_big4_register_callbacks.c). */
typedef void (*lg1_callback)(void);

extern void fn_8861D188(void *field, int a, int b);
extern void ts4_assign_formatted_text(void *object, const char *text);
extern void ts4_destroy_owned_object(void *owned);
extern void fn_889124A8(void *owner, void *name, lg1_callback callback, int a, int b, int c);
extern char lbl_880D7428[];
extern char lbl_880D7438[];
extern char lbl_880D744C[];
extern char lbl_880D7460[];
extern char lbl_880D7474[];
extern char lbl_880D748C[];
extern char lbl_880D74A4[];
extern char lbl_880D74B8[];
extern char lbl_880D74CC[];
extern char lbl_880D74E0[];
extern char lbl_880D74F4[];
extern char lbl_880D7510[];
extern char lbl_880D7530[];
extern char lbl_880D7538[];
extern char lbl_880D7540[];
extern void fn_889C2B10(void);
extern void fn_889C2BE0(void);
extern void fn_889C2ED8(void);
extern void fn_889C3198(void);
extern void fn_889C3680(void);
extern void fn_889C3870(void);
extern void fn_889C3AB8(void);
extern void fn_889C3D60(void);
extern void fn_889C3ED8(void);
extern void fn_889C4170(void);
extern void fn_889C4440(void);
extern void fn_889C49F8(void);
extern void fn_889C4DA0(void);
extern void fn_889C4F28(void);
extern void ts4_call_seq_fn_889C63A0_889C49A8(void);

/* Register the 15 script callbacks of this object. Swing_DLL.xex 0x889C5018 */
void ts4_register_script_callbacks_889C5018(void *owner)
{
    void *name;

    fn_8861D188((char *)owner + 0x20, 0x8000, 4);
    ts4_assign_formatted_text(&name, lbl_880D7428);
    fn_889124A8(owner, &name, fn_889C4F28, 1, 1, 13);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D7438);
    fn_889124A8(owner, &name, fn_889C4440, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D744C);
    fn_889124A8(owner, &name, fn_889C4170, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D7460);
    fn_889124A8(owner, &name, fn_889C3ED8, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D7474);
    fn_889124A8(owner, &name, fn_889C3D60, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D748C);
    fn_889124A8(owner, &name, fn_889C3AB8, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D74A4);
    fn_889124A8(owner, &name, fn_889C3870, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D74B8);
    fn_889124A8(owner, &name, fn_889C4DA0, 1, 1, 13);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D74CC);
    fn_889124A8(owner, &name, fn_889C49F8, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D74E0);
    fn_889124A8(owner, &name, fn_889C3198, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D74F4);
    fn_889124A8(owner, &name, fn_889C2ED8, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D7510);
    fn_889124A8(owner, &name, fn_889C2BE0, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D7530);
    fn_889124A8(owner, &name, fn_889C3680, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D7538);
    fn_889124A8(owner, &name, ts4_call_seq_fn_889C63A0_889C49A8, 0, 0, 0);
    ts4_destroy_owned_object(name);
    ts4_assign_formatted_text(&name, lbl_880D7540);
    fn_889124A8(owner, &name, fn_889C2B10, 0, 0, 0);
    ts4_destroy_owned_object(name);
}
