typedef unsigned char u8;

extern void fn_8833CB90(void *p);

void fn_8833CDD0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8833CB90(ptr);
}