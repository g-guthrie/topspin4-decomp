typedef unsigned char u8;

extern void fn_8833C330(void *p);

void fn_8833CDB8(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8833C330(ptr);
}