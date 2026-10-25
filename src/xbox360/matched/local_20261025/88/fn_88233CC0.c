typedef unsigned int u32;
typedef void (*DestroyFn)(void *obj, u32 flag);

typedef struct Node {
    DestroyFn *vtable;
    u32 field_4;
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u32 field_14;
} Node;

void fn_88233CC0(Node *begin, Node *end)
{
    Node *current = begin;

    while (current != end) {
        current->vtable[1](current, 0);
        current++;
    }
}
