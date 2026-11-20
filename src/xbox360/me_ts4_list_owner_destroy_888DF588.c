/* 0x888DF588: destructor body: set the vtable lbl_880DBDF8, destroy the member at +0xD0, clear and free the four intrusive lists at +0x9C in reverse, destroy the member at +0x3C, then run the base destructor 88617D28 */
/* Matched on /Oc (agAL). Plain route. List dtor = ts4_clear_intrusive_list + the inlined ts4_destroy_owned_object body; agAH reverse destroy_n inline. */
typedef struct Ts4Registry { char p[0x24]; void *fallback; } Ts4Registry;
extern Ts4Registry *lbl_88D45B38;
void *ts4_find_range_owner_8860D360(Ts4Registry *registry, void *key);
void ts4_node_visit_8860DBC8(void *entry, void *key);
void fn_885651F8(void *p);

static __inline void owned_free(void *p)
{
    if (p != 0) {
        Ts4Registry *r = lbl_88D45B38;
        if (r != 0) {
            void *e = ts4_find_range_owner_8860D360(r, p);
            if (e != 0)
                ts4_node_visit_8860DBC8(e, p);
            else
                ts4_node_visit_8860DBC8(r->fallback, p);
        } else {
            fn_885651F8(p);
        }
    }
}

typedef struct ListNode ListNode;
struct ListNode { ListNode *next; ListNode *prev; };
typedef struct List { ListNode *head; } List;
typedef struct ListOwner {
    const void *vt; unsigned char pad4[0x3c - 4]; unsigned char sub3c[0x9c - 0x3c];
    List lists[4]; unsigned char padac[0xd0 - 0xac]; unsigned char subd0[4];
} ListOwner;
extern const char lbl_880DBDF8[];
extern void ts4_clear_intrusive_list(List *l);
extern void ts4_if_call_seq_u32_off4_8817E430(void *p);
extern void ts4_loop_call_seq_lbl_880D6268_8892AF80(void *p);
extern void ts4_if_call_seq_lbl_880F7EE4_88617D28(ListOwner *o);

static __inline void list_dtor(List *l)
{
    ts4_clear_intrusive_list(l);
    owned_free(l->head);
}

static __inline void lists_destroy_n(List *first, int count)
{
    List *p = first + count;
    while (--count >= 0) {
        --p;
        list_dtor(p);
    }
}

void ts4_list_owner_destroy_888DF588(ListOwner *o)
{
    o->vt = lbl_880DBDF8;
    ts4_if_call_seq_u32_off4_8817E430(o->subd0);
    lists_destroy_n(o->lists, 4);
    ts4_loop_call_seq_lbl_880D6268_8892AF80(o->sub3c);
    ts4_if_call_seq_lbl_880F7EE4_88617D28(o);
}
