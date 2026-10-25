typedef unsigned char u8;

extern void fn_8832AAF8(void *p);

void fn_8832ADF0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8832AAF8(ptr);
}