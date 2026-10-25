typedef unsigned char u8;

extern void fn_88341ED0(void *p);

void fn_88342698(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88341ED0(ptr);
}