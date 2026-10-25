typedef struct Ts4Object { void *owned; } Ts4Object;
extern void ts4_object_finalize(Ts4Object *object);

void fn_8890DFC0(void *ptr)
{
    ts4_object_finalize((Ts4Object *)((char *)ptr + 0x14));
}