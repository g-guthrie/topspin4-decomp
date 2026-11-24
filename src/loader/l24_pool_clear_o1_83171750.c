/* Loader_DLL.xex 0x83171750-0x8319E9E8, executable version 0.0.0.3. */

typedef struct ts4l_pnode { int a; struct ts4l_pnode *next; } ts4l_pnode;
typedef struct ts4l_pchunk { struct ts4l_pchunk *next; ts4l_pnode n; } ts4l_pchunk;
/* Node pool with inline first page (1 or 16 chunks), free list and used list. */
typedef struct ts4l_pool1 {
    ts4l_pnode *free;
    ts4l_pchunk *base;
    ts4l_pchunk arr[1];
    int gap;
    ts4l_pnode *head, *tail;
    int count, cap;
} ts4l_pool1;
typedef struct ts4l_pool16 {
    ts4l_pnode *free;
    ts4l_pchunk *base;
    ts4l_pchunk arr[16];
    int gap;
    ts4l_pnode *head, *tail;
    int count, cap;
} ts4l_pool16;

extern void ts4l_pool_free_8316F200(void *p);
extern void ts4l_pool_free_83174FE0(void *p);
extern void ts4l_pool_free_831791F0(void *p);
extern void ts4l_pool_free_8317B410(void *p);
extern void ts4l_pool_free_83180808(void *p);
extern void ts4l_pool_free_831883E0(void *p);
extern void fn_8319CCD0(void *p);
extern void fn_8319D868(void *p);

void ts4l_pool1_clear_83171860(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8316F200(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_83171970(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8316F200(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_83171A78(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8316F200(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_83171B88(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8316F200(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_83171C98(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8316F200(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_83171F60(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8316F200(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_831767A0(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_83174FE0(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_83176830(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_83174FE0(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_831768C0(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_83174FE0(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_83179DB0(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_831791F0(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_83179E40(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_831791F0(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_8317CB38(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8317B410(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_8317CBC8(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8317B410(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_83181EC8(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_83180808(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_831889C8(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_831883E0(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool1_clear_8319D2D8(ts4l_pool1 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                fn_8319CCD0(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool16_clear_83171750(ts4l_pool16 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8316F200(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool16_clear_83171E40(ts4l_pool16 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8316F200(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool16_clear_83171ED0(ts4l_pool16 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_8316F200(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool16_clear_83176950(ts4l_pool16 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_83174FE0(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool16_clear_83181E38(ts4l_pool16 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_83180808(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool16_clear_83182098(ts4l_pool16 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4l_pool_free_83180808(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

void ts4l_pool16_clear_8319E9E8(ts4l_pool16 *p)
{
    ts4l_pnode *n;
    ts4l_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4l_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4l_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                fn_8319D868(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

