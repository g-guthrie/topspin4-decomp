typedef unsigned char u8;

extern void fn_8836F9C8(void *p);

void fn_88370310(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8836F9C8(ptr);
}