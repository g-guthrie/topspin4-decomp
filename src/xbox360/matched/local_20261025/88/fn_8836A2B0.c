typedef unsigned char u8;

extern void fn_88369EF8(void *p);

void fn_8836A2B0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88369EF8(ptr);
}