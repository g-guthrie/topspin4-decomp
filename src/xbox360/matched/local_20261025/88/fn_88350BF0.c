typedef unsigned char u8;

extern void fn_88350560(void *p);

void fn_88350BF0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88350560(ptr);
}