typedef struct Ts4Object { void *owned; } Ts4Object;
extern void ts4_object_finalize(Ts4Object *object);
extern void ts4_destroy_owned_object(void *owned);

void fn_88627A90(Ts4Object *object)
{
    ts4_object_finalize(object);
    if (object->owned != 0) {
        ts4_destroy_owned_object(object->owned);
    }
}