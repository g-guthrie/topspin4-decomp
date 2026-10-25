typedef unsigned char u8;

extern void fn_88343F30(void *p);

void fn_88344208(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88343F30(ptr);
}