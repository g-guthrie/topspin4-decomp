typedef unsigned int u32;

typedef struct Ts4NetDbVirtualObject {
    void *vtable;
} Ts4NetDbVirtualObject;

extern char lbl_880D1F64;
extern void ts4_tsu_cleanup_end(void *object);

/* Swing_DLL.xex 0x881526E0. */
Ts4NetDbVirtualObject *ts4_netdb_destroy_variant_b(
    Ts4NetDbVirtualObject *object,
    u32 delete_object
)
{
    object->vtable = &lbl_880D1F64;
    if ((delete_object & 1U) != 0) {
        ts4_tsu_cleanup_end(object);
    }
    return object;
}
