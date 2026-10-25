typedef unsigned char u8;

extern void fn_8834D3D8(void *p);

void fn_8834D560(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8834D3D8(ptr);
}