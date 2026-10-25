typedef unsigned char u8;

extern void fn_88350C38(void *p);

void fn_88351508(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88350C38(ptr);
}