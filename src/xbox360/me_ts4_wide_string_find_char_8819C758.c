/* 0x8819C758: Returns the index of the first u16 char c at or after start in a counted wide string (length in the 12-byte header before the chars), or -1 if start is past the length or c is absent. */
/* Matched on /Oc (agAH). Search loop written inline (while (*s && *s != c)) followed by a separate *s != c test. */
typedef struct WideString { unsigned short *chars; } WideString;
typedef struct WideStringHeader { int length; int capacity; int refs; } WideStringHeader;
int fn_8819C758(WideString *str, unsigned short c, int start)
{
    unsigned short *s;
    if (start >= ((WideStringHeader *)str->chars)[-1].length)
        return -1;
    s = str->chars + start;
    while (*s != 0 && *s != c)
        s++;
    if (*s != c)
        return -1;
    return s - str->chars;
}
