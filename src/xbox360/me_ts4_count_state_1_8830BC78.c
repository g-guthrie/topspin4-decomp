/* 0x8830BC78: counts the list items (head at +0x63ec, links point at +4 of each item) whose state (+0x234) is 1 */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk). */
typedef struct It { int a; void *next; char p[0x234 - 8]; int state; } It;
typedef struct { char p[0x63ec]; It head; } S;
#define ITEM(l) ((l) ? (It *)((char *)(l) - 4) : 0)
int ts4_count_state_1_8830BC78(S *s) { int n = 0; It *it; for (it = ITEM(s->head.next); it != &s->head; it = ITEM(it->next)) if (it->state == 1) n++; return n; }
