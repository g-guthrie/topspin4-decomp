typedef struct Ts4Object { void *owned; } Ts4Object;
extern void ts4_object_finalize(Ts4Object *object);

void fn_8876D0B0(Ts4Object *object)
{
    ts4_object_finalize((Ts4Object *)((char *)object + 4));
}