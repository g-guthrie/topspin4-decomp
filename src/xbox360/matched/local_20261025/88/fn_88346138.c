typedef unsigned char u8;

extern void fn_883457F0(void *p);

void fn_88346138(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883457F0(ptr);
}