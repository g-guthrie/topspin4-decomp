typedef unsigned char u8;

extern void fn_88371270(void *p);

void fn_883714B0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88371270(ptr);
}