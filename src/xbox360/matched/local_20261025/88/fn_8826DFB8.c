typedef unsigned int u32;
typedef void (*Ts4DestroyFn)(void *object, u32 flag);
typedef struct Ts4PolymorphicValueLarge {
    Ts4DestroyFn *vtable;
    u32 field_4;
    u32 field_8;
    u32 field_C;
    u32 field_10;
} Ts4PolymorphicValueLarge;

void fn_8826DFB8(
    Ts4PolymorphicValueLarge *begin,
    Ts4PolymorphicValueLarge *end
)
{
    Ts4PolymorphicValueLarge *current = begin;

    while (current != end) {
        current->vtable[0](current, 0);
        current++;
    }
}
