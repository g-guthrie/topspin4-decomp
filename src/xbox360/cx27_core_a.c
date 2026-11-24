/* CX27 part a: game core 0x8820F390-0x88220C18, plain route, no flags. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

/* 0x8820F448: wide string inequality (length at -0xc of the character data) */
u32 ts4_wstr_ne_8820F448(const u16 **pa, const u16 **pb)
{
    const u16 *a = *pa;
    const u16 *b = *pb;
    int n = ((int *)a)[-3];
    int eq;
    if (n != ((int *)b)[-3]) return 1;
    if ((u32)n == 0) {
        eq = 1;
    } else {
        while (--n != 0 && *a != 0 && *a == *b) { a++; b++; }
        eq = (int)*b - (int)*a == 0;
    }
    return !(u8)eq;
}

/* ---- ordered tree lookups ---- */
typedef struct Cx27N { u32 p; struct Cx27N *parent; struct Cx27N *left; struct Cx27N *right; int key; } Cx27N;
typedef struct Cx27T { u32 p; Cx27N *head; } Cx27T;

/* 0x88220620: key present */
u32 ts4_tree_found_88220620(Cx27T *t, const int *k)
{
    Cx27N *h = t->head;
    Cx27N *y = h;
    Cx27N *x = h->parent;
    Cx27N *e;
    while (x != 0) {
        if (x->key >= *k) { y = x; x = x->left; }
        else { x = x->right; }
    }
    e = ((volatile Cx27T *)t)->head;
    if (y == e || *(volatile int *)k < y->key) y = e;
    return y != h;
}
