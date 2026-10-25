typedef unsigned char u8;

extern void fn_88381620(void *p);

void fn_88381A40(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88381620(ptr);
}