typedef unsigned char u8;

extern void fn_8834A060(void *p);

void fn_8834A718(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8834A060(ptr);
}