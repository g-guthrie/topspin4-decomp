/* Swing_DLL.xex 0x883356F8-0x8833577C, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct node { struct node *next; u8 pad[0x18]; u16 kind; };
struct list { struct node *first; };
struct obj {
    u8 pad0[0x8c]; void *cur; u8 pad1[0x0c]; int key; u8 pad2[0x28]; u32 total; struct list *list; struct node *end;
};
int ts4_count_matching_883356F8(struct obj *self, u32 *out)
{
    struct node *n;
    if (out == 0) {
        return 0x25;
    }
    if (self->cur != 0) {
        *out = 0;
        if (self->list != 0) {
            for (n = self->list->first; n != self->end; n = n->next) {
                if (n->kind == self->key) {
                    *out = *out + 1;
                }
            }
        }
    } else {
        *out = self->total;
    }
    return 0;
}
