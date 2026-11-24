/* Swing_DLL.xex 0x889C5600-0x889C5660, executable version 0.0.0.3. */

extern void ts4_assign_formatted_text(void *, char *);
extern void fn_889124A8(void *, void *, void *, int, int, int);
extern void fn_889C5550(void);
extern void ts4_destroy_owned_object(void *);
extern char lbl_880D73F0[];

void ts4_register_889C5600(void *self)
{
    void *text[2];
    ts4_assign_formatted_text(text, lbl_880D73F0);
    fn_889124A8(self, text, fn_889C5550, 0, 0, 0);
    ts4_destroy_owned_object(text[0]);
}
