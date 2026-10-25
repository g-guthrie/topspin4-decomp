typedef struct Ts4Object { void *owned; } Ts4Object;
extern void ts4_object_finalize(Ts4Object *object);

void fn_887EAA38(Ts4Object *self) {
    ts4_object_finalize((Ts4Object *)((char *)self + 0x40));
}