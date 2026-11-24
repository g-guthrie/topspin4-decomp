/* Swing_DLL.xex 0x8883AA38: builds literal lbl_880E1054 plus an optional suffix in a 124-byte buffer, interns it (88608590) and sends it to service 0xE2AE8939 through 88611620.
 * /Oc. Same body as the cx23 CX23_NAME_THEN_SEND macro, except the strlen is written `124 - (int)strlen(buf)` (the clrrwi). */
unsigned int strlen(const char *s);
char *ts4_crt_strncat_88564EF0(char *dst, const char *src, unsigned int count);
int ts4_crc32_cstr_seed_88608590(int, const char *);
void *ts4_find_service(unsigned int hash);
void *fn_88611620(void *svc, int name);
extern char lbl_880E1054[];

void fn_8883AA38(const char *suffix)
{
    char buf[124];
    const char *s = lbl_880E1054;
    char *d = buf;
    void *svc;
    while (d != buf + 124) {
        char c = *s;
        if (!c)
            break;
        *d = c;
        d++;
        s++;
    }
    *d = 0;
    if (suffix)
        ts4_crt_strncat_88564EF0(buf, suffix, 124 - (int)strlen(buf));
    svc = ts4_find_service(0xE2AE8939);
    fn_88611620(svc, ts4_crc32_cstr_seed_88608590(0, buf));
}
