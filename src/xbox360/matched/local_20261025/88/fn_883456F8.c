typedef unsigned char u8;

extern void fn_88345508(void *p);

void fn_883456F8(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88345508(ptr);
}