/* 0x881A6A00: free the block held in the first word of an owner (registry release or CRT free, the ts4_destroy_owned_object body inlined) */
/* Matched on /Oc (agAL). Plain route with the destroy_owned_object body as a static __inline. */
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

typedef struct OwnedPtr { void *p; } OwnedPtr;

void ts4_owned_ptr_free_881A6A00(OwnedPtr *o)
{
    owned_free(o->p);
}
