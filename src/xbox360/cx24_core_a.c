/* CW24 slice 0x881A2000-0x881D1D78: game core loaders/resources. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct WStr { u32 pad; u16 *data; int pos; int cur; u32 pad2; int count; u8 eof; };
extern float lbl_88D45A34;
extern float lbl_88C69CB4, lbl_88C69CB8, lbl_88C69CBC, lbl_88C69CC0;
struct F5 { char pad[0x38]; float a, b, c, d, e; };
struct Reg224 { void *vtbl; char pad[0x21c]; void *first; void *cur; };
extern char lbl_880F7940[];
extern struct Reg224 *lbl_88D45B1C;
void ts4_if_call_seq_lbl_880F7EE4_88617D28(void *);
void ts4_tsu_cleanup_end(void *);
struct E12 { int a; int b; int key; };
struct E24 { int a; int b; int key; int c; int d; u8 e; };
struct E24 *ts4_e24_linear_insert_881B0A28(struct E24 *last, struct E24 v)
{
    struct E24 *prev = last - 1;
    while (v.key > prev->key) {
        last->a = prev->a; last->b = prev->b; last->key = prev->key;
        last->c = prev->c; last->d = prev->d; last->e = prev->e;
        last = prev;
        --prev;
    }
    last->a = v.a; last->b = v.b; last->key = v.key;
    last->c = v.c; last->d = v.d; last->e = v.e;
    return last;
}

void ts4_find_last_of_881AF678(char **out, char **pos, char **limit, const char *s, const char *e)
{
    while ((long)*pos != (long)*limit) {
        const char *c;
        for (c = s; c != e; ++c)
            if ((*pos)[-1] == *c) { *out = *pos; return; }
        --*pos;
    }
    *out = *limit;
}

struct Vec38 { char pad[0x380]; char *data; int count; };
void ts4_sb38_grow_881C6998(struct Vec38 *v, int n);
void fn_881C60C8(void *elem, void *arg);
int ts4_vec38_push_back_881C67A0(struct Vec38 *v, void *arg)
{
    char *p;
    ts4_sb38_grow_881C6998(v, v->count + 1);
    p = v->data + v->count * 0x38;
    if (p)
        fn_881C60C8(p, arg);
    return v->count++;
}

struct WVec { u32 pad; u16 *end; };
void *fn_88562DC0(void *dst, const void *src, u32 n);
u16 *ts4_wvec_erase_881AB3A0(struct WVec *v, u16 *first, u16 *last)
{
    if (first != last) {
        int n = (int)(v->end - last) + 1;
        if (n != 0)
            fn_88562DC0(first, last, n * 2);
        v->end -= last - first;
    }
    return first;
}

/* variant value getters: node at *self, type nibble 12 = computed through a temporary */
struct VNode { u8 pad[8]; u8 flags; u8 pad2[3]; u8 data[0x40]; };
struct VBox { struct VNode *node; };
struct VTmp { u8 b[0x20]; };
struct VRes { u8 pad[0x10]; double d; };
extern struct VRes *ts4_call_seq_u32_off10_888377C0(struct VTmp *out, void *a, void *b);
extern void fn_881B19A0(struct VTmp *t);
#define CX24_VPTR(n) (((n)->flags & 0x20) ? *(u8 **)(n)->data : (n)->data)

u8 ts4_variant_get_u8_881C7ED0(struct VBox *self)
{
    struct VNode *n = self->node;
    if ((n->flags & 0xf) == 12) {
        struct VTmp t;
        u8 r;
        u8 *a = n->data;
        struct VRes *v = ts4_call_seq_u32_off10_888377C0(&t, a, a + 0x20);
        r = (u8)(u32)v->d;
        fn_881B19A0(&t);
        return r;
    }
    return *CX24_VPTR(n);
}

u16 ts4_variant_get_u16_881C7F70(struct VBox *self)
{
    struct VNode *n = self->node;
    if ((n->flags & 0xf) == 12) {
        struct VTmp t;
        u16 r;
        u8 *a = n->data;
        struct VRes *v = ts4_call_seq_u32_off10_888377C0(&t, a, a + 0x20);
        r = (u16)(u32)v->d;
        fn_881B19A0(&t);
        return r;
    }
    return *(u16 *)CX24_VPTR(n);
}

int ts4_variant_get_int_881C8070(struct VBox *self)
{
    struct VNode *n = self->node;
    if ((n->flags & 0xf) == 12) {
        struct VTmp t;
        int r;
        u8 *a = n->data;
        struct VRes *v = ts4_call_seq_u32_off10_888377C0(&t, a, a + 0x20);
        r = (int)(u32)v->d;
        fn_881B19A0(&t);
        return r;
    }
    return *(int *)CX24_VPTR(n);
}

double ts4_variant_get_double_881C8258(struct VBox *self)
{
    struct VNode *n = self->node;
    if ((n->flags & 0xf) == 12) {
        struct VTmp t;
        double r;
        u8 *a = n->data;
        struct VRes *v = ts4_call_seq_u32_off10_888377C0(&t, a, a + 0x20);
        r = v->d;
        fn_881B19A0(&t);
        return r;
    }
    return *(double *)CX24_VPTR(n);
}

struct VRes2 { u8 pad[0x10]; u8 *p; };
u8 *ts4_variant_get_ptr_881C8348(struct VBox *self)
{
    struct VNode *n = self->node;
    if ((n->flags & 0xf) == 12) {
        struct VTmp t;
        u8 *r;
        u8 *a = n->data;
        struct VRes *v = ts4_call_seq_u32_off10_888377C0(&t, a, a + 0x20);
        r = ((struct VRes2 *)v)->p + 0x18;
        fn_881B19A0(&t);
        return r;
    }
    return *(u8 **)CX24_VPTR(n);
}

struct VStrOut { void *p; };
struct VTmp16 { u8 b[0x10]; };
typedef void *(*Cx24VFn)(struct VTmp16 *);
extern void *fn_8818EB10(void *out, void *src);
extern void ts4_call_seq_u32_off0_8819AD80(void *p);
extern void *ts4_assign_text_from_c_string(void *out, void *s);
extern void *ts4_string_copy_with_owner_8819ACC8(void *out, void *s);
extern void *ts4_string_from_wide_default_owner_8819AC38(void *out, void *s);

void *ts4_variant_get_text_881C83D8(void *out, struct VBox *self)
{
    struct VNode *n = self->node;
    struct VTmp t;
    struct VTmp16 t0;
    if (n->flags & 0x10) {
        void *r = (*(Cx24VFn *)n->data)(&t0);
        fn_8818EB10(out, r);
        ts4_call_seq_u32_off0_8819AD80(&t0);
    } else if ((n->flags & 0xf) == 12) {
        u8 *a = n->data;
        struct VRes2 *v = (struct VRes2 *)ts4_call_seq_u32_off10_888377C0(&t, a, a + 0x20);
        ts4_assign_text_from_c_string(out, v->p + 0x18);
        fn_881B19A0(&t);
    } else {
        fn_8818EB10(out, CX24_VPTR(n));
    }
    return out;
}

void *ts4_variant_get_string_881C84A0(void *out, struct VBox *self)
{
    struct VNode *n = self->node;
    struct VTmp t;
    struct VTmp16 t0;
    if (n->flags & 0x10) {
        void *r = (*(Cx24VFn *)n->data)(&t0);
        ts4_string_copy_with_owner_8819ACC8(out, r);
        ts4_call_seq_u32_off0_8819AD80(&t0);
    } else if ((n->flags & 0xf) == 12) {
        u8 *a = n->data;
        struct VRes2 *v = (struct VRes2 *)ts4_call_seq_u32_off10_888377C0(&t, a, a + 0x20);
        ts4_string_from_wide_default_owner_8819AC38(out, v->p + 0x18);
        fn_881B19A0(&t);
    } else {
        ts4_string_copy_with_owner_8819ACC8(out, CX24_VPTR(n));
    }
    return out;
}
