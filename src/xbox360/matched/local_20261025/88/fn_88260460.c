typedef unsigned int u32;

typedef void (*DestroyFn)(void *obj, u32 flag);

typedef struct Node {
    DestroyFn *vtable;
    char padding[0x9C]; /* pad to make total size 0xA0 */
} Node;

void fn_88260460(Node *begin, Node *end)
{
    Node *current = begin;

    while (current != end) {
        current->vtable[1](current, 0);
        current++;
    }
}
