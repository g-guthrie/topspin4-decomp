/* Swing_DLL.xex 0x88564EF0-0x88564F40, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: strncat. */
typedef unsigned int u32;

char *ts4_crt_strncat_88564EF0(char *front, const char *back, u32 count)
{
    char *start = front;
    while (*front++)
        ;
    front--;
    while (count--)
        if (!(*front++ = *back++))
            return start;
    *front = 0;
    return start;
}
