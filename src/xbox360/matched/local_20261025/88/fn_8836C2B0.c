typedef unsigned char u8;

extern void fn_8836C040(void *p);

void fn_8836C2B0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8836C040(ptr);
}