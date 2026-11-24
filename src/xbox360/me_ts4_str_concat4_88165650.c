/* Swing_DLL.xex 0x88165650: strcpy then three strcats into one buffer (intrinsics).
 * Leaf, no callees; matches /Oc. */
char *strcpy(char *, const char *);
char *strcat(char *, const char *);
#pragma intrinsic(strcpy, strcat)
void fn_88165650(char *dst, const char *a, const char *b, const char *c, const char *d)
{
    strcpy(dst, a);
    strcat(dst, b);
    strcat(dst, c);
    strcat(dst, d);
}
