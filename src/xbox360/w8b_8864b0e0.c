typedef unsigned int u32;
extern void ts4_msg_pool_service_get_8864DFF0(void);
extern void *fn_8899F760(u32 size);
extern u32 fn_8857BFA8(u32 a, u32 b, u32 c, u32 d);
extern void ts4_if_get_u32_lbl_88C32048_8857A1E0(u32 h);
extern void ts4_registry_dispatch_888860A0(void *p);

u32 **ts4_create_handle_wrapper_8864B0E0(void)
{
    u32 *a;
    u32 **b;
    ts4_msg_pool_service_get_8864DFF0();
    a = (u32 *)fn_8899F760(4);
    if (a == 0)
        return 0;
    *a = fn_8857BFA8(0, 0, 10, 0);
    if (*a != 0) {
        ts4_msg_pool_service_get_8864DFF0();
        b = (u32 **)fn_8899F760(4);
        if (b != 0) {
            *b = a;
            return b;
        }
        ts4_if_get_u32_lbl_88C32048_8857A1E0(*a);
    }
    ts4_msg_pool_service_get_8864DFF0();
    ts4_registry_dispatch_888860A0(a);
    return 0;
}
