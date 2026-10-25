typedef unsigned char u8;

extern void fn_883703A8(void *p);

void fn_88371468(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883703A8(ptr);
}