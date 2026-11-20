/* CW2 batch a: small string / tree / allocator helpers (Swing_DLL.xex). */
typedef unsigned int cw2_u32;
typedef unsigned char cw2_u8;
#ifdef _MSC_VER
extern char *strcpy(char *, const char *);
extern char *strcat(char *, const char *);
#pragma intrinsic(strcpy, strcat)
#else
#include <string.h>
#endif

/* Swing_DLL.xex 0x88165118: strcpy(dst, a); strcat(dst, b) */
void ts4_cw2_strcpy_cat_88165118(char *dst, const char *a, const char *b)
{
    strcpy(dst, a);
    strcat(dst, b);
}

/* Swing_DLL.xex 0x88164338: strcpy(dst, lit0); strcat(dst, s); strcat(dst, lit1) */
extern char lbl_880D3BAC[];
extern char lbl_880D3BA8[];
void ts4_cw2_strcpy_cat2_88164338(char *dst, const char *s)
{
    strcpy(dst, lbl_880D3BAC);
    strcat(dst, s);
    strcat(dst, lbl_880D3BA8);
}

/* red-black tree node: color, parent, left, right */
struct Cw2RbNode {
    cw2_u8 color;
    cw2_u8 pad[3];
    struct Cw2RbNode *parent;
    struct Cw2RbNode *left;
    struct Cw2RbNode *right;
};

/* Swing_DLL.xex 0x8815D4F0: in-order predecessor (header node returns its rightmost) */
struct Cw2RbNode *ts4_cw2_rb_prev_8815D4F0(struct Cw2RbNode *n)
{
    struct Cw2RbNode *l;
    struct Cw2RbNode *p;
    if (n->color == 0 && n->parent->parent == n)
        return n->right;
    l = n->left;
    if (l != 0) {
        struct Cw2RbNode *r = l->right;
        while (r != 0) {
            l = r;
            r = r->right;
        }
        return l;
    }
    p = n->parent;
    while (n == p->left) {
        n = p;
        p = p->parent;
    }
    return p;
}

struct Cw2Str {
    char *first;
    char *last;
    char *cap;
};
void ts4_byte_string_assign_88158908(struct Cw2Str *, struct Cw2Str *);
void fn_881BD170(void *, void *);

/* Swing_DLL.xex 0x8815CD28: assign a value (byte, two byte strings, word, sub-object) into every 0x2c-byte element of a range */
struct Cw2ElemB {
    cw2_u8 b;
    cw2_u8 pad[3];
    struct Cw2Str s0;
    struct Cw2Str s1;
    cw2_u32 w;
    char sub[0xc];
};
void ts4_cw2_fill_range_8815CD28(struct Cw2ElemB *first, struct Cw2ElemB *last, struct Cw2ElemB *val)
{
    for (; first != last; first++) {
        first->b = val->b;
        ts4_byte_string_assign_88158908(&first->s0, &val->s0);
        ts4_byte_string_assign_88158908(&first->s1, &val->s1);
        first->w = val->w;
        fn_881BD170(first->sub, val->sub);
    }
}
