/* CW24 part b: variant family continued. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
/* variant value getters: node at *self, type nibble 12 = computed through a temporary */
struct VNode { u8 pad[8]; u8 flags; u8 pad2[3]; u8 data[0x40]; };
struct VBox { struct VNode *node; };
struct VTmp { u8 b[0x20]; };
struct VRes { u8 pad[0x10]; double d; };
extern struct VRes *ts4_call_seq_u32_off10_888377C0(struct VTmp *out, void *a, void *b);
extern void fn_881B19A0(struct VTmp *t);
#define CX24_VPTR(n) (((n)->flags & 0x20) ? *(u8 **)(n)->data : (n)->data)


float ts4_variant_get_float_881C8168(struct VBox *self)
{
    struct VNode *n = self->node;
    if ((n->flags & 0xf) == 12) {
        struct VTmp t;
        float r;
        u8 *a = n->data;
        struct VRes *v = ts4_call_seq_u32_off10_888377C0(&t, a, a + 0x20);
        r = (float)v->d;
        fn_881B19A0(&t);
        return r;
    }
    return *(float *)CX24_VPTR(n);
}

struct VNodeW { u8 pad[8]; union { u8 flags; u32 word; } f; u8 data[0x40]; };
struct VBoxW { struct VNodeW *node; };
extern void ts4_if_call_seq_u32_off0_8819C190(void *p);
typedef void (*Cx24VSetFn)(struct VBoxW *, int, int);
extern int lbl_88C69D60[];
struct VRes3 { u8 pad[8]; int kind; u8 pad2[4]; int value; };
u8 ts4_variant_get_bool_881C4A88(struct VBox *self)
{
    struct VNode *n = self->node;
    if ((n->flags & 0xf) == 12) {
        struct VTmp t;
        int r;
        u8 *a = n->data;
        struct VRes3 *v = (struct VRes3 *)ts4_call_seq_u32_off10_888377C0(&t, a, a + 0x20);
        if (v->kind == 0 || (v->kind == 1 && v->value == 0))
            r = 0;
        else
            r = 1;
        fn_881B19A0(&t);
        return r;
    }
    return *CX24_VPTR(n);
}

const u16 *ts4_wfind_char_881AB700(const u16 *first, const u16 *last, const char *ch)
{
    int trip;
    for (trip = (int)(last - first) >> 2; trip > 0; --trip) {
        if (*first == *ch) return first;
        ++first;
        if (*first == *ch) return first;
        ++first;
        if (*first == *ch) return first;
        ++first;
        if (*first == *ch) return first;
        ++first;
    }
    switch ((int)(last - first)) {
    case 3:
        if (*first == *ch) return first;
        ++first;
    case 2:
        if (*first == *ch) return first;
        ++first;
    case 1:
        if (*first == *ch) return first;
        ++first;
    case 0:
    default:
        break;
    }
    return last;
}

struct Obj48 { void *vtbl; u32 w[17]; };
extern void *lbl_88D45B38;
extern char lbl_880E3F20[];
extern void *ts4_node_dispatch_with_target_88613268(void *heap, int size, int align, int a, int b);
struct E8 { u32 a; u32 b; };
struct V8 { struct E8 *begin; struct E8 *end; struct E8 *cap; };
extern struct E8 *ts4_if_call_seq_u32_lbl_88D45B38_88263C38(struct E8 **cap, int n);
struct E12b { u32 a; u32 b; u32 c; };
struct V12 { struct E12b *begin; struct E12b *end; struct E12b *cap; };
extern struct E12b *ts4_if_call_seq_u32_lbl_88D45B38_88263C98(struct E12b **cap, int n);
extern struct V8 *fn_881B6A80(struct V8 *self, struct V8 *src);
struct E24 { int a; int b; int key; int c; int d; u8 e; };