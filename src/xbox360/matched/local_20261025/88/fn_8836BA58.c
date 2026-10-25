typedef unsigned char u8;

extern void fn_8836B8A0(void *p);

void fn_8836BA58(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8836B8A0(ptr);
}