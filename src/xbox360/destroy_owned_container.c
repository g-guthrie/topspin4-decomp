typedef unsigned int u32;

typedef struct Ts4OwnedContainer {
    void *vtable;
} Ts4OwnedContainer;

extern void *lbl_880D6AF4;
extern void fn_88617D28(Ts4OwnedContainer *object);
extern void ts4_tsu_cleanup_end(void *object);

/* Swing_DLL.xex 0x8816F8C0. */
Ts4OwnedContainer *ts4_destroy_owned_container(
    Ts4OwnedContainer *object,
    u32 flags
)
{
    object->vtable = &lbl_880D6AF4;
    fn_88617D28(object);
    if ((flags & 1) != 0) {
        ts4_tsu_cleanup_end(object);
    }
    return object;
}
