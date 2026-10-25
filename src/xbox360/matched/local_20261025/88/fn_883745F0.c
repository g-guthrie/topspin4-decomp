typedef unsigned char u8;

extern void fn_88374510(void *p);

void fn_883745F0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88374510(ptr);
}