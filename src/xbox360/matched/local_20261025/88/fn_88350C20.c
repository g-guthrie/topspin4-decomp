typedef unsigned char u8;

extern void fn_8839CA60(void *p);

void fn_88350C20(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8839CA60(ptr);
}