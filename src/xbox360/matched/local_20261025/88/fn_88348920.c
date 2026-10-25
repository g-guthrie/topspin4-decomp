typedef unsigned char u8;

extern void fn_883486A8(void *p);

void fn_88348920(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883486A8(ptr);
}