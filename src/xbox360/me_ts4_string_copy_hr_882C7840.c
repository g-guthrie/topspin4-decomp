/* Swing_DLL.xex 0x882C7840: StringCchCopy-style: E_INVALIDARG (0x80070057) when cch > 0x7fffffff, otherwise strncpy (88563498), terminate at cch-1 and return 0x8007007A if strlen(src) >= cch.
 * /O1 (same as its neighbour 882C74C8). `(int)strlen(src)` gives the clrrwi; the subfc/addze mask is the ?: on the unsigned compare. */
unsigned int strlen(const char *s);
char *ts4_copy_bytes(char *dst, const char *src, unsigned int n); /* strncpy */

long fn_882C7840(char *dst, unsigned int cch, const char *src)
{
    long hr;
    if (cch > 0x7fffffff) {
        hr = 0x80070057;
    } else {
        ts4_copy_bytes(dst, src, cch);
        dst[cch - 1] = 0;
        hr = (unsigned int)(int)strlen(src) < cch ? 0 : 0x8007007A;
    }
    return hr;
}
