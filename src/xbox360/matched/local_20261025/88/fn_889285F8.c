extern void fn_88922B28(void *arg);
extern void ts4_destroy_owned_object(void *owned);

typedef struct Ts4Object { void *owned; } Ts4Object;

void fn_889285F8(Ts4Object *object)
{
    fn_88922B28(object);
    if (object->owned != 0) {
        ts4_destroy_owned_object(object->owned);
    }
}