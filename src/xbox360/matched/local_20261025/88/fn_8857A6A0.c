typedef unsigned int ts4_u32;
extern ts4_u32 XamShowGamerCardUIForXUID(void *object, ts4_u32 argument, ts4_u32 flag);

ts4_u32 fn_8857A6A0(void *object, ts4_u32 argument)
{
    return XamShowGamerCardUIForXUID(object, argument, 0);
}
