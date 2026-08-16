extern void ts4_tsu_set_object_mode(void *object, int mode);
extern void ts4_tsu_finalize_object(void *object);

/* Swing_DLL.xex 0x8878C7E8; callback registration name remains under review. */
void ts4_tsu_disable_object(void *object)
{
    ts4_tsu_set_object_mode(object, 0);
    ts4_tsu_finalize_object(object);
}
