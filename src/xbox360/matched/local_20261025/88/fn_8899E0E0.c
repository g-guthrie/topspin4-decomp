typedef unsigned char ts4_u8;
extern void ts4_clear_intrusive_list();

void fn_8899E0E0(void *ptr)
{
    ts4_clear_intrusive_list((ts4_u8 *)ptr + 0x1c);
}