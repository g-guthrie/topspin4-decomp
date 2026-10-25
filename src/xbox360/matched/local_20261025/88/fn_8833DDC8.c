typedef unsigned char u8;

extern void fn_8833D978(void *p);

void fn_8833DDC8(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8833D978(ptr);
}