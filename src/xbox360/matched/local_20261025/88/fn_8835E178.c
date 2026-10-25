typedef unsigned char u8;

extern void fn_8835DDB8(void *p);

void fn_8835E178(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8835DDB8(ptr);
}