typedef unsigned char u8;

extern void fn_8833CF50(void *p);

void fn_8833D740(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_8833CF50(ptr);
}