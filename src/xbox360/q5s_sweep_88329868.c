/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x88329868: case-insensitive ASCII string compare (A-Z folded to lower case); returns the difference of the first
 * mismatching folded chars.
 * Source: drafts/me_88329868_nearmiss.c (Q5S sweep, 2026-11-24); see work/specs/Q5S/sweep_88329868.json for route and flags. */
static __forceinline char ToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 0x20;
    return c;
}
int ts4_stricmp_ascii_88329868(const char *a, const char *b)
{
    char ca, cb;
    do {
        ca = ToLower(*a++);
        cb = ToLower(*b++);
    } while (ca != 0 && ca == cb);
    return ca - cb;
}
