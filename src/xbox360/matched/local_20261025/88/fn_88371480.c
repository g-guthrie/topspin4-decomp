typedef unsigned char u8;

extern void fn_88370BE0(void *p);

void fn_88371480(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88370BE0(ptr);
}