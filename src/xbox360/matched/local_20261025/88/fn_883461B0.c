typedef unsigned char u8;

extern void fn_88345F68(void *p);

void fn_883461B0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88345F68(ptr);
}