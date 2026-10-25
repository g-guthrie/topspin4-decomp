typedef unsigned char u8;

extern void fn_88358690(void *p);

void fn_88358720(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88358690(ptr);
}