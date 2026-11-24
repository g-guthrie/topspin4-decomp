/*
 * CL2 part c: functions with `clrrwi rD,rS,0` after the strlen-intrinsic loop
 * (extern unsigned strlen(const char *), result used as int).
 * Swing_DLL.xex, Xbox 360, cl.exe 16.00.10224.00, plain route, no flags.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
extern u32 strlen(const char *s);
extern void *memcpy(void *dst, const void *src, u32 n);
#else
#include <string.h>
#endif
struct W2 { u32 pad[7]; const char *name; u32 base; };
int ts4_name_size_885F54D8(struct W2 *w)
{
    const char *n = w->name;
    int len = n ? (int)strlen(n) + 2 : 2;
    return w->base + len + 0x16;
}
int ts4_rfind_char_88605BF8(const char *s, char c)
{
    int i = (int)strlen(s) - 1;
    int r = -1;
    for (; i != -1; --i)
        if (s[i] == c) { r = i; break; }
    return r;
}
struct CStr { char *data; };
int fn_885630C0(const char *a, const char *b, int n);
static __inline int cl2_cslen(const char *s) { return s ? (int)strlen(s) : 0; }
int ts4_cstr_differs_8817E0D0(struct CStr **self, const char *s)
{
    const char *d = (const char *)*self;
    int n = ((int *)d)[-3];
    if (n != cl2_cslen(s)) return 1;
    return fn_885630C0(d, s, n) != 0;
}
int ts4_cstr_equals_881CB1A0(const char *s, struct CStr **o)
{
    int l = cl2_cslen(s);
    const char *d = (const char *)*o;
    int n = ((int *)d)[-3];
    if (l != n) return 0;
    return fn_885630C0(s, d, n) == 0;
}

struct Pool { char pad[0x80c]; char *cur; };
void fn_881898E8(void *a, char **b);
void ts4_pool_append_cstr_88280110(struct Pool *self, const char *s)
{
    int n = (int)strlen(s) + 1;
    char *tmp;
    memcpy(self->cur, s, n);
    tmp = self->cur;
    fn_881898E8((char *)self + 0x800, &tmp);
    self->cur += n;
}

extern char lbl_880E14D4[];
extern char lbl_880E14C8[];
char *ts4_crt_strncat_88564EF0(char *front, const char *back, u32 count);
void fn_8816CAA0(void *self, const char *s);

static __inline char *cl2_copy_bounded(char *dst, const char *src, int n)
{
    char *p = dst;
    char *e = dst + n;
    const char *q = src;
    do {
        char c = *q;
        if (c == 0) break;
        *p = c;
        ++p; ++q;
    } while (p != e);
    *p = 0;
    return dst;
}

void ts4_name_prefix_8884F438(void *self, const char *s)
{
    char buf[0x80];
    cl2_copy_bounded(buf, lbl_880E14D4, 0x7c);
    if (s) ts4_crt_strncat_88564EF0(buf, s, 0x7c - (int)strlen(buf));
    fn_8816CAA0(self, buf);
}
void ts4_name_suffix_8884F390(void *self, const char *s)
{
    char buf[0x80];
    if (s) {
        cl2_copy_bounded(buf, s, 0x7c);
        ts4_crt_strncat_88564EF0(buf, lbl_880E14C8, 0x7c - (int)strlen(buf));
    }
    fn_8816CAA0(self, buf);
}
void ts4_name_suffix_8884F4E0(void *self, const char *s)
{
    char buf[0x80];
    if (s) {
        cl2_copy_bounded(buf, s, 0x7c);
        ts4_crt_strncat_88564EF0(buf, lbl_880E14C8, 0x7c - (int)strlen(buf));
    }
    fn_8816CAA0(self, buf);
}
extern char lbl_880D8C7C[];
void ts4_name_prefix_8884F588(void *self, const char *s)
{
    char buf[0x80];
    cl2_copy_bounded(buf, lbl_880D8C7C, 0x7c);
    if (s) ts4_crt_strncat_88564EF0(buf, s, 0x7c - (int)strlen(buf));
    fn_8816CAA0(self, buf);
}

/* ---- 0x88164000: new string = a + C string ---- */
struct Cl2BStr { char *first; char *last; char *cap; };
void ts4_if_call_seq_lbl_880D19E0_88155A40(struct Cl2BStr *self, u32 n);
void fn_8816C930(struct Cl2BStr *self, const char *from, const char *to);
static __inline void cl2_app(struct Cl2BStr *self, const char *from, const char *to) { if (from != to) fn_8816C930(self, from, to); }
struct Cl2BStr *ts4_bstr_concat_88164000(struct Cl2BStr *self, const struct Cl2BStr *a, const char *s)
{
    int len = (int)strlen(s);
    u32 n = len + (u32)(a->last - a->first) + 1;
    self->first = 0; self->last = 0; self->cap = 0;
    ts4_if_call_seq_lbl_880D19E0_88155A40(self, n);
    *self->last = 0;
    cl2_app(self, a->first, a->last);
    cl2_app(self, s, s + len);
    return self;
}

/* ---- 0x881640A8: new string = C string + a ---- */
struct Cl2BStr *ts4_bstr_concat_rev_881640A8(struct Cl2BStr *self, const char *s, const struct Cl2BStr *a)
{
    int len = (int)strlen(s);
    u32 n = len + (u32)(a->last - a->first) + 1;
    self->first = 0; self->last = 0; self->cap = 0;
    ts4_if_call_seq_lbl_880D19E0_88155A40(self, n);
    *self->last = 0;
    cl2_app(self, s, s + len);
    cl2_app(self, a->first, a->last);
    return self;
}

/* ---- 0x8818A530: global callback pointer called around a vslot call (if (cb) cb(...) gives the clrrwi) ---- */
struct Cl2Node { struct Cl2Node *next; };
struct Cl2VT { void *s[6]; void (*fn)(void *self, struct Cl2Node *n); };
struct Cl2Obj { struct Cl2VT *vt; };
typedef void (*Cl2Cb)(int ev, struct Cl2Node *n, int z, struct Cl2Obj *o);
extern Cl2Cb lbl_88D3E3AC;
struct Cl2Obj *fn_88198E08(struct Cl2Node *n);
void ts4_node_list_run_8818A530(struct Cl2Node *n)
{
    while (n) {
        struct Cl2Node *cur = n;
        struct Cl2Obj *o;
        n = n->next;
        o = fn_88198E08(cur);
        if (o) {
            if (lbl_88D3E3AC) lbl_88D3E3AC(4, cur, 0, o);
            o->vt->fn(o, cur);
            if (lbl_88D3E3AC) lbl_88D3E3AC(5, cur, 0, o);
        }
    }
}

/* ---- 0x8815D0A8: fill [first,last) of 0x30-byte items with copies of src (grid copy inlined; clrrwi on the width) ---- */
struct Cl2FVec { float *data; u32 a, b; };
void ts4_fvec_resize_88158B28(struct Cl2FVec *v, u32 n);
void ts4_byte_string_assign_88158908(void *dst, const void *src);
struct Cl2Item { u32 w; u32 h; struct Cl2FVec v; u32 s1[3]; u32 s2[3]; u8 flag; u8 pad[3]; };
static __inline void cl2_grid_assign(struct Cl2Item *d, const struct Cl2Item *o)
{
    if (d != o) {
        u32 n;
        d->w = o->w;
        d->h = o->h;
        n = d->w * d->h;
        ts4_fvec_resize_88158B28(&d->v, n);
        if (n) memcpy(d->v.data, o->v.data, d->h * d->w * 4);
    }
}
void ts4_item_fill_8815D0A8(struct Cl2Item *first, struct Cl2Item *last, const struct Cl2Item *src)
{
    for (; first != last; ++first) {
        cl2_grid_assign(first, src);
        ts4_byte_string_assign_88158908(&first->s1, &src->s1);
        ts4_byte_string_assign_88158908(&first->s2, &src->s2);
        first->flag = src->flag;
    }
}
