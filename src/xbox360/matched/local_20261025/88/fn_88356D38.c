typedef unsigned char u8;

extern void fn_88356BD8(void *p);

void fn_88356D38(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88356BD8(ptr);
}