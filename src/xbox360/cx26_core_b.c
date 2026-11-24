/* CX26 part b: game core 0x881732E0-0x8818C6C0, /Oc (divide without trap). */
typedef unsigned int u32;
typedef unsigned char u8;

extern void *lbl_88D45B38;
extern void *ts4_find_range_owner_8860D360(void *heap, void *p);
extern void ts4_node_visit_8860DBC8(void *a, void *p);
extern void fn_885651F8(void *p);
typedef struct Cx26Heap { u8 pad[0x24]; void *f24; } Cx26Heap;

/* 0x88174B18: hand a block back to its owning heap (or free it) */
void ts4_destroy_owned_object(void *p)
{
    if (p) {
        Cx26Heap *h = (Cx26Heap *)lbl_88D45B38;
        if (h) {
            void *r = ts4_find_range_owner_8860D360(h, p);
            if (r) ts4_node_visit_8860DBC8(r, p); else ts4_node_visit_8860DBC8(h->f24, p);
        } else {
            fn_885651F8(p);
        }
    }
}

extern void fn_88150600(void *d, void *s);
/* 0x88185D08: copy 0x5c-byte elements [first,last) to dest; returns the end of dest */
typedef struct Cx26E5c { u32 w[0x17]; } Cx26E5c;
Cx26E5c *ts4_copy_e5c_88185D08(Cx26E5c *first, Cx26E5c *last, Cx26E5c *d)
{
    int n = ((char *)last - (char *)first) / 0x5c;
    for (; n > 0; n--) {
        fn_88150600(d, first);
        d->w[3] = first->w[3];
        d->w[4] = first->w[4];
        d->w[5] = first->w[5];
        d->w[6] = first->w[6];
        d->w[7] = first->w[7];
        d->w[8] = first->w[8];
        d->w[9] = first->w[9];
        d->w[10] = first->w[10];
        d->w[11] = first->w[11];
        d->w[12] = first->w[12];
        d->w[13] = first->w[13];
        d->w[14] = first->w[14];
        d->w[15] = first->w[15];
        d->w[16] = first->w[16];
        d->w[17] = first->w[17];
        d->w[18] = first->w[18];
        d->w[19] = first->w[19];
        d->w[20] = first->w[20];
        d->w[21] = first->w[21];
        d->w[22] = first->w[22];
        first++; d++;
    }
    return d;
}
