/*
 * CL2 part d: more clrrwi functions (strlen intrinsic users, string builders).
 * Swing_DLL.xex, Xbox 360, cl.exe 16.00.10224.00, plain route, no flags.
 */
#if defined(__clang__)
#pragma clang diagnostic ignored "-Wpointer-bool-conversion"
#endif
#ifdef _MSC_VER
typedef char *ts4_va_list;
#define TS4_VA_START(ap, v) __va_start(&ap, v)
extern unsigned int strlen(const char *s);
#else
#include <stdarg.h>
#include <string.h>
typedef va_list ts4_va_list;
#define TS4_VA_START(ap, v) va_start(ap, v)
#endif
typedef unsigned int u32;
typedef unsigned char u8;
char *ts4_crt_strncat_88564EF0(char *front, const char *back, u32 count);
void fn_8816CAA0(void *self, const char *s);

static __inline char *cl2_copy_bounded(char *dst, const char *src, int n)
{
    char *p = dst; char *e = dst + n; const char *q = src;
    do { char c = *q; if (c == 0) break; *p = c; ++p; ++q; } while (p != e);
    *p = 0;
    return dst;
}

struct BStr { char *first; char *last; char *cap; };
void fn_8816C930(struct BStr *self, const char *from, const char *to);
void fn_8863B5F8(void *self, const char *s);
extern char lbl_880E196C[], lbl_880D3BA8[];
static __inline void cl2_app(struct BStr *self, const char *from, const char *to) { if (from != to) fn_8816C930(self, from, to); }
struct L { char pad[0x464]; struct BStr str; char pad2[0x488 - 0x470]; int enabled; };
void ts4_log_line_8863EF50(struct L *self, const char *s)
{
    struct BStr *b = &self->str;
    cl2_app(b, lbl_880E196C, lbl_880E196C + 1);
    cl2_app(b, s, s + (int)strlen(s));
    cl2_app(b, lbl_880D3BA8, lbl_880D3BA8 + 1);
    if (self->enabled) fn_8863B5F8(self, s);
}
struct Vt { void *s[4]; void (*write)(void *self, const char *s, int n); };
struct Sk { struct Vt *vt; };
struct Lg { int w0; struct Sk *sink; };
extern char lbl_88D49AD8[];
int ts4_tailcall_fn_885654E8_885655D0(char *buf, int n, const char *fmt, ts4_va_list ap);
void ts4_logf_8860ACC0(struct Lg *self, const char *fmt, ...)
{
    ts4_va_list ap;
    int n;
    TS4_VA_START(ap, fmt);
    n = ts4_tailcall_fn_885654E8_885655D0(lbl_88D49AD8, 0xfff, fmt, ap);
    if (n < 0 || (u32)n >= 0xfff) lbl_88D49AD8[0xffe] = 0;
    lbl_88D49AD8[0xfff] = 0;
    self->sink->vt->write(self->sink, lbl_88D49AD8, (int)strlen(lbl_88D49AD8));
}

extern char lbl_880DFDB0[], lbl_880D592C[];
void ts4_name_mid_8886A190(void *self, const char *s)
{
    char buf[0x80];
    cl2_copy_bounded(buf, lbl_880DFDB0, 0x7c);
    if (s) ts4_crt_strncat_88564EF0(buf, s, 0x7c - (int)strlen(buf));
    ts4_crt_strncat_88564EF0(buf, lbl_880D592C, 0x7c - (int)strlen(buf));
    fn_8816CAA0(self, buf);
}
extern char lbl_880DFDB0[], lbl_880D592C[], lbl_880D5928[];
void ts4_name_mid_8886A270(void *self, const char *s)
{
    char buf[0x80];
    cl2_copy_bounded(buf, lbl_880DFDB0, 0x7c);
    if (s) ts4_crt_strncat_88564EF0(buf, s, 0x7c - (int)strlen(buf));
    ts4_crt_strncat_88564EF0(buf, lbl_880D5928, 0x7c - (int)strlen(buf));
    fn_8816CAA0(self, buf);
}
struct BS { char *first; char *last; char *cap; };
struct Svc2Vt { void *s[10]; void (*query)(void *self, const char *s, struct BS *out); };
struct Svc2 { struct Svc2Vt *vt; };
struct Reg2 { char pad[0x238]; struct Svc2 *svc; };
extern struct Reg2 *lbl_88D45B1C;
extern char lbl_880E152C[];
void fn_8816D1A8(struct BS *s);
int fn_88608590(int a, const char *s);
void ts4_destroy_owned_object(void *p);
int *ts4_name_lookup_88847898(int *out, const char *s)
{
    struct BS tmp;
    char buf[0x80];
    fn_8816D1A8(&tmp);
    lbl_88D45B1C->svc->vt->query(lbl_88D45B1C->svc, s, &tmp);
    cl2_copy_bounded(buf, lbl_880E152C, 0x7c);
    ts4_crt_strncat_88564EF0(buf, tmp.first, 0x7c - (int)strlen(buf));
    *out = fn_88608590(0, buf);
    ts4_destroy_owned_object(tmp.first);
    return out;
}

/* ---- 0x885F56D0: total size of two names plus a child's size ---- */
struct Ch;
struct ChVt { void *s0; int (*size)(struct Ch *self); };
struct Ch { struct ChVt *vt; };
struct W3 { char pad[0x1c]; int base; u32 p20, p24; struct Ch *child; const char *a; const char *b; };
int ts4_total_size_885F56D0(struct W3 *w)
{
    int la = w->a ? (int)strlen(w->a) + 2 : 2;
    int lb = w->b ? (int)strlen(w->b) + 2 : 2;
    int total = w->base + lb + la + 0x1a;
    if (w->child) return w->child->vt->size(w->child) + total;
    return total;
}

/* ---- 0x885FB858: total size of four names ---- */
struct W4 { char pad[0xc]; const char *a; const char *b; const char *c; const char *d; };
int ts4_total_size4_885FB858(struct W4 *w)
{
    int la = w->a ? (int)strlen(w->a) + 2 : 2;
    int lb = w->b ? (int)strlen(w->b) + 2 : 2;
    int lc = w->c ? (int)strlen(w->c) + 2 : 2;
    int ld = w->d ? (int)strlen(w->d) + 2 : 2;
    return ld + lc + lb + la + 8;
}

/* ---- 0x881A25E8: set a function-pointer field, then call it through the field (clrrwi before mtctr) ---- */
struct Cl2S1 { void (*fn)(struct Cl2S1 *); u32 f4; u32 f8; u8 pad[0x18 - 0xc]; u8 f18; };
void fn_881A2658(struct Cl2S1 *self, void *a);
void fn_8818EB10(u32 *p, void *a);
void ts4_if_get_u32_off4_881A26D8(struct Cl2S1 *self);
void ts4_s1_ctor_881A25E8(struct Cl2S1 *self, void *a)
{
    fn_881A2658(self, a);
    if (&self->f4) fn_8818EB10(&self->f4, a);
    self->f8 = 0;
    self->fn = ts4_if_get_u32_off4_881A26D8;
    self->f18 = 0;
    self->fn(self);
}

/* ---- 0x881909D0: destructor that runs a callback-wrapped vslot for each held node ---- */
struct Cl2HNode { struct Cl2HNode *next; };
struct Cl2HObj;
struct Cl2HVT { void *s[6]; void (*fn)(struct Cl2HObj *self, struct Cl2HNode *n); };
struct Cl2HObj { struct Cl2HVT *vt; };
typedef void (*Cl2HCb)(int ev, struct Cl2HNode *n, int z, struct Cl2HObj *o);
extern Cl2HCb lbl_88D3E3AC;
extern char lbl_880DD208[], lbl_880DD088[];
struct Cl2HObj *fn_88198E08(struct Cl2HNode *n);
struct Hold { void *vt; u8 pad[0x6c - 4]; struct Cl2HNode *slots[2]; u8 pad2[0x94 - 0x74]; u32 w94; u32 w98; };
void ts4_if_call_seq_u32_off10_88191858(struct Hold *self);
void ts4_hold_dtor_881909D0(struct Hold *self)
{
    int i;
    struct Cl2HNode **p;
    self->vt = lbl_880DD208;
    ts4_if_call_seq_u32_off10_88191858(self);
    self->w98 = 0;
    self->w94 = 0;
    p = self->slots + 2;
    for (i = 1; i >= 0; --i) {
        struct Cl2HNode *n = *--p;
        if (n) {
            struct Cl2HObj *o = fn_88198E08(n);
            if (o) {
                if (lbl_88D3E3AC) lbl_88D3E3AC(4, n, 0, o);
                o->vt->fn(o, n);
                if (lbl_88D3E3AC) lbl_88D3E3AC(5, n, 0, o);
            }
        }
        *p = 0;
    }
    self->vt = lbl_880DD088;
}
