/* 0x883318D8: links node n (link at +4) at the tail of the list headed at +0x18; returns 0 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct L { struct L *next, *prev; } L;
typedef struct { int a; L link; } N;
typedef struct { char p[0x18]; L head; } S;
int ts4_link_tail_18_883318D8(S *s, N *n) { L *h = &s->head; L *l = &n->link; L *prev = h->prev; l->next = h; l->prev = prev; h->prev = l; l->prev->next = l; return 0; }
