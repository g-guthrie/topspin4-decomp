/* Loader_DLL.xex 0x833A2EA8-0x833A2F2C, 0x833A3120-0x833A31AC, executable version 0.0.0.3. */
typedef unsigned long u32;
struct Cmd9 { u32 op; void *handler; u32 a1; u32 pad; u32 a2, a3, a4, a5, a6, a7; u32 s0, s1; };
struct Cmd10 { u32 op; void *handler; u32 a[10]; };
extern void *ts4l_loop_call_seq_u32_offdb0_83353D00(void *ctx);
extern u32 ts4l_barrier_io_83353D70(void *ctx);
extern void fn_833A2D80(void);
extern void fn_833A2F30(void);

u32 ts4l_queue_cmd_op9_833A2EA8(void *ctx, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 s0, u32 s1)
{
    struct Cmd9 *c = (struct Cmd9 *)ts4l_loop_call_seq_u32_offdb0_83353D00(ctx);
    c->op = 9;
    c->a1 = a1; c->a2 = a2; c->a3 = a3; c->a4 = a4; c->a5 = a5; c->a6 = a6; c->a7 = a7;
    c->s0 = s0;
    c->s1 = s1;
    c->handler = (void *)fn_833A2D80;
    return ts4l_barrier_io_83353D70(ctx);
}
u32 ts4l_queue_cmd_op10_833A3120(void *ctx, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 s0, u32 s1, u32 s2)
{
    struct Cmd10 *c = (struct Cmd10 *)ts4l_loop_call_seq_u32_offdb0_83353D00(ctx);
    c->op = 10;
    c->a[0] = a1; c->a[1] = a2; c->a[2] = a3; c->a[3] = a4; c->a[4] = a5; c->a[5] = a6; c->a[6] = a7;
    c->a[7] = s0; c->a[8] = s1; c->a[9] = s2;
    c->handler = (void *)fn_833A2F30;
    return ts4l_barrier_io_83353D70(ctx);
}
