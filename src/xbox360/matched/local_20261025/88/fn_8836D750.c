typedef unsigned char u8;

extern void fn_8836D228(void *p);

void fn_8836D750(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8836D228(ptr);
}