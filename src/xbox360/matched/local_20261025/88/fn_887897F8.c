typedef unsigned int ts4_u32;

void *ts4_find_service(ts4_u32 service_id);
void fn_888D3780(void *service);

ts4_u32 fn_887897F8(void)
{
    fn_888D3780(ts4_find_service(0x585B1D0A));
    return 0;
}