/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l24_pool_clear_o1_83171750.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
typedef struct ts4_pnode { int a; struct ts4_pnode *next; } ts4_pnode;
typedef struct ts4_pchunk { struct ts4_pchunk *next; ts4_pnode n; } ts4_pchunk;
/* Node pool with inline first page (1 or 16 chunks), free list and used list. */
typedef struct ts4_pool1 {
    ts4_pnode *free;
    ts4_pchunk *base;
    ts4_pchunk arr[1];
    int gap;
    ts4_pnode *head, *tail;
    int count, cap;
} ts4_pool1;
typedef struct ts4_pool16 {
    ts4_pnode *free;
    ts4_pchunk *base;
    ts4_pchunk arr[16];
    int gap;
    ts4_pnode *head, *tail;
    int count, cap;
} ts4_pool16;

extern void ts4_pool_free_885B72F0(void *p);

/* Swing_DLL.xex 0x88599CF8 */
void ts4_pool1_clear_88599CF8(ts4_pool1 *p)
{
    ts4_pnode *n;
    ts4_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4_pool_free_885B72F0(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

/* Swing_DLL.xex 0x885A5E20 */
void ts4_pool16_clear_885A5E20(ts4_pool16 *p)
{
    ts4_pnode *n;
    ts4_pchunk *pg, *nx;
    while (p->head) {
        n = p->head;
        nx = (ts4_pchunk *)n->next;
        n->next = p->free;
        p->free = n;
        p->head = (ts4_pnode *)nx;
    }
    p->count = 0;
    p->tail = 0;
    while (p->base) {
        pg = p->base;
        nx = pg->next;
        if (pg != p->arr) {
            if (p->base) {
                ts4_pool_free_885B72F0(p->base);
                p->base = 0;
            }
        }
        p->base = nx;
    }
}

