typedef unsigned char u8;

extern void fn_883438A0(void *p);

void fn_88343D88(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883438A0(ptr);
}