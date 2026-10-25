typedef unsigned int ts4_u32;

void *ts4_find_service(ts4_u32 service_id);
extern void fn_888CF860();

ts4_u32 fn_88789DB8(void)
{
    fn_888CF860(ts4_find_service(0xE3767AD6));
    return 0;
}