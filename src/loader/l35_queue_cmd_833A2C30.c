/* Loader_DLL.xex 0x833A2C30-0x833A2CAC, 0x833A2D00-0x833A2D7C, executable version 0.0.0.3. */
typedef unsigned long u32;
struct Ts4lCmd {
    u32 op;
    void *handler;
    u32 arg[8];
};
extern struct Ts4lCmd *ts4l_loop_call_seq_u32_offdb0_83353D00(void *ctx);
extern u32 ts4l_barrier_io_83353D70(void *ctx);
extern void ts4l_call_seq_u32_off24_833A2BE0(void);
extern void ts4l_call_seq_u32_off24_833A2CB0(void);

u32 ts4l_queue_cmd_op8_833A2C30(void *ctx, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8)
{
    struct Ts4lCmd *c = ts4l_loop_call_seq_u32_offdb0_83353D00(ctx);
    c->op = 8;
    c->arg[0] = a1; c->arg[1] = a2; c->arg[2] = a3; c->arg[3] = a4;
    c->arg[4] = a5; c->arg[5] = a6; c->arg[6] = a7; c->arg[7] = a8;
    c->handler = (void *)ts4l_call_seq_u32_off24_833A2BE0;
    return ts4l_barrier_io_83353D70(ctx);
}
u32 ts4l_queue_cmd_op12_833A2D00(void *ctx, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8)
{
    struct Ts4lCmd *c = ts4l_loop_call_seq_u32_offdb0_83353D00(ctx);
    c->op = 12;
    c->arg[0] = a1; c->arg[1] = a2; c->arg[2] = a3; c->arg[3] = a4;
    c->arg[4] = a5; c->arg[5] = a6; c->arg[6] = a7; c->arg[7] = a8;
    c->handler = (void *)ts4l_call_seq_u32_off24_833A2CB0;
    return ts4l_barrier_io_83353D70(ctx);
}
