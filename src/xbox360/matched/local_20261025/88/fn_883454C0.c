typedef unsigned char u8;

extern void fn_88344D28(void *p);

void fn_883454C0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88344D28(ptr);
}