/* q5s_cont: containers whose elements go back to the engine heap (LTCG route, /Oc).
 * The inlined heap free (owner lookup in lbl_88D45B38, else CRT free) keeps the heap pointer in a
 * register across the loop and reloads it only after the two owner-visit calls; written out
 * explicitly because a plain inline helper reloads it every iteration. */
#include "include/ts4/ts4.h"

typedef struct Ts4HeapRoot {
    char pad[0x24];
    void *f24; /* +0x24 default owner */
} Ts4HeapRoot;
extern Ts4HeapRoot *lbl_88D45B38;
extern void *ts4_find_range_owner_8860D360(Ts4HeapRoot *heap, void *p);
extern void ts4_node_visit_8860DBC8(void *owner, void *p);
extern void fn_885651F8(void *p); /* free */

/* ---- Circular doubly linked list with a heap-allocated sentinel: free every node, re-link the sentinel. ---- */
typedef struct Ts4LNode {
    struct Ts4LNode *next;
    struct Ts4LNode *prev;
} Ts4LNode;
typedef struct Ts4LList {
    Ts4LNode *head;
} Ts4LList;

void ts4_clear_intrusive_list(Ts4LList *l)
{
    Ts4LNode *n = l->head->next;
    if (n != l->head) {
        Ts4HeapRoot *h = lbl_88D45B38;
        do {
            Ts4LNode *cur = n;
            n = n->next;
            if (h) {
                void *r = ts4_find_range_owner_8860D360(h, cur);
                if (r) { ts4_node_visit_8860DBC8(r, cur); h = lbl_88D45B38; }
                else { ts4_node_visit_8860DBC8(h->f24, cur); h = lbl_88D45B38; }
            } else {
                fn_885651F8(cur);
            }
        } while (n != l->head);
    }
    l->head->next = l->head;
    l->head->prev = l->head;
}

/* ---- Destroy [first, last) of 0x34-byte elements holding three 12-byte buffers at +0x10 (destroyed
 * last to first). Called by the vector erase at 88159558. ---- */
typedef struct Ts4BufSlot {
    void *p;
    int a;
    int b;
} Ts4BufSlot;
typedef struct Ts4Buf3Elem {
    char pad[0x10];
    Ts4BufSlot s[3]; /* +0x10 */
} Ts4Buf3Elem;

void ts4_buf3_destroy_range_8815BB30(Ts4Buf3Elem *first, Ts4Buf3Elem *last)
{
    Ts4Buf3Elem *it = first;
    if (first != last) {
        Ts4HeapRoot *h = lbl_88D45B38;
        do {
            Ts4BufSlot *s = &it->s[3];
            int i;
            for (i = 2; i >= 0; i--) {
                void *p = (--s)->p;
                if (p) {
                    if (h) {
                        void *r = ts4_find_range_owner_8860D360(h, p);
                        if (r) { ts4_node_visit_8860DBC8(r, p); h = lbl_88D45B38; }
                        else { ts4_node_visit_8860DBC8(h->f24, p); h = lbl_88D45B38; }
                    } else {
                        fn_885651F8(p);
                    }
                }
            }
            ++it;
        } while (it != last);
    }
}
