typedef unsigned char u8;

extern void fn_883711D0(void *p);

void fn_88371498(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883711D0(ptr);
}