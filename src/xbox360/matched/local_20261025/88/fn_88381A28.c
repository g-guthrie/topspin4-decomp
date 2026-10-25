typedef unsigned char u8;

extern void fn_883814B8(void *p);

void fn_88381A28(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883814B8(ptr);
}