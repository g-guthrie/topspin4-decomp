/* CX25 part a: game core 0x881EEBB0-0x8820F390 (pools, name lookups, grow), plain route, no flags. */
typedef unsigned int u32;
typedef unsigned char u8;
int fn_885630C0(const char *a, const char *b, int n);
static __inline u8 cx25_streq(const char *a, const char **pb)
{
    const char *b = *pb;
    int n = ((int *)a)[-3];
    if (n != ((int *)b)[-3]) return 0;
    return fn_885630C0(a, b, n) == 0;
}
typedef struct Cx25NNode Cx25NNode;
struct Cx25NNode { Cx25NNode *next; u32 p4; const char *name; };
typedef struct Cx25NList { u8 pad[0x14]; Cx25NNode *head; } Cx25NList;
typedef struct Cx25NOwner { u8 pad[0x10]; Cx25NList *list; } Cx25NOwner;

/* 0x88202040 */
u8 ts4_name_list_has_88202040(Cx25NOwner *o, const char **name)
{
    Cx25NNode *n;
    for (n = o->list->head; n != 0; n = n->next)
        if (cx25_streq(n->name, name)) return 1;
    return 0;
}

typedef struct Cx25MNode Cx25MNode;
struct Cx25MNode { u8 pad[0xc]; const char *name; u32 p10; u32 p14; Cx25MNode *next; };
typedef struct Cx25MOwner { u8 pad[0x14]; Cx25MNode *head; } Cx25MOwner;

/* 0x881F68A0 */
Cx25MNode *ts4_name_list_find_881F68A0(Cx25MOwner *o, const char **name)
{
    Cx25MNode *n;
    for (n = o->head; n != 0; n = n->next)
        if (cx25_streq(n->name, name)) return n;
    return 0;
}


typedef struct Cx25Pay { u8 flag; u8 pad[3]; u32 w[2]; } Cx25Pay;
typedef struct Cx25QNode Cx25QNode;
struct Cx25QNode { Cx25QNode *next; Cx25QNode *prev; Cx25Pay pay; };
typedef struct Cx25Pool {
    Cx25QNode *freelist;
    u8 pad[0x7d4 - 4];
    Cx25QNode *head; Cx25QNode *tail; u32 count;
} Cx25Pool;
extern void fn_8818EB10(void *dst, void *src);
extern void ts4_call_seq_u32_off8_881F7090(void *p);

/* 0x881F7728 */
Cx25Pay *ts4_pool_pop_front_881F7728(Cx25Pay *out, Cx25Pool *p)
{
    Cx25QNode *n = p->head;
    Cx25Pay *pl = &n->pay;
    Cx25QNode *nx;
    out->flag = pl->flag;
    fn_8818EB10(&out->w[0], &pl->w[0]);
    fn_8818EB10(&out->w[1], &pl->w[1]);
    nx = n->next;
    p->head = nx;
    if (nx != 0) nx->prev = 0;
    else p->tail = 0;
    ts4_call_seq_u32_off8_881F7090(pl);
    n->next = p->freelist;
    p->freelist = n;
    p->count--;
    return out;
}

extern void *fn_88562DC0(void *dst, const void *src, u32 n);
typedef struct Cx25Grow { u8 pad[0x24]; void *buf; u32 count; u32 cap; } Cx25Grow;

/* 0x88201118 */
void ts4_grow_reserve_88201118(Cx25Grow *g, u32 n)
{
    if (n > g->cap) {
        if (g->buf != 0) {
            u32 cnt = g->count;
            u32 step = cnt >> 3;
            u32 sum;
            if (step < 4) step = 4;
            else if (step > 0x400) step = 0x400;
            sum = g->cap + step;
            if (n < sum) n = sum;
            fn_88562DC0(g, g->buf, cnt * 4);
        }
        g->cap = n;
        g->buf = g;
    }
}
