typedef unsigned char u8;

extern void fn_883434E8(void *p);

void fn_88343620(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883434E8(ptr);
}