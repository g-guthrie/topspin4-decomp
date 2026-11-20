/* Swing_DLL.xex 0x8827DAE8: copies the 512-byte name at +0x40 into out (strncpy 88563498), terminates it at 511, then strncat()s the suffix into the space that is left.
 * /Oc. `511 - (int)strlen(out)` gives the clrrwi + subfic. */
typedef struct NameSource { char pad[0x40]; char name[0x200]; } NameSource;
unsigned int strlen(const char *s);
char *ts4_copy_bytes(char *dst, const char *src, unsigned int n); /* strncpy */
char *ts4_crt_strncat_88564EF0(char *dst, const char *src, unsigned int n);

void fn_8827DAE8(const NameSource *src, char *out, const char *suffix)
{
    ts4_copy_bytes(out, src->name, sizeof(src->name));
    out[sizeof(src->name) - 1] = 0;
    ts4_crt_strncat_88564EF0(out, suffix, sizeof(src->name) - 1 - (int)strlen(out));
}
