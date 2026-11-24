/* 0x88421708: index of ch in buf[start..min(len-1, end)), or -1 (len counts the terminator) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct { char *buf; int len; } Str;
int ts4_str_find_char_88421708(Str *s, char ch, int start, int end)
{
    int i;
    for (i = start; i < s->len - 1 && i < end; i++)
        if (s->buf[i] == ch) return i;
    return -1;
}
