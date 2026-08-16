typedef struct Ts4Object { void *owned; } Ts4Object;

extern void ts4_object_finalize(Ts4Object *object);
extern void ts4_destroy_owned_object(void *owned);

/* Swing_DLL.xex 0x8878C300; callback registration name remains under review. */
void ts4_tsu_destroy_owned_object(Ts4Object *object)
{
    ts4_object_finalize(object);
    if (object->owned != 0) {
        ts4_destroy_owned_object(object->owned);
    }
}
