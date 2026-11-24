/* Swing_DLL.xex 0x885CF5D8: fixed-capacity node pool init (2 chunks; twin pool8 init) */
typedef struct ts4_pnode { int a; struct ts4_pnode *next; } ts4_pnode;
typedef struct ts4_pchunk { int pad; ts4_pnode n; } ts4_pchunk;
typedef struct ts4_pool2 { ts4_pnode *free; ts4_pchunk *base; ts4_pchunk arr[2]; int gap; int c0, c1, c2, cap; } ts4_pool2;

void ts4_pool8_init_885CF5D8(ts4_pool2 *p)
{
    int i;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 2;
    p->base = p->arr;
    p->arr[0].pad = 0;
    for (i = 0; i < 2; i++) {
        ts4_pchunk *c = p->base + i;
        ts4_pnode *nn = &c->n;
        nn->next = p->free;
        p->free = nn;
    }
}
