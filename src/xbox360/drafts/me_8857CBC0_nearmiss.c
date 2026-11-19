/* Swing_DLL.xex 0x8857CBC0: wildcard name match (near miss, 3 off under /O1).
 * Remaining diff: the target emits mr r29,r5 before the stw r6 param home; ours after it.
 * The s/n register copies of the address-taken params are what give r29/r28 and no reload after tolower. */
typedef unsigned int ts4_size_t;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)

extern int ts4_consume_to_delimiter(char **cursor, ts4_size_t *remaining, char delimiter);
extern int ts4_if_fn_88567730(int c); /* tolower */

/* Match a name against a pattern where '*' must be followed by '.' and skips to the next '.', and '?' matches any one character. */
int fn_8857CBC0(const char *pattern, ts4_size_t patternLen, char *name, ts4_size_t nameLen)
{
    const char *end;
    ts4_size_t n = nameLen;
    char *s = name;
    if (patternLen == 0)
        patternLen = (int)strlen(pattern);
    end = pattern + patternLen;
    while (pattern < end) {
        char c = *pattern++;
        if (c == '*') {
            if (pattern == end)
                return 1;
            if (*pattern++ != '.')
                return 0;
            if (!ts4_consume_to_delimiter(&name, &nameLen, '.'))
                return 0;
            n = nameLen;
            s = name;
        } else {
            char ch;
            if (n == 0)
                return 0;
            ch = *s++;
            n--;
            name = s;
            nameLen = n;
            if (c != '?' && ts4_if_fn_88567730(ch) != ts4_if_fn_88567730(c))
                return 0;
        }
    }
    return n == 0;
}
