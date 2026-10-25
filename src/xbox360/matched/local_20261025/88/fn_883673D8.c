typedef unsigned char u8;

extern void fn_88367020(void *p);

void fn_883673D8(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88367020(ptr);
}