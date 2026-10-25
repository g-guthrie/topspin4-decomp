typedef unsigned char u8;

extern void fn_88343C80(void *p);

void fn_88343DB8(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88343C80(ptr);
}