/* Swing_DLL.xex game core 0x8818C6C0-0x8819C000: small functions, hand written. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int cw5_uptr;
#else
typedef unsigned long cw5_uptr;
#endif
char *fn_8819B5F8(char **self, u32 newlen);

/* 0x881996B0: true when the call on the global handle returns nonzero */
extern void *lbl_88D45B38;
u32 ts4_find_range_owner_8860D360(void *);
u32 ts4_global_handle_is_set_881996B0(void)
{
    return 0 != ts4_find_range_owner_8860D360(lbl_88D45B38);
}

/* 0x88190F70 / 0x88190AB0: current element of a table iterator */
struct cw5_elem { u8 pad[0x10]; u32 val; u8 pad2[0x8]; u32 val1c; };
struct cw5_tbl { u32 p0, p4; char **items; u32 count; };
struct cw5_owner { struct cw5_tbl *tbl; u8 pad[0x48]; u32 base; };
struct cw5_iter { u8 pad[0x10]; struct cw5_owner *owner; u32 idx; };

u32 ts4_iter_current_val_88190F70(struct cw5_iter *it)
{
    struct cw5_owner *o = it->owner;
    u32 i = it->idx;
    struct cw5_tbl *t = o->tbl;
    struct cw5_elem *e;
    if (i < t->count) {
        char **items = t->items;
        e = (struct cw5_elem *)(items[i] + o->base);
    } else
        e = 0;
    return e->val;
}

u32 *ts4_iter_current_field1c_88190AB0(struct cw5_iter *it)
{
    struct cw5_owner *o = it->owner;
    u32 i;
    struct cw5_tbl *t;
    struct cw5_elem *e;
    if (o == 0) return 0;
    i = it->idx;
    t = o->tbl;
    if (i < t->count) {
        char **items = t->items;
        e = (struct cw5_elem *)(items[i] + o->base);
    } else
        e = 0;
    return &e->val1c;
}

/* 0x88190F08: clamp-down the current element value; mark the owner dirty (flags |= 0x20, |= 0x80) */
struct cw5_owner2 { struct cw5_tbl *tbl; u8 pad[0xc]; u8 flags; u8 pad2[0x3b]; u32 base; };
struct cw5_iter2 { u8 pad[0x10]; struct cw5_owner2 *owner; u32 idx; };
void ts4_iter_lower_val_88190F08(struct cw5_iter2 *it, u32 v)
{
    struct cw5_owner2 *o = it->owner;
    u32 i = it->idx;
    struct cw5_tbl *t = o->tbl;
    struct cw5_elem *e;
    if (i < t->count) {
        char **items = t->items;
        e = (struct cw5_elem *)(items[i] + o->base);
    } else
        e = 0;
    if (v > e->val) return;
    e->val = v;
    it->owner->flags |= 0x20;
    it->owner->flags |= 0x80;
}

/* 0x88199DC0: copy up to cap wide characters to a narrow buffer, then terminate */
void ts4_wide_to_narrow_copy_88199DC0(char *dst, int cap, const unsigned short *src)
{
    int len = 0;
    int n;
    int i;
    int j;
    if (src[0] != 0) {
        const unsigned short *p = src;
        do { p++; len++; } while (*p != 0);
    }
    n = cap;
    if (!(cap < len)) n = len;
    j = 0;
    for (i = 0; i <= n; i++) dst[j++] = (char)src[i];
    dst[n] = 0;
}

/* 0x8819B060: allocate a string rep through an allocator object, copy len bytes in, terminate */
struct cw5_alloc_vt { void *s0; void *(*alloc)(void *self, u32 len, int flag); };
struct cw5_alloc { struct cw5_alloc_vt *vt; };
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
#ifdef _MSC_VER
__declspec(noinline)
#endif
char **ts4_string_assign_alloc_8819B060(char **out, const char *src, u32 len, struct cw5_alloc *a)
{
    char *buf = (char *)a->vt->alloc(a, len, 1) + 0x10;
    *out = buf;
    ((u32 *)buf)[-3] = len;
    (*out)[len] = 0;
    memcpy(*out, src, len);
    return out;
}

/* 0x8819B2A0: append count bytes (possibly from inside the string) */
void ts4_string_append_range_8819B2A0(char **self, char *from, u32 count)
{
    char *b = *self;
    u32 off = from - b;
    u32 len = ((u32 *)b)[-3];
    u32 newlen = len + count;
    char *nb = fn_8819B5F8(self, newlen);
    if (!(off > len)) from = nb + off;
    memcpy(nb + len, from, count);
    ((u32 *)*self)[-3] = newlen;
    (*self)[newlen] = 0;
}

/* string representation header lives 0x10 bytes before the character data */
struct cw5_rep { void *owner; u32 len; u32 pad8; int refs; };

/* 0x8819B390: make the string unique (copy when shared), drop one reference, return data */
void fn_8819B530(char **self, u32 len);
char *ts4_string_make_unique_8819B390(char **self)
{
    struct cw5_rep *r = (struct cw5_rep *)(*self - 0x10);
    if (r->refs > 1) {
        fn_8819B530(self, r->len);
        r = (struct cw5_rep *)(*self - 0x10);
    }
    if (--r->refs == 0) r->refs = -1;
    return *self;
}

/* 0x8819B4C8: self = a[0..na) + b[0..nb) */
void ts4_string_assign_concat_8819B4C8(char **self, const char *a, u32 na, const char *b, u32 nb)
{
    u32 total = na + nb;
    char *nbuf = fn_8819B5F8(self, total);
    memcpy(nbuf, a, na);
    memcpy(nbuf + na, b, nb);
    ((u32 *)*self)[-3] = total;
    (*self)[total] = 0;
}

/* 0x8819BE88: out = substring of src, first n characters (n clamped at 0) */
cw5_uptr ts4_if_get_u32_offc_8819B6C0(void *);
char **ts4_string_left_8819BE88(char **out, char **src, int n)
{
    char *s = *src;
    int len;
    n = n < 0 ? 0 : n;
    len = ((int *)s)[-3];
    if (n >= len) {
        *out = (char *)ts4_if_get_u32_offc_8819B6C0(s - 0x10) + 0x10;
    } else {
        ts4_string_assign_alloc_8819B060(out, s, n, (struct cw5_alloc *)((void **)s)[-4]);
    }
    return out;
}

/* 0x8819ACC8: forward to the string builder with the default allocator when the string has none */
extern u32 lbl_88D3E414;
u32 fn_8819A9D8(void);
char **fn_8819C090(char **, char **, u32);
char **ts4_string_copy_with_owner_8819ACC8(char **self, char **src)
{
    int owner = ((int *)*src)[-4];
    if (owner == 0) {
        owner = lbl_88D3E414;
        if ((u32)owner == 0) owner = fn_8819A9D8();
    }
    fn_8819C090(self, src, owner);
    return self;
}

/* 0x8819BA08: map every character through a char->char function in place */
int ts4_if_fn_88567730(int);
char **ts4_string_map_chars_8819BA08(char **self)
{
    u32 len = ((u32 *)*self)[-3];
    char *p = fn_8819B5F8(self, len);
    if (*p != 0) {
        do {
            *p = (char)ts4_if_fn_88567730(*p);
            p++;
        } while (*p != 0);
    }
    ((u32 *)*self)[-3] = len;
    (*self)[len] = 0;
    return self;
}

/* 0x88197958: construct object with an embedded critical-section holder at 0xA0 */
struct cw5_cs_holder { void *vt; u32 f4; u8 cs[0x1c]; };
struct cw5_cs_obj { void *vt; u8 pad[0x78]; u32 f7c, f80, f84, f88, f8c, f90; u8 pad2[0xc]; struct cw5_cs_holder h; };
extern char lbl_880DD528[], lbl_880DCF30[];
void fn_88197E10(void *);
cw5_uptr RtlInitializeCriticalSection(cw5_uptr);
static void cw5_cs_holder_init(struct cw5_cs_holder *h)
{
    h->vt = lbl_880DCF30;
    h->f4 = 0;
    RtlInitializeCriticalSection((cw5_uptr)&h->cs);
}
struct cw5_cs_obj *ts4_cs_obj_ctor_88197958(struct cw5_cs_obj *self)
{
    fn_88197E10(self);
    self->f7c = 0;
    self->vt = lbl_880DD528;
    self->f80 = 0;
    self->f84 = 0;
    self->f88 = 0;
    self->f8c = 0;
    self->f90 = 0;
    cw5_cs_holder_init(&self->h);
    return self;
}

/* 0x8819AEC8: wide-character substring search; returns the match start or 0 */
unsigned short *ts4_wcsstr_8819AEC8(unsigned short *s, const unsigned short *sub)
{
    if (*sub == 0) return s;
    for (; *s != 0; s++) {
        const unsigned short *p = sub;
        const unsigned short *q = s;
        while (*q != 0 && *p != 0 && (*q - *p) == 0) { q++; p++; }
        if (*p == 0) return s;
    }
    return 0;
}

/* 0x88198068: destructor: reset vtable, base cleanup, release the handle held by the sub-object at 0x98 */
struct cw5_handle_sub { void *vt; void *h; };
struct cw5_dtor_obj { void *vt; u8 pad[0x94]; struct cw5_handle_sub sub; };
extern char lbl_880DD640[], lbl_880DCF20[], lbl_880DD088[];
void ts4_if_call_seq_u32_off7c_881981E0(void *);
void ts4_if_get_u32_lbl_88C32048_8857A1E0(void *);
static void cw5_handle_sub_dtor(struct cw5_handle_sub *sub)
{
    sub->vt = lbl_880DCF20;
    if (sub->h) {
        ts4_if_get_u32_lbl_88C32048_8857A1E0(sub->h);
        sub->h = 0;
    }
}
void ts4_cw5_obj_dtor_88198068(struct cw5_dtor_obj *self)
{
    self->vt = lbl_880DD640;
    ts4_if_call_seq_u32_off7c_881981E0(self);
    cw5_handle_sub_dtor(&self->sub);
    self->vt = lbl_880DD088;
}

/* 0x8818F8E0: assign: copy word 0, assign sub-objects at +4, +8 (move), +0xC */
struct cw5_assign { u32 w0; u32 s4[1]; u32 *m8; u32 c[1]; };
void ts4_if_call_seq_u32_off0_8819B0C8(void *, void *);
void ts4_if_call_seq_u32_off0_8818FFE8(void *);
void ts4_counted_ptr_assign_881C38D0(void *, void *);
struct cw5_assign *ts4_assign_8818F8E0(struct cw5_assign *self, struct cw5_assign *src)
{
    u32 **d;
    u32 **s;
    self->w0 = src->w0;
    ts4_if_call_seq_u32_off0_8819B0C8(&self->s4, &src->s4);
    s = (u32 **)&src->m8;
    d = (u32 **)&self->m8;
    if (d != s) {
        ts4_if_call_seq_u32_off0_8818FFE8(d);
        *d = *s;
        *s = 0;
    }
    ts4_counted_ptr_assign_881C38D0(&self->c, &src->c);
    return self;
}
