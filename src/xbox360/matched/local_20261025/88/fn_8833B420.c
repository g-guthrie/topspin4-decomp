typedef unsigned char u8;

extern void fn_8833A628(void *p);

void fn_8833B420(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8833A628(ptr);
}