typedef unsigned int u32;
typedef void (*DestroyFn)(void *object, u32 flag);
typedef struct Object {
    DestroyFn *vtable;
    u32 field_4;
} Object;

void fn_8826DF58(Object *begin, Object *end)
{
    Object *current = begin;

    while (current != end) {
        current->vtable[0](current, 0);
        current++;
    }
}