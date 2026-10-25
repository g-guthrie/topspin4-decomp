typedef unsigned char u8;

extern void fn_883810C8(void *p);

void fn_883818A0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883810C8(ptr);
}