typedef unsigned char u8;

extern void fn_88343800(void *p);

void fn_88343D48(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88343800(ptr);
}