/* 0x885DA380: On first use (bit 0x80 of the byte at +0x7c clear) initialises the list at +4 (locked byte, count, self-linked head at +0xc) and sets the bit; then zeroes the count and returns 0. */
/* Matched on /Oc /Os (agAH). Built /Os (14 off on /Oc). */
typedef struct ListLink { struct ListLink *next; struct ListLink *prev; } ListLink;
typedef struct LinkList { unsigned char locked; int count; ListLink head; } LinkList;
typedef struct Owner { int unk0; LinkList list; char pad[0x7c - 0x14]; unsigned char flags; } Owner;
int fn_885DA380(Owner *o)
{
    if (!(o->flags & 0x80)) {
        LinkList *l = &o->list;
        l->locked = 0;
        l->count = 0;
        l->head.next = &l->head;
        l->head.prev = &l->head;
        o->flags |= 0x80;
    }
    o->list.count = 0;
    return 0;
}
