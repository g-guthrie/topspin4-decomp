typedef struct Ts4Object { void *owned; } Ts4Object;
extern void ts4_object_finalize(Ts4Object *object);

void fn_888033D8(void *object)
{
    ts4_object_finalize((Ts4Object *)((char *)object + 0x1c));
}