typedef unsigned char u8;

extern void fn_8833A0E0(void *p);

void fn_8833A438(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8833A0E0(ptr);
}