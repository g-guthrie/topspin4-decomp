/* Swing_DLL.xex 0x88778558-0x887785DC, executable version 0.0.0.3. */
typedef unsigned int u32;

/* Parse a string of type letters (l/L = 1, b/B = 2, i/I = 4) into a flag mask; 7 when none are present. */
u32 ts4_parse_type_flags_88778558(const char *s)
{
    u32 r = 0;
    if (*s) do {
        switch ((unsigned char)*s) {
        case 'b': case 'B': r |= 2; break;
        case 'i': case 'I': r |= 4; break;
        case 'l': case 'L': r |= 1; break;
        }
    } while (*++s);
    if (r == 0) return 7;
    return r;
}
