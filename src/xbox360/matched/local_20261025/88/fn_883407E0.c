typedef unsigned char u8;

extern void fn_883404E0(void *p);

void fn_883407E0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_883404E0(ptr);
}