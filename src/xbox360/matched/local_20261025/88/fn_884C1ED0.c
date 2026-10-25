typedef unsigned int u32;
typedef u32 (*dispatch_fn)(void *);

u32 fn_884C1ED0(void *object)
{
    void *ptr = *(void **)((char *)object + 0x3c);
    dispatch_fn *disp = *(dispatch_fn **)ptr;
    return disp[5](ptr);
}