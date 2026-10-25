typedef unsigned char u8;

extern void fn_88354BE8(void *p);

void fn_88354F28(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88354BE8(ptr);
}