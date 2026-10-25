typedef unsigned char u8;

extern void fn_88347650(void *p);

void fn_88348810(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88347650(ptr);
}