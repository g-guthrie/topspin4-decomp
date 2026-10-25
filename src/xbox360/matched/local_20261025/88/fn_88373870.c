typedef unsigned char u8;

extern void fn_883714C8(void *p);

void fn_88373870(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883714C8(ptr);
}