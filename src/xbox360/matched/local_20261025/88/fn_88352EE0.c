typedef unsigned char u8;

extern void fn_88352600(void *p);

void fn_88352EE0(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88352600(ptr);
}