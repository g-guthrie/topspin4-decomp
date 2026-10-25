typedef unsigned int u32;
typedef unsigned char u8;

extern u32 fn_88448F90(void *p);

u32 fn_88448F88(void *p)
{
    return fn_88448F90((u8 *)p - 0x10);
}