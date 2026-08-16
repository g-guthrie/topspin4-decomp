typedef unsigned int u32;
typedef void (*Ts4DestroyFn)(void *object, u32 flag);

typedef struct Ts4PolymorphicValue {
    Ts4DestroyFn *vtable;
    u32 field_4;
    u32 field_8;
} Ts4PolymorphicValue;

/* Swing_DLL.xex 0x88170F58. */
void ts4_destroy_polymorphic_value_range(
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
