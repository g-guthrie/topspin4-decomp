/* 0x884C9700: Returns 1 if name starts with any string in the null-terminated table lbl_88C26064, comparing strlen(entry) bytes with fn_885630C0; else 0. */
/* Matched on /Oc (agAH). Indexed for loop over the table. */
extern const char *lbl_88C26064[];
extern unsigned int fn_88421338(const char *s);
extern int ts4_tailcall_fn_885630C0_88421118(const char *a, const char *b, unsigned int n);
int fn_884C9700(const char *name)
{
    int i;
    for (i = 0; lbl_88C26064[i] != 0; i++) {
        const char *p = lbl_88C26064[i];
        if (ts4_tailcall_fn_885630C0_88421118(name, p, fn_88421338(p)) == 0)
            return 1;
    }
    return 0;
}
