/* 0x88329868: Case-insensitive ASCII string compare (A-Z folded to lower case); returns the difference of the first mismatching folded chars. */
/* Near miss (agAH): All instructions identical; the target loop branch back to the function entry carries a REL14 self-relocation that the plain compile does not emit (the checker counts it as 1 off). */
static __forceinline char ToLower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 0x20;
    return c;
}
int fn_88329868(const char *a, const char *b)
{
    char ca, cb;
    do {
        ca = ToLower(*a++);
        cb = ToLower(*b++);
    } while (ca != 0 && ca == cb);
    return ca - cb;
}
