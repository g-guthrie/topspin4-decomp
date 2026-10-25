typedef struct Ts4Object { void *owned; } Ts4Object;
extern void ts4_object_finalize(Ts4Object *object);

void fn_8865A2C0(void *p)
{
    ts4_object_finalize((Ts4Object *)((char *)p + 0x10));
}