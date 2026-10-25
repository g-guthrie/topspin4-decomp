typedef unsigned int u32;

typedef void (*DestroyFn)(void *obj, u32 flag);

typedef struct Node {
    DestroyFn *vtable;
    u32 field_4;
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1C;
    u32 field_20;
    u32 field_24;
    u32 field_28;
    u32 field_2C;
    u32 field_30;
    u32 field_34;
    u32 field_38;
    u32 field_3C;
    u32 field_40;
} Node;

void fn_8825E428(Node *begin, Node *end)
{
    Node *current = begin;

    while (current != end) {
        current->vtable[1](current, 0);
        current++;
    }
}
