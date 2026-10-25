typedef unsigned char u8;

extern void fn_8833DA00(void *p);

void fn_8833DDE0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8833DA00(ptr);
}