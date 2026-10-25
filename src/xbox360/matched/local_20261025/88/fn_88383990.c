typedef unsigned char u8;

extern void fn_88383420(void *p);

void fn_88383990(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88383420(ptr);
}