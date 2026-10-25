typedef unsigned char u8;

extern void fn_8836DEB8(void *p);

void fn_8836E5B0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8836DEB8(ptr);
}