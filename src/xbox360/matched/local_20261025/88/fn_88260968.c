typedef unsigned int u32;

typedef void (*DestroyFn)(void *obj, u32 flag);

struct Node {
    DestroyFn *vtable;
    u32 field_4;
    char pad[0x120 - 8]; /* total size 0x120 */
};

void fn_88260968(struct Node *begin, struct Node *end)
{
    struct Node *current = begin;

    while (current != end) {
        current->vtable[1](current, 0);
        current++;
    }
}