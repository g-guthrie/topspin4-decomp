/* Swing_DLL.xex 0x885847C8: move a page to the most-recent end of the circular page list, optionally making it the head
 * /O1; flag is unsigned (cmplwi) */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct PageLink { u8 pad[5]; u8 next; u8 prev; u8 pad7; } PageLink;
typedef struct PageTable {
    u8 pad[0x30];
    PageLink *links;   /* +0x30 */
    u8 pad34[0xC8 - 0x34];
    u8 count;          /* +0xC8 */
    u8 freeHead;       /* +0xC9 */
} PageTable;

void fn_885847C8(PageTable *t, u32 index, u32 makeHead)
{
    u32 head = t->freeHead;
    PageLink *links = t->links;
    PageLink *h = &links[head];
    if (index == head) {
        if (!makeHead)
            t->freeHead = h->next;
        return;
    }
    if (index != h->prev) {
        PageLink *e = &links[index];
        u8 prev = e->prev;
        u8 next = e->next;
        links[prev].next = next;
        links[next].prev = prev;
        e->next = (u8)head;
        e->prev = h->prev;
        links[h->prev].next = (u8)index;
        h->prev = (u8)index;
    }
    if (makeHead)
        t->freeHead = (u8)index;
}
