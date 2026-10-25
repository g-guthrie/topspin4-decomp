typedef unsigned char u8;

extern void fn_88346598(void *p);

void fn_88347248(void *p)
{
    void *ptr = p ? (void *)((u8 *)p - 0x1c) : 0;
    fn_88346598(ptr);
}