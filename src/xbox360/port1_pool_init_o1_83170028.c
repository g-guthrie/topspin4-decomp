/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l24_pool_init_o1_83170028.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Fixed-capacity node pool: all chunks start on the free list. */
typedef struct ts4_pnode { int a; struct ts4_pnode *next; } ts4_pnode;
typedef struct ts4_pchunk { int pad; ts4_pnode n; } ts4_pchunk;
typedef struct ts4_pool16 { ts4_pnode *free; ts4_pchunk *base; ts4_pchunk arr[16]; int gap; int c0, c1, c2, cap; } ts4_pool16;
typedef struct ts4_pool8 { ts4_pnode *free; ts4_pchunk *base; ts4_pchunk arr[8]; int gap; int c0, c1, c2, cap; } ts4_pool8;



/* Swing_DLL.xex 0x8859D608 */
void ts4_pool8_init_8859D608(ts4_pool8 *p)
{
    int i;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 8;
    p->base = p->arr;
    p->arr[0].pad = 0;
    for (i = 0; i < 8; i++) {
        ts4_pchunk *c = p->base + i;
        ts4_pnode *nn = &c->n;
        nn->next = p->free;
        p->free = nn;
    }
}

/* Swing_DLL.xex 0x885B5E38 */
void ts4_pool16_init_885B5E38(ts4_pool16 *p)
{
    int i;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 16;
    p->base = p->arr;
    p->arr[0].pad = 0;
    for (i = 0; i < 16; i++) {
        ts4_pchunk *c = p->base + i;
        ts4_pnode *nn = &c->n;
        nn->next = p->free;
        p->free = nn;
    }
}

