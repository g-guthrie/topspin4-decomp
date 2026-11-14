/* Swing_DLL.xex 0x8835DD38-0x88369EF8, executable version 0.0.0.3. */
typedef struct Ts4Clock { char pad[0x110]; int ticks; } Ts4Clock;
typedef struct Ts4Runner {
    char pad0[0x20]; Ts4Clock *clock;
    char pad1[0x4f0 - 0x24]; int step;
    char pad2[0x87d - 0x4f4]; unsigned char done;
} Ts4Runner;
extern void fn_8835D7F0(Ts4Runner *r, int a);
extern void fn_8835D5D8(Ts4Runner *r, int a);
extern void fn_883A3950(Ts4Runner *r, int a);
extern void ts4_if_call_seq_u32_off880_883632B8(Ts4Runner *r, int a);
extern void ts4_if_call_seq_u32_off880_88366B60(Ts4Runner *r, int a);
extern void ts4_if_call_seq_u32_off880_88369A38(Ts4Runner *r, int a);
extern void fn_883A3218(Ts4Runner *r);
int ts4_run_to_done_8835DD38(Ts4Runner *r)
{
    r->clock->ticks = 0;
    fn_8835D7F0(r, 0);
    while (!r->done) {
        fn_8835D5D8(r, 0);
        r->clock->ticks += r->step;
    }
    fn_883A3218(r);
    return 0;
}
int ts4_run_to_done_88366FA0(Ts4Runner *r)
{
    r->clock->ticks = 0;
    fn_883A3950(r, 0);
    while (!r->done) {
        ts4_if_call_seq_u32_off880_88366B60(r, 0);
        r->clock->ticks += r->step;
    }
    fn_883A3218(r);
    return 0;
}
int ts4_run_to_done_88369E78(Ts4Runner *r)
{
    r->clock->ticks = 0;
    fn_883A3950(r, 0);
    while (!r->done) {
        ts4_if_call_seq_u32_off880_88369A38(r, 0);
        r->clock->ticks += r->step;
    }
    fn_883A3218(r);
    return 0;
}
