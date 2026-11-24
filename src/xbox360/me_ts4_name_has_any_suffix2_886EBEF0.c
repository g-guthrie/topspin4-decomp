/* Swing_DLL.xex 0x886EBEF0: returns 1 if the name ends with either of two suffixes (lbl_880D4488, lbl_880D3BA0) that are shorter than the name, using the counted compare 885630C0.
 * /Oc. Keep a result local and leave the loop with `result = 1; break;` (a direct `return 1` loses the r27 zero); the lengths are `(int)strlen` held unsigned. */
unsigned int strlen(const char *s);
int fn_885630C0(const char *a, const char *b, unsigned int n);
extern const char lbl_880D4488[];
extern const char lbl_880D3BA0[];

int fn_886EBEF0(const char *name)
{
    const char *suffixes[2];
    int result = 0;
    unsigned int len;
    unsigned int i;
    suffixes[0] = lbl_880D4488;
    suffixes[1] = lbl_880D3BA0;
    len = (int)strlen(name);
    for (i = 0; i < 2; ++i) {
        unsigned int n = (int)strlen(suffixes[i]);
        if (n < len && fn_885630C0(name + (len - n), suffixes[i], n) == 0) {
            result = 1;
            break;
        }
    }
    return result;
}
