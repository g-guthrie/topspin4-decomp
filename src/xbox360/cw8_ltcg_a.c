/* CW8 LTCG route: callers of the varargs formatter ts4_forward_varargs_8819BEF0. Built with /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef long ts4_word;

typedef struct Cw8FmtVt { void *s[13]; u32 *(*get)(void *); } Cw8FmtVt;
typedef struct Cw8Fmt { const Cw8FmtVt *vt; u8 pad4[0x1c]; u8 flag; } Cw8Fmt;

extern const char g_ts4_true_string[];
extern const char lbl_880D1B30[];
extern const char lbl_880E89C4[];
extern ts4_word ts4_forward_varargs_8819BEF0(ts4_word p0, ts4_word p1, ...);

/* 0x881DD9A0: format "<fmt>" with the bool as text, the first word of a virtual getter and a caller value into dst */
ts4_word ts4_format_flag_getter_value_881DD9A0(Cw8Fmt *self, u32 *value, void *dst)
{
    const char *text = self->flag != 0 ? g_ts4_true_string : lbl_880D1B30;
    u32 v = *value;
    u32 *got = self->vt->get(self);
    return ts4_forward_varargs_8819BEF0((ts4_word)dst, (ts4_word)lbl_880E89C4, text, *got, v);
}
