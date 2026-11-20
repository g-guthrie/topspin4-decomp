/* Loader_DLL.xex 0x83170028-0x83181010, executable version 0.0.0.3. */

/* Fixed-capacity node pool: all chunks start on the free list. */
typedef struct ts4l_pnode { int a; struct ts4l_pnode *next; } ts4l_pnode;
typedef struct ts4l_pchunk { int pad; ts4l_pnode n; } ts4l_pchunk;
typedef struct ts4l_pool16 { ts4l_pnode *free; ts4l_pchunk *base; ts4l_pchunk arr[16]; int gap; int c0, c1, c2, cap; } ts4l_pool16;
typedef struct ts4l_pool8 { ts4l_pnode *free; ts4l_pchunk *base; ts4l_pchunk arr[8]; int gap; int c0, c1, c2, cap; } ts4l_pool8;

void ts4l_pool16_init_83170028(ts4l_pool16 *p)
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
        ts4l_pchunk *c = p->base + i;
        ts4l_pnode *nn = &c->n;
        nn->next = p->free;
        p->free = nn;
    }
}

void ts4l_pool16_init_83181010(ts4l_pool16 *p)
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
        ts4l_pchunk *c = p->base + i;
        ts4l_pnode *nn = &c->n;
        nn->next = p->free;
        p->free = nn;
    }
}

void ts4l_pool16_init_83171050(ts4l_pool16 *p)
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
        ts4l_pchunk *c = p->base + i;
        ts4l_pnode *nn = &c->n;
        nn->next = p->free;
        p->free = nn;
    }
}

void ts4l_pool16_init_83171100(ts4l_pool16 *p)
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
        ts4l_pchunk *c = p->base + i;
        ts4l_pnode *nn = &c->n;
        nn->next = p->free;
        p->free = nn;
    }
}

void ts4l_pool16_init_83175D90(ts4l_pool16 *p)
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
        ts4l_pchunk *c = p->base + i;
        ts4l_pnode *nn = &c->n;
        nn->next = p->free;
        p->free = nn;
    }
}

void ts4l_pool16_init_83180DE0(ts4l_pool16 *p)
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
        ts4l_pchunk *c = p->base + i;
        ts4l_pnode *nn = &c->n;
        nn->next = p->free;
        p->free = nn;
    }
}

void ts4l_pool8_init_8317BF40(ts4l_pool8 *p)
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
        ts4l_pchunk *c = p->base + i;
        ts4l_pnode *nn = &c->n;
        nn->next = p->free;
        p->free = nn;
    }
}

