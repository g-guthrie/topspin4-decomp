/* 0x883ED688: stops the object (vtable slot 4, arg 1), unlinks and frees every child in the list at +0x30 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); then unlinks itself (+4), clears +0xC and frees itself to the lbl_88B3302C heap (file lbl_88039ADC, line 0x1AD). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039ADC[];
typedef struct Link { struct Link *next; struct Link *prev; } Link;
struct T;
typedef struct VT { void *s[4]; int (*stop)(struct T *t, int how); } VT;
typedef struct T { VT *vt; Link link; int fc; char pad[0x30 - 0x10]; Link head; } T;
int ts4_unlink_free_883ED0C0(void *item);
void fn_88315F10(void *heap, void *p, const char *file, int line);
int ts4_stop_and_free_883ED688(T *t)
{
    Link *n, *next;
    int r = t->vt->stop(t, 1);
    if (r)
        return r;
    for (n = t->head.next; n != &t->head; n = next) {
        next = n->next;
        r = ts4_unlink_free_883ED0C0((char *)n - 4);
        if (r)
            return r;
    }
    t->link.prev->next = t->link.next;
    t->link.next->prev = t->link.prev;
    t->link.prev = &t->link;
    t->link.next = &t->link;
    t->fc = 0;
    fn_88315F10(lbl_88B3302C->heap, t, lbl_88039ADC, 0x1ad);
    return 0;
}
