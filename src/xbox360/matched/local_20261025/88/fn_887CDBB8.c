typedef struct Ts4Object { void *owned; } Ts4Object;
extern void ts4_object_finalize(Ts4Object *object);

void fn_887CDBB8(Ts4Object *object)
{
    ts4_object_finalize((Ts4Object *)((char *)object + 0x18));
}