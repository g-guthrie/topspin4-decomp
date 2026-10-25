typedef struct Ts4Object { void *owned; } Ts4Object;
extern void ts4_object_finalize(Ts4Object *object);

void fn_886EDB68(Ts4Object *obj)
{
    ts4_object_finalize((Ts4Object *)((char *)obj + 0x1c));
}