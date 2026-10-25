typedef unsigned char u8;

extern void fn_883472D8(void *p);

void fn_88347558(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883472D8(ptr);
}