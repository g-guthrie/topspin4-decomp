/* Swing_DLL.xex 0x886ED490: returns 1 if the name is longer than 4 characters and ends with the 4-character suffix lbl_880D3B5C (compared with 885630C0).
 * /Oc. A result local set to 0 first and to 1 on a match keeps the r31 zero; the length is `(int)strlen(name)` held unsigned. */
unsigned int strlen(const char *s);
int fn_885630C0(const char *a, const char *b, unsigned int n);
extern const char lbl_880D3B5C[];

int fn_886ED490(const char *name)
{
    int r = 0;
    unsigned int len = (int)strlen(name);
    if (len > 4 && fn_885630C0(name + len - 4, lbl_880D3B5C, 4) == 0)
        r = 1;
    return r;
}
