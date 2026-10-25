typedef unsigned char u8;

extern void fn_883673F0(void *p);

void fn_883687D0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883673F0(ptr);
}