/* Swing_DLL.xex 0x884DADB0-0x884DADF8, executable version 0.0.0.3. */
extern char *fn_884DADB0(char *s);
static char ts4_is_space(char c)
{
    if (c == ' ' || c == '\t' || c == '\n' || c == '\r') {
        return 1;
    }
    return 0;
}
char *ts4_skip_space_884DADB0(char *s)
{
    if (ts4_is_space(*s)) {
        return fn_884DADB0(s + 1);
    }
    return s;
}
