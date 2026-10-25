typedef unsigned char u8;

extern void fn_88345298(void *p);

void fn_883454F0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88345298(ptr);
}