typedef unsigned char u8;

typedef struct Ts4CleanupObject {
    void *field_0;
    u8 reserved[8];
    void *field_c;
} Ts4CleanupObject;

extern void ts4_tsu_cleanup_begin(Ts4CleanupObject *object);
extern void ts4_destroy_owned_object(void *owned);
extern void ts4_tsu_cleanup_end(Ts4CleanupObject *object);

/* Swing_DLL.xex 0x8878C940; callback registration name remains under review. */
void ts4_tsu_cleanup_object(Ts4CleanupObject *object)
{
    if (object != 0) {
        ts4_tsu_cleanup_begin(object);
        if (object->field_c != 0) ts4_destroy_owned_object(object->field_c);
        if (object->field_0 != 0) ts4_destroy_owned_object(object->field_0);
        ts4_tsu_cleanup_end(object);
    }
}
