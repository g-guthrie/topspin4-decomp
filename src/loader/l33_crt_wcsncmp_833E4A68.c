/* Loader_DLL.xex 0x833E4A68-0x833E4AB8, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: wcsncmp. */
typedef unsigned long ts4l_u32;

int ts4l_crt_wcsncmp_833E4A68(const unsigned short *first, const unsigned short *last, ts4l_u32 count)
{
    if (!count)
        return 0;
    while (--count && *first && *first == *last) {
        first++;
        last++;
    }
    return (int)(*first - *last);
}
