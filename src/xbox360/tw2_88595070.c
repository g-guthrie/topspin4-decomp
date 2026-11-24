/* Twin of 0x88599CF8 (ts4_pool1_clear_88599CF8 in src/xbox360/port1_pool_clear_o1_83171750.c), pool with 8 inline chunks. */
typedef struct ts4_pnode { int a; struct ts4_pnode *next; } ts4_pnode;
typedef struct ts4_pchunk { struct ts4_pchunk *next; ts4_pnode n; } ts4_pchunk;
typedef struct ts4_pool8 {
    ts4_pnode *free;
    ts4_pchunk *base;
    ts4_pchunk arr[8];
    int gap;
    ts4_pnode *head, *tail;
    int count, cap;
} ts4_pool8;

extern void ts4_pool_free_885B72F0(void *p);

/* Swing_DLL.xex 0x88595070 */
void ts4_pool1_clear_88595070(ts4_pool8 *p)
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
