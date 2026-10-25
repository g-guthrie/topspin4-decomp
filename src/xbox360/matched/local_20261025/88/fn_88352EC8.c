typedef unsigned char u8;

extern void fn_883524E0(void *p);

void fn_88352EC8(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883524E0(ptr);
}