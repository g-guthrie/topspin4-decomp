typedef unsigned char u8;

extern void fn_8833D338(void *p);

void fn_8833D7E8(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8833D338(ptr);
}