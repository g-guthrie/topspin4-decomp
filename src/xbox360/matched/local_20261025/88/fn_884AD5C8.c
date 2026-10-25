typedef unsigned int ts4_u32;
extern ts4_u32 fn_884ACC68(void *record);

ts4_u32 fn_884AD5C8(void *record)
{
    return fn_884ACC68((unsigned char *)record - 0x20);
}