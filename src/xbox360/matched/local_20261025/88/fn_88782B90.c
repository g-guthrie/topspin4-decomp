typedef unsigned int ts4_u32;

void *ts4_find_service(ts4_u32 service_id);
void fn_888CB4D0(void *service);

ts4_u32 fn_88782B90(void)
{
    fn_888CB4D0(ts4_find_service(0x10ADFA5A));
    return 0;
}