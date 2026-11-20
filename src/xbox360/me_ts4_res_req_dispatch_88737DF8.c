/* Swing_DLL.xex 0x88737DF8: dispatch a render resource request by state. */
typedef unsigned int u32;
typedef struct Ts4ResReq { char pad[8]; int handle; u32 slot; char pad2[0x18]; int pending; } Ts4ResReq;
extern int fn_8872F390(void *);
extern int ts4_if_get_u32_off0_8871E468(void *);
static __forceinline unsigned char ts4_res_req_unbound(const Ts4ResReq *r)
{
    return r->handle == 0 || r->slot == 0xFFFFF;
}
int ts4_res_req_dispatch_88737DF8(Ts4ResReq *r)
{
    int res = 0;
    if (!ts4_res_req_unbound(r)) res = fn_8872F390(r);
    else if (r->pending) res = ts4_if_get_u32_off0_8871E468(r);
    return res;
}
