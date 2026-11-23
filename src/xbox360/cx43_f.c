/* CX43 part f: ts4_format_text callers (LTCG route, context cw1_ctx_format_text.c). */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Cx43Sess { u8 pad[0x68]; u8 *p68; } Cx43Sess;
extern Cx43Sess *g_ts4_session_context;
extern int ts4_format_text(char *dst, unsigned size, const char *fmt, ...);
extern char lbl_880D1CEC[];
extern u32 ts4_crc32_cstr_seed_88608590(u32 a, const char *s);
extern u8 *ts4_find_entry_by_id_88866B60(u32 id, u8 *tab);

/* 0x889A5510 */
u32 ts4_lookup_by_index_889A5510(u32 n)
{
    char buf[16];
    u32 r;
    u8 *e;
    u32 h;
    ts4_format_text(buf, 0x10, lbl_880D1CEC, n + 1);
    r = 0;
    h = ts4_crc32_cstr_seed_88608590(0, buf);
    e = ts4_find_entry_by_id_88866B60(h, g_ts4_session_context->p68 + 0x13c0);
    if (e)
        r = *(u32 *)(e + 0xe0);
    return r;
}

/* 0x889B3128 */
typedef struct Cx43Label { u8 b0[0x21]; char name[0x207]; u32 w228; u32 w22c; u8 tail[0x10]; } Cx43Label;
extern char lbl_880D1DA8[];
extern char lbl_880D1ED4[];
extern char lbl_880D1EE0[];
extern u32 ts4_if_call_seq_u32_lbl_88D459E4_8883F238(void);
extern void ts4_label_init_flags_88151E90(Cx43Label *l, const char *s, u32 f);
extern void ts4_loop_call_seq_u32_lbl_88D45B30_888680A0(char *dst, u32 v);
extern void fn_889B17B8(void *self, Cx43Label *l, u32 a);
typedef struct Cx43Self { u8 pad[0xbc]; u32 wbc; } Cx43Self;
void ts4_show_label_889B3128(Cx43Self *self)
{
    char buf[0x30];
    Cx43Label l;
    ts4_format_text(buf, 0x21, lbl_880D1EE0, lbl_880D1ED4, lbl_880D1DA8);
    ts4_label_init_flags_88151E90(&l, buf, ts4_if_call_seq_u32_lbl_88D459E4_8883F238());
    l.w228 = 0;
    ts4_loop_call_seq_u32_lbl_88D45B30_888680A0(l.name, self->wbc);
    l.w22c = 0x3039;
    fn_889B17B8(self, &l, 0);
}
