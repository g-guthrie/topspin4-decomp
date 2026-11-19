/* Swing_DLL.xex 0x88582530: MultiByteToWideChar-style: code page 65001 goes to the UTF-8 converter 8858B388. Otherwise the source length is the given one, or strlen + 1 when it is -1; that length is returned when dst is 0 chars, else RtlMultiByteToUnicodeN converts (the NTSTATUS is mapped to a last error on failure). A too-small buffer sets error 0x7A and returns 0.
 * /O1 (CRT region). `(int)strlen(src) + 1` gives the clrrwi. */
unsigned int strlen(const char *s);
long RtlMultiByteToUnicodeN(unsigned short *dst, unsigned long dstBytes, unsigned long *outBytes, const char *src, unsigned long srcBytes);
unsigned long RtlNtStatusToDosError(long status);
void ts4_call_runtime_2610(unsigned long error); /* SetLastError */
int fn_8858B388(const char *src, int srcLen, unsigned short *dst, int dstLen);

int fn_88582530(unsigned int codePage, unsigned long flags, const char *src, int srcLen, unsigned short *dst, int dstLen)
{
    int n;
    long status;
    if (codePage == 65001)
        return fn_8858B388(src, srcLen, dst, dstLen);
    if (srcLen == -1)
        n = (int)strlen(src) + 1;
    else
        n = srcLen;
    if (dstLen == 0)
        return n;
    if (n < 0 || dstLen < n) {
        ts4_call_runtime_2610(0x7a);
    } else {
        status = RtlMultiByteToUnicodeN(dst, dstLen * 2, 0, src, n);
        if (status >= 0)
            return n;
        ts4_call_runtime_2610(RtlNtStatusToDosError(status));
    }
    return 0;
}
