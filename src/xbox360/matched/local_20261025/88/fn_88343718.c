typedef unsigned char u8;

extern void fn_88343638(void *p);

void fn_88343718(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88343638(ptr);
}