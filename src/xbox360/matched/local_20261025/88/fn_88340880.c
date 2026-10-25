typedef unsigned char u8;

extern void fn_88340660(void *p);

void fn_88340880(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88340660(ptr);
}