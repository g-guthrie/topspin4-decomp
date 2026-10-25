typedef unsigned char u8;

extern void fn_88340898(void *p);

void fn_883426C8(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88340898(ptr);
}