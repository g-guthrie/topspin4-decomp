typedef unsigned char u8;

extern void fn_88349DB8(void *p);

void fn_88349EA8(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88349DB8(ptr);
}