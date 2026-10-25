typedef unsigned char u8;

extern void fn_88366EA8(void *p);

void fn_88366F88(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88366EA8(ptr);
}