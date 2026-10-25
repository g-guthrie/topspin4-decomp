typedef unsigned int u32;
typedef void (*DestroyFn)(void *obj, u32 flag);

typedef struct Item {
    DestroyFn *vtable;
    u32 field_4;
    u32 field_8;
    u32 field_C;
} Item;

void fn_88233F80(Item *begin, Item *end)
{
    Item *current = begin;

    while (current != end) {
        current->vtable[1](current, 0);
        current++;
    }
}
