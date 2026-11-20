/* CX43 part i: net/lobby helpers, Swing_DLL.xex 0x889Axxxx-0x889Bxxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* 0x889A0540 */
extern u32 *ts4_node_dispatch_with_target_88613268(void *t, u32 a, u32 b, u32 c, u32 d);
extern void *lbl_88D45B38;
typedef struct Cx43Tab { u32 *tab; int n; u32 cnt; } Cx43Tab;
#if 0 /* near miss, not byte-identical */
u32 ts4_tab_init_889A0540(Cx43Tab *g, u32 v)
{
    if (g->cnt <= 0) {
        int i;
        g->tab = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x100, 4, 0, 2);
        g->n = 0x40;
        i = 0;
        do {
            u32 *t = g->tab;
            t[i] = 0x80000000;
            i++;
        } while (i < g->n);
        g->cnt = v;
        return 1;
    }
    return 0;
}
#endif

/* 0x889AFE48 */
extern void *fn_889395D8(void *src, u32 *dst);
extern void ts4_bits_step_88936BB0(void *src, u8 *dst);
extern void fn_88939118(void *src, void *dst, u32 n);
#if 0 /* near miss, not byte-identical */
void ts4_load_record_889AFE48(u8 *self, void *a)
{
    u32 v = 0;
    u32 w;
    fn_889395D8(a, &v);
    w = 0;
    *(u32 *)self = v;
    fn_889395D8(a, &w);
    *(u32 *)(self + 4) = w;
    ts4_bits_step_88936BB0(a, self + 0xc);
    ts4_bits_step_88936BB0(a, self + 0xd);
    fn_889395D8(a, (u32 *)(self + 8));
    fn_889395D8(a, (u32 *)(self + 0x14));
    fn_88939118(a, self + 0x18, 0x10);
    fn_88939118(a, self + 0x28, 0x10);
}
#endif

/* 0x889B2F08 */
typedef struct Cx43Cfg2c { u8 pad[0x2c]; u8 b2c; } Cx43Cfg2c;
typedef struct Cx43Svc1c { u8 pad[0x14]; Cx43Cfg2c *p14; } Cx43Svc1c;
typedef struct Cx43Sess1c { u8 pad[0x1c]; Cx43Svc1c *p1c; } Cx43Sess1c;
extern Cx43Sess1c *g_ts4_session_context;
typedef struct Cx43Q { u8 pad[0xa4]; void *pa4; } Cx43Q;
extern u8 fn_889B5A30(void *self, u32 a, u32 *p, u32 b, u32 c);
extern void ts4_memset(void *p, u32 v, u32 n);
extern void fn_889BFDA8(void *o, void *p);
typedef struct Cx43Arg { u32 n; u8 *p; } Cx43Arg;
void ts4_send_empty_889B2F08(Cx43Q *self)
{
    Cx43Svc1c *s = g_ts4_session_context->p1c;
    if (s != 0 && s->p14->b2c != 0) {
        u32 a = 0;
        if (fn_889B5A30(self, 0xd, &a, 0, 0) == 0) {
            u8 buf[1];
            Cx43Arg arg;
            ts4_memset(buf, 0, 1);
            arg.n = 4;
            arg.p = buf;
            fn_889BFDA8(self->pa4, &arg);
        }
    }
}
