typedef unsigned char u8;

extern void fn_883476D8(void *p);

void fn_883488F0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883476D8(ptr);
}