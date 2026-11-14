/* Loader_DLL.xex 0x83170148-0x8319CF10, executable version 0.0.0.3. */

typedef struct ts4l_pnode { int a; struct ts4l_pnode *next; } ts4l_pnode;
typedef struct ts4l_pchunk { int pad; ts4l_pnode n; } ts4l_pchunk;
/* Single-slot node pool with a free list, used-list head/tail, count and capacity. */
typedef struct ts4l_pool1 {
    ts4l_pnode *free;
    ts4l_pchunk *base;
    ts4l_pchunk arr[1];
    int gap;
    int c0, c1, c2, cap;
} ts4l_pool1;

void ts4l_pool1_init_83170148(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_83170258(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_831702F8(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_831703A8(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_831704E0(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_83171150(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_83175F10(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_831795B0(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_83179650(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_8317BAD0(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_8317BBE0(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_83180E90(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_83188600(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_83189AF8(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_83189BF8(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

void ts4l_pool1_init_8319CF10(ts4l_pool1 *p)
{
    ts4l_pchunk *c;
    ts4l_pnode *nn;
    p->free = 0;
    p->c0 = 0;
    p->c1 = 0;
    p->c2 = 0;
    p->cap = 1;
    p->base = p->arr;
    p->base->pad = 0;
    c = p->base;
    nn = &c->n;
    nn->next = p->free;
    p->free = nn;
}

