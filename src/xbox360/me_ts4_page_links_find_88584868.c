/* Swing_DLL.xex 0x88584868: find the in-use page whose aligned base and kind match, walking the circular list from the head
 * /O1; kind 1..3 aligns the base down by lbl_88091428[kind-1] */
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct PageLink { u32 base; u8 pad4; u8 next; u8 prev; u8 flags; } PageLink;
typedef struct PageTable {
    u8 pad[0x30];
    PageLink *links;   /* +0x30 */
    u8 pad34[0xC8 - 0x34];
    u8 count;          /* +0xC8 */
    u8 freeHead;       /* +0xC9 */
} PageTable;

extern const u32 lbl_88091428[3]; /* alignment per page kind 1..3 */

int fn_88584868(PageTable *t, u32 base, u32 kind, u32 *index, PageLink **link)
{
    u32 head = t->freeHead;
    PageLink *links = t->links;
    u32 i = head;
    PageLink *e;
    if (kind >= 1 && kind <= 3)
        base -= base % lbl_88091428[kind - 1];
    for (e = &links[i]; (e->flags & 0x80) != 0; e = &links[i]) {
        if (e->base == base && (e->flags & 3) == kind) {
            *index = i;
            *link = e;
            return 1;
        }
        i = e->next;
        if (i == head)
            break;
    }
    return 0;
}
