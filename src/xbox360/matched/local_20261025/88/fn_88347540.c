typedef unsigned char u8;

extern void fn_88347370(void *p);

void fn_88347540(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88347370(ptr);
}