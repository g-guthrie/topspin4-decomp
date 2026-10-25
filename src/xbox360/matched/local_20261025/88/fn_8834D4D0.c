typedef unsigned char u8;

extern void fn_8834C9F8(void *p);

void fn_8834D4D0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8834C9F8(ptr);
}