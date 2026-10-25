typedef unsigned char u8;

extern void fn_88369D80(void *p);

void fn_88369E60(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88369D80(ptr);
}