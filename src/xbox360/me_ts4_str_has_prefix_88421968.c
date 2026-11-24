/* 0x88421968: stores 1 to *out if the length-counted buffer s (len counts the terminator) begins with the C string p, else 0. */
/* Matched on /Oc (agAB). Result through an out byte; do/while guarded by *p. */
typedef struct S { char *buf; int len; } S;
void fn_88421968(unsigned char *out, S *s, const char *p)
{
    int i = 0;
    if (*p) {
        do {
            if (i >= s->len - 1 || s->buf[i] != p[i]) {
                *out = 0;
                return;
            }
            i++;
        } while (p[i]);
    }
    *out = 1;
}
