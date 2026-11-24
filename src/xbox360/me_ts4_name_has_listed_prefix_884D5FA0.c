/* 0x884D5FA0: Same as 884C9700 using the table lbl_88C263F8. */
/* Matched on /Oc (agAH). Sibling of 884C9700. */
extern const char *lbl_88C263F8[];
extern unsigned int fn_88421338(const char *s);
extern int ts4_tailcall_fn_885630C0_88421118(const char *a, const char *b, unsigned int n);
int fn_884D5FA0(const char *name)
{
    int i;
    for (i = 0; lbl_88C263F8[i] != 0; i++) {
        const char *p = lbl_88C263F8[i];
        if (ts4_tailcall_fn_885630C0_88421118(name, p, fn_88421338(p)) == 0)
            return 1;
    }
    return 0;
}
