typedef unsigned char u8;

extern void fn_8833EBD0(void *p);

void fn_8833EC60(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8833EBD0(ptr);
}