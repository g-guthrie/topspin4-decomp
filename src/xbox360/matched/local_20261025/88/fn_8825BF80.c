typedef unsigned int u32;
typedef void (*DestroyFn)(void *obj, u32 flag);

typedef struct Obj {
    DestroyFn *vtable;
    u32 field_4;
    /* 0xB0 bytes of data */
    char data[0xB0 - 8];
} Obj;

void fn_8825BF80(Obj *begin, Obj *end)
{
    Obj *current = begin;

    while (current != end) {
        current->vtable[1](current, 0);
        current++;
    }
}
