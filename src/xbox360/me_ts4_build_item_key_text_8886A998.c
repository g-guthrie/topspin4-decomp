/* Swing_DLL.xex 0x8886A998: build prefix + upcase(kind tag + item name + suffix) as a returned string
 * assign in if/else (a ?: argument schedules &name late); self-relative name read through a RelStr pointer */
typedef unsigned char u8;
typedef unsigned int u32;
unsigned int strlen(const char *s);
#pragma intrinsic(strlen)

typedef struct Text { char *p; char *last; char *end; } Text;
typedef struct RelStr { int off; } RelStr; /* self-relative, -1 = none */
typedef struct NamedItem {
    u8 pad00[0xC];
    u32 kind;        /* +0x0C */
    u8 pad10[0xD8];
    RelStr name;     /* +0xE8 */
} NamedItem;

void fn_8816D1A8(Text *t);                                       /* default ctor */
void fn_8816CAA0(Text *t, const char *s);                        /* assign */
void fn_8816C930(Text *t, const char *first, const char *last);  /* append */
void ts4_charvec_upcase_8860BA68(Text *t);
void ts4_assign_formatted_text(Text *dst, const char *src);
Text *fn_88163300(Text *r, const Text *a, const Text *b);       /* operator+ */
void ts4_if_call_seq_u32_off0_8816D140(Text *dst, const Text *src); /* copy ctor */
void ts4_destroy_owned_object(void *obj);
extern const char lbl_880DFCB8[];
extern const char lbl_880DFCC0[];
extern const char lbl_880C1320[];
extern const char lbl_880D3BA0[];
extern const char lbl_880D76D4[];

static __inline const char *rel_str(RelStr *r, const char *def)
{
    return r->off != -1 ? (const char *)r + r->off : def;
}

static __inline void text_append_cstr(Text *t, const char *s)
{
    const char *e = s + (int)strlen(s);
    if (s != e)
        fn_8816C930(t, s, e);
}

Text *fn_8886A998(Text *out, NamedItem *item)
{
    Text name;
    Text prefix;
    Text full;
    fn_8816D1A8(&name);
    if (item->kind == 0xF5BF4F97)
        fn_8816CAA0(&name, lbl_880DFCB8);
    else
        fn_8816CAA0(&name, lbl_880DFCC0);
    text_append_cstr(&name, rel_str(&item->name, lbl_880C1320));
    ts4_charvec_upcase_8860BA68(&name);
    fn_8816C930(&name, lbl_880D3BA0, lbl_880D3BA0 + 4);
    ts4_assign_formatted_text(&prefix, lbl_880D76D4);
    ts4_if_call_seq_u32_off0_8816D140(out, fn_88163300(&full, &prefix, &name));
    ts4_destroy_owned_object(full.p);
    ts4_destroy_owned_object(prefix.p);
    ts4_destroy_owned_object(name.p);
    return out;
}
