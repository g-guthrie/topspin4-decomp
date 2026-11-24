/* CX43: net/lobby, scheduler, front end helpers, Swing_DLL.xex 0x889Axxxx-0x889Bxxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX43_INL static __forceinline
#else
#define CX43_INL static inline
#endif
typedef struct Cx43Svc { u8 pad[0x18d]; u8 b18d; u8 pad1[2]; u32 w190; u32 w194; } Cx43Svc;
typedef struct Cx43SvcB { u8 pad[0x27c]; u32 w27c; u32 w280; u8 pad1[0x2d0 - 0x284]; u32 w2d0; } Cx43SvcB;
typedef struct Cx43Sess { u8 pad[0x3c]; Cx43SvcB *p3c; u8 pad1[0x68 - 0x40]; u8 *p68; } Cx43Sess;
extern Cx43Sess *g_ts4_session_context;

extern u32 ts4_if_call_seq_u32_off44_8864BB40(void *o);
#if 0 /* near miss, not byte-identical */
int ts4_flag_nonzero_889BFA88(void *o)
{
    u32 r = ts4_if_call_seq_u32_off44_8864BB40(o);
    return 0 != r;
}
#endif

extern u32 ts4_grid_valid_889A0478(void *p);
#if 0 /* near miss, not byte-identical */
u32 ts4_check_mode_889A4930(u8 *self)
{
    Cx43SvcB *s = g_ts4_session_context->p3c;
    u32 m = s->w2d0;
    if (m == 0x054AB17F || m == 0x582B3086)
        return ts4_grid_valid_889A0478(self + 0xbc);
    return 1;
}
#endif

typedef struct Cx43Obj9c { u8 pad[0x9c]; int w9c; } Cx43Obj9c;
typedef struct Cx43Arg42c { u8 pad[0x42c]; int w42c; } Cx43Arg42c;
#if 0 /* near miss, not byte-identical */
void ts4_sub_time_889A4478(Cx43Obj9c *self, Cx43Arg42c *a)
{
    int n = a->w42c;
    if (g_ts4_session_context->p3c->w280 != 0x0D257AF3)
        return;
    if (self->w9c == 0)
        return;
    self->w9c = self->w9c - n * 1000;
}
#endif

extern void *fn_889395D8(void *src, u32 *dst);
#if 0 /* near miss, not byte-identical */
void ts4_load_w42c_889AF328(u8 *self, void *src)
{
    u32 v = 0;
    fn_889395D8(src, &v);
    *(u32 *)(self + 0x42c) = v;
}
#endif

extern void *ts4_cx42_b_8899D750(void *a);
extern void *ts4_find_entry_by_alt_id_88866C30(u32 id, u8 *tab);
void *ts4_find_alt_entry_889A5598(void *a)
{
    u8 *e = (u8 *)ts4_cx42_b_8899D750(a);
    if (e) {
        void *r = ts4_find_entry_by_alt_id_88866C30(*(u32 *)(e + 0x10), g_ts4_session_context->p68 + 0x13c0);
        if (r)
            return r;
    }
    return 0;
}

extern void ts4_bits_step_88936BB0(void *src, u32 *dst);
#if 0 /* near miss, not byte-identical */
void ts4_load_w42c_4_889A79D0(u8 *self, void *src)
{
    void *p = fn_889395D8(src, (u32 *)(self + 0x42c));
    p = fn_889395D8(p, (u32 *)(self + 0x430));
    p = fn_889395D8(p, (u32 *)(self + 0x434));
    ts4_bits_step_88936BB0(p, (u32 *)(self + 0x438));
}
#endif

extern void ts4_cx42_i_889967F0(void *p);
#if 0 /* near miss, not byte-identical */
void ts4_set_stamp_889A1C28(void *a, u8 *b)
{
    Cx43SvcB *s;
    Cx43Svc *t;
    ts4_cx42_i_889967F0(a);
    t = (Cx43Svc *)g_ts4_session_context->p3c;
    t->w190 = 0xA0BDE62E;
    t->w194 = *(u32 *)(b + 0xdbc);
    t->b18d = 1;
    (void)s;
}
#endif
