typedef unsigned int u32;
typedef void (*Ts4DestroyFn)(void *object, u32 flag);
typedef struct Ts4PolymorphicValue {
    Ts4DestroyFn *vtable;
    u32 field_4;
    u32 field_8;
    u32 field_C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1C;
    u32 field_20;
} Ts4PolymorphicValue;

void fn_88282ED8(
    Ts4PolymorphicValue *begin,
    Ts4PolymorphicValue *end
)
{
    Ts4PolymorphicValue *current = begin;

    while (current != end) {
        current->vtable[0](current, 0);
        current++;
    }
}
