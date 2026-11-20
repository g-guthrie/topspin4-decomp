/* Swing_DLL.xex 0x88421338: int length of a C string (strlen intrinsic).
 * /Oc. Write it as `(int)strlen(s)` with `unsigned int strlen(const char *)` declared: the int conversion gives the trailing clrrwi. */
unsigned int strlen(const char *s);

int fn_88421338(const char *s)
{
    return (int)strlen(s);
}
