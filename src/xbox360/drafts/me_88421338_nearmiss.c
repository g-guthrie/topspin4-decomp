/* 0x88421338: returns the length of the NUL-terminated string s. */
/* Near-miss on /Oc (agAB): 3 instructions off at +0x18. The target ends with subi r11; clrrwi r3,r11,0 (a late-forwarded copy); this source computes straight into r3. */
unsigned int fn_88421338(const char *s)
{
    const char *p = s;
    while (*p++)
        ;
    return (unsigned int)(p - s - 1);
}
